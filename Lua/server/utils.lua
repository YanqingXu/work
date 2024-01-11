-- Desc: 一些工具函数
local PROJECT_ROOT = "E:\\server\\"
local function getProjectRootPath()
    return string.sub(PROJECT_ROOT, 1, 1)
end

function split(str, sep)
    local tbl = {}

    repeat
        local pos = string.find(str, sep)
        if not pos then
			if str ~= " " and str ~= "" and string.len(str) > 0 then
				tbl[#tbl + 1] = str
			end
            break
        end

        local sub_str = string.sub(str, 1, pos - 1)
		if sub_str ~= " " and sub_str ~= "" and string.len(sub_str) > 0 then
			tbl[#tbl + 1] = sub_str
		end

        str = string.sub(str, pos + 1, #str)
    until false

    return tbl
end

function trim(str)
    return string.gsub(str, "^%s*(.-)%s*$", "%1")
end

-- 用于缩进
local function pad(depth)
    return string.rep("  ", depth)
end

-- 用于转义字符串中的换行符
local function escape_newlines(str)
    return str:gsub("\n", "\\n")
end

local function dumpPrintObj(target, depth, k)
    if type(target) == 'table' then
        return
    end

    if type(target) == 'string' then
        local newStr = escape_newlines(target)
        print(pad(depth + 1) .. '[' .. k .. '] = "' .. newStr .. '",')
    else
        print(pad(depth + 1) .. '[' .. k .. '] = ' .. tostring(target) .. ',')
    end
end

local function dumpImpl(obj, depth, mapExisted)
    depth = depth or 0
    if depth > 10 then
        return
    end

    if type(obj) ~= 'table' then
        print(tostring(obj))
        return
    end

    print(pad(depth) .. '{')

    for k, v in pairs(obj) do
        repeat
            if k == "__index" then
                break
            end

            local key = k

            if type(k) ~= 'number' then
                k = '"' .. k .. '"'
            end

            if mapExisted[key] and mapExisted[key] == v then
                dumpPrintObj(v, depth, k)
                break
            end

            mapExisted[key] = v

            if type(v) == "table" then
                print(pad(depth + 1) .. '[' .. k .. '] = ')
                dumpImpl(v, depth + 1, mapExisted)
                break
            end

            dumpPrintObj(v, depth, k)
        until true
    end

    print(pad(depth) .. '},')
end

function dump(obj, source)
    local traceback = split(debug.traceback("", 2), "\n")
    if not traceback then
        return
    end

    print("-----------------------------------------------------------------------------------------")
    print("dump from: " .. trim(traceback[2]))

    if source then
        print(source)
    end

    local mapExisted = {}
    dumpImpl(obj, nil, mapExisted)
    print("-----------------------------------------------------------------------------------------")
end

local function trimPrefix(str, pattern)
    if string.find(str, pattern) then
        local pos = string.find(str, pattern)
        str = string.sub(str, pos + string.len(pattern), #str)
    end

    return str
end

local function trimQuotationMark(str)
    if string.find(str, "\"") then
        str = string.gsub(str, "\"", "")
    end

    if string.find(str, "\'") then
        str = string.gsub(str, "\'", "")
    end

    return str
end

local function extractFuncName(lineContent)
    -- 匹配普通的函数定义，如 "function funcName"
    local funcName = lineContent:match("function%s+([%w_.]+)%(")

    -- 匹配局部函数定义，如 "local funcName ="
    if not funcName then
        funcName = lineContent:match("local%s+([%w_]+)%s*=")
    end

    -- 匹配赋值给变量的匿名函数，如 "funcName = function" 或 "funcName = function()"
    if not funcName then
        funcName = lineContent:match("([%w_]+)%s*=%s*function")
    end

    -- 匹配表方法定义，如 "function TableName.funcName"
    if not funcName then
        funcName = lineContent:match("function%s+[%w_]+%.([%w_]+)")
    end

    -- 匹配冒号语法的方法定义，如 "function TableName:funcName"
    if not funcName then
        funcName = lineContent:match("function%s+[%w_]+:([%w_]+)")
    end

    if not funcName then
        funcName = "anonymous function"
    end

    return funcName
end

local function getFuncNameFromLine(filePath, lineNumber)
    filePath = PROJECT_ROOT .. filePath
    local file = io.open(filePath, "r")
    if not file then
        print("getFuncNameFromLine: file not exist: " .. filePath)
        return nil
    end

    local lineContent
    for i = 1, lineNumber do
        lineContent = file:read("*line")
    end

    file:close()
    return extractFuncName(lineContent)
end

function trace(maxDepth)
    local traceback = split(debug.traceback("", 2), "\n")
    if not traceback then return end

    print("-----------------------------------------------------------------------------------------")
    print("| trace begin:")

    local depth = 2
    maxDepth = depth + (maxDepth or 5)

    repeat
        if depth > maxDepth then
            print("| trace end: depth > maxDepth")
            break
        end

        if not traceback[depth] then
            print("| trace end!")
            break
        end

        local funcInfo = traceback[depth]
        funcInfo = trim(funcInfo)

        local isTailCall = false

        local path, name = "", ""
        repeat
            if string.find(funcInfo, "tail call") then
                isTailCall = true
                break
            end

            if not string.find(funcInfo, "in function") then
                break
            end

            local funcLineInfo = split(funcInfo, "in function")
            if not funcLineInfo or #funcLineInfo < 2 then
                break
            end

            path = funcLineInfo[1]
            name = funcLineInfo[2]

            if string.find(name, "function") then
                name = trimPrefix(name, "function")
                name = trim(name)
            end

            local rootPathPattern = getProjectRootPath()..":\\"
            if string.find(name, rootPathPattern) then
                name = trimPrefix(name, rootPathPattern)
                name = trim(name)
                name = rootPathPattern..name
            end

            if not string.find(name, "(bin.*%w+%.lua):(%d+)") then
                break
            end

            local filePath, lineNum = name:match("(bin.*%w+%.lua):(%d+)")
            if filePath and lineNum then
                local funcName = getFuncNameFromLine(filePath, tonumber(lineNum))
                if funcName then
                    name = funcName
                end
            end
        until true

        name = trimQuotationMark(name)
        name = trim(name)

        if isTailCall then
            print("|".. pad(2) .. "in last function tail call")
        else
            print("|".. pad(2) .. path .. " in function \"" .. name .. "\"")
        end
        depth = depth + 1
    until false

    print("-----------------------------------------------------------------------------------------")
end


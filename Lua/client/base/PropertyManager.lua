local PropertyManager = {}

-- 存储每个table及其原始元表和回调
local managed_tables = {}

-- 回调函数模板
local function default_callback(tbl, key, old_value, new_value)
    print(string.format("属性 '%s' 从 %s 变更为 %s", key, tostring(old_value), tostring(new_value)))
end

-- 修改或设置__index来返回正确的值
local function metaIndex(t, key)
    local tbl = managed_tables[t]
    if tbl == nil then
        print("PropertyManager: table not watched")
        return nil
    end

    if tbl.properties[key] ~= nil then
        return tbl.properties[key]
    end

    if type(tbl.original_mt.__index) == "table" then
        return tbl.original_mt.__index[key]
    end

    if type(tbl.original_mt.__index) == "function" then
        return tbl.original_mt.__index(t, key)
    end

    return nil
end

-- 修改或设置__newindex来正确触发回调
local function metaNewIndex(t, key, new_value)
    local tbl = managed_tables[t]
    local old_value = tbl.properties[key]

    if old_value ~= new_value then
        tbl.properties[key] = new_value
        tbl.callback(t, key, old_value, new_value)
    end
end

-- 设置监视
function PropertyManager.watch(tbl, callback)
    local original_mt = getmetatable(tbl) or {}
    managed_tables[tbl] = {
        original_mt = original_mt,
        callback = callback or default_callback,
        properties = {} -- 用于追踪属性值变化
    }

    local new_mt = {}
    -- 复制原始元表的方法，以确保行为一致
    for k, v in pairs(original_mt) do
        new_mt[k] = v
    end

    new_mt.__index = metaIndex       -- 修改或设置__index来返回正确的值
    new_mt.__newindex = metaNewIndex -- 修改或设置__newindex来正确触发回调

    setmetatable(tbl, new_mt)
end

-- 取消监视
function PropertyManager.unwatch(tbl)
    local info = managed_tables[tbl]
    if info then
        setmetatable(tbl, info.original_mt)
        managed_tables[tbl] = nil
    end
end

return PropertyManager

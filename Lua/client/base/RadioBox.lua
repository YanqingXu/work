---@diagnostic disable: duplicate-set-field
local RadioBox = class("RadioBox")


function RadioBox:ctor()
    self.array = {}
    self.handler = nil
    self.select = nil
    self.canRepeat = false --当已选中的按钮被重复点击时是否要触发事件
end

function RadioBox:getSelectIndex()
    return self.select
end

function RadioBox:setRepeatClick(bool)
    self.canRepeat = bool
end

local function compare(a, b)
    if a == b then
        return true
    end
    if type(a) == "table" and a.id then
        a = a.id
    end
    if type(b) == "table" and b.id then
        b = b.id
    end
    return a == b
end
function RadioBox:selectItem(key, target)
    local item = nil
    if self.canRepeat or not compare(self.select, key) then
        local ok = true
        if self.handler ~= nil then
            if self.handler(key, target) == false then
                ok = false
            end
        end

        if ok then
            self.select = key
        else
            key = self.select
        end

        self.select = key
        for _, v in ipairs(self.array) do
            if compare(v.key, key) then
                v.component:setSelected(true)
                if not self.canRepeat then
                    v.component:setTouchEnabled(false)
                end
                key = v.key
                item = v
            else
                v.component:setSelected(false)
                if not self.canRepeat then
                    v.component:setTouchEnabled(true)
                end
            end
        end
    else
        for _, v in ipairs(self.array) do
            if compare(v.key, key) then
                v.component:setSelected(true)
                if not self.canRepeat then
                    v.component:setTouchEnabled(false)
                end
                item = v
            else
                v.component:setSelected(false)
                if not self.canRepeat then
                    v.component:setTouchEnabled(true)
                end
            end
        end
    end
    return item
end

-- 设置为选择状态，但不出发回调
function RadioBox:setOnlySelect(key)
    self.select = key
    local item = nil
    for _, v in ipairs(self.array) do
        if compare(v.key, key) then
            v.component:setSelected(true)
            item = v
        else
            v.component:setSelected(false)
        end
    end
    return item
end

-- 取消所有选择状态
function RadioBox:cancelAllSelect()
    for _, v in ipairs(self.array) do
        v.component:setSelected(false)
    end
    self:setRepeatClick(true)
end

-- 判断是否存在这个id
function RadioBox:hasItem(key)
    for _, v in ipairs(self.array) do
        if compare(v.key, key) then
            return true
        end
    end
    return false
end

-- 删除id
function RadioBox:removeItem(key)
    for k, v in pairs(self.array) do
        if compare(v.key, key) then
            table.remove(self.array, k)
            return true
        end
    end
    return false
end

function RadioBox:removeAllItems()
    self.array = {}
    self.select = nil
end

---
--@function 添加一个RadioBoxItem
--@param key 按钮对应的关键字或数据
--@param checkBox 按钮对象
--@param selected 当前按钮是否要默认选中
function RadioBox:addItem(key, checkBox, selected)
    local v = { key = key, component = checkBox, selected = selected }
    table.insert(self.array, v)
    v.index = #self.array
    local function selectBox(sender, eventType)
        self:selectItem(key)
    end
    checkBox:addEventListener(selectBox)
    if selected then
        self:selectItem(key)
    end
end

function RadioBox:getItem(key)
    for _, v in ipairs(self.array) do
        if compare(v.key, key) then
            return v.component
        end
    end
    return nil
end

function RadioBox:remove()
    self.handler = nil
    self.array = {}
end

function RadioBox:setHandler(func)
    self.handler = func
end

return RadioBox

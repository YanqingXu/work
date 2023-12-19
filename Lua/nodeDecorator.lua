-- 创建节点装饰器类(主要用于调试)
-- 用于在节点执行完操作以后，某些属性变化时，通过拦截器触发自定义事件
-- 用法：
--     targetNode = NodeDecorator:new(targetNode, tolua.type(targetNode), eventName)
-- 注意：对于尚未addChild的节点需要在addChild时传入原生节点node，如 parent:addChild(targetNode.node)
--      另外，其他在用原生节点的时候也需传入原生节点，如ccui.Helper:seekWidgetByName(targetNode.node, widgetName)
NodeDecorator = {}
NodeEventName = {
    SIZE_ChANGED = "size-changed",
    SCALE_CHANGED = "scale-changed",
    OPACITY_CHANGED = "opacity-changed",
    ROTATION_CHANGED = "rotation-changed",
    POSITION_CHANGED = "position-changed",
}

local nodeLikes = {
    ["cc.Node"] = cc.Node,
    ["ccui.Widget"] = ccui.Widget,
    ["cc.Sprite"] = cc.Sprite,
    ["ccui.Scale9Sprite"] = ccui.Scale9Sprite,
    ["ccui.ImageView"] = ccui.ImageView,
    ["ccui.Text"] = ccui.Text,
    ["ccui.TextAtlas"] = ccui.TextAtlas,
    ["ccui.TextBMFont"] = ccui.TextBMFont,
    ["ccui.LoadingBar"] = ccui.LoadingBar,
    ["ccui.Slider"] = ccui.Slider,
    ["ccui.TextField"] = ccui.TextField,
    ["ccui.Button"] = ccui.Button,
    ["ccui.CheckBox"] = ccui.CheckBox,
    ["ccui.Layout"] = ccui.Layout,
    ["ccui.ScrollView"] = ccui.ScrollView,
    ["ccui.ListView"] = ccui.ListView,
    ["ccui.PageView"] = ccui.PageView,
}

local mapSelfKey = {
    "node",
    "eventNames",
    "oldSize",
    "oldScale",
    "oldOpacity",
    "oldRotation",
    "oldPosition",
    "dispatchEvent",
}

-- node方法拦截
local function funcInterceptor(obj, funcName, ...)
    if tolua.isnull(obj.node) then
        print("error---------->  funcInterceptor: node is null...")
        return
    end

    -- 调用node原始方法
    local results = { obj.node[funcName](obj.node, ...) }
    local firstResult = results[1]

    if tolua.isnull(obj.node) then
        return
    end

    -- 检测判断触发自定义事件
    local newSize = obj.node:getContentSize()
    local newScale = obj.node:getScale()
    local newOpacity = obj.node:getOpacity()
    local newRotation = obj.node:getRotation()
    local newPosition = cc.p(obj.node:getPosition())

    if obj.oldSize then
        if obj.oldSize.width ~= newSize.width or obj.oldSize.height ~= newSize.height then
            obj:dispatchEvent(NodeEventName.SIZE_ChANGED)
        end
    end

    if obj.oldScale and obj.oldScale ~= newScale then
        obj:dispatchEvent(NodeEventName.SCALE_CHANGED)
    end

    if obj.oldOpacity and obj.oldOpacity ~= newOpacity then
        obj:dispatchEvent(NodeEventName.OPACITY_CHANGED)
    end

    if obj.oldRotation and obj.oldRotation ~= newRotation then
        obj:dispatchEvent(NodeEventName.ROTATION_CHANGED)
    end

    if obj.oldPosition then
        if obj.oldPosition.x ~= newPosition.x or obj.oldPosition.y ~= newPosition.y then
            obj:dispatchEvent(NodeEventName.POSITION_CHANGED)
        end
    end

    -- 返回node原始方法的返回值
    if firstResult then
        return unpack(results)
    end
end

-- 重写index元方法
local function metaIndex(obj, key)
    if table.indexof(mapSelfKey, key) then
        return rawget(obj, key)
    end

    local value = obj.node[key]
    if value then
        if type(value) ~= "function" then
            return value
        end

        return function(t, ...)
            return funcInterceptor(t, key, ...)
        end
    end
end

-- 重写newindex元方法
local function metaNewIndex(obj, key, value)
    if table.indexof(mapSelfKey, key) then
        rawset(obj, key, value)
        return
    end

    if type(value) == "function" then
        rawset(obj, key, value)
        return
    end

    obj.node[key] = value
end

-- 构造函数
function NodeDecorator:new(node, nodeLike, ...)
    if not node or tolua.isnull(node) then
        print("error---------->  NodeDecorator: node is null...")
        return
    end

    nodeLike = nodeLikes[nodeLike]
    if not nodeLike then
        print("error---------->  NodeDecorator: nodeLike is not a node...")
        return node
    end

    local obj = {}

    for funcName, funcPtr in pairs(self) do
        if type(funcPtr) == "function" then
            if funcName ~= "new" then
                obj[funcName] = funcPtr
            end
        end
    end

    local nodeMt = getmetatable(nodeLike)
    local metaTable = DeepCopy(nodeMt)
    setmetatable(obj, metaTable)

    -- 属性拦截
    getmetatable(obj).__index = metaIndex
    getmetatable(obj).__newindex = metaNewIndex

    obj.node = node
    obj.eventNames = { ... }

    if #obj.eventNames == 0 then
        obj.eventNames = {
            NodeEventName.SIZE_ChANGED,
            NodeEventName.SCALE_CHANGED,
            NodeEventName.OPACITY_CHANGED,
            NodeEventName.ROTATION_CHANGED,
            NodeEventName.POSITION_CHANGED
        }
    end

    -- 记录node原始的属性值
    obj.oldSize = node:getContentSize()
    obj.oldScale = node:getScale()
    obj.oldOpacity = node:getOpacity()
    obj.oldRotation = node:getRotation()
    obj.oldPosition = cc.p(node:getPosition())

    -- 注册事件监听器
    local eventDispatcher = api_scene.scene:getEventDispatcher()

    for _, eventName in ipairs(obj.eventNames) do
        local customListener = cc.EventListenerCustom:create(eventName, function(event)
            if tolua.isnull(obj.node) then
                return
            end

            print("----------> NodeDecorator: node event " .. eventName .. " is triggered...")
        end)
        eventDispatcher:addEventListenerWithFixedPriority(customListener, 1)
    end

    return obj
end

-- 触发自定义事件的方法
function NodeDecorator:dispatchEvent(eventName)
    if not table.indexof(self.eventNames, eventName) then
        return
    end

    local event = cc.EventCustom:new(eventName)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    eventDispatcher:dispatchEvent(event)
end

return NodeDecorator

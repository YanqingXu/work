local _ui = {}
_ui.__index = _ui

function _ui.new(uid, nodes)
    local self = setmetatable({}, _ui)
    self.uid = uid
    self.ui = api_ui:getPanel(uid)

    if not nodes then
        self:traverseNode(self.ui)
    elseif type(nodes) == "table" then
        self:traverseNode(self.ui, "", nodes)
    end

    return self
end

--- 遍历节点
-- @param node 根节点
-- @param parentName 父节点名称
-- @param nodes 若传入nodes，则只会绑定nodes的节点
function _ui:traverseNode(node, parentName, nodes)
    local children = node:getChildren()

    for i, child in ipairs(children) do
        local name = child:getName()
        if name ~= "" then
            -- 检查是否已经有同名的节点
            if self[name] then
                -- 如果提供了parentName，则将其用作前缀
                if parentName and parentName ~= "" then
                    name = parentName .. "_" .. name
                end
            end

            -- 将处理过的节点存入table
            if not nodes then
                self[name] = child
            elseif nodes[name] then
                self[nodes[name]] = child
            end
        end

        -- 递归遍历子节点，传递当前节点的名字作为parentName
        local childName = child:getName()
        if parentName and parentName ~= "" and childName ~= "" then
            childName = parentName .. "_" .. childName
        end

        self:traverseNode(child, childName, nodes)
    end
end

-- 辅助数据
function _ui:bindData()
    print("bindData from UIBase.lua, you should override this function")
end

-- 绑定组件，可配合nodes使用
function _ui:bindComponent()
    print("bindComponent from UIBase.lua, you should override this function")
end

-- 绑定按钮事件
function _ui:bindEvent()
    print("bindEvent from UIBase.lua, you should override this function")
end

-- 绑定消息
function _ui:bindMsg()
    print("bindMsg from UIBase.lua, you should override this function")
end

-- 初始化界面
function _ui:initView()
    print("initView from UIBase.lua, you should override this function")
end

function _ui:init()
    self:bindData()
    self:bindComponent()
    self:bindEvent()
    self:bindMsg()
    self:initView()
end

return _ui

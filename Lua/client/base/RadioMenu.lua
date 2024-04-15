---@diagnostic disable: duplicate-set-field
local RadioMenu = class("RadioMenu")

function RadioMenu:ctor(lv)
    self.lv_menu = lv
    self.handler = nil
    self.select = nil
    self.canRepeat = false --当已选中的按钮被重复点击时是否要触发事件
end

--@function 添加一个菜单
--@param key 按钮对应的key 整型
--@param data 按钮对应的名字 字体大小 颜色
--@param selected 当前按钮是否要默认选中
function RadioMenu:addItem(key, data, selected)
    local layer = ccui.Layout:create()
    local img_common = ccui.ImageView:create()
    local img_select = ccui.ImageView:create()
    local lbl_name = cc.Label:create()
    local color2 = data.color2 or GAME_COLOR.White                                --选中的字颜色
    local color1 = data.color1 or GAME_COLOR.White                                --未选中字颜色

    api_rui:createImage(data.uid, "imgCommon", img_common, "small/lycq_kfhd11.png") --暗
    img_common:setAnchorPoint(cc.p(0, 0))
    img_common:setName("img_common")
    img_common:setVisible(true)

    api_rui:createImage(data.uid, "imgSelect", img_select, "small/lycq_kfhd11.png") --亮
    img_select:setAnchorPoint(cc.p(0, 0))
    img_select:setName("img_select")
    img_select:setVisible(false)

    layer:setContentSize(img_common:getContentSize().width, img_common:getContentSize().height)

    lbl_name:setString(data.name)
    lbl_name:setColor(data.color1 or GAME_COLOR.White)


    setTTFFontSize(lbl_name, data.size or 24)
    lbl_name:setAnchorPoint(cc.p(0.5, 0.5))
    lbl_name:setPosition(layer:getContentSize().width / 2, layer:getContentSize().height / 2)

    layer:addChild(img_common)
    layer:addChild(img_select)
    layer:addChild(lbl_name)
    layer:setTag(key)
    layer:setTouchEnabled(true)

    local function onSelcetMenu(sender, eventType)
        if not sender or eventType ~= ccui.TouchEventType.ended then
            return
        end

        local img = ccui.Helper:seekWidgetByName(sender, "img_select")
        if img:isVisible() and not self.canRepeat then
            return
        end

        self:selectItem(sender:getTag(), color1, color2)
    end
    layer:addTouchEventListener(onSelcetMenu)

    self.lv_menu:pushBackCustomItem(layer)

    if selected then
        self:selectItem(key, color1, color2)
    end
end

--@function 选中一个菜单
--@param key 按钮对应的key 整型
--@param selected 当前按钮是否要默认选中
--@param col1 未选中字颜色
--@param col2  选中后字颜色
function RadioMenu:selectItem(key, col1, col2)
    local unselcetColor = col1 or GAME_COLOR.White
    local selectColor = col2 or GAME_COLOR.White
    local layer = self.lv_menu:getChildByTag(key)
    if not layer then
        return
    end

    local success = nil
    if self.handler then
        success = self.handler(key)
    end

    if success ~= nil and not success then
        return
    end

    if self.select then
        local lastLayer = self.lv_menu:getChildByTag(self.select)
        if not lastLayer then
            return
        end

        ccui.Helper:seekWidgetByName(lastLayer, "img_select"):setVisible(false)
        lastLayer:getChildren()[3]:setColor(unselcetColor)
        ccui.Helper:seekWidgetByName(lastLayer, "img_common"):setVisible(true)
    end

    self.select = key
    ccui.Helper:seekWidgetByName(layer, "img_select"):setVisible(true)
    layer:getChildren()[3]:setColor(selectColor)
    ccui.Helper:seekWidgetByName(layer, "img_common"):setVisible(false)
end

--@function 设置外部回调函数
function RadioMenu:setHandler(func)
    self.handler = func
end

--@function 设置是否可以重复点击
function RadioMenu:setCanRepeat(bol)
    self.canRepeat = bol
end

--@function 获取当前选中的KEY
function RadioMenu:getSelect()
    return self.select
end

--@function 获取当前获取layer
--@param key 按钮对应的key 整型
function RadioMenu:getItem(key)
    return self.lv_menu:getChildByTag(key)
end

function RadioMenu:remove()
    self.handler = nil
    self.select = nil
end

return RadioMenu

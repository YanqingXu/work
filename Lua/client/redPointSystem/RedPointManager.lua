module("RedPointMgr", package.seeall)
local EffectSprite = require("xf.engine.ui.EffectSprite")

local RuleTable = {}
local QueueID = {}
local timerID = nil
local time = 0.05
local imgSrc = "small/beibaotishi2.png"

-- 设置控件红点 control:红点所在控件，bShow:是否显示红点
local function setControlRedPoint(control, bShow, listId)
	if not control then
		return
	end
	if tolua.isnull(control) then
		RedPointMgr.removeRedPoint(listId, control)
		print("auto release redpoint:", listId)
		return
	end
	-- control:retain()
	if not control.RedPoint then
		if listId == LIST.PROMOTE then
			control.RedPoint = control
		else
			control.RedPoint = ccui.ImageView:create()
			api_rui:loadImageTexture(control.RedPoint, imgSrc)
			control.RedPoint:setLocalZOrder(10000)
			control:addChild(control.RedPoint)
			local size = control:getContentSize()
			if control.rpx and control.rpy then
				control.RedPoint:setPosition(size.width - control.rpx, size.height - control.rpy)
			else
				if control.rpw and control.rph then
					control.RedPoint:setPosition(control.rpw - 15, control.rph - 15)
				else
					control.RedPoint:setPosition(size.width - 15, size.height - 15)
				end
			end
		end
	end
	-- if not control.RedPoint then
	-- 	return
	-- end
	-- if control.showEff then
	-- 	local function refeff()
	-- 		if control.effani then
	-- 			control.effani:setVisible(bShow)
	-- 			return
	-- 		end
	-- 		if bShow then
	-- 			control.effani = EffectSprite:new()
	-- 			control.effani:init(83 ,EFFECTRULE.REPLAY)
	-- 			control.effani:attach(control)
	-- 			control.effani:setEffectToCenter()
	-- 		end
	-- 	end
	-- 	refeff()
	-- end
	control.RedPoint:setVisible(bShow)
end

-- 条件函数
condFunction = {}

-- 判断开关
condFunction[CONDITION.SWITCH] = function(switch_id)
	if not MySwitchManager:isSwitchEnabled(switch_id) then
		return false
	end

	return true
end

-- 判断开服天数
condFunction[CONDITION.SERVER_DAY] = function(server_day)
	if gdServerDays < server_day then
		return false
	end

	return true
end

-- 判断VIP等级
condFunction[CONDITION.VIP] = function(vip)
	if MyRole.getProp(ENTITY_PROP_VIP_LEVEL) < vip then
		return false
	end

	return true
end

-- 判断玩家等级
condFunction[CONDITION.LV] = function(lv)
	if MyRole.getLevel() < lv then
		return false
	end

	return true
end

-- 判断玩家转生等级
condFunction[CONDITION.REBORN] = function(reborn)
	if MyRole.getProp(ENTITY_PROP_REBORN) < reborn then
		return false
	end

	return true
end


condFunction[CONDITION.QUEST] = function(q_id)
	local qid = MyTaskData:getMainTaskID()
	if qid < 0 then
		return true
	end
	if qid >= q_id then
		return true
	end

	return false
end

-- 条件判断
local function condition(list_id)
	if not list_id then
		return false
	end
	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return false
	end

	local cond = RED_POINT_RULE[list_id]
	if not cond then
		return false
	end

	-- 跨服没有红点
	if MyRole.isInCrossScene() then
		return false
	end

	for k, v in pairs(cond) do
		if "function" == type(v) then
			-- 判断是否是条件规则中的函数
			if not cond[k]() then
				return false
			end
		else
			-- 直接判断某个条件数值是否满足条件
			if not condFunction[k] then
				return false
			end
			if not condFunction[k](v) then
				return false
			end
		end
	end

	return true
end

-- 判断是否有红点
function canShowRedPoint(list_id)
	if not list_id then
		return false
	end
	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return false
	end

	-- 先判断是否组合结构
	local rule_compose = RULE_COMPOSE[list_id]
	if rule_compose then
		for i = 1, #rule_compose do
			if canShowRedPoint(rule_compose[i]) then
				return true
			end
		end

		return false
	end

	local id_data = RED_POINT_RULE[list_id]
	if not id_data then
		return false
	end

	return condition(list_id)
end

-- list_id : 红点列表ID ,bShow ：是否显示红点
local function setRedPoint(list_id, bShow)
	if not list_id then
		return
	end
	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return
	end
	for k, v in ipairs(RuleTable) do
		if v.ID == list_id then
			if v.CTRL then
				setControlRedPoint(v.CTRL, bShow, list_id)
			end
		end
	end
end

-- 取队列第一个元素(红点 列表ID 队列)
QueueID.front = function()
	if #QueueID <= 0 then
		return nil
	end

	return QueueID[1].ID
end

local function TimerHandleQueueID()
	for i = 1, 100, 1 do
		local id = QueueID.front()
		if id then
			local bShow = canShowRedPoint(id)
			setRedPoint(id, bShow)
			table.remove(QueueID, 1)
		else
			break
		end
	end

	if QueueID.front() then
		return
	end

	if not timerID then
		return
	end

	api_schedule:unRegisterSchedule("RedPointManagerSchedule", timerID)
	timerID = nil
end

-- 查找数据
QueueID.find = function(list_id)
	if not list_id then
		return false
	end

	for k, v in ipairs(QueueID) do
		if v.ID == list_id then
			return true
		end
	end

	return false
end

local function refreshCompose(list_id)
	for k, v in pairs(RULE_COMPOSE) do
		for _, vv in ipairs(v) do
			if list_id == vv then
				refreshRedPoint(k)
				break
			end
		end
	end
end

-- 刷新红点（塞入红点等待刷新队列）
function refreshRedPoint(list_id)
	if not list_id then
		return
	end
	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return
	end
	if QueueID.find(list_id) then
		return
	end
	refreshCompose(list_id)
	table.insert(QueueID, { ID = list_id })
	if timerID then
		return
	end
	timerID = api_schedule:registerSchedule("RedPointManagerSchedule", time, TimerHandleQueueID)
end

-- 查找数据
RuleTable.find = function(list_id, control)
	if not list_id or not control then
		return nil
	end

	for k, v in ipairs(RuleTable) do
		if v.ID == list_id and v.CTRL == control then
			return k
		end
	end

	return nil
end


-- 查找数据
RuleTable.findAll = function(list_id)
	if not list_id then
		return nil
	end

	for k, v in ipairs(RuleTable) do
		if v.ID == list_id then
			return k
		end
	end

	return nil
end

RuleTable.findByControl = function(control)
	if not control then
		return nil
	end
	for k, v in ipairs(RuleTable) do
		if v.CTRL == control then
			return k
		end
	end
	return nil
end

-- 新增刷新
function addRedPoint(list_id, control)
	if not list_id or not control then
		return
	end

	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return
	end

	local k = RuleTable.find(list_id, control)
	if not k then
		table.insert(RuleTable, { ID = list_id, CTRL = control })
	end

	refreshRedPoint(list_id)
end

-- 移除刷新
function removeRedPoint(list_id, control)
	if not list_id or not control then
		return
	end

	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return
	end

	local k = RuleTable.find(list_id, control)
	if not k then
		return
	end

	refreshRedPoint(list_id)
	table.remove(RuleTable, k)
end

-- 移除刷新
function removeAllRedPoint(list_id)
	if not list_id then
		return
	end

	if list_id <= LIST.NONE or list_id >= LIST.MAX then
		return
	end

	local k = RuleTable.findAll(list_id)
	if not k then
		return
	end

	refreshRedPoint(list_id)
	table.remove(RuleTable, k)
end

function refreshRedPointByCondition(type, id)
	local list = nil
	if type == REFRESH_RULE.PLAYER_LEVEL or type == REFRESH_RULE.SERVER_DAY then
		list = REFRESH_RULE_LIST[type]
	else
		list = REFRESH_RULE_LIST[type][id]
	end
	if list then
		for i, v in ipairs(list) do
			refreshRedPoint(v)
		end
	end
end

-- 刷新红点位置
function refreshRedPointPos(listId, control)
	if not listId or not control then
		return
	end

	if listId <= LIST.NONE or listId >= LIST.MAX then
		return
	end

	if not control.RedPoint then
		return
	end

	local size = control:getContentSize()
	control.RedPoint:setPosition(size.width - control.rpx, size.height - control.rpy)
end
--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：战斗状态机
******************************************************************************************
]]

----------------------------------------------------------------------------------------------------------------------------------------------

--攻击

----------------------------------------------------------------------------------------------------------------------------------------------
StateThisAttack = class("StateThisAttack")

function StateThisAttack:ctor()
	self.mHost = nil
	self.mState = false
	self.magState = ATTACKK_STATE.begin
end

function StateThisAttack:setHost(host)
	self.mHost = host
end

function StateThisAttack:getID()
	return ALIVER_STATE.ATTACK
end

function StateThisAttack:onEnter()
	CMonitor.perf_log_begin("StateThisAttack::onEnter")
	self.magState = ATTACKK_STATE.run

	--进入攻击状态，显示血条、能量、名字
	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	--实体状态机
	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.ATTACK)

	--播放技能动画
	if stateInfo.skillType then
		api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
			stateInfo.y)
		local skillSound = gdSkills[stateInfo.skillType]["sound"]
		api_audio:play(skillSound)
	end
	self.mHost:getEntitySprite():stopActionByTag(22222)

	self.mState = true
	-- 攻击动作（没有技能特效）
	self.mHost:getCloth():runAnimation()

	local acceleration = 1 / (MyRole.entity:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5])

	--注册动作中事件
	local actionTimeTable = {}
	local actionTime = ATTACK_ACTION_DURATION * acceleration / 1.5
	local time = cc.Sequence:create(cc.DelayTime:create(actionTime),
		cc.CallFunc:create(handler(self, self.attackIsControl)))
	table.insert(actionTimeTable, time)

	time = cc.Sequence:create(cc.DelayTime:create(acceleration),
		cc.CallFunc:create(handler(self, self.attackNextState)))
	table.insert(actionTimeTable, time)

	local actionTimes = ZorderHelper.attack_time[1]
	if actionTimes then
		for k, v in pairs(actionTimes) do
			local time = cc.Sequence:create(cc.DelayTime:create((k / 10) * acceleration),
				cc.CallFunc:create(handler(self, self.changeAtkOrder), { ALIVER_STATE.ATTACK, stateInfo.actioncode, k }))
			table.insert(actionTimeTable, time)
		end
	end

	--调整装备的播放速率
	local delaytime = 3
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)

	CMonitor.perf_log_end("StateThisAttack::onEnter")
end

function StateThisAttack:onExit()
	self.magState = ATTACKK_STATE.over
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StateThisAttack:onUpdate(elaspe)
	if self.magState < ATTACKK_STATE.canMove then
		return
	end
	if self.magState >= ATTACKK_STATE.canMove then
		if MyRole.mAIMouseSequence and MyRoleHelper.executeMouseSequence(true) then
			self:stateEnd()
			return
		end
	end
	if self.magState >= ATTACKK_STATE.playState then
		if self.mHost:getState():getStateLength() > 1 or MyRole.mAIAutoAttack or MyRole.mAIEasy then
			self:stateEnd()
			return
		elseif MyRole.mTempSkill > 0 then
			self:stateEnd()
			return
		elseif MyRole.mLockSkill > 0 then
			self:stateEnd()
			return
		elseif MyRole.mAIAutoMove then
			self:stateEnd()
			return
		elseif MyRole.mAIMouseSequence then
			self:stateEnd()
			return
		end
	end
end

function StateThisAttack:changeAtkOrder(ghost, data)
	local orderIndo = ZorderHelper.getStatingOrder(self.mHost, data[1], data[2], data[3])
	if orderIndo then
		self.mHost:getCloth():setOrderTable(orderIndo)
	end
end

function StateThisAttack:attackIsControl()
	self.magState = ATTACKK_STATE.canMove
end

function StateThisAttack:attackNextState()
	self.magState = ATTACKK_STATE.playState
end

function StateThisAttack:stateEnd()
	self.magState = ATTACKK_STATE.over
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	StateHelper.mainRoleNextState()
end

----------------------------------------------------------------------------------------------------------------------------------------------

--施法

----------------------------------------------------------------------------------------------------------------------------------------------

StateThisMagic = class("StateThisMagic")

function StateThisMagic:ctor()
	self.mHost    = nil
	self.mState   = false
	self.magState = ATTACKK_STATE.begin
end

function StateThisMagic:setHost(host)
	self.mHost = host
end

function StateThisMagic:getID()
	return ALIVER_STATE.MAGIC
end

function StateThisMagic:onEnter()
	CMonitor.perf_log_begin("StateThisAttack::onEnter")
	local acceleration = 1 / (MyRole.entity:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)
	self.magState = ATTACKK_STATE.run

	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.MAGIC)
	if stateInfo.skillType then
		api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
			stateInfo.y)
		local skillSound = gdSkills[stateInfo.skillType]["sound"]
		api_audio:play(skillSound)
	end

	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mState = true
	self.mHost:getCloth():runAnimation()

	--注册动作中事件
	local actionTimeTable = {}
	local actionTime = M_ATTACK_CONTROL_DURATION * acceleration / 1.6
	local time = cc.Sequence:create(cc.DelayTime:create(actionTime),
		cc.CallFunc:create(handler(self, self.attackIsControl)))
	table.insert(actionTimeTable, time)

	time = cc.Sequence:create(cc.DelayTime:create(M_ATTACK_ACTION_DURATION * acceleration),
		cc.CallFunc:create(handler(self, self.attackNextState)))
	table.insert(actionTimeTable, time)

	local actionTimes = ZorderHelper.attack_time[2]
	if actionTimes then
		for k, v in pairs(actionTimes) do
			local time = cc.Sequence:create(cc.DelayTime:create((k / 10) * acceleration),
				cc.CallFunc:create(handler(self, self.changeAtkOrder), { ALIVER_STATE.MAGIC, stateInfo.actioncode, k }))
			table.insert(actionTimeTable, time)
		end
	end

	--调整装备的播放速率
	local delaytime = 3
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[6] * (1 / acceleration))
	CMonitor.perf_log_end("StateThisAttack::onEnter")
end

function StateThisMagic:onExit()
	self.magState = ATTACKK_STATE.over
	if self.mState then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StateThisMagic:onUpdate(elaspe)
	if self.magState < ATTACKK_STATE.canMove then
		return
	end

	if self.magState >= ATTACKK_STATE.canMove then
		if MyRole.mAIMouseSequence and MyRoleHelper.executeMouseSequence(true) then
			self:stateEnd()
			return
		end
	end

	if self.magState >= ATTACKK_STATE.playState then
		if self.mHost:getState():getStateLength() > 1 or MyRole.mAIAutoAttack or MyRole.mAIEasy then
			self:stateEnd()
			return
		elseif MyRole.mHandSkillId > 0 then
			self:stateEnd()
			return
		elseif MyRole.mTempSkill > 0 then
			self:stateEnd()
			return
		elseif MyRole.mLockSkill > 0 then
			self:stateEnd()
			return
		elseif MyRole.mAIAutoMove then
			self:stateEnd()
			return
		elseif MyRole.mAIMouseSequence then
			self:stateEnd()
			return
		end
	end
end

function StateThisMagic:attackIsControl()
	self.magState = ATTACKK_STATE.canMove
end

function StateThisMagic:attackNextState()
	self.magState = ATTACKK_STATE.playState
end

function StateThisMagic:changeAtkOrder(ghost, data)
	local orderIndo = ZorderHelper.getStatingOrder(self.mHost, data[1], data[2], data[3])
	if orderIndo then
		self.mHost:getCloth():setOrderTable(orderIndo)
	end
end

function StateThisMagic:stateEnd()
	self.magState = ATTACKK_STATE.over
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	StateHelper.mainRoleNextState()
end

----------------------------------------------------------------------------------------------------------------------------------------------

--挖矿

----------------------------------------------------------------------------------------------------------------------------------------------
StateThisMining = class("StateThisMining")

function StateThisMining:ctor()
	self.mHost = nil
end

function StateThisMining:setHost(host)
	self.mHost = host
end

function StateThisMining:getID()
	return ALIVER_STATE.MINING
end

function StateThisMining:onEnter()
	self.mHost:getEntitySprite():stopActionByTag(22222)

	-- if isMining then
	self.mHost:getCloth():setMiningState(true)
	-- else
	--     self:setMiningState(false)
	-- end
	MyRole.misgather = true

	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.MINING)

	-- 攻击动作（没有技能特效）
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5])

	--注册动作中事件
	local actionTimeTable = {}

	--调整装备的播放速率
	local delaytime = 0.8
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.rePlay)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
end

function StateThisMining:onExit()
	playerRequest.FunDataOperator(FUNC_UPDATE_PLAYER_PROP, ENTITY_PROP_MINING_STATE, 0)
	MyRole.misgather = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():setMiningState(false)
end

function StateThisMining:rePlay()
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():runAnimation()

	--注册动作中事件
	local actionTimeTable = {}

	--调整装备的播放速率
	local delaytime = 0.8
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.rePlay)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
end

function StateThisMining:onUpdate(elaspe)
	if MyRole.mAIMouseSequence then
		self:stateEnd()
		return
	elseif MyRole.mTempSkill > 0 then
		self:stateEnd()
		return
	elseif MyRole.mLockSkill > 0 then
		self:stateEnd()
		return
	elseif MyRole.mAIAutoMove then
		self:stateEnd()
		return
	elseif MyRole.mAIAutoAttack then
		self:stateEnd()
		return
	end
end

function StateThisMining:stateEnd()
	playerRequest.FunDataOperator(FUNC_UPDATE_PLAYER_PROP, ENTITY_PROP_MINING_STATE, 0)
	MyRole.misgather = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():setMiningState(false)
	StateHelper.mainRoleNextState()
end

----------------------------------------------------------------------------------------------------------------------------------------------

--攻击

----------------------------------------------------------------------------------------------------------------------------------------------

StatePlayerAttack = class("StatePlayerAttack")

function StatePlayerAttack:ctor()
	self.mHost    = nil
	self.mState   = false
	self.magState = ATTACKK_STATE.begin
end

function StatePlayerAttack:setHost(host)
	self.mHost = host
end

function StatePlayerAttack:getID()
	return ALIVER_STATE.ATTACK
end

function StatePlayerAttack:onEnter()
	CMonitor.perf_log_begin("StatePlayerAttack::onEnter")
	self.magState = ATTACKK_STATE.run

	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	local delaytime = 1.0

	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.ATTACK)
	if stateInfo.skillType then
		api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
			stateInfo.y)
		delaytime = 0.7
		local skillSound = gdSkills[stateInfo.skillType]["sound"]
		api_audio:play(skillSound)
	end
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mState = true
	self.mHost:getCloth():runAnimation()

	--调整装备的播放速率
	delaytime = 3

	--注册动作中事件
	local actionTimeTable = {}
	local acceleration = 1 / (self.mHost:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)
	local time = cc.Sequence:create(cc.DelayTime:create(ATTACK_ACTION_DURATION * acceleration),
		cc.CallFunc:create(handler(self, self.attackIsControl)))
	table.insert(actionTimeTable, time)
	time = cc.Sequence:create(cc.DelayTime:create(1.2 * acceleration),
		cc.CallFunc:create(handler(self, self.attackNextState)))
	table.insert(actionTimeTable, time)

	local actionTimes = ZorderHelper.attack_time[1]
	if actionTimes then
		for k, v in pairs(actionTimes) do
			local time = cc.Sequence:create(cc.DelayTime:create((k / 10) * acceleration),
				cc.CallFunc:create(handler(self, self.changeAtkOrder),
					{ ALIVER_STATE.ATTACK, stateInfo.actioncode, k }))
			table.insert(actionTimeTable, time)
		end
	end

	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5])
	CMonitor.perf_log_end("StatePlayerAttack::onEnter")
end

function StatePlayerAttack:onExit()
	self.magState = ATTACKK_STATE.over
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StatePlayerAttack:changeAtkOrder(ghost, data)
	local orderIndo = ZorderHelper.getStatingOrder(self.mHost, data[1], data[2], data[3])
	if orderIndo then
		self.mHost:getCloth():setOrderTable(orderIndo)
	end
end

function StatePlayerAttack:onUpdate(elaspe)
	if self.magState < ATTACKK_STATE.canMove then
		return
	end

	if self.magState >= ATTACKK_STATE.canMove then
		if self.mHost:getState():getStateLength() > 1 then
			self:stateEnd()
			return
		end
	end
end

function StatePlayerAttack:attackIsControl()
	self.magState = ATTACKK_STATE.canMove
end

function StatePlayerAttack:attackNextState()
	self.magState = ATTACKK_STATE.playState
end

function StatePlayerAttack:stateEnd()
	self.magState = ATTACKK_STATE.over
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	StateHelper.ghostNextState(self.mHost)
end

----------------------------------------------------------------------------------------------------------------------------------------------

--施法

----------------------------------------------------------------------------------------------------------------------------------------------


StatePlayerMagic = class("StatePlayerMagic")

function StatePlayerMagic:ctor()
	self.mHost    = nil
	self.mState   = false
	self.magState = ATTACKK_STATE.begin
end

function StatePlayerMagic:setHost(host)
	self.mHost = host
end

function StatePlayerMagic:getID()
	return ALIVER_STATE.MAGIC
end

function StatePlayerMagic:onEnter()
	CMonitor.perf_log_begin("StatePlayerMagic::onEnter")
	self.magState = ATTACKK_STATE.run
	local acceleration = 1 / (self.mHost:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)
	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible and isVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.MAGIC)
	if stateInfo.skillType then
		api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
			stateInfo.y)
		local skillSound = gdSkills[stateInfo.skillType]["sound"]
		api_audio:play(skillSound)
	end

	self.mHost:getEntitySprite():stopActionByTag(22222)

	self.mState = true
	self.mHost:getCloth():runAnimation()

	--注册动作中事件
	local actionTimeTable = {}
	local time = cc.Sequence:create(cc.DelayTime:create(ATTACK_ACTION_DURATION * acceleration),
		cc.CallFunc:create(handler(self, self.attackIsControl)))
	table.insert(actionTimeTable, time)
	time = cc.Sequence:create(cc.DelayTime:create(1.0 * acceleration),
		cc.CallFunc:create(handler(self, self.attackNextState)))
	table.insert(actionTimeTable, time)

	local actionTimes = ZorderHelper.attack_time[2]
	if actionTimes then
		for k, v in pairs(actionTimes) do
			local time = cc.Sequence:create(cc.DelayTime:create((k / 10) * acceleration),
				cc.CallFunc:create(handler(self, self.changeAtkOrder),
					{ ALIVER_STATE.MAGIC, stateInfo.actioncode, k }))
			table.insert(actionTimeTable, time)
		end
	end

	--调整装备的播放速率
	local delaytime = 3
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[6] * (1 / acceleration))
	CMonitor.perf_log_end("StatePlayerMagic::onEnter")
end

function StatePlayerMagic:onExit()
	self.magState = ATTACKK_STATE.over
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StatePlayerMagic:onUpdate(elaspe)
	if self.magState < ATTACKK_STATE.canMove then
		return
	end

	if self.magState >= ATTACKK_STATE.canMove then
		if self.mHost:getState():getStateLength() > 1 then
			self:stateEnd()
			return
		end
	end
end

function StatePlayerMagic:attackIsControl()
	self.magState = ATTACKK_STATE.canMove
end

function StatePlayerMagic:attackNextState()
	self.magState = ATTACKK_STATE.playState
end 

function StatePlayerMagic:changeAtkOrder(ghost, data)
	local orderIndo = ZorderHelper.getStatingOrder(self.mHost, data[1], data[2], data[3])
	if orderIndo then
		self.mHost:getCloth():setOrderTable(orderIndo)
	end
end

function StatePlayerMagic:stateEnd()
	self.magState = ATTACKK_STATE.over
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	StateHelper.ghostNextState(self.mHost)
end

----------------------------------------------------------------------------------------------------------------------------------------------

--挖矿

----------------------------------------------------------------------------------------------------------------------------------------------
StatePlayerMining = class("StatePlayerMining")

function StatePlayerMining:ctor()
	self.mHost = nil
end

function StatePlayerMining:setHost(host)
	self.mHost = host
end

function StatePlayerMining:getID()
	return ALIVER_STATE.MINING
end

function StatePlayerMining:onEnter()
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():setMiningState(true)

	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.MINING)

	-- 攻击动作（没有技能特效）
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5])

	--注册动作中事件
	local actionTimeTable = {}

	--调整装备的播放速率
	local delaytime = 0.8
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.rePlay)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
end

function StatePlayerMining:onExit()
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():setMiningState(false)
end

function StatePlayerMining:rePlay()
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():runAnimation()

	--注册动作中事件
	local actionTimeTable = {}

	--调整装备的播放速率
	local delaytime = 0.8
	--运行动画
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.rePlay)))
	table.insert(actionTimeTable, sq)
	local sp = cc.Spawn:create(actionTimeTable)
	sp:setTag(22222)
	self.mHost:getEntitySprite():runAction(sp)
end

function StatePlayerMining:onUpdate(elaspe)
	if self.mHost:getState():getStateLength() >= 1 and self.mHost:getState():getStateList()[1].state ~= ALIVER_STATE.MINING then
		self:stateEnd()
		return
	end
end

function StatePlayerMining:stateEnd()
	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mHost:getCloth():setMiningState(false)
	StateHelper.ghostNextState(self.mHost)
end

----------------------------------------------------------------------------------------------------------------------------------------------

--dog

----------------------------------------------------------------------------------------------------------------------------------------------

StateDogAttack = class("StateDogAttack")

function StateDogAttack:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateDogAttack:setHost(host)
	self.mHost = host
end

function StateDogAttack:getID()
	return ALIVER_STATE.ATTACK
end

function StateDogAttack:onEnter()
	CMonitor.perf_log_begin("StateDogAttack::start")
	local entityType = self.mHost:getType()
	local acceleration = 1 / (self.mHost:getProp(ENTITY_PROP_ACCELERATION_ATTACK) / 10000.0 + 1)

	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible and isVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	local delaytime = 0.7 * acceleration
	self.mState = true
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.ATTACK)
	self.mHost:getCloth():runAnimation()

	if stateInfo.skillType then
		api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
			stateInfo.y)
		local skillSound = gdSkills[stateInfo.skillType]["sound"]
		api_audio:play(skillSound)
	end

	self.mHost:getEntitySprite():stopActionByTag(22222)
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime * acceleration),
		cc.CallFunc:create(handler(self, self.stateEnd)))
	sq:setTag(22222)
	self.mHost:getEntitySprite():runAction(sq)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5] * (1 / acceleration))
	CMonitor.perf_log_end("StateDogAttack::start")
end

function StateDogAttack:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StateDogAttack:onUpdate(elaspe)
	--..nothing
end

function StateDogAttack:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
	StateHelper.ghostNextState(self.mHost)
end

----------------------------------------------------------------------------------------------------------------------------------------------

--普通攻击

----------------------------------------------------------------------------------------------------------------------------------------------

StateCommAttack = class("StateCommAttack")

function StateCommAttack:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateCommAttack:setHost(host)
	self.mHost = host
end

function StateCommAttack:getID()
	return ALIVER_STATE.ATTACK
end

function StateCommAttack:onEnter()
	CMonitor.perf_log_begin("StateCommAttack::start")
	local entityType = self.mHost:getType()
	local acceleration = 1 / (self.mHost:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)

	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible and isVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	local delaytime = 0.65 * acceleration

	self.mHost:getEntitySprite():stopActionByTag(22222)
	self.mState = true
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.ATTACK)
	self.mHost:getCloth():runAnimation()

	if entityType == ALIVER_GHOST_TYPE.GHOST_TYPE_MONSTER then
		-- delaytime = self.mHost:isBoss() and 0.6 * delaytime or 1 * delaytime
		delaytime = acceleration / (PLAYER_STATE_FRAME[5] * (1 / acceleration)) * self.mHost:getCloth():getFrames() / 60
	end

	if stateInfo.skillType then
		if MyRole.entityHero ~= nil and MyRole.entityHero:getClientProp(ClientProp.ENTITY_C_EID) == self.mHost:getClientProp(ClientProp.ENTITY_C_EID) then
			--英雄宝宝技能目前缺资源,暂时屏蔽
			-- api_skill:runSkill( stateMac.mHost.mID , stateInfo.skillType , stateInfo.pid , stateInfo.x , stateInfo.y )
		else
			api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
				stateInfo.y)
			local skillSound = gdSkills[stateInfo.skillType]["sound"]
			api_audio:play(skillSound)
		end
	end

	
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	sq:setTag(22222)
	self.mHost:getEntitySprite():runAction(sq)
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[5] * (1 / acceleration))

	CMonitor.perf_log_end("StateCommAttack::start")
end

function StateCommAttack:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StateCommAttack:onUpdate(elaspe)
	--..nothing
end

function StateCommAttack:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)

	if CommonHelper.checkMyHero(self.mHost) then
		CommonHelper.heroNextAction(self.mHost, true);
	else
		StateHelper.ghostNextState(self.mHost)
	end
end

----------------------------------------------------------------------------------------------------------------------------------------------

--宝宝普通攻击

----------------------------------------------------------------------------------------------------------------------------------------------

StateHeroCommAttack = class("StateHeroCommAttack")

function StateHeroCommAttack:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateHeroCommAttack:setHost(host)
	self.mHost = host
end

function StateHeroCommAttack:getID()
	return ALIVER_STATE.ATTACK
end

function StateHeroCommAttack:onEnter()
	CMonitor.perf_log_begin("StateCommAttack::start")
	local entityType = self.mHost:getType()
	local acceleration = 1 / (self.mHost:getCombatData(COMBAT_PROP_ACCELERATION_ATTACK) / 1000.0 + 1)

	if self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM) and not self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM).mVisible and isVisible then
		local showComponet = {}
		showComponet[A_C_TYPE.C_TYPE_NAME] = 1
		showComponet[A_C_TYPE.C_TYPE_BLOOM] = 1
		showComponet[A_C_TYPE.C_TYPE_EXERCISE] = 1
		ComponentHelper.setComponentsVisible(self.mHost, showComponet, true)
	end

	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	local delaytime = 0.65 * acceleration
	if entityType == ALIVER_GHOST_TYPE.GHOST_TYPE_MONSTER then
		delaytime = self.mHost:isBoss() and 0.6 * acceleration or 1 * acceleration
	end

	self.mState = true
	self.mHost:setClientProp(ClientProp.ENTITY_C_STATE, ALIVER_STATE.ATTACK)
	self.mHost:getCloth():runAnimation()

	if stateInfo.skillType then
		if MyRole.entityHero ~= nil and MyRole.entityHero:getClientProp(ClientProp.ENTITY_C_EID) == self.mHost:getClientProp(ClientProp.ENTITY_C_EID) then
			--英雄宝宝技能目前缺资源,暂时屏蔽
			-- api_skill:runSkill( stateMac.mHost.mID , stateInfo.skillType , stateInfo.pid , stateInfo.x , stateInfo.y )
		else
			api_skill:runSkill(stateMac.mHost.mID, stateInfo.skillType, stateInfo.pid, stateInfo.skillLvl, stateInfo.x,
				stateInfo.y)
		end
	end

	self.mHost:getEntitySprite():stopActionByTag(22222)
	local sq = cc.Sequence:create(cc.DelayTime:create(delaytime), cc.CallFunc:create(handler(self, self.stateEnd)))
	sq:setTag(22222)
	self.mHost:getEntitySprite():runAction(sq)
	self.mHost:getCloth():setSpeed(1.4 * (1 / acceleration))

	CMonitor.perf_log_end("StateCommAttack::start")
end

function StateHeroCommAttack:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)
end

function StateHeroCommAttack:onUpdate(elaspe)
	--..nothing
end

function StateHeroCommAttack:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(22222)

	if CommonHelper.checkMyHero(self.mHost) then
		CommonHelper.heroNextAction(self.mHost, true);
	else
		StateHelper.ghostNextState(self.mHost)
	end
end

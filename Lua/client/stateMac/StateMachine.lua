--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：状态机
******************************************************************************************
]]

local StateMachine = class("StateMachine")

require("xf.engine.ghost.stateMac.StateIdle")
require("xf.engine.ghost.stateMac.StateAttack")
require("xf.engine.ghost.stateMac.StateWalkRun")
require("xf.engine.ghost.stateMac.StateDie")

function StateMachine:ctor()
	self:clear()
end

function StateMachine:clear()
	self.mHost     = nil
	self.mCurInfo  = nil
	self.mCurState = nil
	self.mStates   = nil
	self.mMapState = nil
end

function StateMachine:init(host)
	self.mHost = host
	self.mStates = {}
end

function StateMachine:destroy()
	if self.mCurState then
		self.mCurState:onExit()
	end

	self:clear()
end

function StateMachine:getStateList()
	return self.mStates
end

function StateMachine:getCurState()
	return self.mCurState
end

function StateMachine:getCurInfo()
	return self.mCurInfo
end

function StateMachine:setStateInfo(stateInfo)
	self.mCurInfo = stateInfo
end

function StateMachine:addState(stateInfo)
	table.insert(self.mStates, stateInfo)
end

function StateMachine:popState()
	if #self.mStates == 0 then return end
	table.remove(self.mStates, 1)
end

function StateMachine:popEndState()
	table.remove(self.mStates, #self.mStates)
end

function StateMachine:getStateLength()
	return #self.mStates
end

function StateMachine:clearAllState()
	self.mStates = {}
end

function StateMachine:update(elaspe)
	if self.mCurState then
		self.mCurState:onUpdate(elaspe)
	end
end

function StateMachine:setState(stateid)
	if self.mCurState then
		self.mCurState:onExit()
		self.mCurState = nil
	end

	self.mCurState = self:createState(stateid)
	if not self.mCurState then
		return
	end

	self.mCurState:setHost(self.mHost)
	if self.mCurState then
		self.mCurState:onEnter()
	end
end

function StateMachine:initState()
	local function getMonsterWalkOrRunState()
		if not self.mHost then
			return
		end

		local monInfo = gdMonsters[self.mHost:getClientProp(ClientProp.ENTITY_C_STATICID)]
		local isMonsterRun = false
		if monInfo and monInfo.isHuman == 3 then
			isMonsterRun = true
		end

		if gdZTTQuest[self.mHost:getClientProp(ClientProp.ENTITY_C_STATICID)] then
			isMonsterRun = true
		end

		if isMonsterRun then
			return StateCommRun.new()
		else
			return StateCommWalk.new()
		end
	end

	local mapState = {
		[ALIVER_GHOST_TYPE.GHOST_TYPE_THIS] = {
			[1] = {
				[ALIVER_STATE.IDLE] = StatePlayerIdle.new(),
				[ALIVER_STATE.WALK] = StateCommRun.new(),
				[ALIVER_STATE.RUN] = StateCommRun.new(),
				[ALIVER_STATE.ATTACK] = StatePlayerAttack.new(),
				[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
				[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
				[ALIVER_STATE.DIE] = StatePlayerDie.new(),
			},
			[2] = {
				[ALIVER_STATE.IDLE] = StateThisIdle.new(),
				[ALIVER_STATE.ATTACK] = StateThisAttack.new(),
				[ALIVER_STATE.MAGIC] = StateThisMagic.new(),
				[ALIVER_STATE.WALK] = StateThisWalk.new(),
				[ALIVER_STATE.RUN] = StateThisRun.new(),
				[ALIVER_STATE.COLLIDE] = StateThisCollide.new(),
				[ALIVER_STATE.DIE] = StateThisDie.new(),
				[ALIVER_STATE.MINING] = StateThisMining.new(),
			},
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER] = {
			[ALIVER_STATE.IDLE] = StatePlayerIdle.new(),
			[ALIVER_STATE.WALK] = StateCommWalk.new(),
			[ALIVER_STATE.RUN] = StateCommRun.new(),
			[ALIVER_STATE.ATTACK] = StatePlayerAttack.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
			[ALIVER_STATE.DIE] = StatePlayerDie.new(),
			[ALIVER_STATE.MINING] = StatePlayerMining.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_NPC] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_MONSTER] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.WALK] = getMonsterWalkOrRunState(),
			[ALIVER_STATE.RUN] = getMonsterWalkOrRunState(),
			[ALIVER_STATE.ATTACK] = StateCommAttack.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_SLAVE] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.WALK] = StateCommRun.new(),
			[ALIVER_STATE.RUN] = StateCommRun.new(),
			[ALIVER_STATE.ATTACK] = StateDogAttack.new(),
			[ALIVER_STATE.MAGIC] = StateDogAttack.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER_CLONE] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.WALK] = StateCommRun.new(),
			[ALIVER_STATE.RUN] = StateCommRun.new(),
			[ALIVER_STATE.ATTACK] = StatePlayerMagic.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER_SHADOW] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.WALK] = StateCommRun.new(),
			[ALIVER_STATE.RUN] = StateCommRun.new(),
			[ALIVER_STATE.ATTACK] = StatePlayerMagic.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateShadowCollide.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_MARS] = {
			[ALIVER_STATE.IDLE] = StateCommIdle.new(),
			[ALIVER_STATE.WALK] = StateCommRun.new(),
			[ALIVER_STATE.RUN] = StateCommRun.new(),
			[ALIVER_STATE.ATTACK] = StateCommAttack.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_HERO] = {
			[ALIVER_STATE.IDLE] = StateHeroIdle.new(),
			[ALIVER_STATE.WALK] = StateHeroCommRun.new(),
			[ALIVER_STATE.RUN] = StateHeroCommRun.new(),
			[ALIVER_STATE.ATTACK] = StateHeroCommAttack.new(),
			[ALIVER_STATE.DIE] = StateHeroDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_PET] = {
			[ALIVER_STATE.IDLE] = StatePetIdle.new(),
			[ALIVER_STATE.WALK] = StatePetCommRun.new(),
			[ALIVER_STATE.RUN] = StatePetCommRun.new(),
			[ALIVER_STATE.ATTACK] = StateCommAttack.new(),
			[ALIVER_STATE.DIE] = StateCommDie.new(),
			[ALIVER_STATE.COLLIDE] = StateCommCollide.new(),
			[ALIVER_STATE.MAGIC] = StatePlayerMagic.new(),
			[ALIVER_STATE.PETFINDRUN] = StatePetFindRun.new(),
		},

		[ALIVER_GHOST_TYPE.GHOST_TYPE_MINER] = {
			[ALIVER_STATE.IDLE] = StateMinerIdle.new(),
		},
	}

	self.mMapState = mapState
end

function StateMachine:createState(stateid)
	if not self.mMapState then
		self:initState()
	end

	local hostType = self.mHost:getClientProp(ClientProp.ENTITY_C_TYPE)
	if hostType == ALIVER_GHOST_TYPE.GHOST_TYPE_THIS then
		local isOffTuoguan = MyRole.isOffTuoguan()
		local index = 2
		if isOffTuoguan then
			index = 1
		end

		return self.mMapState[hostType][index][stateid]
	end

	local state = self.mMapState[hostType] and self.mMapState[hostType][stateid] or nil
	return state
end

return StateMachine

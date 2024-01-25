--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：待机状态机
******************************************************************************************
]]
StateThisIdle = class( "StateThisIdle" )

function StateThisIdle:ctor()
	self.mHost  = nil
end

function StateThisIdle:setHost( host )
	self.mHost = host
end

function StateThisIdle:getID()
	return ALIVER_STATE.IDLE
end

function StateThisIdle:onEnter()
	-- 进入待机状态判断是否能挖矿
	api_map:checkCanMining(true)
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
end

function StateThisIdle:onExit()
	MyRole.misgather = false
end

function StateThisIdle:onUpdate( elaspe )
	MyRole.selfPickItemId = 0
	StateHelper.mainRoleNextState()
end

-----------------------------------------------------------------------

StateCommIdle = class( "StateCommIdle" )

function StateCommIdle:ctor()
	self.mHost  = nil
end

function StateCommIdle:setHost( host )
	self.mHost = host
end

function StateCommIdle:getID()
	return ALIVER_STATE.IDLE
end

function StateCommIdle:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
	local effvisible = CommonHelper.hasEffectBuff(self.mHost, EFFECT_VISABLE)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
	elseif effvisible == true then
        self.mHost:getCloth():setAlpha(160)
    else
		self.mHost:getCloth():setAlpha(255)
	end
end

function StateCommIdle:onExit()
	--nothing
end

function StateCommIdle:onUpdate( elaspe )
	--nothing
end

-----------------------------------------------------------------------

StatePlayerIdle = class( "StatePlayerIdle" )

function StatePlayerIdle:ctor()
	self.mHost  = nil
end

function StatePlayerIdle:setHost( host )
	self.mHost = host
end

function StatePlayerIdle:getID()
	return ALIVER_STATE.IDLE
end

function StatePlayerIdle:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
end

function StatePlayerIdle:onExit()
	
end

function StatePlayerIdle:onUpdate( elaspe )
end

---------------------------------------------------------------------------------
-- 英雄待机 

StateHeroIdle = class( "StateHeroIdle" )

function StateHeroIdle:ctor()
	self.mHost  = nil
	self.countIndex = 0
end

function StateHeroIdle:setHost( host )
	self.mHost = host
end

function StateHeroIdle:getID()
	return ALIVER_STATE.IDLE
end

function StateHeroIdle:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
end

function StateHeroIdle:onExit()
	--nothing
end

function StateHeroIdle:onUpdate( elaspe )
	--nothing
	if self.mHost and MyRole.entityHero and self.mHost:getClientProp(ClientProp.ENTITY_C_EID) == MyRole.entityHero:getClientProp(ClientProp.ENTITY_C_EID) then 
		if self.countIndex%10 == 0 then 
			self.countIndex = 0 
			CommonHelper.heroNextAction(MyRole.entityHero, false)
		end 
		self.countIndex = self.countIndex + 1 
	end 
end

---------------------------------------------------------------------------------
-- 萌宠待机 

StatePetIdle = class( "StatePetIdle" )

function StatePetIdle:ctor()
	self.mHost  = nil
	self.countIndex = 0
end

function StatePetIdle:setHost( host )
	self.mHost = host
end

function StatePetIdle:getID()
	return ALIVER_STATE.IDLE
end

function StatePetIdle:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
	
end

function StatePetIdle:onExit()
	--nothing
end

function StatePetIdle:onUpdate( elaspe )
	if self.mHost and MyRole.entityPet  and self.mHost:getClientProp(ClientProp.ENTITY_C_EID) == MyRole.entityPet:getClientProp(ClientProp.ENTITY_C_EID) then 
		 if self.countIndex%5 == 0 then 
			 self.countIndex = 0 
			 MyRole.petPickItemId = 0
			PetHelper.petNextAction(MyRole.entityPet, false)
		 end 
		 self.countIndex = self.countIndex + 1 
	end 
end


---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
-- 矿工待机 

StateMinerIdle = class( "StateMinerIdle" )

function StateMinerIdle:ctor()
	self.mHost  = nil
	self.countIndex = 0
end

function StateMinerIdle:setHost( host )
	self.mHost = host
end

function StateMinerIdle:getID()
	return ALIVER_STATE.IDLE
end

function StateMinerIdle:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.IDLE )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
	self.countIndex = 0
end

function StateMinerIdle:onExit()
	--nothing
end

function StateMinerIdle:onUpdate( elaspe )
	if self.countIndex%10 == 0 then 
		self.countIndex = 0 
		self.mHost:getCloth():runAnimation()
	end 
	self.countIndex = self.countIndex + 1 

end
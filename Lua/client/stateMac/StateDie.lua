--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：死亡状态机
******************************************************************************************
]]
StateThisDie = class("StateThisDie")

function StateThisDie:ctor()
	self.mHost  = nil
end

function StateThisDie:setHost( host )
	self.mHost  = host
end

function StateThisDie:getID()
	return ALIVER_STATE.DIE
end

function StateThisDie:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.DIE )

	--判断进度条是否存在，强制销毁
	if self.mHost.mComponent[A_C_TYPE.C_TYPE_PBS] then
		ComponentHelper.delComponent(self.mHost,A_C_TYPE.C_TYPE_PBS)
		self.mHost.misgather = false
	end

	for v = 1 , A_C_TYPE.C_TYPE_MAX do
		local component = self.mHost:getComponent( v )
		if component and v ~= A_C_TYPE.C_TYPE_NAME then
			component:setVisible(false)
		end
	end

	MyRole.mAIMouseSequence = false
    MyRole.mIsInScreemMove = false
	self.mHost:getCloth():runAnimation()

	if MyRole.mTargetGhostType == ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER then  
        sendNotification(PROXY_INTERACTION_END,{})
        MyRole.mTargetGhostType =-1
        MyRole.mTargetItem=nil
        MyRole.mTargetGhostId=nil
    end

    if api_map.mSceneId == MapID.swdd or (api_map.mSceneId >= MapID.swy1 and api_map.mSceneId <= MapID.swy8) then
		if api_ui:getItemInfo(UI_TIME_RELIVE) == nil then
			sendNotification(UI_OPEN_PANEL, {command = UI_TIME_RELIVE})
		end
	elseif api_map.mSceneId == MapID.zhanduisai3v3 then
		if api_ui:getItemInfo(UI_XJP_3V3GAME_RELIVE) == nil then
			sendNotification(UI_OPEN_PANEL, {command = UI_XJP_3V3GAME_RELIVE})
		end
	elseif api_map.mSceneId~=0 then
		if not api_ui:getPanel(UI_PANEL_RELIVE) and not MyRole.isOffTuoguan() and api_ui:getPanel(UI_MAIN) then
	        sendNotification(UI_OPEN_PANEL,{command = UI_PANEL_RELIVE , datass = nil })
	    end
	end
end

function StateThisDie:onExit()
	for v = 1 , A_C_TYPE.C_TYPE_MAX do
		local component = self.mHost:getComponent( v )
		if component then
			if v == A_C_TYPE.C_TYPE_NAME then
				component:setVisible(MyRole.getUseDataToInt(gdUserDefaultData.SHOW_NAME) == 1)
			elseif v == A_C_TYPE.C_TYPE_GUILD_NAME then
				component:setVisible(MyRole.getUseDataToInt(gdUserDefaultData.SHOW_GUILD) == 1)
			else
				component:setVisible(true)				
			end
		end
	end

	AnimateHelper.playerArmature( self.mHost , 57 )
	ComponentHelper.delComponent( self.mHost , A_C_TYPE.C_TYPE_DEAD )
	self.mHost.mCloth:setVisibleEnum( CLOTH_PLAYER_VISIBLE.HIDE_DEAD , nil )
end

function StateThisDie:onUpdate( elaspe )
	--..nothing
end

----------------------------------------------------------------------------------------------

StatePlayerDie = class("StatePlayerDie")

function StatePlayerDie:ctor()
	self.mHost  = nil
end

function StatePlayerDie:setHost( host )
	self.mHost  = host
end

function StatePlayerDie:getID()
	return ALIVER_STATE.DIE
end

function StatePlayerDie:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.DIE )

	for v = 1 , A_C_TYPE.C_TYPE_MAX do
		local component = self.mHost:getComponent( v )
		if component and v ~= A_C_TYPE.C_TYPE_NAME then
			component:setVisible(false)
		end
	end

	self.mHost:getCloth():runAnimation()
    if self.mHost.mID == MyRole.getClientProp( ClientProp.ENTITY_ATTACK_AIMID ) then
        MyRole.changeTheAim(0)
        sendNotification(PROXY_INTERACTION_END,{})
    end
end

function StatePlayerDie:onExit()

	for v = 1 , A_C_TYPE.C_TYPE_MAX do
		local component = self.mHost:getComponent( v )
		if component then
			if v == A_C_TYPE.C_TYPE_NAME then
				component:setVisible(MyRole.getUseDataToInt(gdUserDefaultData.SHOW_NAME) == 1)
			elseif v == A_C_TYPE.C_TYPE_GUILD_NAME then
				component:setVisible(MyRole.getUseDataToInt(gdUserDefaultData.SHOW_GUILD) == 1)
			else
				component:setVisible(true)				
			end
		end
	end

	AnimateHelper.playerArmature( self.mHost , 57 )
	ComponentHelper.delComponent( self.mHost , A_C_TYPE.C_TYPE_DEAD )
	self.mHost.mCloth:setVisibleEnum( CLOTH_PLAYER_VISIBLE.HIDE_DEAD , nil )
end

function StatePlayerDie:onUpdate( elaspe )
	--..nothing
end

----------------------------------------------------------------------------------------------

StateCommDie = class("StateCommDie")

function StateCommDie:ctor()
	self.mHost  = nil
end

function StateCommDie:setHost( host )
	self.mHost  = host
end

function StateCommDie:getID()
	return ALIVER_STATE.DIE
end

function StateCommDie:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.DIE )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local ghostType = self.mHost:getClientProp( ClientProp.ENTITY_C_TYPE)
    if ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_NPC then
        self.mHost:getEntitySprite():setVisible( false )
    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_MONSTER then
	        local url = "effect_dead_01"
	        local src = GetSkillRes(url)
	        local deadFire = AnimateHelper.createArmature( url , src[1] , EFFECTRULE.ONETIME )
			local pointX , pointY  = self.mHost:getEntitySprite():getPosition()
			deadFire:attach( self.mHost:getEntitySprite() )
			self.mHost:getCloth():setVisible( false )
			if self.mHost:getComponent(A_C_TYPE.C_TYPE_SHADOW) then
				self.mHost:getComponent(A_C_TYPE.C_TYPE_SHADOW):setVisible(false)
			end
			self.mHost:getComponent(A_C_TYPE.C_TYPE_BLOOM):getProgressBar():getNode():setVisible(false)
			deadFire:setCall(
			function()
				if self.mHost and self.mHost:getEntitySprite() and not tolua.isnull(self.mHost:getEntitySprite()) then
					self.mHost:getEntitySprite():setVisible( false )
				end
			end)
        sendNotification(WXSY_MONSTER_DIE_EVENT,{posx=pointX , posy=pointY})


    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_SLAVE then
    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER_CLONE then
    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER_SHADOW then
    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_MARS then
    elseif ghostType == ALIVER_GHOST_TYPE.GHOST_TYPE_HERO then
    else
        self.mHost:getEntitySprite():setVisible( false )
    end

end

function StateCommDie:onExit()
end

function StateCommDie:onUpdate( elaspe )
	--..nothing
end

--------------------------英雄死亡-----------------------------
StateHeroDie = class("StateHeroDie")

function StateHeroDie:ctor()
	self.mHost  = nil
end

function StateHeroDie:setHost( host )
	self.mHost  = host
end

function StateHeroDie:getID()
	return ALIVER_STATE.DIE
end

function StateHeroDie:onEnter()
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.DIE )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	-- 自己英雄死了之后加个死亡特效 
	local EffectSprite = require("xf.engine.ui.EffectSprite")
	local effect = EffectSprite:new()
	effect:init(335,EFFECTRULE.ONETIME)
	effect:attach(api_ghost:getGhostLayer())
	local mx =self.mHost:getClientProp(ClientProp.ENTITY_C_TX)
	local my = self.mHost:getClientProp(ClientProp.ENTITY_C_TY)
	local mapPoint = MapHelper.getPixelPoint( mx, my)
	local efx = mapPoint.x
	local efy = mapPoint.y    
	effect:setXy(ccp(efx,-efy))
end

function StateHeroDie:onExit()
end

function StateHeroDie:onUpdate( elaspe )
	--..nothing
end
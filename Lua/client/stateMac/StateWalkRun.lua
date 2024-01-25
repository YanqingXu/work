--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：走路状态机
******************************************************************************************
]]
StateThisWalk = class("StateThisWalk")

function StateThisWalk:ctor()
	self.mHost  = nil
	self.mState = nil
end

function StateThisWalk:setHost( host )
	self.mHost = host
end

function StateThisWalk:getID()
	return ALIVER_STATE.WALK
end

function StateThisWalk:onEnter()
	local targetXy = self.mHost:getTargetXY()
	local dir      = self.mHost:getClientProp( ClientProp.ENTITY_C_DIR )

	playerRequest.MsgPlayerWalkRequest(dir,targetXy.x,targetXy.y)
	MyRole.checkLocalHaveItem( true )

	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.WALK )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[2] )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte then
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK , ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK ,255)
    end


    local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
    end

	local moveTime = 0.8 / baseSpeed
	local moAction = cc.MoveTo:create( moveTime , StateHelper.calePixelPoint( self.mHost ) )
	local sq  	   = cc.Sequence:create( moAction , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	api_audio:play(GD_UI_MOVE_SK)
end

function StateThisWalk:onExit()
	MyRole.checkLocalHaveItem(false)
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
end

function StateThisWalk:onUpdate( elaspe )
	--..nothing
end

function StateThisWalk:stateEnd()
	self.mState = false
	MyRole.checkLocalHaveItem(true)
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
	self.mHost:getEntitySprite():stopActionByTag(1111)
	api_map:freshPos()
	api_map:checkCanMining(false)
	StateHelper.mainRoleNextState()
	api_map:checkOnPortals()
	MyRoleHelper.refreshIntoPeaceArea()
end

------------------------------------------------------------------------------------------------

StateThisRun = class("StateThisRun")

function StateThisRun:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateThisRun:setHost( host )
	self.mHost = host
end

function StateThisRun:getID()
	return ALIVER_STATE.RUN
end

function StateThisRun:onEnter()
	api_map.transformBack = 0
	local targetXy = self.mHost:getTargetXY()
	local dir      = self.mHost:getClientProp( ClientProp.ENTITY_C_DIR )
	local stateMac = self.mHost:getState()
	local stateInfo = stateMac:getCurInfo()
	-- 野蛮冲撞、十步一杀是不需要同步坐标的
    if SkillHelper.isRightNowAttackTarget(stateInfo.skillType) then
	else
		playerRequest.MsgPlayerRunRequest(dir, targetXy.x, targetXy.y)
	end
	MyRole.checkLocalHaveItem(true)
	
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[3] )
	self.mHost:getEntitySprite():stopActionByTag(1111)
	
	MyRole.mRunFlag = 1

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK , ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK ,255)
    end

	local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end

	local moveTime = 0.8 / baseSpeed
	local moAction = cc.MoveTo:create( moveTime , StateHelper.calePixelPoint( self.mHost ) )
	local sq  	   = cc.Sequence:create( moAction , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	api_audio:play(GD_UI_MOVE_SK)
end

function StateThisRun:onExit()
	MyRole.checkLocalHaveItem(false)
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	api_map.collide = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	MyRole.mRunFlag = 0
end

function StateThisRun:onUpdate( elaspe )
	--..nothing
end

function StateThisRun:stateEnd()
	self.mState = false
	api_map.collide = false
	MyRole.checkLocalHaveItem(true)

	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:setClientProp( ClientProp.ENTITY_C_BE_COLLIDE , 0 )
	api_map:checkCanMining(false)
	api_map:freshPos()
	StateHelper.mainRoleNextState()
	api_map:checkOnPortals()
	MyRoleHelper.refreshIntoPeaceArea()
end

------------------------------------------------------------------------------------------------

StateThisRideRun = class("StateThisRideRun")

function StateThisRideRun:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateThisRideRun:setHost( host )
	self.mHost = host
end

function StateThisRideRun:getID()
	return ALIVER_STATE.RIDE_RUN
end

function StateThisRideRun:onEnter()

	local targetXy = self.mHost:getTargetXY()
	local dir      = self.mHost:getClientProp( ClientProp.ENTITY_C_DIR )
	playerRequest.MsgPlayerHorseRunRequest(dir,targetXy.x,targetXy.y)
	CommonHelper.addComponentXY( self.mHost , 0 , 40 )

	self.mState = true
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , true)
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RIDE_RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( 2.0 )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK , ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK ,255)
    end

    local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end

	local moveTime = 0.52 / baseSpeed
	local moAction = cc.MoveTo:create( moveTime , StateHelper.calePixelPoint( self.mHost ) )
	local sq  	   = cc.Sequence:create( moAction , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
end

function StateThisRideRun:onExit()
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , false)
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
end

function StateThisRideRun:onUpdate( elaspe )
	--..nothing
end

function StateThisRideRun:stateEnd()
	CommonHelper.addComponentXY( self.mHost , 0 ,-40 )
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , false)
	self.mState = false
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
	self.mHost:getEntitySprite():stopActionByTag(1111)
	api_map:checkCanMining(false)
	StateHelper.mainRoleNextState()
	api_map:checkOnPortals()
end

------------------------------------------------------------------------------------------------

StateThisCollide = class( "StateThisCollide" )

function StateThisCollide:ctor()
	self.mHost  = nil
	self.mState = false
	self.index = 0
end

function StateThisCollide:setHost( host )
	self.mHost = host
end

function StateThisCollide:getID()
	return ALIVER_STATE.COLLIDE 
end

function StateThisCollide:onEnter()
	-- api_scene:ShakeSceen()
	api_map.collide = true
	
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:getEntitySprite():stopActionByTag(5555)

    local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end

	local count = 0

	local postar = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_TARGET_X),
	self.mHost:getClientProp(ClientProp.ENTITY_TARGET_Y))

	local pos = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_CUR_X),
    self.mHost:getClientProp(ClientProp.ENTITY_CUR_Y))

	count = math.max(math.abs(postar.x - pos.x)/TILE_WIDTH,math.abs(postar.y - pos.y)/TILE_HEIGHT)
	--跑动时，坐标位置不准确，最大四个残影
	count = math.min(count,4)
	local moveTime = 0.52 / baseSpeed / 2 * count
	for len = 1 ,count do
		api_ghost:createShadowGhost(self.mHost,len)
	end

	local sq = cc.Sequence:create( cc.MoveTo:create(moveTime ,cc.p(postar.x ,-postar.y)), cc.CallFunc:create( handler(self,self.stateEnd) ))
	sq:setTag(5555)
	self.mHost:getEntitySprite():runAction(sq)
end


function StateThisCollide:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(5555)
	api_map.collide = false
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
end

function StateThisCollide:onUpdate( elaspe )
	--..nothing
end

-- function StateThisCollide:createGhost( elaspe )
-- 	self.mHost:
-- end

function StateThisCollide:pause( elaspe )
	self.mHost:getCloth():pause()
end

function StateThisCollide:resume( elaspe )
	self.mHost:getCloth():resume()
end


function StateThisCollide:stateEnd()
	api_map.collide = false
	self.mState = false
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
	self.mHost:getEntitySprite():stopActionByTag(5555)
	api_map:freshPos()

	local shelte = api_map:isSheltered(targetX, targetY)
    if shelte==true then
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK , ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK ,255)
    end

	StateHelper.mainRoleNextState()
end

------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------

StateShadowCollide = class( "StateShadowCollide" )

function StateShadowCollide:ctor()
	self.mHost  = nil
	self.mState = false
	self.refresh_schedule_id = nil
	self.setAlpha = 200
end

function StateShadowCollide:setHost( host )
	self.mHost = host
end

function StateShadowCollide:getID()
	return ALIVER_STATE.COLLIDE 
end

function StateShadowCollide:onEnter()
	-- api_map.collide = true
	
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:setDirection(self.mHost:getClientProp(ClientProp.ENTITY_C_DIR))
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:getEntitySprite():stopActionByTag(5555)
	self.mHost:getCloth():setAlpha(self.setAlpha)
    local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end

	local moveTime = 0.52 / baseSpeed / 2

	local postar = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_TARGET_X),
	self.mHost:getClientProp(ClientProp.ENTITY_TARGET_Y))

	local pos = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_CUR_X),
    self.mHost:getClientProp(ClientProp.ENTITY_CUR_Y))
    
	local index = self.mHost:getClientProp(ClientProp.ENTITY_C_INDEX) - 1

	-- local index = self.mHost.mID -1000000000 - 1
	local count = 0
	count = math.max(math.abs(postar.x - pos.x)/TILE_WIDTH,math.abs(postar.y - pos.y)/TILE_HEIGHT)
	count = math.min(count,4)
	-- local moAction = cc.MoveTo:create( moveTime , cc.p((postar.x - pos.x)/5 * 1 + pos.x,-(postar.y - pos.y)/5 * 1 - pos.y))
	local action = {}

	local sq = cc.Sequence:create(cc.MoveTo:create( moveTime * index , cc.p((postar.x - pos.x)/count * index + pos.x,-(postar.y - pos.y)/count * index - pos.y)),cc.CallFunc:create( handler(self,self.pause) ))

	sq:setTag(5555)
	self.mHost:getEntitySprite():runAction(sq)
end

function StateShadowCollide:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(5555)
	-- api_map.collide = false
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
end

function StateShadowCollide:onUpdate( elaspe )
	--..nothing
end

function StateShadowCollide:pause( elaspe )
	self.mHost:getCloth():setVisible(true)
	self.mHost:getCloth():pause()
	local function onRefresh()
		self.setAlpha = self.setAlpha - 25
		if self.mHost and self.mHost:getCloth() then
			self.mHost:getCloth():setAlpha(math.max(self.setAlpha,0))
		end
		if self.setAlpha <= 0 or not self.mHost then
			if self.refresh_schedule_id then
				api_schedule:unRegisterSchedule("StateShadowCollideSchedule"..self.mHost.mID, self.refresh_schedule_id)
				self.refresh_schedule_id = nil
			end
			api_ghost:removeGhost(self.mHost.mID)
		end
	end
	self.refresh_schedule_id = api_schedule:registerSchedule("StateShadowCollideSchedule"..self.mHost.mID , 0.1, onRefresh)
end

function StateShadowCollide:resume( elaspe )
	self.mHost:getCloth():resume()
end


function StateShadowCollide:stateEnd()
	-- api_map.collide = false
	self.mState = false
	local targetX = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_X )
	local targetY = self.mHost:getClientProp( ClientProp.ENTITY_TARGET_Y )
	api_map.currentX = targetX
	api_map.currentY = targetY
	self.mHost:syncTarAndCurXy()
	self.mHost:getEntitySprite():stopActionByTag(5555)
	api_map:freshPos()

	local shelte = api_map:isSheltered(targetX, targetY)
    if shelte==true then
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK , ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlphaEnum(CLOTH_PLAYER_ALPHA.BLOCK ,255)
    end
end

------------------------------------------------------------------------------------------------

StateCommRun = class( "StateCommRun" )

function StateCommRun:ctor()

end

function StateCommRun:setHost( host )
	self.mHost = host
end

function StateCommRun:getID()
	return ALIVER_STATE.RUN
end

function StateCommRun:onEnter()
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[3] )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end

	local speed = 0
	local ghosttype = self.mHost:getClientProp( ClientProp.ENTITY_C_TYPE )
    if self.mHost:getProp( ENTITY_PROP_DUMMY_PLAYER )==1 then
		speed = gdGame.roleBaseSpeed - 0.5
	elseif ghosttype == ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER then
		speed = gdGame.roleBaseSpeed 
    else
        speed = gdGame.monsterSpeed
    end

	local baseSpeed = speed * self.mHost:getEntityMoveSpeed()
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
	end
	local moveTime = 0.8 / baseSpeed
	local delay    = cc.DelayTime:create(0.1)
	local tarPixPoint = StateHelper.calePixelPoint( self.mHost )
	local moAction = cc.MoveTo:create( moveTime ,tarPixPoint )
	local sq  	   = cc.Sequence:create( moAction , delay , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self:updataPosition()
end

function StateCommRun:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false

	self.mHost:getEntitySprite():stopActionByTag(1111)
end

function StateCommRun:onUpdate( elaspe )
	--..nothing
end

function StateCommRun:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	StateHelper.ghostNextState( self.mHost )
	self:updataPosition()
	self.mHost:setClientProp( ClientProp.ENTITY_C_BE_COLLIDE , 0 )
end

function StateCommRun:updataPosition()
	self.mHost:syncTarAndCurXy()
	local targetXy = self.mHost:getTargetXY()
end

------------------------------------------------------------------------------------------------

-----------------------------------------宝宝移动------------------------------------------------
StateHeroCommRun = class( "StateHeroCommRun" )

function StateHeroCommRun:ctor()

end

function StateHeroCommRun:setHost( host )
	self.mHost = host
end

function StateHeroCommRun:getID()
	return ALIVER_STATE.RUN
end

function StateHeroCommRun:onEnter()
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[2] )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end
	local baseSpeed = ENTITY_HERO_SPEED * self.mHost:getEntityMoveSpeed()
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
	end
	local moveTime = 0.8 / baseSpeed
	local tarPixPoint = StateHelper.calePixelPoint( self.mHost )
	local moAction = cc.MoveTo:create( moveTime ,tarPixPoint )
	local sq  	   = cc.Sequence:create( moAction ,cc.CallFunc:create( handler(self,self.stateEnd) ))
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self:updataPosition()
end

function StateHeroCommRun:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
end

function StateHeroCommRun:onUpdate( elaspe )
	
end

function StateHeroCommRun:stateEnd()
	--宝宝移动结束后检测是否继续移动 
	if CommonHelper.checkMyHero(self.mHost) then
		self.mState = false
		self.mHost:getEntitySprite():stopActionByTag(1111)
		CommonHelper.heroNextAction(self.mHost, true);
		self:updataPosition()
	else
		self.mState = false
		self.mHost:getEntitySprite():stopActionByTag(1111)
		StateHelper.ghostNextState( self.mHost )
		self:updataPosition()
	end
end

function StateHeroCommRun:updataPosition()
	self.mHost:syncTarAndCurXy()
end

------------------------------------------------------------------------------------------------


-----------------------------------------萌宠移动------------------------------------------------
StatePetCommRun = class( "StatePetCommRun" )

function StatePetCommRun:ctor()

end

function StatePetCommRun:setHost( host )
	self.mHost = host
end

function StatePetCommRun:getID()
	return ALIVER_STATE.RUN
end

function StatePetCommRun:onEnter()
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[2] )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end
	local baseSpeed = ENTITY_PET_SPEED * self.mHost:getEntityMoveSpeed()
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
	end
	local moveTime = 0.8 / baseSpeed
	local tarPixPoint = StateHelper.calePixelPoint( self.mHost )
	local moAction = cc.MoveTo:create( moveTime ,tarPixPoint )
	local sq  	   = cc.Sequence:create( moAction ,cc.CallFunc:create( handler(self,self.stateEnd) ))
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self:updataPosition()
end

function StatePetCommRun:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
end

function StatePetCommRun:onUpdate( elaspe )
	
end

function StatePetCommRun:stateEnd()
	--萌宠移动结束后检测是否继续移动 
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	if CommonHelper.checkMyPet(self.mHost) then
		PetHelper.petNextAction(self.mHost, true);
	else
		StateHelper.ghostNextState( self.mHost )
	end
	self:updataPosition()
end

function StatePetCommRun:updataPosition()
	self.mHost:syncTarAndCurXy()
end

------------------------------------------------------------------------------------------------

-----------------------------------------萌宠移动(捡东西)------------------------------------------------
StatePetFindRun = class( "StatePetFindRun" )

function StatePetFindRun:ctor()

end

function StatePetFindRun:setHost( host )
	self.mHost = host
end

function StatePetFindRun:getID()
	return ALIVER_STATE.PETFINDRUN
end

function StatePetFindRun:onEnter()
	local soeedRate = 1 
	--萌宠竹林居士拾取速度+50%
	if PetHelper.checkMengChongGet(3) then 
		local skillid = gdMengChong[3].skillid
		soeedRate = gdBaoBaoSkills[skillid].datax / 100 + 1
	end 

	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[2] * soeedRate )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end
	local baseSpeed = ENTITY_PET_SPEED * self.mHost:getEntityMoveSpeed() * soeedRate
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
	end
	local moveTime = 0.8 / baseSpeed
	local tarPixPoint = StateHelper.calePixelPoint( self.mHost )
	local moAction = cc.MoveTo:create( moveTime ,tarPixPoint )
	local sq  	   = cc.Sequence:create( moAction ,cc.CallFunc:create( handler(self,self.stateEnd) ))
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self:updataPosition()
end

function StatePetFindRun:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
end

function StatePetFindRun:onUpdate( elaspe )
	
end

function StatePetFindRun:stateEnd()
	--萌宠移动结束后检测是否继续移动 
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	
	if CommonHelper.checkMyPet(self.mHost) then
		PetHelper.petNextAction(self.mHost, true);
	else
		StateHelper.clearStateToIdle(self.mHost)
		StateHelper.ghostNextState( self.mHost )
	end
	self:updataPosition()
end

function StatePetFindRun:updataPosition()
	self.mHost:syncTarAndCurXy()
end

------------------------------------------------------------------------------------------------


StateCommWalk = class( "StateCommWalk" )

function StateCommWalk:ctor()

end

function StateCommWalk:setHost( host )
	self.mHost = host
end

function StateCommWalk:getID()
	return ALIVER_STATE.WALK
end

function StateCommWalk:onEnter()
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.WALK )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed(PLAYER_STATE_FRAME[2])
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte==true then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end

    local speed = 0
    if self.mHost:getClientProp( ClientProp.ENTITY_C_TYPE ) == ALIVER_GHOST_TYPE.GHOST_TYPE_PLAYER then
    	speed = gdGame.roleBaseSpeed
    else
        speed = gdGame.monsterSpeed
    end

	local baseSpeed = speed * self.mHost:getEntityMoveSpeed()
    if baseSpeed < 0.1 then
        baseSpeed = 0.1
    end

	local moveTime = 0.8 / baseSpeed
	local delay    = cc.DelayTime:create(0.1)
	local moAction = cc.MoveTo:create( moveTime , StateHelper.calePixelPoint( self.mHost ) )
	local sq  	   = cc.Sequence:create( moAction , delay , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self:updataPosition()
end

function StateCommWalk:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
end

function StateCommWalk:onUpdate( elaspe )
	--..nothing
end

function StateCommWalk:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	StateHelper.ghostNextState( self.mHost )
	self:updataPosition()
end

function StateCommWalk:updataPosition()
	self.mHost:syncTarAndCurXy()
end

------------------------------------------------------------------------------------------------

StateCommCollide = class("StateCommCollide")

function StateCommCollide:ctor()
	self.mHost  = nil
	self.mState = false
end

function StateCommCollide:setHost( host )
	self.mHost = host
end

function StateCommCollide:getID()
	return ALIVER_STATE.RUN
end

function StateCommCollide:onEnter()
	-- api_map.collide = true
	
	self.mState = true
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( PLAYER_STATE_FRAME[1] )
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:getEntitySprite():stopActionByTag(5555)

    local baseSpeed = gdGame.roleBaseSpeed * MyRole.entity:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end


	local count = 0

	local postar = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_TARGET_X),
	self.mHost:getClientProp(ClientProp.ENTITY_TARGET_Y))

	local pos = MapHelper.getPixelPoint(self.mHost:getClientProp(ClientProp.ENTITY_C_TX),
    self.mHost:getClientProp(ClientProp.ENTITY_C_TY))

	count = math.max(math.abs(postar.x - pos.x)/TILE_WIDTH,math.abs(postar.y - pos.y)/TILE_HEIGHT)
	count = math.min(count,4)
	local moveTime = 0.52 / baseSpeed / 2 * count
	for len = 1 ,count do
		api_ghost:createShadowGhost(self.mHost,len)
	end

	local sq = cc.Sequence:create( cc.MoveTo:create(moveTime ,cc.p(postar.x,-postar.y)), cc.CallFunc:create( handler(self,self.stateEnd) ))
	sq:setTag(5555)
	self.mHost:getEntitySprite():runAction(sq)
end

function StateCommCollide:onExit()
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:getEntitySprite():stopActionByTag(5555)
end

function StateCommCollide:onUpdate( elaspe )
	--..nothing
end

function StateCommCollide:stateEnd()
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	self.mHost:getEntitySprite():stopActionByTag(5555)
	StateHelper.ghostNextState( self.mHost )
	self:updataPosition()
end

function StateCommCollide:updataPosition()
	self.mHost:syncTarAndCurXy()
end

--------------------------------------------------------------------------------------

StatePlayerRideRun = class("StatePlayerRideRun")

function StatePlayerRideRun:ctor()
	self.mHost  = nil
	self.mState = false
end

function StatePlayerRideRun:setHost( host )
	self.mHost = host
end

function StatePlayerRideRun:getID()
	return ALIVER_STATE.RIDE_RUN
end

function StatePlayerRideRun:onEnter()
	local targetXy = self.mHost:getTargetXY()
	local dir      = self.mHost:getClientProp( ClientProp.ENTITY_C_DIR )
	CommonHelper.addComponentXY( self.mHost ,0,40 )
	self.mState = true
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , true)
	self.mHost:setClientProp( ClientProp.ENTITY_C_STATE , ALIVER_STATE.RIDE_RUN )
	self.mHost:getCloth():runAnimation()
	self.mHost:getCloth():setSpeed( 2.0 )
	self.mHost:getEntitySprite():stopActionByTag(1111)

	local targetXy = self.mHost:getTargetXY()
	local shelte = api_map:isSheltered(targetXy.x,targetXy.y)
    if shelte then
        self.mHost:getCloth():setAlpha(ENITITY_ALPHA)
    else
        self.mHost:getCloth():setAlpha(255)
    end

    local baseSpeed = gdGame.roleBaseSpeed * self.mHost:getEntityMoveSpeed()
    if baseSpeed < 0.1 then baseSpeed = 0.1 end
	local moveTime = 0.52 / baseSpeed
	local moAction = cc.MoveTo:create( moveTime + 0.01 , StateHelper.calePixelPoint( self.mHost ) )
	local sq  	   = cc.Sequence:create( moAction , cc.CallFunc:create( handler(self,self.stateEnd) ) )
	sq:setTag(1111)
	self.mHost:getEntitySprite():runAction(sq)
	self.mHost:syncTarAndCurXy()
end

function StatePlayerRideRun:onExit()
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , false)
	if self.mState == true then
		local stateMac = self.mHost:getState()
		stateMac:popState()
	end
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
end

function StatePlayerRideRun:onUpdate( elaspe )
	--..nothing
end

function StatePlayerRideRun:stateEnd()
	local entityState = self.mHost:getState()
	CommonHelper.addComponentXY( self.mHost , 0,-40 )
	self.mHost:getCloth():setFlashVisible(ALIVER_CLOTH_TYPE.HORSE , false)
	self.mState = false
	self.mHost:getEntitySprite():stopActionByTag(1111)
	StateHelper.ghostNextState( self.mHost )
end
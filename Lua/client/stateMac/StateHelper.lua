--[[
******************************************************************************************
** 程      序 ： 王中军
** 修 改时 间 ：2017.02.23
** 内      容 ：状态机逻辑
******************************************************************************************
]]
StateHelper = {}

-- 状态解析器
-- 新旧状态相同 状态重载
StateHelper.analyState = function(stateMac, stateInfo)
    -- 麻痹、冰冻
    if CommonHelper.getInjectioBuff(stateMac.mHost) and not stateMac.mHost:isMyRole() then
        return
    end

    -- 状态
    stateMac:setStateInfo(stateInfo)
    if stateMac:getCurState() and stateMac:getCurState():getID() == stateInfo.state then
        stateMac:getCurState():onEnter()
        return
    end
    -- 设置状态机
    stateMac:setState(stateInfo.state)
end

-- 立刻播放此状态 无视状态列表
StateHelper.rightNowPlayThisStateInfo = function(entity, stateinfo)
    if not entity then
        return
    end
    local stateMac = entity:getState()
    if not stateMac then
        return
    end
    entity:getState():clearAllState()
    StateHelper.analyState(stateMac, stateinfo)
end

-- 立刻进入idle状态 无视状态列表
StateHelper.clearStateToIdle = function(entity)
    if not entity then
        return
    end
    if entity:getRunState() == ALIVER_STATE.RUN or entity:getRunState() == ALIVER_STATE.PREPARE then
        return
    end
    if not entity:getState() or not entity:getState():getStateList() then
        return
    end
    if #entity:getState():getStateList() == 0 and entity:getState():getCurInfo() and
        entity:getState():getCurInfo().state == ALIVER_STATE.IDLE then
        return
    end
    entity:getState():clearAllState()
    local stateMac = entity:getState()
    if not stateMac then
        return
    end
    StateHelper.analyState(stateMac, { state = ALIVER_STATE.IDLE })
end

-- 加入新状态
StateHelper.addEntityState = function(entity, stateinfo)
    if entity:getType() == ALIVER_GHOST_TYPE.GHOST_TYPE_MONSTER then
        -- 麻痹、冰冻
        if CommonHelper.getInjectioBuff(entity) then
            return
        end
    end

    local stateMac = entity:getState()
    if not stateMac then
        return
    end

    local isRestart = true
    local stateList = stateMac:getStateList()

    if #stateList > 0 then
        local si = stateList[#stateList]
        local isWalk = stateinfo.state == ALIVER_STATE.WALK
        local isRun = stateinfo.state == ALIVER_STATE.RUN
        local isAttack = stateinfo.state == ALIVER_STATE.ATTACK or stateinfo.state == ALIVER_STATE.MAGIC
        local isHeroAttack = isAttack and MyRole.entityHero ~= nil and
            MyRole.entityHero:getClientProp(ClientProp.ENTITY_C_EID) == entity:getClientProp(ClientProp.ENTITY_C_EID)
        if si.state == stateinfo.state and (isWalk or isRun or isHeroAttack) then
            stateMac:popEndState()
        elseif si.skilltype == 10201 and (stateinfo.state == ALIVER_STATE.MAGIC) and entity:getType() == ALIVER_GHOST_TYPE.GHOST_TYPE_THIS then
            stateMac:popEndState()
        else
            isRestart = false
        end
    end
    if stateinfo.state ~= ALIVER_STATE.IDLE then
        stateMac:addState(stateinfo)
    end

    if not isRestart then
        return
    end

    StateHelper.analyState(stateMac, stateinfo)
end

StateHelper.mainRoleNextState = function()
    local entityState = MyRole.entity:getState()
    if entityState == nil then
        return
    end
    entityState:popState()
    if #entityState.mStates > 0 then
        StateHelper.analyState(entityState, entityState:getStateList()[1])
    else
        StateHelper.mainFindNextState()
    end
end

StateHelper.mainFindNextState = function()
    local oldState = MyRole.getClientProp(ClientProp.ENTITY_C_STATE)

    if oldState == ALIVER_STATE.DIE then
        return
    end

    -- 准备释放手动操作技能
    if MyRole.mHandSkillId > 0 and MyRole.mHandSkillPos then
        if not MyAttackHelper.startCastSkill(MyRole.mHandSkillId) then
            MyRole.mHandSkillPos = nil
        end
    elseif MyRole.mTempSkill > 0 then
        MyRoleHelper.nextStateTempSkill()
    elseif MyRole.mLockSkill > 0 then
        MyRoleHelper.nextStateLockSkill()
    elseif MyRole.mAIAutoMove and MyRole.mTargetItem then
        if MyRole.mTargetItem:isMonster() or MyRole.mTargetItem:isPlayer() then
            MyAttackHelper.executeMoveAndAttack()
        else
            api_map:executeAutoMove()
        end
    elseif MyRole.mAIEasy and MyRole.mAIMouseSequence then
        if not MyAttackHelper.easyAI() then
            MyRoleHelper.executeMouseSequence()
        end
        MyRole.mAIEasy = false
    elseif MyRole.mAIAutoMove and MyRole.mAIAutoAttack then
        if MyRoleHelper.pickUpSet() then
            api_map:executeAutoMove()
        elseif api_ghost:getNearestEnemy() then
            MyRole.mAIEasy = true
            MyAttackHelper.executeMoveAndAttack()
        else
            api_map:executeAutoMove()
        end
    elseif MyRole.mAIMouseSequence then
        MyRoleHelper.executeMouseSequence()
    elseif MyRole.mAIisMoveAndAttack then
        --[[
            MyAttackHelper.executeMoveAndAttack()
        ]]
        -- (2021.6.24)改
        -- 自动战斗移动过程中优先拾取
        -- 非自动战斗过程，战斗优先
        if MyRole.mAIAutoAttack then
            if MyRoleHelper.pickUpSet() then
                api_map:executeAutoMove()
            else
                MyAttackHelper.executeMoveAndAttack()
            end
        else
            -- 选中攻击目标时，自动跑过去
            MyAttackHelper.executeMoveAndAttack()
        end
    elseif MyRole.mAIAutoMove then
        api_map:executeAutoMove()

        -- 跑到目标处进行自动攻击
    elseif MyRole.mAIEasy then
        MyAttackHelper.easyAI()
    elseif MyRole.mAIAutoAttack then -- 自动攻击状态
        -- 先检查有没有要拾取的物品
        if MyRoleHelper.pickUpSet() then
            api_map:executeAutoMove()
        else
            MyAttackHelper.autoAttack()
        end
    else
        if MyRole.entity:getState():getStateLength() == 0 then
            local stateid = MyRole.getClientProp(ClientProp.ENTITY_C_STATE)
            if stateid ~= ALIVER_STATE.IDLE then
                StateHelper.addEntityState(MyRole.entity, {
                    state = ALIVER_STATE.IDLE
                })
            end
        end
    end

    local curState = MyRole.getClientProp(ClientProp.ENTITY_C_STATE)
    if MyRole.entity:getState():getStateLength() == 0 then
        if curState == oldState and
            (curState == ALIVER_STATE.WALK or curState == ALIVER_STATE.RUN or curState == ALIVER_STATE.ATTACK or
                curState == ALIVER_STATE.COLLIDE or curState == ALIVER_STATE.MAGIC) then
            StateHelper.addEntityState(MyRole.entity, {
                state = ALIVER_STATE.IDLE
            })
        end
    end
end

StateHelper.ghostNextState = function(entity)
    if entity == nil then
        return
    end
    local entityState = entity:getState()
    if entityState == nil then
        StateHelper.addEntityState(entity, {
            state = ALIVER_STATE.IDLE
        })
    end

    entityState:popState()
    if #entityState:getStateList() == 0 then
        StateHelper.addEntityState(entity, {
            state = ALIVER_STATE.IDLE
        })
    else
        StateHelper.analyState(entityState, entityState:getStateList()[1])
    end
end

StateHelper.calePixelPoint = function(host)
    local pos = MapHelper.getPixelPoint(host:getClientProp(ClientProp.ENTITY_TARGET_X),
        host:getClientProp(ClientProp.ENTITY_TARGET_Y))
    return cc.p(pos.x, -pos.y)
end

-- 处理ghost 移动消息机制
StateHelper.handleWalkRes = function(resGhost, dir, posx, posy)
    if resGhost:getState() then
        resGhost:getState():clearAllState()
    end
    api_ghost:unRegisterXY(resGhost)
    resGhost:setTargetXY(posx, posy)
    api_ghost:registerXY(resGhost)
    resGhost:setClientProp(ClientProp.ENTITY_C_DIR, dir + 1)
    resGhost:getCloth():setDirection(dir + 1)
    StateHelper.addEntityState(resGhost, {
        state = ALIVER_STATE.WALK
    })
end

StateHelper.collide = function(resGhost, dir, posx, posy)
    resGhost:getState():clearAllState()
    api_ghost:unRegisterXY(resGhost)
    resGhost:setTargetXY(posx, posy)
    api_ghost:registerXY(resGhost)
    StateHelper.clearStateToIdle(resGhost)
    resGhost:setClientProp(ClientProp.ENTITY_C_DIR, dir + 1)
    resGhost:getCloth():setDirection(dir + 1)
    StateHelper.addEntityState(resGhost, {
        state = ALIVER_STATE.COLLIDE
    })
end

StateHelper.becollide = function(resGhost, dir, posx, posy)
    resGhost:getState():clearAllState()
    api_ghost:unRegisterXY(resGhost)
    resGhost:setTargetXY(posx, posy)
    api_ghost:registerXY(resGhost)
    StateHelper.clearStateToIdle(resGhost)
    resGhost:setClientProp(ClientProp.ENTITY_C_DIR, dir + 1)
    resGhost:getCloth():setDirection(dir + 1)
    resGhost:setClientProp( ClientProp.ENTITY_C_BE_COLLIDE , 1 )
    StateHelper.rightNowPlayThisStateInfo(resGhost, {
        state = ALIVER_STATE.IDLE
    })
    StateHelper.addEntityState(resGhost, {
        state = ALIVER_STATE.RUN
    })
end

StateHelper.handleRunRes = function(resGhost, dir, posx, posy)
    resGhost:getState():clearAllState()
    api_ghost:unRegisterXY(resGhost)
    resGhost:setTargetXY(posx, posy)
    api_ghost:registerXY(resGhost)
    resGhost:setClientProp(ClientProp.ENTITY_C_DIR, dir + 1)
    resGhost:getCloth():setDirection(dir + 1)
    StateHelper.addEntityState(resGhost, {
        state = ALIVER_STATE.RUN
    })
end

StateHelper.handleHorseRunRes = function(resGhost, dir, posx, posy)
    resGhost:getState():clearAllState()
    api_ghost:unRegisterXY(resGhost)
    resGhost:setTargetXY(posx, posy)
    api_ghost:registerXY(resGhost)
    resGhost:setClientProp(ClientProp.ENTITY_C_DIR, dir + 1)
    resGhost:getCloth():setDirection(dir + 1)
    StateHelper.addEntityState(resGhost, {
        state = ALIVER_STATE.RIDE_RUN
    })
end

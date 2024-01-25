local SkillFlash = class("SkillFlash")

local CIArmatureEventType = {
    LOOP = 1, -- 循环完成
    OVER = 2, -- 结束
}

function SkillFlash:ctor()
    self.mHost = nil
    self.mFlash = nil
    self.mIndex = nil
    self.mSkillRule = nil
    self.mArmatureName = nil
    self.mUrl = nil
    self.mPath = nil
    self.mDir = 1
    self.scaleX = 1
    self.scaleY = 1
    self.loaded = false
    self.state = false
    self.lvl = 1
end

function SkillFlash:setHost(host)
    self.mHost = host
end

function SkillFlash:getHost()
    return self.mHost
end

function SkillFlash:init(skillId, index, lvl)
    self.mIndex = index

    local skillRuleId = gdSkillRule[skillId]["ruleid"]
    local skillRule = SKILL_REGISTER[skillRuleId]

    if not skillRule then
        return
    end

    self.mSkillRule = skillRule

    local mo = SKILL_EFFECT_MOMENT[self.mSkillRule[index][SKILL_RULE.moment]]
    self.mUrl = gdSkills[skillId][mo]

    local skillinfo = gdSkillLvl[skillId]
    self.lvl = lvl

    if skillinfo and skillinfo[lvl] then
        self.mUrl = skillinfo[lvl][mo]
    end

    self.mPath = GetSkillRes(self.mUrl)[1]
end

function SkillFlash:start()
    self.state = true

    if self.mPath ~= 0 and self.mUrl ~= 0 and self.mUrl ~= "none" then
        self:loadSkill(self.mPath, self.mUrl)
    end

    local scale = self.mSkillRule[self.mIndex][SKILL_RULE.scale]
    if scale then
        self.scaleX = scale[1]
        self.scaleY = scale[2]
    end
end

function SkillFlash:loadSkill(path, armatureName)
    if self.callback then
        api_remote_load_manager:unregisterCallBack(self.mArmatureName .. "0", self.callback)
    end
    self.mArmatureName = armatureName
    self.callback = handler(self, self.loadcallback)
    -- 资源加载
    api_remote_load_manager:preload(armatureName .. "0", "animation", self.callback)
end

-- 播放动画
function SkillFlash:addIAnimation(path)
    -- 判断动画资源是否损毁
    local path_plist = path .. "0.plist"
    local path_png = path .. "0.png"
    local tmp = cc.FileUtils:getInstance():isFileExist(path_plist .. ".tmp")
    if not tmp then
        tmp = cc.FileUtils:getInstance():isFileExist(cc.FileUtils:getInstance():getWritablePath() ..
            GAME_REMOTE_SAVE_URL .. path_plist .. ".tmp")
    end
    if not tmp then
        tmp = cc.FileUtils:getInstance():isFileExist(path_png .. ".tmp")
    end
    if not tmp then
        tmp = cc.FileUtils:getInstance():isFileExist(cc.FileUtils:getInstance():getWritablePath() ..
            GAME_REMOTE_SAVE_URL .. path_png .. ".tmp")
    end

    if tmp then
        cc.FileUtils:getInstance():removeFile(cc.FileUtils:getInstance():getWritablePath() ..
            GAME_REMOTE_SAVE_URL .. path_plist .. ".tmp")
        cc.FileUtils:getInstance():removeFile(cc.FileUtils:getInstance():getWritablePath() ..
            GAME_REMOTE_SAVE_URL .. path_png .. ".tmp")
    else
        if not tolua.isnull(CIAnimationCache:getInstance()) then
            CIAnimationCache:getInstance():addIAnimation(path)
        end
    end
end

function SkillFlash:loadcallback(resName)
    if not self.loaded then
        self:addIAnimation(self.mPath)
        self.mFlash = CIArmature:create(self.mArmatureName)
        if not self.mFlash then
            return
        end
        self.mFlash:retain()
        self.mFlash:addEventListen(handler(self, self.animationEvent))
        self.loaded = true
    else
        self.mFlash:resumeAnimation()
    end

    self.mFlash:setVisible(true)

    self:getHost().mSKillMap[self.mIndex] = self
    SkillOperHelper.runSkillFlash(self)
end

function SkillFlash:getIndex()
    return self.mIndex
end

function SkillFlash:attach(parent)
    if not parent or tolua.isnull(parent) then
        return
    end

    if not self.mFlash or tolua.isnull(self.mFlash) then
        return
    end

    parent:addChild(self.mFlash)
end

function SkillFlash:run()
    self:play(self.mDir)
end

function SkillFlash:onExit()
    api_remote_load_manager:unregisterCallBack(self.mArmatureName .. "0", self.callback)
    if not tolua.isnull(self.mFlash) then
        self.mFlash:stop()
        self.mFlash:removeFromParent(false)
    end

    self.callback = nil
    self.mHost = nil
    self.state = false
end

function SkillFlash:animationEvent(armatureBack, movementType)
    if movementType == CIArmatureEventType.LOOP or
        movementType == CIArmatureEventType.OVER then
        self.mFlash:setVisible(false)
        self.mHost:onSkillEvent(SKILL_EVENT_ID.FLASH_DEL, self)
    end
end

function SkillFlash:setPosition(pos)
    self.mFlash:setPosition(pos)
end

function SkillFlash:getPosition()
    return self.mFlash:getPosition()
end

function SkillFlash:setOrder(order)
    self.mFlash:setLocalZOrder(order)
end

function SkillFlash:setVisible(boo)
    self.mFlash:setVisible(boo)
end

function SkillFlash:setRotation(rotation)
    self.mFlash:setRotation(rotation)
end

function SkillFlash:setScaleX(scaleX)
    self.scaleX = scaleX
end

function SkillFlash:setScaleY(scaleY)
    self.scaleY = scaleY
end

function SkillFlash:setAlpha(alpha)
    self.mFlash:setOpacity(alpha)
end

function SkillFlash:getParentSprite()
    if not tolua.isnull(self.mFlash) then
        return self.mFlash:getParent()
    else
        return nil
    end
end

function SkillFlash:getArmature()
    return self.mFlash
end

function SkillFlash:actionCallBack()
    if self.mHost then
        self.mHost:onSkillEvent(SKILL_EVENT_ID.NEXT_PHASE, self)
    end
end

function SkillFlash:moveCallBack()
    if self.mHost then
        self.mHost:onSkillEvent(SKILL_EVENT_ID.NEXT_PHASE, self)
        self.mHost:onSkillEvent(SKILL_EVENT_ID.FLASH_DEL, self)
    end
end

-- 内部调用
function SkillFlash:play(dir)
    if not self.mFlash then
        return
    end

    dir = dir or 0

    if dir < 1 then
        dir = 1
    end
    if dir > 8 then
        dir = 8
    end

    local reverse = 1
    local size = self.mFlash:getIAnimation():getMovementSize()

    if dir > size then
        if dir > 5 then
            reverse = -1
        end

        if dir == 6 then
            dir = 4
        end
        if dir == 7 then
            dir = 3
        end
        if dir == 8 then
            dir = 2
        end
    end

    if reverse ~= -1 then
        self.mFlash:setScaleX(self.scaleX)
        self.mFlash:setScaleY(self.scaleY)
    else
        self.mFlash:setScaleX(reverse)
    end
    self.mFlash:play(dir - 1)
end

return SkillFlash

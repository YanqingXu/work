REFRESH_RULE_LIST = {}
REFRESH_RULE = {
    CURRENCY        = 1,    --货币
    PLAYER_LEVEL    = 2,    --等级
    ITEM            = 3,    --道具
    SERVER_DAY      = 4,    --开服天数
    PLAYER_PROP     = 5,    --玩家属性
    PLAYER_EVENT    = 6,    --玩家事件
    WORLD_PROP      = 7,    --世界属性
    EQUIP           = 8,    --装备
}

REFRESH_RULE_LIST = {
    --货币相关
    [REFRESH_RULE.CURRENCY] = {
        [Captital.LINGFU_ALL] = {
            LIST.XJP_ITEM_COMPOSE
            -- LIST.ENHANCE_EQUIP,
            -- LIST.ENHANCE_SHENSHI,
        },
        [Captital.INGOT_ALL] = {
            LIST.XJP_SSJJ_DIVINE_SWORD,
            LIST.XJP_SSJJ_DIVINE_ARMOR,
            LIST.XJP_ITEM_COMPOSE,
            LIST.XJP_GUARD_SOUL,
            LIST.XJP_REINCARNATION_UPGRADE,
            LIST.XJP_HERALDRY,
            LIST.SX_HC,
            LIST.ENHANCE,
            LIST.XX_SXZL_QINGLONG,
            LIST.XX_SXZL_BAIHU,
            LIST.XX_SXZL_ZHUQUE,
            LIST.XX_SXZL_XUANWU,
            LIST.XJP_XZ_UPGRADE,
            LIST.XJP_FH_UPGRADE,
            LIST.ENHANCE_EQUIP,
            LIST.ENHANCE_SHENSHI,
            LIST.XJP_XQ_UPGRADE,
        }
    },

    --等级相关
    [REFRESH_RULE.PLAYER_LEVEL] = {
        LIST.XJP_SSJJ_DIVINE_SWORD,
        LIST.XJP_SSJJ_DIVINE_ARMOR,
        LIST.XJP_SSJJ_HOLY_SWORD,
        LIST.XJP_SSJJ_HOLY_ARMOR,
        LIST.XJP_GUARD,
        LIST.XJP_GUARD_GUARD,
        LIST.XJP_GUARD_SOUL,
        LIST.XJP_GUARD_FLAG,
        LIST.XJP_REINCARNATION_UPGRADE,
        LIST.XJP_HERALDRY,
        LIST.XX_SXZL_QINGLONG,
        LIST.XX_SXZL_BAIHU,
        LIST.XX_SXZL_ZHUQUE,
        LIST.XX_SXZL_XUANWU,
        LIST.XJP_XZ_UPGRADE,
        LIST.XJP_FH_UPGRADE,
        LIST.BAG_1, 
        LIST.BAG_2, 
        LIST.BAG_3, 
        LIST.BAG_4,
        LIST.XJP_XQ_UPGRADE,
    },

    --道具相关
    [REFRESH_RULE.ITEM] = {
        [74400] = {LIST.XJP_SSJJ_HOLY_SWORD},
        [74401] = {LIST.XJP_SSJJ_HOLY_ARMOR}, 
        [72002] = {LIST.XJP_GUARD_GUARD},
        [72003] = {LIST.XJP_GUARD_SOUL},
        [72017] = {LIST.XJP_GUARD_FLAG},
        --[74318] = {LIST.ENHANCE_EQUIP, LIST.ENHANCE_SHENSHI},
        --[74319] = {LIST.ENHANCE_EQUIP, LIST.ENHANCE_SHENSHI},
        [81613] = {LIST.ENHANCE_SHENSHI},
        [83461] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83462] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83405] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83406] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83407] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83408] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83409] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83410] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83411] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83412] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83413] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83405] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83406] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83407] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83408] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83409] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83410] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83411] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83412] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
        [83413] = {LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU},
    },
    
    --开服天数相关
    [REFRESH_RULE.SERVER_DAY] = {
        LIST.XJP_GHLC,
        LIST.XJP_DIAOWEN_UPGRADE,
        -- LIST.XJP_RONGLIAN_REPAIR,
    },

    --玩家属性相关
    [REFRESH_RULE.PLAYER_PROP] = {
        [ENTITY_PROP_DIAMONDS_VALUE] = {LIST.XJP_KFHD_ZSDH},
        [ENTITY_PROP_GUARD_LEVEL] = {LIST.XJP_GUARD_GUARD},
        [ENTITY_PROP_GUARD_PROGRESS] = {LIST.XJP_GUARD_GUARD},
        [ENTITY_PROP_SOUL_LEVEL] = {LIST.XJP_GUARD_SOUL},

        [ENTITY_PROP_WAR_FLAG_LEVEL] = {LIST.XJP_GUARD_FLAG},
        [ENTITY_PROP_WAR_FLAG_PROGRESS] = {LIST.XJP_GUARD_FLAG},

        [ENTITY_PROP_HORCRUXES_LEVEL_1] = {LIST.XJP_GUARD_HORCRUXES_1},
        [ENTITY_PROP_HORCRUXES_LEVEL_2] = {LIST.XJP_GUARD_HORCRUXES_2},
        [ENTITY_PROP_HORCRUXES_LEVEL_3] = {LIST.XJP_GUARD_HORCRUXES_3},
        [ENTITY_PROP_HORCRUXES_LEVEL_4] = {LIST.XJP_GUARD_HORCRUXES_4},
        [ENTITY_PROP_HORCRUXES_LEVEL_5] = {LIST.XJP_GUARD_HORCRUXES_5},
        [ENTITY_PROP_HORCRUXES_LEVEL_6] = {LIST.XJP_GUARD_HORCRUXES_6},
        [ENTITY_PROP_VIP_LV]            = {LIST.VIP_ALL},
        [ENTITY_PROP_REBORN] = {
            LIST.XJP_REINCARNATION_UPGRADE, 
            LIST.XJP_FULI_TOUZI_REBORN,
            LIST.XJP_TUJIAN,
            LIST.XX_SXZL_QINGLONG,
            LIST.XX_SXZL_BAIHU,
            LIST.XX_SXZL_ZHUQUE,
            LIST.XX_SXZL_XUANWU,
            LIST.XJP_XZ_UPGRADE,
            LIST.XJP_XQ_UPGRADE
        },
        [ENTITY_PROP_REFINING_LEVEL] = {LIST.XJP_REINCARNATION_REFINING,LIST.XJP_REINCARNATION_UPGRADE},

        [ENTITY_PROP_DIVINE_SWORD_LEVEL] = {LIST.XJP_FULI_TOUZI_WEAPON, LIST.XJP_SHENJIAN_JIJIN, LIST.XJP_JJKH_2},
        [ENTITY_PROP_DIVINE_ARMOR_LEVEL] = {LIST.XJP_FULI_TOUZI_CLOTH, LIST.XJP_SHENJIA_JIJIN, LIST.XJP_JJKH_2},

        [ENTITY_PROP_HERALDRY_QINGLONG_LEVEL] = {LIST.XJP_HERALDRY, LIST.XJP_JJKH_1},
        [ENTITY_PROP_HERALDRY_BAIHU_LEVEL] = {LIST.XJP_HERALDRY, LIST.XJP_JJKH_1},
        [ENTITY_PROP_HERALDRY_ZHUQUE_LEVEL] = {LIST.XJP_HERALDRY, LIST.XJP_JJKH_1},
        [ENTITY_PROP_HERALDRY_XUANWU_LEVEL] = {LIST.XJP_HERALDRY, LIST.XJP_JJKH_1},
        [ENTITY_PROP_RECHARGE_GIFT_RECORD]  = {LIST.FIRST_CHARGE},
        [ENTITY_PROP_RECHARGE_MONEY]        = {LIST.FIRST_CHARGE},
        [ENTITY_PROP_RECHARGE_MONEY_EXT]    = {LIST.FIRST_CHARGE},
        [ENTITY_PROP_MAX_ATK] = {LIST.XJP_JJKH_3},
        [ENTITY_PROP_USE_NOT_BIND_LINGFU_NUM] = {LIST.XJP_JJKH_4},
        [ENTITY_PROP_FIND_TREASURE_PROGRESS] = {LIST.XJP_XUNBAO}, -- 寻宝进度
        [ENTITY_PROP_FIND_TREASURE_REWARD] = {LIST.XJP_XUNBAO}, -- 寻宝档位

        [ENTITY_PROP_BUY_MONSTER_KILL] = {LIST.XJP_KFHD_GWTJ}, -- 怪物通缉
        [ENTITY_PROP_SL_RED] = {LIST.XJP_SL_XY}, -- 神炉血玉
        [ENTITY_PROP_SL_SHIELD] = {LIST.XJP_SL_HD}, -- 神炉护盾
        [ENTITY_PROP_SL_GEM] = {LIST.XJP_SL_BS}, -- 神炉护盾
        [ENTITY_PROP_SL_SOUL] = {LIST.XJP_SL_HZ}, -- 神炉护盾

        [ENTITY_PROP_NTGM_DOULI_SCORE]   = {LIST.XX_SXZL_QINGLONG}, -- 逆天改命斗笠
        [ENTITY_PROP_NTGM_HUNDUN_SCORE]  = {LIST.XX_SXZL_BAIHU}, -- 逆天改命护盾
        [ENTITY_PROP_NTGM_YUPEI_SCORE]   = {LIST.XX_SXZL_ZHUQUE}, -- 逆天改命玉佩
        [ENTITY_PROP_NTGM_LONGHUN_SCORE] = {LIST.XX_SXZL_XUANWU}, -- 逆天改命龙魂
        [ENTITY_PROP_NTGM_DOULI_ACTIVIE]   = {LIST.XX_SXZL_QINGLONG}, -- 逆天改命斗笠
        [ENTITY_PROP_NTGM_HUNDUN_ACTIVIE]  = {LIST.XX_SXZL_BAIHU}, -- 逆天改命护盾
        [ENTITY_PROP_NTGM_YUPEI_ACTIVIE]   = {LIST.XX_SXZL_ZHUQUE}, -- 逆天改命玉佩
        [ENTITY_PROP_NTGM_LONGHUN_ACTIVIE] = {LIST.XX_SXZL_XUANWU}, -- 逆天改命龙魂

        -- [ENTITY_PROP_YBHS_DOUBLE] = {LIST.XJP_YBHS_DOUBLE,LIST.XJP_YBHS_SUIT,LIST.XJP_YBHS_1,LIST.XJP_YBHS_2,
        --                             LIST.XJP_YBHS_3,LIST.XJP_YBHS_4,LIST.XJP_YBHS_5,LIST.XJP_YBHS_6,LIST.XJP_YBHS_7,LIST.XJP_YBHS_8}, -- 元宝回收  双倍特权

        [ENTITY_PROP_XUNZHANG_SCORE] = {LIST.XJP_XZ_UPGRADE}, -- 勋章升级
        [ENTITY_PROP_XUNZHANG_ACTIVIE] = {LIST.XJP_XZ_UPGRADE}, -- 勋章升级

        [ENTITY_PROP_CHUMO_SCORE] = {LIST.XJP_FH_UPGRADE}, -- 封号升级
        [ENTITY_PROP_REBORN_POINTS] = {LIST.XJP_REINCARNATION_UPGRADE}, -- 转生红点
    },

    --玩家事件相关
    [REFRESH_RULE.PLAYER_EVENT] = {
        [EVENT_XYDZP_GRADE] = {LIST.XJP_KFHD_XYZP},
        [EVENT_XYDZP_REWARD] = {LIST.XJP_KFHD_XYZP},
        [EVENT_DBBK] = {LIST.XJP_DBBK},
        -- [EVENT_XBCS] = {LIST.XJP_XUNBAO},
        [EVENT_TZ_KILL] = {LIST.XJP_FULI_TOUZI_KILL},
        [EVENT_TZ_WEAPON] = {LIST.XJP_FULI_TOUZI_WEAPON, LIST.XJP_SHENJIAN_JIJIN},
        [EVENT_TZ_CLOTH] = {LIST.XJP_FULI_TOUZI_CLOTH, LIST.XJP_SHENJIA_JIJIN},
        [EVENT_TZ_LEVEL] = {LIST.XJP_FULI_TOUZI_LEVEL},
        [EVENT_TZ_REBORN] = {LIST.XJP_FULI_TOUZI_REBORN},
        -- [EVENT_ZP_COUNT] = {LIST.XJP_FULI_TURNTABLE}

        -- 勋章
        [EVENT_XUNZHANG_QUEST_COP_CNT] = {LIST.XJP_XZ_QUEST},
        [EVENT_XUNZHANG_QUEST_SELECT] = {LIST.XJP_XZ_QUEST},
        [EVENT_XUNZHANG_QUEST_INDEX1] = {LIST.XJP_XZ_QUEST},
        [EVENT_XUNZHANG_QUEST_INDEX2] = {LIST.XJP_XZ_QUEST},
        [EVENT_XUNZHANG_QUEST_INDEX3] = {LIST.XJP_XZ_QUEST},
        [EVENT_XUNZHANG_QUEST_INDEX4] = {LIST.XJP_XZ_QUEST},
    },

    --世界属性相关
    [REFRESH_RULE.WORLD_PROP] = {
        [WORLD_PROP_GUILD_STARTING_1] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_2] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_3] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_4] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_5] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_6] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_7] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_8] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_9] = {LIST.XJP_KFHD_JGLY},
        [WORLD_PROP_GUILD_STARTING_10] = {LIST.XJP_KFHD_JGLY},
    }
}

local function addRule(type, id, value)
    if not REFRESH_RULE_LIST[type][id] then
        REFRESH_RULE_LIST[type][id] = {}
    end
    for i, v in ipairs(REFRESH_RULE_LIST[type][id]) do
        if v == value then
            return
        end
    end
    table.insert(REFRESH_RULE_LIST[type][id], value)
end

----------------------------------------------------------player event start----------------------------------------------

--学院宝库每日任务
for i, v in ipairs(gdXueyuanBaokuDialyQuest) do
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventID, LIST.XY_BK_DIALY)
end
--学院宝库每周任务
for i, v in ipairs(gdXueyuanBaokuWeekQuest) do
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventID, LIST.XY_BK_MONTH)
end
--内置活动
for k, v in pairs(gdAllActivity) do
    if v.eventId then
        --开服活动
        if v.root == ACTIVITY_ROOT_OPEN then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_NEW_KFHD)
        --合服活动
        elseif v.root == ACTIVITY_ROOT_JOIN then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_NEW_HFHD)
        --内置活动
        elseif v.root == ACTIVITY_ROOT_INLAY then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_NZHD)
        --福利活动
        elseif v.root == ACTIVITY_ROOT_FULI then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_NEW_FULI)
        end
    end
    if v.eventExId then
        --开服活动
        if v.root == ACTIVITY_ROOT_OPEN then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventExId, LIST.XJP_NEW_KFHD)
        --合服活动
        elseif v.root == ACTIVITY_ROOT_JOIN then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventExId, LIST.XJP_NEW_HFHD)
        --内置活动
        elseif v.root == ACTIVITY_ROOT_INLAY then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventExId, LIST.XJP_NZHD)
        --福利活动
        elseif v.root == ACTIVITY_ROOT_FULI then
            addRule(REFRESH_RULE.PLAYER_EVENT, v.eventExId, LIST.XJP_NEW_FULI)
        end
    end
end
--战令
for i, v in ipairs(gdAllZhanling) do
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_ZHANGLING_REWARD)
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventExId, LIST.XJP_ZHANGLING_REWARD)
end
--战令任务
for i, v in ipairs(gdZhanlingTask) do
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_ZHANGLING_TASK)
end
-- 怪物通缉
for i, v in pairs(gdMonsterKill) do
    for kk, vv in ipairs(v) do
        addRule(REFRESH_RULE.PLAYER_EVENT, vv.eventId, LIST.XJP_KFHD_GWTJ)
    end
end
-- 装备首爆
for i, v in pairs(gdEquipFirstGet) do
    for kk, vv in ipairs(v) do
        addRule(REFRESH_RULE.PLAYER_EVENT, vv.eventId, LIST.XJP_KFHD_ZBSB)
    end
end
-- 装备回收
for i, v in pairs(gdEquipFirstRecovery) do
    for kk, vv in ipairs(v) do
        addRule(REFRESH_RULE.PLAYER_EVENT, vv.eventId, LIST.XJP_KFHD_ZBHS)
    end
end
-- 超级BOSS
for i, v in ipairs(gdSuperMap) do
    addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_SUPER_BOSS)
end

-- -- 元宝回收
-- for k = 1, #gdYBHSOnce do
--     for i, v in ipairs(gdYBHSOnce[k].equip) do
--         addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_YBHS_1+k-1)
--     end
-- end

-- for i, v in ipairs(gdYBHSSuit[1]) do
--     addRule(REFRESH_RULE.PLAYER_EVENT, v.eventId, LIST.XJP_YBHS_SUIT)
-- end
    

----------------------------------------------------------player event end------------------------------------------------

----------------------------------------------------------player prop start-----------------------------------------------
-- 合成系统相关
for k, v in pairs(gdItemComposeLimit) do
    addRule(REFRESH_RULE.PLAYER_PROP, v.propId, LIST.XJP_ITEM_COMPOSE)
end

for k, v in pairs(gdStaticAward) do
    for i, vv in ipairs(v) do
        if k == RANK_TYPE_WEN_ZHANG then
            addRule(REFRESH_RULE.PLAYER_PROP, vv.propId, LIST.XJP_JJKH_1)
        elseif k == RANK_TYPE_SHEN_JIAN_SHEN_JIA then
            addRule(REFRESH_RULE.PLAYER_PROP, vv.propId, LIST.XJP_JJKH_2)
        elseif k == RANK_TYPE_ATTACK then
            addRule(REFRESH_RULE.PLAYER_PROP, vv.propId, LIST.XJP_JJKH_3)
        elseif k == RANK_TYPE_USE_NOT_BIND_LINGFU then
            addRule(REFRESH_RULE.PLAYER_PROP, vv.propId, LIST.XJP_JJKH_4)
        end
    end
end

----------------------------------------------------------player prop end-----------------------------------------------

----------------------------------------------------------player item start-----------------------------------------------

-- 合成系统
for k, v in pairs(gdItemFormulaMap) do
    addRule(REFRESH_RULE.ITEM, k, LIST.XJP_ITEM_COMPOSE)
end

-- 魂器系统
for k, v in ipairs(gdHorcruxes) do
    for i = 1, #v.items do
        addRule(REFRESH_RULE.ITEM, v.items[i], LIST.XJP_GUARD_HORCRUXES + i)
        for j = 1,#gdSoulBeadsStars[v.items[i]] do
            addRule(REFRESH_RULE.ITEM, gdSoulBeadsStars[v.items[i]][j].costItem[1].item_sid, LIST.XJP_GUARD_HORCRUXES + i)
        end
    end
end

for index, value in ipairs(gdEquipTujian) do
    for k, v in pairs(value.equip) do
        addRule(REFRESH_RULE.ITEM, k, LIST.XJP_TUJIAN)
    end
end


-- 守护
addRule(REFRESH_RULE.ITEM, gdGuards[1].single_time_items.item_sid, LIST.XJP_GUARD_GUARD)

-- 魂珠
addRule(REFRESH_RULE.ITEM, gdSoulBeads[1].cost_items[1].item_sid, LIST.XJP_GUARD_SOUL)

-- 战旗
addRule(REFRESH_RULE.ITEM, gdWarFlags[1].cost_items[1].item_sid, LIST.XJP_GUARD_FLAG)

-- 转生炼体
for k, v in ipairs(gdReincarnationRefining) do
    addRule(REFRESH_RULE.ITEM, v.item_id, LIST.XJP_REINCARNATION_REFINING)
end

--魔纹融合
for k, v in pairs(gdMowen) do
    for kk, vv in pairs(v) do
        addRule(REFRESH_RULE.ITEM, vv.sid, LIST.MOWEN_RONGHE_EQUIP)
        addRule(REFRESH_RULE.ITEM, vv.sid, LIST.MOWEN_RONGHE_BAG)
    end
end

--宝石镶嵌
for sid, v in pairs(gdBaoShi) do
    addRule(REFRESH_RULE.ITEM, sid, LIST.BAOSHI)
end

-- 纹章
for k, v in ipairs(gdHeraldryOne[1].cost) do
    addRule(REFRESH_RULE.ITEM, v.item_id, LIST.XJP_HERALDRY)
end

for k, v in ipairs(gdHeraldryTwo[1].cost) do
    addRule(REFRESH_RULE.ITEM, v.item_id, LIST.XJP_HERALDRY)
end

for k, v in ipairs(gdHeraldryThree[1].cost) do
    addRule(REFRESH_RULE.ITEM, v.item_id, LIST.XJP_HERALDRY)
end

for k, v in ipairs(gdHeraldryFour[1].cost) do
    addRule(REFRESH_RULE.ITEM, v.item_id, LIST.XJP_HERALDRY)
end

-- 打宝宝库
local dbbk_item = {76126, 76127, 76128, 76129, 76130, 76131, 76132, 76133}
for k, v in ipairs(dbbk_item) do
    addRule(REFRESH_RULE.ITEM, v, LIST.XJP_DBBK)
end

--生肖合成
for i, v in ipairs(gdHCShengxiao) do
    local useItems = v.useItmes
    for ii, vv in ipairs(useItems) do
        addRule(REFRESH_RULE.ITEM, vv.sid, LIST.SX_HC)
    end
end

-- 法宝
for id, levelData in ipairs(gdFabaoLevelData) do
    addRule(REFRESH_RULE.PLAYER_PROP, ENTITY_PROP_REBORN, LIST.XJP_FABAO)
    for level, starData in ipairs(levelData) do
        for k, v in ipairs(starData) do
            local itemInfo = gdItems[v.cost1.itemId]
            if itemInfo and  itemInfo.cate == ITEM_CATEGORY_SPECIAL then
                addRule(REFRESH_RULE.CURRENCY, v.cost1.itemId, LIST.XJP_FABAO)
            else
                addRule(REFRESH_RULE.ITEM, v.cost1.itemId, LIST.XJP_FABAO)
            end
            local itemInfo = gdItems[v.cost2.itemId]
            if itemInfo and  itemInfo.cate == ITEM_CATEGORY_SPECIAL then
                addRule(REFRESH_RULE.CURRENCY, v.cost2.itemId, LIST.XJP_FABAO)
            else
                addRule(REFRESH_RULE.ITEM, v.cost2.itemId, LIST.XJP_FABAO)
            end
        end
    end
end
for id, levelData in ipairs(gdLingBaoLevelData) do
    addRule(REFRESH_RULE.PLAYER_PROP, ENTITY_PROP_REBORN, LIST.XJP_LINGBAO)
    for level, starData in ipairs(levelData) do
        for k, v in ipairs(starData) do
            local itemInfo = gdItems[v.cost1.itemId]
            if itemInfo and  itemInfo.cate == ITEM_CATEGORY_SPECIAL then
                addRule(REFRESH_RULE.CURRENCY, v.cost1.itemId, LIST.XJP_LINGBAO)
            else
                addRule(REFRESH_RULE.ITEM, v.cost1.itemId, LIST.XJP_LINGBAO)
            end
            local itemInfo = gdItems[v.cost2.itemId]
            if itemInfo and  itemInfo.cate == ITEM_CATEGORY_SPECIAL then
                addRule(REFRESH_RULE.CURRENCY, v.cost2.itemId, LIST.XJP_LINGBAO)
            else
                addRule(REFRESH_RULE.ITEM, v.cost2.itemId, LIST.XJP_LINGBAO)
            end
        end
    end
end
-- 雕纹 
for k,v in pairs(gdDiaoWenEquip) do
    addRule(REFRESH_RULE.ITEM, k, LIST.XJP_DIAOWEN_UPGRADE)
    -- addRule(REFRESH_RULE.ITEM, k, LIST.XJP_RONGLIAN_REPAIR)
end
-- 雕纹材料
for k,v in pairs(gdDiaoWenMaterial) do
    addRule(REFRESH_RULE.ITEM, k, LIST.XJP_DIAOWEN_UPGRADE)
    -- addRule(REFRESH_RULE.ITEM, k, LIST.XJP_RONGLIAN_REPAIR)
end

-- 仙器
for k,v in ipairs(gdXianQiData) do
    addRule(REFRESH_RULE.ITEM, v.equipID, LIST.XJP_XQ_UPGRADE)
    if v.reqItems then
        for reqKey, reqValue in ipairs(v.reqItems) do
            addRule(REFRESH_RULE.ITEM, reqValue.itemId, LIST.XJP_XQ_UPGRADE)
        end
    end
end

----------------------------------------------------------player item end-----------------------------------------------


----------------------------------------------------------world prop start-----------------------------------------------
-- 首杀
for i, v in ipairs(gdFirstBloodBossInfo or {}) do
    addRule(REFRESH_RULE.WORLD_PROP, v.highProp, LIST.XJP_FIRSTBLOOD)
    addRule(REFRESH_RULE.WORLD_PROP, v.lastProp, LIST.XJP_FIRSTBLOOD)
end
-- 超级BOSS
for i, v in ipairs(gdSuperMap) do
    addRule(REFRESH_RULE.WORLD_PROP, v.worldId, LIST.XJP_SUPER_BOSS)
end
----------------------------------------------------------world prop start-----------------------------------------------



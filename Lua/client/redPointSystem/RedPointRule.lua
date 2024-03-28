CONDITION = {
    SWITCH = 1,             -- 开关
    SERVER_DAY = 2,         -- 开服天数
    VIP = 3,                -- VIP等级
    LV = 4,                 -- 玩家等级
    REBORN = 5,             -- 玩家转生等级
    RED_POINT_FUNCTION = 6, -- 红点功能函数function
    QUEST = 7
}

-- 红点总列表
LIST = {
    NONE                       = 0,
    XY_BK                      = 1,  -- 学院宝库
    XY_BK_DIALY                = 2,  -- 学院宝库每日任务
    XY_BK_MONTH                = 3,  -- 学院宝库每月任务
    XJP_SSJJ                   = 4,  -- 神圣剑甲
    XJP_SSJJ_DIVINE_SWORD      = 5,  -- 神圣剑甲 神剑
    XJP_SSJJ_DIVINE_ARMOR      = 6,  -- 神圣剑甲 神甲
    XJP_SSJJ_HOLY_SWORD        = 7,  -- 神圣剑甲 圣剑
    XJP_SSJJ_HOLY_ARMOR        = 8,  -- 神圣剑甲 圣甲
    HC                         = 10, -- 合成
    XJP_ITEM_COMPOSE           = 11, -- 材料合成
    XJP_GUARD                  = 12, -- 守护
    XJP_GUARD_GUARD            = 13, -- 守护 守护
    XJP_GUARD_SOUL             = 14, -- 守护 魂珠
    XJP_GUARD_FLAG             = 15, -- 守护 战旗
    XJP_GUARD_HORCRUXES        = 16, -- 守护 魂器
    XJP_GUARD_HORCRUXES_1      = 17, -- 守护 魂器1阶
    XJP_GUARD_HORCRUXES_2      = 18, -- 守护 魂器2阶
    XJP_GUARD_HORCRUXES_3      = 19, -- 守护 魂器3阶
    XJP_GUARD_HORCRUXES_4      = 20, -- 守护 魂器4阶
    XJP_GUARD_HORCRUXES_5      = 21, -- 守护 魂器5阶
    XJP_GUARD_HORCRUXES_6      = 22, -- 守护 魂器6阶
    PROMOTE                    = 23, -- 提升助手
    ENHANCE                    = 24, -- 强化
    ENHANCE_EQUIP              = 25, -- 装备强化
    ENHANCE_SHENSHI            = 26, -- 神饰强化
    XJP_REINCARNATION          = 27, -- 转生炼体
    XJP_REINCARNATION_UPGRADE  = 28, -- 转生升级
    XJP_REINCARNATION_REFINING = 29, -- 炼体
    MOWEN_RONGHE               = 30, -- 魔纹融合
    MOWEN_RONGHE_EQUIP         = 31, -- 魔纹融合装备
    MOWEN_RONGHE_BAG           = 32, -- 魔纹融合背包
    EQUIP_DUANZAO              = 33, -- 锻造
    BAOYU                      = 34, -- 宝玉
    BAOSHI                     = 35, -- 宝石
    BAG                        = 36, -- 背包
    BAG_1                      = 37,
    BAG_2                      = 38,
    BAG_3                      = 39,
    BAG_4                      = 40,

    XJP_KFHD                   = 41,  -- 开服活动
    XJP_NEW_KFHD               = 42,  -- 新开服活动
    XJP_KFHD_ZSDH              = 43,  -- 钻石兑换
    XJP_KFHD_GWTJ              = 48,  -- 怪物通缉
    XJP_KFHD_ZBSB              = 49,  -- 装备首爆
    XJP_KFHD_ZBHS              = 50,  -- 装备回收
    XJP_KFHD_XYZP              = 54,  -- 幸运转盘
    XJP_KFHD_JGLY              = 56,  -- 建功立业
    XJP_FABAO_MAIN             = 65,  -- 法宝
    XJP_FABAO                  = 66,  -- 法宝
    XJP_LINGBAO                = 67,  -- 灵宝

    XJP_HFHD                   = 70,  -- 合服活动
    XJP_NEW_HFHD               = 71,  -- 新合服活动
    XJP_HFHD_DBCZ              = 72,  -- 多倍充值

    XJP_NZHD                   = 80,  -- 内置活动
    XJP_YYHD                   = 81,  -- 运营活动

    XJP_KFHD_GCZ               = 90,  -- 攻城战
    XJP_HERALDRY               = 91,  -- 纹章
    SX_HC                      = 92,  -- 生肖合成
    XJP_DBBK                   = 93,  -- 打宝宝库
    FIRST_CHARGE               = 94,  -- 首充
    XJP_ZHANGLING              = 95,  -- 战令
    XJP_ZHANGLING_REWARD       = 96,  -- 战令奖励
    XJP_ZHANGLING_TASK         = 97,  -- 战令任务
    XJP_XUNBAO                 = 98,  -- 寻宝
    XJP_FIRSTBLOOD             = 99,  -- 首杀
    XJP_DABAO_BOSS             = 100, -- 打宝BOSS
    XJP_DABAO_BOSS_1           = 101, -- 野外BOSS
    XJP_DABAO_BOSS_2           = 102, -- 个人BOSS
    XJP_DABAO_BOSS_3           = 103, -- BOSS积分

    XJP_FULI                   = 110, -- 福利
    XJP_NEW_FULI               = 111, -- 福利活动
    XJP_FULI_TOUZI             = 112, -- 投资
    XJP_FULI_TOUZI_KILL        = 113,
    XJP_FULI_TOUZI_WEAPON      = 114,
    XJP_FULI_TOUZI_CLOTH       = 115,
    XJP_FULI_TOUZI_LEVEL       = 116,
    XJP_FULI_TOUZI_REBORN      = 117,
    XJP_KFHD_SLZL              = 118, -- 神龙之力
    XJP_FULI_TURNTABLE         = 120, -- 转盘
    XJP_JJKH                   = 121, --竞技狂欢
    XJP_JJKH_1                 = 122,
    XJP_JJKH_2                 = 123,
    XJP_JJKH_3                 = 124,
    XJP_JJKH_4                 = 125,
    XJP_JJKH_5                 = 126,
    XJP_SHENJIAN_JIJIN         = 127,
    XJP_SHENJIA_JIJIN          = 128,
    XJP_EQUIP_NPC_FORGE        = 129, -- NPC装备锻造
    XJP_EQUIP_NPC_COMPOSE      = 130, -- NPC装备合成
    XJP_SHENSHI_NPC_COMPOSE    = 131, -- NPC神饰合成
    XJP_MOWEN_NPC_COMPOSE      = 132, -- NPC魔纹合成
    XJP_MAGIC_NPC_COMPOSE      = 133, -- NPC魔器合成

    UNREADCHAT_1               = 136,
    UNREADCHAT_2               = 137,
    UNREADCHAT_3               = 138,
    UNREADCHAT_4               = 139,
    UNREADCHAT_5               = 140,
    UNREADCHAT_6               = 141,
    XJP_SUPER_BOSS             = 142,
    XJP_GHLC                   = 143,

    XJP_SL                     = 144, --神炉
    XJP_SL_XY                  = 145, --神炉 血玉
    XJP_SL_HD                  = 146, --神炉 护盾
    XJP_SL_BS                  = 147, --神炉 宝石
    XJP_SL_HZ                  = 148, --神炉 魂珠
    XJP_TUJIAN                 = 149, --图鉴
    XJP_TUJIAN_MAIN            = 150, -- 图鉴main

    XJP_RONGYU_SHENGXING       = 151, -- 荣誉升星

    XX_SXZL                    = 152, -- 四象之力
    XX_SXZL_QINGLONG           = 153, -- 四象之力 青龙
    XX_SXZL_BAIHU              = 154, -- 四象之力 白虎
    XX_SXZL_ZHUQUE             = 155, -- 四象之力 朱雀
    XX_SXZL_XUANWU             = 156, -- 四象之力 玄武

    -- XJP_YBHS                   = 157, -- 元宝回收 总
    -- XJP_YBHS_SUIT              = 158, -- 元宝回收 套装
    -- XJP_YBHS_ONCE              = 159, -- 元宝回收 单件
    -- XJP_YBHS_DOUBLE            = 160, -- 元宝回收 双倍
    -- XJP_YBHS_1                 = 161, -- 元宝回收 单件
    -- XJP_YBHS_2                 = 162,
    -- XJP_YBHS_3                 = 163,
    -- XJP_YBHS_4                 = 164,
    -- XJP_YBHS_5                 = 165,
    -- XJP_YBHS_6                 = 166,
    -- XJP_YBHS_7                 = 167,
    -- XJP_YBHS_8                 = 168,

    XJP_XZ                     = 170, --勋章
    XJP_XZ_QUEST               = 171, --勋章任务
    XJP_XZ_UPGRADE             = 172, --勋章升级

    XJP_FH_UPGRADE             = 173, --封号升级

    XJP_ZHANDUISAI             = 174, --战队赛
    XJP_KF3V3_HAIXUAN          = 175,
    XJP_KF3V3_HAIXUAN_ZHANDUI  = 176,
    XJP_KF3V3_JINJI            = 177,
    XJP_KF3V3_JINJI_ZHANDUI    = 178,
    XJP_ZHANDUI                = 179,
    XJP_ZHANDUI_APP            = 180, --申请入队

    XJP_GUILD                  = 190, --行会
    XJP_GUILD_INFO             = 191, --行会信息
    XJP_GUILD_MEMBER           = 192, --行会成员
    XJP_GUILD_RED_PACKET       = 193, --行会红包
    XJP_GUILD_LIST             = 194, --行会列表

    XX_JINGJIE                 = 200, --境界
    XX_JINGJIE_JINGJIE         = 201, --境界
    XX_JINGJIE_JINGJIE_TIXIU   = 202, --境界体修
    XX_JINGJIE_JINGJIE_FAXIU   = 203, --境界法修
    XX_JINGJIE_TIANFU          = 204, --境界天赋

    XJP_XQ_UPGRADE             = 205, --仙器升级
    XJP_KFHD_YBZP              = 206, --元宝转盘

    VIP_ALL                    = 449,
    MDS_VIP_BEGIN              = 450,
    MDS_VIP_END                = 500,

    XJP_DIAOWEN               = 501, --雕纹
    XJP_DIAOWEN_UPGRADE       = 502, --雕纹升级
    XJP_RONGLIAN_REPAIR        = 503, --雕纹修复

    SKILL                      = 504,
    SKILL_LEVEL                = 505,
    MAX                        = 506
}

-- 红点组合结构
RULE_COMPOSE = {
    --竞技狂欢
    [LIST.XJP_JJKH] = { LIST.XJP_JJKH_1, LIST.XJP_JJKH_2, LIST.XJP_JJKH_3, LIST.XJP_JJKH_4, LIST.XJP_JJKH_5 },
    --合成
    [LIST.HC] = { LIST.XJP_ITEM_COMPOSE },
    -- 背包
    [LIST.BAG] = { LIST.BAG_1, LIST.BAG_2, LIST.BAG_3, LIST.BAG_4 },
    -- 提升助手
    [LIST.PROMOTE] = { LIST.XJP_HERALDRY, LIST.XJP_GUARD_GUARD, LIST.XJP_GUARD_SOUL, LIST.XJP_GUARD_FLAG,
        LIST.XJP_GUARD_HORCRUXES, LIST.HC, LIST.ENHANCE, LIST.MOWEN_RONGHE, LIST.BAOYU, LIST.XJP_REINCARNATION,
        LIST.XJP_EQUIP_NPC_FORGE, LIST.XJP_EQUIP_NPC_COMPOSE, LIST.XJP_SHENSHI_NPC_COMPOSE, LIST.XJP_MOWEN_NPC_COMPOSE,
        LIST.XJP_MAGIC_NPC_COMPOSE, LIST.SX_HC, LIST.XJP_SL, LIST.XJP_TUJIAN, LIST.XJP_XZ_UPGRADE, LIST.XJP_XQ_UPGRADE,
        LIST.XJP_FH_UPGRADE, LIST.XX_SXZL, LIST.XJP_DABAO_BOSS_3, LIST.XJP_DIAOWEN, LIST.SKILL },
    -- 宝玉
    [LIST.BAOYU] = { LIST.BAOSHI },
    -- 魔纹融合
    [LIST.MOWEN_RONGHE] = { LIST.MOWEN_RONGHE_EQUIP, LIST.MOWEN_RONGHE_BAG },
    -- 强化
    [LIST.ENHANCE] = { LIST.ENHANCE_EQUIP, LIST.ENHANCE_SHENSHI },
    -- 锻造
    [LIST.EQUIP_DUANZAO] = { LIST.ENHANCE, LIST.MOWEN_RONGHE, LIST.XJP_DIAOWEN },
    -- 学院宝库
    [LIST.XY_BK] = { LIST.XY_BK_DIALY, LIST.XY_BK_MONTH },
    -- 神圣剑甲
    [LIST.XJP_SSJJ] = { LIST.XJP_SSJJ_DIVINE_SWORD, LIST.XJP_SSJJ_DIVINE_ARMOR, LIST.XJP_SSJJ_HOLY_SWORD, LIST
        .XJP_SSJJ_HOLY_ARMOR },
    -- 开服活动
    [LIST.XJP_KFHD] = { LIST.XJP_NEW_KFHD, LIST.XJP_KFHD_ZSDH, LIST.XJP_KFHD_ZBSB, LIST.XJP_KFHD_GCZ, LIST.XJP_KFHD_JGLY,
        LIST.XJP_JJKH,
        LIST.XJP_KFHD_SLZL },
    -- 合服活动
    [LIST.XJP_HFHD] = { LIST.XJP_NEW_HFHD, LIST.XJP_HFHD_DBCZ },
    -- 战令
    [LIST.XJP_ZHANGLING] = { LIST.XJP_ZHANGLING_REWARD, LIST.XJP_ZHANGLING_TASK },
    -- 打宝BOSS
    [LIST.XJP_DABAO_BOSS] = { LIST.XJP_DABAO_BOSS_1, LIST.XJP_DABAO_BOSS_2, LIST.XJP_DABAO_BOSS_3 },
    -- 福利
    [LIST.XJP_FULI] = { LIST.XJP_NEW_FULI, LIST.XJP_FULI_TOUZI, LIST.XJP_FULI_TURNTABLE, LIST.XJP_KFHD_GWTJ, LIST
        .XJP_KFHD_ZBHS, LIST.XJP_KFHD_XYZP },
    -- 投资
    [LIST.XJP_FULI_TOUZI] = { LIST.XJP_FULI_TOUZI_KILL, LIST.XJP_FULI_TOUZI_WEAPON, LIST.XJP_FULI_TOUZI_CLOTH,
        LIST.XJP_FULI_TOUZI_LEVEL, LIST.XJP_FULI_TOUZI_REBORN },
    -- 守护
    [LIST.XJP_GUARD] = { LIST.XJP_GUARD_GUARD, LIST.XJP_GUARD_SOUL, LIST.XJP_GUARD_FLAG },
    [LIST.XJP_GUARD_HORCRUXES] = { LIST.XJP_GUARD_HORCRUXES_1, LIST.XJP_GUARD_HORCRUXES_2, LIST.XJP_GUARD_HORCRUXES_3,
        LIST.XJP_GUARD_HORCRUXES_4, LIST.XJP_GUARD_HORCRUXES_5, LIST.XJP_GUARD_HORCRUXES_6 },
    [LIST.XJP_REINCARNATION] = { LIST.XJP_REINCARNATION_REFINING, LIST.XJP_REINCARNATION_UPGRADE }, -- 转生
    -- 法宝
    [LIST.XJP_FABAO_MAIN] = { LIST.XJP_FABAO, LIST.XJP_LINGBAO },
    [LIST.XJP_SL] = { LIST.XJP_SL_XY, LIST.XJP_SL_HD, LIST.XJP_SL_BS, LIST.XJP_SL_HZ },
    [LIST.XJP_TUJIAN_MAIN] = { LIST.XJP_TUJIAN },
    -- 四象之力
    [LIST.XX_SXZL] = { LIST.XX_SXZL_QINGLONG, LIST.XX_SXZL_BAIHU, LIST.XX_SXZL_ZHUQUE, LIST.XX_SXZL_XUANWU },
    -- -- 元宝回收
    -- [LIST.XJP_YBHS] = { LIST.XJP_YBHS_SUIT, LIST.XJP_YBHS_ONCE, LIST.XJP_YBHS_DOUBLE },
    -- [LIST.XJP_YBHS_ONCE] = { LIST.XJP_YBHS_1, LIST.XJP_YBHS_2, LIST.XJP_YBHS_3, LIST.XJP_YBHS_4, LIST.XJP_YBHS_5, LIST
    --     .XJP_YBHS_6, LIST.XJP_YBHS_7, LIST.XJP_YBHS_8 },
    -- 勋章
    [LIST.XJP_XZ] = { LIST.XJP_XZ_QUEST, LIST.XJP_XZ_UPGRADE },
    -- 行会
    [LIST.XJP_GUILD] = { LIST.XJP_GUILD_INFO, LIST.XJP_GUILD_MEMBER, LIST.XJP_GUILD_RED_PACKET, LIST.XJP_GUILD_LIST },
    -- 雕纹
    [LIST.XJP_DIAOWEN] = { LIST.XJP_DIAOWEN_UPGRADE },
    --跨服3V3
    [LIST.XJP_ZHANDUISAI] = { LIST.XJP_KF3V3_HAIXUAN, LIST.XJP_KF3V3_JINJI },
    [LIST.XJP_KF3V3_HAIXUAN] = { LIST.XJP_KF3V3_HAIXUAN_ZHANDUI },
    [LIST.XJP_KF3V3_JINJI] = { LIST.XJP_KF3V3_JINJI_ZHANDUI },
    [LIST.XJP_KF3V3_HAIXUAN_ZHANDUI] = { LIST.XJP_ZHANDUI },
    [LIST.XJP_KF3V3_JINJI_ZHANDUI] = { LIST.XJP_ZHANDUI },
    [LIST.XJP_ZHANDUI] = { LIST.XJP_ZHANDUI_APP },
    [LIST.SKILL] = { LIST.SKILL_LEVEL },

    -- 境界
    [LIST.XX_JINGJIE] = { LIST.XX_JINGJIE_JINGJIE, LIST.XX_JINGJIE_TIANFU },
    [LIST.XX_JINGJIE_JINGJIE] = { LIST.XX_JINGJIE_JINGJIE_TIXIU, LIST.XX_JINGJIE_JINGJIE_FAXIU },

}

RULE_COMPOSE[LIST.VIP_ALL] = {}
for i = LIST.MDS_VIP_BEGIN, LIST.MDS_VIP_END do
    table.insert(RULE_COMPOSE[LIST.VIP_ALL], i)
end
-- 红点详细条件
RED_POINT_RULE = {
    [LIST.SX_HC] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shengxiaohecheng") then
                return false
            end
            for i, v in ipairs(gdHCShengxiao) do
                local canHC = true
                for ii, vv in ipairs(v.useItmes) do
                    local sid = vv.sid
                    local count = vv.counts
                    if sid == ITEM_INGOT_ALL then
                        local suitId = MyRole.getProp(ENTITY_PROP_SHENGXIAO_SUIT_ID)
                        if gdZodiacSuit[suitId] then
                            local hecheng = gdZodiacSuit[suitId].hecheng
                            if hecheng > 0 then
                                local num = count * (1 - hecheng / 10000)
                                count = math.floor(tonumber(tostring(num)))
                            end
                        end
                    end

                    if gdItems[sid] and gdItems[sid].cate == ITEM_CATEGORY_EQUIP and gdItems[sid].type and gdItems[sid].type >= EQUIP_TYPE_SHENGXIAO_1 and gdItems[sid].type <= EQUIP_TYPE_SHENGXIAO_12 then
                        if MyRole.getItemCountBySid(sid) == 0 then
                            local equiped = MyItemData:getItemByPosition(-gdItems[sid].type)
                            if not equiped then
                                canHC = false
                                break
                            else
                                if equiped.sid ~= v.oldSid then
                                    canHC = false
                                    break
                                end
                            end
                        end
                    else
                        if not MyRole.haveEnoughItem(sid, count) then
                            canHC = false
                            break
                        end
                    end
                end
                if canHC then
                    return true
                end
            end
            return false
        end
    },
    [LIST.BAOSHI] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("baoshi") then
                return false
            end
            local baoshiList = {}
            for position = PLAYER_BAG_BEGIN, ITEM_BAG.getEndIndex(PLAYER_BAG_BEGIN) do
                local userItem = MyItemData:getItemByPosition(position)
                if userItem and userItem.item and userItem.item.cate == ITEM_CATEGORY_STONE then
                    table.insert(baoshiList, userItem)
                end
            end

            for pos = EQUIP_PROP_BAOSHI_START, EQUIP_PROP_BAOSHI_END do
                for position = EQUIP_POS_BEGIN, EQUIP_POS_END, -1 do
                    if MyItemData:getItemByPosition(position) then
                        local sid = MyRole.getProp(position * 100 - pos)
                        for i, baoshi in ipairs(baoshiList) do
                            if gdBaoShi[baoshi.sid].pos == pos then
                                if sid <= 0 then
                                    return true
                                else
                                    if gdBaoShi[baoshi.sid].level > gdBaoShi[sid].level then
                                        return true
                                    end
                                end
                            end
                        end
                    end
                end
            end

            for pos = EQUIP_PROP_BAOSHI_START, EQUIP_PROP_BAOSHI_END do
                for position = EQUIP_POS_SHEN_SHI_BEGIN, EQUIP_POS_SHEN_SHI_END, -1 do
                    if MyItemData:getItemByPosition(position) then
                        local sid = MyRole.getProp(position * 100 - pos)
                        for i, baoshi in ipairs(baoshiList) do
                            if gdBaoShi[baoshi.sid].pos == pos then
                                if sid <= 0 then
                                    return true
                                else
                                    if gdBaoShi[baoshi.sid].level > gdBaoShi[sid].level then
                                        return true
                                    end
                                end
                            end
                        end
                    end
                end
            end
            return false
        end
    },

    [LIST.MOWEN_RONGHE_EQUIP] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("ronghe") then
                return false
            end
            for position = EQUIP_POS_BEGIN, EQUIP_POS_END, -1 do
                if position ~= EQUIP_POS_WUQI and position ~= EQUIP_POS_YIFU then
                    local userItem = MyItemData:getItemByPosition(position)
                    if userItem and userItem.item and userItem.data and userItem.data[ITEM_PROP_MOWEN_ID] == 0 and
                        gdMowen[userItem.item.type] then
                        for k, v in pairs(gdMowen[userItem.item.type]) do
                            if MyRole.getItemCountBySid(v.sid) > 0 then
                                return true
                            end
                        end
                    end
                end
            end
            return false
        end
    },

    [LIST.MOWEN_RONGHE_BAG] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("ronghe") then
                return false
            end
            for position = PLAYER_BAG_BEGIN, ITEM_BAG.getEndIndex(PLAYER_BAG_BEGIN), 1 do
                local userItem = MyItemData:getItemByPosition(position)
                if userItem and userItem.item and userItem.item.cate == ITEM_CATEGORY_EQUIP and
                    gdMowen[userItem.item.type] and userItem.data and userItem.data[ITEM_PROP_MOWEN_ID] == 0 then
                    for k, v in pairs(gdMowen[userItem.item.type]) do
                        if MyRole.getItemCountBySid(v.sid) > 0 then
                            return true
                        end
                    end
                end
            end
            return false
        end
    },

    -- [LIST.PROMOTE] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return true
    --     end
    -- },

    [LIST.XY_BK_DIALY] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for i, v in ipairs(gdXueyuanBaokuDialyQuest) do
                local datay = MyActivityData:getExDataY(v.eventID)
                local dataz = MyActivityData:getExDataZ(v.eventID)
                if dataz < 1 and datay >= v.datax then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XY_BK_MONTH] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for i, v in ipairs(gdXueyuanBaokuWeekQuest) do
                local datay = MyActivityData:getExDataY(v.eventID)
                if v.type == 3 or v.type == 4 then -- 月累计登录 和充值任务
                    datay = datay % 100
                end

                local dataz = MyActivityData:getExDataZ(v.eventID)
                if dataz < 1 and datay >= v.datax then
                    return true
                end
            end
            return false
        end
    },
    [LIST.ENHANCE_EQUIP] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("zhuangbeiqianghua") then
                return false
            end
            for position = EQUIP_POS_BEGIN, EQUIP_POS_END, -1 do
                local userItem = MyItemData:getItemByPosition(position)
                if userItem then
                    local curLevel = MyRole.getProp(position * 100 - EQUIP_PROP_JING_LIAN)
                    local nextInfo = gdJinglian[position][curLevel + 1]
                    if nextInfo and nextInfo.useItems then
                        local canEnhance = true
                        for i, item in ipairs(nextInfo.useItems) do
                            if MyRole.getItemCountBySid(item.sid) < item.counts then
                                canEnhance = false
                            end
                        end
                        if canEnhance then
                            return true
                        end
                    end
                end
            end
            return false
        end
    },
    [LIST.ENHANCE_SHENSHI] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenqizhuzao") then
                return false
            end

            for position = EQUIP_POS_ARTIFACT_BEGIN, EQUIP_POS_ARTIFACT_END, -1 do
                local userItem = MyItemData:getItemByPosition(position)
                if userItem then
                    local curLevel = MyRole.getProp(position * 100 - EQUIP_PROP_JING_LIAN)
                    local nextInfo = gdJinglian[position][curLevel + 1]
                    if nextInfo and nextInfo.useItems then
                        local canEnhance = true
                        for i, item in ipairs(nextInfo.useItems) do
                            if MyRole.getItemCountBySid(item.sid) < item.counts then
                                canEnhance = false
                            end
                        end
                        if nextInfo.level > 20 and not funcHelper.isOpen("qianghuasanshi") then
                            canEnhance = false
                        end
                        if canEnhance then
                            return true
                        end
                    end
                end
            end
            return false
        end
    },
    [LIST.XJP_SSJJ_DIVINE_SWORD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenjian") then
                return false
            end
            local ingot = MyRole.getCaptital(Captital.INGOT) + MyRole.getCaptital(Captital.BOUNDINGOT)
            local level = MyRole.getProp(ENTITY_PROP_DIVINE_SWORD_LEVEL) + 1
            if gdDivineSword[level] and gdDivineSword[level].item_count <= ingot then
                return true
            end
            return false
        end
    },
    [LIST.XJP_SSJJ_DIVINE_ARMOR] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenjia") then
                return false
            end
            local ingot = MyRole.getCaptital(Captital.INGOT) + MyRole.getCaptital(Captital.BOUNDINGOT)
            local level = MyRole.getProp(ENTITY_PROP_DIVINE_ARMOR_LEVEL) + 1
            if gdDivineArmor[level] and gdDivineArmor[level].item_count <= ingot then
                return true
            end
            return false
        end
    },
    [LIST.XJP_SSJJ_HOLY_SWORD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shengjian") then
                return false
            end
            local level = MyRole.getProp(ENTITY_PROP_HOLY_SWORD_LEVEL) + 1
            if gdHolySword[level] and gdHolySword[level].item_count <=
                MyRole.getItemCountBySid(gdHolySword[level].item_id) then
                return true
            end
            return false
        end
    },
    [LIST.XJP_SSJJ_HOLY_ARMOR] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shengjia") then
                return false
            end
            local level = MyRole.getProp(ENTITY_PROP_HOLY_ARMOR_LEVEL) + 1
            if gdHolyArmor[level] and gdHolyArmor[level].item_count <=
                MyRole.getItemCountBySid(gdHolyArmor[level].item_id) then
                return true
            end
            return false
        end
    },

    -- 新开服活动
    [LIST.XJP_NEW_KFHD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activities = ActivityHelper.getOpenActivities()
            for k, v in pairs(activities) do
                local sd = ActivityHelper.ActivityMenu[v.type]
                if sd and sd.attention and sd.attention(v.id) then
                    return true
                end
            end
            return false
        end
    },

    -- 新合服活动
    [LIST.XJP_NEW_HFHD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activities = ActivityHelper.getJoinActivities()
            for k, v in pairs(activities) do
                local sd = ActivityHelper.ActivityMenu[v.type]
                if sd and sd.attention and sd.attention(v.id) then
                    return true
                end
            end
            return false
        end
    },

    -- 内置活动
    [LIST.XJP_NZHD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activities = ActivityHelper.getInlayActivities()
            for k, v in pairs(activities) do
                local sd = ActivityHelper.ActivityMenu[v.type]
                if sd and sd.attention and sd.attention(v.id) then
                    return true
                end
            end
            return false
        end
    },

    -- 福利活动
    [LIST.XJP_NEW_FULI] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activities = ActivityHelper.getFuliActivities()
            for k, v in pairs(activities) do
                local sd = ActivityHelper.ActivityMenu[v.type]
                if sd and sd.attention and sd.attention(v.id) then
                    return true
                end
            end
            return false
        end
    },

    -- 钻石兑换
    [LIST.XJP_KFHD_ZSDH] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activity = ActivityHelper.getActivityByType(HOLIDAY_ZSDH)
            if activity and gdDiamondExchange[activity.id] then
                local total = MyRole.getProp(ENTITY_PROP_DIAMONDS_VALUE)
                for i = #gdDiamondExchange[activity.id], 1, -1 do
                    local data = gdDiamondExchange[activity.id][i]
                    if data.cost <= total then
                        local has_count = MyActivityData:getExDataX(data.eventId)
                        if has_count < data.limit then
                            return true
                        end
                    end
                end
            end
            return false
        end
    },

    -- 怪物通缉
    [LIST.XJP_KFHD_GWTJ] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activity = ActivityHelper.getActivityByType(HOLIDAY_GWTJ)
            if activity and gdMonsterKill[activity.id] then
                for k, v in ipairs(gdMonsterKill[activity.id]) do
                    local count = MyActivityData:getExDataX(v.eventId)
                    if count >= v.count then
                        if MyActivityData:getExDataY(v.eventId) <= 0 then
                            return true
                        end
                        if MyRole.getProp(ENTITY_PROP_BUY_MONSTER_KILL) >= 1 then
                            if MyActivityData:getExDataZ(v.eventId) <= 0 then
                                return true
                            end
                        end
                    end
                end
            end

            return false
        end
    },

    -- 装备首爆
    [LIST.XJP_KFHD_ZBSB] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activity = ActivityHelper.getActivityByType(HOLIDAY_ZBSB)
            if activity and gdEquipFirstGet[activity.id] then
                for k, v in ipairs(gdEquipFirstGet[activity.id]) do
                    local count = MyActivityData:getWorldDataX(v.worldId)
                    local isHave = MyActivityData:getExDataX(v.eventId)
                    local isGet = MyActivityData:getExDataY(v.eventId)
                    if count < v.limit and isHave > 0 and isGet <= 0 then
                        return true
                    end
                end
            end
            return false
        end
    },

    -- 装备回收
    [LIST.XJP_KFHD_ZBHS] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activity = ActivityHelper.getActivityByType(HOLIDAY_ZBHS)
            if activity and gdEquipFirstRecovery[activity.id] then
                for k, v in ipairs(gdEquipFirstRecovery[activity.id]) do
                    local count = MyActivityData:getWorldDataX(v.worldId)
                    local isGet = MyActivityData:getExDataY(v.eventId)
                    -- 判断背包中是否有该物品
                    local num = MyItemData:getItemCountBySid(v.equipId)
                    if count < v.limit and num > 0 and isGet <= 0 then
                        return true
                    end
                end
            end
            return false
        end
    },

    -- 神龙之力
    [LIST.XJP_KFHD_SLZL] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local activity = ActivityHelper.getActivityByType(HOLIDAY_SLZL)
            if activity then
                if MyActivityData:getExDataX(activity.eventId) > 0 then
                    return false
                end
                if not getNoConfirm("buy_slzl_buff") then
                    return true
                end
            end
            return false
        end
    },

    -- 建功立业
    [LIST.XJP_KFHD_JGLY] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("gonghui") then
                return false
            end
            if JIANGONGLIYE_LOOK then
                return false
            end
            return rewardHelper.check_guild_jgly_red()
        end
    },

    -- 大转盘
    [LIST.XJP_KFHD_XYZP] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            -- if funcHelper.activityIsOpen(ACTIVITY_XYZP) then
            --     local num = MyActivityData:getExDataX(EVENT_XYDZP_REWARD)
            --     local numL = num % 100
            --     local numH = math.floor(num / 100)
            --     if numH <= 0 then
            --         numH = 1
            --     end

            --     if numH > #gdTurntableGrades then
            --         numH = #gdTurntableGrades
            --         numL = gdTurntableGrades[#gdTurntableGrades].count
            --     else
            --         if numL >= gdTurntableGrades[numH].count then
            --             numH = numH + 1
            --             numL = 0
            --         end
            --     end

            --     if numH <= #gdTurntableGrades then
            --         local allCount = CommonHelper.calTurnTableCount(MyActivityData:getExDataZ(EVENT_XYDZP_GRADE))
            --         local useCount = CommonHelper.calTurnTableCount(numH, numL)
            --         return MyRole.checkLingFu(gdTurntableGrades[numH].base) and allCount - useCount > 0
            --     end
            -- end
            return false
        end
    },

    -- 多倍充值
    [LIST.XJP_HFHD_DBCZ] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return false
        end
    },

    -- 战令奖励
    [LIST.XJP_ZHANGLING_REWARD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for _, v in ipairs(gdAllZhanling) do
                if rewardHelper.check_zhanling_reward_redpoint(v) then
                    return true
                end
            end
            return false
        end
    },

    -- 战令任务
    [LIST.XJP_ZHANGLING_TASK] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for k, v in ipairs(gdZhanlingTask) do
                local datax = MyActivityData:getExDataX(v.eventId)
                -- 在线时长
                if k == gdZhanlingType.zl_online then
                    datax = math.floor(datax / 60)
                end
                datax = datax >= v.count and v.count or datax
                if datax >= v.count then
                    if MyActivityData:getExDataY(v.eventId) <= 0 then
                        return true
                    end
                end
            end
            return false
        end
    },

    -- 寻宝
    [LIST.XJP_XUNBAO] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local count = MyRole.getProp(ENTITY_PROP_FIND_TREASURE_PROGRESS) or 0
            local reward_grede = MyRole.getProp(ENTITY_PROP_FIND_TREASURE_REWARD) or 0 --档位领取情况 二进制存储
            local show_red = false
            for i, v in ipairs(gdXunbaoProgressReward) do
                local status = count >= v.progress
                if status then
                    -- 判断有没有领取过
                    local got_state = bit.lshift(1, (i - 1))
                    got_state = bit.band(reward_grede, got_state)
                    if got_state ~= 0 then
                        status = false
                    end
                    if status then
                        show_red = true
                        break
                    end
                end
            end

            return show_red
        end
    },

    -- 转生投资
    [LIST.XJP_FULI_TOUZI_REBORN] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays < gdFuliType[FULI_TOUZI_REBORN].openDay then
                return false
            end

            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_REBORN)
            if isBuy > 0 then
                local level = MyRole.getProp(ENTITY_PROP_REBORN)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_REBORN]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_REBORN)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 等级投资
    [LIST.XJP_FULI_TOUZI_LEVEL] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays < gdFuliType[FULI_TOUZI_LEVEL].openDay then
                return false
            end

            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_LEVEL)
            if isBuy > 0 then
                local level = MyRole.getLevel()
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_LEVEL]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_LEVEL)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 杀怪投资
    [LIST.XJP_FULI_TOUZI_KILL] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays < gdFuliType[FULI_TOUZI_KILL].openDay then
                return false
            end

            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_KILL)
            if isBuy > 0 then
                local killCount = MyActivityData:getExDataX(EVENT_TZ_KILL)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_KILL]) do
                    if killCount >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_KILL)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 神剑投资
    [LIST.XJP_FULI_TOUZI_WEAPON] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays < gdFuliType[FULI_TOUZI_WEAPON].openDay then
                return false
            end

            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_WEAPON)
            if isBuy > 0 then
                local level = MyRole.getProp(ENTITY_PROP_DIVINE_SWORD_LEVEL)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_WEAPON]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_WEAPON)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 神甲投资
    [LIST.XJP_FULI_TOUZI_CLOTH] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays < gdFuliType[FULI_TOUZI_CLOTH].openDay then
                return false
            end

            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_CLOTH)
            if isBuy > 0 then
                local level = MyRole.getProp(ENTITY_PROP_DIVINE_ARMOR_LEVEL)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_CLOTH]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_CLOTH)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 神剑神甲中的神剑基金
    [LIST.XJP_SHENJIAN_JIJIN] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_WEAPON)
            if isBuy > 0 then
                local level = MyRole.getProp(ENTITY_PROP_DIVINE_SWORD_LEVEL)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_WEAPON]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_WEAPON)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            else
                return true
            end

            return false
        end
    },

    -- 神剑神甲中的神甲基金
    [LIST.XJP_SHENJIA_JIJIN] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local isBuy = MyActivityData:getExDataZ(EVENT_TZ_CLOTH)
            if isBuy > 0 then
                local level = MyRole.getProp(ENTITY_PROP_DIVINE_ARMOR_LEVEL)
                for k, v in pairs(gdFuliGrade[FULI_TOUZI_CLOTH]) do
                    if level >= v.count then
                        local getted = MyActivityData:getExDataY(EVENT_TZ_CLOTH)
                        if LuaHelper.and_op(LuaHelper.push_bit(0, 1, v.index - 1), getted) == 0 then
                            return true
                        end
                    end
                end
            else
                return true
            end

            return false
        end
    },

    -- 福利转盘
    [LIST.XJP_FULI_TURNTABLE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            -- if funcHelper.activityIsOpen(ACTIVITY_FLXYZP1, "kfhd_zp1") or funcHelper.activityIsOpen(ACTIVITY_FLXYZP2, "kfhd_zp2") or
            -- funcHelper.activityIsOpen(ACTIVITY_28, "kfhd_28") or funcHelper.activityIsOpen(ACTIVITY_29, "kfhd_29") or
            -- funcHelper.activityIsOpen(ACTIVITY_35, "kfhd_35") then
            --     return  MyActivityData:getExDataX(EVENT_ZP_COUNT) > 0
            -- end
            return false
        end
    },

    -- 运营活动
    [LIST.XJP_YYHD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local holidays = HolidayHelper.getAllHoliday()
            for i, v in ipairs(holidays) do
                local sd = HolidayHelper.HolidayMenu[v.type]
                if sd and sd.attention and sd.attention(v.switch_id) then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_ITEM_COMPOSE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("hecheng") then
                return false
            end
            sendNotification(PROXY_ITEM_COMPOSE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemComposeAll()
        end
    },
    [LIST.XJP_GUARD_GUARD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shouhu1") then
                return false
            end
            local level = MyRole.getProp(ENTITY_PROP_GUARD_LEVEL)
            local progress = MyRole.getProp(ENTITY_PROP_GUARD_PROGRESS)

            local config = gdGuards[level + 1]
            if not config then
                return false
            end
            local has_count = MyRole.getItemCountBySid(config.single_time_items.item_sid)
            if has_count >= (config.single_time_items.item_count * (config.times - progress)) then
                return true
            end

            return false
        end
    },
    [LIST.XJP_GUARD_SOUL] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("hunzhu") then
                return false
            end

            local level = MyRole.getProp(ENTITY_PROP_SOUL_LEVEL)
            local config = gdSoulBeads[level + 1]
            if not config then
                return false
            end

            for k, v in ipairs(config.cost_items) do
                if v.item_sid == 5 then
                    if v.item_count > MyRole.getCaptital(Captital.INGOT) + MyRole.getCaptital(Captital.BOUNDINGOT) then
                        return false
                    end
                else
                    if v.item_count > MyRole.getItemCountBySid(v.item_sid) then
                        return false
                    end
                end
            end

            return true
        end
    },
    [LIST.XJP_GUARD_FLAG] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("zhanqi") then
                return false
            end

            local level = MyRole.getProp(ENTITY_PROP_WAR_FLAG_LEVEL)
            local progress = MyRole.getProp(ENTITY_PROP_WAR_FLAG_PROGRESS)

            local config = gdWarFlags[level + 1]
            if not config then
                return false
            end
            local has_count = MyRole.getItemCountBySid(config.cost_items[1].item_sid)
            if has_count >= config.cost_items[1].item_count - progress then
                return true
            end
            return false
        end
    },
    [LIST.XJP_GUARD_HORCRUXES] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesAll()
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_1] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(1)
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_2] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(2)
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_3] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(3)
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_4] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(4)
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_5] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(5)
        end
    },
    [LIST.XJP_GUARD_HORCRUXES_6] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return itemHelper.checkRedHorcruxesRank(6)
        end
    },

    [LIST.XJP_REINCARNATION_UPGRADE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("zslt") then
                return false
            end
            local level = MyRole.getProp(ENTITY_PROP_REBORN)
            local next_config = gdReincarnationUpgrade[level + 1]
            if not next_config then
                return false
            end

            if MyRole.getLevel() < next_config.need_player_level then
                return false
            end

            if MyRole.getProp(ENTITY_PROP_REFINING_LEVEL) < next_config.need_refining_level then
                return false
            end

            if MyRole.getProp(ENTITY_PROP_REBORN_POINTS) < next_config.need_point then
                return false
            end

            if MyRole.getItemCountBySid(Captital.INGOT_ALL) < next_config.need_coin then
                return false
            end

            return true
        end
    },

    [LIST.XJP_REINCARNATION_REFINING] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("zslt") then
                return false
            end
            local re_level = MyRole.getProp(ENTITY_PROP_REBORN)
            local re_next_config = gdReincarnationUpgrade[re_level + 1]
            local level = MyRole.getProp(ENTITY_PROP_REFINING_LEVEL)
            -- 满足转生，前往转生
            if re_next_config then
                if level >= re_next_config.need_refining_level then
                    return false
                end
            end

            local config = gdReincarnationRefining[level + 1]
            if not config then
                return false
            end

            if not MyRole.haveEnoughItem(config.item_id, config.item_cnt) then
                return false
            end

            return true
        end
    },
    [LIST.XJP_HERALDRY] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("wenzhang") then
                return false
            end
            for i = 1, 4 do
                if itemHelper.checkHeraldryRed(i) then
                    return true
                end
            end
            return false
        end
    },
    [LIST.XJP_DBBK] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local top_item = { 76126, 76127 }
            for k, v in ipairs(top_item) do
                if MyRole.getItemCountBySid(v) > 0 then
                    return true
                end
            end
            if MyActivityData:getExDataX(EVENT_DBBK) >= 5 + MyActivityData:getExDataY(EVENT_DBBK) + MyRole.getProp(ENTITY_PROP_DABAO_TIMES) then
                return false
            end
            local limit_item = { 76128, 76129, 76130, 76131, 76132, 76133 }
            for k, v in ipairs(limit_item) do
                if MyRole.getItemCountBySid(v) > 0 then
                    return true
                end
            end
            return false
        end
    },

    [LIST.FIRST_CHARGE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.check_shouchong()
        end
    },

    [LIST.XJP_FIRSTBLOOD] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.check_firstblood_reward()
        end
    },

    [LIST.XJP_DABAO_BOSS_3] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("jizhanboss") then
                return false
            end
            return rewardHelper.check_boss_score_redpoint()
        end
    },

    [LIST.XJP_JJKH_1] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays > 7 or gdServerDays < 2 then
                return false
            end
            local awards = gdStaticAward[RANK_TYPE_WEN_ZHANG]
            if not awards then
                return false
            end
            local myLevel = MyRole.getProp(ENTITY_PROP_HERALDRY_QINGLONG_LEVEL) +
                MyRole.getProp(ENTITY_PROP_HERALDRY_BAIHU_LEVEL) + MyRole.getProp(ENTITY_PROP_HERALDRY_ZHUQUE_LEVEL) +
                MyRole.getProp(ENTITY_PROP_HERALDRY_XUANWU_LEVEL)
            for i, v in ipairs(awards) do
                if MyRole.getProp(v.propId) == 0 and myLevel >= v.level then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_JJKH_2] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays > 7 or gdServerDays < 3 then
                return false
            end
            local awards = gdStaticAward[RANK_TYPE_SHEN_JIAN_SHEN_JIA]
            if not awards then
                return false
            end
            local myLevel = MyRole.getProp(ENTITY_PROP_DIVINE_SWORD_LEVEL) +
                MyRole.getProp(ENTITY_PROP_DIVINE_ARMOR_LEVEL)
            for i, v in ipairs(awards) do
                if MyRole.getProp(v.propId) == 0 and myLevel >= v.level then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_JJKH_3] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays > 7 or gdServerDays < 4 then
                return false
            end
            local awards = gdStaticAward[RANK_TYPE_ATTACK]
            if not awards then
                return false
            end
            local myLevel = MyRole.getProp(ENTITY_PROP_MAX_ATK)
            for i, v in ipairs(awards) do
                if MyRole.getProp(v.propId) == 0 and myLevel >= v.level then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_JJKH_4] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays > 7 or gdServerDays < 5 then
                return false
            end
            local awards = gdStaticAward[RANK_TYPE_USE_NOT_BIND_LINGFU]
            if not awards then
                return false
            end
            local myLevel = MyRole.getProp(ENTITY_PROP_USE_NOT_BIND_LINGFU_NUM)
            for i, v in ipairs(awards) do
                if MyRole.getProp(v.propId) == 0 and myLevel >= v.level then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_JJKH_5] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if gdServerDays > 7 then
                return false
            end
            local awards = gdStaticAward[RANK_TYPE_REBORN]
            if not awards then
                return false
            end
            local myLevel = MyRole.getProp(ENTITY_PROP_REBORN)
            for i, v in ipairs(awards) do
                if MyRole.getProp(v.propId) == 0 and myLevel >= v.level then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_EQUIP_NPC_FORGE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not MySwitchManager:isSwitchEnabled(SWITCH_ZBDZ) then
                return false
            end
            if not MapHelper.checkEnterMapNoTips(MapID.kfzc_benfu) then
                return false
            end
            sendNotification(PROXY_ITEM_NPC_FORGE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemForgeComposeAll()
        end
    },

    [LIST.XJP_EQUIP_NPC_COMPOSE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not MapHelper.checkEnterMapNoTips(MapID.kfzc_benfu) then
                return false
            end
            sendNotification(PROXY_ITEM_COMPOSE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemComposeFirst(14)
        end
    },

    [LIST.XJP_SHENSHI_NPC_COMPOSE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not MySwitchManager:isSwitchEnabled(SWITCH_SSHC) then
                return false
            end
            if not MapHelper.checkEnterMapNoTips(MapID.kfzc_benfu) then
                return false
            end
            sendNotification(PROXY_ITEM_COMPOSE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemComposeFirst(19)
        end
    },

    [LIST.XJP_MOWEN_NPC_COMPOSE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not MySwitchManager:isSwitchEnabled(SWITCH_MWCH) then
                return false
            end
            if not MapHelper.checkEnterMapNoTips(MapID.kfzc_benfu) then
                return false
            end
            sendNotification(PROXY_ITEM_COMPOSE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemComposeFirst(18)
        end
    },

    [LIST.XJP_MAGIC_NPC_COMPOSE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("moqi") then
                return false
            end
            sendNotification(PROXY_ITEM_COMPOSE_RED_POINT_INFO)
            return itemHelper.checkRedPointItemComposeFirst(21)
        end
    },

    [LIST.UNREADCHAT_6] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return ChatHelper.unreadChat[ChatChannel.c_private] and ChatHelper.unreadChat[ChatChannel.c_private] > 0
        end
    },

    [LIST.XJP_FABAO] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local function getFabaoPlayerProp(propId)
                local fabaoData = MyRole.getProp(propId)
                -- 第一个返回等级 第二个返回当前星级
                local level = tonumber(string.sub(tostring(fabaoData), 1, -4)) or 0
                local star = tonumber(string.sub(tostring(fabaoData), -3))
                return level, star
            end
            -- 获取下一级的配置
            local function getNextConfig(fabaoId, level, star, isInit)
                -- 都为0级时 未激活
                local fabaoData = gdFabaoLevelData[fabaoId]
                if isInit then
                    return fabaoData[1][1]
                end
                level = level == 0 and 1 or level
                -- 下一星级
                local nextCfg = fabaoData[level][star + 1]
                -- 下一星级 不存在 则 装备满星 继续下一等级
                if not nextCfg and fabaoData[level + 1] then
                    nextCfg = fabaoData[level + 1][1]
                    return nextCfg
                end
                -- 下一等级不存在 装备满等满星
                if not nextCfg then
                    return nil
                end
                -- 默认的下一星级
                return nextCfg
            end

            if not funcHelper.isOpen("fabao") then
                return false
            end
            -- 材料足够任意等级升级或激活 就有红点
            for _, v in pairs(gdFabaoNewData) do
                local fabaoId = v.id
                local propId = v.propId
                local level, star = getFabaoPlayerProp(propId)
                local nextConfig = getNextConfig(fabaoId, level, star, level == 0 and star == 0)
                -- 有下一级配置 并且满足转生等级
                if nextConfig and MyRole.getReborn() >= nextConfig.reborn then
                    -- 判断消耗
                    local hasCount1 = MyRole.getItemCountBySid(nextConfig.cost1.itemId)
                    local hasCount2 = MyRole.getItemCountBySid(nextConfig.cost2.itemId)
                    if hasCount1 >= nextConfig.cost1.count and hasCount2 >= nextConfig.cost2.count then
                        return true
                    end
                end
            end
            return false
        end
    },

    [LIST.XJP_LINGBAO] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local function getPlayerLingBaoProp(propId)
                local fabaoData = MyRole.getProp(propId)
                -- 第一个返回等级 第二个返回当前星级
                local level = tonumber(string.sub(tostring(fabaoData), 1, -4)) or 0
                local star = tonumber(string.sub(tostring(fabaoData), -3))
                return level, star
            end
            -- 获取下一级的配置
            local function getNextConfig(fabaoId, level, star, isInit)
                -- 都为0级时 未激活
                local fabaoData = gdLingBaoLevelData[fabaoId]
                if isInit then
                    return fabaoData[1][1]
                end
                level = level == 0 and 1 or level
                -- 下一星级
                local nextCfg = fabaoData[level][star + 1]
                -- 下一星级 不存在 则 装备满星 继续下一等级
                if not nextCfg and fabaoData[level + 1] then
                    nextCfg = fabaoData[level + 1][1]
                    return nextCfg
                end
                -- 下一等级不存在 装备满等满星
                if not nextCfg then
                    return nil
                end
                -- 默认的下一星级
                return nextCfg
            end

            if not funcHelper.isOpen("lingbaobao") then
                return false
            end
            -- 材料足够任意等级升级或激活 就有红点
            for _, v in pairs(gdLingBaoData) do
                local fabaoId = v.id
                local propId = v.propId
                local level, star = getPlayerLingBaoProp(propId)
                local nextConfig = getNextConfig(fabaoId, level, star, level == 0 and star == 0)
                -- 有下一级配置 并且满足转生等级
                if nextConfig then
                    -- 判断消耗
                    local hasCount1 = MyRole.getItemCountBySid(nextConfig.cost1.itemId)
                    local hasCount2 = MyRole.getItemCountBySid(nextConfig.cost2.itemId)
                    if hasCount1 >= nextConfig.cost1.count and hasCount2 >= nextConfig.cost2.count then
                        return true
                    end
                end
            end
            return false
        end
    },

    [LIST.XJP_SUPER_BOSS] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for i, v in ipairs(gdSuperMap) do
                if rewardHelper.check_superboss_redpoint(v) then
                    return true
                end
            end

            return false
        end
    },

    [LIST.XJP_GHLC] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if rewardHelper.check_ghlc_redpoint() then
                return true
            end
            return false
        end
    },
    [LIST.XJP_SL_XY] = {
        --神炉 血玉
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenlu") then
                return false
            end

            local result1, result2 = rewardHelper.checkAloneGod(1)

            return result1 or result2
        end
    },
    [LIST.XJP_SL_HD] = {
        --神炉 护盾
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenlu") then
                return false
            end

            local result1, result2 = rewardHelper.checkAloneGod(2)

            return result1 or result2
        end
    },
    [LIST.XJP_SL_BS] = {
        --神炉 宝石
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenlu") then
                return false
            end

            local result1, result2 = rewardHelper.checkAloneGod(3)

            return result1 or result2
        end
    },
    [LIST.XJP_SL_HZ] = {
        --神炉 魂珠
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shenlu") then
                return false
            end
            local result1, result2 = rewardHelper.checkAloneGod(4)

            return result1 or result2
        end
    },
    [LIST.XJP_TUJIAN] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("zhenbaotujian") then
                return false
            end
            return rewardHelper.check_tujian_redpoint()
        end
    },
    [LIST.XJP_RONGYU_SHENGXING] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("shengxing") then
                return false
            end
            return rewardHelper.check_shengxing_redpoint()
        end
    },
    [LIST.XX_SXZL_QINGLONG] = {
        -- 四象之力 青龙
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedSXZLByType(1)
        end
    },
    [LIST.XX_SXZL_BAIHU] = {
        -- 四象之力 白虎
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedSXZLByType(2)
        end
    },
    [LIST.XX_SXZL_ZHUQUE] = {
        -- 四象之力 朱雀
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedSXZLByType(3)
        end
    },
    [LIST.XX_SXZL_XUANWU] = {
        -- 四象之力 玄武
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedSXZLByType(4)
        end
    },
    [LIST.XJP_GUILD_MEMBER] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkGuildApply()
        end
    },
    [LIST.XJP_GUILD_RED_PACKET] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedGuildRedPacket()
        end
    },
    -- [LIST.XJP_YBHS_SUIT] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSSuit()
    --     end
    -- },
    -- [LIST.XJP_YBHS_DOUBLE] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSDouble()
    --     end
    -- },
    -- [LIST.XJP_YBHS_1] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(1)
    --     end
    -- },
    -- [LIST.XJP_YBHS_2] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(2)
    --     end
    -- },
    -- [LIST.XJP_YBHS_3] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(3)
    --     end
    -- },
    -- [LIST.XJP_YBHS_4] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(4)
    --     end
    -- },
    -- [LIST.XJP_YBHS_5] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(5)
    --     end
    -- },
    -- [LIST.XJP_YBHS_6] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(6)
    --     end
    -- },
    -- [LIST.XJP_YBHS_7] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(7)
    --     end
    -- },
    -- [LIST.XJP_YBHS_8] = {
    --     [CONDITION.RED_POINT_FUNCTION] = function()
    --         return itemHelper.checkRedYBHSOnce(8)
    --     end
    -- },
    [LIST.XJP_XZ_QUEST] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedXZQuest()
        end
    },

    [LIST.XJP_XZ_UPGRADE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedXZUpgrade()
        end
    },

    [LIST.XJP_FH_UPGRADE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local chumo_score = MyRole.getProp(ENTITY_PROP_CHUMO_SCORE)
            local chumo_head = MyRole.getProp(ENTITY_PROP_CHUMO_HEAD)
            local coin = MyRole.getItemCountBySid(Captital.INGOT_ALL)
            local next_head = gdCMHead[chumo_head + 1]
            if not next_head then
                return false
            end
            if chumo_score < next_head.gx then
                return false
            end
            if coin < next_head.gold then
                return false
            end
            return true
        end
    },

    [LIST.XJP_DIAOWEN_UPGRADE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("xiuxiandiaowen") then
                return false
            end
            -- 装备
            for position = EQUIP_POS_BEGIN, EQUIP_POS_END, -1 do
                if itemHelper.checkDiaoWenUpgrad(position) then
                    return true
                end
            end
            -- 背包
            for position = PLAYER_BAG_BEGIN, ITEM_BAG.getEndIndex(PLAYER_BAG_BEGIN), 1 do
                if itemHelper.checkDiaoWenUpgrad(position) then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_RONGLIAN_REPAIR] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if not funcHelper.isOpen("xiuxiandiaowen") then
                return false
            end
            -- 装备
            for position = EQUIP_POS_BEGIN, EQUIP_POS_END, -1 do
                if itemHelper.checkRonglianRepair(position) then
                    return true
                end
            end
            -- 背包
            for position = PLAYER_BAG_BEGIN, ITEM_BAG.getEndIndex(PLAYER_BAG_BEGIN), 1 do
                if itemHelper.checkRonglianRepair(position) then
                    return true
                end
            end
            return false
        end
    },

    [LIST.XJP_ZHANDUI_APP] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local zhandui_id = MyRole.getProp(ENTITY_PROP_ZHANDUI_ID)
            if zhandui_id == 0 then
                return false
            end

            local zhandui_post = MyRole.getProp(ENTITY_PROP_ZHANDUI_POST)
            if zhandui_post ~= ZHANDUI_POST_MASTER then
                return false
            end

            if #MyZhanDuiData.app_list == 0 then
                return false
            end

            return true
        end
    },

    [LIST.XJP_KFHD_YBZP] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedYBZP()
        end
    },

    [LIST.SKILL_LEVEL] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            local source = MyRole.getProp(ENTITY_PROP_SKILL_SCORE)
            if source == 0 then
                return false
            end

            local function checkCanLvUp(sid)
                local skill = MySkillData:getSkill(sid)
                local data = gdSkillLvl[sid]
                local skillInfo = gdSkills[sid]
                if not skill then
                    return false
                end
                if not skillInfo then
                    return false
                end
                if not skill.level then
                    return false
                end
                if not data then
                    return false
                end
                local lvData = data[skill.level]
                if not lvData then
                    return false
                end
                local nextData = nil
                local nextLv = skill.level + 1
                if #data < skill.level + 1 then
                    return false
                else
                    nextData = data[nextLv]
                    if source < nextData.exp then
                        return false
                    end
                    return true
                end
            end

            local job = MyRole.getJob()
            for i, v in ipairs(gdPlayerSkill) do
                if i == job then
                    for kk, vv in ipairs(v) do
                        if checkCanLvUp(vv) then
                            return true
                        end
                    end
                end
            end

            return false
        end
    },

    -- 境界体修
    [LIST.XX_JINGJIE_JINGJIE_TIXIU] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedJingJie(1)
        end
    },

    -- 境界法修
    [LIST.XX_JINGJIE_JINGJIE_FAXIU] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedJingJie(2)
        end
    },
    -- 仙器升级
    [LIST.XJP_XQ_UPGRADE] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            return rewardHelper.checkRedXianQi()
        end
    },

}

for i = LIST.UNREADCHAT_1, LIST.UNREADCHAT_6, 1 do
    RED_POINT_RULE[i] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            if i == LIST.UNREADCHAT_6 then
                return ChatHelper.unreadChat[ChatChannel.c_private] and ChatHelper.unreadChat[ChatChannel.c_private] > 0
            else
                return false
            end
        end
    }
end

for i = LIST.BAG_1, LIST.BAG_4 do
    RED_POINT_RULE[i] = {
        [CONDITION.RED_POINT_FUNCTION] = function()
            for position = PLAYER_BAG_BEGIN + (i - LIST.BAG_1) * GRID_COUNT_PAGE, PLAYER_BAG_BEGIN + (i - LIST.BAG_1) * GRID_COUNT_PAGE + GRID_COUNT_PAGE - 1 do
                local userItem = MyItemData:getItemByPosition(position)

                repeat
                    if not userItem then
                        break
                    end

                    if EquipHelper.isBestEquip(userItem) then
                        return true
                    end

                    local item = userItem.item
                    if not item then
                        break
                    end

                    -- 特殊道具红点处理
                    local isSpecial, hasRedPoint = itemHelper.checkSpecialItemRedPoint(item)
                    if isSpecial then
                        if hasRedPoint then
                            return true
                        end
                        break
                    end

                    -- 不是礼包
                    if item.cate ~= ITEM_CATEGORY_GIFT then
                        -- 不显示红点
                        if item.showRedpoint ~= 1 then
                            break
                        end

                        -- 转生丹特殊处理
                        if item.script == "zhuanshendan" and not itemHelper.checkRebornItemRedPoint(item) then
                            break
                        end

                        -- 不可使用
                        if not itemHelper.chechItemCanUse(item) then
                            break
                        end
                    end

                    if userItem.item.cate == ITEM_CATEGORY_RUNE then
                        if not itemMgr.isLowSkillBook(userItem) and itemMgr.canBeUserSkillBook(userItem) then
                            return true
                        end
                    else
                        return true
                    end
                until true
            end
            return false
        end
    }
end

for i = LIST.MDS_VIP_BEGIN + 1, LIST.MDS_VIP_END do
    RED_POINT_RULE[i] = {}
    local idx = i - LIST.MDS_VIP_BEGIN
    RED_POINT_RULE[i][CONDITION.RED_POINT_FUNCTION] = function()
        return rewardHelper.check_mds_vip_free_gift(idx)
    end
end

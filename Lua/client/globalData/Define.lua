-- 常量类（定义常量值请用GameData）
---------------------------------------------确定一定会用的start------------------------------------------------------
-- 货币属性
Captital = {
    EXP = 1,
    LINGFU = 3,       -- 灵符
    INGOT = 4,        -- 元宝
    BOUNDINGOT = 5,   -- 绑定元宝
    BOUNDLINGFU = 6,  -- 绑定灵符
    LINGFU_ALL = 100, -- 灵符+绑定灵符
    INGOT_ALL = 101,  -- 元宝+绑定元宝
}

-- 货币集合
CapitalSet = {
    Captital.EXP,
    Captital.LINGFU,
    Captital.INGOT,
    Captital.BOUNDINGOT,
    Captital.BOUNDLINGFU,
    Captital.LINGFU_ALL,
    Captital.INGOT_ALL,
}

-- 属性对应的货币
function convertPropToCapital(prop)
    local PropCapital = {
        [ENTITY_PROP_EXP] = Captital.EXP,
        [ENTITY_PROP_LINGFU] = Captital.LINGFU,
        [ENTITY_PROP_INGOT] = Captital.INGOT,
        [ENTITY_PROP_BOUND_INGOT] = Captital.BOUNDINGOT,
        [ENTITY_PROP_BOUND_LINGFU] = Captital.BOUNDLINGFU,
    }

    return PropCapital[prop]
end

-- 生命的状态集合
ALIVER_STATE = {
    IDLE = 0,
    WALK = 1,
    RUN = 2,
    PREPARE = 3,
    ATTACK = 4,
    MAGIC = 5,
    INJURY = 6,
    DIE = 7,
    COUNT = 8,
    CHANGEDIRECTION = 9,
    MINE = 10,
    PETFINDRUN = 11, -- 宠物捡东西（移动状态），有特殊技能状态
    COLLIDE = 12,
    MINING = 13      --  挖矿
}

ClientProp = {
    -- ENTITY_C_MAIN           = 0,
    ENTITY_C_EID                = 1,
    -- ENTITY_C_RUN            = 2,
    ENTITY_C_PID                = 3,
    ENTITY_C_STATICID           = 4,
    ENTITY_C_TYPE               = 5,
    ENTITY_C_GENDER             = 6,
    ENTITY_C_JOB                = 7,
    ENTITY_C_STATE              = 8,
    ENTITY_C_DIR                = 9, -- 方向
    ENTITY_C_TX                 = 10,
    ENTITY_C_TY                 = 11,
    ENTITY_C_CLOTH              = 12,
    ENTITY_C_WING               = 13,
    ENTITY_C_WEAPON             = 14,
    ENTITY_C_HP                 = 15,
    ENTITY_C_MAX_HP             = 16,
    ENTITY_C_MP                 = 17,
    ENTITY_C_MAX_MP             = 18,
    ENTITY_C_REBORN             = 19,
    ENTITY_C_LV                 = 20, -- player等级
    ENTITY_C_EXP                = 21, -- 玩家经验
    ENTITY_C_EXP_NEXT           = 22, -- 下一级经验
    ENTITY_C_OWER_PID           = 23,
    ENTITY_C_ASELFAIL           = 24,
    ENTITY_C_TRANFERING         = 25, -- 进传送门
    ENTITY_C_ITEM_EFFECT        = 26, -- 物品特效
    ENTITY_C_WIDTH              = 27, -- 对象宽度
    ENTITY_C_HEIGHT             = 28, -- 对象高度
    ENTITY_C_SKILL_LVL          = 29, -- 对应的技能等级
    ENTITY_C_SID                = 30, -- 服务器id
    ENTITY_C_SNAME              = 31, -- 服务器名称
    ENTITY_C_COUNT              = 34, -- 数量
    ENTITY_C_SHIELD             = 35, -- 盾牌
    ENTITY_C_HOLY_STRIPE        = 36, -- 灵纹
    ENTITY_C_GUARD              = 37, -- 小极品守护
    ENTITY_C_HAT                = 38, -- 斗笠
    ENTITY_C_CHENGHAO           = 39, --称号
    ENTITY_C_HUNHUAN            = 40, --魂环
    ENTITY_C_JINGLING           = 41, --精灵
    ENTITY_C_CHENGHAO2          = 42, --称号2
    ENTITY_C_CHENGHAO3          = 43, --称号3
    ENTITY_C_CHENGHAO4          = 44, --称号4
    ENTITY_C_CHENGHAO5          = 45, --称号5

    ENTITY_STR_NAME             = 50, -- player 昵称
    ENTITY_STR_PID_NAME         = 51, -- playe英雄的昵称
    ENTITY_STR_G_D_NMAE         = 52,
    ENTITY_STR_NPC_GN           = 53,
    ENTITY_ATK_CODE             = 54, -- 攻击名
    ENTITY_S_RANGE              = 55,
    ENTITY_S_TIME               = 56,
    ENTITY_OWNER_TYPE           = 57,
    ENTITY_SERVER_ID            = 58, -- 服务器id

    ENTITY_TARGET_X             = 100,
    ENTITY_TARGET_Y             = 101,
    ENTITY_CUR_X                = 102,
    ENTITY_CUR_Y                = 103,
    ENTITY_BASE_SPEED           = 104, -- 基础速度
    ENTITY_MOVE_STEP            = 105, -- 移动步数
    ENTITY_MOVE_TIME            = 106, -- 移动时间
    ENTITY_ATTACK_AIMID         = 107, -- 攻击的敌人

    ENTITY_SEL_TIME             = 118, -- 选择次数
    ENTITY_IS_GATHER            = 119, -- 是否可采集 0：可采；1：不可采
    ENTITY_GATHER_ID            = 120, -- 正在采集的对象

    ENTITY_DOG_SUBTYPE          = 130, -- 神兽子类型

    ENTITY_TITLE_BROADCAST      = 131, -- 特殊播報
    ENTITY_C_NORMAL_MODEL       = 132, -- 普通模型
    ENTITY_C_HUANHUA_MODEL      = 133, -- 幻化模型
    ENTITY_C_PALSY              = 134, -- 宝宝麻痹概率

    ENTITY_C_MINER_ROB_STATE    = 136, -- 矿工被掠夺状态
    ENTITY_C_LODE_LEVEL         = 137, -- 矿工等级
    ENTITY_C_MINER_PROTECT_TIME = 138, -- 矿工保护时间
    ENTITY_C_FABAO_INDEX        = 139, -- 穿戴的法宝

    ENTITY_C_SCALE              = 141, --模型缩放

    ENTITY_C_INDEX              = 142, --残影id标记

    ENTITY_C_MINING             = 143, --是否正在挖矿

    ENTITY_C_BE_COLLIDE         = 144, --被野蛮
    ENTITY_C_PK_STATE           = 145, -- pkState
    ENTITY_C_FACTION_ID         = 146, -- 阵营ID
}

-- 客户端属性id 和 服务器属性id映射表
MapServerPropIdToClientPropId = {
    [ENTITY_PROP_PK_STATE] = ClientProp.ENTITY_C_PK_STATE,
    [ENTITY_PROP_FACTION_ID] = ClientProp.ENTITY_C_FACTION_ID,
}

-- 客户端属性id 和 服务器属性id映射表
MapClientPropIdToServerPropId = {
    [ClientProp.ENTITY_C_PK_STATE] = ENTITY_PROP_PK_STATE,
    [ClientProp.ENTITY_C_FACTION_ID] = ENTITY_PROP_FACTION_ID,
}

-- 物品质量
Quality = {
    PUTONG = 1,    -- 普通
    YOUXIU = 2,    -- 优秀
    JINGLIANG = 3, -- 精良
    XIYOU = 4,     -- 稀有
    SHISHI = 5     -- 史诗
}

-- 特殊地图视角偏移
gdMapVisualShiftX = {
    [10010] = 200
}

gdMapVisualShiftY = {
    [10010] = 100
}

MAP_VISUAL_SHIFT_XY =
{
    X = 0,
    Y = 50,
}

-- 基础攻击类型
BASE_ATK_TYPE = {
    none = 0,
    player = 1,
    monster = 2
}

-- 攻击状态
ATTACKK_STATE = {
    over = 0,
    begin = 1,
    run = 2,
    canMove = 3,
    playState = 4
}

-- 人物类 状态
ENTITY_STATE_TP = {
    CREATE = 0,  -- 创建
    RUNNING = 1, -- 运行
    STOP = 2,    -- 暂停
    DESTROY = 3  -- 销毁
}

-- 帧频数  1-8是人物的各个状态
NPC_STATE_FRAME = { 1, 1, 1, 1, 1, 1, 1, 1 }
MONSTER_STATE_FRAME = { 1, 1.6, 1, 1, 1.7, 1, 1, 1 }
PLAYER_STATE_FRAME = { 1, 2.1, 1.0, 1, 1, 2, 1, 1 }
PET_STATE_FRAME = { 1, 1.8, 2, 1, 1, 1, 1, 1 }
SKILL_STATE_FRAME = { 1, 1, 1, 1, 1, 1, 1, 1 }
MARS_STATE_FRAME = { 1, 1.8, 2.5, 1, 1, 1.0, 1, 1 }

-- 动作常量
ALIVER_ACTION = { "start", "walk", "run", "prepare", "attack", "magic", "injury", "dead" }

-- 对象类型区分
ALIVER_GHOST_TYPE = {
    GHOST_TYPE_STO_STUT = 98,
    GHOST_TYPE_STO_FIRE = 99, -- 剧情火
    GHOST_TYPE_STORYER = 100, -- 剧情人物
    GHOST_TYPE_NPC = 500,
    GHOST_TYPE_PLAYER = 501,  -- 玩家（其他玩家）
    GHOST_TYPE_MONSTER = 502,
    GHOST_TYPE_MAP_ITEM = 503,
    GHOST_TYPE_SLAVE = 504, -- 狗
    GHOST_TYPE_PLANT = 506,
    GHOST_TYPE_COLLECTION = 507,
    GHOST_TYPE_SKILL = 509,
    GHOST_TYPE_PET = 510,
    GHOST_TYPE_MINE = 511,
    GHOST_TYPE_SKILL_BIND = 512,
    GHOST_TYPE_MARS = 513,
    GHOST_TYPE_PLAYER_CLONE = 514,  -- 分身
    GHOST_TYPE_HERO = 515,          -- 英雄（角色的英雄）
    GHOST_TYPE_SPBOSS = 516,        -- 未知暗殿的boss
    GHOST_TYPE_JQBG = 517,          -- 激情闭关的泡点光圈
    GHOST_TYPE_MINER = 518,         -- 矿工
    GHOST_TYPE_TOUSHI = 519,        -- 透视
    GHOST_TYPE_PLAYER_SHADOW = 520, -- 残影
    GHOST_TYPE_THIS = 999
}

-- 衣服
ALIVER_CLOTH_TYPE = {
    CLOTH       = 0,  -- 衣服
    WEAPON      = 1,  -- 武器
    WINGS       = 2,  -- 翅膀
    SKILL_MIT   = 3,  -- 魔法盾
    EFFECT      = 4,  -- buff特效  针对既是buff 又是 技能这一类特殊的类型
    SKILL       = 5,  -- 技能
    HAT         = 6,  -- 斗笠
    KB          = 7,  -- 狂暴
    SHIELD      = 8,  -- 盾牌
    HOLY_STRIPE = 9,  -- 灵纹
    GUARD       = 10, -- 小极品守护
    CHENGHAO    = 11, --称号
    HUNHUAN     = 12, --魂环
    JINGLING    = 13, --精灵
    MOQI        = 14, --魔器
}

-- 方向define
DIRECTION = {
    DIR_UP = 0,
    DIR_UP_RIGHT = 1,
    DIR_RIGHT = 2,
    DIR_DOWN_RIGHT = 3,
    DIR_DOWN = 4,
    DIR_DOWN_LEFT = 5,
    DIR_LEFT = 6,
    DIR_UP_LEFT = 7,
    AVATAR_DIR_COUNT = 8
}

-- 通用颜色
GAME_COLOR = {
    -- 标准颜色
    Gray = cc.c3b(213, 213, 213),   -- 灰
    Green = cc.c3b(19, 226, 18),    -- 绿
    Green_2 = cc.c3b(140, 208, 80), -- 绿2
    Blue = cc.c3b(37, 138, 255),    -- 蓝
    Purple = cc.c3b(161, 78, 254),  -- 紫
    Pink = cc.c3b(204, 62, 164),    -- 粉
    Red = cc.c3b(241, 2, 3),        -- 红
    Yellow = cc.c3b(222, 191, 44),  -- 黄
    White = cc.c3b(255, 255, 255),  -- 白
    Black = cc.c3b(0, 0, 0),
    MWhite = cc.c3b(212, 210, 18),
    -- 提示模块颜色
    Tip_Green = cc.c3b(126, 254, 49),        -- 绿
    Tip_Blue = cc.c3b(71, 194, 250),         -- 蓝
    Tip_Purple = cc.c3b(170, 96, 253),       -- 紫
    Tip_Pink = cc.c3b(252, 59, 198),         -- 粉
    Tip_Red = cc.c3b(249, 62, 43),           -- 红
    Tip_Orabge = cc.c3b(254, 155, 59),       -- 橙
    Tip_Title_Yellow = cc.c3b(255, 225, 61), -- 标题黄色
    -- 背包特殊颜色
    Bag_Green = cc.c3b(21, 203, 107),        -- 绿
    Bag_Red = cc.c3b(219, 75, 60),           -- 红
    miniMapMonster = cc.c3b(234, 0, 0),      -- 小地图boss
    miniMapTime = cc.c3b(255, 239, 8),       -- 小地图倒计时

    -- 其它（最好不用）
    RedMonster = cc.c3b(255, 55, 55),
    Yellow2 = cc.c3b(255, 231, 0),
    Orange = cc.c3b(254, 155, 59),
    Purple2 = cc.c3b(255, 0, 236),

    Gray2 = cc.c3b(147, 148, 180),
    Orange1 = cc.c3b(255, 127, 0),
    NPCwtite = cc.c3b(255, 248, 218),
    BOSSyellow = cc.c3b(255, 204, 0),
    GreenH = cc.c3b(132, 235, 0),

    Gray3 = cc.c3b(128, 128, 128)
}

-- 特效播放类型
EFFECTRULE = {
    REPLAY = 0,
    ONETIME = 1,
    CONTORL = 2 -- 自己控制
}

-- 技能等级称号
SKILL_LEVEL = {
    [1] = "初级",
    [2] = "黄级",
    [3] = "玄级",
    [4] = "地级",
    [5] = "天级",
    [6] = "尊级",
    [100] = "觉醒"
}

-- 开服活动
OPEN_ACTIVITYS = {
    {
        key = "kfhd_jjkh",
        sort = 15,
        visible = function() return false end,
        title = "竞技狂欢",
        ui = UI_XJP_KFHD_JJKH,
        redPoint = 121
    },
}

-- 福利活动
FULI_ACTIVITYS = {
    {
        key = "fuli_touzi",
        sort = 120,
        title = "投资",
        ui = UI_XJP_FULI_TOUZI,
        redPoint = 112,
        visible = function()
            for index, value in ipairs(gdFuliType) do if gdServerDays >= value.openDay then return true end end
            return false
        end,
    },
    {
        key = "fuli_yqs",
        sort = 169,
        visible = function() return false end,
        title = "摇钱树",
        ui = UI_XJP_FULI_YAOQIANSHU
    },
    {
        key = "kfhd_gcz",
        sort = 165,
        visible = function() return funcHelper.isOpen("juezhanshabake") end,
        title = "沙城争霸",
        ui = UI_XJP_KFHD_GCZ
    }
}

-- 运营活动状态
HOLIDAY_STATE = {
    HOLIDAY_REWARE_STATE_ERROR = 0,           -- 错误
    HOLIDAY_REWARE_STATE_RECEIVE = 1,         -- 可领取
    HOLIDAY_REWARE_STATE_UNFINISH = 2,        -- 未达成
    HOLIDAY_REWARE_STATE_FINISH = 3,          -- 已领取
    HOLIDAY_REWARE_STATE_BUY = 4,             -- 购买
    HOLIDAY_REWARE_STATE_BUYED = 5,           -- 已购买
    HOLIDAY_REWARE_STATE_EXCHANGE = 6,        -- 兑换
    HOLIDAY_REWARE_STATE_EXCHANGEED = 7,      -- 已兑换
    HOLIDAY_REWARE_STATE_RECEIVE_WITHOUT = 8, -- 可领取状态，不提示（全服限制不可领取奖励）
    HOLIDAY_REWARE_STATE_EXPIRED = 9          -- 已过期
}

-- 内置活动状态
ACTIVITY_STATE = {
    ACTIVITY_REWARE_STATE_ERROR = 0,           -- 错误
    ACTIVITY_REWARE_STATE_RECEIVE = 1,         -- 可领取
    ACTIVITY_REWARE_STATE_UNFINISH = 2,        -- 未达成
    ACTIVITY_REWARE_STATE_FINISH = 3,          -- 已领取
    ACTIVITY_REWARE_STATE_BUY = 4,             -- 购买
    ACTIVITY_REWARE_STATE_BUYED = 5,           -- 已购买
    ACTIVITY_REWARE_STATE_EXCHANGE = 6,        -- 兑换
    ACTIVITY_REWARE_STATE_EXCHANGEED = 7,      -- 已兑换
    ACTIVITY_REWARE_STATE_RECEIVE_WITHOUT = 8, -- 可领取状态，不提示（全服限制不可领取奖励）
    ACTIVITY_REWARE_STATE_EXPIRED = 9          -- 已过期
}

---------------------------------------------确定一定会用的end--------------------------------------------------------

SPNPC = {
    CHUANSONG = 811,
    HUISHOU = 715,
    HECHENG = 705,
    BIQI = 712,
    CANGKU = 915,
    KUAFU = 930 -- 跨服npc
}

-- 精灵身上的特性tag
ENTITY_EFFECT_TAG = {
    BOSS_SHIELD = 300 -- boss盾
}

-- 9格
ALL_ROUND = { { 1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { -1, 1 }, { -1, -1 }, { 0, 1 }, { 0, 0 }, { 0, -1 } }

-- 周围8格
TILE_STEP = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } }

-- 半月范围
HalfMoon = {
    {
        {1, 0},
        {-1, 0},
        {1, 1},
        {-1, 1},
    },
    {
        {0, 1},
        {-1, 0},
        {0, 2},
        {-2, 0},
    },
    {
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
    },
    {
        {-1, 0},
        {0, -1},
        {-2, 0},
        {0, -2},
    },
    {
        {-1, 0},
        {1, 0},
        {-1, -1},
        {1, -1},
    },
    {
        {0, -1},
        {1, 0},
        {0, -2},
        {2, 0},
    },
    {
        {0, 1},
        {0, -1},
        {1, 1},
        {1, -1},
    },
    {
        {1, 0},
        {0, 1},
        {2, 0},
        {0, 2},
    },
}

smallHalfMoon = {
    {{1, 0}, {-1, 0}, {1, 1}},
    {{0, 1}, {-1, 0}, {0, 2}},
    {{0, -1}, {0, 1}, {-1, -1}},
    {{-1, 0}, {0, -1}, {-2, 0}},
    {{-1, 0}, {1, 0}, {-1, -1}},
    {{0, -1}, {1, 0}, {0, -2}},
    {{0, 1}, {0, -1}, {1, 1}},
    {{1, 0}, {0, 1}, {2, 0}},
}

-- 血量状态常量
BEATTACKNOCHANGEHP = {
    batt_miss = 0,
    batt_immunity = 1,
    batt_hpchange = 2
}

-- 消息格式
MSG = {
    INT = "i",
    SHORT = "h",
    CHAR = "b",
    STRING = "s",

    LEFT_IT = "(",
    RIGHT_IT = ")"
}

-- 对象选中状态
GHOST_CHOICE_STATE = {
    NOCHOICE = 0, -- 未选中
    CHOICING = 1, -- 已选中
    CHOICED = 2   -- 第二次选中
}

-- ghostManager深度层级管理
GHOST_Z_LAYER = {
    ITEM_Z = 0,
    GHOST_Z = 10000,
    EFFECT_Z = 20000
}

-- 复活状态
ENTITYREVIVE = {
    revive_dead = 1, -- 原地复活
    revive_safe = 2, -- 安全复活
    revive_rand = 3  -- 本场景随机复活点复活
}

-- 威望任务状态
WWTASKSTATUS = {
    unAccept = 1, -- 未接任务
    accept = 2,   -- 接受该任务	
    finished = 3  -- 提交任务
}

------------------------------color -------------------------------

NPCtag = {
    TAG_CHANGEMAP = 10,
    TAG_NPCSHOP = 11,
    TAG_SCRIPT_C = 12,
    TAG_SCRIPT_S = 13,
    TAG_SHOWTALK = 14,
    TAG_CONNNPC = 15,
    TAG_BACK = 16,
    TAG_BACKSCENE = 17,
    TAG_DETAILS = 18
}

NPCFUNCTION = {
    Function_Shop = 1,
    Function_Portal = 2,
    Function_ScriptC = 3,
    Function_ScriptS = 4,
    Function_ShowText = 5,
    Function_SubNPC = 6,
    Function_BackTop = 7,
    Function_BackScene = 8,
    Function_Details = 9,
    Function_Max = 10
}

-- 蓝 0,255,255
-- 绿 0,255,0
-- 按钮颜色 255,238,186
-- 灰色149,149,149
-- 黄色255,241,0
-- 红色255,0,0
-- 紫色139,0,255

JEWEL_COLOR = {
    Gray = cc.c3b(174, 161, 136),
    Green = cc.c3b(0, 214, 5),
    Yellow = cc.c3b(245, 223, 169),
    Dirty = cc.c3b(184, 147, 120)
}


------------------------------2020.4.1李枫定义的颜色----------------------
TIPS_COLOR = {
    Gray = cc.c3b(213, 213, 213),  -- 灰色
    Green = cc.c3b(21, 203, 107),  -- 绿色
    Blue = cc.c3b(37, 138, 255),   -- 蓝色
    Purple = cc.c3b(161, 78, 254), -- 紫色
    Pink = cc.c3b(204, 62, 164),   -- 粉色
    Red = cc.c3b(219, 75, 60),
    Orange = cc.c3b(222, 191, 44)
}

------------------------------2018.1.24陈潮定义的颜色----------------------
STANDARD_COLOR = {
    White = cc.c3b(255, 255, 255),
    Green = cc.c3b(126, 254, 49),
    Blue = cc.c3b(71, 194, 250),
    Purple = cc.c3b(170, 96, 253),
    Pink = cc.c3b(252, 59, 198),
    Red = cc.c3b(249, 62, 43),
    Orange = cc.c3b(254, 155, 59),
    Gray = cc.c3b(149, 149, 149), -- 灰
    Deep = cc.c3b(222, 209, 147)  -- 灰
}

QUEST_COLOR = {
    MAIN = cc.c3b(0xff, 0x72, 0),
    SUB = cc.c3b(0x13, 0xe2, 0x12),
    FINISH = cc.c3b(132, 255, 0),
    NOTFINISH = cc.c3b(246, 255, 0),
    DES = cc.c3b(0xe5, 0xdd, 0xd2),
    BOSS = cc.c3b(255, 20, 147),
    EQUIP = cc.c3b(0xff, 0x35, 0xa2),
    DIALY = cc.c3b(0xff, 0xfd, 0x52)
}

-- 怪物名字颜色(2021.5.17 由策划李沛歌提供)
MONSTER_NAME_COLOR = {
    BLUE = cc.c3b(0, 0x8a, 0xe8),
    YELLOW = cc.c3b(0xf6, 0xff, 0),
    PINK = cc.c3b(0xff, 0x35, 0xba),
    ORANGE = cc.c3b(0xff, 0x7f, 0),
    RED = cc.c3b(0xeb, 0, 0xb),
    GREEN = cc.c3b(0x13, 0xe2, 0x12),
    PURPLE = cc.c3b(255, 0, 236)
}

ACTIVITYSTATE = {
    Activity_End = 0,
    Activity_Begin = 1
}

FirstPlayer = {
    firstplayer_pid = 1,
    firstplayer_reborn = 2,
    firstplayer_level = 3,
    firstplayer_gender = 4,
    firstplayer_cloth = 5,
    firstplayer_weapon = 6,
    firstplayer_wings = 7,

    firstplayer_name = 1,
    firstplayer_message = 2
}

CityMaster = {
    city_master_pid = 0,
    city_master_gender = 1,
    city_master_job = 2,
    city_master_name = 0
}

ActivityState = {
    stopped = 1, -- 已结束
    unstart = 2, -- 未开始
    started = 3  -- 进行中
}

ActivityGroup = {
    min = 1,
    vip = 1,  -- VIP活动
    dshd = 2, -- 定时活动
    qthd = 3, -- 全天活动
    rcfb = 4, -- 日常副本
    sjlz = 5, -- 世界领主
    dtlz = 6, -- 地图领主
    hhfb = 7, -- 行会副本
    max = 7
}

-- 快速购买类型
QuickBuyType = {
    buy_reborn_points = 1,     -- 购买转生修为
    buy_samsara_points = 2,    -- 购买轮回修为
    buy_achievement_points = 3 -- 购买成就点数
}

gdActivityDefinition = {
    MeiNvHuSongData = {
        Meinvhusong_exp = 0,
        Meinvhusong_money = 1,
        Meinvhusong_isdouble = 2,
        Meinvhusong_round_max = 3,
        Meinvhusong_refresh_max = 4

    }
}

IconTips = {
    T_friend = 1,
    T_inviteguild = 2,
    T_forgetreward = 3,
    T_findmaster = 4,
    T_findapprentice = 5,
    T_itemendure = 6,
    T_shortmedicinal = 7,
    T_mining = 8,
    T_perpareactivity = 9,
    T_cansecondsactivity = 10,
    T_trade = 11,
    T_team = 12,
    T_bagfull = 13,
    T_perpareboss = 14,
    T_itembroken = 15,
    -- T_reborntips      = 16,
    -- T_hollowitem      = 17,
    --T_kf3v3 = 16,
    T_rubbish = 18,
    T_boothsell = 19,
    T_mail = 20,
    T_gczbegin = 21,
    T_fullpackage = 22,
    T_exp_store = 23,
    T_kfyz = 24,
    T_xsrw = 25,
    T_guild_call = 26,
    T_team_call = 27,
    T_impeach = 28,
    T_scgm = 29,
    T_compose = 30,
    T_another_compose = 31,
    T_other_compose = 32,
    T_guild_invite = 33,
    T_guild_merge = 34,
    T_Max = 35

}

GuideTips = {
    T_private_chat = 1,      -- 有新的私聊信息
    T_join_guild = 2,        -- 70级提示加公会
    T_join_team = 3,         -- 43级提示组队
    T_set_title = 4,         -- 获得2个以上可装备称号
    T_award_vitality = 5,    -- 可领取活跃奖励
    T_take_activity = 6,     -- 可参加活动
    T_lost_activity = 7,     -- 资源找回
    T_guild_war = 8,         -- 攻城战（行会战）开启
    T_fast_shop_hp = 9,      -- 随身商店（血药耗尽且包内无药）
    T_upgrade_exercise = 10, -- 内功可升级
    T_fast_shop_mp = 11,     -- 随身商店（BUFF没了，雪莲也没了）
    T_recovery = 12,         -- 有3件以上可回收装备
    T_zhanshen = 13,         -- 战神可激活
    T_shenlu = 14,           -- 有可升级的神炉装备
    T_jizhan_boss = 15,      -- 75级激战boss
    T_achieve = 16,          -- 有新成就奖励可领取
    T_biqi = 17,             -- 当前界面守卫不满16个，且此时有守卫可用
    T_max = 18
}

ATTR_RULE = {
    INTEGER        = 1, -- 固定数值
    SECTION        = 2, -- 区间段（10-20）
    PERCENT        = 3, -- 百分比
    PERTHOUSAND    = 4, -- 千分比
    PERTENTHOUSAND = 5, -- 万分比
    REFERENCE      = 6, -- 参照属性（1/100）
    CUSTOM         = 7, -- 自定义

}

INTERACTION_KEY = {
    AddFriend = 1, -- 添加好友
    Transaction = 2,
    Talk = 3,
    ViewEquip = 4,
    AddEnemy = 5, -- 添加仇人
    Grenade = 6,
    Apprentice = 7,
    TeamInvit = 8,      -- 邀请组队
    InvitGuild = 9,
    TeamSetLeader = 10, -- 移交队长
    TeamQuit = 11,      -- 退出队伍
    UpdateGuildPostion = 12,
    DownGuildPostion = 13,
    GiveGuildMaster = 14,
    KickOutGuild = 15,
    DelFriend = 16,
    addBlackList = 17,     -- 添加黑名单
    TeamKick = 18,         -- 踢出队伍
    ArenaTeamInvite = 19,  -- 竞技场队伍邀请
    ArenaTeamKick = 20,    -- 竞技场队伍踢人
    ArenaTeamLeader = 21,  -- 竞技场队伍移交队长
    DelEnemy = 22,         -- 删除仇人
    DelBlackList = 23,
    VoicePermissions = 24, -- 是否开启语音权限
    ViewHeroEquip = 25     -- 查看英雄装备
}

DZY_INTERACTION_KEY = {
    ViewEquip = 1,      -- 查看装备
    TALK = 2,           -- 私聊
    AddFriend = 3,      -- 加好友
    TeamInvit = 4,      -- 组队邀请
    InvitGuild = 5,     -- 帮会邀请
    AddBlackList = 6,   -- 添加至黑名单
    DelFriend = 7,      -- 移除好友
    DelEnemy = 8,       -- 移除仇人
    DelBlackList = 9,   -- 移除黑名单
    TeamKick = 10,      -- 踢出队伍
    TeamSetLeader = 11, -- 移交队长
    Transaction = 12    -- 交易
}

--背包格子位置编号的编排
ITEM_BAG = {
    getEndIndex = function(startIndex)
        local endIndex = 0
        if startIndex == PLAYER_BAG_BEGIN then
            endIndex = PLAYER_BAG_BEGIN + MyRole.getProp(ENTITY_PROP_BAG_SLOT) - 1
        end
        if startIndex == TREASURE_BAG_BEGIN then
            endIndex = TREASURE_BAG_END
        end
        if startIndex == LUCKY_COMPASS_BAG_BEGIN then
            endIndex = LUCKY_COMPASS_BAG_END
        end
        if startIndex == MARKET_BAG_BEGIN then
            endIndex = MARKET_BAG_END
        end
        if startIndex == HOLLOW_BAG_BEGIN then
            endIndex = HOLLOW_BAG_END
        end
        if startIndex == NPC_BAG_BEGIN then
            endIndex = NPC_BAG_END + MyRole.getProp(ENTITY_PROP_NPC_BAG_SLOT) - 1
        end
        if startIndex == ZHUZAO_BAG_BEGIN then
            endIndex = ZHUZAO_BAG_END
        end
        return endIndex
    end,
    getBagSlot = function(startIndex) --获取当前用户的背包可用背包格子数（已解锁的数量，而非空闲的数量）————此代码为临时代码，建议转到ItemOperate
        local bagSlot = nil
        if startIndex == PLAYER_BAG_BEGIN then
            bagSlot = MyRole.getProp(ENTITY_PROP_BAG_SLOT)
        elseif startIndex == NPC_BAG_BEGIN then
            bagSlot = MyRole.getProp(ENTITY_PROP_NPC_BAG_SLOT)
        elseif startIndex == MARKET_BAG_BEGIN then
            bagSlot = MyRole.getProp(ENTITY_PROP_MARKET_BAG_SLOT)
        end
        return bagSlot
    end,
    getEndIndexAvailable = function(startIndex) --获取当前背包最后一个位置的索引
        local endIndexAvailable = nil
        if startIndex >= PLAYER_BAG_BEGIN and startIndex <= PLAYER_BAG_END then
            endIndexAvailable = PLAYER_BAG_BEGIN + MyRole.getProp(ENTITY_PROP_BAG_SLOT) - 1
        elseif startIndex >= NPC_BAG_BEGIN and startIndex <= NPC_BAG_END then
            endIndexAvailable = NPC_BAG_BEGIN + MyRole.getProp(ENTITY_PROP_NPC_BAG_SLOT) - 1
        elseif startIndex == TREASURE_BAG_BEGIN then
            endIndexAvailable = TREASURE_BAG_END
        elseif startIndex == LUCKY_COMPASS_BAG_BEGIN then
            endIndexAvailable = LUCKY_COMPASS_BAG_END
        elseif startIndex == MARKET_BAG_BEGIN then
            endIndexAvailable = MARKET_BAG_BEGIN + MyRole.getProp(ENTITY_PROP_MARKET_BAG_SLOT)
        elseif startIndex == ZHUZAO_BAG_BEGIN then
            endIndexAvailable = ZHUZAO_BAG_END
        end
        return endIndexAvailable
    end
}

-- 装备部位排序（陈潮定的顺序）
ITEM_POSITION_SORT = { BAG_POS_EQUIP_WEAPON, -- 武器
    BAG_POS_EQUIP_CLOTH,                     -- 衣服
    BAG_POS_EQUIP_HELMET,                    -- 头盔
    BAG_POS_EQUIP_BELT,                      -- 腰带
    BAG_POS_EQUIP_NECKLESS,                  -- 项链
    BAG_POS_EQUIP_RING,                      -- 戒指
    BAG_POS_EQUIP_RING_TWO,                  -- 戒指2
    BAG_POS_EQUIP_BANGLE,                    -- 护腕
    BAG_POS_EQUIP_BANGLE_TWO,                -- 护腕2
    BAG_POS_EQUIP_SHOES,                     -- 鞋子
    BAG_POS_EQUIP_SOUL_BEAD,                 -- 魂珠
    BAG_POS_EQUIP_SHIELD,                    -- 盾牌
    BAG_POS_EQUIP_STONE,                     -- 宝石
    BAG_POS_EQUIP_PHYLACTERY,                -- 血符
    BAG_POS_EQUIP_MEDAL,                     -- 勋章
    BAG_POS_EQUIP_SHOULDER_PADS,             -- 护肩
    BAG_POS_EQUIP_KNEE_PADS,                 -- 护膝
    BAG_POS_EQUIP_VIZARD,                    -- 面甲
    BAG_POS_EQUIP_PENDANT,                   -- 吊坠
    BAG_POS_EQUIP_BAMBOO_HAT,                -- 笠帽
    BAG_POS_EQUIP_SILK_RIBBON,               -- 纶巾
    BAG_POS_EQUIP_GOBE,                      -- 护镜
    BAG_POS_EQUIP_DRUM,                      -- 韧鼓
    BAG_POS_EQUIP_HAND_CHAIN,                -- 手链
    BAG_POS_EQUIP_JADE_PENDANT               -- 玉佩
}

-- 标记道具在背包中位置
POS_TAG_PLAYER = 1
POS_TAG_HERO = 2

-- 套装部位（主要用于排序）
ITEM_EQUIP_SUIT_POSITION = {
    [1] = {
        position = BAG_POS_EQUIP_WEAPON, -- 武器
        type = ITEM_TYPE_EQUIP_WEAPON
    },
    [2] = {
        position = BAG_POS_EQUIP_CLOTH, -- 衣服
        type = ITEM_TYPE_EQUIP_CLOTH
    },
    [3] = {
        position = BAG_POS_EQUIP_HELMET, -- 头盔
        type = ITEM_TYPE_EQUIP_HELMET
    },
    [4] = {
        position = BAG_POS_EQUIP_NECKLESS, -- 项链
        type = ITEM_TYPE_EQUIP_NECKLESS
    },
    [5] = {
        position = BAG_POS_EQUIP_BANGLE, -- 护腕
        type = ITEM_TYPE_EQUIP_BANGLE,
        number = 1
    },
    [6] = {
        position = BAG_POS_EQUIP_BANGLE_TWO, -- 护腕2
        type = ITEM_TYPE_EQUIP_BANGLE,
        number = 2
    },
    [7] = {
        position = BAG_POS_EQUIP_RING, -- 戒指
        type = ITEM_TYPE_EQUIP_RING,
        number = 1
    },
    [8] = {
        position = BAG_POS_EQUIP_RING_TWO, -- 戒指2
        type = ITEM_TYPE_EQUIP_RING,
        number = 2
    },
    [9] = {
        position = BAG_POS_EQUIP_BELT, -- 腰带
        type = ITEM_TYPE_EQUIP_BELT
    },
    [10] = {
        position = BAG_POS_EQUIP_SHOES, -- 鞋子
        type = ITEM_TYPE_EQUIP_SHOES
    },
    [11] = {
        position = BAG_POS_EQUIP_SHOULDER_PADS, -- 护肩
        type = ITEM_TYPE_EQUIP_SHOULDER_PADS
    },
    [12] = {
        position = BAG_POS_EQUIP_KNEE_PADS, -- 护膝
        type = ITEM_TYPE_EQUIP_KNEE_PADS
    },
    [13] = {
        position = BAG_POS_EQUIP_VIZARD, -- 面甲
        type = ITEM_TYPE_EQUIP_VIZARD
    },
    [14] = {
        position = BAG_POS_EQUIP_PENDANT, -- 吊坠
        type = ITEM_TYPE_EQUIP_PENDANT
    }
}

-- 膜拜的数据类型
MO_BAI_DATA = {
    Mobai_baseexp = 0,
    Mobai_isdouble = 1,
    Mobai_maxrefresh = 2,
    Mobai_maxmobaicnt = 3,
    Mobai_maxaddmobaicnt = 4
}

HeroAttackModel = {
    HeroAttackModelNormal = 1,    -- 强攻
    HeroAttackModelDefMonster = 2 -- 抗怪
}

-- 英雄技能
HeroSkill = {
    -- 战士
    [1] = { { 80101, 0 }, -- 攻杀
        { 80201, 3 },     -- 刺杀
        { 80301, 2 },     -- 半月
        { 80401, 1 }      -- 烈火
    },

    -- 法师
    [2] = { { 90101, 3 }, -- 雷电术
        { 90201, 1 },     -- 火墙
        { 90301, 4 },     -- 魔法盾
        { 90401, 2 }      -- 冰咆哮
    },

    -- 道士
    [3] = { { 100101, 3 }, -- 灵魂火符
        { 100201, 1 },     -- 群体治愈术
        { 100301, 2 },     -- 群体施毒术
        { 100401, 4 }      -- 召唤神兽
    }
}

Monster_Type = {
    Monster_TYPE_Common = 1,   -- 野外
    Monster_TYPE_Activity = 2, -- 活动
    Monster_Type_Instance = 3, -- 副本
    Monster_Type_Sercet = 4,   -- 秘境
    Monster_Type_Boss = 5,     -- boss
    Monster_Type_Cream = 6     -- 精英
}

-- 运动操控
Vehicle_Type = {
    red = 1,   -- 红球
    yellow = 2 -- 篮球
}

-- 运动状态
Vehicle_State = {
    idle = 0,   -- 静止
    pursue = 1, -- 跟随
    arrive = 2  -- 就位
}

-- 开启仓库标志
Ware_Open = 0

-- 符文操作分栏类型
PAPER_OP_TYPE_NIL = 0
PAPER_OP_TYPE_ACTIVE = 1
PAPER_OP_TYPE_EXCHANGE = 2
PAPER_OP_TYPE_RECYCLE = 3

-- 玩家显示的最多邮件数量
MailMaxCount = 50

-- 英雄复活时间
HeroReliveTime = 10

-- OPPO渠道ID(新的)
CHANNEL_FUGU_OPPO = 20200

-- 每次攻击动作时间
ATTACK_ACTION_DURATION = 1
M_ATTACK_ACTION_DURATION = 1
M_ATTACK_CONTROL_DURATION = 1

SmeltColorList = {
    [0] = "w",
    [1] = "g",
    [2] = "b",
    [3] = "p",
    [4] = "r"
}

LodeColor = {
    [1] = "b",
    [2] = "p",
    [3] = "y",
    [4] = "r"
}

-- 分身星级
sepLevel = {
    [1] = ENTITY_PROP_SEPARATION_WARTERlEVEL,
    [2] = ENTITY_PROP_SEPARATION_FIRElEVEL,
    [3] = ENTITY_PROP_SEPARATION_SOILlEVEL,
    [4] = ENTITY_PROP_SEPARATION_THUNDERlEVEL
}

-- 角色提升提示
ENUM_PROMOTE = {
    GUARD_GUARD = 1,  -- 守护
    GUARD_SOUL  = 2,  -- 魂珠
    GUARD_FLAG  = 3,  -- 战旗
    SSJJ        = 25, -- 神圣剑甲
    BaoWu       = 26, -- 宝物
    NTGM        = 27, -- 逆天改命
    MAX         = 30
}

-- 开启等级
BaobaoOpenLevel = 20 -- 宝宝开启等级

-- 切换左侧任务栏所需完成的任务id
SwitchTaskPanelQuestId = 0

-- 藏宝地图开启宝箱物品sid（抽奖券）
TreasureMapOpenBoxKey = 72111
TREASURE_MAP_QUEST_CNT = 10 -- 藏宝图任务次数

FLY_SHOE_OPEN_LEVEL = 70    -- 小飞鞋开启等级
XYSL_LVL = 400
SHAOZHU_QUEST = 690

SettingSecondMenuMax = 30
SettingMenuId = {
    PT_EQUIP = 1,  -- 普通装备
    YX_EQUIP = 2,  -- 优秀装备
    JL_EQUIP = 3,  -- 精良装备
    XY_EQUIP = 4,  -- 稀有装备
    SS_EQUIP = 5,  -- 史诗装备
    TeJie = 6,     -- 特戒
    JinBin = 7,    -- 金币
    POTION = 8,    -- 药水
    Other = 9,     -- 其他
    ShenBing = 10, -- 神兵
    SH_EQUIP = 11  -- 神话装备
}

-- 快捷栏类型
ShortcutBarType = {
    HP_POTION = 1,  -- 只能放红药
    MP_POTION = 2,  -- 只能放蓝药
    SUN_POTION = 3, -- 只能放太阳水
    FREED = 4       -- 可自由支配
}

ShowRedPointItem = {
    [70608] = true,
    [70609] = true,
    [70610] = true,
    [70611] = true,
    [70612] = true,
    [72509] = true,
    [72510] = true,
    [72901] = true,
    [72902] = true,
    [72903] = true,
    [73137] = true,
    [73138] = true,
    [73221] = true,
    [73222] = true,
    [73223] = true,
    [73224] = true
}

SPECIAL_RING_BOX = 65197            -- 史诗特戒宝箱
SPECIAL_RING_NPC = 894              -- 特戒大师

SkillPos4OpenLevel = 10             -- 技能位4开启等级
SkillPos5OpenLevel = 20             -- 技能位5开启等级
WingSkillId = 40101                 -- 翅膀技能id
SjStoneId = 80001                   -- 随机石
HcStoneId = 80003                   -- 回城石
SunPotionId = 72913                 -- 太阳水
QxSunPotionId = 72914               -- 强效太阳水
StoneOpenLevel = 15                 -- 随机/回城石开启等级
NPCQuestSymbolHeight = 60           -- npc任务符号高度
WarehouseAndAppraisalOpenLevel = 13 -- 仓库和鉴定开启等级

UI_LAYER_BOTTOM = 1
UI_LAYER_MID = 2
UI_LAYER_TOP = 3

COMBAT_PROP_CLASS_DATA = 1
COMBAT_PROP_CLASS_MIN = 2
COMBAT_PROP_CLASS_MAX = 3

ACTION_DEFINE_86666 = 86666
ACTION_DEFINE_86667 = 86667
ACTION_DEFINE_11256 = 11256

AutoAttacMap = {
    [1] = 1623,
    [2] = 1624,
    [3] = 1625,
    [4] = 1626,
    [5] = 1627,
    [6] = 1628,
    [7] = 1629,
    [8] = 1630,
    [9] = 1631,
    [10] = 1806,
    [11] = 1807,
    [12] = 1808,
    [13] = 1809,
    [14] = 1810,
    [15] = 1811
}

lingwen_posy = { 195, 170, 80, 185, 215, 195 } -- 灵纹特效界面相对位置
lingwen_scale = { 1.8, 2, 2, 1.7, 1.7, 1.6 }   -- 灵纹特效界面缩放比例

TONGMO_MONSTER = 1002
TONGMO_PLAYER = 1010010

-- 寄售行货币类型
TRANSACTION_PRICE_TYPE = 3

-- 是否打开过建功立业界面
JIANGONGLIYE_LOOK = false

-- 装备投保最高上限
EQUIP_PROTECT_MAX = 99

-- 常量值（定义常量类请用Define）
---------------------------------------------确定一定会用的start------------------------------------------------------
GAME_REMOTE_SAVE_URL = "remotepackage/" .. XF_GAME_CODE .. "/"
DOUBLE_CLICK_SPEED = 0.2 -- 双击速度
RECHARGE_RATE = 10 -- 充值比例
---------------------------------------------确定一定会用的end--------------------------------------------------------

OFFON_EQUIP_CHANGE = 0 -- 开关 装备 更换
OFFON_ADD_HURT = 0 -- 客户端添加伤害
SHOW_PLAYER_TIME = 0 -- 显示人物时间
SHOW_MONSTER_TIME = 0 -- 显示怪物时间
SHOW_PET_G_TIME = 0 -- 显示召唤物时间
SHOW_PET_TIME = 0 -- 显示萌宠时间
SHOW_GUILDS_TIME = 0 -- 显示同工会时间
SHOW_SHAROW_TIME = 0 -- 显示影子时间
SHOW_SPERING_TIME = 0 -- 显示特戒时间

OPEN_STONE_SEC = 0

HIDE_ALL_PLAYER = 0 -- 是否隐藏所有玩家
HIDE_ALL_PETS = 0 -- 屏蔽召唤物

UI_REDPACK_IS_OPEN = true -- 红包界面是否显示

NPC_BAG_SLOT_MAX = 780

GAMEROLE_STATE_ID = 123456789 -- 人物初始key

ReachDistance = 3
ReachNPCDistanceNormal = 8 -- 人物接任务与NPC 所需要的最远
ReachNPCDistanceQuest = 8 -- 还没看，呵呵
AUTOSEARCHRANK = 1000

PER_FRAME_SIZE = 1048576 -- 每一最大处理消息尺度
PER_FRAME_MAX = 10 -- 一帧中创建最大下载消息条数

BUTTON_COOLDOWN_TIME = 0 -- 按钮按钮冷却时间（在这个时间内部不能重复点击）
CONFIRM_COOLDOWN_TIME = 0.5 -- 确认按钮冷却时间
RADIO_COOLDOWN_TIME = 0.5 -- RADIO按钮冷却时间，含Tree控件菜单在内的控件
BOSSTEST = 0 -- boss 测试

ENTITY_RCFB_BOSS = 1921

IOS_CHARGE_NAME = ""

gdServerDays = 0
gdHeFuDay = 0

-- 覆盖透明度
ENITITY_ALPHA = 180

-- 宝宝移动速度  
ENTITY_HERO_SPEED = 3
ENTITY_PET_SPEED = 3
-- DEL 人物差值
MAPDEL = 0

JuHeData = {}

NR_PreciseRec_Switch = false

OtherGameRole = {}

TianTuoAccountInfo = {
    uid = "",
    uname = ""
}

RechargeInfoData = {}

HuoyueData = {
    huoyueboss = 0,
    huoyuechumo = 0,
    huoyuewakuang = 0,
    huoyuefuben = 0,
    huoyuelongcheng = 0,
    huoyuesore = 0
}

TempData = {
    ghostProp = {},

    setGhostProp = function(key, index, value)
        TempData.ghostProp[key .. "prop" .. index] = value
    end,

    getGhostProp = function(key, index)
        return TempData.ghostProp[key .. "prop" .. index] or 0
    end
}

GczData = {
    phase = 0
}

GameRoleIsOk = false -- 初始化完成
GameRoleCreateOneTime = false -- 创建一次

ServerStatus = {
    LOGIN_OK = 0
}

ModuleName = {
    CHAT = "chat"
}
ChatData = {
    LAST_CHAT_TYPE = "last_chat_type",
    LAST_CHAT_ID = "last_chat_id",

    -- chat record list
    HORN_CHAT_LIST = "horn_chat_list",
    NORM_CHAT_LIST = "norm_chat_list",
    CHAT_TYPE = "chat_type",
    PID = "pid",
    PLAYER_NAME = "player_name",
    GENDER = "gender",
    VIP_LEVEL = "vip_level",
    CHAT_TEXT = "chat_text",

    -- chat partner
    CHAT_PARTNER_PID = "chat_partner_pid",
    CHAT_PARTNER_NAME = "chat_partner_name",

    -- chat item data
    CHAT_ITEM_PID = "chat_item_pid",
    CHAT_ITEM_ID = "chat_item_id",
    CHAT_ITEM_DATA_LIST = "chat_item_data_list",
    CHAT_ITEM_DATA = "chat_item_data",

    -- gm flag
    CHAT_TO_GM = "chat_to_gm",
    CHAT_CHUANYIN_OPEN = false, -- 是否在播放传音消息
    CHAT_EXPANED = false, -- 是否已展开，为展开为false（3行模式），展开true（6行模式）
    clear = function()
        ChatData.CHAT_CHUANYIN_OPEN = false
        ChatData.CHAT_EXPANED = false
    end
}

DeviceLocalTime = 0

-- 上古战场BOSS动态
SGZCBOSSData = {}
SGZCAliveBosses = {}
SGZCNotAppearCount = 0

-- 场景分线
SceneLineData = {
    scene_static_id = 0,
    scene_lines = {}
}

-- 显示交易图标
TradeReqData = {
    showTradeIcon = false,
    other_player_id = 0,
    other_player_name = ""
}

-- 荣誉数据
MyHonorData = {
    attr_honor_start = 0
}

-- 超值理财奖励
czlc_rewards = {{
    level = 80,
    ingot = 1500
}, {
    reborn = 2,
    ingot = 1500
}, {
    reborn = 3,
    ingot = 1500
}, {
    reborn = 4,
    ingot = 2500
}, {
    reborn = 5,
    ingot = 3000
}, {
    reborn = 7,
    ingot = 5000
}}

last_gjzsd_use_clock = 0
last_cjzsd_use_clock = 0

last_gjlhd_use_clock = 0
last_cjlhd_use_clock = 0
last_forgeqh_use_clock = 0
last_forgeall_use_clock = 0

guide_recordLevel = 0

openShouchong = 0
openYBHSDouble = 0
-- oppo专属活动
SdkOppoInfo = {
    isGameCenterLaunched = false,
    vipLevel = 0
}

Shop18_Close = 0 -- 公会商城

LoadFileEnd = 0

HASOPENKUANGBAO = 0

KF3V3 = {
    competition_id = 0,
    competition_time = 0,
}

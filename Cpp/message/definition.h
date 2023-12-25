
#ifndef _DEFINITION_H_INCLUDED
#define _DEFINITION_H_INCLUDED

#include "EventDefinition.h"

// 角色名称最大长度
#define PLAYER_NAME_MAX 7
// 角色名称最小长度
#define PLAYER_NAME_MIN 2
// 玩家同时申请加入行会最大数量
#define PLAYER_APP_MAX 10
// 行会名称最大长度
#define GUILD_NAME_MAX 7
// 行会公告最大长度
#define GUILD_NOTICE_MAX 80
// 战队名称最大长度
#define ZHANDUI_NAME_MAX 7
// 竞技战队名称最大长度
#define ARENA_TEAM_NAME_MAX 6
// 邮件标题最大长度
#define MAIL_TITLE_MAX 20
// 邮件内容最大长度
#define MAIL_CONTENT_MAX 100
// 最大服务器ID
#define SERVER_ID_MAX 9999
// 英雄相关
#define SUMMON_PLAYER_LEVEL 20
// 英雄死亡复活时间
#define ENTITYHERO_RELIVE_TIME 10
// 宠物tag
#define ENTITY_PET_TAG 9999
// int数值上限
#define THINGS_MAX 2100000000
#define COIN_MAX 9999999999

// 攻击间隔
#define ATTACK_ACTION_DURATION 300
#define MOVE_ACTION_DURATION 800
#define BASE_SPEED 3.0
#define ATTACK_ACTION_DURATION_MAX 1800
#define MOVE_ACTION_WAVE_MAX 810
#define MOVE_DURATION_INIT 100

enum RechargeConstants
{
	RECHARGE_RATE = 10, // 充值比例
};

// 数值增加方式
enum VALUEADDTYPE
{
	VALUEADDTYPE_PERCENT = 1, // 百分比增加
	VALUEADDTYPE_VALUE = 2,	  // 固定值增加
};

// 拍卖行交易类型
enum ConsignmentType
{
	CONSIGNMENT_BUY = 1,		   // 购买
	CONSIGNMENT_SALE = 2,		   // 出售
	CONSIGNMENT_AUCTION = 3,	   // 拍卖
	CONSIGNMENT_PURCHASE_BUY = 4,  // 求购
	CONSIGNMENT_PURCHASE_SELL = 5, // 卖出
};

////拍卖行上架持续时间
enum ConsignmentTimeType
{
	CONSIGNMENT_TIME_TYPE_12 = 1,
	CONSIGNMENT_TIME_TYPE_24 = 2,
};

enum OPT_TYPE
{
	POST,
	GET,
};

// 挖矿状态
enum MiningType
{
	MINING_TYPE_NORMAL,		// 可以掠夺
	MINING_TYPE_ROBBING,	// 正在被掠夺中
	MINING_TYPE_CANNOT_ROB, // 不能掠夺
};

// 实体状态ID
enum EntityStateID
{
	ENTITY_STATE_INVALID,
	ENTITY_STATE_IDLE,			// 空闲
	ENTITY_STATE_DEAD,			// 死亡
	ENTITY_STATE_BACKING,		// 返回
	ENTITY_STATE_TRACKING,		// 追踪
	ENTITY_STATE_RUNAWAY,		// 逃跑
	ENTITY_STATE_ATTACKING,		// 攻击
	ENTITY_STATE_FOLLOWING,		// 跟随
	ENTITY_STATE_PROTECTED,		// 未用
	ENTITY_STATE_MINE,			// 挖矿
	ENTITY_STATE_TRADE,			// 交易
	ENTITY_STATE_PATROL,		// 巡逻
	ENTITY_STATE_DO_TASK,		// 机器人做任务
	ENTITY_STATE_OFFLINE,		// 离线
	ENTITY_STATE_OFF_IDLE,		//
	ENTITY_STATE_OFF_ATTACKING, // 离线攻击
	ENTITY_STATE_OFF_PATROL,	// 巡回
	ENTITY_STATE_OFF_PICKUP,	// 离线拾取
	ENTITY_STATE_OFF_TRACKING,	// 离线追踪
	ENTITY_STATE_OFF_DIE,		// 离线死亡
};

// 状态事件
enum EntityStateEvent
{
	ENTITY_EVENT_STATE_OVER,		  // 当前状态结束
	ENTITY_EVENT_FOUND_TARGET,		  // 发现目标
	ENTITY_EVENT_LOST_TARGET,		  // 丢失目标
	ENTITY_EVENT_TARGET_OUT_OF_RANGE, // 目标超出范围
	ENTITY_EVENT_TARGET_IN_RANGE,	  // 目标进入范围
	ENTITY_EVENT_FAR_OWNER,			  // 距离拥有者太远
	ENTITY_EVENT_PATROL_START,		  // 寻路开始
	ENTITY_EVENT_PATROL_FINISH,		  // 寻路结束
	ENTITY_EVENT_PICK_START,		  // 开始拾取
	ENTITY_EVENT_PICK_FINISH,		  // 拾取完毕
	ENTITY_EVENT_PET_ONLINE,
	ENTITY_EVENT_PET_OFFLINE,
	ENTITY_EVENT_ROBOT_TASK_FINISH,

};

// 实体类型
enum EntityType
{
	ENTITY_TYPE_INVALID = 0,
	ENTITY_TYPE_PLAYER = 1,		   // 玩家
	ENTITY_TYPE_NPC = 3,		   // NPC
	ENTITY_TYPE_MONSTER_GROUP = 4, // 怪物组
	ENTITY_TYPE_MONSTER = 5,	   // 怪物
	ENTITY_TYPE_SKILL = 6,		   // 技能实体
	ENTITY_TYPE_ITEM = 9,		   // 物品
	ENTITY_TYPE_PET = 10,		   // 宠物
	ENTITY_TYPE_DOG = 11,		   // 道士狗
	ENTITY_TYPE_MARKET = 12,	   // 摊位
	ENTITY_TYPE_HERO = 13,		   // 英雄
	ENTITY_TYPE_PLAYER_CLONE = 14, // 分身
	ENTITY_TYPE_MINER = 15,		   // 矿工
	ENTITY_TYPE_ANIMAL = 16,	   // 骷髅
	ENTITY_TYPE_MAX,
};

// 实体类型子类型
enum EntityTypeSubType
{
	ENTITY_TYPE_DOG_INVALID = 0,
	ENTITY_TYPE_DOG_PLAYERDOG = 1,	 // 神兽(玩家)
	ENTITY_TYPE_DOG_PLAYERML = 2,	 // 月灵(玩家)
	ENTITY_TYPE_DOG_HERODOG = 3,	 // 神兽(英雄)
	ENTITY_TYPE_DOG_PLAYERTIGER = 4, // 老虎玩家(老虎)
	ENTITY_TYPE_DOG_BEAUTY = 5,		 // 美女（玩家）
	ENTITY_TYPE_DOG_KULOU = 6,		 // 骷髅（玩家）
	ENTITY_TYPE_DOG_MAX = 7,
};

// 这个定义太复杂了, 不会自动导出到definition.lua中, 需要在script_definition.lua中手动修改
enum EntityScope
{
	ENTITY_SCOPE_PLAYER = 1 << ENTITY_TYPE_PLAYER,		// 0x0002
	ENTITY_SCOPE_NPC = 1 << ENTITY_TYPE_NPC,			// 0x0008
	ENTITY_SCOPE_MG = 1 << ENTITY_TYPE_MONSTER_GROUP,	// 0x0010
	ENTITY_SCOPE_MONSTER = 1 << ENTITY_TYPE_MONSTER,	// 0x0020
	ENTITY_SCOPE_SKILL = 1 << ENTITY_TYPE_SKILL,		// 0x0040
	ENTITY_SCOPE_ITEM = 1 << ENTITY_TYPE_ITEM,			// 0x0200
	ENTITY_SCOPE_PET = 1 << ENTITY_TYPE_PET,			// 0x0400
	ENTITY_SCOPE_DOG = 1 << ENTITY_TYPE_DOG,			// 0x0800
	ENTITY_SCOPE_MARKET = 1 << ENTITY_TYPE_MARKET,		// 0x1000
	ENTITY_SCOPE_HERO = 1 << ENTITY_TYPE_HERO,			// 0x2000
	ENTITY_SCOPE_CLONE = 1 << ENTITY_TYPE_PLAYER_CLONE, // 0x4000
	ENTITY_SCOPE_ALL = ENTITY_SCOPE_PLAYER | ENTITY_SCOPE_NPC | ENTITY_SCOPE_MONSTER | ENTITY_SCOPE_SKILL | ENTITY_SCOPE_ITEM | ENTITY_SCOPE_PET | ENTITY_SCOPE_DOG | ENTITY_SCOPE_MARKET | ENTITY_SCOPE_HERO | ENTITY_SCOPE_CLONE,
};

// 攻击模式
enum AttackMode
{
	ATTACK_MODE_BEGIN = 0,

	ATTACK_MODE_PEACE = 0,	 // 和平, 不对任何玩家造成伤害
	ATTACK_MODE_TEAM = 1,	 // 队伍,	对队伍外的玩家造成伤害
	ATTACK_MODE_GUILD = 2,	 // 行会, 只对行会外的玩家造成伤害
	ATTACK_MODE_ANY = 3,	 // 全体, 对任何玩家都能造成伤害
	ATTACK_MODE_FACTION = 4, // 帮派, 只对帮派外的玩家造成伤害  实际现在（2022-6-13）是阵营
	ATTACK_MODE_RED = 5,	 // 善恶, 只对红名玩家和灰名玩家造成伤害
	//ATTACK_MODE_FACTION_M_ONLY = 6,
	//ATTACK_MODE_FACTION_P_ONLY = 7,
	//ATTACK_MODE_RED_AND_DOG = 8,
	//ATTACK_MODE_RED_ONLY = 9,
	//ATTACK_MODE_PROTECT = 10,	   // 保护，无法被攻击
	//ATTACK_MODE_MONSTER_ONLY = 11, // 只攻击怪物

	ATTACK_MODE_END,
};

// 伤害类型
enum DamamgeType
{
	NORMAL_DAMAGE = 1,			 // 普通伤害
	FATAL_DAMAGE = 2,			 // 致命伤害
	CAI_JUE_DAMAGE = 3,			 // 裁决伤害
	TU_LONG_DAMAGE = 4,			 // 屠龙伤害
	HUIXIN_DAMAGE = 5,			 // 会心伤害
	HP_RETURNING = 6,			 // 生命回复
	ZHAN_FU_DAMAGE = 7,			 // 战斧伤害
	MO_QIANG_DAMAGE = 8,		 // 魔枪伤害
	BAOBAO_DAMAGE = 9,			 // 宝宝普攻伤害
	BAOBAO_BLOOD = 10,			 // 宝宝流血
	BAOBAO_FENSUI = 11,			 // 粉碎伤害
	MABI_DAMAGE = 12,			 // 麻痹
	MABI_RESIST_DAMAGE = 13,	 // 抗麻痹
	DD_CUTTING_PLAYER = 14,		 // 刀刀切割（玩家）
	PB_CHOPPING_PLAYER = 15,	 // 概率斩杀（玩家）
	DD_CUTTING_MONSTER = 16,	 // 刀刀切割（怪物）
	PB_CHOPPING_MONSTER = 17,	 // 概率斩杀（怪物）
	SUPER_CAIJUE_DAMAGE = 18,	 // 裁决伤害
	SUPER_TULONG_DAMAGE = 19,	 // 屠龙伤害
	SUPER_ZHANFU_DAMAGE = 20,	 // 战斧伤害
	SUPER_MOQIANG_DAMAGE = 21,	 // 魔枪伤害
	PLAYER_EXP_ADD = 22,		 // 玩家经验变化
	PLAYER_POWER_ADD = 23,		 // 玩家战力变化
	SELF_BE_ATTACK = 24,		 // 自生收到的伤害
	CANG_LONG_DAMAGE = 25,		 // 苍龙之力
	PLAYER_LEVEL_ADD = 26,		 // 玩家等级提升
	ZHUOSHAO_DAMGE = 28,		 // 灼烧伤害
	ATTACK_MISS = 29,			 // 闪避
	NORMAL_DAMAGE_LUA_SHOW = 30, // NORMAL_DAMAGE LUA调用不显示伤害，用这个 会在客户端显示伤害
	DOUBLE_DROP = 31,			 // 幻境boss双倍掉落
	BDZZ_DROP = 32,				 // 挂机特权boss必掉紫装即以上
	LEGEND_DAMGE = 33,			 // 神圣伤害
	SMZD_DAMGE = 34,			 // 神秘之电
	POOSON_CRIT_DAMAGE = 37,	 // 毒暴击
	MENTAL_POJIA_EFF = 38,		 // 压倒优势 min
	MENTAL_DUNPAI_EFF = 39,		 // 心法
	MENTAL_MENTAL_SDZH = 40,	 // 心法
	MENTAL_SMZD_TIMES = 41,		 // 神秘之电
	SHIELD_MISS = 42,			 // 护盾 无敌
	ANTI_MABI = 43,				 // 抗麻痹
	FABAO_EFF = 44,				 // 法宝
	MENTAL_POJIA_EFF_MIN = 45,	 // 压倒优势 min
	MENTAL_DUNPAI_EFF_MIN = 46,	 // 恃强凌弱 min
	DOUBLE_FIRE_DAMAGE = 47,	 // 屠龙刀效果（烈火逐日）
	YTJ_COOLDOWN = 48,			 // 倚天剑效果（刷新cd）
	SHL_MEIHUO = 49,			 // 圣火令效果（魅惑）
	BUFF_HXYJ = 50,				 // 会心一击
	SWORDSTORM_DAMAGE = 51,		 // 剑刃风暴
	CRIT_SWORDSTORM_DAMAGE = 52, // 剑刃风暴(暴击)
	DIBAO_TIANXING_DAMAGE = 53,	 // 地爆天星
	XURUO_EFF = 54,				 // 虚弱
	SUCK_BLOOD = 56,			 // 吸血
	REVERSE_DMG = 57,			 // 反伤
	DIVINE_LIGHT = 59,			 // 护体神光格挡
	TRUE_BODY_SB = 60,			 // 蓝银真身闪避
	HOLY_LIGHT = 61,			 // 圣光伤害
	GUARD_HALO = 62,			 // 光辉守护
	HORCRUXES_GUARD = 63,		 // 敏捷之魂闪避
	JIAOXIE = 64,				 // 缴械
	NOSUCK_BLOOD = 64,			 // 反吸血
	NO_BACK = 65,				 // 反回城
	LUCK_DAMAGE = 66,			 // 幸运伤害
	LUCK_DAMAGE_TIMES = 67,		 // 触发幸运伤害次数
};

// 伤害类型
enum DamageType
{
	DAMAGE_TYPE_PHYSICAL = 1, // 物理伤害
	DAMAGE_TYPE_MAGICAL = 2,  // 魔法伤害
	DAMAGE_TYPE_TAOSIM = 3,	  // 道术伤害
};

// 职业类型
enum OccupationType
{
	OCCUPATION_TYPE_PHYSICAL = 1, // 物理
	OCCUPATION_TYPE_MAGICAL = 2,  // 魔法
	OCCUPATION_TYPE_TAOSIM = 3,	  // 道术
	OCCUPATION_TYPE_ALL = 4,	  // 通用
};

// 技能系列
enum SkillSeries
{
	SKILL_SERIES_NO = 0,		// 没有系
	SKILL_SERIES_FLAME = 1,		// 火焰系
	SKILL_SERIES_FROST = 2,		// 冰霜系
	SKILL_SERIES_LIGHTNING = 3, // 雷电系
	SKILL_SERIES_SUMMON = 4,	// 召唤系
	SKILL_SERIES_POISON = 5,	// 毒系
	SKILL_SERIES_PHYSICAL = 6,	// 物理系
	SKILL_SERIES_HTMD = 7,		// 毁天灭地（冰火雷）
};

// 技能类型
enum SkillType
{
	SKILL_TYPE_COMMON_CD = 1, // 无CD的技能（享公共cd）
	SKILL_TYPE_SELF_CD = 2,	  // 有CD的技能
};

// PK状态
enum PKState
{
	PK_STATE_WHITE,	 // 白名
	PK_STATE_YELLOW, // 黄名
	PK_STATE_GRAY,	 // 灰名
	PK_STATE_RED,	 // 红名
	PK_STATE_CLEAN,	 //??
};

// 复活方式
enum ReviveMode
{
	REVIVE_MODE_DEAD = 1, // 原地复活
	REVIVE_MODE_SAFE = 2, // 安全复活
	REVIVE_MODE_RAND = 3, // 随机复活
};

// 原地复活类型
enum InplaceReviveType
{
	INPLACE_REVIVE_FREE = 1,	// 免费原地复活
	INPLACE_REVIVE_DIAMOND = 2, // 花费钻石原地复活
};

// 玩家进入跨服时，对gene采取的动作
enum GeneAction
{
	ACTION_NOT_SYNC = 0, // 保留，但不同步给跨服
	ACTION_DELETE = 1,	 // 删除，且不同步给跨服
	ACTION_SYNC = 2,	 // 保留，并且同步给跨服
};

// 获取服合要求的周边玩家
enum PlayerNearCondition
{
	CONDITION_NEAR_TEAM = 1,
};

// 加载玩家原因
enum PlayerLoadReason
{
	PLAYER_LOAD_REASON_NORMAL, // 正常进入游戏加载
	PLAYER_LOAD_REASON_ARENA,  // 竞技场加载虚拟玩家
	PLAYER_LOAD_REASON_GM,	   // GM查看玩家
};

// 退出跨服地图的原因
enum LeaveCSMapReason
{
	REASON_ENTER_GS_MAP = 0,  // 进入游戏服地图
	REASON_REVIVE = 1,		  // 回城复活
	REASON_SWITCH_CS_MAP = 2, // 从一张跨服地图切换到另一种跨服地图
};

// 进入跨服地图的原因
enum EnterCSMapReason
{
	REASON_INVALID = 0,
	REASON_WAR_ZONE = 1,	 // 战区相关（跨服地图杀怪等）
	REASON_COMMON_CS = 2,
};

// 战区排行榜类型
enum WarZoneRankType
{
	WAR_ZONE_RANK_TYPE_BEGIN = 0,
	WAR_ZONE_RANK_TYPE_KILL_BOSS = 1,
	WAR_ZONE_RANK_TYPE_END = 4,
};

// 实体基础属性
enum EntityProp
{
	/**********************************************************************************************/
	/******************************游戏服需要实时同步给跨服的属性 START****************************/
	/**********************************************************************************************/
	ENTITY_PROP_SYNC_BEGIN = 0,

	ENTITY_PROP_MOVE_SPEED = 1,	 // 移动速度
	ENTITY_PROP_GENE_DAMAGE = 2, // 伤害加成%
	ENTITY_PROP_GENE_BE_DAMAGE = 3,
	ENTITY_PROP_GENE_BE_MAGIC_DAMAGE = 4,
	ENTITY_PROP_GENE_DAMAGE_LAST_ADD = 5,
	ENTITY_PROP_DOG_ATTACK = 6,				 // 狗的战斗力提升
	ENTITY_PROP_GENE_GLJ_DAMAGE = 7,		 // 鬼灵剑伤害加成%，与73属性是并列关系
	ENTITY_PROP_DAMAGE_IMMUNE_ADD = 8,		 // 免伤
	ENTITY_PROP_ACCELERATION_ATTACK = 9,	 // 召唤物攻速加成(万分比)
	ENTITY_PROP_IS_TEAM_LEAD = 10,			 // 是否是队长
	ENTITY_PROP_TEAM_ID = 11,				 // 队伍ID
	ENTITY_PROP_GUILD_ID = 12,				 // 行会ID
	ENTITY_PROP_ZHANDUI_ID = 13,			 // 战队ID
	ENTITY_PROP_ZHANDUI_POST = 14,			 // 在战队中的职位
	ENTITY_PROP_FACTION_ID = 15,			 // 帮派ID 阵营ID
	ENTITY_PROP_FORCE = 117,				 // 战力   --后台写死战力id  不能轻易改变
	ENTITY_PROP_DOG_ATTACK_INTERVAL = 118,	 // 狗攻击间隔
	ENTITY_PROP_DOG_ATTACK_K = 119,			 // 狗攻击系数
	ENTITY_PROP_DOG_ATTACK_DATA = 120,		 // 狗攻击固定值
	ENTITY_PROP_MAX_FORCE = 121,			 // 人物历史最高战力
	ENTITY_PROP_PALSY_CD = 122,				 // 麻痹冷却时间
	ENTITY_PROP_REVIVE_CD = 123,			 // 复活冷却时间
	ENTITY_PROP_MENTAL_JDLD_EFF_TO_CS = 125, // 绝对零度特效
	ENTITY_PROP_MENTAL_SDBH_EFF_TO_CS = 126, // 闪电庇护特效
	ENTITY_PROP_SHIELD_EFF_TO_CS1 = 127,	 // 神盾跨服特效
	ENTITY_PROP_SHIELD_EFF_TO_CS2 = 128,	 // 神盾跨服特效
	ENTITY_PROP_SHIELD_EFF_TO_CS3 = 129,	 // 神盾跨服特效
	ENTITY_PROP_MENTAL_SXKB_EFF_TO_CS = 130, // 嗜血狂暴（英勇）
	ENTITY_PROP_BAG_HAVE_TORCH_NUM = 131,	 // 背包内火把数量，同步给跨服使用

	ENTITY_PROP_SYNC_END = 150, // 游戏服需要实时同步给跨服的属性
	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/

	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_PROP_INIT_CROSS_BEGIN    = 151,
	ENTITY_PROP_INTERVAL_ATTACK		= 153,		//攻击最短时间间隔(毫秒)
	ENTITY_PROP_LAST_ATTACK_MS		= 154,		//还剩多少时间(毫秒)才可以发起攻击
	ENTITY_PROP_INTERVAL_MOVE		= 155,		//最大移动时间间隔(毫秒)
	ENTITY_PROP_SWZDZ_KILL_CNT		= 157,		//尸王争夺战连续杀人数
	ENTITY_PROP_INIT_CROSS_END      = 157,
	ENTITY_PROP_INIT_CROSS_MAX      = 180,
	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_PK_STATE = 182,	   // PK状态
	ENTITY_PROP_IS_SAFE = 187,	   // 是否在安全区
	ENTITY_PROP_IN_SAND = 188,	   // 是否在沙城区
	ENTITY_PROP_AREA_ID = 189,	   // 所在区域ID
	ENTITY_PROP_NAME_ID = 191,
	ENTITY_PROP_INTERVAL_TRACK = 192, // 跟踪移动时间间隔(毫秒)
	ENTITY_PROP_GENE_MITIGATE = 194,  // 魔法盾减伤%
	ENTITY_PROP_MINING_STATE = 195,  // 挖矿状态

	ENTITY_PROP_TARGET_EID = 201,	   // 目标实体ID
	ENTITY_PROP_LAST_ATTACKER = 202,   // 最后的攻击者
	ENTITY_PROP_OWNER_DATA = 203,	   // 掉落归属的ID
	ENTITY_PROP_OWNER_TYPE = 204,	   // 掉落归属的类型
	ENTITY_PROP_BELOING_STR = 205,	   // 给BOSS用的掉落归属
	ENTITY_PROP_CHANNEL_ID = 206,	   // 渠道ID
	ENTITY_PROP_DEVICE_ID = 207,	   // 设备ID
	ENTITY_PROP_PLATFORM_ID = 208,	   // 平台ID
	ENTITY_PROP_CAMP_ID = 209,		   // 阵营id
	ENTITY_PROP_CAN_VISIBLE = 210,	   // 是否可以进入隐身状态 0可以 1不可以
	ENTITY_PROP_INVISIBLE = 211,	   // 是否隐身
	ENTITY_PROP_POSION = 212,		   // 是否中毒
	ENTITY_PROP_AREA_TYPE = 216,	   // 所在区域类型
	ENTITY_PROP_AI_CENTER_X = 217,	   // 中心点x
	ENTITY_PROP_AI_CENTER_Y = 218,	   // 中心点y
	ENTITY_PROP_AI_RANGE = 219,		   // 活动范围
	ENTITY_PROP_AI_SERACH_RANGE = 220, // 搜索目标范围
	ENTITY_PROP_PROPS_LOADED = 221,	   // 属性是否已经加载
	ENTITY_PROP_OFFLINE = 222,		   // 是否已经离线
	ENTITY_PROP_TIME_TO_LIVE = 223,	   // 存活时间
	ENTITY_PROP_IS_CLEAN_ENTITY = 224, // 是否是clean entity
	ENTITY_PROP_INVINCIBLE = 225,	   // 无敌的
	ENTITY_PROP_TIME_SKILL_DISAPPEAR = 226,
	ENTITY_PROP_SKILL_CREATE_TIME = 227,
	ENTITY_PROP_GS_RAND = 228, // 攻杀随机值
	ENTITY_PROP_GS_MIN = 229,
	ENTITY_PROP_GS_MAX = 230,
	ENTITY_PROP_HP_CFLAG = 231,			  // 血量变化标识
	ENTITY_RPOP_HP_TICK = 232,			  // 血量计时次数
	ENTITY_PROP_MODE = 236,
	ENTITY_PROP_OWNER_ID = 237,
	ENTITY_PROP_MONSTER_SHILD_ID = 238, // 怪物的盾id

	ENTITY_PROP_EID_IN_CROSS_SERVER = 239, // 实体在跨服的eid
	ENTITY_PROP_IS_PEACE = 240,			   // 是不是和平状态（不会攻击1、是 2、不是）
	ENTITY_PROP_LIVE_END_TIME = 241,	   // 存活截止时间

	ENTITY_PROP_TRACK_RANGE = 242,			// 追踪范围
	ENTITY_PROP_UPDATING_FROM_GS = 243, 	// 跨服的玩家正在接受原服同步过来的数据

	ENTITY_PROP_AUTO_FETCH = 244, // 自动拾取时间

	ENTITY_PROP_MAX_PHY_ATK = 245,	  // 历史最大物攻
	ENTITY_PROP_MAX_MAGIC_ATK = 246,  // 历史最大魔攻
	ENTITY_PROP_MAX_TAOISM_ATK = 247, // 历史最大道攻

	ENTITY_PROP_MAX_PHY_ATK_TIME = 248,	   // 历史最大物攻更新时间
	ENTITY_PROP_MAX_MAGIC_ATK_TIME = 249,  // 历史最大魔攻更新时间
	ENTITY_PROP_MAX_TAOISM_ATK_TIME = 250, // 历史最大道攻更新时间

	ENTITY_PROP_MAX_ATK = 251,		// 历史最大攻击
	ENTITY_PROP_MAX_ATK_TIME = 252, // 历史最大攻击

	ENTITY_PROP_BLOOD_STATUS = 259,		   // 怪物的血量状态
	ENTITY_PROP_ENTER_SCENE_TIME = 260,	   // 玩家进入副本时间
	ENTITY_PROP_FIND_TREASURE_SCORE = 261, // 寻宝积分
	ENTITY_PROP_DRAGON_POWER_LV = 263,	   // 购买龙神之力等级
	ENTITY_PROP_DRAGON_POWER_TIME = 264,   // 购买龙神之力的有效时间
	ENTITY_PROP_MONEY_TREE_COUNT = 265,	   // 摇钱树剩余次数
	ENTITY_PROP_ZF_EQUIP_GENE_ID = 266,	   // 增幅套装装备技能ID
	ENTITY_PROP_SQ_EQUIP_GENE_ID = 267,	   // 增幅套装神器技能ID
	ENTITY_PROP_ZF_EQUIP_GENE_LV = 268,	   // 增幅套装装备等级
	ENTITY_PROP_SQ_EQUIP_GENE_LV = 269,	   // 增幅套装神器等级

	ENTITY_PROP_FIND_TREASURE_PROGRESS = 270, // 寻宝奖励进度
	ENTITY_PROP_FIND_TREASURE_REWARD = 271,	  // 寻宝奖励领取档位情况
	ENTITY_PROP_KEY_SIGN = 272,				  // 是否激活工会理财权限 ]
	ENTITY_PROP_DECLARE_GUILD_ID = 273,		  // 行会宣战行会id
	ENTITY_PROP_TU_JIAN_1_LV = 274,			  // 图鉴类型1套装等级
	ENTITY_PROP_TU_JIAN_2_LV = 275,			  // 图鉴类型2套装等级
	ENTITY_PROP_UP_STAR_LV = 276,			  // 套装等级

	ENTITY_PROP_JJKH_WEN_ZHANG_AWARD_1 = 300, // 竞技狂欢
	ENTITY_PROP_JJKH_WEN_ZHANG_AWARD_2 = 301,
	ENTITY_PROP_JJKH_WEN_ZHANG_AWARD_3 = 302,
	ENTITY_PROP_JJKH_WEN_ZHANG_AWARD_4 = 303,
	ENTITY_PROP_JJKH_WEN_ZHANG_AWARD_5 = 304,
	ENTITY_PROP_JJKH_SHEN_JIAN_SHEN_JIA_AWARD_1 = 310,
	ENTITY_PROP_JJKH_SHEN_JIAN_SHEN_JIA_AWARD_2 = 311,
	ENTITY_PROP_JJKH_SHEN_JIAN_SHEN_JIA_AWARD_3 = 312,
	ENTITY_PROP_JJKH_SHEN_JIAN_SHEN_JIA_AWARD_4 = 313,
	ENTITY_PROP_JJKH_SHEN_JIAN_SHEN_JIA_AWARD_5 = 314,
	ENTITY_PROP_JJKH_ZHAN_LI_AWARD_1 = 320,
	ENTITY_PROP_JJKH_ZHAN_LI_AWARD_2 = 321,
	ENTITY_PROP_JJKH_ZHAN_LI_AWARD_3 = 322,
	ENTITY_PROP_JJKH_ZHAN_LI_AWARD_4 = 323,
	ENTITY_PROP_JJKH_ZHAN_LI_AWARD_5 = 324,
	ENTITY_PROP_JJKH_XIAO_FEI_AWARD_1 = 330,
	ENTITY_PROP_JJKH_XIAO_FEI_AWARD_2 = 331,
	ENTITY_PROP_JJKH_XIAO_FEI_AWARD_3 = 332,
	ENTITY_PROP_JJKH_XIAO_FEI_AWARD_4 = 333,
	ENTITY_PROP_JJKH_XIAO_FEI_AWARD_5 = 334,
	ENTITY_PROP_JJKH_ZHUAN_SHENG_AWARD_1 = 340,
	ENTITY_PROP_JJKH_ZHUAN_SHENG_AWARD_2 = 341,
	ENTITY_PROP_JJKH_ZHUAN_SHENG_AWARD_3 = 342,
	ENTITY_PROP_JJKH_ZHUAN_SHENG_AWARD_4 = 343,
	ENTITY_PROP_JJKH_ZHUAN_SHENG_AWARD_5 = 344,

	ENTITY_PROP_SCRIPT_BEGIN = 1000, // 未用
	ENTITY_PROP_SCRIPT_END = 1998,	 // 未用

};

// 玩家和英雄的共同属性
enum EntityPlayerSameToHero
{
	ENTITY_PROP_PLAYER_HERO_BEGIN = 1999, // 玩家和英雄的共同属性

	/**********************************************************************************************/
	/******************************游戏服需要实时同步给跨服的属性 START****************************/
	/**********************************************************************************************/
	ENTITY_PLAYER_SYNC_BEGIN = 2000,
	ENTITY_PROP_EXP_EX = 2001,		  // 经验(高32位)
	ENTITY_PROP_EXP = 2002,			  // 经验(低32位)
	ENTITY_PROP_JOB = 2003,			  // 职业（根据三攻最大值确定）
	ENTITY_PROP_REBORN = 2004,		  // 转生等级
	ENTITY_PROP_REBORN_POINTS = 2005, // 转生修为
	ENTITY_PROP_GENDER = 2007,		  // 性别
	ENTITY_PROP_PLAYER_CLOTH = 2008,  // 衣服
	ENTITY_PROP_PLAYER_WEAPON = 2009, // 武器
	ENTITY_PROP_PLAYER_HAT = 2010,	  // 斗笠
	ENTITY_PROP_PLAYER_SHIELD = 2011, // 盾牌

	//////////////////////////////112-151可用//////////////////////////////////////////////
	ENTITY_PROP_WING_SKILL_CD_1 = 2012, // 翅膀技能冷却CD
	ENTITY_PROP_WING_SKILL_CD_2 = 2013,
	ENTITY_PROP_WING_SKILL_CD_3 = 2014,
	ENTITY_PROP_WING_SKILL_CD_4 = 2015,
	ENTITY_PROP_WING_SKILL_CD_5 = 2016,
	ENTITY_PROP_WING_SKILL_CD_6 = 2017,
	ENTITY_PROP_PLAYER_WING_LV = 2018,

	ENTITY_PROP_CHUANSHI_LEVEL_PART_1 = 2052,  // 武器 传世等级(霸业神装)
	ENTITY_PROP_CHUANSHI_LEVEL_PART_2 = 2053,  // 衣服 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_3 = 2054,  // 手镯 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_4 = 2055,  // 戒指 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_5 = 2056,  // 腰带 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_6 = 2057,  // 头盔 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_7 = 2058,  // 项链 传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_8 = 2059,  // 手镯2传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_9 = 2060,  // 戒指2传世等级
	ENTITY_PROP_CHUANSHI_LEVEL_PART_10 = 2061, // 鞋子 传世等级

	ENTITY_PROP_MAX_EX_LEVEL = 2062,	 // 曾经达到的最大等级
	ENTITY_PROP_SHIELD_LVL = 2063,		 // 护盾等级
	ENTITY_PROP_SHIELD_SKILL_LVL = 2064, // 护盾技能等级

	// 弑神装备精炼
	ENTITY_PROP_DEICIDE_JINGLIAN_LVL_BEGIN = 2066,
	ENTITY_PROP_DEICIDE_JINGLIAN_WEAPON_LVL = 2066,
	ENTITY_PROP_DEICIDE_JINGLIAN_CLOTH_LVL = 2067,
	ENTITY_PROP_DEICIDE_JINGLIAN_BRACELET_LVL = 2068,
	ENTITY_PROP_DEICIDE_JINGLIAN_GOBE_LVL = 2069,
	ENTITY_PROP_DEICIDE_JINGLIAN_SCARF_LVL = 2070,
	ENTITY_PROP_DEICIDE_JINGLIAN_VIZARD_LVL = 2071,
	ENTITY_PROP_DEICIDE_JINGLIAN_BALDRIC_LVL = 2072,
	ENTITY_PROP_DEICIDE_JINGLIAN_DRUM_LVL = 2073,
	ENTITY_PROP_DEICIDE_JINGLIAN_WEAPON_FAILED_TIMES = 2074,
	ENTITY_PROP_DEICIDE_JINGLIAN_CLOTH_FAILED_TIMES = 2075,
	ENTITY_PROP_DEICIDE_JINGLIAN_BRACELET_FAILED_TIMES = 2076,
	ENTITY_PROP_DEICIDE_JINGLIAN_GOBE_FAILED_TIMES = 2077,
	ENTITY_PROP_DEICIDE_JINGLIAN_SCARF_FAILED_TIMES = 2078,
	ENTITY_PROP_DEICIDE_JINGLIAN_VIZARD_FAILED_TIMES = 2079,
	ENTITY_PROP_DEICIDE_JINGLIAN_BALDRIC_FAILED_TIMES = 2080,
	ENTITY_PROP_DEICIDE_JINGLIAN_DRUM_FAILED_TIMES = 2081,
	ENTITY_PROP_DEICIDE_JINGLIAN_SUIT_LVL = 2082,

	ENTITY_PROP_PAPER_SUIT_ID = 2200,				 // 符文套装id
	ENTITY_PROP_SUIT_STRENGTH_LEVEL = 2201,			 // 全套装备强换等级
	ENTITY_PROP_SUIT_STONE_LEVEL = 2202,			 // 全套魂石阶数
	ENTITY_PROP_SUIT_EQUIP_LEVEL = 2203,			 // 全套装备等级
	ENTITY_PROP_SUIT_INHERIT_LEVEL = 2204,			 // 传世套装ID
	ENTITY_PROP_SUIT_EQUIP_LEVEL_TIPS_NOTIFY = 2205, // 装备套装的提示标识(按位存储对应ID)

	ENTITY_PROP_XUEMAI = 2207,	// 血脉等级
	ENTITY_PROP_SHENDUN = 2208, // 神盾等级
	ENTITY_PROP_GUANYIN = 2209, // 官印等级
	ENTITY_PROP_ZHANGU = 2210,	// 战鼓等级

	ENTITY_PROP_NTGM_START = 2211,
	ENTITY_PROP_NTGM_1 = 2211,
	ENTITY_PROP_NTGM_2 = 2212,
	ENTITY_PROP_NTGM_3 = 2213,
	ENTITY_PROP_NTGM_4 = 2214,
	ENTITY_PROP_NTGM_5 = 2215,
	ENTITY_PROP_NTGM_6 = 2216,
	ENTITY_PROP_NTGM_7 = 2217,
	ENTITY_PROP_NTGM_8 = 2218,
	ENTITY_PROP_NTGM_9 = 2219,
	ENTITY_PROP_NTGM_10 = 2220,
	ENTITY_PROP_NTGM_END = 2220,

	ENTITY_PROP_DOG_SUBTYPE = 2250, // 对象当前使用的子神兽类型

	ENTITY_PROP_INGORE_TARGET_DEFENCE = 2251, // 忽视目标防御(百分比)

	ENTITY_PLAYER_SYNC_END = 2300, // 游戏服需要实时同步给跨服的属性
	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/

	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_PLAYER_SAME_TO_HERO_INIT_CROSS_BEGIN = 2501,

	ENTITY_PLAYER_SAME_TO_HERO_INIT_CROSS_END = 2600,
	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_COMBAT_EXDATA_BEGIN = 2620, // 战斗属性开始(用于保存下线前需要保存的战斗属性)
	ENTITY_PROP_COMBAT_EXDATA_END = 2650,	// 战斗属性结束

	ENTITY_PROP_PLAYER_HERO_END = 2998, // 玩家和英雄的共同属性
};

enum EntityStrProp
{
	/**********************************************************************************************/
	/******************************游戏服需要实时同步给跨服的属性 START****************************/
	/**********************************************************************************************/
	ENTITY_STR_PROP_SYNC_BEGIN = 0,
	ENTITY_PROP_SOURCE_SERVER_NAME = 1, // 玩家所在游戏服的名称
	ENTITY_PROP_GUILD_NAME = 2,			// 工会名称
	ENTITY_PROP_ZHANDUI_NAME = 3,		// 战队名称
	ENTITY_STR_PROP_SYNC_END = 3,
	ENTITY_STR_PROP_SYNC_MAX = 100,
	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/

	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_STR_PROP_INIT_CROSS_BEGIN = 101,
	ENTITY_STR_PROP_INIT_CROSS_END      = 101,
	ENTITY_STR_PROP_INIT_CROSS_MAX      = 200,
	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 END***********************************/
	/**********************************************************************************************/

	ENTITY_STRPPROP_HHYD_HYDT = 1001,	 // 运营活动 之鸿运当头
	ENTITY_STRPPROP_HHYD_HYDTDAY = 1002, // 运营活动 之鸿运当头 存储日期

	ENTITY_STRPROP_GUILD_SKILL_DATA = 1003,	 // 公会技能等级
	ENTITY_STRPROP_GUILD_INVITE_DATA = 1004, // 公会邀请名单

	ENTITY_STRPROP_TXMJ_RANK_INFO = 1005, // 世界boss的排行数据
	ENTITY_STRPROP_YZBQ_RANK_INFO = 1006, // 夜战比奇的排行数据
	ENTITY_STRPROP_SWY_RANK_INFO = 1007,  // 神威狱的排行数据

	ENTITY_STRPROP_REWARD_ITEMS = 1008, // 开礼包活动的物品
	ENTITY_STRPROP_FIRST_OWNER = 1009,	// 开礼包活动的物品
	ENTITY_STRPROP_APPRAISER = 1010,	// 开礼包活动的物品

	ENTITY_STRPROP_SWY_GUILD_RANK_INFO = 1011,	// 神威狱的公会排行数据
	ENTITY_STRPROP_GMD_RANK_INFO = 1012,		// 决战光明顶排行数据
	ENTITY_STRPROP_SBMB_REWARDS = 1013,			// 神兵秘宝获得的所有奖励
	ENTITY_STRPROP_SBMB_ADD_REWARDS = 1014,		// 神兵秘宝获得的新增奖励
	ENTITY_STRPROP_ADVANCE_REWARDS = 1015,		// 功能开启的奖励
	ENTITY_STRPROP_TUOGUAN_ITEM = 1016,			// 离线托管获得道具收益
	ENTITY_STRPROP_FIND_TREASURE_RECORD = 1017, // 寻宝记录
	ENTITY_STRPROP_GUILD_MERGE_DATA = 1018,		// 公会合并
	ENTITY_STRPROP_ZHUZAO_RECORD = 1019,		// 铸造记录

	ENTITY_STRPROP_MAX = 2000,
};

// 玩家属性
enum EntityPlayerProp
{
	ENTITY_PROP_PLAYER_BEGIN = 2999, // 未用

	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 START***********************************/
	/**********************************************************************************************/
	ENTITY_PLAYER_PROP_SYNC_BEGIN = 3000,
	ENTITY_PROP_ACCOUNT_ID = 3001, // 账号ID

	ENTITY_PROP_MOVE_COUNT = 3008,
	ENTITY_PROP_HIDE_WEAPON = 3009,	   // 隐藏武器
	ENTITY_PROP_EXERCISE = 3010,	   // 内功 低32位
	ENTITY_PROP_EXERCISE_EX = 3011,	   // 内功 高32位
	ENTITY_PROP_EXERCISE_LV = 3012,	   // 内功等级
	ENTITY_PROP_EXE_DEFEND = 3013,	   // 内功防御（内功减免率）
	ENTITY_PROP_VIP_LEVEL = 3015,	   // VIP等级
	ENTITY_PROP_HEADTITLE_LOAD = 3017, // 称号是否已经加载
	ENTITY_PROP_HEADTITLE_GET = 3018,  // 最新获得的称号
	ENTITY_PROP_OFFSET_DAMAGE = 3019,  // 抵消伤害 瞬间回复20%生命值 并在5秒内持续回复15%生命值

	ENTITY_PROP_NO_ALLOW_CHAT = 3020,  // 是否被禁言
	ENTITY_PROP_LAST_CHAT_TIME = 3021, // 最后发言时间
	ENTITY_PROP_CHAT_EX_DATA = 3022,   // 是否是新手指导员(用于发言时加前缀)

	ENTITY_PROP_SPE_SKILL_1_CD_EX = 3023,	// 特殊技能
	ENTITY_PROP_SPE_SKILL_1_CD = 3024,		// 特殊技能
	ENTITY_PROP_SPE_SKILL_1_CAN_USE = 3025, // 特殊技能 0未学习 1学习并能使用 2 学习不能使用
	ENTITY_PROP_LEASE = 3026,				// 神兵租赁

	ENTITY_PROP_GUILD_POST = 3027,	  // 行会职务
	ENTITY_PROP_REVIVE_RATE = 3028,	  // 复活血量（万分比）
	ENTITY_PROP_GENE_LOOT_EXP = 3029, // 杀怪额外获得经验，%
	ENTITY_PROP_GENE_FIRE_EXP = 3030, // 圣火争霸额外获得经验，%
	ENTITY_PROP_GENE_PROC_EXP = 3031, // 杀人惩罚

	ENTITY_PROP_GENE_MONEY_COUNT = 3032,	 // 基础怪物掉落金币，%
	ENTITY_PROP_GOLD_MAP_ENTER_FLAG1 = 3033, // 打金地图进入flag
	ENTITY_PROP_GOLD_MAP_ENTER_FLAG2 = 3034,
	ENTITY_PROP_DS_POISON = 3035,
	ENTITY_PROP_CL_SPEED = 3036,

	ENTITY_PROP_ZS_JICHU_PERCENT = 3037,
	ENTITY_PROP_ZS_JICHU_EXDAMAGE = 3038,
	ENTITY_PROP_HIDE_ATTACK = 3039,

	ENTITY_PROP_ATTACK_OTHER_EX = 3040, // 对玩家造成伤害

	ENTITY_PROP_SRC_SVR = 3041,	  // 源服务器ID
	ENTITY_PROP_SRC_HOST = 3042,  // 源服务器地址
	ENTITY_PROP_SRC_PORT = 3043,  // 源服务器端口
	ENTITY_PROP_KFYZ_TIME = 3045, // 进入跨服远征场景时间(在原服务器上表示是否在跨服场景)

	ENTITY_PROP_GOD_LV = 3047,	  // 神级等级
	ENTITY_PROP_HEJI = 3049,	  // 合击技能
	ENTITY_PROP_XMFB_BUFF = 3050, // 0 无  1 免疫	2 中毒

	ENTITY_PROP_PROTECT_1 = 3051, // 护身扣除伤害比例（百分比）
	ENTITY_PROP_PROTECT_2 = 3052, // 护身n点mp抵扣1点伤害

	ENTITY_PROP_SPECIAL_RING = 3055, // 玩家特戒打开状态
	ENTITY_PROP_TJ_MAX_POWER = 3056, // 玩家历史穿戴特戒最高战力值
	ENTITY_PROP_SUCK_BLOOD = 3057,	 // 人物吸血buff

	ENTITY_PROP_YY_RING_TIME = 3060,	  // 阴阳特戒30分钟的cd
	ENTITY_PROP_GOD_BODY_TIME = 3061,	  // 神之体30秒的cd
	ENTITY_PROP_GOD_STRENGTH_TIME = 3062, // 神之力30秒的cd
	ENTITY_PROP_SUCK_BLOOD_TIME = 3063,	  // 吸血30秒的cd
	ENTITY_PROP_GOLD_BAR = 3064,		  // 金条数量
	ENTITY_PROP_ZHANLING_EXP = 3067,	  // 战令经验

	ENTITY_PROP_NEW_VIP_LVL = 3070,					  // 新vip等级
	ENTITY_PROP_NEW_VIP_EXP = 3071,					  // 新vip经验
	ENTITY_PROP_NEW_VIP_MAGIC_SOUL = 3072,			  // 当前魔魂值
	ENTITY_PROP_NEW_VIP_INSTANCE_PASS_INDEX = 3073,	  // 当前一星通关关卡
	ENTITY_PROP_NEW_VIP_INSTANCE_ACTIVE_INDEX = 3074, // 当前已激活关卡
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_1 = 3075,	  // 新VIP关卡完美通关标识
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_2 = 3076,	  // 新VIP关卡完美通关标识
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_3 = 3077,	  // 新VIP关卡完美通关标识
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_4 = 3078,	  // 新VIP关卡完美通关标识
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_5 = 3079,	  // 新vip关卡完美通关标识
	ENTITY_PROP_NEW_VIP_PERFECT_PASS_FLAG_6 = 3080,	  // 新vip关卡完美通关标识
	ENTITY_PROP_NEW_VIP_STAR_REWARD_FLAG_1 = 3081,	  // 新vip关卡星数奖励领取标识
	ENTITY_PROP_NEW_VIP_STAR_REWARD_FLAG_2 = 3082,	  // 新vip关卡星数奖励领取标识
	ENTITY_PROP_NEW_VIP_INSTANCE_PASS_TIME = 3083,	  // 新vip已通关关卡时间
	ENTITY_PROP_NEW_VIP_QUEST_REWARD_FLAG = 3084,	  // 新vip任务奖励领取状态标识
	ENTITY_PROP_QI_LING_ACTIVE_FLAG = 3085,			  // 器灵激活标识
	ENTITY_PROP_GUILD_QUEST = 3086,					  // 公会任务
	ENTITY_PROP_SPONSOR_GRADE = 3087,				  // 购买的赞助档次
	ENTITY_PROP_SPONSOR_REWARD = 3088,				  // 赞助领取奖励

	ENTITY_PROP_CURSE_TIME = 3090,		 // 诅咒时间
	ENTITY_PROP_DRINK_BLOOD = 3091,		 // 嗜血
	ENTITY_PROP_HARM_REDUCTION = 3092,	 // 人物减伤
	ENTITY_PROP_BOSS_SCORE = 3093,		 // boss积分
	ENTITY_PROP_BOSS_SCORE_LEVEL = 3094, // boss积分等级
	ENTITY_PROP_PRIVILEGE = 3095,		 // 特权开启状态
	ENTITY_PROP_PRIVILEGE_TIME1 = 3096,	 // 贵族特权时间
	ENTITY_PROP_PRIVILEGE_TIME2 = 3097,	 // 王者特权时间
	ENTITY_PROP_PRIVILEGE_TIME3 = 3098,	 // 至尊特权时间
	ENTITY_PROP_MC_ID = 3099,			 // 当前萌宠的ID

	ENTITY_PROP_EQUIP_RELIEVE_RING = 3100, // 是否装备复活特戒

	ENTITY_PROP_PRIVILEGE_FOREVER = 3148, // 永久开启特权

	ENTITY_PROP_CQ_EQUIP_ATK = 3155,   // 概率增伤
	ENTITY_PROP_CQ_EQUIP_BEATK = 3156, // 概率减伤

	ENTITY_PROP_USE_ARTIFACT = 3160, // 角色身上使用的神兵id

	ENTITY_PROP_GUAJI_HP = 3284,
	ENTITY_PROP_GUAJI_MP = 3285,
	ENTITY_PROP_GUAJI_SUN = 3286,

	ENTITY_PROP_DREAM_BOSS_START = 3290,
	// 中间不要插
	ENTITY_PROP_DREAM_BOSS_END = 3371,

	ENTITY_PROP_FABAO_INDEX = 3372,
	ENTITY_PROP_FABAO_1 = 3373,
	ENTITY_PROP_FABAO_2 = 3374,
	ENTITY_PROP_FABAO_3 = 3375,
	ENTITY_PROP_FABAO_4 = 3376,
	ENTITY_PROP_FABAO_5 = 3377,
	ENTITY_PROP_FABAO_MAX = 3389,
	ENTITY_PROP_FABAO_CD = 3390,

	ENTITY_PROP_SHENBING_RECIVERY_LOW = 3398,
	ENTITY_PROP_SHENBING_RECIVERY_HIGH = 3399,
	ENTITY_PROP_SHENBING_RECOVERY_BEGIN = 3400, // 神兵回收配置开始
	ENTITY_PROP_SHENBING_RECOVERY_END = 3420,	// 神兵回收配置结束

	ENTITY_PROP_POTION_CD_BEGIN = 3901, // 药水CD开始
	ENTITY_PROP_HP_POTION_CD_1 = 3901,	// 小瓶红药CD
	ENTITY_PROP_HP_POTION_CD_2 = 3902,	// 中瓶红药CD
	ENTITY_PROP_HP_POTION_CD_3 = 3903,	// 大瓶红药CD
	ENTITY_PROP_HP_POTION_CD_4 = 3904,	// 大瓶红药CD
	ENTITY_PROP_MP_POTION_CD_1 = 3911,	// 小瓶蓝药CD
	ENTITY_PROP_MP_POTION_CD_2 = 3912,	// 中瓶蓝药CD
	ENTITY_PROP_MP_POTION_CD_3 = 3913,	// 大瓶蓝药CD
	ENTITY_PROP_MP_POTION_CD_4 = 3914,	// 大瓶蓝药CD
	ENTITY_PROP_SUN_POTION_CD_1 = 3921, // 太阳水CD
	ENTITY_PROP_SUN_POTION_CD_2 = 3922, // 强效太阳水CD
	ENTITY_PROP_SUN_POTION_CD_3 = 3923, // 万年雪霜CD
	ENTITY_PROP_POTION_CD_END = 3940,	// 药水CD结束

	ENTITY_PROP_CHAT_CD_BEGIN = 3943, // 聊天频道CD占用
	ENTITY_PROP_CHAT_CD_END = 3963,	  // 聊天频道CD占用

	ENTITY_PROP_TITLE_LODED = 3964, // 角色称号加载完成

	ENTITY_PROP_HIDE_MOGUAN = 3965, // 隐藏魔冠
	ENTITY_PROP_MOSHI_LV = 3966,	// 魔饰等级

	ENTITY_PROP_SHIELD_EFFECT_ID = 3967, // 魔饰特效id

	ENTITY_PROP_SPECIAL_ACCOUNT = 3968, //(0: 普通账号， 1: 托号)
	ENTITY_PROP_HUOYUE_RECORD = 3969,	// 活跃更新版本直接送

	ENTITY_PROP_SOURCE_WORLD_ID = 3970, // 玩家源服务器id
	ENTITY_PROP_FLY_NPC = 3973,			// 飞鞋飞的目标npc
	ENTITY_PROP_FLY_REASON = 3974,		// 飞鞋的使用原因

	ENTITY_PROP_XL_SUIT = 3977,		  // 洗练套装
	ENTITY_PROP_XY_DRUMSTIMES = 3978, // 幸运大爆次数
	ENTITY_PROP_DB_LEVEL = 3979,	  // 大爆等级

	// 图腾装备
	ENTITY_PROP_DRAGON_SUIT_LVL = 3985,	  // 苍龙套装等级
	ENTITY_PROP_TORTOISE_SUIT_LVL = 3986, // 玄武套装等级

	// 战装
	ENTITY_PROP_FIGHT_SUIT_LVL = 3988, // 战装套装等级

	ENTITY_PROP_WAR_ZONE_LINE_ID = 3989,	  // 战区分线id
	ENTITY_PROP_HERO_MODEL_ID = 3990,		  // 宝宝模型的ID
	ENTITY_PROP_HERO_MODEL_HUANHUA_ID = 3991, // 宝宝幻化模型ID

	ENTITY_PROP_TIGU_PROB = 3994,		// 剔骨概率
	ENTITY_PROP_TIGU_DAMAGE = 3995,		// 剔骨伤害
	ENTITY_PROP_TIANZHU_PROB = 3996,	// 天诛概率
	ENTITY_PROP_TIANZHU_PERCENT = 3997, // 天诛伤害比列

	ENTITY_PROP_CSZT_ENEMY_PID = 4000, // 被挑战者PID

	ENEITY_PROP_BANYUE_DAMAGE_ADD = 4002,			  // 半月伤害增加（技能符文）
	ENEITY_PROP_BANYUE_ATTACK_TARGET_ADD_PROB = 4003, // 半月 攻击目标 变多 的概率（技能符文）
	ENEITY_PROP_LIEHUO_DAMAGE_ADD = 4004,			  // 烈火伤害增加（技能符文
	ENEITY_PROP_LIEHUO_CD_DELETE = 4005,			  // 烈火 cd减少
	// ENEITY_PROP_RESET_LIEHUO_CD_PROB                = 4006,  // 重置烈火
	ENEITY_PROP_LIEHUO_ADD_BUFF_PROB = 4007,	 // 烈火攻击附加灼烧buff  概率
	ENEITY_PROP_LIEHUO_BAOYAN_DAMAGE = 4008,	 // 烈火攻击炎爆伤害
	ENEITY_PROP_LIEHUO_HUICHUN_ADD_HP = 4009,	 // 烈火 回春 回血
	ENEITY_PROP_KAITIAN_CD_DELETE = 4010,		 // 开天 cd减少
	ENEITY_PROP_KAITIAN_DAMAGE_ADD = 4011,		 // 开天伤害提升
	ENEITY_PROP_KAITIAN_ADD_BUFF_PROB = 4012,	 // 开天攻击附加冰冻buff  概率
	ENEITY_PROP_KAITIAN_TIANJIE_DAMAGE = 4013,	 // 开天攻击天劫伤害
	ENEITY_PROP_RESET_KAITIAN_CD_PROB = 4014,	 // 重置开天
	ENEITY_PROP_SHIDUSHU_CD_DELETE = 4015,		 // 施毒术 cd减少
	ENEITY_PROP_SHIDUSHU_R_HP_DELETE = 4016,	 // 施毒术 减少目标 生命恢复 百分比
	ENEITY_PROP_SHIDUSHU_ATTACK_DELETE = 4017,	 // 施毒术 减少目标 攻击力
	ENEITY_PROP_SHIDUSHU_ASPD_DELETE = 4018,	 // 施毒术 减少目标 攻速
	ENEITY_PROP_SHIDUSHU_MOVE_SPD_DELETE = 4019, // 施毒术 减少目标 移速
	ENEITY_PROP_SHIDUSHU_ADD_TARGET_PORB = 4020, // 施毒术 增加 目标 概率
	ENEITY_PROP_YEMAN_CD_DELETE = 4021,			 // 野蛮 cd减少
	ENEITY_PROP_HUIXIN_PROB_ADD = 4022,			 // 施毒术 符文 会心概率 提高
	ENEITY_PROP_ZHIYUESHU_CD_DELETE = 4023,		 // 治愈术 cd减少
	ENTITY_PROP_GODWEAPON_CUTTING_GIFT = 4025,	 // 神器  切割 礼包
	ENTITY_PROP_GODWEAPON_CHOPPING_GIFT = 4026,	 // 神器  斩杀 礼包
	ENTITY_PROP_GODWEAPON_TIGU_GIFT = 4027,		 // 神器  剔骨 礼包
	ENTITY_PROP_GODWEAPON_TIANZHU_GIFT = 4028,	 // 神器  天诛 礼包
	ENTITY_PROP_MC_RECORD = 4029,				 // 萌宠模型获取记录
	ENTITY_PROP_HERO_HHMODEL_RECORD = 4030,		 // 宝宝幻化模型get记录
	ENTITY_PROP_SKILL_RUNE_POWER = 4031,		 // 技能符文战力
	ENTITY_PROP_GODWEAPON_EFFECT_POWER = 4032,	 // 神器特效相关战力
	ENTITY_PROP_SKILL_POWER = 4033,				 // 技能模块战力        temp 下 表示cd
	ENTITY_PROP_ROBOT_NEXT_CAST_SKILL = 4034,	 // 机器人 下一个使用的技能
	ENITTY_PROP_ROBOT_NEXT_CAST_DISTANCE = 4035,
	ENITTY_PROP_SXKB_ATTR_ADDED = 4036,			// 嗜血属性是否已经增加
	ENITTY_PROP_SXKB_STATE = 4037,				// 嗜血狂暴状态[0:未购买  2:绑定灵符购买  1:非绑灵符购买]
	ENITTY_PROP_XSKB_END_TIME = 4038,			// 限时狂暴结束时间
	ENTITY_PROP_CUTTING_DAMAGE = 4039,			// 切割伤害
	ENTITY_PROP_CHOPPING_PROB = 4040,			// 生命低于多少%（有几率斩杀）
	ENEITY_PROP_LIEHUO_HUICHUN_ADD_HP_K = 4041, // 烈火 回春符文 的系数
	ENEITY_PROP_KAITIAN_LIAOSHANG_PROB = 4042,	// 开天 疗伤 概率
	ENEITY_PROP_KAITIAN_LIAOSHANG_K = 4043,		// 开天 疗伤 系数

	ENTITY_PROP_THERION_TT_LEVEL = 4050, // 饕餮 重级
	ENTITY_PROP_THERION_QQ_LEVEL = 4051, // 穷奇 重级
	ENTITY_PROP_THERION_TW_LEVEL = 4052, // 梼杌 重级
	ENTITY_PROP_THERION_HD_LEVEL = 4053, // 混沌 重级

	ENTITY_PROP_THERION_TT_MER_LEVEL = 4054,  // 饕餮 经脉等级
	ENTITY_PROP_THERION_QQ_MER_LEVEL = 4055,  // 穷奇 经脉等级
	ENTITY_PROP_THERION_TW_MER_LEVEL = 4056,  // 梼杌 经脉等级
	ENTITY_PROP_THERION_HD_MER_LEVEL = 4057,  // 混沌 经脉等级
	ENTITY_PROP_PLAYER_FEI_SHENG = 4058,	  // 玩家飞升（）
	ENTITY_PROP_HERO_PET_SKILL_RECORD = 4059, // 萌宠和宝宝的技能学习状态

	ENEITY_PROP_CISHA_DAMAGE_ADD = 4060, // 刺杀伤害增加

	// 技能位
	ENTITY_PROP_SKILL_POSITION_MAIN = 4061,
	ENTITY_PROP_SKILL_POSITION_1 = 4062,
	ENTITY_PROP_SKILL_POSITION_2 = 4063,
	ENTITY_PROP_SKILL_POSITION_3 = 4064,
	ENTITY_PROP_SKILL_POSITION_4 = 4065,
	ENTITY_PROP_SKILL_POSITION_5 = 4066,
	ENTITY_PROP_SKILL_POSITION_6 = 4067,
	ENTITY_PROP_SKILL_POSITION_7 = 4068,
	ENTITY_PROP_SKILL_POSITION_8 = 4069,
	ENTITY_PROP_SKILL_POSITION_9 = 4070,
	ENTITY_PROP_SUPER_SKILL_POSITION_1 = 4075,

	ENTITY_PROP_GUAJI_PATROL = 4078,

	ENTITY_PROP_STONE_RANDOM_CD_COUNTDOWN = 4091, // 随机石cd
	ENTITY_PROP_STONE_GOHOME_CD_COUNTDOWN = 4092, // 回城石cd
	ENTITY_PROP_STONE_RANDOM_CD = 4093,			  // 随机石CD
	ENTITY_PROP_STONE_GOHOME_CD = 4094,			  // 回城石CD

	ENTITY_PROP_EFFECT_DATA					= 4110,		//特效

	ENTITY_PROP_ATTACK_MODE					= 4111,		//攻击模式
	ENTITY_PROP_ATTACK_MODE_BACKUP			= 4112,		//上次的攻击模式

	ENTITY_PROP_SUMMON_CNT = 4131, // 召唤是够可以同时存活

	ENTITY_PROP_GUARD_LEVEL = 4200,					// 小极品 守护等级
	ENTITY_PROP_GUARD_PROGRESS = 4201,				// 小极品 守护升级进度
	ENTITY_PROP_SOUL_LEVEL = 4202,					// 小极品 魂珠等级
	ENTITY_PROP_WAR_FLAG_LEVEL = 4203,				// 小极品 战旗等级
	ENTITY_PROP_WAR_FLAG_PROGRESS = 4204,			// 小极品 战旗升级进度
	ENTITY_PROP_WAR_FLAG_RANK_SUPPRESS_HURT = 4205, // 小极品 战旗排行额外增伤
	ENTITY_PROP_GUARD_SHOW_ID = 4206,				// 小极品 守护特效显示id

	ENTITY_PROP_HORCRUXES_LEVEL_1 = 4207, // 小极品 魂器一阶激活状态
	ENTITY_PROP_HORCRUXES_LEVEL_2 = 4208, // 小极品 魂器二阶激活状态
	ENTITY_PROP_HORCRUXES_LEVEL_3 = 4209, // 小极品 魂器三阶激活状态
	ENTITY_PROP_HORCRUXES_LEVEL_4 = 4210, // 小极品 魂器四阶激活状态
	ENTITY_PROP_HORCRUXES_LEVEL_5 = 4211, // 小极品 魂器五阶激活状态
	ENTITY_PROP_HORCRUXES_LEVEL_6 = 4212, // 小极品 魂器六阶激活状态

	ENTITY_PROP_ARTIFACT_SUIT_GENE = 4213,	   // 小极品 神器6件套套装基因
	ENTITY_PROP_HUNLING_SIX_GENE = 4214,	   // 小极品 魂灵装备6件套基因
	ENTITY_PROP_HUNLING_SIX_TIME = 4215,	   // 小极品 魂灵装备6件套基因触发时间
	ENTITY_PROP_HUNLING_TRUE_BODY_GENE = 4216, // 小极品 蓝银真身基因
	ENTITY_PROP_HOLY_LIGHT_CRIT_TIME = 4217,   // 小极品 圣光伤害时间

	ENTITY_PROP_HERALDRY_QINGLONG_LEVEL = 4218, // 小极品 青龙纹章等级
	ENTITY_PROP_HERALDRY_BAIHU_LEVEL = 4219,	// 小极品 白虎纹章等级
	ENTITY_PROP_HERALDRY_ZHUQUE_LEVEL = 4220,	// 小极品 朱雀纹章等级
	ENTITY_PROP_HERALDRY_XUANWU_LEVEL = 4221,	// 小极品 玄武纹章等级
	ENTITY_PROP_HORCRUXES_GUARD_TIME = 4222,	// 小极品 守护之魂下次触发时间
	ENTITY_PROP_REFINING_LEVEL = 4223,			// 小极品 转生炼体等级
	ENTITY_PROP_DOCTOR_NEXT_TIME = 4224,		// 小极品 下一次一键回血可以最早时间
	ENTITY_PROP_GUARD_FB_CAN_REWARD = 4225,		// 小极品 守护副本奖励是否可领取
	ENTITY_PROP_HUISHOU_INGOT_NO_BIND = 4226,	// 小极品 回收非绑定

	ENTITY_PROP_HUNLING_CUTTING_PRO = 4227,	  // 小极品 魂灵12件套基因触发几率
	ENTITY_PROP_HUNLING_CUTTING_VALUE = 4228, // 小极品 魂灵12件套基因斩杀比例
	ENTITY_PROP_SOUL_GENE_ID = 4229,		  // 小极品 魂珠灵魂吞噬基因编号

	ENTITY_PROP_DRESS_START = 4230,
	ENTITY_PROP_DRESS_WUQI = 4230,		// 装扮武器
	ENTITY_PROP_DRESS_YIFU = 4231,		// 装扮衣服
	ENTITY_PROP_DRESS_CHENGHAO = 4232,	// 装扮称号
	ENTITY_PROP_DRESS_HUNHUAN = 4233,	// 装扮魂环
	ENTITY_PROP_DRESS_JINGLING = 4234,	// 装扮精灵
	ENTITY_PROP_DRESS_CHENGHAO2 = 4235, // 装扮精灵
	ENTITY_PROP_DRESS_CHENGHAO3 = 4236, // 装扮精灵
	ENTITY_PROP_DRESS_CHENGHAO4 = 4237, // 装扮精灵
	ENTITY_PROP_DRESS_CHENGHAO5 = 4238, // 装扮精灵
	ENTITY_PROP_DRESS_END = 4238,
	ENTITY_PROP_DRESS_MAX = 4239,

	ENTITY_PROP_WAR_FLAG_LEVEL_TIME = 4240,	  // 小极品 战旗升级时间
	ENTITY_PROP_LEVEL_UP_TIME = 4241,		  // 小极品 角色升级时间
	ENTITY_PROP_MURDEROUS_GAS_VALUE = 4242,	  // 小极品 杀气值
	ENTITY_PROP_IS_GREY_NAME = 4243,		  // 小极品 是否灰名
	ENTITY_PROP_MEXT_WASHING_INTERVAL = 4244, // 小极品 下一次在线降杀气值时间
	ENTITY_PROP_PK_ADD_HURT = 4245,			  // 小极品 PK值导致PK伤害加深
	ENTITY_PROP_PK_ADD_DROP = 4246,			  // 小极品 PK值导致爆装几率增加

	ENTITY_PROP_WEN_ZHANG_LEVEL_TIME = 4247,		  // 纹章等级变化时间
	ENTITY_PROP_SHEN_JIAN_SHEN_JIA_LEVEL_TIME = 4248, // 神剑神甲等级变化时间
	ENTITY_PROP_USE_NOT_BIND_LINGFU_TIME = 4249,	  // 消耗不绑定灵符时间
	ENTITY_PROP_USE_NOT_BIND_LINGFU_NUM = 4250,		  // 使用不绑定灵符总量

	ENTITY_PROP_MOQI_SUIT_ID = 4251,	// 魔器套装ID
	ENTITY_PROP_HUNLING_SKILL_3 = 4252, // 神级魂灵3级-神圣伤害
	ENTITY_PROP_HUNLING_SKILL_4 = 4253, // 神级魂灵4级-炽热防御

	ENTITY_PROP_HORCRUXES_STAR_1_1 = 4261, // 小极品 魂器一阶第1位星级
	ENTITY_PROP_HORCRUXES_STAR_1_2 = 4262, // 小极品 魂器一阶第2位星级
	ENTITY_PROP_HORCRUXES_STAR_1_3 = 4263, // 小极品 魂器一阶第3位星级
	ENTITY_PROP_HORCRUXES_STAR_1_4 = 4264, // 小极品 魂器一阶第4位星级

	ENTITY_PROP_HORCRUXES_STAR_2_1 = 4265, // 小极品 魂器2阶第1位星级
	ENTITY_PROP_HORCRUXES_STAR_2_2 = 4266, // 小极品 魂器2阶第2位星级
	ENTITY_PROP_HORCRUXES_STAR_2_3 = 4267, // 小极品 魂器2阶第3位星级
	ENTITY_PROP_HORCRUXES_STAR_2_4 = 4268, // 小极品 魂器2阶第4位星级

	ENTITY_PROP_HORCRUXES_STAR_3_1 = 4269, // 小极品 魂器3阶第1位星级
	ENTITY_PROP_HORCRUXES_STAR_3_2 = 4270, // 小极品 魂器3阶第2位星级
	ENTITY_PROP_HORCRUXES_STAR_3_3 = 4271, // 小极品 魂器3阶第3位星级
	ENTITY_PROP_HORCRUXES_STAR_3_4 = 4272, // 小极品 魂器3阶第4位星级

	ENTITY_PROP_HORCRUXES_STAR_4_1 = 4273, // 小极品 魂器4阶第1位星级
	ENTITY_PROP_HORCRUXES_STAR_4_2 = 4274, // 小极品 魂器4阶第2位星级
	ENTITY_PROP_HORCRUXES_STAR_4_3 = 4275, // 小极品 魂器4阶第3位星级
	ENTITY_PROP_HORCRUXES_STAR_4_4 = 4276, // 小极品 魂器4阶第4位星级
	ENTITY_PROP_HORCRUXES_STAR_4_5 = 4277, // 小极品 魂器4阶第5位星级
	ENTITY_PROP_HORCRUXES_STAR_4_6 = 4278, // 小极品 魂器4阶第6位星级

	ENTITY_PROP_HORCRUXES_STAR_5_1 = 4279, // 小极品 魂器5阶第1位星级
	ENTITY_PROP_HORCRUXES_STAR_5_2 = 4280, // 小极品 魂器5阶第2位星级
	ENTITY_PROP_HORCRUXES_STAR_5_3 = 4281, // 小极品 魂器5阶第3位星级
	ENTITY_PROP_HORCRUXES_STAR_5_4 = 4282, // 小极品 魂器5阶第4位星级
	ENTITY_PROP_HORCRUXES_STAR_5_5 = 4283, // 小极品 魂器5阶第5位星级
	ENTITY_PROP_HORCRUXES_STAR_5_6 = 4284, // 小极品 魂器5阶第6位星级
	ENTITY_PROP_ZENGFU_SHOW_ID = 4285,	   // 增幅特效显示
	ENTITY_PROP_MOQI_EFF_SHOW_ID = 4286,   // 魔器特效显示
	ENTITY_PROP_MOQI_EFF_ROLE_ID = 4287,   // 魔器特效显示

	ENTITY_PROP_ZK_START = 4400,
	ENTITY_PROP_ZK_TIME1 = 4401, // 周卡1结束时间
	ENTITY_PROP_ZK_TIME2 = 4402, // 周卡2结束时间
	ENTITY_PROP_ZK_TIME3 = 4403, // 周卡3结束时间
	ENTITY_PROP_ZK_TIME4 = 4404, // 周卡4结束时间
	ENTITY_PROP_ZK_TIME5 = 4405, // 周卡5结束时间
	ENTITY_PROP_ZK_TIME6 = 4406, // 周卡6结束时间
	ENTITY_PROP_ZK_TIME7 = 4407, // 周卡7结束时间
	ENTITY_PROP_ZK_TIME8 = 4408, // 周卡8结束时间
	ENTITY_PROP_ZK_END = 4409,

	ENTITY_PROP_BUY_MONSTER_KILL = 4410,			  // 是否购买怪物通缉
	ENTITY_PROP_DIAMONDS_VALUE = 4411,				  // 聚宝盆钻石数量
	ENTITY_PROP_CORNUCOPIA_LAST_TIME = 4412,		  // 上次领取聚宝盆时间
	ENTITY_PROP_CORNUCOPIA_DIAMONDS_LAST_TIME = 4413, // 上次领取聚宝盆钻石时间0
	ENTITY_PROP_TOTAL_DIAMONDS_VALUE = 4414,		  // 总共领取钻石数量
	ENTITY_PROP_DIAMONDS_BALANCE_LAST = 4415,		  // 上次在线累积的时间
	ENTITY_PROP_DIAMONDS_INCREASE_VALUE = 4416,		  // 聚宝盆奖励提升比例
	ENTITY_PROP_REPUTATION_VALUE = 4417,			  // 声望

	ENTITY_PROP_DABAO_TIMES = 4420,	  // VIP打宝次数
	ENTITY_PROP_VIP_JBP_ADD = 4421,	  // VIP聚寶盆加成
	ENTITY_PROP_VIP_INGOT_ADD = 4422, // VIP装备回收提升加成
	ENTITY_PROP_ZF_INGOT_ADD = 4423,  // 增幅装备回收加成
	// 技能

	ENTITY_PROP_SKILL_RED_POINT_MODE = 4480, // 技能推荐方案

	ENTITY_PROP_SKILL_FETTER_TYPE = 4481,	  // 技能羁绊类型
	ENTITY_PROP_SKILL_FETTER_QUALITY = 4482,  // 技能羁绊品质
	ENTITY_PROP_SKILL_FETTER_LEVEL = 4483,	  // 技能羁绊等级
	ENTITY_PROP_DIANFENGSHENGLI_POWER = 4484, // 巅峰神力

	ENTITY_PROP_ARTIFACT_XR_CD = 4485,	   // 神兵虚弱CD
	ENTITY_PROP_ARTIFACT_LAST_DAM = 4486,  // 上一次造成的伤害
	ENTITY_PROP_ARTIFACT_YS_CD = 4487,	   // 神兵地爆天星CD
	ENTITY_PROP_YUELING_SUB_RATE = 4488,   // 月灵降低继承主体属性百分比（-75相当于只继承25%）
	ENTITY_PROP_YUELING_ADD_VALUE = 4489,  // 月灵增加额外的伤害
	ENTITY_PROP_ZHAOHUAN_SUB_RATE = 4490,  // 神兽降低继承主体属性百分比（-75相当于只继承25%）
	ENTITY_PROP_ZHAOHUAN_ADD_VALUE = 4492, // 神兽增加额外的伤害

	ENTITY_PROP_YUEKA_TIME = 4491,			  // 特惠月卡结束时间
	ENTITY_PROP_ZHOUKA_TIME = 4493,			  // 特惠周卡结束时间
	ENTITY_PROP_WEEK_CARD_MARKET_TIME = 4494, // 周卡推销结束时间

	ENTITY_PLAYER_PROP_SYNC_END				= 4500,			//游戏服需要实时同步给跨服的属性
	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/

	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_PLAYER_PROP_INIT_CROSS_BEGIN    = 4501,
	ENTITY_PROP_REVIVE_RING_TIME	= 4505,		//复活特戒30分钟的cd
	ENTITY_PROP_PALSY_RING_TIME     = 4506,		//麻痹特戒60秒的cd
	ENTITY_PROP_PLAYERDOG_LIVE					= 4508,	// 神兽存活
	ENTITY_PROP_YERML_LIVE						= 4509,	// 月灵存活
	ENTITY_PROP_TIGER_LIVE						= 4510,	// 老虎存活
	ENTITY_PROP_CLONE_LIVE						= 4511,	// 分身存活
	ENTITY_PROP_KULOU_LIVE						= 4514, // 骷髅存活
	ENTITY_PLAYER_PROP_INIT_CROSS_END      = 4514,
	ENTITY_PLAYER_PROP_INIT_CROSS_MAX      = 4600,
	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_CAN_USE_SKILL = 4800,	   // 可使用技能
	ENTITY_PROP_CAN_USE_SKILL_TIME = 4801, // 使用技能时间
	ENTITY_PROP_EVENT_IN = 4803,
	ENTITY_PROP_ATTACK_GUILD_BOSS = 4804,	 // 最近一次攻击公会boss的ID
	ENTITY_PROP_GUILD_BOSS_OWNER_GID = 4805, // 最近一次攻击公会boss时公会ID

	/**********************************************************************************************/
	/***********************法宝ID 						   BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_PROP_FABAO_EQUIP = 4900, // 当前穿戴生效的法宝ID
	ENTITY_PROP_FABAO_BEGIN = 4901,
	ENTITY_PROP_FABAO_END = 5000,
	/**********************************************************************************************/
	/***********************法宝ID 							 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_LOAD_STATE = 5001,				// 加载状态
	ENTITY_PROP_HERO_ID = 5002,					// 玩家拥有的英雄的ID
	ENTITY_PROP_SAMSARA = 5003,					// 轮回等级(十位数为道, 个位数为层)
	ENTITY_PROP_SAMSARA_POINTS = 5004,			// 轮回修为
	ENTITY_PROP_PK_VALUE = 5005,				// PK值
	ENTITY_PROP_INSTANCE_IID = 5006,			// 副本实例ID
	ENTITY_PROP_SAFE_ID = 5007,					// 玩家所在安全区ID
	ENTITY_PROP_TARGET_OTHER = 5008,			// 其它目标(战神，狗使用)
	ENTITY_PROP_DUMMY_PLAYER = 5009,			// 傀儡玩家
	ENTITY_PROP_DUMMY_PLAYER_EID = 5010,		// 傀儡玩家实体ID
	ENTITY_PROP_CAN_LEAVE_OFFLINE = 5011,		// 是否可以离开离线状态
	ENTITY_PROP_CMQUEST_OPEN = 5012,			// 除魔任务是否开启   0 未开启， 1 已经开启
	ENTITY_PROP_DBQUEST_OPEN = 5013,			// 打宝人物是否开启   0 未开启， 1 已开启
	ENTITY_PROP_WWQUEST_OPEN = 5014,			// 威望任务是否开启   0 未开启， 1 已开启
	ENTITY_PROP_TALENT_MAGIC = 5015,			// 天赋魔力值
	ENTITY_PROP_LINGFU = 5017,					// 灵符
	ENTITY_PROP_INGOT = 5018,					// 元宝
	ENTITY_PROP_BOUND_INGOT = 5019,				// 绑定元宝
	ENTITY_PROP_BOUND_LINGFU = 5020,			// 绑定灵符
	ENTITY_PROP_STONE_EX = 5021,				// 魂石附加加成等级
	ENTITY_PROP_ENHANCE_EX = 5022,				// 强化附加加成等级
	ENTITY_PROP_SUIT_EX = 5023,					// 套装附加加成等级
	ENTITY_PROP_VITALITY = 5024,				// 活跃度
	ENTITY_PROP_VITALITY_LEVEL = 5025,			// 活跃度等级
	ENTITY_PROP_SOUL_EX = 5026,					// 注灵附加加成等级
	ENTITY_PROP_GIFT_CODE_TIME = 5029,			// 上次领取激活码时间
	ENTITY_PROP_IN_GAME = 5030,					// 是否已经在游戏中
	ENTITY_PROP_IN_TRADE = 5031,				// 交易状态
	ENTITY_PROP_OL_LAST_LEAVE_TIME = 5032,		// 离线-上一次储存离线时间
	ENTITY_PROP_OFFLINE_IS_REWARD = 5033,		// 是否有离线奖励
	ENTITY_PROP_EVALUATE_GRADE = 5035,			// 鉴定积分??
	ENTITY_PROP_OFFLINE_EXP_LEVEL = 5036,		// 离线经验等级
	ENTITY_PROP_OFFLINE_SID = 5037,				// 离线场景
	ENTITY_PROP_OFFLINE_COORDINATE = 5038,		// 离线坐标
	ENTITY_PROP_OFFLINE_EXP_FACTOR = 5039,		// 离线基因加成
	ENTITY_PROP_OFFLINE_EXP_FACTOR_TIME = 5040, // 离线基因加成时间
	ENTITY_PROP_OFFLINE_EXP_FACTORV = 5041,		// vip基因加成
	ENTITY_PROP_OFFLINE_EXP_FACTOR_TIMEV = 5042,
	ENTITY_PROP_OFFLINE_SPEED = 5043,
	ENTITY_PROP_OFFLINE_DOU_SPEED = 5044,
	ENTITY_PROP_APP_STORE_COMMENT_REWARDED = 5045,	   // 是否领取5星好评礼包
	ENTITY_PROP_RECHARGE_RETURN_FLAG = 5046,		   // 充值返还标志
	ENTITY_PROP_RECHARGE_RETURN_ORIGINAL_INGOT = 5047, // 充值返还原始元宝
	ENTITY_PROP_RECHARGE_RETURN_INGOT = 5048,		   // 充值返还元宝(含原始元宝)
	ENTITY_PROP_QUEST_REMAIN_COUNT_MONEY = 5049,
	ENTITY_PROP_QUEST_REMAIN_COUNT_HONOR = 5050,
	ENTITY_PROP_QUEST_REMAIN_COUNT_EXP = 5051,
	ENTITY_PROP_QUEST_DAILY_ID = 5052,
	ENTITY_PROP_QUEST_DAILY_SEED = 5053,
	ENTITY_PROP_QUEST_DAILY_STATE = 5054,
	ENTITY_PROP_GXCH_LVL = 5055,   // 功勋称号
	ENTITY_PROP_GXCH_VALUE = 5056, // 功勋值
	ENTITY_PROP_GXMO_VALUE = 5057, // 魔魂值(战魂值)
	ENTITY_PROP_BUY_DISCOUNT_PACKAGE = 5058,
	ENTITY_PROP_SOUL_VALUE = 5059,					  // 灵力值
	ENTITY_PROP_OFFLINE_SPEED_MAX = 5060,			  // 挂机效率取地图最大
	ENTITY_PROP_CZLC_BUYED = 5061,					  // 是否已购买超值理财
	ENTITY_PROP_CZLC_REWARDED = 5062,				  // 是否已领取超值理财奖励
	ENTITY_PROP_OFFLINE_FLAG = 5068,				  // 在线挂机开关
	ENTITY_PROP_GUIDE_BUY_OPEN = 5069,				  // 商城购买引导  0.未开启  1.可以开启  2.开启过
	ENTITY_PROP_OFFLINE_WORLD_EXP_FACTOR = 5070,	  // 离线世界等级基因加成
	ENTITY_PROP_OFFLINE_WORLD_EXP_FACTOR_TIME = 5071, // 离线世界等级基因加成时间
	ENTITY_PROP_CROSS_FROCE = 5072,					  // 跨服战力
	ENTITY_PROP_MARS_SUMMON_TIMES = 5073,			  // 可用召唤战神次数
	ENTITY_PROP_MARS_SUMMON_LEVEL = 5074,			  // 当前可召唤战神等级
	ENTITY_PROP_MARS_SUMMON_FREE = 5075,			  // 免费召唤
	ENTITY_PROP_MARS_USING = 5076,					  // 当前战神
	ENTITY_PROP_MARS_BACK_INGOT = 5077,				  // 是否可以领取返还元宝

	ENTITY_PROP_LOGIN_TIME = 5078,		// 本次登录
	ENTITY_PROP_LAST_LOGIN_TIME = 5079, // 上次登录时间
	ENTITY_PROP_LAST_LEAVE_TIME = 5080, // 上次离线时间
	ENTITY_PROP_LOGIN_DAYS = 5081,		// 累计登录天数
	ENTITY_PROP_DAY_LOGIN_TIME = 5082,	// 当天登录时间

	ENTITY_PROP_PET_ON = 5083,			 // 出战宠物ID
	ENTITY_PROP_PET_PICK_STATE = 5084,	 // 宠物拾取状态
	ENTITY_PROP_PET_MARKET = 5085,		 // 当前摆摊宠物
	ENTITY_PROP_PET_MAX = 5086,			 // 最大可拥有的宠物数量
	ENTITY_PROP_PET_COUNT = 5087,		 // 宠物数量(不包含狗)
	ENTITY_PROP_PET_PICKEX_STATE = 5088, // 宠物拾取状态
	ENTITY_PROP_PET_REBORN_POINT = 5089, // 宠物转生点数

	ENTITY_PROP_MARKET_STATE = 5090, // 是否摆摊中
	ENTITY_PROP_MARKET_MAX_COUNT = 5091,
	ENTITY_PROP_MARKET_PET_SELECT = 5092,		 // 摆摊宠物
	ENTITY_PROP_MARKET_BAG_SLOT = 5093,			 // 摊位容量
	ENTITY_PROP_MARKET_PLAYER_BEGIN_TIME = 5094, // 摆摊开始时间

	ENTITY_PROP_SL_RED = 5095,	  // 神炉 - 血玉碎片
	ENTITY_PROP_SL_SHIELD = 5096, // 神炉 - 护盾碎片
	ENTITY_PROP_SL_GEM = 5097,	  // 神炉 - 宝石碎片
	ENTITY_PROP_SL_SOUL = 5098,	  // 神炉 - 魂珠碎片

	ENTITY_PROP_HONOR = 5099, // 荣誉

	ENTITY_PROP_GHOST_STONE = 5101, // 魂石精华

	ENTITY_PROP_CUR_SKILL_ID = 5102, // 仅用于挖矿
	ENTITY_PROP_CUR_TARGET_X = 5103, // 仅用于挖矿
	ENTITY_PROP_CUR_TARGET_Y = 5104, // 仅用于挖矿

	ENTITY_PROP_DOG_MAX = 5105,	  // 最大狗数量
	ENTITY_PROP_DOG_COUNT = 5106, // 当前狗数量
	ENTITY_PROP_DOG_MODE = 5107,  // 狗的模式
	ENTITY_PROP_DOG_LV = 5108,	  // 狗的等级

	ENTITY_PROP_TEAM_CALL_CD = 5109, // 召唤队友冷却时间  NPC 冷却时间
	ENTITY_PROP_REFUSE_TRADE = 5111, // 拒绝交易请求

	ENTITY_PROP_XL_COUNT = 5112, // 洗练总次数
	ENTITY_PROP_XL_CHART = 5114, // 洗练排行数据

	ENTITY_PROP_GTCL_LEVEL = 5115, // 宫廷长廊等级

	ENTITY_PROP_USE_MEDICINE_CD = 5116, // 使用药水冷却时间

	ENTITY_PROP_THLB_LS = 5117,	 // 灵石特惠礼包（仅此一次）
	ENTITY_PROP_THLB_BS = 5118,	 // 宝石特惠礼包（仅此一次）
	ENTITY_PROP_THLB_HZ = 5119,	 // 魂珠特惠礼包（仅此一次）
	ENTITY_PROP_THLB_CB = 5120,	 // 翅膀特惠礼包（仅此一次）
	ENTITY_PROP_THLB_JF = 5121,	 // 积分特惠礼包（仅此一次）
	ENTITY_PROP_THLB_XJZ = 5122, // 金砖特惠小礼包（仅此一次）
	ENTITY_PROP_THLB_DJZ = 5123, // 金砖特惠大礼包（仅此一次）

	ENTITY_PROP_DEAD_REL_LAST_T = 5124,	  // 上一次时间
	ENTITY_PROP_DEAD_RELIVE_CNT = 5125,	  // 死亡复活次数
	ENTITY_PROP_DEAD_RELIVE_CD = 5126,	  // 死亡复活CD
	ENTITY_PROP_DEAD_RELIVE_MONEY = 5127, // 死亡花费
	ENTITY_PROP_DEAD_RELIVE_RED = 5128,

	ENTITY_PROP_SPQUEST_1 = 5129, // 装备特殊任务1
	ENTITY_PROP_SPQUEST_2 = 5130, // 装备特殊任务1
	ENTITY_PROP_SPQUEST_3 = 5131, // 装备特殊任务1
	ENTITY_PROP_SPQUEST_4 = 5132, // 装备特殊任务1
	ENTITY_PROP_SPQUEST_5 = 5133, // 装备特殊任务1
	ENTITY_PROP_SPQUEST_6 = 5134, // 装备特殊任务1

	ENTITY_PROP_MAX_PET_LEVEL = 5135, // 玩家已有宠物的最高等级
	ENTITY_PROP_STONE_POINT = 5136,	  // 宝石评分
	ENTITY_PROP_INGOT_USED = 5137,	  // 累计花费元宝数量

	ENTITY_PROP_LEVEL_REWARD_PLANE = 5138, // 等级奖励的索引
	// ENTITY_PROP_UPGRADE_GIFT_PLANE	= 5142,	//冲级礼包的索引
	ENTITY_PROP_ZHANSHEN_PATK_MAX = 5143, // 战神攻击力
	ENTITY_PROP_CUR_CAPTAIN_LEVEL = 5144, // 当前的官印级别

	ENTITY_PROP_SUIT_COMBAT_0 = 5145, // 职业套装加成的ID
	ENTITY_PROP_SUIT_COMBAT_1 = 5146,
	ENTITY_PROP_SUIT_COMBAT_2 = 5147,
	ENTITY_PROP_SUIT_COMBAT_3 = 5148,
	ENTITY_PROP_SUIT_COMBAT_4 = 5149,
	ENTITY_PROP_SUIT_COMBAT_5 = 5150, // 首饰套装加成的ID

	ENTITY_PROP_PET_AUTO_RELIVE = 5151, // 宠物自动复活

	ENTITY_PROP_GUILD_CONTRIBUTION = 5152,		 // 行会贡献
	ENTITY_PROP_GUILD_CONTRIBUTION_TODAY = 5153, // 当日贡献
	ENTITY_PROP_CHECK_DONATE = 5154,			 // 记录是否捐赠过（暂时用于金币）

	ENTITY_PROP_GUILD_CONTRIBUTION_RANK_DAY = 5155, // 行会贡献排名天
	ENTITY_PROP_GUILD_CONTRIBUTION_RANK = 5156,		// 行会贡献排名

	ENTITY_PROP_LEAVE_GUILD_TIME = 5157,		  // 退出行会时间
	ENTITY_PROP_GUILD_WORSHIP_DAY = 5158,		  // 已膜拜信息日期
	ENTITY_PROP_GUILD_WORSHIP_COUNT = 5159,		  // 已膜拜行会玩家数量
	ENTITY_PROP_GUILD_WORSHIP1 = 5160,			  // 已膜拜行会玩家1
	ENTITY_PROP_GUILD_WORSHIP2 = 5161,			  // 已膜拜行会玩家2
	ENTITY_PROP_GUILD_WORSHIP3 = 5162,			  // 已膜拜行会玩家3
	ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT = 5163,  // 被行会玩家膜拜次数
	ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD = 5164, // 被行会玩家膜拜奖励

	ENTITY_PROP_GUILD_ADD_ATTR_LEVEL = 5165, // 附加行会属性等级

	ENTITY_PROP_MONSTER_POINT_INDEX = 5166, // 押镖点索引

	ENTITY_PROP_CAISHENCHUANGGUAN_STATE = 5167, // 财神闯关状态

	ENTITY_PROP_MEINVHUSONG_MID = 5168,
	ENTITY_PROP_MEINVHUSONG_REMAIN = 5169,
	ENTITY_PROP_MEINVHUSONG_MONSTERGID = 5170,
	ENTITY_PROP_MEINVHUSONG_PER_TIME = 5171, // 单次押镖的刷新次数
	ENTITY_PROP_PDART_SUCCESSED = 5172,		 // 押镖是否成功 1 个人成功 2 个人失败

	ENTITY_PROP_TREASURE_RANDOMSEED = 5173,
	ENTITY_PROP_TREASURE_LOOT = 5174,
	ENTITY_PROP_TREASURE_COUNT = 5175, // 寻宝总次数

	ENTITY_PROP_WORLD_PRAY_COUNT = 5176,

	ENTITY_PROP_BS_SC_LV = 5177,  // bs积分等级--废弃
	ENTITY_PROP_BS_SC_CUR = 5178, // bs当前积分--废弃

	ENTITY_PROP_CONSUME_GIFT = 5179,
	ENTITY_PROP_RECHARGE_MONEY = 5180, // 累计充值的灵符
	ENTITY_PROP_RECHARGE_GIFT = 5181,
	ENTITY_PROP_LIMIT_TIME_GIFT = 5182,

	ENTITY_PROP_NS_FIGHT_LEVEL_GIFT = 5183,
	ENTITY_PROP_NS_FIGHT_PET_LEVEL_GIFT = 5184,
	ENTITY_PROP_NS_FIGHT_STONE_GIFT = 5185,
	ENTITY_PROP_NS_FIGHT_LEVEL_CANGET = 5186,
	ENTITY_PROP_NS_FIGHT_PET_LEVEL_CANGET = 5187,
	ENTITY_PROP_NS_FIGHT_STONE_CANGET = 5188,

	ENTITY_PROP_LAST_RENAME_TIME = 5189, // 最近一次改名时间
	ENTITY_PROP_MRQD_TIME = 5190,		 // 每日签到时间戳
	ENTITY_PROP_NS_IS_LOGIN = 5191,
	ENTITY_PROP_VIP_GIFT = 5192,
	ENTITY_PROP_YK_TYPE = 5193,
	ENTITY_PROP_YK_DATE = 5194,
	ENTITY_PROP_VIP_WARE_HOUSE = 5195,
	ENTITY_PROP_FULL_PACKAGE = 5196,
	ENTITY_PROP_SUIT_REWARD = 5197,
	ENTITY_PROP_XB_HAPPNESS = 5198,			 // 寻宝积分(宝藏积分)
	ENTITY_PROP_TOTAL_RECHARGE_RMB = 5199,	 // 总RMB
	ENTITY_PROP_TOTAL_RECHARGE_TIMES = 5200, // 总次数
	ENTITY_PROP_JQBG_EXP = 5201,			 // 玩家所获累计经验值
	ENTITY_PROP_LOAD_REASON = 5202,			 // 加载原因: 0-正常加载, 1-竞技场加载虚拟玩家, 2-GM查看玩家
	ENTITY_PROP_GM_SESSION_ID = 5203,		 // GM所在session id
	ENTITY_PROP_CREATE_TIME = 5204,			 // 角色创建时间
	ENTITY_PROP_REDPACK_VALUE = 5205,		 // 全民红包

	ENTITY_PROP_RECHARGE_MONEY_EXT = 5206, // 额外累计充值的灵符

	ENTITY_PROP_REBORN_CONV_CNT = 5207, // 可以使用次数
	ENTITY_PROP_REBORN_CONV_DAY = 5208, // 记录时间

	ENTITY_PROP_TALENT_UNSAVE = 5209,			// 操作天赋页后是否保存
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_1 = 5210,	// 第一重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_2 = 5211,	// 第二重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_3 = 5212,	// 第三重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_4 = 5213,	// 第四重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_5 = 5214,	// 第五重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_6 = 5215,	// 第六重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_7 = 5216,	// 第七重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_8 = 5217,	// 第八重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_9 = 5218,	// 第九重天赋激活
	ENTITY_PROP_ACTIVE_TALENT_LEVEL_10 = 5219,	// 第十重天赋激活
	ENTITY_PROP_PRESTIGE_VALUE = 5220,			// 玩家威望值
	ENTITY_PROP_TALENT_MAGIC_VALUE_TEMP = 5221, // 激活/洗点所产生的天赋魔力值
	ENTITY_PROP_LEASE_INDEX = 5222,				// 神兵租赁
	ENTITY_PROP_FINISHED_WWTASK = 5223,			// 已完成的威望任务mask码
	ENTITY_PROP_TALENT_LEVEL = 5224,			// 当前已激活的天赋

	ENTITY_PROP_FINISH_MAIN_TASK = 5225,	// 完成主线任务
	ENTITY_PROP_LOGIN_DAYS_CONTINUE = 5226, // 连续登陆天数

	ENTITY_PROP_XSRW_IS_ACTIVE = 5227,	  // 激活限时任务  0:活动未开启  1:活动可开启  2:活动进行中  3:活动结束
	ENTITY_PROP_TOWER_HISTORY = 5228,	  // 爬塔历史纪录
	ENTITY_PROP_BOSS_SCORE_TIME = 5229,	  // boss积分时间
	ENTITY_PROP_XSRW_TIME_LEFT = 5230,	  // 限时任务倒计时
	ENTITY_PROP_GATHER_DEAD_TIMES = 5231, // 公会采集中的死亡次数
	ENTITY_PROP_GUILD_CALL_CD = 5232,	  // 召集公会成员冷却时间
	ENTITY_PROP_ENTER_CD = 5233,		  // 召集组队成员冷却CD
	ENITIY_PROP_CALL_SCENE = 5234,		  // 召唤的目标场景
	ENTIIY_PROP_CALL_POSX = 5235,		  // 召唤的目标坐标X
	ENTITY_PROP_CALL_POSY = 5236,		  // 召唤的目标坐标Y
	ENTITY_PROP_IMPEACH_VOTED = 5237,	  // 弹劾会长是否已经投票
	ENTITY_PROP_PRIVATE_DART_MULT = 5238, // 个人押镖奖励倍数
	ENTITY_PROP_BOSS_TREASURE_ID = 5239,  // 挖取掉落宝箱的id

	ENTITY_PROP_EXP_STROE_TIME = 5240,	// 累计领取特定经验玉的次数的有效期
	ENTITY_PROP_EXP_STROE_COUNT = 5241, // 累计领取特定经验玉的次数

	ENTITY_PROP_WWREWARD_UNGET = 5242,			// 未领取的威望令
	ENTITY_PROP_GET_MASTER_CLOTH = 5243,		// 是否获得城主时装武器
	ENTITY_PROP_QUEST_THF_FINISHED = 5244,		// 350任务是否提交
	ENTITY_PROP_QUEST_FHN_FINISHED = 5245,		// 490任务是否提交
	ENTITY_PROP_DAYLY_ACTIVITY_FINISHED = 5246, // 已完成的日常任务
	ENTITY_PROP_LOAD_CODE = 5247,				// 玩家是否首次登录
	ENTITY_PROP_MINING_TIME = 5248,				// 挖矿时间
	ENTITY_PROP_MINING_COUNT = 5249,			// 挖矿次数
	ENTITY_PROP_COMPOSE_STATE = 5250,			// 合成icon闪烁状态： 0闪 1不闪
	ENTITY_PROP_COMPOSE_STATE_S = 5251,			// 合成圣装icon闪烁状态： 0闪 1不闪
	ENTITY_PROP_DATI_TIMU = 5252,				// 今日题表 string
	ENTITY_PROP_THLB_XZ = 5253,					// 功勋特惠礼包
	ENTITY_PROP_THLB_HS = 5254,					// 魂石特惠礼包
	ENTITY_PROP_THLB_QH = 5255,					// 强化特惠礼包
	ENTITY_PROP_THLB_JM = 5256,					// 经脉特惠礼包
	ENTITY_PROP_GUILD_SPEEK = 5257,				// 是否能说话
	ENTITY_PROP_THLB_LP = 5258,					// 龙魄特惠礼包
	ENTITY_PROP_VIP_SERVICE_SHOW = 5259,		// vip客服
	ENTITY_PROP_THLB_JZQH = 5260,				// 极致强化特惠礼包
	ENTITY_PROP_CASHGIFT_TIME = 5261,			// 最后一次现金直购的日期
	ENTITY_PROP_SOUL_SYSTEM_VALUE = 5262,		// 魂力值
	ENTITY_PROP_SOUL_GRADE = 5263,				// 神魂阶数
	ENTITY_PROP_SOUL_ACTIVE = 5264,				// 神魂系统开启

	ENTITY_PROP_EVENT_TIPS_MASK = 5265,			 // 用来标记是否需要为玩家客户端默认勾选活动推送
	ENTITY_PROP_EVENT_BOSS_UPDATE_NOTICE = 5266, // BOSS刷新提醒默认勾选设置 标记位
	ENTITY_PROP_GuildCOIN = 5267,				 // 公会币

	ENTITY_PROP_RANK_SCORE = 5269,		 // 竞技积分
	ENTITY_PROP_INGOT_EX = 5280,		 // 元宝高位
	ENTITY_PROP_BOUND_INGOT_EX = 5281,	 // 绑定元宝高位
	ENTITY_PROP_HF_YBZP_TIME = 5282,	 // 在合服时间活动内，记录玩家上一次转盘操作的时间
	ENTITY_PROP_NOT_RECHARGE_VIP = 5283, // 非充值VIP等级

	ENTITY_PROP_CROSS_KFZB_REWARD_TIME = 5286,	 // 跨服争霸奖励领取次数
	ENTITY_PROP_CROSS_KFZB_REST_TIME = 5287,	 // 跨服争霸重置
	ENTITY_PROP_THLB_XF = 5288,					 // 英雄血符特惠礼包
	ENTITY_PROP_SL_SHIELD2_CHIP = 5289,			 // 神炉 - 护盾碎片
	ENTITY_PROP_THLB_HD2 = 5290,				 // 英雄护盾特惠礼包
	ENTITY_PROP_CROSS_REWARD_CLICK_STATE = 5291, // 跨服争霸奖励点击次数
	ENTITY_PROP_IS_IN_CROSS = 5292,				 // 是否进入跨服

	ENTITY_PROP_BAG_SLOT = 5300,		 // 解锁的背包格子数量
	ENTITY_PROP_PET_BAG_SLOT = 5301,	 // 宠物背包格子上限
	ENTITY_PROP_WAREHOUSE_SLOT = 5302,	 //
	ENTITY_PROP_NPC_BAG_SLOT = 5303,	 // 解锁仓库格子数量
	ENTITY_PROP_NPC_SEC_BAG_SLOT = 5304, // 二号NPC仓库可用格子数

	ENTITY_PROP_RECOVER_HM = 5305, // 恢复值 血量 蓝量
	ENTITY_PROP_CUR_MAPID = 5306,  // 当前场景ID
	ENTITY_PROP_OLD_MAPID = 5307,
	ENTITY_PROP_OLD_X = 5308,
	ENTITY_PROP_OLD_Y = 5309,
	ENTITY_PROP_GUILD_TEAM_ID = 5310, // 公会队伍ID

	ENTITY_PROP_DIVINE_SWORD_LEVEL = 5312,	  // 神剑等级
	ENTITY_PROP_DIVINE_SWORD_ADD_RATE = 5313, // 神剑升级概率加成

	ENTITY_PROP_DIVINE_ARMOR_LEVEL = 5314,	  // 神甲等级
	ENTITY_PROP_DIVINE_ARMOR_ADD_RATE = 5315, // 神甲升级概率加成

	ENTITY_PROP_HOLY_SWORD_LEVEL = 5316,	// 圣剑等级
	ENTITY_PROP_HOLY_SWORD_ADD_RATE = 5317, // 圣剑升级概率加成

	ENTITY_PROP_HOLY_ARMOR_LEVEL = 5318,	// 圣甲等级
	ENTITY_PROP_HOLY_ARMOR_ADD_RATE = 5319, // 圣甲升级概率加成

	ENTITY_PROP_STONE_PART_BEGIN = 5320,
	ENTITY_PROP_STONE_PART_1 = 5320,  // 武器 魂石
	ENTITY_PROP_STONE_PART_2 = 5321,  // 衣服 魂石
	ENTITY_PROP_STONE_PART_3 = 5322,  // 手镯 魂石
	ENTITY_PROP_STONE_PART_4 = 5323,  // 戒指 魂石
	ENTITY_PROP_STONE_PART_5 = 5324,  // 腰带 魂石
	ENTITY_PROP_STONE_PART_6 = 5325,  // 头盔 魂石
	ENTITY_PROP_STONE_PART_7 = 5326,  // 项链 魂石
	ENTITY_PROP_STONE_PART_8 = 5327,  // 手镯2魂石
	ENTITY_PROP_STONE_PART_9 = 5328,  // 戒指2魂石
	ENTITY_PROP_STONE_PART_10 = 5329, // 鞋子 魂石
	ENTITY_PROP_STONE_PART_END = 5329,

	ENTITY_PROP_HERO_STONE_PART_BEGIN = 5330,
	ENTITY_PROP_HERO_STONE_PART_1 = 5330,  // 英雄武器 魂石
	ENTITY_PROP_HERO_STONE_PART_2 = 5331,  // 英雄衣服 魂石
	ENTITY_PROP_HERO_STONE_PART_3 = 5332,  // 英雄手镯 魂石
	ENTITY_PROP_HERO_STONE_PART_4 = 5333,  // 英雄戒指 魂石
	ENTITY_PROP_HERO_STONE_PART_5 = 5334,  // 英雄腰带 魂石
	ENTITY_PROP_HERO_STONE_PART_6 = 5335,  // 英雄头盔 魂石
	ENTITY_PROP_HERO_STONE_PART_7 = 5336,  // 英雄项链 魂石
	ENTITY_PROP_HERO_STONE_PART_8 = 5337,  // 英雄手镯2魂石
	ENTITY_PROP_HERO_STONE_PART_9 = 5338,  // 英雄戒指2魂石
	ENTITY_PROP_HERO_STONE_PART_10 = 5339, // 英雄鞋子 魂石
	ENTITY_PROP_HERO_STONE_PART_END = 5339,

	ENTITY_PROP_ENHANCE_TOTAL = 5340,		   //  强化总值
	ENTITY_PROP_WEAPON_ENHANCE_LEVEL = 5341,   // 武器
	ENTITY_PROP_CLOTH_ENHANCE_LEVEL = 5342,	   // 衣服
	ENTITY_PROP_BANGLE_ENHANCE_LEVEL = 5343,   // 手镯
	ENTITY_PROP_RING_ENHANCE_LEVEL = 5344,	   // 戒指
	ENTITY_PROP_BELT_ENHANCE_LEVEL = 5345,	   // 腰带
	ENTITY_PROP_HELMET_ENHANCE_LEVEL = 5346,   // 头盔
	ENTITY_PROP_NECKLESS_ENHANCE_LEVEL = 5347, // 项链
	ENTITY_PROP_BANGLE2_ENHANCE_LEVEL = 5348,  // 手镯2
	ENTITY_PROP_RING2_ENHANCE_LEVEL = 5349,	   // 戒指2
	ENTITY_PROP_SHOES_ENHANCE_LEVEL = 5350,	   // 鞋子

	ENTITY_PROP_WEAPON_BLESS = 5351,   // 武器祝福值
	ENTITY_PROP_CLOTH_BLESS = 5352,	   // 衣服祝福值
	ENTITY_PROP_BANGLE_BLESS = 5353,   // 手镯祝福值
	ENTITY_PROP_RING_BLESS = 5354,	   // 戒指祝福值
	ENTITY_PROP_BELT_BLESS = 5355,	   // 腰带祝福值
	ENTITY_PROP_HELMET_BLESS = 5356,   // 头盔祝福值
	ENTITY_PROP_NECKLESS_BLESS = 5357, // 项链祝福值
	ENTITY_PROP_BANGLE2_BLESS = 5358,  // 手镯2祝福值
	ENTITY_PROP_RING2_BLESS = 5359,	   // 戒指2祝福值
	ENTITY_PROP_SHOES_BLESS = 5360,	   // 鞋子祝福值

	ENTITY_PROP_HERO_WEAPON_ENHANCE_LEVEL = 5361,	// 英雄武器
	ENTITY_PROP_HERO_CLOTH_ENHANCE_LEVEL = 5362,	// 英雄衣服
	ENTITY_PROP_HERO_BANGLE_ENHANCE_LEVEL = 5363,	// 英雄手镯
	ENTITY_PROP_HERO_RING_ENHANCE_LEVEL = 5364,		// 英雄戒指
	ENTITY_PROP_HERO_BELT_ENHANCE_LEVEL = 5365,		// 英雄腰带
	ENTITY_PROP_HERO_HELMET_ENHANCE_LEVEL = 5366,	// 英雄头盔
	ENTITY_PROP_HERO_NECKLESS_ENHANCE_LEVEL = 5367, // 英雄项链
	ENTITY_PROP_HERO_BANGLE2_ENHANCE_LEVEL = 5368,	// 英雄手镯2
	ENTITY_PROP_HERO_RING2_ENHANCE_LEVEL = 5369,	// 英雄戒指2
	ENTITY_PROP_HERO_SHOES_ENHANCE_LEVEL = 5370,	// 英雄鞋子

	ENTITY_PROP_HERO_WEAPON_BLESS = 5371,	// 英雄武器祝福值
	ENTITY_PROP_HERO_CLOTH_BLESS = 5372,	// 英雄衣服祝福值
	ENTITY_PROP_HERO_BANGLE_BLESS = 5373,	// 英雄手镯祝福值
	ENTITY_PROP_HERO_RING_BLESS = 5374,		// 英雄戒指祝福值
	ENTITY_PROP_HERO_BELT_BLESS = 5375,		// 英雄腰带祝福值
	ENTITY_PROP_HERO_HELMET_BLESS = 5376,	// 英雄头盔祝福值
	ENTITY_PROP_HERO_NECKLESS_BLESS = 5377, // 英雄项链祝福值
	ENTITY_PROP_HERO_BANGLE2_BLESS = 5378,	// 英雄手镯2祝福值
	ENTITY_PROP_HERO_RING2_BLESS = 5379,	// 英雄戒指2祝福值
	ENTITY_PROP_HERO_SHOES_BLESS = 5380,	// 英雄鞋子祝福值

	ENTITY_PROP_ADD_EXTRA_TALENT = 5381, // 是否有额外的特权返还魔力加成
	ENTITY_PROP_REVIVE_RING = 5382,		 // 复活特戒 是否在开服7天内开启
	ENTITY_PROP_PECULIAR_RING = 5383,	 // 特有特戒 是否在开服7天内开启

	ENTITY_PROP_MOON_SPIRIT_MAX = 5384,	  // 最大月灵数量
	ENTITY_PROP_MOON_SPIRIT_COUNT = 5385, // 当前月灵数量
	ENTITY_PROP_MOON_SPIRIT_LV = 5386,	  // 月灵等级

	ENTITY_PROP_CAPITAIN_MATA_INVITE_ADMIT = 5387, // 队伍中的队员邀请其他玩家，队长默认同意

	ENTITY_PROP_MOGUAN_ENHANCE_LEVEL = 5390,   // 魔冠强化等级
	ENTITY_PROP_HUJIN_ENHANCE_LEVEL = 5391,	   // 护镜强化等级
	ENTITY_PROP_YUPEI_ENHANCE_LEVEL = 5392,	   // 玉佩强化等级
	ENTITY_PROP_LUNJIN_ENHANCE_LEVEL = 5393,   // 纶巾强化等级
	ENTITY_PROP_SHOULIAN_ENHANCE_LEVEL = 5394, // 手链强化等级
	ENTITY_PROP_JUNGU_ENHANCE_LEVEL = 5395,	   // 军鼓强化等级
	ENTITY_PROP_MOGUAN_BLESS = 5396,		   // 魔冠祝福值
	ENTITY_PROP_HUJIN_BLESS = 5397,			   // 护镜祝福值
	ENTITY_PROP_YUPEI_BLESS = 5398,			   // 玉佩祝福值
	ENTITY_PROP_LUNJIN_BLESS = 5399,		   // 纶巾祝福值
	ENTITY_PROP_SHOULIAN_BLESS = 5400,		   // 手链祝福值
	ENTITY_PROP_JUNGU_BLESS = 5401,			   // 军鼓祝福值

	ENTITY_PROP_PRESTIGE_LOST_TIME = 5410, // 威望丢失时间(跨天扣除威望后，立即重启服务器，登陆流程会再次扣除威望)

	ENTITY_PROP_BAG_EMPTY_POS = 5411, // 玩家背包的剩余格子

	ENTITY_PROP_GOD_WEAPON_CUTTING = 5412,	// 切割 等级  神器
	ENTITY_PROP_GOD_WEAPON_CHOPPING = 5413, // 斩杀 等级
	ENTITY_PROP_GOD_WEAPON_TIGU = 5414,		// 剔骨 等级
	ENTITY_PROP_GOD_WEAPON_TIANZHU = 5415,	// 天诛 等级

	ENTITY_PROP_CROSS_MAP_LINE_ID = 5416, // 玩家所在的跨服场景分线id（给游戏服用）
	ENTITY_PROP_CROSS_MAP_ID = 5417,	  // 玩家所在的跨服场景id（给游戏服用）
	ENTITY_PROP_CROSS_MAP_POSX = 5418,	  // 玩家所在的跨服场景posx（给游戏服用）
	ENTITY_PROP_CROSS_MAP_POSY = 5419,	  // 玩家所在的跨服场景posy（给游戏服用）

	// 跨服竞技相关
	ENTITY_PROP_CROSS_BATTLE_GROUP_ID = 5420,		 // 玩家的分组id
	ENTITY_PROP_CROSS_RANK_SCORE = 5421,			 // 跨服排位积分
	ENTITY_PROP_CROSS_BATTLE_USE_COUNTS = 5425,		 // 跨服排位使用次数
	ENTITY_PROP_CROSS_BATTLE_RESET_TIME = 5426,		 // 玩家最近一次重置赛季的时间
	ENTITY_PROP_ALL_WAR_ZONE_CROSS_SERVER_ID = 5427, // 全区跨服玩法的跨服服务器id

	// 爵位
	ENTITY_PROP_JUE_WEI_LEVEL = 5430, // 爵位等级
	ENTITY_PROP_JUE_WEI_EXP = 5431,	  // 爵位经验

	// 翅膀提升次数
	ENTITY_PROP_WING_IMPROVE_1 = 5435, // 翅膀属性1提升次数
	ENTITY_PROP_WING_IMPROVE_2 = 5436, // 翅膀属性2提升次数
	ENTITY_PROP_WING_IMPROVE_3 = 5437, // 翅膀属性3提升次数

	// 官阶
	ENTITY_PROP_GUAN_JIE_LEVEL = 5440, // 官阶等级
	ENTITY_PROP_GUAN_JIE_EXP = 5441,   // 官阶经验值
	ENTITY_PROP_GUAN_YIN_LEVEL = 5442, // 官印等级
	ENTITY_PROP_GUAN_YIN_EXP = 5443,   // 官印经验值

	// 霸业装备
	ENTITY_PROP_HEGEMON_EQUIP_IS_SHOW = 5444,	 // 霸业   0 表示不显示  1 表示显示
	ENTITY_PROP_HEGEMON_EQUIP_SUIT_2_LVL = 5445, // 霸业套装2套 等级
	ENTITY_PROP_HEGEMON_EQUIP_SUIT_8_LVL = 5446, // 霸业套装8件套 等级
	// 雷霆装备

	ENTITY_PROP_THUNDER_POWER_SUIT_2_LVL = 5447, // 雷霆两件套 等级
	ENTITY_PROP_THUNDER_POWER_SUIT_8_LVL = 5448, // 雷霆两件套 等级

	ENTITY_PROP_THUNDER_POWER_SUIT_2_STEP = 5449, // 雷霆之力套装激活的阶数(第2种)
	ENTITY_PROP_THUNDER_POWER_SUIT_2_CNT = 5450,  // 雷霆之力套装激活的个数(第2种)

	ENTITY_PROP_THUNDER_SOUL_SUIT_1_STEP = 5451, // 雷霆之魂套装激活的阶数(第一种)
	ENTITY_PROP_THUNDER_SOUL_SUIT_1_CNT = 5452,	 // 雷霆之魂套装激活的个数(第一种)
	ENTITY_PROP_THUNDER_SOUL_SUIT_2_STEP = 5453, // 雷霆之魂套装激活的阶数(第2种)
	ENTITY_PROP_THUNDER_SOUL_SUIT_2_CNT = 5454,	 // 雷霆之魂套装激活的个数(第2种)

	ENTITY_PROP_SHENYU_SUIT = 5455,		// 神域套装阶数
	ENTITY_PROP_HOT_TBLOOM_SUIT = 5456, // 热血套装阶数

	ENTITY_PROP_STOVE_RED_STAR_LEVEL = 5457,	// 神炉 - 血玉星级
	ENTITY_PROP_STOVE_SHIELD_STAR_LEVEL = 5458, // 神炉 - 护盾星级
	ENTITY_PROP_STOVE_GEM_STAR_LEVEL = 5459,	// 神炉 - 宝石星级
	ENTITY_PROP_STOVE_SOUL_STAR_LEVEL = 5460,	// 神炉 - 魂珠星级

	ENTITY_PROP_STOVE_RED_ORDER_LEVEL = 5461,	 // 神炉 - 血玉等阶
	ENTITY_PROP_STOVE_SHIELD_ORDER_LEVEL = 5462, //  神炉 - 护盾等阶
	ENTITY_PROP_STOVE_GEM_ORDER_LEVEL = 5463,	 //  神炉 - 宝石等阶
	ENTITY_PROP_STOVE_SOUL_ORDER_LEVEL = 5464,	 //  神炉 - 魂珠等阶

	ENTITY_PROP_SEPARATION_WARTERlEVEL = 5465,	// 赤水分身等级
	ENTITY_PROP_SEPARATION_FIRElEVEL = 5466,	// 烈火分身等级
	ENTITY_PROP_SEPARATION_SOILlEVEL = 5467,	// 岩土分身等级
	ENTITY_PROP_SEPARATION_THUNDERlEVEL = 5468, // 狂雷分身等级

	ENTITY_PROP_HERO_ATTACK_MDOEL = 5474, // 宝宝攻击模式  0-跟随 1-自由攻击

	ENTITY_PROP_STONE_GHOST_TOTAL = 5475, //  宝石魂石总值

	ENTITY_PROP_THERION_TOTAL = 5484, // 魔灵总值

	ENTITY_PROP_BAOBAO_SKILLBAG_RECORD = 5485, // 宝宝技能获取

	ENTITY_PROP_FIRST_RECHARGE_TIME = 5486,	 // 首充时间 -dzy
	ENTITY_PROP_RECHARGE_GIFT_RECORD = 5487, // 首充领取记录  -dzy
	ENTITY_PROP_CHAT_CODE = 5490,			 // 聊天消息号

	ENTITY_PROP_LCLB_RECORD = 5492,				   // 累充礼包领取记录
	ENTITY_PROP_TRAIN_MISSION = 5493,			   // 练功房通关最大数
	ENTITY_PROP_SPECIAL_RING_GIFT_RECORD = 5494,   // 特戒礼包领取记录
	ENTITY_PROP_TREASURE_CNT_IN_A_ACTICITY = 5495, // 某一次活动的寻宝次数
	ENTITY_PROP_BAOBAO_SKILL_GIFT_RECORD = 5496,   // 宝宝礼包购买记录

	ENTITY_PROP_BIGBANG_BOSS1_KILLNUM = 5497, // 击杀BOSS1次数
	ENTITY_PROP_BIGBANG_BOSS2_KILLNUM = 5498, // 击杀BOSS2次数
	ENTITY_PROP_LOGIN_TIME_YMD = 5499,		  // 登录年月日
	ENTITY_PROP_ZBGDI_JP = 5500,			  // 珍宝阁地级珍宝精魄数量
	ENTITY_PROP_ZBGTJ_JP = 5501,			  // 珍宝阁天级珍宝精魄数量
	ENTITY_PROP_ZBGSJ_JP = 5502,			  // 珍宝阁神级珍宝精魄数量
	ENTITY_PROP_ZBGHH_JP = 5503,			  // 珍宝阁洪荒珍宝精魄数量
	ENTITY_PROP_ZBGWS_JP = 5504,			  // 珍宝阁无上珍宝精魄数量
	ENTITY_PROP_ZBG_DISCOUNT = 5505,		  // 珍宝阁打折
	ENTITY_PROP_ZBGDI_DISCOUNT_TIME = 5506,	  // 珍宝阁地级打折次数
	ENTITY_PROP_ZBGTJ_DISCOUNT_TIME = 5507,	  // 珍宝阁天级打折次数
	ENTITY_PROP_ZBGSJ_DISCOUNT_TIME = 5508,	  // 珍宝阁神级打折次数
	ENTITY_PROP_ZBGHH_DISCOUNT_TIME = 5509,	  // 珍宝阁洪荒打折次数
	ENTITY_PROP_ZBGWS_DISCOUNT_TIME = 5510,	  // 珍宝阁无上打折次数
	ENEITY_PROP_HUIXN_ATTACK = 5512,		  //  必出会心
	ENTITY_PROP_FIRE_RAIN_CD = 5513,		  // 火雨CD
	ENTITY_PROP_WEEK_CARD_TIME = 5515,		  // 周卡结束时间
	ENTITY_PROP_MEMBER_TIME = 5516,			  // 会员结束时间
	ENTITY_REWARD_GET_TIME = 5517,			  // 会员奖励领取时间
	ENTITY_PROP_IS_MEMBER = 5518,			  // 是会员1  不是会员0
	ENTITY_PROP_ZHIZUN_REWARD_RECORD = 5519,  // 真VIP奖励领取情况

	ENTITY_PROP_MINER_LEVEL_EXP = 5520,			// 矿工等级经验
	ENTITY_PROP_MINER_LEVEL = 5521,				// 矿工等级

	ENTITY_PROP_MINING_END_TIME = 5522,			// 挖矿结算时间
	ENTITY_PROP_USE_FIRE_RAIN = 5523,			// 使用火雨
	ENTITY_PROP_BOSS_LEVEL_UP_ID = 5524,		// BOSS图鉴升级的当前id
	ENTITY_PROP_BOSS_LEVEL_UP_SCORE = 5525,		// BOSS图鉴升级的积分

	ENTITY_PRIVILEGE_BEGIN = 5547,
	ENTITY_PROP_JUBAOPENG_OPEN_FLAG = 5548,		  // 聚宝盆开启标志
	ENTITY_PROP_HUICHENG_NO_CD_FLAG = 5549,		  // 回城石无CD
	ENTITY_PROP_SUIJI_NO_CD_FLAG = 5550,		  // 随机石无CD
	ENTITY_PROP_HUISHOU_ADD_PERCENT = 5551,		  // 背包回收加成
	ENTITY_PROP_HUISHOU_INGOT_ADD_PERCENT = 5552, // 背包回收元宝加成

	ENTITY_PROP_LIAGONGFANG_ADD_PERCENT = 5553,		// 练功房收益加成
	ENTITY_PROP_WAKUANG_ADD_PERCENT = 5554,			// 挖矿收益加成
	ENTITY_PROP_YABIAO_ADD_PERCENT = 5555,			// 押镖收益加成
	ENTITY_PROP_SHIMUSHAOZHU_COUNTS_ADD = 5556,		// 石墓烧猪次数增加
	ENTITY_PROP_WAKUANG_COUNTS_ADD = 5557,			// 挖矿次数增加
	ENTITY_PROP_CHUMO_COUNTS_ADD = 5558,			// 除魔次数增加
	ENTITY_PROP_QIFU_COUNTS_ADD = 5559,				// 祈福次数增加
	ENTITY_PROP_QIFUBAOJI_ADD_PERCENT = 5560,		// 祈福暴击增加
	ENTITY_PROP_DIJIZHENBAO_COUNTS_ADD = 5561,		// 地级珍宝次数增加
	ENTITY_PROP_TIANJIZHENBAO_COUNTS_ADD = 5562,	// 天级珍宝次数增加
	ENTITY_PROP_SHENJIZHENBAO_COUNTS_ADD = 5563,	// 神级珍宝次数增加
	ENTITY_PROP_HONGHUANGZHENBAO_COUNTS_ADD = 5564, // 洪荒珍宝次数增加
	ENTITY_PROP_WUSHANGZHENBAO_COUNTS_ADD = 5565,	// 无上珍宝次数增加
	ENTITY_PROP_DABAO_COUNTS_ADD = 5566,			// 幸运大爆额外次数
	ENTITY_PROP_CANGKU_COUNTS_ADD = 5567,			// 仓库格子额外数量
	ENTITY_PROP_TRADE_DERATE = 5568,				// 交易行税率减免
	ENTITY_PROP_RELIVE_COUNTS_ADD = 5569,			// 每次原地复活额外次数  4个特权额外属性

	ENTITY_PROP_TOWER_ROUND = 5570, // 爬塔层数
	ENTITY_PRIVILEGE_END = 5600,
	ENTITY_PROP_EX_EXP_ADD = 5601, // 经验加成额外属性 百分比

	ENTITY_PROP_MINING_HAS_BEEN_ROBBED = 5605, // 当前矿 被掠夺
	ENTITY_PROP_INVERST_FLAG = 5606,		   // 投资标记

	ENTITY_PROP_CROSS_SERVER_ID = 5607, // 玩家跨服服务器id

	ENTITY_PROP_FIRE_RAIN = 5610,			  // 火雨技能购买状态
	ENTITY_PROP_MINER_OWNER_ID = 5612,		  // 矿工的主人的id
	ENTITY_PROP_MINER_STATE = 5613,			  // 矿工的状态
	ENTITY_PROP_EXPERIENCE_GET_RECORD = 5614, // 历练之路奖励领取

	ENTITY_PROP_TOUZI_TIME_LOGIN = 5617,	// 登录投资购买时间
	ENTITY_PROP_TOUZI_TIME_FORCE = 5618,	// 战力投资购买时间
	ENTITY_PROP_TOUZI_RECORD_LOGIN = 5619,	// 登录投资领取记录
	ENTITY_PROP_TOUZI_RECORD_FORCE = 5620,	// 战力投资领取记录
	ENTITY_PROP_TOUZI_RECORD_LEVEL = 5621,	// 等级投资领取记录
	ENTITY_PROP_TOUZI_TIME_LEVEL = 5622,	// 等级投资购买时间
	ENTITY_PROP_CONTINUE_KILL_CNT = 5630,	// 连杀人数
	ENTITY_PROP_RECHARGE_FIVE_TIMES = 5632, // 五倍充值状态  0 -- 没有享受过五倍充值 1-- 享受过五倍充值
	ENTITY_PROP_TOUZI_RECORD_LEVEL2 = 5633, // 等级投资2领取记录
	ENTITY_PROP_TOUZI_TIME_LEVEL2 = 5634,	// 等级投资2购买时间
	ENTITY_PROP_TOUZI_RECORD_LEVEL3 = 5635, // 等级投资3领取记录
	ENTITY_PROP_TOUZI_TIME_LEVEL3 = 5636,	// 等级投资3购买时间

	ENTITY_PROP_CSZT_REWARDED = 5640,	  // 发送奖励标记
	ENTITY_PROP_CSZT_IS_OPEN = 5641,	  // 是否开放
	ENTITY_PROP_CSZT_DINGYUE = 5642,	  // 订阅
	ENTITY_PROP_CSZT_CHALLENGECNT = 5643, // 挑战次数
	ENTITY_PROP_MC_ID_OLD = 5644,		  // 上个当前萌宠的ID

	ENTITY_PROP_VIP_PRIVILEGE = 5774, //  vip特权
	ENTITY_PROP_VIP_LV = 5775,		  //  vip等级
	ENTITY_PROP_VIP_PAY_GIFT = 5777,
	ENTITY_PROP_VIP_FREE_GIFT = 5778,
	ENTITY_PROP_VIP_FREE_GIFT_EXTEND = 5779,   // vip占位给扩展
	ENTITY_PROP_VIP_FREE_GIFT_EXTEND_1 = 5780, // vip占位给扩展
	ENTITY_PROP_VIP_TASK_START = 5781,		   // vip任务
	ENTITY_PROP_VIP_TASK_1 = 5781,			   // vip任务
	ENTITY_PROP_VIP_TASK_2 = 5782,			   // vip任务
	ENTITY_PROP_VIP_TASK_3 = 5783,			   // vip任务
	ENTITY_PROP_VIP_TASK_4 = 5784,			   // vip任务
	ENTITY_PROP_VIP_TASK_5 = 5785,			   // vip任务
	ENTITY_PROP_VIP_TASK_6 = 5786,			   // vip任务
	ENTITY_PROP_VIP_TASK_7 = 5787,			   // vip任务
	ENTITY_PROP_VIP_TASK_8 = 5788,			   // vip任务
	ENTITY_PROP_VIP_TASK_9 = 5789,			   // vip任务
	ENTITY_PROP_VIP_TASK_10 = 5790,			   // vip任务
	ENTITY_PROP_VIP_TASK_END = 5790,		   // vip任务

	ENTITY_PROP_SYNTHESIS_SIGN_START = 5800, // 合成系统标记开始

	ENTITY_PROP_SYNTHESIS_SIGN_END = 5999, // 合成系统标记结束

	/**********************************************************************************************/
	/***********************灵宝ID 						   BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_PROP_LINGBAO_EQUIP = 6000, // 当前穿戴生效的灵宝ID
	ENTITY_PROP_LINGBAO_BEGIN = 6001,
	ENTITY_PROP_LINGBAO_END = 6099,
	ENTITY_PROP_LINGBAO_SHOW_ID = 6100,
	/**********************************************************************************************/
	/***********************灵宝ID 							 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_1 = 6111,  // 武器位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_2 = 6112,  // 衣服位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_3 = 6113,  // 手镯位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_4 = 6114,  // 戒指位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_5 = 6115,  // 腰带位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_6 = 6116,  // 头盔位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_7 = 6117,  // 项链位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_8 = 6118,  // 手镯2位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_9 = 6119,  // 戒指2位洗出的属性条数
	ENTITY_PROP_SMELT_ATTR_COUNT_EQUIP_10 = 6120, // 鞋子位洗出的属性条数

	ENTITY_PROP_SHENLONGHUTI_LEVEL = 6121,	   // 神龙护体等级
	ENTITY_PROP_SHACHENG_DONATION = 6123,	   // 沙城捐献额度
	ENTITY_PROP_SCDONATE_BASEATTR_FLAG = 6124, // 沙城捐献[是否加过保底属性标记]
	ENTITY_PROP_FIRST_GAME = 6126,			   // 是否第一次登陆游戏

	ENTITY_PROP_GUIDE_BAG_FULL_OPEN = 6127, // 背包满引导  0.未开启  1.可以开启  2.开启过

	ENTITY_PROP_SC_TREASURY_CAN_DROP_VALUE = 6128, // 沙城宝库个人剩余可掉落灵符数量
	ENTITY_PROP_SC_TREASURY_DROP_VALUE = 6129,	   // 沙城宝库个人本次掉落数量
	// BOSS首杀
	ENTITY_PROP_BOSS_FIRST_KILL_BEGIN = 6130,
	ENTITY_PROP_BOSS_FIRST_KILL_END = 6150,

	ENTITY_PROP_RANK_TIME_BASE = 6200, //  CHART_TYPE_PLAYER_FORCE 开始的值
	ENTITY_PROP_RANK_TIME_START = 7001,
	ENTITY_PROP_RANK_TIME_END = 7099,			//  CHART_TYPE_TIANTI    中间的值 不要占用
	ENTITY_PROP_TREASURE_CNT_IN_HOLIDAY = 7100, // 运营活动的寻宝次数

	ENTITY_PROP_PLAYER_BLOOD = 7102,	  // 玩家血脉等级
	ENTITY_PROP_PLAYER_GOD_POWER = 7103,  // 玩家神力等级
	ENTITY_PROP_OTHER_INFO_GET_CD = 7104, // 查看其它玩家装备的cd(需要数据库操作)
	ENTITY_PROP_PLAYER_GEM = 7105,		  // 玩家宝石等级
	ENTITY_PROP_PLAYER_SOUL_BEAD = 7106,  // 玩家魂珠等级

	ENTITY_PROP_HUANJING_REMAIN_TIME = 7107, // 幻境地图剩余时间


	// 加速检查
	ENTITY_PROP_LAST_ATTACK_TICK = 7122,		// 上一次攻击的时间戳
	ENTITY_PROP_ATTACK_ENABLE_WAVE_TICK = 7123, // 攻击隔间允许波动总时间
	ENTITY_PROP_ERROR_TIMES = 7124,				// 当前攻击阶段  错误攻击的次数
	ENTITY_RPOP_ERROP_BEGIN_TICK = 7125,
	ENTITY_RPOP_ATTACK_BEGIN_TICK = 7126,
	ENTITY_RPOP_ATTACK_TOTAL_TICK = 7127,		 // 攻击总时长（）
	ENTITY_RPOP_ATTACK_TOTAL_TIMES = 7128,		 // 攻击总次数
	ENTITY_PROP_ATTACK_ENABLE_WAVE_TICK2 = 7129, // 攻击总次数2
	ENTITY_PROP_ATTACK_CHECK_FLAG = 7130,		 // 攻击总次数2

	// 移动加速
	ENTITY_PROP_LAST_MOVE_TICK = 7131,		  // 上一次移动的时间戳
	ENTITY_PROP_MOVE_ENABLE_WAVE_TICK = 7132, // 移动隔间允许波动总时间
	ENTITY_PROP_MOVE_CHECK_FLAG = 7133,		  // 上一次是否错误
	ENTITY_PROP_LAST_ATTACK_TICK_EX = 7134,	  // 上一次攻击的时间戳(EX)
	ENTITY_PROP_LAST_MOVE_TICK_EX = 7135,	  // 上一次移动的时间戳(EX)

	ENTITY_PROP_MOVE_TIME_EX = 7136,
	ENTITY_PROP_MOVE_TIME = 7137,
	ENTITY_PROP_MOVE_TICK = 7138,
	ENTITY_PROP_MOVE_TOTAL = 7139,
	ENTITY_PROP_CANGLONG_GIFT = 7140,  // 苍龙礼包
	ENTITY_PROP_MENGCHONG_GIFT = 7141, // 萌宠礼包
	ENTITY_RPOP_SPEED_CHECK_END = 7150,
	// 加速检查

	ENTITY_PROP_ADDFRIEND_CD = 7152, // 通过名字加好友，可以直接操作数据库，加个CD保护
	ENTITY_PROP_TRADE_OPEN = 7153,	 // 交易功能是否开启  1 - 开启 0 - 未开启
	ENTITY_PROP_SMSZ_FLAG = 7154,

	ENTITY_PROP_RUNE_DAMAGE_ADD = 7155, // 野蛮符文  受伤害增加（万分比）
	ENTITY_PROP_RECOVERY_OPEN = 7156,	// 回收特权是否开启
	// ENTITY_PROP_RECHARGE_RECORD		= 7157,   //充值记录（已作废）
	ENTITY_PROP_RECOVER_EXP = 7158, // 钻石回收经验

	ENTITY_PROP_HISTORY_SCORE = 7159, // 装备历史评分
	ENTITY_PROP_FEISHENG_EXP = 7160,  // 飞升经验

	// 地图统计信息
	ENTITY_PROP_SCENE_ENTER_TIME = 7161,		 // 进入该场景时间戳
	ENTITY_PROP_SCENE_GET_EXP = 7162,			 // 在该场景获得的经验
	ENTTIY_PROP_SCENE_KILL_MONSTER_CNT_1 = 7163, // 在该场景击杀普通怪物数量
	ENTTIY_PROP_SCENE_KILL_MONSTER_CNT_2 = 7164, // 在该场景击杀精英怪物数量
	ENTTIY_PROP_SCENE_KILL_MONSTER_CNT_3 = 7165, // 在该场景击杀头目怪物数量
	ENTTIY_PROP_SCENE_KILL_MONSTER_CNT_4 = 7166, // 在该场景击杀统领怪物数量
	ENTTIY_PROP_SCENE_KILL_MONSTER_CNT_5 = 7167, // 在该场景击杀领主怪物数量
	ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_1 = 7168,	 // 在该场景普通装备掉落数量
	ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_2 = 7169,	 // 在该场景优秀装备掉落数量
	ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_3 = 7170,	 // 在该场景精良装备掉落数量
	ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_4 = 7171,	 // 在该场景稀有装备掉落数量
	ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_5 = 7172,	 // 在该场景史诗装备掉落数量

	// 世界Boss
	ENTITY_PROP_WORLD_BOSS_REWARD_FLAG = 7173, // 新版世界Boss领奖标记（0，未参与，1参与未领奖，2，已领奖）

	ENTITY_PROP_BLOOD_COST_ATTR = 7174,		// 血脉提升，属性值
	ENTITY_PROP_GOD_POWER_COST_ATTR = 7175, // 神力提升，属性值

	ENTITY_PROP_JIFEN_1 = 7176,				   // 积分   普通
	ENTITY_PROP_JIFEN_2 = 7177,				   // 积分	稀有
	ENTITY_PROP_JIFEN_3 = 7178,				   // 积分	史诗
	ENTITY_PROP_JIFEN_4 = 7179,				   // 积分   传说
	ENTITY_PROP_ENDLESS_CHAL_GATE = 7180,	   // 无限挑战关卡
	ENTITY_PROP_ENDLESS_CHAL_EXP = 7181,	   // 无限挑战进度条
	ENTITY_PROP_ENDLESS_CHAL_SANDCLOCK = 7182, // 无限挑战沙漏
	ENTITY_PROP_ENDLESS_CHAL_REC_GATE = 7183,  // 无限挑战推荐关卡
	ENTITY_PROP_ENDLESS_CHAL_GATE_TIME = 7184, // 无限挑战推荐时间
	ENTITY_PROP_ENDLESS_CHAL_IS_TAKE = 7185,   // 无限挑战推荐时间
	ENTITY_PROP_ENDLESS_CHAL_SAODANG = 7186,
	ENTITY_PROP_ENDLESS_CHAL_TIMEOUT = 7187,  // 无限挑战沙漏时间到了
	ENTITY_PROP_ENDLESS_CHAL_DROPRATE = 7188, // 无限挑战极品掉落

	ENTITY_PROP_GEM_COST_ATTR = 7191,		// 宝石提升，属性值
	ENTITY_PROP_SOUL_BEAD_COST_ATTR = 7192, // 魂珠提升，属性值

	ENTITY_PROP_MIME_STAMINA = 7200,			 // 挖矿 体力值
	ENTITY_PROP_MIME_ITEM_1 = 7201,				 // 挖矿 收获道具1ID
	ENTITY_PROP_MIME_ITEM_2 = 7202,				 // 挖矿 收获道具2ID
	ENTITY_PROP_MIME_ITEM_COUNT_1 = 7206,		 // 挖矿 收获道具1数量
	ENTITY_PROP_MIME_ITEM_COUNT_2 = 7207,		 // 挖矿 收获道具2数量
	ENTITY_PROP_MIME_STATE = 7210,				 // 挖矿 状态 0：空闲 1：正在挖矿
	ENTITY_PROP_MIME_DURATION = 7211,			 // 挖矿 挖矿时长，单位秒，领取收成时清零
	ENTITY_PROP_MIME_TIME_NODE = 7212,			 // 挖矿 时间节点，每产出一次刷新一次时间，开始挖矿或换矿脉时也刷新时间
	ENTITY_PROP_MINE_PROTECT_END_TIME = 7213,	 // 挖矿 保护结束时间
	ENTITY_PROP_MINE_LODE_LEVEL = 7214,			 // 挖矿 矿脉等级
	ENTITY_PROP_MINE_DEFENSE_SKILL_PLAN = 7215,	 // 挖矿 防守技能方案
	ENTITY_PROP_TUOGUAN_YUEKA_GET_TIME = 7218,	 // 托管月卡奖励领取时间 (天)
	ENTITY_PROP_TEHUI_YUEKA_GET_TIME = 7219,	 // 特惠奖励领取时间 (天)
	ENTITY_PROP_TEHUI_ZHOUKA_GET_TIME = 7220,	 // 特惠周卡奖励领取时间 (天)
	ENTITY_PROP_WEAPON_DROP_DEC_PERCENT = 7221,	 // 死亡掉落装备概率减少
	ENTITY_PROP_TRADE_DEC_PERCENT = 7222,		 // 交易行税率减少
	ENTITY_PROP_HUANJING_BOSS_PERCENT = 7223,	 // 幻境boss刷新时间减
	ENTITY_PROP_MINE_LODE_INDEX = 7224,			 // 挖矿 矿脉号
	ENTITY_PROP_EX_BAG_SLOT = 7225,				 // 特权背包格子开启
	ENTITY_PROP_DART_COUNT = 7226,				 // 历史押镖次数
	ENTITY_PROP_QIRI_FENGSHEN_SCORE = 7227,		 // 七日封神积分
	ENTITY_PROP_QIRI_FENGSHEN_DAYS = 7228,		 // 七日封神第几日
	ENTITY_PROP_QIRI_FENGSHEN_BEGIN_TIEM = 7229, // 七日封神开始时间
	ENTITY_PROP_QIRI_FENGSHEN_END_TIEM = 7230,	 // 七日封神结束时间

	ENTITY_PROP_GONGLUE_READ_1 = 7231,	  // 攻略1是否已阅读
	ENTITY_PROP_GONGLUE_READ_2 = 7232,	  // 攻略2是否已阅读
	ENTITY_PROP_GONGLUE_READ_3 = 7233,	  // 攻略3是否已阅读
	ENTITY_PROP_GONGLUE_READ_4 = 7234,	  // 攻略4是否已阅读
	ENTITY_PROP_GONGLUE_READ_5 = 7235,	  // 攻略5是否已阅读
	ENTITY_PROP_GONGLUE_GET_AWARD = 7236, // 是否已领取阅读攻略的奖励

	ENTITY_PROP_GUANFANGDAYI_READ_1 = 7237,	   // 官方答疑1是否已阅读
	ENTITY_PROP_GUANFANGDAYI_READ_2 = 7238,	   // 官方答疑2是否已阅读
	ENTITY_PROP_GUANFANGDAYI_READ_3 = 7239,	   // 官方答疑3是否已阅读
	ENTITY_PROP_GUANFANGDAYI_READ_4 = 7240,	   // 官方答疑4是否已阅读
	ENTITY_PROP_GUANFANGDAYI_READ_5 = 7241,	   // 官方答疑5是否已阅读
	ENTITY_PROP_GUANFANGDAYI_GET_AWARD = 7242, // 是否已领取阅读官方答疑的奖励

	ENTITY_PROP_FPZN_GET_AWARD = 7245,		  // 防骗指南奖励是否领取
	ENTITY_PROP_QIRI_FENGSHEN_IS_OPEN = 7246, // 七日封神是否进行中

	ENTITY_PROP_ASK_BLACK_MARKET_STATE = 7250,	  // 打听和寻找黑市商人的进度
	ENTITY_PROP_IS_READ_GMD_NOTIFY = 7251,		  // 是否已弹出光明顶通知
	ENTITY_PROP_LAST_READ_GMD_NOTIFY_TIME = 7252, // 上次弹出光明顶通知的时间

	ENTITY_PROP_LINGWEN_SHOW_ID = 7253,

	ENTITY_PROP_IS_CHANGE_JOB = 7254,  // 是否转过职
	ENTITY_PROP_IS_SEEN_WEIXIN = 7255, // 是否浏览过微信福利

	ENTITY_PROP_TUOGUAN_BEGIN = 7271,
	ENTITY_PROP_TUOGUAN_MAP = 7271,					 // 托管地图
	ENTITY_PROP_TUOGUAN_TIME = 7272,				 // 托管特权结束时间
	ENTITY_PROP_TUOGUAN_STATE = 7273,				 // 托管状态
	ENTITY_PROP_TUOGUAN_KILL_MONSTER_NUM = 7274,	 // 杀怪数量
	ENTITY_PROP_TUOGUAN_DEATH_NUM = 7275,			 // 死亡次数
	ENTITY_PROP_TUOGUAN_EXP_TOTAL = 7276,			 // 累计获得的经验
	ENTITY_PROP_TUOGUAN_EXP_TOTAL_HIGH = 7277,		 // 累计获得的经验高位
	ENTITY_PROP_TUOGUAN_INGOT_TOTAL = 7278,			 // 累计获得的元宝
	ENTITY_PROP_TUOGUAN_START_TIME = 7279,			 // 开始时间
	ENTITY_PROP_TUOGUAN_DEATH_NUM_BY_MONSTOR = 7280, // 托管期间同一地图被怪物击杀次数
	ENTITY_PROP_TUOGUAN_LAST_MAP = 7281,			 // 上次进入的挂机地图
	ENTITY_PROP_TUOGUAN_OFFLINE = 7282,				 // 0 真实离线，1在线
	ENTITY_PROP_TUOGUAN_LEFT_TIME = 7283,			 // 托管剩余时间
	ENTITY_PROP_TUOGUAN_USE_TIME = 7284,			 // 离线托管时间
	ENTITY_PROP_TUOGUAN_END = 7284,
	ENTITY_PROP_TUOGUAN_MAX = 7299,

	//---------------------回收的相关设置-----------------------------
	ENTITY_PROP_RECYCLE_PUTONG_START = 7300,
	//////////////中间不要插
	ENTITY_PROP_RECYCLE_AUTO = 7458,
	ENTITY_PROP_RECYCLE_LINGSHI_END = 7459,
	//---------------------火祭的相关设置-----------------------------
	ENTITY_PROP_HUOJI_START = 7460,
	//////////////中间不要插
	ENTITY_PROP_AUTO_HUOJI = 7559,
	ENTITY_PROP_HUOJI_END = 7560,

	ENTITY_PROP_AUTO_USE_INGOT = 7561, // 自动使用经验元宝道具
	ENTITY_PROP_ACTIVITY_JBP = 7562,   // 内置活动聚宝盆
	ENTITY_PROP_HOLIDAY_JBP = 7563,	   // 运营活动聚宝盆
	ENTITY_PROP_ACTIVITY_MLGJ = 7564,  // 内置活动猛龙过江
	ENTITY_PROP_HOLIDAY_MLGJ = 7565,   // 运营活动猛龙过江

	// 生肖装备合成失败次数
	ENTITY_PROP_SX_HC_FAILED_COUNT_BEGIN = 7600,
	// 中间不要插
	ENTITY_PROP_SX_HC_FAILED_COUNT_END = 7720,

	// 逆天改命 2023.6.14 7721-7750
	ENTITY_PROP_NTGM_DOULI_ACTIVIE = 7721,	 // 逆天改命斗笠激活
	ENTITY_PROP_NTGM_HUNDUN_ACTIVIE = 7722,	 // 逆天改命护盾激活
	ENTITY_PROP_NTGM_YUPEI_ACTIVIE = 7723,	 // 逆天改命玉佩激活
	ENTITY_PROP_NTGM_LONGHUN_ACTIVIE = 7724, // 逆天改命龙魂激活

	ENTITY_PROP_NTGM_DOULI_LEVEL = 7731,   // 逆天改命斗笠等级
	ENTITY_PROP_NTGM_HUNDUN_LEVEL = 7732,  // 逆天改命护盾等级
	ENTITY_PROP_NTGM_YUPEI_LEVEL = 7733,   // 逆天改命玉佩等级
	ENTITY_PROP_NTGM_LONGHUN_LEVEL = 7734, // 逆天改命龙魂等级

	ENTITY_PROP_NTGM_DOULI_SCORE = 7741,   // 逆天改命斗笠积分
	ENTITY_PROP_NTGM_HUNDUN_SCORE = 7742,  // 逆天改命护盾积分
	ENTITY_PROP_NTGM_YUPEI_SCORE = 7743,   // 逆天改命玉佩积分
	ENTITY_PROP_NTGM_LONGHUN_SCORE = 7744, // 逆天改命龙魂积分
	// 逆天改命end
	// 勋章 2023.6.21
	ENTITY_PROP_XUNZHANG_ACTIVIE = 7751, // 勋章激活
	ENTITY_PROP_XUNZHANG_LEVEL = 7752,	 // 勋章等级
	ENTITY_PROP_XUNZHANG_SCORE = 7753,	 // 勋章积分
	ENTITY_PROP_CHUMO_SCORE = 7754,		 // 除魔积分（功勋值）
	ENTITY_PROP_CHUMO_HEAD = 7755,		 // 除魔称号等级
	// 勋章end

	ENTITY_PROP_SKILL_SCORE = 7760,   // 技能点

	//---------------------自动合成的相关设置-----------------------------
	ENTITY_PROP_AUTO_HC_START = 7800,
	//////////////中间不要插
	ENTITY_PROP_AUTO_HC = 7899,
	ENTITY_PROP_AUTO_HC_END = 7900,

	//---------------------自动使用道具的相关设置-----------------------------
	ENTITY_PROP_AUTO_USE_ITEM_START = 7901,
	//////////////中间不要插
	ENTITY_PROP_AUTO_USE_ITEM_END = 7910,
	ENTITY_PROP_AUTO_USE_ITEM = 7911,
	
	//---------------------战队-----------------------------
	ENTITY_PROP_ZHANDUI_QUIT_TIME = 8001,		  // 退出战队时间

	// 攻击时间检测
	ENTITY_PROP_LAST_USING_TIME_EX = 9000, // 高位MAX
	ENTITY_PROP_LAST_USING_TIME = 9001,	   // 低位MAX
	ENTITY_PROP_ATTACK_PO_FANG = 9002,	   // 攻击破防（此次攻击对方防御以为0）

	ENTITY_PROP_SKILL_FREE_RESET_USED = 9003,	  // 技能免费重置
	ENTITY_PROP_CREATE_RECYCLE_RES_TIME = 9004,	  // 记录创建资源找回的时间
	ENTITY_PROP_TREASURE_BAODI_COUNT = 9005,	  // 寻宝保底次数
	ENTITY_PROP_ROLE_SKILL_FILTER_IDX = 9006,	  // 心仪技能类型
	ENTITY_PROP_MENTAL_MULTI_THUNDER = 9007,	  // 多重释法
	ENTITY_PROP_MENTAL_KJHH = 9008,				  // 抗拒火环
	ENTITY_PROP_LUCKY_COMPASS_BAODI_COUNT = 9009, // 神运罗盘保底次数
	ENTITY_PROP_LUCKY_SCORE = 9010,				  // 神运值（神运罗盘活动）

	ENTITY_PROP_ATTACK_SKILL_PO_FANG = 9011,  // 技能 直接破防 与 数值无关
	ENTITY_PROP_TOTAL_RECHARGE_REWARD = 9013, // 累充送礼领取记录

	ENTITY_PROP_TULONGDAO_DOUBLE_FIRE = 9014,	 // 屠龙刀双烈火
	ENTITY_PROP_RELIVE_COUNTS_ADD_BY_PET = 9015, // 萌宠增加的复活次数

	ENTITY_PROP_NEW_VERSION_RECHARGE_REWARD = 9016, // 新版本充值奖励

	ENTITY_PROP_DEICIDE_SUIT_3 = 9017, // 弑神装备3件套
	ENTITY_PROP_DEICIDE_SUIT_5 = 9018, // 弑神装备5件套
	ENTITY_PROP_DEICIDE_SUIT_8 = 9019, // 弑神装备8件套
	ENTITY_PROP_SKILL_STAR = 9020,	   // 技能星星

	ENTITY_PROP_SCENE_ID = 9021,			 // 地图编号
	ENTITY_PROP_NEW_SINGN_FIRST_DAY = 9022,	 // 新版签到首日
	ENTITY_PROP_RECHARGE_RECORD = 9023,		 // 充值记录
	ENTITY_PROP_TEQUAN_CHANGE_REWARD = 9024, // 2022.4新版本特权奖励发还

	ENTITY_PROP_LAST_GENDER_TIME = 9025,		 // 最后一次改性别的时间
	ENTITY_PROP_SHACHENG_DONATION_TIME = 9026,	 // 沙城捐献时间
	ENTITY_PROP_GUILD_BUFF_STRENGTH_TIME = 9029, // 行会强化buff开始时间

	// 透视 9030 ~ 9040
	ENTITY_PROP_TOUSHI_LV = 9030,	// 透视等级
	ENTITY_PROP_TOUSHI_CD = 9031,	// 透视属性
	ENTITY_PROP_TOUSHI_USED = 9032, // 是否透视过
	ENTITY_PROP_TOUSHI_TIME = 9033, // 透视属性

	ENTITY_PROP_GUILD_TOKEN_LV = 9050,	  // 令牌等级
	ENTITY_PROP_GUILD_BLESS_VALUE = 9051, // 祝福值
	ENTITY_PROP_JINLONG_END_TIME = 9052,  // 金龙体验结束时间

	ENTITY_PROP_GCZ_SCORE = 9900,		  // 攻城战个人积分
	ENTITY_PROP_GCZ_REWARD_RECORD = 9901, // 攻城战个人积分奖励领取记录

	ENTITY_PROP_GUILD_BATTLE_SCORE = 9902, // 行会对战个人积分
	ENTITY_PROP_GUILD_BATTLE_FLAG = 9903,  // 行会对战个人战旗数

	ENTITY_PROP_YZBQ_REWARD_RECORD = 9905,	  // 夜战比奇个人积分奖励领取记录
	ENTITY_PROP_GID_TO_SDK = 9906,			  // 加入公会上报sdk公会id
	ENTITY_PROP_ROBOT = 9907,				  // 机器人
	ENTITY_PROP_ROBOT_IDLE_START_TIME = 9908, // 机器人进入idle状态开始时间
	ENTITY_PROP_ROBOT_PATROL = 9909,		  // 机器人巡逻寻路序号

	ENTITY_PROP_SERVER_ID = 9910, // 原始服务器ID

	ENTITY_PROP_SHENGXIAO_SUIT_ID = 9911, // 生肖套装id
	ENTITY_PROP_REBORN_TIME = 9912,		  // 转生等级升级时间

	ENTITY_PROP_SC_BOSS_DAMAGE = 9913, // 沙城boss伤害
	ENTITY_PROP_HG_BOSS_DAMAGE = 9914, // 皇宫boss伤害

	ENTITY_PROP_YBHS_DOUBLE = 9915, // 元宝回收双倍特权

	ENTITY_PROP_ZHUZAO_COUNT = 9916,			 // 铸造次数记录
	ENTITY_PROP_RELIVE_COUNTS_ADD_BY_VIP = 9917, // vip增加的复活次数
	ENTITY_PROP_ZSD_EXTRA_COUNTS = 9918,		 // 转生丹额外增加次数
	ENTITY_PROP_NOT_FIRST_LOGIN = 9919,			 // 是否非第一次登陆(0: 第一次登录， 1: 不是)

	ENTITY_PROP_ZHUZAO_BEST_COUNT = 9920,		 // 铸造大奖次数记录
	ENTITY_PROP_ENTER_SCENE_FLAG = 9921,		 // 进入场景标记

	ENTITY_PROP_ARTIFACT_SUIT_GENE_12 = 9930, // 小极品 神器12件套套装基因
	ENTITY_PROP_HUN_QI_ADD_HP_TIME = 9931,	  // 小极品 魂器 3阶4件套套装效果

	ENTITY_PROP_TEJIE_MABI					= 9932,
	ENTITY_PROP_TEJIE_FUHUO					= 9933,
	ENTITY_PROP_TEJIE_HUSHEN				= 9934,

	ENTITY_PROP_HUNLING_SUIT_6_LEVLE		= 9935,
	ENTITY_PROP_HUNLING_SUIT_12_LEVLE		= 9936,
	ENTITY_PROP_SHENQI_SUIT_6_LEVLE			= 9937,
	ENTITY_PROP_SHENQI_SUIT_12_LEVLE		= 9938,

	ENTITY_PROP_EQUIP_ENHANCE_LV_BEGIN 			= 9940,
	ENTITY_PROP_EQUIP_ENHANCE_LV_END 			= 9950,

	ENTITY_PROP_PROP_PLAYER_END = 9999, // 未用

	ENTITY_PROP_COMPOSE_FAIL_RECORD_START = 20000, // 合成系统失败记录开始
	ENTITY_PROP_COMPOSE_FAIL_RECORD_END = 29999,   // 合成系统失败记录结束
};

// 玩家的设置属性
enum EntitySettingProp
{
	ENTITY_SET_BEGIN = 10000, // 设置开始

	ENTITY_SET_INIT = 10000, // 设置是否初始化

	// ---------------------------------------游戏基础设置---------------------------------------------
	ENTITY_SET_REFUSE_ADD_FRIEND = 10003,	// 拒绝好友申请
	ENTITY_SET_REFUSE_PRIVATE_CHAT = 10004, // 拒绝私聊消息
	ENTITY_SET_REFUSE_GUILD_INVITE = 10005, // 拒绝公会邀请

	// -----------------------------------------战斗设置-----------------------------------------------
	ENTITY_SET_AUTO_USE_STONE_HP_VAL = 10011, // 自动使用石头HP限制
	ENTITY_SET_AUTO_USE_ADD_HP_DRUG = 10012,  // 自动使用回血药
	ENTITY_SET_AUTO_USE_STONE_TYPE = 10013,	  // 自动使用 0-回城石 1-随机石
	ENTITY_SET_AUTO_USE_ADD_MP_DRUG = 10014,  // 自动使用回蓝药
	ENTITY_SET_VIEW_ZOOM_RATIO = 10039,		  // 视野缩放倍率
	ENTITY_SET_SIMPLIFY_MONSTER = 10040,	  // 是否把怪物简化成稻草人

	// ------------------------------------------拾取设置-----------------------------------------------
	ENTITY_SET_AUTOPICK_SWITCH = 10500, // 自动拾取总开关

	//-----------------------------------------自动战斗设置---------------------------------------------
	ENTITY_SET_AUTO_FIGHT_BEGIN = 13351,	  // 战斗设置开始
	ENTITY_SET_COMMON_CONTINUE_FIGHT = 13352, // 持续攻击
	ENTITY_SET_ZS_AUTO_BYWD = 13353,		  // 智能半月
	ENTITY_SET_ZS_AUTO_ZRJF = 13354,		  // 自动逐日
	ENTITY_SET_ZS_AUTO_LHJF = 13355,		  // 自动烈火
	ENTITY_SET_ZS_AUTO_KTZ = 13356,			  // 自动开天斩
	ENTITY_SET_ZS_AUTO_SZH = 13357,			  // 自动狮子吼
	ENTITY_SET_ZS_AUTO_QLS = 13358,			  // 自动擒龙手
	ENTITY_SET_FS_AUTO_MFD = 13359,			  // 自动魔法盾
	ENTITY_SET_FS_AUTO_HBZ = 13360,			  // 自动寒冰掌
	ENTITY_SET_FS_AUTO_MTH = 13361,			  // 自动灭天火
	ENTITY_SET_FS_AUTO_FSS = 13362,			  // 自动分身术
	ENTITY_SET_FS_AUTO_KLZD = 13363,		  // 自动魔狂龙紫电
	ENTITY_SET_DS_AUTO_SDS = 13364,			  // 自动施毒术
	ENTITY_SET_DS_AUTO_YLD = 13365,			  // 自动幽灵盾
	ENTITY_SET_DS_AUTO_ZJS = 13366,			  // 自动神圣战甲术
	ENTITY_SET_DS_AUTO_WJZQ = 13367,		  // 自动无极真气
	ENTITY_SET_ZS_AUTO_CSJF = 13368,		  // 自动刺杀剑法
	ENTITY_SET_FS_AUTO_LDS = 13369,			  // 自动雷电术
	ENTITY_SET_DS_AUTO_LHHF = 13370,		  // 自动灵魂火符
	ENTITY_SET_SINGLE_SKILL = 13380,		  // 单体技能
	ENTITY_SET_AOE_SKILL = 13381,			  // 群体技能
	ENTITY_SET_CALL_SKILL = 13382,			  // 召唤术技能
	ENTITY_SET_FS_AUTO_LXHY = 13384,		  // 自动流星火雨
	ENTITY_SET_DS_AUTO_SXS  = 13385,		  // 自动嗜血术
	ENTITY_SET_DS_AUTO_YLMJ = 13386,		  // 自动幽灵魔甲
	ENTITY_SET_ZS_GW_CSJF = 13387,		      // 隔位刺杀
	ENTITY_SET_ZS_JS_LHJF = 13388,		      // 近身烈火
	ENTITY_SET_AUTO_FIGHT_END = 13451,		  // 战斗设置结束

	//-----------------------------------------公会boss订阅设置---------------------------------------------
	ENTITY_SET_GUILD_BOSS_ORDER_START = 13452, // 公会Boss订阅开始
	ENTITY_SET_GUILD_BOSS_ORDER_END = 13471,   // 公会Boss订阅结束

	ENTITY_SET_SUPER_BOSS_ORDER_START = 13472,	// 超级Boss订阅开始
	ENTITY_SET_SUPER_BOSS_ORDER_END = 13480,	// 超级Boss订阅结束
	ENTITY_SET_SUPER_CLONE_ORDER_START = 13481, // 超级Boss幻象订阅开始
	ENTITY_SET_SUPER_CLONE_ORDER_END = 13490,	// 超级Boss幻象订阅结束

	ENTITY_SET_END = 14000, // 设置结束
};

enum EntityHeroProp
{
	ENTITY_PROP_HERO_BEGIN = 2999,

	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/
	ENTITY_HERO_PROP_SYNC_BEGIN = 3000,
	ENTITY_PROP_HERO_ATTACK_MODEL = 3401,		// 攻击模式
	ENTITY_PROP_HERO_AGGRO_ADD,					// 攻击目标，目标对自己的仇恨的仇恨系数
	ENTITY_PROP_HERO_DEF_ADD,					// 防御增加系数
	ENTITY_PROP_HERO_ATTACK_ADD,				// 攻击力增加系数
	ENTITY_PROP_HERO_SKILL = 3405,				// 玩家记录打开关闭保存
	ENTITY_PROP_HERO_DEFAULT_SKILL = 3406,		// 英雄默认技能
	ENTITY_PROP_HERO_NEXT_SPECIAL_SKILL = 3408, // 英雄 下一个使用的特殊技能
	ENTITY_PROP_HERO_MERIDIAN_LV = 3409,		// 英雄经脉等级
	ENTITY_PROP_HERO_VITAL_QI_FAIL = 3411,		// 英雄失败真气
	ENTITY_PROP_HERO_REBORN_CONV_CNT = 3412,	// 英雄 转生次数
	ENTITY_PROP_HERO_REBORN_CONV_DAY = 3413,	// 英雄 转生天书

	ENTITY_PROP_HERO_MIND_PRACTICE_LEVEL = 3415, // 英雄灵魂刻印等级
	ENTITY_PROP_HERO_MIND_PRACTICE_VALUE = 3416, // 英雄灵魂刻印当前等级的刻印值
	ENTITY_PROP_HERO_STATE = 3417,				 // 出战待命
	ENTITY_PROP_HERO_CURE_OBJECT = 3418,		 // 英雄释放恢复术  释放位置

	ENTITY_PROP_HERO_DEAD_FLAG = 3419,	  // 英雄是否因为上线时玩家死亡而导致的死亡0表示否，非0表示是
	ENTITY_PROP_HERO_EXE_DEFEND = 3422,	  // 英雄内功防御
	ENTITY_PROP_HERO_CD_MIND = 3423,	  // 英雄5%概率攻击时减少合击CD
	ENTITY_PROP_HERO_CAN_AUTOMOVE = 3424, // 英雄被攻击一定概率位移

	ENTITY_HERO_PROP_SYNC_END = 5000, // 游戏服需要实时同步给跨服的属性
	/**********************************************************************************************/
	/***********************游戏服需要实时同步给跨服的属性 END***********************************/
	/**********************************************************************************************/

	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 BEGIN***********************************/
	/**********************************************************************************************/
	ENTITY_HERO_PROP_INIT_CROSS_BEGIN = 6001,
	ENTITY_PROP_HERO_DEAD_TIME = 6002, // 英雄死亡时间

	ENTITY_PROP_HERO_NEXT_CAST_SKILL = 6003, // 英雄 下一个使用的技能

	ENTITY_HERO_PROP_INIT_CROSS_END = 6100,
	/**********************************************************************************************/
	/***********************进入跨服时用于初始化跨服对象的属性 END***********************************/
	/**********************************************************************************************/

	ENTITY_PROP_HERO_END = 9999, // 未用
};

enum EntityHeroAttackModel
{
	EntityHeroAttackModelNormal = 1,	 // 强攻
	EntityHeroAttackModelDefMonster = 2, // 抗怪
};

enum EntityItemProp
{
	ENTITY_PROP_ITEM_BEGIN = 2100,			 // 物品属性开始, 未用
	ENTITY_PROP_ITEM_COUNT = 2200,			 // 物品堆叠数
	ENTITY_PROP_ITEM_LAST_OWNER = 2201,		 // 物品是谁丢弃的
	ENTITY_PROP_ITEM_LIMIT_PICK = 2202,		 // 物品限制拾取
	ENTITY_PROP_ITEM_MONSTER_SID = 2203,	 // 物品是哪个怪物掉的
	ENTITY_PROP_ITEM_TIME_LIMIT_PICK = 2204, // 物品禁止拾取时间
	ENTITY_PROP_ITEM_TYPE = 2256,			 // 物品类型
	ENTITY_PROP_ITEM_CATE = 2257,			 // 物品分类

	ENTITY_PROP_ITEM_PROP_BEGIN = 2300, // 物品扩展属性开始(记录ItemProp)
	// don't put any thing in 300 - 400
	ENTITY_PROP_ITEM_PROP_END = 2400, // 物品扩展属性结束

	ENTITY_PROP_ITEM_OWNER_PID1 = 2801,	 // 归属玩家ID第一个
	ENTITY_PROP_ITEM_OWNER_PID15 = 2815, // 归属玩家ID最后一个

	ENTITY_PROP_ITEM_END = 9999, // 物品属性结束, 未用
};

enum EntityMarketProp
{
	ENTITY_PROP_MARKET_BEGIN = 2000,  // 未用
	ENTITY_PROP_MARKET_REBORN = 2001, // 玩家转生
	ENTITY_PROP_MARKET_LEVEL = 2002,  // 玩家等级
	ENTITY_PROP_MARKET_COMBAT = 2003, // 战力
	ENTITY_PROP_MARKET_CLASS = 2004,  // 玩家等级
	ENTITY_PROP_MARKET_GENDER = 2005, // 战力
	ENTITY_PROP_MARKET_SLOGAN = 2006, // 广告语(字符串)

	ENTITY_PROP_MARKET_BEGIN_TIME = 2200, // 摆摊开始时间
	ENTITY_PROP_MARKET_END_TIME = 2201,	  // 摆摊结束时间
	ENTITY_PROP_MARKET_MAX_SLOT = 2202,
	ENTITY_PROP_MARKET_SELL_COIN = 2250,
	ENTITY_PROP_MARKET_SELL_INGOT = 2251,
	ENTITY_PROP_MARKET_IS_HIGH = 2260,
	ENTITY_PROP_MARKET_END = 3000, // 未用
};

// 宠物，道士狗，分身，战神属性
enum EntityPetDogMarsProp
{
	ENTITY_PROP_PET_BEGIN = 2000, // 未用

	ENTITY_PROP_PET_SPEED = 2001,

	// 2002为经验值属性，不要占用added by luoshen
	// 本应为重新定义，或者放在entity里面但是为了省事就做了此处理
	// ENTITY_PROP_EXP				= 2002,		// 经验(低32位)

	ENTITY_PROP_PET_STATE = 2200,
	ENTITY_PROP_PET_LIFE_POINT = 2202,
	ENTITY_PROP_PET_EX_PROP_TYPE = 2203,
	ENTITY_PROP_PET_EX_PROP_ONE = 2204,
	ENTITY_PROP_PET_EX_PROP_TWO = 2205,
	ENTITY_PROP_PET_EX_PROP_THREE = 2206,
	ENTITY_PROP_PET_TOP_PROP_TYPE = 2207,
	ENTITY_PROP_PET_TOP_PROP = 2208,
	ENTITY_PROP_PET_REACH_TEN = 2209,
	ENTITY_PROP_PET_STAR_LEVEL = 2210, // 宠物星级
	ENTITY_PROP_PET_REBORN = 2211,	   // 宠物转生
	ENTITY_PROP_PET_DEAD_TIME = 2212,  // 宠物上次阵亡时间

	ENTITY_PROP_PET_MARKET_TIME = 2310,
	ENTITY_PROP_PET_OFFLINE_TIME = 2311,
	ENTITY_PROP_DS_SUMMON_TYPE = 2312,

	ENTITY_PROP_DOG_ATK_CD = 2400,	// 攻击时间 10s
	ENTITY_PROP_MARS_ATK_CD = 2400, // 攻击时间 10s

	ENTITY_PROP_PET_END = 9999, // 未用
};

enum EntityMonsterProp
{
	ENTITY_PROP_MONSTER_BEGIN = 2000,		// 未用
	ENTITY_PROP_MONSTER_TIME_TO_OWN = 2101, // 归属清除时间(毫秒)

	ENTITY_PROP_MONSTER_LAST_PATROL_X = 2210,
	ENTITY_PROP_MONSTER_LAST_PATROL_Y = 2211,

	ENTITY_PROP_MONSTER_DROPNOOWNER = 2213, // 额外设定的无归属怪物

	ENTITY_PROP_MONSTER_NOT_DOG_QUTO_ATTACK = 2215, // 是否不被dog自动攻击

	ENTITY_PROP_MONSTER_REWARD_EXP_HERO = 2229, // 杀死怪物奖励-经验-英雄
	ENTITY_PROP_MONSTER_REWARD_EXP = 2230,		// 杀死怪物奖励-经验
	ENTITY_PROP_MONSTER_REWARD_ID = 2231,		// 杀死怪物奖励-掉落ID
	ENTITY_PROP_MONSTER_REWARD_BSSC = 2232,		// 杀死怪物奖励-BOSS积分

	ENTITY_PROP_MONSTER_DEFAULT_SKILL = 2310, // 怪物默认技能
	ENTITY_PROP_MONSTER_DEFAULT_SKILL_DISTANCE = 2311,

	ENTITY_PROP_MONSTER_HAS_SKILL = 2350,
	ENTITY_PROP_MONSTER_HAS_EVENT = 2351,

	ENTITY_PROP_MONSTER_NEXT_CAST_SKILL = 2400,
	ENTITY_PROP_MONSTER_NEXT_CAST_SKILL_DISTANCE = 2401,

	ENTITY_PROP_MONSTER_SKILL_DYDATA_BEGIN = 2500,
	ENTITY_PROP_MONSTER_SKILL_DYDATA_END = 2520,

	ENTITY_PROP_MONSTER_BOSS_WID = 2550,		  // BOSS怪物ID, 应该和getStaticID()相同
	ENTITY_PROP_MONSTER_OWNER_PID = 2551,		  // 归属玩家ID
	ENTITY_PROP_MONSTER_OWNER_NAME = 2552,		  // 归属玩家名称
	ENTITY_PROP_MONSTER_OWNER_CLASS = 2553,		  // 归属玩家职业
	ENTITY_PROP_MONSTER_OWNER_GENDER = 2554,	  // 归属玩家性别
	ENTITY_PROP_MONSTER_OWNER_SERVER_ID = 2555,	  // 归属玩家服务器id
	ENTITY_PROP_MONSTER_OWNER_SREVER_NAME = 2556, // 归属玩家服务器名称
	ENTITY_PROP_MONSTER_IS_PLANT = 2560,		  // 是否可被采集
	ENTITY_PROP_MONSTER_IS_BOSS = 2561,			  // 是否是BOSS
	ENTITY_PROP_MONSTER_HOST_NAME = 2562,		  // 宿主的名字
	ENTITY_PROP_MONSTER_IS_DART = 2563,			  // 是否是镖车
	ENTITY_PROP_MONSTER_OWNER_TEAM_ID = 2564,	  // 归属玩家队伍id
	ENTITY_PROP_MONSTER_OWNER_GUILD_ID = 2565,	  // 归属玩家工会id
	ENTITY_PROP_MONSTER_OWNER_CAMP_ID = 2566,	  // 归属玩家阵营id
	ENTITY_PROP_MONSTER_BOSS_TYPE = 2568,		  // 怪物类型

	ENTITY_PROP_MONSTER_SKILL_DAMAGE = 2710,
	ENTITY_PROP_MONSTER_GUILD_NAME = 2730,

	ENTITY_PROP_MONSTER_SCENE_INDEX = 2731,
	ENTITY_PROP_MONSTER_HAVE_BOX = 2732,
	ENTITY_PROP_MONSTER_INDEX = 2733,

	ENTITY_PROP_UN_GODWEAPON_EFFECT = 2734, // 免疫神器特效
	ENTITY_PROP_MONSTER_WORLD_INDEX = 2735, // 世界boss的顺序

	ENTITY_PROP_MONSTER_DREAM_INDEX = 2736, // 试炼幻境怪物索引

	ENTITY_PROP_MONSTER_TOUSHI_ITEMLIST = 2800, // 透视 物品掉落

	ENTITY_PROP_MONSTER_USE_LHP = 3000, // LHP
	ENTITY_PROP_MONSTER_END = 9999,		// 未用
};

enum EntityMonsterGroupProp
{
	ENTITY_PROP_MG_BEGIN = 2000,			  // 未用
	ENTITY_PROP_MG_REFRESH_INTERVAL = 2200,	  // 刷怪间隔
	ENTITY_PROP_MG_REFRESH_RANGE = 2201,	  // 刷怪范围
	ENTITY_PROP_MG_REFRESH_WAVE = 2204,		  // 刷怪波数
	ENTITY_PROP_MG_REFRESH_TYPE = 2205,		  // 刷怪方式
	ENTITY_PROP_MG_MONSTER_TYPE_COUNT = 2206, // 怪物种类数量
	ENTITY_PROP_MG_ENDLESS_STATE = 2207,
	ENTITY_PROP_MG_WORLD_ID = 2208,	  // 定时刷新worldid
	ENTITY_PROP_MG_RANDOM_POS = 2209, // 是否是全图随机位置（0：否 1：是）

	ENTITY_PROP_MG_REFRESH_SID_BEGIN = 2230, // 怪物sid
	ENTITY_PROP_MG_REFRESH_SID_END = 2250,
	ENTITY_PROP_MG_REFRESH_COUNT_BEGIN = 2250, // 单次刷怪最大数量
	ENTITY_PROP_MG_REFRESH_COUNT_END = 2270,
	ENTITY_PROP_MG_REFRESH_LIMIT_BEGIN = 2270, // 怪物数量上限
	ENTITY_PROP_MG_REFRESH_LIMIT_END = 2290,

	ENTITY_PROP_MG_AROUND_PLAYER_COUNT = 2330,

	ENTITY_PROP_MG_END = 9999, // 未用
};

enum EntitySkillProp
{
	ENTITY_PROP_SKILL_BEGIN = 2000, // 未用

	ENTITY_PROP_SKILL_SCRIPT_DURATION = 2201,
	ENTITY_PROP_SKILL_NEED_SYNC = 2202,
	ENTITY_PROP_SKILL_PROCESS_CLASS = 2203,
	ENTITY_PROP_SKILL_GROUP_ID = 2204,
	ENTITY_PROP_SKILL_SYNC_ACT = 2205,
	ENTITY_PROP_SKILL_IGNORE_BLOCK = 2207,
	ENTITY_PROP_SKILL_EX_DATA = 2220,
	ENTITY_PROP_SKILL_GENE_FLAG = 2221,

	ENTITY_PROP_SKILL_END = 9999, // 未用
};

enum EntityNPCProp
{
	ENTITY_PROP_NPC_GET_EXDATA = 2300,	 // 未用
	ENTITY_PROP_NPC_CLOTH = 2301,		 // 服装
	ENTITY_PROP_NPC_WEAPON = 2302,		 // 武器
	ENTITY_PROP_NPC_WINGS = 2303,		 // 翅膀
	ENTITY_PROP_NPC_PID = 2304,			 // 未用
	ENTITY_PROP_NPC_GENDER = 2305,		 // 性别
	ENTITY_PROP_NPC_REBORN_LEVEL = 2306, // 转生等级
	ENTITY_PROP_NPC_JOB = 2307,			 // 职业
	ENTITY_PROP_NPC_DIE = 2308,			 // npc死亡
	ENTITY_PROP_NPC_OPEN_TIME = 2309,	 // 采集完成的时间
	ENTITY_PROP_NPC_BOSS_ID = 2310,		 // 对应的boss id
	ENTITY_PROP_NPC_BOSS_STR = 2311,	 // 对应的时间戳+bossid
	ENTITY_PROP_NPC_OWNER_PID = 2312,	 // 正在采集的PID
	ENTITY_PROP_NPC_ALIVE_TIME = 2313,	 // 宝箱倒计时
	ENTITY_PROP_NPC_MAP_INSTANCE = 2314, // npc对应的地图唯一id
	ENTITY_PROP_NPC_BOOK_ID = 2315,		 // 图鉴npcid
	ENTITY_PROP_NPC_RECORD_STR = 2400,	 // 未用
};

// 宠物状态
enum PetState
{
	PET_STATE_SLEEP = 0,	// 休息
	PET_STATE_ON = 1,		// 出战
	PET_STATE_DEAD = 2,		// 死亡
	PET_STATE_MARKET = 3,	// 摆摊
	PET_STATE_IMPRISON = 4, // 封印
};

// 宠物喂养类型
enum PetFeedType
{
	// PET_FEED_HONOR = 1,         // 荣誉喂养
	PET_FEED_INGOT = 2,		  // 元宝喂养
	PET_FEED_SUPER_INGOT = 3, // 超级喂养
	PET_FEED_XIANG_QUAN = 4,  // 项圈喂养
};

// 怪物攻击类型
enum MonsterMode
{
	MONSTER_MODE_AGGRESSIVE = 0,			   // 主动 attack aggressive
	MONSTER_MODE_PASSIVE = 1,				   // 被动 attack passive
	MONSTER_MODE_RUNAWAY = 2,				   // 逃跑 run away when under attack
	MONSTER_MODE_STATIC = 3,				   // 静止 stand static, no move, no attack
	MONSTER_MODE_HOLD = 4,					   // 防守 stand and hold, no move, but attack
	MONSTER_MODE_MERCS = 5,					   // 雇佣 following owner, attack aggressive
	MONSTER_MODE_GUARD = 6,					   // 保镖 following owner, attack passive
	MONSTER_MODE_FOLLOWING = 7,				   // 跟随 just following owner, no attack
	MONSTER_MODE_MARCHING = 8,				   // 被动前往 marching to target point, passive
	MONSTER_MODE_MARCHING_AGGRESSIVE = 9,	   // 主动前往 marching to target point, aggressive
	MONSTER_MODE_SELF_DESTROY = 10,			   // 被动自杀 cast a last skill when found and tracked to a target
	MONSTER_MODE_SELF_DESTROY_AGGRESSIVE = 11, // 主动自杀 cast a last skill when found and tracked to a target, aggressive
	MONSTER_MODE_SENTRY = 12,				   // 岗哨 stand and hold for bad player who kill player
	MONSTER_MODE_SENTRY_MOVE = 13,			   // 巡逻 move and search for bad player who kill player
	MONSTER_MODE_TOTEM = 14,				   // 图腾 attack when player nearby, useskill has cool down
	MONSTER_MODE_GIRL_MOVE = 15,			   // 护送 guild procect or princess procect
	MONSTER_MODE_SENTRY_HUNTING = 16,		   // 猎杀 hunting
	MONSTER_MODE_MARCHING_DISAPPEAR = 17,	   // 前往目的地后消失 marching to target point, then disappear
};

// 怪物类型
enum MonsterType
{
	MONSTER_TYPE_NORMAL = 1,	   // 普通怪
	MONSTER_TYPE_ELITE = 2,		   // 精英怪
	MONSTER_TYPE_NORMAL_BOSS = 3,  // 普通Boss
	MONSTER_TYPE_DOMINATE = 4,	   // 主宰
	MONSTER_TYPE_GUILD_BOSS = 8,   // 溶洞Boss
	MONSTER_TYPE_ANCIENT_BOSS = 9, // 远古Boss
	MONSTER_TYPE_SUPER_BOSS = 10,  // 超级Boss
	MONSTER_TYPE_BOOK_BOSS = 11,   // 图鉴Boss
};

enum PetMode
{
	PET_MODE_NORMAL,			// 进攻	attack aggressive
	PET_MODE_IN_MARKET,			// 摆摊
	PET_MODE_IN_MARKET_OFFLINE, // 离线摆摊
};

enum DogMode
{
	DOG_MODE_NORMAL,  // 进攻 attack
	DOG_MODE_DEFENSE, // 防守
};

// enum ChoriotMode
//{
//	CHARIOT_MODE_TRACE = 0,		    // 移动
//	CHARIOT_MODE_ATTACK = 1,		// 攻击
// };

// 实体所有者类型
enum OwnerType
{
	OWNER_TYPE_NONE,		  // 无归属
	OWNER_TYPE_SINGLE_PLAYER, // 单个玩家
	// OWNER_TYPE_TEAM,				//团队
	// OWNER_TYPE_GUILD,				//行会
	// OWNER_TYPE_FACTION,				//帮派
	OWNER_TYPE_SHOW_ONLY, // 展示,不归属任何人
};

enum DogOption
{
	DOG_OPTION_UPGRADE = 1,
	DOG_OPTION_CALL = 2,
	DOG_OPTION_DEFENSE = 3,
	DOG_OPTION_ATTACK = 4,
};

// 职业
enum ClassType
{
	CLASS_ALL = 0,	   // 所有职业
	CLASS_WARRIOR = 1, // 战士
	CLASS_MAGE = 2,	   // 法师
	CLASS_TAOIST = 3,  // 道士
};

// 性别
enum GenderType
{
	GENDER_MALE = 1,   // 男
	GENDER_FEMALE = 2, // 女
};

// 聊天频道
enum ChatType
{
	CHAT_TYPE_SYSTEM = 1,		// 系统
	CHAT_TYPE_WORLD = 2,		// 世界
	CHAT_TYPE_WARZONE = 3,		// 战区
	CHAT_TYPE_GROUP = 4,		//
	CHAT_TYPE_GUILD = 5,		// 行会
	CHAT_TYPE_PRIVATE = 6,		// 私聊
	CHAT_TYPE_HORN = 7,			// 喇叭
	CHAT_TYPE_GM = 8,			// GM
	CHAT_TYPE_REDPACKET = 9,	// 红包
	CHAT_TYPE_GUILDNOTICE = 10, // 公会公告
	CHAT_TYPE_NEAR = 11,		// 附近
};

// VIP特权
enum VipDesc
{
	VIP_HERO = 1,
	VIP_BOSS_HOME = 2,
	VIP_RELIVE = 3,
	VIP_GOLDUSE = 4,
	VIP_ATTACK_MIN = 5,
	VIP_ATTACK_MAX = 6,
	VIP_ATTACKBUFF = 7,
	VIP_EXPADDBUFF = 8,
	VIP_MRGJLHD = 9,  // 高级轮回丹
	VIP_MRCJLHD = 10, // 超级轮回丹
	VIP_GONGXUN = 11, // 功勋额外
};

// 物品使用的目标类型
enum ItemUseEntityType
{
	ItemUseEntityTypePlayer = 1,
	ItemUseEntityTypeHero = 2,
};

// 物品加载原因
enum ItemLoadReason
{
	ITEM_LOAD_REASON_PLAYER = 0,
	ITEM_LOAD_REASON_MARKET = 1,
};

// 物品分类
enum ItemCategory
{
	ITEM_CATEGORY_INVALID = 0,
	ITEM_CATEGORY_EQUIP = 1,		 // 装备	including equipment and precious
	ITEM_CATEGORY_STONE = 2,		 // 宝石
	ITEM_CATEGORY_EXTENSION = 3,	 // 功能扩展	including all kinds function items
	ITEM_CATEGORY_MATERIAL = 4,		 // 材料
	ITEM_CATEGORY_SPECIAL = 5,		 // 特殊
	ITEM_CATEGORY_MEDICINE = 6,		 // 药类
	ITEM_CATEGORY_GIFT = 7,			 // 礼包? 礼物，赠品
	ITEM_CATEGORY_PAPAER = 8,		 // 符文
	ITEM_CATEGORY_RUNE = 9,			 // 技能书
	ITEM_CATEGORY_MENGCHONG = 10,	 // 萌宠激活道具
	ITEM_CATEGORY_ELIXIR = 11,		 // 升级丹
	ITEM_CATEGORY_BBSKIN = 12,		 // 宝宝皮肤
	ITEM_CATEGORY_SPECIAL_RING = 13, // 特戒
	ITEM_CATEGORY_COUPON = 14,		 // 充值抵用券
	ITEM_CATEGORY_HORCRUXES = 15,	 // 魂器
	ITEM_CATEGORY_DRESS = 16,		 // 装扮
	ITEM_CATEGORY_HOLIDAY = 17,		 // 节日物品
	ITEM_CATEGORY_MAX,
};

// 物品类型
enum ItemType
{
	ITEM_TYPE_NULL = 0,

	// 装备目录道具类型
	// ITEM_CATEGORY_EQUIP
	ITEM_TYPE_EQUIP_START = 0,
	ITEM_TYPE_EQUIP_WEAPON = 1,		   // 武器--
	ITEM_TYPE_EQUIP_HELMET = 2,		   // 头盔--
	ITEM_TYPE_EQUIP_NECKLESS = 3,	   // 项链--
	ITEM_TYPE_EQUIP_RING = 4,		   // 戒指--
	ITEM_TYPE_EQUIP_MEDAL = 5,		   // 勋章--
	ITEM_TYPE_EQUIP_CLOTH = 6,		   // 衣服--
	ITEM_TYPE_EQUIP_SHOES = 7,		   // 靴子--
	ITEM_TYPE_EQUIP_BELT = 8,		   // 腰带--
	ITEM_TYPE_EQUIP_BANGLE = 9,		   // 护腕 手镯--
	ITEM_TYPE_EQUIP_JADE_PENDANT = 10, // 玉佩--
	ITEM_TYPE_EQUIP_SHIELD = 11,	   // 护盾 盾牌
	ITEM_TYPE_EQUIP_AOYI = 12,		   // 奥义
	ITEM_TYPE_EQUIP_PEARL = 13,		   // 宝珠
	ITEM_TYPE_EQUIP_BAMBOO_HAT = 14,   // 斗笠
	ITEM_TYPE_EQUIP_BANGLE_2 = 15,	   // 手镯2
	ITEM_TYPE_EQUIP_RING_2 = 16,	   // 手镯2

	ITEM_TYPE_EQUIP_CHAOS_WEAPON = 30,	 // 混沌武器
	ITEM_TYPE_EQUIP_CHAOS_HELMET = 31,	 // 混沌头盔
	ITEM_TYPE_EQUIP_CHAOS_NECKLESS = 32, // 混沌项链
	ITEM_TYPE_EQUIP_CHAOS_RING = 33,	 // 混沌戒指
	ITEM_TYPE_EQUIP_CHAOS_CLOTH = 34,	 // 混沌衣服
	ITEM_TYPE_EQUIP_CHAOS_SHOES = 35,	 // 混沌鞋子
	ITEM_TYPE_EQUIP_CHAOS_BELT = 36,	 // 混沌腰带
	ITEM_TYPE_EQUIP_CHAOS_BANGLE = 37,	 // 混沌手镯

	ITEM_TYPE_EQUIP_SHENGXIAO_1 = 41,  // 生肖 1 鼠
	ITEM_TYPE_EQUIP_SHENGXIAO_2 = 42,  // 生肖 2 牛
	ITEM_TYPE_EQUIP_SHENGXIAO_3 = 43,  // 生肖 3 虎
	ITEM_TYPE_EQUIP_SHENGXIAO_4 = 44,  // 生肖 4 兔
	ITEM_TYPE_EQUIP_SHENGXIAO_5 = 45,  // 生肖 5 龙
	ITEM_TYPE_EQUIP_SHENGXIAO_6 = 46,  // 生肖 6 蛇
	ITEM_TYPE_EQUIP_SHENGXIAO_7 = 47,  // 生肖 7 马
	ITEM_TYPE_EQUIP_SHENGXIAO_8 = 48,  // 生肖 8 羊
	ITEM_TYPE_EQUIP_SHENGXIAO_9 = 49,  // 生肖 9 猴
	ITEM_TYPE_EQUIP_SHENGXIAO_10 = 50, // 生肖 10 鸡
	ITEM_TYPE_EQUIP_SHENGXIAO_11 = 51, // 生肖 11 狗
	ITEM_TYPE_EQUIP_SHENGXIAO_12 = 52, // 生肖 12 猪

	// ITEM_TYPE_EQUIP_VIZARD			= 16,	//翅膀（原面甲）

	ITEM_TYPE_EQUIP_END,

	// 特戒
	// ITEM_CATEGORY_SPECIAL_RING
	ITEM_TYPE_SUCK_BLOOD = 1, // 吸血
	ITEM_TYPE_WIND = 2,		  // 狂风
	ITEM_TYPE_LIGHTNING = 3,  // 闪电
	ITEM_TYPE_FIRE = 4,		  // 火焰
	ITEM_TYPE_ICE = 5,		  // 寒冰
	ITEM_TYPE_POISON = 6,	  // 剧毒
	ITEM_TYPE_SUMMON = 7,	  // 召唤
	ITEM_TYPE_REVIVE = 8,	  // 复活
	ITEM_TYPE_PALSY = 9,	  // 麻痹
	ITEM_TYPE_PROTECT = 10,	  // 护身

	// 符文目录的道具类型
	// ITEM_CATEGORY_PAPAER
	ITEM_TYPE_EQUIP_PAPER_QIAN = 1, // 乾
	ITEM_TYPE_EQUIP_PAPER_KUN = 2,	// 坤
	ITEM_TYPE_EQUIP_PAPER_ZHEN = 3, // 震
	ITEM_TYPE_EQUIP_PAPER_XUN = 4,	// 巽
	ITEM_TYPE_EQUIP_PAPER_KAN = 5,	// 坎
	ITEM_TYPE_EQUIP_PAPER_LI = 6,	// 离
	ITEM_TYPE_EQUIP_PAPER_GEN = 7,	// 艮
	ITEM_TYPE_EQUIP_PAPER_DUI = 8,	// 兑

	// 材料目录的道具类型
	// ITEM_CATEGORY_MATERIAL
	ITEM_CATEGORY_MATERIAL_ADDPROP = 1,				// 增加属性
	ITEM_CATEGORY_MATERIAL_ADDPROP_COUNT_LIMIT = 2, // 增加属性(有次数限制)

	ITEM_COUNT_EVENT_LIMIT_SUB_X = 1, // 事件属性限制datax
	ITEM_COUNT_EVENT_LIMIT_SUB_Y = 2, // 事件属性限制datay
	ITEM_COUNT_EVENT_LIMIT_SUB_Z = 3, // 事件属性限制dataz

	// 扩展类道具类型
	// ITEM_CATEGORY_EXTENSION
	ITEM_CATEGORY_EXTENSION_CONVERT = 1, // 转换成数值类道具

	// 药类
	// ITEM_CATEGORY_MEDICINE
	ITEM_CATEGORY_MEDICINE_ADD_BUFFER = 1, // 添加buffer
	ITEM_CATEGORY_MEDICINE_ADD_EXP = 2,	   // 添加目标经验

	ITEM_TYPE_PET = 1, // 宠物
	// ITEM_TYPE_POTION				=  2,	//药水
	ITEM_TYPE_EXP_JADE = 3, // 经验玉(灵石)
	ITEM_TYPE_BOOK = 4,		// 书籍
	ITEM_TYPE_COMFIRM_BUY = 5,
	ITEM_TYPE_FAST_SETTING = 6,
	ITEM_TYPE_PET_BOOK = 7, // 宠物书籍
	// ITEM_TYPE_MAGIC_WEAPON_BOOK     =  8,	// 法器书籍
	ITEM_TYPE_OTHER_MAX,
};

// 装备类型
enum EquipType
{
	EQUIP_TYPE_ZHANZHUANG = 1, // 战装
	EQUIP_TYPE_BAYE = 2,	   // 霸业
	EQUIP_TYPE_LEITING = 3,	   // 雷霆
	EQUIP_TYPE_REXUE = 4,	   // 热血
	EQUIP_TYPE_ZHANSHEN = 5,   // 战神
	EQUIP_TYPE_CANGLONG = 6,   // 苍龙
	EQUIP_TYPE_XUANWU = 7,	   // 玄武
	EQUIP_TYPE_TEJIE = 8,	   // 特戒
	EQUIP_TYPE_CHOUCHONG = 9,  // 首充
	EQUIP_TYPE_HULING = 10,	   // 护灵
	EQUIP_TYPE_GODIMP = 11,	   // 绝世 神器

};

enum EquipPutStatus
{
	EQUIP_PUT_STATE_OFF = 0,
	EQUIP_PUT_STATE_ON = 1,
	EQUIP_PUT_STATE_HIDEN = 2,
};

// 穿分身装备类型
enum SEPARATIONUSETYPE
{
	SEPARATION_USETYPE_WARTER = 1,	// 穿赤水分身
	SEPARATION_USETYPE_FIRE = 2,	// 穿烈火分身
	SEPARATION_USETYPE_SOIL = 3,	// 穿岩土分身
	SEPARATION_USETYPE_THUNDER = 4, // 穿狂雷分身
};
// 神炉类型
enum ShenLuType
{
	SHENLU_TYPE_ERROR = 0,	// 神炉
	SHENLU_TYPE_RED = 1,	// 神炉 - 血玉
	SHENLU_TYPE_SHIELD = 2, // 神炉 - 护盾
	SHENLU_TYPE_GEM = 3,	// 神炉 - 宝石
	SHENLU_TYPE_SOUL = 4,	// 神炉 - 魂珠
};

enum equipType
{
	EQUIP_TYPE_WUQI = 1,	  // 武器
	EQUIP_TYPE_YIFU = 2,	  // 衣服
	EQUIP_TYPE_TOUGUI = 3,	  // 头盔
	EQUIP_TYPE_XIANGLIAN = 4, // 项链
	EQUIP_TYPE_JIEZHI = 5,	  // 戒指
	EQUIP_TYPE_HUWAN = 7,	  // 护腕
	EQUIP_TYPE_YAODAI = 9,	  // 腰带
	EQUIP_TYPE_XIEZI = 10,	  // 鞋子

	EQUIP_TYPE_XUNZHANG = 19, // 勋章
	EQUIP_TYPE_DOULI = 20,	  // 斗笠
	EQUIP_TYPE_DUNPAI = 21,	  // 盾牌
	EQUIP_TYPE_BAOZHU = 22,	  // 宝珠
	EQUIP_TYPE_YUPEI = 23,	  // 玉佩
	EQUIP_TYPE_HUFU = 24,	  // 虎符
	EQUIP_TYPE_TIANSHU = 25,  // 天书

	EQUIP_TYPE_MABI = 32,	// 麻痹特戒
	EQUIP_TYPE_FUHUO = 33,	// 复活特戒
	EQUIP_TYPE_HUSHEN = 34, // 护身特戒
	EQUIP_TYPE_TOUSHI = 35, // 透视特戒

	EQUIP_TYPE_SHENGXIAO_1 = 41,  // 生肖 鼠
	EQUIP_TYPE_SHENGXIAO_2 = 42,  // 生肖 牛
	EQUIP_TYPE_SHENGXIAO_3 = 43,  // 生肖 虎
	EQUIP_TYPE_SHENGXIAO_4 = 44,  // 生肖 兔
	EQUIP_TYPE_SHENGXIAO_5 = 45,  // 生肖 龙
	EQUIP_TYPE_SHENGXIAO_6 = 46,  // 生肖 蛇
	EQUIP_TYPE_SHENGXIAO_7 = 47,  // 生肖 马
	EQUIP_TYPE_SHENGXIAO_8 = 48,  // 生肖 羊
	EQUIP_TYPE_SHENGXIAO_9 = 49,  // 生肖 猴
	EQUIP_TYPE_SHENGXIAO_10 = 50, // 生肖 鸡
	EQUIP_TYPE_SHENGXIAO_11 = 51, // 生肖 狗
	EQUIP_TYPE_SHENGXIAO_12 = 52, // 生肖 猪

	EQUIP_TYPE_HUNLING_1 = 61, // 魂灵装备
	EQUIP_TYPE_HUNLING_2 = 62,
	EQUIP_TYPE_HUNLING_3 = 63,
	EQUIP_TYPE_HUNLING_4 = 64,
	EQUIP_TYPE_HUNLING_5 = 65,
	EQUIP_TYPE_HUNLING_6 = 66,
	EQUIP_TYPE_HUNLING_7 = 67,
	EQUIP_TYPE_HUNLING_8 = 68,
	EQUIP_TYPE_HUNLING_9 = 69,
	EQUIP_TYPE_HUNLING_10 = 70,
	EQUIP_TYPE_HUNLING_11 = 71,
	EQUIP_TYPE_HUNLING_12 = 72,
	EQUIP_TYPE_HUNLING_13 = 73,
	EQUIP_TYPE_HUNLING_14 = 74,
	EQUIP_TYPE_HUNLING_15 = 75,
	EQUIP_TYPE_HUNLING_16 = 76,

	EQUIP_TYPE_ARTIFACT_1 = 81, // 神器
	EQUIP_TYPE_ARTIFACT_2 = 82,
	EQUIP_TYPE_ARTIFACT_3 = 83,
	EQUIP_TYPE_ARTIFACT_4 = 84,
	EQUIP_TYPE_ARTIFACT_5 = 85,
	EQUIP_TYPE_ARTIFACT_6 = 86,
	EQUIP_TYPE_ARTIFACT_7 = 87,
	EQUIP_TYPE_ARTIFACT_8 = 88,
	EQUIP_TYPE_ARTIFACT_9 = 89,
	EQUIP_TYPE_ARTIFACT_10 = 90,
	EQUIP_TYPE_ARTIFACT_11 = 91,
	EQUIP_TYPE_ARTIFACT_12 = 92,

	EQUIP_TYPE_MAGIC_WUQI = 101,	  // 魔器 武器
	EQUIP_TYPE_MAGIC_YIFU = 102,	  // 魔器 衣服
	EQUIP_TYPE_MAGIC_TOUGUI = 103,	  // 魔器 头盔
	EQUIP_TYPE_MAGIC_XIANGLIAN = 104, // 魔器 项链
	EQUIP_TYPE_MAGIC_JIEZHI = 105,	  // 魔器 戒指
	EQUIP_TYPE_MAGIC_HUWAN = 107,	  // 魔器 护腕
	EQUIP_TYPE_MAGIC_YAODAI = 109,	  // 魔器 腰带
	EQUIP_TYPE_MAGIC_XIEZI = 110,	  // 魔器 鞋子

	EQUIP_TYPE_TUJIAN_1 = 121,	// 图鉴装备 1
	EQUIP_TYPE_TUJIAN_2 = 122,	// 图鉴装备 2
	EQUIP_TYPE_TUJIAN_3 = 123,	// 图鉴装备 3
	EQUIP_TYPE_TUJIAN_4 = 124,	// 图鉴装备 4
	EQUIP_TYPE_TUJIAN_5 = 125,	// 图鉴装备 5
	EQUIP_TYPE_TUJIAN_6 = 126,	// 图鉴装备 6
	EQUIP_TYPE_TUJIAN_7 = 127,	// 图鉴装备 7
	EQUIP_TYPE_TUJIAN_8 = 128,	// 图鉴装备 8
	EQUIP_TYPE_TUJIAN_9 = 129,	// 图鉴装备 9
	EQUIP_TYPE_TUJIAN_10 = 130, // 图鉴装备 10
	EQUIP_TYPE_TUJIAN_11 = 131, // 图鉴装备 11
	EQUIP_TYPE_TUJIAN_12 = 132, // 图鉴装备 12
	EQUIP_TYPE_TUJIAN_13 = 133, // 图鉴装备 13
	EQUIP_TYPE_TUJIAN_14 = 134, // 图鉴装备 14
	EQUIP_TYPE_TUJIAN_15 = 135, // 图鉴装备 15
	EQUIP_TYPE_TUJIAN_16 = 136, // 图鉴装备 16
	EQUIP_TYPE_TUJIAN_17 = 137, // 图鉴装备 17
	EQUIP_TYPE_TUJIAN_18 = 138, // 图鉴装备 18
	EQUIP_TYPE_TUJIAN_19 = 139, // 图鉴装备 19
	EQUIP_TYPE_TUJIAN_20 = 140, // 图鉴装备 20
	EQUIP_TYPE_TUJIAN_21 = 141, // 图鉴装备 21
	EQUIP_TYPE_TUJIAN_22 = 142, // 图鉴装备 22
	EQUIP_TYPE_TUJIAN_23 = 143, // 图鉴装备 23
	EQUIP_TYPE_TUJIAN_24 = 144, // 图鉴装备 24
	EQUIP_TYPE_TUJIAN_25 = 145, // 图鉴装备 25
	EQUIP_TYPE_TUJIAN_26 = 146, // 图鉴装备 26
	EQUIP_TYPE_TUJIAN_27 = 147, // 图鉴装备 27
	EQUIP_TYPE_TUJIAN_28 = 148, // 图鉴装备 28
	EQUIP_TYPE_TUJIAN_29 = 149, // 图鉴装备 29
	EQUIP_TYPE_TUJIAN_30 = 150, // 图鉴装备 30

	EQUIP_TYPE_HONOR_WUQI = 171,	  // 荣誉装备 功勋武器
	EQUIP_TYPE_HONOR_YIFU = 172,	  // 荣誉装备 功勋衣服
	EQUIP_TYPE_HONOR_TOUGUI = 173,	  // 荣誉装备 头盔
	EQUIP_TYPE_HONOR_XIANGLIAN = 174, // 荣誉装备 项链
	EQUIP_TYPE_HONOR_JIEZHI = 175,	  // 荣誉装备 戒指
	EQUIP_TYPE_HONOR_HUWAN = 177,	  // 荣誉装备 护腕
	EQUIP_TYPE_HONOR_YAODAI = 179,	  // 荣誉装备 腰带
	EQUIP_TYPE_HONOR_XIEZI = 180,	  // 荣誉装备 鞋子
	EQUIP_TYPE_HONOR_MIANJIA = 181,	  // 荣誉装备 面甲
	EQUIP_TYPE_HONOR_HUJIAN = 182,	  // 荣誉装备 功勋护肩
	EQUIP_TYPE_HONOR_DIAOZHUI = 183,  // 荣誉装备 功勋吊坠
	EQUIP_TYPE_HONOR_HUQI = 184,	  // 荣誉装备 功勋护膝

	EQUIP_TYPE_NTGM_DOULI = 191,   // 逆天改命斗笠
	EQUIP_TYPE_NTGM_HUDUN = 192,   // 逆天改命护盾
	EQUIP_TYPE_NTGM_YUPEI = 193,   // 逆天改命玉佩
	EQUIP_TYPE_NTGM_LONGHUN = 194, // 逆天改命龙魂

	EQUIP_TYPE_XUNZHANG_UNIQUE = 201, // 唯一的勋章

};

// 属性是负数，装备位的position 减去对应的值就是其属性id （比如武器的精炼等级是 EQUIP_POS_WUQI * 100 - EQUIP_PROP_JING_LIAN = -1 * 100 - 0 = -100）
enum EquipPosProp
{
	EQUIP_PROP_JING_LIAN = 0,	 // 装备精炼
	EQUIP_PROP_BAOSHI_START = 1, // 装备镶嵌宝石位置属性开始
	EQUIP_PROP_BAOSHI_END = 8,	 // 装备镶嵌宝石位置属性结束
	EQUIP_PROP_BAOSHI_MAX = 12,
	EQUIP_PROP_CUI_LIAN = 13, // 装备淬炼等级
	EQUIP_PROP_UP_STAR = 14,  // 装备升星

	EQUIP_PROP_JING_LIAN_ADD_RATE = 50,	// 装备精炼失败次数
};

enum ItemPos
{
	EQUIP_POS_START = 0,
	EQUIP_SEAT_BEGIN = -1,
	EQUIP_POS_BEGIN = -1,
	EQUIP_POS_WUQI = -1,		 // 武器
	EQUIP_POS_YIFU = -2,		 // 衣服
	EQUIP_POS_TOUGUI = -3,		 // 头盔
	EQUIP_POS_XIANGLIAN = -4,	 // 项链
	EQUIP_POS_JIEZHI_LEFT = -5,	 // 戒指左
	EQUIP_POS_JIEZHI_RIGHT = -6, // 戒指右
	EQUIP_POS_HUWAN_LEFT = -7,	 // 护腕左
	EQUIP_POS_HUWAN_RIGHT = -8,	 // 护腕右
	EQUIP_POS_YAODAI = -9,		 // 腰带
	EQUIP_POS_XIEZI = -10,		 // 鞋子
	EQUIP_POS_END = -10,

	EQUIP_POS_SHEN_SHI_BEGIN = -19,
	EQUIP_POS_XUNZHANG = -19, // 勋章
	EQUIP_POS_DOULI = -20,	  // 斗笠
	EQUIP_POS_DUNPAI = -21,	  // 盾牌
	EQUIP_POS_BAOZHU = -22,	  // 宝珠
	EQUIP_POS_YUPEI = -23,	  // 玉佩
	EQUIP_POS_HUFU = -24,	  // 虎符
	EQUIP_POS_TIANSHU = -25,  // 天书
	EQUIP_POS_SHEN_SHI_END = -25,

	EQUIP_POS_TE_JIE_BEGIN = -32,
	EQUIP_POS_MABI = -32,	// 麻痹特戒
	EQUIP_POS_FUHUO = -33,	// 复活特戒
	EQUIP_POS_HUSHEN = -34, // 护身特戒
	EQUIP_POS_TOUSHI = -35, // 透视特戒
	EQUIP_POS_TE_JIE_END = -35,
	EQUIP_SEAT_END = -35,

	EQUIP_POS_SHENGXIAO_BEGIN = -41,
	EQUIP_POS_SHENGXIAO_1 = -41,  // 生肖 1 鼠
	EQUIP_POS_SHENGXIAO_2 = -42,  // 生肖 2 牛
	EQUIP_POS_SHENGXIAO_3 = -43,  // 生肖 3 虎
	EQUIP_POS_SHENGXIAO_4 = -44,  // 生肖 4 兔
	EQUIP_POS_SHENGXIAO_5 = -45,  // 生肖 5 龙
	EQUIP_POS_SHENGXIAO_6 = -46,  // 生肖 6 蛇
	EQUIP_POS_SHENGXIAO_7 = -47,  // 生肖 7 马
	EQUIP_POS_SHENGXIAO_8 = -48,  // 生肖 8 羊
	EQUIP_POS_SHENGXIAO_9 = -49,  // 生肖 9 猴
	EQUIP_POS_SHENGXIAO_10 = -50, // 生肖 10 鸡
	EQUIP_POS_SHENGXIAO_11 = -51, // 生肖 11 狗
	EQUIP_POS_SHENGXIAO_12 = -52, // 生肖 12 猪
	EQUIP_POS_SHENGXIAO_END = -52,

	EQUIP_POS_HUNLING_BEGIN = -61,
	EQUIP_POS_HUNLING_1 = -61, // 魂灵装备
	EQUIP_POS_HUNLING_2 = -62,
	EQUIP_POS_HUNLING_3 = -63,
	EQUIP_POS_HUNLING_4 = -64,
	EQUIP_POS_HUNLING_5 = -65,
	EQUIP_POS_HUNLING_6 = -66,
	EQUIP_POS_HUNLING_7 = -67,
	EQUIP_POS_HUNLING_8 = -68,
	EQUIP_POS_HUNLING_9 = -69,
	EQUIP_POS_HUNLING_10 = -70,
	EQUIP_POS_HUNLING_11 = -71,
	EQUIP_POS_HUNLING_12 = -72,
	EQUIP_POS_HUNLING_13 = -73,
	EQUIP_POS_HUNLING_14 = -74,
	EQUIP_POS_HUNLING_15 = -75,
	EQUIP_POS_HUNLING_16 = -76,
	EQUIP_POS_HUNLING_END = -76,

	EQUIP_POS_ARTIFACT_BEGIN = -81, // 神器装备
	EQUIP_POS_ARTIFACT_1 = -81,
	EQUIP_POS_ARTIFACT_2 = -82,
	EQUIP_POS_ARTIFACT_3 = -83,
	EQUIP_POS_ARTIFACT_4 = -84,
	EQUIP_POS_ARTIFACT_5 = -85,
	EQUIP_POS_ARTIFACT_6 = -86,
	EQUIP_POS_ARTIFACT_7 = -87,
	EQUIP_POS_ARTIFACT_8 = -88,
	EQUIP_POS_ARTIFACT_9 = -89,
	EQUIP_POS_ARTIFACT_10 = -90,
	EQUIP_POS_ARTIFACT_11 = -91,
	EQUIP_POS_ARTIFACT_12 = -92,
	EQUIP_POS_ARTIFACT_END = -92, // 神器装备

	EQUIP_POS_MAGIC_BEGIN = -101,		 // 魔器装备位开始
	EQUIP_POS_MAGIC_WUQI = -101,		 // 武器
	EQUIP_POS_MAGIC_YIFU = -102,		 // 衣服
	EQUIP_POS_MAGIC_TOUGUI = -103,		 // 头盔
	EQUIP_POS_MAGIC_XIANGLIAN = -104,	 // 项链
	EQUIP_POS_MAGIC_JIEZHI_LEFT = -105,	 // 戒指左
	EQUIP_POS_MAGIC_JIEZHI_RIGHT = -106, // 戒指右
	EQUIP_POS_MAGIC_HUWAN_LEFT = -107,	 // 护腕左
	EQUIP_POS_MAGIC_HUWAN_RIGHT = -108,	 // 护腕右
	EQUIP_POS_MAGIC_YAODAI = -109,		 // 腰带
	EQUIP_POS_MAGIC_XIEZI = -110,		 // 鞋子
	EQUIP_POS_MAGIC_END = -110,			 // 魔器装备位

	EQUIP_POS_TUJIAN_BEGIN = -121, // 图鉴装备
	EQUIP_POS_TUJIAN_1 = -121,	   // 图鉴装备 1
	EQUIP_POS_TUJIAN_2 = -122,	   // 图鉴装备 2
	EQUIP_POS_TUJIAN_3 = -123,	   // 图鉴装备 3
	EQUIP_POS_TUJIAN_4 = -124,	   // 图鉴装备 4
	EQUIP_POS_TUJIAN_5 = -125,	   // 图鉴装备 5
	EQUIP_POS_TUJIAN_6 = -126,	   // 图鉴装备 6
	EQUIP_POS_TUJIAN_7 = -127,	   // 图鉴装备 7
	EQUIP_POS_TUJIAN_8 = -128,	   // 图鉴装备 8
	EQUIP_POS_TUJIAN_9 = -129,	   // 图鉴装备 9
	EQUIP_POS_TUJIAN_10 = -130,	   // 图鉴装备 10
	EQUIP_POS_TUJIAN_11 = -131,	   // 图鉴装备 11
	EQUIP_POS_TUJIAN_12 = -132,	   // 图鉴装备 12
	EQUIP_POS_TUJIAN_13 = -133,	   // 图鉴装备 13
	EQUIP_POS_TUJIAN_14 = -134,	   // 图鉴装备 14
	EQUIP_POS_TUJIAN_15 = -135,	   // 图鉴装备 15
	EQUIP_POS_TUJIAN_16 = -136,	   // 图鉴装备 16
	EQUIP_POS_TUJIAN_17 = -137,	   // 图鉴装备 17
	EQUIP_POS_TUJIAN_18 = -138,	   // 图鉴装备 18
	EQUIP_POS_TUJIAN_19 = -139,	   // 图鉴装备 19
	EQUIP_POS_TUJIAN_20 = -140,	   // 图鉴装备 20
	EQUIP_POS_TUJIAN_21 = -141,	   // 图鉴装备 21
	EQUIP_POS_TUJIAN_22 = -142,	   // 图鉴装备 22
	EQUIP_POS_TUJIAN_23 = -143,	   // 图鉴装备 23
	EQUIP_POS_TUJIAN_24 = -144,	   // 图鉴装备 24
	EQUIP_POS_TUJIAN_25 = -145,	   // 图鉴装备 25
	EQUIP_POS_TUJIAN_26 = -146,	   // 图鉴装备 26
	EQUIP_POS_TUJIAN_27 = -147,	   // 图鉴装备 27
	EQUIP_POS_TUJIAN_28 = -148,	   // 图鉴装备 28
	EQUIP_POS_TUJIAN_29 = -149,	   // 图鉴装备 29
	EQUIP_POS_TUJIAN_30 = -150,	   // 图鉴装备 30
	EQUIP_POS_TUJIAN_END = -150,   // 图鉴装备 10

	EQUIP_POS_HONOR_BEGIN = -171,		 // 荣誉装备
	EQUIP_POS_HONOR_WUQI = -171,		 // 武器
	EQUIP_POS_HONOR_YIFU = -172,		 // 衣服
	EQUIP_POS_HONOR_TOUGUI = -173,		 // 头盔
	EQUIP_POS_HONOR_XIANGLIAN = -174,	 // 项链
	EQUIP_POS_HONOR_JIEZHI_LEFT = -175,	 // 戒指左
	EQUIP_POS_HONOR_JIEZHI_RIGHT = -176, // 戒指右
	EQUIP_POS_HONOR_HUWAN_LEFT = -177,	 // 护腕左
	EQUIP_POS_HONOR_HUWAN_RIGHT = -178,	 // 护腕右
	EQUIP_POS_HONOR_YAODAI = -179,		 // 腰带
	EQUIP_POS_HONOR_XIEZI = -180,		 // 鞋子
	EQUIP_POS_HONOR_MIANJIA = -181,		 // 荣誉装备 面甲
	EQUIP_POS_HONOR_HUJIAN = -182,		 // 荣誉装备 功勋护肩
	EQUIP_POS_HONOR_DIAOZHUI = -183,	 // 荣誉装备 功勋吊坠
	EQUIP_POS_HONOR_HUQI = -184,		 // 荣誉装备 功勋护膝
	EQUIP_POS_HONOR_END = -184,			 // 荣誉装备位

	EQUIP_POS_NTGM_BEGIN = -191,   // 逆天改命装备
	EQUIP_POS_NTGM_DOULI = -191,   // 逆天改命斗笠
	EQUIP_POS_NTGM_HUDUN = -192,   // 逆天改命护盾
	EQUIP_POS_NTGM_YUPEI = -193,   // 逆天改命玉佩
	EQUIP_POS_NTGM_LONGHUN = -194, // 逆天改命龙魂
	EQUIP_POS_NTGM_END = -194,	   // 逆天改命装备

	EQUIP_POS_XUNZHANG_UNIQUE = -201, // 独立的勋章，不与任何装备关联
	EQUIP_POS_MAX = -210,
};

// 物品位置
enum ItemPosition
{
	BAG_POS_EQUIP_BEGIN = 0,
	BAG_POS_EQUIP_NECKLESS = -1,   // 项链
	BAG_POS_EQUIP_WEAPON = -2,	   // 武器
	BAG_POS_EQUIP_BANGLE = -3,	   // 手镯
	BAG_POS_EQUIP_RING = -4,	   // 戒指
	BAG_POS_EQUIP_BELT = -5,	   // 腰带
	BAG_POS_EQUIP_SHOES = -6,	   // 鞋子
	BAG_POS_EQUIP_RING_TWO = -7,   // 戒指2
	BAG_POS_EQUIP_BANGLE_TWO = -8, // 手镯2
	BAG_POS_EQUIP_CLOTH = -9,	   // 衣服
	BAG_POS_EQUIP_HELMET = -10,	   // 头盔
	BAG_POS_EQUIP_DOULI = -11,	   // 斗笠
	BAG_POS_EQUIP_DUNPAI = -12,	   // 盾牌
	BAG_POS_EQUIP_AOYI = -13,	   // 奥义
	BAG_POS_EQUIP_YUPEI = -14,	   // 玉佩
	BAG_POS_EQUIP_XUNZHANG = -15,  // 勋章
	BAG_POS_EQUIP_BAOZHU = -16,	   // 珠宝
	BAG_POS_EQUIP_PROB = -20,	   // 战装预留

	BAG_POS_THUNDER_EQUIP_BEGIN = -21,		// 雷霆装备开始
	BAG_POS_THUNDER_EQUIP_WEAPON = -21,		// 武器
	BAG_POS_THUNDER_EQUIP_CLOTH = -22,		// 衣服
	BAG_POS_THUNDER_EQUIP_HELMET = -23,		// 头盔
	BAG_POS_THUNDER_EQUIP_BANGLE = -24,		// 护腕
	BAG_POS_THUNDER_EQUIP_RING = -25,		// 戒指
	BAG_POS_THUNDER_EQUIP_BELT = -26,		// 腰带
	BAG_POS_THUNDER_EQUIP_NECKLESS = -27,	// 项链
	BAG_POS_THUNDER_EQUIP_BANGLE_SEC = -28, // 护腕
	BAG_POS_THUNDER_EQUIP_RING_SEC = -29,	// 戒指
	BAG_POS_THUNDER_EQUIP_SHOES = -30,		// 鞋子
	BAG_POS_THUNDER_EQUIP_END = -30,		// 雷霆装备结束
	BAG_POS_THUNDER_EQUIP_PROB = -40,		// 雷霆装备预留

	BAG_POS_HEGEMON_EQUIP_BEGIN = -41,		// 霸业装备开始
	BAG_POS_HEGEMON_EQUIP_WEAPON = -41,		// 霸业 之刃
	BAG_POS_HEGEMON_EQUIP_CLOTH = -42,		// 霸业 之甲
	BAG_POS_HEGEMON_EQUIP_HELMET = -43,		// 霸业 头盔
	BAG_POS_HEGEMON_EQUIP_BANGLE = -44,		// 霸业 手镯
	BAG_POS_HEGEMON_EQUIP_RING = -45,		// 霸业 戒指
	BAG_POS_HEGEMON_EQUIP_BELT = -46,		// 霸业 腰带
	BAG_POS_HEGEMON_EQUIP_NECKLESS = -47,	// 霸业 项链
	BAG_POS_HEGEMON_EQUIP_BANGLE_SEC = -48, // 霸业 护腕2
	BAG_POS_HEGEMON_EQUIP_RING_SEC = -49,	// 霸业 戒指2
	BAG_POS_HEGEMON_EQUIP_SHOES = -50,		// 霸业 鞋子
	BAG_POS_HEGEMON_EQUIP_END = -50,		// 霸业装备结束
	BAG_POS_HEGEMON_EQUIP_PROB = -60,		// 霸业装备预留

	// 弑神装备
	BAG_POS_HOT_TBLOOM_EQUIP_BEGIN = -61,	 // 弑神装备 开始
	BAG_POS_HOT_TBLOOM_EQUIP_WEAPON = -61,	 // 武器
	BAG_POS_HOT_TBLOOM_EQUIP_CLOTH = -62,	 // 衣服
	BAG_POS_HOT_TBLOOM_EQUIP_BRACELET = -63, // 手链
	BAG_POS_HOT_TBLOOM_EQUIP_GOBE = -64,	 // 护镜
	BAG_POS_HOT_TBLOOM_EQUIP_VIZARD = -65,	 // 面甲
	BAG_POS_HOT_TBLOOM_EQUIP_SCARF = -66,	 // 披风
	BAG_POS_HOT_TBLOOM_EQUIP_BALDRIC = -67,	 // 玉佩
	BAG_POS_HOT_TBLOOM_EQUIP_DRUM = -68,	 // 军鼓
	BAG_POS_HOT_TBLOOM_EQUIP_END = -68,		 // 弑神装备 结束
	BAG_POS_HOT_TBLOOM_EQUIP_PROB = -80,	 // 弑神装备 预留

	// 神域装备
	BAG_POS_SHENYU_EQUIP_BEGIN = -81,	   // 神域 开始
	BAG_POS_SHENYU_EQUIP_WEAPON = -81,	   // 神域 武器
	BAG_POS_SHENYU_EQUIP_CLOTH = -82,	   // 神域 衣服
	BAG_POS_SHENYU_EQUIP_HELMET = -83,	   // 战神 头盔
	BAG_POS_SHENYU_EQUIP_NECKLESS = -84,   // 战神 项链
	BAG_POS_SHENYU_EQUIP_BANGLE = -85,	   // 战神 手镯
	BAG_POS_SHENYU_EQUIP_BANGLE_SEC = -86, // 战神 手镯2
	BAG_POS_SHENYU_EQUIP_RING = -87,	   // 战神 戒指
	BAG_POS_SHENYU_EQUIP_RING_SEC = -88,   // 战神 戒指2
	BAG_POS_SHENYU_EQUIP_BELT = -89,	   // 战神 腰带
	BAG_POS_SHENYU_EQUIP_SHOES = -90,	   // 战神 之靴
	BAG_POS_SHENYU_EQUIP_END = -90,		   // 神域 结束
	BAG_POS_SHENYU_EQUIP_PROB = -100,	   // 战神装备预留

	BAG_POS_CAREER_1 = -101,
	BAG_POS_CAREER_2 = -102,
	BAG_POS_CAREER_3 = -103,
	BAG_POS_CAREER_4 = -104,
	BAG_POS_CAREER_5 = -105,
	BAG_POS_CAREER_6 = -106,
	BAG_POS_CAREER_7 = -107,
	BAG_POS_CAREER_8 = -108,
	BAG_POS_CAREER_9 = -109,
	BAG_POS_CAREER_10 = -110,

	// 苍龙装备
	BAG_POS_EQUIP_DRAGON_HORN = -126,  // 苍龙之角
	BAG_POS_EQUIP_DRAGON_BEARD = -127, // 苍龙之须
	BAG_POS_EQUIP_DRAGON_TEETH = -128, // 苍龙之牙
	BAG_POS_EQUIP_DRAGON_HEART = -129, // 苍龙之心
	BAG_POS_EQUIP_DRAGON_CLAW = -130,  // 苍龙之爪
	BAG_POS_EQUIP_DRAGON_EYES = -131,  // 苍龙之瞳
	BAG_POS_EQUIP_DRAGON_SCALE = -132, // 苍龙之鳞
	BAG_POS_EQUIP_DRAGON_GRAIN = -133, // 苍龙之纹
	BAG_POS_EQUIP_DRAGON_TAIL = -134,  // 苍龙之尾
	BAG_POS_EQUIP_DRAGON_BLOOD = -135, // 苍龙之血

	// 玄武装备
	BAG_POS_EQUIP_TORTOISE_EYES = -150,	 // 玄武之眼
	BAG_POS_EQUIP_TORTOISE_BLOOD = -151, // 玄武之血
	BAG_POS_EQUIP_TORTOISE_TEETH = -152, // 玄武之牙
	BAG_POS_EQUIP_TORTOISE_GRAIN = -153, // 玄武之纹
	BAG_POS_EQUIP_TORTOISE_JAW = -154,	 // 玄武之颚
	BAG_POS_EQUIP_TORTOISE_SCALE = -155, // 玄武之鳞
	BAG_POS_EQUIP_TORTOISE_ARMOR = -156, // 玄武之甲
	BAG_POS_EQUIP_TORTOISE_HEART = -157, // 玄武之心
	BAG_POS_EQUIP_TORTOISE_CLAW = -158,	 // 玄武之爪
	BAG_POS_EQUIP_TORTOISE_TAIL = -159,	 // 玄武之尾

	// 特戒
	BAG_POS_EQUIP_SPECIAL_RING = -160,	   // 特戒
	BAG_POS_EQUIP_SPECIAL_RING_TWO = -161, // 特戒2

	// 神兵
	BAG_POS_EQUIP_ARTIFACT = -162,

	// 勋章
	BAG_POS_EQUIP_MEDAL = -163,

	BAG_POS_EQUIP_END = -168,

	BAG_POS_SEPARATION_EQUIP_BEGIN = -200,
	BAG_POS_SEPARATION_WARTER_EQUIP_WEAPON = -201,	   // 赤水分身武器
	BAG_POS_SEPARATION_WARTER_EQUIP_CLOTH = -202,	   // 赤水分身衣服
	BAG_POS_SEPARATION_WARTER_EQUIP_BANGLE = -203,	   // 赤水分身手镯
	BAG_POS_SEPARATION_WARTER_EQUIP_RING = -204,	   // 赤水分身戒指
	BAG_POS_SEPARATION_WARTER_EQUIP_BELT = -205,	   // 赤水分身腰带
	BAG_POS_SEPARATION_WARTER_EQUIP_HELMET = -206,	   // 赤水分身头盔
	BAG_POS_SEPARATION_WARTER_EQUIP_NECKLESS = -207,   // 赤水分身项链
	BAG_POS_SEPARATION_WARTER_EQUIP_BANGLE_TWO = -208, // 赤水分身手镯2
	BAG_POS_SEPARATION_WARTER_EQUIP_RING_TWO = -209,   // 赤水分身戒指2
	BAG_POS_SEPARATION_WARTER_EQUIP_SHOES = -210,	   // 赤水分身鞋子

	BAG_POS_SEPARATION_FIRE_EQUIP_WEAPON = -211,	 // 烈火分身武器
	BAG_POS_SEPARATION_FIRE_EQUIP_CLOTH = -212,		 // 烈火分身衣服
	BAG_POS_SEPARATION_FIRE_EQUIP_BANGLE = -213,	 // 烈火分身手镯
	BAG_POS_SEPARATION_FIRE_EQUIP_RING = -214,		 // 烈火分身戒指
	BAG_POS_SEPARATION_FIRE_EQUIP_BELT = -215,		 // 烈火分身腰带
	BAG_POS_SEPARATION_FIRE_EQUIP_HELMET = -216,	 // 烈火分身头盔
	BAG_POS_SEPARATION_FIRE_EQUIP_NECKLESS = -217,	 // 烈火分身项链
	BAG_POS_SEPARATION_FIRE_EQUIP_BANGLE_TWO = -218, // 烈火分身手镯2
	BAG_POS_SEPARATION_FIRE_EQUIP_RING_TWO = -219,	 // 烈火分身戒指2
	BAG_POS_SEPARATION_FIRE_EQUIP_SHOES = -220,		 // 烈火分身鞋子

	BAG_POS_SEPARATION_SOIL_EQUIP_WEAPON = -221,	 // 岩土分身武器
	BAG_POS_SEPARATION_SOIL_EQUIP_CLOTH = -222,		 // 岩土分身衣服
	BAG_POS_SEPARATION_SOIL_EQUIP_BANGLE = -223,	 // 岩土分身手镯
	BAG_POS_SEPARATION_SOIL_EQUIP_RING = -224,		 // 岩土分身戒指
	BAG_POS_SEPARATION_SOIL_EQUIP_BELT = -225,		 // 岩土分身腰带
	BAG_POS_SEPARATION_SOIL_EQUIP_HELMET = -226,	 // 岩土分身头盔
	BAG_POS_SEPARATION_SOIL_EQUIP_NECKLESS = -227,	 // 岩土分身项链
	BAG_POS_SEPARATION_SOIL_EQUIP_BANGLE_TWO = -228, // 岩土分身手镯2
	BAG_POS_SEPARATION_SOIL_EQUIP_RING_TWO = -229,	 // 岩土分身戒指2
	BAG_POS_SEPARATION_SOIL_EQUIP_SHOES = -230,		 // 岩土分身鞋子

	BAG_POS_SEPARATION_THUNDER_EQUIP_WEAPON = -231,		// 狂雷分身武器
	BAG_POS_SEPARATION_THUNDER_EQUIP_CLOTH = -232,		// 狂雷分身衣服
	BAG_POS_SEPARATION_THUNDER_EQUIP_BANGLE = -233,		// 狂雷分身手镯
	BAG_POS_SEPARATION_THUNDER_EQUIP_RING = -234,		// 狂雷分身戒指
	BAG_POS_SEPARATION_THUNDER_EQUIP_BELT = -235,		// 狂雷分身腰带
	BAG_POS_SEPARATION_THUNDER_EQUIP_HELMET = -236,		// 狂雷分身头盔
	BAG_POS_SEPARATION_THUNDER_EQUIP_NECKLESS = -237,	// 狂雷分身项链
	BAG_POS_SEPARATION_THUNDER_EQUIP_BANGLE_TWO = -238, // 狂雷分身手镯2
	BAG_POS_SEPARATION_THUNDER_EQUIP_RING_TWO = -239,	// 狂雷分身戒指2
	BAG_POS_SEPARATION_THUNDER_EQUIP_SHOES = -240,		// 狂雷分身鞋子
	BAG_POS_SEPARATION_EQUIP_END = -241,

	BAG_POS_EQUIP_SHENGXIAO_BEGIN = -300, // 生肖装备开始
	BAG_POS_EQUIP_SHENGXIAO_1 = -301,	  // 生肖 1
	BAG_POS_EQUIP_SHENGXIAO_2 = -302,	  // 生肖 2
	BAG_POS_EQUIP_SHENGXIAO_3 = -303,	  // 生肖 3
	BAG_POS_EQUIP_SHENGXIAO_4 = -304,	  // 生肖 4
	BAG_POS_EQUIP_SHENGXIAO_5 = -305,	  // 生肖 5
	BAG_POS_EQUIP_SHENGXIAO_6 = -306,	  // 生肖 6
	BAG_POS_EQUIP_SHENGXIAO_7 = -307,	  // 生肖 7
	BAG_POS_EQUIP_SHENGXIAO_8 = -308,	  // 生肖 8
	BAG_POS_EQUIP_SHENGXIAO_9 = -309,	  // 生肖 9
	BAG_POS_EQUIP_SHENGXIAO_10 = -310,	  // 生肖 10
	BAG_POS_EQUIP_SHENGXIAO_11 = -311,	  // 生肖 11
	BAG_POS_EQUIP_SHENGXIAO_12 = -312,	  // 生肖 12
	BAG_POS_EQUIP_SHENGXIAO_END = -313,	  // 生肖装备结束

	BAG_POS_EQUIP_MAX = -1000,

	// 技能符文镶嵌位置
	BAG_POS_SKIIL_SUNE_BEG = -1001,
	BAG_POS_SKIIL_SUNE_1_1 = -1001, // 技能1（刺杀）
	BAG_POS_SKIIL_SUNE_1_2 = -1002,
	BAG_POS_SKIIL_SUNE_1_3 = -1003,
	BAG_POS_SKIIL_SUNE_1_4 = -1004,
	BAG_POS_SKIIL_SUNE_1_5 = -1005,
	BAG_POS_SKIIL_SUNE_2_1 = -1006, // 技能2（半月）
	BAG_POS_SKIIL_SUNE_2_2 = -1007,
	BAG_POS_SKIIL_SUNE_2_3 = -1008,
	BAG_POS_SKIIL_SUNE_2_4 = -1009,
	BAG_POS_SKIIL_SUNE_2_5 = -1010,
	BAG_POS_SKIIL_SUNE_3_1 = -1011, // 技能3（野蛮）
	BAG_POS_SKIIL_SUNE_3_2 = -1012,
	BAG_POS_SKIIL_SUNE_3_3 = -1013,
	BAG_POS_SKIIL_SUNE_3_4 = -1014,
	BAG_POS_SKIIL_SUNE_3_5 = -1015,
	BAG_POS_SKIIL_SUNE_4_1 = -1016, // 技能4（烈火）
	BAG_POS_SKIIL_SUNE_4_2 = -1017,
	BAG_POS_SKIIL_SUNE_4_3 = -1018,
	BAG_POS_SKIIL_SUNE_4_4 = -1019,
	BAG_POS_SKIIL_SUNE_4_5 = -1020,
	BAG_POS_SKIIL_SUNE_5_1 = -1021, // 技能5（自愈术）
	BAG_POS_SKIIL_SUNE_5_2 = -1022,
	BAG_POS_SKIIL_SUNE_5_3 = -1023,
	BAG_POS_SKIIL_SUNE_5_4 = -1024,
	BAG_POS_SKIIL_SUNE_5_5 = -1025,
	BAG_POS_SKIIL_SUNE_6_1 = -1026, // 技能6（施毒术）
	BAG_POS_SKIIL_SUNE_6_2 = -1027,
	BAG_POS_SKIIL_SUNE_6_3 = -1028,
	BAG_POS_SKIIL_SUNE_6_4 = -1029,
	BAG_POS_SKIIL_SUNE_6_5 = -1030,
	BAG_POS_SKIIL_SUNE_7_1 = -1031, // 技能7（开天）
	BAG_POS_SKIIL_SUNE_7_2 = -1032,
	BAG_POS_SKIIL_SUNE_7_3 = -1033,
	BAG_POS_SKIIL_SUNE_7_4 = -1034,
	BAG_POS_SKIIL_SUNE_7_5 = -1035,
	BAG_POS_SKIIL_SUNE_END = -1036,
	BAG_POS_SKIIL_SUNE_PROB = -1100, //-1031 至 -1100 技能符文预留

	BAG_POS_MAX_END = -2000, // 位置最大值

	BAG_POS_INVALID = 10000, // 无效的背包位索引,角色加载时,从DB加到的装备位的装备,先把该item的pos设置这个值,用于辨别是初始时的穿装备
};

// 背包类型
enum BagType
{
	BAG_TYPE_PLAYER = 1,		// 玩家背包
	BAG_TYPE_TREASURE = 2,		// 寻宝仓库
	BAG_TYPE_MARKET = 3,		// 摊位背包
	BAG_TYPE_TRADE = 4,			// 交易背包
	BAG_TYPE_NPC = 5,			// NPC仓库
	BAG_TYPE_ALL = 6,			// 所有背包
	BAG_TYPE_HOLLOW = 7,		// 虚空背包
	BAG_TYPE_LUCKY_COMPASS = 8, // 神运罗盘背包
	BAG_TYPE_QUICK_USE = 9,		// 快捷使用
	BAG_TYPE_ZHUZAO = 10,		// 铸造背包
};

// 背包位置范围
enum BagSlotIndex
{
	BAG_POS_BEGIN = -526,	// 背包位置开始
	HERO_BAG_BEGIN = -526,	// 英雄穿戴位置开始
	HERO_BAG_END = -500,	// 英雄穿戴位置结束
	PUTON_BAG_BEGIN = -180, // 穿戴位置开始
	PUTON_BAG_END = -1,		// 穿戴位置结束

	GRID_COUNT_PAGE = 48, // 每页放48个格子

	PLAYER_BAG_BEGIN = 1,			// 玩家背包位置开始
	PLAYER_BAG_END = 96,			// 玩家背包位置结束
	PLAYER_BAG_PREPARED_END = 4000, // 玩家背包预留最大结束位置

	QUICK_USE_BAG_BEGIN = 4001,		   // 快捷使用背包开始
	QUICK_USE_BAG_END = 4005,		   // 快捷使用背包结束
	QUICK_USE_BAG_PREPARED_END = 5000, // 快捷使用背包预留最大结束位置

	TREASURE_BAG_BEGIN = 5001,		  // 寻宝背包位置开始
	TREASURE_BAG_END = 5720,		  // 寻宝背包位置结束
	TREASURE_BAG_PREPARED_END = 6000, // 寻宝背包预留最大结束位置

	MARKET_BAG_BEGIN = 6001,		// 摆摊背包位置开始
	MARKET_BAG_END = 6040,			// 摆摊背包位置结束
	MARKET_BAG_PREPARED_END = 7000, // 摆摊背包预留最大结束位置

	TRADE_BAG_BEGIN = 7001,		   // 交易背包位置开始
	TRADE_BAG_END = 7010,		   // 交易背包位置结束
	TRADE_BAG_PREPARED_END = 7500, // 交易背包预留最大结束位置

	HOLLOW_BAG_BEGIN = 7501,		// 临时背包位置开始
	HOLLOW_BAG_END = 7600,			// 临时背包位置结束
	HOLLOW_BAG_PREPARED_END = 8000, // 临时背包预留最大结束位置

	NPC_BAG_BEGIN = 8001,		  // NPC仓库位置开始
	NPC_BAG_END = 8240,			  // NPC仓库位置结束
	NPC_BAG_PREPARED_END = 10000, // NPC仓库预留最大结束位置

	LUCKY_COMPASS_BAG_BEGIN = 10001,		// 神韵罗盘位置开始
	LUCKY_COMPASS_BAG_END = 10720,			// 神韵罗盘位置结束
	LUCKY_COMPASS_BAG_PREPARED_END = 11000, // 寻宝背包预留最大结束位置

	ZHUZAO_BAG_BEGIN = 11001,		 // 铸造背包位置开始
	ZHUZAO_BAG_END = 11200,			 // 铸造背包位置阶数
	ZHUZAO_BAG_PREPARED_END = 12000, // 铸造背包预留最大结束位置

	BAG_POS_END, // 背包位置结束
};

// 物品绑定状态
enum ItemBindState
{
	ITEM_BIND_STATE_UNBOUND = 0, // 未绑定
	ITEM_BIND_STATE_BOUND = 1,	 // 普通绑定
};

// 装备增幅
enum EquipIncreaseFailType
{
	EQUIP_INCREASE_DOWN = 1,	// 降级
	EQUIP_INCREASE_RESTORE = 2, // 还原等级
	EQUIP_INCREASE_LOSE = 3,	// 爆装备
};

// 物品绑定类型
enum ItemBindType
{
	ITEM_BIND_TYPE_NORMAL = 0, // 不指定是否绑定(可绑定也可不绑定)
	ITEM_BIND_TYPE_PUTON = 1,  // 穿戴时绑定
	ITEM_BIND_TYPE_ALWAYS = 2, // 永久绑定
	ITEM_BIND_TYPE_NEVER = 3,  // 永久不绑定
};

// 物品来源 类型
enum ItemBirthType
{
	ITEM_BIRTH_TYPE_BEGIN = 1,
	ITEM_BIRTH_TYPE_KILL_MONSTER = 1, // 杀怪掉落
	ITEM_BIRTH_TYPE_NPC_MAKE = 2,	  // npc制造
};

// 物品属性(注意，ITEM_PROP_BEGIN~ITEM_PROP_MAX段属性默认都会存数据库，所以，不需要存数据库
// 的要处理一下）
enum ItemProp
{
	ITEM_PROP_BEGIN = 1,			// 物品属性开始值
	ITEM_PROP_BIND_STATE = 2,		// 绑定状态
	ITEM_PROP_OVER_TIME = 3,		// 物品过期时间
	ITEM_PROP_EQUIP_LOCK = 4,		// 物品被锁定(不可使用)
	ITEM_PROP_CONSIGNMENT_TIME = 5, // 寄售冷却时间
	// 物品来源
	ITEM_PROP_BIRTH_MAP = 6,		 // 地图
	ITEM_PROP_BIRTH_TYPE = 7,		 // 出生类型（杀怪掉落 or npc制造）
	ITEM_PROP_BIRTH_MONSTER_ID = 8,	 // 怪物类型
	ITEM_PROP_BIRTH_FIRST_OWNER = 9, // 首位拥有者
	ITEM_PROP_BIRTH_TIME = 10,		 // 出生时间
	ITEM_PROP_APPRAISER = 11,		 // 鉴定者
	ITEM_PROP_REDPACKET_MONEY = 12,	 // 红包数额
	ITEM_PROP_REDPACKET_CNT = 13,	 // 红包领取次数

	//
	ITEM_PROP_LEGEND_PROP_NUMS = 12,	// 特殊属性条数
	ITEM_PROP_FUSE_TIMES = 13,			// 装备重铸（融合）次数
	ITEM_PROP_APPRAISE_BASE_TIMES = 14, // 装备鉴定 基础属性（保存的条数，并非实际显示条数）
	ITEM_PROP_FUSE_ATTR_IDX = 15,		// 装备重铸的属性idx
	ITEM_PROP_RANDOM_PROP_COUNT = 16,	// 随机属性条数
	ITEM_PROP_LOCK_RECOVERY = 17,		// 回收锁定（无法回收）
	// 18是之前的物品绑定状态
	ITEM_PROP_PERFECT_APPRAISED = 19, // 极品鉴定

	ITEM_PROP_GET_DAY = 20, // 获得时间day

	// 基础鉴定属性（非弑神装备）
	ITEM_PROP_BASE_ATTR_TYPE_BEGIN = 21,
	ITEM_PROP_BASE_ATTR_TYPE_1 = 21,
	ITEM_PROP_BASE_ATTR_TYPE_2 = 22,
	ITEM_PROP_BASE_ATTR_TYPE_3 = 23,
	ITEM_PROP_BASE_ATTR_TYPE_4 = 24,
	ITEM_PROP_BASE_ATTR_TYPE_5 = 25,
	ITEM_PROP_BASE_ATTR_TYPE_6 = 26,
	ITEM_PROP_BASE_ATTR_TYPE_7 = 27,
	ITEM_PROP_BASE_ATTR_TYPE_8 = 28,
	ITEM_PROP_BASE_ATTR_TYPE_END = 30,
	ITEM_PROP_BASE_ATTR_VALUE_BEGIN = 31,
	ITEM_PROP_BASE_ATTR_VALUE_1 = 31,
	ITEM_PROP_BASE_ATTR_VALUE_2 = 32,
	ITEM_PROP_BASE_ATTR_VALUE_3 = 33,
	ITEM_PROP_BASE_ATTR_VALUE_4 = 34,
	ITEM_PROP_BASE_ATTR_VALUE_5 = 35,
	ITEM_PROP_BASE_ATTR_VALUE_6 = 36,
	ITEM_PROP_BASE_ATTR_VALUE_7 = 37,
	ITEM_PROP_BASE_ATTR_VALUE_8 = 38,
	ITEM_PROP_BASE_ATTR_VALUE_END = 40,

	// 特殊属性（鉴定出来的，融合可以修改）
	ITEM_PROP_LEGEND_PROP_TYPE_BEGIN = 41,
	ITEM_PROP_LEGEND_PROP_TYPE_1 = 41,
	ITEM_PROP_LEGEND_PROP_TYPE_2 = 42,
	ITEM_PROP_LEGEND_PROP_TYPE_3 = 43,
	ITEM_PROP_LEGEND_PROP_TYPE_4 = 44,
	ITEM_PROP_LEGEND_PROP_TYPE_5 = 45,
	ITEM_PROP_LEGEND_PROP_TYPE_6 = 46,
	ITEM_PROP_LEGEND_PROP_TYPE_7 = 47,
	ITEM_PROP_LEGEND_PROP_TYPE_8 = 48,
	ITEM_PROP_LEGEND_PROP_TYPE_END = 48,
	//
	ITEM_PROP_LEGEND_PROP_VALUE_BEGIN = 49,
	ITEM_PROP_LEGEND_PROP_VALUE_1 = 49,
	ITEM_PROP_LEGEND_PROP_VALUE_2 = 50,
	ITEM_PROP_LEGEND_PROP_VALUE_3 = 51,
	ITEM_PROP_LEGEND_PROP_VALUE_4 = 52,
	ITEM_PROP_LEGEND_PROP_VALUE_5 = 53,
	ITEM_PROP_LEGEND_PROP_VALUE_6 = 54,
	ITEM_PROP_LEGEND_PROP_VALUE_7 = 55,
	ITEM_PROP_LEGEND_PROP_VALUE_8 = 56,
	ITEM_PROP_LEGEND_PROP_VALUE_END = 56,
	// 重铸属性出的属性
	ITEM_PROP_FUSING_PROP_TYPE_1 = 57,
	ITEM_PROP_FUSING_PROP_TYPE_2 = 58,
	ITEM_PROP_FUSING_PROP_VALUE_1 = 59,
	ITEM_PROP_FUSING_PROP_VALUE_2 = 60,

	// 随机属性类型（装备生成和洗练出来的）
	ITEM_PROP_RANDOM_PROP_ID_BEGIN = 61,
	ITEM_PROP_RANDOM_PROP_ID_1 = 61,
	ITEM_PROP_RANDOM_PROP_ID_2 = 62,
	ITEM_PROP_RANDOM_PROP_ID_3 = 63,
	ITEM_PROP_RANDOM_PROP_ID_4 = 64,
	ITEM_PROP_RANDOM_PROP_ID_5 = 65,
	ITEM_PROP_RANDOM_PROP_ID_END = 65,
	// 随机属性值
	ITEM_PROP_RANDOM_PROP_VALUE_BEGIN = 66,
	ITEM_PROP_RANDOM_PROP_VALUE_1 = 66,
	ITEM_PROP_RANDOM_PROP_VALUE_2 = 67,
	ITEM_PROP_RANDOM_PROP_VALUE_3 = 68,
	ITEM_PROP_RANDOM_PROP_VALUE_4 = 69,
	ITEM_PROP_RANDOM_PROP_VALUE_5 = 70,
	ITEM_PROP_RANDOM_PROP_VALUE_END = 70,

	// 洗练临时属性类型
	ITEM_PROP_SMELT_TEMP_ID_BEGIN = 71,
	ITEM_PROP_SMELT_TEMP_ID_1 = 71,
	ITEM_PROP_SMELT_TEMP_ID_2 = 72,
	ITEM_PROP_SMELT_TEMP_ID_3 = 73,
	ITEM_PROP_SMELT_TEMP_ID_4 = 74,
	ITEM_PROP_SMELT_TEMP_ID_5 = 75,
	ITEM_PROP_SMELT_TEMP_ID_END = 75,
	// 洗练临时属性值
	ITEM_PROP_SMELT_TEMP_VALUE_BEGIN = 76,
	ITEM_PROP_SMELT_TEMP_VALUE_1 = 76,
	ITEM_PROP_SMELT_TEMP_VALUE_2 = 77,
	ITEM_PROP_SMELT_TEMP_VALUE_3 = 78,
	ITEM_PROP_SMELT_TEMP_VALUE_4 = 79,
	ITEM_PROP_SMELT_TEMP_VALUE_5 = 80,
	ITEM_PROP_SMELT_TEMP_VALUE_END = 80,

	// 特戒相关属性
	ITEM_PROP_TJ_LEVEL_TOP = 81,	  // 阶数上限
	ITEM_PROP_TJ_EX_LEVEL_TOP = 82,	  // 额外阶数上限
	ITEM_PROP_TJ_LEVEL = 83,		  // 阶数
	ITEM_PROP_TJ_QUALITY_1 = 84,	  // 资质1
	ITEM_PROP_TJ_QUALITY_2 = 85,	  // 资质2
	ITEM_PROP_TJ_QUALITY_3 = 86,	  // 资质3
	ITEM_PROP_TJ_QUALITY_4 = 87,	  // 资质4
	ITEM_PROP_TJ_QUALITY_5 = 88,	  // 资质5
	ITEM_PROP_TJ_QUALITY_6 = 89,	  // 资质6
	ITEM_PROP_TJ_QUALITY_TEMP_1 = 90, // 临时资质1
	ITEM_PROP_TJ_QUALITY_TEMP_2 = 91, // 临时资质2
	ITEM_PROP_TJ_QUALITY_TEMP_3 = 92, // 临时资质3
	ITEM_PROP_TJ_QUALITY_TEMP_4 = 93, // 临时资质4
	ITEM_PROP_TJ_QUALITY_TEMP_5 = 94, // 临时资质5
	ITEM_PROP_TJ_QUALITY_TEMP_6 = 95, // 临时资质6

	ITEM_PROP_LUCKY = 101,			   // 幸运值
	ITEM_PROP_TEMP_MAIL = 102,		   // 临时属性，邮件专用
	ITEM_PROP_CHECK_IN_BAG = 103,	   // 标记是否在背包中查看过这个物品
	ITEM_PROP_CHECK_IN_FS_BAG_1 = 104, // 标记是否在分身1背包中查看过这个物品
	ITEM_PROP_CHECK_IN_FS_BAG_2 = 105, // 标记是否在分身2背包中查看过这个物品
	ITEM_PROP_CHECK_IN_FS_BAG_3 = 106, // 标记是否在分身3背包中查看过这个物品
	ITEM_PROP_CHECK_IN_FS_BAG_4 = 107, // 标记是否在分身4背包中查看过这个物品

	// 弑神特殊属性
	ITEM_PROP_DEICIDE_IDX_BEGIN = 111,		  //
	ITEM_PROP_DEICIDE_IDX_END = 118,		  //
	ITEM_PROP_DEICIDE_VALUE_BEGIN = 121,	  //
	ITEM_PROP_DEICIDE_VALUE_END = 128,		  //
	ITEM_PROP_DEICIDE_TEMP_IDX_BEGIN = 131,	  // 临时
	ITEM_PROP_DEICIDE_TEMP_IDX_END = 138,	  // 临时
	ITEM_PROP_DEICIDE_TEMP_VALUE_BEGIN = 141, // 临时
	ITEM_PROP_DEICIDE_TEMP_VALUE_END = 148,	  // 临时
	ITEM_PROP_DEICIDE_NUMS = 151,			  // 弑神特殊属性 条数
	ITEM_PROP_DEICIDE_TEMP_NUMS = 152,		  // 弑神特殊属性 临时条数
	ITEM_PROP_DEICIDE_TEMP_SID = 153,		  // 弑神特殊属性 临时sid

	// 神兵
	ITEM_PROP_ARTIFACT_STEP = 160, // 当前神兵阶数
	// 神兵当前资质
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_BEGIN = 161,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_1 = 161,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_2 = 162,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_3 = 163,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_4 = 164,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_5 = 165,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_6 = 166,
	ITEM_PROP_ARTIFACT_CUR_APTITUDE_END = 166,
	// 神兵资质上限
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_BEGIN = 171,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_1 = 171,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_2 = 172,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_3 = 173,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_4 = 174,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_5 = 175,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_6 = 176,
	ITEM_PROP_ARTIFACT_MAX_APTITUDE_END = 176,

	ITEM_PROP_MOWEN_ID = 177, // 魔纹
	ITEM_PROP_INCREASE = 178, // 装备增幅等级
	ITEM_PROP_PROTECT = 179,  // 装备投保状态
	ITEM_PROP_UP_STAR = 180,  // 装备升星等级
	ITEM_PROP_RONGLIAN_LEVEL = 181, // 装备熔炼等级
	ITEM_PROP_BROKEN_STATE = 182, // 装备破损状态

	ITEM_PROP_MAX,

	/*--------下面为无效属性-----------------------------------------------
	--------旧版本 定义过，新版本未使用，没删除的； 如果要使用 请放置到 ITEM_PROP_MAX 之前---------------------------------*/
	ITEM_PROP_ENHANCE_LEVEL = 20001, // 物品强化等级
	ITEM_PROP_DATA_COMBO = 20002,	 // DataCombo
	ITEM_PROP_DATA_X = 20003,		 // DataX
	ITEM_PROP_DATA_Y = 20004,		 // DataY
	ITEM_PROP_DATA_Z = 20005,		 // DataZ
	ITEM_PROP_REBORN_LEVEL = 20009,	 // 转生等级
	ITEM_PROP_EQUIP_MAX = 20010,
	ITEM_PROP_MARKET_TYPE = 20012,	// 摆摊出售价格类型
	ITEM_PROP_MARKET_PRICE = 20013, // 摆摊出售价格

	ITEM_PROP_EXP_STORE = 20015,	 // 经验存储
	ITEM_PROP_POLISH = 20017,		 // 打磨
	ITEM_PROP_FOOT_POLISH = 20019,	 // 足迹
	ITEM_PROP_QL_POLISH = 20020,	 // 启灵
	ITEM_PROP_COLOR_LEVEL = 20023,	 // 颜色等级
	ITEM_PROP_EVALUATECOUNT = 20024, // 鉴定次数
	ITEM_PROP_ENHANCE_CNT = 20025,	 // 强化次数
	ITEM_PROP_ENHANCE_TIMES = 20025, // 物品强化次数
	ITEM_PROP_SOUL_LEVEL = 20026,	 // 物品注灵等级
	// 洗练属性
	ITEM_PROP_XL_PATK = 20027,			   // 物攻
	ITEM_PROP_XL_PATK_MAX = 20028,		   // 最大物攻
	ITEM_PROP_XL_PATK_ADD = 20029,		   // 增加物攻
	ITEM_PROP_XL_MATK = 20030,			   // 魔攻
	ITEM_PROP_XL_MATK_MAX = 20031,		   // 最大魔攻
	ITEM_PROP_XL_MATK_ADD = 20032,		   // 增加魔攻
	ITEM_PROP_XL_TATK = 20033,			   // 道功
	ITEM_PROP_XL_TATK_MAX = 20034,		   // 最大道功
	ITEM_PROP_XL_TATK_ADD = 20035,		   // 增加道功
	ITEM_PROP_LY_LEVEL = 20036,			   // 蓝月神装激活等级
	ITEM_PROP_XL_PDEF = 20039,			   // 物防
	ITEM_PROP_XL_PDEF_MAX = 20040,		   // 最大物防
	ITEM_PROP_XL_PDEF_ADD = 20041,		   // 增加物防
	ITEM_PROP_XL_MDEF = 20042,			   // 魔防
	ITEM_PROP_XL_MDEF_MAX = 20043,		   // 最大魔防
	ITEM_PROP_XL_MDEF_ADD = 20044,		   // 增加魔防
	ITEM_PROP_XL_LUCKY = 20045,			   // 幸运
	ITEM_PROP_XL_LUCKY_ADD = 20046,		   // 增加幸运
	ITEM_PROP_XL_CRIT = 20047,			   // 暴击率
	ITEM_PROP_XL_CRIT_ADD = 20048,		   // 增加暴击率
	ITEM_PROP_XL_CRIT_DEFENSE = 20049,	   // 暴击抗性
	ITEM_PROP_XL_CRIT_DEFENSE_ADD = 20050, // 增加暴击抗性
	ITEM_PROP_XL_CRIT_DAMAGE = 20051,	   // 暴击伤害(暴击力)
	ITEM_PROP_XL_CRIT_DAMAGE_ADD = 20052,  // 增加暴击伤害(暴击力)
	ITEM_PROP_XL_CRIT_IMMUNE = 20053,	   // 暴击免伤)
	ITEM_PROP_XL_CRIT_IMMUNE_ADD = 20054,  // 增加暴击免伤
	ITEM_PROP_XL_LEVEL = 20055,			   // 洗练等级
	ITEM_PROP_XL_FIRST = 20056,			   // 首次（0：首次，1：非首次）
	ITEM_PROP_XL_NEED_SAVE = 20057,		   // 是否需要保存
	ITEM_PROP_ADDED_1 = 20061,			   // 符文系统装配的极品属性1
	ITEM_PROP_ADDED_2 = 20062,			   // 符文系统装配的极品属性2
	ITEM_PROP_ADDED_3 = 20063,			   // 符文系统装配的极品属性3
	ITEM_PROP_ADDED_4 = 20064,			   // 符文系统装配的极品属性4
	ITEM_PROP_ADDED_5 = 20065,			   // 符文系统装配的极品属性5
	ITEM_PROP_ADDED_6 = 20066,			   // 符文系统装配的极品属性6
	ITEM_PROP_ADDED_VALUE_1 = 20067,	   // 符文系统装配的极品属性1的值
	ITEM_PROP_ADDED_VALUE_2 = 20068,	   // 符文系统装配的极品属性2的值
	ITEM_PROP_ADDED_VALUE_3 = 20069,	   // 符文系统装配的极品属性3的值
	ITEM_PROP_ADDED_VALUE_4 = 20070,	   // 符文系统装配的极品属性4的值
	ITEM_PROP_ADDED_VALUE_5 = 20071,	   // 符文系统装配的极品属性5的值
	ITEM_PROP_ADDED_VALUE_6 = 20072,	   // 符文系统装配的极品属性6的值
	ITEM_PROP_NORMAL_1 = 20081,			   // 符文系统装配的普通属性1
	ITEM_PROP_NORMAL_2 = 20082,			   // 符文系统装配的普通属性2
	ITEM_PROP_NORMAL_3 = 20083,			   // 符文系统装配的普通属性3
	ITEM_PROP_NORMAL_4 = 20084,			   // 符文系统装配的普通属性4
	ITEM_PROP_NORMAL_5 = 20085,			   // 符文系统装配的普通属性5
	ITEM_PROP_NORMAL_VALUE_1 = 20087,	   // 符文系统装配的普通属性1的值
	ITEM_PROP_NORMAL_VALUE_2 = 20088,	   // 符文系统装配的普通属性2的值
	ITEM_PROP_NORMAL_VALUE_3 = 20089,	   // 符文系统装配的普通属性3的值
	ITEM_PROP_NORMAL_VALUE_4 = 20090,	   // 符文系统装配的普通属性4的值
	ITEM_PROP_NORMAL_VALUE_5 = 20091,	   // 符文系统装配的普通属性5的值
	ITEM_PROP_REMOULD_COUNT = 20100,	   // 物品改造次数
	ITEM_PROP_RUNE_LEVEL = 20101,		   // 技能符文等级
	ITEM_PROP_FULING_LEVEL = 20105,		   // 附灵等级
	ITEM_PROP_FULING_EXP = 20106,		   // 附灵当前经验
										   /*必看*/
										   /*必看*/
										   /*必看*/
										   //---------不能在这定义物品属性-----------------------------//
										   //--请在 ITEM_PROP_MAX 之前定义物品属性---------------------//
										   /*必看*/
										   /*必看*/
										   /*必看*/
};

// 特殊物品静态ID
enum ItemStaticID
{
	ITEM_EXP = 1,		   // 经验
	ITEM_COIN = 2,		   // 金币
	ITEM_LINGFU = 3,	   // 灵符
	ITEM_INGOT = 4,		   // 元宝
	ITEM_BIND_INGOT = 5,   // 绑定元宝
	ITEM_BIND_LINGFU = 6,  // 绑定灵符
	ITEM_GONGXUN = 8, //功勋
	ITEM_LINGFU_ALL = 100, // 灵符+绑定灵符
	ITEM_INGOT_ALL = 101,  // 元宝+绑定元宝
};

// 特殊物品类型
enum ThingsType
{
	THINGS_EXP = 1,				// 经验
	THINGS_COIN = 2,			// 金币
	THINGS_LINGFU = 3,			// 灵符
	THINGS_INGOT = 4,			// 元宝
	THINGS_BOUND_INGOT = 5,		// 绑定元宝
	THINGS_BOUND_LINGFU = 6,	// 绑定灵符
	THINGS_LINGFU_ALL = 100,	// 灵符+绑定灵符
	THINGS_INGOT_ALL = 101,		// 元宝+绑定元宝
	FINANCIAL_ACTIVETION = 102, // 理财激活物品

	THINGS_DOUBLE_RECHARGE1 = 10001, // 直充
	THINGS_DOUBLE_RECHARGE2 = 10002,
	THINGS_DOUBLE_RECHARGE3 = 10003,
	THINGS_DOUBLE_RECHARGE4 = 10004,
	THINGS_DOUBLE_RECHARGE5 = 10005,
	THINGS_DOUBLE_RECHARGE6 = 10006,
	THINGS_DOUBLE_RECHARGE7 = 10007,
	THINGS_DOUBLE_RECHARGE8 = 10008,
	THINGS_DOUBLE_RECHARGE9 = 10009,
	THINGS_DOUBLE_RECHARGE10 = 10010,
	THINGS_DOUBLE_RECHARGE11 = 10011,

	THINGS_TUOGUAN_MONTH_CARD = 10021, // 托管月卡
	THINGS_TEHUI_MONTH_CARD = 10022,   // 特惠月卡
	THINGS_TEHUI_WEEK_CARD = 10023,	   // 特惠周卡
	THINGS_MONSTER_KILL = 10024,	   // 怪物通缉
	THINGS_ZHANLING_1 = 10025,		   // 中级战令
	THINGS_ZHANLING_2 = 10026,		   // 高级战令
	THINGS_TOUZI_LEVEL = 10027,		   // 升级基金
	THINGS_TOUZI_REBORN = 10028,	   // 转生基金
	THINGS_LIMIT_TIME_GIFT_1 = 10031,  // 12转礼包
	THINGS_LIMIT_TIME_GIFT_2 = 10032,  // 限时礼包2

	THINGS_DAILY_RECHARGE1 = 10041, // 3元每日礼包
	THINGS_DAILY_RECHARGE2 = 10042, // 6元每日礼包
	THINGS_DAILY_RECHARGE3 = 10044, // 9元每日礼包
	THINGS_DAILY_RECHARGE4 = 10045, // 12元全部礼包

	THINGS_CASH_BUY_1 = 10046,	// 10元现金直购
	THINGS_CASH_BUY_2 = 10047,	// 30元现金直购
	THINGS_CASH_BUY_3 = 10048,	// 68元现金直购
	THINGS_CASH_BUY_4 = 10049,	// 98元现金直购
	THINGS_CASH_BUY_5 = 10050,	// 128元现金直购
	THINGS_CASH_BUY_6 = 10051,	// 328元现金直购
	THINGS_CASH_BUY_7 = 10052,	// 648元现金直购
	THINGS_CASH_BUY_8 = 10053,	// 888元现金直购
	THINGS_CASH_BUY_9 = 10054,	// 1200元现金直购
	THINGS_CASH_BUY_10 = 10055, // 198元现金直购
	THINGS_CASH_BUY_11 = 10056, // 558元现金直购
	THINGS_CASH_BUY_12 = 10057, // 988元现金直购
	THINGS_CASH_BUY_13 = 10058, // 1800元现金直购
	THINGS_CASH_BUY_14 = 10059, // 298元现金直购
	THINGS_CASH_BUY_15 = 10060, // 88元现金直购
	THINGS_CASH_BUY_16 = 10061, // 148元现金直购
	THINGS_CASH_BUY_17 = 10062, // 2000元现金直购

	OPERATE_THINGS_CASH_BUY_1 = 10066,	// 运营活动 10元现金直购
	OPERATE_THINGS_CASH_BUY_2 = 10067,	// 运营活动 30元现金直购
	OPERATE_THINGS_CASH_BUY_3 = 10068,	// 运营活动 68元现金直购
	OPERATE_THINGS_CASH_BUY_4 = 10069,	// 运营活动 98元现金直购
	OPERATE_THINGS_CASH_BUY_5 = 10070,	// 运营活动 128元现金直购
	OPERATE_THINGS_CASH_BUY_6 = 10071,	// 运营活动 328元现金直购
	OPERATE_THINGS_CASH_BUY_7 = 10072,	// 运营活动 648元现金直购
	OPERATE_THINGS_CASH_BUY_8 = 10073,	// 运营活动 888元现金直购
	OPERATE_THINGS_CASH_BUY_9 = 10074,	// 运营活动1200元现金直购
	OPERATE_THINGS_CASH_BUY_10 = 10075, // 运营活动198元现金直购
	OPERATE_THINGS_CASH_BUY_11 = 10076, // 运营活动558元现金直购
	OPERATE_THINGS_CASH_BUY_12 = 10077, // 运营活动988元现金直购
	OPERATE_THINGS_CASH_BUY_13 = 10078, // 运营活动1800元现金直购
	OPERATE_THINGS_CASH_BUY_14 = 10079, // 运营活动298元现金直购
	OPERATE_THINGS_CASH_BUY_15 = 10080, // 运营活动88元现金直购
	OPERATE_THINGS_CASH_BUY_16 = 10081, // 运营活动148元现金直购
	OPERATE_THINGS_CASH_BUY_17 = 10082, // 运营活动2000元现金直购
	OPERATE_THINGS_CASH_BUY_18 = 10083, // 运营活动100元每日礼包
	OPERATE_THINGS_CASH_BUY_19 = 10084, // 运营活动200元每日礼包
	OPERATE_THINGS_CASH_BUY_20 = 10085, // 运营活动1000元每日礼包
	OPERATE_THINGS_CASH_BUY_21 = 10086, // 运营活动1500元每日礼包
	OPERATE_THINGS_CASH_BUY_22 = 10087, // 运营活动2000元每日礼包
	OPERATE_THINGS_CASH_BUY_23 = 10088, // 运营活动100元每日礼包
	OPERATE_THINGS_CASH_BUY_24 = 10089, // 运营活动200元每日礼包
	OPERATE_THINGS_CASH_BUY_25 = 10090, // 运营活动1000元每日礼包
	OPERATE_THINGS_CASH_BUY_26 = 10091, // 运营活动1500元每日礼包
	OPERATE_THINGS_CASH_BUY_27 = 10092, // 运营活动2000元每日礼包
	OPERATE_THINGS_CASH_BUY_28 = 10093, // 运营活动888元每日礼包
	OPERATE_THINGS_CASH_BUY_29 = 10094, // 运营活动1200元每日礼包

	THINGS_ZHANLING_START = 15000,
	THINGS_ZHANLING_01 = 15001, // 中级战令
	THINGS_ZHANLING_02 = 15002, // 高级战令
	THINGS_ZHANLING_11 = 15003, // 中级战令
	THINGS_ZHANLING_12 = 15004, // 高级战令
	THINGS_ZHANLING_21 = 15005, // 中级战令
	THINGS_ZHANLING_22 = 15006, // 高级战令
	THINGS_ZHANLING_31 = 15007, // 中级战令
	THINGS_ZHANLING_32 = 15008, // 高级战令
	THINGS_ZHANLING_41 = 15009, // 中级战令
	THINGS_ZHANLING_42 = 15010, // 高级战令
	THINGS_ZHANLING_51 = 15011, // 中级战令
	THINGS_ZHANLING_52 = 15012, // 高级战令
	THINGS_ZHANLING_61 = 15013, // 中级战令
	THINGS_ZHANLING_62 = 15014, // 高级战令
	THINGS_ZHANLING_71 = 15015, // 中级战令
	THINGS_ZHANLING_72 = 15016, // 高级战令
	THINGS_ZHANLING_81 = 15017, // 中级战令
	THINGS_ZHANLING_82 = 15018, // 高级战令
	THINGS_ZHANLING_91 = 15019, // 中级战令
	THINGS_ZHANLING_92 = 15020, // 高级战令
	THINGS_ZHANLING_END = 15100,

	THINGS_YBHS_DOUBLE = 15101, // 装备回收双倍
	THINGS_TRADE_CARD  = 15102, // 交易卡直购
};

enum CombatPercent
{
	COMBAT_PERCENT_TO_INT = 100,
};

// 战斗属性
enum CombatProp
{
	COMBAT_PROP_BEGIN = 0,
	// 战斗属性开始
	COMBAT_PROP_HP_MAX = 1, // 最大血量值
	COMBAT_PROP_MP_MAX = 2, // 最大魔法值
	COMBAT_PROP_HP = 3,		// 当前血量值
	COMBAT_PROP_MP = 4,		// 当前魔法值
	COMBAT_PROP_PATK = 5,	// 物理攻击力
	COMBAT_PROP_PATK_MIN = 5,
	COMBAT_PROP_PATK_MAX = 6,
	COMBAT_PROP_MATK = 7, // 魔法攻击力
	COMBAT_PROP_MATK_MIN = 7,
	COMBAT_PROP_MATK_MAX = 8,
	COMBAT_PROP_TATK = 9, // 道术攻击力
	COMBAT_PROP_TATK_MIN = 9,
	COMBAT_PROP_TATK_MAX = 10,
	COMBAT_PROP_PDEF = 11, // 物理防御
	COMBAT_PROP_PDEF_MIN = 11,
	COMBAT_PROP_PDEF_MAX = 12,
	COMBAT_PROP_MDEF = 13, // 魔法防御
	COMBAT_PROP_MDEF_MIN = 13,
	COMBAT_PROP_MDEF_MAX = 14,
	COMBAT_PROP_PATK_PRO = 15,				  // 物攻加成（上下限都有效）（万分比）
	COMBAT_PROP_MATK_PRO = 16,				  // 魔攻加成（上下限都有效）（万分比）
	COMBAT_PROP_TATK_PRO = 17,				  // 道攻加成（上下限都有效）（万分比）
	COMBAT_PROP_TOTAL_ATK_PRO = 18,			  // 攻击增伤（上下限都有效）（万分比）
	COMBAT_PROP_PDEF_PRO = 19,				  // 物防加成（上下限都有效） (万分比)
	COMBAT_PROP_MDEF_PRO = 20,				  // 魔防加成（上下限都有效） (万分比)
	COMBAT_PROP_TOTAL_DEF_PRO = 21,			  // 防御增加（上下限都有效） (万分比)
	COMBAT_PROP_SUCK_BLOOD = 22,			  // 吸血 (万分比)
	COMBAT_PROP_SUCK_BLOOD_RESIST = 23,		  // 吸血抵抗 (万分比)
	COMBAT_PROP_HIT = 24,					  // 命中(准确)
	COMBAT_PROP_DODGE = 25,					  // 闪避(敏捷)
	COMBAT_PROP_RELIVE_RESIST = 26,			  // 复活抵抗（万分比）
	COMBAT_PROP_CRITICAL_RATE = 27,			  // 暴击概率（万分比）
	COMBAT_PROP_CRITICAL_DAMAGE = 28,		  // 暴击伤害（数值）
	COMBAT_PROP_DROPRATE = 29,				  // 掉率(极品掉率)（万分比）
	COMBAT_PROP_EXTRA_DROPRATE = 30,		  // 掉率( 额外掉率)（万分比）
	COMBAT_PROP_PATK_IGNORE = 31,			  // 物理减免（万分比）
	COMBAT_PROP_MATK_IGNORE = 32,			  // 魔法减免（万分比）
	COMBAT_PROP_REBOUND_ATK = 33,			  // 反伤（万分比）
	COMBAT_PROP_IGNORE_REBOUND_ATK = 34,	  // 反伤减免（万分比）
	COMBAT_PROP_PALSY = 35,					  // 触发麻痹几率%(万分比)
	COMBAT_PROP_PALSY_RESISTANCE = 36,		  // 麻痹抗性几率%(万分比)
	COMBAT_PROP_PARRY_DAMAGE = 37,			  // 格挡伤害[万分比]
	COMBAT_PROP_CUT_FIXED_DAMAGE = 38,		  // 切割，对怪物产生的格外固定伤害
	COMBAT_PROP_PK_DEFENCE_VALUE = 39,		  // pk护盾值[当前值]
	COMBAT_PROP_PK_IGNORE_DEFENCE_VALUE = 40, // pk破盾值
	COMBAT_PROP_MONSTER_DODGE_RESIST = 41,	  // 忽视怪物闪避（无视虚化）
	COMBAT_PROP_MONSTER_SUCK_RESIST = 42,	  // 减低怪物回血（万分比）
	COMBAT_PROP_ZODIAC = 43,				  // 生肖之力
	COMBAT_PROP_MRP = 44,					  // 魔法恢复
	COMBAT_PROP_HRP = 45,					  // 生命恢复
	COMBAT_PROP_DESATK_TO_PLAYER = 46,		  // 怪物对玩家造成伤害减免（万分比）
	COMBAT_PROP_DESATK_TO_PLAYER_VALUE = 47,  // 怪物对玩家造成伤害减免固定值
	COMBAT_PROP_ADDATK_TO_MONSTER = 48,		  // 增加对怪物的伤害 （万分比）
	COMBAT_PROP_ADDATK_TO_PLAYER = 49,		  // 增加对玩家的伤害<PVP增加> （万分比）
	COMBAT_PROP_ADDATK_TO_PLAYER_RESIST = 50, // 减少受玩家的伤害<PVP减伤> （万分比）
	COMBAT_PROP_CRITICAL_RATE_RESIST = 51,	  // 暴击抵抗（万分比）
	COMBAT_PROP_IGNORE_DEF = 52,			  // 忽视防御（万分比）
	COMBAT_PROP_IGNORE_PDEF = 53,			  // 忽视物防（万分比）
	COMBAT_PROP_IGNORE_MDEF = 54,			  // 忽视魔防（万分比）
	COMBAT_PROP_HP_ADD = 55,				  // 生命加成（万分比）
	COMBAT_PROP_GUARD_HALO = 56,			  // 守护触发概率（万分比，成功则免疫本次受到伤害，并飘字“守护-1”，扣1点血）
	COMBAT_PROP_DROP_EQUIP_RESIST = 57,		  // 降低装备被爆概率（万分比）
	COMBAT_PROP_CRITICAL_INGORE = 58,		  // 暴击减免（万分比）
	COMBAT_PROP_MONSTER_DODGE = 59,			  // 怪物闪避（虚化）
	COMBAT_PROP_CLASS_ATK = 60,				  // 根据职业增加攻击
	COMBAT_PROP_CLASS_ATK_MIN = 60,			  // 根据职业增加攻击小（具体值）
	COMBAT_PROP_CLASS_ATK_MAX = 61,			  // 根据职业增加攻击大（具体值）
	COMBAT_PROP_PK_DEFENCE_VALUE_MAX = 62,	  // pk护盾值[最大值]
	COMBAT_PROP_ADD_DAMAGE_TRUE = 63,		  // 放大最终伤害（万分比）
	COMBAT_PROP_CLASS_ATK_PRO = 64,			  // 根据职业增加攻击加成
	COMBAT_PROP_PK_DROP = 65,				  // 自身爆对方装备概率（万分比）
	COMBAT_PROP_PK_DROP_RESIST = 66,		  // 自身免爆（万分比）
	COMBAT_PROP_MP_ADD = 67,				  // 魔法加成（万分比）
	COMBAT_PROP_MONSTER_SHIELD = 68,		  // 怪物护盾减伤（具体值）
	COMBAT_PROP_ACCELERATION_ATTACK = 69,	  // 攻击速度
	COMBAT_PROP_HP_MAX_ADD = 70,			  // 最大血量值翻倍（万分比）
	COMBAT_PROP_MP_MAX_ADD = 71,			  // 最大魔法值翻倍（万分比）
	COMBAT_PROP_ATK_IGNORE_MISS = 72,		  // 攻击者无视目标的伤害减免
	COMBAT_PROP_BOOK_BOSS_EX = 73,			  // 图鉴boss额外加伤（万分比）
	COMBAT_PROP_LUCK = 74,					  // 幸运
	COMBAT_PROP_CURSE = 75,					  // 诅咒

	//[原属性后面跟EX]其他情况添加的战斗属性，不会改变原属性（BUFF类的）
	COMBAT_PROP_PATK_PRO_EX = 101,			//[BUFF]物攻加成（上下限都有效）（万分比）
	COMBAT_PROP_MATK_PRO_EX = 102,			//[BUFF]魔攻加成（上下限都有效）（万分比）
	COMBAT_PROP_TATK_PRO_EX = 103,			//[BUFF]道攻加成（上下限都有效）（万分比）
	COMBAT_PROP_TOTAL_ATK_PRO_EX = 104,		//[BUFF]攻击增伤（上下限都有效）（万分比）
	COMBAT_PROP_PDEF_PRO_EX = 105,			//[BUFF]物防加成（上下限都有效） (万分比)
	COMBAT_PROP_MDEF_PRO_EX = 106,			//[BUFF]魔防加成（上下限都有效） (万分比)
	COMBAT_PROP_TOTAL_DEF_PRO_EX = 107,		//[BUFF]防御增加（上下限都有效） (万分比)
	COMBAT_PROP_SUCK_BLOOD_EX = 108,		//[BUFF]吸血 (万分比)
	COMBAT_PROP_SUCK_BLOOD_RESIST_EX = 109, //[BUFF]吸血抵抗 (万分比)
	COMBAT_PROP_CRITICAL_RATE_EX = 110,		//[BUFF]暴击概率（万分比）
	COMBAT_PROP_CRITICAL_DAMAGE_EX = 111,	//[BUFF]暴击伤害（万分比）
	COMBAT_PROP_DROPRATE_EX = 112,			//[BUFF]掉率(极品掉率)（万分比）
	///////////////////////////////////////////////////////////////////////

	COMBAT_PROP_HP_MAX_EX = 199, // 血量超过21亿后 扩展（高位32位）
	COMBAT_PROP_NORMAL_END = 200,

	COMBAT_PROP_MUTI_BEGIN = 200, // COMBAT_PROP_MUTI_BEGIN
	COMBAT_PROP_MUTI_END = 400,	  // COMBAT_PROP_MUTI_BEGIN + COMBAT_PROP_MUTI_BEGIN,

	COMBAT_PROP_END,

};

// enum Immunity
//{
//	IMMUNITY_FIRE		= 1,
//	IMMUNITY_WET		= 2,
//	IMMUNITY_THUNDER	= 3,
//	IMMUNITY_MAX		= 100,
// };

// 战斗系统一些标志位
enum CombatFlag
{
	COMBAT_FLAG_STICK = 1,		   // 沉默
	COMBAT_FLAG_DAZE = 2,		   // 定身
	COMBAT_FLAG_SPEED_STRANGE = 4, // 加速器惩罚
};

// 被攻击生命值未改变原因
enum BeAttackNoChangeHP
{
	COMBAT_MISS = 0,	 // 闪避
	COMBAT_IMMUNITY = 1, // 免疫
};

// 技能属性
enum SkillProps
{
	SKILL_PROP_NEED_EXP = 0,	   // 技能是否需要经验值
	SKILL_PROP_RANGE = 1,		   // 技能范围
	SKILL_PROP_DISTANCE = 2,	   // 技能有效距离
	SKILL_PROP_COOLDOWN = 3,	   // 技能冷却时间
	SKILL_PROP_MANA = 4,		   // 技能魔法消耗
	SKILL_PROP_EXP = 5,			   // 技能经验值
	SKILL_PROP_USING_TIME = 6,	   // 技能从什么何时起可以使用
	SKILL_PROP_USE_TYPE = 7,	   // 技能使用类型(对实体使用,对位置使用等)
	SKILL_PROP_NEED_ACCELE = 8,	   // CD受攻速影响
	SKILL_PROP_NEXTCD = 12,		   // 下一次技能冷却时间
	SKILL_PROP_POSITION = 13,	   // 位置
	SKILL_PROP_USING_TIME_EX = 14, // 技能从什么何时起可以使用(高32位)
	SKILL_PROP_DATA_X = 15,
	SKILL_PROP_DATA_Y = 16,
	SKILL_PROP_DATA_Z = 17,
	SKILL_PROP_SHIELD_TARGET = 18,	  // 屏蔽对象
	SKILL_PROP_IS_NORMAL_ATTACK = 19, // 是否是普通攻击
	SKILL_PROP_ADVANCE_LEVEL = 20,	  // 进阶等级
	SKILL_PROP_LEVEL = 23,			  // 技能等级
	SKILL_PROP_DAMAGE_ADD = 24,		  // 伤害增加的系数对应的战斗属性
	SKILL_PROP_COOLDOWN_DEC = 25,	  // 减CD
	SKILL_PROP_POWER_RATE = 26,		  // 技能威力加成 百分比

	SKILL_PROP_MAX = 27, // 技能属性个数
};

// 技能使用类型
enum SkillUseType
{
	SKILL_USE_ON_ENTITY = 1, // 对实体使用
	SKILL_USE_ON_POS = 2,	 // 对位置使用
};

// 场景技能范围
enum SceneSkillRange
{
	SKILL_SCENE_RANGE_1 = 1, // 范围是1*1
	SKILL_SCENE_RANGE_3 = 3, // 范围是3*3
};

// 技能目标搜索类型
enum SkillSearcherType
{
	SKILL_SEARCHER_SINGLE = 1,			 // 单体
	SKILL_SEARCHER_AROUND = 2,			 // 周围
	SKILL_SEARCHER_SELF = 3,			 // 自身
	SKILL_SEARCHER_HALF_MOON = 4,		 // 半月
	SKILL_SEARCHER_STRAIGHT = 5,		 // 前线
	SKILL_SEARCHER_CROSS = 6,			 // 十字
	SKILL_SEARCHER_AREA = 7,			 // 区域 3*3
	SKILL_SEARCHER_LINE = 8,			 // 对称直线
	SKILL_SEARCHER_STRAIGHT_MOVE = 9,	 // 向前移动[野蛮冲撞]
	SKILL_SEARCHER_ALL = 10,			 // 当前场景
	SKILL_SEARCHER_RANDOM = 11,			 // 随机一个点的周围区域
	SKILL_SEARCHER_AREA_BIG = 12,		 // 区域 7*7
	SKILL_SEARCHER_SCREEN = 13,			 // 区域 16*16
	SKILL_SEARCHER_HALF_SCREEN = 14,	 // 半区域 16 *16
	SKILL_SEARCHER_TRIPLE_STRAIGHT = 15, // 前线加粗[宽度为3]
};

// 技能目标类型
enum SkillTargetType
{
	SKILL_TARGET_NONE = -10,  // 非目标
	SKILL_TARGET_MAIN = -1,	  // 主目标
	SKILL_TARGET_SPLASH = -2, // 其他目标
	SKILL_TARGET_SELF = -3,	  // 自己
};

// 技能执行器属性
enum SkillExecuterProp
{
	EXECUTER_PROP_CLEAR_DYDATA = 0, // 清除EXECUTER_PROP_MISSED和EXECUTER_PROP_DAMAGE
	EXECUTER_PROP_FLAGS = 1,		// 暴击等标记
	EXECUTER_PROP_KILL_SHEILD = 3,	// 减少护盾时间
	EXECUTER_PROP_MISSED = 50,		// 未击中(闪避)
	EXECUTER_PROP_DAMAGE = 51,		// 伤害
	EXECUTER_PROP_BASE_DAMAGE = 52, // 基础伤害
	EXECUTER_PROP_REAL_DAMAGE = 53, // 是否是真实伤害
	EXECUTER_PROP_USER_DATA = 54,	// 自定义数据 用来处理某些奇怪需求
};

// 技能执行器标记
enum SkillExecuterFlags
{
	EXECUTER_FLAG_CRIT = 1,			// 暴击
	EXECUTER_FLAG_PRESTIGE = 2,		// 威慑
	EXECUTER_FLAG_BOSS_SCORE = 3,	// BOSS 积分
	EXECUTER_FLAG_HEJI = 4,			// 合击
	EXECUTER_FLAG_DEATH_DAMAGE = 5, // 致命一击
	EXECUTER_FALG_SUCK_BLOOD = 6,	// 吸血
};

// 方向
//   7 | 0  | 1
//----+----+----
//   6 | X  | 2
//----+----+----
//   5 | 4  | 3
enum Direction
{
	DIR_UP = 0,			// 上
	DIR_UP_RIGHT = 1,	// 右上
	DIR_RIGHT = 2,		// 右
	DIR_DOWN_RIGHT = 3, // 右下
	DIR_DOWN = 4,		// 下
	DIR_DOWN_LEFT = 5,	// 左下
	DIR_LEFT = 6,		// 左
	DIR_UP_LEFT = 7,	// 左上

	DIR_COUNT = 8 // 方向个数
};

static const short SearchMonsterByDirection[8][5] =
	{
		{1, 2, 3, 4, 6},
		{1, 2, 3, 6, 9},
		{2, 3, 6, 8, 9},
		{3, 6, 7, 8, 9},
		{4, 6, 7, 8, 9},
		{1, 4, 7, 8, 9},
		{1, 2, 4, 7, 8},
		{1, 2, 3, 4, 7},
};

// 移动类型
enum MoveType
{
	MOVE_TYPE_WALK = 1,		 // 走路
	MOVE_TYPE_RUN = 2,		 // 跑步
	MOVE_TYPE_COLLIDE = 100, // 碰撞
	MOVE_TYPE_FLY = 101,	 // 飞行
	MOVE_TYPE_QLS = 102,	 // 擒龙手
	MOVE_TYPE_SBYS = 103,	 // 十步一杀
	MOVE_TYPE_BE_COLLIDE = 104,	//被野蛮

};

// for the lefttop--(0,0) Coordinate system
static const short move_step[8][2] =
	{
		{0, 1}, {1, -1}, {1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {-1, 0}, {1, 1}};

// for the leftbottom--(0,0) Coordinate system
static const short tile_step[8][2] =
	{
		{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

static const short triple_tile_step[3][8][2] =
	{
		{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{-1, 0}, {0, -1}, {0, -1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {-1, 0}},
		{{1, 0}, {1, 0}, {0, 1}, {0, 1}, {-1, 0}, {-1, 0}, {0, -1}, {0, -1}},
};

static const short smallhalfmoon[8][3][2] =
	{
		{{1, 0}, {-1, 0}, {1, 1}},
		{{0, 1}, {-1, 0}, {0, 2}},
		{{0, -1}, {0, 1}, {-1, -1}},
		{{-1, 0}, {0, -1}, {-2, 0}},
		{{-1, 0}, {1, 0}, {-1, -1}},
		{{0, -1}, {1, 0}, {0, -2}},
		{{0, 1}, {0, -1}, {1, 1}},
		{{1, 0}, {0, 1}, {2, 0}},
};
static const short halfmoon[8][4][2] =
	{
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
};

static const short longhalfmoon[8][7][2] =
	{
		{
			{-1, -1},
			{0, -1},
			{1, -1},
			{-1, 0},
			{1, 0},
			{-1, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{0, -1},
			{1, -1},
			{-1, 0},
			{1, 0},
			{0, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{0, -1},
			{1, -1},
			{1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
		},
		{
			{0, -1},
			{1, -1},
			{-1, 0},
			{1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{1, -1},
			{-1, 0},
			{1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{0, -1},
			{-1, 0},
			{1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{0, -1},
			{1, -1},
			{-1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
		},
		{
			{-1, -1},
			{0, -1},
			{1, -1},
			{-1, 0},
			{1, 0},
			{-1, 1},
			{0, 1},
		},
};

// 场景属性索引
enum SceneProp
{
	SCENE_PROP_SIZE_X = 1,			 // 场景在x轴方向大小
	SCENE_PROP_SIZE_Y = 2,			 // 场景在y轴方向大小
	SCENE_PROP_BLOCK_TYPE = 3,		 // 玩家是否是障碍物
	SCENE_PROP_PK_DROP = 4,			 // PK是否会爆装备
	SCENE_PROP_RELIVE_TYPE = 5,		 // 复活模式
	SCENE_PROP_LINE_ID = 7,			 // 分线ID
	SCENE_PROP_WAR_ZONE_LINE_ID = 8, // 战区分线ID
	SCENE_PROP_ADD_ROBOT_TIME = 9,	 // 上一次添加机器人的时间

	SCENE_PROP_SCENE_CLOSE = 20, // 场景是否已关闭?

	SCENE_PROP_NEXT_SCENE = 50,	   // 下一个场景实例ID
	SCENE_PROP_INSTANCE_TYPE = 51, // 副本类型

	SCENE_PROP_INSTANCE_BEGIN_SID = 53,
	SCENE_PROP_INSTANCE_PORTAL = 55,

	SCENE_PROP_ENTER_DISABLE = 70,		// 场景是否禁止进入
	SCENE_PROP_SKILL_LIMIT = 71,		// 场景是否限制使用某些技能
	SCENE_PROP_PET_LIMIT_IN = 72,		// 场景禁止宠物进入
	SCENE_PROP_DOG_LIMIT_IN = 73,		// 场景禁止狗进入
	SCENE_PROP_MARS_LIMIT_IN = 74,		// 场景禁止狗进入
	SCENE_PROP_HERO_LIMIT_IN = 75,		// 场景禁止英雄进入
	SCENE_PROP_LINE_ENTER_DISABLE = 76, // 场景分线是否可以进入 0可以进入 1不可以进入

	SCENE_PROP_SLHD_LAYER = 1091,
	SCENE_PROP_TIME_REMAIN = 1200, // 场景剩余时间
	SCENE_PROP_TIME_END = 1201,	   // 场景结束时间
	SCENE_PROP_JQBG_TIME = 1202,   // 激情闭关经验光圈刷新时间
	SCENE_PROP_MAX_MONSTER = 1203,
	SCENE_PROP_NOW_MONSTER = 1204,
	SCENE_PROP_OWNER_GUILD_ID = 1205,	   // 场景所属行会
	SCENE_PROP_TIME_START = 1206,		   // 场景开始时间
	SCENE_PROP_FTXG_MONSTER = 1207,		   // 梵天星宫开始数据
	SCENE_PROP_KILL_COUNT = 1208,		   // 夜袭比奇城连杀次数
	SCENE_PROP_YSJDC_RANK = 1209,		   // 夜袭比奇城实时排名
	SCENE_PROP_YSJDC_RANK_FINAL = 1210,	   // 夜袭比奇城最终排名
	SCENE_PROP_CHECK_AGAIN = 1211,		   // 告诉客户端重新寻路
	SCENE_PROP_MZRQ_RANK = 1212,		   // 魔族入侵实时排名
	SCENE_PROP_SWY_RANK = 1213,			   // 神威狱实时排名
	SCENE_PROP_ALIVE_PLAYER_COUNTS = 1214, // 场景内存活玩家数量

	SCENE_PROP_GTCL_STATE = 1220,				 // 宫廷长廊状态
	SCENE_PROP_GTCL_TIME = 1221,				 // 宫廷长廊时间
	SCENE_PROP_GTCL_TIME_POINT = 1222,			 // 宫廷长廊时间
	SCENE_PROP_GTCL_OWNER = 1223,				 // 宫廷长廊
	SCENE_PROP_YZBQ_TOP = 1224,					 //  夜战比奇积分最高的
	SCENE_PROP_MYWS_TYPE = 1225,				 // 玛雅卫士 是否刷新  0 已经刷新不能进入  1 刚刚被击杀 20分钟传送门  2 迪亚波罗 多久刷出来
	SCENE_PROP_MYWS_TIME = 1226,				 // 只是记录时间而已
	SCENE_PROP_SMMZ_RANK = 1229,				 // 石墓迷阵排行
	SCENE_PROP_GCZ_PLAYER_RANK = 1230,			 // 攻城战玩家排名
	SCENE_PROP_JZSL_FRESH_TIME = 1232,			 // 金猪刷新倒计时
	SCENE_PROP_JZ_ALIVE_COUNT = 1233,			 // 金猪存活数量
	SCENE_PROP_GUILD_BOSS_STATE = 1234,			 // 公会BOSS刷新状态
	SCENE_PROP_TXMJ_BOSS_DIE = 1235,			 // 世界boss死亡
	SCENE_PROP_SYT_PICK_TIME = 1236,			 // 世界boss物品可拾取倒计时
	SCENE_PROP_SYT_BOSS_DIE = 1237,				 // 锁妖塔顶层boss死亡
	SCENE_PROP_SMMS_STATUS = 1238,				 // 石墓密室活动状态
	SCENE_PROP_GCZ_HC_OPEN = 1239,				 // gcz皇宫开启
	SCENE_PROP_BOSS_REFRESH_TIME = 1240,		 // boss刷新时间
	SCENE_PROP_BOSS_REFRESH_CUTDOWN_TIME = 1241, // boss刷新倒计时
	SCENE_PROP_TOWER_TIME = 1242,				 // 爬塔倒计时
	SCENE_PROP_TOWER_SUCCESS_TIME = 1243,		 // 爬塔通关5秒倒计时
	SCENE_PROP_BOSS_DIE = 1244,					 // boss死亡
	SCENE_PROP_SECOND_HURT = 1245,				 //
	SCENE_PROP_TOWER_RESULT = 1246,				 // 爬塔结果
	SCENE_PROP_JZSL_TIME_LEFT = 1247,			 // 金龟送礼活动剩余时间
	SCENE_PROP_JZSL_FRESH_TIMES = 1248,			 // 金龟送礼刷新金龟次数
	SCENE_PROP_SMMZ_NOT_NOTIFY = 1249,			 // 猪洞迷阵广播首次进入地图
	SCENE_PROP_JFJP = 1250,
	SCENE_PROP_JZSL_DROP_BIND_INGOT = 1251, // 金猪送礼掉落绑定元宝次数
	SCENE_PROP_JZSL_DRO_INGOT = 1252,		// 金猪送礼掉落元宝次数
	SCENE_PROP_KFZB_START = 1253,			// 跨服争霸开始时间
	SCENE_PROP_KFZB_STATE = 1254,			// 跨服争霸活动状态  0未开启状态 1 两分钟准备状态 2活动开启状态
	SCENE_PROP_KFZB_PLAYER_COUNT = 1255,	// 跨服参与人数
	SCENE_PROP_KFZB_ALIVE_COUNT = 1256,		// 跨服活着人数
	SCENE_PROP_KFZB_TIME = 1257,			// 跨服时间
	SCENE_RPOP_SMMS_PREPARE_TIME = 1258,	// 准备时间倒计时
	SCENE_RPOP_SMMS_POISON_TIME = 1259,		// 刷毒倒计时
	SCENE_PROP_SMMS_POISON_DURATION = 1260, // 刷毒时长

	// 跨服3v3
	SCENE_PROP_BATTLE_SCENE_INDEX = 1270,	   // 跨服排位场景的场景索引
	SCENE_PROP_BATTLE_START_COUNTDOWN = 1271,  // 跨服排位战斗前倒计时
	SCENE_PROP_BATTLE_END_TIME = 1272,		   // 跨服排位战斗结束时间
	SCENE_PROP_BATTLE_END_COUNTDOWN = 1273,	   // 跨服排位战斗结束倒计时
	SCENE_PORP_RED_CAMP_PLAYER_COUNTS = 1274,  // 红色方人数
	SCENE_PORP_BLUE_CAMP_PLAYER_COUNTS = 1275, // 蓝色方人数
	SCENE_PROP_KFJJ_RANK_LIST = 1276,		   // 跨服竞技伤害排行
	SCENE_PROP_BATTLE_STATUS_END = 1277,	   // 当前对局结束

	// 新VIP副本
	SCENE_PROP_NEW_VIP_INSTANCE_INDEX = 1278,		   // 当前关卡idx
	SCENE_PROP_NEW_VIP_INSTANCE_END_TIME = 1279,	   // 挑战结束时间戳
	SCENE_PROP_VIP_INSTANCE_FRESH_MONSTER = 1280,	   // 刷新boss
	SCENE_PROP_VIP_INSTANCE_END_TIME_COUNTDOWN = 1281, // 挑战结束倒计时
	SCENE_PROP_VIP_INSTANCE_RESULT = 1282,			   // 挑战结果

	SCENE_PROP_WK_LD_COUNTDOWN = 1283, // 挖矿掠夺冷却时间
	SCENE_PROP_TXMJ_RANK_INFO = 1284,

	SCENE_PROP_SWZDZ_MAX_WAVES = 1290,		 // 最大波数
	SCENE_PROP_SWZDZ_CUR_WAVES = 1291,		 // 当前波数
	SCENE_PROP_SWZDZ_NEXT_WAVES_CD = 1292,	 // 下一波刷新时间
	SCENE_PROP_SWZDZ_BOX_BELONG_PID = 1293,	 // 宝箱归属PID
	SCENE_PROP_SWZDZ_BOX_BELONG_NAME = 1294, // 宝箱归属名（字符串）
	SCENE_PROP_SWZDZ_BOX_BELONG_CD = 1295,	 // 宝箱归属倒计时
	SCENE_PROP_CSZT_LEFT_TIME = 1296,		 // 副本倒计时
	SCENE_PROP_CSZT_PID = 1297,				 // 挑战者PID
	SCENE_PROP_CSZT_ENEMY_PID = 1298,		 // 被挑战者PID
	SCENE_PROP_CSZT_WIN_PID = 1299,			 // 胜利者PID

	SCENE_PROP_ADD_CROSS_NPC = 1300,  // 是否刷新跨服传送员
	SCENE_PROP_CSZT_FIGHT_CD = 1301,  // 开战倒计时
	SCENE_PROP_CSZT_ENEMY_EID = 1302, // 被挑战者EID
	SCENE_PROP_TGMJ_STATE = 1303,	  // 天关秘境爬塔进行状态
	SCENE_PROP_SMSZ_PIG_NUM = 1304,	  // 石墓烧猪场景猪数

	SCENE_PROP_NEW_WORLD_BOSS_RANK_1 = 1305, // 世界Boss排行1
	SCENE_PROP_NEW_WORLD_BOSS_RANK_2 = 1306, // 世界Boss排行2
	SCENE_PROP_NEW_WORLD_BOSS_RANK_3 = 1307, // 世界Boss排行3
	SCENE_PROP_SWY_GUILD_RANK = 1308,		 // 神威狱公会实时排名
	SCENE_PROP_SWY_BOSS_DIE = 1311,			 // 神威狱boss死亡

	SCENE_PROP_SBMB_STATE = 1314, // 神兵秘宝地图内是否已经刷过宝箱(0-初始状态  1-宝箱状态  2-生死门状态)
	SCENE_PROP_JRDT_STATE = 1315, // 节日地图内是否已经刷怪

	SCENE_PROP_GMD_BOSS_BATCH = 1316,		// 决战光明顶boss批次
	SCENE_PROP_GMD_BOSS_COUNT = 1317,		// 决战光明顶boss数量
	SCENE_PROR_GMD_RANK1 = 1318,			// 决战光明顶第一阶段排行
	SCENE_PROR_GMD_RANK2 = 1319,			// 决战光明顶第二阶段排行
	SCENE_PROP_GMD_TIMER = 1320,			// 决战光明顶TIMER
	SCENE_PROP_GMD_SQ_OWNER = 1321,			// 决战光明顶神器拥有者
	SCENE_PROP_GMD_FIRST_OVER_CHECK = 1322, // 决战光明顶第一阶段结束

	SCENE_PROP_GUARD_CUR_WAVES = 1323,			  // 守护副本刷怪阶段
	SCENE_PROP_GUARD_CUR_PID = 1324,			  // 守护副本归属玩家pid
	SCENE_PROP_FIRSTBLOOD_STATE = 1325,			  // 首杀boss是否存在  0 没有 1 存在
	SCENE_PROP_GUILD_BATTLE_PLAYER_RANK = 1326,	  // 行会对战玩家积分排名
	SCENE_PROP_GUILD_BATTLE_GUILD_RANK = 1327,	  // 行会对战行会积分排名
	SCENE_PROP_GUILD_BATTLE_FLAGS = 1328,		  // 行会对战战旗归属
	SCENE_PROP_SC_BOSS_BATTLE_PLAYER_RANK = 1329, // 沙城boss玩家伤害排名
	SCENE_PROP_HG_BOSS_BATTLE_PLAYER_RANK = 1330, // 皇宫boss玩家伤害排名
	SCENE_PROP_BOSS_HC_OPEN = 1331,				  // boss战皇宫开启
	SCENE_PROP_PERSONAL_BOSS_CUR_WAVE = 1332,	  // 个人boss当前波数
	SCENE_PROP_PERSONAL_BOSS_CUR_PID = 1333,	  // 个人boss归属玩家pid
	SCENE_PROP_GUILD_BATTLE_RESULT					= 1346,		//行会对战结果

	SCENE_PROP_KF3V3_COMPETITION_ID = 1351,			// 比赛ID
	SCENE_PROP_KF3V3_ZHANDUI_ID1 = 1352,			// 战队ID1
	SCENE_PROP_KF3V3_ZHANDUI_NAME1 = 1353,			// 战队名称1（字符串）
	SCENE_PROP_KF3V3_ZHANDUI_KILLCOUNT1 = 1354,		// 战队击杀数1
	SCENE_PROP_KF3V3_ZHANDUI_ID2 = 1355,			// 战队ID2
	SCENE_PROP_KF3V3_ZHANDUI_NAME2 = 1356,			// 战队名称1（字符串）
	SCENE_PROP_KF3V3_ZHANDUI_KILLCOUNT2 = 1357,		// 战队击杀数2
	SCENE_PROP_KF3V3_PLAYER_ID11 = 1360,			// 战队1玩家ID1
	SCENE_PROP_KF3V3_PLAYER_NAME11 = 1361,			// 战队1玩家名称1（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE11 = 1362,			// 战队1玩家状态1
	SCENE_PROP_KF3V3_PLAYER_ID12 = 1363,			// 战队1玩家ID2
	SCENE_PROP_KF3V3_PLAYER_NAME12 = 1364,			// 战队1玩家名称2（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE12 = 1365,			// 战队1玩家状态2
	SCENE_PROP_KF3V3_PLAYER_ID13 = 1366,			// 战队1玩家ID3
	SCENE_PROP_KF3V3_PLAYER_NAME13 = 1367,			// 战队1玩家名称3（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE13 = 1368,			// 战队1玩家状态3
	SCENE_PROP_KF3V3_PLAYER_ID21 = 1369,			// 战队2玩家ID1
	SCENE_PROP_KF3V3_PLAYER_NAME21 = 1370,			// 战队2玩家名称1（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE21 = 1371,			// 战队2玩家状态1
	SCENE_PROP_KF3V3_PLAYER_ID22 = 1372,			// 战队2玩家ID2
	SCENE_PROP_KF3V3_PLAYER_NAME22 = 1373,			// 战队2玩家名称2（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE22 = 1374,			// 战队2玩家状态2
	SCENE_PROP_KF3V3_PLAYER_ID23 = 1375,			// 战队2玩家ID3
	SCENE_PROP_KF3V3_PLAYER_NAME23 = 1376,			// 战队2玩家名称3（字符串）
	SCENE_PROP_KF3V3_PLAYER_STATE23 = 1377,			// 战队2玩家状态3
	SCENE_PROP_KF3V3_ZHANDUI_ENTER1 = 1378,			// 战队1有队员进入
	SCENE_PROP_KF3V3_ZHANDUI_ENTER2 = 1379,			// 战队2有队员进入

	SCENE_PROP_KF3V3_COMPETITION_START = 1381,		// 比赛是否已经开始
	SCENE_PROP_KF3V3_COMPETITION_END = 1382,		// 比赛是否已经结束
	SCENE_PROP_KF3V3_WINNER = 1383,					// 获胜战队
};

// 场景类型定义
enum SceneType
{
	SCENE_TYPE_INVALID,	 // 无效的类型
	SCENE_TYPE_NORMAL,	 // 普通场景
	SCENE_TYPE_INSTANCE, // 副本场景
	SCENE_TYPE_EVENT,	 // 活动场景
	SCENE_TYPE_PRISON,	 // 监牢
	SCENE_TYPE_NORMAL2,	 // 普通2
	SCENE_TYPE_BOOK,	 // 图鉴场景
	SCENE_TYPE_END
};

// 场景阻挡类型
enum SceneBlockType
{
	SCENE_BLOCK_TYPE_NONE = 0,	  // 场景未设置阻挡
	SCENE_BLOCK_TYPE_BLOCKED = 1, // 场景设置阻挡
};

// 这个定义太复杂了, 不会自动导出到definition.lua中, 需要在script_definition.lua中手动修改
// 场景阻挡标记
enum SceneObstacleFlags
{
	OBSTACLE_FLAG_PLAYER = 1 << ENTITY_TYPE_PLAYER,	   // 0x0002
	OBSTACLE_FLAG_NPC = 1 << ENTITY_TYPE_NPC,		   // 0x0008
	OBSTACLE_FLAG_MG = 1 << ENTITY_TYPE_MONSTER_GROUP, // 0x0010
	OBSTACLE_FLAG_MONSTER = 1 << ENTITY_TYPE_MONSTER,  // 0x0020
	OBSTACLE_FLAG_SKILL = 1 << ENTITY_TYPE_SKILL,	   // 0x0040
	OBSTACLE_FLAG_ITEM = 1 << ENTITY_TYPE_ITEM,		   // 0x0200
	OBSTACLE_FLAG_PET = 1 << ENTITY_TYPE_PET,		   // 0x0400
	OBSTACLE_FLAG_DOG = 1 << ENTITY_TYPE_DOG,		   // 0x0800
	OBSTACLE_FLAG_MARKET = 1 << ENTITY_TYPE_MARKET,	   // 0x1000
	OBSTACLE_FLAG_HERO = 1 << ENTITY_TYPE_HERO,		   // 0x2000
	OBSTACLE_FLAG_MINER = 1 << ENTITY_TYPE_MINER,	   // 0x8000

	OBSTACLE_FLAG_BLOCK2P = 0x02000000, // 玩家不能重叠
	OBSTACLE_FLAG_BOSS = 0x04000000,	// BOSS
	OBSTACLE_FLAG_BLOCK = 0x08000000,	// 地图block
};

////副本状态
// enum InstanceState
//{
//	scene_st_ins_notover	= 0,
//	scene_st_ins_isover		= 1,
// };

////场景状态
// enum SceneState
//{
//	scene_ssPeace,			//和平
//	scene_ssCombating,		//战斗中
//	scene_ssCombatEnd		//战斗结束
// };

// 进入场景途径
enum SceneEnterReason
{
	SCENE_ENTER_REASON_PORTAL = 1,
	SCENE_ENTER_REASON_INSTANCE = 2,
	SCENE_ENTER_REASON_NPC = 3,
	SCENE_ENTER_REASON_MONSTER = 4,
	SCENE_ENTER_REASON_BACK = 5,
	SCENE_ENTER_REASON_BOSS = 6,
	SCENE_ENTER_REASON_ANYWHERE_ID = 7,
	SCENE_ENTER_REASON_WW_TASK = 8,
	SCENE_ENTER_REASON_JY_TASK = 9,
	SCENE_ENTER_REASON_NPC_SWBQ = 10,
	SCENE_ENTER_REASON_TREASURE = 11, // 藏宝图挖宝
	SCENE_ENTER_REASON_WORLD = 12,	  // 世界地图传送
	SCENE_ENTER_REASON_BOOK = 13,	  // 图鉴地图传送
};

// 副本类型
enum InstanceType
{
	SCENE_INSTANCE_PLAYER = 1, // 单人副本
	SCENE_INSTANCE_TEAM = 2,   // 组队副本
	SCENE_INSTANCE_GUILD = 3,  // 行会副本
};

enum SceneID
{
	// 场景实例ID开始值
	SCENE_INSTANCE_ID_BEGIN = 1000,
};

// 区域类型
enum AreaType
{
	SCENE_AREA_SAFE = 1, // 安全区
	SCENE_AREA_SAND = 2, // 沙城区域
	// SCENE_AREA_SCRIPT	= 1,
};

// 任务属性
enum QuestProp
{
	QUEST_PROP_DATA_X = 0,
	QUEST_PROP_DATA_Y = 1,
	QUEST_PROP_DATA_Z = 2,
	QUEST_PROP_STATIC_DATA_X = 3,
	QUEST_PROP_STATIC_DATA_Y = 4,
	QUEST_PROP_STATIC_DATA_Z = 5,
	QUEST_PROP_MAX = 6,
};

// 任务状态
enum QuestState
{
	QUEST_STATE_SUBMITED = 0,	  // 已提交
	QUEST_STATE_AVAILABLE = 1,	  // 可接
	QUEST_STATE_FINISHED = 2,	  // 完成
	QUEST_STATE_NOT_FINISHED = 3, // 已接取,未完成
};

// 任务分线
enum QuestLine
{
	QUEST_LINE_INVALID,
	QUEST_LINE_MAIN,			 // 主线任务
	QUEST_LINE_SINFUL_KARST,	 // 日常 罪恶溶洞 占位
	QUEST_LINE_GUARD_THROUGH,	 // 日常 守护副本 占位
	QUEST_LINE_EFFICIENT_GUAJI,	 // 高效挂机      占位
	QUEST_LINE_HIGH_YIELD_GUAJI, // 高收益挂机    占位
	QUEST_LINE_BRANCH,			 // 支线任务
	QUEST_LINE_XUNZHANG,		 // 日常 勋章任务
	QUEST_LINE_CM,
	QUEST_LINE_MINING,			 // 日常 挖矿任务
	QUEST_LINE_MAX,
};

// 任务类型
enum QuestType
{
	QUEST_TYPE_INVALID = 0,
	QUEST_TYPE_NPC_TALK = 1,			 // 对话
	QUEST_TYPE_WEAR_EQUIP = 2,			 // 穿戴装备
	QUEST_TYPE_KILL_MONSTER_AT_MAP = 3,	 // 指定地图击杀怪物
	QUEST_TYPE_DIVINE_SWORD_ACTIVED = 4, // 激活神剑之力
	QUEST_TYPE_ROLE_LEVEL = 5,			 // 角色等级
	QUEST_TYPE_ROLE_REINCA_LEVEL = 6,	 // 角色转生等级
	QUEST_TYPE_DIVINE_ARMOR_ACTIVED = 7, // 激活神甲
	QUEST_TYPE_VIP_LEVEL = 8,			 // VIP等级
	QUEST_TYPE_KILL_TARGET_MONSTER = 9,	 // 击杀指定id怪物

	QUEST_TYPE_END,
};

// 支线任务类型
enum BranchLineType
{
	BRANCHLIINE_VIP_LEVEL = 1,		// 支线 VIP任务
	BRANCHLIINE_ADD_GUILD,			// 支线 加入行会
	BRANCHLIINE_LOOK_FURY,			// 支线 了解狂暴
	BRANCHLIINE_CROSS_CHAT,			// 支线 跨服聊天
	BRANCHLINE_CORPSE_DEVIL_CAVE,	// 支线 尸魔洞
	BRANCHLIINE_ROLE_LEVEL,			// 支线 角色等级
	BRANCHLINE_ZSSD_BOSS,			// 支线 去往转生神殿打怪
	BRANCHLINE_SHENQI_ZHUZAO,		// 支线 神器铸造
	BRANCHLINE_SHOP_BUY,			// 支线 商店购买
	BRANCHLINE_BOSS_SCORE,			// 支线 BOSS积分
	BRANCHLINE_UPGRADE_SKILL,		// 支线 升级技能
	BRANCHLINE_DEVIL_DRAGON_CITY,	// 支线 魔龙城
	BRANCHLINE_SNOW_AREA_TEST,		// 支线 雪域试炼
	BRANCHLINE_MAGICAL_ICE_PALACE,	// 支线 玄冰殿
	BRANCHLINE_LIVE_OR_DIE_ROOM,	// 支线 生死之间
	BRANCHLINE_LAMENT_GALLERY,		// 支线 叹息长廊
};

// 七日封神任务类型
enum QRFSTaskType
{
	QRFS_TASK_LEVEL = 1,			// 等级
	QRFS_TASK_WXTZ = 2,				// 无限挑战
	QRFS_TASK_EQUIP_ENHANCE = 3,	// 装备强化
	QRFS_TASK_REBORN = 4,			// 转生
	QRFS_TASK_WING = 5,				// 翅膀
	QRFS_TASK_FIRST_PAY = 6,		// 首充
	QRFS_TASK_TUOGUAN = 7,			// 托管
	QRFS_TASK_ZHIZUN = 8,			// 至尊
	QRFS_TASK_ZHANSHEN = 9,			// 战神
	QRFS_TASK_KILL_TEJIE_BOSS = 10, // 击杀特戒BOSS
	QRFS_TASK_PUTON_TEJIE = 11,		// 装备特戒
	QRFS_TASK_FENSHEN = 12,			// 分身等级
	QRFS_TASK_JOIN_GCZ = 13,		// 参加攻城战
	QRFS_TASK_MOLING = 14,			// 魔灵升级次数
	QRFS_TASK_SHIELD = 15,			// 神盾等级
	QRFS_TASK_LINGWEN = 16,			// 灵纹升级次数
	QRFS_TASK_HUNT_BOSS = 17,		// BOSS狩猎
	QRFS_TASK_TEJIE_TUPO = 18,		// 特戒突破
	QRFS_TASK_XMHJ = 19,			// 心魔幻境
};

enum TeamMakeType
{
	TEAM_INVITE = 1,	// 队伍邀请
	TEAM_WANT_JOIN = 2, // 申请入队
};

enum TeamMakeResult
{
	TEAM_ACCEPT = 1,
	TEAM_REFUSE = 2,
	TEAM_OVERTIME = 3,
	TEAM_DISBAND = 4,
	TEAM_FULL = 5,
	TEAM_GET_TEAM = 6,
};

enum TeamMateType
{
	TEAM_MATE_OFFLINE = 0,
	TEAM_MATE_ONLINE = 1,
	TEAM_MAX = 10,
};

// 队伍属性
enum TeamProp
{
	TEAM_PROP_INSTANCE = 1,		// 队伍副本
	TEAM_PROP_LEADER_ID = 2,	// 队长
	TEAM_PROP_STATUS = 3,		// 队伍状态 0 等待中 1 进行中 2 已结束
	TEAM_PROP_CHAT_TIME = 4,	// 队伍发送公会消息的间隔
	TEAM_PROP_CALL_CD_TIME = 5, // 队伍召集令CD
};


enum ZhanDuiMemberType
{
	ZHANDUI_MEMBER_OFFLINE = 0,
	ZHANDUI_MEMBER_ONLINE = 1,

	ZHANDUI_MEMBER_MAX = 3,
};

// 战队职务
enum ZhanDuiPost
{
	ZHANDUI_POST_BEGIN = 0,
	ZHANDUI_POST_NONE = 0,			// 无职务
	ZHANDUI_POST_MASTER = 1,		// 队长
	ZHANDUI_POST_END,
};


// 入会申请结果
enum ZhanDuiAppDecide
{
	ZHANDUI_APP_ACCEPT, // 同意
	ZHANDUI_APP_REFUSE, // 拒绝
};


// 战队属性
enum ZhanDuiProp
{
	ZHANDUI_PROP_BEGIN = 1,
	ZHANDUI_PROP_MASTER_ID = 1,			// 队长
	ZHANDUI_PROP_KF3V3_RANK = 2,		// KF3V3海选赛排名
	ZHANDUI_PROP_KF3V3_SCORE = 3,		// KF3V3海选赛积分
	ZHANDUI_PROP_KF3V3_TOP = 4,			// KF3V3淘汰赛n强
	ZHANDUI_PROP_KF3V3_REGISTERED = 5,	// KF3V3已报名
	ZHANDUI_PROP_END,

	// 字符串属性
	ZHANDUI_PROP_MASTER_NAME = 1,		// 队长名称
};

// 行会属性
enum GuildProp
{
	GUILD_PROP_MASTER_ID = 1,				 // 会长id
	GUILD_PROP_MASTER_NAME = 2,				 // 会长名字
	GUILD_PROP_CONTRIBUTION = 3,			 // 行会贡献
	GUILD_PROP_MONEY = 4,					 // 行会资金
	GUILD_PROP_RANK = 5,					 // 行会实体在管理器中的位置
	GUILD_PROP_LEVEL = 6,					 // 行会等级
	GUILD_PROP_LEVEL_TIME = 7,				 // 行会等级时间
	GUILD_PROP_NEXT_LEVEL_TIME = 8,			 // 行会可以升级时间
	GUILD_PROP_LEAGUE_TIMES = 9,			 // 剩余结盟次数
	GUILD_PROP_KFYZ_SCORE = 10,				 // 跨服远征积分
	GUILD_PROP_KFYZ_SCORE_TIME = 11,		 // 跨服远征积分时间
	GUILD_PROP_KFYZ_TIME_RANK_REWARDED = 12, // 跨服远征排名奖励领取
	GUILD_PROP_LEAGUE_GUILD_ID = 13,		 // 结盟行会ID
	GUILD_PROP_KFYZ_KILLS = 14,				 // 跨服远征击杀数
	GUILD_PROP_MASTER_LAST_LOGOUT_TIME = 15, // 会长最后离线时间
	GUILD_PROP_IMPEACH_PID = 16,			 // 弹劾发起人
	GUILD_PROP_IMPEACH_TIME = 17,			 // 弹劾发起时间
	GUILD_PROP_IMPEACH_AGREE = 18,			 // 弹劾同意票数
	GUILD_PROP_IMPEACH_DISAGREE = 19,		 // 弹劾反对票数
	GUILD_PROP_INGOT = 20,					 // 行会元宝
	GUILD_PROP_AUTOADD_LEVEL = 21,			 // 自动同意加入公会等级,<=0-关闭,
	GUILD_PROP_PRIVATE_NOTICE = 25,			 // 行会公告(字符串)
	GUILD_PROP_PUBLIC_NOTICE = 26,			 // 行会宣言(字符串)
	GUILD_PROP_VITALITY = 27,				 // 行会活跃度
	GUILD_PROP_VITALITY_DAY = 28,			 // 行会当天活跃度是哪一天的
	GUILD_PROP_VITALITY_TODAY = 29,			 // 行会当天活跃度
	GUILD_PROP_OPEN_INSTANCE_TIME = 31,		 // 开启副本时间
	GUILD_PROP_OPEN_INSTANCE_EVENT_ID = 32,	 // 开启副本活动ID
	GUILD_PROP_OPEN_INSTANCE_ID = 33,		 // 开启副本实例ID
	GUILD_PROP_OPEN_INSTANCE_PLAYER_ID = 34, // 开启副本玩家ID
	GUILD_PROP_INSTANCE_DAY = 35,			 // 已开启过的行会副本日期
	GUILD_PROP_INSTANCE_BEGIN = 36,			 // 已开启过的行会副本开始
	GUILD_PROP_INSTANCE_END = 38,			 // 已开启过的行会副本结束
	GUILD_PROP_LAST_LOGIN_TIME = 39,		 // 已开启过的行会副本结束
	GUILD_PROP_HAS_GOT_GIFT = 40,			 // 是否已领取建功立业礼包
	GUILD_PROP_ACTIVITY_BOSS = 41,			 // 公会爬塔BOSS是否全部击杀
	GUILD_PROP_CALL_CD_TIME = 42,			 // 公会召集令CD开始时间
	GUILD_PROP_CALL_SCENEID = 43,			 // 公会召集令场景id
	GUILD_PROP_CALL_POSX = 44,				 // 公会召集令场景坐标X
	GUILD_PROP_CALL_POSY = 45,				 // 公会召集令场景坐标Y
	GUILD_PROP_CALL_NAME = 45,				 // 公会召集令名字
	GUILD_PROP_GATHER_POINT = 47,			 // 公会采集积分
	GUILD_PROP_FCDC_LEVEL = 48,				 // 风驰电掣  移动速度加成
	GUILD_PROP_SNLB_LEVEL = 49,				 // 势若奔雷  攻击速度加成
	GUILD_PROP_JRBB_LEVEL = 50,				 // 坚忍不拔  生命加成
	GUILD_PROP_GRJT_LEVEL = 51,				 // 固若金汤  防御加成
	GUILD_PROP_LTWJ_LEVEL = 52,				 // 雷霆万钧  攻击加成
	GUILD_PROP_KBYZ_LEVEL = 53,				 // 狂暴意志  会心伤害加成
	GUILD_PROP_YNQL_LEVEL = 54,				 // 一念千里  随机和回城CD降低
	GUILD_PROP_QZYB_LEVEL = 55,				 // 奇珍异宝  开启公会商店 提升公会商店等级
	GUILD_PROP_RJDJ_LEVEL = 56,				 // 日进斗金  激活普通红包功能 激活俸禄红包功能
	GUILD_PROP_FKDG_LEVEL = 57,				 // 富可敌国  提升捐献贡献收益
	GUILD_PROP_CBTX_LEVEL = 58,				 // 吃遍天下  开启公会食堂
	GUILD_PROP_JSCD_LEVEL = 59,				 // 积少成多  提升日常收益
	GUILD_PROP_MONEY_COUNT = 60,			 // 今日捐献获的行会次数
	GUILD_PROP_MONEY_TODAY_MONEY = 61,		 // 今日捐献获得的行会资金
	GUILD_PROP_MONEY_TODAY_TIME = 62,		 // 今日捐献获得的行会资金星期几
	GUILD_PROP_KILL_BOSS_NUM = 63,			 // 工会Boss击杀个数
	GUILD_PROP_SPECIAL_RED_BAG_DAY = 64,	 // 公会俸禄红包发放时间（天）
	GUILD_PROP_MILITARY_EXPLOITS = 65,		 // 公会战功
	GUILD_PROP_DECLARE_WAR_GUILD = 66,		 // 宣战工会id
	GUILD_PROP_DECLARE_WAR_OVER_TIME = 67,	 // 宣战结束时间
	GUILD_PROP_DECLARE_WAR_TIMES = 68,		 // 宣战今日使用次数
};

enum GuildBagPos
{
	//[1, 80]
	GUILD_BAG_POS_FIRST = 1,
	GUILD_BAG_POS_LAST = 156,
};

// 行会职务
enum GuildPost
{
	GUILD_POST_BEGIN = 0,
	GUILD_POST_NORMAL = 0,		  // 普通会员
	GUILD_POST_ELITE = 1,		  // 精英
	GUILD_POST_PROTECTOR = 2,	  // 护法
	GUILD_POST_ELDER = 3,		  // 长老
	GUILD_POST_SECOND_MASTER = 4, // 副会长
	GUILD_POST_MASTER = 5,		  // 会长
	GUILD_POST_END,
};

// 行会职务人数上限
enum GuildPostMax
{
	GUILD_POST_NORMAL_MAX = 0,
	GUILD_POST_MASTER_MAX = 1,
	GUILD_POST_SECOND_MASTER_MAX = 1,
	GUILD_POST_ELDER_MAX = 3,
};

// 行会红包类型
enum GuildRedPackageType
{
	GUILD_RED_PACKAGE_COMMON = 1,	// 普通红包
	GUILD_RED_PACKAGE_SALARY = 2,	// 俸禄红包
	GUILD_RED_PACKAGE_SHAJUAN = 3,	// 沙捐红包
	GUILD_RED_PACKAGE_FULI = 4,		// 福利红包
	GUILD_RED_PACKAGE_ACTIVITY = 5, // 活动红包
};

enum GczStateType
{
	GCZ_STATE_CLOSED = 0,	// 关闭，当天不开
	GCZ_STATE_WAITTING = 1, // 等待开启，当天未开启
	GCZ_STATE_DX = 2,		// 雕像阶段
	GCZ_STATE_HG = 3,		// 皇宫阶段
	GCZ_STATE_END = 4,		// 结束
};

enum KfzbPhaseType
{
	KFZB_PHASE_PREPARE = 0, // 准备阶段，未开启
	KFZB_PHASE_READY = 1,	// 装备阶段
	KFZB_PHASE_FIGHT = 2,	// 攻击阶段
	KFZB_PHASE_END = 3,		// 结束
};

enum PeakMapType
{
	PEAK_MAP_STOPPING = 0, // 关闭状态
	PEAK_MAP_OPENNING = 1, // 开放状态
};

enum GuildOperationCode
{
	GUILD_REASON_BEGIN,
	GUILD_REASON_ADD_APP,
	GUILD_REASON_DELETE_APP,
	GUILD_REASON_ADD_MEMBER,
	GUILD_REASON_DELETE_MEMBER,
	GUILD_REASON_LEAVE,
	GUILD_REASON_CONTRIBUTION_CHANGE,
	GUILD_REASON_CONFIRM_APP,
	GUILD_REASON_REFUSE_APP,
	GUILD_REASON_KICK,
	GUILD_REASON_ONLINE,
	GUILD_REASON_OFFLINE,
	GUILD_REASON_PLAYER_LEVEL_UP,
	GUILD_REASON_JOIN_MEET,
	GUILD_REASON_LEAVE_MEET,
	GUILD_REASON_RANK_CHANGED,
	GUILD_REASON_MASTER_LEAVE,	 // 会长退出行会
	GUILD_REASON_PLAYER_DELETED, // 玩家删号
	GUILD_REASON_INACTIVE,		 // 非活跃行会
	GUILD_REASON_GM_RELEASE,	 // 释放工会
	GUILD_REASON_MERGE,			 // 合并
};

// 入会申请结果
enum GuildAppDecide
{
	GUILD_APP_ACCEPT, // 同意
	GUILD_APP_REFUSE, // 拒绝
};

// 行会记录类型
enum GuildRecordType
{
	GUILD_RECORD_DONATE = 1,			  // 捐献 namex = Donater, datax = donatermoney
	GUILD_RECORD_MEMBER_JOIN = 2,		  // 成员加入 namex = Joiner
	GUILD_RECORD_MEMBER_LEAVE = 3,		  // 成员离开 namex = Leaver
	GUILD_RECORD_KICK_MEMBER = 4,		  // 开除成员 namex = Leaver , namey = Kicker
	GUILD_RECORD_MEMBER_POST_CHANGED = 5, // 职务变更 datax = old post, datay = new post
	GUILD_RECORD_LEVEL_UP = 6,			  // 升级 datax = new level
	GUILD_RECORD_UNLOCK_SCENE = 7,		  // 副本解锁 datax = scene static id
	GUILD_RECORD_KILL_BOSS = 8,			  // 击杀BOSS datax = boss static id
	GUILD_RECORD_GCZ = 9,				  // 攻城战 datax = success?
	GUILD_RECORD_RELATION = 10,			  // 行会关系操作
	GUILD_RECORD_BAG_GET_ITEM = 11,		  // 捐献装备
	GUILD_RECORD_BAG_SEND_ITEM = 12,	  // 获取装备
	GUILD_RECORD_BAG_DONATE = 13,		  // 捐献金币
	GUILD_RECORD_BAG_CLEAN = 14,		  // 系统清理
	GUILD_RECORD_IMPEACH = 15,			  // 弹劾记录
	GUILD_RECORD_BAG_DONATE_INGOT = 16,	  // 捐献元宝
	GUILD_RECORD_BIND_COIN = 17,		  // 绑定元宝捐赠
	GUILD_RECORD_BOUNDINGOT = 18,		  // 传奇币捐赠
	GUILD_RECORD_INGOT = 19,			  // 钻石捐赠
	GUILD_RECORD_TECHNOLOGY_FUN = 20,	  // 功能科技
	GUILD_RECORD_TECHNOLOGY_PRO = 22,	  // 属性科技
	GUILD_RECORD_CHANGENAME = 23,		  // 公会改名
	GUILD_RECORD_REDPAG = 24,			  // 红包
	GUILD_RECORD_SHOP_LIMIT = 25,		  // 公会限购商品
	GUILD_RECORD_DEVOTEITEM = 26,		  // 公会捐献物品

};

enum GuildState
{
	GUILD_STATE_NORMAL = 0,		// 普通
	GUILD_STATE_LIMIT = 1,		// 等级限制
	GUILD_STATE_APPLY_JOIN = 2, // 已申请加入此行会
};

// 玩家关系类型
enum SocialType
{
	SOCIAL_TYPE_BEGIN = 0,
	SOCIAL_TYPE_FRIEND = 0,		 // 好友
	SOCIAL_TYPE_MASTER,			 // 师傅
	SOCIAL_TYPE_APPRENTICE,		 // 徒弟
	SOCIAL_TYPE_COUPLE,			 // 伴侣
	SOCIAL_TYPE_ENEMY,			 // 仇人
	SOCIAL_TYPE_MASTER_LIST,	 // 拜师列表
	SOCIAL_TYPE_APPRENTICE_LIST, // 高徒列表
	SOCIAL_TYPE_BLACK_LIST,		 // 黑名单
	SOCIAL_TYPE_RECENTLY,		 // 最近联系人
	SOCIAL_TYPE_END,

	SOCIAL_TYPE_REQUEST = 100, // 申请类型
};

// 玩家阵营类型
enum CampType
{
	CAMP_TYPE_BEGIN = 0,
	CAMP_TYPE_RED = 1,	   // 红色阵营方
	CAMP_TYPE_BLUE = 2,	   // 蓝色阵营方
	CAMP_TYPE_NEUTRAL = 3, // 中立方
};

enum SocialOpType
{
	OP_SOCIAL_REQUEST = 0,	// 请求
	OP_SOCIAL_RESPONSE = 1, // 回复

	OP_SOCIAL_AGREE = 0,  // 同意
	OP_SOCIAL_REFUSE = 1, // 拒绝
	OP_SOCIAL_DELETE = 2, // 删除
};

enum GiftCate
{
	GIFT_RECHARGE_ALL = 1,		 // Type = 0 首充 ，Type > 1 累计充值对应
	GIFT_LIMIT_TIME = 2,		 // Type 无意义
	GIFT_RECHARGE_DAY = 3,		 // Type = 0 首充
	GIFT_RECHARGE_MONTH = 4,	 // Type 无意义
	GIFT_ONLINE = 5,			 // Type 对应累计在线
	GIFT_SIGN_UP = 6,			 // Type 对应签到次数
	GIFT_WEEK = 7,				 // Type 无意义
	GIFT_NS_LEVEL_UP = 8,		 // Type 1,2,3,4,5对应不同条件
	GIFT_NS_PET_LEVEL_UP = 9,	 // Type 1,2,3,4,5对应不同条件
	GIFT_NS_STONEP = 10,		 // Type 1,2,3,4,5对应不同条件
	GIFT_VIP_LEVEL = 11,		 // 1-15级各级的奖励
	GIFT_CONSUME_ALL = 12,		 // 1-15级各级的奖励
	GIFT_SUIT_REWARD = 13,		 // 套装奖励
	GIFT_ONLINE_GOLD = 14,		 // 每周在线奖励元宝
	GIFT_ONLINE_GOLD_CHECK = 15, // 每周在线奖励元宝_检测（刷新到客户端）
	GIFT_KFHD_QMBS_RECEIVE = 16, // 领取开服活动奖励-全民boss
	GIFT_KFHD_JSCJ_RECEIVE = 17, // 领取开服活动奖励-角色冲级
	GIFT_KFHD_CBCJ_RECEIVE = 18, // 领取开服活动奖励-翅膀冲级
	GIFT_KFHD_BSCJ_RECEIVE = 19, // 领取开服活动奖励-宝石冲级
	GIFT_KFHD_HZCJ_RECEIVE = 20, // 领取开服活动奖励-魂珠冲级
	GIFT_KFHD_7DAY_RECEIVE = 21, // 领取开服活动奖励-7天奖励（奖励大厅）
	GIFT_KFHD_7DAY_SIGN_IN = 22, // 领取开服活动奖励-7天奖励-登陆自动签到
	GIFT_KFHD_COMMENT = 23,		 // AppStore五星好评奖励
	GIFT_KFHD_XFDB = 24,		 // 领取开服活动奖励-消费夺宝
	// GIFT_KFHD_XFPH          = 25,	//领取开服活动奖励-消费排行——此项将通过邮件发送，先占坑
	GIFT_KFHD_SCCZFL = 26,		   // 首充超值返利
	GIFT_WEEK_SIGN_IN = 27,		   // 每周签到
	GIFT_KFHD_JGLY_RECEIVE = 32,   // 领取开服活动奖励-建功立业
	GIFT_KFHD_QMJC_RECEIVE = 33,   // 全名竞猜活动
	GIFT_KFHD_HERO_RECEIVE = 34,   // 领取开服活动奖励-英雄冲级
	GIFT_KFHD_SOUL_RECEIVE = 35,   // 领取开服活动奖励-龙魂冲级
	GIFT_KFHD_OFFICE_RECEIVE = 36, // 领取开服活动奖励-官印冲级
	GIFT_KFHD_STONE_RECEIVE = 37,  // 领取开服活动奖励-魂石冲级
	GIFT_HYD_REWARD = 38,		   // 活跃度领奖
	GIFT_KFHD_VEIN_RECEIVE = 39,   // 领取开服活动奖励-经脉冲级
	GIFT_KFHD_YBZP_RECEIVE = 40,   // 元宝转盘
	GIFT_RECHARGE_FIRST = 41,	   // 首冲 dzy
	GIFT_LCLB = 42,				   // 累充礼包 dzy
	GIFT_BAOBAO_SKILL = 43,		   // 宝宝技能礼包 dzy
	GIFT_ZHIZUN_LEVEL = 44,		   // 至尊礼包领取情况
	GIFT_WANTED_BOSS_RECEIVE = 45, // 领取BOSS通缉奖励
};

// 特效类型
enum EffectBit
{
	EFFECT_VISABLE = 0,
	EFFECT_POSION_RED = 1,
	EFFECT_POSION_GREEN = 2,
	EFFECT_MITIGATE = 3,
	EFFECT_SPEED_DOWN = 4,
	EFFECT_SPEED_UP = 5,
	EFFECT_VIOLENT = 6,
	EFFECT_XURUO = 7, // 虚弱特效
	EFFECT_DAZE = 8,  // 麻痹
	EFFECT_HIDE = 9,
	EFFECT_FROZEN = 10, // 冰冻
	EFFECT_AGNAIL = 11,
	EFFECT_INVINCIBLE = 12,		 // 无敌
	EFFECT_BOSS_SHIELD = 13,	 // 怪物护盾
	EFFECT_FALI_JINGJI = 14,	 // 法力荆棘（狂暴）
	EFFECT_KB = 15,				 // 狂暴
	EFFECT_SWORDSTORM = 16,		 // 剑刃风暴
	EFFECT_JIAOXIE = 17,		 // 缴械
	EFFECT_SHIELD = 24,			 // 护盾
	EFFECT_WHIRLWIND = 25,		 // 旋风斩
	EFFECT_HUNLING_HD = 26,		 // 魂之护盾
	EFFECT_HUNQI_WD = 27,		 // 守护之魂
	EFFECT_LINGBAO_BUQU = 28,	 // 灵宝不屈技能
	EFFECT_LINGBAO_JIANYI = 29,	 // 灵宝坚毅技能
	EFFECT_LINGBAO_JIAOZHA = 30, // 灵宝狡诈技能
	EFFECT_LINGBAO_SHIXUE = 31,	 // 灵宝嗜血技能
};

enum EffectComponentBit
{
	EFFECT_COMP_BEGIN = 0,

	EFFECT_COMP_WJZQ = 1, // 无极真气

	EFFECT_COMP_HXZT = 2, // 会心状态

	EFFECT_COMP_SXKM = 3, // 嗜血狂魔

	EFFECT_COMP_MAX = 4,
};

// 事件组
enum EventGroup
{
	EVENT_GROUP_INVALID = 0,

	EVENT_GROUP_QUEST = 1,		 // 任务事件组
	EVENT_GROUP_COMBAT = 2,		 // 战斗事件组
	EVENT_GROUP_PLAYER_LOAD = 4, // 玩家加载事件组
	EVENT_GROUP_ENTITY = 8,		 //

	// 跨服事件(事件发生在跨服，触发逻辑在原服处理）
	CROSS_EVENT_GROUP_QUEST = 32, // 任务事件组

	EVENT_GROUP_SCRIPT = 32768,
};

// 任务事件
enum EventQuest
{
	EVENT_KILL_MONSTER = 1,
	EVENT_TALK_NPC = 2,
	EVENT_TAKE_ITEM = 3,
	EVENT_FINISH_QUEST = 4,
	EVENT_GOTO_INSTANCE = 5,
	EVENT_KILL_PLAYER = 6,
	EVENT_EQUIP_PUT_ON_OFF = 7,		 // 穿脱装备
	EVENT_GET_MOHUN = 8,			 // 获得魔魂
	EVENT_BIGBANG_ON = 9,			 // 触发大爆
	EVENT_OPEN_TREASURE = 10,		 // 藏宝图挖宝
	EVENT_BAOBAO_LEVEL_CHANGE = 11,	 // 宝宝等级变化
	EVENT_RECOVER_EQUIP = 12,		 // 回收装备
	EVENT_PLAYER_PROP_CHANGED = 13,	 // 属性变化
	EVENT_PLAYER_LEVEL_CHANGED = 14, // 等级变化
	EVENT_ENHANCE_POS = 15,			 // 强化
	EVENT_PLAYER_OPERATION = 16,	 // 玩家操作
	EVENT_ACTIVE_SKILL = 17,		 // 激活技能
	EVENT_USE_ITEM = 18,			 // 使用物品
	EVENT_SKILL_PUT_ON_OFF = 19,	 // 装备/取消技能
	EVENT_TASK_MINE = 20,			 // 挖矿任务
	EVENT_SPECIAL_RING_UPGRADE = 21, // 特戒升阶
	EVENT_HUOJI_EQUIP = 22,			 // 火祭装备
};

// 加载玩家数据事件
enum EventPlayerLoad
{
	EVENT_LOAD_PLAYER_BEGIN = 151,
	EVENT_LOAD_PLAYER_PROPS = 151,		// 加载属性
	EVENT_LOAD_PLAYER_ITEMS = 152,		// 加载物品
	EVENT_LOAD_PLAYER_QUESTS = 153,		// 加载任务
	EVENT_LOAD_PLAYER_SKILLS = 154,		// 加载技能
	EVENT_LOAD_PLAYER_PETS = 155,		// 加载宠物
	EVENT_LOAD_PLAYER_EVENTS = 156,		// 加载活动数据
	EVENT_LOAD_PLAYER_RELATIONS = 157,	// 加载关系
	EVENT_LOAD_PLAYER_PET_SKILLS = 158, // 加载宠物技能
	EVENT_LOAD_PLAYER_MAILS = 159,		// 加载邮件
	EVENT_LOAD_PLAYER_GENES = 161,		// 加载基因
	// EVENT_LOAD_PLAYER_MW_SKILLS	= 162,		//加载法器技能
	EVENT_LOAD_PLAYER_HERO = 163,		 // 加载英雄
	EVENT_LOAD_PLAYER_HERO_SKILLS = 164, // 加载英雄技能
	EVENT_LOAD_PLAYER_DRESS = 165,		 // 加载装扮
	EVENT_LOAD_PLAYER_HERO_TALENT = 166, // 加载英雄天赋
	EVENT_LOAD_PLAYER_STR = 167,		 // 加载文本属性
	EVENT_LOAD_PLAYER_HERO_ITEM = 168,	 // 加载英雄物品
	EVENT_LOAD_PLAYER_HERO_PET = 169,	 // 加载英雄神兽
	EVENT_LOAD_PLAYER_CASHBACK = 170,	 // 加载现金红包
	EVENT_LOAD_PLAYER_ROBBED_INFO = 171, // 加载掠夺管理
	EVENT_LOAD_PLAYER_GUAJI = 172,		 // 加载挂机
	EVENT_LOAD_PLAYER_GUAJI_ITEM = 173,
	// 跨服玩法相关的数据
	EVENT_LOAD_PLAYER_CROSS_EVENTS = 300, // 跨服活动数据

	EVENT_LOAD_PLAYER_END,
};

// 经验奖励事件
enum EventExpReward
{
	EVENT_NULL = 200,
	EVENT_KILL_EXP = 201,
	EVENT_QUEST_EXP = 202,
	EVENT_FIRE_EXP = 203,
	EVENT_GUILD_FIGHT_EXP = 204,
};

// 战斗事件
enum EventCombat
{
	EVENT_ATTACK = 300,		 // 攻击
	EVENT_BE_ATTACKED = 301, // 被攻击
	EVENT_BE_COLLIDED = 302, // 被野蛮冲撞
	EVENT_BE_POISON = 303,	 // 被毒
	EVENT_FLY = 304,
	EVENT_EFFECT_REMOVE = 305,
	EVENT_MONSTER_DEAD = 306, // 怪物死亡(通知怪物组)
	EVENT_QINGLONGSHOU = 307, // 擒龙手
	EVENT_MEET_ENTITY_SKILL = 350,
	EVENT_LEAVE_ENTITY_SKILL = 351,

	EVENT_INIT = 360,
};

// 实体事件
enum EventEntity
{
	EVENT_SCENE_GET_INFO = 800,
	EVENT_MARKET_BUY = 801,
	EVENT_CLEAN_PET_GENE = 802, // 清除宠物的所有gene
};

// 限时任务中的日常任务
enum DailyTaskType
{
	TASK_TYPE_MATERIAL = 1, // 材料任务
	TASK_TYPE_GONGXUN = 2,	// 功勋任务
	TASK_TYPE_WEIWANG = 3,	// 威望任务
	TASK_TYPE_JINGYING = 4, // 精英任务
	TASK_TYPE_CHUMO = 5,	// 除魔任务
	TASK_TYPE_FMG = 6,		// 封魔谷
};

// 平台ID
enum PlatformID
{
	PLATFORM_WIN32 = 0,
	PLATFORM_ANDROID = 1,
	PLATFORM_IOS = 2,
};

// 商店类型
enum ShopType
{
	SHOP_TYPE_MALL = 1,	   // 商城
	SHOP_TYPE_NPC = 2,	   // NPC商店
	SHOP_TYPE_BAG = 3,	   // 随身商店
	SHOP_TYPE_FANTIAN = 7, // 梵天星宫
};

// 世界属性
enum WorldProp
{
	WORLD_PROP_PLAYER_LIMIT = 1,		 // 服务器最大承载玩家数
	WORLD_PROP_CLIENT_GM_STATE = 2,		 // 是否允许客户端GM
	WORLD_PROP_PLAYER_COUNT = 3,		 // 服务器当前人数
	WORLD_PROP_CHAT_REQ = 4,			 // 世界频道聊天所需等级
	WORLD_PROP_PLAYER_REBORN_MAX = 5,	 // 玩家转生上限
	WORLD_PROP_GUILD_LEVEL_MAX = 6,		 // 行会等级上限
	WORLD_PROP_CHAT_GUILD_REQ = 7,		 // 行会频道聊天所需等级
	WORLD_PROP_CHAT_TEAM_REQ = 8,		 // 队伍频道聊天所需等级
	WORLD_PROP_CHAT_PRIVATE_REQ = 9,	 // 私聊频道聊天所需等级
	WORLD_PROP_PLAYER_LEVEL_MAX = 10,	 // 玩家等级上限
	WORLD_ACCELERATOR_PING_COUNT = 11,	 // 加速软件判断-PING数量
	WORLD_ACCELERATOR_PING_AVERAGE = 12, // 加速软件判断-PING平均值毫秒

	WORLD_PROP_RECHARGE_REWARD_INDEX = 20, // 充值额第几档额外奖励
	WORLD_PROP_PLAYER_LEVEL_TO_TRADE = 21, // 交易所需等级
	WORLD_PROP_CONSIGNMENTS_MAX = 22,	   // 寄售数量限制
	WORLD_PROP_CHAT_HORN_REQ = 24,		   // 传音频道聊天所需等级
	WORLD_PROP_HERO_REBORN_MAX = 25,	   // 英雄转生上限
	WORLD_PROP_HERO_LEVEL_MAX = 26,		   // 英雄等级上限

	WORLD_PROP_CLEAR_DIRTY_WORLD_PROP = 99,	 // 备服时有些世界属性已经记录了，真正开服时需要清掉
	WORLD_PROP_CREATE_ROLE_CLOSE_DAYS = 100, // 服务器关闭注册天数

	WORLD_PROP_GM_QUERY_PLAYER = 200, // 后台查询角色（datas：查询类型）

	WORLD_PROP_KF3V3 = 301,					// datax-跨服3v3战区, datay=跨服3v3开始时间
	WORLD_PROP_KF3V3_TOP32 = 311,			// 跨服3v3已产生32强
	WORLD_PROP_KF3V3_TOP16 = 312,			// 跨服3v3已产生16强
	WORLD_PROP_KF3V3_TOP8 = 313,			// 跨服3v3已产生8强
	WORLD_PROP_KF3V3_TOP4 = 314,			// 跨服3v3已产生4强
	WORLD_PROP_KF3V3_TOP2 = 315,			// 跨服3v3已产生2强
	WORLD_PROP_KF3V3_TOP1 = 316,			// 跨服3v3已产生冠军

	//// KF3V3 海选赛期间排行榜（游戏服）
	//WORLD_PROP_KF3V3_RANK_1		= 321,
	//WORLD_PROP_KF3V3_RANK_2		= 322,
	//WORLD_PROP_KF3V3_RANK_3		= 323,
	//WORLD_PROP_KF3V3_RANK_4		= 324,
	//WORLD_PROP_KF3V3_RANK_5		= 325,
	//WORLD_PROP_KF3V3_RANK_6		= 326,
	//WORLD_PROP_KF3V3_RANK_7		= 327,
	//WORLD_PROP_KF3V3_RANK_8		= 328,
	//WORLD_PROP_KF3V3_RANK_9		= 329,
	//WORLD_PROP_KF3V3_RANK_10	= 330,

	// KF3V3 32强（游戏服）
	WORLD_PROP_KF3V3_TOP32_1	= 331,
	WORLD_PROP_KF3V3_TOP32_2	= 332,
	WORLD_PROP_KF3V3_TOP32_3	= 333,
	WORLD_PROP_KF3V3_TOP32_4	= 334,
	WORLD_PROP_KF3V3_TOP32_5	= 335,
	WORLD_PROP_KF3V3_TOP32_6	= 336,
	WORLD_PROP_KF3V3_TOP32_7	= 337,
	WORLD_PROP_KF3V3_TOP32_8	= 338,
	WORLD_PROP_KF3V3_TOP32_9	= 339,
	WORLD_PROP_KF3V3_TOP32_10	= 340,
	WORLD_PROP_KF3V3_TOP32_11	= 341,
	WORLD_PROP_KF3V3_TOP32_12	= 342,
	WORLD_PROP_KF3V3_TOP32_13	= 343,
	WORLD_PROP_KF3V3_TOP32_14	= 344,
	WORLD_PROP_KF3V3_TOP32_15	= 345,
	WORLD_PROP_KF3V3_TOP32_16	= 346,
	WORLD_PROP_KF3V3_TOP32_17	= 347,
	WORLD_PROP_KF3V3_TOP32_18	= 348,
	WORLD_PROP_KF3V3_TOP32_19	= 349,
	WORLD_PROP_KF3V3_TOP32_20	= 350,
	WORLD_PROP_KF3V3_TOP32_21	= 351,
	WORLD_PROP_KF3V3_TOP32_22	= 352,
	WORLD_PROP_KF3V3_TOP32_23	= 353,
	WORLD_PROP_KF3V3_TOP32_24	= 354,
	WORLD_PROP_KF3V3_TOP32_25	= 355,
	WORLD_PROP_KF3V3_TOP32_26	= 356,
	WORLD_PROP_KF3V3_TOP32_27	= 357,
	WORLD_PROP_KF3V3_TOP32_28	= 358,
	WORLD_PROP_KF3V3_TOP32_29	= 359,
	WORLD_PROP_KF3V3_TOP32_30	= 360,
	WORLD_PROP_KF3V3_TOP32_31	= 361,
	WORLD_PROP_KF3V3_TOP32_32	= 362,

	// KF3V3 16强（游戏服）
	WORLD_PROP_KF3V3_TOP16_1	= 363,
	WORLD_PROP_KF3V3_TOP16_2	= 364,
	WORLD_PROP_KF3V3_TOP16_3	= 365,
	WORLD_PROP_KF3V3_TOP16_4	= 366,
	WORLD_PROP_KF3V3_TOP16_5	= 367,
	WORLD_PROP_KF3V3_TOP16_6	= 368,
	WORLD_PROP_KF3V3_TOP16_7	= 369,
	WORLD_PROP_KF3V3_TOP16_8	= 370,
	WORLD_PROP_KF3V3_TOP16_9	= 371,
	WORLD_PROP_KF3V3_TOP16_10	= 372,
	WORLD_PROP_KF3V3_TOP16_11	= 373,
	WORLD_PROP_KF3V3_TOP16_12	= 374,
	WORLD_PROP_KF3V3_TOP16_13	= 375,
	WORLD_PROP_KF3V3_TOP16_14	= 376,
	WORLD_PROP_KF3V3_TOP16_15	= 377,
	WORLD_PROP_KF3V3_TOP16_16	= 378,

	// KF3V3 8强（游戏服）
	WORLD_PROP_KF3V3_TOP8_1		= 379,
	WORLD_PROP_KF3V3_TOP8_2		= 380,
	WORLD_PROP_KF3V3_TOP8_3		= 381,
	WORLD_PROP_KF3V3_TOP8_4		= 382,
	WORLD_PROP_KF3V3_TOP8_5		= 383,
	WORLD_PROP_KF3V3_TOP8_6		= 384,
	WORLD_PROP_KF3V3_TOP8_7		= 385,
	WORLD_PROP_KF3V3_TOP8_8		= 386,

	// KF3V3 4强（游戏服）
	WORLD_PROP_KF3V3_TOP4_1		= 387,
	WORLD_PROP_KF3V3_TOP4_2		= 388,
	WORLD_PROP_KF3V3_TOP4_3		= 389,
	WORLD_PROP_KF3V3_TOP4_4		= 390,

	// KF3V3 2强（游戏服）
	WORLD_PROP_KF3V3_TOP2_1		= 391,
	WORLD_PROP_KF3V3_TOP2_2		= 392,

	// KF3V3 冠军（游戏服）
	WORLD_PROP_KF3V3_TOP1_1		= 393,

	// KF3V3 海选赛期间排行榜（游戏服）
	WORLD_PROP_KF3V3_RANK_1		= 401,
	WORLD_PROP_KF3V3_RANK_2		= 402,
	WORLD_PROP_KF3V3_RANK_3		= 403,
	WORLD_PROP_KF3V3_RANK_4		= 404,
	WORLD_PROP_KF3V3_RANK_5		= 405,
	WORLD_PROP_KF3V3_RANK_6		= 406,
	WORLD_PROP_KF3V3_RANK_7		= 407,
	WORLD_PROP_KF3V3_RANK_8		= 408,
	WORLD_PROP_KF3V3_RANK_9		= 409,
	WORLD_PROP_KF3V3_RANK_10	= 410,
	WORLD_PROP_KF3V3_RANK_11	= 411,
	WORLD_PROP_KF3V3_RANK_12	= 412,
	WORLD_PROP_KF3V3_RANK_13	= 413,
	WORLD_PROP_KF3V3_RANK_14	= 414,
	WORLD_PROP_KF3V3_RANK_15	= 415,
	WORLD_PROP_KF3V3_RANK_16	= 416,
	WORLD_PROP_KF3V3_RANK_17	= 417,
	WORLD_PROP_KF3V3_RANK_18	= 418,
	WORLD_PROP_KF3V3_RANK_19	= 419,
	WORLD_PROP_KF3V3_RANK_20	= 420,
	WORLD_PROP_KF3V3_RANK_21	= 421,
	WORLD_PROP_KF3V3_RANK_22	= 422,
	WORLD_PROP_KF3V3_RANK_23	= 423,
	WORLD_PROP_KF3V3_RANK_24	= 424,
	WORLD_PROP_KF3V3_RANK_25	= 425,
	WORLD_PROP_KF3V3_RANK_26	= 426,
	WORLD_PROP_KF3V3_RANK_27	= 427,
	WORLD_PROP_KF3V3_RANK_28	= 428,
	WORLD_PROP_KF3V3_RANK_29	= 429,
	WORLD_PROP_KF3V3_RANK_30	= 430,
	WORLD_PROP_KF3V3_RANK_31	= 431,
	WORLD_PROP_KF3V3_RANK_32	= 432,


	// WORLD_PROP_ACTIVITY_BEGIN				= 0,
	// WORLD_PROP_ACTIVITY_END				= 400,
	WORLD_PROP_MONSTER_BEGIN = 501, // 定时怪物刷新（datax：数据重置时间戳 datay：怪物刷新时间戳 dataz：刷新次数）
	WORLD_PROP_MONSTER_END = 700,

	// WORLD_PROP_MB_DATA					= 800,		//膜拜次数，鄙视次数，投入的元宝数
	// WORLD_PROP_MB_PLAYER					= 801,		//衣服，武器，特效

	WORLD_PROP_FIRST_ZS_APP = 810,		   // 第一战士：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_FS_APP = 811,		   // 第一法师：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_DS_APP = 812,		   // 第一道士：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_ZS_DATA = 813,		   // 第一战士：pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_FIRST_FS_DATA = 814,		   // 第一法师：pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_FIRST_DS_DATA = 815,		   // 第一道士：pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_WORLD_FIRST_ALL_APP = 816,  // 天下第一  2018.2.26 新加的  衣服，武器，翅膀 留言
	WORLD_PROP_WORLD_FIRST_ALL_DATA = 817, // 天下第一  2018.2.26 新加的  pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_FIRST_ZS_GUILDDATA = 818,	//第一战士：公会信息
	WORLD_PROP_FIRST_FS_GUILDDATA = 819,	//第一法师：公会信息
	WORLD_PROP_FIRST_DS_GUILDDATA = 820,	//第一道士：公会信息


	WORLD_PROP_CZLC = 841, // 超值理财: x-剩余数量, z-总量
	WORLD_PROP_HYSD = 842, // 幻影神殿

	WORLD_PROP_FIRST_OTHER_ZS_APP = 870,  // 第一异性战士：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_OTHER_FS_APP = 871,  // 第一异性法师：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_OTHER_DS_APP = 872,  // 第一异性道士：衣服，武器，翅膀 留言
	WORLD_PROP_FIRST_OTHER_ZS_DATA = 873, // 第一异性战士：pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_FIRST_OTHER_FS_DATA = 874, // 第一异性法师：pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_FIRST_OTHER_DS_DATA = 875, // 第一异性道士：pid, （reborn << 16 | level）,性别，名字

	WORLD_PROP_NEW_SERVER_LEVEL = 880,	  // 天下第一(等级最高)
	WORLD_PROP_NEW_SERVER_LEVEL_ZS = 881, // 战士的荣耀: pid ,lvl, reborn
	WORLD_PROP_NEW_SERVER_LEVEL_FS = 882, // 法师的荣耀: pid ,lvl, reborn
	WORLD_PROP_NEW_SERVER_LEVEL_DS = 883, // 道士的荣耀: pid ,lvl, reborn
	WORLD_PROP_SERVER_FIRST_ZS = 884,	  // 第一战士(战力)
	WORLD_PROP_SERVER_FIRST_FS = 885,	  // 第一法师(战力)
	WORLD_PROP_SERVER_FIRST_DS = 886,	  // 第一道士(战力)

	WORLD_PROP_FIRST_PRESTIGE_PLAYER = 887,	 // 第一玩家(威望)
	WORLD_PROP_SECOND_PRESTIGE_PLAYER = 888, // 第二玩家(威望)
	WORLD_PROP_THIRD_PRESTIGE_PLAYER = 889,	 // 第三玩家(威望)

	WORLD_PROP_NATIONAL_GUESS_ACTIVITY = 890,	   // x 竞猜总数值 y 竞猜总人数
	WORLD_PROP_NATIONAL_GUESS_MEN1 = 891,		   // 竞猜活动1 ： x , y , z 名字 最多放三个玩家
	WORLD_PROP_NATIONAL_GUESS_MEN2 = 892,		   // 竞猜活动2 ： x , y , z 名字 最多放三个玩家
	WORLD_PROP_NATIONAL_GUESS_MEN3 = 893,		   // 竞猜活动3 ： x , y , z 名字 最多放三个玩家
	WORLD_PROP_NATIONAL_GUESS_YEST_ACTIVITY = 894, // 昨天x 昨日获奖人数 y 竞猜总人数 z 昨日中奖值
	WORLD_PROP_FIRST_BS_PLAYER = 895,			   // 第一玩家(BOSS积分)
	WORLD_PROP_SECOND_BS_PLAYER = 896,			   // 第二玩家(BOSS积分)
	WORLD_PROP_THIRD_BS_PLAYER = 897,			   // 第三玩家(BOSS积分)

	WORLD_PROP_GCZ_BEGIN = 900,
	WORLD_PROP_GCZ_STATE = 900,		  // 攻城战当前阶段
	WORLD_PROP_GCZ_WINNER = 901,	  // 攻城战胜利信息 x：城主pid，y：当前占领公会id，z：上场胜利公会id
	WORLD_PROP_GCZ_MASTER_INFO = 902, // 攻城战占领公会信息
	WORLD_PROP_GCZ_END = 920,
	WORLD_PROP_MJSP = 1020,			  // 面甲大放送礼包
	WORLD_PROP_TREASUER_COUNT = 1021, // 寻宝总次数

	WORLD_PROP_QFXZ_RANK = 1030,	// 祈福仙子排名
	WORLD_PROP_XYDZP_RANK = 1031,	// 幸运大转盘排名
	WORLD_PROP_CZKB_RANK = 1032,	// 充值魁榜
	WORLD_PROP_XFZW_RANK = 1033,	// 消费之王
	WORLD_PROP_HF_CZKB_RANK = 1034, // 合服充值魁榜
	WORLD_PROP_SMMZ_RANK = 1035,	// 石墓迷阵排名
	WORLD_PROP_HF_HCZB = 1036,		// 合服皇城争霸首位城主及领取状态
	WORLD_PROP_HF_GWGC = 1037,		// 合服怪物攻城各BOSS刷新状态

	WORLD_PROP_ZSZB = 1040, // 战神争霸: 霸主pid, 奖励是否领取, 那一天, 霸主名称

	WORLD_PROP_SMMZ_RANK_1 = 1041,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_2 = 1042,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_3 = 1043,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_4 = 1044,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_5 = 1045,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_6 = 1046,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_7 = 1047,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_8 = 1048,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_9 = 1049,	// 石墓迷阵排名
	WORLD_PROP_SMMZ_RANK_10 = 1050, // 石墓迷阵排名

	WORLD_REDPACK_MONEYALL = 10814, // 红包池红包总数
	WORLD_REDPACK_MONEYROB = 10815, // 红包抢夺总数
	WORLD_REDPACK_MONEYKEY = 10816, // 抢夺红包总位置
	WORLD_REDPACK_OODER1 = 10817,	// 记录全民红包1-3名id
	WORLD_REDPACK_OODER2 = 10818,	// 记录全民红包4-6名id
	WORLD_OLD_ZREO_TIME = 10819,	// 记录上次执行过0点逻辑的时间

	WORLD_HYDT_TOTAL = 1041,   //     x 记录当前状态 是否开奖0、是否出奖1、是否领奖2			y 记录今天开奖 数字   z 记录 string 的max   s记录当天所有购买的玩家 id
	WORLD_HYDT_HISTORY = 1042, // 只用 string  用来记录所有的 history name

	// WORLD_PROP_XIAOJUBAOPEN_COUNT			= 1050,
	// WORLD_PROP_DAJUBAOPEN_COUNT			= 1051,

	// 新服冲级活动(开服活动限制7天):玩家等级
	WORLD_PROP_NS_FIGHT_LEVEL_1 = 1151,
	WORLD_PROP_NS_FIGHT_LEVEL_2 = 1152,
	WORLD_PROP_NS_FIGHT_LEVEL_3 = 1153,
	WORLD_PROP_NS_FIGHT_LEVEL_4 = 1154,
	WORLD_PROP_NS_FIGHT_LEVEL_5 = 1155,
	WORLD_PROP_NS_FIGHT_LEVEL_6 = 1156,
	// 新服冲级活动(开服活动限制7天):宠物等级
	WORLD_PROP_NS_FIGHT_PET_LEVEL_1 = 1160,
	WORLD_PROP_NS_FIGHT_PET_LEVEL_2 = 1161,
	WORLD_PROP_NS_FIGHT_PET_LEVEL_3 = 1162,
	WORLD_PROP_NS_FIGHT_PET_LEVEL_4 = 1163,
	WORLD_PROP_NS_FIGHT_PET_LEVEL_5 = 1164,
	// 新服冲级活动(开服活动限制7天):宝石评分
	WORLD_PROP_NS_FIGHT_STONE_1 = 1171,
	WORLD_PROP_NS_FIGHT_STONE_2 = 1172,
	WORLD_PROP_NS_FIGHT_STONE_3 = 1173,
	WORLD_PROP_NS_FIGHT_STONE_4 = 1174,
	WORLD_PROP_NS_FIGHT_STONE_5 = 1175,
	// 新服冲级活动(开服活动限制7天):建功立业
	WORLD_PROP_NS_FIGHT_GUILD_1 = 1176,
	WORLD_PROP_NS_FIGHT_GUILD_2 = 1177,
	WORLD_PROP_NS_FIGHT_GUILD_3 = 1178,
	WORLD_PROP_NS_FIGHT_GUILD_4 = 1179,
	WORLD_PROP_NS_FIGHT_GUILD_5 = 1180,
	WORLD_PROP_NS_FIGHT_GUILD_6 = 1181,
	// WORLD_PROP_PRAY_FIRST					= 1180,
	// 新服冲级活动(开服活动限制7天):龙魂
	WORLD_PROP_ACT_SOUL_1 = 1183,
	WORLD_PROP_ACT_SOUL_2 = 1184,
	WORLD_PROP_ACT_SOUL_3 = 1185,
	WORLD_PROP_ACT_SOUL_4 = 1186,
	WORLD_PROP_ACT_SOUL_5 = 1187,

	// 新服冲级活动(开服活动限制7天):英雄
	WORLD_PROP_ACT_HERO_1 = 1188,
	WORLD_PROP_ACT_HERO_2 = 1189,
	WORLD_PROP_ACT_HERO_3 = 1190,
	WORLD_PROP_ACT_HERO_4 = 1191,
	WORLD_PROP_ACT_HERO_5 = 1192,

	// 新服冲级活动(开服活动限制7天):魂石
	WORLD_PROP_ACT_STONE_1 = 1193,
	WORLD_PROP_ACT_STONE_2 = 1194,
	WORLD_PROP_ACT_STONE_3 = 1195,
	WORLD_PROP_ACT_STONE_4 = 1196,
	WORLD_PROP_ACT_STONE_5 = 1197,

	// 新服冲级活动(开服活动限制7天):官职
	WORLD_PROP_ACT_OFFICE_1 = 1198,
	WORLD_PROP_ACT_OFFICE_2 = 1199,
	WORLD_PROP_ACT_OFFICE_3 = 1200,
	WORLD_PROP_ACT_OFFICE_4 = 1201,
	WORLD_PROP_ACT_OFFICE_5 = 1202,

	// 新服冲级活动(开服活动限制7天):经脉
	WORLD_PROP_ACT_VEIN_1 = 1203,
	WORLD_PROP_ACT_VEIN_2 = 1204,
	WORLD_PROP_ACT_VEIN_3 = 1205,
	WORLD_PROP_ACT_VEIN_4 = 1206,
	WORLD_PROP_ACT_VEIN_5 = 1207,

	// 新服冲级活动(开服活动限制7天):翅膀竞技
	WORLD_PROP_ACT_WING_LEVEL_1 = 1211,
	WORLD_PROP_ACT_WING_LEVEL_2 = 1212,
	WORLD_PROP_ACT_WING_LEVEL_3 = 1213,
	WORLD_PROP_ACT_WING_LEVEL_4 = 1214,
	WORLD_PROP_ACT_WING_LEVEL_5 = 1215,
	WORLD_PROP_ACT_WING_LEVEL_6 = 1216,

	// 开服建功立业活动
	WORLD_PROP_GUILD_STARTING_1 = 1301,
	WORLD_PROP_GUILD_STARTING_2 = 1302,
	WORLD_PROP_GUILD_STARTING_3 = 1303,
	WORLD_PROP_GUILD_STARTING_4 = 1304,
	WORLD_PROP_GUILD_STARTING_5 = 1305,
	WORLD_PROP_GUILD_STARTING_6 = 1306,
	WORLD_PROP_GUILD_STARTING_7 = 1307,
	WORLD_PROP_GUILD_STARTING_8 = 1308,
	WORLD_PROP_GUILD_STARTING_9 = 1309,
	WORLD_PROP_GUILD_STARTING_10 = 1310,

	WORLD_PROP_BEGIN_TIME = 2000,	 // 游戏时间开始时间
	WORLD_PROP_RECHARGE_INFO = 2002, // 充值引导

	// 全服称号记录
	WORLD_PROP_HEADTITLE_BEGIN = 3000, // 全服称号: pid
	WORLD_PROP_HEADTITLE_END = 3500,

	//
	WORLD_PROP_SPECIAL_MOSTER_LIST_1 = 3600, // 沙城弓箭手的存活状态
	WORLD_PROP_SPECIAL_MOSTER_LIST_2 = 3601, // 矿洞帮众的存活状态

	// 开服10天活动的领先者名单数据(十天嘉年华)
	WORLD_PROP_WORLD_NEW_SERVER_BEGIN = 5000,
	WORLD_PROP_WORLD_FIRST_ZS_LEVEL = 5001,
	WORLD_PROP_WORLD_FIRST_FS_LEVEL = 5002,
	WORLD_PROP_WORLD_FIRST_DS_LEVEL = 5003,
	// WORLD_PROP_WORLD_WINGS_MAX				= 5004,
	WORLD_PROP_WORLD_PET_MAX = 5005,
	WORLD_PROP_WORLD_TUHAO_MAX = 5007,
	WORLD_PROP_WORLD_STONE_MAX = 5008,
	WORLD_PROP_WORLD_SPRIDER_MAX = 5009,
	WORLD_PROP_WORLD_STRONG_MAX = 5010,
	WORLD_PROP_WORLD_IDENTIFY_MAX = 5011,
	WORLD_PROP_WORLD_FIRST_COMBAT_ZS_MAX = 5012,
	WORLD_PROP_WORLD_FIRST_COMBAT_FS_MAX = 5013,
	WORLD_PROP_WORLD_FIRST_COMBAT_DS_MAX = 5014,
	WORLD_PROP_WORLD_NEW_SERVER_END = 5100,
	WORLD_PROP_KFHD_XFBD_MIN = 5101,		// 开服活动-消费夺宝
	WORLD_PROP_KFHD_XFBD_MAX = 5133,		// 开服活动-消费夺宝
	WORLD_PROP_KFHD_XFPH_MIN = 5140,		// 开服活动-消费排行
	WORLD_PROP_KFHD_XFPH_MAX = 5143,		// 开服活动-消费排行
	WORLD_PROP_OFFICIAL_RECHARGE_YB = 5200, // 官网充值推送元宝数
	WORLD_PROP_CHAOXI_RANK = 5201,			// 潮汐幻境 的排行榜
	WORLD_PROP_VIP_SERVICE_RECHARGE = 5202, // vip专属服务所需充值额度（默认5000)
	WORLD_PROP_DABAO_MIN = 5300,			// 打宝任务
	WORLD_PROP_DABAO_MAX = 5399,			// 打宝任务
	WORLD_PROP_FIFA_MIN = 5400,				// 2018世界杯足球赛（16组比赛数值）
	WORLD_PROP_FIFA_MAX = 5415,				// 2018世界杯足球赛（16组比赛数值

	WORLD_PROP_CROSS_WARM_UP_RANK = 5420, // 跨服预热贡献排行榜

	WORLD_PROP_LUCKY_POWER_START = 5500,
	WORLD_PROP_LUCKY_POWER_1 = 5501, // 幸运神力 第1位 pid
	WORLD_PROP_LUCKY_POWER_2 = 5502, // 幸运神力 第2位 pid
	WORLD_PROP_LUCKY_POWER_3 = 5503, // 幸运神力 第3位 pid
	WORLD_PROP_LUCKY_POWER_4 = 5504, // 幸运神力 第4位 pid
	WORLD_PROP_LUCKY_POWER_5 = 5505, // 幸运神力 第5位 pid
	WORLD_PROP_LUCKY_POWER_6 = 5506, // 幸运神力 第6位 pid

	WORLD_PROP_RECHARGE_500_DATA = 10010,
	WORLD_PROP_USEGOLD_300_DATA = 10011,
	WORLD_PROP_FORGE_8_CHARGE = 10018, // 强化7-8需要充值的元宝数

	// 老一批内置活动
	WORLD_PROP_ACTIVITY_START = 10020,	  // 内置运营活动开始
	WORLD_PROP_ACTIVITY_END = 10070,	  // 内置运营活动结束
	WORLD_PROP_REBRON_PLAYER_NUM = 10201, // 到达转3的人数

	// 战区开启标识
	WORLD_PROP_WARZONE_OPEN_FLAG_BEGIN = 10203,
	WORLD_PROP_WARZONE_OPEN_FLAG_END = 10212,

	// 超级boss[不同大陆]
	WORLD_PROP_SUPER_BOSS_1 = 10215,
	WORLD_PROP_SUPER_BOSS_2 = 10216,
	WORLD_PROP_SUPER_BOSS_3 = 10217,
	WORLD_PROP_SUPER_BOSS_4 = 10218,

	// boss首杀
	WORLD_PROP_BOSS_FIRST_KILL_BEGIN = 10305,
	WORLD_PROP_BOSS_FIRST_KILL_END = 10400,

	WORLD_PROP_PLAYER_NUM_ALL = 10405, // 全服总人数

	WORLD_PROP_GUILD_SHOP_VERSION = 10406,		  // 公会商城版本
	WORLD_PROP_CREATE_PLAYER_LIMITED_DAY = 10407, // 邀请码开启天数

	WORLD_PROP_TRANSACTION_LIMIT = 10408, // 元宝每日使用上限

	WORLD_PROP_RANK_AWARD_BEGIN = 10412, // 新服排行奖励开始
	WORLD_PROP_RANK_AWARD_1 = 10413,	 // 新服 玩家等级排行奖励
	WORLD_PROP_RANK_AWARD_2 = 10414,	 // 新服 宝宝战力排行奖励

	WORLD_PROP_COMMON_CROSS_SERVER_ID = 10420,

	WORLD_PROP_WAR_ZONE_INFO = 10425,	   // 战区信息
	WORLD_PROP_WAR_ZONE_DATE_INFO = 10426, // 战区开启时间信息
	WORLD_PROP_WAR_ZONE_STATUS = 10427,	   // 战区状态(0: 未开启   1： 预热中  2：正式开启中）
	WORLD_PROP_WAR_ZONE_FIRST = 10428,	   // 第一个战区

	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME = 10429,

	// 寻宝 随机数
	WORLD_PROP_TREASURE_HUNT_RANDOM_BEGIN = 10430,	// 活动寻宝随机数 (X:保存的是需要全服寻宝达到的次数， Y 是全服寻宝已经得到的物品)
	WORLD_PROP_TREASURE_HUNT_RANDOM_END = 10458,	// 活动寻宝随机数
	WORLD_PROP_TREASURE_HUNT_OPEN = 10480,			// 活动寻宝开启（X 是否开启； Y 全服寻宝次数）
	WORLD_PROP_TREASURE_HUNT_FIRST_REFRESH = 10481, // 活动首次开启

	// 战区boss击杀排行榜重置时间
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_1 = 10490,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_2 = 10491,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_3 = 10492,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_4 = 10493,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_5 = 10494,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_6 = 10495,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_7 = 10496,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_8 = 10497,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_9 = 10498,
	WORLD_PROP_RESET_KILL_BOSS_RANK_TIME_WAR_ZONE_10 = 10499,

	//
	WORLD_PROP_DIAMOND_RECOVER_BEGIN = 10500, // 限制钻石回收次数
	WORLD_PROP_DIAMOND_RECOVER_END = 11000,	  // 限制钻石回收次数

	WORLD_PROP_AUCTION_INDEX = 11001, // 拍卖行id

	WORLD_PROP_CSZT_RANK_1 = 11002,	 // 传说之塔排行榜(x:pid,y:chengji,z:ryz,s:name,sourceSvrName)
	WORLD_PROP_CSZT_RANK_10 = 11011, // 传说之塔排行榜(1-10之间不要占用)

	WORLD_PROP_SHACHENG_DONATE = 12001,		 // 沙城捐献总额
	WORLD_PROP_SHACHENG_DONATE_FAKE = 12002, // 沙城捐献作假额度

	WORLD_PROP_PEAK_MAP_IS_OPEN_1 = 12003, // 巅峰地图是否开放（翅膀）
	WORLD_PROP_PEAK_MAP_IS_OPEN_2 = 12004, // 巅峰地图是否开放（特戒）
	WORLD_PROP_PEAK_MAP_IS_OPEN_3 = 12005, // 巅峰地图是否开放（转生）
	WORLD_PROP_PEAK_MAP_IS_OPEN_4 = 12006, // 巅峰地图是否开放（神盾）

	WORLD_PROP_BLACK_MARKET_NPC_INFO = 12012, // 黑市商人实体ID,场景ID,结束时间
	WORLD_PROP_BLACK_MARKET_NEXT_POS = 12013, // 黑市商人下次出现位置

	WORLD_PROP_NEW_ACTIVITY_START = 12020, // 内置运营活动开始
	WORLD_PROP_NEW_ACTIVITY_END = 14999,   // 内置运营活动结束

	// 11012 - 15000   记录的是BOSS的刷新时间 (预留)
	// 31012 - 35000   记录的是BOSS上一次是死亡的时间(预留)
	WORLD_PROP_CHAT_WARZONE_REQ = 15001, // 战区聊天限制
	WORLD_PROP_WORLD_INIT = 15002,		 // 战区初始化

	WORLD_PROP_WORLD_SECOND_ALL_DATA = 15003, // 天下第二   新加的  pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_WORLD_THIRD_ALL_DATA = 15004,  // 天下第三   新加的  pid, （reborn << 16 | level）,性别，名字
	WORLD_PROP_ALLPLAYERREST = 15005,		  // 玩家每日重置通知
	WORLD_MOVE_SPEED_ENABLE_EX = 15006,		  // 移动加速 修正值
	WORLD_ATTACK_SPEED_ENABLE_EX = 15007,	  // 攻击加速 修正值
	WORLD_PROP_WORLD_BOSS_DATA = 15008,		  // 世界boss

	WORLD_PROP_SERVER_SU_MOVE = 15008,
	WORLD_PROP_MOVE_CHECK_METHOD = 15009, //  0 表示 龙城的 方法 1 表示单职业的 方法；默认 龙城的发放

	WORLD_PROP_RECORD_CHAT_QQ = 15100,		// 官方QQ群号 交流群号
	WORLD_PROP_RECORD_CHAT_QQ_KEY = 15101,	// 官方QQ群号 交流群号key值
	WORLD_PROP_RECORD_DEAL_QQ = 15102,		// 官方QQ群号 交易群
	WORLD_PROP_RECORD_DEAL_QQ_KEY = 15103,	// 官方QQ群号 交易群号key值
	WORLD_PROP_RECORD_CHAT_QQ_NAME = 15104, // 官方QQ群号 交流群名
	WORLD_PROP_RECORD_DEAL_QQ_NAME = 15105, // 官方QQ群号 交易群名

	WORLD_PROP_WORSHIP_DESPISE_AND_SUPPORT = 15106, // 膜拜鄙视

	WORLD_PROP_MILITARY_EXPLOITS_RANK_1 = 15107, // 战功排行榜第一名 x,y,z  服务器id,角色id,旧角色id
	WORLD_PROP_MILITARY_EXPLOITS_RANK_2 = 15108, // 战功排行榜第二名
	WORLD_PROP_MILITARY_EXPLOITS_RANK_3 = 15109, // 战功排行榜第三名
	WORLD_PROP_MILITARY_EXPLOITS_RANK_4 = 15110, // 战功排行榜第四名
	WORLD_PROP_MILITARY_EXPLOITS_RANK_5 = 15111, // 战功排行榜第五名

	WORLD_PROP_WAR_ZONE_RANK_TYPE = 15112, // 跨服排行活动类型 1、战功排行（烽火捐献） 2、威望排行（光明顶）

	WORLD_PROP_SHENQIZHONG_RANK_1 = 15113, // 神器冢排行榜第一名 x,y,z  服务器id,角色id,旧角色id
	WORLD_PROP_SHENQIZHONG_RANK_2 = 15114, // 神器冢排行榜第二名
	WORLD_PROP_SHENQIZHONG_RANK_3 = 15115, // 神器冢排行榜第三名

	WORLD_PROP_PAIMAI_INFO = 15121, // 拍卖行版本

	WORLD_PROP_KF_RECOVERY_START = 15131, // 装备首爆开始
	// 15131~15680
	WORLD_PROP_KF_RECOVERY_END = 15680, // 装备首爆结束

	WORLD_PROP_KF_DROP_START = 15681, // 装备回收开始
	// 15681~16231
	WORLD_PROP_KF_DROP_END = 16231, // 装备回收结束

	WORLD_PROP_SC_TREASURY_INFO = 16260,		 // 沙城宝库信息 x:开启时间 y:剩余可掉落灵符数量
	WORLD_PROP_CLEAR_DBBK_ITEM_LAST_DAY = 16261, // 最后清除打宝宝库道具的时间

	WORLD_PROP_TIME_WORLD_BOSS_DATA = 16270, // 限时世界BOSS

	// 首杀 16275 - 16300
	WORLD_PROP_FIRSTBLOOD_BOSS_DATA = 16275, // BOSS

	WORLD_PROP_FIRSTBLOOD_HIGH_DATA_START = 16280, // 伤害最高
	WORLD_PROP_FIRSTBLOOD_HIGH_DATA_END = 16289,
	WORLD_PROP_FIRSTBLOOD_LAST_DATA_START = 16290, // 最后一击
	WORLD_PROP_FIRSTBLOOD_LAST_DATA_END = 16299,

	WORLD_PROP_JJKH_BEGIN = 16300,
	WORLD_PROP_JJKH_WEN_ZHANG = 16301,			// 纹章排行
	WORLD_PROP_JJKH_SHEN_JIAN_SHEN_JIA = 16302, // 神剑神甲排行
	WORLD_PROP_JJKH_ZHAN_LI = 16303,			// 战力排行
	WORLD_PROP_JJKH_XIAO_FEI = 16304,			// 消费排行
	WORLD_PROP_JJKH_ZHUAN_SHENG = 16305,		// 转生排行
	WORLD_PROP_JJKH_END = 16320,

	WORLD_PROP_FIRSTBLOOD_HIGH_DATA_START_EX = 16330, // 伤害最高
	WORLD_PROP_FIRSTBLOOD_HIGH_DATA_END_EX = 16339,
	WORLD_PROP_FIRSTBLOOD_LAST_DATA_START_EX = 16340, // 最后一击
	WORLD_PROP_FIRSTBLOOD_LAST_DATA_END_EX = 16349,

	WORLD_PROP_SC_BOSS_STATE = 16350, // 沙城boss阶段

	WORLD_PROP_GUILD_DECLARE_RESET = 16351, // 重置宣战次数

	WORLD_PROP_CHAT_NEARBY_REQ = 16352,//附近频道聊天所需等级

	// 运营活动中使用world id 站位
	WORLD_PROP_HOLIDAY_BEGIN = 21001,
	WORLD_PROP_HOLIDAY_END = 21999,
};

enum CSZT_ACTION
{
	CSZT_FIGHT = 1, // 挑战
	CSZT_SHOW = 2,	// 詳情
};

enum HolidayWorldProp
{
	// 十天嘉年华奖励发放情况
	WORLD_PROP_JNH_REWARD = 20001,
};

enum HolidayEvent
{
	// 运营活动使用event id占位
	EVENT_ID_HOLIDAY_BEGIN = 5000,
	EVENT_ID_HOLIDAY_END = 9999,
};

// 活动类型
enum HolidayType
{
	HOLIDAY_TYPE_BEGIN = 0,
	HOLIDAY_RECHARGE_TOTAL = 1,	 // 累计充值
	HOLIDAY_RECHARGE_COUNT = 2,	 // 累次充值
	HOLIDAY_CONSUME_TOTAL = 3,	 // 累计消费
	HOLIDAY_RECHARGE_DAILY = 4,	 // 每日累充
	HOLIDAY_COLLECT_WORD = 9,	 // 集字活动
	HOLIDAY_FESTIVAL_SHOP = 10,	 // 节日商店
	HOLIDAY_BESTITEM_LIMIT = 11, // 极品限购
	HOLIDAY_ZHANLING = 12,		 // 战令
	HOLIDAY_SIGN = 13,			 // 每日签到
	HOLIDAY_THYK = 14,			 // 特惠月卡
	HOLIDAY_ZSDH = 15,			 // 钻石兑换
	HOLIDAY_XYZP = 16,			 // 幸运转盘
	HOLIDAY_MRDL = 17,			 // 每日登陆
	HOLIDAY_XJZG = 18,			 // 现金直购
	HOLIDAY_LSLB = 19,			 // 连锁礼包
	HOLIDAY_MLGJ = 20,			 // 猛龙过江
	HOLIDAY_JBP = 21,			 // 聚宝盆
	HOLIDAY_RANK_START = 22,
	HOLIDAY_CHONGZHI_RANK = 22,	 // 充值排行
	HOLIDAY_XIAOFEI_RANK = 23,	 // 消费排行
	HOLIDAY_XUNBAO_RANK = 24,	 // 寻宝排行
	HOLIDAY_FINANCIAL_SIGN = 25, // 工会理财签到
	HOLIDAY_RANK_END = 40,
	HOLIDAY_GWTJ = 41, // 怪物通缉
	HOLIDAY_GWKH = 42, // 怪物狂欢
	HOLIDAY_ZBSB = 43, // 装备首爆
	HOLIDAY_ZBHS = 44, // 装备回收
	HOLIDAY_SLZL = 45, // 神龙之力
	HOLIDAY_XBKH = 46, // 寻宝狂欢
	HOLIDAY_KF3V3 = 47, // 跨服3v3
	HOLIDAY_TYPE_END,  // 全部活动结束
};

// 转盘任务
enum XYZPTask
{
	TASK_ONLINE = 1,	  // 在线时长
	TASK_RECHARGE = 2,	  // 每日充值
	TASK_KILL_PLAYER = 3, // 击杀玩家
	TASK_KILL_BOSS = 4,	  // 击杀BOSS
	TASK_USE_LF = 5,	  // 消费灵符
};

// 拍卖行
enum AUCTION_TYPE
{
	AUCTION_TYPE_IID = 1,			  // 物品的唯一id
	AUCTION_TYPE_SID = 2,			  // 物品id
	AUCTION_TYPE_SERVER_ID = 3,		  // 服务器id
	AUCTION_TYPE_TIME = 4,			  // 销毁类型
	AUCTION_TYPE_IS_NEXT_AUCTION = 5, // 是否进入下一个拍卖行
	AUCTION_TYPE_COMPETE_PRICE = 6,	  // 竞争价格
};

// 运营活动定义
enum HolidayDefine
{
	// 运营活动物品类型
	HOLIDAY_ITEM_TYPE_REWARD = 1,  // 奖励物品
	HOLIDAY_ITEM_TYPE_CONSUME = 2, // 消耗物品

	HOLIDAY_GRADE_INDEX = 1,	  // 档次索引
	HOLIDAY_GRADE_INDEX_MAX = 99, // 档次索引最大值

	HOLIDAY_CATE_HOLIDAY = 1, // 活动
	HOLIDAY_CATE_GRADE = 2,	  // 档次
	HOLIDAY_CATE_ITEM = 3,	  // 物品

	HOLIDAY_RANK_INIT_SIZE = 3, // 排行榜初始化数量倍数

	HOLIDAY_ITEM_INDEX_TRANS = 1000, // 物品所以转换数

	HOLIDAY_STRPROP_TRANS = 1000, // 属性索引转换(整形<1000，字符串>1000)
};

// 运营活动属性
enum HolidayProp
{
	// 添加属性要在HolidayManager中配置次属性是否需要更新清楚
	// --------------------------------------------------------------------------------------

	// 活动整数属性
	HOLIDAY_PROP_BEGIN = 0,
	HOLIDAY_PROP_SWITCH = 1,			 // 活动开关
	HOLIDAY_PROP_RESET = 2,				 // 是否每日重置
	HOLIDAY_PROP_OPEN_LEVEL = 3,		 // 活动开启等级
	HOLIDAY_PROP_UPDATE_RESET = 4,		 // 更新是否重置活动 0：否 1：是
	HOLIDAY_PROP_WORLDID_IDX = 5,		 // 世界属性重置戳
	HOLIDAY_PROP_SORT = 6,				 // 排序编号
	HOLIDAY_PROP_REPETITION = 7,		 // 重复多开
	HOLIDAY_PROP_CAN_NOT_DELETE = 8,	 // 可否删除 0：可以删除，1：不可删除
	HOLIDAY_PROP_FESTIVAL = 9,			 // 什么节日活动
	HOLIDAY_PROP_RANK_IN = 10,			 // 排行榜上榜条件
	HOLIDAY_PROP_SHOW_SERVER_DAYS = 11,	 // 相对开服时间开启显示天数
	HOLIDAY_PROP_OPEN_SERVER_DAYS = 12,	 // 相对开服时间开启天数
	HOLIDAY_PROP_CLOSE_SERVER_DAYS = 13, // 相对开服时间关闭天数
	HOLIDAY_PROP_HIDE_SERVER_DAYS = 14,	 // 相对开服时间关闭显示天数
	HOLIDAY_PROP_SHOW_HEFU_DAYS = 15,	 // 相对合服时间开启显示天数
	HOLIDAY_PROP_OPEN_HEFU_DAYS = 16,	 // 相对合服时间开启天数
	HOLIDAY_PROP_CLOSE_HEFU_DAYS = 17,	 // 相对合服时间关闭天数
	HOLIDAY_PROP_HIDE_HEFU_DAYS = 18,	 // 相对合服时间关闭显示天数
	HOLIDAY_PROP_WAR_ZONE_ID = 19,		 // 战区ID
	HOLIDAY_PROP_END,

	// 档次整数属性
	HOLIDAY_GRADE_PROP_BEGIN = 0,
	HOLIDAY_GRADE_PROP_LEVEL = 1,		 // 等级需求
	HOLIDAY_GRADE_PROP_REBORN = 2,		 // 转生需求
	HOLIDAY_GRADE_PROP_NEED = 3,		 // 条件数量
	HOLIDAY_GRADE_PROP_LIMIT = 4,		 // 个人限次
	HOLIDAY_GRADE_PROP_WORLD_LIMIT = 5,	 // 全服限次
	HOLIDAY_GRADE_PROP_WEIGHT = 6,		 // 档次权重
	HOLIDAY_GRADE_PROP_REPORT = 7,		 // 极品播报
	HOLIDAY_GRADE_PROP_RANK_BEGIN = 8,	 // 排行名次开始
	HOLIDAY_GRADE_PROP_RANK_END = 9,	 // 排行名次结束
	HOLIDAY_GRADE_PROP_RECHARGE_ID = 10, // 付费ID
	HOLIDAY_GRADE_PROP_SECTION = 11,	 // 档次段
	HOLIDAY_GRADE_PROP_RANK_IN = 12,	 // 排行上榜条件
	HOLIDAY_GRADE_PROP_DISCOUNT = 13,	 // 折扣档次展示
	HOLIDAY_GRADE_PROP_RECHARGE = 14,	 // 充值需求
	HOLIDAY_GRADE_PROP_JOB = 15,		 // 职业需求
	HOLIDAY_GRADE_PROP_RESET = 16,		 // 档位每日重置
	HOLIDAY_GRADE_PROP_END,

	// 物品整数属性
	HOLIDAY_ITEM_PROP_BEGIN = 0,
	HOLIDAY_ITEM_PROP_WEIGHT = 1, // 权重
	HOLIDAY_ITEM_PROP_LIMIT = 2,  // 限制条件
	HOLIDAY_ITEM_PROP_TYPE = 3,	  // 分类条件
	HOLIDAY_ITEM_PROP_SHOW = 4,	  // 奖励展示
	HOLIDAY_ITEM_PROP_END,

	// 活动字符串属性
	HOLIDAY_STRPROP_BEGIN = 1000,
	HOLIDAY_STRPROP_SERVERID = 1001, // 服务器列表
	HOLIDAY_STRPROP_CHANNEL = 1002,	 // 渠道列表
	HOLIDAY_STRPROP_PPATFORM = 1003, // 平台列表
	HOLIDAY_STRPROP_KEY = 1004,		 // 活动key
	HOLIDAY_STRPROP_END,

	// 档次字符串属性
	HOLIDAY_GRADE_STRPROP_BEGIN = 1000,
	HOLIDAY_GRADE_USERSELF_PROP = 1001, // 档次自定义属性
	HOLIDAY_GRADE_PORT_PROP = 1002,		// iOS平台识别类型
	HOLIDAY_GRADE_TYPE_NAME = 1003,		// 类型名称
	HOLIDAY_GRADE_STRPROP_END,

	// 物品字符串属性
	HOLIDAY_ITEM_STRPROP_BEGIN = 1000,
	HOLIDAY_ITEM_STRPROP_END,
};

// 内置活动状态
enum ActivityState
{
	ACTIVITY_STATE_UNKNOW = 0, // 未知
	ACTIVITY_STATE_OPEN = 1,   // 开启
	ACTIVITY_STATE_END = 2,	   // 结束
};

// 活动归属
enum ActivityRoot
{
	ACTIVITY_ROOT_OPEN = 1,			// 开服活动
	ACTIVITY_ROOT_JOIN = 2,			// 合服活动
	ACTIVITY_ROOT_INLAY = 3,		// 内置活动
	ACTIVITY_ROOT_FULI = 4,			// 福利活动
	ACTIVITY_ROOT_ZHANLING = 5,		// 战令活动
	ACTIVITY_ROOT_GONGHUILICAI = 6, // 增加活动归属工会理财
};

// 内置活动相对时间
enum ActivityCate
{
	ACTIVITY_CATE_OPEN = 1, // 相对开服时间
	ACTIVITY_CATE_JOIN = 2, // 相对合服时间
};

// 投资类型
enum FuliType
{
	FULI_TYPE_BEGIN = 0,
	FULI_TOUZI_KILL = 1,   // 除魔基金
	FULI_TOUZI_WEAPON = 2, // 神剑基金
	FULI_TOUZI_CLOTH = 3,  // 神甲基金
	FULI_TOUZI_LEVEL = 4,  // 升级基金
	FULI_TOUZI_REBORN = 5, // 转生基金
	FULI_TYPE_END,
};

// 是否是挑战者
enum ArenaChallengeType
{
	ARENA_FIGHT_IS_CHALLENGE_FALSE = 0,
	ARENA_FIGHT_IS_CHALLENGE_TRUE = 1,
};

// 挑战结果
enum ArenaChallengeResult
{
	ARENA_FIGHT_IS_LOSE = 0,
	ARENA_FIGHT_IS_WIN = 1,
};

// 基因类型
enum GeneType
{
	GENE_TYPE_RECOVER = 1,	 // 恢复
	GENE_TYPE_BLADEMAIL = 3, // 反伤

	GENE_TYPE_SAND = 5,			// 沙城
	GENE_TYPE_SAND_WAR_GOD = 6, // 战神之力
	GENE_TYPE_SAND_MAFA = 7,	// 玛法神力
	GENE_TYPE_SAND_REVANGE = 8, // 复仇之怒

	GENE_TYPE_MOT = 11,			  // MOT
	GENE_TYPE_HOT = 12,			  // HOT
	GENE_TYPE_DOT = 13,			  // DOT
	GENE_TYPE_DAZE = 14,		  // 定身
	GENE_TYPE_DAZE_IMMUNITY = 15, // 定身免疫
	GENE_TYPE_INVINCIBLE = 16,	  // 无敌
	GENE_TYPE_STICK = 17,		  // 沉默
	GENE_TYPE_SPEED_STRANGE = 18, // 加速器惩罚

	GENE_TYPE_VISIABLE = 20,	   // 隐身
	GENE_TYPE_HIDE = 21,		   // 道士破隐
	GENE_TYPE_VIP = 25,			   // VIP
	GENE_TYPE_HEADTITLE = 26,	   // 称号
	GENE_TYPE_HEADTITLE_TIME = 27, // 称号持续时间
	GENE_TYPE_ITEM_TIME = 28,	   // 物品过期时间

	GENE_TYPE_DAMAGE = 30,			// 伤害
	GENE_TYPE_DEFEND = 31,			// 防御
	GENE_TYPE_HPMAX = 32,			// 最大生命
	GENE_TYPE_MPMAX = 33,			// 最大魔法
	GENE_TYPE_LUCKY = 34,			// 幸运
	GENE_TYPE_DAMAGE_LAST_ADD = 35, // 伤害结算
	GENE_TYPE_ADD_PHY_DEFEND = 36,	// 增加物防
	GENE_TYPE_ADD_MIC_DEFEND = 37,	// 增加魔防
	GENE_TYPE_EQUIP_DISABLE = 38,	// 装备失效

	GENE_TYPE_BUFFER_MODIFY_COMBAT_PROP = 39, // 修正目标战斗属性
	GENE_TYPE_ADD_PHY_MIC_DEFEND = 40,	// 增加物防、魔防（37+38），有别于31

	GENE_TYPE_EFFECT = 50, // 特效

	GENE_TYPE_SPEED_MOVE = 60,	 // 速度
	GENE_TYPE_GIRL_PROTECT = 65, // 美女护送

	GENE_TYPE_KILL_MONSTER_EXP = 100, // 杀怪经验
	GENE_TYPE_FIRE_EXP = 101,		  // 篝火经验
	GENE_TYPE_HONOR_EXP = 102,		  // 荣誉神殿奖励
	GENE_TYPE_DOUBLE_EXP = 103,		  // 个人双倍经验
	GENE_TYPE_HALF_AGAIN_EXP = 104,	  // 个人1.5倍经验

	GENE_TYPE_FB_STATE = 148, // 副本状态
	GENE_TYPE_FB_BOSS = 149,  // 副本boss
	GENE_TYPE_XMFB = 150,	  // 降魔副本

	GENE_TYPE_MITIGATE = 200,		// 护盾
	GENE_TYPE_POISON = 201,			// 毒
	GENE_TYPE_RED_POISON = 202,		// 毒
	GENE_TYPE_POISON_PERCENT = 203, // 毒,百分比掉血
	GENE_TYPE_GREEN_POISON = 204,	// 绿毒,对怪物持续伤害

	GENE_TYPE_SCRIPT_ITEM = 210, // 物品脚本
	// GENE_TYPE_SCRIPT_HONOR			= 211,		//荣誉脚本
	GENE_TYPE_SCRIPT_SKILL = 212, // 技能脚本

	GENE_TYPE_POISON_AREA_SKILL = 300, // 万毒噬天
	GENE_TYPE_SCRIPT_PET_SKILL = 301,  // 宠物技能
	GENE_TYPE_ARMOR = 302,			   // 护甲
	GENE_TYPE_YK = 303,				   // 月卡buff
	GENE_TYPE_QL = 304,				   // 宠物技能（青龙）
	GENE_TYPE_ZQ = 305,				   // 宠物技能（朱雀）
	GENE_TYPE_PET_DEFEND = 306,		   // 宠物玄武（玄武）

	GENE_TYPE_GUILD = 307, // 行会等级
	GENE_TYPE_TITLE = 308, // 活跃称号

	GENE_TYPE_EXERCISE = 309, // 内功回复

	// GENE_TYPE_TAOWEAP				= 310,		//法器
	GENE_TYPE_FALIJJ = 311,		   // 法力荆棘
	GENE_TYPE_FIRE_SWORD = 312,	   // 烈火
	GENE_TYPE_ZHU_RI = 313,		   // 逐日
	GENE_TYPE_PHY_DAM = 314,	   // 物理伤害
	GENE_TYPE_MAG_DAM = 315,	   // 魔法伤害
	GENE_TYPE_TAO_DAM = 316,	   // 道术伤害
	GENE_TYPE_QF_DOUBLE_EXP = 317, // 全服双倍
	GENE_TYPE_RECOVER_HM = 318,	   // 恢复血和蓝
	GENE_TYPE_TIPS = 319,		   // 提示
	GENE_TYPE_OFFLINE = 320,	   // 挂机
	GENE_TYPE_GOD_LV = 321,		   // 神
	GENE_TYPE_GOD_NEST = 322,	   // 神
	GENE_TYPE_PERC_EXP = 323,	   // 经验降低
	GENE_TYPE_HMOD = 324,		   // 加血和蓝百分比
	GENE_TYPE_PROP_SHILED = 327,   // pk护盾
	GENE_TYPE_ALL_DAM = 328,	   // 百分比挺高所有伤害力
	GENE_TYPE_SUCK_BLOOD = 329,	   // 百分比吸血
	GENE_TYPE_HOT_PERCENT = 330,   // 规定时间内持续百分比回血
	GENE_TYPE_ADD_DEFEND = 331,	   // 百分比挺高防御
	GENE_TYPE_PROTECT_RING = 332,  // 护身特戒cd
	GENE_TYPE_REVIVE_RING = 333,   // 复活特戒cd
	GENE_TYPE_LEASE = 334,		   // 神兵租赁
	GENE_TYPE_WINGSKILL_1 = 335,
	GENE_TYPE_WINGSKILL_2 = 336,
	GENE_TYPE_WINGSKILL_3 = 337,
	GENE_TYPE_WINGSKILL_4 = 338,
	GENE_TYPE_CURSE = 339,					// 诅咒
	GENE_TYPE_DRINKBLOOD = 340,				// 嗜血
	GENE_TYPE_BOSS_DAMAGE = 341,			// boss积分 伤害
	GENE_TYPE_BOSS_LUCK = 342,				// boss积分 增加掉落
	GENE_TYPE_PRIVILEGE = 343,				// 特权
	GENE_TYPE_CRIT = 344,					// 增加暴击值
	GENE_TYPE_GUILDQIFU = 345,				// 公会祈福
	GENE_TYPE_AGGRESSIVITY = 346,			// 天关药水增加攻击力
	GENE_TYPE_BAIL = 347,					// 红名保释
	GENE_TYPE_GW_COIN = 348,				// 金币鼓舞
	GENE_TYPE_GW_INGOT = 349,				// 元宝鼓舞
	GENE_TYPE_YZBQ = 350,					// 夜战比奇buff
	GENE_TYPE_ADDMAXHP = 351,				// 增加生命值上限
	GENE_TYPE_DAM_PHY = 352,				// 物理伤害 + 累加时间
	GENE_TYPE_DAM_MAG = 353,				// 法术伤害 + 累加时间
	GENE_TYPE_DAM_TAO = 354,				// 道术伤害 + 累加时间
	GENE_TYPE_GODEQUIP_ADD_ATK = 355,		// 神装增伤
	GENE_TYPE_GODEQUIP_ADD_DEF = 356,		// 神装减伤
	GENE_TYPE_HMOD_PRIOD = 358,				// 血蓝回复加速%（一段时间内）
	GENE_TYPE_GLJ_ADD_ATK = 359,			// 鬼灵剑增伤
	GENE_TYPE_HLJ_HPMAX = 360,				// 海龙戟增加最大生命百分比
	GENE_TYPE_XJK_DEC_COMBINE_DEMAGE = 361, // 象甲窟受合击伤害减少
	GENE_TYPE_WINGSKILL_5 = 362,
	GENE_TYPE_SHIELD = 363,		// boss减伤盾
	GENE_TYPE_DEFEND_ALL = 364, // 防御(上下限)
	// 技能相关
	GENE_TYPE_ATTACK_SPEED_ADD = 365,  // 攻速增加（技能符文）
	GENE_TYPE_ATTACK_HUIXIN_ADD = 366, // 提高会心率（技能符文）
	GENE_TYPE_MOVE_SPEED_DEL = 367,	   // 降低移速（技能）
	GENE_TYPE_DEFEND_DEL = 368,		   // 降低目标防御百分比（技能）
	GENE_TYPE_MOVE_SPEED_ADD = 369,	   // 提高移速（技能符文）

	GENE_TYPE_LIEHUUO_FIRE = 370,	// 烈火灼烧（技能符文）<火球术 灼烧buff>
	GENE_TYPE_KAITIAN_FROZEN = 371, // 开天冰冻（技能符文）
	GENE_TYPE_ASP_DEL = 372,		// 降低攻速（技能）
	GENE_TYPE_PATK_DEL = 373,		// 降低攻击力（技能符文）
	GENE_TYPE_DEFEND_ADD = 374,		// 增加防御（技能符文）
	GENE_TYPE_DAMAGE_ADD = 375,		// 伤害加成
	GENE_TYPE_NOTHING1 = 377,
	GENE_TYPE_NOTHING2 = 378,
	GENE_TYPE_SDQ_CRIT_RATE = 379, // 闪电拳（暴击几率）
	GENE_TYPE_SDQ_CRIT_DMG = 380,  // 闪电拳（暴击伤害）

	GENE_TYPE_ADD_DEFENCE = 381,	   // 增加防御百分比
	GENE_TYPE_ADD_CUT = 382,		   // 增加切割
	GENE_TYPE_ADD_DAMAGE = 383,		   // 提升增伤
	GENE_TYPE_ADD_CRIT = 384,		   // 增加暴击
	GENE_TYPE_ADD_M_IGNORE_HURT = 385, // 增加怪伤减免
	GENE_TYPE_ADD_MP_DAMAGE = 386,	   // 增加对怪增伤、pk增伤
	GENE_TYPE_FABAO_ZYHL_CD = 389,	   // 法宝紫玉葫芦CD
	GENE_TYPE_FABAO_FTLHS_CD = 390,	   // 法宝焚天烈火扇CD
	GENE_TYPE_FABAO_HHDHL_CD = 391,	   // 法宝火凰夺魂铃CD
	GENE_TYPE_FABAO_DHZ_CD = 392,	   // 法宝东皇钟CD
	GENE_TYPE_FABAO_JZLLB_CD = 393,	   // 法宝金盏琉璃杯CD
	GENE_TYPE_FABAO_SLFTY_CD = 394,	   // 法宝神龙番天印CD
	GENE_TYPE_FABAO_QKDHZ_CD = 395,	   // 法宝乾坤定海珠CD

	GENE_TTPE_JRFB = 398,					// 剑刃风暴
	GENE_TTPE_XFZ = 399,					// 旋风斩
	GENE_TYPE_FIRE_SWORD2 = 400,			// 烈火2
	GENE_TYPE_ZHU_RI2 = 401,				// 逐日2
	GENE_TYPE_SZH_CRIT_ADD = 402,			// 狮子吼（提高暴击）
	GENE_TYPE_SZH_AS_DEC = 403,				// 狮子吼（降低攻速）
	GENE_TYPE_CDD_PDEF_DEC = 404,			// 彻地钉（减物理防御）
	GENE_TYPE_CDD_MS_DEC = 405,				// 彻地钉（降低移动速度）
	GENE_TYPE_MTH_M_MB = 406,				// 灭天火（移动束缚）
	GENE_TYPE_SXS_SX = 407,					// 嗜血术（吸血增加）
	GENE_TYPE_KB = 408,						// 狂暴（召唤物攻速增加，伤害提升）
	GENE_TYPE_SBYS_MS_ADD = 409,			// 十步一杀（减速）
	GENE_TTPE_MTH_SHUFU = 410,				// 束缚 灭天火
	GENE_TTPE_SMZD = 411,					// 神秘之电
	GENE_TTPE_YINGYONG = 412,				// 英勇（飓风破没有冷却）
	GENE_TTPE_KLYZ = 413,					// 狂乱意志（心法）
	GENE_TTPE_SDBH = 414,					// 闪电庇护（心法）
	GENE_TTPE_SHIELD = 415,					// 护盾
	GENE_TTPE_BAOLV = 416,					// 护盾
	GENE_TYPE_MILITARY_RANK_1 = 417,		// 战功排行第一名（全服增加爆率）
	GENE_TYPE_MILITARY_RANK_2 = 418,		// 战功排行第二名（全服增加爆率）
	GENE_TYPE_MILITARY_RANK_3 = 419,		// 战功排行第三名（全服增加爆率）
	GENE_TYPE_MILITARY_RANK_4 = 420,		// 战功排行第四名（全服增加爆率）
	GENE_TYPE_MILITARY_RANK_5 = 421,		// 战功排行第五名（全服增加爆率）
	GENE_TTPE_SHENZHU = 422,				// 神柱buff
	GENE_TTPE_FROZEN = 423,					// 冰冻Buff
	GENE_TTPE_WJZQ = 424,					// 无极真气buff
	GENE_TYPE_MON_UN_RECOVER = 425,			// 怪物禁止生命恢复
	GENE_TYPE_HUNLING_SHELTER = 426,		// 魂灵套装 魂之庇佑
	GENE_TYPE_HUNLING_CUTTING = 427,		// 魂灵套装 斩妖除魔
	GENE_TYPE_HUNLING_TRUE_BODY = 428,		// 魂灵装备 蓝银真身
	GENE_TYPE_HUNLING_DODGE = 429,			// 魂灵装备 闪避数次攻击
	GENE_TYPE_HUNLING_HOLY_LIGHT = 430,		// 魂灵装备 圣光制裁
	GENE_TYPE_HUNLING_KNIFE_CRIT_HIT = 431, // 魂灵装备 刀刀暴击
	GENE_TYPE_GUARD_HALO = 432,				// 光辉守护
	GENE_TYPE_DEVOUR_SOUL = 433,			// 灵魂吞噬
	GENE_TYPE_REDUCE_SUCK_BLOOD = 434,		// 降低吸血比例

	GENE_TYPE_HORCRUXES_THORNS = 435,	// 魂器 荆棘之魂
	GENE_TYPE_HORCRUXES_SHACKLES = 436, // 魂器 束缚之魂
	GENE_TYPE_HORCRUXES_GIANT = 437,	// 魂器 金刚之魂
	GENE_TYPE_HORCRUXES_GUARD = 438,	// 魂器 守护之魂
	GENE_TYPE_HORCRUXES_AGILE = 439,	// 魂器 敏捷之魂
	GENE_TYPE_HORCRUXES_TENACITY = 440, // 魂器 坚韧之魂

	GENE_TYPE_DIVINE_LIGHT = 441, // 神器套装 护体神光
	GENE_TYPE_FENSHEN_SHU = 442,  // 分身术持续时间

	GENE_TYPE_SHACKLES_REDUCE_ATTACK = 443, // 魂器 束缚之魂触发降低角色攻击

	GENE_TYPE_GREY_NAME = 444,				 // 灰名倒计时
	GENE_TYPE_ONLINE_WASHING_RED_NAME = 445, // 在线洗红名
	GENE_TYPE_DRAGON_POWER = 446,			 // 神龙之力
	GENE_TYPE_MABI_RING_RESIST_CD = 447,	 // 被麻痹特戒麻痹保护CD

	GENE_TYPE_JIOAXIE = 448,	// 缴械
	GENE_TYPE_JIOAXIE_CD = 449, // 缴械CD
	GENE_TYPE_STICK_CD = 450,	// 沉默CD

	GENE_TYPE_ZF_CRIT_ADD = 451,	 // 增幅暴击
	GENE_TYPE_ZF_NOSUCK_BLOOD = 452, // 对方无法吸血

	GENE_TYPE_ZF_NO_BACK = 453,			  // 无法回城
	GENE_TYPE_ZF_INVINCIBLE_COOL = 454,	  // 无敌冷却
	GENE_TYPE_ZF_INVINCIBLE_COMMON = 455, // 无敌持续
	GENE_TYPE_ZF_RECOVERY = 456,		  // 装备回收增益
	GENE_TYPE_ZF_KILL_MONSTER = 457,	  // 击杀怪物额外经验
	GENE_TYPE_ZF_KILL_MONSTER_CRIT = 458, // 击杀怪物暴击
	GENE_TYPE_ZF_REDUCE_DROP = 459,		  // 击杀被爆装率降低
	GENE_TYPE_ZF_NOSUCK_BLOOD_COOL = 460, // 吸血冷却
	GENE_TYPE_ZF_NO_BACK_COOL = 461,	  // 吸血持续

	GENE_TYPE_TUJIAN_CANGHAI = 462,		   // 图鉴沧海一声笑
	GENE_TYPE_TUJIAN_CANGHAI_COMMON = 463, // 图鉴沧海一声笑持续
	GENE_TYPE_TUJIAN_CANGHAI_COOL = 464,   // 图鉴沧海一声笑冷却

	GENE_TYPE_TUJIAN_HUOSHAO = 465,		   // 图鉴三国志火烧连营
	GENE_TYPE_TUJIAN_HUOSHAO_COMMON = 466, // 图鉴三国志火烧连营持续
	GENE_TYPE_TUJIAN_HUOSHAO_COOL = 467,   // 图鉴三国志火烧连营冷却

	//-------------------------------------    通用基因    -------------------------------------
	GENE_TYPE_SCRIPT_GENE = 1000, // 脚本基因类型
	GENE_TYPE_CD_GENE = 1001,	  // CD基因类型
};

// 功能开关
enum SwitchType
{
	SWITCH_SCENE = 1,		  // 副本, 世界地图
	SWITCH_EVENT = 2,		  // 活动
	SWITCH_EQUIP = 3,		  // 装备
	SWITCH_REBORN = 4,		  // 转生等级
	SWITCH_VIP = 5,			  // vip
	SWITCH_RECHARGE = 6,	  // 充值
	SWITCH_PET_SKILL = 7,	  // 宠物技能
	SWITCH_GUILD_GOAL = 8,	  // 行会目标
	SWITCH_GUILD_GCZ = 9,	  // 攻城战
	SWITCH_GUILD_HALO = 10,	  // 行会光环
	SWITCH_GUILD_SHOP = 11,	  // 行会商城
	SWITCH_GUILD_SCENE = 12,  // 行会副本
	SWITCH_COURAGE_SHOP = 13, // 勇气商店
	SWITCH_CROSS_BATTLE = 14, // 跨服战
	SWITCH_TRADE = 15,		  // 交易
	SWITCH_ACTIVE_CODE = 16,  // 激活码
	SWITCH_PET_STALL = 17,	  // 宠物摆摊
	// SWITCH_PAID_DOWNLOAD_GIFT		= 18,		//付费下载礼包(渠道属性中设置)
	SWITCH_MARKET = 19,				 // 寄售行
	SWITCH_CSCG = 20,				 // 财神闯关
	SWITCH_MONTH_CARD = 21,			 // 月卡
	SWITCH_XBYG = 22,				 // 新版预告
	SWITCH_TREASURE = 24,			 // 寻宝
	SWITCH_SAMSARA = 25,			 // 轮回开关
	SWITCH_CUSTOMER_SERVICE = 26,	 // 客服
	SWITCH_YYHD = 27,				 // 运营活动
	SWITCH_KFHD = 28,				 // 开服活动
	SWITCH_GUJI = 29,				 // 挂机
	SWITCH_NEW_POSITION = 30,		 // 开启新部位
	SWITCH_RECOVERY_UNLIMIT = 31,	 // 回收无上限
	SWITCH_OPERATION_THLB = 32,		 // 开服活动特惠礼包
	SWITCH_JYLZ = 33,				 // 经验炼制
	SWITCH_CHAT_SUBMIT = 34,		 // 聊天提交服务器
	SWITCH_APPSTORE_COMMEND = 35,	 // 五星好评
	SWITCH_HYPER_SOUL = 36,			 // 高级魂珠（17级以上魂珠-含）
	SWITCH_FULI = 37,				 // 福利。奖励大厅
	SWITCH_ITEM_PAY_USING = 38,		 // 物品额外付费使用
	SWITCH_OFFICIAL_RECHARGE = 39,	 // 官方充值推广
	SWITCH_CZLC = 40,				 // 超值理财
	SWITCH_WEIXIN = 41,				 // 微信
	SWITCH_KFHD_XFDB = 42,			 // 开服活动，消费夺宝
	SWITCH_KFHD_XFPH = 43,			 // 开服活动，消费排行
	SWITCH_KFHD_DJJJ_Z6Z5 = 44,		 // 开服活动，等级竞技转6送转5武器
	SWITCH_KFHD_THLB_ZHUZAI_Z2 = 45, // 开服活动，特惠礼包主宰送转2武器
	SWITCH_RECHARGE_TOTAL = 46,		 // 开服活动，累计充值
	SWITCH_KFHD_SCCZFL = 47,		 // 开服活动，首充超值福利
	SWITCH_YYHD_YYB = 48,			 // 应用宝专属运营活动
	// SWITCH_NEW_CHAT_RULE			= 49,		//使用新的聊天限制规则
	SWITCH_CONSIGNMENT_FIXED_TAX = 50, // 寄售固定税收
	SWITCH_KILL_PREC_GENE = 51,		   // 杀人惩罚Gene
	SWITCH_CHAT_VOICE = 52,			   // 开启语音聊天
	SWITCH_CHAOXI = 53,				   // 潮汐幻境
	SWITCH_CHAOXI_ALL = 54,
	SWITCH_CHAOXI_OPEN_FOUR = 55, // 潮汐副本5个全开，不然就开3个
	SWITCH_NEW_YEAR = 56,		  // 新年运营活动
	SWITCH_XILIAN_FJ_LIMIT = 57,  // 洗练分解限制
	// SWITCH_ZHUZAI					= 58,       // 主宰
	SWITCH_GTCL = 59,			 // 宫廷长廊
	SWITCH_LUNHUIMIJING = 60,	 // 轮回秘境
	SWITCH_BUY_LHD = 61,		 // 购买轮回丹
	SWITCH_SWLC2 = 62,			 // 守卫龙城2
	SWITCH_DABAO = 63,			 // 打宝开关
	SWITCH_HUOYUE = 64,			 // 活跃度开关
	SWITCH_ENGLISH_ALLOWED = 65, // 是否允许出现英文（如VIP、BOSS）
	SWITCH_REDPACK = 66,		 // 全民红包开关
	SWITCH_MM_SHOP = 67,		 // 商城美女气泡
	SWITCH_MYWS = 68,			 // 玛雅五层的开关
	SWITCH_BOSS3 = 72,			 // boss 3层开启
	SWITCH_ZSSD7 = 73,			 // zzsd 7层
	SWITCH_ZSSD8 = 74,			 // ZZSD 9层
	SWITCH_HJTJ5 = 75,			 // 幻境通缉 5层
	SWITCH_HJTJ6 = 76,			 // 幻境通缉 6层
	SWITCH_BAOSHI10 = 77,
	SWITCH_BAOSHI11 = 78,
	SWITCH_BAOSHI12 = 79,
	SWITCH_HUNZHU10 = 80,
	SWITCH_HUNZHU11 = 81,
	SWITCH_XUEFU9 = 82,
	SWITCH_XUEFU10 = 83,
	SWITCH_HUDUN9 = 84,
	SWITCH_HUDUN10 = 85,
	SWITCH_WING10 = 86,
	SWITCH_WING11 = 87,
	SWITCH_WING12 = 88,
	SWITCH_CHENGHAO15 = 89,
	SWITCH_CHENGHAO20 = 90,
	SWITCH_SZXT = 91, // 神装系统
	SWITCH_SZXL = 92, // 神装洗练
	SWTICH_SWZ = 93,
	SWITCH_ZHUZAI = 94,
	SWITCH_HFHD = 95,	  // 合服活动总开关
	SWITCH_FORGE_CQ = 96, // 传奇套装
	SWITCH_FORGE_SS = 97, // 神圣装备
	SWITCH_RONALDO = 98,  // 变身罗纳尔多
	SWITCH_FIFA = 99,	  // 世界杯
	SWITCH_MIND9 = 100,	  // 龙魄
	SWITCH_MIND10 = 101,  // 龙魄
	SWITCH_TIME_SAY = 102,
	SWITCH_GUILD_JOIN_CD = 103,		// 退出公会CD
	SWITCH_FULING = 104,			// 附灵
	SWITCH_NEARBY_PLAYER = 105,		// 附近玩家
	SWITCH_OPPO_REWARD = 106,		// oppo专属活动
	SWITCH_KF_FORBID_CREATE = 107,	// 开服3天内禁止创角 （作废）
	SWITCH_CASHGIFT_QUICKTAG = 108, // 现金直购快捷按钮
	SWITHC_SHENHUN = 109,			// 神魂系统

	SWITCH_KFSY = 110,				  // 跨服深渊  (废弃)
	SWITCH_CHANGE_STONE = 111,		  // 改造石
	SWITHC_ZYHS = 112,				  // 资源回收
	SWITCH_MIND11 = 113,			  // 血符
	SWITCH_MIND12 = 114,			  // 护盾
	SWITCH_CHANGE_HERO_CLASS = 115,	  // 英雄转职
	SWITCH_LYD_AND_SQ = 116,		  // 凌云殿和神器
	SWITCH_MOSHI = 117,				  // 魔饰
	SWITCH_SPECIAL_DROP_EQUIO = 118,  // 扶持号丢弃物品直接销毁
	SWITCH_KFHD_YBZP = 119,			  // 开服活动-元宝转盘
	SWITCH_TRANSACTION = 120,		  // 托交易开关
	SWITCH_HFHD_CZYL = 121,			  // 合服活动-充值有礼
	SWITCH_HFHD_YBZP = 122,			  // 合服活动-元宝转盘
	SWITCH_XILIAN = 123,			  // 洗练
	SWITCH_SEPEQUIP = 124,			  // 分身
	SWITCH_JJKH = 125,				  // 竞技狂欢
	SWITCH_LOGBUS = 126,			  // 数数科技
	SWITCH_YICHU_UPGRADE = 127,		  // 衣橱升级
	SWITCH_RMB_DIAMOND_WELCOME = 128, // 欢迎界面显示钻石还是rmb 开-rmb  关-钻石

	SWITCH_BIND_PHONE = 129,	// 聊天绑定手机开关
	SWITCH_TUOGUAN = 130,		// 托管开关
	SWITCH_JIGUANG = 131,		// 极光推送开关
	SWITCH_CLOSE_PUSHALL = 132, // 是否关闭极光全局推送，默认关闭
	SWITCH_FABAO = 133,			// 法宝
	SWITCH_FULIDATING = 134,	// 福利大厅（激活码兑换）
	SWITCH_GUANFANGDAYI = 135,	// 官方答疑
	SWITCH_FULI_GUILD = 136,	// 福利大厅（一键加群）
	SWITCH_DAILY_GIFT = 137,	// 每日礼包
	SWITCH_FULI_WECHAT = 138,	// 微信福利
	SWITCH_ROBOT = 139,			// 机器人
	SWITCH_GHLC = 140,			// 工会理财

	SWITCH_SHOUHU = 141,   // 守护
	SWITCH_SHENSHI = 142,  // 神石(宝玉)
	SWITCH_TUJIAN = 143,   // 图鉴
	SWITCH_ZERD = 144,	   // 罪恶熔洞
	SWITCH_WENZHANG = 145, // 纹章
	SWITCH_SJSJ = 146,	   // 神剑神甲
	SWITCH_ZHUANZHI = 147, // 转职
	SWITCH_ZBDZ = 148,	   // 装备锻造
	SWITCH_SSHC = 149,	   // 神饰合成
	SWITCH_MWCH = 150,	   // 魔纹合成
	SWITCH_TRADECARD = 151,// 交易卡特权限制
	SWITCH_KF3V3 = 152,    // 跨服3v3

	// 开关请加在上面
	SWITCH_END, // switch end
};

enum OpResult
{
	OP_LOST_THING = 1, // 失去
	OP_GET_THING = 2,  // 获得
};

enum GiftType
{
	GIFT_TYPE_AUTH_GIFT = 1,
	GIFT_TYPE_ITEM_NAME = 2,
	GIFT_TYPE_LOGIN_GIFT = 3,
	GIFT_TYPE_ARENA_GIFT = 4,
	GIFT_TYPE_RECHARGE_ONCE = 5,
	GIFT_TYPE_RECHARGE_500 = 6,
	GIFT_TYPE_RECHARGE_500_NEW = 7,
	GIFT_TYPE_USE_GOLD_300 = 8,
	GIFT_TYPE_NS_LEVEL = 10,
	GIFT_TYPE_NS_PET = 11,
	GIFT_TYPE_NS_STONE = 12,
	GIFT_TYPE_NS_ACT_ALL = 13,
	GIFT_TYPE_NS_ACT_BEST = 14,
};

enum SamsaraContants
{
	SAMSARA_ROUND_MAX = 6, // 最大轮回道数
	SAMSARA_FLOOR_MAX = 6, // 最大轮回层数
};

enum ChannelProp
{
	CHANNEL_PROP_PAID_GIFT = 1,				 // 付费下载礼包
	CHANNEL_PROP_BIG_PAID_GIFT = 2,			 // 付费下载大礼包
	CHANNEL_PROP_RECHARGE_DISABLED = 3,		 // 禁止充值
	CHANNEL_PROP_CREATE_PLAYER_DISABLED = 4, // 禁止创建角色
	CHANNEL_PROP_TREASURE_DAILY_LIMIT = 5,	 // 每日寻宝上限
	CHANNEL_PROP_APPSTORE_COMMEND = 6,		 // 五星好评
	CHANNEL_PROP_OFFICIAL_RECHARGE = 7,		 // 官方充值推广
	CHANNEL_PROP_OFFICIAL_RECHARGE_YB = 8,	 // 官方充值推广元宝数
	CHANNEL_PROP_CXHJ_SHOP_DAILY_LIMIT = 9,	 // 潮汐幻境道具每天限制购买
	CHANNEL_PROP_GENE_KILL = 10,			 // 惩戒gene
	CHANNEL_PROP_THIRD_PARTY_RECHARGE = 11,	 // 第三方支付
	CHANNEL_PROP_IOS_MSG = 12,
	CHANNEL_PROP_SWITCH_RONALDO = 13,		 // 罗纳尔多渠道开关
	CHANNEL_PROP_RONALDO_WELCOME = 14,		 // 罗纳尔多欢迎开关
	CHANNEL_PROP_GUILD_JOIN_TIME_LIMIT = 15, // 再次加入帮会CD时间
	CHANNEL_PROP_VIP_SERVICE = 16,			 // vip客服
	CHANNEL_PROP_VIP_EXCLUSIVE_SERVICE = 17, // vip客服专属服
	CHANNEL_PROP_FULI_WECHAT = 18,			 // 福利大厅，微信公众号
};

enum OperationCode
{
	// general 0 - 199

	OP_INIT = 0, // 角色初始化

	OP_UNKNOWN = 1,			// 未知
	OP_TEST = 5,			// 测试
	OP_CLIENT_GM = 6,		// 客户端GM命令
	OP_AUTH_GM = 7,			// 验证服务器GM命令
	OP_RECHARGE_RETURN = 8, // 充值返还
	OP_QUEST = 100,			// 任务
	OP_LOOT = 101,			// 掉落
	OP_CMQUEST = 102,		// 除魔任务
	OP_ACTIVITY = 103,		// 活动
					   // OP_GUILD									= 104,	//公会
	OP_KILL_MONSTER = 105, // 杀怪
	OP_TRADE = 106,		   // 交易
	OP_ITEM = 107,		   // 物品
	OP_GIFT = 108,		   // 礼包
	OP_RECHARGE = 109,	   // 充值
	OP_MARKET_SELL = 110,  // 摆摊
	OP_MINE = 111,		   // 挖矿
				   // OP_ARENA									= 112,	//竞技场
	OP_MAIL = 113,		  // 邮件
	OP_BUY_AND_USE = 114, // 购买并使用
						  // OP_OPEN_GIFY								= 115,
	OP_GET_OFFLINE_EXP = 116,	   // 领取离线经验
	OP_BUY_DISCOUNT_PACKAGE = 117, // 购买折扣礼包
	OP_SWY = 118,				   // 六道轮回道具获取
	OP_BUY_BOSS_SC = 119,		   // 购买boss积分
	OP_LEVEL_BSSC = 120,		   // 降级boss积分
	OP_BSSC = 121,				   // 正常消耗boss积分
	OP_CONSIGNMENT = 122,		   // 寄售
	OP_CONSIGNMENT_FEE = 123,	   // 寄售税
	OP_HOLLOW_ITEM = 125,		   // 虚空背包里的物品通过邮件发放
	OP_PURCHASE = 126,			   // 求购

	OP_PAPER_SCENEEXP = 127,	   // 符文秘境通关经验获取
	OP_CASH_HOLIDAY = 128,		   // 现金直购运营活动
	OP_SIGN = 129,				   // 签到
	OP_BUY_LEVEL = 132,			   // 购买等级
	OP_WING = 133,				   // 翅膀
	OP_HOLIDAY_REWARD = 134,	   // 运营活动奖励
	OP_HOLIDAY_CONSUME = 135,	   // 运营活动消耗
	OP_XILIAN = 136,			   // 洗练
	OP_OPEN_YEAR_RED = 137,		   // 开新年红包
	OP_ENHANCE_POS = 138,		   // 强化部位
	OP_GHOST_STONE = 139,		   // 魂石
	OP_SPECIAL_RING = 140,		   // 特戒
	OP_CHUANSHI = 141,			   // 传世
	OP_STRENTHEN_EQUIP = 142,	   // 强化装备
	OP_GHOST_STONE_HERO = 143,	   // 魂石[hero]
	OP_STRENTHEN_EQUIP_HERO = 144, // 强化装备[hero]
	OP_ACTIVITY_EXTRA_EXP = 145,   // 活动有额外经验加成
	OP_STRENTHEN_MOSHI = 146,	   // 强化魔饰
	OP_OPTIONAL_GIFT = 147,		   // 自选礼包
	OP_HOLIDAY_ZHANLING = 148,	   // 战令
	OP_HOLIDAY_WANTED = 149,	   // 悬赏
	OP_ENTER_SCENE = 150,		   // mds 进入地图

	//
	// EntityOpcode 200 - 399
	//
	OP_BUY_BAG = 201,		   // 解锁背包格子
	OP_FEED_PET = 202,		   // 喂养宠物
	OP_REVIVE = 203,		   // 复活
	OP_SC_DONATE = 204,		   // 沙城捐献
	OP_PLAYER_LEVEL_EXP = 205, // 获得经验
							   // OP_PET_DEAD									= 206,	//宠物死亡
	OP_MONSTER_DEAD = 207, // 怪物死亡
						   // OP_OFFLINE_MONEY							= 208,
						   // OP_OFFLINE_ITEM  							= 209,
	OP_PROP_UPDATE = 210, // 属性更新
						  // OP_COIN_UPDATE								= 211,	//金币更新
						  // OP_INGOT_UPDATE								= 212,	//元宝更新
						  // OP_COUPON_UPDATE							= 213,		//礼券更新
						  // OP_HONOR_UPDATE								= 214,	//喂养宠物
						  // OP_UPGRADE_HONOR_LEVEL						= 220,	//荣誉升级
						  // OP_OPEN_HONOR_LEVEL							= 221,	//开启荣誉
	OP_EXCHANGE_SOUL = 220,		 // 兑换魂力值
	OP_ADD_SKILL = 230,			 // 增加技能
	OP_SKILL_LEVEL_UP = 231,	 // 技能升级
	OP_SKILL_AWAKE = 232,		 // 技能觉醒
	OP_EQUIP_PUT_ON_OFF = 250,	 // 穿脱装备
	OP_EQUIP_CHANGED = 251,		 // 装备更换
	OP_OFFLINE = 252,			 // 离线奖励
	OP_EQUIP_PUT_MEDAL = 253,	 // 卸下成就勋章
	OP_EQUIP_PUT_MEDAL_ON = 254, // 穿戴成就勋章
	OP_SKILL_CHNAGE_JOB = 255,	 // 换职
							   // OP_IMPRISON_PET								= 260,	//封印宠物
							   // OP_DOG_ATTACK								= 261,		//狗攻击
							   // OP_DOG_DEFENSE								= 262,	//狗防御
	OP_PLAYER_LEVEL_UP = 262,		  // 玩家升级
	OP_DOG_UPGRADE = 263,			  // 升级狗
	OP_FLYING_SCENE = 270,			  // 飞鞋
	OP_HERO_LEVEL_EXP = 271,		  // 英雄经验
	OP_REBORN = 280,				  // 转生
	OP_EXCHANGE_REBORN_POINTS = 281,  // 兑换转生修为
	OP_SAMSARA = 282,				  // 轮回
	OP_EXCHANGE_SAMSARA_POINTS = 283, // 兑换轮回修为
	OP_REBORN_POINTS = 284,			  // 人物等级兑换转生修为
	OP_EXERCISE = 290,				  // 内功
	OP_CLEAN_CD_BEGIN = 301,		  // 清除CD时间
	OP_CLEAN_CD_END = 399,

	//
	// ItemOpcode 400 - 599
	//
	// OP_ITEM_UPDATE								= 401,			//物品更新
	OP_ITEM_MERGE = 402,		   // 物品合成	merge stones into big stones
	OP_ITEM_FORGE = 403,		   // 物品锻造	forge equipment with materials
	OP_ITEM_SPLIT = 404,		   // 物品拆分
	OP_ITEM_UPGRADE = 405,		   // 物品升级	upgrade item into higher level
	OP_ITEM_REBORN = 406,		   // 物品转生
	OP_ITEM_ENHANCE = 407,		   // 物品强化
	OP_ITEM_EVALUATE = 408,		   // 物品鉴定
	OP_ITEM_CLEAR_ITEM = 409,	   // 物品清洗
	OP_ITEM_STONE_TRANS = 410,	   // 魂石转换
	OP_ITEM_CHANGE_ATTR = 412,	   // 物品属性转移
	OP_ITEM_AUTO_MERGE = 413,	   // 购买次数并强化
	OP_JEWEL_UPGRADE = 414,		   // 宝石升级
	OP_ITEM_POLISH = 415,		   // 物品打磨
	OP_ITEM_PERFECT_ENHANCE = 416, // 物品完美强化
	OP_ITEM_SET_POSITION = 417,
	OP_ITEM_CREATE = 418,
	OP_ITEM_DELETE = 419,				  // 删除物品
	OP_ITEM_UNLOCK_SLOT = 420,			  // 解锁背包格子
	OP_ITEM_CHANGE_ENHANCE = 421,		  // 转移强化属性
	OP_ITEM_CHANGE_EVALUATE = 422,		  // 转移鉴定属性
	OP_ITEM_CLEAR_SPECIAL_ATTR = 423,	  // 清洗极品属性
	OP_ITEM_DESTROY = 424,				  // 销毁物品
	OP_TAKE_OUT_TREASURE_ITEM = 425,	  // 取出寻宝仓库的物品
	OP_TAKE_OUT_LUCKY_COMPASS_ITEM = 426, // 取出神运罗盘仓库的物品
	OP_ITEM_BAG_MOVE_STORE = 427,		  // 背包移动物品到仓库
	OP_ITEM_STORE_MOVE_BAG = 428,		  // 仓库移动物品到背包
	OP_ITEM_DROP_FROM_BAG = 429,		  // 从背包中丢弃物品
	OP_ITEM_DIEJIA = 430,				  // 叠加物品
	OP_ITEM_USE_EXP_JADE = 460,			  // 使用经验玉
	OP_ITEM_RECHARGE_COUPON = 461,		  // 使用充值抵用券
	OP_ITEM_UNUSE = 466,				  // 该抵用券无法使用
	OP_ITEM_PILE = 467,					  // 物品整理
	OP_ITEM_TO_POINTS = 468,			  // 兑换积分
	OP_ITEM_ADD_ENHANCE_COUNT = 469,	  // 增加强化次数
	OP_USE_HOLIDAY_ITEM = 470,			  // 使用节日活动材料
	OP_SELL_ITEM = 500,					  // 出售物品给系统
	OP_BUY_ITEM = 501,					  // 购买物品
	OP_USE_ITEM = 502,					  // 使用物品
	OP_USE_STONE = 503,					  // 使用宝石
	OP_ABANDON_ITEM = 504,				  // 丢弃物品(old)
	OP_BUY_BACK_ITEM = 505,				  // 回购物品
	OP_DROP_ITEM = 506,					  // 掉落物品
	OP_SHOP_BUY_ITEM_INGOT = 507,		  // 商城元宝购买
	OP_SHOP_BUY_ITEM_COUPON = 508,		  // 商城礼券购买
	OP_SHOP_BUY_ITEM_POINTS = 509,		  // 商城积分购买
	OP_SHOP_BUY_ITEM_FANTIAN = 510,		  // 商城梵天积分购买
	OP_BUY_IN_PORTABLE_SHOP = 511,		  // 随身商店
	OP_SELL_ITEM_TO_SYSTEM = 512,		  // 出售物品
	OP_REFOEGE_ITEM = 513,				  // 重铸饰品
	OP_EQUIP_FULING = 514,				  // 装备附灵
	OP_EQUIP_FULINGZY = 515,			  // 附灵转移
	OP_EQUIP_CHANGE = 516,				  // 装备改造
	OP_ABANDON_ITEM_NEW = 517,			  // 丢弃物品
	OP_UPGRADE_SOUL = 520,				  // 升级魂器

	//
	// QuestOpcode 600 - 699
	//
	OP_QUEST_ACCEPT = 601, // 接受任务
	OP_QUEST_UPDATE = 602, // 更新任务
	OP_QUEST_FINISH = 603, // 完成任务
	OP_QUEST_REMOVE = 604, // 移除任务
	OP_QUEST_SUBMIT = 605, // 提交任务
						   // OP_QUEST_ENABLE								= 606,	//
	OP_QUEST_INIT = 607,  // 初始任务
	OP_QUEST_QUICK = 608, // 快速任务
	OP_QUEST_JY = 609,	  // 精英任务

	// 拆分
	OP_FORGE_SPLIT = 610, // 拆分

	//
	// WeiMingOpcode 700 - 719
	//
	OP_WW_QUEST = 700,		 // 威望任务
	OP_JQBG_EVENT = 701,	 // 激情闭关活动
	OP_YZBQ_EVENT = 702,	 // 夜战比奇活动
	OP_LCZB_EVENT = 703,	 // 龙城争霸活动
	OP_LYTQ = 704,			 // 蓝月特权
	OP_OFFLINE_CUTOFF = 705, // 离线
	OP_DAILY_RECOVERY = 706, // 每日回收

	// 宝物Opcode 720 - 730
	OP_SHENLU = 720,		// 神炉
	OP_SHENLU_RED = 721,	// 神炉 - 血玉
	OP_SHENLU_SHIELD = 722, // 神炉 - 护盾
	OP_SHENLU_GEM = 723,	// 神炉 - 宝石
	OP_SHENLU_SOUL = 724,	// 神炉 - 魂珠

	// 特权Opcode 731-734
	OP_PRIVILEGE_GZ = 731,	// 贵族特权
	OP_PRIVILEGE_WZ = 732,	// 王者特权
	OP_PRIVILEGE_ZZ = 733,	// 至尊特权
	OP_PRIVILEGE_ALL = 734, // 特权【全部开启】

	// 圣兽Opcode 740 - 744
	OP_THERION = 740,	 // 圣兽
	OP_THERION_TT = 741, // 圣兽 - 饕餮
	OP_THERION_QQ = 742, // 圣兽 - 穷奇
	OP_THERION_TW = 743, // 圣兽 - 梼杌
	OP_THERION_HD = 744, // 圣兽 - 混沌

	OP_SHENLONGHUTI = 750,	   // 神龙护体
	OP_SHENJIAN_SHENJIA = 751, // 神剑神甲
	OP_LIANTI = 752,		   // 炼体
					 //
					 // ActivityOpcode 800 - 999
					 //
	OP_ACTIVITY_BEGIN = 800, // 活动操作码开始
	OP_REFRESH_MOBAI = 801,	 // 刷新膜拜
	OP_REFRESH_MEINV = 802,	 // 刷新美女
	OP_TTSY_GUWU = 803,		 // 世界boss 鼓舞
						// OP_ACTIVITY_STATE_CHANGE					= 803,
	OP_FIRE = 810,	// 圣火争霸
	OP_MOBAI = 811, // 城主膜拜
					// OP_CAI_SHEN_CHAUNG_GUAN						= 812,	//财神闯关
	OP_ARENA_TREASURE_HUNT = 813,	   // 寻宝
	OP_ARENA_PROTECT_GIRL = 814,	   // 美女护送
	OP_ARENA_LUCKY_COMPASS = 815,	   // 神运罗盘
	OP_ARENA_LUCKY_COMPASS_SHOP = 816, // 神运罗盘
	OP_ARENA_DRAGON_POWER = 818,	   // 龙神之力
	OP_ARENA_MONEYTREE = 819,		   // 摇钱树
							  // OP_ARENA_REFRESH_BUFF						= 815,
	OP_LIE_HUO_DONG_BUY_LING = 850, // 领取水晶令
	OP_LIE_HUO_DONG_GONEX = 851,	// 经验水晶宫领取
	OP_CHDD_SEED = 860,				// 购买种子
	OP_CHDD_BOMB = 861,				// 购买催泪弹
	OP_MLSD = 862,					// 魔龙神殿
	OP_DYJJ = 863,					// 地狱结界
	OP_SLHD = 864,					// 水域龙都
	OP_WYZC = 865,					// 武易战场
	OP_ZSZB = 866,					// 称霸天下
	OP_XMFB_CALL = 870,				// 降魔副本召唤
	OP_XMFB_BUY = 871,				// 降魔副本购买
	OP_SPIDER_THROW_ITEM = 880,		// 诛魔结阵放入物品
	OP_XYZP_CALL = 881,				// 幸运转盘
	OP_YK_BUY = 882,				// 月卡购买
	OP_BOSSHOME_BUY = 883,			// boss之家购买
	OP_FULI_TOUZI = 884,			// 购买福利投资
	OP_DBQB = 885,					// 夺宝奇兵
	OP_CZLC = 886,					// 超值理财
	OP_HYSD = 887,					// 幻影神殿
	OP_CROSS_REWARDS = 889,			// 跨服远征奖励
	OP_JQBG = 890,					// 激情闭关
	OP_YZBQ = 891,					// 夜战比奇

	//
	// HeroOpcode 900 - 1000
	//
	OP_REBORN_HERO = 900,			  // 英雄转生
	OP_REBORN_HERO_POINTS = 901,	  // 英雄转生修为
	OP_REBORN_HERO_MIPRAC = 905,	  // 英雄灵魂刻印
	OP_REBORN_HERO_MERIDIAN = 906,	  // 英雄经脉
	OP_REBORN_HERO_LEVELUP = 907,	  // dzy-宝宝升级
	OP_EQUIP_INCREASE = 908,		  // 装备增幅
	OP_EQUIP_INCREASE_INCREASE = 909, // 装备增幅增幅
	OP_EQUIP_INCREASE_INHERIT = 910,  // 装备增幅传承
	OP_EQUIP_PROTECT = 911,			  // 装备担保
	OP_MQ_CUI_LIAN = 912,			  // 魔器淬炼
	OP_EQUIP_UP_STAR = 913,			  // 装备升星

	// 跨服类型 1000 - 1999
	// OP_KFBEGIN									= 1000,		//跨服类型开始
	OP_KFYZ = 1000,		  // 跨服远征
	OP_KFSY = 1001,		  // 跨服深渊（跨服乱斗）
	OP_CROSS_PROP = 1002, // 跨服属性改变
	OP_YZBQ_KF = 1003,	  // 跨服夜战比奇
	OP_KFEND = 1999,	  // 跨服类型结束

	//
	// GuildOpcode 2000 - 2999
	//
	OP_GUILD_NOENT = 2000,	// 行会不存在
	OP_GUILD_CREATE = 2001, // 公会创建
	OP_GUILD_REWARD = 2002, // 公会捐献奖励
	OP_GUILD_DONATE = 2003, // 公会捐献
							// OP_GUILD_PRAY								= 2004,	//拜关公
	OP_GUILD_MAINTAIN = 2005, // 公会维持
							  // OP_GUILD_UPDATE_BUILDING					= 2006,
	OP_GUILD_GCZ = 2007, // 攻城战
						 // OP_GUILD_OPEN_BUFF							= 2008,
	OP_GUILD_WORSHIP_MEMBER = 2009,		 // 膜拜行会成员
	OP_GUILD_BE_WORSHIPED_REWARD = 2010, // 被膜拜奖励
	OP_GUILD_CLEAR_UPGRADE_CD = 2011,	 // 清除行会升级CD
	OP_GUILD_GET_RED = 2012,			 // 获取行会红包
	OP_GUILD_SEND_RED = 2013,			 // 发放行会红包
	OP_GUILD_DONATE_COIN = 2014,		 // 捐赠金币
	OP_GUILD_ENTER = 2015,				 // 加入行会
	OP_GUILD_LEAVE = 2016,				 // 退出行会
	OP_GUILD_UPGRADE = 2017,			 // 行会升级
	OP_GUILD_DISMISS = 2018,			 // 行会解散
	OP_GUILD_KICKOUT = 2019,			 // 行会踢人
	OP_GUILD_MASTER_CHANGE = 2020,		 // 行会会长变更
	OP_GUILD_DONATE_INGOT = 2024,		 // 捐赠元宝
	OP_GUILD_UPGRADE_INGOT = 2025,		 // 行会元宝升级
	OP_GUILD_SHOP_BUY = 2026,			 // 行会商城购买
	OP_GUILD_STUDY_SKILL = 2027,		 // 公会学习技能
	OP_GUILD_CANTEEN_AWARD = 2028,		 // 公会食堂奖励
	OP_GUILD_RESET_SKILL = 2029,		 // 公会重置技能
	OP_GUILD_MERGE = 2030,				 // 公会合并
	OP_GUILD_DECLEAR_WAR = 2031,		 // 工会宣战


	//
	// ZhanDui opcode 2501 - 2999
	//

	OP_ZHANDUI_CREATE = 2501,			// 创建战队
	OP_ZHANDUI_JOIN = 2502,				// 加入战队
	OP_ZHANDUI_QUIT = 2503,				// 退出战队
	OP_ZHANDUI_DISBAND = 2504,			// 解散战队
	OP_ZHANDUI_KICKOUT = 2505,			// 战队踢人
	OP_ZHANDUI_SET_LEADER = 2506,		// 战队队长变更



								 //
								 //  GiftOpcode  3000 - 3999
								 //
	OP_BUY_LIMIT_TIME_GIFT = 3001, // 购买限时礼包
	OP_BUY_DAILY_GIFT = 3002,	   // 每日直购
	OP_BUY_RECHARGE_GIFT = 3003,   // 首充奖励

	//
	// PetOpcode 4000 - 4999
	//
	OP_PET_PICK_UP = 4000, // 宠物拾取
	OP_MARS_SUMMON = 4001, // 召唤战神
	OP_MARS_BACK = 4002,   // 返还召唤元宝

	//
	// TeamOpcode 5000 - 5999
	//
	// team_add_member = 5000,
	// team_del_member = 5001,
	// team_exit = 5002,
	// team_set_leader = 5003,
	OP_DEAD_RELIVE_MONEY = 5127, // 消耗灵符原地复活

	//
	// ScriptOpcode 10000 - 19999
	//
	OP_BUY_ROSE = 10000, // 购买玫瑰
	OP_TELEPORT = 10001, // 传送石传送
						 // OP_EVENT_YSJDC								= 10002,	//勇士竞技场
						 // OP_EVENT_HHZDZ								= 10003,	//行会争夺战
	OP_SRPING_BROTHER = 10005,		// 信春哥
	OP_INSTANCE = 10007,			// 副本 、 个人boss
	OP_QIFUXIANZI_SCENE = 10008,	// 祈福仙子场景
	OP_QIFUXIANZI_GUILD = 10009,	// 祈福仙子公会
	OP_BUNDLING_ITEM = 10010,		// 打捆物品
	OP_EXCHANGE_JYSF = 10011,		// 兑换经验神符
	OP_MOBAI_XUAN_SHANG = 10012,	// 膜拜悬赏
	OP_MOBAI_CZ_REWARD = 10013,		// 膜拜的城主奖励
	OP_MHXG_LAYER_REWARD = 10014,	// 魔幻星宫每层奖励
	OP_FCDJF = 10015,				// 发财大家发奖励
	OP_GUILD_MNHS = 10017,			// 行会美女护送
	OP_MAIL_GIFT = 10018,			// 离线礼包获取
	OP_ARENA_FIGHT = 10019,			// 战力竞技奖励
	OP_SCRIPT_GUILD_REWARD = 10020, // 行会奖励
	OP_ARENA_REWARD = 10021,		// 竞技场奖励
	OP_WEEK_FLEE = 10022,
	OP_RECHARGE_ONCE = 10023,	   // 首次充值
	OP_NS_FIGHT_LEVEL = 10100,	   // 新服等级竞技
	OP_NS_FIGHT_PET = 10101,	   // 新服宠物竞技
	OP_NS_FIGHT_STONE = 10102,	   // 新服魂石竞技
	OP_NS_LOGIN = 10103,		   // 新服登录奖励
	OP_CLEAR_RED_NAME = 10104,	   // 清除红名
	OP_LYT_MONSTER_EXP = 10106,	   // 龙影谭怪物经验
	OP_LOOT_ITEM_BIND = 10108,	   // 发财礼包
	OP_LINGSHI_SPLIT = 10110,	   // 灵石分解
	OP_BUY_GOLD_BOWL = 10120,	   // 聚宝盆(失效)
	OP_USE_LUCKY_CIRCLE = 10121,   // 幸运转盘奖励
	OP_TREASURE_HUNT_FREE = 10130, // 免费寻宝
	OP_SUMMER = 10140,
	OP_TAOWEAPON = 10141,
	OP_XYCM = 10142,				   // 降妖除魔
	OP_SIGNIN_REWARD = 10143,		   // 在线周累计元宝奖励
	OP_KFHD_QMBS = 10144,			   // 开服活动，全民BOSS
	OP_KFHD_JSCJ = 10145,			   // 开服活动，角色冲级
	OP_KFHD_BSCJ = 10146,			   // 开服活动，宝石冲级
	OP_KFHD_CBCJ = 10147,			   // 开服活动，翅膀冲级
	OP_KFHD_HZCJ = 10148,			   // 开服活动，魂珠冲级
	OP_KFHD_7DAY = 10149,			   // 开服活动，7日奖励
	OP_APPSTORE_COMMENT = 10150,	   // APPSTORE五星好评奖励
	OP_TREASURE_HUNT_EXCHANGE = 10151, // 寻宝积分兑换
	OP_GUILD_PUT_ITEM = 10152,		   // 公会放置道具
	OP_GUILD_GET_ITEM = 10153,		   // 公会取道具
	OP_GUILD_DEL_ITEM = 10154,		   // 公会删除道具
	OP_ONLINE_EVERY_DAY = 10155,	   // 每日在线
	OP_KFHD_XFDB = 10156,			   // 开服活动，消费夺宝
	OP_KFHD_SCCZFL = 10157,			   // 开服活动，首充超值福利
	OP_CXHJ = 10158,				   // 潮汐幻境
	OP_KILL_GENE = 10159,			   // 杀人GENE，降低经验
	OP_CHAT_HORN = 10160,			   // 聊天传音
	OP_DABAO_TASK = 10161,			   // 打宝任务
	OP_DABAO_SHOP = 10162,			   // 打宝商店
	OP_YYBX = 10163,				   // 一元宝箱
	OP_KFHD_JGLY = 10164,			   // 开服活动，建功立业
	OP_GUIDE_LEVEL_REWARD = 10165,	   // 等级引导
	OP_ZIYUANZHAOHUI = 10166,		   // 资源找回
	OP_REDPACK = 10167,				   // 全民红包
	OP_AUTO_EQUIP = 10168,			   // 自动穿戴
	OP_CAPTAIN = 10169,				   // 官印
	OP_GUILD_BOSS = 10170,			   // 公会爬塔活动
	OP_HOLIDAY_CASH = 10171,		   // 现金红包

	OP_ACTIVE_PAPER = 10180,   // 激活符文极品属性
	OP_EXCHANGE_PAPER = 10181, // 交换符文极品属性
	OP_RECYCLE_PAPER = 10182,  // 回收符文道具

	OP_VITAL_QI = 10183,	 // 英雄真气兑换
	OP_PRIVATE_DART = 10175, // 个人押镖
	OP_PRAY = 10184,		 // 祈福
	OP_GUILD_GATHER = 10185, // 公会采集
	OP_GUILDQIFU = 10186,	 // 公会祈福
	OP_IMPEACH = 10187,		 // 弹劾会长

	OP_HFHD_SBJY = 10188,				  // 合服活动，双倍经验
	OP_HFHD_YBPD = 10189,				  // 合服活动，元宝派对
	OP_HFHD_HCZB = 10190,				  // 合服活动，皇城争霸
	OP_HFHD_SMSD = 10191,				  // 合服活动，神秘商店
	OP_HFHD_XSQG = 10192,				  // 合服活动，限时抢购
	OP_HFHD_CZYL = 10193,				  // 合服活动，充值有理
	OP_HFHD_FKXB = 10194,				  // 合服活动，疯狂寻宝
	OP_HFHD_CBPD = 10195,				  // 合服活动，翅膀派对
	OP_HFHD_BSPD = 10196,				  // 合服活动，宝石派对
	OP_HFHD_HZPD = 10197,				  // 合服活动，魂珠派对
	OP_BAIL = 10198,					  // 红名保释
	OP_KFHD_HERO = 10199,				  // 英雄竞技
	OP_KFHD_SOUL = 10200,				  // 龙魂竞技
	OP_KFHD_OFFICE = 10201,				  // 官职竞技
	OP_KFHD_STONE = 10202,				  // 魂石竞技
	OP_KFHD_VEIN = 10203,				  // 经脉竞技
	OP_FIFA = 10204,					  // 世界杯足球赛
	OP_HOLIDAY_CLOUD = 10205,			  // 云购抽奖
	OP_HOLIDAY_JBP = 10206,				  // 聚宝盆 运营活动
	OP_HOLIDAY_BUYDRAW = 10207,			  // 抢购抽奖
	OP_HOLIDAY_REBATE = 10208,			  // 折扣商城
	OP_HOLIDAY_SDSLC = 10210,			  // 圣诞狩猎场
	OP_SHENQI = 10211,					  // 神器操作
	OP_RECORD_BOSS_CORE = 10212,		  // 回收道具boss积分
	OP_EVERYDAY_RECORD_BOSS_CORE = 10213, // 0点系统固定回收
	OP_OPEN_SEC_WAREHOUSE = 10214,		  // 开启第二仓库
	OP_LEASE = 10215,					  // 神兵租赁
	OP_GODWEAPON_UP = 10216,			  // 神器升级
	OP_SKILL_RUNE_PUTOFF = 10217,		  // 技能符文卸下
	OP_RANK_STATIC_AWARD = 10218,		  // 竞技排行榜固定奖励
	OP_RECOVER = 10219,					  // 钻石回收
	OP_SIGN_EXTRA = 10220,				  // 钻石补签
	OP_SIGN_REWARD = 10221,				  // 签到奖励
	OP_TRAINING_ROOM_REWARD = 10222,	  // 练功房奖励
	OP_TGMJ_TOWER_REWARD = 10223,		  // pve爬塔（练功房 天关秘境）
	OP_FIRST_GET = 10224,				  // 首爆奖励
	OP_FIRST_RECOVERY = 10225,			  // 首次回收
	OP_BUY_ACUTION = 10230,				  // 拍卖行购买
	OP_BUY_SPECIALRING_GIFT = 10231,	  // 购买特戒礼包
	OP_EXCHANGE_INGOT = 10232,			  // 购买元宝
	OP_BIY_BAOBAO_SKILL_GIFT = 10233,	  // 购买宝宝技能礼包
	OP_JBP = 10234,						  // 聚宝盆获取
	OP_BIGBANGITEM = 10235,				  // 大爆
	OP_ZBG_DONATE = 10236,				  // 珍宝阁使用钻石刷新
	OP_ZBG_BUYITEM = 10237,				  // 珍宝阁购买道具
	OP_SHAOZHU = 10238,					  // 石墓烧猪奖励
	OP_MEMBER_REWARD = 10239,			  // 会员奖励
	OP_ZHIZUN_REWARD = 10240,			  // 至尊奖励
	OP_UP_MINER = 10241,				  // 升阶矿工
	OP_WANTED_BOSS = 10242,				  // BOSS通缉
	OP_TREASURE_MAP = 10243,			  // 藏宝图
	OP_INVERSERT = 10244,				  // 投资
	OP_GUANJIE = 10245,					  // 官阶
	OP_GODWEAPON_GIFT = 10246,			  // 神器礼包
	OP_VIP_TASK = 10247,				  // VIP尊享任务
	OP_REVIVE_COST = 10248,				  // 复活花费
	OP_REFRESH_SMELT = 10249,			  // 洗练刷新
	OP_LUCKY_FULL_LEVEL = 10250,		  // 幸运直升满级花费
	OP_CSZT_ADD_COUNT = 10251,			  // 传说之塔购买挑战次数
	OP_USE_EXP_ITEM = 10252,			  // 使用经验丹升级
	OP_SHAOZHU_EXP = 10253,				  // 石墓烧猪经验增加
	OP_KBZL_KILL_DIAMOND = 10254,		  // 击杀拥有狂暴之力的玩家给的奖励钻石
	OP_BUY_KBZL = 10255,				  // 购买狂暴之力
	OP_LUCKY_POWER = 10256,				  // 狂暴之力
	OP_FEISHENG = 10257,				  // 飞升（转生）
	OP_LCLB_REWARD = 10258,				  // 累充礼包奖励
	OP_CAREER_QUEST = 10259,			  // 打金之路
	OP_MONTH_CARD = 10260,				  // 月卡
	OP_WEEK_CARD = 10261,				  // 周卡
	OP_RUNE_PUT_ON_OFF = 10262,			  // 技能符文穿脱
	OP_CSZT_CJ = 10263,					  // 传说塔成就
	OP_MEMBER_BUY = 10264,				  // 购买会员
	OP_EQUIP_FENJIE = 10265,			  // 装备分解
	OP_HC = 10266,						  // 合成
	OP_HC_AND_USE = 10267,				  // 合成并使用
	OP_RECOVERY = 10268,				  // 回收
	OP_CANGLONG_GIFT = 10269,			  // 苍龙礼包
	OP_MENGCHONG_GIFT = 10270,			  // 萌宠礼包
	OP_ACTIVITY_LIMIT = 10271,			  // 活动限购
	OP_WING_UPGRADE = 10272,			  // 翅膀升级
	OP_ADD_SKILL_EXP = 10273,			  // 增加技能经验
	OP_CLEAR_SKILL_LEVEL = 10274,		  // 重置技能经验
	OP_TEHUI_MONTH = 10275,				  // 特惠月卡
	OP_TEHUI_WEEK = 10276,				  // 特惠周卡
	OP_SKILL_RESET = 10277,				  // 技能重置
	OP_SKILL_AUTO_OP = 10278,			  // 技能自动
	OP_ITEM_DECOMPOSE = 10279,			  // 分解
	OP_QIHAI_XIULIAN = 10280,			  // 气海修炼
	OP_QIHAI_DEVOUR = 10281,			  // 吞噬红装
	OP_QIHAI_RESET = 10282,				  // 重置气海天赋
	OP_HIGH_INVERSERT = 10283,			  // 高阶投资
	OP_ADD_CONSIGNMENT = 10284,			  // 上架寄售行
	OP_DAILY_RECHARGE = 10285,			  // 每日累计充值
	OP_LINGWEN_ACTIVE = 10286,			  // 激活灵纹
	OP_LINGWEN_UP = 10287,				  // 灵纹升级
	OP_ONCE_RECHARGE = 10288,			  // 单笔充值
	OP_KILL_SHENZHU_BOSS = 10289,		  // 击杀神柱BOSS
	OP_GET_QRFS_TASK_AWARD = 10290,		  // 领取七日封神任务奖励
	OP_GET_QRFS_JIEDUAN_AWARD = 10291,	  // 领取七日封神阶段奖励
	OP_HUOJI = 10292,					  // 火祭
	OP_REMOVE_ZERO = 10293,				  // 零点回收
	OP_JJKH_GIFT = 10299,				  // 购买竞技狂欢礼包
	OP_RECHARGE_REWARD = 10300,			  // 累充送礼
	OP_WORSHIP_REFRESH = 10301,			  // 膜拜刷新
	OP_WORSHIP = 10302,					  // 膜拜
	OP_HOLIDAY_SHOP = 10303,			  // 节日商店
	OP_HOLIDAY_QINGDIAN = 10304,		  // 节日庆典领取奖励
	OP_SHENQIZHONG = 10305,				  // 神器冢膜拜
	OP_DEICIDE = 10306,					  // 弑神装备
	OP_ZHIZUN_INVERSERT = 10307,		  // 至尊投资
	OP_CONTINUITY_RECHARGE_AWARD = 10308, // 连续充值
	OP_SHENBING = 10309,				  // 神兵 合成
	OP_ZANZHU = 10310,					  // MDS赞助
	OP_ASSIST = 10311,					  // 美杜莎 辅助功能
	OP_XUEYUAN_BAOKU = 10312,			  // 学院宝库
	OP_DIAMOND_EXCHANGE = 10313,		  // 钻石兑换
	OP_SHOP = 10314,					  // 商城
	OP_BAOSHI = 10315,					  // 宝石系统
	OP_HERALDRY = 10316,				  // 纹章
	OP_MOWEN = 10317,					  // 魔纹
	OP_ENHANCE = 10318,					  // 强化
	OP_GCZ = 10319,						  // 攻城战
	OP_SHFB = 10320,					  // 守护副本
	OP_SX_HC = 10321,					  // 生肖合成
	OP_DRESS = 10322,					  // 装扮
	OP_FIRSTBLOOD = 10323,				  // 首杀boss
	OP_BUY_ZHANLING_EXP = 10324,		  // 战令经验
	OP_BUY_GUILD_BUFF = 10325,			  // 帮会buff
	OP_GUILD_TOKEN = 10326,				  // 工会令牌
	OP_GUILD_EXCHANGE = 10327,			  // 工会兑换
	OP_VIP_FREE_GIFT = 10328,			  // vip 奖励
	OP_VIP_PAY_GIFT = 10329,			  // vip购买奖励
	OP_JJKH_RANK = 10330,				  // 竞技狂欢排行奖励
	OP_JJKH_AWARD = 10331,				  // 竞技狂欢达成奖励
	OP_GUILD_BATTLE = 10332,			  // 行会对战
	OP_FENJIE = 10333,					  // 分解
	OP_MLGJ = 10334,					  // 猛龙过江抽奖
	OP_HOLIDAY_LSLB = 10335,			  // 连锁礼包
	OP_HOLIDAY_XJZG = 10336,			  // 现金直购
	OP_HOLIDAY_CHONGZHI_RANK = 10337,	  // 运营活动充值排行
	OP_HOLIDAY_XIAOFEI_RANK = 10338,	  // 运营活动消费排行
	OP_ACTIVITY_CHONGZHI_RANK = 10339,	  // 充值排行
	OP_ACTIVITY_XIAOFEI_RANK = 10340,	  // 消费排行
	OP_SC_BOSS_GUILD = 10341,			  // 沙城boss最后一刀工会奖励
	OP_SC_BOSS_PLAYER = 10342,			  // 沙城boss玩家伤害奖励
	OP_HG_BOSS_PLAYER = 10343,			  // 皇宫boss玩家伤害奖励
	OP_SC_BOSS_FINAL = 10344,			  // 皇宫boss最后一刀奖励
	OP_HOLIDAY_XUNBAO_RANK = 10345,		  // 运营活动寻宝排行
	OP_ACTIVITY_XUNBAO_RANK = 10346,	  // 寻宝排行
	OP_FABAO = 10347,					  // 法宝
	OP_SUPER_BOSS_REWARD = 10348,		  // 超级boss奖励
	OP_HC_AUTO = 10349,					  // 自动合成
	OP_GHLC = 10350,					  // 工会理财
	OP_TUJIAN = 10351,					  // 图鉴发放时装
	OP_NTGM = 10352,					  // 逆天改命
	OP_NTGM_DOULI = 10353,				  // 逆天改命斗笠
	OP_NTGM_HUDUN = 10354,				  // 逆天改命护盾
	OP_NTGM_YUPEI = 10355,				  // 逆天改命玉佩
	OP_NTGM_LONGHUN = 10356,			  // 逆天改命龙魂
	OP_YBHS = 10357,					  // 元宝回收
	OP_XUNZHANG = 10358,				  // 勋章任务
	OP_CHUMO = 10359,					  // 除魔
	OP_ZHUZAO = 10360,					  // 神器铸造
	OP_YBHS_DOUBLE = 10361,				  // 元宝回收双倍直购奖励
	OP_GE_REN_BOSS = 10362,				  // 个人BOSS
	OP_BOSS_LEVEL_UP = 10363,			  // BOSS升级
	OP_RONGLIANG = 10364,				  // 熔炼
	OP_RONGLIANGSPLIT = 10365,			  // 熔炼拆分
	OP_BUY_HUANJING_TIME = 10366,		  // 购买幻境时间
};

enum ErrorCode
{
	SUCCESS = 0, // 成功

	//
	// General Error 1-99
	//
	ERROR_UNKNOWN = 1,			 // 未知错误
	ERROR_SCRIPT = 2,			 // lua脚本错误
	ERROR_NOT_IMPLEMENTED = 3,	 // 功能未实现
	ERROR_PLAYER_IS_OFFLINE = 4, // 玩家不在线
	ERROR_NAME_EXIST = 5,		 // 名称已经存在
	ERROR_PASSWORD = 6,			 // 密码错误
	ERROR_ACCOUNT_NOT_EXIST = 7, // 账号不存在
	ERROR_ACCOUNT_IS_FREEZE = 8, // 账号被锁定
	ERROR_SWITCH_NOT_ENABLE = 9, // 功能未开放
	ERROR_INVALID_PARAM = 10,	 // 无效参数
	ERROR_INVALID_ENTITY = 11,	 // 无效实体
	ERROR_INVALID_CATE = 12,	 // 无效物品类型
	ERROR_INVALID_TYPE = 13,
	ERROR_INVALID_ITEM = 14,  // 无效的物品
	ERROR_INVALID_MGR = 15,	  // 无效的物品管理器
	ERROR_INVALID_SCENE = 16, // 无效的场景
	ERROR_INVALID_STATIC_ID = 17,
	ERROR_INVALID_STATIC_DATA = 18,
	ERROR_INVALID_ITEM_MGR = 19, // 无效的物品管理器
	ERROR_NOT_ENOUGH_CONDITION = 20,
	ERROR_HAS_GET_FINISH = 21,
	ERROR_NOT_ENOUGH_LEVEL = 22, // 等级不足
	ERROR_NOT_ENOUGH_PAPER = 23, // 符文不足
	ERROR_NOT_ENOUGH_ITEM = 24,	 // 物品不足
	ERROR_NOT_ENOUGH_SOUL = 25,
	ERROR_NOT_ENOUGH_POWER = 27, // 战力不足
	ERROR_NOT_ENOUGH_SCORE = 28,
	ERROR_NOT_ENOUGH_REBORN_LEVEL = 29, // 转生不足
	ERROR_NOT_ENOUGH_EQUIVALENT = 30,
	ERROR_NOT_ENOUGH_REQ = 31,
	ERROR_NOT_ENOUGH_LINGFU = 32,		// 灵符不足
	ERROR_NOT_ENOUGH_INGOT = 33,		// 元宝不足
	ERROR_NOT_ENOUGH_BOUND_LINGFU = 34, // 绑定灵符不足
	ERROR_NOT_ENOUGH_BOUND_INGOT = 35,	// 绑定元宝不足
	ERROR_NOT_ENOUGH_HONOR = 36,
	ERROR_NOT_ENOUGH_FLYSTONE = 37,
	ERROR_NOT_ENOUGH_POINTS = 38,
	ERROR_NOT_EQUIP = 39,
	ERROR_NOT_ENOUGH_DAY = 40,
	ERROR_NOT_ENOUGH_PET_LEVEL = 41,
	ERROR_NOT_ENOUGH_STONE_POINT = 42,
	ERROR_NOT_ENOUGH_REBORN_POINTS = 43, // 转生修为不够
	ERROR_NOT_OPEN_NEW_FUNC = 44,
	ERROR_NOT_LEARN_SKILL = 45,
	ERROR_NOT_ENOUGH_OIL = 46,
	ERROR_NOT_ENOUGH_RECHARGE_DIAMOND = 47, // 充值钻石不足
	ERROR_NOT_ENOUGH_SPECIAL_DIAMOND = 48,	// 福利钻石不足
	ERROR_ALREADY_USED = 49,
	ERROR_STILL_IN_CD = 50,
	ERROR_UP_TO_LIMIT = 51,
	ERROR_LEVEL_MAX = 52,
	ERROR_ALREADY_GET = 53,
	ERROR_EVENT_NOT_OVER = 54,
	ERROR_HAS_NO_ITEM_REMAIN = 55,
	ERROR_GET_GIFT_SUCCESS = 56,
	ERROR_ALREADY_SET = 57,
	ERROR_TIME_IS_OVER = 58,
	ERROR_NOT_ENOUGH_DIAMOND = 59, // 钻石不足
	ERROR_CANNOT_REMOVE = 60,
	ERROR_CANNOT_REPLACE = 61,
	ERROR_CANNOT_SAME_ITEM = 62,
	ERROR_CANNOT_SAME_FOOT_LV = 63,
	ERROR_NOT_ENOUGH_SAMSARA_POINTS = 64, // 轮回修为不够
	ERROR_PLAYER_NOT_EXIST = 65,		  // 该玩家不存在
	ERROR_NOT_ENOUGH_BOSS_SCORE = 66,	  // BOSS积分不足
	ERROR_NOT_ENOUGH_HUDUN = 67,		  // 护盾不足
	ERROR_RANDOM_STONE_IN_CD = 68,		  // 随机石冷却中
	ERROR_NOT_MATCH_GENDER = 70,		  // 性别不匹配
	ERROR_NOT_MATCH_CLASS = 71,			  // 职业不匹配
	ERROR_NOT_HAS_MONSTER = 72,
	ERROR_NOT_MATCH_CITY_MASTER = 73,
	ERROR_MAX_FAST_KEY = 75,
	ERROR_INVALID_GIFT = 76,
	ERROR_SQL = 77,						  // sql执行失败
	ERROR_ORDER_EXIST = 78,				  // 充值订单已经存在
	ERROR_NOT_ENOUGH_ITEM_NOT_MONEY = 79, // 副本没钱
	ERROR_CONTAINS_SENSITIVE_WORDS = 80,
	ERROR_CONTAINS_SPECIAL_WORDS = 81,
	ERROR_CONTAINS_WHITESPACE_WORDS = 82,
	ERROR_NOT_ENOUGH_GONGCHENGHAOJIAO = 83, // 攻城号角不足
	ERROR_THIS_IS_YOURSELF = 85,
	ERROR_NOT_ENOUGH_BZSD_MONEY = 86,	  // 霸者神殿钱不够
	ERROR_NOT_ENOUGH_COIN_CHUMO = 87,	  // 除魔的钱不够
	ERROR_NOT_ENOUGH_VIP_LEVEL_BOSS = 88, // BOSS 界面VIP
	ERROR_NOT_ENOUGH_ITEM_FB = 89,		  // 副本卷轴不足
	ERROR_FEATURES_NOT_OPEN = 90,
	ERROR_PLAYER_STILL_IN_QUEUE = 91,
	ERROR_NOT_ENOUGH_ZSSD_ITEM = 92,	 // 请购买转生神殿卷轴进入
	ERROR_NOT_ENOUGH_ZSMJ_ITEM = 93,	 // 请购买转生秘境卷轴进入
	ERROR_PLAYER_BANNED = 94,			 // 角色被禁
	ERROR_FORBID_CREATE_ROLE = 95,		 // 注册关闭
	ERROR_FUNCTION_DISABLED = 96,		 // 功能未开放
	ERROR_PLAYER_NAME_NOEXIST = 97,		 // 不存在的玩家名
	ERROR_CANNOT_ADD_ITEM_IN_TRADE = 98, // 处于交易状态不能添加物品
	ERROR_NOT_ENOUGH_BZSD_ITEM = 99,	 // 请购买霸者卷轴进入

	//
	// Entity Error 100-199
	//
	ERROR_ROLE_TOO_MUCH = 100, // 角色数量过多
	ERROR_PET_TOO_MUCH = 101,  // 宠物数量过多
	ERROR_DOG_TOO_MUCH = 102,  // 道士狗数量过多
	ERROR_ITEM_TOO_MUCH = 103,
	ERROR_NOT_IN_GUILD = 104,
	ERROR_NOT_IN_TEAM = 105,
	ERROR_TARGET_NOT_ONLINE = 106, // 目标不在线
	ERROR_HAVE_NO_DOG = 107,
	ERROR_NOT_ENOUGH_VIP_LEVEL = 108, // VIP等级不足
	ERROR_NOT_ENOUGH_COUNT = 109,
	ERROR_TARGET_NOT_IN_GUILD = 116, // 目标不在行会中
	ERROR_NOT_ENOUGH_SHUT_UP = 117,	 // 剩余禁言次数不足
	ERROR_SC_DONATE_MIN = 118,		 // 沙城捐献最少捐200灵符
	ERROR_VIP_2_CHANGE_MASTER = 119, // 至少需要VIP3转移会长
	ERROR_PET_NOT_SLEEP = 120,
	ERROR_PET_NOT_DEAD = 121,
	ERROR_PET_NOT_ON = 122,
	ERROR_PET_CANNOT_IMPRISON = 123,
	ERROR_PET_NEED_LIGHT = 124,
	ERROR_NOT_HAS_ADVANCE_ATTR = 125,
	ERROR_NOT_HAS_BEST_ATTR = 126,
	ERROR_MAX_ADVANCE_ATTR = 127,
	ERROR_PLAYER_IS_DEAD = 130,
	ERROR_PLAYER_IS_ALIVE = 131,
	ERROR_REVIVE_NOT_ALLOW = 132,
	// ERROR_PLAYER_IS_OFFLINE					= 133,
	ERROR_PLAYER_NOT_ALLOW_CHAT = 134,
	ERROR_PLAYER_SPEAK_TOO_FAST = 135,
	ERROR_PLAYER_SPEAK_NOTHING = 136,
	ERROR_PLAYER_HAS_NOT_EQUIP_THIS_ITEM = 137,
	ERROR_PLAYER_IS_ONLINE = 138,
	ERROR_PLAYER_MAX_OFFICIAL = 139, // 官职已达最大
	ERROR_INVALID_CD_TYPE = 140,
	ERROR_CD_HAS_CLEANED = 141,
	ERROR_CD_HAS_LOCKED = 142,
	ERROR_NO_NEED_CLEAN_CD = 143,
	ERROR_REWARD_HAS_GOT = 150,	   // 奖励已领取
	ERROR_NO_REWARD_TO_GET = 151,  // 没有可领取的奖励
	ERROR_NO_REWARD_TO_TIME = 152, // 奖励领取时间未到
	ERROR_NEED_RECHARGE = 160,
	ERROR_MAX_BAG_SOLT = 161,
	ERROR_SALE_30S_INTERVAL = 162,
	ERROR_TIME_3S_SPAN = 163,
	ERROR_TIME_30S_SPAN = 164,
	ERROR_TIME_10S_SPAN = 165,
	ERROR_THINGS_OVER_MAX = 170,
	ERROR_TITLE_HAS_OPEN = 175,
	ERROR_TITLE_HAS_CLOSE = 176,
	ERROR_HAS_NO_TITLE = 177,
	ERROR_ALREADY_HAS_TITLE = 178,
	ERROR_BOOTH_UP_TYPE_LIMIT = 179,
	ERROR_HAS_NOT_OFF_EXP = 180,
	ERROR_HAS_OFFICIAL_SALARY = 181,		   // 已经领取过俸禄
	ERROR_NEED_CONSUME = 182,				   // 消费不足
	ERROR_PLAYER_REBORN_MAX = 183,			   // 玩家转生等级已经达到上限
	ERROR_NO_ENOUGH_VITALITY = 184,			   // 活跃度不足
	ERROR_PLAYER_SAMSARA_MAX = 185,			   // 玩家轮回等级已经达到上限
	ERROR_NOT_ENOUGH_GONGXUN = 186,			   // 功勋不足
	ERROR_NOT_ENOUGH_MOHUN = 187,			   // 魔魂不足
	ERROR_VIP_2_CREATE = 188,				   // 至少需要VIP3创建行会
	ERROR_PLAYER_REBORN_POINTS_MAX = 189,	   // 玩家转生修为已经达到上限
	ERROR_CONSIGNMENT_EXPIRED = 190,		   // 物品已下架
	ERROR_CONSIGNMENT_NOT_EXIST = 191,		   // 寄售物品已不存在
	ERROR_RECOVERY_OVERLIMIT = 192,			   // 回收超过限制
	ERROR_CONNOT_RECOVERY = 193,			   // 该物品无法回收
	ERROR_HERO_REBORN_POINTS_MAX = 194,		   // 英雄转生修为已经达到上限
	ERROR_PLAYER_NOT_ALLOW_PRIVATE_CHAT = 195, // 私聊被禁
	ERROR_PROHIBIT_ZYZH_WHEN_DEAD = 196,	   // 死亡状态无法资源找回
	//
	// Item Error 200-299
	//
	ERROR_NO_SUCH_SLOT = 200,
	ERROR_BAG_NOT_ENOUGH = 201, // 背包空间不足
	ERROR_BAG_NOT_LEFT_FIVE = 203,
	ERROR_BAG_IS_FULL = 204,
	ERROR_ITEM_SUCCESS_BAG_FULL = 205,
	ERROR_ITEM_ALREADY_INLAY = 215,
	ERROR_ITEM_NO_MATCH_CLASS = 216,
	ERROR_ITEM_NO_MATCH_GENDER = 217,
	ERROR_ITEM_DESTINATION_NOT_FOUND = 220,
	ERROR_ITEM_CD_LOCKED = 226,
	ERROR_ITEM_NOT_ENOUGH_SLOT = 227,
	ERROR_ITEM_PLAYER_TYPE = 228,
	ERROR_ITEM_MEDICINE_CD_LOCKED = 229,
	ERROR_ITEM_CANNOT_SELL = 230, // 此物品不能售卖
	ERROR_ONLY_IN_GONGHUIBOSS = 231,
	ERROR_ONLY_IN_TIANWEIMOYU = 232,
	ERROR_CANT_USE_ITEM_HERE = 233,
	ERROR_CANT_USE_SAME_TYPE_ITEM = 234,	 // 同类道具不可同时使用
	ERROR_CANT_DELETE_PUT_ON_ITEM = 235,	 // 无法删除已装备物品
	ERROR_CANT_DROP_PUT_ON_ITEM = 236,		 // 无法丢弃已装备物品
	ERROR_CANT_ADD_ITEM_IN_BAG = 237,		 // 无法将该物品添加进背包
	ERROR_PAGE_STORE_IS_LOCKED = 238,		 // 本页仓库未解锁
	ERROR_NOT_ENOUGH_LUNHUI_BIND_COIN = 239, // 轮回绑定金币不足
	ERROR_NOT_ENOUGH_ZSXW_BIND_COIN = 240,	 // 转生绑定金币不足
	ERROR_ITEM_MAX_LEVEL = 241,
	ERROR_PAGE_BAG_IS_FULL = 242, // 本页背包已满
	ERROR_ITEM_CANNOT_DO_IT = 243,
	ERROR_PAGE_STORE_IS_FULL = 244,				 // 本页仓库已满
	ERROR_ITEM_CANNOT_ABANDON_CURRENT_MAP = 245, // 此物品不能丢弃在当前地图
	ERROR_ITEM_CANNOT_ABANDON = 246,			 // 此物品不能丢弃
	ERROR_ITEM_CANNOT_TRADE = 247,				 // 此物品不能交易
	ERROR_ITEM_CANNOT_BOOTH = 248,
	ERROR_ITEM_CANNOT_USE = 249, // 此物品不能使用
	ERROR_ITEM_SAME_POSITION = 250,
	ERROR_PLAYER_BAG_IS_FULL = 251, // 玩家背包已满
	ERROR_PET_BAG_IS_FULL = 252,	// 宠物背包已满
	ERROR_WAREHOUSE_BAG_IS_FULL = 253,
	ERROR_MARKET_BAG_IS_FULL = 254,
	ERROR_NPC_BAG_IS_FULL = 255,	   // NPC仓库已满
	ERROR_PAGE_BAG_IS_LOCKED = 256,	   // 本页背包未解锁
	ERROR_ITEM_CANNOT_MOVE = 257,	   // 不满足交换规则
	ERROR_ALL_BAG_SLOT_UNLOCK = 258,   // 所有的背包格子都被解锁
	ERROR_ALL_STORE_SLOT_UNLOCK = 259, // 所有的仓库格子都被解锁
	ERROR_ITEM_UNLOCK_REQ_NOT_ENOUGH = 260,
	ERROR_ITEM_NOT_ENOUGH_EHANCE_LEVEL = 261,
	ERROR_ITEM_MAX_BORN_LEVEL = 262,
	ERROR_ITEM_EXP_JADE_NOT_FULL = 265,	   // 经验玉没满
	ERROR_TREASURE_BAG_IS_FULL = 266,	   // 寻宝仓库已满
	ERROR_LUCKY_COMPASS_BAG_IS_FULL = 267, // 神运罗盘背包已满
	ERROR_USE_ITEM_ADD_EXP = 268,		   // 使用物品增加经验时，经验储存已经达到上限
	ERROR_ITEM_FAILED = 271,
	ERROR_EQUIP_CANNOT_PUOFF = 272, // 当前装备不可脱下
	ERROR_ITEM_CANNOT_DIEJIA = 273,  //不能叠加

	ERROR_ITEM_MARKET_CHANGED = 284,
	ERROR_ITEM_NO_USE_NOW = 285,
	ERROR_ITEM_POSITION_UNAVAILABLE = 286,	 // 当前位置不可用
	ERROR_ITEM_CHUANSHI_NO_MORE_LEVEL = 287, // 该传世装备已升满
	ERROR_ITEM_PK_NO_REASON_DECLINE = 288,	 // 无需使用消红药水
	ERROR_ITEM_PK_NO_TRANSFER_STONE = 289,	 // 当前地图不可使用传送石
	ERROR_CAN_NOT_USE_IN_GCZ = 290,			 // 攻城战期间无法使用该道具
	ERROR_HP_IS_FULL = 291,					 // 生命值已满
	ERROR_MP_IS_FULL = 292,					 // 魔法值已满
	ERROR_NOT_ENOUGH_TICKET = 293,			 // 入场券不足
	ERROR_ITEM_FIRE_IS_FULL = 294,			 // 火把拥有数量达到上限
	// MilitaryExploits
	ERROR_NOT_ENOUGH_MILITARY_EXPLOITS = 295, // 战功不足
	ERROR_NOT_ENOUGH_PRESTIGE_VALUE = 296,	  // 威望不足
	ERROR_NOT_ENOUGH_KEY = 297,				  // 秘宝钥匙不足
	ERROR_PK_VALUE_IS_ZERO = 298,			  // 杀戮值为0
	ERROR_BAG_NOT_ENOUGH_TO_SPLIT_DRUGS = 299,	  // 背包已满，药品无法拆分！

	//
	// Combat Error 300-399
	//
	ERROR_COMBAT_FAILED = 300,
	ERROR_COMBAT_OUT_OF_MANA = 301,
	ERROR_COMBAT_NOT_IN_RANGE = 302,
	ERROR_COMBAT_INVALID_SKILL = 303,
	ERROR_COMBAT_IN_COOLDOWN = 305,
	ERROR_COMBAT_PLAYER_IS_DAZE = 306,
	ERROR_COMBAT_SKILL_DUPLICATE = 310,
	ERROR_COMBAT_SKILL_LEVEL_NOT_ENOUGH = 311,
	ERROR_COMBAT_SKILL_TOTEM = 320,

	//
	// Scene Error  400-499
	//
	ERROR_NOT_IN_GRID = 401,
	ERROR_TEAM_MEMBER_NOT_NEAR = 410,
	ERROR_TOO_MANY_TIMES = 411, // 已经没有可用的次数了
	ERROR_ENTRANCE_CLOSED = 412,
	ERROR_SCENE_NOT_ALLOW = 413,
	ERROR_SCENE_NOT_FINISH = 414,
	ERROR_SCENE_PEACE_AREA = 415,
	ERROR_CANT_QUIT_TEAM_IN_INS = 416,
	ERROR_SCENE_STOP_MINE = 417,
	ERROR_SCENE_SWITCH_IN_EVENT = 418,
	ERROR_ITEM_NOT_BELONG_YOU = 420,
	ERROR_SCENE_SEARCH_PLAYER = 421,				  // 查找玩家失败，不在线，或者不存在
	ERROR_NO_BUY_TIMES = 422,						  // 已经没有购买次数了
	ERROR_ITEM_LIMIT_PICK = 423,					  // 物品不可拾取
	ERROR_NOT_MEET_LEVEL = 424,						  // 不满足等级
	ERROR_NOT_TRANS_PROCON = 425,					  // 押镖中无法通过召唤令传送
	ERROR_DELAY_ENTER = 426,						  // 从一个服务器的地图进入到另一个服务器的地图
	ERROR_DISABLE_INSTANCE_TRANSFER = 427,			  // 当前地图无法传送至副本地图
	ERROR_DISABLE_TRANSFER_WHEN_IN_PRIVATEDART = 428, // 押镖过程无法传送至其他地图

	ERROR_FLY_BOOT_IS_DISABLE = 450, // 此场景禁用飞鞋
	ERROR_NOT_ENOUGH_FLY_BOOT = 451, // 飞鞋数量不足
	ERROR_CANT_RANDOM_STONE = 452,	 // 不能使用随机石
	ERROR_ONLY_IN_MOCITY = 453,
	ERROR_MARKET_NOT_ALLOW_PLACE = 460,
	ERROR_SCENE_LINE_FULL = 470,	   // 分线人数已满
	ERROR_SCENE_GTCL_MAX_PORTAL = 471, // 宫廷长廊传送门已最大
	ERROR_SCENE_GTCL_HAS_PORTAL = 472, // 宫廷长廊已有传送门
	ERROR_SCENE_GTCL_NOT_ENABLE = 473, // 时间上未开放

	//
	//	符文刻印相关报错 475 - 485
	//
	ERROR_MIND_PRACTICE_NOHERO = 475,	// 没有英雄
	ERROR_MIND_PRACTICE_NOVALUE = 476,	// 刻印值不足
	ERROR_MIND_PRACTICE_MAXLEVEL = 477, // 刻印最大等级

	//
	// Quest Error  500-599
	//
	ERROR_INVALID_QUEST_ID = 500,
	ERROR_INVALID_QUEST_STATE = 501,
	ERROR_CANT_REMOVE_QUEST = 502,
	ERROR_NEED_FINISHI_CURRENT_TASK = 503, // 需要先完成当前任务
	ERROR_NOT_ACHIEVE_VIP_LEVEL = 504,	   // 未达到所需vip等级
	ERROR_QUEST_GET_ENOUGH_ITEM = 510,
	ERROR_ITEM_NOT_THIS_QUEST = 511,
	ERROR_CML_NOT_ENOUGH = 512,			// 除魔令数量不足
	ERROR_QUEST_TIMES_NOT_ENOUGH = 513, // 任务剩余次数不足

	//
	// Trade Error  600-699
	//
	ERROR_TRADE_SELF_TRADING = 601,		 // 自己已经在交易中
	ERROR_TRADE_OTHER_TRADING = 602,	 // 对方已经在交易中
	ERROR_TRADE_SELF_NO_TRADING = 603,	 // 自己不在交易中
	ERROR_TRADE_CANNOT_FIND_OTHER = 604, // 在场景中未找到对方玩家
	ERROR_TRADE_OTHER_REFUSE = 605,		 // 对方拒绝交易
	ERROR_TRADE_OTHER_BUZY = 606,		 // 对方正忙
	ERROR_TRADE_CREATE_FAILED = 607,	 // 创建交易失败
	ERROR_TRADE_DISABLE_IN_SCENE = 608,	 // 场景禁止交易
	ERROR_TRADE_OTHER_NO_RESPOSNE = 609, // 对方未响应交易请求
	ERROR_TRADE_SELF_NO_RESPOSNE = 610,	 // 自己未响应对方的交易请求
	ERROR_TRADE_REVISION = 611,			 // 交易版本号不一致
	ERROR_TRADE_ALREADY_COMMITED = 613,	 // 已经确认交易了
	ERROR_TRADE_MONEY_NO_CHANGED = 625,
	ERROR_TRADE_COIN_COUNT = 616,				  // 金钱数量错误
	ERROR_TRADE_INGOT_COUNT = 616,				  // 金钱数量错误
	ERROR_TRADE_CANCEL_BY_SELF = 619,			  // 自己取消了交易
	ERROR_TRADE_CANCEL_BY_OTHER = 620,			  // 对方取消了交易
	ERROR_TRADE_NOT_ENOUGH_BAG = 621,			  // 背包空间不足
	ERROR_TRADE_OUT_OF_RANG = 622,				  // 超出交易范围
	ERROR_TRADE_NOT_SAME_SCENE = 623,			  // 玩家不在同一个场景
	ERROR_TRADE_TIMEOUT = 624,					  // 交易超时
	ERROR_TRADE_OTHER_OFFLINE = 625,			  // 对方下线
	ERROR_TRADE_WAIT_OTHER_DECIDE = 626,		  // 交易申请成功，等待对方响应
	ERROR_TRADE_DISABLED = 627,					  // 交易功能尚未开放
	ERROR_TRADE_LIMIT_BUY = 628,				  // 未开放此物品购买
	ERROR_TRADE_NOT_ENOUGH_LEVEL_SELF = 629,	  // 自己等级不够
	ERROR_TRADE_NOT_ENOUGH_LEVEL_OTHER = 630,	  // 对方等级不够
	ERROR_HERO_HAS_EQUIP = 631,					  // 英雄身上有装备，不能转职
	ERROR_HERO_DEAD = 632,						  // 英雄已经死亡，不能转职
	ERROR_TRADE_FAILED = 633,					  // 交易失败
	ERROR_TRADE_NOT_ENOUGH_ZANZHU_LV_SELF = 634,  // 自己赞助等级不够
	ERROR_TRADE_NOT_ENOUGH_ZANZHU_LV_OTHER = 635, // 对方赞助等级不够

	//
	// NPC Error	700-799
	//
	ERROR_INVALID_NPC_FUNCTION = 700,
	ERROR_EVENT_IN_ACTIVE = 701,
	ERROR_EVENT_IS_ACTIVE = 702,
	ERROR_NOT_ENOUGH_INSTANCE_PASSPORT = 703,
	ERROR_ACTIVIE_DOOR_CLOSE = 704,
	ERROR_MAIN_TASK_NOT_FINISHED = 705,
	ERROR_BOSS_BEEN_KILLED = 706,
	ERROR_GZC_UNOPNE = 707,

	//
	// Team Error 800-899
	//
	ERROR_TEAM_IS_YOUSELF = 800,		  // 无法对自己进行组队操作
	ERROR_TEAM_OPERATION_OVER_TIME = 801, // 超时
	ERROR_PLAYER_GET_NO_TEAM = 802,		  // 该玩家没有队伍
	ERROR_PLAYER_GET_TEAM = 803,		  // 该玩家已有队伍
	ERROR_TEAM_MAX_MEMBER = 804,		  //
	ERROR_YOU_GET_TEAM = 805,			  // 你已有队伍
	ERROR_NOT_TEAM_LEADER = 806,		  // 你不是队长
	ERROR_PLAYER_IN_PRISON = 807,		  // 监狱
	ERROR_YOU_NOT_TEAM = 808,			  // 你没有队伍
	ERROR_INVITE_NOT_LEADER = 809,		  // 邀请人已经不是队长
	ERROR_TEAM_NOT_EXIST = 810,			  // 该队伍不存在
	ERROR_TEAM_NEED_CAPITAL_DEC = 811,	  // 向队长发送要求玩家入队的请求
	ERROR_TEAM_CAPITAL_DEC_ADMIT = 812,	  // 队长同意玩家加入队列
	ERROR_TEAM_CAPITAL_DEC_REJECT = 813,  // 队长拒绝玩家加入队列
	ERROR_TEAM_CROSSSERVER = 814,		  // 跨服不能组队
	ERROR_FIFA_BET_FINISHED = 815,		  // 比赛停止押注
	ERROR_FIFA_NOT_FINISHED = 816,		  // 比赛尚未结束
	ERROR_FIFA_REWARD_REPEATED = 817,	  // 重复领取奖励
	ERROR_FIFA_NO_REWARD = 818,			  // 没有奖励可领取

	//
	// Guild Error 900-999
	//
	// ERROR_GUILD_SUCCESS						= 900,
	// ERROR_GUILD_UNKNOWN						= 901,
	ERROR_GUILD_REAPP = 902,			// 重复申请
	ERROR_GUILD_AUTHORITY = 903,		// 你没有权限执行该操作
	ERROR_GUILD_NOAPP = 904,			// 该申请不存在
	ERROR_GUILD_HAS_GUILD = 905,		// 目标已经有公会
	ERROR_GUILD_NOT_ENOUGH_INGOT = 906, // 没有足够的公会资金
	ERROR_GUILD_NO_THIS = 907,			// 没有这个公会
	ERROR_GUILD_NO_GUILD = 908,			// 没有公会
	ERROR_GUILD_NOT_EXIST = 909,		// 公会不存在
	ERROR_GUILD_NOT_SEND_RED = 910,		// 不在公会中，无法发送红包
	ERROR_GUILD_NAME_USED = 911,		// 公会名字已经被使用G
	ERROR_GUILD_CREATING = 912,			// 正在创建中
	ERROR_GUILD_NOT_MASTER = 913,		// 你不是公会会长
	ERROR_GUILD_NOT_ENOUGH_ITEM = 914,	// 所需物品不足
	ERROR_GUILD_NOT_THIS_MEMBER = 915,
	ERROR_GUILD_NAME_TOO_LONG = 916, // 行会名称太长
	ERROR_GUILD_KICK_SELF = 917,
	ERROR_GUILD_SAME_PLAYER = 918,
	ERROR_GUILD_MAX_MEMBER = 919,
	ERROR_GUILD_BOSS_HAS_CALLED = 920,
	ERROR_GUILD_NO_BOSS = 921,
	ERROR_GUILD_NOT_IN_CP_SHIP = 922,
	ERROR_GUILD_UNKNOWN_FIGHT_ID = 923,
	ERROR_GUILD_BOSS_CALL_MAX = 924,
	ERROR_GUILD_BOSS_FIGHT_MAX = 925,
	ERROR_GUILD_BOSS_LEVEL_TOO_LOW = 926,
	ERROR_GUILD_TODAY_MEET_END = 927,
	ERROR_GUILD_MEET_NOT_INVITE = 928,
	ERROR_GUILD_MEET_NOT_BEGIN = 929,
	ERROR_GUILD_IS_REWARD = 930,
	ERROR_GUILD_INVALID_NICKNAME = 931,
	ERROR_GUILD_INVALID_JOB = 932,
	ERROR_GUILD_INVITEE_HAS_APP = 934,
	ERROR_GUILD_APP_SUCCESS = 935,
	ERROR_GUILD_GET_WELFARE_SUCCESS = 936,
	ERROR_GUILD_INVALID_MEMBER = 937,
	ERROR_GUILD_APP_MAX = 938,
	ERROR_GUILD_SHOP_INVALID_PAGE = 939,
	ERROR_GUILD_SHOP_NOT_ENOUGH_CONTRIBUTION = 940, // 您的公会贡献不足！
	ERROR_GUILD_CANCEL_APPLY_SUCCESS = 941,			// 取消申请加入行会成功
	ERROR_GUILD_NOT_APPLY = 942,
	ERROR_GUILD_IN_LEAVE_TIME = 943,
	ERROR_GUILD_POST_RESET_FORBID = 944,
	ERROR_GUILD_MONEY_INCREASED = 945,
	ERROR_GUILD_ON_22_ON_FRIDAY = 946,
	ERROR_GUILD_TARGET_IN_LEAVE_TIME = 948,
	ERROR_GUILD_APP_PENDING = 949, // 请求已经发送，等待回复
	ERROR_GUILD_MASTER_LEAVE_INVALID = 950,
	ERROR_GUILD_NOT_ENOUGH_CONTRIBUTION = 951,
	ERROR_GUILD_EXPLORE_BUILDING_NOT_FOUND = 952,
	ERROR_GUILD_EXPLORE_TIME_NOT_ENOUGH = 953,
	ERROR_GUILD_PLCARD_NULL = 954,	   // 公告没有
	ERROR_GUILD_PLCARD_TOO_LONG = 955, // 行会公告太长
	ERROR_GUILD_INVAGE_FULL = 956,	   // 最多10个公会邀请
	ERROR_GUILD_BUILDING_LEVEL_NOT_SATISFIED = 957,
	ERROR_GUILD_COUNT_MAX_LIMIT = 958,				 // 服务器行会数量达到上限
	ERROR_GUILD_WORSHIP_COUNT_LIMIT = 959,			 // 膜拜次数达到上限
	ERROR_GUILD_WORSHIP_EXIST = 960,				 // 同一个玩家只能被膜拜一次
	ERROR_GUILD_WORSHIP_TYPE = 961,					 // 无效的膜拜类型
	ERROR_GUILD_NO_BE_WORSHIPED_REWARD = 962,		 // 没有被膜拜的奖励
	ERROR_GUILD_NOT_ENOUGH_GUILD_LEVEL = 963,		 // 行会等级不够
	ERROR_GUILD_NOT_ENOUGH_GUILD_MONEY = 964,		 // 行会资金不足
	ERROR_GUILD_NOT_ENOUGH_GUILD_VITALITY = 965,	 // 行会活跃度不足
	ERROR_GUILD_INSTANCE_NOT_OPENED = 966,			 // 行会副本未开启
	ERROR_GUILD_EVENT_NOT_OPENED = 967,				 // 行会副本活动未开启
	ERROR_GUILD_LEAGUE_APP_EXIST = 968,				 // 已经申请结盟
	ERROR_GUILD_LEAGUE_APP_NOENT = 969,				 // 没有申请结盟
	ERROR_GUILD_SELF_LEAGUE_EXIST = 970,			 // 您的行会已经结盟
	ERROR_GUILD_OTHER_LEAGUE_EXIST = 971,			 // 对方行会已经结盟
	ERROR_GUILD_LEAGUE_NOENT = 972,					 // 不是结盟
	ERROR_GUILD_HAVE_APPLYED = 973,					 // 该行会已经申请
	ERROR_GUILD_UPGRADE_CD_ZERO = 974,				 // 行会升级CD已经结束
	ERROR_GUILD_NO_NEXT_LEVEL = 975,				 // 行会等级已经最高
	ERROR_GUILD_DATA = 976,							 // 行会数据错误
	ERROR_GUILD_NOT_MASTER_GUILD = 977,				 // 你不是乾坤圣殿占领行会成员！
	ERROR_GUILD_NOT_APPLY_GCZ = 978,				 // 你的行会并未报名攻城战！
	ERROR_GUILD_INSTANCE_ANOTHER_OPENED = 979,		 // 行会副本同一时间只能开启一个
	ERROR_GUILD_UPGRADE_IN_CD = 980,				 // 行会升级冷却中
	ERROR_GUILD_INSTANCE_OPENED_TODAY = 981,		 // 行会副本今天已经开启过
	ERROR_GUILD_MONEY_LIMITED = 982,				 // 行会资金已达到上限
	ERROR_GUILD_IS_PALYING = 983,					 // 行会争夺战中
	ERROR_GUILD_GCZ_NEED_APPLY = 984,				 // 城主行会不需要报名
	ERROR_GUILD_EVENT_UNJOIN = 985,					 // 未参加公会活动，不能领红包
	ERROR_GUILD_NOT_EXIST_GUILD_RED = 986,			 // 无效红包
	ERROR_GUILD_ARRADY_GET_GUILD_RED = 987,			 // 红包已领取
	ERROR_GUILD_NOT_ENOUGH_GUILD_RED = 988,			 // 红包余额不足
	ERROR_GUILD_NOT_ENOUGH_GUILD_BAG = 989,			 // 行会仓库已满
	ERROR_GUILD_NOTICE_TOO_LONG = 990,				 // 行会公告太长
	ERROR_GUILD_NEED_MASTER_OR_SECOND_MASTER = 991,	 // 你不是会长或副会长，无权操作！
	ERROR_GUILD_OTHER_NOT_ENOUGH_LEAGUE_TIMES = 992, // 对方公会已经没有结盟次数了！
	ERROR_GUILD_NOT_ENOUGH_LEAGUE_TIMES = 993,		 // 您的公会已经没有结盟次数了！
	ERROR_NOT_NEED_APPLY = 994,						 // 活动首次开启无需报名
	ERROR_GUILD_PROSECUTOR_CANNOT_EXIT = 995,		 // 您发起的弹劾投票还未结束，不可退会！
	ERROR_GUILD_PROSECUTOR_CANNOT_BE_KICKED = 996,	 // 该玩家发起的弹劾投票还未结束，不可踢出！
	ERROR_GUILD_NEWER_CANNOT_VOTED = 997,			 // 公会新加入成员没有投票权！
	ERROR_GUILD_MASTER_BEING_IMPEACHED = 998,		 // 您正在被弹劾，暂时没有公会的管理权限！
	ERROR_GUILD_SPEEK_MAX = 999,					 // 发语音的人超过上限

	//
	// Activity Error 1000 - 1099
	//
	ERROR_MOBAI_IS_OVER_MAX = 1001,
	ERROR_MOBAI_EXPPER_IS_MAX = 1002,
	ERROR_MOBAI_EXP_CHOOSE_LOWER = 1003,
	ERROR_MOBAI_ADD_COUNT_MAX = 1004,
	ERROR_MOBAI_COUNT_IS_ZERO = 1005,
	ERROR_GUWU_FAILURE = 1006,
	ERROR_GUWU_MAX_COUNTS = 1007,
	ERROR_DIAMOND_GUWU_MAX_COUNTS = 1008,
	ERROR_CAI_SHEN_CHUANG_GUAN_IS_OVER_MAX = 1010,
	ERROR_CAI_SHEN_CHUANG_GUAN_IS_GAMEOVER = 1011,
	ERROR_CAI_SHEN_CHUANG_GUAN_MEET_CASE = 1012,
	ERROR_CAI_SHEN_CHUANG_GUAN_HAS_QUEST = 1013,
	ERROR_MEI_NV_HU_SONG_IS_OVER_MAX = 1020,
	ERROR_MEI_NV_HU_SONG_NO_GIRL = 1021,
	ERROR_MEI_NV_HU_SONG_IS_BEGIN = 1022,
	ERROR_MEI_NV_HU_SONG_SOMEONE_BEGIN = 1023,
	ERROR_TREASURE_LEVEL_NOT_ENOUGH = 1030,
	ERROR_TREASURE_REWARD_IS_GET = 1031,
	ERROR_TREASURE_HAPPNESS_NOT_ENOUGH = 1032,
	ERROR_TREASURE_DAILY_TIME_NOT_ENOUGH = 1033,
	ERROR_RICH_NOT_GUILD_BOSS = 1040,
	ERROR_RICH_NOT_ENOUGH_MONEY = 1041,
	ERROR_RICH_SCENE = 1042,
	ERROR_RICH_NOT_HAS_GUILD = 1043,
	ERROR_ARENA_REFRESH_BUFF_MAX = 1050,
	ERROR_ARENA_FIGHT_MAX = 1051,
	ERROR_ARENA_FIGHT_ZERO = 1052,
	ERROR_ARENA_BUFF_BEST = 1053,
	ERROR_DAY_SIGN_HAS_SIGNED = 1060,
	ERROR_DAY_SIGN_NOT_ALREADY = 1061,
	ERROR_DAY_SIGN_ONLY_RETROACTIVE_THIS_WEEK = 1062,
	ERROR_NOT_REACH_NEED_TIME = 1071,
	ERROR_ARENA_CREATE_TEAM = 1084,
	ERROR_HERE_NOT_ALLOW_RELIVE = 1087,
	ERROR_HAVE_BUYED_CZLC = 1088,		  // 已经购买过超值理财
	ERROR_NOT_BUYED_CZLC = 1089,		  // 未购买过超值理财
	ERROR_HAVE_REWARDED_CZLC = 1090,	  // 已领取过超值理财奖励
	ERROR_CZLC_SOLD_OUT = 1091,			  // 超值理财已售完
	ERROR_EXCHANGE_MAX_HYSD = 1092,		  // 幻影神殿满三次兑换
	ERROR_ALREADY_QUIT_KFYZ = 1093,		  // 已经退出跨服远征, 不能再进入
	ERROR_ALREADY_IN_ACTIVITY_MAP = 1094, // 已经在活动场景中

	//
	// Pet Error 1100 - 1199
	//
	// pe_succeed								= 1100,
	// pe_unknown								= 1101,
	ERROR_PET_NOT_PET = 1102, // 不存在此宠物
	// pe_not_player								= 1103,
	// pe_not_gold								= 1104,
	// pe_not_exp								= 1105,
	// pe_not_allow								= 1106,
	// pe_not_enoughlvl							= 1107,
	// pe_is_combat								= 1108,
	ERROR_PET_ALREADY_MAX_LEVEL = 1109,
	// BoothDownSuccess							= 1110,  //下架成功
	// BoothUpSuccess							= 1111,  //上架成功
	// MarketSuccess								= 1112,  //摆摊成功
	// MarketCantNone							= 1113,  //摆摊不能不出售物品
	// NotAdvanceAttr							= 1114,  //没有可提升的进阶属性

	ERROR_PET_NOT_SKILL = 1120,		 // 不存在此宠物技能
	ERROR_PET_HAS_PET = 1121,		 // 已经拥有此宠物
	ERROR_PET_DEAD_COOL = 1122,		 // 宠物死亡冷却中
	ERROR_PET_MAX_STAR = 1123,		 // 已达最大星级
	ERROR_PET_MARKET_LEVEL = 1124,	 // 当前宠物没有达到摆摊等级--宠物到达10级才能摆摊
	ERROR_PET_MARKET_PACK_UP = 1125, // 该摊位已收摊

	ERROR_DOG_MAX_LEVEL = 1130,
	ERROR_DOG_DEAD = 1131,
	ERROR_MARS_HAS_EXIT = 1132,			// 已已经有战神
	ERROR_MARS_NOT_ENOUGH_TIMES = 1133, // 剩余召唤次数不足

	//
	// Relationship Error 1200 - 1299
	//
	ERROR_SOCIAL_NAME_EMPTY = 1201,		  // 名字不得为空
	ERROR_SOCIAL_PLAYER_NOT_EXIST = 1202, // 玩家角色不存在
	ERROR_SOCIAL_ALREADY_FRIEND = 1210,
	ERROR_SOCIAL_ALREADY_MASTER = 1211,
	ERROR_SOCIAL_ALREADY_APPRENTICE = 1212,
	ERROR_SOCIAL_ALREADY_COUPLE = 1213,
	ERROR_SOCIAL_ALREADY_ENEMY = 1214,
	ERROR_SOCIAL_ALREADY_BLACKLIST = 1215,
	ERROR_SOCIAL_HAS_ENOUGH_MASTER = 1220,
	ERROR_SOCIAL_HAS_ENOUGH_APPRENTICE = 1221,
	ERROR_SOCIAL_TARGET_LEVEL = 1230,
	ERROR_SOCIAL_LEVEL_MAX = 1231,
	ERROR_SOCIAL_REFUSE_ADD_FRIEND = 1232,	  // 对方拒绝添加好友
	ERROR_SOCIAL_IS_ENEMY = 1233,			  // 对方是你的仇人，无法添加好友
	ERROR_SOCIAL_IS_ENEMY_TOO = 1234,		  // 对方添加你为仇人，无法添加好友
	ERROR_SOCIAL_REQUEST_NOT_EXIST = 1235,	  // 邀请已不存在
	ERROR_SOCIAL_IS_BLACK = 1236,			  // 黑名单，无法添加好友
	ERROR_SOCIAL_IS_BLACK_TOO = 1237,		  // 对方添加你为黑名单，无法添加好友
	ERROR_SOCIAL_HAS_ENOUGH_FRIEND = 1238,	  // 好友数量已达上线
	ERROR_SOCIAL_HAS_ENOUGH_BLACK = 1239,	  // 黑名单数量已达上线
	ERROR_SOCIAL_HAS_ENOUGH_ENEMY = 1240,	  // 仇人数量已达上线
	ERROR_SOCIAL_TARGET_ENOUGH_FRIEND = 1241, // 对方好友已满
	ERROR_SOCIAL_ADD_SELF_FRIEND = 1242,	  // 不能添加自己为好友
	ERROR_SOCIAL_CANT_RECENTLY = 1243,		  // 不能添加最近联系人
	ERROR_SOCIAL_ADD_FRIEND_IN_CD = 1244,	  // 添加好友在冷却中

	//
	// Gift Error 1300 - 1399
	//
	ERROR_GIFT_BEGIN = 1300,
	ERROR_GIFT_SERVER = 1310,
	ERROR_GIFT_INVALID = 1311,
	ERROR_GIFT_HAS_USED = 1312,
	ERROR_GIFT_HAS_BUY = 1313,
	ERROR_CODE_EXPIRED = 1317, // 激活码过期

	//
	// Mail Error 1400 - 1499
	//
	ERROR_MAIL_RECEIVER_NAME_EMPTY = 1401,	  // 收件人姓名为空
	ERROR_MAIL_RECEIVER_NAME_TOO_LONG = 1402, // 收件人姓名过长
	ERROR_MAIL_TITLE_TOO_LONG = 1403,		  // 邮件标题过长
	ERROR_MAIL_CONTENT_TOO_LONG = 1404,		  // 邮件内容过长

	//
	// Market Error 1500 - 1599
	//
	ERROR_MARKET_IS_OPEN = 1500,
	ERROR_MARKET_NOT_OPEN = 1501,
	ERROR_MARKET_NO_ITEM = 1502,
	ERROR_MARKET_SELF_ADDWORDS = 1503,
	ERROR_MARKET_NOT_EXIST = 1504,
	ERROR_MARKET_OVER_MAX_BAG = 1505, // 选择的宠物摆摊容量不足，也就是有物品存在于摆摊最大数之外
	ERROR_MARKET_BUY_SELF = 1506,	  // 购买自己的物品

	//
	// GCZ Error 1600 - 1615
	//
	ERROR_GCZ_NOT_BEGIN = 1600, // 攻城战未开启
	ERROR_GCZ_HAS_END = 1602,
	ERROR_GCZ_ALLOW_QKZD = 1603,
	ERROR_GCZ_GET_REWARD_TIME = 1604, // 城主奖励领取时间
	ERROR_GCZ_REWARD_HAS_GOT = 1606,  // 奖励已领取
	ERROR_GCZ_DEAD_HUANGGONG = 1607,  // 死亡状态无法进入皇宫
	ERROR_GCZ_REWARD_TIME = 1608,	  // 不在领取奖励时间

	//
	// 神威魔域 Error 1616 - 1620
	//
	EROOR_SWMY_BOSS_IS_ALIVE = 1616, // boss未击杀

	//
	// Talent Error 1651 - 1699
	//
	ERROR_TALENT_PAGE_NOT_ACTIVE = 1651,	  // 天赋页未激活
	ERROR_MOLI_NOT_ENOUGH = 1652,			  // 魔力值不足
	ERROR_NEED_ACTIVE_FRONT_TALENT = 1653,	  // 请先激活前置天赋
	ERROR_FORBID_CANCEL_FIRST_TALENT = 1654,  // 不允许取消起始天赋点
	ERROR_FORBID_CANCEL_MIDDLE_TALENT = 1655, // 不允许取消中间点
	ERROR_ACHIEVE_MAX_TALENT = 1656,		  // 本重天赋点数已达上限
	//
	// Holiday Error 1700 - 1799
	//
	ERROR_HOLIDAY_NOT_EXIST = 1700,						  // 该活动已不存在
	ERROR_HOLIDAY_NOT_OPEN = 1701,						  // 该活动未开启
	ERROR_HOLIDAY_WROLD_LIMIT = 1702,					  // 全服剩余可获取次数不足
	ERROR_HOLIDAY_SELF_LIMIT = 1703,					  // 你的剩余可获取次数不足
	ERROR_HOLIDAY_NOT_FIRST_CITY_MASTER = 1704,			  // 你不是首届城主！
	ERROR_HOLIDAY_XYZP_RECHARGE = 1705,					  // 充值不足，无法开启
	ERROR_HOLIDAY_XYZP_LCQ = 1706,						  // 龙城券不足!
	ERROR_HOLIDAY_XYZP_BYQ = 1707,						  // 霸业券不足！
	ERROR_HOLIDAY_IS_END = 1708,						  // 活动已结束
	ERROR_HOLIDAY_INVALID_SWITCH_ID = 1709,				  // 无效的活动id
	ERROR_HOLIDAY_TIME_ERROR = 1710,					  // 时间错误
	ERROR_HOLIDAY_KFYZ_STATE = 1711,					  // 跨服远征不能关闭开启
	ERROR_HOLIDAY_INVALID_PROP_VALUE = 1712,			  // 无效的活动属性值
	ERROR_HOLIDAY_RANK_CANNOT_RESET = 1713,				  // 排行榜不能重置
	ERROR_HOLIDAY_REBATE_SHOP_RESET = 1714,				  // 折扣商店必须设置重置
	ERROR_HOLIDAY_GRADE_INDEX_NOT_CONTINUITY = 1715,	  // 普通档次序号没连续
	ERROR_HOLIDAY_GRADE_EXA_INDEX_NOT_CONTINUITY = 1716,  // 扩展档次序号没连续
	ERROR_HOLIDAY_INVALID_GRADE_INDEX = 1717,			  // 无效的档次序号
	ERROR_HOLIDAY_INVALID_GRADE_PROP_VALUE = 1718,		  // 无效的活动档次属性值
	ERROR_HOLIDAY_GRADE_ITEM_INDEX_NOT_CONTINUITY = 1719, // 档次奖励物品序号没连续
	ERROR_HOLIDAY_GRADE_ITEM_INVALID_TYPE = 1720,		  // 无效的档次奖励物品类型
	ERROR_HOLIDAY_GRADE_ITEM_INVALID_ID = 1721,			  // 无效的档次奖励物品ID
	ERROR_HOLIDAY_GRADE_ITEM_INVALID_COUNT = 1722,		  // 无效的档次奖励物品数量
	ERROR_HOLIDAY_GRADE_ITEM_INVALID_BIND = 1723,		  // 无效的档次奖励物品绑定
	ERROR_HOLIDAY_GRADE_ITEM_INVALID_PROP_VALUE = 1724,	  // 无效的档次奖励物品属性值
	ERROR_HOLIDAY_NOT_ALLOW_OPEN_MULT = 1725,			  // 该活动不允许多开
	ERROR_HOLIDAY_INVALILD_TIME = 1726,					  // 活动时间配置错误
	ERROR_HOLIDAY_INVALILD_SERVER_TIME = 1727,			  // 开服活动时间配置错误
	ERROR_HOLIDAY_INVALILD_HEFU_TIME = 1728,			  // 合服活动时间配置错误

	//
	//	Paper Error 1790 - 1820
	//
	ERROR_PAPER_ACTIVE_CONSUME_COLOR = 1790,	 // 符文激活消耗品阶配置错误
	ERROR_PAPER_ACTIVE_CONSUME_NOTENOUGH = 1791, // 符文激活消耗不足
	ERROR_PAPER_ACTIVE_CONFIG = 1792,			 // 符文道具配置错误
	ERROR_PAPER_ACTIVE_CONSUME_VALUE = 1793,	 // 符文激活消耗数量配置错误
	ERROR_PAPER_ALREADY_ACTIVED = 1801,			 // 改符文装备的该属性已经全部激活
	ERROR_PAPER_ACTIVED_FAILD_LUA = 1803,		 // 改符文装备的该属性LUA激活失败

	ERROR_PAPER_EXCHANGE_FAILD_DIFCOLOR = 1804,	  // 交换符文道具的品阶不同
	ERROR_PAPER_EXCHANGE_FAILD_NOT_ENOUGH = 1805, // 交换符文道具的消耗不够
	ERROR_PAPER_EXCHANGE_FAILD_REPEATTYPE = 1806, // 交换符文道具的极品属性类型重复

	ERROR_PAPER_RECYCLE_FAILD_REPEATTYPE = 1807,  // 回收符文道具消耗不足
	ERROR_PAPER_RECYCLE_FAILD_SERVERDAY = 1808,	  // 回收符文开服时间配置不对
	ERROR_PAPER_RECYCLE_FAILD_POWERADD = 1809,	  // 回收符文可增加战力
	ERROR_PAPER_RECYCLE_FAILD_REBORNLEVEL = 1810, // 回收符文转生等级高

	ERROR_GHOST_STONE_NOT_ENOUGH = 1810, // 魂石精华不足

	//
	ERROR_FULING_LEVEL_MAX = 1815, // 附灵达到上限
	ERROR_FULINGZY_NOEXP = 1816,   // 该装备我附灵值

	// SoulSystem Error  1900 - 1920
	ERROR_SOUL_NOT_ENOUGH = 1900,	  // 魂力不足, 无法炼魂
	ERROR_SOUL_LEVLE_MAX = 1901,	  // 满阶满级
	ERROR_SOUL_LEVLE_NOT_MEET = 1902, // 等级不足,无法兑换
	ERROR_SOULVALUE_MAX = 1903,		  // 魂力值已满

	ERROR_MAX_LEVEL = 1930, // 已满级
	// 3v3  1950 - 2000
	ERROR_IS_MATCHING = 1950,			 // 已处于匹配状态
	ERROR_ONLY_LEADER_CAN_MATCH = 1951,	 // 只有队长才有权限匹配
	ERROR_TO_MANY_PLAYER = 1952,		 // 最多只能3人
	ERROR_SOMEONE_OFFLINE = 1953,		 // 所有队员必须在线
	ERROR_NEED_TEAM = 1954,				 // 请先组队
	ERROR_NEED_QUIT_TEAM = 1955,		 // 请先退出队伍
	ERROR_SCORE_DIFFER_MUCH = 1956,		 // 段位相差太多
	ERROR_IN_MATCHING = 1957,			 // 玩家处于匹配中，无法进行该操作
	ERROR_TARGET_IN_MATCHING = 1958,	 // 目标玩家处于匹配中，无法进行该操作
	ERROR_SOMEONE_LVL_NOT_ENOUGH = 1959, // 队伍中有人等级不足
	ERROR_SOMEONE_NO_ENTRIES = 1960,	 // 队伍中有人没有可用次数
	ERROR_NO_ENTRIES = 1961,			 // 没有可用次数
	ERROR_KFJJ_NOT_ENOUGH_LVL = 1962,	 // 跨服竞技参与等级不够

	//
	//	Skill Error 2001 - 2100
	//
	ERROR_SKILL_ONLY_MAIN_POSITION = 2001, // 普攻技能只能放到主技能位
	ERROR_SKILL_HAVE_MAX_LEVEL = 2002,	   // 已经升级到最大等级
	ERROR_SKILL_CANNOT_ON_POSITION = 2003, // 护体神盾不能装到技能位上
	ERROR_SKILL_NOT_STUDY = 2004,		   // 该技能还未学习
	ERROR_SKILL_HAVE_AWAKE = 2005,		   // 该技能已经觉醒过了
	ERROR_SKILL_NOT_ENOUGH_SOURCE = 2006,  // 技能升级点不够

	//
	// ZHANDUI Error 2201 - 2300
	//
	ERROR_ZHANDUI_NAME_EMPTY = 2201,		// 战队名称不能为空
	ERROR_ZHANDUI_NAME_EXIST = 2202,		// 战队名称已经被使用
	ERROR_ZHANDUI_NAME_TOO_LONG = 2203,		// 战队名称太长
	ERROR_ZHANDUI_NOT_EXIST = 2204,			// 战队不存在
	ERROR_ZHANDUI_HAS_JOINED = 2205,		// 已经加入战队
	ERROR_ZHANDUI_NOT_JOINED = 2206,		// 未加入战队
	ERROR_ZHANDUI_AUTHORITY = 2207,			// 你没有权限执行该操作
	ERROR_ZHANDUI_KICK_SELF = 2208,			// 不能踢除自己
	ERROR_ZHANDUI_MEMBER_NOENT = 2209,		// 不是此战队队员
	ERROR_ZHANDUI_MEMBER_FULL = 2210,		// 战队人数已满
	ERROR_ZHANDUI_QUIT_CD = 2211,			// 玩家退出/解散战队后，再次加入新战队需要等待3小时
	ERROR_ZHANDUI_APP_EXIST = 2212,			// 重复申请
	ERROR_ZHANDUI_APP_NOENT = 2213,			// 该申请不存在
	ERROR_ZHANDUI_APP_MAX = 2214,			// 申请数量达到上限
	ERROR_ZHANDUI_APP_PENDING = 2215,		// 请求已经发送，等待回复
	ERROR_ZHANDUI_CANNOT_QUIT_IN_KF3V3 = 2216,			// 战队赛晋级赛期间无法退出战队！
	ERROR_ZHANDUI_CANNOT_REMOVE_MEMBER_IN_KF3V3 = 2217,	// 战队赛晋级赛期间无法踢出队员！
	ERROR_ZHANDUI_CREATE_NOT_ENOUGH_REBORN	= 2218,		// 3转才能创建战队
	ERROR_ZHANDUI_CANNOT_JOIN_IN_KF3V3 = 2219,			// 战队赛晋级赛期间无法加入战队！
	ERROR_ZHANDUI_CANNOT_SET_MASTER_IN_KF3V3 = 2220,	// 战队赛晋级赛期间无法转让队长！
	ERROR_ZHANDUI_CANNOT_QUIT_IN_CSMAP = 2221,			// 战队赛淘汰赛期间在跨服场景无法退出战队！
	ERROR_ZHANDUI_CANNOT_REMOVE_MEMBER_IN_CSMAP = 2222,	// 战队赛淘汰赛期间在跨服场景无法踢出队员！
	ERROR_ZHANDUI_CANNOT_CREATE_IN_KF3V3 = 2223,		// 战队赛晋级赛期间无法创建战队！

	ERROR_KF3V3_NO_COMPETITION = 2301,		// 活动未开启
	ERROR_KF3V3_NOT_REGISTERING_TIME = 2302,// 非报名时段
	ERROR_KF3V3_ALREADY_REGISTERED = 2303,	// 已经报名
	ERROR_KF3V3_NOT_REGISTERED = 2304,		// 未报名
	ERROR_KF3V3_CANNOT_JINJI = 2305,		// 未获得参与晋级赛的资格！
	ERROR_KF3V3_ONLY_MASTER_CAN_REGISTER = 2306,	// 只有会长能报名
	ERROR_KF3V3_CANNOT_USE_SKILL = 2307,	// 准备阶段不是使用技能

	//
	// ScriptErrorCode 10000 - 19999
	//
	ERROR_GUILD_NOT_IN_HHMNHS = 10000,
	ERROR_GUILD_GIRL_NOT_REACH = 10001,
	ERROR_GUILD_HHMNHS_IS_OPEN = 10002,
	ERROR_INVALID_GUILD_BUILD_ID = 10010,
	ERROR_GUILD_IS_BUILDING = 10011,
	ERROR_GUILD_BUILD_NOT_OPEN = 10012,
	ERROR_GUILD_BUILD_LEVEL_MAX = 10013,
	ERROR_GUILD_NOT_ENOUGH_MONEY = 10014,
	ERROR_GUILD_HAS_APPLY_GCZ = 10015,
	ERROR_GUILD_PRAY_BUY_MAX = 10018,
	ERROR_LEVEL_NOT_ENOUGH_40 = 10100,
	ERROR_LEVEL_NOT_ENOUGH_42 = 10101,
	ERROR_LEVEL_NOT_ENOUGH_44 = 10102,
	ERROR_LEVEL_NOT_ENOUGH_46 = 10103,
	ERROR_LEVEL_NOT_ENOUGH_48 = 10104,
	ERROR_LEVEL_NOT_ENOUGH_49 = 10105,
	ERROR_LEVEL_NOT_ENOUGH_50 = 10106,
	ERROR_PLAYER_STATE_GOOD = 11001,
	ERROR_ITEM_REPAIR_SOME = 11002,
	ERROR_NEED_USE_IT = 11003,
	ERROR_HAS_GET_GOLD_BOWL = 11010,
	ERROR_BOWL_NO_NEED_REMOVE = 11011,
	ERROR_GOLD_BOWL_TODAY_HAS_GET = 11012,
	ERROR_XYCM_GUARD_MAX = 11013,	// 降妖除魔守卫数已达到上限
	ERROR_XYCM_GUARD_EXIST = 11014, // 同一地点只能放一个守卫
	ERROR_HUANJING_TIME_NOT_ENOUGH = 11015, // 幻境时间不足，无法进入
	ERROR_HUANJING_REACH_MAX_TIME = 11016, // 幻境时间已达上限

	ERROR_PENDING = 11111, // 操作未立即完成，请等待

	// 饰品重铸
	ERROR_REFORGE_ITEM_LIMIT_RESTRICT = 11150, // 该道具不符合可重铸的条件
	ERROR_REFORGE_ITEM_LEVEL_MIN = 11151,	   // 该道具等级太低
	ERROR_REFORGE_ITEM_LEVEL_MAX = 11152,	   // 该道具等级太高
	ERROR_REFORGE_ITEM_LACKINFO = 11153,	   // 该道具重铸信息错误

	ERROR_TAO_WEAP_UPDATA_LOST = 13001, // 法器提升失败
	ERROR_TAO_WEAP_U_LV_MAX = 13002,	// 法器已经升级最大
	ERROR_TAO_WEAP_SEC_SKILL = 13003,	// 三阶开放技能槽
	ERROR_TAO_WEAP_SIX_SKILL = 13004,	// 六阶开放技能槽
	ERROR_TAO_WEAP_NIN_SKILL = 13005,	// 九阶开放技能槽
	ERROR_TAO_WEAP_UN_SKILL = 13006,	// 法器等级不够，不能学习此技能书

	ERROR_WING_UPDATA_LOST = 14001, // 翅膀升级失败
	ERROR_WING_MAX = 14002,			// 翅膀升到顶级
	ERROR_WING_ITEM_NO = 14003,		// 物品数量不足

	ERROR_BSSC_NO_COUNT = 15001,				  // bs积分不足
	ERROR_BSSC_MAX_LV = 15002,					  // bs已满级
	ERROR_BSSC_LV_NO = 15003,					  // 兑换等级不满足
	ERROR_BSSC_NO_CION = 15004,					  // 没有金币bos
	ERROR_BSSC_LV_MAX = 15005,					  // 升级过大
	ERROR_AUTO_LIMLT = 15006,					  // 不满足条件
	ERROR_COIN_MAX = 15007,						  // 金币满了
	ERROR_BOUND_COIN_MAX = 15008,				  // 绑金满了
	ERROR_NO_WEARING_WEAPON = 15009,			  // 未穿戴武器
	ERROR_CHANNEL_CREATE_PLAYER_DISABLED = 15010, // 当前渠道禁止创建角色
	ERROR_ZHUFU_ISFULL = 15011,					  // 祝福值满了

	ERROR_HERO_REBORN_MAX = 15012, // 英雄转生等级已经达到上限

	ERROR_HERO_VITAL_QI_NOT_ENOUGH = 15013, // 英雄真气不足
	ERROR_UPGRADE_MERIDIAN_FAILED = 15014,	// 英雄升级经脉失败
	ERROR_MERIDIAN_MAX = 15015,				// 英雄升级经脉满级

	ERROR_PRIORITY_KILL_BOSS = 15016,		 // 先击杀BOSS
	ERROR_IS_IN_GUILD_INSTANCE = 15017,		 // 已经在公会BOSS副本中
	ERROR_NOT_ENTER_IN_DEAD_STATE = 15018,	 // 死亡状态无法进入
	ERROR_GUILD_TEAM_SPEAK_TOO_FAST = 15019, // 公会队伍发送邀请
	ERROR_NOT_GET_IN_DEAD_STATE = 15020,	 // 死亡状态无法领取
	ERROR_PRIVATE_DART_HAS_MAX = 15021,		 // 个人押镖已达最大值

	ERROR_PRIVATE_CURR_SKILL_NOT_USE = 15022, // 当前技能不能释放

	ERROR_SKILLBOOK_NO_USE = 15023,		  // 升级使用的技能书不正确
	ERROR_SKILL_NO_OPEN = 15024,		  // 技能没有学习
	ERROR_SKILL_LV_MAX = 15025,			  // 技能满级了
	ERROR_HIGHER_LEASE_EXISIT = 15026,	  // 已经租赁更高等级的神兵
	ERROR_HERO_NOT_ENOUGH_LEVEL = 15027,  // 英雄等级不足
	ERROR_HERO_NOT_ENOUGH_REBORN = 15028, // 英雄转生不足

	ERROR_NATIONAL_GUESS_NUM_IS_BIG = 15029, // 活动数据过大

	ERROR_PRIVILEGE_TIMEOVER = 15030,			// 该特权已经到期
	ERROR_GET_GIFT_QMJC_SUCCESS = 15031,		// 全民竞猜
	ERROR_BUY_TIMES_MAX = 15032,				// 购买次数上限制
	ERROR_NOT_FORGE_ENOUGH_ITEM = 15033,		// 公会装备合成道具不足
	ERROR_ITEM_USE_NOT_TYPE = 15034,			// 英雄和人物性别都不符
	ERROR_NOT_ENOUGH_GATHER_ITEM = 15035,		// 没有足够的宝箱
	ERROR_TEAM_ONLY_ONE = 15036,				// 队伍里面只有你一人
	ERROR_GUILD_POST_NOT_ENOUGH = 15037,		// 公会职位不满足
	ERROR_HERO_CC_SAME_CLASS = 15038,			// 已经是相同职业
	ERROR_REMOULD_MAX = 15039,					// 已经改造最大次
	ERROR_NOT_ENOUGH_ACHIEVE_SCORE = 15040,		// 成就积分不足
	ERROR_HERO_NOT_HERO = 15041,				// 没有英雄
	ERROR_SKILLBOOK_SPECIAL_RING = 15050,		// 特戒激活
	ERROR_FOR_BAIL = 15051,						// 红名保释报错
	ERROR_PRIVILEGE_NOT_GET = 15052,			// 提示特权不足，导致次数不够
	ERROR_VIP_NOT_GET = 15053,					// 提示VIP 不足，导致次数不够
	ERROR_ACTIVIE_HAS_CLOSE = 15054,			// 活动已经结束
	ERROR_NO_NEED_BUY = 15055,					// 无需购买
	ERROR_BOUND_COIN_OVERLIMIT = 15056,			// 绑金超过上限
	ERROR_MINIE_OVERLIMIT = 15057,				// 矿石超过上限
	ERROR_BOUUNDINGOT_OVERLIMIT = 15058,		// 绑元超过上限
	ERROR_BOSSSCORE_OVERLIMIT = 15059,			// boss积分超过上限
	ERROR_CLOUD_SHOPPING_LIMIT_BUY = 15061,		// 限购
	ERROR_CLOUD_SHOPPING_TOP_LIMIT_BUY = 15062, // 全服限购
	ERROR_NOT_ENOUGH_BUYDRAW_COUNT = 15063,		// 没有足够的抢购抽奖次数
	ERROR_NOT_HAS_REBATE = 15064,				// 请先抽取折扣券
	ERROR_HAS_BUY_THIS_ITEM = 15065,			// 已经购买过该道具
	ERROR_NO_LEFT_TIMES = 15066,				// 购买次数不足，无法刷新

	ERROR_ITEM_NOT_ENOUGH_REBORN = 15070, // 物品转生等级不足

	ERROR_CREATE_PLAYER_NEED_CODE = 15073,		// 当前服务创建角色需要激活码
	ERROR_CREATE_PLAYER_CODE_NO = 15074,		// 邀请码错误
	ERROR_CREATE_PLAYER_CODE_USED = 15075,		// 邀请码已使用
	ERROR_CREATE_PLAYER_CODE_NO_USE = 15076,	// 生成的邀请码未使用
	ERROR_CREATE_PLAYER_CODE_NO_ENOUGH = 15077, // 您已经不能再申请激活码了

	ERROR_CREATE_CROSS_PLAYER_FULL = 15078, // 当前跨服场景人数已满
	ERROR_CREATE_CROSS_NO_SCENE = 15079,	// 跨服没有当前场景
	ERROR_MAIL_SUCCESS = 15080,				// 跨服邮件错误码  有跨服邮件
	ERROR_MAIL_NO = 15081,					// 跨服邮件错误码  没有跨服邮件
	ERROR_MOSHI_7_DAYS = 15082,				// 开服7天或者合服后，且等级达到80级开启魔装功能

	ERROR_NOT_ENOUGH_GUILDCOIN = 15083, // 公会币不足
	ERROR_GUILDCOIN_MAX = 15084,		// 公会币上限

	ERROR_USE_INGOT_MAX = 15085,	   // 元宝使用达上限
	ERROR_SPECIAL_CANNOT_SELL = 15086, // 扶持号不能寄售行出售物品

	ERROR_ENOUGH_STONE = 15087, // 一键穿魂石没有操作

	ERROR_MAKESUCCESS = 15088,		 // 魂石合成
	ERROR_GODOREDERlEVEL = 15089,	 // 突破条件未满足
	ERROR_SEPEQUIP_LEVEL = 15090,	 // 当前分身阶数无法穿戴此装备，请提升分身阶数
	ERROR_SEPEQUIP_TOPLEVEL = 15091, // 当前分身已提升至最高阶，无法穿戴更高等级装备
	ERROR_CAN_NOT_USE_ITEM = 15092,	 // 物品使用条件不满足

	ERROR_NOT_TARGET = 15093,					   // 请选择私聊对象
	ERROR_NOT_ENOUGH_VIP_LEVEL_SHOP = 15094,	   // 商城购买VIP等级不够
	ERROR_RRCHARGE_EQUIP_LEVLE_UP_SUCCESS = 15095, // 首充装备升级成功
	ERROR_EQUIP_MAX_LEVEL = 15096,				   // 装备已达到最大级
	ERROR_DAILY_GIFT_CAN_BUY = 15097,			   // 日常礼包可以购买
	ERROR_DAILY_GIFT_BOUGHT = 15098,			   // 当日该档礼包已经买完了
	ERROR_THINGS_IN_MAIL = 15099,				   // 背包已满，请至邮箱查收
	ERROE_SIGNIN_CANNOT = 15100,				   // 当前不能签到
	ERROR_RANDOM_GOHOME_IN_CD = 15101,			   // 回城冷却中
	ERROR_ATTENTION_MAX = 15102,				   // 关注数量已达上限
	ERROR_AUCTION_ITEM_IN_CD = 15103,			   // 物品冷却中
	ERROR_GUILD_DENOTE_NOTADD_MONEY = 15104,	   // 捐献次数已达上限，本次捐献只获得贡献
	ERROR_AUCTION_PRICE_MAX = 15105,			   // 您当前出价最高
	ERROR_GUARD_MAX = 15106,					   // 守卫已达最大值
	ERROR_FIRE_RAIN_CD = 15107,					   // 火雨cd
	ERROR_ALREADY_IS_MEMBER = 15108,			   // 已经是会员
	ERROR_NEED_BAOBAO_GOT = 15109,				   // 需要先获得宝宝
	ERROR_ALREADY_GOT_SKIN = 15110,				   // 已获得当前皮肤
	ERROR_DABAO_NOT_OPEN = 15111,				   // 大爆未开启
	ERROR_WARZONE_NOT_ALLOW_CHAT = 15112,		   // 战区不能聊天
	ERROR_REFUSE_GUILD_INVITE = 15113,			   // 对方拒绝公会邀请
	ERROR_REFUSE_PRIVATE_CHAT = 15114,			   // 对方拒绝私聊消息
	ERROR_BUY_REWARD_MAX = 15115,				   // 已达到最大购买次数
	ERROR_EXP_CANNOT_GET = 15116,				   // 历练之路条件不满足
	ERROR_NEED_FIRSTRECHARGE = 15117,			   // 需要首充

	ERROR_MINER_UP_FAILED = 15118,			 // 升级矿工失败
	ERROR_ALREADY_GOT_PET = 15119,			 // 已获得当前宝宝
	ERROR_NO_PLAYER_INFO = 15120,			 // 挑战或查看的数据不存在
	ERROR_ROBBED_ING = 15121,				 // 该玩家在挑战中
	ERROR_WARZONE_SVR_NOT_START = 15122,	 // 战区服务器没有启动
	ERROR_NO_CHANLLENG_TIME = 15123,		 // 剩余挑战次数不足
	ERROR_CANT_FIGHT_TOO_HEIGH = 15124,		 // 不能挑战超高层的玩家
	ERROR_NOT_START = 15125,				 // 活动未开启
	ERROR_SPECIAL_STONE_LEVEL_ERROR = 15126, // 超级魂石的等级不能高于此装备位普通魂石的最低等级
	ERROR_NORMAL_STONE_LEVEL_ERROR = 15127,	 // 普通魂石的等级不能低于此装备位超级魂石的最高等级
	ERROR_CSZT_BUY_MAX_OVER = 15128,		 // 传说之塔每日购买超过超过上限
	ERROR_SDKB_EXIST = 15129,				 // 嗜血狂暴已存在
	ERROR_XSKB_EXIST = 15130,				 // 限时狂暴已存在
	ERROR_TIME_NOT_ALLOW = 15131,			 // 当前时间不可操作
	ERROR_SHENLONG_UPlEVEL_FAIL = 15132,	 // 神龙升级失败
	ERROR_TQLS_CONDITION_LIMIT = 15133,		 // 条件不满足
	ERROR_TQLS_REWARD_GOT = 15134,			 // 奖励已领完
	ERROR_ATTACK_LOSE_EFFICACY = 15135,		 // 攻击已失效
	ERROR_NOT_TEAM_MEMBER = 15136,			 // 不是队伍成员
	ERROR_HAS_FASHION_CLOTH = 15137,		 // 已拥有当前时装
	ERROR_HAS_FASHION_WEAPON = 15138,		 // 已拥有当前幻武
	ERROR_HAS_FASHION_TITLE = 15139,		 // 已拥有当前称号
	ERROR_TRAININGROOM_NO_REWARD = 15140,	 // 练功房没有奖励
	ERROR_IN_LIMIT_MAP = 15141,				 // 在限制地图中
	ERROR_NOT_VIP_MEMBER = 15142,			 // 不是会员
	ERROR_CANNOT_BUY_REPEAT = 15143,		 // 不能重复购买
	ERROR_CANNOT_CHAT_PRIVATE = 15144,		 // 不能私聊
	ERROR_SELF_BE_ROBBED_ING = 15145,		 // 自己正在被别人挑战

	// 拍卖行   15150 ~ 15250
	ERROR_ACUTION_ALREADY_SELLED = 15150,	  // 该物品已被其他玩家拍下
	ERROR_ACUTION_NOT_EXIST = 15151,		  // 该物品不存在
	ERROR_ACUTION_NOT_IN_ONWER_GUILD = 15152, // 该物品属于其他工会，你无权竞拍
	ERROR_ACUTION_TRY_LATER = 15153,		  // 请稍后再试
	ERROR_CUR_PRICE_CHANGED = 15154,		  // 当前价格发生变化
	ERROR_PURCHASE_INVAILD = 15155,			  // 当前求购已失效

	// 寄售行
	ERROR_CONSIGNMENT_QUOTA_SELL = 15161, // 出售限制
	ERROR_CONSIGNMENT_QUOTA_BUY = 15162,  // 购买限制

	ERROR_ACUTION_END = 15250,

	ERROR_THUNDER_NOT_OPEN = 15251,				  // 雷霆装备系统尚未开启
	ERROR_SHENYU_NOT_OPEN = 15252,				  // 神域装备系统尚未开启
	ERROR_DIAMOND_RECOVRER_MAX = 15253,			  // 钻石回收达到最大回收数量
	ERROR_TIME_OVER = 15254,					  // 不在活动时间内
	ERROR_CSZT_CANT_BUY = 15255,				  // 购买失败
	ERROR_NOT_ENOUGH_KB_RECHARGE_DIAMOND = 15256, // 充值钻石不足
	ERROR_OFFLINE_OR_NOT_SAME_SERVER = 15257,	  // 不是本服玩家或者玩家不在线
	ERROR_BUY_DAILY_LIMIT_COUNT_LIMIT = 15258,	  // 每日限购数量不足
	ERROR_BUY_FOERVER_LIMIT_COUNT_LIMIT = 15259,  // 永久限购数量不足
	ERROR_TRADE_NOT_OPEN = 15260,				  // 交易未开启
	ERROR_OTHER_TRADE_NOT_OPEN = 15261,			  // 对方交易未开启
	ERROR_NO_PIGS = 15262,						  // 石墓中没有猪
	ERROR_NOT_INT_MINING_POS = 15263,			  // 不在矿点
	ERROR_MINGING_POS_IS_BUSY = 15264,			  // 矿点有人

	ERROR_BAYE_NOT_OPEN = 15265,  // 霸业装备系统尚未开启
	ERROR_REXUE_NOT_OPEN = 15266, // 热血装备系统尚未开启
	ERROR_ITEM_SHOW_ONLY = 15267,
	ERROR_CANT_BUY_REWARD = 15268,		 // 不能购买
	ERROR_PLAYER_EXP_NOT_ENOUGH = 15269, // 玩家经验不足

	ERROR_SKILL_EXP_ENOUGH = 15269, // 技能经验已满

	ERROR_SKILL_LVL_NOT_ENOUGH = 15270, // 技能等级不足

	ERROR_MINE_IN_PROGRESS = 15271,				  // 正在挖矿中
	ERROR_MINE_STAMINA_NOT_ENOUGH = 15272,		  // 体力不足
	ERROR_MINE_PROTECT = 15273,					  // 挖矿保护中
	ERROR_MINE_ROBBING = 15274,					  // 正被他人掠夺
	ERROR_MINE_STOP = 15275,					  // 对方已停止挖矿
	ERROR_MINE_NONE_GRAIN = 15276,				  // 矿工口粮已用尽
	ERROR_MINE_STAMINA_FULL = 15277,			  // 体力已满
	ERROR_MINE_LODE_FULL = 15278,				  // 此种矿脉已无空位
	ERROR_MINE_CHANGE_HANDS = 15279,			  // 矿脉易主，无法夺回
	ERROR_JQBG_USED = 15280,					  // 今日已参加过激情闭关
	ERROR_UNUSE_SUNWATER = 15281,				  // 无法使用太阳水
	ERROR_CANT_TRANSFER = 15282,				  // 处于活动内，无法传送
	ERROR_GUILD_ONLY_ONE = 15283,				  // 公会只有一个人
	ERROR_GUILD_NO_GUILD1 = 15284,				  // 你目前没有公会
	ERROR_ZHAOJI_SCENE_NOT_EXIST = 15285,		  // 召集令传送的场景不存在
	ERROR_DAZE_UNABLE_FLY = 15286,				  // 麻痹定身状态不能传送
	ERROR_PEAK_MAP_NOT_OPEN = 15287,			  // 巅峰地图未开放
	ERROR_MC_TAST_FINISHED = 15288,				  // 萌宠任务已完成
	ERROR_DAZE_UNABLE_USE = 15289,				  // 麻痹状态不能使用道具
	ERROR_XMHJ_MONSTER_MAX = 15290,				  // 心魔幻境怪达到上限
	ERROR_LUCKY_COMPASS_SCORE_NOT_ENOUGH = 15291, // 神运值不足
	ERROR_SHEZHU_IS_STARTED = 15292,			  // 神柱活动中，无法捐献
	ERROR_WORSHIP_MAX = 15293,					  // 今日膜拜次数已用完
	ERROR_WORSHIP_LEVEL_MAX = 15294,			  // 已刷新到超级奖励
	ERROR_WORSHIP_REFRESH_FAILD = 15295,		  // 膜拜刷新失败
	ERROR_FIRE_NO_TIME = 15296,					  // 不在捐献时间
	ERROR_WORSHIP_REFRESH_SUCCESS = 15297,		  // 膜拜刷新成功
	ERROR_WORSHIP_SUCCESS = 15298,				  // 膜拜成功
	ERROR_SHENQIZHONG_JINBI_MAX = 15299,		  // 今日神器冢金币膜拜次数已用完
	ERROR_SHENQIZHONG_LINGFU_MAX = 15300,		  // 今日神器冢灵符膜拜次数已用完
	ERROR_SHENQIZHONG_NO_TIME = 15301,			  // 不在膜拜时间
	ERROR_ZANZHU_ONBUY_ORDER = 15302,			  // 赞助按照顺序进行购买
	ERROR_ZANZHU_NOT_PERMISSION = 15303,		  // 无赞助权限
	ERROR_DIVINE_HOLY_LEVEL_MAX = 15304,		  // 神圣剑甲满级
	ERROR_DIVINE_HOLY_UPGRADE_SUCCESS = 15305,	  // 神圣剑甲升级成功
	ERROR_DIVINE_HOLY_UPGRADE_FAIL = 15306,		  // 神圣剑甲升级失败

	// shop error code
	ERROR_SHOP_ITEM_NOT_PUTAWAY = 15307,		// 商城商品未上架
	ERROR_SHOP_ITEM_SOLD_OUT = 15308,			// 商城商品已下架
	ERROR_SHOP_LEVELE_NOT_ENOUGH = 15309,		// 商城购买等级不足
	ERROR_SHOP_REBORN_LEVEL_NOT_ENOUGH = 15400, // 商城购买转生等级不足
	ERROR_SHOP_ITEM_NOT_ENOUGH = 15401,			// 商城购买道具不足
	ERROR_SHOP_CAPITAL_NOT_ENOUGH = 15402,		// 商城购买货币不足

	ERROR_OVER_MAX_LIMIT = 15450,			 // 超过最大限制数量
	ERROR_OVER_GUILD_OPERATOR_LIMIT = 15451, // 工会限时活动限制操作

	// chat error code
	ERROR_CHAT_FAIL = 15460,		 // 聊天
	ERROR_CHAT_PRIVATE_FAIL = 15461, // 私聊聊天
	ERROR_CHAT_ZHANQU_FAIL = 15460,	 // 跨服聊天

	ERROR_RENAME_IN_CD = 15461,			// 改名卡使用cd中
	ERROR_HORCRUXES_HAS_ACTIVE = 15462, // 魂器已激活

	ERROR_MURDEROUS_GAS_ZERO = 15463,	 // 杀气值为0， 无需使用血虫
	ERROR_FIND_NO_COUNT = 15464,		 // 寻宝次数不足
	ERROR_TURNTABLE_NOT_TIMES = 15465,	 // 转盘抽奖次数不足
	ERROR_HORCRUXES_HAS_MAX = 15466,	 // 魂器已升至满级
	ERROR_SHELL_UPGRADE_SUCCESS = 15467, // 纹章升级成功
	ERROR_SHELL_UPGRADE_FAIL = 15468,	 // 纹章升级失败

	ERROR_GOLDBAR_NOT_ENOUGH = 15470, // 金条不足

	ERROR_ZF_NOT_ENOUGH_INHERIT = 15471,  // 不满足传承条件
	ERROR_ZF_NOT_ENOUGH_ITEM = 15473,	  // 传承所需材料不足
	ERROR_ZF_NOT_ENOUGH_INCREASE = 15474, // 不满足增幅条件
	ERROR_ZF_NOT_BACK = 15475,			  // 增幅套装禁止回城
	ERROR_ZF_ERROR = 15476,				  // 操作异常

	ERROR_ZHUISHA_SCENE_NOT_EXIST = 15480, // 追杀令传送的场景不存在
	ERROR_ZHUISHA_ROLE_NOT_EXIST = 15481,  // 追杀令角色不存在场景中
	ERROR_ZHUISHA_MYSELF = 15482,		   // 追杀令自己
	ERROR_ZHUISHA_LEVEL_UNENOUGH = 15483,  // 追杀令等级不足
	ERROR_ZHUISHA_TARGET_DIED = 15484,	   // 目标玩家已死亡

	ERROR_HOLIDAY_MLGJ_CONDITION = 15485, // 猛龙过江未达到充值条件
	ERROR_HOLIDAY_MLGJ_RECHARGE = 15486,  // 猛龙过江充值次数不足
	ERROR_HOLIDAY_MLGJ_CONSUME = 15487,	  // 猛龙过江消费次数不足
	ERROR_HOLIDAY_MLGJ_LIMIT = 15488,	  // 猛龙过江当日抽奖次数不足

	ERROR_TREASURE_NO_GRADE = 15489,	  // 没有当前档位奖励
	ERROR_TREASURE_HAS_GOT = 15490,		  // 奖励已领取
	ERROR_EQUIP_PROTECT_MAX = 15491,	  // 担保超上限
	ERROR_EQUIP_PROTECT_INCREASE = 15492, // 投保不可增幅

	ERROR_DECLARE_NOT_MERGE = 15493,	// 宣战无法合并
	ERROR_DECLARE_NOT = 15494,			// 行会不存在无法宣战
	ERROR_DECLARE_ONLY_ONE = 15495,		// 每个行会只能同时发起一次宣战！
	ERROR_DECLARE_NO_TIMES = 15496,		// 今天宣战次数不足！
	ERROR_NOT_ENTER_BOOK_MAP = 15497,	// 图鉴地图无法传送
	ERROR_NOT_CONVENE_BOOK_MAP = 15498, // 图鉴地图无法召集

	ERROR_XUNZHANG_NOT_ACCEPT = 15499,		// 勋章任务 当前任务不可接取
	ERROR_XUNZHANG_NOT_FORGO = 15500,		// 勋章任务 没有可放弃的任务
	ERROR_XUNZHANG_CANNOT_FRESH = 15501,	// 勋章任务 请完成或放弃已接取的任务
	ERROR_XUNZHANG_CANNOT_COMPLETE = 15502, // 勋章任务 不满足领取条件
	ERROR_XUNZHANG_HAS_GETREWARD = 15503,	// 勋章任务 奖励已经领取
	ERROR_XUNZHANG_NOT_TIMES = 15504,		// 勋章任务 次数已用完

	ERROR_ITEMS_NOT_USETIMES = 15505,	// 物品使用次数上限
	ERROR_ITEMDRESS_HAS_ACTIVE = 15506, // 时装已激活
	ERROR_TRADE_NOT_ENOUGH_PRIVILEGE_SELF = 15507,  // 自己交易特权不够
	ERROR_TRADE_NOT_ENOUGH_PRIVILEGE_OTHER = 15508, // 对方交易特权不够
	ERROR_NOT_TRADECARD_PRIVILEGE = 15509, // 缺少交易卡特权

	ERROR_RONGLIAN_ITEM_BROKEN = 15510,			// 熔炼装备破损，无法熔炼
	ERROR_RONGLIAN_ITEM_REPAIR = 15511,			// 当前装备，无法修复
	ERROR_RONGLIAN_ITEM_MAX = 15512,			// 已达到最大熔炼等级
	ERROR_RONGLIAN_ITEM_CANNOT = 15513,			// 不可熔炼此装备
	ERROR_RONGLIAN_ITEM_NOENOUGH = 15514,		// 熔炼条件不满足
	ERROR_RONGLIAN_ITEM_WEAREQUIP = 15515,		// 穿戴装备不可进行此操作
	ERROR_RONGLIAN_ITEM_REPAIR_NOENOUGH = 15516,// 修复条件不满足
	ERROR_RONGLIAN_ITEM_BROKEN_SPLIT = 15516,	// 破损装备不可拆分
	ERROR_RONGLIAN_ITEM_CANNOT_SPLIT = 15517,	// 不可拆分
	ERROR_RONGLIAN_ITEM_SPLIT_NOENOUGH = 15518,	// 拆分条件不满足

	ERROR_ZANZHU_LV_NOT_ENOUGH = 15519,	// 赞助等级不足

	ERROR_WARZONE_NOT_CONFIG = 15520, // 本服未配置战区
};

enum EventRecordType
{
	RECORD_OP_NDNH_1 = 1,	// 六道轮回1层
	RECORD_OP_NDNH_2 = 2,	// 六道轮回2层 1
	RECORD_OP_NDNH_3 = 3,	// 六道轮回3层 1
	RECORD_OP_NDNH_4 = 4,	// 六道轮回4层 1
	RECORD_OP_NDNH_5 = 5,	// 六道轮回5层 1
	RECORD_OP_NDNH_6 = 6,	// 六道轮回6层 1
	RECORD_OP_NDNH_7 = 7,	// 六道轮回7层 1
	RECORD_OP_NDNH_8 = 8,	// 六道轮回8层 1
	RECORD_OP_NDNH_9 = 9,	// 六道轮回9层 1
	RECORD_OP_NDNH_10 = 10, // 六道轮回10层 1
	RECORD_OP_NDNH_11 = 11, // 六道轮回11层 1
	RECORD_OP_NDNH_12 = 12, // 六道轮回12层 1
	RECORD_OP_NDNH_13 = 13, // 六道轮回13层 1

	RECORD_OP_TJYB = 20, // 天降元宝
	RECORD_OP_TTSY = 21, // 饕餮盛宴 1
	RECORD_OP_CBTX = 22, // 称霸天下 1
	RECORD_OP_SBJY = 23, // 双倍经验
	RECORD_OP_SMZS = 24, // 生命之树
	RECORD_OP_GWGC = 25, // 怪物攻城
	RECORD_OP_DBQB = 26, // 夺宝奇兵 1
	RECORD_OP_YZLC = 27, // 夜战龙城 1
	RECORD_OP_MZRQ = 28, // 魔族入侵
	RECORD_OP_HYSD = 29, // 幻影神殿

	RECORD_OP_MYJZ = 40, // 玛雅教主 1
	RECORD_OP_YHJZ = 41, // 炎煌教主 1
	RECORD_OP_SYJZ = 42, // 噬月教主 1
	RECORD_OP_SYLZ = 43, // 深渊领主 1
	RECORD_OP_MRLZ = 44, // 末日领主 1
	RECORD_OP_CYML = 45, // 赤炎魔龙 1

	RECORD_OP_BZSD1 = 50, // 霸者神殿1 1
	RECORD_OP_BZSD2 = 51, // 霸者神殿2 1
	RECORD_OP_BZSD3 = 52, // 霸者神殿3 1
	RECORD_OP_BZSD4 = 53, // 霸者神殿3 1

	RECORD_OP_BSCX_1 = 60, // BOSS巢穴1 1
	RECORD_OP_BSCX_2 = 61, // BOSS巢穴2 1
	RECORD_OP_BSCX_3 = 62, // BOSS巢穴3 1

	RECORD_OP_ZSSD_1 = 70, // 转生神殿1 1
	RECORD_OP_ZSSD_2 = 71, // 转生神殿2 1
	RECORD_OP_ZSSD_3 = 72, // 转生神殿3 1
	RECORD_OP_ZSSD_4 = 73, // 转生神殿4 1

	RECORD_OP_ZSSD_5 = 74, // 转生神殿5 1
	RECORD_OP_ZSSD_6 = 75, // 转生神殿6 1
	RECORD_OP_ZSSD_7 = 76, // 转生神殿7 1
	RECORD_OP_ZSSD_8 = 77, // 转生神殿8 1

	RECORD_OP_WZSD = 80, // 未知神殿 1

	RECORD_OP_FMFX = 90, // 封魔废墟
	RECORD_OP_TKZC = 91, // 天空之城
	RECORD_OP_CMSD = 92, // 沉默神殿
	RECORD_OP_EMSD = 93, // 恶魔神殿
	RECORD_OP_CHMZ = 94, // 沧海明珠
	RECORD_OP_MRCM = 95, // 每日除魔

	RECORD_OP_SWLC = 96, // 守卫龙城

	RECORD_OP_LHMJ_1 = 97,	// 轮回秘境1
	RECORD_OP_LHMJ_2 = 98,	// 轮回秘境2
	RECORD_OP_LHMJ_3 = 99,	// 轮回秘境3
	RECORD_OP_LHMJ_4 = 100, // 轮回秘境4
	RECORD_OP_LHMJ_5 = 101, // 轮回秘境5
	RECORD_OP_LHMJ_6 = 102, // 轮回秘境6
	RECORD_OP_LHMJ_7 = 103, // 轮回秘境7
	RECORD_OP_LHMJ_8 = 104, // 轮回秘境8

	RECORD_OP_ZSMJ_1 = 105, // 转生秘境1
	RECORD_OP_ZSMJ_2 = 106, // 转生秘境2
	RECORD_OP_ZSMJ_3 = 107, // 转生秘境3
	RECORD_OP_ZSMJ_4 = 108, // 转生秘境4
	RECORD_OP_ZSMJ_5 = 109, // 转生秘境5
	RECORD_OP_ZSMJ_6 = 110, // 转生秘境6

	RECORD_OP_XFFB = 111, // 血符副本
	RECORD_OP_SDFB = 112, // 神盾副本

};

// 玩家不能召唤英雄错误列表
enum EnumPlayerSummonResult
{
	PLAYER_SUMMON_HERO_SUCCESS = 0,			// 可以召唤英雄
	PLAYER_SUMMON_HERO_ERROR_NOTPLAYER = 1, // 非玩家对象不能召唤英雄
	PLAYER_SUMMON_HERO_ERROR_REPEAT = 2,	// 已经召唤过英雄
	PLAYER_SUMMON_HERO_ERROR_GENDER = 3,	// 召唤的英雄职业或者性别不对
	PLAYER_SUMMON_HERO_ERROR_LEVEL = 4,		// 玩家等级不满足召唤英雄等级

	PLAYER_CHANGEAI_HERO_ERROR_STATE = 1, // 玩家英雄该状态不能切换状态
	PLAYER_CHANGEAI_HERO_ERROR_NULL = 2,  // 玩家英雄不存在

	PLAYER_SUMMON_HERO_ERROR_MAX, // 玩家不存在
};

// 触发buff类型
enum EntityTriggerType
{
	ENTITY_STATE_ATTACK = 1,   // 攻击
	ENTITY_STATE_ATTACKED = 2, // 被攻击
	ENTITY_STATE_DIE = 3,	   // 死亡时候检测
};

// 装备合成
enum ForceRule
{
	FORGE_RULE_LOW_LV = 10,		  // 60合成
	FORGE_RULE_LOW_LV_1 = 11,	  // 70合成
	FORGE_RULE_GOLD_HC = 20,	  // 神圣合成
	FORGE_RULE_LY_HC = 30,		  // 蓝月装备合成
	FORGE_RULE_LY_ITEM1 = 31,	  // 蓝月兑换（消耗装备+道具+元宝）
	FORGE_RULE_LY_ITEM2 = 32,	  // 蓝月兑换（道具+道具）
	FORGE_RULE_LY_SEX = 33,		  // 蓝月性别转换（装备+元宝）
	FORGE_RULE_MOSHI_ITEM = 34,	  // 魔饰合成
	FORGE_RULE_CS_EXC = 40,		  // 传世兑换（多个道具换一个）
	FORGE_RULE_LY_ITEM_COIN = 50, // 首饰兑换(多个道具 + 元宝)
	FORGE_RULE_LY_SPL = 100,	  // 蓝月拆分（装备+元宝拆分成装备+装备）
	FORGE_RULE_LY_ITEM = 110,	  // 蓝月拆分（装备+元宝拆分成装备+装备）
	FORGE_RULE_LY_CQTZ3 = 120,	  // 传奇套装三
};

// 饰品重铸类型
enum ItemReforgeType
{
	ItemReforgeTypeNormal = 1,	// 普通重铸
	ItemReforgeTypeSpecial = 2, // 特殊重铸
};

// 经验玉操作
enum ItemExpStoreOption
{
	ItemExpStoreOptionNormal = 1,	// 普通操作
	ItemExpStoreOptionDouble = 2,	// 双倍操作
	ItemExpStoreOptionOctuple = 3,	// 八倍操作
	ItemExpStoreOptionDOctuple = 4, // 十六倍操作
};

// 技能书兑换的等级
enum SkillBookExchangeType
{
	SkillBookExchangeTypeNormal = 1, // 普通
	SkillBookExchangeTypeBetter = 2, // 中级
	SkillBookExchangeTypeBest = 3,	 // 高级
};

// 技能等级
enum SkillLevelType
{
	SkillLevelTypeOne = 1,
	SkillLevelTypeTwo = 2,
	SkillLevelTypeThree = 3,
	SkillLevelTypeFour = 4,
	SkillLevelTypeFive = 5,
	SkillLevelTypeSix = 6,
	SkillLevelTypeSeven = 7,
	SkillLevelTypeEight = 8,
	SkillLevelTypeNine = 9,
};

// 跨服请求类型
enum CROSS_REQUEST_TYPE
{
	CROSS_REQUEST_TYPE_NULL = 0,
	CROSS_REQUEST_TYPE_APPLY = 1,  // 申请加入跨服玩法
	CROSS_REQUEST_TYPE_CANCEL = 2, // 取消跨服玩法
};

// 跨服请求类型
enum SCENE_LINE_RULE
{
	SCENE_LINE_RULE_FEW = 0,  // 优先选择人少的
	SCENE_LINE_RULE_MANY = 1, // 优先选择人多的
};

// 数值枚举
enum MagicNumber
{
	MagicNumber0 = 0,
	MagicNumber1 = 1,
	MagicNumber2 = 2,
	MagicNumber3 = 3,
	MagicNumber4 = 4,
	MagicNumber5 = 5,
	MagicNumber6 = 6,
	MagicNumber7 = 7,
	MagicNumber8 = 8,
	MagicNumber9 = 9,
	MagicNumber11 = 11,
	MagicNumber12 = 12,
};

// 全服播报的类型
enum BROADCAST_TYPE
{
	GENERAL_BROADCAST = 0, // 默认是跑马灯
	SPECIAL_BROADCAST = 1, // 目前是充值之后的提示（两侧挂着鞭炮的那种）
	POP_BROADCAST = 2,	   // 冒泡提示
	NOTOP_BROADCAST = 3,   // 只在聊天框中有提示
	KF3V3_BROADCAST = 4,
};

// 装备强化ENTITY_PROP_NOT_RECHARGE_VIP
enum STRENGTHEN_TYPE
{
	NORMAL_STRENGTHEN = 0, // 普通强化
	ONEKEY_STRENGTHEN = 1, // 一键强化
};

// 魂石类型 1- 6 普通魂石 7 - 8 特殊魂石
enum STONE_TYPE
{
	STONE_TYPE1 = 1,
	STONE_TYPE2 = 2,
	STONE_TYPE3 = 3,
	STONE_TYPE4 = 4,
	STONE_TYPE5 = 5,
	STONE_TYPE6 = 6,
	STONE_TYPE7 = 7,
	STONE_TYPE8 = 8,
};
enum SPIRIT_STONE_TYPE
{
	SPIRIT_STONE_TYPE_ALONE_WEAR = 0, // 单个魂石镶嵌
	SPIRIT_STONE_TYPE_ALONE_OFF = 1,  // 单个魂石摘除
	SPIRIT_STONE_TYPE_AUTO_WEAR = 2,  // 一键魂石镶嵌
	SPIRIT_STONE_TYPE_AUTO_OFF = 3,	  // 一键魂石摘除
};

enum GODSTOVE_TYPE
{
	GODSTOVE_TYPE_UPLEVEL = 1,		// 神炉升级
	GODSTOVE_TYPE_UPORDERLEVEL = 2, // 神炉突破
};

enum BAOBAOSKILL
{
	BB_SKILL_SMASH = 1,				  // 粉碎
	BB_SKILL_TEAR = 2,				  // 撕裂
	BB_SKILL_DOUBLE_HIY = 3,		  // 连击
	BB_SKILL_DRAGON_FEAR = 4,		  // 龙威
	BB_SKILL_PICK = 5,				  // 拾取
	BB_SKILL_BLESSING = 6,			  // 福泽
	BB_SKILL_QUICK = 7,				  // 迅捷
	BB_SKILL_LUCKY = 8,				  // 幸运
	BB_SKILL_BLESSED = 9,			  // 粉碎
	BB_SKILL_SUPER_PETRIFACTION = 10, // 超级石化
	BB_SKILL_SPEED = 11,			  // 神速
	BB_SKILL_MANYONG = 12,			  // 蛮勇
	BB_SKILL_INVINCIBLE = 13,		  // 不败
};

// 公会食堂领奖状态
enum GuildCanteenAwardType
{
	GUILD_CANTEENAWARD_NOTGET,	// 没有领取
	GUILD_CANTEENAWARD_YESTGET, // 已经领取
};

// 跨服的玩家行为
enum PlayerCrossActionType
{
	CROSS_ACTION_MONSTER_OWNER,			// boss归属
	CROSS_ACTION_MONSTER_LAST_ATTACKER, // boss最后一击
	CROSS_ACTION_KILL_PLAYER,			// 玩家击杀另一玩家
	CROSS_ACTION_BE_KILLED,				// 玩家被击杀
	CROSS_ACTION_BE_KILLED_KBZL,		// 玩家被击杀(击杀的有狂暴之力)
	CROSS_ACTION_KILL_PLAYER_KBZL,		// 玩家击杀另一玩家(被击杀的有狂暴之力)
	CROSS_ACTION_USE_ITEM,				// 用药，用回城石，等
	CROSS_ACTION_GOTO_MAP,				// 进入地图
	CROSS_ACTION_FAOBAO,				// 法宝相关
	CROSS_ACTION_CD_TIME,				// 写一个统一的 CD 同步方法
};

enum PlayerCrossActionIntParamType
{
	CROSS_ACTION_INT_PARAM_MONSTER_SID,		   // 怪物id
	CROSS_ACTION_INT_PARAM_SCENE_ID,		   // 场景id
	CROSS_ACTION_INT_PARAM_PID,				   // 玩家pid
	CROSS_ACTION_INT_PARAM_PLAYER_LEVEL,	   // 玩家等级
	CROSS_ACTION_INT_PARAM_PLAYER_FORCE,	   // 玩家战力
	CROSS_ACTION_INT_PARAM_KILLER_TYPE,		   // 击杀者类型
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_TYPE, // 归属类型
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID,  // boss归属者
	CROSS_ACTION_INT_PARAM_MONSTER_KILLER_PID, // boss击杀者

	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_1,	 // boss归属者1
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_2,	 // boss归属者2
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_3,	 // boss归属者3
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_4,	 // boss归属者4
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_5,	 // boss归属者5
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_6,	 // boss归属者6
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_7,	 // boss归属者7
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_8,	 // boss归属者8
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_9,	 // boss归属者9
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_10, // boss归属者10
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_11, // boss归属者11
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_12, // boss归属者12
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_13, // boss归属者13
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_14, // boss归属者14
	CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_15, // boss归属者15

	CROSS_ACTION_INT_PARAM_KBZL_DIAMOND,  // 击杀拥有狂暴之力的玩家可以获得的钻石
	CROSS_ACTION_INT_PARAM_KILLER_NAME,	  // 击杀者姓名
	CROSS_ACTION_INT_PARAM_BEKILLER_NAME, // 被击杀者姓名

	CROSS_ACTION_INT_PARAM_ITEM_SID,  //   使用物品的ID
	CROSS_ACTION_INT_PARAM_ITEM_PROP, //  使用物品对应的CD 值
	CROSS_ACTION_INT_PARAM_FABAO_CD,  // 法宝cd
	CROSS_ACTION_INT_PARAM_TIMECD_TYPE,
	CROSS_ACTION_INT_PRRAM_TIMECD_VALUE, // 不解释了
};

enum PlayerCrossActionStrParamType
{
	CROSS_ACTION_STR_PARAM_PLAYER_NAME, // 玩家名字
};

enum ModuleLogLevel
{
	LOG_LEVEL_NONE,	  // 无日志
	LOG_LEVEL_LITTLE, // 少量必要日志
	LOG_LEVEL_MANY,	  // 详细日志
};

// 装备品质
enum EquipColor
{
	EQUIP_COLOR_WHITE = 0,	// 白装
	EQUIP_COLOR_GREEN = 1,	// 绿装
	EQUIP_COLOR_BLUE = 2,	// 蓝装
	EQUIP_COLOR_PURPLE = 3, // 紫装
	EQUIP_COLOR_RED = 4,	// 红装
	EQUIP_COLOR_GOD = 6,	// 金装

};

// 技能名
enum SkillName
{
	// 通用技能
	SKILL_NAME_BASE_AEGIS = 40101, // 护体神盾

	// 物理伤害
	SKILL_NAME_BASE_ZS = 10101,			  // 战士普攻
	SKILL_NAME_CISHA_JIANSHU = 10201,	  // 刺杀剑术
	SKILL_NAME_BANYUE_DAOFA = 10301,	  // 半月弯刀
	SKILL_NAME_YEMANNCHONGZHUANG = 10401, // 野蛮冲撞
	SKILL_NAME_LIEHUO_JIANFA = 10501,	  // 烈火剑法
	SKILL_NAME_ZHURI_JIANFA = 10601,	  // 逐日剑法
	SKILL_NAME_KAITIAN_ZHAN = 10701,	  // 开天斩
	SKILL_NAME_SHIHOUGONG = 10801,		  // 狮子吼
	SKILL_NAME_QINGLONGSHOU = 10901,	  // 擒龙手
	SKILL_NAME_SHIBUYISHA = 11001,		  // 十步一杀
	SKILL_NAME_JIANRENFENGBAO = 11101,	  // 剑刃风暴
	SKILL_NAME_JICHUJIANFA = 11102,		  // 基础剑法
	SKILL_NAME_GONGSHAJIANSHU = 11201,	  // 攻杀剑术

	// 魔法伤害
	SKILL_NAME_BASE_FS = 20001,			// 法师普攻
	SKILL_NAME_LEIDIAN_SHU = 20101,		// 雷电术
	SKILL_NAME_DIYULEIGUANG = 20201,	// 地狱雷光
	SKILL_NAME_JIGUANGDIANYING = 20301, // 疾光电影
	SKILL_NAME_HUOQIANG = 20401,		// 火墙
	SKILL_NAME_BINGPAOXIAO = 20501,		// 冰咆哮
	SKILL_NAME_HANBINGZHANG = 20601,	// 寒冰掌
	SKILL_NAME_MIETIANHUO = 20701,		// 灭天火
	SKILL_NAME_MOFADUN = 20801,			// 魔法盾
	SKILL_NAME_LIUXINGHUOYU = 20901,	// 流星火雨
	SKILL_NAME_KANGJUHUOHUAN = 21001,	// 抗拒火环
	SKILL_NAME_DIYUHUO = 21101,			// 地狱火
	SKILL_NAME_KUANGLONGZIDIAN = 21201, // 狂龙紫电
	SKILL_NAME_FENSHENSHU = 21301,		// 分身术
	SKILL_NAME_DAHUOQIU		 = 21401,	// 大火球
	SKILL_NAME_YOUHUOZHIGUANG = 21501,	// 诱惑之光
	SKILL_NAME_BAOLIEHUOYAN = 21601,	// 爆裂火焰
	SKILL_NAME_SHENGYANSHU  = 21701,	// 圣言术
	SKILL_NAME_SHUNXIYIDONG = 21801,	// 瞬息移动

	// 道术伤害
	SKILL_NAME_BASE_DS = 30001,			 // 道士普攻
	SKILL_NAME_LINGHUNHUOFU = 30101,	 // 灵魂火符
	SKILL_NAME_SHIDUSHU = 30201,		 // 施毒术
	SKILL_NAME_ZHAOHUAN_BAIHU = 30301,	 // 召唤白虎术
	SKILL_NAME_YOULINGDUN = 30401,		 // 幽灵盾
	SKILL_NAME_SSZJ_SHU = 30501,		 // 神圣战甲术
	SKILL_NAME_WUJIZHENQI = 30601,		 // 无极真气
	SKILL_NAME_SHIXUESHU = 30701,		 // 嗜血术
	SKILL_NAME_ZHAOHUANYUELING = 30801,	 // 召唤月灵
	SKILL_NAME_JUFENGPO = 30901,		 // 飓风破
	SKILL_NAME_QIBOGONG = 31001,		 // 气波功
	SKILL_NAME_ZHAOHUANBINGLONG = 31101, // 召唤冰龙[召唤月灵觉醒之后，仅提供给客户端使用]
	SKILL_NAME_MOLONGJIANGSHI = 31201,	 // 魔龙将士
	SKILL_NAME_JINGSHENLIZHANFA = 31401, // 精神力战法
	SKILL_NAME_QUNTIYINSHENSHU	 = 31501, //群体隐身术
	SKILL_NAME_ZHAOHUANKULOU	 = 31601, //召唤骷髅
	SKILL_NAME_YOULINGMOJIASHU	 = 31701, //幽灵魔甲术
	SKILL_NAME_QUNTIZHILIAOSHU	 = 31801, //群体治疗术
	SKILL_NAME_ZHILIAOSHU = 31901, //治疗术
	SKILL_NAME_YINSHENSHU = 32001, //隐身术

	//---------------------------目前用不到的技能----------------------------
	SKILL_NAME_ZHAOHUANSHU = 21301, // 召唤术
};

// 怪物品质
enum MonsterQuality
{
	MONSTER_QUALITY_1 = 1,
	MONSTER_QUALITY_2,
	MONSTER_QUALITY_3,
	MONSTER_QUALITY_4,
	MONSTER_QUALITY_5,
	MONSTER_QUALITY_6,
};

// 技能类型
enum SkillAttackType
{
	BAOFA_SKILL = 1,		 // 爆发技能
	AOE_NORMAL_SKILL = 2,	 // AOE普攻
	SINGLE_NORMAL_SKILL = 3, // 单体普攻
	CALL_NORMAL_SKILL = 4,	 // 召唤技能
};

// 其他gene的id
enum OtherBuffName
{
	BUFF_NAME_PROP_SHILED = 327, // PK护盾[战斗属性buff]

	BUFF_NAME_PROP_GUILD_PK = 20075, // PK增伤[战斗属性buff]
};

// 技能gene的id  （不是 gene 类型）
enum SkillBuffName
{
	BUFF_NAME_MABI = 14,			   // 麻痹
	BUFF_NAME_CHENMO = 17,			   // 沉默
	BUFF_NAME_DS_ZJS = 36,			   // 神圣战甲术
	BUFF_NAME_DS_YLD = 37,			   // 幽灵盾
	BUFF_NAME_DS_YLMJ_1 = 40,		   // 幽灵魔甲术1
	BUFF_NAME_DS_YLMJ_2 = 4001,		   // 幽灵魔甲术2
	BUFF_NAME_DS_YLMJ_3 = 4002,		   // 幽灵魔甲术3
	BUFF_NAME_FS_MOFADUN = 200,		   // 魔法盾
	BUFF_NAME_FS_FSS = 20061,		   // 分身术
	BUFF_NAME_DS_POSION = 201,		   // 道士毒
	BUFF_NAME_FALIJJ = 311,			   // 法力荆棘（寒冰盾）
	BUFF_NAME_LIE_HUO = 312,		   // 烈火
	BUFF_NAME_ZHU_RI = 313,			   // 逐日
	BUFF_NAME_SHIBUYISHA_JIANSU = 378, // 十步一杀减速
	BUFF_NAME_MOVE_DEC = 384,		   // 降低移速
	BUFF_NAME_SDQ_CRIT_RATE = 385,	   // 闪电拳（暴击概率提升）
	BUFF_NAME_SDQ_CRITDMG_RATE = 387,  // 闪电拳（暴击伤害提升）
	BUFF_NAME_KB = 388,				   // 狂暴
	BUFF_NAME_SXS_XX_ADD = 389,		   // 嗜血术 吸血增加
	BUFF_NAME_LIE_HUO2 = 390,		   // 烈火2
	BUFF_NAME_ZHU_RI2 = 391,		   // 逐日2
	BUFF_NAME_FROZEN = 394,			   // 冰冻
	BUFF_NAME_WJZQ = 395,			   // 无极真气
	BUFF_NAME_JIANREN = 396,		   // 剑刃风暴
	BUFF_NAME_XFZ = 397,			   // 旋风斩
	BUFF_NAME_JIAOXIE = 20080,		   // 缴械
	BUFF_NAME_SHENGDONG = 60064,	   // 深冬buff
	BUFF_NAME_ZHUOSHAO = 60066,		   // 灼烧buff
	BUFF_NAME_YINGYONG = 60039,		   // 英勇buff
	BUFF_NAME_KLYZ = 60040,			   // 狂乱意志buff
	BUFF_NAME_SDBH = 60078,			   // 闪电庇护buff
	BUFF_NAME_SHIELD1 = 60081,		   // 金钟罩1
	BUFF_NAME_SHIELD2 = 60082,		   // 金钟罩2
	BUFF_NAME_SHIELD3 = 60083,		   // 金钟罩3
	BUFF_NAME_LYSB = 20021,			   // 蓝银真身闪避
	BUFF_NAME_HOLY_LIGHT = 20030,	   // 圣光制裁基因
	BUFF_NAME_HOLY_LIGHT_CRIT = 20031, // 圣光制裁暴击基因
};

const float mental_percent_denominator = 10000.0;

const int shiledCoolDownTime = 60;

enum NewPlayer
{
	NOVICE_PROTECTION_LEVEL = 10, // 新手保护等级 （小于等于39级的受新手保护）
};

// 是否加入自动战斗序列
enum AutoSkill
{
	SKILL_AUTO_OP_ATTACK = 0, // 开启自动
	SKILL_HAND_OP_ATTACK = 1, // 关闭自动（手动）
};

enum EnterSceneType
{
	ENTER_SCENE_DEFAULT = 0,
	ENTER_SCENE_ZHAOJILING = 1,	 // 通过召集令进入场景
	ENTER_SCENE_ZHUISHALING = 2, // 通过追杀令进入场景
	ENTER_SCENE_BY_POS = 3,		 // 通过指定坐标进入场景
};

enum SWYRankType
{
	SWY_RANK_PLAYER = 0,
	SWY_RANK_GUILD = 1,
};

enum GuildBattleRankType
{
	GUILD_BATTLE_RANK_PLAYER		= 0,
	GUILD_BATTLE_RANK_PLAYER_BAODI	= 1,
	GUILD_BATTLE_RANK_GUILD			= 2,
};

// 赞助
enum ZANZHU
{
	ZANZHU_HUISHOU_ADD = 101, // 回收比例加成（万分比）
	ZANZHU_DROPRATE = 201,	  // 掉落加成（万分比）
	ZANZHU_TRADE_SELF = 301,  // 交易权限开启
	// ZANZHU_TRADE_SELF  			= 401,		//寄售行开启
	ZANZHU_UNBIND = 501,			   // 掉落非绑
	ZANZHU_DESATK_PVE = 601,		   // 怪物减伤（万分比）
	ZANZHU_ADDATK_PVE = 701,		   // 怪物增伤（万分比）
	ZANZHU_ADD_MAX_HP = 801,		   // 最大生命
	ZANZHU_DESATK_PVP = 901,		   // PK减伤（万分比）
	ZANZHU_AUTO_USE_INGOT_ITEM = 1001, // 自动使用元宝道具
	ZANZHU_USE_INGOT_UNBIND = 1101,	   // 使用元宝变成非绑
	ZANZHU_AUTO_USE_ITEM = 1201,   // 自动使用道具
	ZANZHU_AUTO_RECOVERY = 1301,	   // 自动回收
	ZANZHU_RECOVERY_UNBIND = 1401,	   // 回收获得非绑
	// ZANZHU_AUTO_FIRE_SACRIFICE  = 1401,     //自动火祭
	// ZANZHU_AUTO_COMPOSE			= 1701,     //自动合成

};

// 交易卡权限
enum TradeCard
{
    TRADECARD_PLAYERTRADE_PRIVILEGE = 101,		//开放交易权限
    TRADECARD_SELL_PRIVILEGE = 201,				//开启寄售行
    TRADECARD_DROP_UNBIND = 301,				//掉落道具非绑定
    TRADECARD_INGOTITEM_UNBIND = 401,			//使用金币道具变为非绑
    TRADECARD_RECOVERY_UNBIND = 501,			//回收获得非绑定金币
    TRADECARD_CAN_DROPITEM = 601,				//允许丢弃物品
};

enum WebPayName
{
	WEB_PAY_NAME_BEGIN = 0,

	WEB_PAY_CHONGZHI = 1, // 充值
	// 特权
	WEB_PAY_TEQUAN_MONTH_1 = 2,
	WEB_PAY_TEQUAN_MONTH_2 = 3,
	WEB_PAY_TEQUAN_MONTH_3 = 4,
	WEB_PAY_TEQUAN_QUARTER = 5,
	WEB_PAY_ZHANLING = 6,	  // 战令
	WEB_PAY_ZIXUAN_GITF = 7,  // 自选礼包
	WEB_PAY_XIANSHI_SHOP = 8, // 限时商店售卖
	WEB_PAY_YFCT = 9,		  // 一飞冲天
	WEB_PAY_TZJH = 10,		  // 投资计划
	WEB_PAY_MRLB = 11,		  // 每日礼包
	WEB_PAY_ZXLB_ITEM = 12,	  // 自选礼包

};

enum VipTaskType
{
	VIP_TASK_LEVEL = 1,		// 等级任务，X等级
	VIP_TASK_REBORN = 2,	// 转生任务，X转数
	VIP_TASK_EQ = 3,		// 装备任务，X件数，Y等级/转生，Z
	VIP_TASK_MON = 4,		// 杀怪任务
	VIP_TASK_SJSJ = 5,		// 神剑神甲任务
	VIP_TASK_NTGM = 6,		// 逆天改命：x阶数，y部位(1斗笠，2护盾，3玉佩，4龙魂)
	VIP_TASK_BAOSHI = 7,	// 宝石任务
	VIP_TASK_BAOSHI_EX = 8, // 带宝石等级的任务
	VIP_TASK_BOSS = 9,		// 击杀boss，X数量，Y等级
	VIP_TASK_FMON = 10,		// 击杀固定怪物X数量，Y怪物ID，Z地图
	VIP_TASK_QIANGHUA = 11,	// 强化X个部位达到Y星
	VIP_TASK_XUNZHANG = 12, // 勋章X
	VIP_TASK_FENGHAO = 13,	// 封号X
	VIP_TASK_SKILL = 14,	// 技能X个达到Y级
};

enum RankType
{
	RANK_TYPE_GUARD_FLAG = 1,			// 守护战旗排名
	RANK_TYPE_SHA_JUAN = 2,				// 沙城捐献
	RANK_TYPE_ROLE_LEVEL = 3,			// 角色等级
	RANK_TYPE_PHYSICAL_ATTACK = 4,		// 物理攻击榜
	RANK_TYPE_MAGIC_ATTACK = 5,			// 魔法攻击榜
	RANK_TYPE_TAOIST_ATTACK = 6,		// 道术攻击榜
	RANK_TYPE_ATTACK = 7,				// 竞技狂欢 攻击排行
	RANK_TYPE_WEN_ZHANG = 8,			// 竞技狂欢 纹章排行
	RANK_TYPE_SHEN_JIAN_SHEN_JIA = 9,	// 竞技狂欢 神剑神甲排行
	RANK_TYPE_USE_NOT_BIND_LINGFU = 10, // 竞技狂欢 消费排行，使用非绑灵符排行
	RANK_TYPE_XIAOFEI = 11,				// 运营活动，消费排行
	RANK_TYPE_CHONGZHI = 12,			// 运营活动，充值排行
	RANK_TYPE_REBORN = 13,				// 竞技狂欢 转生排行
	RANK_TYPE_CHONGZHI_ACTIVITY = 14,	// 充值排行
	RANK_TYPE_XIAOFEI_ACTIVITY = 15,	// 消费排行
	RANK_TYPE_XUNBAO = 16,				// 运营活动，寻宝排行
	RANK_TYPE_XUNBAO_ACTIVITY = 17,		// 寻宝排行
};

// 排行榜刷新类型
enum RankUpdateType
{
	RANK_UPDATE_TYPE_DEFAULT = 0, // 默认刷新
	RANK_UPDATE_TYPE_CUSTOM = 1,  // 自定义刷新
};
// 排行榜初始化类型
enum RankInitType
{
	RANK_INIT_TYPE_DEFAULT = 0,	   // 启服时创建
	RANK_INIT_TYPE_SERVER_DAY = 1, // 开服天数相关
	RANK_INIT_TYPE_ACTIVITY = 2,   // 活动相关
	RANK_INIT_TYPE_HOLIDAY = 3,	   // 运营活动相关
};

enum DressType
{
	DRESS_TYPE_WUQI = 1,
	DRESS_TYPE_YIFU = 2,
	DRESS_TYPE_CHENGHAO = 3,
	DRESS_TYPE_HUNHUAN = 4,
	DRESS_TYPE_JINGLING = 5,
	DRESS_TYPE_CHENGHAO2 = 6,
	DRESS_TYPE_CHENGHAO3 = 7,
	DRESS_TYPE_CHENGHAO4 = 8,
	DRESS_TYPE_CHENGHAO5 = 9,
};

// 沙城boss阶段
enum SCBossStateType
{
	BOSS_STATE_CLOSED = 0,	 // 关闭，当天不开
	BOSS_STATE_SC = 2,		 // 沙城阶段
	BOSS_STATE_WAITTING = 1, // 等待开启皇宫阶段
	BOSS_STATE_HG = 3,		 // 皇宫阶段
	BOSS_STATE_END = 4,		 // 结束
};

#endif //_DEFINITION_H_INCLUDED

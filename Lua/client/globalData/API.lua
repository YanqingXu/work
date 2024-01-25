--全局事件
api_event = cc.Director:getInstance():getEventDispatcher()
require("xf.essential.EssScript")
require("xf.logic.globalData.EventNames")
require("xf.base.database.UIEventNames")
require("xf.engine.audio.YIM")

local api_load = {}
local start_Scheduler = nil


local function _add_require(luafile)
	require(luafile)
end

---加载并创建全局接口的写到这里
local function _load_other()
	--计时器
	local ScheduleManager      = require("xf.engine.ScheduleManager")
	api_schedule               = ScheduleManager.getInstance()

	--音乐加载类
	local AudioLoad            = require("xf.engine.load.AudioLoad")
	api_audio                  = AudioLoad.getInstance()

	local UIManager            = require("xf.engine.UIManager")
	api_ui                     = UIManager.getInstance()

	local RemoteUIManager      = require("xf.engine.RemoteUIManager")
	api_rui                    = RemoteUIManager.getInstance()

	local MsgBox               = require("xf.engine.ui.MsgBox")
	api_msgbox                 = MsgBox.getInstance()

	local GameFeatureInfo      = require("xf.engine.ui.GameFeatureInfo")
	api_game_feature           = GameFeatureInfo.getInstance()

	local ToolTipsManager      = require("xf.logic.tooltips.ToolTipsManager")
	api_tips                   = ToolTipsManager.getInstance()

	--全屏特效
	local FullScreenEffect     = require("xf.engine.ui.FullScreenEffect")
	api_screen_effect          = FullScreenEffect.getInstance()

	local LoadingPanel         = require("xf.engine.ui.LoadingPanel")
	api_loading                = LoadingPanel.getInstance()

	--小地图的层
	local MiniManager          = require("xf.engine.MiniManager")
	api_mini                   = MiniManager.getInstance()
	--人物管理类
	local GhostManager         = require("xf.engine.GhostManager")
	api_ghost                  = GhostManager.getInstance()

	--地图管理类
	local MapManager           = require("xf.engine.MapManager")
	api_map                    = MapManager.getInstance()

	-- Gm管理类
	local GmManager            = require("xf.engine.GmManager")
	api_gm                     = GmManager.getInstance()

	--场景管理类
	local SceneManager         = require("xf.engine.SceneManager")
	api_scene                  = SceneManager.getInstance()

	--技能管理
	local SkillManager         = require("xf.engine.SkillManager")
	api_skill                  = SkillManager.getInstance()

	local UpDateFunctorManager = require("xf.logic.updatefunctor.UpDateFunctorManager")
	api_functor                = UpDateFunctorManager.getInstance()

	local EffectManager        = require("xf.engine.EffectManager")
	api_effect                 = EffectManager.getInstance()

	--主玩家
	require("xf.engine.ghost.MyRole")
	MyRole.init()

	--版本管理器
	local VersionManager = require "xf.engine.VersionManager"
	api_version_manager = VersionManager.getInstance()

	-- 用户道具
	local UserItemData = require("xf.logic.vo.UserItemData")
	MyItemData = UserItemData:new()

	-- 任务数据
	local taskData = require("xf.logic.vo.TaskData")
	MyTaskData = taskData:new()

	-- 社交数据
	local RelationData = require("xf.logic.vo.RelationData")
	MyRelationData = RelationData:new()

	-- 组队数据
	local TeamData = require("xf.logic.vo.TeamData")
	MyTeamData = TeamData:new()

	-- 邮件管理
	local MailManager = require("xf.engine.MailManager")
	MyMailManager = MailManager:new()

	-- 其它玩家
	local OtherInfo = require("xf.engine.OtherInfoManager")
	OtherInfoManager = OtherInfo:new()

	-- boss 数据
	local bossData = require("xf.logic.vo.BossData")
	MyBossData = bossData:new()

	-- boss掉落记录 数据
	local dropRecordData = require("xf.logic.vo.BossDropRecord")
	MyDropRecordData = dropRecordData:new()

	-- 寻宝 数据
	local TreasureHuntData = require("xf.logic.vo.TreasureHuntData")
	MyTreasureHuntData = TreasureHuntData:new()

	-- 功能开关管理
	local SwitchManager = require("xf.engine.SwitchManager")
	MySwitchManager = SwitchManager:new()

	--渠道属性
	local ChannelPropsManager = require("xf.engine.ChannelPropsManager")
	MyChannelPropsManager = ChannelPropsManager:new()

	local GuildDataManager = require("xf.logic.vo.GuildDataVO")
	MyGuildData = GuildDataManager:new()

	local ZhanDuiDataManager = require("xf.logic.vo.ZhanDuiDataVO")
	MyZhanDuiData = ZhanDuiDataManager:new()

	local ActivityDataManager = require("xf.logic.vo.ActivityDataVo")
	MyActivityData = ActivityDataManager:new()

	local SceneDataManager = require("xf.logic.vo.SceneDataVo")
	MySceneData = SceneDataManager:new()

	local PanelEffectManager = require("xf.engine.PanelEffectManager")
	api_panel_effect_manager = PanelEffectManager.getInstance()

	--召集令
	local ZhaoJiLingManager = require("xf.logic.ui.ZJL.ZhaoJiLingManager")
	api_zjl_manager = ZhaoJiLingManager.getInstance()

	---飘字管理
	local FlyWordManager = require("xf.logic.flyword.FlyWordManager")
	api_flyword = FlyWordManager.getInstance()

	--新手引导
	local NoviceManager = require("xf.engine.NoviceManager")
	api_novice = NoviceManager.getInstance()

	--技能数据
	local SkillData = require("xf.logic.vo.SkillDataVo")
	MySkillData = SkillData:new()

	-- 运营活动数据
	local HolidayData = require("xf.logic.vo.HolidayDataVo")
	MyHoliday = HolidayData:new()

	api_remote_load_manager:addListener()
end

local function _do_require()
	_load_other()
end

----------------------------------------------------
---纯粹加载的放到这里 不要用require用_add_require
-----------------------------------------------
_add_require("xf.logic.helper.loginHelper")
_add_require("xf.logic.network.proxy.LoginProxy")

_add_require("xf.base.database.language_data")
_add_require("xf.base.database.jumplist_data")
_add_require("xf.base.database.event_definition.lua")


--本地配置
_add_require("xf.logic.utils.CommonUtils")
_add_require("xf.logic.utils.DebugUtils")
_add_require("xf.logic.utils.StringUtils")
_add_require("xf.logic.utils.ArithUtils")
_add_require("xf.logic.utils.AttrUtils")
_add_require("xf.logic.utils.DirectionUtils")
_add_require("xf.logic.utils.DrawUtils")
_add_require("xf.logic.utils.TimeUtils")
_add_require("xf.logic.utils.IAPUtils")
_add_require("xf.logic.utils.HttpUtils")
_add_require("xf.logic.utils.MouseUtils")
_add_require("xf.logic.utils.ColorUtils")
_add_require("xf.logic.utils.filter_data_name")
_add_require("xf.logic.utils.ResPathUtils")
_add_require("xf.logic.utils.SpriteBlurUtils")
_add_require("xf.logic.globalData.definition")

_add_require("xf.logic.globalData.Define")
_add_require("xf.logic.globalData.script_definition")
_add_require("xf.logic.globalData.SkillDefine")
_add_require("xf.monitor")

-- 功能定义
_add_require("xf.logic.helper.ColorHelper")
_add_require("xf.engine.ghost.helper.MyAttackHelper")
_add_require("xf.engine.ghost.helper.SkillOperHelper")
_add_require("xf.engine.ghost.stateMac.StateHelper")
_add_require("xf.engine.ghost.helper.TitleHelper")
_add_require("xf.engine.ghost.helper.SkillHelper")
_add_require("xf.engine.ghost.helper.SkillExcuteHelper")
_add_require("xf.engine.map.helper.MapHelper")

_add_require("xf.engine.ghost.helper.AnimateHelper")
_add_require("xf.engine.ghost.helper.ZorderHelper")
_add_require("xf.engine.ghost.helper.CommonHelper")
_add_require("xf.engine.ghost.helper.MyRoleHelper")
_add_require("xf.engine.ghost.helper.NpcFuncHelper")
_add_require("xf.engine.ghost.helper.PetHelper")

_add_require("xf.logic.utils.PositionUtils")
_add_require("xf.logic.utils.LabelUtils")
_add_require("xf.logic.utils.ListViewDecorator")
_add_require("xf.logic.utils.NodeDecorator")
_add_require("xf.logic.utils.RichTextUtils")
_add_require("xf.Switch")

_add_require("xf.logic.helper.srvToClientHelper")
_add_require("xf.base.platform.PlatformConfig")

--语言
_add_require("xf.base.local.zh-CN.language")
_add_require("xf.base.local.zh-CN.systeminfo")
_add_require("xf.base.local.zh-CN.propnotify")


--全局数据
if not GAME_REMOTE_SAVE_URL then
	_add_require("xf.logic.globalData.GameData")
end

--宏定义
_add_require("xf.logic.network.proxy.MsgCategory")

--小包开关
_add_require("xf.TinySwitch")


_add_require("xf.logic.userdata.UserDefaultDataDefination")
_add_require("xf.logic.userdata.UserDefaultDataHelper")
_add_require("xf.logic.updatefunctor.UpDateFunctorDefination") --加载功能组件定义


_add_require("xf.logic.network.message.receive_message")

_add_require("xf.logic.network.entity.target")
_add_require("xf.logic.network.task.taskTarget")
--全局数据代理
_add_require("xf.logic.vo.ItemOperator") --加载功能组件操作
_add_require("xf.logic.vo.BagOperator")

_add_require("xf.logic.network.proxy.SocketProxy")
_add_require("xf.logic.network.proxy.SceneProxy")
_add_require("xf.logic.network.proxy.PlayerProxy")
_add_require("xf.logic.network.proxy.WorldProxy")
_add_require("xf.logic.network.proxy.ItemProxy")
_add_require("xf.logic.network.proxy.TradeProxy")

_add_require("xf.logic.network.proxy.RelationProxy")
_add_require("xf.logic.network.proxy.MailProxy")
_add_require("xf.logic.network.proxy.TeamProxy")
_add_require("xf.logic.network.proxy.PetProxy")
_add_require("xf.logic.network.proxy.GuildProxy")
_add_require("xf.logic.network.proxy.ZhanDuiProxy")
_add_require("xf.logic.network.proxy.HolidayProxy")
_add_require("xf.logic.ui.NPC.NPCFunctionData")
_add_require("xf.logic.network.task.taskProxy")

-- 红点管理系统
_add_require("xf.logic.redPointSystem.RedPointRule")
_add_require("xf.logic.redPointSystem.RedPointRefreshRule")
_add_require("xf.logic.redPointSystem.RedPointManager")

--全局助手
_add_require("xf.logic.helper.chat_func")
_add_require("xf.logic.helper.ChatHelper")
_add_require("xf.logic.helper.socialHelper")
_add_require("xf.logic.helper.teamHelper")
_add_require("xf.logic.helper.guildHelper")
_add_require("xf.logic.helper.NotifyHelper")
_add_require("xf.logic.helper.iconTipHelper")
_add_require("xf.logic.helper.CommonFunction")
_add_require("xf.logic.helper.attentionHelper")
_add_require("xf.logic.helper.charUiHelper")
_add_require("xf.logic.helper.itemHelper")
_add_require("xf.logic.helper.nameHelper")
_add_require("xf.logic.helper.numberHelper")
_add_require("xf.logic.helper.speechHelper")
_add_require("xf.logic.helper.scrollHelper")
_add_require("xf.logic.helper.common_fun")
_add_require("xf.logic.helper.rewardHelper")
_add_require("xf.logic.helper.notification")
_add_require("xf.logic.helper.quickBuyHelper")
_add_require("xf.logic.helper.NewVipHelper")
_add_require("xf.logic.ui.Team.TeamCommon")
_add_require("xf.logic.helper.questHelper")
_add_require("xf.logic.helper.MsgboxHelper")
_add_require("xf.logic.helper.systemMenuHelper")
_add_require("xf.logic.helper.funcHelper")
_add_require("xf.logic.flyword.FlyWordHelper")
_add_require("xf.logic.flyword.FlySelfWordHelper")
_add_require("xf.logic.helper.PowerHelper")
_add_require("xf.logic.helper.EquipHelper")
_add_require("xf.logic.helper.CombatHelper")
_add_require("xf.logic.helper.CommonOpResponseHelper")
_add_require("xf.logic.helper.HolidayHelper")
_add_require("xf.logic.helper.ActivityHelper")
_add_require("xf.logic.helper.privilegeHelper")
_add_require("xf.logic.helper.logicHelper")

--消息发送助手
_add_require("xf.logic.request.guildRequest")
_add_require("xf.logic.request.socialRequest")
_add_require("xf.logic.request.itemRequest")
_add_require("xf.logic.request.tradeRequest")
_add_require("xf.logic.request.loginRequest")
_add_require("xf.logic.request.npcActivityRequest")
_add_require("xf.logic.request.bagRequest")
_add_require("xf.logic.request.bossRequest")
_add_require("xf.logic.request.playerRequest")
_add_require("xf.logic.network.task.taskRequest")

--CPP回调
_add_require("xf.engine.audio.speech_callback")

--GM批处理
_add_require("xf.GM")

--消息开关管理
_add_require("xf.logic.userdata.UserSwitchMsg")

_add_require("xf.engine.ghost.helper.ComponentHelper")
--UI管理类
_add_require("xf.logic.command.PopUpCommand")

_add_require("xf.engine.load.Animation_load")

_add_require("xf.logic.helper.Vector2D")

_add_require("xf.logic.mgr.itemMgr")
_add_require("xf.logic.mgr.eventMgr")
_add_require("xf.logic.mgr.propMgr")
_add_require("xf.logic.grid.gridMgr")
_add_require("xf.logic.mgr.shopMgr")
_add_require("xf.logic.mgr.rankMgr")
_add_require("xf.logic.helper.BaseUI")
_add_require("xf.logic.tooltips.ToolTipsHelper")

_add_require("xf.logic.ui.YBHS.YBHSOnce")
_add_require("xf.logic.ui.YBHS.YBHSSuit")

_do_require()

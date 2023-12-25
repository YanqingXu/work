messages =
{
	{
		define = "class", name = "MsgGetCodeGiftFromAsRequest", category = "MSG_CATEGORY_GM", id = 40, base = "Message",
		attributes =
		{
			{type = "int32", name = "ServerID"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "string", name = "code"},
		},
	},

	{
		define = "struct", name = "GiftData",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "isbind"},
		},
	},

	{
		define = "struct", name = "KeyValueData",
		attributes =
		{
			{type = "string", name = "key"},
			{type = "string", name = "value"},
		},
	},

	{
		define = "class", name = "MsgGetCodeGiftFromAsResponse", category = "MSG_CATEGORY_GM", id = 41 , base = "Message",
		attributes =
		{
			{type = "int32", name = "ServerID"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "errcode"},
			{type = "string", name = "code"},
			{type = "GiftData", name = "GiftList", vector = true},
		},
	},

	{
		define = "class", name = "MsgGetCodeGiftResultToAsNotify", category = "MSG_CATEGORY_GM", id = 42, base = "Message",
		attributes =
		{
			{type = "int32", name = "ServerID"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "string", name = "code"},
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgRechargeReturnRequest", category = "MSG_CATEGORY_GM", id = 43, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name = "channel_id", desc = "渠道ID"},
			{type = "string", name = "begin_time", desc = "开始时间"},
			{type = "string", name = "end_time", desc = "结束时间"},
			{type = "int32", name = "client_session_id", desc = "玩家会话ID"},
			{type = "int16", name = "player_class", desc = "玩家职业"},
			{type = "string", name = "player_name", desc = "玩家名称"},
			{type = "int8", name = "player_gender", desc = "玩家性别"},
		},
	},

	{
		define = "class", name = "MsgRechargeReturnResponse", category = "MSG_CATEGORY_GM", id = 44, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name = "channel_id", desc = "渠道ID"},
			{type = "string", name = "begin_time", desc = "开始时间"},
			{type = "string", name = "end_time", desc = "结束时间"},
			{type = "int32", name = "client_session_id", desc = "玩家会话ID"},
			{type = "int16", name = "player_class", desc = "玩家职业"},
			{type = "string", name = "player_name", desc = "玩家名称"},
			{type = "int8", name = "player_gender", desc = "玩家性别"},
			{type = "int32", name = "recharge", desc = "充值金额"},
		},
	},

	{
		define = "class", name = "MsgRechargeRequest", category = "MSG_CATEGORY_GM", id = 121, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
			{type = "string", name = "OrderSerial"},
		},
	},

	{
		define = "class", name = "MsgRechargeResponse", category = "MSG_CATEGORY_GM", id = 122, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "string", name = "OrderSerial"},
		},
	},

	{
		define = "class", name = "MsgPlayerLoginLogoutNotify", category = "MSG_CATEGORY_GM", id = 130, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name",},
			{type = "string", name = "deviceId"},
			{type = "int32", name = "serverId"},
			{type = "int32", name = "channelId"},
			{type = "int32", name = "platformId"},
			{type = "int32", name = "time"},
		},
	},

	{
		define = "class", name = "MsgPlayerCreateDeleteNotify", category = "MSG_CATEGORY_GM", id = 131, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name",},
			{type = "int32", name = "career"},
			{type = "string", name = "deviceId"},
			{type = "int32", name = "serverId"},
			{type = "int32", name = "channelId"},
			{type = "int32", name = "platformId"},
			{type = "int32", name = "time"},
		},
	},

	{
		define = "class", name = "MsgAuthRewardDataNotify", category = "MSG_CATEGORY_GM", id = 140, base = "Message",
		attributes =
		{
			{type = "int32", name = "rewardid"},
			{type = "string", name = "rewardname"},
			{type = "int32" , name = "ismail"},
			{type = "GiftData", name = "GiftList", vector = true},
		},
	},

	{
		define = "class", name = "MsgGetAuthRewardDataRequest", category = "MSG_CATEGORY_GM", id = 141, base = "Message",
		attributes =
		{
			{type = "int32", name = "rewardid"},
		},
	},

	{
		define = "class", name = "MsgSendPlayerGiftRequest", category = "MSG_CATEGORY_GM", id = 142, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "rewardid"},
			{type = "int32", name = "endtime"},
			{type = "int32", name = "isbind"},
		},
	},

	{
		define = "class", name = "MsgSendSystemMsgNotify", category = "MSG_CATEGORY_GM", id = 143, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "string", name = "msg"},
		},
	},

	{
		define = "class", name = "MsgGMsendToPlayer", category = "MSG_CATEGORY_GM", id = 144, base = "Message",
		attributes =
		{
			{type = "int32", name = "playerid"},
			{type = "string", name = "content"},
			{type = "int32", name = "gmid"},
			{type = "string", name = "gm"},
		},
	},

	{
		define = "class", name = "MsgPlayersendToGM", category = "MSG_CATEGORY_GM", id = 145, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "serverid"},
			{type = "string", name = "content"},
		},
	},

	{
		define = "class", name = "MsgSendPlayerGiftOnlineRequest", category = "MSG_CATEGORY_GM", id = 146, base = "Message",
		attributes =
		{
			{type = "int32", name = "rewardid"},
			{type = "int32", name = "endtime"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "job" },
			{type = "int32", name = "lvlMin" },
			{type = "int32", name = "lvlMax" },
			{type = "int32", name = "rebornMin"},
			{type = "int32", name = "rebornMax"},
			{type = "int32", name = "channelId"},
		},
	},
	
	{
		define = "class", name = "MsgSendMail", category = "MSG_CATEGORY_GM", id = 147, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid", desc="玩家ID"},
			{type = "string", name = "title", desc="邮件标题"},
			{type = "string", name = "content", desc="邮件内容"},
			{type = "string", name = "items", desc="邮件附件: 物品ID;物品ID*数量;物品ID*数量,属性ID=属性值;"},
		},
	},

	{
		define = "class", name = "MsgGetSensitiveWordsRequest", category = "MSG_CATEGORY_GM", id = 151, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverid"},
		},
	},

	{
		define = "class", name = "MsgGetSensitiveWordsResponse", category = "MSG_CATEGORY_GM", id = 152, base = "Message",
		attributes =
		{
			{type = "string", name = "words", vector = true},
		},
	},
	
	--[[
	-- 老的，兼容王权霸业，保留占位
	{
		define = "class", name = "MsgUpdateGMHolidayRequest", category = "MSG_CATEGORY_GM", id = 153, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgUpdateGMHolidayResponse", category = "MSG_CATEGORY_GM", id = 154, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayGlobleRankAddValueRequest", category = "MSG_CATEGORY_GM", id = 155, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayGlobleRankAddValueResponse", category = "MSG_CATEGORY_GM", id = 156, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "struct", name = "GMHolidayGRank",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayGlobleRankRequest", category = "MSG_CATEGORY_GM", id = 157, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayGlobleRankResponse", category = "MSG_CATEGORY_GM", id = 158, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayNoteRequest", category = "MSG_CATEGORY_GM", id = 159, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMHolidayNoteResponse", category = "MSG_CATEGORY_GM", id = 160, base = "Message",
		attributes =
		{
		},
	},
	]]

	---------------------------------Check Server Msg ----------------------------------------
	{
		define = "class", name = "MsgGMGetPlayerInfoRequest", category = "MSG_CATEGORY_GM", id = 200, base = "Message",
		attributes =
		{
			{type = "string", name = "playername"},
		},
	},

	{
		define = "class", name = "MsgGMGetPlayerInfoResponse", category = "MSG_CATEGORY_GM", id = 201, base = "Message",
		attributes =
		{
			{type = "string", name = "playername"},
			{type = "int32" , name = "errcode" },
		},
	},

	{
		define = "class", name = "MsgGMPlayerBaseInfoNotify", category = "MSG_CATEGORY_GM", id = 202, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid", desc="账号ID"},
			{type = "int32", name = "pid", desc="玩家ID"},
			{type = "string", name = "playername", desc="玩家名称"},
			{type = "int16", name = "job", desc="玩家职业"},
			{type = "int16", name = "gender", desc="玩家性别"},
			{type = "int32", name = "lvl", desc="玩家等级"},
			{type = "int32", name = "reborn", desc="玩家转生等级"},
			{type = "int64", name = "currentexp", desc="玩家经验"},
			{type = "string", name = "guildname", desc="玩家所属行会名称"},
			{type = "int64", name  = "money", desc="玩家金币"},
			{type = "int32", name = "gold", desc="玩家元宝"},
			{type = "int32", name = "createtime", desc="玩家创建时间"},
			{type = "int32", name = "lastLogouttime", desc="玩家最后登出时间"},
			{type = "string", name = "mapname", desc="玩家当前地图"},
			{type = "int32", name = "vip", desc="玩家VIP等级"},
			{type = "int32", name = "honor", desc="玩家荣誉"},
			{type = "int32", name = "pkvalue", desc="玩家PK值"},
			{type = "int32", name = "rebornsoul", desc="玩家转生修为"},
			{type = "int32", name = "honorlvl", desc="玩家荣誉等级"},
			{type = "int64", name = "coupon", desc="玩家绑金"},
			{type = "int32", name = "jifen", desc="玩家绑元"},
			{type = "int32", name = "boss_score", desc="玩家BOSS积分"},
			{type = "int32", name = "boss_score_level", desc="玩家BOSS积分等级"},
			{type = "int32", name = "stone_chip", desc="宝石碎片"},
			{type = "string", name = "equip_stone", desc="宝石"},
			{type = "int32", name = "soul_chip", desc="魂珠碎片"},
			{type = "string", name = "equip_soul_bead", desc="魂珠"},
			{type = "int32", name = "blood_chip", desc="血符碎片"},
			{type = "string", name = "equip_phylactery", desc="血符"},
			{type = "int32", name = "hudun_chip", desc="护盾碎片"},
			{type = "string", name = "equip_shield", desc="护盾"},
			{type = "int32", name = "wings_bless", desc="翅膀祝福值"},
			{type = "int32", name = "wings_level", desc="翅膀等级"},
			{type = "int32", name = "xb_happness", desc="宝藏积分"},
			{type = "int32", name = "soul_value", desc="灵力值"},
			{type = "int32", name = "achievement_points", desc="玩家成就积分"},
			{type = "string", name = "equip_medal", desc="玩家成就勋章"},
			{type = "int32", name = "mars", desc="玩家战神等级"},
			{type = "int64", name = "exercise", desc="内功值"},
			{type = "int32", name = "exercise_level", desc="内功等级"},
			{type = "int32", name = "gongxun", desc="功勋值"},
			{type = "int32", name = "gongxun_level", desc="功勋称号"},
			{type = "int32", name = "mohun", desc="魔魂值(战魂值)"},
			{type = "int32", name = "hero_wings_bless", desc="英雄翅膀祝福值"},
			{type = "int32", name = "hero_wings_level", desc="英雄翅膀等级"},
		},
	},

	{
		define = "class", name = "MsgGMPlayerCombatDataInfoNotify", category = "MSG_CATEGORY_GM", id = 203, base = "Message",
		attributes =
		{
			{type = "int32", name = "cbtnum"},
			{type = "int32", name = "cbtdata", vector = true},
		},
	},

	{
		define = "struct", name = "GMItemData",
		attributes =
		{
			{type = "int32", name = "ItemPos"},
			{type = "int32", name = "iid"},
			{type = "string", name = "itemname"},
			{type = "int32", name = "itemcnt"},
		},
	},

	{
		define = "class", name = "MsgGMPlayerItemInfoNotify", category = "MSG_CATEGORY_GM", id = 204, base = "Message",
		attributes =
		{
			{type = "GMItemData", name = "items", vector = true},
		},
	},

	{
		define = "struct", name = "GMItemExData",
		attributes =
		{
			{type = "int16", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "struct", name = "GMSkillInfo",
		attributes =
		{
			{type = "string", name = "skillname"},
			{type = "int32", name = "skilllvl"},
			{type = "int32", name = "exp"},
			{type = "int32", name = "maxexp"},
		},
	},

	{
		define = "class", name = "MsgGMPlayerSkillNotify", category = "MSG_CATEGORY_GM", id = 205, base = "Message",
		attributes =
		{
			{type = "GMSkillInfo", name = "skills", vector = true},
		},
	},

	{
		define = "struct", name = "GMPetData",
		attributes =
		{
			{type = "string", name = "petname",},
			{type = "string", name = "petrename"},
			{type = "int32", name = "petlvl"},
			{type = "int32" , name = "petid"},
		},
	},

	{
		define = "class", name = "MsgGMPlayerPetInfoNotify", category = "MSG_CATEGORY_GM", id = 206, base = "Message",
		attributes =
		{
			{type = "GMPetData", name = "pets", vector = true},
		},
	},

	{
		define = "class", name = "MsgGMLoadPlayerInfoOverNotify", category = "MSG_CATEGORY_GM", id = 207, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMCommondRequest", category = "MSG_CATEGORY_GM", id = 208, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "commond"},
		},
	},

	{
		define = "class", name = "MsgGMCommondResponse", category = "MSG_CATEGORY_GM", id = 209, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgCloseServerRequest", category = "MSG_CATEGORY_GM", id = 210,base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGetServerPlayerCntRequest", category = "MSG_CATEGORY_GM", id = 220, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGetServerPlayerCntResponse", category = "MSG_CATEGORY_GM", id = 221, base = "Message",
		attributes =
		{
			{type = "int32", name = "playercnt"},
			{type = "int32", name = "serverid"},
		},
	},

	--{
	--	define = "class", name = "MsgGetPlayerOfflineLoadRequest", category = "MSG_CATEGORY_GM", id = 222, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "pid"},
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgGetPlayerOfflineLoadResponse", category = "MSG_CATEGORY_GM", id = 223, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "pid"},
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	{
		define = "struct", name = "GMOnlineNumByChannel",
		attributes =
		{
			{type = "int32", name = "channelid"},
			{type = "int32", name = "playercnt"},
		},
	},

	{
		define = "class", name = "MsgGetChannelPlayerCntRequest", category = "MSG_CATEGORY_GM", id = 224, base = "Message",
		attributes =
		{
			{type = "string", name = "token"},
		},
	},

	{
		define = "class", name = "MsgGetChannelPlayerCntResponse", category = "MSG_CATEGORY_GM", id = 225, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverId"},
			{type = "int32", name = "onlineTotal"},
			{type = "GMOnlineNumByChannel", name = "channelNum", vector = true},
			{type = "string", name = "token"},
		},
	},

	{
		define = "class", name = "MsgGMRequest", category = "MSG_CATEGORY_GM", id = 226, base = "Message",
		attributes =
		{
			{type = "string", name = "request"},
		},
	},

	{
		define = "class", name = "MsgGMResponse", category = "MSG_CATEGORY_GM", id = 227, base = "Message",
		attributes =
		{
			{type = "string", name = "response"},
		},
	},

	{
		define = "class", name = "MsgGMPing", category = "MSG_CATEGORY_GM", id = 228, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMPong", category = "MSG_CATEGORY_GM", id = 229, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGMGetPlayerInfoRequestNew", category = "MSG_CATEGORY_GM", id = 300, base = "Message",
		attributes =
		{
			{type = "string", name = "playername"},
			{type = "string", name = "type"},
		},
	},

	{
		define = "class", name = "MsgGMGetPlayerInfoResponseNew", category = "MSG_CATEGORY_GM", id = 301, base = "Message",
		attributes =
		{
			{type = "string", name = "playername"},
			{type = "string" , name = "type" },
			{type = "string" , name = "subtype" },
			{type = "KeyValueData", name = "data", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgGMRecordInfoResponseNew", category = "MSG_CATEGORY_GM", id = 302, base = "Message",
		attributes =
		{
			{type = "string", name = "playername"},
			{type = "string", name = "type"},
			{type = "string" , name = "subtype" },
			{type = "string", name = "title", vector = true},
			{type = "string", name = "data", vector = true},
		},
	},

	{
		define = "struct", name = "GMHolidayProp",
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "string", name = "value"},
		},
	},

	{
		define = "struct", name = "GMHolidayItem",
		attributes =
		{
			{type = "int32", name = "index"},
			{type = "int32", name = "static_id"},
			{type = "int32", name = "count"},
			{type = "int32", name = "bind"},
			{type = "int32", name = "type"},
			{type = "GMHolidayProp", name = "vprop", vector = true},
		},
	},

	{
		define = "struct", name = "GMHolidayGrade",
		attributes =
		{
			{type = "int32", name = "index"},
			{type = "int32", name = "mark"},
			{type = "string", name = "content"},			
			{type = "GMHolidayProp", name = "vprop", vector = true},
			{type = "GMHolidayItem", name = "vitem", vector = true},
		},
	},
	
	{
		define = "struct", name = "GMHoliday",
		attributes =
		{
			{type = "int32", name = "mark"},
			{type = "int32", name = "type"},
			{type = "string", name = "str_menu"},
			{type = "string", name = "str_title"},
			{type = "string", name = "str_content"},
			{type = "string", name = "begin_time"},
			{type = "string", name = "begin_show_time"},
			{type = "string", name = "end_time"},
			{type = "string", name = "end_show_time"},
			{type = "int32", name = "state"},
			{type = "GMHolidayProp", name = "vprop", vector = true},
			{type = "GMHolidayGrade", name = "vgrade", vector = true},
		},
	},

	{
		define = "class", name = "MsgUpdateGMHolidayRequest", category = "MSG_CATEGORY_GM", id = 400, base = "Message",
		attributes =
		{
			{type = "int32", name = "mark_id"},
		},
	},

	{
		define = "class", name = "MsgUpdateGMHolidayResponse", category = "MSG_CATEGORY_GM", id = 401, base = "Message",
		attributes =
		{
			{type = "GMHoliday", name = "holiday"},
		},
	},

	{
		define = "class", name = "MsgGMHolidayGRankValueAddRequest", category = "MSG_CATEGORY_GM", id = 402, base = "Message",
		attributes =
		{
			{type = "int32", name = "server_id"},
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "job"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "value"},
			{type = "int32", name = "flag"},
		},
	},

	{
		define = "class", name = "MsgGMHolidayGRankValueAddResponse", category = "MSG_CATEGORY_GM", id = 403, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "struct", name = "GMHolidayGRankData",
		attributes =
		{
			{type = "int32", name = "server_id"},
			{type = "string", name = "server_name"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "job"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "value"},
			{type = "string", name = "time"},
		},
	},

	{
		define = "class", name = "MsgGMHolidayGRankRequest", category = "MSG_CATEGORY_GM", id = 404, base = "Message",
		attributes =
		{
			{type = "int32", name = "server_id"},
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "is_end"},
			{type = "string", name = "begin_time"},
			{type = "string", name = "end_time"},
			{type = "int32", name = "count"},
			{type = "int32", name = "server_group"},
		},
	},

	{
		define = "class", name = "MsgGMHolidayGRankResponse", category = "MSG_CATEGORY_GM", id = 405, base = "Message",
		attributes =
		{		
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "is_end"},
			{type = "GMHolidayGRankData", name = "vglobalrank", vector = true},
		},
	},

	{
		define = "class", name = "MsgGMHolidayNoteRequest", category = "MSG_CATEGORY_GM", id = 406, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
			{type = "int32", name = "account_id"},
			{type = "int32", name = "server_id"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
			{type = "string", name = "begin_time"},
		},
	},

	{
		define = "class", name = "MsgGMHolidayNoteResponse", category = "MSG_CATEGORY_GM", id = 407, base = "Message",
		attributes =
		{		
			{type = "int32", name = "pid"},
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
		},
	},
	
	{
		define = "class", name = "MsgGMGetBlackListRequest", category = "MSG_CATEGORY_GM", id = 416, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverId"},
		},
	},
	
	{
		define = "class", name = "MsgGMGetBlackListResponse", category = "MSG_CATEGORY_GM", id = 417, base = "Message",
		attributes =
		{
			{type = "int32", name = "blackList", vector = true},
		},
	},
	
	{
		define = "struct", name = "ServerCommonInfo",
		attributes =
		{
			{type = "string", name = "serverName"},
			{type = "int32", name = "serverId"},
		},
	},
	
	{
		define = "struct", name = "WarZoneInfo",
		attributes =
		{
			{type = "int32", name = "warZoneServerId", desc="战区所在的服务器的id"},
			{type = "string", name = "warZoneServerName", desc="战区所在的服务器的名称"},
			{type = "int16", name = "warZoneLineId", desc="战区的分线id"},
			{type = "int32", name = "warZonePreOpenTime", desc="战区的预开启时间"},
			{type = "int32", name = "warZoneOpenTime", desc="战区的正式开启时间"},
			{type = "ServerCommonInfo", name = "gameServerInfoList", vector = true, desc="该战区内的所有游戏服信息"},
		},
	},
	
	{
		define = "class", name = "MsgGMWarZoneNotifyStart", category = "MSG_CATEGORY_GM", id = 421, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgGMWarZoneNotify", category = "MSG_CATEGORY_GM", id = 422, base = "Message",
		attributes =
		{
			{type = "WarZoneInfo", name = "infoList", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgGMWarZoneNotifyEnd", category = "MSG_CATEGORY_GM", id = 423, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgJuHeLoginRequest", category = "MSG_CATEGORY_GM", id = 427, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "应用编号"},
			{type = "int32", name = "packageId", desc = "分包编号"},
			{type = "string", name = "deviceId", desc = "设备id"},
			{type = "string", name = "ip", desc = "ip地址"},
			{type = "string", name = "data", desc = "json数据"},
			{type = "string", name = "openId", desc = "账号唯一标识"},
			{type = "string", name = "token", desc = "中通行凭证"},
		},
	},

	{
		define = "struct", name = "UserData",
		attributes =
		{
			{type = "int32", name = "uid"},
			{type = "int32", name = "packageId"},
			{type = "int32", name = "sdkId"},
			{type = "string", name = "uin"},
			{type = "string", name = "deviceId"},
			{type = "string", name = "ip"},
			{type = "int32", name = "createTime"},
			{type = "string", name = "extn"},
		},
	},

	{
		define = "class", name = "MsgJuHeLoginResponse", category = "MSG_CATEGORY_GM", id = 424, base = "Message",
		attributes =
		{
			{type = "UserData", name = "userData", vector = true},
			{type = "string", name = "msg", desc = "提示信息"},
			{type = "int16" , name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgJuHePayRequest", category = "MSG_CATEGORY_GM", id = 426, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "应用编号"},
			{type = "int32", name = "packageId", desc = "分包编号"},
			{type = "string", name = "deviceId", desc = "设备id"},
			{type = "int32", name = "aid", desc = "ip地址"},
			{type = "string", name = "money", desc = "ip地址"},
			{type = "string", name = "ip", desc = "ip地址"},
			{type = "string", name = "cpExt", desc = "json数据"},
			{type = "string", name = "serverName", desc = "账号唯一标识"},
			{type = "string", name = "roleName", desc = "中通行凭证"},
			{type = "int32", name = "sdkId", desc = "sdk编号"},
			{type = "int32", name = "sessionId", desc = "sdk编号"},
			{type = "string", name = "openId", desc = "账号唯一标识"},
			{type = "string", name = "appKey", desc = "中通行凭证"},
		},
	},

	{
		define = "class", name = "MsgJuHePayResponse", category = "MSG_CATEGORY_GM", id = 428, base = "Message",
		attributes =
		{
			{type = "string", name = "orderId", desc = "订单编号"},
			{type = "int32" , name = "errcode"},
			{type = "int32" , name = "sessionId"},
			{type = "string", name = "msg", desc = "提示信息"},
		},
	},
	
	{
		define = "struct", name = "VisitorLoginData",
		attributes =
		{
			{type = "int32", name = "appId"},
			{type = "int32", name = "packageId"},
			{type = "string", name = "deviceId"},
			{type = "string", name = "deviceUin"},
			{type = "string", name = "ip"},
			{type = "string", name = "appKey"},
		},
	},
	
	{
		define = "struct", name = "AccountLoginData",
		attributes =
		{
			{type = "int32", name = "appId"},
			{type = "int32", name = "packageId"},
			{type = "string", name = "account"},
			{type = "string", name = "password"},
			{type = "string", name = "deviceId"},
			{type = "string", name = "ip"},
			{type = "string", name = "appKey"},
		},
	},
	
	{
		define = "struct", name = "VerificationLoginData",
		attributes =
		{
			{type = "int32", name = "appId"},
			{type = "int32", name = "packageId"},
			{type = "string", name = "deviceId"},
			{type = "string", name = "ip"},
			{type = "string", name = "username"},
			{type = "string", name = "verification"},
			{type = "string", name = "appKey"},
		},
	},
	
	{
		define = "struct", name = "responseData",
		attributes =
		{
			{type = "string", name = "openId"},
			{type = "string", name = "token"},
			{type = "string", name = "nickName", desc = "游客编号(1是游客. 其他是空字符串"},
		},
	},
	
	
	
	{
		define = "class", name = "MsgIosResetPwdRequest", category = "MSG_CATEGORY_GM", id = 431, base = "Message",
		attributes =
		{
			{type = "string", name = "username", desc = "用户名"},
			{type = "int32", name = "appId", desc = "应用编号"},
			{type = "string", name = "ip", desc = "ip地址"},
			{type = "string", name = "verification", desc = "验证码"},
			{type = "string", name = "password", desc = "新密码"},
		},
	},

	{
		define = "class", name = "MsgIosResetPwdResponse", category = "MSG_CATEGORY_GM", id = 432, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error", desc = "错误码"},
			{type = "string" , name = "msg", desc = "登录结果"},
		},
	},
	
	{
		define = "class", name = "MsgIosBandPhoneOrEmailRequest", category = "MSG_CATEGORY_GM", id = 433, base = "Message",
		attributes =
		{
			{type = "string", name = "deviceId", desc = "设备唯一标识"},
			{type = "string", name = "deviceUin", desc = "游客唯一标志"},
			{type = "int32", name = "appId", desc = "app编号"},
			{type = "int32", name = "packageId", desc = "分包编号"},
			{type = "string", name = "phone", desc = "手机号"},
			{type = "string", name = "email", desc = "email地址"},
			{type = "string", name = "verification", desc = "验证码"},
			{type = "string", name = "password", desc = "密码"},
		},
	},

	{
		define = "class", name = "MsgIosBandPhoneOrEmailResponse", category = "MSG_CATEGORY_GM", id = 434, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error", desc = "错误码"},
			{type = "string" , name = "msg", desc = "提示信息"},
			{type = "string", name = "token", desc = "同行凭证"},
		},
	},

	{
		define = "class", name = "MsgIosSendVerificationRequest", category = "MSG_CATEGORY_GM", id = 435, base = "Message",
		attributes =
		{
			{type = "string", name = "username", desc = "用户名"},
			{type = "int32", name = "appId", desc = "应用编号"},
			{type = "string", name = "appKey", desc = "app密钥"},
		},
	},

	{
		define = "class", name = "MsgIosSendVerificationResponse", category = "MSG_CATEGORY_GM", id = 436, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error", desc = "错误码"},
			{type = "string" , name = "msg", desc = "登录结果"},
		},
	},

	{
		define = "class", name = "MsgIosLoginRequest", category = "MSG_CATEGORY_GM", id = 437, base = "Message",
		attributes =
		{
			{type = "int32", name = "loginType", desc = "1.游客登陆 2.账号登录 3.验证码登陆"},
			{type = "VisitorLoginData", name = "visitorLoginData", desc = "登录数据:每种登录场合参照下方参数"},
			{type = "AccountLoginData", name = "accountLoginData", desc = "登录数据:每种登录场合参照下方参数"},
			{type = "VerificationLoginData", name = "VerLoginData",  desc = "登录数据:每种登录场合参照下方参数"},
		},
	},

	{
		define = "class", name = "MsgIosLoginResponse", category = "MSG_CATEGORY_GM", id = 438, base = "Message",
		attributes =
		{
			{type = "responseData", name = "resdata", desc = "登录结果信息"},
			{type = "string" , name = "msg", desc = "登录结果"},
			{type = "int32" , name = "error", desc = "错误码"},
		},
	},

	{
		define = "class", name = "MsgGMChatVeriPhoneRequest", category = "MSG_CATEGORY_GM", id = 439, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "订单编号"},
			{type = "string" , name = "openId"},
			{type = "string", name = "mobile", desc = "手机号"},
			{type = "string", name = "verifyCode", desc = "手机号"},
			{type = "int32", name = "sessionId", desc = "手机号"},
		},
	},

	{
		define = "class", name = "MsgGMChatVeriPhoneResponse", category = "MSG_CATEGORY_GM", id = 440, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error"},
			{type = "string" , name = "message"},
			{type = "int32", name = "sessionId", desc = "手机号"},
		},
	},

	{
		define = "class", name = "MsgGMChatVeriCodeRequest", category = "MSG_CATEGORY_GM", id = 441, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "订单编号"},
			{type = "string" , name = "openId"},
			{type = "string", name = "mobile", desc = "手机号"},
			{type = "int32", name = "sessionId", desc = "手机号"},
		},
	},

	{
		define = "class", name = "MsgGMChatVeriCodeResponse", category = "MSG_CATEGORY_GM", id = 442, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error"},
			{type = "string" , name = "message"},
			{type = "int32", name = "sessionId", desc = "手机号"},
		},
	},

	{
		define = "class", name = "MsgIosPERegisterRequest", category = "MSG_CATEGORY_GM", id = 443, base = "Message",
		attributes =
		{
			{type = "string", name = "ip", desc = "订单编号"},
			{type = "string" , name = "username"},
			{type = "int32", name = "appId", desc = "订单编号"},
			{type = "string" , name = "appKey"},
			{type = "string", name = "verification", desc = "手机号"},
			{type = "string", name = "password", desc = "手机号"},
		},
	},

	{
		define = "class", name = "MsgIosPERegisterResponse", category = "MSG_CATEGORY_GM", id = 444, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error"},
			{type = "string" , name = "message"},
		},
	},

    {
		define = "class", name = "MsgGetChannelTuoGuanCntRequest", category = "MSG_CATEGORY_GM", id = 501, base = "Message",
		attributes =
		{
			{type = "string", name = "token"},
		},
	},

	{
		define = "class", name = "MsgGetChannelTuoGuanCntResponse", category = "MSG_CATEGORY_GM", id = 502, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverId"},
			{type = "int32", name = "onlineTotal"},
			{type = "GMOnlineNumByChannel", name = "channelNum", vector = true},
			{type = "string", name = "token"},
		},
	},
	{
		define = "class", name = "MsgGMWarZoneNotifyRequest", category = "MSG_CATEGORY_GM", id = 503, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverList", vector = true},
		},
	},
	{
		define = "class", name = "MsgGMWarZoneNotifyResponse", category = "MSG_CATEGORY_GM", id = 504, base = "Message",
		attributes =
		{
			{type = "int32", name = "serverList", vector = true},
		},
	},
	
	
	{
		define = "class", name = "MsgNewRechargeReturnRequest", category = "MSG_CATEGORY_GM", id = 505, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name = "channel_id", desc = "渠道ID"},
			{type = "string", name = "begin_time", desc = "开始时间"},
			{type = "string", name = "end_time", desc = "结束时间"},
			{type = "int32", name = "client_session_id", desc = "玩家会话ID"},
			{type = "int16", name = "player_class", desc = "玩家职业"},
			{type = "string", name = "player_name", desc = "玩家名称"},
			{type = "int8", name = "player_gender", desc = "玩家性别"},
            {type = "int32", name = "pid", desc = "玩家id"},
		},
	},

	
	{
		define = "struct", name = "Privilege",
		attributes =
		{
			{type = "int32", name = "p_type"},
			{type = "int32", name = "p_num"},
		},
	},


	{
		define = "class", name = "MsgNewRechargeReturnResponse", category = "MSG_CATEGORY_GM", id = 506, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name = "channel_id", desc = "渠道ID"},
			{type = "string", name = "begin_time", desc = "开始时间"},
			{type = "string", name = "end_time", desc = "结束时间"},
			{type = "int32", name = "client_session_id", desc = "玩家会话ID"},
			{type = "int16", name = "player_class", desc = "玩家职业"},
			{type = "string", name = "player_name", desc = "玩家名称"},
			{type = "int8", name = "player_gender", desc = "玩家性别"},
			{type = "int32", name = "recharge", desc = "充值金额"},
			{type = "Privilege", name = "privilege" , desc = "特权" ,vector = true},
			{type = "int32", name = "player_level", desc = "等级"},
            {type = "int32", name = "pid", desc = "玩家id"},
		},
	},

	{
		define = "class", name = "MsgWebPayActivityProductsRequest", category = "MSG_CATEGORY_GM", id = 516, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "activityId"},
		},
	},
	{
		define = "class", name = "MsgWebPayActivityProductsResponse", category = "MSG_CATEGORY_GM", id = 517, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "activityId"},
			{type = "string", name = "jsondata"},

		},
	},

	{
		define = "class", name = "MsgWebPayRechargeRequest", category = "MSG_CATEGORY_GM", id = 518, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
			{type = "string", name = "OrderSerial"},
			{type = "string", name = "ext"},

		},
	},

	{
		define = "class", name = "MsgWebPaySelecetItemsRequest", category = "MSG_CATEGORY_GM", id = 519, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "productId"},
		},
	},

	{
		define = "class", name = "MsgWebPaySelecetItemsResponse", category = "MSG_CATEGORY_GM", id = 520, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "productId"},
			{type = "string", name = "jsondata"},

		},
	},

	{
	    define = "class", name = "MsgGMHolidayResultRequest", category = "MSG_CATEGORY_GM", id = 535, base = "Message",
	    attributes =
	    {    
		    {type = "int32",  name = "code"},
		    {type = "string",  name = "cnMsg"}, --错误中文类型（例:活动属性错误）
		    {type = "string",  name = "msg"},
		    {type = "int32",  name = "activityId"},
		    {type = "int32",  name = "serverId"},
	    },
	},
}


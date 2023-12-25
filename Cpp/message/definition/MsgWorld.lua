messages =
{
	{
		define = "class", name = "MsgSyncWorldDataNotify", category = "MSG_CATEGORY_WORLD", id = 100, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas",},
		},
	},

	{
		define = "class", name = "MsgSyncWorldDataExNotify", category = "MSG_CATEGORY_WORLD", id = 101, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int32", name = "data", vector = true},
			{type = "string", name = "str", vector = true},
		},
	},

	{
		define = "class", name = "MsgSyncWorldDataStringRequest", category = "MSG_CATEGORY_WORLD", id = 102, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int16", name = "version"},
		},
	},

	{
		define = "class", name = "MsgSyncWorldDataStringResponse", category = "MSG_CATEGORY_WORLD", id = 103, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int16", name = "version"},
			{type = "string", name = "datas",},
		},
	},

	{
		define = "class", name = "MsgSyncWorldDataRequest", category = "MSG_CATEGORY_WORLD", id = 104, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int16", name = "version"},
		},
	},

	{
		define = "class", name = "MsgSyncWorldDataResponse", category = "MSG_CATEGORY_WORLD", id = 105, base = "Message",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int16", name = "version"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgSyncFloatNoticeNotify", category = "MSG_CATEGORY_WORLD", id = 110, base = "Message",
		attributes =
		{
			{type = "string", name = "basestring"},
			{type = "int32", name = "showflag"},
			{type = "string", name = "TouchID"},

		},
	},

	{
		define = "struct", name = "BossData",
		attributes =
		{
			{type = "int32", name = "eventid"},
			{type = "int32", name = "bossid"},
			{type = "int32", name = "bossexp"},
			{type = "int16", name = "bossstate"},
			{type = "int32", name = "killpid"},
			{type = "string", name = "killname"},
		},
	},

	{
		define = "class", name = "MsgSyncWorldBossNotify", category = "MSG_CATEGORY_WORLD", id = 120, base = "Message",
		attributes =
		{
			{type = "BossData", name = "Bosses", vector = true},
		},
	},

	{
		define = "struct", name = "ChartIntData",
		attributes =
		{
			{type = "int16", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "struct", name = "ChartStrData",
		attributes =
		{
			{type = "int16", name = "idx"},
			{type = "string", name = "data"},
		},
	},

	{
		define = "struct", name = "ChartElem",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "ChartIntData", name = "nums", vector = true},
			{type = "ChartStrData", name = "strs", vector = true},
		},
	},

	{
		define = "class", name = "MsgGetWorldChartResponse", category = "MSG_CATEGORY_WORLD", id = 131, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGetWorldChartNotify", category = "MSG_CATEGORY_WORLD", id = 132, base = "Message",
		attributes =
		{
			{type = "int16", name = "charttype"},
			{type = "ChartElem", name = "charts", vector = true},
			{type = "int32", name = "version"},
			{type = "int16", name = "posttimes"},
			{type = "int16", name = "selfrank"},

		},
	},

	{
		define = "class", name = "MsgSyncWorldBeginTimeNotify", category = "MSG_CATEGORY_WORLD", id = 140, base = "Message",
		attributes =
		{
			{type = "int32", name = "Begintime"},
		},
	},

	{
		define = "class", name = "MsgSyncServerDaysNotify", category = "MSG_CATEGORY_WORLD", id = 141, base = "Message",
		attributes =
		{
			{type = "int32", name = "server_days"},
			{type = "int32", name = "hefu_days"},
		},
	},

	{
		define = "class", name = "MsgSyncServerTimeNotify", category = "MSG_CATEGORY_WORLD", id = 142, base = "Message",
		attributes =
		{
			{type = "int32", name = "time"},
		},
	},

	{
		define = "class", name = "MsgSyncCrossServerDaysNotify", category = "MSG_CATEGORY_WORLD", id = 153, base = "Message",
		attributes =
		{
			{type = "int32", name = "server_days"},
		},
	},

	{
		define = "class", name = "MsgAddArenaRewardNotify", category = "MSG_CATEGORY_WORLD", id = 300, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "rank"},
			{type = "int32", name = "endtime"},
			{type = "int16", name = "type"},
		},
	},

	{
		define = "class", name = "MsgAddGiftDataNotify", category = "MSG_CATEGORY_WORLD", id = 301 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "gifttype"},
			{type = "int32", name = "data"},
			{type = "int32", name = "endtime"},
		},
	},

	{
		define = "class", name = "MsgSyncSwitchNotify", category = "MSG_CATEGORY_WORLD", id = 302, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "sub_id"},
			{type = "int8", name = "disabled"},
		},
	},
	{
		define = "class", name = "MsgAddSensitiveWordNotify", category = "MSG_CATEGORY_WORLD", id = 303, base = "Message",
		attributes =
		{
			{type = "string", name = "words", vector = true},
		},
	},
	{
		define = "class", name = "MsgDelSensitiveWordNotify", category = "MSG_CATEGORY_WORLD", id = 304, base = "Message",
		attributes =
		{
			{type = "string", name = "words", vector = true},
		},
	},

	{
		define = "struct", name = "ChannelPropData",
		attributes =
		{
			{type="int32", name="cid", desc = "渠道ID"},
			{type="int32", name="id", desc = "属性ID"},
			{type="int32", name="val", desc = "属性值"},
		}
	},

	{
		define = "class", name = "MsgSyncChannelPropsNotify", category = "MSG_CATEGORY_WORLD", id = 305, base = "Message",
		attributes =
		{
			{type="ChannelPropData", name="props", vector=true},
		},
	},

	{
		define = "class", name = "MsgSyncHefuDateNotify", category = "MSG_CATEGORY_WORLD", id = 143, base = "Message",
		attributes =
		{
			{type = "int32", name = "hefu_date"},
			{type = "int32", name = "hefu_time"},
			{type = "int32", name = "hfhd_enabled"},
		},
	},

   {
		-- 开服活动五个竞技
		define = "class", name = "MsgOperatingGroupRequest", category = "MSG_CATEGORY_WORLD", id = 144, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
		},
	},

    {
		-- 开服活动五个竞技
		define = "class", name = "MsgOperatingGroupResponse", category = "MSG_CATEGORY_WORLD", id = 145, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "type"},

		},
	},

	{
		define = "class", name = "MsgSyncWorldBossFreshPower", category = "MSG_CATEGORY_WORLD", id = 146, base = "Message",
		attributes =
		{
			{type = "int16", name = "power"},
		},
	},
	{
		define = "class", name = "MsgSyncDiamondRecoverRequest", category = "MSG_CATEGORY_WORLD", id = 147, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgSyncSystemAnnouncement", category = "MSG_CATEGORY_WORLD", id = 148, base = "Message",
		attributes =
		{
			{type = "string", name = "basestring"},
			{type = "string", name = "TouchID"},
			{type = "int32", name = "ItemSid"},
			{type = "int32", name = "showflag"},
		},
	}, 
	{
		define = "class", name = "MsgRemoveChatNotify", category = "MSG_CATEGORY_WORLD", id = 151, base = "Message",
		attributes =
		{
			{type="int32", name="pid"},
		},
	},
	{
		define = "class", name = "MsgSyncEventStateNotify", category = "MSG_CATEGORY_WORLD", id = 152, base = "Message",
		attributes =
		{
			{type = "int32", name = "eventtimeid"},
			{type = "int32", name = "eventstate"},
		},
	},
}


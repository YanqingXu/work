messages = {
	{
		define = "struct" , name = "DBWorldData",
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas" },
			{type = "int32", name = "uptime"},
		},
	},
	{
		define = "class", name="MsgDBLoadWorldData",category = "MSG_CATEGORY_DB_WORLD" , id = 1 ,base = "MessageEx",
		attributes =
		{
			{type = "DBWorldData", name = "data", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdWorldData", category = "MSG_CATEGORY_DB_WORLD" , id = 2, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "wid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas" },
		},
	},

	{
		define = "class", name = "MsgDBServerID", category = "MSG_CATEGORY_DB_WORLD" , id = 3, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "server_id"},
			{type = "int16", name = "register_server_id"},
		},
	},
	{
		define = "struct" , name = "DBChannelProp",
		attributes =
		{
			{type = "int32", name = "cid"},
			{type = "int32", name = "id"},
			{type = "int32", name = "val"},
		},
	},
	{
		define = "class", name="MsgDBLoadChannelProps",category = "MSG_CATEGORY_DB_WORLD" , id = 4 ,base = "MessageEx",
		attributes =
		{
			{type = "DBChannelProp", name = "props", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdateChannelProp", category = "MSG_CATEGORY_DB_WORLD" , id = 5, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "cid"},
			{type = "int32", name = "id"},
			{type = "int32", name = "val"},
		},
	},

	{
		define = "struct" , name = "DBSwitch",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "sub_id"},
			{type = "int8", name = "disabled"},
		},
	},
	{
		define = "class", name="MsgDBLoadSwitch", category = "MSG_CATEGORY_DB_WORLD", id = 108, base = "MessageEx",
		attributes =
		{
			{type = "DBSwitch", name = "switchs", vector = true},
		},
	},
	{
		define = "class", name="MsgDBEnableSwitch", category = "MSG_CATEGORY_DB_WORLD", id = 109, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "sub_id"},
		},
	},
	{
		define = "class", name="MsgDBDisableSwitch", category = "MSG_CATEGORY_DB_WORLD", id = 110, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "sub_id"},
		},
	},
	
	{
		define = "struct" , name = "DBWorldPlayerExData",
		attributes =
		{
			{type = "int32", name = "data"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int8",  name = "gender"},
			{type = "int8"	, name = "clazz"},
			{type = "int32"	, name = "reborn"},
			{type = "int32"	, name = "level"},
			{type = "string", name = "guild"},
			{type = "int32"	, name = "zhanli"},
            {type = "int32"	, name = "weapon"},
            {type = "int32"	, name = "cloth"},
            {type = "int32"	, name = "wings"},
		},
	},


	{
		define = "class", name = "MsgDBLoadTeams", category = "MSG_CATEGORY_DB_WORLD", id = 124, base = "MessageEx",
		attributes=
		{
			{type = "int32", name = "type"},
			{type = "DBWorldPlayerExData", name = "datas", vector = true},
		},
	},

	{
		define = "struct" , name = "DBWorldFireworks",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int32", name = "bless"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "lvl"},
		},
	},

	{
		define = "struct" , name = "DBPlayerReward",
		attributes =
		{
			{type = "int32", name = "idx" },
			{type = "int32", name = "type"},
			{type = "int32", name = "rewardid"},
			{type = "int32", name = "endtime" },
		},
	},

	{
		define = "class", name = "MsgDBLoadAuthRewardIDRequest", category = "MSG_CATEGORY_DB_WORLD", id = 199, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "rewardid", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerRewardData", category = "MSG_CATEGORY_DB_WORLD", id = 200, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBPlayerReward", name = "datas", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBInsertPlayerRewardData", category = "MSG_CATEGORY_DB_WORLD", id = 201, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "idx" },
			{type = "int32", name = "type"},
			{type = "int32", name = "rewardid"},
			{type = "int32", name = "endtime" },
		},
	},

	{
		define = "class", name = "MsgDBDeletePlayerRewardData", category = "MSG_CATEGORY_DB_WORLD", id = 202, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "idx" },
		},
	},


	{
		define = "struct" , name = "DBPlayersqldata",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "string", name = "name"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay" },
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerDataBySql", category = "MSG_CATEGORY_DB_WORLD", id = 300, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "dx"},
			{type = "int32", name = "dy"},
			{type = "int32", name = "dz"},
			{type = "string", name = "sqlstr"},
			{type = "DBPlayersqldata", name = "loaddata", vector = true},
		},
	},
	
	{
		define = "struct" , name = "DBPlayerInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
		},
	},
	
	{
		define = "class", name = "MsgDBLoadNextIDs", category = "MSG_CATEGORY_DB_WORLD", id = 312, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "next_pid"},
			{type = "int32", name = "next_gid"},
			{type = "DBPlayerInfo", name = "infos", vector = true},
		},
	},

	--开服活动-消费夺宝
	{
		define = "class", name = "MsgDBLoadKfhdXfdb", category = "MSG_CATEGORY_DB_WORLD", id = 313, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "index"},
			{type = "DBPlayersqldata", name = "loaddata", vector = true},
		},
	},

	--开服活动-消费排行
	{
		define = "class", name = "MsgDBLoadKfhdXfph", category = "MSG_CATEGORY_DB_WORLD", id = 314, base = "MessageEx",
		attributes =
		{
			{type = "DBPlayersqldata", name = "loaddata", vector = true},
		},
	},

    {
        define = "struct" , name = "DBWorldActivityGuess",
        attributes =
        {
            {type = "int32", name = "pid"},
            {type = "string", name = "name"},
            {type = "int32", name = "datax"},
        },
    },

    {
        define = "class", name = "MsgDBActivityQmjc", category = "MSG_CATEGORY_DB_WORLD", id = 317, base = "MessageEx",
        attributes=
        {
            {type = "int32", name = "guessResult"},
            {type = "int32", name = "guessTime"},
            {type = "DBWorldActivityGuess", name = "datas", vector = true},
        },
    },

    {
        define = "class", name = "MsgDBLoadWorldContinueDayPlayerNum", category = "MSG_CATEGORY_DB_WORLD", id = 319, base = "MessageEx",
        attributes=
        {
            {type = "int16", name = "type"},--类型
            {type = "int32", name = "num"},--数量
        },
    },

	--加载激活码
	{
		define = "struct" , name = "DBCreateRoleCode",
		attributes =
		{
			{type = "string", name = "code" },
			{type = "int32", name = "spid"},
			{type = "int32", name = "dpid" },
			{type = "int32", name = "state" },
		},
	},
	
	{
		define = "class", name = "MsgDBCreateRoleCodeLoad", category = "MSG_CATEGORY_DB_WORLD", id = 325, base = "MessageEx",
		attributes =
		{
			{type = "DBCreateRoleCode", name = "loaddata", vector = true},
		},
	},
	
		--生成激活码
	{
		define = "class", name = "MsgDBCreateRoleCodeAdd", category = "MSG_CATEGORY_DB_WORLD", id = 326, base = "MessageEx",
		attributes =
		{
			{type = "string", name = "code" },
			{type = "int32", name = "spid"},
		},
	},
	
	--领取激活码
	{
		define = "class", name = "MsgDBCreateRoleCodeUse", category = "MSG_CATEGORY_DB_WORLD", id = 327, base = "MessageEx",
		attributes =
		{
			{type = "string", name = "code" },
			{type = "int32", name = "dpid" },
		},
	},

	{
		define = "class", name = "MsgDBDeleteSomeOneProp", category = "MSG_CATEGORY_DB_WORLD" , id = 338, base = "MessageEx", send_back = false,
		attributes =
		{

			{type = "int32", name = "prop"},
		},
	},

	{
		define = "struct" , name = "DBLoadTgmjTower",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int32", name = "level"},
			{type = "int32", name = "round"},
			{type = "int32", name = "job"},
			{type = "int32", name = "reborn"},
            {type = "int32", name = "gender"},
			{type = "string", name = "guildname" },
			{type = "int32"	, name = "weapon"},
            {type = "int32"	, name = "cloth"},
            {type = "int32"	, name = "wings"},
            {type = "int32"	, name = "viplevel"},
            {type = "int32"	, name = "fishioncloth"},
            {type = "int32", name = "ranktime" },
            {type = "int32", name = "fashionweapon" },
          	{type = "int32", name = "wing" },
          	{type = "int32", name = "shield" },
			{type = "int32", name = "lingwen"},
            {type = "int32", name = "fabao"},
		},
	},

	{
		define = "class", name="MsgDBClearSCDonate", category = "MSG_CATEGORY_DB_WORLD", id = 359, base = "MessageEx", send_back = false,
		attributes =
		{
		},
	},

	{
		define = "struct" , name = "DBWorldPlayerWxsyData",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int32", name = "job"},
			{type = "int32", name = "level"},
            {type = "int32", name = "gender"},
			{type = "string", name = "guildname" },
         	{type = "int32"	, name = "wings"},
            {type = "int32"	, name = "recGate"},
          	{type = "int32", name = "ranktime" },
		},
	},

	{
		define = "struct", name = "DBPidData",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "leavetime"},
			{type = "int32", name = "channelid"},
		},
	},

	{
		define = "class",name = "MsgDBLoadPidInfo" ,category = "MSG_CATEGORY_DB_WORLD", id = 369, base = "MessageEx",
		attributes =
		{
			{type = "DBPidData", name = "pidinfos", vector = true},
		},
	},

	{
		define = "struct", name = "wbpProps",
		attributes =
		{
			{type="int32", name="type"},
			{type="int32", name="value"},
		}
	},

	{
		define = "struct", name = "wbpEvents",
		attributes =
		{
			{type="int32", name="type"},
			{type="int32", name="datax"},
			{type="int32", name="datay"},
			{type="int32", name="dataz"},

		}
	},

	{
		define = "class", name = "MsgDBWepPayPlayerInfo", category = "MSG_CATEGORY_DB_WORLD", id = 377, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "activityId"},
			{type = "wbpProps", name = "props",vector = true },
			{type = "wbpEvents", name = "events",vector = true},
			{type = "wbpProps", name = "backprops",vector = true },
			{type = "wbpEvents", name = "backevents",vector = true},
			{type = "int32", name = "datax"},
		},
	},


	{
		define = "struct" , name = "DBLoadPlayerSCDonate",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int32", name = "svalue"},
			{type = "int32", name = "level"},
			{type = "string", name = "guildname" },
			{type = "int32", name = "ranktime" },
		},
	},

	{
		define = "class", name="MsgDBCreateSCTreasuryDropInfo", category = "MSG_CATEGORY_DB_WORLD", id = 389, base = "MessageEx",
		attributes =
		{
		},
	},

	{
		define = "struct" , name = "DBRankData",
		attributes =
		{
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int32", name = "time", desc = "上榜时间"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "gid"},
			{type = "string", name = "name"},
			{type = "string", name = "guildName"},		
		},
	},

	{
		define = "class", name = "MsgDBLoadRank", category = "MSG_CATEGORY_DB_WORLD", id = 406, base = "MessageEx",
		attributes=
		{		
			{type = "int32", name = "type"},
			{type = "int32", name = "history"},
			{type = "int32", name = "eventId"},
			{type = "int32", name = "minValue",desc = "上榜最低条件"},
			{type = "int32", name = "capacity",desc = "排行榜长度"},
			{type = "int32", name = "total"},
			{type = "int32", name = "timePropId"},
			{type = "string", name = "dataxStr"},
			{type = "string", name = "datayStr"},
			{type = "string", name = "datazStr"},
			{type = "DBRankData", name = "list", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdateRankHistory", category = "MSG_CATEGORY_DB_WORLD", id = 407, base = "MessageEx",
		attributes=
		{
			{type = "int32", name = "type"},
			{type = "DBRankData", name = "list", vector = true},
		},
	},
}

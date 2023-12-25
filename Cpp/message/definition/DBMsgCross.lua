messages =
{
	--创建邮件
	{
		define = "class", name="MsgDBCreateCrossMail", category = "MSG_CATEGORY_DB_CROSS" , id = 1, base = "MessageEx",salt = "pid",
		attributes =
		{
			{type="string", name="pname"},
			{type="int32", name="pid"},
			{type="int32", name="sourceServerId"},
			{type="int32", name="mid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		},
	},
	
	{
		define = "struct", name = "DBPlayerCrossEvent",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "tindex"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerCrossEvent", category = "MSG_CATEGORY_DB_CROSS", id = 2, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBPlayerCrossEvent", name = "events", vector = true},
		},
	},

	{
		define = "struct", name = "DBKF3V3ZhanDui",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "string", name = "zhandui_name"},
			{type = "int32", name = "game_server_id"},
			{type = "string", name = "game_server_name"},
			{type = "int32", name = "score"},
			{type = "int32", name = "score_seq"},
			{type = "int32", name = "score_time"},
			{type = "int32", name = "rank"},
			{type = "int32", name = "top"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiLoad", category = "MSG_CATEGORY_DB_CROSS", id = 11, base = "MessageEx",
		attributes =
		{
			{type = "DBKF3V3ZhanDui", name = "zhanduis", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiAdd", category = "MSG_CATEGORY_DB_CROSS", id = 12, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "string", name = "zhandui_name"},
			{type = "int32", name = "game_server_id"},
			{type = "string", name = "game_server_name"},
			{type = "int32", name = "score"},
			{type = "int32", name = "score_seq"},
			{type = "int32", name = "score_time"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiSetScore", category = "MSG_CATEGORY_DB_CROSS", id = 13, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "score"},
			{type = "int32", name = "score_seq"},
			{type = "int32", name = "score_time"},
		},
	},
	
	{
		define = "class", name = "MsgDBKF3V3ZhanDuiSetRank", category = "MSG_CATEGORY_DB_CROSS", id = 14, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "rank"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiSetTop", category = "MSG_CATEGORY_DB_CROSS", id = 15, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "top"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiSetGameServerId", category = "MSG_CATEGORY_DB_CROSS", id = 16, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "game_server_id"},
			{type = "string", name = "game_server_name"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiDel", category = "MSG_CATEGORY_DB_CROSS", id = 17, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
		},
	},

	{
		define = "struct", name = "DBKF3V3ZhanDuiMember",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "player_id"},
			{type = "string", name = "player_name"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiMemberLoad", category = "MSG_CATEGORY_DB_CROSS", id = 21, base = "MessageEx",
		attributes =
		{
			{type = "DBKF3V3ZhanDuiMember", name = "members", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiMemberAdd", category = "MSG_CATEGORY_DB_CROSS", id = 22, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "player_id"},
			{type = "string", name = "player_name"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiMemberDel", category = "MSG_CATEGORY_DB_CROSS", id = 23, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "player_id"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3ZhanDuiMemberNameChanged", category = "MSG_CATEGORY_DB_CROSS", id = 24, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "player_id"},
			{type = "string", name = "player_name"},
		},
	},

	{
		define = "struct", name = "DBKF3V3Record",
		attributes =
		{
			{type = "int32", name = "competition_id"},
			{type = "int32", name = "zhandui_id1"},
			{type = "string", name = "zhandui_name1"},
			{type = "int32", name = "zhandui_id2"},
			{type = "string", name = "zhandui_name2"},
			{type = "int32", name = "winner"},
			{type = "int32", name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3RecordLoad", category = "MSG_CATEGORY_DB_CROSS", id = 31, base = "MessageEx",
		attributes =
		{
			{type = "DBKF3V3Record", name = "records", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3RecordAdd", category = "MSG_CATEGORY_DB_CROSS", id = 32, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "competition_id"},
			{type = "int32", name = "zhandui_id1"},
			{type = "string", name = "zhandui_name1"},
			{type = "int32", name = "zhandui_id2"},
			{type = "string", name = "zhandui_name2"},
			{type = "int32", name = "winner"},
			{type = "int32", name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgDBKF3V3Clear", category = "MSG_CATEGORY_DB_CROSS", id = 33, base = "MessageEx", send_back = false,
		attributes =
		{
		},
	},

}


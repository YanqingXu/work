messages =
{
	{
		define = "struct" , name = "DBCrossWarSceneData",
		attributes =
		{
			{type = "int32", name = "kf_server_id"},
			{type = "int32", name = "kf_scene_index"},
		},
	},
	
	{
		define = "struct" , name = "DBCenterWorldData",
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
		define = "class", name = "MsgDBLoadCrossWarSceneIndex", category = "MSG_CATEGORY_DBCENTER", id = 1, base = "MessageEx",
		attributes =
		{
			{type = "DBCrossWarSceneData", name = "data", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgDBUpdCrossWarSceneIndex", category = "MSG_CATEGORY_DBCENTER", id = 2, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "kf_server_id", desc = "跨服服务器id"},
			{type = "int32", name = "kf_scene_index", desc = "场景索引"},
		},
	},
	
	{
		define = "class", name="MsgDBLoadCenterWorldData",category = "MSG_CATEGORY_DBCENTER" , id = 9 ,base = "MessageEx",
		attributes =
		{
			{type = "DBCenterWorldData", name = "data", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdCenterWorldData", category = "MSG_CATEGORY_DBCENTER" , id = 10, base = "MessageEx",
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
		define = "struct", name = "DBWarZoneInfo",
		attributes =
		{
			{type = "int32", name = "warZoneId"},
			{type = "string", name = "warZoneServerName", desc="战区所在的服务器的名称"},
			{type = "int64", name = "warZonePreOpenTime", desc="战区的预开启时间"},
			{type = "int64", name = "warZoneOpenTime", desc="战区的正式开启时间"},
			{type = "string", name = "warZoneServerInfoStr", desc="战区内的服务器信息"},
		},
	},
	
	{
		define = "class", name = "MsgDBSaveWarZoneInfo", category = "MSG_CATEGORY_DBCENTER" , id = 11, base = "MessageEx",
		attributes =
		{
			{type = "DBWarZoneInfo", name = "data"},
		},
	},
	
	{
		define = "class", name = "MsgDBLoadWarZoneInfo", category = "MSG_CATEGORY_DBCENTER" , id = 12, base = "MessageEx",
		attributes =
		{
			{type = "DBWarZoneInfo", name = "data", vector = true},
		},
	},
	
	{
		define = "struct", name = "CrossMailInfo",
		attributes =
		{
			{type="int32", name="mailIndex"},
			{type="int32", name="sourceServerId"},
			{type="int32", name="pid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		}
	},

	
	{
		define = "class", name="MsgDBSaveCrossMailInfo", category = "MSG_CATEGORY_DBCENTER" , id = 13, base = "MessageEx",
		attributes =
		{
			{type = "CrossMailInfo", name = "mailInfo"},
		},
	},
	
	{
		define = "class", name="MsgDBDelteCrossMailInfo", category = "MSG_CATEGORY_DBCENTER" , id = 14, base = "MessageEx",
		attributes =
		{
			{type="int32", name="mailIndex"},
		},
	},
	
	{
		define = "class", name="MsgDBLoadCrossMailInfo", category = "MSG_CATEGORY_DBCENTER" , id = 15, base = "MessageEx",
		attributes =
		{
			{type = "CrossMailInfo", name = "mailInfoList", vector = true},
		},
	},
}


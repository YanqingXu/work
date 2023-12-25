messages = {
	{
		define = "struct", name = "DBPlayerData",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "serverID"},
			{type = "int16", name = "mclass"},
			{type = "string", name = "name"},
			{type = "int8", name = "gender"},
			{type = "int32", name = "sceneid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int64", name = "coin"},
			{type = "int32", name = "ingot"},
			{type = "int32", name = "boundingot"},
			{type = "int64", name = "boundcoin"},
			{type = "int32", name = "honor"},
			{type = "int32", name = "guildid"},
			{type = "int32", name = "ctime"},
			{type = "int32", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int64", name = "exp"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "wings"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "team"},
			{type = "int32", name = "is_transfer"},
			{type = "int32", name = "zhandui_id"},
		}
	},

	{
		define = "class", name = "MsgDBLoadPlayerList", category = "MSG_CATEGORY_DB_LOGIN", id = 1, base = "MessageEx", salt="aid",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "DBPlayerData", name = "players", vector = true},
			{type = "int32", name = "channelid"},
			{type = "string", name = "deviceid"},
			{type = "int32", name = "platformid"},
			{type = "int32", name = "serverID"},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayer", category = "MSG_CATEGORY_DB_LOGIN", id = 2, base = "MessageEx", salt="pid",
		attributes =
		{
			{type = "int32", name = "channelid"},
			{type = "string", name = "deviceid"},
			{type = "int32", name = "platformid"},
			{type = "int32", name = "pid"},
			{type = "DBPlayerData", name = "player"},
		},
	},

	{
		define = "class", name="MsgDBCreatePlayer",category = "MSG_CATEGORY_DB_LOGIN" , id = 3 ,base = "MessageEx", salt="pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "aid" },
			{type = "int32", name = "channelid"},
			{type = "string", name = "deviceid"},
			{type = "int32", name = "platformid"},
			{type = "int32", name = "serverID"},
			{type = "int32", name = "recharge_return_original_ingot"},
			{type = "int32", name = "recharge_return_ingot"},
			{type = "string", name = "code"},
			{type = "DBPlayerData", name = "player"},
		},
	},

	{
		define = "class", name="MsgDBDeletePlayer",category = "MSG_CATEGORY_DB_LOGIN" , id = 4 ,base = "MessageEx", salt="pid",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid" },
		},
	},

	{
		define = "class" ,name = "MsgDBLoadPlayerByName", category = "MSG_CATEGORY_DB_LOGIN", id = 5, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "string", name = "name"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int16", name = "mclass"},
			{type = "int8", name = "gender"},
			{type = "int32", name = "sceneid"},
			{type = "int64", name = "coin"},
			{type = "int32", name = "ingot"},
			{type = "int32", name = "boundingot"},
			{type = "int64", name = "boundcoin"},
			{type = "int32", name = "honor"},
			{type = "int32", name = "guildid"},
			{type = "int32", name = "state"},
			{type = "int32", name = "ctime"},
			{type = "int32", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int64", name = "exp"},
		},
	},

	{
		define = "class", name = "MsgDBSetPlayerState", category = "MSG_CATEGORY_DB_LOGIN", id = 6, base = "MessageEx", salt = "pid",
		attributes 	=
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "state"},
			{type = "int32", name = "result"},
		},
	},

	{
		define = "class", name = "MsgDBLoadDummyPlayer", category = "MSG_CATEGORY_DB_LOGIN", id = 7, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "scene_instance_id"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int32", name = "entity_id"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "aid"},
			{type = "int32", name = "exercise"},
			{type = "int32", name = "taoweaplv"},
			{type = "int32", name = "taoweappro"},
			{type = "DBPlayerData", name = "player"},
		},
	},

	{
		define = "class", name = "MsgDBLoadAllTuoguanPlayer", category = "MSG_CATEGORY_DB_LOGIN", id = 8, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "channelid"},
			{type = "string", name = "deviceid"},
			{type = "int32", name = "platformid"},
			{type = "int32", name = "pid"},
			{type = "DBPlayerData", name = "player", vector = true},
		},
	},
	{
		define = "class", name="MsgDBChangeJob", category = "MSG_CATEGORY_DB_LOGIN" , id = 10, base = "MessageEx", salt = "pid", 
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="job"},
		},
	},
}

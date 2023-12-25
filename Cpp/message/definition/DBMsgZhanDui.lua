messages = {

	-- -------------------------------------------------------------------------
	-- 战队
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "DBZhanDui",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "string" ,name = "zhandui_name"},
			{type = "int32", name = "master_id"},
			{type = "string", name = "master_name"},
			{type = "int32",  name = "member_count"},
			{type = "int32",  name = "auto_join_reborn"},
			{type = "int32" , name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiLoad", category = "MSG_CATEGORY_DB_ZHANDUI", id = 1, base = "MessageEx",
		attributes =
		{
			{type = "DBZhanDui", name = "zhanduis", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiCreate", category = "MSG_CATEGORY_DB_ZHANDUI", id = 2, base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "string", name = "zhandui_name"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "auto_join_reborn"},
			{type = "int32", name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiDelete", category = "MSG_CATEGORY_DB_ZHANDUI", id = 3, base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiSetMaster", category = "MSG_CATEGORY_DB_ZHANDUI", id = 4 , base = "MessageEx", salt = "zhandui_id", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name="MsgDBZhanDuiSetName",category = "MSG_CATEGORY_DB_ZHANDUI" , id = 5,base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type="int32", name ="zhandui_id" },
			{type="string", name="name"},
		},
	},
	{
		define = "class", name = "MsgDBZhanDuiSetAutoJoinLevel", category = "MSG_CATEGORY_DB_ZHANDUI", id = 6, base = "MessageEx", salt = "zhandui_id", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "auto_join_reborn"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 战队属性
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "DBZhanDuiExData",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},
	{
		define = "class", name = "MsgDBZhanDuiExDataLoad", category = "MSG_CATEGORY_DB_ZHANDUI", id = 21, base = "MessageEx",
		attributes =
		{

			{type = "DBZhanDuiExData", name = "props", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiExDataUpdate", category = "MSG_CATEGORY_DB_ZHANDUI", id = 22, base = "MessageEx", salt = "zhandui_id", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiExDataUpdateAll", category = "MSG_CATEGORY_DB_ZHANDUI", id = 23, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 战队队员
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "DBZhanDuiMember",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "pid"},
			{type = "string",name = "name"},
			{type = "int32", name = "job"},
			{type = "int16", name = "gender"},
			{type = "int32", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "post"},
			{type = "int32", name = "intime"},
			{type = "int32", name = "recharge"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiMemberLoad",category = "MSG_CATEGORY_DB_ZHANDUI", id = 31, base = "MessageEx",
		attributes =
		{
			{type = "DBZhanDuiMember", name ="members",vector = true},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiMemberUpdate", category = "MSG_CATEGORY_DB_ZHANDUI", id = 32, base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "post"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiMemberDelete", category = "MSG_CATEGORY_DB_ZHANDUI", id = 33 , base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "pid"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 申请加入战队
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "DBZhanDuiApplication",
		attributes =
		{
			{type = "int32" , name = "zhandui_id"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int16", name = "job"},
			{type = "int16", name = "gender"},
			{type = "int32" ,name = "level"},
			{type = "int32" ,name = "reborn"},
			{type = "int32", name = "sponsor_grade"},
			{type = "int32", name = "type"},
			{type = "int32", name = "apptime"},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiApplicationLoad", category = "MSG_CATEGORY_DB_ZHANDUI", id = 41, base = "MessageEx",
		attributes =
		{
			{type = "DBZhanDuiApplication", name = "applications", vector = true},
		},
	},


	{
		define = "class" ,name = "MsgDBZhanDuiApplicationUpdate", category = "MSG_CATEGORY_DB_ZHANDUI", id = 42, base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32" ,name=  "zhandui_id"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class" ,name = "MsgDBZhanDuiApplicationDelete", category = "MSG_CATEGORY_DB_ZHANDUI", id = 43, base = "MessageEx", salt = "zhandui_id",
		attributes =
		{
			{type = "int32" ,name=  "zhandui_id"},
			{type = "int32", name = "pid"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 战队记录
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "DBZhanDuiRecord",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "id" },
			{type = "int16", name = "type" },
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "int32", name = "dataz" },
			{type = "string", name = "name1" },
			{type = "string", name = "name2" },
			{type = "int32", name = "ctime" },
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiRecordLoad",category = "MSG_CATEGORY_DB_ZHANDUI", id = 51, base = "MessageEx",
		attributes =
		{
			{type = "DBZhanDuiRecord", name = "records", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiRecordAdd",category = "MSG_CATEGORY_DB_ZHANDUI", id = 52, base = "MessageEx", salt = "zhandui_id", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "id" },
			{type = "int16", name = "type"},
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "int32", name = "dataz" },
			{type = "string", name = "name1" },
			{type = "string", name = "name2" },
			{type = "int32", name = "ctime" },
		},
	},

	{
		define = "class", name = "MsgDBZhanDuiRecordDel",category = "MSG_CATEGORY_DB_ZHANDUI", id = 53, base = "MessageEx", salt = "zhandui_id", send_back = false,
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int32", name = "ids", vector = true},
		},
	},

}

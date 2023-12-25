messages = {
	{
		define = "struct", name = "DBAccount",
		attributes =
		{
			{type = "int32",     name = "aid"},
			{type = "string",    name = "account"},
			{type = "string",    name = "passwd" },
			{type = "string",	 name = "data"},
		}
	},

	{
		define = "struct", name = "DBRoleCount",
		attributes =
		{
			{type = "int32",     name = "accid"},
			{type = "int32",    name = "svrid"},
			{type = "int32",    name = "count" },
		}
	},

	{
		define = "class", name="MsgDBCreateAccount",category = "MSG_CATEGORY_DB_AUTH" , id = 1 ,base = "MessageEx",
		attributes =
		{
			{type = "DBAccount", name = "m_account"},
			{type = "int8",	 name = "flag"},
		},
	},

	{
		define = "class", name="MsgDBAuthAccount",category = "MSG_CATEGORY_DB_AUTH", id = 2,base = "MessageEx",
		attributes =
		{
			{type = "int8", 	 name = "flag"},
			{type = "DBAccount", name = "m_account"},
		},
	},

	{
		define = "class", name="MsgDBGetRoleCount",category = "MSG_CATEGORY_DB_AUTH", id = 3,base = "MessageEx",
		attributes =
		{
			{type = "int32", 	 name = "aid"},
			{type = "DBRoleCount", name = "RoleCounts", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBAuthBind", category = "MSG_CATEGORY_DB_AUTH", id = 4, base = "MessageEx",
		attributes =
		{
			{type = "int8", 	 name = "flag"},
			{type = "int32",	 name = "type"},
			{type = "DBAccount", name = "m_account"},
		},
	},

}

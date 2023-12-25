messages = {
	{
		define = "class", name="MsgDBChangeCareer",category = "MSG_CATEGORY_DB_TEST" , id = 1 ,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "cid" },
		},
	},

	--{
	--	define = "class", name="MsgChangeDBMessageHandler",category = "MSG_CATEGORY_DB_TEST" , id = 2 ,base = "MessageEx",
	--	 attributes =
	--	 {
	--		{type = "int32", name = "type" },
	--	 },
	--},
}

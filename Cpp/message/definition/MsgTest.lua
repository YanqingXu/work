messages =
{
	{
		define = "class", name = "MsgGMCommand", category = "MSG_CATEGORY_TEST", id = 100, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "string", name = "cmd"},
		},
	},

	{
		define = "class", name = "MsgImprisonPlayer", category = "MSG_CATEGORY_TEST", id = 101, base = "Message",
		attributes =
		{
			{type = "int32", name = "average"},
			{type = "int32", name = "times"},
		},
	},

}


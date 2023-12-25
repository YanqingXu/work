messages =
{
	{
		define = "class", name = "MsgSessionClosed", category = "MSG_CATEGORY_CONTROL", id = 2, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgSessionKick", category = "MSG_CATEGORY_CONTROL", id = 5, base = "Message",
		attributes =
		{
			--{type = "int32", name = "kickSessionID"},
		},
	},

	{
		define = "class", name = "MsgSessionRelease", category = "MSG_CATEGORY_CONTROL", id = 6, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgSessionAged", category = "MSG_CATEGORY_CONTROL", id = 8, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgMulticast", category = "MSG_CATEGORY_CONTROL", id = 10, base = "Message",
		attributes =
		{
			{type = "Message*", name = "m_message"},
			{type = "int32", name = "m_sessions", vector = true},
		},
	},

	{
		define = "class", name = "MsgBroadcast", category = "MSG_CATEGORY_CONTROL", id = 12, base = "Message",
		attributes =
		{
			{type = "Message*", name = "m_message"},
		},
	},

	{
		define = "class", name = "MsgBroadcastToGameServer", category = "MSG_CATEGORY_CONTROL", id = 14, base = "MessageEx",
		attributes =
		{
			{type = "Message*", name = "m_message"},
		},
	},

	{
		define = "class", name = "MsgGameServerSessionClosed", category = "MSG_CATEGORY_CONTROL", id = 15, base = "Message",
		attributes =
		{
		},
	},

}

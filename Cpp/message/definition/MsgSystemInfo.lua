messages =
{
	{
		define = "class", name = "MsgSystemInfoNotify", category = "MSG_CATEGORY_SYSINFO", id = 1, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "string", name = "args", vector = true},
		},
	},

	{
		define = "class", name = "MsgShowPrompt", category = "MSG_CATEGORY_SYSINFO", id = 2, base = "Message",
		attributes =
		{
			{type = "int32", name = "kind"},
			{type = "int32", name = "id"},
			{type = "string", name = "args", vector = true},
		},
	},

	{
		define = "class", name = "MsgShowNote", category = "MSG_CATEGORY_SYSINFO", id = 3, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "id"},
			{type = "string", name = "args", vector = true},
		},
	},

	{
		define = "class", name = "MsgShowTopNote", category = "MSG_CATEGORY_SYSINFO", id = 4, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "string", name = "args", vector = true},
		},
	},

}


messages =
{
	{
		define = "struct", name = "Mail",
		attributes =
		{
			 {type="int32", name="pid"},
			 {type="int32", name="mid"},
			 {type="string", name="title"},
			 {type="string", name="content"},
			 {type="string", name="items"},
			 {type="int8", name="readed"},
			 {type="int8", name="got"},
			 {type="int32", name="ctime"},
		}
	},

	{
		define = "class", name = "MsgSyncMailsNotify", category = "MSG_CATEGORY_MAIL", id = 1, base = "Message",
		attributes =
		{
			{type = "Mail", name = "mails", vector=true},
		},
	},

	{
		define = "class", name = "MsgAddMailNotify", category = "MSG_CATEGORY_MAIL", id = 2, base = "Message",
		attributes =
		{
			{type = "Mail", name = "mail"},
		},
	},

	{
		define = "class", name = "MsgDeleteMailRequest", category = "MSG_CATEGORY_MAIL", id = 3, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
		},
	},

	{
		define = "class", name = "MsgDeleteMailResponse", category = "MSG_CATEGORY_MAIL", id = 4, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgDeleteReadedMailsRequest", category = "MSG_CATEGORY_MAIL", id = 5, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgDeleteReadedMailsResponse", category = "MSG_CATEGORY_MAIL", id = 6, base = "Message",
		attributes =
		{
			{type = "int32", name = "mids", vector=true},
		},
	},

	{
		define = "class", name = "MsgSetMailReadedRequest", category = "MSG_CATEGORY_MAIL", id = 7, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
		},
	},

	{
		define = "class", name = "MsgSetMailReadedResponse", category = "MSG_CATEGORY_MAIL", id = 8, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGetMailItemRequest", category = "MSG_CATEGORY_MAIL", id = 9, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
		},
	},

	{
		define = "class", name = "MsgGetMailItemResponse", category = "MSG_CATEGORY_MAIL", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgRecvMaillAllRequest", category = "MSG_CATEGORY_MAIL", id = 11, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgRecvMaillAllResponse", category = "MSG_CATEGORY_MAIL", id = 12, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "readed_mids", vector=true},
			{type = "int32", name = "got_mids", vector=true},
		},
	},
}

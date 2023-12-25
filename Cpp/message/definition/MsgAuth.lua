messages =
{
	{
		define = "struct", name = "SvrInfo",
		attributes =
		{
			 {type="int16", name="SvrID"},
			 {type="string", name="SvrName"},
			 {type="int8", name="m_PlayerCount"},
			 {type="int8", name="SvrState"}, -- 服务器状态是否在维护之类
			 {type="string", name = "SvrIP"},
			 {type="int16",	 name = "SvrPort"},
			 {type="int16",	 name = "Region"},

		}
	},

	{
		define = "class", name="MsgAuthRegisterRequest", category = "MSG_CATEGORY_AUTH", id = "2", base = "Message",
		 attributes =
		 {
			 {type="string", name="name"},
			 {type="string", name="pwd"},
			 {type="int16", name="version"},
		 }
	},

	{
		define = "class", name="MsgAuthResponse", category = "MSG_CATEGORY_AUTH", id = "3", base = "Message",
		 attributes =
		 {
			 {type="int16", name = "errcode"},
			 {type="int32", name = "aid"},
			 {type="SvrInfo", name="SvrList",vector = true},
		 }
	},

	{
		define = "class", name="MsgAuthRegisterResponse", category = "MSG_CATEGORY_AUTH", id = "4", base = "Message",
		 attributes =
		 {
			 {type="int16", name = "errcode"},
			 {type="int32", name = "aid"},
			 {type="SvrInfo", name="SvrList",vector = true},
		 }
	},

	{
		define = "class", name = "MsgAuthBindRequest", category = "MSG_CATEGORY_AUTH", id = 5, base = "Message",
		attributes =
		{
			 {type="int32",  name="channelId"},
			 {type="int32",  name="platformId"},
			 {type="int32",  name="loginType"},
			 {type="string", name="uid"},
			 {type="string", name="name"},
			 {type="string", name="data"},
			 {type="int16",  name="version"},
		}
	},

	{
		define = "class", name = "MsgAuthBindExRequest", category = "MSG_CATEGORY_AUTH", id = 14, base = "Message",
		attributes =
		{
			 {type="string",  name="channelId"},
			 {type="int32",  name="platformId"},
			 {type="int32",  name="loginType"},
			 {type="string", name="uid"},
			 {type="string", name="name"},
			 {type="string", name="data"},
			 {type="int16",  name="version"},
		}
	},

	{
		define = "class", name="MsgAuthServerListNotify", category = "MSG_CATEGORY_AUTH", id = 13, base = "Message",
		 attributes =
		 {
			 {type="SvrInfo", name="SvrList",vector = true},
		 }
	},

	{
		define = "class", name = "MsgAuthCheckVersionRequest", category = "MSG_CATEGORY_AUTH", id = 6, base = "Message",
		attributes =
		{
			{type = "int16", name = "channelID"},
			{type = "int16", name = "gameVersion"},
			{type = "int16", name = "dataVersion"},
		}
	},

	{
		define = "class", name = "MsgAuthCheckVersionExRequest", category = "MSG_CATEGORY_AUTH", id = 11, base = "Message",
		attributes =
		{
			{type = "string", name = "channelID"},
			{type = "int16", name = "gameVersion"},
			{type = "int16", name = "dataVersion"},
		}
	},

	{
		define = "class", name = "MsgAuthCheckVersionResponse", category = "MSG_CATEGORY_AUTH", id = 7, base = "Message",
		attributes =
		{
			{type = "int16", name = "gameVersion"},
			{type = "int16", name = "dataVersion"},
			{type = "string", name = "downloadURL"},
			{type = "string", name = "announcement"},
		},
	},

	{
		define = "class", name = "MsgAccessTokenResponse", category = "MSG_CATEGORY_AUTH", id = 8 , base = "Message",
		attributes =
		{
			{type = "int16" , name = "errcode"},
			{type = "string" , name = "accessToken"},
			{type = "string" , name = "userId"},
			{type = "string" , name = "userName"},
		},
	},

	{
		define = "class", name = "MsgAuthCheckSVNVersionRequest", category = "MSG_CATEGORY_AUTH", id = 9, base = "Message",
		attributes =
		{
			{type = "int16", name = "channelID"},
			{type = "int32", name = "svnVersion"},
		},
	},

	{
		define = "class", name = "MsgAuthCheckSVNVersionExRequest", category = "MSG_CATEGORY_AUTH", id = 12, base = "Message",
		attributes =
		{
			{type = "string", name = "channelID"},
			{type = "int32", name = "svnVersion"},
		},
	},

	{
		define = "class", name = "MsgAuthCheckSVNVersionResponse", category = "MSG_CATEGORY_AUTH", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "svnVersion"},
			{type = "string", name = "downloadURL"},
		},
	},

	{
		define = "class", name = "MsgGSAuthToASRequest", category = "MSG_CATEGORY_AUTH", id = 20, base = "Message",
		attributes =
		{
			{type = "string", name = "ServerIP",},
			{type = "int16", name = "ServerPort"},
			{type = "string", name = "lastpingID"},
		},
	},

	{
		define = "class", name = "MsgGSAuthToASResponse", category = "MSG_CATEGORY_AUTH", id = 21, base = "Message",
		attributes =
		{
			{type = "int32", name = "mID"},
		},
	},
	{
		define = "class", name = "MsgServerInfoResponse", category = "MSG_CATEGORY_AUTH", id = 510, base = "Message",
		attributes =
		{
			{type = "int32", name = "mID"},
			{type = "string", name = "serverName"},
		},
	},
}


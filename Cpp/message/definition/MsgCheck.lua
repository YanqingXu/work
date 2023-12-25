messages =
{
	{
		define = "struct", name = "PlayerInfo",
		attributes =
		{
			{type = "int32", name="pid", desc = "玩家角色ID"},
		}
	},

	{
		define = "class", name = "MsgEnterServerRequest", category = "MSG_CATEGORY_LOGIN", id = 1, base = "Message",
		attributes =
		{
			{type = "string", name = "fullChannelId", desc = "渠道ID"},
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name ="channelId", desc = "渠道ID"},
			{type = "int32", name = "platformId", desc = "平台ID"},
			{type = "string", name = "deviceId", desc = "设备ID"},
		}
	},

}


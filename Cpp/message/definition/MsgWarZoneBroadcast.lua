--
--战区广播消息
--

messages = {
	{
		define = "class", name = "MsgAddNiceConsignmentNotify", category = "MSG_CATEGORY_WAR_ZONE_BROADCAST", id = 1, base = "Message",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="sid"},
		},
	},
	{
		define = "class", name = "MsgCrossSyncFloatNoticeNotify", category = "MSG_CATEGORY_WAR_ZONE_BROADCAST", id = 2, base = "Message",
		attributes =
		{
			{type = "string", name = "basestring"},
			{type = "int32", name = "showflag"},
			{type = "string", name = "TouchID"},

		},
	},
}

messages =
{
	{
		 define = "class", name="MsgChatSubmit", category = "MSG_CATEGORY_CHAT", id = "500", base = "Message",
		 attributes =
		 {
			 {type="string",  name="serverIp"},
			 {type="int32",  name="port"},
			 {type="int32",  name="chatType"},
			 {type="int32",  name="pid"},
			 {type="string", name="playerName"},
			 {type="string", name="privateName"},
			 {type="string", name="chatStr"},
		 }
	},
}
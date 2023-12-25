messages =
{
	{
		define = "struct", name = "History",
		attributes =
		{
			 {type="int32", name="uid"},
			 {type="string", name="uname"},
			 {type="int32", name="money_rob"},
		}
	},
	
	{
		define = "struct", name = "OrderItem",
		attributes =
		{
			 {type="int32", name="uid"},
			 {type="string", name="uname"},
			 {type="int32", name="order"},
			 {type="string", name="detail"},
		}
	},
	
	{
		define = "struct", name = "ReadPack",
		attributes =
		{
		     {type="int32", name="uid"},
			 {type="string", name="uname"},
			 {type="int32", name="money_all"},
			 {type="int32", name="money_donate"},
			 {type="int32", name="time"},
			 {type="History", name="history_rob",vectory=true},
			 {type="string", name="OrderItem",vectory=true},
		}
	},

	{
		define = "class", name = "MsgSyncRedPackNotify", category = "MSG_CATEGORY_RedPack", id = 1, base = "Message",
		attributes =
		{
			{type = "ReadPack", name = "redPack"},
		},
	},

	{
		define = "class", name = "MsgRedPackInfoRequest", category = "MSG_CATEGORY_RedPack", id = 2, base = "Message",
		attributes =
		{
			
		},
	},

	{
		define = "class", name = "MsgRedPackInfoResponse", category = "MSG_CATEGORY_RedPack", id = 3, base = "Message",
		attributes =
		{
			{type = "ReadPack", name = "redPack"},
		},
	},
}

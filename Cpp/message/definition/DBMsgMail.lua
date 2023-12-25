messages = {
	{
		define = "struct", name = "DBMail",
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="mid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int8", name="readed"},
			{type="int8", name="got"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		}
	},

	--加载邮件
	{
		define = "class", name="MsgDBLoadMail", category = "MSG_CATEGORY_DB_MAIL" , id = 1, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name ="pid"},
			{type="int32", name ="load_id"},
			{type="DBMail", name="mails", vector = true},
		},
	},
	
	--加载过期邮件
	{
		define = "class", name="MsgDBLoadExpiredMail", category = "MSG_CATEGORY_DB_MAIL" , id = 2, base = "MessageEx",
		attributes =
		{
			{type="DBMail", name="mails", vector = true},
		},
	},

	--创建邮件
	{
		define = "class", name="MsgDBCreateMail", category = "MSG_CATEGORY_DB_MAIL" , id = 3, base = "MessageEx",
		attributes =
		{
			{type="string", name="pname"},
			{type="int32", name="pid"},
			{type="int32", name="mid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		},
	},
	
	--删除邮件
	{
		define = "class", name="MsgDBDeleteMail", category = "MSG_CATEGORY_DB_MAIL" , id = 4, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="mids", vector=true},
		},
	},
	
	--标记邮件已读
	{
		define = "class", name="MsgDBSetMailReaded", category = "MSG_CATEGORY_DB_MAIL" , id = 5, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="mid"},
		},
	},
	
	--标记邮件物品已领取
	{
		define = "class", name="MsgDBSetMailGot", category = "MSG_CATEGORY_DB_MAIL" , id = 6, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="mid"},
		},
	},
}

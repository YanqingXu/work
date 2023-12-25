messages = {
	{
		define = "struct", name = "DBQuestInfo",
		attributes =
		{
			{type="int16",	name="qid"},
			{type="int32", name="sid"},
			{type="int16",  name="state"},
			{type="int32", name="datax"},
			{type="int32", name="datay"},
			{type="int32", name="dataz"},
		}
	},
	{
		define = "class", name="MsgDBLoadQuests",category = "MSG_CATEGORY_DB_QUEST" , id = 1,base = "MessageEx", salt="pid",
		attributes =
		{
			{type="int32", name ="pid" },
			{type="int32", name ="load_id" },
			{type="DBQuestInfo", name="quests", vector = true},
		},
	},
	{
		define = "class", name="MsgDBUpdateQuest",category = "MSG_CATEGORY_DB_QUEST" , id = 2,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name ="pid" },
			{type="DBQuestInfo", name="quest",},
		},
	},
	{
		define = "class", name="MsgDBDeleteQuest",category = "MSG_CATEGORY_DB_QUEST" , id = 3,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name ="pid" },
			{type="int32", name ="qid",},
		},
	},
}

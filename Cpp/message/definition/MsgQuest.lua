messages =
{
	{
		define = "struct", name = "QuestInfo",
		attributes =
		{
			 {type="int16",	name="qid"},
			 {type="int16",	name="sid"},
			 {type="int16", name="state"},
			 {type="int32",	name="datax"},
			 {type="int32", name="datay"},
			 {type="int32", name="dataz"},
		}
	},

	{
		define = "class", name = "MsgQuestUpdateListNotify", category = "MSG_CATEGORY_QUEST", id = "1", base = "Message",
		 attributes =
		 {
			{type="QuestInfo",name= "quests",vector = true},
		 }
	},

	{
		define = "class", name = "MsgQuestUpdateNotify", category = "MSG_CATEGORY_QUEST", id = "2", base = "Message",
		 attributes =
		 {
			{type="QuestInfo",name= "quest"},
			{type = "int32"	,name = "opcode"},
		 }
	},

	{
		define = "class", name = "MsgQuestAcceptRequest", category = "MSG_CATEGORY_QUEST",id ="3",base ="Message",
		attributes =
		{
			{type="int16", name = "qid" },
			{type="int16", name = "sid"},
		}
	},

	{
		define = "class", name = "MsgQuestAcceptResponse", category = "MSG_CATEGORY_QUEST",id ="4",base ="Message",
		attributes =
		{
			{type="int16", name = "qid" },
			{type="int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgQuestSubmitRequest", category = "MSG_CATEGORY_QUEST",id = "5", base= "Message",
		attributes =
		{
			{type = "int16" , name = "qid"},
		}
	},

	{
		define = "class", name = "MsgQuestSubmitResponse", category = "MSG_CATEGORY_QUEST",id = "6", base= "Message",
		attributes =
		{
			{type = "int16" , name = "qid"},
			{type = "int16" , name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgQuestRemoveRequest", category = "MSG_CATEGORY_QUEST", id = "7", base = "Message",
		attributes =
		{
			{type = "int16",  name = "qid"},
		}
	},

	{
		define = "class", name = "MsgQuestRemoveResponse", category = "MSG_CATEGORY_QUEST", id = "8", base = "Message",
		attributes =
		{
			{type = "int16",  name = "qid"},
			{type = "int16",  name = "errcode"},
		}
	},

	{
		define = "struct", name = "npcFunction",
		attributes =
		{
			{type="int16",	name="functionid"},
			{type="int32",	name="data"},
			{type="int32",	name="show"},
			{type="int32",	name="numid"},
		}
	},

	{
		define = "class", name = "MsgClickNPCRequest", category = "MSG_CATEGORY_QUEST", id = "9", base = "Message",
		attributes =
		{
			{type = "int32",  name = "NPCid"},
		}
	},

	{
		define = "class", name = "MsgClickNPCResponse", category = "MSG_CATEGORY_QUEST", id = "10", base = "Message",
		attributes =
		{
			{type = "int32",  name = "NPCid"},
			{type = "int16",  name = "errcode" },
			{type = "npcFunction",  name = "function", vector = true},
		}
	},

	{
		define = "class", name = "MsgClickNPCFunctionScriptRequest", category = "MSG_CATEGORY_QUEST", id = "11", base = "Message",
		attributes =
		{
			{type = "int32",  name = "NPCid"},
			{type = "int32",  name = "data" },
		}
	},

	{
		define = "class", name = "MsgClickNPCFunctionScriptResponse", category = "MSG_CATEGORY_QUEST", id = "12", base = "Message",
		attributes =
		{
			{type = "int32",  name = "NPCid"},
			{type = "int32",  name = "data" },
			{type = "int16",  name = "errcode" },
		}
	},
    
    {
		define = "class", name = "MsgClickCMRequest", category = "MSG_CATEGORY_QUEST", id = "112", base = "Message",
		attributes =
		{
			{type = "int32",  name = "id"},
			{type = "int32",  name = "type" },
			{type = "int32",  name = "code" },
		}
	},
    
       {
		define = "class", name = "MsgClickCMResponse", category = "MSG_CATEGORY_QUEST", id = "113", base = "Message",
		attributes =
		{
            {type = "int16",  name = "errcode"},
			{type = "int32",  name = "type" },
			{type = "int32",  name = "code" },
            {type = "int32",  name = "time" },
		}
	},
}


messages = {

	{
		define = "struct", name = "DBRelationInfo",
		attributes =
		{
			{type = "int32" , 	name = "pid"},
			{type = "string", 	name = "name"		},
			{type = "int8",  	name = "gender"},
			{type = "int8"	, 	name = "clazz"},
			{type = "int32"	, 	name = "reborn"},
			{type = "int32"	, 	name = "level"},
			{type = "string", 	name = "gdname"		},
			{type = "int32"	, 	name = "zhanli"},
			{type = "int16" , 	name = "type"},
            {type = "int32" , 	name = "contactTime"},
		}
	},

	{
		define = "class", name="MsgDBRelationshipLoad",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 1,base = "MessageEx", salt="pid",
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="load_id"},
			{type = "DBRelationInfo", name = "relations", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBRelationshipCreate",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 2,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid" },
			{type="int32", name="tgtpid"},
			{type="int32", name="type"},
		},
	},
	
	{
		define = "class", name="MsgDBRelationshipDelete",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 3,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name ="pid" },
			{type="int32", name="tgtpid"},
			{type="int32", name="type"},
		},
	},
	
	{
		define = "class", name="MsgDBRelationSearchPlayer",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 4,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "type" },
			{type = "string", name = "name"},
			{type = "int32", name = "step" },
			{type = "DBRelationInfo", name= "info"},
		},
	},
	
	{
		define = "class", name="MsgDBRelationLoadAddPlayer",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 5,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "type" },
			{type = "DBRelationInfo", name= "info"},
		},
	},
	
	{
		define = "class", name="MsgDBRelationRmvAboutPlayer",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 6,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "vdata", vector = true},
		},
	},

    {
		define = "class", name="MsgDBRelationshipUpdateTime",category = "MSG_CATEGORY_DB_RELATIONSHIP" , id = 7,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid" },
			{type="int32", name="tgtpid"},
			{type="int32", name="type"},
            {type="int32", name="contactTime"},
		},
	},
}

messages =
{
	{
		define = "struct", name = "RelationInfo",
		attributes =
		{
			{type = "int32" , name = "pid" 			},
			{type = "string", name = "name"		},
			{type = "int8",  name = "gender"		},
			{type = "int8"	, name = "clazz"		},
			{type = "int32"	, name = "reborn"		},
			{type = "int32"	, name = "level"		},
			{type = "string", name = "gdname"	},
			{type = "int32"	, name = "online"		},
			{type = "int32"	, name = "zhanli"		},
            {type = "int32"	, name = "contactTime"		},
		},
	},

	{
		define = "class", name = "MsgRelationListRequest", category = "MSG_CATEGORY_RELATIONSHIP", id = 11, base = "Message",
		attributes =
		{
			{type = "int8",	name = "type"},
		},
	},

	{
		define = "class", name = "MsgRelationListResponse", category = "MSG_CATEGORY_RELATIONSHIP", id = 12, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"	},
			{type = "int8",	name = "type"},
			{type = "int8",	name = "isbegin"},
			{type = "int8",	name = "isend"},
			{type = "RelationInfo", name = "relations", vector = true	},
		},
	},
	
	{
		define = "class", name = "MsgRelationOperateRequest", category = "MSG_CATEGORY_RELATIONSHIP", id = 13, base = "Message",
		attributes =
		{
			{type = "int16"	, name = "type"		},
			{type = "int16"	, name = "step"		},
			{type = "int32"	, name = "pid"		},
			{type = "string", name = "name"	},
		},
	},

	{
		define = "class", name = "MsgRelationOperateResponse", category = "MSG_CATEGORY_RELATIONSHIP", id = 14, base = "Message",
		attributes =
		{
			{type = "int16"			, name = "type"			},
			{type = "int16"			, name = "step"			},
			{type = "int16"			, name = "errcode"		},
			{type = "RelationInfo", name = "data"		},
		},
	},

	{
		define = "class", name = "MsgRelationFindingRequest", category = "MSG_CATEGORY_RELATIONSHIP", id = 15, base = "Message",
		attributes =
		{
			{type = "int32"	, name = "pid"		},
			{type = "string", name = "name"	},
		},
	},

	{
		define = "class", name = "MsgRelationFindingResponse", category = "MSG_CATEGORY_RELATIONSHIP", id = 16, base = "Message",
		attributes =
		{
			{type = "int32"	, name = "pid"		},
			{type = "string", name = "name"	},
			{type = "int32", name = "posx"		},
			{type = "int32", name = "posy"		},
			{type = "int32", name = "sceneid"		},
			{type = "int16", name = "errcode"		},
		},
	},
	
	{
		define = "class", name = "MsgRelationAddNotify", category = "MSG_CATEGORY_RELATIONSHIP", id = 17, base = "Message",
		attributes =
		{
			{type = "int32" ,       name = "type"},
			{type = "RelationInfo", name = "info"},
		},
	},
	
	{
		define = "class", name = "MsgRelationRmvNotify", category = "MSG_CATEGORY_RELATIONSHIP", id = 18, base = "Message",
		attributes =
		{
			{type = "int32" , name = "type"	},
			{type = "int32" , name = "pid"	},
		},
	},
}

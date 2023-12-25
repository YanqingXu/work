messages =
{	
	{
		define = "struct", name = "sHolidayPropInt",
		attributes =
		{
			{type = "int32", name = "prop"},
			{type = "int32", name = "value"},
		},
	},
	
	{
		define = "struct", name = "sHolidayPropString",
		attributes =
		{
			{type = "int32", name = "prop"},
			{type = "string", name = "value"},
		},
	},
	
	{
		define = "struct", name = "sHolidayInfo",
		attributes =
		{
			{type = "int32", name="type"},
			
			{type = "int32", name="begin_show_time"},
			{type = "int32", name="end_show_time"},
			{type = "int32", name="begin_time"},
			{type = "int32", name="end_time"},
			
			{type = "int32", name="state"},
			
			{type = "int32", name="world_id"},
			{type = "int32", name="event_id"},
			
			{type = "string", name="str_menu"},
			{type = "string", name="str_title"},
			{type = "string", name="str_content"},

			{type = "sHolidayPropInt", name="vint", vector = true},	
			{type = "sHolidayPropString", name="vstring", vector = true},	
		}
	},

	{
		define = "struct", name = "sHolidayGrade",
		attributes =
		{
			{type = "int32", name="index"},
			
			{type = "int32", name="world_id"},
			{type = "int32", name="event_id"},

			{type = "string", name="str_content"},

			{type = "sHolidayPropInt", name="vint", vector = true},	
			{type = "sHolidayPropString", name="vstring", vector = true},	
		}
	},

	{
		define = "struct", name = "sHolidayItem",
		attributes =
		{
			{type = "int32", name="index"},
			{type = "int32", name="type"},

			{type = "int32", name="static_id"},
			{type = "int32", name="bind"},
			{type = "int32", name="count"},
			
			{type = "int32", name="world_id"},
			{type = "int32", name="event_id"},

			{type = "sHolidayPropInt", name="vint", vector = true},	
			{type = "sHolidayPropString", name="vstring", vector = true},	
		}
	},

	{
		define = "class", name="MsgHolidayInfoNotify", category = "MSG_CATEGORY_HOLIDAY" , id = 1 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "sHolidayInfo", name="info"},		
		},
	},

	{
		define = "class", name="MsgHolidayGradeNotify", category = "MSG_CATEGORY_HOLIDAY" , id = 2 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "sHolidayGrade", name="vgrade", vector = true},		
		},
	},

	{
		define = "class", name="MsgHolidayItemNotify", category = "MSG_CATEGORY_HOLIDAY" , id = 3 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "sHolidayItem", name="vitem", vector = true},		
		},
	},

	{
		define = "class", name="MsgHolidayRemoveNofity", category = "MSG_CATEGORY_HOLIDAY" , id = 4 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},		
		},
	},

	{
		define = "class", name="MsgHolidayRequest", category = "MSG_CATEGORY_HOLIDAY" , id = 5 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},
		},
	},

	{
		define = "class", name="MsgHolidayResponse", category = "MSG_CATEGORY_HOLIDAY" , id = 6 ,base = "Message",
		attributes =
		{
			{type = "int32", name="switch_id"},		
		},
	},

	{
		define = "class", name="MsgHolidayRewardRequest", category = "MSG_CATEGORY_HOLIDAY" , id = 11 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
		},
	},

	{
		define = "class", name="MsgHolidayRewardResponse", category = "MSG_CATEGORY_HOLIDAY" , id = 12 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},	
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
		},
	},

	{
		define = "class", name="MsgHolidayOperateRequest", category = "MSG_CATEGORY_HOLIDAY" , id = 18 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "switch_id"},
			{type = "string", name = "fun_name"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name="MsgHolidayOperateResponse", category = "MSG_CATEGORY_HOLIDAY" , id = 19 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},	
			{type = "int32", name = "switch_id"},
			{type = "string", name = "fun_name"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name="MsgHolidayOperateNotify", category = "MSG_CATEGORY_HOLIDAY" , id = 20 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "type"},
			{type = "int32", name = "index"},
			{type = "int64", name = "flag"},
			{type = "int32", name = "vdata", vector = true},
		},
	},
}



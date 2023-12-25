messages = 
{	
	{
		define = "struct", name = "DBHolidayInfo",
		attributes =
		{
			{type = "int32", name="switch_id"},
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
		}
	},

	{
		define = "struct", name = "DBHolidayGrade",
		attributes =
		{
			{type = "int32", name="index"},
			{type = "int32", name="mark"},
			{type = "int32", name="switch_id"},
			
			{type = "int32", name="world_id"},
			{type = "int32", name="event_id"},

			{type = "string", name="str_content"},
		}
	},

	{
		define = "struct", name = "DBHolidayItem",
		attributes =
		{
			{type = "int32", name="index"},
			{type = "int32", name="mark"},
			{type = "int32", name="switch_id"},
			{type = "int32", name="type"},

			{type = "int32", name="static_id"},
			{type = "int32", name="bind"},
			{type = "int32", name="count"},
			
			{type = "int32", name="world_id"},
			{type = "int32", name="event_id"},
		}
	},

	{
		define = "struct", name = "DBHolidayPropInt",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "int32", name="index"},
			{type = "int32", name="cate"},
			{type = "int32", name="prop"},
			{type = "int32", name="value"},
		}
	},

	{
		define = "struct", name = "DBHolidayPropString",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "int32", name="index"},
			{type = "int32", name="cate"},
			{type = "int32", name="prop"},
			{type = "string", name="value"},
		}
	},
	
	{
		define = "class", name="MsgDBHolidayLoad", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 1 ,base = "MessageEx",
		attributes =
		{
			{type = "DBHolidayInfo", name="vinfo", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayGradeLoad", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 2 ,base = "MessageEx",
		attributes =
		{
			{type = "DBHolidayGrade", name="vdata", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayItemLoad", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 3 ,base = "MessageEx",
		attributes =
		{
			{type = "DBHolidayItem", name="vitem", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayPropIntLoad", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 4 ,base = "MessageEx",
		attributes =
		{
			{type = "DBHolidayPropInt", name="vint", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayPropStringLoad", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 5 ,base = "MessageEx",
		attributes =
		{
			{type = "DBHolidayPropString", name="vstring", vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayCreate", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 11 ,base = "MessageEx", salt = "switch_id",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "DBHolidayInfo", name="info"},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayGradeCreate", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 12 ,base = "MessageEx", salt = "switch_id",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "DBHolidayGrade", name="data"},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayItemCreate", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 13 ,base = "MessageEx", salt = "switch_id",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "DBHolidayItem", name="item"},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayPropIntCreate", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 14 ,base = "MessageEx", salt = "switch_id",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "DBHolidayPropInt", name="data"},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayPropStringCreate", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 15 ,base = "MessageEx", salt = "switch_id",
		attributes =
		{
			{type = "int32", name="switch_id"},
			{type = "DBHolidayPropString", name="data"},
		},
	},
	
	{
		define = "class", name="MsgDBHolidayRemove", category = "MSG_CATEGORY_DB_HOLIDAY" , id = 21 ,base = "MessageEx", salt = "switch_id",send_back = false,
		attributes =
		{
			{type = "int32", name="switch_id"},
		},
	}
}

messages = {
	{
		define = "struct", name="DBItem",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID或行会ID"},
			{type="int32", name="iid", desc="物品ID"},
			{type="int32", name="sid"},
			{type="int16", name="bind"},
			{type="int16", name="count"},
			{type="int16", name="position"},
			{type = "string", name = "firstowner"},		
			{type = "string", name = "appraiser"},		
		}
	},
	
	{
		define = "struct", name="DBGJItem",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID或行会ID"},
			{type="int32", name="iid", desc="物品ID"},
			{type="int32", name="sid"},
			{type="int16", name="bind"},
			{type="int32", name="count"},
			{type="int16", name="position"},
			{type = "string", name = "firstowner"},		
			{type = "string", name = "appraiser"},		
		}
	},
	
	{
		define = "struct", name="DBItemProp",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID或行会ID"},
			{type="int32", name="iid"},
			{type="int16", name="idx"},
			{type="int32", name="data"},
		}
	},
	{
		define = "class", name="MsgDBLoadItems", category = "MSG_CATEGORY_DB_ITEM", id = 1, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="load_id"},
			{type="int8" , name="load_reason"},
			{type="DBItem", name="items", vector=true},
			{type="DBItemProp", name="props", vector =true},
		},
	},
	{
		define = "class", name="MsgDBLoadGuildItems", category = "MSG_CATEGORY_DB_ITEM", id = 2, base = "MessageEx",
		attributes =
		{
			{type="DBItem", name="items", vector=true},
			{type="DBItemProp", name="props", vector =true},
		},
	},
	{
		define = "class", name="MsgDBCreateItem", category = "MSG_CATEGORY_DB_ITEM", id = 3, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid"},
			{type="DBItem", name="item"},
			{type="DBItemProp", name="props", vector =true},
		},
	},
	{
		define = "class", name="MsgDBDeleteItem", category = "MSG_CATEGORY_DB_ITEM", id = 4, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
		},
	},
	{
		define = "class", name="MsgDBUpdateItemBase", category = "MSG_CATEGORY_DB_ITEM", id = 10, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="DBItem", name="item"},
		},
	},
	{
		define = "class", name="MsgDBUpdateItemCount", category = "MSG_CATEGORY_DB_ITEM", id = 11, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="int16", name="count"},
		},
	},
	{
		define = "class", name="MsgDBUpdateItemProp", category = "MSG_CATEGORY_DB_ITEM", id = 12, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="int16", name="idx"},
			{type="int32", name="data"},
		},
	},
	{
		define = "class", name="MsgDBUpdateItemPosition", category = "MSG_CATEGORY_DB_ITEM", id = 13, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="int16", name="position"},
		},
	},
	{
		define = "class", name="MsgDBUpdateItemSid", category = "MSG_CATEGORY_DB_ITEM", id = 14, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="int32", name="sid"},
		},
	},
	{
		define = "struct", name="DBIncome",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID"},
			{type="int32", name="iid", desc="物品ID"},
			{type="int32", name="sid", desc="物品静态ID"},
			{type="int32", name="count", desc="物品数量"},
			{type="int32", name="bind", desc="物品绑定状态"},
			{type="int32", name="opcode", desc="操作码"},
			{type="int32", name="data", desc="操作附加数据"},
			{type="int32", name="ctime", desc="获得时间"},
		}
	},
	{
		define = "struct", name="DBIncomeProp",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID"},
			{type="int32", name="iid", desc="物品ID"},
			{type="int32", name="idx", desc="属性ID"},
			{type="int32", name="data", desc="属性值"},
		}
	},
	{
		define = "class", name="MsgDBLoadIncome", category = "MSG_CATEGORY_DB_ITEM", id = 21, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid", desc="角色ID"},
			{type="DBIncome", name="items", vector=true},
			{type="DBIncomeProp", name="props", vector =true},
		},
	},
	{
		define = "class", name="MsgDBCreateIncome", category = "MSG_CATEGORY_DB_ITEM", id = 22, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="DBIncome", name="item"},
			{type="DBIncomeProp", name="props", vector =true},
		},
	},
	{
		define = "class", name="MsgDBDeleteIncome", category = "MSG_CATEGORY_DB_ITEM", id = 23, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
		},
	},
	
	{
		define = "class", name="MsgDBUpdBagItems", category = "MSG_CATEGORY_DB_ITEM", id = 25, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="deleteItemList", vector=true},
			{type="DBItem", name="items", vector=true},
		},
	},
	
	{
		define = "class", name="MsgDBCreateAuctionItems", category = "MSG_CATEGORY_DB_ITEM", id = 26, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="iid"},
			{type="int32", name="serverid"},
		},
	},

	{
		define = "class", name="MsgDBUpdateItemAppraiser", category = "MSG_CATEGORY_DB_ITEM", id = 27, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="string", name="appraiser"},
		},
	},

	{
		define = "struct", name="DBItemPropEx",
		attributes =
		{
			{type="int16", name="idx"},
			{type="int32", name="data"},
		}
	},
	{
		define = "class", name="MsgDBUpdateItemChangedProp", category = "MSG_CATEGORY_DB_ITEM", id = 28, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="iid"},
			{type="DBItemPropEx", name="props", vector =true},
		},
	},
	
	{
		define = "class", name="MsgDBDeleteDBBKItems", category = "MSG_CATEGORY_DB_ITEM", id = 29, base = "MessageEx",
		attributes =
		{

		},
	},
}

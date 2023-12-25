
messages = {
	{
		--商品信息
		define = "struct", name = "ShopItem",
		attributes =
		{
			{type = "int32", name = "sid", desc="物品配置ID"},
			{type = "int32", name = "count", desc="物品数量"},
			{type = "int32", name = "price_type", desc="出售价格类型"},
			{type = "int32", name = "price", desc="出售价格"},
			{type = "int32", name = "server_days", desc="第几天开启"},
			{type = "int8", name = "is_bind", desc="是否绑定"},
			{type = "int16", name = "eventId", desc="限购对应的eventid"},
			{type = "int32", name = "itemidx", desc="物品在商城中的id"},
			{type = "int32", name = "oriprice", desc="初始价格"},
			{type = "int32", name = "end_days", desc="第几天关闭"},
			{type = "int32", name = "vip", desc="限制购买的贵族等级"},
			{type = "int32", name = "limit_level", desc="限制购买的玩家等级"},
		},
	},

	{
		define = "class", name = "MsgOpenShopRequest", category = "MSG_CATEGORY_SHOP", id = "1", base = "Message",
		attributes =
		{
			{type = "int32", name = "shop_id", desc="商店ID"},
			{type = "int32", name = "version", desc="版本号"},
		},
	},

	{
		define = "class", name = "MsgOpenShopResponse", category = "MSG_CATEGORY_SHOP", id = 2, base = "Message",
		attributes=
		{
			{type = "int32", name = "shop_id"},
			{type = "int32", name = "version", desc="版本号"},
			{type = "int16", name = "errcode"},
			{type = "ShopItem", name = "items", vector = true},
		},
	},

	{
		define = "struct", name = "ShopBuyBackData",
		attributes =
		{
			{type = "int32", name = "itemsid"},
			{type = "int32", name = "itemiid"},
			{type = "int32", name = "count"},
			{type = "int32", name = "price"},
			{type = "int16", name = "isbind" },
		},
	},

	{
		define = "class", name = "MsgShopBackBuyNotify", category = "MSG_CATEGORY_SHOP", id = 4, base = "Message",
		attributes =
		{
			{type = "ShopBuyBackData", name = "items", vector = true},
		},
	},

	{
		define = "class", name = "MsgShopBackBuyRmvNotify", category = "MSG_CATEGORY_SHOP", id = 5, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemiid"},
		},
	},

	{
		define = "class", name = "MsgShopBackBuyAddNotify", category = "MSG_CATEGORY_SHOP", id = 6, base = "Message",
		attributes =
		{
			{type = "ShopBuyBackData", name = "item"},
		},
	},

	{
		define = "class", name = "MsgBuyItemInShopRequest", category = "MSG_CATEGORY_SHOP", id = 20, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "id"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
		},
	},

	{
		define = "class", name = "MsgBuyItemInShopResponse", category = "MSG_CATEGORY_SHOP", id = 21, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode" },
		},
	},

	{
		define = "class", name = "MsgShopBackBuyItemRequest", category = "MSG_CATEGORY_SHOP", id = 22, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemiid"},
		},
	},
	{
		define = "class", name = "MsgShopBackBuyItemResponse", category = "MSG_CATEGORY_SHOP", id = 23, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},


	{
		define = "class", name = "MsgBuyAndUseItemRequest", category = "MSG_CATEGORY_SHOP", id = 24, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "id"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
		},
	},

	{
		define = "class", name = "MsgBuyAndUseItemResponse", category = "MSG_CATEGORY_SHOP", id = 25, base = "Message",
		attributes =
		{
			{type = "int32", name = "shop_id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
			{type = "int16", name = "errcode"},
		},
	},

}


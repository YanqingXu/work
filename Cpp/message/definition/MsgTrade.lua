
--
--交易消息定义
--

messages = {
	{
		define = "struct", name = "TradeItemProp",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int32", name = "data"},
		},
	},

	{
		--申请交易(客户端->服务器)
		define = "class", name = "MsgTradeStartRequestC", category = "MSG_CATEGORY_TRADE", id = 1, base = "Message",
		attributes =
		{
			{type = "int32", name = "other_player_id", desc = "对方玩家ID"},
		},
	},

	{
		--申请交易(服务器->客户端)
		define = "class", name = "MsgTradeStartRequestS", category = "MSG_CATEGORY_TRADE", id = 2, base = "Message",
		attributes =
		{
			{type = "int32", name = "other_player_id", desc = "对方玩家ID"},
			{type = "string", name = "other_player_name", desc = "对方玩家名称"},
		},
	},

	{
		--回复交易申请(客户端->服务器)
		define = "class", name = "MsgTradeStartResponseC", category = "MSG_CATEGORY_TRADE", id = 3, base = "Message",
		attributes =
		{
			{type = "int32", name = "other_player_id", desc = "对方玩家ID"},
			{type = "int16", name = "errcode", desc = "错误码: 1-同意, 2-拒绝"},
		},
	},

	{
		--回复交易申请(服务器->客户端)
		define = "class", name = "MsgTradeStartResponseS", category = "MSG_CATEGORY_TRADE", id = 4, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码: 1-同意, 2-拒绝, 3-无响应, 4-很忙"},
			{type = "string", name = "other_player_name", desc = "对方玩家名称"},
			{type = "int32", name = "param1", desc = "参数1"},
		},
	},

	{
		--更改交易物品请求(客户端->服务器)
		define = "class", name = "MsgTradeChangeItemRequest", category = "MSG_CATEGORY_TRADE", id = 5, base = "Message",
		attributes =
		{
			{type = "int32", name = "item_id", desc = "物品ID"},
			{type = "int32", name = "old_position", desc = "物品旧位置"},
			{type = "int32", name = "position", desc = "物品新位置"},
			{type = "int32", name = "count", desc = "物品数量"},
		},
	},

	{
		--更改交易物品回复(服务器->客户端)
		define = "class", name = "MsgTradeChangeItemResponse", category = "MSG_CATEGORY_TRADE", id = 6, base = "Message",
		attributes =
		{
			{type = "int32", name = "item_id", desc = "物品ID"},
			{type = "int32", name = "old_position", desc = "物品旧位置"},
			{type = "int32", name = "position", desc = "物品新位置"},
			{type = "int32", name = "count", desc = "物品数量"},
			{type = "int32", name = "revision", desc = "最新版本号"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--更改交易物品通知(服务器->客户端)
		define = "class", name = "MsgTradeChangeItemNotify", category = "MSG_CATEGORY_TRADE", id = 7, base = "Message",
		attributes =
		{
			{type = "int32", name = "static_id", desc = "物品静态ID"},
			{type = "int32", name = "item_id", desc = "物品ID"},
			{type = "int32", name = "old_position", desc = "物品旧位置"},
			{type = "int32", name = "position", desc = "物品新位置"},
			{type = "int32", name = "count", desc = "物品数量"},
			{type = "TradeItemProp", name = "props", vector = true, desc = "物品属性"},
			{type = "int32", name = "revision", desc = "最新版本号"},
		},
	},

	{
		--更改交易金币请求(客户端->服务器)
		define = "class", name = "MsgTradeChangeCoinRequest", category = "MSG_CATEGORY_TRADE", id = 8, base = "Message",
		attributes =
		{
			{type = "int64", name = "coin", desc = "金币数量"},
		},
	},

	{
		--更改交易金币回复(服务器->客户端)
		define = "class", name = "MsgTradeChangeCoinResponse", category = "MSG_CATEGORY_TRADE", id = 9, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int64", name = "coin", desc = "当前金币数量"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--更改交易金币通知(服务器->客户端)
		define = "class", name = "MsgTradeChangeCoinNotify", category = "MSG_CATEGORY_TRADE", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int64", name = "coin", desc = "当前金币数量"},
		},
	},

	{
		--更改交易元宝请求(客户端->服务器)
		define = "class", name = "MsgTradeChangeIngotRequest", category = "MSG_CATEGORY_TRADE", id = 11, base = "Message",
		attributes =
		{
			{type = "int32", name = "ingot", desc = "元宝数量"},
		},
	},

	{
		--更改交易元宝回复(服务器->客户端)
		define = "class", name = "MsgTradeChangeIngotResponse", category = "MSG_CATEGORY_TRADE", id = 12, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int32", name = "ingot", desc = "当前元宝数量"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--更改交易元宝通知(服务器->客户端)
		define = "class", name = "MsgTradeChangeIngotNotify", category = "MSG_CATEGORY_TRADE", id = 13, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int32", name = "ingot", desc = "当前元宝数量"},
		},
	},

	{
		--确认交易请求(客户端->服务器)
		define = "class", name = "MsgTradeCommitRequest", category = "MSG_CATEGORY_TRADE", id = 17, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "版本号"},
		},
	},

	{
		--确认交易结果(服务器->客户端)
		define = "class", name = "MsgTradeCommitResponse", category = "MSG_CATEGORY_TRADE", id = 18, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int16", name = "errcode", desc = "错误码"},	--0-成功
		},
	},

	{
		--确认交易通知(服务器->客户端)
		define = "class", name = "MsgTradeCommitNotify", category = "MSG_CATEGORY_TRADE", id = 19, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "版本号"},
			{type = "int32", name = "other_player_id", desc = "对方玩家ID"},
		},
	},

	{
		--交易取消请求(客户端->服务器)
		define = "class", name = "MsgTradeCancelRequest", category = "MSG_CATEGORY_TRADE", id = 23, base = "Message",
		attributes =
		{
		},
	},

	{
		--交易结果(服务器->客户端)
		define = "class", name = "MsgTradeResultNotify", category = "MSG_CATEGORY_TRADE", id = 24, base = "Message",
		attributes =
		{
			{type = "string", name = "other_player_name", desc = "对方玩家名称"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--交易锁定 请求
		define = "class", name = "MsgTradeItemLockRequest", category = "MSG_CATEGORY_TRADE", id = 25, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "版本号"},
			{type = "int32", name = "tradestate", desc = "是否锁定"},--0 解锁 1锁定
		},
	},

	{
		----交易锁定 请求结果(服务器->客户端)
		define = "class", name = "MsgTradeItemLockResponse", category = "MSG_CATEGORY_TRADE", id = 26, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "当前版本号"},
			{type = "int32", name = "tradestate", desc = "锁定结果"},	--0-成功
			{type = "int16", name = "errcode", desc = "错误码"},	--0-成功
		},
	},

	{
		--交易锁定 通知(服务器->客户端)
		define = "class", name = "MsgTradeItemLockNotify", category = "MSG_CATEGORY_TRADE", id = 27, base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "版本号"},
			{type = "int32", name = "other_player_id", desc = "对方玩家ID"},
			{type = "int32", name = "tradestate", desc = "锁定结果"},
		},
	},


}


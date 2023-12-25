messages={
	{
		define = "struct", name="DBConsignmentItemProp",
		attributes =
		{
			{type="int16", name="idx"},
			{type="int32", name="data"},
		}
	},
	{
		define="struct", name="DBConsignment",
		attributes=
		{
			{type="int32", name="sellerPid", desc="卖家ID"},
			{type="string", name="sellerName", desc="卖家姓名"},
			{type="int32", name="sellerServerId", desc="卖家服务器id"},
			{type="string", name="sellerServerName", desc="卖家服务器名称"},
			{type="int32", name="sellerWarZoneId", desc="卖家战区id"},
			{type="int32", name="cid", desc="寄售ID"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
			{type="int32", name="taxRate", desc="税率"},
			{type="int32", name="price", desc="出售价格"},
			{type="int32", name="ctime", desc="寄售时间"},
			{type="int32", name="etime", desc="过期时间"},
			{type="string", name="firstOwner", desc="第一个拥有者"},
			{type="string", name="appraiser", desc="鉴定者"},
			{type="int32", name="mailTip", desc="邮件提示标志"},
			{type="DBConsignmentItemProp", name="props", vector =true},
		}
	},

	{
		define="class", name="MsgDBLoadConsignments", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=1, base="MessageEx",
		attributes=
		{
			{type="DBConsignment", name="consignments", vector=true},
		},
	},

	{
		define="class", name="MsgDBAddConsignment", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=2, base="MessageEx", salt="consignment.sellerPid", send_back=false,
		attributes=
		{
			{type="DBConsignment", name="consignment"},
		},
	},

	{
		define="class", name="MsgDBDeleteConsignment", category="MSG_CATEGORY_DB_CONSIGNMENT", id=3, base="MessageEx", salt="pid",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
		},
	},

	{
		define="class", name="MsgDBUpdateConsignment", category="MSG_CATEGORY_DB_CONSIGNMENT", id=4, base="MessageEx", salt="pid",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
			{type="int32", name="count", desc="寄售数量"},
		},
	},

	    {
		define="struct", name="DBAcution",
		attributes=
		{
            {type="int64", name="aid", desc="拍卖ID"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
            {type="int32", name="fixed_price", desc="一口价"},
            {type="int32", name="start_price", desc="起拍价"},
            {type="int32", name="things_type", desc="货币类型"},
            {type="int32", name="status", desc="拍卖状态"},
			{type="int32", name="buyer_pid", desc="竞价人pid"},
            {type="string", name="buyer_name", desc="竞价人名字"},
			{type="int32", name="cur_price", desc="当前竞拍价格"},
            {type="int32", name="atime", desc="成交时间"},
			{type="int32", name="etime", desc="过期时间"},
            {type="int32", name="parters", vector=true, desc="拍卖受益人"},
            {type="int32", name="buyers", vector=true, desc="拍卖竞价者"},
            {type="int32", name="crt_type", desc="当前竞拍归属组"},
            {type="int32", name="next_auction", desc="是否进入下一拍卖行"},
            {type="int32", name="guild_id", desc="公会id"},
            {type="int32", name="server_id", desc="区服id"},
            {type="int32", name="war_zone_id", desc="战区id"},
			{type="int32", name="buyer_server_id", desc="竞价人区服id"},
		}
	},

	{
		define="class", name="MsgDBDelOneAcution", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=7, base="MessageEx",send_back=false,
		attributes=
		{
			{type="DBAcution", name="acution"},
		},
	},

	{
		define="class", name="MsgDBUpdateOneAcution", category="MSG_CATEGORY_DB_CONSIGNMENT", id=8, base="MessageEx", send_back=false,
		attributes=
		{
			{type="DBAcution", name="acution"},
		},
	},

	{
		define="class", name="MsgDBAddOneAcution", category="MSG_CATEGORY_DB_CONSIGNMENT", id=9, base="MessageEx", send_back=false,
		attributes=
		{
			{type="DBAcution", name="acution"},
		},3
	},

	 {
		define="class", name="MsgDBLoadAllAcution", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=10, base="MessageEx",
		attributes=
		{
			{type="DBAcution", name="acutions", vector=true},
		},
	},
	
	{
		define="struct", name="DBPurchase",
		attributes=
		{
			{type="int32", name="buyerPid", desc="求购者pid"},
			{type="string", name="buyerName", desc="求购者姓名"},
			{type="int32", name="buyerServerId", desc="求购者服务器id"},
			{type="string", name="buyerServerName", desc="求购者服务器名称"},
			{type="int32", name="buyerWarZoneId", desc="求购者战区id"},
			{type="int32", name="purchaseId", desc="求购id"},
			{type="int32", name="sid", desc="求购物品ID"},
			{type="int32", name="count", desc="求购物品数量"},
			{type="int32", name="taxRate", desc="税率"},
			{type="int32", name="price", desc="求购价格"},
			{type="int32", name="ctime", desc="求购时间"},
			{type="int32", name="etime", desc="求购过期时间"},
		}
	},
	
	{
		define="class", name="MsgDBLoadPurchases", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=11, base="MessageEx",
		attributes=
		{
			{type="DBPurchase", name="purchases", vector=true},
		},
	},

	{
		define="class", name="MsgDBAddPurchase", category="MSG_CATEGORY_DB_CONSIGNMENT" , id=12, base="MessageEx", salt="purchase.buyerPid",
		attributes=
		{
			{type="DBPurchase", name="purchase"},
		},
	},

	{
		define="class", name="MsgDBDeletePurchase", category="MSG_CATEGORY_DB_CONSIGNMENT", id=13, base="MessageEx", salt="pid",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="purchaseId", desc="求购ID"},
		},
	},

	{
		define="class", name="MsgDBUpdatePurchase", category="MSG_CATEGORY_DB_CONSIGNMENT", id=14, base="MessageEx", salt="pid",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="purchaseId", desc="求购ID"},
			{type="int32", name="count", desc="求购数量"},
		},
	},
	{
		define="class", name="MsgDBUpdateConsignmentMailTip", category="MSG_CATEGORY_DB_CONSIGNMENT", id=15, base="MessageEx", salt="pid",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
			{type="int32", name="mailTip", desc="邮件提醒"},
		},
	},
}

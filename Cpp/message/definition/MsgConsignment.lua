messages =
{
	{
		define = "struct", name="ConsignmentItemProp",
		attributes =
		{
			{type="int32", name="sellerpid", desc="角色ID"},
			{type="int32", name="cid"},
			{type="int32", name="sid"},
			{type="int16", name="idx"},
			{type="int32", name="data"},
		}
	},
	{
		define="struct", name="Consignment",
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
			{type="int32", name="mailTip", desc="邮件提示"},
			{type="ConsignmentItemProp", name="props", vector =true},
		}
	},
	
	{
        --寄售列表请求
		define = "class", name = "MsgGetConsignmentsRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "1", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},

	
	{
		define = "class", name = "MsgUpdateAllConsignmentNotifyStart", category = "MSG_CATEGORY_CONSIGNMENT", id = "2", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
        --寄售列表应答
		define = "class", name = "MsgUpdateAllConsignmentNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "3", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
			{type = "Consignment", name = "consignments", vector=true},
		}
	},
	
	{
		define = "class", name = "MsgUpdateAllConsignmentNotifyEnd", category = "MSG_CATEGORY_CONSIGNMENT", id = "4", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},

	{
        --寄售请求
		define = "class", name = "MsgAddConsignmentRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "5", base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", desc = "物品ID"},
			{type = "int32", name = "count", desc = "物品数量"},
			{type = "int32", name = "price", desc = "价格"},
			{type = "int32", name = "period", desc = "期限"},
			{type = "int32", name = "timetype",desc = "寄售持续时间"}
		}
	},

	{
        --寄售应答
		define = "class", name = "MsgAddConsignmentResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "6", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		}
	},

	{
        --寄售通知
		define = "class", name = "MsgAddConsignmentNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "7", base = "Message",
		attributes =
		{
		}
	},

	{
        --取消寄售请求
		define = "class", name = "MsgDeleteConsignmentRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "8", base = "Message",
		attributes =
		{
			{type="int32", name="cid", desc="寄售ID"},
		}
	},

	{
        --取消寄售应答
		define = "class", name = "MsgDeleteConsignmentResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "9", base = "Message",
		attributes =
		{
			{type="int32", name="cid", desc="寄售ID"},
			{type = "int16", name = "errcode", desc = "错误码"},
		}
	},

	{
        --取消寄售通知
		define = "class", name = "MsgDeleteConsignmentNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "10", base = "Message",
		attributes =
		{
			{type="int32", name="cid", desc="寄售ID"},
		}
	},
   
	{
        --购买寄售请求
		define = "class", name = "MsgBuyConsignmentRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "11", base = "Message",
		attributes =
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
			{type="int32", name="count", desc="购买数量"},
		}
	},

	{
        --购买寄售应答
		define = "class", name = "MsgBuyConsignmentResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "12", base = "Message",
		attributes =
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
			{type="int32", name="count", desc="购买数量"},
			{type = "int16", name = "errcode", desc = "错误码"},
		}
	},

	{
		define="struct", name="ConsignmentRecording",
		attributes=
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="string", name="sellername", desc="卖家姓名"},
			{type="int32", name="buyerpid", desc="买家id"},
			{type="string", name="buyername", desc="买家姓名"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
			{type="int32", name="price", desc="出售价格"},
			{type="int32", name="ctype", desc="交易类型"},
			{type="int32", name="btime", desc="交易时间"},
			{type="int32", name="pricetype", desc="货币类型"},
		}
	},

	{
        --增加交易记录
		define = "class", name = "MsgAddConsignmentRecordRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "13", base = "Message",
		attributes =
		{
			
		}
	},

	{
        --增加交易记录应答
		define = "class", name = "MsgAddConsignmentRecordResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "14", base = "Message",
		attributes =
		{
			{type = "ConsignmentRecording", name = "consignmentsRecording", vector=true},
		}
	},
	{
        --请求关注列表
		define = "class", name = "MsgGetConsignmentAttentionRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "15", base = "Message",
		attributes =
		{
			
		}
	},

	{
        --请求关注列表响应
		define = "class", name = "MsgGetConsignmentAttentionResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "16", base = "Message",
		attributes =
		{
			{type = "Consignment", name = "consignments", vector=true},
		}
	},
	{
        --增加关注
		define = "class", name = "MsgAddConsignmentAttentionRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "17", base = "Message",
		attributes =
		{
			{type="int32", name="pid", desc="玩家ID"},
			{type="int32", name="cid", desc="寄售ID"},
		}
	},

	{
        --增加关注响应
		define = "class", name = "MsgAddConsignmentAttentionResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "18", base = "Message",
		attributes =
		{
			{type = "Consignment", name = "consignment", desc="关注物品"},
		}
	},


	    {
		define="struct", name="Acution",
		attributes=
		{
            {type="int32", name="aid_high", desc="拍卖ID(高32位)"},
            {type="int32", name="aid_lower", desc="拍卖ID(低32位)"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
            {type="int32", name="fixed_price", desc="一口价"},
            {type="int32", name="start_price", desc="起拍价"},
            {type="int32", name="things_type", desc="货币类型"},
			{type="int32", name="buyer_pid", desc="竞价人pid"},
            {type="string", name="buyer_name", desc="竞价人名字"},
			{type="int32", name="cur_price", desc="当前竞拍价格"},
            {type="int32", name="atime", desc="成交时间"},
			{type="int32", name="etime", desc="过期时间"},
            {type="int32", name="parters", vector=true, desc="拍卖受益人"},
            {type="int32", name="buyers", vector=true, desc="拍卖竞价者"},
            {type="int32", name="crt_type",desc="拍卖物品归属组"},
            {type="int32", name="guild_id",desc="公会id"},
            {type="int32", name="server_id",desc="区服id"},
            {type="int32", name="war_zone_id",desc="战区id"},
			{type="int32", name="buyer_server_id", desc="竞价人区服id"},
			{type="int32", name="next_auction", desc="是否进入下一拍卖行"},
		}
	},
	
	{
		define = "class", name = "MsgRmvOneAcutionNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "19", base = "Message",
		attributes =
		{
			{type="Acution", name="acution", desc="一个条目"},
		}
	},

    {
		define = "class", name = "MsgAddOneAcutionNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "20", base = "Message",
		attributes =
		{
			{type="Acution", name="acution", desc="一个条目"},
		}
	},

    {
		define = "class", name = "MsgUpdateOneAcutionNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "21", base = "Message",
		attributes =
		{
			{type="Acution", name="acution", desc="一个条目"},
		}
	},

    {
		define = "class", name = "MsgBuyAcutionRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "22", base = "Message",
		attributes =
		{
			{type="int32", name="ctype", desc="1 竞拍 2 一口价"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="aid_high", desc="拍卖ID(高32位)"},
            {type="int32", name="aid_lower", desc="拍卖ID(低32位)"},
			{type="int32", name="payMoney", desc="出价"},
		}
	},

	{
		define = "class", name = "MsgBuyAcutionResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "23", base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode", desc = "错误码"},
			{type = "int32", name = "ctype", desc = "1 竞拍  2 一口价"},
		}
	},

	{
		define = "class", name = "MsgGetAllAcutionRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "24", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},

	{
		define = "class", name = "MsgUpdateAllAcutionNotifyStart", category = "MSG_CATEGORY_CONSIGNMENT", id = "25", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgUpdateAllAcutionNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "26", base = "Message",
		attributes =
		{
			{type="Acution", name="acutions", vector=true, desc="所有条目"},
		}
	},
	
	{
		define = "class", name = "MsgUpdateAllAcutionNotifyEnd", category = "MSG_CATEGORY_CONSIGNMENT", id = "27", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgRmvManyAcutionNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "28", base = "Message",
		attributes =
		{
			{type="Acution", name="acutions", vector=true, desc="一个条目"},
		}
	},
	
	{
		define="struct", name="Purchase",
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
        --求购列表请求
		define = "class", name = "MsgGetPurchaseListRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "29", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgUpdateAllPurchaseNotifyStart", category = "MSG_CATEGORY_CONSIGNMENT", id = "30", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
        --寄售列表应答
		define = "class", name = "MsgUpdateAllPurchaseNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "31", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
			{type = "Purchase", name = "purchaseList", vector=true},
		}
	},
	
	{
		define = "class", name = "MsgUpdateAllPurchaseNotifyEnd", category = "MSG_CATEGORY_CONSIGNMENT", id = "32", base = "Message",
		attributes =
		{
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgPostPurchaseRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "33", base = "Message",
		attributes =
		{
			{type = "int32", name = "needItemId", desc = "求购物品id"},
			{type = "int32", name = "needCounts", desc = "求购物品数量"},
			{type = "int32", name = "payMoney", desc = "求购者出价"},
		}
	},
	
	{
		define = "class", name = "MsgPostPurchaseResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "34", base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "Purchase", name = "newPurchase"},
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgCancelPurchaseRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "35", base = "Message",
		attributes =
		{
			{type = "int32", name = "buyerPid", desc = "求购者pid"},
			{type = "int32", name = "purchaseId", desc = "求购id"},
		}
	},
	
	{
		define = "class", name = "MsgCancelPurchaseResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "36", base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "buyerPid", desc = "求购者pid"},
			{type = "int32", name = "purchaseId", desc = "求购id"},
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	
	{
		define = "class", name = "MsgSellPurchaseRequest", category = "MSG_CATEGORY_CONSIGNMENT", id = "37", base = "Message",
		attributes =
		{
			{type = "int32", name = "buyerPid", desc = "求购者pid"},
			{type = "int32", name = "purchaseId", desc = "求购id"},
			{type = "int32", name = "sellCounts", desc = "出售数量"},
		}
	},
	
	{
		define = "class", name = "MsgSellPurchaseResponse", category = "MSG_CATEGORY_CONSIGNMENT", id = "38", base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "buyerPid", desc = "求购者pid"},
			{type = "int32", name = "purchaseId", desc = "求购id"},
			{type = "int32", name = "leftCounts", desc = "剩余求购数量"},
			{type = "int32", name = "revision", desc = "数据版本号"},
		}
	},
	{
		define = "class", name = "MsgAcutionBuyerChangeNotify", category = "MSG_CATEGORY_CONSIGNMENT", id = "39", base = "Message",
		attributes =
		{
			{type = "int32", name = "pid", desc = "之前的拍卖玩家id"},
		}
	},
}

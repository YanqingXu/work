
--
--跨服消息定义
--

messages = {
	{
		define = "struct", name = "CrossIntProp",
		attributes =
		{
			{type = "int32", name = "ctype"},
			{type = "int32", name = "data"},
			{type = "int32", name = "valueInGS"},
		},
	},
	
	{
		define = "struct", name = "CrossStrProp",
		attributes =
		{
			{type = "int32", name = "ctype"},
			{type = "string", name = "data"},
		},
	},
	
	{
		define = "struct", name = "CrossSkill",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "level"},
			{type = "int16", name = "remove"},
		},
	},
	
	{
		define = "struct", name = "CrossCombat",
		attributes =
		{
			{type = "int16", name = "ctype"},
			{type = "int32", name = "data"},
		},
	},
	
	{
		define = "struct", name = "CrossGene",
		attributes =
		{
			{type = "int32", name = "geneId"},
			{type = "int32", name = "geneType"},
			{type = "int32", name = "geneGroup"},
			{type = "int32", name = "duration"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int16", name = "inherit"},
			{type = "int16", name = "remove"},
		},
	},
	
	{
		define = "struct", name = "CrossCommonStruct",
		attributes =
		{
			{type = "CrossIntProp", name = "intProps", vector=true, desc = "整型属性"},
			{type = "CrossStrProp" , name = "strProps" , vector = true , desc = '字符属性'},
			{type = "CrossGene" , name = "genes" , vector = true , desc = '基因'},
			{type = "CrossSkill", name = "skills", vector=true, desc = "技能"},
			{type = "CrossCombat", name = "combatImmunity", vector=true, desc = "战斗免疫属性"},
			{type = "CrossCombat", name = "combatProps", vector=true, desc = "战斗属性"}
		},
	},
	
	{
		define = "struct", name = "CrossItemProp",
		attributes =
		{
			{type = "int16", name = "ctype"},
			{type = "int32", name = "data"},
		},
	},
	
	{
		define = "class", name = "MsgRegisterGameServerToCrossServer", category = "MSG_CATEGORY_CROSS", id = 1, base = "MessageEx",
		attributes =
		{
			{type="int32", name="gameServerId"},
			{type="string", name="gameServerName"},
			{type="string", name="gameServerAddr"},
			{type="int32", name="gameServerPort"},
			{type="string", name="dbAgentAddr"},
			{type="int32", name="dbAgentPort"},
		},
	},
	
	{
		define = "struct", name = "CrossEventData",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32", name="datax"},
			{type="int32", name="datay"},
			{type="int32", name="dataz"},
			{type="int32", name="timeIndex"},
		}
	},
	
	{
		define = "class", name = "MsgCreatePlayerInCrossServerRequest", category = "MSG_CATEGORY_CROSS", id = 3, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="dstMapId"},
			{type="int32", name="posX"},
			{type="int32", name="posY"},
			{type="string", name="name"},
			{type = "int32", name = "job"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "level"},
            {type = "int32", name = "gjtime"},
			{type = "CrossEventData", name = "events", vector = true},
			{type = "CrossCommonStruct", name = "playerInfo",desc = "玩家数据"},
		},
	},
	
	{
		define = "class", name = "MsgCreatePlayerInCrossServerEnd", category = "MSG_CATEGORY_CROSS", id = 7, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
		},
	},

	
	{
		define = "class", name = "MsgCreatePlayerInCrossServerResponse", category = "MSG_CATEGORY_CROSS", id = 8, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="playerEid"},
			{type="int32", name="heroEid"},
		},
	},
	
	{
		define = "class", name = "MsgSyncPropToCrossServer", category = "MSG_CATEGORY_CROSS", id = 9, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "CrossCombat", name = "combatProps", vector=true, desc = "战斗属性"},
		},
	},
	
	{
		define = "class", name = "MsgLeaveFromCrossServerMapRequest", category = "MSG_CATEGORY_CROSS", id = 10, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sourceServerId"},
			{type="int32", name="playerId"},
			{type="int32", name="dstMapId"},
			{type="int32", name="posX"},
			{type="int32", name="posY"},
			{type="int16", name="reason"},
			{type ="int32", name = "sceneInstanceId"},
			{type ="int32", name = "enterSceneType"}
		},
	},
	
	{
		define = "class", name = "MsgLeaveFromCrossServerMapResponse", category = "MSG_CATEGORY_CROSS", id = 11, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="dstMapId"},
			{type="int32", name="posX"},
			{type="int32", name="posY"},
			{type="int16", name="reason"},
			{type ="int32", name = "sceneInstanceId"},
			{type ="int32", name = "enterSceneType"}
		},
	},
	
	{
		define = "class", name = "MsgSyncCommonInfoToCrossServerRequest", category = "MSG_CATEGORY_CROSS", id = 13, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="heroId"},
			{type="int16", name="entityType"},
			{type = "CrossCommonStruct", name = "commonInfo",desc = "玩家数据"},
		},
	},
	
	{
		define = "class", name = "MsgSyncInfoToGameServerRequest", category = "MSG_CATEGORY_CROSS", id = 14, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type = "CrossCommonStruct", name = "commonInfoPlayer",desc = "玩家数据"},
			{type = "CrossCommonStruct", name = "commonInfoHero",desc = "英雄数据"},
		},
	},
	
	{
		define = "class", name = "MsgSwitchCSMapRequest", category = "MSG_CATEGORY_CROSS", id = 15, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="dstMapId"},
			{type="int32", name="posX"},
			{type="int32", name="posY"},
		},
	},
	
	{
		define = "class", name = "MsgKickPlayerFromCSRequest", category = "MSG_CATEGORY_CROSS", id = 16, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
		},
	},
	
	{
		define = "class", name = "MsgNotifyGameServerItemAdd", category = "MSG_CATEGORY_CROSS", id = 51, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
			{type = "int32", name = "bindType"},
			{type = "int32", name = "bag"},
			{type = "int32", name = "monster"},
			{type = "int32", name = "opcode"},
			{type = "string", name = "firstowner"},
			{type = "string", name = "appraiser"},
            {type = "CrossItemProp", name = "itemProps", vector=true},
		},
	},
	
	{
		define = "class", name = "MsgNotifyCrossServerItemAbandon", category = "MSG_CATEGORY_CROSS", id = 52, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "warZoneLineId"},
			{type = "int32", name = "mapId"},
			{type = "int32", name = "mapLineId"},
			{type = "int32", name = "itemId"},
			{type = "int32", name = "itemCount"},
			{type = "int32", name = "posX"},
			{type = "int32", name = "posY"},
			{type = "string", name = "firstowner"},
			{type = "string", name = "appraiser"},
			{type = "CrossItemProp", name = "itemProps", vector=true},
		},
	},
	{
		define = "class", name = "MsgCrossMapDropRequest", category = "MSG_CATEGORY_CROSS", id = 55, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "int32", name = "mapId"},
			{type = "int32", name = "mapLineId"},
			{type = "int32", name = "posx"},
			{type = "int32", name = "posy"},
			{type = "string", name = "killerName"},
		},
	},
	
	{
		define = "class", name = "MsgReviveInCSMapRequest", category = "MSG_CATEGORY_CROSS", id = 56, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "int32", name = "subType"},
		},
	},
	
	{
		define = "class", name = "MsgReviveInCSMapResponse", category = "MSG_CATEGORY_CROSS", id = 57, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "int32", name = "subType"},
		},
	},
	
	{
		define = "class", name = "MsgConveyToSceneRequest", category = "MSG_CATEGORY_CROSS", id = 58, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "int32", name = "mapId"},
			{type = "int32", name = "posX"},
			{type = "int32", name = "posY"},
		},
	},
	
	{
		define = "class", name = "MsgSyncEventDataRequest", category = "MSG_CATEGORY_CROSS", id = 59, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "CrossEventData", name = "data"},
		},
	},
	
	{
		define = "class", name = "MsgResetAndSyncAllEventDataNotify", category = "MSG_CATEGORY_CROSS", id = 60, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "playerId"},
			{type = "CrossEventData", name = "events", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgUseItemInCSMapRequest", category = "MSG_CATEGORY_CROSS", id = 61, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="sid"},
			{type="int32", name="count"},
			{type="int32", name="rid"},
			{type="int32", name="targetType"},
		},
	},
	
	{
		define = "class", name = "MsgSyncCSPosToGSNotify", category = "MSG_CATEGORY_CROSS", id = 62, base = "MessageEx",
		attributes =
		{
			{type="int32", name="playerId"},
			{type="int32", name="mapId"},
			{type="int32", name="mapLineId"},
			{type="int32", name="posX"},
			{type="int32", name="posY"},
		},
	},
	
	{
		define = "class", name = "MsgBroadcastSystemPromptToGSNotify", category = "MSG_CATEGORY_CROSS", id = 63, base = "MessageEx",
		attributes =
		{
			{type="int32", name="serverId"},
			{type = "string", name = "msg"},
			{type = "string", name = "touchID"},
			{type = "int32", name = "itemSid"},
			{type = "int32", name = "showflag"},
		},
	},
	
	{
		define = "struct", name = "CrossBossInfo",
		attributes =
		{
			{type = "int32", name = "index"},
			{type = "int32", name = "bossId"},
			{type = "int32", name = "freshTime"},
			{type = "int16", name = "alive"},
		},
	},
	
	{
		define = "class", name = "MsgSyncBossInfoToGSNotify", category = "MSG_CATEGORY_CROSS", id = 64, base = "MessageEx",
		attributes =
		{
			{type="int32", name="serverId"},
			{type="int32", name="sceneId"},
			{type = "CrossBossInfo", name = "list", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgGetQualifiedPlayerListNearbyRequest", category = "MSG_CATEGORY_CROSS", id = 66, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "condition"},
		},
	},
	
	{
		define = "class", name = "MsgGetQualifiedPlayerListNearbyResponse", category = "MSG_CATEGORY_CROSS", id = 67, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "condition"},
			{type = "int32", name = "list", vector = true},
		},
	},
	
	{
		define = "struct", name = "WarZoneDropInfo",
		attributes =
		{
			{type = "int32", name = "killerPid"},
			{type = "string", name = "killerName"},
			{type = "string", name = "gameServerName"},
			{type = "int32", name = "mapId"},
			{type = "int32", name = "monsterId"},
			{type = "int32", name = "dropItemId"},
			{type = "int32", name = "dropTime"},
		},
	},
	
	{
		define = "class", name = "MsgSyncWarZoneDropInfo", category = "MSG_CATEGORY_CROSS", id = 68, base = "MessageEx",
		attributes =
		{
			{type = "int16", name = "reload"},
			{type = "WarZoneDropInfo", name = "topDropInfoList", vector = true},
			{type = "WarZoneDropInfo", name = "dropInfoList", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgSyncWarZoneDropInfoToCS", category = "MSG_CATEGORY_CROSS", id = 69, base = "MessageEx",
		attributes =
		{
			{type = "int16", name = "top"},
			{type = "int32", name = "serverId"},
			{type = "WarZoneDropInfo", name = "record"},
		},
	},
	
	{
		define="struct", name="CrossAcution",
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
		define = "struct" , name = "RyzRank",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "zhiye"},
			{type = "int32", name = "chengji"},
			{type = "int32", name = "ryz"},
			{type = "int32", name = "force"},
			{type = "int32", name = "robbedCnt"},
			{type = "int32", name = "fighting"},
			{type = "int32", name = "challengeCnt"},
			{type = "int32", name = "lastchallengetime"},
			{type = "int32", name = "sourceWorldID"},
			{type = "int32", name = "warzoneID"},
			{type = "int32", name = "logintime"},
			{type = "string", name = "sourceSvrName"},
		},
	},
	
	{
		define = "class", name = "MsgAddItemToCrossAuctionRequset", category = "MSG_CATEGORY_CROSS", id = 70, base = "MessageEx",
		attributes =
		{
			{type = "CrossAcution", name = "auctionItem"},
		},
	},
	
	{
		define = "class", name = "MsgCrossAuctionItemAddNotify", category = "MSG_CATEGORY_CROSS", id = 71, base = "MessageEx",
		attributes =
		{
			{type = "int16", name = "reload"},
			{type = "CrossAcution", name = "auctionItemList", vector=true},
		},
	},
	
	{
		define = "class", name = "MsgCrossAuctionItemRmvNotify", category = "MSG_CATEGORY_CROSS", id = 72, base = "MessageEx",
		attributes =
		{
			{type = "CrossAcution", name = "auctionItemList", vector=true},
		},
	},
	
	{
		define = "class", name = "MsgCrossAuctionRecordNotify", category = "MSG_CATEGORY_CROSS", id = 73, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyer_pid", desc="竞价人pid"},
            {type="string", name="buyer_name", desc="竞价人名字"},
			{type="int32", name="other_pid", desc="卖家pid"},
            {type="string", name="other_name", desc="卖家名字"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
            {type="int32", name="fixed_price", desc="一口价"},
            {type="int32", name="things_type", desc="货币类型"},
			{type="int16", name="ctype", desc="货币类型"},
		},
	},
	
	{
		define = "class", name = "MsgCheckBuyCrossAuctionItemRequest", category = "MSG_CATEGORY_CROSS", id = 74, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyer_pid", desc="竞价人pid"},
			{type="int32", name="buyer_server_id", desc="竞价人区服id"},
			{type="int32", name="buyer_war_zone_id", desc="竞价人战区id"},
            {type="int64", name="aid", desc="拍卖ID"},
			{type="int16", name="type", desc="竞拍类型"},
		},
	},
	
	{
		define = "class", name = "MsgCheckBuyCrossAuctionItemResponse", category = "MSG_CATEGORY_CROSS", id = 75, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyer_pid", desc="竞价人pid"},
            {type="int64", name="aid", desc="拍卖ID"},
			{type="int16", name="type", desc="竞拍类型"},
			{type="int32", name="errcode", desc="错误码"},
		},
	},
	
	{
		define = "class", name = "MsgBuyCrossAuctionItemRequest", category = "MSG_CATEGORY_CROSS", id = 76, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyer_pid", desc="竞价人pid"},
            {type="string", name="buyer_name", desc="竞价人名字"},
			{type="int32", name="buyer_server_id", desc="竞价人区服id"},
			{type="int32", name="buyer_war_zone_id", desc="竞价人战区id"},
			{type="int32", name="cost_money", desc="出价"},
			{type="int32", name="money_type", desc="货币类型"},
            {type="int64", name="aid", desc="拍卖ID"},
			{type="int32", name="sid", desc="拍卖物品id"},
			{type="int16", name="type", desc="竞拍类型"},
		},
	},
	
	{
		define = "class", name = "MsgBuyCrossAuctionItemResponse", category = "MSG_CATEGORY_CROSS", id = 77, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyer_pid", desc="竞价人pid"},
			{type="int32", name="buyer_server_id", desc="竞价人区服id"},
            {type="int32", name="cost_money", desc="出价"},
			{type="int32", name="money_type", desc="货币类型"},
			{type="int32", name="sid", desc="拍卖物品id"},
			{type="int16", name="type", desc="竞拍类型"},
			{type="int32", name="errcode", desc="错误码"},
		},
	},
	
	{
		define = "class", name = "MsgCrossAuctionItemUpdNotify", category = "MSG_CATEGORY_CROSS", id = 78, base = "MessageEx",
		attributes =
		{
			{type = "CrossAcution", name = "auctionItem"},
		},
	},
		{
		define = "struct", name="CrossConsignmentItemProp",
		attributes =
		{
			{type="int16", name="idx"},
			{type="int32", name="data"},
		}
	},
	{
		define="struct", name="CrossConsignment",
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
			{type="CrossConsignmentItemProp", name="props", vector =true},
		}
	},

	{
		define = "class", name = "MsgAddConsignmentToCrossRequest", category = "MSG_CATEGORY_CROSS", id = 79, base = "MessageEx",
		attributes =
		{
			{type="int32", name="pid"},
			{type="string", name="name"},
			{type="int32", name="srcServerId"},
			{type="string", name="srcServerName"},
			{type="int32", name="warZoneId"},
			{type="int32", name="sid"},
			{type="int32", name="taxRate"},
			{type="int32", name="count"},
			{type="int32", name="price"},
			{type="int32", name="time"},
			{type="int32", name="cTime", desc="寄售时间"},
			{type="int32", name="eTime", desc="结束时间"},
			{type="int32", name="mailTip", desc="过期邮件提示"},
			{type="string", name="firstOwner", desc="第一个拥有者"},
			{type="string", name="appraiser", desc="鉴定者"},
			{type="CrossConsignmentItemProp", name="props", vector =true},
		},
	},
	
	{
		define = "class", name = "MsgAddConsignmentToCrossResponse", category = "MSG_CATEGORY_CROSS", id = 80, base = "MessageEx",
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="errcode"},
			{type="int32", name="sid"},
			{type="int32", name="count"},
		},
	},
	
	{
		define = "class", name = "MsgCrossConsignmentAddNotify", category = "MSG_CATEGORY_CROSS", id = 81, base = "MessageEx",
		attributes =
		{
			{type="CrossConsignment", name="item"},
		},
	},
	
	{
		define = "class", name = "MsgCrossConsignmentRmvNotify", category = "MSG_CATEGORY_CROSS", id = 82, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
		},
	},
	
	{
		define = "class", name = "MsgCrossConsignmentUpdNotify", category = "MSG_CATEGORY_CROSS", id = 83, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="newCount"},
		},
	},
	
	{
		define = "class", name = "MsgCheckBuyCrossConsignmentRequest", category = "MSG_CATEGORY_CROSS", id = 84, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="buyerServerId"},
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="count"},
		},
	},
	
	{
		define = "class", name = "MsgCheckBuyCrossConsignmentResponse", category = "MSG_CATEGORY_CROSS", id = 85, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="count"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgSendSellerRewardRequest", category = "MSG_CATEGORY_CROSS", id = 86, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="buyerServerId"},
			{type="string", name="buyerName"},
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="count"},
		},
	},
	
	{
		define = "class", name = "MsgSendSellerRewardResponse", category = "MSG_CATEGORY_CROSS", id = 87, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="count"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgRmvCrossConsignmentRequest", category = "MSG_CATEGORY_CROSS", id = 88, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerServerId"},
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
		},
	},
	
	{
		define = "class", name = "MsgRmvCrossConsignmentResponse", category = "MSG_CATEGORY_CROSS", id = 89, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="cid"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgSyncAllCrossConsignmentNotify", category = "MSG_CATEGORY_CROSS", id = 90, base = "MessageEx",
		attributes =
		{
			{type="CrossConsignment", name="list", vector=true},
		},
	},
	{
		define = "struct", name = "crossChatPlayerProp",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "value"},
		},
	
	},
	{
		define = "class", name = "MsgSyncCrossChatNotify", category = "MSG_CATEGORY_CROSS", id = 91, base = "MessageEx",
		attributes =
		{
			{type = "int16", name = "chatType"},
			{type = "int32", name = "pid"},
			{type = "string", name = "playerName"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "vipLevel"},
			{type = "string", name = "chatText"},
            {type = "int16", name = "level"},
            {type = "int16", name = "job"},
            {type = "int16", name = "position"},
            {type = "int32", name = "redID"},
            {type = "int32", name = "targetPid"},
            {type = "string", name = "guildName"},
            {type = "int32", name = "serverid"},
            {type = "crossChatPlayerProp", name = "props", vector = true},
		},
	},
	{
		define = "class", name = "MsgSendCrossChaToCsRequest", category = "MSG_CATEGORY_CROSS", id = 92, base = "MessageEx",
		attributes =
		{
			{type = "int16", name = "chatType"},
			{type = "int32", name = "pid"},
			{type = "string", name = "playerName"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "vipLevel"},
			{type = "string", name = "chatText"},
            {type = "int16", name = "level"},
            {type = "int16", name = "job"},
            {type = "int16", name = "position"},
            {type = "int32", name = "redID"},
            {type = "int32", name = "targetPid"},
            {type = "string", name = "guildName"},
            {type = "int32", name = "serverid"},
            {type = "crossChatPlayerProp", name = "props", vector = true},
		},
	},
	{
		define = "class", name = "MsgGetPlayerCrossPropRequest", category = "MSG_CATEGORY_CROSS", id = 93, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type="int32", name="ctype"},
		},
	},
	{
		define = "class", name = "MsgPlayerCSActionNotify", category = "MSG_CATEGORY_CROSS", id = 94, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "crossActionType"},
			{type = "CrossIntProp", name = "intParams", vector=true, desc = "整型参数"},
			{type = "CrossStrProp" , name = "strParams" , vector = true , desc = '字符参数'},
		},
	},
	
	{
		define = "class", name = "MsgAddGeneInGameServerRequest", category = "MSG_CATEGORY_CROSS", id = 95, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "geneId"},
			{type = "int32", name = "geneType"},
			{type = "int32", name = "geneGroup"},
			{type = "int32", name = "geneDuration"},
			{type = "int16", name = "geneInherit"},
			{type = "int32", name = "geneDatax"},
			{type = "int32", name = "geneDatay"},
			{type = "int32", name = "geneDataz"},
			{type = "int32", name = "geneDatau"},

		},
	},
	
	{
		define = "class", name = "MsgRmvGeneFromGameServerRequest", category = "MSG_CATEGORY_CROSS", id = 96, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "geneId"},
		},
	},
	{
		define = "class", name = "MsgCheckPlayerAllCrossPropRequest", category = "MSG_CATEGORY_CROSS", id = 97, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "CrossCommonStruct", name = "commonInfo",desc = "玩家数据"},
			{type = "CrossEventData", name = "events", vector = true},
		},
	},
	{
		define = "class", name = "MsgCrossGetPlayerSerializeInfoG2C", category = "MSG_CATEGORY_CROSS", id = 103, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "sourceWorldId"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "enemy_pid"},
			{type = "int32", name = "action"},
			{type = "int32", name = "scene_static_id"},
			{type = "string", name = "json"},
		},
	},
	{
		define = "class", name = "MsgCrossGetPlayerSerializeInfoC2G", category = "MSG_CATEGORY_CROSS", id = 104, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "enemy_pid"},
			{type = "int32", name = "action"},
			{type = "int32", name = "scene_static_id"},
			{type = "int32", name = "errcode"},
			{type = "string", name = "json"},
		},
	},
	{
		define = "struct" , name = "UpdateSerializeUnit",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "force"},
			{type = "string", name = "name"},
			{type = "string", name = "json"},
		},
	},
	
	{
		define="struct", name="CrossPurchase",
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
		define = "class", name = "MsgAddPurchaseToCrossRequest", category = "MSG_CATEGORY_CROSS", id = 115, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="string", name="buyerName"},
			{type="int32", name="buyerServerId"},
			{type="string", name="buyerServerName"},
			{type="int32", name="buyerWarZoneId"},
			{type="int32", name="sid"},
			{type="int32", name="count"},
			{type="int32", name="price"},
			{type="int32", name="time"},
		},
	},
	
	{
		define = "class", name = "MsgAddPurchaseToCrossResponse", category = "MSG_CATEGORY_CROSS", id = 116, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="sid"},
			{type="int32", name="count"},
			{type="int32", name="price"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgCrossPurchaseAddNotify", category = "MSG_CATEGORY_CROSS", id = 117, base = "MessageEx",
		attributes =
		{
			{type="CrossPurchase", name="crossPurchase"},
		},
	},
	
	{
		define = "class", name = "MsgCrossPurchaseRmvNotify", category = "MSG_CATEGORY_CROSS", id = 118, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
		},
	},
	
	{
		define = "class", name = "MsgCrossPurchaseUpdNotify", category = "MSG_CATEGORY_CROSS", id = 119, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="newCount"},
		},
	},
	
	{
		define = "class", name = "MsgTrySellCrossPurchaseRequest", category = "MSG_CATEGORY_CROSS", id = 120, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="sellerServerId"},
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="sellCounts"},
		},
	},
	
	{
		define = "class", name = "MsgTrySellCrossPurchaseResponse", category = "MSG_CATEGORY_CROSS", id = 121, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sellerPid"},
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="sellCounts"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgSendBuyerPurchaseItemRequest", category = "MSG_CATEGORY_CROSS", id = 122, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="sellerPid"},
			{type="string", name="sellerName"},
			{type="int32", name="sellerServerId"},
			{type="int32", name="sellCounts"},
		},
	},
	
	{
		define = "class", name = "MsgSendBuyerPurchaseItemResponse", category = "MSG_CATEGORY_CROSS", id = 123, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="sellerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgRmvCrossPurchaseRequest", category = "MSG_CATEGORY_CROSS", id = 124, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerServerId"},
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
		},
	},
	
	{
		define = "class", name = "MsgRmvCrossPurchaseResponse", category = "MSG_CATEGORY_CROSS", id = 125, base = "MessageEx",
		attributes =
		{
			{type="int32", name="buyerPid"},
			{type="int32", name="purchaseId"},
			{type="int32", name="errcode"},
		},
	},
	
	{
		define = "class", name = "MsgSyncAllCrossPurchaseNotify", category = "MSG_CATEGORY_CROSS", id = 126, base = "MessageEx",
		attributes =
		{
			{type="CrossPurchase", name="list", vector=true},
		},
	},

	{
		define = "class", name = "MsgPlayerChangeNotify", category = "MSG_CATEGORY_CROSS", id = 128, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "lvl"},
		},
	},
	{
		define = "class", name = "MsgCrossPlayerStateG2C", category = "MSG_CATEGORY_CROSS", id = 130, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "state"},
		},
	},

	{
		define = "struct", name = "CrossMap",
		attributes =
		{
			{type = "int16", name = "index"},
			{type = "int32", name = "map_id"},
		}
	},
	{
		define = "class", name = "MsgGetBossCntInCrossMapRequest", category = "MSG_CATEGORY_CROSS", id = 131, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "source_world_id"},
			{type = "int32", name = "warzone_line_id"},
			{type = "int32", name = "pid"},
			{type = "CrossMap", name = "cross_maps", vector = true},
			{type = "string", name = "targetName"}
		},
	},
	{
		define = "struct", name = "CrossMapBossInfo",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int32", name = "count"}, 
		}
	},
	{
		define = "struct", name = "CrossMapBossCount",
		attributes =
		{
			{type = "int16", name = "index"},
			{type = "int32", name = "count"},
			{type = "int32", name = "sceneId"},
			{type = "CrossMapBossInfo",   name = "boss_list", vector = true},
		}
	},
	{
		define = "class", name = "MsgGetBossCntInCrossMapNotify", category = "MSG_CATEGORY_CROSS", id = 132, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "CrossMapBossCount", name = "boss_cnts", vector = true},
			{type = "string", name = "targetName"}
		},
	},
	{
		define = "class", name = "MsgServerDaysNotify", category = "MSG_CATEGORY_CROSS", id = 133, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "server_id"},
			{type = "int32", name = "server_days"},
		},
	},

	{
		define = "struct", name = "SkillExpAdd",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "addexp"},
		},
	},
	{
		define = "class", name = "MsgSyncSkillExpAddToGameServer", category = "MSG_CATEGORY_CROSS", id = 134, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "opcode"},
            {type = "SkillExpAdd", name = "skillList", vector=true},
		},
	},

    {
		define = "class", name = "MsgEnterGameGuajiRequest", category = "MSG_CATEGORY_CROSS", id = 135, base = "MessageEx",
		attributes =
		{
            {type = "int32", name = "sourceServerId"},
			{type = "int32", name = "pid"},
		},
	},

    {
		define = "class", name = "MsgNotifyGameServerExpAdd", category = "MSG_CATEGORY_CROSS", id = 136, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "count"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "opdata"},
		},
	},

    {
		define = "class", name = "MsgNotifyInitDreamNotify", category = "MSG_CATEGORY_CROSS", id = 137, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},
    {
		define = "class", name = "MsgRemoveChatCrossRequest", category = "MSG_CATEGORY_CROSS", id = 138, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "src_server_id"},
			{type = "int32", name = "pid"},
		},
	},
    {
		define = "class", name = "MsgRemoveChatCrossNotify", category = "MSG_CATEGORY_CROSS", id = 139, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

    {
		define = "class", name = "MsgSetCrossFlagNotify", category = "MSG_CATEGORY_CROSS", id = 140, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "flag"},
		},
	},
	{
		define = "class", name = "MsgSendSWZDZAwardNotify", category = "MSG_CATEGORY_CROSS", id = 141, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "GuildID"},
		},
	},
	
	{
		define = "class", name = "MsgSyncPlayerDeletedNotify", category = "MSG_CATEGORY_CROSS", id = 152, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "serverid"},
		},
	},
	
	{
		define = "class", name = "MsgSyncGuildDeletedNotify", category = "MSG_CATEGORY_CROSS", id = 153, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildid"},
            {type = "int32", name = "serverid"},
		},
	},
	
	{
		define = "class", name = "MsgSyncPlayerRenameNotify", category = "MSG_CATEGORY_CROSS", id = 154, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "serverid"},
			{type = "string", name = "newName"},
		},
	},
	
	{
		define = "class", name = "MsgSyncGuildRenameNotify", category = "MSG_CATEGORY_CROSS", id = 155, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildid"},
            {type = "int32", name = "serverid"},
			{type = "string", name = "newName"},
		},
	},
	
	{
		define = "class", name = "MsgSendSWYAwardNotify", category = "MSG_CATEGORY_CROSS", id = 164, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "serverid"},			
			{type = "int32", name = "rank"},
			{type = "int32", name = "rankType"},
			{type = "int32", name = "gid"},
		},
	},
	{
		define = "class", name = "MsgSendGuildBattleAwardNotify", category = "MSG_CATEGORY_CROSS", id = 165, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "serverid"},			
			{type = "int32", name = "rank"},
			{type = "int32", name = "rankType"},
		},
	},
	
	{
		define = "class", name = "MsgGSBroadcastAllGSRequest", category = "MSG_CATEGORY_CROSS", id = 168, base = "MessageEx",
		attributes =
		{
			{type = "string", name = "basestring"},			
			{type = "int32", name = "showflag"},
			{type = "string", name = "TouchID"},
			{type = "int32", name = "serverid"},
		},
	},
	{
		define = "class", name = "MsgGSBroadcastAllGSResponse", category = "MSG_CATEGORY_CROSS", id = 169, base = "MessageEx",
		attributes =
		{
			{type = "string", name = "basestring"},			
			{type = "int32", name = "showflag"},
			{type = "string", name = "TouchID"},
		},
	},
	
	{
		define = "class", name = "MsgSyncGuildMasterNotify", category = "MSG_CATEGORY_CROSS", id = 170, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildid"},
            {type = "int32", name = "serverid"},
			{type = "int32", name = "masterpid"},
		},
	},
	
	{
		define = "class", name = "MsgSyncPlayerJobNotify", category = "MSG_CATEGORY_CROSS", id = 175, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "serverid"},
			{type = "int32", name = "job"},
		},
	},
	
	{
		define = "class", name = "MsgSyncCrossActivityNotify", category = "MSG_CATEGORY_CROSS", id = 176, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "reset"},
		},
	},

	{
		define = "class", name = "MsgSyncWordDataToGSNotify", category = "MSG_CATEGORY_CROSS", id = 177, base = "MessageEx",
		attributes =
		{
			{type="int32", name="serverId"},
			{type = "int32", name = "wprop"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},

		},
	},

	{
		define = "class", name = "MsgChangeCsWordDataRequestFromGs", category = "MSG_CATEGORY_CROSS", id = 178, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "wprop"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},

		},
	},
	
	{
		define = "class", name = "MsgRemoveCSGeneFromeGSNotify", category = "MSG_CATEGORY_CROSS", id = 179, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "serverid"},
			{type = "int32", name = "geneid"},
		},
	},	
	{
		define = "class", name = "MsgDoctorPlayerNotify", category = "MSG_CATEGORY_CROSS", id = 180, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "serverid"},
		},
	},
	{
		define = "class", name = "MsgAddHYDScoreNotify", category = "MSG_CATEGORY_CROSS", id = 181, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "eventId"},
		},
	},
	{
		define = "class", name = "MsgCS2GS", category = "MSG_CATEGORY_CROSS", id = 182, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "funcID"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name = "MsgGS2CS", category = "MSG_CATEGORY_CROSS", id = 183, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "funcID"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name = "MsgGetPlayerBaseInfoFromGSRequest", category = "MSG_CATEGORY_CROSS", id = 191, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerId"},

			{type = "int32", name = "pid"},	
			{type = "int32", name = "serverId"},					
		},
	},
	
	{
		define = "class", name = "MsgGetPlayerBaseInfoFromGSResponse", category = "MSG_CATEGORY_CROSS", id = 192, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerId"},

			{type = "int32", name = "pid"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "job"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "dressWeapon"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "dressCloth"},
			{type = "int32", name = "hat"},
			{type = "int32", name = "shield"},
			{type = "int32", name = "guardLevel"},
			{type = "int32", name = "hunhuan"},
			{type = "int32", name = "jingling"},				
		},
	},
	
	{
		define = "class", name = "MsgGetPlayerBaseInfoFromCSRequest", category = "MSG_CATEGORY_CROSS", id = 193, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerId"},

			{type = "int32", name = "pid"},	
			{type = "int32", name = "serverId"},					
		},
	},
	
	{
		define = "class", name = "MsgGetPlayerBaseInfoFromCSResponse", category = "MSG_CATEGORY_CROSS", id = 194, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerId"},

			{type = "int32", name = "pid"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "job"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "dressWeapon"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "dressCloth"},
			{type = "int32", name = "hat"},
			{type = "int32", name = "shield"},
			{type = "int32", name = "guardLevel"},	
			{type = "int32", name = "hunhuan"},
			{type = "int32", name = "jingling"},				
		},
	},

	{
		define = "struct" , name = "CrossDBRankData",
		attributes =
		{
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int32", name = "time", desc = "上榜时间"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "gid"},
			{type = "string", name = "name"},
			{type = "string", name = "guildName"},		
		},
	},

	{
		define = "class", name = "MsgSendPlayerGreyNameToGS", category = "MSG_CATEGORY_CROSS", id = 195, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},				
		},
	},
	
	{
		define = "class", name = "MsgSendPlayerKillWhiteRoleToGS", category = "MSG_CATEGORY_CROSS", id = 196, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},			
		},
	},
	
	{
		define = "class", name = "MsgSendGSRankToCS", category = "MSG_CATEGORY_CROSS", id = 197, base = "MessageEx",
		attributes=
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "warZoomId"},
			{type = "int32", name = "serverId"},
			{type = "CrossDBRankData", name = "list", vector = true},
		},
	},

	{
		define = "class", name = "MsgSendCSRankToGS", category = "MSG_CATEGORY_CROSS", id = 198, base = "MessageEx",
		attributes=
		{
			{type = "int32", name = "type"},
			{type = "CrossDBRankData", name = "list", vector = true},
		},
	},

	{
		define = "class", name = "MsgLoadCSRankNotify", category = "MSG_CATEGORY_CROSS", id = 199, base = "MessageEx",
		attributes=
		{
			{type = "int32", name = "warZoomId"},
			{type = "int32", name = "serverId"},
		},
	},
}

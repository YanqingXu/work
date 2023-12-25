messages =
{
	{
		define = "struct", name = "ItemBase",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
		},
	},
	{
		define = "struct", name = "ItemBase64",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "countLow"},
			{type = "int32", name = "countHigh"},
		},
	},

	{
		define = "struct", name = "ItemInfo",
		attributes =
		{
			 {type="int32", name="iid"},
			 {type="int32",	name="sid"},
			 {type="int16", name="bind"},
			 {type="int16", name="count"},
			 {type="int16", name="position"},
			 {type="string", name="firstowner"},
			 {type="string", name="appraiser"},
		}
	},

	{
		define = "struct", name = "ItemExData",
		attributes =
		{
			{type = "int16", name = "nIdx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name="MsgItemInfoNotify", category = "MSG_CATEGORY_ITEM" , id = 1 ,base = "Message",
		 attributes =
		 {
			{type = "int32",	name = "pid" , dump = true},
			{type = "ItemInfo",	name = "item_list",vector = true},
		 },
	},

	{
		define = "class", name = "MsgItemAddNotifyEx", category = "MSG_CATEGORY_ITEM", id = 4, base = "Message",
		attributes =
		{
			{type = "int32"	,		name = "opcode"},
			{type = "ItemInfo" , 		name = "iteminfo"},
			{type = "ItemExData" , 		name = "data", vector = true},
		},
	},

	{
		define = "class", name = "MsgItemRmvNotify", category = "MSG_CATEGORY_ITEM", id = 5, base = "Message",
		attributes =
		{
			{type = "int32"	,	name = "opcode"},
			{type = "int32" ,	name = "iid", dump = true},
		},
	},

	--
	--	Item Update Base
	--
	{
		define = "class", name="MsgItemUpdItemBaseNotify", category = "MSG_CATEGORY_ITEM" , id = 6,base = "Message",
		 attributes =
		 {
		--	{type = "int32",	name = "pid" , dump = true},
			{type = "int32",	name = "opcode" },
			{type = "ItemInfo",	name = "item"},
		 },
	},

	{
		define = "class", name = "MsgItemUpdExDataNotify", category = "MSG_CATEGORY_ITEM", id = 7, base = "Message",
		attributes =
		{
			{type = "int32"	,	name = "opcode"},
			{type = "int32" , 	name = "iid"},
			{type = "ItemExData", name = "data", vector = true},
		},
	},

	{
		define = "class", name = "MsgItemInfoDataGetRequest", category = "MSG_CATEGORY_ITEM", id = 8, base = "Message",
		attributes =
		{
			{type = "int32",	name = "eid"},
			{type = "int32", 	name = "pid"},
			{type = "int32", 	name = "iid"},
		},
	},

	{
		define = "class", name = "MsgItemInfoDataGetResponse", category = "MSG_CATEGORY_ITEM", id = 9, base = "Message",
		attributes =
		{
			{type = "int16", 	name = "errcode"},
			{type = "int32",	name = "eid"},
			{type = "int32", 	name = "pid"},
			{type = "int32", 	name = "iid"},
			{type = "int32", 	name = "pos"},
			{type = "ItemExData", name = "data", vector = true},
		},
	},

	--
	--	Item update speicific attributes
	--
	{
		define = "class", name = "MsgItemUpdCountNotify", category = "MSG_CATEGORY_ITEM", id = 10, base = "Message",
		attributes =
		{
			{type = "int32"	,	name = "opcode"},
			{type = "int32" , 	name = "iid", dump = true},
			{type = "int16" ,	name = "count"},
		},
	},

	{
		define = "class", name = "MsgItemUpdPositionNotify", category = "MSG_CATEGORY_ITEM", id = 11, base = "Message",
		attributes =
		{
			{type = "int32"	,	name = "opcode"},
			{type = "int32" , 	name = "iid", dump = true},
			{type = "int16" ,	name = "position"},
		},
	},

	{
		define = "class", name = "MsgItemUpdSidNotify", category = "MSG_CATEGORY_ITEM", id = 12, base = "Message",
		attributes =
		{
			{type = "int32" ,	name = "iid", dump = true},
			{type = "int32",	name = "opcode" },
			{type = "int32" , 	name = "sid"},
		},
	},

	{
		define = "class", name = "MsgItemUpdDataNotify", category = "MSG_CATEGORY_ITEM", id = 13, base = "Message",
		attributes =
		{
			{type = "int32"	,	name = "opcode"},
			{type = "int32" , 	name = "iid", dump = true},
			{type = "int16" ,	name = "idx"},
			{type = "int32" ,	name = "data"},
		},
	},

	{
		define = "class", name = "MsgItemResolveRequest", category = "MSG_CATEGORY_ITEM", id = 15, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "iid", dump = true},
			{type = "int16" ,	name = "bagtype"},
			{type = "int32" ,	name = "count"},
		},
	},

	--
	--	物品操作返回通知
	--
	{
		define = "class", name = "MsgItemOperationNotify", category = "MSG_CATEGORY_ITEM", id = 20, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32"	,name = "opcode"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgItemOperationRequestBuy", category = "MSG_CATEGORY_ITEM", id = 22, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "count", dump = true},
		},
	},

	{
		--删除物品
		define = "class", name = "MsgItemOperationRequestDelete", category = "MSG_CATEGORY_ITEM", id = 23, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "count", dump = true},
		},
	},

	{
		--物品合成
		define = "class", name = "MsgItemOperationRequestMerge", category = "MSG_CATEGORY_ITEM", id = 27, base = "Message",
		attributes =
		{
			{type = "int32", name = "sid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "usepoints", dump = true},
		},
	},

	{
		--魂石转化
		define = "class", name = "MsgItemOperationRequestStoneTrans", category = "MSG_CATEGORY_ITEM", id = 28, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "tgtsid", dump = true},
		},
	},

	{
		--极品转移
		define = "class", name = "MsgItemOperationRequestChangeSpecialAttr", category = "MSG_CATEGORY_ITEM", id = 30, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "tgtiid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},
	
	{
		--物品使用
		define = "class", name = "MsgItemOperationRequestUse", category = "MSG_CATEGORY_ITEM",id = 32, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "cnt", dump = true},
			{type = "int16", name = "type", dump = true},
			{type = "int32", name = "pos", dump = true},  --替换装备时，戒指 手镯 这种要指定装备位

		},
	},

	{   -- 设置物品position
		define = "class", name = "MsgItemOperationRequestSetPosition", category = "MSG_CATEGORY_ITEM", id  = 33, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "position"},
			{type = "int16", name = "exchange"},
			{type = "int16", name = "flag"},
		},
	},

	{
		--强化转移
		define = "class", name = "MsgItemOperationRequestChangeEnhance", category = "MSG_CATEGORY_ITEM", id = 34, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "tgtiid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--鉴定转移
		define = "class", name = "MsgItemOperationRequestChangeEvaluate", category = "MSG_CATEGORY_ITEM", id = 35, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "tgtiid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--极品清洗
		define = "class", name = "MsgItemOperationRequestClearSpecialAttr", category = "MSG_CATEGORY_ITEM", id = 36, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		define = "class", name = "MsgItemOperationRequestPile", category = "MSG_CATEGORY_ITEM", id  = 37, base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "bagtype"},
			{type = "int32", name = "num"},
		},
	},

	{
		define = "class", name = "MsgItemOperationResponsePile", category = "MSG_CATEGORY_ITEM", id  = 38, base = "Message",
		attributes =
		{
			{type = "int32", name = "num"},
			{type = "int32", name = "errorcode"},
		},
	},

	{   -- 交换物品position
		define = "class", name = "MsgItemOperationMovePositionRequest", category = "MSG_CATEGORY_ITEM", id  = 39, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "position"},
		},
	},

	{   
		define = "class", name = "MsgItemOperationMovePositionResponse", category = "MSG_CATEGORY_ITEM", id  = 40, base = "Message",
		attributes =
		{
			{type = "int32", name = "errorCode"},
			{type = "int32", name = "iidNew"},
			{type = "int32", name = "positionNew"},
			{type = "int32", name = "iidOld"},
			{type = "int32", name = "positionOld"},
		},
	},

	--
	--	装备操作
	--
	{
		--装备升级
		define = "class", name = "MsgItemOperationRequestUpgrade", category = "MSG_CATEGORY_ITEM", id = 41, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "secondiid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备强化
		define = "class", name = "MsgItemOperationRequestEnhance", category = "MSG_CATEGORY_ITEM", id = 42, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "enhancetype", dump = true},
			{type = "int32", name = "isProtect", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备鉴定
		define = "class", name = "MsgItemOperationRequestEvaluate", category = "MSG_CATEGORY_ITEM", id = 43, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备清洗
		define = "class", name = "MsgItemOperationRequestClearItem", category = "MSG_CATEGORY_ITEM", id = 44, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "block1", dump = true},
			{type = "int32", name = "block2", dump = true},
			{type = "int32", name = "block3", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备转生
		define = "class", name = "MsgItemOperationRequestReborn", category = "MSG_CATEGORY_ITEM", id = 45, base = "Message",
		attributes =
		{
			{type = "int32", name = "iidtgt", dump = true},
			{type = "int32", name = "iidreq", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备完美强化
		define = "class", name = "MsgItemOperationRequestPerfectEnhance", category = "MSG_CATEGORY_ITEM", id = 46, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "reqtype", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},

	{
		--装备打磨
		define = "class", name = "MsgItemOperationRequestPolish", category = "MSG_CATEGORY_ITEM", id = 48, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int16", name = "usevcoin", dump = true},
		},
	},
		
	{
		--物品分解(兑换成积分)
		define = "class", name = "MsgItemToPointsRequest", category = "MSG_CATEGORY_ITEM", id = 53, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
		},
	},

	{
		define = "class", name = "MsgMoveItemInStoreRequest", category = "MSG_CATEGORY_ITEM", id = 54, base = "Message",
		attributes =
		{
			{type = "int32", name = "page"},
			{type = "int32", name = "iid"},
			{type = "int32", name = "position"}
		},
	},

	{
		define = "class", name = "MsgMoveItemInBagRequest", category = "MSG_CATEGORY_ITEM", id = 55, base = "Message",
		attributes =
		{
			{type = "int32", name = "page"},
			{type = "int32", name = "iid"},
			{type = "int32", name = "position"}
		},
	},

	{
		define = "class", name = "MsgMoveItemResponse", category = "MSG_CATEGORY_ITEM", id = 56, base = "Message",
		attributes =
		{
			{type = "int32", name = "errorcode"},
		},
	},

	{
		define="class", name="MsgSyncGuildItemsNotify", category="MSG_CATEGORY_ITEM" , id=71 ,base="Message",
		attributes =
		{
			{type="int32", name="pid", dump=true},
			{type="ItemInfo", name="items", vector=true},
		},
	},

	{
		define="class", name="MsgAddGuildItemNotify", category="MSG_CATEGORY_ITEM", id=72, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="ItemInfo", name="iteminfo"},
			{type="ItemExData", name="props", vector=true},
		},
	},

	{
		define="class", name="MsgDeleteGuildItemNotify", category="MSG_CATEGORY_ITEM", id=73, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="int32", name="iid", dump=true},
		},
	},

	--
	--	Item Update Base
	--
	{
		define="class", name="MsgUpdateGuildItemBaseNotify", category="MSG_CATEGORY_ITEM", id=74, base="Message",
		attributes =
		{
		--	{type="int32", name="pid", dump=true},
			{type="int32", name="opcode"},
			{type="ItemInfo", name="item"},
		},
	},

	--
	--	Item update speicific attributes
	--
	{
		define="class", name="MsgUpdateGuildItemCountNotify", category="MSG_CATEGORY_ITEM", id=75, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="int32", name="iid", dump=true},
			{type="int16", name="count"},
		},
	},

	{
		define="class", name="MsgUpdateGuildItemPositionNotify", category="MSG_CATEGORY_ITEM", id=76, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="int32", name="iid", dump=true},
			{type="int16", name="position"},
		},
	},

	{
		define="class", name="MsgUpdateGuildItemSidNotify", category="MSG_CATEGORY_ITEM", id=77, base="Message",
		attributes =
		{
			{type="int32", name="iid", dump=true},
			{type="int32", name="opcode" },
			{type="int32", name="sid"},
		},
	},

	{
		define="class", name="MsgUpdateGuildItemPropNotify", category="MSG_CATEGORY_ITEM", id=78, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="int32", name="iid", dump=true},
			{type="int16", name="idx"},
			{type="int32", name="data"},
		},
	},

	{
		define="class", name="MsgUpdateGuildItemAllPropsNotify", category="MSG_CATEGORY_ITEM", id=79, base="Message",
		attributes =
		{
			{type="int32", name="opcode"},
			{type="int32", name="iid"},
			{type="ItemExData", name="props", vector=true},
		},
	},

	--
	--	other
	--
	{
		--提示是否成功
		define = "class", name = "MsgItemFailorSuccessNotify", category = "MSG_CATEGORY_ITEM", id = 100, base = "Message",
		attributes =
		{
			{type = "int32", name = "idx", dump = true},
			{type = "int32", name = "data", dump = true},
		},
	},

	--
	--	this is an testing message , will be remove after releasing
	--
	{
		define = "struct", name = "OtherEquip",
		attributes =
		{
			{type = "int32", name = "position"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "iid"},
			{type = "int16", name = "itemlvl"},
			{type = "int16", name = "itemreborn"},
		},
	},

	{
		define = "class", name = "MsgSyncOtherPlayerEquipNotify", category = "MSG_CATEGORY_ITEM", id = 150, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type ="OtherEquip", name = "equips", vector = true},
		},
	},

	{
		define = "class", name = "MsgItemShenLuUpRequest", category = "MSG_CATEGORY_ITEM", id = 151, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "index"},
		},
	},

	{
		define = "class", name = "MsgItemShenLuUpResponse", category = "MSG_CATEGORY_ITEM", id = 152, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{	-- 洗练
		define = "class", name = "MsgItemXiLianRequest", category = "MSG_CATEGORY_ITEM", id = 161, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "type"},
			{type = "int32", name = "single"},
			{type = "int32", name = "autobuy"},
		},
	},

	{
		define = "class", name = "MsgItemXiLianResponse", category = "MSG_CATEGORY_ITEM", id = 162, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "type"},
			{type = "int32", name = "single"},
		},
	},

	{	-- 洗练
		define = "class", name = "MsgItemXiLianSaveRequest", category = "MSG_CATEGORY_ITEM", id = 163, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},

	{
		define = "class", name = "MsgItemXiLianSaveResponse", category = "MSG_CATEGORY_ITEM", id = 164, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{	-- 洗练分解
		define = "class", name = "MsgItemXiLianFJRequest", category = "MSG_CATEGORY_ITEM", id = 165, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid1"},
			{type = "int32", name = "iid2"},
			{type = "int32", name = "iid3"},
			{type = "int32", name = "iid4"},
			{type = "int32", name = "iid5"},
			{type = "int32", name = "iid6"},
			{type = "int32", name = "iid7"},
			{type = "int32", name = "iid8"},
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class", name = "MsgItemXiLianFJResponse", category = "MSG_CATEGORY_ITEM", id = 166, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{	-- 洗练转移
		define = "class", name = "MsgItemXiLianZYRequest", category = "MSG_CATEGORY_ITEM", id = 167, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid1"},
			{type = "int32", name = "iid2"},
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class", name = "MsgItemXiLianZYResponse", category = "MSG_CATEGORY_ITEM", id = 168, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{	
		-- 饰品重铸
		define = "class", name = "MsgItemReforgeRequest", category = "MSG_CATEGORY_ITEM", id = 170, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemid"},
			{type = "int16", name = "reforgetype"},
		},
	},

	{
		-- 饰品重铸
		define = "class", name = "MsgItemReforgeResponse", category = "MSG_CATEGORY_ITEM", id = 171, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "struct", name = "ItemReforgeInfo",
		attributes =
		{
			 {type = "string", name = "name"},
			 {type="int32",	name="itemid"},
		}
	},
	
	{	
		-- 请求饰品重铸全服记录
		define = "class", name = "MsgItemReforgeRecordRequest", category = "MSG_CATEGORY_ITEM", id = 172, base = "Message",
		attributes =
		{
			{type = "int16", name = "count"},
		},
	},

	{
		-- 饰品重铸全服记录
		define = "class", name = "MsgItemReforgeRecordResponse", category = "MSG_CATEGORY_ITEM", id = 173, base = "Message",
		attributes =
		{
			{type = "ItemReforgeInfo", name = "recordlist", vector = true},
		},
	},
	
	{	
		-- 请求使用经验玉
		define = "class", name = "MsgItemUserExpStoreRequest", category = "MSG_CATEGORY_ITEM", id = 174, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "eid", dump = true},
			{type = "int16", name = "cnt", dump = true},
			{type = "int16", name = "option", dump = true},
		},
	},

	{
		-- 回复使用经验玉
		define = "class", name = "MsgItemUserExpStoreResponse", category = "MSG_CATEGORY_ITEM", id = 175, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{	
		-- 改造装备
		define = "class", name = "MsgItemTransformRequest", category = "MSG_CATEGORY_ITEM", id = 177, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},

	{
		-- 改造装备
		define = "class", name = "MsgItemTransformResponse", category = "MSG_CATEGORY_ITEM", id = 178, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{	
		define = "class", name = "MsgPutinSkillRuneToPosRequest", category = "MSG_CATEGORY_ITEM", id = 181, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "skillsid"},
			{type = "int32", name = "runeId"},
		},
	},
	{	
		define = "class", name = "MsgSkillRuneLvlUpResponse", category = "MSG_CATEGORY_ITEM", id = 183, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "iid"},
		},
	},
	{	
		define = "class", name = "MsgSkillRunePutoffRequest", category = "MSG_CATEGORY_ITEM", id = 184, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},
	{	
		define = "class", name = "MsgSkillRunePutoffResponse", category = "MSG_CATEGORY_ITEM", id = 185, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgQuickUseItemListRequest", category = "MSG_CATEGORY_ITEM", id = 186, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemList", vector = true},
		},
	},
	{
		define = "class", name = "MsgQuickUseItemListResponse", category = "MSG_CATEGORY_ITEM", id = 187, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgMoveItemListRequest", category = "MSG_CATEGORY_ITEM", id = 188, base = "Message",
		attributes =
		{
			{type = "int32", name = "operatorType"},
			{type = "int32", name = "itemList", vector = true},
		},
	},
	{
		define = "class", name = "MsgMoveItemListResponse", category = "MSG_CATEGORY_ITEM", id = 189, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name="MsgResetBagItemInfoNotify", category = "MSG_CATEGORY_ITEM" , id = 190 ,base = "Message",
		 attributes =
		 {
			{type = "int32",	name = "pid" , dump = true},
			{type = "int32",	name = "beginPos"},
			{type = "int32",	name = "endPos"},
			{type = "ItemInfo",	name = "item_list",vector = true},
		 },
	},
	
	{
		define = "class", name = "MsgSortBagRequest", category = "MSG_CATEGORY_ITEM", id = 191, base = "Message",
		attributes =
		{
			{type = "int16", name = "bagType"},
		},
	},
	
	{
		define = "class", name = "MsgSortBagResponse", category = "MSG_CATEGORY_ITEM", id = 192, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
		}
	},
	
	{
		define = "class", name = "MsgHCItemRequest", category = "MSG_CATEGORY_ITEM", id = 193, base = "Message",
		attributes =
		{
			{type = "int32", name = "formulaId"},
			{type = "int32", name = "count"},
			{type = "int16", name = "useStore"},
		},
	},
	{
		define = "class", name = "MsgHCItemResponse", category = "MSG_CATEGORY_ITEM", id = 194, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgRecoveryItemListRequest", category = "MSG_CATEGORY_ITEM", id = 195, base = "Message",
		attributes =
		{
			{type = "int32", name = "posBegin"},
			{type = "int32", name = "posEnd"},
			{type = "int32", name = "itemList", vector = true},
			{type = "int16", name = "autoRecovery"},
		},
	},
	{
		define = "class", name = "MsgRecoveryItemListResponse", category = "MSG_CATEGORY_ITEM", id = 196, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int16", name = "autoRecovery"},
			{type = "int32", name = "posBegin"},
			{type = "int32", name = "posEnd"},
			{type = "ItemBase64",   name = "items", vector = true},
		},
	},
	
			    --分身装备进阶
	{
		define = "class", name = "MsgSepEquipUpLevelRequest", category = "MSG_CATEGORY_ITEM", id = 197, base = "Message",
		attributes =
		{
			{type = "int32", name = "sepType"},
		},
		
	},
			--分身装备进阶返回
	{
		define = "class", name = "MsgSepEquipUpLevelResponse", category = "MSG_CATEGORY_ITEM", id = 198, base = "Message",
		attributes =
		{
			{type = "int32", name = "sepType"},
			{type = "int16", name = "errcode"},
		},
		
	},
	{
		define = "class", name = "MsgRechargeEquipUpLevelRequest", category = "MSG_CATEGORY_ITEM", id = 199, base = "Message",
		attributes =
		{
			{type = "int32", name = "position"},
		},
		
	},
	{
		define = "class", name = "MsgRechargeEquipUpLevelResponse", category = "MSG_CATEGORY_ITEM", id = 200, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},
	{
		define = "class", name = "MsgRechargeEquipRecycleRequest", category = "MSG_CATEGORY_ITEM", id = 201, base = "Message",
		attributes =
		{
			{type = "int32", name = "position"},
		},
		
	},
	{
		define = "class", name = "MsgRechargeEquipRecycleResponse", category = "MSG_CATEGORY_ITEM", id = 202, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},

	{
		define = "class", name = "MsgDHItemRequest", category = "MSG_CATEGORY_ITEM", id = 203, base = "Message",
		attributes =
		{
			{type = "int32", name = "formulaId"},
			{type = "int32", name = "count"},
			{type = "int16", name = "useStore"},
		},
	},

	{
		define = "class", name = "MsgItemUpdAppraiserNotify", category = "MSG_CATEGORY_ITEM", id = 206, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
			{type = "string", name = "appraiser"},
		},
	},

	{
		define = "class", name = "MsgItemIdentifySpecialRingRequest", category = "MSG_CATEGORY_ITEM", id = 207, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
		},
	},

	{
		define = "class", name = "MsgItemIdentifySpecialRingResponse", category = "MSG_CATEGORY_ITEM", id = 208, base = "Message",
		attributes =
		{
			{type = "int16" , 	name = "errcode"},
			{type = "int32" , 	name = "newringiid"},
		},
	},

	{
		define = "class", name = "MsgItemUpgradeSpecialRingRequest", category = "MSG_CATEGORY_ITEM", id = 209, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
		},
	},

	{
		define = "class", name = "MsgItemUpgradeSpecialRingResponse", category = "MSG_CATEGORY_ITEM", id = 210, base = "Message",
		attributes =
		{
			{type = "int16" , 	name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgItemAdvandeSpecialRingRequest", category = "MSG_CATEGORY_ITEM", id = 211, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "src_iid"},
			{type = "int32" , 	name = "tgt_iid"},
			{type = "int32" ,   name = "lock"},
		},
	},

	{
		define = "class", name = "MsgItemAdvandeSpecialRingResponse", category = "MSG_CATEGORY_ITEM", id = 212, base = "Message",
		attributes =
		{
			{type = "int16" , 	name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgItemAdvandeSpecialRingConfirmRequest", category = "MSG_CATEGORY_ITEM", id = 213, base = "Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
			{type = "int16" , 	name = "save"},
		},
	},

	{
		define = "class", name = "MsgItemAdvandeSpecialRingConfirmResponse", category = "MSG_CATEGORY_ITEM", id = 214, base = "Message",
		attributes =
		{
			{type = "int16" , 	name = "errcode"},
		},
	},


    {
		define = "struct", name = "gjItem",
		attributes =
		{
			 {type="int32", name="iid"},
			 {type="int32",	name="sid"},
			 {type="int32", name="count"},
		}
	},

	-- 物品锁定/解锁回收
    {
		define="class", name="MsgItemSwitchLockRecoveryRequest", category="MSG_CATEGORY_ITEM" , id=217 ,base="Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
		},
	},
	-- 物品使用  通过sid和数量 
	{
		define="class", name="MsgItemUseWithSidRequest", category="MSG_CATEGORY_ITEM" , id=218 ,base="Message",
		attributes =
		{
			{type = "int32" , 	name = "sid"},
			{type = "int32" , 	name = "count"},
		},
	},
	-- 标记该物品已经在背包中查看过
    {
		define="class", name="MsgItemCheckInBagRequest", category="MSG_CATEGORY_ITEM" , id=219 ,base="Message",
		attributes =
		{
			{type = "int32" , 	name = "iid"},
			{type = "int32" , 	name = "page"},
		},
	},
	-- 分解
    {
		define="class", name="MsgItemDecomposeRequest", category="MSG_CATEGORY_ITEM" , id=220 ,base="Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "count", dump = true},
		},
	},
	-- 火祭
	{
		define = "class", name = "MsgHuoJiItemListRequest", category = "MSG_CATEGORY_ITEM", id = 221, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemList", vector = true},
			{type = "int16", name = "autoHuoJi"},
		},
	},
	{
		define = "class", name = "MsgHuoJiItemListResponse", category = "MSG_CATEGORY_ITEM", id = 222, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int16", name = "autoHuoJi"},
			{type = "ItemBase",   name = "items", vector = true},
		},
	},
	-- 分解奖励
	{
		define = "class", name = "MsgFenJieItemListRequest", category = "MSG_CATEGORY_ITEM", id = 224, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemList", vector = true},
			{type = "int32", name = "itemType"},
		},
	},
	{
		define = "class", name = "MsgFenJieListResponse", category = "MSG_CATEGORY_ITEM", id = 225, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "ItemBase",   name = "items", vector = true},
		},
	},
	-- 熔炼
	{
		define = "class", name = "MsgRongLianItemRequest", category = "MSG_CATEGORY_ITEM", id = 226, base = "Message",
		attributes =
		{
			{type = "int16", name = "itemtype"},
			{type = "int32", name = "itemiid"},
			{type = "string",name = "iidListStr"},
		},
	},
	{
		define = "class", name = "MsgRongLianItemResponse", category = "MSG_CATEGORY_ITEM", id = 227, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "itemiid"},
			{type = "int16", name = "itemtype"},
			{type = "int16", name = "opCode"},
		},
	},
	-- 熔炼拆分
	{
		define = "class", name = "MsgRongLianSplitItemRequest", category = "MSG_CATEGORY_ITEM", id = 228, base = "Message",
		attributes =
		{
			{type = "int16", name = "itemtype"},
			{type = "int32", name = "itemiid"},
		},
	},
	{
		define = "class", name = "MsgRongLianSplitItemResponse", category = "MSG_CATEGORY_ITEM", id = 229, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "ItemBase",name = "itemlist", vector = true},
		},
	},
}

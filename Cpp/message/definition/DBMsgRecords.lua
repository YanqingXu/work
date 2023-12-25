messages = {
	{
		define = "class", name="MsgDBRecordExpOp", category = "MSG_CATEGORY_DB_RECORDS", id = 1, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int64", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int64", name = "old_count"},
			{type = "int64", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordLingFuOp", category = "MSG_CATEGORY_DB_RECORDS", id = 2, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordIngotOp", category = "MSG_CATEGORY_DB_RECORDS", id = 3, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int64", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int64", name = "old_count"},
			{type = "int64", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordBoundLingFuOp", category = "MSG_CATEGORY_DB_RECORDS", id = 4, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordBoundIngotOp", category = "MSG_CATEGORY_DB_RECORDS", id = 5, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int64", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int64", name = "old_count"},
			{type = "int64", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordHonorOp", category = "MSG_CATEGORY_DB_RECORDS", id = 6, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordBsscOp", category = "MSG_CATEGORY_DB_RECORDS", id = 7, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordContributionOp", category = "MSG_CATEGORY_DB_RECORDS", id = 8, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordRebornPointsOp", category = "MSG_CATEGORY_DB_RECORDS", id = 9, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordSamsaraPointsOp", category = "MSG_CATEGORY_DB_RECORDS", id = 10, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordItemOp", category = "MSG_CATEGORY_DB_RECORDS", id = 11, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "string", name = "name" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "mapId"},
			{type = "int32", name = "posX"},
			{type = "int32", name = "posY"},
		},
	},

	{
		define = "class", name = "MsgDBRecordEnhance", category = "MSG_CATEGORY_DB_RECORDS", id = 12, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "iid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "enhancelevel"},
			{type = "int32", name = "enhancepropid"},
			{type = "int32", name = "enhancepropvalue"},
			{type = "int32", name = "opcode"},
		},
	},

	{
		define = "class", name = "MsgDBRecordEvaluate", category = "MSG_CATEGORY_DB_RECORDS", id = 13, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "iid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "datacombo"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int32", name = "evaluatecount"},
			{type = "int32", name = "playerevaluatecount"},
			{type = "int32", name = "opcode"},
		},
	},

	{
		define = "class", name="MsgDBRecordLevelOp", category = "MSG_CATEGORY_DB_RECORDS", id = 21, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "old_level"},
			{type = "int32", name = "new_level"},
		},
	},

	{
		define = "class", name="MsgDBRecordRebornOp", category = "MSG_CATEGORY_DB_RECORDS", id = 22, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "old_reborn"},
			{type = "int32", name = "new_reborn"},
		},
	},

	{
		define = "class", name="MsgDBRecordSamsaraOp", category = "MSG_CATEGORY_DB_RECORDS", id = 23, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "old_samsara"},
			{type = "int32", name = "new_samsara"},
		},
	},

	{
		define = "class", name="MsgDBRecordQuestDesc", category = "MSG_CATEGORY_DB_RECORDS", id = 24, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "questid"},
			{type = "int32", name = "state"},
			{type = "int32", name = "overcnt"},
		},
	},

	{
		define = "class", name="MsgDBRecordTradeOp", category = "MSG_CATEGORY_DB_RECORDS", id = 25, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "string", name = "name"},
			{type = "int32", name = "aid_"},
			{type = "int32", name = "pid_"},
			{type = "string", name = "name_"},
			{type = "int32", name = "sid"},
			{type = "int64", name = "cnt"},
			{type = "int32", name = "opcode"},
		},
	},

	{
		define = "class", name="MsgDBRecordCrossSceneOp", category = "MSG_CATEGORY_DB_RECORDS", id = 26, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "lastmap"},
			{type = "int32", name = "lastx"},
			{type = "int32", name = "lasty"},
			{type = "int32", name = "nowmap"},
			{type = "int32", name = "nowx"},
			{type = "int32", name = "nowy"},
		},
	},

	{
		define = "class", name="MsgDBRecordGuildMoneyOp", category = "MSG_CATEGORY_DB_RECORDS", id = 31, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "gid" },
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name = "MsgDBRecordEnterEventOp", category = "MSG_CATEGORY_DB_RECORDS", id = 41, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "id1"},
			{type = "int32", name = "id2"},
		},
	},

	{
		define = "class", name = "MsgDBRecordLeaveEventOp", category = "MSG_CATEGORY_DB_RECORDS", id = 42, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "id1"},
			{type = "int32", name = "id2"},
		},
	},

	{
		define = "class", name = "MsgDBRecordGCZ", category = "MSG_CATEGORY_DB_RECORDS", id = 43, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "gid"},
			{type = "int32", name = "score"},
			{type = "int32", name = "serverId"},
			{type = "int32", name = "rank"},
			{type = "int32", name = "result"},
			{type = "string", name = "playerName"},
			{type = "string", name = "guildName"},
		},
	},

	{
		define = "class", name = "MsgDBRecordBossKilled", category = "MSG_CATEGORY_DB_RECORDS", id = 44, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "scene"},
			{type = "int32", name = "posx"},
			{type = "int32", name = "posy"},
		},
	},

	{
		define = "class", name = "MsgDBRecordPlayerDead", category = "MSG_CATEGORY_DB_RECORDS", id = 45, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "scene"},
			{type = "int32", name = "posx"},
			{type = "int32", name = "posy"},
		},
	},

	{
		define = "class", name = "MsgDBRecordAccelerator", category = "MSG_CATEGORY_DB_RECORDS", id = 51, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "average"},
			{type = "int32", name = "times"},
		},
	},

	{
		define = "class", name = "MsgDBRecordRecharge", category = "MSG_CATEGORY_DB_RECORDS", id = 52, base = "MessageEx", salt="pid",
		attributes =
		{
			{type = "string", name = "serial"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
			{type = "string", name = "ext"},
		},
	},

	{
		define = "class", name = "MsgDBRecordRechargeState", category = "MSG_CATEGORY_DB_RECORDS", id = 53, base = "MessageEx", salt="pid", send_back=false,
		attributes =
		{
			{type = "string", name = "serial"},
			{type = "int32", name = "pid"},
		},
	},
	
	{
		define = "class", name="MsgDBRecordDBMessageStatistics", category = "MSG_CATEGORY_DB_RECORDS", id = 54, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "msgcate" },
			{type = "int32", name = "msgid" },
			{type = "int32", name = "msgcnt"},
			{type = "int32", name = "msgtime"},
			{type = "int32", name = "msgqueuetime"},
		},
	},

	{
		define = "class", name="MsgDBRecordLogicMessageStatistics", category = "MSG_CATEGORY_DB_RECORDS", id = 55, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "queue_len" },
			{type = "int32", name = "update_time" },
			{type = "int32", name = "message_time"},
			{type = "int32", name = "online_player_num"},
		},
	},

	{
		define = "class", name = "MsgDBRecordMemory", category = "MSG_CATEGORY_DB_RECORDS", id = 56, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "usememory"},
			{type = "int32", name = "maxmemory"},
		},
	},

	{
		define = "class", name = "MsgDBRecordHoliday", category = "MSG_CATEGORY_DB_RECORDS", id = 57, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "type"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name="MsgDBRecordMail", category = "MSG_CATEGORY_DB_RECORDS", id = 58, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="aid"},
			{type="int32", name="pid"},
			{type="string", name="pname"},
			{type="int32", name="mid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		},
	},

	{
		define = "class", name = "MsgDBRecordCrossOp", category = "MSG_CATEGORY_DB_RECORDS", id = 59, base = "MessageEx",
		attributes =
		{
			{type="int32", name="aid"},
			{type="int32", name="pid"},
			{type="string", name="pname"},
			{type="int32", name="opcode"},
		},
	},

	{
		define = "class", name = "MsgDBRecordLoginOp", category = "MSG_CATEGORY_DB_RECORDS", id = 60, base = "MessageEx",
		attributes =
		{
			{type="int32", name="aid"},
			{type="int32", name="pid"},
			{type="string", name="pname"},
			{type="int32", name="line"},
		},
	},

	{
		define = "class", name = "MsgDBRecordLogoutOp", category = "MSG_CATEGORY_DB_RECORDS", id = 61, base = "MessageEx",
		attributes =
		{
			{type="int32", name="aid"},
			{type="int32", name="pid"},
			{type="string", name="pname"},
		},
	},

	{
		define = "class", name = "MsgDBRecordGuildOp", category = "MSG_CATEGORY_DB_RECORDS", id = 62, base = "MessageEx",
		attributes =
		{
			{type="int32", name="gid"},
			{type="string", name="gname"},
			{type="int32", name="pid1"},
			{type="string", name="pname1"},
			{type="int32", name="pid2"},
			{type="string", name="pname2"},
			{type="int32", name="opcode"},
			{type="int32", name="opdata"},
		},
	},
	
	{
		define = "class", name="MsgDBRecordPlayerSROp", category = "MSG_CATEGORY_DB_RECORDS", id = 66, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name="MsgDBRecordPlayerSkillOp", category = "MSG_CATEGORY_DB_RECORDS", id = 67, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "skillid"},
		},
	},
	
	{
		define = "class", name = "MsgDBRecordBaoWuOp", category = "MSG_CATEGORY_DB_RECORDS", id = 69, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "oldlevel" },
			{type = "int32", name = "newlevel" },
			{type = "int32", name = "cost"},
		},
	},
	
	{
		define = "class", name = "MsgDBRecordStrenghthenOp", category = "MSG_CATEGORY_DB_RECORDS", id = 70, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "pre_level" },
			{type = "int32", name = "new_level" },
			{type = "int32", name = "pos"},
			{type = "int32", name = "material_id"},
			{type = "int32", name = "count"},
			{type = "int32", name = "material_id2"},
			{type = "int32", name = "count2"},
			{type = "int32", name = "isauto"},

		},
	},
	
	{
		define = "class", name = "MsgDBRecordStoneUpdateOp", category = "MSG_CATEGORY_DB_RECORDS", id = 71, base = "MessageEx",--魂石
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "pre_level" },
			{type = "int32", name = "new_level" },
			{type = "int32", name = "pos"},
			{type = "int32", name = "stone"},
			{type = "int32", name = "cnt"},

		},
	},
	
	{
		define = "class", name = "MsgDBRecordChuanshiOp", category = "MSG_CATEGORY_DB_RECORDS", id = 72, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "pre_level" },
			{type = "int32", name = "new_level" },
			{type = "int32", name = "pos"},
			{type = "int32", name = "material1"},
			{type = "int32", name = "count1"},
			{type = "int32", name = "material2"},
			{type = "int32", name = "count2"},
			
		},
	},
	
	{
		define = "class", name = "MsgDBRecordWeiMingOp", category = "MSG_CATEGORY_DB_RECORDS", id = 74, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode" },
			{type = "int32", name = "counts"},
		},
	},

    {
		define = "class", name = "MsgDBRecordTowerOp", category = "MSG_CATEGORY_DB_RECORDS", id = 75, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
            {type = "int32", name = "enterLayer"},
            {type = "int32", name = "exitLayer"},
			{type = "string", name = "rewards" },
		},
	},
	
	{
		define = "class", name = "MsgDBRecordMindPracRec", category = "MSG_CATEGORY_DB_RECORDS", id = 81, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode" },
			{type = "int32", name = "curvalue" },
			{type = "int32", name = "nextvalue" },
			{type = "int32", name = "res"},
			{type = "int32", name = "intvalue"},
		},
	},

	{
		define = "class", name = "MsgDBRecordPlayerWingOp", category = "MSG_CATEGORY_DB_RECORDS", id = 84, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "oldlevel" },
			{type = "int32", name = "newlevel" },
			{type = "int32", name = "cost"},
		},
	},

	{
		define = "class", name = "MsgDBRecordRename", category = "MSG_CATEGORY_DB_RECORDS", id = 85, base = "MessageEx",
		attributes =
		{
			{type="int32", name="pid"},
			{type="string", name="oldname"},
			{type="string", name="newname"},
			{type="int32", name="time"},
		},
	},

	{
		define = "class", name = "MsgDBRecordFulingOp", category = "MSG_CATEGORY_DB_RECORDS", id = 86, base = "MessageEx",--附灵日志
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "iid"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "pre_level" },
			{type = "int32", name = "pre_exp" },
			{type = "int32", name = "new_level" },
			{type = "int32", name = "new_exp"},

		},
	},

	{
		define = "class", name="MsgDBRecordGuildCoin", category = "MSG_CATEGORY_DB_RECORDS", id = 87, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

	{
		define = "class", name="MsgDBRecordPlayerPropOp", category = "MSG_CATEGORY_DB_RECORDS", id = 88, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "prop_id"},
			{type = "int32", name = "old_data" },
			{type = "int32", name = "new_data" },
			{type = "int32", name = "add_data"},
			{type = "int32", name = "opcode"},
		},
	},
	
	{
		define = "class", name="MsgDBRecordShenhunOp", category = "MSG_CATEGORY_DB_RECORDS", id = 89, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "string", name = "optype"},
			{type = "int32", name = "consumeexp"},
			{type = "int32", name = "consumecoin"},
			{type = "int32", name = "consumebindcoin"},
			{type = "int32", name = "shenhun"},
			{type = "int32", name = "equiptype"},
			{type = "string", name = "oldlevelinfo"},
			{type = "string", name = "newlevelinfo"},
			{type = "int32", name = "gradeup"},
		},
	},

	{
		define = "class", name="MsgDBRecordRankScore", category = "MSG_CATEGORY_DB_RECORDS", id = 90, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
            {type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},

		{
		define = "class", name="MsgDBRecordQuanMinGuess", category = "MSG_CATEGORY_DB_RECORDS", id = 91, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid" },
			{type = "int32", name = "datax"},
			{type = "int32", name = "result"},
			{type = "int32", name = "sum"},
			{type = "int32", name = "value"},
		},
	},
	
	{
		define = "class", name = "MsgDBSmeltOp", category = "MSG_CATEGORY_DB_RECORDS", id = 94, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "opcode"},
			{type = "string", name = "name"},
			{type = "string", name = "strprop"},
			{type = "int32", name = "pos" },
			{type = "int32", name = "locks" },
			{type = "int32", name = "stone_sid"},
			{type = "int32", name = "stone_num"},
			{type = "int32", name = "ingot"},

		},
	},
	{
		define = "class", name = "MsgDBRecordTherion", category = "MSG_CATEGORY_DB_RECORDS", id = 96, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "oldlevel" },
			{type = "int32", name = "newlevel" },
			{type = "int32", name = "cost1"},
			{type = "int32", name = "cost2"},
		},
	},
	{
		define="class", name="MsgDBAddConsignmentRecording", category="MSG_CATEGORY_DB_RECORDS", id=97, base="MessageEx",
		attributes=
		{
			{type="int32", name="pid", desc="卖家ID"},
			{type="string", name="sellername", desc="卖家姓名"},
			{type="int32", name="buyerpid", desc="买家ID"},
			{type="string", name="buyername", desc="买家姓名"},
			{type="int32", name="sid", desc="物品ID"},
			{type="int32", name="count", desc="物品数量"},
			{type="int32", name="price", desc="出售价格"},
			{type="int32", name="pricetype", desc="货币类型"},
			{type="int32", name="ctype", desc="交易类型"},
			{type="int32", name="btime", desc="交易时间"},
		},
	},
	{
		define = "class", name = "MsgDBRecordShenLongHuTiOp", category = "MSG_CATEGORY_DB_RECORDS", id = 98, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int32", name = "opcode"},
			{type = "int32", name = "oldlevel" },
			{type = "int32", name = "newlevel" },
			{type = "int32", name = "cost1"},
			{type = "int32", name = "cost2"},
		},
	},
	{
		define = "class", name = "MsgDBRecordHolidayUpdateResponse", category = "MSG_CATEGORY_DB_RECORDS", id = 99, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "switch_id"},
			{type = "int32", name = "type"},
			{type = "int8", name = "reset"},
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name="MsgDBRecordIngotSpecialOp", category = "MSG_CATEGORY_DB_RECORDS", id = 100, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "opcode"},
			{type = "int32", name = "cnt"},
			{type = "int32", name = "type"},
			{type = "int32", name = "data"},
			{type = "int32", name = "old_count"},
			{type = "int32", name = "new_count"},
		},
	},
	{
		define = "class", name="MsgDBRecordIncreaseEnhanceOp", category = "MSG_CATEGORY_DB_RECORDS", id = 101, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "sid" },
			{type = "int32", name = "source_sid" },
			{type = "int32", name = "old_level"},
			{type = "int32", name = "new_level"},
			{type = "int32", name = "opcode"},
		},
	},
	{
		define = "class", name="MsgDBRecordEquipEnhanceOp", category = "MSG_CATEGORY_DB_RECORDS", id = 102, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "aid" },
			{type = "int32", name = "pid" },
			{type = "int32", name = "old_level"},
			{type = "int32", name = "new_level"},
			{type = "int32", name = "pos"},
		},
	},

}

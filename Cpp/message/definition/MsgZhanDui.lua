messages =
{

	-- -------------------------------------------------------------------------
	-- 战队
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "ZhanDuiInfo",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "string", name ="zhandui_name"},
			{type = "int32", name = "master_id"},
			{type = "string", name = "master_name"},
			{type = "int8", name = "master_online"},
			{type = "int16", name = "member_count"},
			{type = "int32", name = "auto_join_reborn"},
			{type = "int32", name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiListRequest", category = "MSG_CATEGORY_ZHANDUI", id = 1, base = "Message",
		attributes =
		{
			{type = "int16", name ="version"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiListResponse", category = "MSG_CATEGORY_ZHANDUI", id = 2, base = "Message",
		attributes =
		{
			{type = "int32", name = "version"},
			{type = "int16", name = "maxpage"},
			{type = "int16", name = "page"},
			{type = "ZhanDuiInfo", name = "zhanduis",vector = true},
		}
	},

	--{
	--	define = "class", name = "MsgZhanDuiListVersionNotify", category = "MSG_CATEGORY_ZHANDUI", id = 3, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "version"},
	--		{type = "int32", name = "maxpage"},
	--	}
	--},

	{
		define = "class", name = "MsgZhanDuiCreateRequest", category = "MSG_CATEGORY_ZHANDUI", id = 4, base = "Message",
		attributes =
		{
			{type = "string", name = "zhandui_name"},
			{type = "int16", name = "auto_join_reborn"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiCreateResponse", category = "MSG_CATEGORY_ZHANDUI", id = 5, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiSetAutoJoinRebornRequest", category = "MSG_CATEGORY_ZHANDUI", id = 7, base = "Message",
		attributes =
		{
			{type = "int16", name = "auto_join_reborn"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiSetAutoJoinRebornResponse", category = "MSG_CATEGORY_ZHANDUI", id = 8, base = "Message",
		attributes =
		{
			{type = "int16", name = "auto_join_reborn"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
	
	{
		define = "class", name = "MsgZhanDuiSetMasterRequest", category = "MSG_CATEGORY_ZHANDUI", id = 9, base = "Message",
		attributes =
		{
			{type = "int32", name = "new_master_pid"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiSetMasterResponse", category = " MSG_CATEGORY_ZHANDUI", id = 10 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "new_master_pid"},
			{type = "int16", name = "errcode"},
			{type = "int32", name = "old_master_pid"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiUpdateNotify", category = "MSG_CATEGORY_ZHANDUI", id = 11, base = "Message",
		attributes =
		{
			{type = "ZhanDuiInfo", name = "zhandui"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiDeleteNotify", category = "MSG_CATEGORY_ZHANDUI", id = 12, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
		}
	},

	-- -------------------------------------------------------------------------
	-- 战队队员
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "ZhanDuiMemberInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string",name = "name"},
			{type = "int32", name = "job"},
            {type = "int16", name = "gender"},
			{type = "int16", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int16", name = "post"},
			{type = "int8", name = "online"},
			{type = "int32", name = "sceneid"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiMemberListNotify", category = "MSG_CATEGORY_ZHANDUI", id = 21, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "ZhanDuiMemberInfo", name = "members", vector = true},
		},
	},

	{
		define = "class", name = "MsgZhanDuiMemberDeleteRequest", category = "MSG_CATEGORY_ZHANDUI", id = 22, base ="Message",
		attributes =
		{
			{type = "int32", name ="pid"},
		}
	},
	
	{
		define = "class", name = "MsgZhanDuiMemberDeleteResponse", category = "MSG_CATEGORY_ZHANDUI", id = 23, base ="Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name ="errcode"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiMemberQuitRequest", category = "MSG_CATEGORY_ZHANDUI", id = 24, base ="Message",
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgZhanDuiMemberQuitResponse", category = "MSG_CATEGORY_ZHANDUI", id = 25, base ="Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiMemberUpdateNotify", category = "MSG_CATEGORY_ZHANDUI", id = 26, base ="Message",
		attributes =
		{
			{type = "ZhanDuiMemberInfo", name = "member"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiMemberDeleteNotify", category = "MSG_CATEGORY_ZHANDUI", id = 27, base ="Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		}
	},
	
	{
		define = "class", name = "MsgZhanDuiMemberOnlineNotify", category = "MSG_CATEGORY_ZHANDUI", id = 28, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int8", name = "online"},
			{type = "int32", name = "sceneid"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 入队申请
	-- -------------------------------------------------------------------------
	
	{
		define = "struct", name ="ZhanDuiAppInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int16", name ="job"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "apptime"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiApplicationListNotify", category = "MSG_CATEGORY_ZHANDUI", id = 41 , base = "Message",
		attributes =
		{
			{type = "ZhanDuiAppInfo", name = "apps", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgZhanDuiApplicationAddNotify", category = "MSG_CATEGORY_ZHANDUI", id = 42, base ="Message",
		attributes =
		{
			{type = "ZhanDuiAppInfo", name = "app"},
		}
	},
	
	{
		define = "class", name = "MsgZhanDuiApplicationDeleteNotify", category = "MSG_CATEGORY_ZHANDUI", id = 43, base ="Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		}
	},

	{
		define = "class", name = "MsgZhanDuiJoinRequest", category = "MSG_CATEGORY_ZHANDUI", id = 44, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiJoinResponse", category = "MSG_CATEGORY_ZHANDUI", id = 45, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiCancelRequest", category = "MSG_CATEGORY_ZHANDUI", id = 46, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiCancelResponse", category = "MSG_CATEGORY_ZHANDUI", id = 47, base = "Message",
		attributes =
		{
			{type = "int32", name = "zhandui_id"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class" , name = "MsgZhanDuiDecideRequest", category = "MSG_CATEGORY_ZHANDUI", id = 48, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "decide"},
		}
	},

	{
		define = "class" , name = "MsgZhanDuiDecideResponse", category = "MSG_CATEGORY_ZHANDUI", id = 49, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "decide"},
			{type = "int16", name = "errcode"},
		}
	},

	--{
	--	define = "class", name = "MsgZhanDuiMemberInfoByPidRequest", category = "MSG_CATEGORY_ZHANDUI", id = 15, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "pid"},
	--	}
	--},

	--{
	--	define = "class", name = "MsgMyZhanDuiInfoNotify", category = "MSG_CATEGORY_GUILD", id = 50, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "zhandui_id"},
	--		{type = "string", name ="zhandui_name"},
	--		{type = "int32", name = "intime"},
	--		{type = "int16", name = "level"},
	--		{type = "string", name ="master_name"},
	--		{type = "int16", name = "member_count"},
	--	}
	--},

	-- -------------------------------------------------------------------------
	-- 战队属性
	-- -------------------------------------------------------------------------
	{
		define = "class", name = "MsgZhanDuiExDataNotify", category = "MSG_CATEGORY_ZHANDUI", id = 61, base= "Message",
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgZhanDuiExDataStringNotify", category = "MSG_CATEGORY_ZHANDUI", id = 62, base= "Message",
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "string", name = "data"},
		},
	},

	-- -------------------------------------------------------------------------
	-- 战队记录
	-- -------------------------------------------------------------------------

	{
		define = "struct", name = "ZhanDuiRecord",
		attributes =
		{
			{type = "int32", name = "id" },
			{type = "int16", name = "type" },
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "int32", name = "dataz" },
			{type = "string", name = "name1" },
			{type = "string", name = "name2" },
			{type = "int32", name = "ctime" },
		},
	},

	{
		define = "class", name = "MsgZhanDuiRecordListNotify", category = "MSG_CATEGORY_ZHANDUI", id = 71, base = "Message", -- 进入游戏后发送
		attributes =
		{
			{type = "ZhanDuiRecord", name = "records", vector = true},
		},
	},

	{
		define = "class", name = "MsgZhanDuiRecordAddNotify", category = "MSG_CATEGORY_ZHANDUI", id = 72, base = "Message", -- 有新的记录更新
		attributes =
		{
			{type = "ZhanDuiRecord", name = "record"},
		},
	},

}

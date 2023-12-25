messages =
{
	{
		define = "struct", name = "GuildMemberInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string",name = "name"},
			{type = "int16", name = "level"},
			{type = "int16", name = "post"},
			{type = "int32", name = "contribution"},
			{type = "int32", name = "todaycontribution"},
			{type = "int8", name = "online"},
			{type = "int32", name = "rank"},
			{type = "int32", name = "vitality"},
            {type = "int16", name = "gender"},
			{type = "int16", name = "speek"},
			{type = "int32", name = "force"},
			{type = "int32", name = "offtime"},
			{type = "int32", name = "sceneid"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "sponsorGrade"},
			{type = "int32", name = "job"},
		},
	},

	{
		define = "class", name = "MsgCreateGuildRequest", category = "MSG_CATEGORY_GUILD", id =1 , base = "Message",
		attributes =
		{
			{type = "string", name = "GuildName"},
			{type = "string", name = "placard"},
			{type = "int16", name = "level", desc = "最低等级"},
		},
	},

	{
		define = "class", name = "MsgCreateGuildResponse", category = "MSG_CATEGORY_GUILD", id =2 , base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgApplicationToGuildRequest", category = "MSG_CATEGORY_GUILD", id = 3 , base = "Message",
		attributes =
		{
			{type = "int32", name = "GuildID"},
		},
	},

	{
		define = "class" , name = "MsgApplicationResultRequest", category = "MSG_CATEGORY_GUILD", id = 4, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "Decide"},
		}
	},

	{
		define = "class", name = "MsgApplicationToGuildResponse", category = "MSG_CATEGORY_GUILD", id = 5 , base = "Message",
		attributes =
		{
			{type = "int32", name = "GuildID"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgDeleteGuildMemberRequest", category = "MSG_CATEGORY_GUILD", id = 6, base ="Message",
		attributes =
		{
			{type = "int32", name ="pid"},
		}
	},

	{
		define = "struct", name = "GuildInfo",
		attributes =
		{
			{type = "int32", name = "rank"},
			{type = "int32", name = "GuildID"},
			{type = "string", name ="GuildName"},
			{type = "int32", name = "MasterID"},
			{type = "string", name = "MasterName"},
			{type = "int8", name = "MasterOnline"},
			{type = "int16", name = "MemberCount"},
			{type = "int16", name = "state"},
			{type = "int32", name = "level"},
			{type = "int32", name = "ctime"},
			{type = "int64", name = "combat"},
			{type = "string", name = "notice"},
			{type = "int32", name = "declareguildid"},
			{type = "int32", name = "declareovertime"},
		},
	},

	{
		define = "class", name = "MsgGetGuildsInfoRequest", category = "MSG_CATEGORY_GUILD", id = 7, base = "Message",
		attributes =
		{
			{type = "int16", name ="page"},
		}
	},

	{
		define = "class", name = "MsgGuildsInfoResponse", category = "MSG_CATEGORY_GUILD", id = 8, base = "Message",
		attributes =
		{
			{type = "int16", name = "page"},
			{type = "int16", name = "maxpage"},
			{type = "GuildInfo", name = "Guilds",vector = true},
			{type = "int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgGuildMemberChangeNotify", category = "MSG_CATEGORY_GUILD", id = 9, base ="Message",
		attributes =
		{
			{type = "GuildMemberInfo", name = "player"},
			{type = "int8", name = "reason"},
		}
	},

	{
		define = "class" , name = "MsgApplicationResultResponse", category = "MSG_CATEGORY_GUILD", id = 10, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgLeaveGuildRequest", category = "MSG_CATEGORY_GUILD", id = 11, base ="Message",
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgLeaveGuildResponse", category = "MSG_CATEGORY_GUILD", id = 12, base ="Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgCancelApplicationToGuildRequest", category = "MSG_CATEGORY_GUILD", id = 13 , base = "Message",
		attributes =
		{
			{type = "int32", name = "GuildID"},
		},
	},

	{
		define = "class", name = "MsgDeleteGuildMemberResponse", category = "MSG_CATEGORY_GUILD", id = 14, base ="Message",
		attributes =
		{
			{type = "int16", name ="errcode"},
			{type = "int32", name = "pid"},

		}
	},

	{
		define = "class", name = "MsgGuildMemberInfoByPidRequest", category = "MSG_CATEGORY_GUILD", id = 15, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		}
	},

	-- {
		-- define = "class", name = "MsgGuildMemberInfoByPidResponse", category = "MSG_CATEGORY_GUILD", id = 16, base = "Message",
		-- attributes =
		-- {
			-- {type = "GuildMemberInfo", name = "myGuildInfo"},
			-- {type = "int16", name = "errcode"},
		-- }
	-- },

	{
		define = "class", name = "MsgGuildPublicNoticeNotify", category ="MSG_CATEGORY_GUILD", id = 17, base = "Message",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "string", name ="publicnotice"},
		},
	},

	{
		define = "struct", name ="GuildApplicationInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "lvl"},
			{type = "int16", name = "gender"},
			{type = "int16", name ="job"},
			{type = "int32", name = "force"},
			{type = "string", name = "name"},
			{type = "int32", name = "apptime"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberInfoRequest", category = "MSG_CATEGORY_GUILD", id = 18, base = "Message",
		attributes =
		{
			{type = "int16", name ="page"},
			{type = "int16", name ="job"},
		}
	},

	-- {
		-- define = "class", name = "MsgGuildMemberInfoResponse", category = "MSG_CATEGORY_GUILD", id = 19, base = "Message",
		-- attributes =
		-- {
			-- {type = "int16", name = "page"},
			-- {type = "int16", name = "maxpage"},
			-- {type = "GuildMemberInfo", name = "GuildMember",vector = true},
			-- {type = "int16", name = "errcode"},
		-- }
	-- },

	{
		define = "class", name = "MsgGuildMemberInfoNotify", category = "MSG_CATEGORY_GUILD", id = 20, base = "Message",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "GuildMemberInfo", name = "members", vector =true},
		},
	},

	{
		define = "class", name = "MsgGuildApplicationInfoNotify", category = "MSG_CATEGORY_GUILD", id = 21 , base = "Message",
		attributes =
		{
			{type = "GuildApplicationInfo", name = "apps",vector = true},
		},
	},

	{
		define = "class", name = "MsgRefreshMyGuildInfoNotify", category = "MSG_CATEGORY_GUILD" , id = 22, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGuildPlacardNotify", category ="MSG_CATEGORY_GUILD", id = 23, base = "Message",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "string", name ="placard"},
		},
	},

	{
		define = "class", name = "MsgGetGuildDetailRequest", category = "MSG_CATEGORY_GUILD", id = 24, base ="Message",
		attributes =
		{
			{type = "int32", name = "guildid"},
		},
	},

	{
		define = "class", name = "MsgMyGuildInfoNotify", category = "MSG_CATEGORY_GUILD", id = 25, base = "Message",
		attributes =
		{
			{type = "int32", name = "GuildID"},
			{type = "string", name ="GuildName"},
			{type = "int32", name = "inTime"},
			{type = "int16", name = "level"},
			{type = "string", name ="MasterName"},
			{type = "int16", name = "MemberCount"},
			{type = "int32", name = "myGuildmoney"},
			{type = "int16", name = "myGuildFCDCLevel"},
			{type = "int16", name = "myGuildSNLBLevel"},
			{type = "int16", name = "myGuildJRBBLevel"},
			{type = "int16", name = "myGuildGRJTLevel"},
			{type = "int16", name = "myGuildLTWJLevel"},
			{type = "int16", name = "myGuildKBYZLevel"},
			{type = "int16", name = "myGuildYNQLLevel"},
			{type = "int16", name = "myGuildQZYBLevel"},
			{type = "int16", name = "myGuildRJDJLevel"},
			{type = "int16", name = "myGuildFKDGLevel"},
			{type = "int16", name = "myGuildCBTXLevel"},
			{type = "int16", name = "myGuildJSCDLevel"},
			{type = "int32", name = "DonTodaymoney"},
			{type = "int16", name = "DonTodaytime"},
		}
	},

	{
		define = "class", name = "MsgGuildApplicationChangeNotify", category = "MSG_CATEGORY_GUILD", id = 26, base ="Message",
		attributes =
		{
			{type = "GuildApplicationInfo", name = "app"},
			{type = "int8", name = "reason"},
		}
	},

	{
		define = "class", name = "MsgCancelApplicationToGuildResponse", category = "MSG_CATEGORY_GUILD", id = 27 , base = "Message",
		attributes =
		{
			{type = "int32", name = "GuildID"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildRewardRequest", category = "MSG_CATEGORY_GUILD", id = 28, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},

	{
		define = "class", name = "MsgGuildRewardResponse", category = "MSG_CATEGORY_GUILD", id = 29, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildDonateRequest", category = "MSG_CATEGORY_GUILD", id = 30, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class", name = "MsgGuildDonateResponse", category = "MSG_CATEGORY_GUILD", id = 31, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildMoneyUpdateNotify", category = "MSG_CATEGORY_GUILD", id = 32, base = "Message",
		attributes =
		{
			{type = "int32", name = "gold"},
		},
	},

	{
		define = "class", name = "MsgGuildPlacardChangeRequest", category = "MSG_CATEGORY_GUILD", id = 35, base = "Message",
		attributes =
		{
			{type = "string", name = "placard"},
		},
	},

	{
		define = "class", name = "MsgGuildPlacardChangeResponse", category = "MSG_CATEGORY_GUILD", id = 36, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildPublicNoticeChangeRequest", category = "MSG_CATEGORY_GUILD", id = 37, base = "Message",
		attributes =
		{
			{type = "string", name = "publicnotice"},
		},
	},

	{
		define = "class", name = "MsgGuildPublicNoticeChangeResponse", category = "MSG_CATEGORY_GUILD", id = 38, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberOnlineNotify", category = "MSG_CATEGORY_GUILD", id = 39, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int8", name = "online"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberSceneNotify", category = "MSG_CATEGORY_GUILD", id = 40, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sceneid"},
		},
	},
	
	{
		define = "class", name = "MsgCreateGuildNotify", category = "MSG_CATEGORY_GUILD", id = 41, base = "Message",
		attributes =
		{
			{type = "GuildInfo", name = "guild"},
		}
	},
	{
		define = "class", name = "MsgAutoAddGuildAppRequest", category = "MSG_CATEGORY_GUILD", id = 42, base = "Message",
		attributes =
		{

		},
	},
	{
		define = "class", name = "MsgGuildStudySkillRequest", category = "MSG_CATEGORY_GUILD", id = 43, base = "Message",
		attributes =
		{
			{type = "int16", name = "skillIndex"},
		},
	},
	{
		define = "class", name = "MsgGuildStudySkillResponse", category = "MSG_CATEGORY_GUILD", id = 44, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgGuildResetSkillRequest", category = "MSG_CATEGORY_GUILD", id = 45, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},
	{
		define = "class", name = "MsgGuildResetSkillResponse", category = "MSG_CATEGORY_GUILD", id = 46, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildMasterResetRequest", category = "MSG_CATEGORY_GUILD", id = 50, base = "Message",
		attributes =
		{
			{type = "int32", name = "ResetPid"},
		},
	},

	{
		define = "class", name = "MsgGuildMasterResetResponse", category = " MSG_CATEGORY_GUILD", id = 51 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "oldpid"},
			{type = "int32", name = "newpid"},
		},
	},

	{
		define = "struct", name = "GuildRecord",
		attributes =
		{
			{type = "int16", name = "type" },
			{type = "int32", name = "recordtime" },
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "string", name = "namex" },
			{type = "string", name = "namey" },
		},
	},

	{
		define = "class", name = "MsgGuildRecordsNotify", category = "MSG_CATEGORY_GUILD",id = 52,base = "Message", -- 进入游戏后发送
		attributes =
		{
			{type = "GuildRecord", name = "records", vector = true},
		},
	},

	{
		define = "class", name = "MsgGuildRecordAddNotify", category = "MSG_CATEGORY_GUILD", id = 53, base = "Message", -- 有新的记录更新
		attributes =
		{
			{type = "GuildRecord", name = "record"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRefuseAllApplicationRequest", category = "MSG_CATEGORY_GUILD", id = 54, base = "Message", -- 拒绝所有加入行会申请请求
		attributes =
		{
			
		},
	},
	
	{
		define = "class", name = "MsgGuildRefuseAllApplicationResponse", category = "MSG_CATEGORY_GUILD", id = 55, base = "Message", -- 拒绝所有加入行会申请回执
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgGuildPassAllApplicationRequest", category = "MSG_CATEGORY_GUILD", id = 56, base = "Message", -- 通过所有加入行会申请请求
		attributes =
		{
			
		},
	},
	
	{
		define = "class", name = "MsgGuildPassAllApplicationResponse", category = "MSG_CATEGORY_GUILD", id = 57, base = "Message", -- 通过所有加入行会申请回执
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	-----nickname-------------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildNicknameLoadNotify", category = " MSG_CATEGORY_GUILD", id = 61 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "job"},
			{type = "string", name = "nickname"},
		},
	},

	--{
	--	define = "class", name = "MsgGuildNicknameUpdateRequest", category = "MSG_CATEGORY_GUILD", id = 62, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "job"},
	--		{type = "string", name = "nickname"},
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgGuildNicknameUpdateResponse", category = " MSG_CATEGORY_GUILD", id = 63 ,base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	{
		define = "class", name = "MsgGuildMemberNicknameChangeRequest", category = "MSG_CATEGORY_GUILD", id = 64, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "post"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberNicknameChangeResponse", category = "MSG_CATEGORY_GUILD", id = 65, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberSpeekChangeRequest", category = "MSG_CATEGORY_GUILD", id = 66, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "speek"},
		},
	},

	{
		define = "class", name = "MsgGuildMemberSpeekChangeResponse", category = "MSG_CATEGORY_GUILD", id = 67, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "pid"},
		},
	},
	--{
	--	define = "class", name = "MsgGuildAllNicknameNotify", category = " MSG_CATEGORY_GUILD", id = 66 ,base = "Message",
	--	attributes =
	--	{
	--		{type = "string", name = "nickname",vector = true},
	--	},
	--},

	{
		define = "class", name = "MsgGuildInviteRequest", category = "MSG_CATEGORY_GUILD", id = 70, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgGuildInviteResponse", category = "MSG_CATEGORY_GUILD", id = 71, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "leaveCD"},
		},
	},

	{
		define = "class", name = "MsgGuildInviteNotify", category = "MSG_CATEGORY_GUILD", id = 72, base = "Message",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "guildname"},
			{type = "string", name = "name"},
		},
	},

	{
		define = "class", name = "MsgGuildInviteResultRequest", category = "MSG_CATEGORY_GUILD", id = 73, base = "Message",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "string", name = "name"},
			{type = "int16", name = "decide"},
		},
	},

	{
		define = "class", name = "MsgGuildInviteResultResponse", category = "MSG_CATEGORY_GUILD", id = 74, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildInviteResultNotify", category = "MSG_CATEGORY_GUILD", id = 75, base = "Message",
		attributes =
		{
			{type = "int16", name = "decide"},
			{type = "string", name = "name"},
		},
	},

	{
		define = "struct", name = "GuildRed",
		attributes =
		{			
			{type = "int32", name = "id"},
			{type = "int16", name = "redtype"},
			{type = "int32", name = "guildid"},
			{type = "int32", name = "maxgold"},
			{type = "int32", name = "createtime"},
			{type = "int32", name = "maxcount"},
			{type = "int32", name = "curcount"},	
			{type = "int32", name = "curgold"},	
			{type = "int32", name = "pid"},	
            {type = "int32", name = "job"},
            {type = "int32", name = "gender"},		
			{type = "string", name = "name"},	
            {type = "string", name = "desc"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedCountResponse", category = "MSG_CATEGORY_GUILD", id = 80, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "count"},		
			{type = "int16", name = "id"},				
			{type = "int32", name = "createtime"},
		},
	},

	{
		define = "class", name = "MsgGuildRedCountRequest", category = "MSG_CATEGORY_GUILD", id = 81, base = "Message",
		attributes =
		{
            {type = "int16", name = "id"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedsNotify", category = "MSG_CATEGORY_GUILD",id = 82,base = "Message", -- 进入游戏后发送
		attributes =
		{
			{type = "GuildRed", name = "reds", vector = true},
		},
	},

	{
		define = "class", name = "MsgGuildRedAddNotify", category = "MSG_CATEGORY_GUILD", id = 83, base = "Message", -- 有新的记录更新
		attributes =
		{
			{type = "GuildRed", name = "red"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedUpdateNotify", category = "MSG_CATEGORY_GUILD", id = 84, base = "Message", -- 有新的记录更新
		attributes =
		{
			{type = "GuildRed", name = "red"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedSendRequest", category = "MSG_CATEGORY_GUILD", id = 85, base = "Message",
		attributes =
		{
			{type = "int16", name = "redtype"},
			{type = "int32", name = "maxgold"},
			{type = "int32", name = "maxcount"},
            {type = "string", name = "desc"},
		},
	},

	{
		define = "class", name = "MsgGuildRedSendResponse", category = "MSG_CATEGORY_GUILD", id = 86, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedGetRequest", category = "MSG_CATEGORY_GUILD", id = 87, base = "Message",
		attributes =
		{
			{type = "int16", name = "redid"},
		},
	},

	{
		define = "class", name = "MsgGuildRedGetResponse", category = "MSG_CATEGORY_GUILD", id = 88, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
            {type = "int32", name = "redid"},
		},
	},
	
	{
		define = "struct", name = "GuildRedRecord",
		attributes =
		{			
			{type = "int32", name = "id"},
		    {type = "int32", name = "redid"},
			{type = "int16", name = "redtype"},
			{type = "int32", name = "guildid"},
			{type = "int32", name = "spid"},
			{type = "string", name = "sname"},			
			{type = "int32", name = "gold"},		
			{type = "int32", name = "dpid"},
            {type = "int32", name = "djob"},
            {type = "int32", name = "dgender"},
			{type = "string", name = "dname"},
			{type = "int32", name = "type"},	
		},
	},

	{
		define = "class", name = "MsgGuildRedRecordsNotify", category = "MSG_CATEGORY_GUILD",id = 89, base = "Message", -- 进入游戏后发送
		attributes =
		{
			{type = "GuildRedRecord", name = "GuildRedRecords", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgGuildRedRecordsAddNotify", category = "MSG_CATEGORY_GUILD",id = 90, base = "Message", -- 进入游戏后发送
		attributes =
		{
			{type = "GuildRedRecord", name = "record"},
		},
	},   
	
	{
		define = "class", name = "MsgGuildContributionRequest", category = "MSG_CATEGORY_GUILD", id = 91, base = "Message",
		attributes =
		{
			{type = "int32", name = "money"},
			{type = "int8", name = "blIngot"},
		},
	},

	{
		define = "class", name = "MsgGuildContributionResponse", category = "MSG_CATEGORY_GUILD", id = 92, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgPutGuildBagRequest", category = "MSG_CATEGORY_GUILD", id = 93, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},

	{
		define = "class", name = "MsgPutGuildBagResponse", category = "MSG_CATEGORY_GUILD", id = 94, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgGetGuildBagRequest", category = "MSG_CATEGORY_GUILD", id = 95, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},

	{
		define = "class", name = "MsgGetGuildBagResponse", category = "MSG_CATEGORY_GUILD", id = 96, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgDelGuildBagRequest", category = "MSG_CATEGORY_GUILD", id = 97, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
		},
	},

	{
		define = "class", name = "MsgDelGuildBagResponse", category = "MSG_CATEGORY_GUILD", id = 98, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	-------------GuildExData ---------------------------------------------------------------
	{
		define = "class", name = "MsgSyncGuildExDataNotify", category = "MSG_CATEGORY_GUILD", id = 110, base= "Message",
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgSyncGuildExStringDataNotify", category = "MSG_CATEGORY_GUILD", id = 111, base= "Message",
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "string", name = "data"},
		},
	},

	{
		define = "class", name = "MsgGuildLeaveNotify" , category = "MSG_CATEGORY_GUILD", id = 120, base = "Message",
		attributes =
		{
		},
	},

	-------------GuildBuild---------------------------------------------------------
	--{
	--	define = "class" , name = "MsgGuildBuildRequest" ,category = "MSG_CATEGORY_GUILD", id = 150, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "buildingid"},
	--	},
	--},
    --
	--{
	--	define = "class" , name = "MsgGuildBuildResponse", category = "MSG_CATEGORY_GUILD", id = 151, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},
    --
	--{
	--	define = "class" , name = "MsgGuildFinishBuildingRequest" ,category = "MSG_CATEGORY_GUILD", id = 152, base = "Message",
	--	attributes =
	--	{
	--	},
	--},
    --
	--{
	--	define = "class" , name = "MsgGuildFinishBuildingResponse", category = "MSG_CATEGORY_GUILD", id = 153, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	-------------GuildShop----------------------------------------------------------
	{
		define = "struct", name = "GuildShopItem",
		attributes =
		{
			{type = "int32", name = "sid" },
			{type = "int32", name = "price" },
			{type = "int16", name = "level" },
		},
	},

	{
		define = "class", name = "MsgGuildShopItemRequest", category = "MSG_CATEGORY_GUILD",id = 200,base = "Message",
		attributes =
		{
			{type = "int16", name = "page"},
		},
	},

	{
		define = "class", name = "MsgGuildShopItemResponse", category = "MSG_CATEGORY_GUILD",id = 201,base = "Message",
		attributes =
		{
			{type = "GuildShopItem", name = "items", vector = true},
			{type = "int16", name = "page"},
			{type = "int16", name = "maxpage"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGuildShopItemBuyRequest", category = "MSG_CATEGORY_GUILD",id = 202,base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "cnt"},
		},
	},

	{
		define = "class", name = "MsgGuildShopItemBuyResponse", category = "MSG_CATEGORY_GUILD",id = 203,base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSyncGuildShopItemSellNum", category = "MSG_CATEGORY_GUILD",id = 204,base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "sellCount"},
		},
	},


	-------------------拜关公---------------------------------------------------
	--{
	--	define = "class", name = "MsgGuildGuanGongWorshipRequest", category = "MSG_CATEGORY_GUILD",id = 210,base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "type"},
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgGuildGuanGongWorshipResponse", category = "MSG_CATEGORY_GUILD",id = 211,base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	--{
	--	define = "class", name = "MsgGuildGuanGongAddCountRequest", category = "MSG_CATEGORY_GUILD",id = 212,base = "Message",
	--	attributes =
	--	{
    --
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgGuildGuanGongAddCountResponse", category = "MSG_CATEGORY_GUILD",id = 213,base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	--{
	--	define = "class", name = "MsgGuildGuanGongGetRewardRequest", category = "MSG_CATEGORY_GUILD",id = 214,base = "Message",
	--	attributes =
	--	{
    --
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgGuildGuanGongGetRewardResponse", category = "MSG_CATEGORY_GUILD",id = 215,base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--	},
	--},

	{
		define = "class", name = "MsgGuildListVersionNotify", category = "MSG_CATEGORY_GUILD", id = 220, base = "Message",
		attributes =
		{
			{type = "int32", name = "version"},
			{type = "int32", name = "maxpage"},
		}
	},

	{
		define = "class", name = "MsgGuildGetIntDataRequest", category = "MSG_CATEGORY_GUILD", id = 260, base = "Message",
		attributes =
		{
			{type = "int32", name = "guildID"},
			{type = "int16", name = "key"},
		},
	},

	{
		define = "class", name = "MsgGuildGetIntDataResponse", category = "MSG_CATEGORY_GUILD", id = 261, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "guildID"},
			{type = "int16", name = "key"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgGuildGetStringDataRequest", category = "MSG_CATEGORY_GUILD", id = 262, base = "Message",
		attributes =
		{
			{type = "int32", name = "guildID"},
			{type = "int16", name = "key"},
		},
	},

	{
		define = "class", name = "MsgGuildGetStringDataResponse", category = "MSG_CATEGORY_GUILD", id = 263, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "guildID"},
			{type = "int16", name = "key"},
			{type = "string", name = "data"},
		},
	},
	
	--{
	--	define = "class", name = "MsgGuildExploreInitRequest", category = "MSG_CATEGORY_GUILD", id = 271, base = "Message",
	--	attributes =
	--	{
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildExploreInitResponse", category = "MSG_CATEGORY_GUILD", id = 272, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--		{type = "int32", name = "items", vector = true},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildExploreRequest", category = "MSG_CATEGORY_GUILD", id = 273, base = "Message",
	--	attributes =
	--	{
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildExploreResponse", category = "MSG_CATEGORY_GUILD", id = 274, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--		{type = "int32", name = "item"},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildWelfareStatusRequest", category = "MSG_CATEGORY_GUILD", id = 275, base = "Message",
	--	attributes =
	--	{
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildWelfareStatusResponse", category = "MSG_CATEGORY_GUILD", id = 276, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--		{type = "int32", name = "welfareStatus"},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildOpenWelfareRequest", category = "MSG_CATEGORY_GUILD", id = 277, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "welfareID"},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildOpenWelfareResponse", category = "MSG_CATEGORY_GUILD", id = 278, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--		{type = "int32", name = "welfareID"},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildGetWelfareRequest", category = "MSG_CATEGORY_GUILD", id = 279, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "welfareID"},
	--	},
	--},
	
	--{
	--	define = "class", name = "MsgGuildGetWelfareResponse", category = "MSG_CATEGORY_GUILD", id = 280, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode"},
	--		{type = "int32", name = "welfareID"},
	--	},
	--},
	
	{
		define = "class", name = "MsgGuildOpenBuffRequest", category = "MSG_CATEGORY_GUILD", id = 281, base = "Message",
		attributes =
		{
			{type = "int32", name = "buffID"},
		},
	},
	
	{
		define = "class", name = "MsgGuildOpenBuffResponse", category = "MSG_CATEGORY_GUILD", id = 282, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "buffID"},
		},
	},

	----------------------------------------------------------------------------
	-- 申请结盟
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildLeagueAppRequest", category = "MSG_CATEGORY_GUILD", id = 290, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "目标行会ID"}
		},
	},
	{
		define = "class", name = "MsgGuildLeagueAppResponse", category = "MSG_CATEGORY_GUILD", id = 291, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "目标行会ID"},
			{type = "int16", name = "errcode"}
		},
	},

	----------------------------------------------------------------------------
	-- 取消结盟申请
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildCancelLeagueAppRequest", category = "MSG_CATEGORY_GUILD", id = 292, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "目标行会ID"}
		},
	},
	{
		define = "class", name = "MsgGuildCancelLeagueAppResponse", category = "MSG_CATEGORY_GUILD", id = 293, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "目标行会ID"},
			{type = "int16", name = "errcode"}
		},
	},

	----------------------------------------------------------------------------
	-- 审核结盟申请
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildCheckLeagueAppRequest", category = "MSG_CATEGORY_GUILD", id = 294, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "申请行会ID"},
			{type = "int16", name = "errcode", desc = "0-同意, 其他-拒绝"}
		},
	},
	{
		define = "class", name = "MsgGuildCheckLeagueAppResponse", category = "MSG_CATEGORY_GUILD", id = 295, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "申请行会ID"},
            {type = "string", name = "guild_name", desc = "申请行会名称"},
			{type = "int16", name = "errcode"}
		},
	},
	{
		define = "class", name = "MsgGuildCheckLeagueAppNotify", category = "MSG_CATEGORY_GUILD", id = 296, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "被申请行会ID"},
            {type = "string", name = "guild_name", desc = "被申请行会名称"},
			{type = "int16", name = "errcode"}
		},
	},

	----------------------------------------------------------------------------
	-- 添加结盟申请
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildAddLeagueAppNotify", category = "MSG_CATEGORY_GUILD", id = 297, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
            {type = "string", name = "guild_name1", desc = "申请行会名称"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
            {type = "string", name = "guild_name2", desc = "申请行会名称"},
			{type = "int8", name = "show_notice", desc = "是否显示提示:0-不显示, 1-显示"},
		},
	},

	----------------------------------------------------------------------------
	-- 删除结盟申请
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildDelLeagueAppNotify", category = "MSG_CATEGORY_GUILD", id = 298, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
		},
	},

	----------------------------------------------------------------------------
	-- 取消结盟
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildCancelLeagueRequest", category = "MSG_CATEGORY_GUILD", id = 299, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "对方行会ID"},
		},
	},
	{
		define = "class", name = "MsgGuildCancelLeagueResponse", category = "MSG_CATEGORY_GUILD", id = 300, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id", desc = "对方行会ID"},
			{type = "int16", name = "errcode"}
		},
	},
    
	----------------------------------------------------------------------------
	-- 设置结盟行会
	----------------------------------------------------------------------------
	{
		define = "class", name = "MsgGuildAddLeagueNotify", category = "MSG_CATEGORY_GUILD", id = 301, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "行会ID1"},
			{type = "int32", name = "guild_id2", desc = "行会ID2"},
		},
	},
	{
		define = "class", name = "MsgGuildDelLeagueNotify", category = "MSG_CATEGORY_GUILD", id = 302, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "行会ID1"},
			{type = "int32", name = "guild_id2", desc = "行会ID2"},
		},
	},

	--{
	--	--行会目标领取礼包(客户端->服务器)
	--	define = "class", name = "MsgGuildTargetGetRewardRequest", category = "MSG_CATEGORY_GUILD", id = 301, base = "Message",
	--	attributes =
	--	{
	--	},
	--},

	--{
	--	--行会目标领取礼包(服务器->客户端)
	--	define = "class", name = "MsgGuildTargetGetRewardResponse", category = "MSG_CATEGORY_GUILD", id = 302, base = "Message",
	--	attributes =
	--	{
	--		{type = "int16", name = "errcode", desc = "错误码"},
	--	},
	--},
    
	{
		--行会贡献排行领取礼包(客户端->服务器)
		define = "class", name = "MsgGuildContributionGetRewardRequest", category = "MSG_CATEGORY_GUILD", id = 303, base = "Message",
		attributes =
		{
		},
	},
    
	{
		--行会贡献排行领取礼包(服务器->客户端)
		define = "class", name = "MsgGuildContributionGetRewardResponse", category = "MSG_CATEGORY_GUILD", id = 304, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
    
	{
		--行会膜拜请求
		define = "class", name = "MsgGuildWorshipRequest", category = "MSG_CATEGORY_GUILD", id = 305, base = "Message",
		attributes =
		{
			{type = "int32", name = "player_id", desc = "目标玩家ID"},
			{type = "int32", name = "type", desc = "膜拜类型: 0-免费膜拜, 1-1000金币膜拜, 2-10元宝膜拜"},
		},
	},
    
	{
		--行会膜拜应答
		define = "class", name = "MsgGuildWorshipResponse", category = "MSG_CATEGORY_GUILD", id = 306, base = "Message",
		attributes =
		{
			{type = "int32", name = "player_id", desc = "目标玩家ID"},
			{type = "int32", name = "type", desc = "膜拜类型: 0-免费膜拜, 1-1000金币膜拜, 2-10元宝膜拜"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
    
	{
		--领取被膜拜奖励请求
		define = "class", name = "MsgGuildGetBeWorshipedRewardRequest", category = "MSG_CATEGORY_GUILD", id = 307, base = "Message",
		attributes =
		{
		},
	},
    
	{
		--领取被膜拜奖励应答
		define = "class", name = "MsgGuildGetBeWorshipedRewardResponse", category = "MSG_CATEGORY_GUILD", id = 308, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
    
	{
		--行会升级请求
		define = "class", name = "MsgGuildUpgradeLevelRequest", category = "MSG_CATEGORY_GUILD", id = 309, base = "Message",
		attributes =
		{
			{type = "int8", name = "type", desc = "升级类型"},
		},
	},
    
	{
		--行会升级应答
		define = "class", name = "MsgGuildUpgradeLevelResponse", category = "MSG_CATEGORY_GUILD", id = 310, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
    
	{
		--清除行会升级CD请求
		define = "class", name = "MsgGuildClearUpgradeCDRequest", category = "MSG_CATEGORY_GUILD", id = 311, base = "Message",
		attributes =
		{
		},
	},
    
	{
		--清除行会升级CD应答
		define = "class", name = "MsgGuildClearUpgradeCDResponse", category = "MSG_CATEGORY_GUILD", id = 312, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--行会开启副本请求
		define = "class", name = "MsgGuildOpenInstanceRequest", category = "MSG_CATEGORY_GUILD", id = 321, base = "Message",
		attributes =
		{
			{type = "int32", name = "event_id", desc = "活动ID"},
		},
	},

	{
		--行会开启副本应答
		define = "class", name = "MsgGuildOpenInstanceResponse", category = "MSG_CATEGORY_GUILD", id = 322, base = "Message",
		attributes =
		{
			{type = "int32", name = "event_id", desc = "活动ID"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

	{
		--行会开启副本通知
		define = "class", name = "MsgGuildOpenInstanceNotify", category = "MSG_CATEGORY_GUILD", id = 323, base = "Message",
		attributes =
		{
			{type = "int32", name = "player_id", desc = "开启玩家ID"},
			{type = "int32", name = "event_id", desc = "活动ID"},
		},
	},

	{
		--进入行会副本请求
		define = "class", name = "MsgGuildEnterInstanceRequest", category = "MSG_CATEGORY_GUILD", id = 324, base = "Message",
		attributes =
		{
			{type = "int32", name = "event_id", desc = "活动ID"},
		},
	},

	{
		--进入行会副本应答
		define = "class", name = "MsgGuildEnterInstanceResponse", category = "MSG_CATEGORY_GUILD", id = 325, base = "Message",
		attributes =
		{
			{type = "int32", name = "event_id", desc = "活动ID"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
	
	{
		define = "class", name = "MsgGuildSetAutoAddLevelRequest", category = "MSG_CATEGORY_GUILD", id = 352, base = "Message",
		attributes =
		{
			{type = "int16", name = "level", desc = "最低等级"},
		},
	},
	
	{
		define = "class", name = "MsgGuildSetAutoAddLevelResponse", category = "MSG_CATEGORY_GUILD", id = 353, base = "Message",
		attributes =
		{
			{type = "int16", name = "level", desc = "最低等级"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
	
	{
		define = "class", name = "MsgGuildRecommendNotify", category = "MSG_CATEGORY_GUILD", id = 354, base = "Message",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "行会ID1"},
			{type = "string", name = "guild_name1", desc = "行会名称1"},
			{type = "int32", name = "master_class1", desc = "会长职业1"},
			{type = "int32", name = "master_gender1", desc = "会长性别1"},
			{type = "int32", name = "guild_id2", desc = "行会ID2"},
			{type = "string", name = "guild_name2", desc = "行会名称2"},
			{type = "int32", name = "master_class2", desc = "会长职业2"},
			{type = "int32", name = "master_gender2", desc = "会长性别2"},
		},
	},

    {
		define = "class", name = "MsgGuildCreateTeamRequest", category = "MSG_CATEGORY_GUILD", id = 359, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildCreateTeamResponse", category = "MSG_CATEGORY_GUILD", id = 360, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "struct", name = "teaminfo",
		attributes =
		{
            {type = "int32", name = "teamid", desc = "队伍ID"},
            {type = "int32", name = "status", desc = "队伍状态"},
            {type = "int32", name = "count", desc = "队伍人数"},
			{type = "int32", name = "pid", desc = "队长PID"},
            {type = "int32", name = "level", desc = "队长等级"},
			{type = "int16", name = "gender", desc = "队长性别"},
			{type = "int16", name = "job", desc = "队长职业"},
		    {type = "string", name = "name", desc = "队长名字"},
		},
	},

    {
		define = "class", name = "MsgGuildTeamListNotify", category = "MSG_CATEGORY_GUILD", id = 361, base = "Message",
		attributes =
		{
            {type = "teaminfo", name = "TeamList", vector = true, desc = "队伍列表"},
		},
	},

    {
		define = "class", name = "MsgGuildAddTeamNotify", category = "MSG_CATEGORY_GUILD", id = 362, base = "Message",
		attributes =
		{
            {type = "teaminfo", name = "TeamInfo", desc = "队伍信息"},
		},
	},

    {
		define = "class", name = "MsgGuildJoinTeamRequest", category = "MSG_CATEGORY_GUILD", id = 363, base = "Message",
		attributes =
		{
            {type = "int32", name = "teamid", desc = "队伍ID"},
		},
	},

    {
		define = "class", name = "MsgGuildJoinTeamResponse", category = "MSG_CATEGORY_GUILD", id = 364, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildDeleteTeamNotify", category = "MSG_CATEGORY_GUILD", id = 365, base = "Message",
		attributes =
		{
            {type = "int32", name = "teamid", desc = "队伍ID"},
		},
	},

    {
		define = "class", name = "MsgGuildUpdateTeamNotify", category = "MSG_CATEGORY_GUILD", id = 366, base = "Message",
		attributes =
		{
            {type = "int32", name = "teamid", desc = "队伍ID"},
            {type = "int32", name = "count", desc = "队伍人数"},
		},
	},

    {
		define = "class", name = "MsgGuildSearchTeamRequest", category = "MSG_CATEGORY_GUILD", id = 375, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildSearchTeamResponse", category = "MSG_CATEGORY_GUILD", id = 376, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildStartAddMonRequest", category = "MSG_CATEGORY_GUILD", id = 377, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildStartAddMonResponse", category = "MSG_CATEGORY_GUILD", id = 378, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildExitTeamRequest", category = "MSG_CATEGORY_GUILD", id = 379, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildExitTeamResponse", category = "MSG_CATEGORY_GUILD", id = 380, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildGetExpRewardRequest", category = "MSG_CATEGORY_GUILD", id = 381, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildGetExpRewardResponse", category = "MSG_CATEGORY_GUILD", id = 382, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildTeamStatusNotify", category = "MSG_CATEGORY_GUILD", id = 383, base = "Message",
		attributes =
		{
            {type = "int32", name = "teamid", desc = "队伍ID"},
            {type = "int32", name = "status", desc = "队伍状态"},
		},
	},

    {
		define = "class", name = "MsgGuildSendTeamChatRequest", category = "MSG_CATEGORY_GUILD", id = 384, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildSendTeamChatResponse", category = "MSG_CATEGORY_GUILD", id = 385, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildBagForgeRequest", category = "MSG_CATEGORY_GUILD", id = 386, base = "Message",
		attributes =
		{
		},
	},

    {
		define = "class", name = "MsgGuildBagForgeResponse", category = "MSG_CATEGORY_GUILD", id = 387, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "struct", name = "Gather",
		attributes =
		{
			{type="int32", name="pid"},
            {type="int32", name="point"},
            {type="int32", name="sumkill"},
            {type="int32", name="level"},
            {type="int32", name="rebron"},
            {type="string", name="name"},
		}
	},

    {
		define = "class", name = "MsgGuildGatherListNotify", category = "MSG_CATEGORY_GUILD", id = 388, base = "Message",
		attributes =
		{
            {type = "Gather", name ="GatherList", vector = true},
		},
		
	},

    {
		define = "class", name = "MsgGuildGatherKillNotify", category = "MSG_CATEGORY_GUILD", id = 389, base = "Message",
		attributes =
		{
            {type = "int32", name ="pid", desc = "击杀者pid"},
            {type = "int32", name ="job", desc = "击杀者职业"},
            {type = "int32", name ="gender", desc = "击杀者性别"},
            {type = "int32", name ="isdead", desc = "击杀者是否死过"},
            {type = "int32", name ="tpid", desc = "被杀者pid"},
            {type = "int32", name ="tjob", desc = "被杀者职业"},
            {type = "int32", name ="tgender", desc = "被杀者性别"},
            {type = "int32", name ="killNum", desc = "击杀数量 0是被终结"},
            {type = "string", name ="name", desc = "击杀者名字"},
            {type = "string", name ="tname", desc = "被杀者名字"},
		},
		
	},

    {
		define = "struct", name = "Balance",
		attributes =
		{
			{type="int32", name="sumpoint"},
            {type="int32", name="point"},
            {type="string", name="guildname"},
            {type="string", name="name"},
		}
	},

    {
		define = "class", name = "MsgGuildGatherBalanceNotify", category = "MSG_CATEGORY_GUILD", id = 390, base = "Message",
		attributes =
		{
            {type = "Balance", name ="balanceList", vector = true},
		},
		
	},

    {
		define = "class", name = "MsgGuildCanGatherRequest", category = "MSG_CATEGORY_GUILD", id = 391, base = "Message",
		attributes =
		{
            {type = "int32", name = "eid", desc = "采集物的eid"},
		},
	},

    {
		define = "class", name = "MsgGuildCanGatherResponse", category = "MSG_CATEGORY_GUILD", id = 392, base = "Message",
		attributes =
		{
			{type = "int32", name = "rep", desc = "0可以采集 1不可以采集 2自己正在采集"},
		},
	},

    {
		define = "class", name = "MsgGuildQiFuRequest", category = "MSG_CATEGORY_GUILD", id = 393, base = "Message",
		attributes =
		{
			
		},
	},
	{
		define = "class", name = "MsgGuildQiFuResponse", category = "MSG_CATEGORY_GUILD", id = 394, base = "Message",
		attributes =
		{
			{type = "int32", name = "result", desc = "返回结果"},
			{type = "int32", name = "percent", desc = "工会祈福进度百分比"},
			{type = "int32", name = "percentOld", desc = "昨日工会祈福进度百分比"},
			{type = "int32", name = "isQiFu", desc = "角色是否已祈福，1代表已祈福"},
			
		},
	},
	{
		define = "class", name = "MsgGuildQiFuStartRequest", category = "MSG_CATEGORY_GUILD", id = 395, base = "Message",
		attributes =
		{
			
		},
	},
	{
		define = "class", name = "MsgGuildQiFuStartResponse", category = "MSG_CATEGORY_GUILD", id = 396, base = "Message",
		attributes =
		{
			{type = "int32", name = "result", desc = "返回结果"},
			{type = "int32", name = "percent", desc = "工会祈福进度百分比"},
			{type = "int32", name = "percentOld", desc = "昨日工会祈福进度百分比"},
			{type = "int32", name = "isQiFu", desc = "角色是否已祈福，1代表已祈福"},
			{type = "int32", name = "bei", desc = "暴击倍数"},
		},
	},

    {
		define = "class", name = "MsgGuildImpeachMasterRequest", category = "MSG_CATEGORY_GUILD", id = 397, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid", desc = "弹劾发起人"},
		},
	},
	
	{
		define = "class", name = "MsgGuildImpeachMasterResponse", category = "MSG_CATEGORY_GUILD", id = 398, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid", desc = "弹劾发起人"},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildImpeachVoteRequest", category = "MSG_CATEGORY_GUILD", id = 399, base = "Message",
		attributes =
		{
			{type = "int32", name = "time", desc = "弹劾发起时间"},
			{type = "int32", name = "vote", desc = "0-反对弹劾, 其他-同意弹劾 "},
		},
	},

    {
		define = "class", name = "MsgGuildImpeachVoteResponse", category = "MSG_CATEGORY_GUILD", id = 400, base = "Message",
		attributes =
		{
			{type = "int32", name = "time", desc = "弹劾发起时间"},
			{type = "int32", name = "vote", desc = "0-反对弹劾, 其他-同意弹劾 "},
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},

    {
		define = "class", name = "MsgGuildBatchDeleteMemRequest", category = "MSG_CATEGORY_GUILD", id = 401, base = "Message",
		attributes =
		{
			{type = "int32", name = "pids", vector = true, desc = "角色pid数组"},
		},
	},
	
	{
		define = "class", name = "MsgGuildBatchDeleteMemResponse", category = "MSG_CATEGORY_GUILD", id = 402, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", vector = true, desc = "错误码"},
		},
	},
	{
		define = "struct", name = "ShopItemInfo",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "sellCount"},
		},
	},

	{
		define="class", name="MsgSyncGuildShopNotify", category="MSG_CATEGORY_GUILD" , id=403 ,base="Message",
		attributes =
		{
			{type="int32", name="pid", dump=true, desc = "公会id"},
			{type="ShopItemInfo", name="items", vector=true, desc = "公会商店物品"},
		},
	},
	
	{
		define = "class", name = "MsgGuildTechnologyUpLevelRequest", category = "MSG_CATEGORY_GUILD", id = 404, base = "Message",
		attributes =
		{
			{type = "int16", name = "type", desc = "科技类型"},
			{type = "int16", name = "index", desc = "技能index"},
		},
	},
	
	{
		define = "class", name = "MsgGuildTechnologyUpLevelResponse", category = "MSG_CATEGORY_GUILD", id = 405, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
		},
	},
	
	{
		define = "struct", name = "GuishiItem",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "cid"},
		},
	},

	{
		define="class", name="MsgSyncGuildGuishiItemsNotify", category="MSG_CATEGORY_GUILD" , id=406 ,base="Message",
		attributes =
		{
			{type="int32", name="gid", dump=true, desc = "公会id"},
			{type="GuishiItem", name="items", vector=true, desc = "公会商店物品"},
		},
	},
	
	{
		define="class", name="MsgDelGuildGuishiItemNotify", category="MSG_CATEGORY_GUILD" , id=407 ,base="Message",
		attributes =
		{
			{type="int32", name="cid", dump=true, desc = "物品id"},
		},
	},
	
	{
		define="class", name="MsgAddGuildGuishiItemNotify", category="MSG_CATEGORY_GUILD" , id=408 ,base="Message",
		attributes =
		{
			{type="int32", name="gid", dump=true, desc = "公会id"},
			{type="GuishiItem", name="items", desc = "公会商店物品"},
		},
	},
	
}

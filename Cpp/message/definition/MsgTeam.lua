messages =
{
	{
		define = "class", name = "MsgTeamInviteRequest", category = "MSG_CATEGORY_TEAM", id = 1, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgTeamInviteResponse", category = "MSG_CATEGORY_TEAM", id = 2, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "errcode"},
		},
	},


	{
		define = "class", name = "MsgTeamJoinRequest", category = "MSG_CATEGORY_TEAM", id = 3, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgTeamJoinResponse", category = "MSG_CATEGORY_TEAM", id = 4, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgTeamQuitRequest", category = "MSG_CATEGORY_TEAM", id = 5, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgTeamQuitResponse", category = "MSG_CATEGORY_TEAM", id = 6, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgTeamMakeOperation", category = "MSG_CATEGORY_TEAM", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "opid"},
			{type = "int16", name = "type" },
			{type = "int32", name = "pid"},
			{type = "string", name = "name",},
			{type = "int32", name = "job",},
            {type = "int32", name = "gender",},
			{type = "int32", name = "level",},
			{type = "string", name = "guild",},
 		},
	},

	{
		define = "class", name = "MsgTeamMakeOperationReply", category = "MSG_CATEGORY_TEAM", id = 11, base = "Message",
		attributes =
		{

			{type = "int32", name = "opid"},
			{type = "int32", name = "type"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name",},
			{type = "int16", name = "result"},
		},

	},

	{
		define = "class", name = "MsgTeamMakeDecisionRequest", category = "MSG_CATEGORY_TEAM", id = 12 , base = "Message",
		attributes =
		{
			{type = "int32", name = "opid"},
			{type = "int16", name = "decide"},
		},
	},

	{
		define = "class", name = "MsgTeamMakeDecisionResponse", category = "MSG_CATEGORY_TEAM", id = 13 , base = "Message",
		attributes =
		{
			{type = "int32", name = "opid"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "struct", name = "TeamMate",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "int8", name = "leader"},
			{type = "int8",  name = "gender"		},
			{type = "int8"	, name = "clazz"		},
			{type = "int32"	, name = "reborn"		},
			{type = "int32"	, name = "level"		},
			{type = "string", name = "guild"	},
			{type = "int8"	, name = "online"		},
			{type = "int32"	, name = "zhanli"		},
            {type = "int32"	, name = "weapon"		},
            {type = "int32"	, name = "cloth"		},
            {type = "int32"	, name = "wings"		},
            {type = "int32"	, name = "mapid"		},
            {type = "int32"	, name = "logintime"		},
		},
	},

	{
		define = "class", name = "MsgTeamInfoNotify", category = "MSG_CATEGORY_TEAM", id = 20, base = "Message",
		attributes =
		{
			{type = "TeamMate", name = "teammates", vector = true},
		},
	},

	{
		define = "class", name = "MsgTeamInfoUpdNotify", category = "MSG_CATEGORY_TEAM", id = 21, base = "Message",
		attributes =
		{
			{type = "TeamMate", name = "mate"},
		},
	},

	{
		define = "class", name = "MsgTeamInfoRmvNotify", category = "MSG_CATEGORY_TEAM", id = 22, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgTeamKickPlayerRequest", category = "MSG_CATEGORY_TEAM", id = 30, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgTeamKickPlayerResponse", category = "MSG_CATEGORY_TEAM", id = 31, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgTeamSetLeaderRequest", category = "MSG_CATEGORY_TEAM", id = 32, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgTeamSetLeaderResponse", category = "MSG_CATEGORY_TEAM", id = 33, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgTeamCreateRequest", category = "MSG_CATEGORY_TEAM", id = 35, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgTeamCreateResponse", category = "MSG_CATEGORY_TEAM", id = 36, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgTeamDestroyRequest", category = "MSG_CATEGORY_TEAM", id = 37, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgTeamDestroyResponse", category = "MSG_CATEGORY_TEAM", id = 38, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgTeamListRequest", category = "MSG_CATEGORY_TEAM", id = 39, base = "Message",
		attributes =
		{
			{type = "int32", name = "flag"},
		},
	},
	
	{
		define = "class", name = "MsgTeamListResponse", category = "MSG_CATEGORY_TEAM", id = 40, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "flag"},
		},
	},
	
	{
		define = "class", name = "MsgTeamNearbyRequest", category = "MSG_CATEGORY_TEAM", id = 41, base = "Message",
		attributes =
		{
			{type = "int32", name = "flag"},
		},
	},
	
	{
		define = "struct", name = "TeamNearbyList",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "string", name = "guild_name" },
			{type = "int32",  name = "gender"		},
			{type = "int32"	, name = "clazz"		},
			{type = "int32"	, name = "level"		},
			{type = "int32"	, name = "reborn"		},
			{type = "int32"	, name = "zhanli"		},
			{type = "int32"	, name = "membercount"		},
		},
	},
	
	{
		define = "class", name = "MsgTeamNearbyResponse", category = "MSG_CATEGORY_TEAM", id = 42, base = "Message",
		attributes =
		{
			{type = "TeamNearbyList", name = "teamnearbylistvec", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgTeamMataInvitePlayerResponse", category = "MSG_CATEGORY_TEAM", id = 43, base = "Message",
		attributes =
		{
			{type = "int32", name = "pidinvite"},
			{type = "string", name = "nameinvite" },
			{type = "int32", name = "pidinvited"},
			{type = "string", name = "nameinvited" },
			{type = "string", name = "nameinvitedguild" },
		},
	},
	
	{
		define = "class", name = "MsgTeamMataInvitePlayerRequest", category = "MSG_CATEGORY_TEAM", id = 44, base = "Message",
		attributes =
		{
			{type = "int32", name = "result"},
			{type = "int32", name = "captain_set"},
			{type = "int32", name = "pidinvite"},
			{type = "string", name = "nameinvite" },
			{type = "int32", name = "pidinvited"},
			{type = "string", name = "nameinvited" },
		},
	},
		{
		define = "class", name = "MsgTeamMemeberNearbyRequest", category = "MSG_CATEGORY_TEAM", id = 45, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},
	
	{
		define = "struct", name = "TeamMemberNearbyList",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name" },
			{type = "string", name = "guild_name" },
			{type = "int32",  name = "gender"		},
			{type = "int32"	, name = "clazz"		},
			{type = "int32"	, name = "level"		},
			{type = "int32"	, name = "reborn"		},
			{type = "int32"	, name = "zhanli"		},
			{type = "int32"	, name = "isleader"		},
			{type = "int32"	, name = "mapid"		},
		},
	},
	
	{
		define = "class", name = "MsgTeamMemberNearbyResponse", category = "MSG_CATEGORY_TEAM", id = 46, base = "Message",
		attributes =
		{
			{type = "TeamMemberNearbyList", name = "teammembernearbylistvec", vector = true},
		},
	},
	
}


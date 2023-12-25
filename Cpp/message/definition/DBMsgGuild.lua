messages = {
	{
		define = "struct", name = "DBGuildInfo",
		attributes =
		{
			{type = "int32", name ="guildid"},
			{type = "int32", name ="money"},
			{type = "int32", name ="ingot"},
            {type = "int32", name ="isgot"},
			{type = "string" ,name = "guildname"},
			{type = "string" ,name = "guildplacard"},
			{type = "string" ,name = "publicnotice"},
			{type = "int32" , name = "createtime"},
			{type = "int32", name = "masterpid"},
			{type = "string", name = "mastername"},
			{type = "int32",  name = "playercnt"},
		},
	},
	{
		define = "class", name = "MsgDBGuildCreate", category = "MSG_CATEGORY_DB_GUILD", id = 1, base = "MessageEx", salt = "gid",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "string", name = "guildname"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "newgid"},
			{type = "int32", name = "money"},
			{type = "int32", name = "lvl"},
			{type = "int32", name = "next_level_time"},
            {type = "string", name = "defaultnotice"},
		},
	},

	{
		define = "class", name = "MsgDBGuildLoad", category = "MSG_CATEGORY_DB_GUILD", id = 2, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildInfo", name = "Guilds", vector = true},
		},
	},
	{
		define = "struct", name = "DBGuildApplication",
		attributes =
		{
			{type = "int32" , name = "gid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int16", name = "job"},
			{type = "int16", name = "gender"},
			{type = "int32" ,name = "reborn"},
			{type = "int32" ,name = "level"},
			{type = "int32" ,name = "force"},
			{type = "int32", name = "apptime"},
			{type = "int32", name = "type"},
			{type = "int32", name = "sponsorGrade"},
		},
	},

	{
		define = "class", name = "MsgDBGuildApplicationLoad", category = "MSG_CATEGORY_DB_GUILD", id = 3 ,base = "MessageEx",
		attributes =
		{
			{type = "DBGuildApplication", name = "Applications", vector = true},
		},
	},

	{
		define = "class" ,name = "MsgDBGuildApplicationUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 4, base = "MessageEx", salt = "gid",
		attributes =
		{
			{type = "int32" ,name=  "gid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class" ,name = "MsgDBGuildApplicationDelete", category = "MSG_CATEGORY_DB_GUILD", id = 5, base = "MessageEx", salt = "gid",
		attributes =
		{
			{type = "int32" ,name=  "gid"},
			{type = "int32", name = "pid"},
		},
	},


	{
		define = "struct", name = "DBGuildMember",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "pid"},
			{type = "string",name = "playername"},
			{type = "int32", name = "level"},
			{type = "int32", name = "post"},
			{type = "int32", name = "offtime"},
			{type = "int32", name = "contribution"},
			{type = "int32", name = "todaycontribution"},
			{type = "int16", name = "gender"},
			{type = "int32", name = "force"},
			{type = "int32", name = "rank_day"},
			{type = "int32", name = "rank"},
			{type = "int32", name = "vitality"},
			{type = "int32", name = "kfyz_time"},
			{type = "int32", name = "intime"},
			{type = "int16", name = "speek"},
			{type = "int32", name = "exploits"},
			{type = "int32", name = "exploits_tindex"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "sponsorGrade"},
			{type = "int32", name = "job"},
		},
	},

	{
		define = "class", name = "MsgDBGuildMemberLoad",category = "MSG_CATEGORY_DB_GUILD", id = 10, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildMember", name ="members",vector = true},
		},
	},

	{
		define = "class", name = "MsgDBGuildMemberDelete", category = "MSG_CATEGORY_DB_GUILD", id = 11 , base = "MessageEx", salt = "guildid",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "pid"},
		},
	},
	{
		define = "class", name = "MsgDBGuildMemberUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 15, base = "MessageEx", salt = "guildid",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "post"},
			{type = "int16", name = "speek"},
			{type = "int32", name = "offtime"},
		},
	},

	{
		define = "class", name = "MsgDBGuildMasterUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 12 , base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "pid"},
		},
	},

	--{
	--	define = "class", name = "MsgDBGuildContributionUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 13, base = "MessageEx", salt = "guildid", send_back = false,
	--	attributes =
	--	{
	--		{type = "int32", name = "guildid"},
	--		{type = "int32", name = "sumcon"},
	--	},
	--},

	{
		define = "class", name = "MsgDBGuildDelete", category = "MSG_CATEGORY_DB_GUILD", id = 14, base = "MessageEx", salt = "guildid",
		attributes =
		{
			{type = "int32", name = "guildid"},
		},
	},

	{
		define = "class", name = "MsgDBGuildPlacardUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 16, base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "string", name = "placard"},
		},
	},

	{
		define = "class", name = "MsgDBGuildPublicnoticeUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 17, base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "string", name = "publicnotice"},
		},
	},
	{
		define = "class", name = "MsgDBGuildMoneyUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 18, base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "money"},
		},
	},

	--{
	--	define = "struct", name = "nicknameData",
	--	attributes =
	--	{
	--		{type = "int32", name = "gid"},
	--		{type = "int32", name = "job"},
	--		{type = "string", name = "name"},
	--	},
	--},
	--{
	--	define = "class", name = "MsgDBGuildLoadNickname", category = "MSG_CATEGORY_DB_GUILD",  id = 19, base = "MessageEx",
	--	attributes =
	--	{
	--		{type = "nicknameData", name = "ndata", vector = true},
	--	},
	--},
	--{
	--	define = "class" , name = "MsgDBGuildUpdateNickname", category = "MSG_CATEGORY_DB_GUILD", id = 20, base = "MessageEx",
	--	attributes =
	--	{
	--		{type = "int32", name = "gid"},
	--		{type = "int32", name = "job"},
	--		{type = "string", name = "name"},
	--	},
	--},

	{
		define = "class", name = "MsgDBGuildMemberAdd", category = "MSG_CATEGORY_DB_GUILD", id = 21 , base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "pid"},
		},
	},
	{
		define = "struct", name = "DBGuildRecord",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int16", name = "type" },
			{type = "int32", name = "recordtime" },
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "string", name = "namex" },
			{type = "string", name = "namey" },
		},
	},
	
	{
		define = "class", name = "MsgDBGuildMemberOffTimeUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 22 , base = "MessageEx", salt = "guildid", send_back = false,
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "offTime"},
		},
	},

	{
		define = "class", name = "MsgDBGuildRecordLoad",category = "MSG_CATEGORY_DB_GUILD", id = 41, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildRecord", name = "Records", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBGuildRecordAdd",category = "MSG_CATEGORY_DB_GUILD", id = 42, base = "MessageEx", salt = "gid", send_back = false,
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int16", name = "type"},
			{type = "int32", name = "datax" },
			{type = "int32", name = "datay" },
			{type = "string", name = "namex" },
			{type = "string", name = "namey" },
		},
	},

	{
		define = "class", name = "MsgDBGuildRecordDel",category = "MSG_CATEGORY_DB_GUILD", id = 43, base = "MessageEx", salt = "gid", send_back = false,
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "recordtime" },
		},
	},

	{
		define = "struct", name = "DBGuildExData",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},
	{
		define = "class", name = "MsgDBGuildExDataLoad", category = "MSG_CATEGORY_DB_GUILD", id = 60, base = "MessageEx",
		attributes =
		{

			{type = "DBGuildExData", name = "datas", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBGuildExDataUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 61, base = "MessageEx", salt = "gid", send_back = false,
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgDBGuildExDataUpdateAll", category = "MSG_CATEGORY_DB_GUILD", id = 62, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	--{
	--	define = "class", name = "MsgDBGuildRankLoad",  category = "MSG_CATEGORY_DB_GUILD", id = 70,base = "MessageEx",
	--	attributes =
	--	{
	--		{type = "int32", name = "gid", vector = true},
	--	},
	--},

	{
		define = "class", name="MsgDBGuildUpdateName",category = "MSG_CATEGORY_DB_GUILD" , id = 71,base = "MessageEx", salt = "guildid",
		attributes =
		{
			{type="int32", name ="guildid" },
			{type="string", name="name"},
		},
	},

	{
		--行会结盟记录
		define = "struct", name = "DBGuildLeague",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
			{type = "int32", name = "ctime", desc = "创建时间"},
		},
	},

	{
		--加载行会结盟表
		define = "class", name = "MsgDBGuildLeagueLoad", category = "MSG_CATEGORY_DB_GUILD", id = 72 ,base = "MessageEx",
		attributes =
		{
			{type = "DBGuildLeague", name = "leagues", vector = true},
		},
	},

	{
		--增加行会结盟
		define = "class" ,name = "MsgDBGuildLeagueAdd", category = "MSG_CATEGORY_DB_GUILD", id = 73, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
		},
	},

	{
		--删除行会结盟
		define = "class" ,name = "MsgDBGuildLeagueDelete", category = "MSG_CATEGORY_DB_GUILD", id = 74, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
		},
	},

	{
        --行会结盟申请记录
		define = "struct", name = "DBGuildLeagueApp",
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
			{type = "int32", name = "ctime", desc = "申请时间"},
		},
	},

	{
		--加载结盟申请列表
		define = "class", name = "MsgDBGuildLeagueAppLoad", category = "MSG_CATEGORY_DB_GUILD", id = 75 ,base = "MessageEx",
		attributes =
		{
			{type = "DBGuildLeagueApp", name = "apps", vector = true},
		},
	},

	{
		--增加结盟申请记录
		define = "class", name = "MsgDBGuildLeagueAppAdd", category = "MSG_CATEGORY_DB_GUILD", id = 76, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
		},
	},

	{
		--删除结盟申请记录
		define = "class" ,name = "MsgDBGuildLeagueAppDelete", category = "MSG_CATEGORY_DB_GUILD", id = 77, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "guild_id1", desc = "申请行会ID"},
			{type = "int32", name = "guild_id2", desc = "目标行会ID"},
		},
	},
    
	{
		define = "struct", name = "DBGuildMemberRank",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "contribution"},
		},
	},

	{
		define = "class", name = "MsgDBGuildMemberRankLoad",category = "MSG_CATEGORY_DB_GUILD", id = 81, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildMemberRank", name ="members",vector = true},
		},
	},
	
	{
		define = "struct", name = "DBGuildRed",
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
		define = "class", name = "MsgDBGuildRedLoad", category = "MSG_CATEGORY_DB_GUILD", id = 82, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildRed", name = "GuildReds", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgDBGuildRedAdd", category = "MSG_CATEGORY_DB_GUILD", id = 83, base = "MessageEx",  salt = "guildid",
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
			{type = "int32", name = "vipLevel"},
            {type = "int32", name = "gender"},			
			{type = "string", name = "name"},
            {type = "string", name = "desc"},		
		},
	},
	
		{
		define = "class", name = "MsgDBGuildRedUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 84, base = "MessageEx", salt = "id",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "curgold"},
			{type = "int32", name = "curcount"},
		},
	},
	
	{
		define = "struct", name = "DBGuildRedRecord",
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
		define = "class", name = "MsgDBGuildRedRecordLoad", category = "MSG_CATEGORY_DB_GUILD", id = 85, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildRedRecord", name = "GuildRedRecords", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgDBGuildRedRecordAdd", category = "MSG_CATEGORY_DB_GUILD", id = 86, base = "MessageEx", salt = "redid",
		attributes =
		{
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
		define = "class", name = "MsgDBGuildRedDel", category = "MSG_CATEGORY_DB_GUILD", id = 87, base = "MessageEx", salt = "redid",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "redid"},
		},
	},
	
	{
		define = "struct", name = "DBGczLeaderInfo",
		attributes =
		{
			{type = "int32", name = "pid"},
		    {type = "string", name = "name"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "job"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "hat"},
			{type = "int32", name = "shield"},
			{type = "int32", name = "guardLevel"},
			{type = "int32", name = "hunhuan"},
			{type = "int32", name = "jingling"},
			{type = "int16", name = "post"},
		},
	},
	
	{
		define = "class", name = "MsgDBSeachGczLeader", category = "MSG_CATEGORY_DB_GUILD", id = 88, base = "MessageEx", salt = "pid",
		attributes =
		{
		    {type = "int32", name = "pid"},
		    {type = "int32", name = "guildid"},
			{type = "DBGczLeaderInfo", name = "vInfo", vector = true},	
		},
	},
	
	{
		define = "class", name = "MsgDBClearGuilds", category = "MSG_CATEGORY_DB_GUILD", id = 89, base = "MessageEx", send_back = false,
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgDBQmRedRecordAdd", category = "MSG_CATEGORY_DB_GUILD", id = 90, base = "MessageEx", salt = "spid",
		attributes =
		{
			{type = "int32", name = "spid"},
			{type = "string", name = "sname"},			
			{type = "int32", name = "gender"},		
			{type = "int32", name = "job"},
            {type = "int32", name = "guildid"},
            {type = "int32", name = "money"},
			{type = "int32", name = "moneyall"},
			{type = "int32", name = "mode"},
		},
	},
	{
		define = "struct", name = "DBQmRedRecord",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "spid"},
			{type = "string", name = "sname"},			
			{type = "int32", name = "gender"},		
			{type = "int32", name = "job"},
            {type = "int32", name = "guildid"},
			{type = "string", name = "guildname"},
            {type = "int32", name = "money"},
			{type = "int32", name = "moneyall"},
			{type = "int32", name = "mode"},
		},
	},
	{
		define = "class", name = "MsgDBQmRedRecordLoad", category = "MSG_CATEGORY_DB_GUILD", id = 91, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBQmRedRecord", name = "QmRedRecord", vector = true},
		},
	},
	{
		define = "class", name = "MsgDBQmRedRecordClear", category = "MSG_CATEGORY_DB_GUILD", id = 92, base = "MessageEx",
		attributes =
		{
		},
	},
	{
		define = "struct", name = "DBQmRedOrderItem",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "order"},
			{type = "int32", name = "spid"},
			{type = "string", name = "sname"},			
			{type = "int32", name = "money"},
		},
	},
	{
		define = "class", name = "MsgDBQmRedOrderUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 93, base = "MessageEx",
		attributes =
		{
			{type = "DBQmRedOrderItem", name = "qmRedOrderItem", vector = true},
		},
	},
	{
		define = "struct", name = "GuildQFInfo",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "guildid"},
			{type = "int32", name = "percent"},			
			{type = "int32", name = "percentOld"},	
		},
	},
	{
		define = "class", name = "MsgDBQiFuLoad", category = "MSG_CATEGORY_DB_GUILD", id = 94, base = "MessageEx",
		attributes =
		{
			{type = "GuildQFInfo", name = "guildQfItems", vector = true},
		},
	},
	{
		define = "class", name = "MsgDBQiFuUpdate", category = "MSG_CATEGORY_DB_GUILD", id = 95, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "GuildQFInfo", name = "guildQfItems",vector = true},
		},
	},

	{
		define = "struct", name = "DBGuildShopItems",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "sid"},	
			{type = "int32", name = "buycount"},	
		},
	},

	{
		define = "class", name="MsgDBLoadGuildShop", category = "MSG_CATEGORY_DB_GUILD", id = 96, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildShopItems", name = "items", vector = true},
		},
	},

	{
		define = "class", name="MsgDBGuildShopAdd", category = "MSG_CATEGORY_DB_GUILD", id = 97, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildId"},
			{type = "int32", name = "sid"},
		},
	},

	{
		define = "class", name="MsgDBGuildShopDel", category = "MSG_CATEGORY_DB_GUILD", id = 98, base = "MessageEx",
		attributes =
		{
		},
	},
	{
		define = "class", name="MsgDBUpdataGuildShopItemNum", category = "MSG_CATEGORY_DB_GUILD", id = 99, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildId"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "sellCount"},
		},
	},
	
	{
		define = "struct", name = "DBGuildCrossIntegralItem",
		attributes =
		{
			{type = "int32", name = "sid"},	
			{type = "int32", name = "value"},	
		},
	},
	
	{
		define = "class", name="MsgDBLoadGuildCrossIntegral", category = "MSG_CATEGORY_DB_GUILD", id = 100, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildId"},
			{type = "int32", name = "eventid"},
			{type = "int32", name = "tindex"},
			{type = "DBGuildCrossIntegralItem", name = "members", vector = true},
		},
	},
	
	{
		define = "struct", name = "DBGuildGuishiItems",
		attributes =
		{
			{type = "int32", name = "guildid"},
			{type = "int32", name = "sid"},	
			{type = "int32", name = "cid"},	
		},
	},

	{
		define = "class", name="MsgDBLoadGuildGuishi", category = "MSG_CATEGORY_DB_GUILD", id = 101, base = "MessageEx",
		attributes =
		{
			{type = "DBGuildGuishiItems", name = "items", vector = true},
		},
	},

	{
		define = "class", name="MsgDBGuildGuishiAdd", category = "MSG_CATEGORY_DB_GUILD", id = 102, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildId"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "cid"},
		},
	},

	{
		define = "class", name="MsgDBGuildGuishiDel", category = "MSG_CATEGORY_DB_GUILD", id = 103, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "guildId"},
			{type = "int32", name = "cid"},
		},
	},
}

messages = {
	{
		define = "class", name="MsgDBUpdatePlayerName", category = "MSG_CATEGORY_DB_PLAYER" , id = 1, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid", desc="Íæ¼ÒID"},
			{type="string", name="name"},
			{type="int16", name="flags"},
		},
	},

	{
		define = "class",name = "MsgDBUpdatePlayerLvlExp" ,category = "MSG_CATEGORY_DB_PLAYER", id = 2, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int16", name = "lvl"},
			{type = "int64", name = "exp"},
			{type = "int16", name = "reborn"},
		},
	},

	{
		define = "class", name = "MsgDBUpdatePlayerPositon", category = "MSG_CATEGORY_DB_PLAYER", id = 3, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32" ,name = "pid"},
			{type = "int32" ,name = "sceneid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
		},
	},

	{
		define = "class", name="MsgDBUpdatePlayerLingFu", category = "MSG_CATEGORY_DB_PLAYER" , id = 4, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="lingfu"},
		},
	},

	{
		define = "class", name="MsgDBUpdatePlayerIngot", category = "MSG_CATEGORY_DB_PLAYER" , id = 5, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int64", name="ingot"},
		},
	},
	
	{
		define = "class", name="MsgDBUpdatePlayerBoundLingFu", category = "MSG_CATEGORY_DB_PLAYER" , id = 6, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="boundlingfu"},
		},
	},

	{
		define = "class", name="MsgDBUpdatePlayerBoundIngot", category = "MSG_CATEGORY_DB_PLAYER" , id = 7, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name="pid"},
			{type="int64", name="boundingot"},
		},
	},
	
	{
		define = "struct", name = "exData",
		attributes =
		{
			{type = "int32", name = "ctype"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerProps", category = "MSG_CATEGORY_DB_PLAYER",  id = 21, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "exData", name = "props", vector = true},
		},
	},

	{
		define = "class" , name = "MsgDBAddPlayerProp", category = "MSG_CATEGORY_DB_PLAYER", id = 22, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "ctype"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class" , name = "MsgDBUpdatePlayerProp", category = "MSG_CATEGORY_DB_PLAYER", id = 23, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "ctype"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name="MsgDBUpdatePlayerGuildID", category = "MSG_CATEGORY_DB_PLAYER" , id = 31, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type="int32", name = "pid"},
			{type="int32", name = "gid"},
		},
	},
	
	{
		define = "struct", name = "DBCooldown",
		attributes =
		{
			{type = "int16", name = "ctype"},
			{type = "int32", name = "endtime"},
			{type = "int8", name = "flag"},
		},
	},

	{
		define = "class", name = "MsgDBLoadCoolDown", category = "MSG_CATEGORY_DB_PLAYER", id = 41 , base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBCooldown",name = "CDlist", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdateCoolDown", category = "MSG_CATEGORY_DB_PLAYER", id = 42 , base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBCooldown",name = "CDinfo"},
		},
	},

	{
		define = "struct", name = "DBPlayerEvent",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "tindex"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int32", name = "ctime"},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerEvent", category = "MSG_CATEGORY_DB_PLAYER", id = 51, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "DBPlayerEvent", name = "events", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdPlayerEvent", category = "MSG_CATEGORY_DB_PLAYER", id = 52, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "eid"},
			{type = "int32", name = "tindex"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgDBDeletePlayerEvent", category = "MSG_CATEGORY_DB_PLAYER", id = 53, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "eid"},
		},
	},

	{
		define = "struct", name = "DBPlayerGene",
		attributes =
		{
			{type = "int32", name = "geneid"},
			{type = "int32", name = "duration"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgDBLoadPlayerGene", category = "MSG_CATEGORY_DB_PLAYER", id = 61, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "DBPlayerGene", name = "genes", vector = true},
		},
	},

	{
		define = "class", name = "MsgDBUpdPlayerGene", category = "MSG_CATEGORY_DB_PLAYER", id = 62, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "geneid"},
			{type = "int32", name = "duration"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgDBRmvPlayerGene", category = "MSG_CATEGORY_DB_PLAYER", id = 63, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "geneid"},
		},
	},
	
	{
		define = "struct", name = "DBSkillInfo",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="exp"},
			{type="int8" , name="position"},
		}
	},

	{
		define = "struct", name = "DBPlayerSkillInfo",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="lvl"},
		}
	},

	{
		define = "class", name="MsgDBLoadSkill", category = "MSG_CATEGORY_DB_PLAYER" , id = 71 , base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "DBPlayerSkillInfo", name = "skill_list", vector = true},
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "int8" , name = "load_reason"},
		},
	},

	{
		define = "class",name = "MsgDBAddSkill" , category = "MSG_CATEGORY_DB_PLAYER", id = 72, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "level"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class",name = "MsgDBRemoveSkill" , category = "MSG_CATEGORY_DB_PLAYER", id = 73, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class",name = "MsgDBUpdateSkillSidExp" ,category = "MSG_CATEGORY_DB_PLAYER", id = 74, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "osid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "exp"},
		},
	},

	{
		define = "class",name = "MsgDBUpdateSkillPosition" ,category = "MSG_CATEGORY_DB_PLAYER", id = 75, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "position"},
		},
	},

	{
		define = "class",name = "MsgDBLoadPetSkill" ,category = "MSG_CATEGORY_DB_PLAYER", id = 81, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "DBSkillInfo", name = "skill_list", vector = true},
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "int8" , name = "load_reason"},
		},
	},

	{
		define = "class",name = "MsgDBAddPetSkill" , category = "MSG_CATEGORY_DB_PLAYER", id = 82, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "exp"},
			{type = "int16", name = "position"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class",name = "MsgDBRemovePetSkill" , category = "MSG_CATEGORY_DB_PLAYER", id = 83, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class",name = "MsgDBUpdatePetSkill" ,category = "MSG_CATEGORY_DB_PLAYER", id = 84, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},			
			{type = "int32", name = "sid"},
			{type = "int32", name = "exp"},
			{type = "int16", name = "position"},
		},
	},
	
	{
		define = "class",name = "MsgDBCheckAppStoreCommentRewarded" , category = "MSG_CATEGORY_DB_PLAYER", id = 94, base = "MessageEx", salt = "aid",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
		},
	},

    {
		define = "struct", name = "DBdress",
		attributes =
		{
			{type = "int32", name = "dressid"},
			{type = "int32", name = "status"},
			{type = "int32", name = "etime"},
			{type = "int32", name = "lvl"},
		},
	},
	
	{ define = "struct" , name = "DBPlayerStr",
		attributes = 
		{
			{type = "int32" , name = "keyid"},
			{type = "string" , name = "data"},
		},
	},

	{
		define = "class", name = "MsgDBSavePlayerDress", category = "MSG_CATEGORY_DB_PLAYER", id = 95, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBdress", name = "dress"},
		},
	},
	

    {
		define = "class", name = "MsgDBUpdatePlayerDress", category = "MSG_CATEGORY_DB_PLAYER", id = 96, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBdress", name = "dress"},
		},
	},

    {
		define = "class", name = "MsgDBLoadPlayerDress", category = "MSG_CATEGORY_DB_PLAYER", id = 97, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
            {type = "int32", name = "load_id"},
			{type = "DBdress", name = "dressVec", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgDBLoadPlayerStrData", category = "MSG_CATEGORY_DB_PLAYER", id = 98, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
			{type = "DBPlayerStr", name = "playerStrVec", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgDBUpdatePlayerStrData", category = "MSG_CATEGORY_DB_PLAYER", id = 99, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
		    {type = "int32", name = "pid"},
			{type = "int32", name = "keyid"},
			{type = "string", name = "data"},
		},
	},
	

	{
		define = "class",name = "MsgDBUpDateSkillLevel" , category = "MSG_CATEGORY_DB_PLAYER", id = 100, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "sid"},
			{type = "int16", name = "level"},
			{type = "int16", name = "opcode"},
		},
	},


    {
		define = "struct", name = "RobbingInfo",
		attributes =
		{
			{type = "int32", name = "owner_id"},
			{type = "string", name = "owner_name"},
			{type = "int32", name = "owner_lvl"},
			{type = "int32", name = "lode_lvl"},
			{type = "int32", name = "lode_index"},
			{type = "int32", name = "robber_id"},
			{type = "string", name = "robber_name"},
			{type = "int32", name = "robber_power"},
			{type = "int32", name = "rob_time"},
			{type = "int32", name = "retake_time"},
			{type = "int32", name = "retake_result"},
		},
	},

	{
		define = "struct", name = "OtherEquipInfoDB",
		attributes =
		{
			{type="int32", name="pos"},
			{type="int32", name="sid"},
			{type="int32", name="iid"},
			{type="int32", name="bind"},
			{type="int32", name="props", vector=true},
		}
	},
	{
		define = "struct", name = "OtherEntityPropDB",
		attributes =
		{
			{type="int32", name="type"},
			{type="int32", name="value"},
		}
	},
	{
		define = "struct", name = "OtherEntityStringPropDB",
		attributes =
		{
			{type="int32", name="type"},
			{type="string", name="value"},
		}
	},
	{
		define = "class", name = "MsgDBLoadPlayerEquipInfo", category = "MSG_CATEGORY_DB_PLAYER", id = 104, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerid"},

			{type = "int32" , name = "pid" },
			{type = "string", name = "name"	},
			{type = "int8",  name = "gender"},
			{type = "int8"	, name = "clazz"},
			{type = "int32"	, name = "reborn"},
			{type = "int32"	, name = "level"},
			{type = "int32"	, name = "cloth"},
			{type = "int32"	, name = "weapon"},
			{type = "int32"	, name = "wings"},
			{type = "string", name = "guild"},
			{type = "int32"	, name = "zhanli"},
			{type = "int32"	, name = "godLevel"},
            {type = "int32"	, name = "enhanceExLevel"},
            {type = "int32"	, name = "soulExLevel"},
            {type = "int32"	, name = "moshiLevel"},
			{type = "int32"	, name = "honor"},
			{type = "int32"	, name = "pkvalue"},
			{type = "int32"	, name = "rebornsoul"},
			{type = "int32", name = "stonepoint"},
			{type = "int32", name = "xiliansuit"},
			{type = "int32", name = "heji"},
			{type = "int32", name = "exMaxLvl"},
            {type = "int32", name = "hide_moguan"},
			{type = "int32", name = "dress_cloth"},
			{type = "int32", name = "vcombat", vector = true},
			{type = "OtherEquipInfoDB", name = "equips", vector = true},
			{type = "OtherEntityPropDB", name = "prop", vector = true},
			{type = "OtherEntityStringPropDB", name = "sprop", vector = true},
		},
	},
	{
		define = "struct", name = "DBOtherItemProp",
		attributes =
		{
			{type="int32", name="idx"},
			{type="int32", name="data"},
		}
	},

	{
		define = "struct", name = "DBOtherPlayerEquip",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="iid"},
			{type="int32", name="pos"},
			{type="string", name="firstowner"},
			{type="string", name="appraiser"},
			{type="DBOtherItemProp", name="props", vector=true},
		}
	},

	{
		define = "struct", name = "DBOtherPlayerSkill",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32", name="level"}
		}
	},

	{
		define = "class", name = "MsgDBLoadOtherPlayerInfo", category = "MSG_CATEGORY_DB_PLAYER", id = 107, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerid"},
			{type = "int32" , name = "pid" },
			{type = "string", name = "name"	},
			{type = "int8",  name = "gender"},
			{type = "int32"	, name = "level"},
			{type = "int64"	, name = "exp"},
			{type = "int32"	, name = "cloth"},
			{type = "int32"	, name = "weapon"},
			{type = "int32"	, name = "wings"},
			{type = "string", name = "guild"},
			{type = "int32"	, name = "zhanli"},
			{type = "int32" , name = "lingwen"},
			{type = "int32" , name = "guildpost"},
			{type = "int32" , name = "job"},
			{type = "int32" , name = "reborn"},
			{type = "int32" , name = "hunhuan"},
			{type = "int32" , name = "jingling"},
			
			{type = "DBOtherPlayerEquip", name = "equips", vector = true},
			{type = "OtherEntityPropDB", name = "prop", vector = true},
			{type = "OtherEntityStringPropDB", name = "sprop", vector = true},
			{type = "DBOtherPlayerSkill", name = "skill", vector = true},
		},
	},
	{
		define = "struct", name = "DBSkillExp",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="exp"},
		}
	},

	{
		define = "class",name = "MsgDBUpdateSomeSkillExp" ,category = "MSG_CATEGORY_DB_PLAYER", id = 108, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "osid"},
			{type = "DBSkillExp", name = "skillinfo",vector = true},
		},
	},
	
	{
		define = "class", name="MsgDBUpdatePlayerClass", category = "MSG_CATEGORY_DB_PLAYER" , id = 109, base = "MessageEx", salt = "pid", 
		attributes =
		{
			{type="int32", name="pid"},
			{type="int32", name="job"},
		},
	},


    	{
		define = "class", name="MsgDBUpdatePlayerGender", category = "MSG_CATEGORY_DB_PLAYER" , id = 110, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type="int32", name="pid", desc="Íæ¼ÒID"},
			{type="int8", name="gender"},
		},
	},
	
	{
		define = "class", name="MsgLoadPlayerBaseInfo", category = "MSG_CATEGORY_DB_PLAYER" , id = 111, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "srcServerid"},			
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
		define = "class" , name = "MsgDBUpdatePlayerAllProp", category = "MSG_CATEGORY_DB_PLAYER", id = 112, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "exData", name = "props", vector = true},
		},
	},
	
	{
		define = "struct", name = "DBEventData",
		attributes =
		{
			{type="int32", name="eid"},
			{type="int32", name="tindex"},
			{type="int32", name="datax"},
			{type="int32", name="datay"},
			{type="int32", name="dataz"},
		}
	},
	
	{
		define = "class" , name = "MsgDBSavePlayerAllEvent", category = "MSG_CATEGORY_DB_PLAYER", id = 113, base = "MessageEx", salt = "pid", send_back=false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBEventData", name = "props", vector = true},
		},
	},	
}

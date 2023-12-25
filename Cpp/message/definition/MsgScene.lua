messages =
{
	{
		define = "class", name= "MsgEnterSceneRequest", category = "MSG_CATEGORY_SCENE", id = "1", base = "Message",canSendToCrossFromCli=true,
		 attributes =
		 {
			{type= "int32", name = "sid"},
			{type= "int16", name = "reason", deault = 0}, -- 0: enter 1: portal, 2: instance, 3:npc 4:monster
		 }
	},

	{
		define = "class", name = "MsgEnterSceneResponse", category = "MSG_CATEGORY_SCENE", id = "6", base = "Message",
		attributes =
		{
			{type= "int16", name = "errcode"},
            {type= "int16", name = "npcfly"},
			{type= "int16", name = "reason"},
		}
	},

	{
		define = "class", name = "MsgPlayerWalkRequest", category = "MSG_CATEGORY_SCENE", id = 11, base = "Message",canSendToCrossFromCli=true,
		attributes =
		 {
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
			{type = "int32", name = "SkipTime"},
		 }
	},

	{
		define = "class", name = "MsgPlayerWalkResponse", category = "MSG_CATEGORY_SCENE", id = 12, base = "Message",
		attributes =
		 {
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
		 }
	},

	{
		define = "class", name = "MsgPlayerRunRequest", category = "MSG_CATEGORY_SCENE", id = 13, base = "Message",canSendToCrossFromCli=true,
		attributes =
		 {
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
			{type = "int32", name = "SkipTime"},
		 }
	},

	{
		define = "class", name = "MsgPlayerRunResponse", category = "MSG_CATEGORY_SCENE", id = 14, base = "Message",
		attributes =
		 {
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
		 }
	},

	{
		define = "class", name = "MsgPlayerMoveNotify", category = "MSG_CATEGORY_SCENE", id =  15, base = "Message",
		attributes =
		{
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
			{type = "int16", name = "movetype"},
		}
	},

	{
		define = "class", name = "MsgEntityMoveNotify", category = "MSG_CATEGORY_SCENE", id = 17, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int16", name = "movetype"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
		},
	},

	{
		define = "class", name = "MsgEntityTurnNotify", category = "MSG_CATEGORY_SCENE", id = 18, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgEntityTurnRequest", category = "MSG_CATEGORY_SCENE", id = 19, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgPlayerUseSkillonPosRequest", category = "MSG_CATEGORY_SCENE", id = 20, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "skillid", dump = true},
			{type = "int32", name = "lvl", dump = true},
			{type = "int16", name = "targetx", dump = true},
			{type = "int16", name = "targety", dump = true},
		},
	},

	{
		define = "class", name = "MsgPlayerUseSkillonEntityRequest", category = "MSG_CATEGORY_SCENE", id = 21, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "skillid", dump = true},
			{type = "int32", name = "lvl", dump = true},
		},
	},

	{
		define = "class", name = "MsgPlayerUseSkillResponse", category = "MSG_CATEGORY_SCENE", id = 22, base = "Message",
		attributes =
		{
			{type = "int32", name = "skillid", dump = true},
			{type = "int16", name = "errcode", dump = true},
		},
	},


	{
		define = "struct", name = "MentalData",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgEntityUseSkillNotify", category = "MSG_CATEGORY_SCENE", id = 23, base = "Message",
		attributes =
		{
			{type = "int32", name = "skillid", },
			{type = "int32", name = "lvl", },
			{type = "int32", name = "eidSrc", },
			{type = "int32", name = "eidTgt", },
			{type = "int32", name = "posx", },
			{type = "int32", name = "posy", }
		},
	},

	{
		define = "class", name = "MsgEntityEffectNotify", category = "MSG_CATEGORY_SCENE", id = 24, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "effect", dump = true},
		},
	},

	{
		define = "class", name = "MsgEntityHpChangeNotify", category = "MSG_CATEGORY_SCENE", id = 25, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "hp", dump = true},
		},
	},

	{
		define = "class", name = "MsgEntityMpChangeNotify", category = "MSG_CATEGORY_SCENE", id = 26, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "mp", dump = true},
		},
	},

	{
		define = "class", name = "MsgEntityHpMpChangeNotify", category = "MSG_CATEGORY_SCENE", id = 27, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "hp", dump = true},
			{type = "int32", name = "mp", dump = true},
		},
	},

	{
		define = "class", name = "MsgEntityEquipChangeNotify", category = "MSG_CATEGORY_SCENE", id = 28, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "type", dump = true},
			{type = "int32", name = "sid", dump = true},
			{type = "int16", name = "status", dump = true},
		},
	},

	{
		define = "class", name = "MsgEntityHpChangeDelayNotify", category = "MSG_CATEGORY_SCENE", id = 30, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid",},
			{type = "int64", name = "hp", },
			{type = "int32", name = "skillId"},
			{type = "int32", name = "flags",},
		},
	},

	{
		define = "class", name = "MsgEntityBeAttackedDelayNotify", category = "MSG_CATEGORY_SCENE", id = 32, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int16", name = "type", dump = true},
			{type = "int16", name = "delay", dump = true},
		},
	},

	{
		define = "class", name = "MsgImBeAttackedDelayNotify", category = "MSG_CATEGORY_SCENE", id = 33, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
		},
	},

	{
		define = "class", name = "MsgEntityBeUsedSkillNotify", category = "MSG_CATEGORY_SCENE", id = 34, base = "Message",
		attributes =
		{
			{type = "int32", name = "skillid"},
			{type = "int32", name = "lvl"},
			{type = "int16", name = "issrc"}, -- issrc = 1  为源
			{type = "int32", name = "eidTgt"},
		},
	},

	{
		define = "class", name = "MsgPlayerMineonPosRequest", category = "MSG_CATEGORY_SCENE", id = 35, base = "Message",
		attributes =
		{
			{type = "int16", name = "mineid", dump = true},
			{type = "int16", name = "targetx", dump = true},
			{type = "int16", name = "targety", dump = true},
		},
	},

	{
		define = "class", name = "MsgPlayerMineonPosResponse", category = "MSG_CATEGORY_SCENE", id = 36, base = "Message",
		attributes =
		{
			{type = "int16", name = "mineid", dump = true},
			{type = "int16", name = "errcode", dump = true},
		},
	},

	{
		define = "struct", name = "MeetExData",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int32", name = "data"},
		},
	},
	{
		define = "struct", name = "MeetExStr",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "string", name = "data"},
		},
	},
	

	{
		define = "class", name = "MsgEntityMaxHPChangeNotify", category = "MSG_CATEGORY_SCENE", id = 38, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},
		},
	},
	
	{
		define = "class", name = "MsgEntityExerChangeNotify", category = "MSG_CATEGORY_SCENE", id = 39, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"		, dump = true},
			{type = "int32", name = "exercise", dump = true},
		},
	},
	
	{
		define = "class", name = "MsgEntityMaxExerChangeNotify", category = "MSG_CATEGORY_SCENE", id = 40, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "maxexer"},
			{type = "int32", name = "exercise"},
		},
	},

	{
		define = "class", name = "MsgMeetEntityExStrNotify", category = "MSG_CATEGORY_SCENE", id =  48, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid" },
			{type = "MeetExStr",name = "exstr", vector= true},
		},
	},

	{
		define = "class", name = "MsgMeetEntityExDataNotify", category = "MSG_CATEGORY_SCENE", id =  49, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid" },
			{type = "MeetExData",name = "exdata", vector= true},
		},
	},


	{
		define = "class", name = "MsgMapByeNotify", category = "MSG_CATEGORY_SCENE", id = 50, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid" , dump = true},
		},
	},

	{
		define = "class", name = "MsgMapMeetPlayerNotify", category = "MSG_CATEGORY_SCENE", id = 51, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "pid"},
			{type = "int16", name = "staticid"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "reborn"},
			{type = "int32", name = "level"},
	

			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},

			{type = "int32", name = "maxmp"},
			{type = "int32", name = "mp"},
			{type = "int32", name = "attackspeed"},

			{type = "string", name = "name"},
			{type = "int32", name= 	"cloth"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "wings"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int32", name = "serverid"},
		    {type = "int32", name = "fabao"},
		    {type = "int16", name = "effectlist",vector = true},
			{type = "int32", name = "hat"},
			{type = "int32", name = "chenghao"},
			{type = "int32", name = "chenghao2"},
			{type = "int32", name = "chenghao3"},
			{type = "int32", name = "chenghao4"},
			{type = "int32", name = "chenghao5"},
			{type = "int32", name = "hunhuan"},
			{type = "int32", name = "jingling"},
			{type = "int16", name = "isMining"},
			{type = "int32", name = "pkstate"},
			{type = "int32", name = "factionid"},
		},
	},

	{
		define = "class", name = "MsgMapMeetMonsterNotify", category = "MSG_CATEGORY_SCENE", id = 52, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "staticid"},
			{type = "string", name = "name"},
			{type = "int64", name = "maxhp"},
			{type = "int64", name = "hp"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int32", name = "status"},
		},
	},

	{
		define = "class", name = "MsgMapMeetNPCNotify", category = "MSG_CATEGORY_SCENE", id = 53, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "staticid"},
			{type = "string", name = "name"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			--{type = "int32", name = "effect"},
			--{type = "int32", name = "speed"},
		},
	},

	{
		define = "class", name = "MsgMapMeetItemNotify", category = "MSG_CATEGORY_SCENE", id = 54, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "staticid"},
			{type = "int32", name = "count"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			--{type = "int32", name = "speed"},
		},
	},

	{
		define = "class", name = "MsgMapMeetSkillNotify", category = "MSG_CATEGORY_SCENE", id = 55, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "staticid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			--{type = "int32", name = "speed"},
		},
	},

	{
		define = "class", name = "MsgMapMeetDogNotify", category = "MSG_CATEGORY_SCENE", id = 56, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "did"},
			{type = "int16", name = "level"},
			{type = "string", name = "name"},
			{type = "int32", name = "ownerpid"},
			{type = "string", name = "ownername"},
			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int32", name = "skillLvl"},
			{type = "int16", name = "ownertype"},
			{type = "int16", name = "subtype"},
		},
	},

	{
		define = "class", name = "MsgMapMeetPetNotify", category = "MSG_CATEGORY_SCENE", id = 58, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "staticid"},
			{type = "string", name = "name"},
			{type = "int32", name = "ownerpid"},
			{type = "string", name = "ownername"},
			{type = "int32", name = "hp"},
			{type = "int32", name = "maxhp"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "level"},
			{type = "int32", name = "reborn"},
			{type = "int32", name = "modelid"},
		},
	},

	{
		define = "class", name = "MsgMapMeetMarsNotify", category = "MSG_CATEGORY_SCENE", id = 59, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "sid"},
			{type = "string", name = "name"},
			{type = "int32", name = "ownerpid"},
			{type = "string", name = "ownername"},
			{type = "int32", name = "hp"},
			{type = "int32", name = "maxhp"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "job"},
			{type = "int16", name = "skill"},
		},
	},

	{
		define = "class", name = "MsgMapSelfEnterNotify", category = "MSG_CATEGORY_SCENE", id = 60, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type= "int32", name="sceneid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgMapSelfLeaveNotify", category = "MSG_CATEGORY_SCENE", id = 61, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type="int16", name="sceneid"},
		},
	},

	{
		define = "class", name = "MsgMapSelfEnterVirtalSceneNotify", category = "MSG_CATEGORY_SCENE", id = 62, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int16", name = "sceneid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgSyncEntityEffectNotify", category = "MSG_CATEGORY_SCENE", id = 65, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "effect"},
		},
	},

	{
		define = "class", name = "MsgSyncEntitySpeedNotify", category = "MSG_CATEGORY_SCENE", id = 66, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "speed"},
		},
	},

	{
		define = "class", name = "MsgSyncEntityLevelNotify", category = "MSG_CATEGORY_SCENE", id = 67, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},
			{type = "int32", name = "maxmp"},
			{type = "int32", name = "mp"},
			{type = "int16", name = "lvl"},
		},
	},

	{
		define = "class", name = "MsgSyncEntityPKStateNotify", category = "MSG_CATEGORY_SCENE", id = 68, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "pkstate"},
		},
	},

	{
		define = "class", name = "MsgSyncEntityTitleNotify", category = "MSG_CATEGORY_SCENE", id = 69, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "title"},
		},
	},

	{
		define = "class", name = "MsgFetchItemRequest", category = "MSG_CATEGORY_SCENE", id = 70, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
		},
	},

	{
		define = "class", name = "MsgFetchItemResponse", category = "MSG_CATEGORY_SCENE", id = 71, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32" , name = "sid"},
			{type = "int32", name = "posx"},
			{type = "int32", name = "posy"},
		},
	},

	{
		define = "class", name = "MsgAbandonItemRequest", category = "MSG_CATEGORY_SCENE", id = 72, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid", dump = true},
			{type = "int32", name = "count", dump = true},
		},
	},

	{
		define = "class", name = "MsgAbandonItemResponse", category = "MSG_CATEGORY_SCENE", id = 73, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "position"},
		},
	},

	{
		define = "class", name = "MsgPickPlantRequest", category = "MSG_CATEGORY_SCENE", id = 74, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
		},
	},

	{
		define = "class", name = "MsgPickPlantResponse", category = "MSG_CATEGORY_SCENE", id = 75, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgReviveEntityRequest", category = "MSG_CATEGORY_SCENE", id = 80, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int16", name = "type"},--0:复活点复活，1:原地复活, 2:定向复活
            {type = "int16", name = "subType"},--原地复活小分类：1 有复活玫瑰；2：没有复活玫瑰
		},
	},

	{
		define = "class", name = "MsgReviveEntityResponse", category = "MSG_CATEGORY_SCENE", id = 81, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "eid"},
			{type="int16", name="sceneid"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
		},
	},

	{
		define = "class", name = "MsgGetSceneEntityInfoRequest", category = "MSG_CATEGORY_SCENE", id = 100, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "eid"},
		},
	},
	
	{
		define = "struct", name = "geneInfo",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "int32", name = "datau"},
			{type = "int32", name = "srcpid"},
			{type = "int32", name = "duration"},
		},
	},
	{
		define = "class", name = "MsgEntityPlayerInfoNotify", category = "MSG_CATEGORY_SCENE", id = 102, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "pid"},
			{type = "string", name = "name", },
			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},
			{type = "int32", name = "maxmp"},
			{type = "int32", name=  "mp"},
			{type = "int32", name = "lvl"},
			{type = "int16", name = "staticid"},
			{type = "int16", name = "gender"},
			{type = "geneInfo", name = "genelist", vector = true},

		},
	},

	
	{
		define="struct", name="SceneLine",
		attributes =
		{
			{type="int16", name="line_id"},
			{type="int16", name="player_count"},
		},
	},

	{
		define="class", name="MsgSceneLineInfoNotify", category="MSG_CATEGORY_SCENE", id=152, base="Message",
		attributes =
		{
			{type="int32", name = "scene_static_id"},
			{type="int32", name = "player_max_per_line"},
			{type="int8", name = "can_choose_line"},
			{type="int8", name = "enable"},
			{type="SceneLine", name="lines", vector=true},
		},
	},

	{
		define="class", name="MsgChooseSceneLineRequest", category="MSG_CATEGORY_SCENE", id=153, base="Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type="int16", name="line_id"},
		},
	},

	{
		define="class", name="MsgChooseSceneLineResponse", category="MSG_CATEGORY_SCENE", id=154, base="Message",
		attributes =
		{
			{type="int16", name="line_id"},
			{type="int16", name="errcode"},
		},
	},

	{
		define = "class", name = "MsgUpdScenePropsNotify", category = "MSG_CATEGORY_SCENE", id = 200, base = "Message",
		attributes =
		{
			{type = "int32", name = "prop"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgUpdSceneStringNotify", category = "MSG_CATEGORY_SCENE", id = 220, base = "Message",
		attributes =
		{
			{type=  "int32", name = "nidx"},
			{type = "string", name = "str",},
		},
	},

	---------------dog option---------------------------
	{
		define = "class", name = "MsgDogOptionRequest", category = "MSG_CATEGORY_SCENE", id = 230, base = "Message",
		attributes =
		{
			{type=  "int32", name = "option"},
			{type=  "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgDogOptionResponse", category = "MSG_CATEGORY_SCENE", id = 231, base = "Message",
		attributes =
		{
			{type=  "int16", name = "errcode"},
		},
	},
    
    {
		define = "class", name = "MsgGoFantianRequest", category = "MSG_CATEGORY_SCENE", id = 233, base = "Message",
		attributes =
		{
			{type=  "int32", name = "mapid"},
		},
	},
    
    {
		define = "class", name = "MsgGoFantianNotify", category = "MSG_CATEGORY_SCENE", id = 234, base = "Message",
		attributes =
		{
			{type=  "int32", name = "mapid"},
            {type=  "int32", name = "type"},
		},
	},
    
    {
		define = "class", name = "MsgSearchPlayerRequest", category = "MSG_CATEGORY_SCENE", id = 240, base = "Message",
		attributes =
		{
			{type=  "int32", name = "pid"},
			{type = "string", name = "name",},
		},
	},
    
    {
		define = "class", name = "MsgSearchPlayerResponse", category = "MSG_CATEGORY_SCENE", id = 241, base = "Message",
		attributes =
		{
			{type=  "int16", name = "errcode"},
			{type=  "int32", name = "pid"},
			{type = "string", name = "name",},
			{type=  "int8", name = "gender"},
			{type=  "int8", name = "job"},
			{type=  "int16", name = "reborn"},
			{type=  "int16", name = "level"},
			{type=  "string", name = "guild"},
            {type = "int32"	, name = "weapon"},
            {type = "int32"	, name = "cloth"},
            {type = "int32"	, name = "wings"},
		},
	},
    
    {
		define = "class", name = "MsgGtclPortalNotify", category = "MSG_CATEGORY_SCENE", id = 245, base = "Message",
		attributes =
		{
			{type = "int32", name = "flag"},				
			{type = "int32", name = "portal_id"},
			{type = "int32", name = "pid"},
			{type = "string", name = "pname"},
			{type = "int32", name = "gid"},
			{type = "string", name = "gname"},
		},
	},

	{
		define = "class", name = "MsgPlayerUseSkillStartRequest", category = "MSG_CATEGORY_SCENE", id = 247, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "skillid", dump = true},
			{type = "int8", name = "isEntity", dump = true},
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "targetx", dump = true},
			{type = "int32", name = "targety", dump = true},
		},
	},

	{
		define = "class", name = "MsgPlayerUseSkillStartResponse", category = "MSG_CATEGORY_SCENE", id = 248, base = "Message",
		attributes =
		{
			{type = "int32", name = "skillid", dump = true},
			{type = "int16", name = "errcode", dump = true},
		},
	},

    {
		define = "class", name = "MsgEntityDressChangeNotify", category = "MSG_CATEGORY_SCENE", id = 249, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "type"},
			{type = "int32", name = "sid"},
		},
	},

	{
		define = "class", name = "MsgMapMeetPlayerCloneNotify", category = "MSG_CATEGORY_SCENE", id = 251, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "did"},
			{type = "int16", name = "level"},
			{type = "string", name = "name"},
			{type = "int32", name = "ownerpid"},
			{type = "string", name = "ownername"},
			{type = "int32", name = "maxhp"},
			{type = "int32", name = "hp"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int32", name = "skillLvl"},
			{type = "int16", name = "ownertype"},
			{type = "int16", name = "gender"},
			{type = "int32", name= 	"cloth"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "hat"},
		},
	},
	{
		define = "class", name = "MsgSyncTitleEffect", category = "MSG_CATEGORY_SCENE", id = 252, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
		},
	},
	
	{
		define="struct", name="BossDetail",
		attributes =
		{
			{type="int32", name="index"},
			{type="int32", name="bossId"},
			{type="int16", name="alive"},
			{type="int32", name="freshTime"},
		},
	},
	
	{
		define = "class", name = "MsgSyncSceneBossInfoNotify", category = "MSG_CATEGORY_SCENE", id = 257, base = "Message",
		attributes =
		 {
			{type="int32", name="sceneId"},
			{type="BossDetail", name="list", vector=true},
		 }
	},
	{
		define = "class", name = "MsgGodWeaponAttackEffectNotify", category = "MSG_CATEGORY_SCENE", id = 259, base = "Message",
		attributes =
		 {
			{type="int32", name="bossId"},
			{type="int32", name="effectType"},
		 }
	},	

	{
		define = "class", name = "MsgMapMeetMinerNotify", category = "MSG_CATEGORY_SCENE", id = 260, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int32", name = "did"},
			{type = "int32", name = "ownerpid"},
			{type = "string", name = "ownername"},
			{type = "int16", name = "dir"},
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "ownertype"},
			{type = "int32", name = "cntdown"},
			{type = "int16", name = "state"},
			{type = "int32", name = "lodeLevel"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "cloth"},
		},
	},

	{
		define = "class", name = "MsgMapMinerSateChangeNotify", category = "MSG_CATEGORY_SCENE", id = 261, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int16", name = "state"},
			{type = "int32", name = "datax"},

		},
	},

	{
		define = "class", name = "MsgBossRefreshWarnNotify", category = "MSG_CATEGORY_SCENE", id = 262, base = "Message",
		attributes =
		 {
			{type="int32", name="bossId"},
		 }
	},	
	{
		define = "class", name = "MsgPetRunRequest", category = "MSG_CATEGORY_SCENE", id = 263, base = "Message",canSendToCrossFromCli=true,
		attributes =
		 {
			{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
			{type = "int32", name = "SkipTime"},
		 }
	},

	{
		define = "class", name = "MsgPetRunResponse", category = "MSG_CATEGORY_SCENE", id = 264, base = "Message",
		attributes =
		 {
			{type = "int16", name = "success" },
		 	{type = "int16", name = "dir" },
			{type = "int16", name = "posx"},
			{type = "int16", name = "posy"},
			{type = "int16", name = "mMoveStep"},
		 }
	},
	{
		define = "class", name = "MsgPetFetchItemRequest", category = "MSG_CATEGORY_SCENE", id = 265, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
		},
	},

	{
		define = "class", name = "MsgPetFetchItemResponse", category = "MSG_CATEGORY_SCENE", id = 266, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32" , name = "sid"},
			{type = "int32", name = "posx"},
			{type = "int32", name = "posy"},
		},
	},


	{
		define = "class", name = "MsgEntityMonsterInfoNotify", category = "MSG_CATEGORY_SCENE", id = 267, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int16", name = "staticid"},
			{type = "geneInfo", name = "genelist", vector = true},
		},
	},
	
	{
		define = "class", name = "MsgEntityReviveNotify", category = "MSG_CATEGORY_SCENE", id = 268, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid",},
			{type = "int32", name = "flags",},
		},
	},

    {
		define = "class", name = "MsgFabaoSkillNotify", category = "MSG_CATEGORY_SCENE", id = 269, base = "Message",
		attributes =
		{
			{type = "int32", name = "skillid", },
			{type = "int32", name = "eid", },
			{type = "int32", name = "dposx", },
			{type = "int32", name = "dposy", },
		},
	},

	{
		define = "class", name = "MsgEntityComponetEffectNotify", category = "MSG_CATEGORY_SCENE", id = 272, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid", dump = true},
			{type = "int16", name = "effectlist",  vector = true},
		},
	},

	{
		define = "class", name = "MsgSyncMonsterBloodStatusNotify", category = "MSG_CATEGORY_SCENE", id = 274, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "percent"},
			{type = "int32", name = "status"},
		},
	},


	{
		define = "class", name = "MsgEntityMiningRequest", category = "MSG_CATEGORY_SCENE", id = 275, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgEntityMiningNotify", category = "MSG_CATEGORY_SCENE", id = 276, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int16", name = "dir"},
		},
	},

	{
		define = "class", name = "MsgEntityPropChangeNotify", category = "MSG_CATEGORY_SCENE", id = 277, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
			{type = "int32", name = "propid"},
			{type = "int32", name = "data"},
		},
	}

}

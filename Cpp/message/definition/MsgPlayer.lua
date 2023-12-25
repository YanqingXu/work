messages =
{
	{
		define = "struct", name = "SkillInfo",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="lvl"},
		}
	},
	
	{
		define = "struct", name = "GeneInfo",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "duration"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		}
	},

	{
		define = "class", name = "MsgUpdPlayerBaseNotify", category = "MSG_CATEGORY_PLAYER", id = 6, base = "Message",
		attributes =
		{
			{type = "string", name = "mName"},
			{type = "int32", name = "mPid"},
			{type = "int8", name = "mJob"},
			{type = "int8", name = "mGender"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "wing"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "hat"},
			{type = "int32", name = "chenghao"},
			{type = "int32", name = "chenghao2"},
			{type = "int32", name = "chenghao3"},
			{type = "int32", name = "chenghao4"},
			{type = "int32", name = "chenghao5"},
			{type = "int32", name = "jingling"},
			{type = "int32", name = "hunhuan"},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerCombatDataAllNotify", category = "MSG_CATEGORY_PLAYER", id = 7, base = "Message",
		attributes =
		{
			{type = "int32", name ="combatdata", vector = true},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerCombatDataNotify", category = "MSG_CATEGORY_PLAYER", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "int16", name = "type"},
			{type = "int32", name = "data"},
		},
	},


	{
		define = "class", name = "MsgUpdPlayerPropsDataRequest", category = "MSG_CATEGORY_PLAYER", id = 12, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "int16", name = "type"},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerPropsDataNotify", category = "MSG_CATEGORY_PLAYER", id = 13, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "int16", name = "type"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerSkillDataNotify", category = "MSG_CATEGORY_PLAYER", id = 14, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "SkillInfo", name ="skilldata", vector = true},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerLvlExpNotify", category = "MSG_CATEGORY_PLAYER", id = 15, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "int64", name = "mExperience"},
			{type = "int64", name = "mExperienceNext"},
			{type = "int16", name = "mLevel"},
			{type = "int32", name = "oldlvl"},

		}
	},

	{
		define = "class", name = "MsgUpdPlayerHPNotify", category = "MSG_CATEGORY_PLAYER", id = 29, base = "Message",
		attributes =
		{
			{type = "int32", name = "hp"},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerMPNotify", category = "MSG_CATEGORY_PLAYER", id = 28, base = "Message",
		attributes =
		{
			{type = "int32", name = "mp"},
		},
	},

	{
		define = "class", name = "MsgUpdPlayerDetailNotify", category = "MSG_CATEGORY_PLAYER", id = "30", base = "Message",
		attributes =
		{
			{type = "int16",   name = "bagslot"},
			{type = "int16",   name = "storeslot"},
			{type = "int32",   name = "lingfu"},
			{type = "int64",   name = "ingot"},
			{type = "int32",   name = "boundlingfu"},
			{type = "int64",   name = "boundingot"},
		}
	},

	{
		define = "class", name = "MsgUpdPlayerCapitalNotify", category = "MSG_CATEGORY_PLAYER", id = 35, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "type"},
			{type = "int64",   name = "oldcount"},
			{type = "int64",   name = "newcount"},
		}
	},

	{
		define = "class", name = "MsgUpdPlayerHonorNotify", category = "MSG_CATEGORY_PLAYER", id = "39", base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "honor"},
		}
	},
    
    {
		define = "class", name = "MsgUpdPlayerGongxunNotify", category = "MSG_CATEGORY_PLAYER", id = 40, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "gongxun"},
		}
	},
    
    {
		define = "class", name = "MsgUpdPlayerMohunNotify", category = "MSG_CATEGORY_PLAYER", id = 41, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "mohun"},
		}
	},

    
    {
		define = "class", name = "MsgUpdPlayerHudunNotify", category = "MSG_CATEGORY_PLAYER", id = 42, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "hudun"},
		}
	},
	
	{
		define = "class", name = "MsgUpdPlayerBsscNotify", category = "MSG_CATEGORY_PLAYER", id = "43", base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "bssc"},
		}
	},


	{
		define = "class", name = "MsgAddSkillNotify", category = "MSG_CATEGORY_PLAYER", id = 61, base = "Message",
		attributes =
		{
			{type = "int16", name="opcode"},
			{type = "int32", name="sid"},
			{type = "int32", name="lvl"},
		},
	},

	{
		define = "class", name = "MsgRmvSkillNotify", category = "MSG_CATEGORY_PLAYER", id = 63, base = "Message",
		attributes =
		{
			{type = "int16",   name = "opcode"},
			{type = "int32",   name = "sid"},
		},
	},

	{
		define = "class", name = "MsgUpdSkillExpNotify", category = "MSG_CATEGORY_PLAYER", id = 65, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "sid"},
			{type = "int32",   name = "exp"},
		},
	},

	{
		define = "class", name = "MsgUpdSkillCoolDownNotify", category = "MSG_CATEGORY_PLAYER", id = 66, base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "cooldown"},
		},
	},

	{
		--��ȡ���߾�������
		define = "class", name = "MsgGetOfflineExpRequest", category = "MSG_CATEGORY_PLAYER", id = 98, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
		},
	},

	{
		--��ȡ���߾���Ӧ��
		define = "class", name = "MsgGetOfflineExpResponse", category = "MSG_CATEGORY_PLAYER", id = 99, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSpecialQuestCountResponse", category = "MSG_CATEGORY_PLAYER", id = 100, base = "Message",
		attributes =
		{
			{type = "int16", name = "qtype"},
			{type = "int16", name = "count"},
		},
	},
	
	{
		define = "class", name = "MsgPlayerSyncAllGeneNotify", category = "MSG_CATEGORY_PLAYER", id = 149, base = "Message",
		attributes =
		{
			{type = "GeneInfo", name = "genes", vector = true},
		},
	},

	{
		define = "class", name = "MsgPlayerUpdGeneNotify", category = "MSG_CATEGORY_PLAYER", id = 150, base = "Message",
		attributes =
		{
			{type = "int32", name = "gid"},
			{type = "int32", name = "duration"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
 	},

	{
		define = "class", name = "MsgPlayerRmvGeneNotify", category = "MSG_CATEGORY_PLAYER", id = 151, base = "Message",
		attributes =
		{
			{type = "int32", name = "gid"},
		},
	},

	{
		define = "class", name = "MsgSetPlayerPkModeRequest", category = "MSG_CATEGORY_PLAYER", id = 160, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "pkmode"},
		},
	},

	{
		define = "class", name = "MsgSetPlayerPkModeResponse", category = "MSG_CATEGORY_PLAYER", id = 161, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
    {
		define = "class", name = "MsgSyncPlayerStringPropNotify", category = "MSG_CATEGORY_PLAYER", id = 164, base = "Message",
		attributes =
		{
			{type = "int32", name = "keyid"},
			{type = "string", name = "data"},
		},
	},

	{
		define = "struct", name = "chatPlayerProp",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "value"},
		},
	
	},

	{
		define = "class", name = "MsgChatNotify", category = "MSG_CATEGORY_PLAYER", id = 200, base = "Message",
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
            {type = "chatPlayerProp", name = "props", vector = true},
		},
	},

	{
		define = "class", name = "MsgChatRequest", category = "MSG_CATEGORY_PLAYER", id = 201, base = "Message",
		attributes =
		{
			{type = "int16", name = "chatType"},
			{type = "int32", name = "partnerPid"},
			{type = "string", name = "chatText"},
		},
	},

	{
		define = "class", name = "MsgChatResponse", category = "MSG_CATEGORY_PLAYER", id = 202, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgExchangeRebornPointsRequest", category = "MSG_CATEGORY_PLAYER", id = 227, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgExchangeRebornPointsResponse", category = "MSG_CATEGORY_PLAYER", id = 228, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgRebornRequest", category = "MSG_CATEGORY_PLAYER", id = 229, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgRebornResponse", category = "MSG_CATEGORY_PLAYER", id = 230, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSamsaraRequest", category = "MSG_CATEGORY_PLAYER", id = 231, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgSamsaraResponse", category = "MSG_CATEGORY_PLAYER", id = 232, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgExchangeSamsaraPointsRequest", category = "MSG_CATEGORY_PLAYER", id = 233, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgExchangeSamsaraPointsResponse", category = "MSG_CATEGORY_PLAYER", id = 234, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSyncPlayerEventDataNotify", category = "MSG_CATEGORY_PLAYER", id = 250, base = "Message",
		attributes =
		{
			{type = "int32", name = "eventid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
		},
	},

	{
		define = "class", name = "MsgSyncPlayerEventDataRequest", category = "MSG_CATEGORY_PLAYER", id = 251, base = "Message",
		attributes =
		{
			{type = "int32", name = "eventid"},
		},
	},

	{
		define = "class", name = "MsgSyncPlayerEventDataResponse", category = "MSG_CATEGORY_PLAYER", id = 252, base = "Message",
		attributes =
		{
			{type = "int32", name = "eventid"},
			{type = "int32", name = "moredata", vector = true},
		},
	},

	{
		define = "class", name = "MsgPlayerDeadInfoNotify", category = "MSG_CATEGORY_PLAYER", id = 280, base = "Message",
		attributes =
		{
			{type = "int16", name = "killertype"},
			{type = "int32", name = "killsid"},
			{type = "string", name = "killname"},
		},
	},

	{
		define = "class", name = "MsgGetOtherPlayerDataRequest", category = "MSG_CATEGORY_PLAYER", id = 300, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgGetOtherPlayerDataResponse", category = "MSG_CATEGORY_PLAYER" , id = 301, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSyncOtherPlayerDataNotify", category = "MSG_CATEGORY_PLAYER", id = 302, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "string", name = "name"},
			{type = "int16", name = "gender"},
			{type = "int16", name = "job"},
			{type = "int16", name = "lvl" },
			{type = "int16", name = "reborn" },
			{type = "int32", name = "honor"},
			{type = "int32", name = "pkvalue"},
			{type = "int32", name = "combatdatanum"},
			{type = "int32", name = "combatdata", vector = true},
		},
	},

	{
		define = "class", name = "MsgGetGiftRequest", category = "MSG_CATEGORY_PLAYER", id = 330, base = "Message",
		attributes =
		{
			{type = "int16", name = "GiftCate"},
			{type = "int16", name = "GiftType"},
		},
	},

	{
		define = "class", name = "MsgGetGiftResponse", category = "MSG_CATEGORY_PLAYER", id = 331, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "GiftCate"},
			{type = "int16", name = "GiftType"},
		},
	},

	{
		define = "class", name = "MsgFuncDataNotify", category = "MSG_CATEGORY_PLAYER", id = 342, base = "Message",
		attributes =
		{
			{type = "int16", name = "funcid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name = "MsgFuncDataOperatorRequest", category = "MSG_CATEGORY_PLAYER", id = 343, base = "Message",
		attributes =
		{
			{type = "int16", name = "funcid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},
	
	{
		define = "class", name = "MsgFuncDataOperatorResponse", category = "MSG_CATEGORY_PLAYER", id = 344, base = "Message",
		attributes =
		{
			{type = "int16", name = "funcid"},
			{type = "int16", name = "errcode"},			
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},
	
	{
		define = "class", name = "MsgOpenHeadTitleRequest", category = "MSG_CATEGORY_PLAYER", id = 350, base = "Message",
		attributes =
		{
			{type = "int16", name = "idx"},
		},
	},
	
	{
		define = "class", name = "MsgCloseHeadTitleRequest", category = "MSG_CATEGORY_PLAYER", id = 351, base = "Message",
		attributes =
		{
			{type = "int16", name = "idx"},			
		},
	},
	
	{
		define = "class", name = "MsgHeadTitleOperationResponse", category = "MSG_CATEGORY_PLAYER", id = 352, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},			
		},
	},
	
	{
		define = "class", name = "MsgRenameRequest", category = "MSG_CATEGORY_PLAYER", id = 360, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "string", name = "newname"},
			{type = "int16", name = "flags"},
		},
	},
	
	{
		define = "class", name = "MsgRenameResponse", category = "MSG_CATEGORY_PLAYER", id = 361, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},		
			{type = "int16", name = "type"},			
		},
	},
	
	{
		define = "struct", name = "OtherEquipInfo",
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
		define = "class", name = "MsgCheckEquipRequest", category = "MSG_CATEGORY_PLAYER", id = 370, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32"	, name = "pid"		},
			{type = "int32"	, name = "serverid"		},
		},
	},

	{
		define = "struct", name = "OtherEntityProp",
		attributes =
		{
			{type="int32", name="type"},
			{type="int32", name="value"},
		}
	},
	
	{
		define = "struct", name = "OtherEntityStringProp",
		attributes =
		{
			{type="int32", name="type"},
			{type="string", name="value"},
		}
	},

	{
		define = "class", name = "MsgCheckEquipResponse", category = "MSG_CATEGORY_PLAYER", id = 371, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			
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
			{type = "OtherEquipInfo", name = "equips", vector = true},
			{type = "OtherEntityProp", name = "prop", vector = true},
			{type = "OtherEntityStringProp", name = "sprop", vector = true},
			
		},
	},
	
	{
		define = "class", name = "MsgCheckSoulStoneRequest", category = "MSG_CATEGORY_PLAYER", id = 372, base = "Message",
		attributes =
		{
			{type = "int32"	, name = "pid"		},
			{type = "int32"	, name = "pos"		},
		},
	},
	
	{
		define = "class", name = "MsgCheckSoulStoneResponse", category = "MSG_CATEGORY_PLAYER", id = 373, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			
			{type = "int32"	, name = "pid"		},
			{type = "int32"	, name = "pos"		},
			{type = "int32", name = "vsoul", vector = true},
		},
	},

	{
		define = "class", name = "MsgEventDataRequest", category = "MSG_CATEGORY_PLAYER", id = 374, base = "Message",
		attributes =
		{
			{type = "int32"	, name = "id"		},
		},
	},

	{
		define = "class", name = "MsgShutUpRequest", category = "MSG_CATEGORY_PLAYER", id = 384, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgShutUpResponse", category = "MSG_CATEGORY_PLAYER", id = 385, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgExerciseRequest", category = "MSG_CATEGORY_PLAYER", id = 386, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgExerciseResponse", category = "MSG_CATEGORY_PLAYER", id = 387, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "level"},
			{type = "int64", name = "curExercise"},
		},
	},
	
	{
		define = "class", name = "MsgExerciseUpdataRequest", category = "MSG_CATEGORY_PLAYER", id = 388, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgExerciseUpdataResponse", category = "MSG_CATEGORY_PLAYER", id = 389, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "level"},
			{type = "int64", name = "curExercise"},
		},
	},
	
	{
		define = "class", name = "MsgExerciseNotify", category = "MSG_CATEGORY_PLAYER", id = 390, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "int64", name = "data"},
		},
	},
	
	{
		define = "class", name = "MsgOpenWingsRequest", category = "MSG_CATEGORY_PLAYER", id = 410, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgUpdataWingsRequest", category = "MSG_CATEGORY_PLAYER", id = 412, base = "Message",
		attributes =
		{

		},
	},
	
	{
		define = "class", name = "MsgUpdataWingsResponse", category = "MSG_CATEGORY_PLAYER", id = 413, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgUpdataBossScoreRequest", category = "MSG_CATEGORY_PLAYER", id = 416, base = "Message",
		attributes =
		{
			{type = "int16", name = "level"	  },
		},
	},
	
	{
		define = "class", name = "MsgUpdataBossScoreResponse", category = "MSG_CATEGORY_PLAYER", id = 417, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgUpdataBsscCnRequest", category = "MSG_CATEGORY_PLAYER", id = 418, base = "Message",
		attributes =
		{
		},
	},
	
	{
		define = "class", name = "MsgUpdataBsscCnResponse", category = "MSG_CATEGORY_PLAYER", id = 419, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgOpenAutoAtkMapRequest", category = "MSG_CATEGORY_PLAYER", id = 420, base = "Message",
		attributes =
		{
			{type = "int32", name = "sceneId"},
		},
	},
	
	{
		define = "class", name = "MsgOpenAutoAtkMapResponse", category = "MSG_CATEGORY_PLAYER", id = 421, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},
	
	{
		define = "class", name = "MsgGetVipExpBuffRequest", category = "MSG_CATEGORY_PLAYER", id = 422, base = "Message",
		attributes =
		{
			
		},
	},
	
	{
		define = "class", name = "MsgGetVipExpBuffResponse", category = "MSG_CATEGORY_PLAYER", id = 423, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},

	{
		define = "class", name = "MsgOfflineTakeRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 426, base = "Message",
		attributes =
		{
			
		},
		
	},
	
	{
		define = "class", name = "MsgOfflineTakeRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 427, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},
	
	{
		define = "class", name = "MsgOfflineVipRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 428, base = "Message",
		attributes =
		{
			
		},
		
	},
	
	{
		define = "class", name = "MsgOfflineVipRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 429, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},
	
	{
		define = "struct", name = "OfflineItem",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="count"},
		}
	},
	
	{
		define = "class", name = "MsgOfflineExpOtherNotify", category = "MSG_CATEGORY_PLAYER", id = 431, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "OfflineItem", name ="offItem", vector = true},
		},
		
	},
	
	{
		define = "class", name = "MsgStartOffLineRequest", category = "MSG_CATEGORY_PLAYER", id = 432, base = "Message",
		attributes =
		{
			{type = "int32", name = "sid"},
		},
		
	},
	
	{
		define = "class", name = "MsgStartOffLineResponse", category = "MSG_CATEGORY_PLAYER", id = 433, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "sid"},
		},
		
	},
	
	{
		define = "class", name = "MsgOpenOffLineRequest", category = "MSG_CATEGORY_PLAYER", id = 434, base = "Message",
		attributes =
		{
		},
		
	},
	
	{
		define = "class", name = "MsgOpenOffLineResponse", category = "MSG_CATEGORY_PLAYER", id = 435, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "swit"},
			{type = "int32", name = "offtime"},
			{type = "OfflineItem", name ="offItem", vector = true},
		},
		
	},
	
	{
		define = "class", name = "MsgCloseOffLineRequest", category = "MSG_CATEGORY_PLAYER", id = 436, base = "Message",
		attributes =
		{
		},
		
	},
	
	{
		define = "class", name = "MsgCloseOffLineResponse", category = "MSG_CATEGORY_PLAYER", id = 437, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
		
	},
	
	{
		define = "class", name = "MsgOfflineExpGeneNotify", category = "MSG_CATEGORY_PLAYER", id = 439, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "OfflineItem", name ="offItem", vector = true},
		},
		
	},
		
	{
		define = "class", name = "MsgRefreshEventDataRequest", category = "MSG_CATEGORY_PLAYER", id = 440, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
		},
		
	},
	
	{
		define = "class", name = "MsgRefreshEventDataResponse", category = "MSG_CATEGORY_PLAYER", id = 441, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
		
	},

    {
		define = "struct", name = "Damage",
		attributes =
		{
			{type="int32", name="pid"},
            {type="int16", name="level"},
			{type="int16", name="job"},
            {type="int16", name="gender"},
            {type="int32", name="damage"},
            {type="string", name="name"},
		}
	},

    {
		define = "class", name = "MsgAttackDamageListNotify", category = "MSG_CATEGORY_PLAYER", id = 442, base = "Message",
		attributes =
		{
            {type = "Damage", name ="DamageList", vector = true},
		},
		
	},

	{
		define = "class", name = "MsgStoryStartNotify", category = "MSG_CATEGORY_PLAYER", id = 443, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
            {type = "int32", name ="storyId" },
		},
		
	},

    {
		define = "class", name = "MsgGetLevelRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 444, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
		
	},
	
	{
		define = "class", name = "MsgGetLevelRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 445, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "id"},
		},
		
	},

    {
		define = "class", name = "MsgGetUpgradeGiftRequest", category = "MSG_CATEGORY_PLAYER", id = 446, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
		
	},
	
	{
		define = "class", name = "MsgNotifyReward", category = "MSG_CATEGORY_PLAYER", id = 450, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "type"},
			{type = "int32",   name = "value"},
		}
		
	},

	{
		define = "class", name = "MsgOpenSpecialRingRequest", category = "MSG_CATEGORY_PLAYER", id = 451, base = "Message",
		attributes =
		{
			{type = "int32",   name = "index"},
		}
		
	},
	{
		define = "class", name = "MsgOpenSpecialRingResponse", category = "MSG_CATEGORY_PLAYER", id = 452, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
			{type = "int32",   name = "index"},
		}
		
	},
	{
		define = "class", name = "MsgCheckOnAutoPickMoney", category = "MSG_CATEGORY_PLAYER", id = 453, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
		}
		
	},
	
	{
		define = "class", name = "MsgAskForRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 454, base = "Message",
		attributes =
		{
		}
		
	},
	
	{
		define = "class", name = "MsgTTSYGuWuRequest", category = "MSG_CATEGORY_PLAYER", id = 455, base = "Message",
		attributes =
		{
			{type = "int32",   name = "index"},
		}
		
	},
	
	{
		define = "class", name = "MsgTTSYGuWuResponse", category = "MSG_CATEGORY_PLAYER", id = 456, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
			{type = "int32",   name = "index"},
		}
		
	},

	{
		define = "class", name = "MsgPlayerLvChangeCultRequest", category = "MSG_CATEGORY_PLAYER", id = 457, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgPlayerLvChangeCultResponse", category = "MSG_CATEGORY_PLAYER", id = 458, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgEnhancePosRequest", category = "MSG_CATEGORY_PLAYER", id = 459, base = "Message",
		attributes =
		{
			{type = "int32",   name = "type"},
			{type = "int32",   name = "pos"},
		},
	},
	{
		define = "class", name = "MsgEnhancePosResponse", category = "MSG_CATEGORY_PLAYER", id = 460, base = "Message",
		attributes =
		{
			{type = "int32",   name = "type"},
			{type = "int32",   name = "pos"},
			{type = "int16", name = "errcode"},
		},
	},

    {
		define = "struct", name = "dress",
		attributes =
		{
			{type = "int32", name = "dressid"},
			{type = "int32", name = "status"},
			{type = "int32", name = "etime"},
			{type = "int32", name = "lvl"},
		}
	},

    {
		define = "class", name = "MsgPlayerAllDressNotify", category = "MSG_CATEGORY_PLAYER", id = 461, base = "Message",
		attributes =
		{
            {type = "dress", name ="DressList", vector = true},
		},
	},

     {
		define = "class", name = "MsgPlayerDressStatusNotify", category = "MSG_CATEGORY_PLAYER", id = 462, base = "Message",
		attributes =
		{
            {type = "int32", name = "dressid"},
			{type = "int32", name = "status"},
			{type = "int32", name = "etime"},
			{type = "int32", name = "lvl"},
		},
	},

    {
		define = "class", name = "MsgPlayerDressAddNotify", category = "MSG_CATEGORY_PLAYER", id = 463, base = "Message",
		attributes =
		{
            {type = "int32", name = "dressid"},
			{type = "int32", name = "status"},
            {type = "int32", name = "etime"},
			{type = "int32", name = "lvl"},
		},
	},

    {
		define = "class", name = "MsgPlayerDressOperatorRequest", category = "MSG_CATEGORY_PLAYER", id = 464, base = "Message",
		attributes =
		{
            {type = "int16",   name = "op", desc = "1 ���� 2 ����"},
			{type = "int16",   name = "type"},
			{type = "int32",   name = "id"},
		},
	},

    {
		define = "class", name = "MsgPlayerDressOperatorResponse", category = "MSG_CATEGORY_PLAYER", id = 465, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "������"},
            {type = "int16",   name = "op", desc = "1 ���� 2 ����"},
            {type = "int32",   name = "id"},
		},
	},


	{
		define = "class", name = "MsgExchangeSkillBookRequest", category = "MSG_CATEGORY_PLAYER", id = 466, base = "Message",
		attributes =
		{
			{type = "int16", name = "exchageType"},
			{type = "int32", name = "exchageId"},
		},
	},

	{
		define = "class", name = "MsgExchangeSkillBookResponse", category = "MSG_CATEGORY_PLAYER", id = 467, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "exchageType"},
			{type = "int16", name = "exchageId"},
		},
	},

	{
		define = "class", name = "MsgStonePosRequest", category = "MSG_CATEGORY_PLAYER", id = 470, base = "Message",
		attributes =
		{
			{type = "int32",   name = "partpos"},
			{type = "int32",   name = "stonepos"},
			{type = "int32",   name = "typeId"},
		},
	},
	{
		define = "class", name = "MsgStonePosResponse", category = "MSG_CATEGORY_PLAYER", id = 471, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32",   name = "partpos"},
			{type = "int32",   name = "stonepos"},
		},
	},
	
	{
		define = "class", name = "MsgUpdateCSRequest", category = "MSG_CATEGORY_PLAYER", id = 473, base = "Message",
		attributes =
		{
			{type = "int32",   name = "pos"},
			{type = "int32",   name = "typeId"},
		},
	},
	
	{
		define = "class", name = "MsgUpdateCSResponse", category = "MSG_CATEGORY_PLAYER", id = 474, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32",   name = "pos"},
			{type = "int32",   name = "typeId"},
			
		},
	},

    {
		define = "class", name = "MsgSetDressStatusRequest", category = "MSG_CATEGORY_PLAYER", id = 475, base = "Message",
		attributes =
		{
			{type = "int32",   name = "status", desc = "0 ���� 1 ��ʾ"},
		},
	},

    {
		define = "class", name = "MsgSetDressStatusResponse", category = "MSG_CATEGORY_PLAYER", id = 476, base = "Message",
		attributes =
		{
			{type = "int16",    name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgVipServiceShowCheckRequest", category = "MSG_CATEGORY_PLAYER", id = 479, base = "Message",
		attributes =
		{
			{type = "int32",   name = "showflag"},
		},
	},

	{
		define = "class", name = "MsgNearbyPlayerRequest", category = "MSG_CATEGORY_PLAYER", id = 480, base = "Message",
		attributes =
		{

		},	
	},

	{
		define = "struct", name = "NearPlayerInfo",
		attributes =
		{
			{type = "int32" , name = "pid" },
			{type = "string", name = "name"},
			{type = "int32"	, name = "level"},
			{type = "int32"	, name = "reborn"},
			{type = "int32"	, name = "distance"},

		},
	},
	
	{
		define = "class", name = "MsgNearbyPlayerResponse", category = "MSG_CATEGORY_PLAYER", id =  481, base = "Message",
		attributes =
		{
				{type = "NearPlayerInfo",name = "playerlist", vector= true},
		},
	},
	{
		define = "class", name = "MsgNearbyPlayerCheckRequest", category = "MSG_CATEGORY_PLAYER", id = 482, base = "Message",
		attributes =
		{
			{type=  "int32", name = "pid"},
		},	
	},
	{
		define = "class", name = "MsgNearbyCheckPlayerResponse", category = "MSG_CATEGORY_PLAYER", id =  483, base = "Message",
		attributes =
		{
			{type = "int32", name = "repcode"},
			{type = "int32", name = "reppid"},
		},
	},

	{
		define = "class", name = "MsgCreateRoleCodeInfoRequest", category = "MSG_CATEGORY_PLAYER", id = 484, base = "Message",
		attributes =
		{
		},
		
	},
	{
		define = "class", name = "MsgCreateRoleCodeInfoResponse", category = "MSG_CATEGORY_PLAYER", id = 485, base = "Message",
		attributes =
		{
			{type = "int32", name = "count"},
			{type = "string", name = "code"},
		},
	},
	
	{
		define = "class", name = "MsgCreateRoleCodeRequest", category = "MSG_CATEGORY_PLAYER", id = 486, base = "Message",
		attributes =
		{
		},
		
	},
	
	{
		define = "class", name = "MsgCreateRoleCodeResponse", category = "MSG_CATEGORY_PLAYER", id = 487, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "string", name = "code"},
		},
	},

	{
		define = "class", name = "MsgGetMasterRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 499, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},

	{
		define = "class", name = "MsgGetMasterRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 500, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgOpenPrivilegeRequest", category = "MSG_CATEGORY_PLAYER", id = 501, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},

	{
		define = "class", name = "MsgOpenPrivilegeResponse", category = "MSG_CATEGORY_PLAYER", id = 502, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGetPrivilegeRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 504, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},
	{
		define = "class", name = "MsgGetPrivilegeRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 505, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgRenewPrivilegeRequest", category = "MSG_CATEGORY_PLAYER", id = 506, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},

	{
		define = "class", name = "MsgRenewPrivilegeResponse", category = "MSG_CATEGORY_PLAYER", id = 507, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgUpdateXSRWTaskStateRequest", category = "MSG_CATEGORY_PLAYER", id = 508, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgUpdateXSRWTaskStateResponse", category = "MSG_CATEGORY_PLAYER", id = 509, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgOnChallengeTowerRequest", category = "MSG_CATEGORY_PLAYER", id = 510, base = "Message",
		attributes =
		{
			{type = "int16", name = "index"},
		},
	},

	{
		define = "class", name = "MsgOnChallengeTowerResponse", category = "MSG_CATEGORY_PLAYER", id = 511, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgGetTowerRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 512, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgBuyDailyItemRequest", category = "MSG_CATEGORY_PLAYER", id = 513, base = "Message",
		attributes =
		{
			{type = "int16", name = "bigindex"},
			{type = "int16", name = "smallindex"},
		},
	},
	{
		define = "class", name = "MsgBuyDailyItemResponse", category = "MSG_CATEGORY_PLAYER", id = 514, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

    {
		define = "class", name = "MsgCalcMyBossTimesRequest", category = "MSG_CATEGORY_PLAYER", id = 515, base = "Message",
		attributes =
		{
            {type = "int32", name = "eventid"},
		},
	},

	{
		define = "class", name = "MsgCalcMyBossTimesResponse", category = "MSG_CATEGORY_PLAYER", id = 516, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgGetTowerSweepRequest", category = "MSG_CATEGORY_PLAYER", id = 517, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgGetTowerSweepResponse", category = "MSG_CATEGORY_PLAYER", id = 518, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
        define = "class", name = "MsgBossBoxDigRequest", category = "MSG_CATEGORY_PLAYER", id = 519, base = "Message",
        attributes =
        {
            {type = "int32", name = "eid"},
        },
    },
    
    {
        define = "class", name = "MsgBossBoxDigResponse", category = "MSG_CATEGORY_PLAYER", id = 520, base = "Message",
        attributes =
        {
            {type = "int16", name = "errcode"},
        },
    },
	
	{
		define = "class", name = "MsgUpdateShopGuideRequest", category = "MSG_CATEGORY_PLAYER", id = 521, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgUpdateShopGuideResponse", category = "MSG_CATEGORY_PLAYER", id = 522, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
    {
		define = "class", name = "MsgStoneTransNpcNotify", category = "MSG_CATEGORY_PLAYER", id = 523, base = "Message",
		attributes =
		{
            {type = "int32", name = "npcid"},
		},
	},
	
	{
		define = "class", name = "MsgBossScoreAddNotify", category = "MSG_CATEGORY_PLAYER", id = 526, base = "Message",
		attributes =
		{
			{type = "int32"	, name = "data"},
			{type = "int32"	, name = "typeId"},
		},
	},

     {
		-- ��������
		define = "class", name = "MsgBailRequest", category = "MSG_CATEGORY_PLAYER", id = 527, base = "Message",
		attributes =
		{
			{type = "int16", name = "money_type"},
		},
	},

     {
		-- ��������
		define = "class", name = "MsgBailResponse", category = "MSG_CATEGORY_PLAYER", id = 528, base = "Message",
		attributes =
		{
			{type = "int16", name = "sub_type"},
			{type = "int16", name = "errcode"},
		},
	},

    --װ���ϳ�Iconͼ��װ���仯����
    {
		define = "class", name = "MsgUpdateComposeStateRequest", category = "MSG_CATEGORY_PLAYER", id = 529, base = "Message",
		attributes =
		{
			{type = "int16", name = "mode"},
		},
	},

	{
		define = "class", name = "MsgMRDTTimuRequest", category = "MSG_CATEGORY_PLAYER", id = 530, base = "Message",
		attributes =
		{
		},
		
	},

	{
		define = "class", name = "MsgMRDTTimuResponse", category = "MSG_CATEGORY_PLAYER", id = 531, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int8", name = "id"},
			{type = "int32", name = "startTime"},
			{type = "int8", name = "curIndex"},
			{type = "int8", name = "curRight"},
		},
		
	},

	{
		define = "class", name = "MsgMRDTAnserRequest", category = "MSG_CATEGORY_PLAYER", id = 532, base = "Message",
		attributes =
		{
			{type = "int8", name = "id"},
			{type = "int8", name = "answer"},
		},
		
	},

	{
		define = "class", name = "MsgMRDTAnserResponse", category = "MSG_CATEGORY_PLAYER", id = 533, base = "Message",
		attributes =
		{
			{type = "int8", name = "result"},
		},
		
	},

	{
		define = "class", name = "MsgMRDTRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 534, base = "Message",
		attributes =
		{
			{type = "int32", name = "rewardid"},
		},
		
	},

	{
		define = "class", name = "MsgMRDTQIUZHURequest", category = "MSG_CATEGORY_PLAYER", id = 535, base = "Message",
		attributes =
		{
		},
		
	},

	{
		define = "class", name = "MsgFulingRequest", category = "MSG_CATEGORY_PLAYER", id = 536, base = "Message",
		attributes =
		{
			{type = "int32",   name = "equipId"},
			{type = "int32",   name = "matEquipId", vector = true},
			{type = "int32",   name = "matEquipCount"},
		},
	},
	{
		define = "class", name = "MsgFulingResponse", category = "MSG_CATEGORY_PLAYER", id = 537, base = "Message",
		attributes =
		{
			{type = "int32",   name = "equipId"},
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgFulingZYRequest", category = "MSG_CATEGORY_PLAYER", id = 538, base = "Message",
		attributes =
		{
			{type = "int32",   name = "equipId"},
			{type = "int32",   name = "targetEquipId"},
		},
	},
	{
		define = "class", name = "MsgFulingZYResponse", category = "MSG_CATEGORY_PLAYER", id = 539, base = "Message",
		attributes =
		{
			{type = "int32",   name = "equipId"},
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgAskforSoulSystemInfoRequest", category = "MSG_CATEGORY_PLAYER", id = 540, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgAskforSoulSystemInfoResponse", category = "MSG_CATEGORY_PLAYER", id = 541, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgImproveSoulRequest", category = "MSG_CATEGORY_PLAYER", id = 542, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgImproveSoulResponse", category = "MSG_CATEGORY_PLAYER", id = 543, base = "Message",
		attributes =
		{
			{type = "int16", name = "type"},
			{type = "int16", name = "levelUp"},
			{type = "int16", name = "gradeUp"},
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgExchangeSoulRequest", category = "MSG_CATEGORY_PLAYER", id = 544, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgExchangeSoulResponse", category = "MSG_CATEGORY_PLAYER", id = 545, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgBossUpdateTimeRequest", category = "MSG_CATEGORY_PLAYER", id = 546, base = "Message",
		attributes =
		{
			{type = "int32", name = "powerkey"},
		},
	},

	{
		define = "class", name = "MsgOpenSecondWareRequest", category = "MSG_CATEGORY_PLAYER", id = 547, base = "Message",
		attributes =
		{
			{type = "int32", name = "gridKey"},
		},
	},
	{
		define = "class", name = "MsgOpenSecondWareResponse", category = "MSG_CATEGORY_PLAYER", id = 548, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int16", name = "beginPos"},
			{type = "int16", name = "endPos"},
		},
	},
	{
		define = "class", name = "MsgQuickUseItemsRequest", category = "MSG_CATEGORY_PLAYER", id = 549, base = "Message",
		attributes =
		{
			{type = "int64", name = "totalIndex"},
		},
	},
	{
		define = "class", name = "MsgInviteFriendsToSameGuildResponse", category = "MSG_CATEGORY_PLAYER", id = 553, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "leaveCD"},

		},
	},
	{
		define = "class", name = "MsgQuickUseItemsResponse", category = "MSG_CATEGORY_PLAYER", id = 550, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgInviteFriendsToSameGuildRequest", category = "MSG_CATEGORY_PLAYER", id = 551, base = "Message",
		attributes =
		{
			{type = "int32", name = "palyerPid"},
		},
	},
	{
		define = "class", name = "MsgTellInvitedFriendToGuildNotify", category = "MSG_CATEGORY_PLAYER", id = 552, base = "Message",
		attributes =
		{
			{type = "string", name = "playerName"},
			{type = "int32", name = "playerID"},
			{type = "string", name = "guildName"},
			{type = "int32", name = "guildID"},
		},
	},
	{
		define = "class", name = "MsgDecomposeDressRequest", category = "MSG_CATEGORY_PLAYER", id = 554, base = "Message",
		attributes =
		{
			{type = "int32", name ="itemList", vector = true},
		},
		
	},
	{
		define = "class", name = "MsgDecomposeDressResponse", category = "MSG_CATEGORY_PLAYER", id = 555, base = "Message",
		attributes =
		{
			{type = "int32", name ="errcode"},
		},
		
	},
	{
		define = "class", name = "MsgSyntheticRequest", category = "MSG_CATEGORY_PLAYER", id = 556, base = "Message",
		attributes =
		{
			{type = "int32", name = "targetItemCounts"},
		},
	},
	{
		define = "class", name = "MsgSyntheticResponse", category = "MSG_CATEGORY_PLAYER", id = 557, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "struct", name = "DamageShow",
		attributes =
		{
			{type="int32", name="DamageValue"},
			{type="int32", name="DamageType"},
		}
	},
	{
		define = "class", name = "MsgFloatWordMessageResponse", category = "MSG_CATEGORY_PLAYER", id = 558, base = "Message",
		attributes =
		{
			{type = "int32",   name = "dstEid"},
			{type = "DamageShow",   name = "damage",vector = true},
			{type = "int32",   name = "delay"},

		},
	},
	{
		define = "class", name = "MsgEnterCrossServerNotify", category = "MSG_CATEGORY_PLAYER", id = 559, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgUpdServerNameRequest", category = "MSG_CATEGORY_PLAYER", id = 560, base = "Message",
		attributes =
		{
			{type = "string", name = "serverName"},
		},
	},
	{
		define = "class", name = "MsgPlayerLevelUpRequest", category = "MSG_CATEGORY_PLAYER", id = 561, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgPlayerLevelUpResponse", category = "MSG_CATEGORY_PLAYER", id = 562, base = "Message",
		attributes =
		{
			{type = "int16",   name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgSmeltRefreshRequest", category = "MSG_CATEGORY_PLAYER", id = 565, base = "Message",
		attributes =
		{
			{type = "int32",   name = "ItemId"},
			{type = "int32",   name = "lockedNums"},
			{type = "int32",   name = "lockedFlag"},
		}
	},

	{
		define = "class", name = "MsgSmeltRefreshResponse", category = "MSG_CATEGORY_PLAYER", id = 566, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
		}
	},
	{
		define = "class", name = "MsgSmeltReplaceRequest", category = "MSG_CATEGORY_PLAYER", id = 567, base = "Message",
		attributes =
		{
			{type = "int32",   name = "ItemId"},
		}
	},
	{
		define = "class", name = "MsgSmeltReplaceResponse", category = "MSG_CATEGORY_PLAYER", id = 568, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
		}
	},
	{
		define = "class", name = "MsgSpiritStoneRequest", category = "MSG_CATEGORY_PLAYER", id = 569, base = "Message",
		attributes =
		{	
			{type = "int16",   name = "wearType"},
			{type = "int32",   name = "equipIndex"},
			{type = "int32",   name = "stoneSid"},
			{type = "int32",   name = "itemId"},
		}
	},
	{
		define = "class", name = "MsgSpiritStoneResponse", category = "MSG_CATEGORY_PLAYER", id = 570, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
			{type = "int32",   name = "equipIndex"},
		}
	},
	{
		define = "class", name = "MsgSpiritStoneMakeRequest", category = "MSG_CATEGORY_PLAYER", id = 571, base = "Message",
		attributes =
		{	
			{type = "int16",   name = "equipIndex"},
			{type = "int16",   name = "stoneType"},
			{type = "int32",   name = "stoneLevel"},
			{type = "int32",   name = "stoneNum"},
		}
	},
	{
		define = "class", name = "MsgStoneMakeResponse", category = "MSG_CATEGORY_PLAYER", id = 572, base = "Message",
		attributes =
		{
			{type = "int32",   name = "errcode"},
			{type = "int16",   name = "equipIndex"},
		}
	},

    {
		define = "class", name = "MsgFabaoUpRequest", category = "MSG_CATEGORY_PLAYER", id = 652, base = "Message",
		attributes =
		{
			{type = "int32" , name = "id" },
			{type = "int32" , name = "opt"},
		},
	
	},
	{
		define = "class", name = "MsgFabaoUpResponse", category = "MSG_CATEGORY_PLAYER", id = 653, base = "Message",
		attributes =
		{
            {type = "int32" , name = "errcode" },
			{type = "int32" , name = "opt"},
		},
	},
	
	{
		define = "class", name = "MsgChangeWingDressRequest", category = "MSG_CATEGORY_PLAYER", id = 712, base = "Message",
		attributes =
		{
			{type = "int16",   name = "wingIndex"},
		},
	},
	
	{
		define = "class", name = "MsgChangeWingDressResponse", category = "MSG_CATEGORY_PLAYER", id = 713, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgImproveWingRequest", category = "MSG_CATEGORY_PLAYER", id = 714, base = "Message",
		attributes =
		{
			{type = "int16",   name = "index"},
		},
	},
	
	{
		define = "class", name = "MsgImproveWingResponse", category = "MSG_CATEGORY_PLAYER", id = 715, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgUpdatePlayerSkillRequest", category = "MSG_CATEGORY_PLAYER", id = 716, base = "Message",
		attributes =
		{
			{type = "int32",   name = "skillid"},
		}
	},
	{
		define = "class", name = "MsgUpdatePlayerSkillResponse", category = "MSG_CATEGORY_PLAYER", id = 717, base = "Message",
		attributes =
		{
			{type = "int32",   name = "skillid"},
			{type = "int32",   name = "errcode"},
		}
	},
	
	{
		define = "class", name = "MsgTriggerDragonSkillNotify", category = "MSG_CATEGORY_PLAYER", id = 722, base = "Message",
		attributes =
		{
			{type = "int32",   name = "skillId"},
			{type = "int32",   name = "targetEid"},
		}
	},

	{
		define = "class", name = "MsgExchangeHegemonEquipShowRequest", category = "MSG_CATEGORY_PLAYER", id = 723, base = "Message",
		attributes =
		{
			{type = "int16", name = "exchageType"},
		},
	},

	{
		define = "class", name = "MsgPlayerDressWardrobeLvlUpRequest", category = "MSG_CATEGORY_PLAYER", id = 726, base = "Message",
		attributes =
		{
			{type = "int32",   name = "value"},
			{type = "int32", name ="itemList", vector = true},
		},
	},

	{
		define = "class", name = "MsgPlayerDressWardrobeLvlUpResponse", category = "MSG_CATEGORY_PLAYER", id = 727, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgPlayerTherionLevelRequest", category = "MSG_CATEGORY_PLAYER", id = 731, base = "Message",
		attributes =
		{
			{type = "int32", name = "index"},
		},
	},
	{
		define = "class", name = "MsgPlayerTherionLevelResponse", category = "MSG_CATEGORY_PLAYER", id = 732, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgPlayerLovelyPetRequest", category = "MSG_CATEGORY_PLAYER", id = 733, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "petid"},
		},
	},
	{
		define = "class", name = "MsgPlayerLovelyPetResponse", category = "MSG_CATEGORY_PLAYER", id = 734, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgPlayerLoadPetRequest", category = "MSG_CATEGORY_PLAYER", id = 736, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgKeepMsgRequest", category = "MSG_CATEGORY_PLAYER", id = 737, base = "Message",
		attributes =
		{
		},
	
	},
	
    {
		define = "struct", name = "stcChatKeepInfo",
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
            {type = "int32", name = "keepTime"},
            {type = "int32", name = "serverid"},
            {type = "chatPlayerProp", name = "props", vector = true},
		},
	
	},
	
    {
		define = "class", name = "MsgKeepMsgResponse", category = "MSG_CATEGORY_PLAYER", id = 738, base = "Message",
		attributes =
		{
			{type = "stcChatKeepInfo", name = "WorldArray", vector = true},
            {type = "stcChatKeepInfo", name = "TheaterArray", vector = true},--ս��
            {type = "stcChatKeepInfo", name = "GuildArray", vector = true},
            {type = "stcChatKeepInfo", name = "PrivateArray", vector = true},
		},
	
	},
	{
		define = "class", name = "MsgPlayerGetBaoBaoSkillRequest", category = "MSG_CATEGORY_PLAYER", id = 739, base = "Message",
		attributes =
		{
			{type = "int32", name = "bagid"},
		},
	},
	{
		define = "class", name = "MsgPlayerGetBaoBaoSkillResponse", category = "MSG_CATEGORY_PLAYER", id = 740, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},
	
	{
		define = "struct", name = "WarZoneDropDetail",
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
		define = "class", name = "MsgSyncWarZoneDropInfoToPlayer", category = "MSG_CATEGORY_PLAYER", id = 743, base = "Message",
		attributes =
		{
			{type = "int16", name = "reload"},
			{type = "WarZoneDropDetail", name = "topDropInfoList", vector = true},
			{type = "WarZoneDropDetail", name = "dropInfoList", vector = true},
		},
	},

	{
		define = "class", name = "MsgPlayerGetTrainingRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 744, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgTrainingChallengeNotify", category = "MSG_CATEGORY_PLAYER", id = 745, base = "Message",
		attributes =
		{
			{type = "int32", name = "state"},
		},
	},
	{
		define = "class", name = "MsgPlayerGetSpecialRingGiftRequest", category = "MSG_CATEGORY_PLAYER", id = 746, base = "Message",
		attributes =
		{
			{type = "int32", name = "index"},
		},
	},
	{
		define = "class", name = "MsgPlayerGetSpecialRingGiftResponse", category = "MSG_CATEGORY_PLAYER", id = 747, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
		{
		define = "class", name = "MsgExchangeIngotRequest", category = "MSG_CATEGORY_PLAYER", id = 748, base = "Message",
		attributes =
		{
			{type = "int32", name = "count",desc = "��ʯ����"},
		},
	},
	{
		define = "class", name = "MsgExchangeIngotResponse", category = "MSG_CATEGORY_PLAYER", id = 749, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgBigBangItemResponse", category = "MSG_CATEGORY_PLAYER", id = 750, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemId"},
		},
	},
	{
		define = "class", name = "MsgBigBangUpLevelResponse", category = "MSG_CATEGORY_PLAYER", id = 751, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgRoastPigRequest", category = "MSG_CATEGORY_PLAYER", id = 752, base = "Message",
		attributes =
		{
			{type = "int32", name = "type",desc = "�������ͣ�1-��ʼ�й� 2-��ȡ����"},
		},
	},
	{
		define = "class", name = "MsgRoastPigResponse", category = "MSG_CATEGORY_PLAYER", id = 753, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgVipFireRainResponse", category = "MSG_CATEGORY_PLAYER", id = 755, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgMonthCardGetRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 756, base = "Message",
		attributes =
		{
			{type = "int32", name = "type",desc = "�������ͣ�1-�¿� 2-�ܿ�"},
		},
	},
	{
		define = "class", name = "MsgMemberOpeartionRequest", category = "MSG_CATEGORY_PLAYER", id = 757, base = "Message",
		attributes =
		{
			{type = "int32", name = "type",desc = "�������ͣ�1-�����Ա 2-��ȡ����"},
		},
	},
	{
		define = "class", name = "MsgMemberOpeartionResponse", category = "MSG_CATEGORY_PLAYER", id = 758, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgNewVipActiveRequest", category = "MSG_CATEGORY_PLAYER", id = 759, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgNewVipActiveResponse", category = "MSG_CATEGORY_PLAYER", id = 760, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgNewVipLvlUpRequest", category = "MSG_CATEGORY_PLAYER", id = 761, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgNewVipLvlUpResponse", category = "MSG_CATEGORY_PLAYER", id = 762, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgNewVipChallengeRequest", category = "MSG_CATEGORY_PLAYER", id = 763, base = "Message",
		attributes =
		{
			{type = "int32", name = "index"},
		},
	},
	
	{
		define = "class", name = "MsgNewVipChallengeResponse", category = "MSG_CATEGORY_PLAYER", id = 764, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgRobResultResponse", category = "MSG_CATEGORY_PLAYER", id = 765, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "lode_lvl"},
			{type = "int32", name = "owner_lvl"},
			{type = "int32", name = "result"},
			{type = "string", name = "owner_name"},
			{type = "int32", name = "owner_power"},
		},
	},


    {
		define = "struct", name = "SyncRobbingInfo",
		attributes =
		{
			{type = "int32", name = "owner_id"},
			{type = "string", name = "owner_name"},
			{type = "int32", name = "owner_lvl"},
			{type = "int32", name = "lode_lvl"},
			{type = "int32", name = "robber_id"},
			{type = "int32", name = "robber_power"},
			{type = "string", name = "robber_name"},
			{type = "int32", name = "rob_time"},
			{type = "int32", name = "retake_time"},
			{type = "int32", name = "retake_result"},
		},
	},
	{
		define = "class", name = "MsgSyncRobRecordResponse", category = "MSG_CATEGORY_PLAYER", id = 766, base = "Message",
		attributes =
		{
			{type = "SyncRobbingInfo", name = "info_list", vector = true},

		},
	},
	{
		define = "class", name = "MsgOpenTheasureMapRequest", category = "MSG_CATEGORY_PLAYER", id = 767, base = "Message",
		attributes =
		{
			
		},
	},
		{
		define = "class", name = "MsgOpenTheasureMapResponse", category = "MSG_CATEGORY_PLAYER", id = 768, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "eventIndex"},
		},
	},
		{
		define = "class", name = "MsgOpenTheasureMapGetAwardRequest", category = "MSG_CATEGORY_PLAYER", id = 769, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"},
		},
	},
		{
		define = "class", name = "MsgOpenTheasureMapGetAwardResponse", category = "MSG_CATEGORY_PLAYER", id = 770, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "index"},
		},
	},
		{
		define = "class", name = "MsgGetTheasureMapPosRequest", category = "MSG_CATEGORY_PLAYER", id = 771, base = "Message",
		attributes =
		{
			
		},
	},
		{
		define = "class", name = "MsgGetTheasureMapPosResponse", category = "MSG_CATEGORY_PLAYER", id = 772, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgIntoTheasureMapPosResponse", category = "MSG_CATEGORY_PLAYER", id = 773, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	
	{
		define = "class", name = "MsgSyncPlayerAllIntPropsNotify", category = "MSG_CATEGORY_PLAYER", id = 774, base = "Message",
		attributes =
		{
			{type = "OtherEntityProp", name = "proplist", vector = true},
		},
	},
	{
		define = "struct", name = "AffiliationItem",
		attributes =
		{
			{type = "int32", name = "sid"},
			{type = "int32", name = "count"},
			{type = "int32", name = "bind"},
		},
	},
	{
		define = "class", name = "MsgSyncPlayerAffiliationItemInfosNotify", category = "MSG_CATEGORY_PLAYER", id = 775, base = "Message",
		attributes =
		{
			{type = "AffiliationItem", name = "items", vector = true},
		},
	},
	{
		define = "class", name = "MsgGetXiYouRewardCountRequest", category = "MSG_CATEGORY_PLAYER", id = 776, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
		},
	},
	{
		define = "class", name = "MsgGetXiYouRewardCountResponse", category = "MSG_CATEGORY_PLAYER", id = 777, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgTreasureMapDropNotify", category = "MSG_CATEGORY_PLAYER", id = 778, base = "Message",
		attributes =
		{
			{type = "int32", name = "itemId"},
		},
	},
	{
		define = "class", name = "MsgTortoiseEquipLevelNeedNotify", category = "MSG_CATEGORY_PLAYER", id = 779, base = "Message",
		attributes =
		{
			{type = "int32", name = "level"},
		},
	},
	{
		define = "class", name = "MsgAttackBossLimitNotify", category = "MSG_CATEGORY_PLAYER", id = 780, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},
	{
		define = "class", name = "MsgExpRoadRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 781, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "index"},
		},
	},
	{
		define = "class", name = "MsgExpRoadRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 782, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "index"},
		},
	},
	{
		define = "class", name = "MsgPrivateChatOnlineCheckRequest", category = "MSG_CATEGORY_PLAYER", id = 783, base = "Message",
		attributes =
		{
			{type = "int32", name = "playerid"},
			{type = "string", name = "name"},
		},
	},
	{
		define = "class", name = "MsgPrivateChatOnlineCheckResponse", category = "MSG_CATEGORY_PLAYER", id = 784, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "playerid"},
			{type = "string", name = "name"},
		},
	},

	{
		define = "class", name = "MsgLuckyImmedFullLevelRequest", category = "MSG_CATEGORY_PLAYER", id = 786, base = "Message",
		attributes =
		{
		}
	},
	{
		define = "class", name = "MsgLuckyImmedFullLevelResponse", category = "MSG_CATEGORY_PLAYER", id = 787, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgTgmjTowerClearRequest", category = "MSG_CATEGORY_PLAYER", id = 789, base = "Message",
		attributes =
		{
			{type = "int32", name = "clearType"},
		}
	},
	{
		define = "class", name = "MsgTgmjTowerClearResponse", category = "MSG_CATEGORY_PLAYER", id = 790, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	-- Ѫ��������Ϣ
	{
		define = "class", name = "MsgBloodUpdateRequest", category = "MSG_CATEGORY_PLAYER", id = 792, base = "Message",
		attributes =
		{
			{type = "int32", name = "BloodType"},
		}
	},
	{
		define = "class", name = "MsgBloodUpdateResponse", category = "MSG_CATEGORY_PLAYER", id = 793, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

    {
		define = "class", name = "MsgSYNCTABRequest", category = "MSG_CATEGORY_PLAYER", id = 794, base = "Message",
		attributes =
		{
			{type = "int32", name = "syncType"},
            {type = "int32", name = "syncCode"},
		},
	},


     {
		define = "class", name = "MsgSvrToClientNotify", category = "MSG_CATEGORY_PLAYER", id = 795, base = "Message",
		attributes =
		{
			{type = "int32", name = "funcId"},
            {type = "int32", name = "datax"},
            {type = "int32", name = "datay"},
            {type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	
	},
	{
		define = "class", name = "MsgMolingBossNeedGetTipsNotify", category = "MSG_CATEGORY_PLAYER", id = 803, base = "Message",
		attributes =
		{
			{type = "int32", name = "boss_id"},
		},
	},

	{
		define = "class", name = "MsgNewVipGetStarRewardRequest", category = "MSG_CATEGORY_PLAYER", id = 804, base = "Message",
		attributes =
		{
			{type = "int32", name = "map_page"},
			{type = "int32", name = "index"},
		},
	},

	{
		define = "class", name = "MsgNewVipGetStarRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 805, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "map_page"},
		},
	},
	{
		define = "class", name = "MsgPlayerGetTrainingRewardResponse", category = "MSG_CATEGORY_PLAYER", id = 806, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgNewVipSubmitQuestRequest", category = "MSG_CATEGORY_PLAYER", id = 807, base = "Message",
		attributes =
		{
			{type = "int32", name = "quest_type"},
		},
	},

	{
		define = "class", name = "MsgNewVipSubmitQuestResponse", category = "MSG_CATEGORY_PLAYER", id = 808, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "quest_type"},
		},
	},

	{
		define = "class", name = "MsgActiveQiLingRequest", category = "MSG_CATEGORY_PLAYER", id = 809, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgActiveQiLingNotify", category = "MSG_CATEGORY_PLAYER", id = 810, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgActiveQiLingResponse", category = "MSG_CATEGORY_PLAYER", id = 811, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "id"},
		},
	},
	{
		define = "class", name = "MsgUpdPlayerSpecialDiamondNotify", category = "MSG_CATEGORY_PLAYER", id = 812, base = "Message",
		attributes =
		{
			{type = "int32",   name = "opcode"},
			{type = "int32",   name = "ingot"},
		}
	},
	{
		define = "class", name = "MsgSmeltClearNewAttrsRequest", category = "MSG_CATEGORY_PLAYER", id = 813, base = "Message",
		attributes =
		{
			{type = "int32",   name = "equipIndex"},
		}
	},

	{
		define = "class", name = "MsgFinishPigSmNotify", category = "MSG_CATEGORY_PLAYER", id = 814, base = "Message",
		attributes =
		{
		},
	
	},

	{
		define = "class", name = "MsgPlayerJuHePayRequest", category = "MSG_CATEGORY_PLAYER", id = 815, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "Ӧ�ñ��"},
			{type = "int32", name = "packageId", desc = "�ְ����"},
			{type = "string", name = "deviceId", desc = "�豸id"},
			{type = "int32", name = "aid", desc = "ip��ַ"},
			{type = "string", name = "money", desc = "ip��ַ"},
			{type = "string", name = "ip", desc = "ip��ַ"},
			{type = "string", name = "cpExt", desc = "json����"},
			{type = "string", name = "serverName", desc = "�˺�Ψһ��ʶ"},
			{type = "string", name = "roleName", desc = "��ͨ��ƾ֤"},
			{type = "int32", name = "sdkId", desc = "sdk���"},
			{type = "string", name = "openId", desc = "��ͨ��ƾ֤"},
			{type = "string", name = "appKey", desc = "sdk���"},
		},
	},

	{
		define = "class", name = "MsgPlayerJuHePayResponse", category = "MSG_CATEGORY_PLAYER", id = 816, base = "Message",
		attributes =
		{
			{type = "string", name = "orderId", desc = "�������"},
			{type = "int32" , name = "errcode"},
			{type = "string", name = "msg", desc = "��ʾ��Ϣ"},
		},
	},

	{
		define = "class", name = "MsgPlayerAutoAttackNotify", category = "MSG_CATEGORY_PLAYER", id = 817, base = "Message",
		attributes =
		{
			{type = "int32" , name = "id"},
		},
	},

	{
		define = "class", name = "MsgPlayerChatVeriPhoneRequest", category = "MSG_CATEGORY_PLAYER", id = 818, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "�������"},
			{type = "string" , name = "openId"},
			{type = "string", name = "mobile", desc = "�ֻ���"},
			{type = "string", name = "verifyCode", desc = "�ֻ���"},
		},
	},

	{
		define = "class", name = "MsgPlayerChatVeriPhoneResponse", category = "MSG_CATEGORY_PLAYER", id = 819, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error"},
			{type = "string" , name = "message"},
		},
	},

	{
		define = "class", name = "MsgPlayerChatVeriCodeRequest", category = "MSG_CATEGORY_PLAYER", id = 820, base = "Message",
		attributes =
		{
			{type = "int32", name = "appId", desc = "�������"},
			{type = "string" , name = "openId"},
			{type = "string", name = "mobile", desc = "�ֻ���"},
		},
	},

	{
		define = "class", name = "MsgPlayerChatVeriCodeResponse", category = "MSG_CATEGORY_PLAYER", id = 821, base = "Message",
		attributes =
		{
			{type = "int32" , name = "error"},
			{type = "string" , name = "message"},
		},
	},

	{
		define = "class", name = "MsgIOSRechargeSuccessNotify", category = "MSG_CATEGORY_PLAYER", id = 822, base = "Message",
		attributes =
		{
			{type = "int32" , name = "sid"},
			{type = "int32" , name = "cnt"},
			{type = "int32" , name = "pid"},
			{type = "int32" , name = "type"},
			{type = "string" , name = "orderid"},
		},
	},

	{
		define = "struct", name = "Combatprop",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "int32", name = "value"},
		}
	},
	{
		define = "class", name = "MsgUpPlayerCombatPropNotify", category = "MSG_CATEGORY_PLAYER", id = 823, base = "Message",
		attributes =
		{
			{type = "int32", name = "opcode"},
			{type = "Combatprop", name = "combatprop", vector = true},
		},
	},

	{
		define = "class", name = "MsgCommonOperatorRequest", category = "MSG_CATEGORY_PLAYER", id = 824, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int16", name = "funcid"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},
	
	{
		define = "class", name = "MsgCommonOperatorResponse", category = "MSG_CATEGORY_PLAYER", id = 825, base = "Message",
		attributes =
		{
			{type = "int16", name = "funcid"},
			{type = "int16", name = "errcode"},			
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},
	

	{
		define = "class", name = "MsgGetMapStatisticsDataRequest", category = "MSG_CATEGORY_PLAYER", id = 826, base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGetMapStatisticsDataResponse", category = "MSG_CATEGORY_PLAYER", id = 827, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "OtherEntityProp", name = "data_list", vector = true},
		},
	},
	{
		define = "struct", name = "OtherItemProp",
		attributes =
		{
			{type="int32", name="idx"},
			{type="int32", name="data"},
		}
	},

	{
		define = "struct", name = "OtherPlayerEquip",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="iid"},
			{type="int32", name="pos"},
			{type="string", name="firstowner"},
			{type="string", name="appraiser"},
			{type="OtherItemProp", name="props", vector=true},
		}
	},

	{
		define = "struct", name = "OtherPlayerSkill",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32", name="level"},
		}
	},

	{
		define = "class", name = "MsgNewCheckEquipResponse", category = "MSG_CATEGORY_PLAYER", id = 840, base = "Message",
		attributes =
		{
			{type = "int32" , name = "pid" },
			{type = "int8",  name = "gender"},
			{type = "int32"	, name = "level"},
			{type = "int64"	, name = "exp"},
			{type = "int32"	, name = "cloth"},
			{type = "int32"	, name = "weapon"},
			{type = "int32"	, name = "wings"},
			{type = "int32"	, name = "zhanli"},
			{type = "string", name = "name"	},
			{type = "string", name = "guild"},
			{type = "int32",  name = "lingwen"},
			{type = "int32",  name = "guildpost"},
			{type = "int32",  name = "job"},
			{type = "int32",  name = "reborn"},
			{type = "OtherPlayerEquip", name = "equips", vector = true},
			{type = "OtherEntityProp", name = "prop", vector = true},
			{type = "OtherEntityStringProp", name = "sprop", vector = true},
			{type = "OtherPlayerSkill", name = "skill", vector = true},
			{type = "int32", name = "vcombat", vector = true},
		},
	},
	{
		define = "class", name = "MsgSyncExDropNotify", category = "MSG_CATEGORY_PLAYER", id = 841, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgDreamLandBossRefreshNotify", category = "MSG_CATEGORY_PLAYER", id = 842, base = "Message",
		attributes =
		{
			{type = "int32" , name = "boss_id" },
		},
	},

	{
		define = "class", name = "MsgLodeOccupyDataRequest", category = "MSG_CATEGORY_PLAYER", id = 843, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "struct", name = "LodeOccupy",
		attributes =
		{
			{type = "int32", name = "lode_lvl"},
			{type = "int32", name = "count"},
		}
	},
	{
		define = "class", name = "MsgLodeOccupyDataResponse", category = "MSG_CATEGORY_PLAYER", id = 844, base = "Message",
		attributes =
		{
			{type = "LodeOccupy",   name = "lodeOccupyData", vector = true},
		},
	},
	{
		define = "class", name = "MsgGetBossCntInMapRequest", category = "MSG_CATEGORY_PLAYER", id = 845, base = "Message",
		attributes =
		{
			{type = "int32",   name = "maps", vector = true},
			{type = "string",  name = "targetName"}
		},
	},

	{
		define = "struct", name = "MapBossInfo",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int32", name = "count"}, 
		}
	},

	{
		define = "struct", name = "MapBossCount",
		attributes =
		{
			{type = "int16", name = "index"},
			{type = "int32", name = "count"},
			{type = "int32", name = "sceneId"},
			{type = "MapBossInfo",   name = "boss_list", vector = true},
		}
	},
	{
		define = "class", name = "MsgGetBossCntInMapNotify", category = "MSG_CATEGORY_PLAYER", id = 846, base = "Message",
		attributes =
		{
			{type = "MapBossCount",   name = "boss_cnts", vector = true},
			{type = "string", name = "targetName"}
		},
	},
	{
        define = "class",
        name = "MsgFinishWantedTaskRequest",
        category = "MSG_CATEGORY_PLAYER",
        id = 847,
        base = "Message",
        attributes = {
            {type = "int32", name = "taskindex"}
        }
    },
    {
        define = "class",
        name = "MsgFinishWantedTaskResponse",
        category = "MSG_CATEGORY_PLAYER",
        id = 848,
        base = "Message",
        attributes = {
            {type = "int32", name = "errcode"}
        }
    },
	{
        define = "class",
        name = "MsgGetWantedRewardRequest",
        category = "MSG_CATEGORY_PLAYER",
        id = 849,
        base = "Message",
        attributes = {
            {type = "int32", name = "gradeindex"},
            {type = "int32", name = "type"}
        }
    },
    {
        define = "class",
        name = "MsgGetWantedRewardResponse",
        category = "MSG_CATEGORY_PLAYER",
        id = 850,
        base = "Message",
        attributes = {
            {type = "int32", name = "errcode"}
        }
    },
	{
		define = "class", name = "MsgSyncDoubleDropNotify", category = "MSG_CATEGORY_PLAYER", id = 851, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"}
		},
	},
	{
		define = "class", name = "MsgSyncBDZZDropNotify", category = "MSG_CATEGORY_PLAYER", id = 852, base = "Message",
		attributes =
		{
			{type = "int32", name = "eid"}
		},
	},

	{
		define = "class", name = "MsgOpenQiRiShengFenNotify", category = "MSG_CATEGORY_PLAYER", id = 875, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},	
		},
	},
	{
		define = "class", name = "MsgStopQiRiShengFenNotify", category = "MSG_CATEGORY_PLAYER", id = 876, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},	
		},
	},
	
	{
		define = "class", name = "MsgOperationRecordNotify", category = "MSG_CATEGORY_PLAYER", id = 879, base = "Message",
		attributes =
		{
			{type = "int32", name = "code"},	
			{type = "int32", name = "platformId"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},
	{
		define = "class", name = "MsgHideCrossActivityNotify", category = "MSG_CATEGORY_PLAYER", id = 880, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
		},
	},
	
	{
		define = "class", name = "MsgShenBingFuseRequest", category = "MSG_CATEGORY_PLAYER", id = 881, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid1"},
			{type = "int32", name = "iid2"},
		},
	},
	{
		define = "class", name = "MsgShenBingFuseResponse", category = "MSG_CATEGORY_PLAYER", id = 882, base = "Message",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "code"},
		},
	},

	{
		define = "class", name = "MsgDoctorRequest", category = "MSG_CATEGORY_PLAYER", id = 883, base = "Message",
		attributes =
		{
		},
	},
	{
		define = "class", name = "MsgDoctorResponse", category = "MSG_CATEGORY_PLAYER", id = 884, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},	
		},
	},	
	{
		define = "class", name = "MsgNoviceNotify", category = "MSG_CATEGORY_PLAYER", id = 885, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "step"},	
		},
	},	
	{
		define = "class", name = "MsgChangeJobNotify", category = "MSG_CATEGORY_PLAYER", id = 886, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "job"},	
		},
	},	

	-- 透视
	{
		define = "class", name = "MsgToushiRequest", category = "MSG_CATEGORY_PLAYER", id = 891, base = "Message",
		attributes =
		{
			{type = "int32", name = "monsterId"},
		},
	},
	{
		define = "class", name = "MsgToushiResponse", category = "MSG_CATEGORY_PLAYER", id = 892, base = "Message",
		attributes =
		{
			{type = "int32", name = "errcode"},
			{type = "int32", name = "monsterId"},
			{type = "string", name = "itemList"},
		},
	},

	{
		define = "class", name = "MsgGuildBossChangeOwnerNotify", category = "MSG_CATEGORY_PLAYER", id = 895, base = "Message",
		attributes =
		{
			{type = "int32", name = "mid"},
			{type = "int32", name = "ownPid"},
			{type = "int32", name = "ownGid"},
			{type = "int32", name = "killCount"},
			{type = "int32", name = "status"},
			{type = "string", name = "playerName"},
			{type = "string", name = "guildName"},
		},
	},
	
	{
		define = "class", name = "MsgGetPlayerBaseInfoRequest", category = "MSG_CATEGORY_PLAYER", id = 896, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "serverid"},
		},
	},
	{
		define = "class", name = "MsgGetPlayerBaseInfoResponse", category = "MSG_CATEGORY_PLAYER", id = 897, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "gender"},
			{type = "int32", name = "job"},
			{type = "int32", name = "weapon"},
			{type = "int32", name = "dress_weapon"},
			{type = "int32", name = "cloth"},
			{type = "int32", name = "dress_cloth"},
			{type = "int32", name = "hat"},
			{type = "int32", name = "shield"},
			{type = "int32", name = "guard_level"},
			{type = "int32", name = "hunhuan"},
			{type = "int32", name = "jingling"},
		},
	},
	{
		define = "class", name = "MsgGetGiftByCodeRequest", category = "MSG_CATEGORY_PLAYER", id = 898, base = "Message",
		attributes =
		{
			{type = "string", name = "code"},
		},
	},

	{
		define = "class" , name = "MsgGetGiftByCodeResponse", category = "MSG_CATEGORY_PLAYER", id = 899, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name="MsgActivityRewardRequest", category = "MSG_CATEGORY_PLAYER" , id = 900 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
		},
	},

	{
		define = "class", name="MsgActivityRewardResponse", category = "MSG_CATEGORY_PLAYER" , id = 901 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},	
			{type = "int32", name = "id"},
			{type = "int32", name = "index"},
			{type = "int32", name = "flag"},
		},
	},

	{
		define = "class", name="MsgActivityOperateRequest", category = "MSG_CATEGORY_PLAYER" , id = 902 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "string", name = "fun_name"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "class", name="MsgActivityOperateResponse", category = "MSG_CATEGORY_PLAYER" , id = 903 ,base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},	
			{type = "int32", name = "id"},
			{type = "string", name = "fun_name"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},
			{type = "string", name = "datas"},
		},
	},

	{
		define = "struct", name = "RankItemData",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "datax"},
			{type = "int32", name = "datay"},
			{type = "int32", name = "dataz"},			
			{type = "string", name = "name"},
			{type = "string", name = "guild_name"},
			{type = "string", name = "server_name"},
		},
	},

	{
		define = "class", name = "MsgGetRankRequest", category = "MSG_CATEGORY_PLAYER", id = 904, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
		},
	},

	{
		define = "class", name = "MsgGetRankResponse", category = "MSG_CATEGORY_PLAYER", id = 905, base = "Message",
		attributes =
		{
			{type = "int32", name = "type"},
			{type = "RankItemData", name = "list", vector = true},
		},
	},
}

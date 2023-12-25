messages =
{
	{
		define = "struct", name = "PetInfo",
		attributes =
		{
			{type = "int32", name="id"},
			{type = "int32", name = "sid"},
			{type = "string", name="name"},
			{type = "int16" , name="lvl"},
			{type = "int32", name = "exp"},
			{type = "int32", name = "state"},
			{type = "int32", name = "reborn"},
		}
	},

	{
		define = "class", name="MsgUpdPetInfoBaseNotify", category = "MSG_CATEGORY_PET" , id = 1 ,base = "Message",
		attributes =
		{
			{type = "PetInfo",	name = "petBase",vector = true},
		},
	},

	{
		define = "class", name="MsgUpdPetCombatNotify", category = "MSG_CATEGORY_PET" , id = 2 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "id" },
			{type = "int32", name ="combatdata", vector = true},
		},
	},

	{
		define = "class", name = "MsgRmvPetRequest", category = "MSG_CATEGORY_PET", id = 3, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgRmvPetResponse", category = "MSG_CATEGORY_PET", id = 4, base = "Message",
		attributes =
		{
			--{type = "int32", name = "id"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgActivePetStateRequest", category = "MSG_CATEGORY_PET", id = 5, base = "Message",
		attributes=
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class", name = "MsgActivePetStateResponse", category = "MSG_CATEGORY_PET", id = 6, base = "Message",
		attributes=
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "opcode"},
			{type = "int16", name = "errcode"},
			{type = "int32", name = "cooltime"},			
		},
	},

	{
		define = "class", name = "MsgPetStateNotify", category = "MSG_CATEGORY_PET", id = 7, base = "Message",
		attributes =
		{
			{type = "int32", name = "id" },
			{type = "int32", name = "state"},
		},
	},

	{
		define = "class", name = "MsgRelivePetRequest", category = "MSG_CATEGORY_PET", id = 8, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgRelivePetResponse", category = "MSG_CATEGORY_PET", id = 9, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "errcode" },
		},
	},

	{
		define = "class", name = "MsgFeedPetRequest", category = "MSG_CATEGORY_PET", id = 10, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "feedtype"},
		},
	},

	{
		define = "class", name = "MsgFeedPetResponse", category = "MSG_CATEGORY_PET", id = 11, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgUpdPetLvlExpNotify", category = "MSG_CATEGORY_PET", id = 12, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int32", name = "lvl"},
			{type = "int32", name = "exp"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class", name="MsgRmvPetNotify", category = "MSG_CATEGORY_PET" , id = 15 ,base = "Message",
		attributes =
		{
			{type = "int32", name = "petid"},
		},
	},

	{
		define = "class", name="MsgAddPetNotify", category = "MSG_CATEGORY_PET" , id = 16 ,base = "Message",
		attributes =
		{
			{type = "PetInfo",	name = "petBase"},
			{type = "int32",  	name = "combatdata", vector = true},
		},
	},

	{
		define = "class", name = "MsgSleepPetStateRequest", category = "MSG_CATEGORY_PET", id = 17, base = "Message",
		attributes=
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "opcode"},
		},
	},

	{
		define = "class", name = "MsgSleepPetStateResponse", category = "MSG_CATEGORY_PET", id = 18, base = "Message",
		attributes=
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "opcode"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgImprisonPetRequest", category = "MSG_CATEGORY_PET", id = 19, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgImprisonPetResponse", category = "MSG_CATEGORY_PET", id = 20, base = "Message",
		attributes =
		{
			{type = "int32", name = "id"},
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "struct", name = "sellitem",
		attributes =
		{
			{type = "int32", name = "iid"},
			{type = "int32", name = "selltype"},
			{type = "int32", name = "sellprice"},
			{type = "int32", name = "sellcnt"},
			--{type = "int32", name = "position"},
		},
	},

	--{
	--	define = "class", name = "MsgAddPetEggNotify", category = "MSG_CATEGORY_PET", id = 61, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "id"},
	--		{type = "PetInfo",	name = "petBase"},
	--		{type = "int32", name ="combatdata", vector = true},
	--	},
	--},
    --
	--{
	--	define = "class", name = "MsgAddPetEggExNotify", category = "MSG_CATEGORY_PET", id = 62, base = "Message",
	--	attributes =
	--	{
	--		{type = "int32", name = "id"},
	--		{type = "int32", name = "idx"},
	--		{type = "int32", name = "data"},
	--	},
	--},

	{
		define = "class", name = "MsgImprovePetAdvanceRequest", category = "MSG_CATEGORY_PET", id = 63, base = "Message",
		attributes =
		{
			{type = "int32", name = "petid"},
			{type = "int16", name = "datax"},
			{type = "int16", name = "datay"},
			{type = "int16", name = "dataz"},
			{type = "int16", name = "isvcoin"},
		},
	},

	{
		define = "class", name = "MsgChangePetBestAttrRequest", category = "MSG_CATEGORY_PET", id = 64, base = "Message",
		attributes =
		{
			{type = "int32", name = "petid"},
			{type = "int16", name = "isvcoin"},
		},
	},

	{
		define = "class", name = "MsgImprovePetAdvanceResponse", category = "MSG_CATEGORY_PET", id = 65, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgChangePetBestAttrResponse", category = "MSG_CATEGORY_PET", id = 66, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSetPetPickStateRequest", category = "MSG_CATEGORY_PET", id = 101, base = "Message",
		attributes =
		{
			{type = "int16", name = "state"},
		},
	},

	{
		define = "class", name = "MsgSetPetPickStateResponse", category = "MSG_CATEGORY_PET", id = 102, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSetPetPickSettingRequest", category = "MSG_CATEGORY_PET", id = 103, base = "Message",
		attributes =
		{
			{type = "int16", name = "state"},
		},
	},

	{
		define = "class", name = "MsgSetPetPickSettingResponse", category = "MSG_CATEGORY_PET", id = 104, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		},
	},

	{
		define = "class", name = "MsgSyncPetExPropDataNotify", category = "MSG_CATEGORY_PET", id = 110, base = "Message",
		attributes =
		{
			{type = "int32", name = "petid"},
			{type = "int16", name = "idx"},
			{type = "int32", name = "data"},
		},
	},

	{
		define = "class", name = "MsgRaisePetStarRequest", category = "MSG_CATEGORY_PET", id = 125, base = "Message",
		attributes =
		{		
			{type = "int32", name = "id"},
			{type = "int32", name = "star"},
		},
	},

	{
		define = "class", name = "MsgRaisePetStarResponse", category = "MSG_CATEGORY_PET", id = 126, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "id"},
			{type = "int32", name = "idx"},
			{type = "int32", name = "star"},
		},
	},
    
    {
		define = "class", name = "MsgNirvanaPetRequest", category = "MSG_CATEGORY_PET", id = 127, base = "Message",
		attributes =
		{		
			{type = "int32", name = "id"},
		},
	},
    
    {
		define = "class", name = "MsgNirvanaPetResponse", category = "MSG_CATEGORY_PET", id = 128, base = "Message",
		attributes =
		{		
			{type = "int16", name = "errcode"},
			{type = "int32", name = "id"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "reborn"},
			
		},
	},
    
    {
		define = "class", name = "MsgPetSkillNotify", category = "MSG_CATEGORY_PET", id = 129, base = "Message",
		attributes =
		{	
			{type="int32", name="sid"},
			{type="int8" , name="position"},
		},
	},
    
    {
		define = "class", name = "MsgPetSkillEquipRequest", category = "MSG_CATEGORY_PET", id = 131, base = "Message",
		attributes =
		{		
			{type = "int32", name = "sid"},
            {type = "int8", name = "position"},
		},
	},
    
    {
		define = "class", name = "MsgPetSkillEquipResponse", category = "MSG_CATEGORY_PET", id = 132, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
            {type = "int32", name = "sid"},
		},
	},
	
	{
		define = "class", name = "MsgPetSummonRequest", category = "MSG_CATEGORY_PET", id = 133, base = "Message",
		attributes =
		{		
			{type = "int32", name = "sid"},
			{type = "int32", name = "type"},
		},
	},
    
    {
		define = "class", name = "MsgPetSummonResponse", category = "MSG_CATEGORY_PET", id = 134, base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
            {type = "int32", name = "sid"},
		},
	},
	
	{
		define = "class", name = "MsgAddPetSkillNotify", category = "MSG_CATEGORY_PET", id = 135, base = "Message",
		attributes =
		{
            {type = "int32", name = "sid"},
		},
	},
	
	{
		define = "class", name = "MsgRebornPetNotify", category = "MSG_CATEGORY_PET", id = 136, base = "Message",
		attributes =
		{		
			{type = "int32", name = "id"},
			{type = "int32", name = "sid"},
			{type = "int32", name = "reborn"},	
		},
	},
}



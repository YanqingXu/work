--
--ͬս������Ϸ������һ��Ϸ������Ϣ
--

messages = {
	{
		define = "class", name = "MsgGSToGSTestRequest", category = "MSG_CATEGORY_GS_TO_GS", id = 1, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sourceGameServerId"},
		},
	},
	
	{
		define = "class", name = "MsgGSToGSTestResponse", category = "MSG_CATEGORY_GS_TO_GS", id = 2, base = "MessageEx",
		attributes =
		{
			{type="int32", name="sourceGameServerId"},
		},
	},
	{
		define = "struct", name = "CrossOtherEntityProp",
		attributes =
		{
			{type="int32", name="type"},
			{type="int32", name="value"},
		}
	},
	{
		define = "struct", name = "CrossOtherEntityStringProp",
		attributes =
		{
			{type="int32", name="type"},
			{type="string", name="value"},
		}
	},
	{
		define = "struct", name = "CrossOtherEquipInfo",
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
		define = "class", name = "MsgGetPlayerEquipInfoRequest", category = "MSG_CATEGORY_GS_TO_GS", id = 3, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "targetPid"},
			{type = "int32", name = "srcServerid"},
		},
	},
	
	{
		define = "class", name = "MsgGetPlayerEquipInfoResponse", category = "MSG_CATEGORY_GS_TO_GS", id = 4, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "targetPid"},
			{type = "string", name = "name"},
			{type = "int32"	, name = "gender"},
			{type = "int32"	, name = "clazz"},
			{type = "int32"	, name = "level"},
			{type = "int32"	, name = "zhanli"},
			{type = "int32"	, name = "reborn"},
			{type = "int32"	, name = "cloth"},
			{type = "int32"	, name = "weapon"},
			{type = "int32"	, name = "wings"},
			{type = "string", name = "guild"},
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
			{type = "int32", name = "targetServerid"},
			{type = "int32", name = "srcServerid"},
			{type = "int32", name = "vcombat", vector = true},
			{type = "CrossOtherEquipInfo", name = "equips", vector = true},
			{type = "CrossOtherEntityProp", name = "prop", vector = true},
			{type = "CrossOtherEntityStringProp", name = "sprop", vector = true},
		},
	},

	{
		define = "struct", name = "CrossOtherItemProp",
		attributes =
		{
			{type="int32", name="idx"},
			{type="int32", name="data"},
		}
	},

	{
		define = "struct", name = "CrossOtherPlayerEquip",
		attributes =
		{
			{type="int32", name="sid"},
			{type="int32", name="iid"},
			{type="int32", name="pos"},
			{type="string", name="firstowner"},
			{type="string", name="appraiser"},
			{type="CrossOtherItemProp", name="props", vector=true},
		}
	},

	{
		define = "struct", name = "CrossOtherPlayerSkill",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32", name="level"},
		}
	},

	{
		define = "class", name = "MsgNewGetPlayerEquipInfoResponse", category = "MSG_CATEGORY_GS_TO_GS", id = 5, base = "MessageEx",
		attributes =
		{
			{type = "int32", name = "targetServerid"},
			{type = "int32", name = "srcServerid"},
			{type = "int32", name = "srcPid"},
			{type = "int32", name = "targetPid"},
			{type = "int8"	, name = "gender"},
			{type = "int32"	, name = "level"},
			{type = "int64"	, name = "exp"},
			{type = "int32"	, name = "zhanli"},
			{type = "int32"	, name = "cloth"},
			{type = "int32"	, name = "weapon"},
			{type = "int32"	, name = "wings"},
			{type = "string", name = "name"},
			{type = "string", name = "guild"},
			{type = "int32", name = "lingwen"},
			{type = "int32", name = "guildpost"},
			{type = "int32", name = "job"},
			{type = "int32", name = "reborn"},
			{type = "CrossOtherPlayerEquip", name = "equips", vector = true},
			{type = "CrossOtherEntityProp", name = "prop", vector = true},
			{type = "CrossOtherEntityStringProp", name = "sprop", vector = true},
			{type = "CrossOtherPlayerSkill", name = "skill", vector = true},
			{type = "int32", name = "vcombat", vector = true},
		},
	},
}

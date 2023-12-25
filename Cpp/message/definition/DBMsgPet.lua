messages = {
	{
		define = "struct", name = "DBPetInfo",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32", name="sid"},
			{type="int16", name="type"},
			{type="string", name="name"},
			{type="int16" , name="lvl"},
			{type="int32", name ="exp"},
		}
	},
	{
		define = "struct", name = "DBPetData",
		attributes =
		{
			{type="int32", name="id"},
			{type="int32",	name="ctype"},
			{type="int32", name="data"},
		}
	},
	{
		define = "class", name="MsgDBLoadPet",category = "MSG_CATEGORY_DB_PET" , id = 1 ,base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "DBPetInfo", name = "pet_list", vector = true},
			{type = "int32", name = "pid"},
			{type = "int32", name = "load_id"},
		},
	},
	{
		define = "class",name = "MsgDBPetLoadData",category = "MSG_CATEGORY_DB_PET", id = 2, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBPetData", name = "petDatalist", vector =true},
			{type = "int32", name = "load_id"},
		},
	},
	{
		define = "class",name = "MsgDBPetCreate",category = "MSG_CATEGORY_DB_PET", id = 3, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "DBPetInfo" , name = "petInfo"},
		},
	},
	{
		define = "class",name = "MsgDBPetDelete",category = "MSG_CATEGORY_DB_PET", id = 4, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "id"},
		},
	},

	{
		define = "class", name = "MsgDBPetUpdLvlExp", category = "MSG_CATEGORY_DB_PET", id = 5, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "id"},
			{type = "int32", name = "lvl"},
			{type = "int32", name = "exp"},
		},
	},

	{
		define = "class", name = "MsgDBPetUpdName", category = "MSG_CATEGORY_DB_PET", id = 6, base = "MessageEx", salt = "pid",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "id"},
			{type = "string", name = "name"},
		},
	},

	{
		define = "class", name = "MsgDBPetUpdOwner", category = "MSG_CATEGORY_DB_PET", id = 7, base = "MessageEx", send_back = false,
		attributes =
		{
			{type = "int32", name = "oldpid"},
			{type = "int32", name = "oldid"},
			{type = "int32", name = "newpid"},
			{type = "int32", name = "newid"},
		},
	},

	{
		define = "class",name = "MsgDBPetExDataUpdate",category = "MSG_CATEGORY_DB_PET", id = 11, base = "MessageEx", salt = "pid", send_back = false,
		attributes =
		{
			{type = "int32", name = "pid"},
			{type="DBPetData", name="petExData"},
		},
	},
}

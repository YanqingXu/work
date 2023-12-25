messages =
{
	{
		define = "class", name = "MsgRegisterToCenterServer", category = "MSG_CATEGORY_CENTER", id = 1, base = "Message",
		attributes =
		{
			{type="int32", name="serverId"},
			{type="string", name="gameServerAddr"},
			{type="int32", name="gameServerPort"},
			{type="string", name="crossManagerServerAddr"},
			{type="int32", name="crossManagerServerPort"},
			{type="string", name="dbAgentAddr"},
			{type="int32", name="dbAgentPort"},
			{type="int16", name="isCrossServer"},
			{type="int16", name="isCommonCrossServer"},
			{type="int16", name="errcode"},
		}
	},
	
	{
		define = "class", name = "MsgFindNewCrossServerNotify", category = "MSG_CATEGORY_CENTER", id = 2, base = "Message",
		attributes =
		{
			{type="int32", name="serverId"},
			{type="string", name="crossServerAddr"},
			{type="int32", name="crossServerPort"},
			{type="string", name="crossManagerServerAddr"},
			{type="int32", name="crossManagerServerPort"},
			{type="int32", name="isCommonCrossServer"},
		}
	},
	
	{
		define="class", name="MsgCrossSvrInfoReport", category="MSG_CATEGORY_CENTER", id=5, base="Message",
		attributes =
		{
			{type="int32", name="serverId"},
			{type="int32", name="playerCnt"},
		},
	},
	
	{
		define = "struct" , name = "ServerInfo",
		attributes =
		{
			{type="int32", name="serverId"},
			{type="string", name="serverName"},
		},
	},
	
	{
		define = "struct" , name = "WarZoneInfoDetail",
		attributes =
		{
			{type = "int32", name = "warZoneId", desc="战区id"},
			{type = "int64", name = "warZonePreOpenTime", desc="战区的预开启时间"},
			{type = "int64", name = "warZoneOpenTime", desc="战区的正式开启时间"},
			{type = "ServerInfo", name = "gameServerInfoList", vector = true, desc="该战区内的所有游戏服信息"},
		},
	},
	
	{
		define="class", name="MsgWarZoneInfoNotify", category="MSG_CATEGORY_CENTER", id=6, base="Message",
		attributes =
		{
			{type = "WarZoneInfoDetail", name = "list", vector=true},
		},
	},
	
	{
		define="class", name="MsgWarZoneInfoUpdFinishedNotify", category="MSG_CATEGORY_CENTER", id=7, base="Message",
		attributes =
		{
		},
	},
	
	{
		define="class", name="MsgSendCrossMailFromCenterNotify", category="MSG_CATEGORY_CENTER", id=8, base="Message",
		attributes =
		{
			{type="int32", name="sourceServerId"},
			{type="int32", name="pid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		},
	},
	
	{
		define="class", name="MsgSendCrossMailFromCenter", category="MSG_CATEGORY_CENTER", id=9, base="Message",
		attributes =
		{
			{type="int32", name="pid"},
			{type="string", name="title"},
			{type="string", name="content"},
			{type="string", name="items"},
			{type="int32", name="opcode"},
			{type="int32", name="ctime"},
		},
	},
}
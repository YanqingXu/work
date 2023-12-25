messages =
{
	{
		define = "struct", name = "PlayerInfo",
		attributes =
		{
			{type = "int32", name="pid", desc = "玩家角色ID"},
			{type = "int16", name="reborn", desc = "转生"},
			{type = "int16", name="level", desc = "等级"},
			{type = "string", name="PlayerName", desc = "玩家名称"},
			{type = "int8" , name="Gender", desc = "玩家性别"},
			{type = "int8",  name="mclass", desc = "玩家等级"},
			{type = "int16", name="sid"},
			{type = "int16", name="sceneid", desc = "玩家所在场景ID"},
			{type = "int16", name="posx", desc = "玩家位置"},
			{type = "int16", name="posy", desc = "玩家位置"},
			{type = "int32", name= 	"cloth", desc = "玩家服装"},
			{type = "int32", name = "weapon", desc = "玩家武器"},
			{type = "int32", name = "wings", desc = "玩家翅膀"},
			{type = "int32", name = "is_transfer", desc = "是否转过职"},
		}
	},

	{
		define = "class", name = "MsgEnterServerRequest", category = "MSG_CATEGORY_LOGIN", id = 1, base = "Message",
		attributes =
		{
			{type = "string", name = "fullChannelId", desc = "渠道ID"},
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name ="channelId", desc = "渠道ID"},
			{type = "int32", name = "platformId", desc = "平台ID"},
			{type = "string", name = "deviceId", desc = "设备ID"},
			{type = "int32", name = "token", desc = "令牌"},
			{type = "int32", name = "serverID", desc = "选择的服务器ID"},
		}
	},

	{
		define = "class", name = "MsgEnterServerResponse", category = "MSG_CATEGORY_LOGIN", id = "2", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode", desc = "错误码"},
			{type = "PlayerInfo", name = "PlayerList", vector = true, desc = "角色列表"},
			{type = "int16", name = "cross_server", desc = "是否是跨服"},
		}
	},

	{
		define = "class", name = "MsgCreatePlayerRequest", category = "MSG_CATEGORY_LOGIN", id = "5", base = "Message",
		attributes =
		{
			{type = "string",name="PlayerName"},
			{type = "int8",  name="career"},
			{type = "int8",  name="gender"},
			{type = "string",  name="code"},
			{type = "int32", name = "serverID", desc = "创角的服务器ID"},	
		}
	},

	{
		define = "class", name = "MsgCreatePlayerResponse", category = "MSG_CATEGORY_LOGIN", id = "6", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode" },
			{type = "int32", name = "pid"},
			{type = "int32", name = "ctime"},
		}
	},

	{
		define = "class", name = "MsgEnterGameRequest", category = "MSG_CATEGORY_LOGIN", id = "7" , base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		}
	},

	{
		define = "class", name = "MsgEnterGameResponse", category = "MSG_CATEGORY_LOGIN", id = "8", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "ctime"},
		}
	},

	{
		define = "class", name = "MsgDeletePlayerRequest", category= "MSG_CATEGORY_LOGIN",id = "9", base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "serverID", desc = "创角的服务器ID"},
		}
	},

	{
		define = "class", name = "MsgDeletePlayerResponse", category= "MSG_CATEGORY_LOGIN",id = "10", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
			{type = "int32", name = "pid"},
		}
	},

	{
		define = "class", name = "MsgPlayerReconnectRequest", category= "MSG_CATEGORY_LOGIN",id = "11", base = "Message",
		attributes =
		{
			{type = "int32", name="aid"},
			{type = "int32", name = "pid"},
		}
	},

	{
		define = "class", name = "MsgPlayerReconnectResponse", category= "MSG_CATEGORY_LOGIN",id = "12", base = "Message",
		attributes =
		{
			{type = "int16", name = "errcode"},
		}
	},

	{
		define = "class", name = "MsgPlayerQuitNotify", category= "MSG_CATEGORY_LOGIN",id = "13", base = "Message",
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgBeKicked", category = "MSG_CATEGORY_LOGIN", id = 14, base = "Message",
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgTimeNotify", category = "MSG_CATEGORY_LOGIN", id = 15, base = "Message",
		attributes =
		{
			{type = "int32", name = "time"},
			{type = "int32", name = "random"},
		}
	},
	
	{
		define = "class", name = "MsgEnterGameWithNoLoginRequest", category = "MSG_CATEGORY_LOGIN", id = 16 , base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
			{type = "int32", name = "pid"},
		}
	},

	{
		define = "class", name = "MsgPing", category= "MSG_CATEGORY_LOGIN",id = "50", base = "Message",canSendToCrossFromCli=true,
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgPong", category= "MSG_CATEGORY_LOGIN",id = "51", base = "Message",
		attributes =
		{
		}
	},

	{
		define = "class", name = "MsgGSASPing", category = "MSG_CATEGORY_LOGIN", id = 52, base = "Message",
		attributes =
		{
			{type = "string", name = "PingID"},
		},
	},

	{
		define = "class", name = "MsgGSASPong", category = "MSG_CATEGORY_LOGIN", id = 53, base = "Message",
		attributes =
		{
			{type = "string", name = "PingID"},
		},
	},

	{
		define = "class", name = "MsgPlayerLoadedNotify" , category = "MSG_CATEGORY_LOGIN", id = 70, base = "Message",
		attributes =
		{
			{type = "int32", name =  "pid" },
			{type = "int32", name =  "load_id" },
			{type = "int16", name = "isinit"},
		},
	},
	
	{
		define = "class", name = "MsgPlayerLoginSceneNotify" , category = "MSG_CATEGORY_LOGIN", id = 71, base = "Message",
		attributes =
		{
			{type = "int32", name =  "sceneid" },
		},
	},

	{
		define = "class", name = "MsgServerQueueNotify" , category = "MSG_CATEGORY_LOGIN", id = 80, base = "Message",
		attributes =
		{
			{type ="int32", name = "queueposition" },
			{type ="int32", name = "remaintimeestimate" },
		},
	},

	{
		define = "class", name = "MsgServerQueueReset", category = "MSG_CATEGORY_LOGIN", id =  90, base = "Message",
		attributes =
		{
		},
	},

	{
		define = "class", name = "MsgGetPlayerCreateTimeRequest", category = "MSG_CATEGORY_LOGIN", id = 91, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
		},
	},

	{
		define = "class", name = "MsgGetPlayerCreateTimeResponse", category = "MSG_CATEGORY_LOGIN", id = 92, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "ctime"},
		},
	},
	
	{
		define = "class", name = "MsgGMPlayerControlRequest", category = "MSG_CATEGORY_LOGIN", id = 100, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "opcode"},
		},
	},

	-- Before enter server, this message will be sent to ams for authentication
	{
		define = "class", name = "MsgAccountAuthRequest", category = "MSG_CATEGORY_LOGIN", id = 161, base = "Message",
		attributes =
		{
			-- session id, ams should send the same thing back to me
			-- even the account is invalid
			{type = "int32", name = "sid"},
			-- account id, ams will check if this account is valid
			{type = "int32", name = "aid"},
			-- a token generated by ams
			{type = "int32", name = "token"},
			-- if the account is valid, ams should send back the same thing back to me
			-- on the following fields
			{type = "int32", name = "channelId"},
			{type = "int32", name = "platformId"},
			{type = "string", name = "fullChannelId"},
			{type = "string", name = "deviceId"},
			{type = "int32", name = "serverID"},
		},
	},

	{
		define = "class", name = "MsgAccountAuthResponse", category = "MSG_CATEGORY_LOGIN", id = 162, base = "Message",
		attributes =
		{
			-- if this valud is 1, the authentication is successful
			{type = "int16", name = "success", desc = "1-成功, 其他-失败"},
			-- ams should alwasy send the same value back as that in the request
			{type = "int32", name = "sid"},
			-- ams should send back the same thing to me if the auth succeed
			{type = "int32", name = "aid"},
			{type = "int32", name ="channelId"},
			{type = "int32", name = "platformId"},
			{type = "string", name = "fullChannelId"},
			{type = "string", name = "deviceId"},
			{type = "int32", name = "serverID"},
		},
	},


	--切换服务器通知
	{
		define = "class", name = "MsgChangeServerNotify", category = "MSG_CATEGORY_LOGIN", id = 103, base = "Message",
		attributes =
		{
			{type = "string", name = "addr", desc = "目标服务器地址"},
			{type = "int32", name = "port", desc = "目标服务器端口"},
			--{type = "int32", name = "is_cross_server", desc = "是否是跨服服务器"},
			{type = "int32", name = "aid", desc = "账号ID"},
			{type = "int32", name = "serverID", desc = "选择的服务器ID"},
			{type = "int32", name = "pid", desc = "角色ID"},
		}
	},
	
	{
		define = "class", name = "MsgPlayerAuthRequest", category = "MSG_CATEGORY_LOGIN", id = 104, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},	
		},
	},

	{
		define = "class", name = "MsgPlayerAuthResponse", category = "MSG_CATEGORY_LOGIN", id = 105, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},
			{type = "int32", name = "ctime", desc = "解封时间，如果角色未被禁，置0"},
		},
	},
	
	{
		define = "class", name = "MsgPlayerAuthRequestEx", category = "MSG_CATEGORY_LOGIN", id = 434, base = "Message",
		attributes =
		{
			{type = "int32", name = "aid"},
			{type = "int32", name = "pid"},	
			{type = "int32", name = "channelId"},	
		},
	},
	{
		define = "class", name = "MsgChangeJobRequest", category = "MSG_CATEGORY_LOGIN", id = 106, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},	
			{type = "int32", name = "job"},
		},
	},
	{
		define = "class", name = "MsgChangeJobResponse", category = "MSG_CATEGORY_LOGIN", id = 107, base = "Message",
		attributes =
		{
			{type = "int32", name = "pid"},
			{type = "int32", name = "job"},	
		},
	},

}


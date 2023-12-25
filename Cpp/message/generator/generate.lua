
require 'table'
require 'compile'

files =
{
	--客户端服务器消息定义
	"MsgAuth.lua",
	"MsgLogin.lua",
	"MsgScene.lua",
	"MsgPlayer.lua",
	"MsgItem.lua",
	"MsgQuest.lua",
	"MsgGuild.lua",
	"MsgPet.lua",
	"MsgTest.lua",
	"MsgShop.lua",
	"MsgTrade.lua",
	"MsgTeam.lua",
	"MsgWorld.lua",
	"MsgRelationship.lua",
	"MsgGMaster.lua",
	"MsgMail.lua",
	"MsgSystemInfo.lua",
	"MsgConsignment.lua",
	"MsgHoliday.lua",
	"MsgChat.lua",
	"MsgWarZoneBroadcast.lua",
	"MsgZhanDui.lua",
	--数据库消息定义
	"DBMsgAuth.lua",
	"DBMsgLogin.lua",
	"DBMsgPlayer.lua",
	"DBMsgItem.lua",
	"DBMsgQuest.lua",
	"DBMsgGuild.lua",
	"DBMsgPet.lua",
	"DBMsgTest.lua",
	"DBMsgWorld.lua",
	"DBMsgRelationship.lua",
	"DBMsgRecords.lua",
	"DBMsgMail.lua",
	"DBMsgArena.lua",
	"DBMsgConsignment.lua",
	"DBMsgHoliday.lua",
	"DBMsgZhanDui.lua",
	
	--管理服消息
	"MsgCenter.lua",
	
	--跨服消息定义
	"MsgCross.lua",
	"DBMsgCross.lua",
	
	--游戏服到同战区游戏服的消息定义
	"MsgGSToGS.lua",
	"MsgHttp.lua",
	"MsgControl.lua",
	
	-- 服务器内部消息
	"MsgServerLogic.lua",
	-- 中心服务器数据库消息
	"DBMsgCenter.lua",
}

messages = {}
messages_all = {}
messages_db = {}

for _, filename in ipairs(files) do
	local ifilename = "../definition/"..filename
	local ofilename = "../" .. filename
	ofilename = ofilename:gsub(".lua", ".h")
	
	compile("MsgTemplate.h", ifilename, ofilename)
	
	for _, msg in ipairs(messages) do
		if msg.define == "class" then
			table.insert(messages_all, msg)
		end
	end
end

compile("MsgRegisterTemplate.cpp", "", "../MsgRegister.cpp")

messages = nil

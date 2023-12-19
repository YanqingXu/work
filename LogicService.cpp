#include "LogicService.h"
#include "MainLua.h"
#include "Application.h"
#include "NetService.h"
#include "MsgLua.h"
#include "Database.h"

#include "Login/LoginMsgHandler.h"
#include "Scene/SceneMsgHandler.h"
#include "Player/PlayerMsgHandler.h"
#include "Item/ItemMsgHandler.h"
#include "Quest/QuestMsgHandler.h"
#include "Guild/GuildMsgHandler.h"
#include "ZhanDui/ZhanDuiMsgHandler.h"
#include "Test/TestMsgHandler.h"
#include "World/WorldMsgHandler.h"
#include "Shop/ShopMsgHandler.h"
#include "Trade/TradeMsgHandler.h"
#include "Team/TeamMsgHandler.h"
#include "Relationship/RelationshipMsgHandler.h"
#include "Cross/CSMsgHandler.h"
#include "Cross/GSMsgHandler.h"
#include "Mail/MailMsgHandler.h"
#include "Consignment/ConsignmentMsgHandler.h"
#include "Auction/AuctionMsgHandler.h"
#include "message/DBMsgConsignment.h"
#include "message/DBMsgItem.h"
#include "message/DBMsgHoliday.h"
#include "message/MsgAuth.h"
#include "message/MsgGMaster.h"
#include "message/DBMsgWorld.h"
#include "message/DBMsgCross.h"
#include "Entity/EntityLua.h"
#include "Entity/EntityOperationHelper.h"
#include "Entity/WorldPlayerManager.h"
#include "Combat/CombatLua.h"
#include "Item/ItemLua.h"
#include "Scene/SceneLua.h"
#include "Quest/QuestLua.h"
#include "Quest/QuestOperationHelper.h"
#include "Skill/SkillLua.h"
#include "Gene/GeneLua.h"
#include "Gene/GeneFactory.h"
#include "World/World.h"
#include "World/WorldLua.h"
#include "World/SwitchManager.h"
#include "OperationHelper.h"
#include "Guild/GuildLua.h"
#include "Guild/GuildMgr.h"
#include "ZhanDui/ZhanDuiMgr.h"
#include "Admin/AdminModule.h"
#include "Team/TeamManager.h"
#include "Holiday/HolidayLua.h"
#include "Holiday/HolidayManager.h"
#include "Holiday/HolidayMsgHandler.h"
#include "Player/PlayerMsgKeepManager.h"
#include "Consignment/ConsignmentStore.h"
#include "Login/LoginHelper.h"
#include "Event/EventLua.h"
#include "Rank/RankLua.h"
#include "Rank/RankItemLua.h"
#include "Rank/RankManager.h"
#include "Rank/RankMsgHandler.h"
#include "ZhanDui/ZhanDuiLua.h"

#include <windows.h>
#include <psapi.h>
#pragma comment(lib,"psapi.lib")

static std::set<int> g_load_set;

template<typename T>
void sendLoadMessage()
{
	int key = ((T::Category << 16) | T::Id);
	if (g_load_set.find(key) != g_load_set.end() )
	{
		return;
	}

	g_load_set.insert(key);

	T *msg = new T;
	g_app.postToNetService(msg);
}


LogicService::LogicService()
{
	m_message_time = 0;

	__super::registerMessageHandler(MsgGSAuthToASResponse::Category, MsgGSAuthToASResponse::Id, std::bind(&LogicService::onGSAuthToASResponse, this, std::placeholders::_1));
	__super::registerMessageHandler(MsgServerInfoResponse::Category, MsgServerInfoResponse::Id, std::bind(&LogicService::onServerInfoResponse, this, std::placeholders::_1));
}

LogicService::~LogicService()
{
}

void LogicService::init()
{

}

void LogicService::onStart()
{

}

void LogicService::onStop()
{
	g_rank_mgr.clear();
	g_world_player_mgr.for_each([](Entity *entity){
		 
		EntityPlayer* player = (EntityPlayer*)entity;
		if (player )
		{
			player->saveAutoInfo();
		} 
	});

	g_guild_mgr.clear();
	g_world.clear();
	g_switch_mgr.clear();
	g_team_mgr.clear();
	g_guild_mgr.clear();
	g_world.clear();
	g_switch_mgr.clear();
	g_team_mgr.clear();	
	EntityOperationHelper::clear();
	LOG_INFO("g_scene_mgr.deleteAllScenes()");
	g_scene_mgr.deleteAllScenes();

	if (g_gene_factory != nullptr)
	{
		delete g_gene_factory;
		g_gene_factory = nullptr;
	}

	for (size_t i = 0; i < m_modules.size(); ++i)
	{
		Module *module = m_modules[i];

		delete module;
	}
	m_modules.clear();

	LOG_INFO("close lua");
	if (lua::L != nullptr)
	{
		lua::gc(lua::L);
		lua::close(lua::L);
	}

	QuestOperationHelper::cleanFunctiononNPC();
	SkillHelper::clearGlobalItemSkills();
}

void LogicService::broadcast(Message *message)
{
	if (message == NULL)
	{
		LOG_ERROR("message is null");
		return;
	}

	std::vector<int> sessions;

	g_world_player_mgr.for_each([&sessions](Entity *entity){
		if ((entity->getState() != ENTITY_STATE_OFFLINE) &&(entity->getSessionID()>0))
		{
			sessions.push_back(entity->getSessionID());
		}
	});

	MsgMulticast *msg = new MsgMulticast;
	msg->m_message = message;
	msg->m_sessions = sessions;
	g_app.postToNetService(msg);
}

void LogicService::keepMessage(stcChatKeepInfo message)
{
	g_msg_keep_mgr.AddMsgKeep(ENTITY_PROP_CHAT_CODE,CHAT_TYPE_WORLD,message);
}

void LogicService::registerMessageHandler(int msgcat, int msgid, int ref)
{
	m_handler_map[(msgcat << 16) | msgid].push_back(ref);
}

void LogicService::onMessage(Message *message)
{
	uint64 previous = get_tick_count();

	OperationHelper::setOpCode(OP_UNKNOWN);

	__super::onMessage(message);

	int msgcat = message->getCategory();
	int msgid = message->getID();
	auto it = m_handler_map.find((msgcat << 16) | msgid);
	if (it != m_handler_map.end())
	{
		EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
		if (player == NULL)
		{
			LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		}
		else
		{
			for (size_t i = 0; i < it->second.size(); ++i)
			{
				lua::getref(lua::L, it->second[i]);
				lua::call(lua::L, nullptr, player, message);
				lua::pop(lua::L, 1);
			}
		}
	}

	if (g_load_set.size() > 0)
	{
		int key = ((msgcat << 16) | msgid);
		g_load_set.erase(key);
		if (g_load_set.size() == 0)
		{
			onDataLoaded();
		}
	}

	delete message;
	message = NULL;

	m_message_time += (int)(get_tick_count() - previous);
}

void LogicService::onServerInfoResponse(Message *message)
{
	MsgServerInfoResponse *msg = dynamic_cast<MsgServerInfoResponse*>(message);
	if (!msg)
	{
		return;
	}
	if (msg->serverName == g_world.getServerName())
	{
		return;
	}
	if (msg->serverName != "")
	{
		g_world.setServerName(msg->serverName);
	}
}

//注册服务器结果
void LogicService::onGSAuthToASResponse(Message *message)
{
	MsgGSAuthToASResponse *msg = dynamic_cast<MsgGSAuthToASResponse*>(message);
	if (!msg)
	{
		return;
	}

	if (msg->mID <= 0)
	{
		LOG_INFO("invalid world id", msg->mID);
		exit(0);
		return;
	}

	if (msg->mID == g_world.getID())
	{
		return;
	}

	LOG_INFO("world id: %d", msg->mID);

	g_config.server_id = msg->mID;
	g_world.setID(msg->mID);

	MsgDBServerID *dbmsg = new MsgDBServerID;
	dbmsg->server_id = msg->mID;
	dbmsg->register_server_id = 1;
	g_app.postToNetService(dbmsg);

	bool isCrossServer = g_config.isCrossServer();
	if(!isCrossServer)
	{
		MsgGetSensitiveWordsRequest *request = new MsgGetSensitiveWordsRequest;
		request->serverid = msg->mID;
		g_app.postToNetService(request);
	}
	else
	{
		if(g_config.getWarZoneCounts() > 0)
		{
			g_scene_mgr.initialize();
		}
	}

	g_gene_factory = new GeneFactory;
	g_gene_factory->initialize();

	lua::L = lua::open();
	lua::dostring(lua::L, "gdGame = {}");

	lua::openlog(lua::L);
	lua::openscene(lua::L);
	lua::opencombat(lua::L);
	lua::openitem(lua::L);
	lua::openentity(lua::L);
	lua::openquest(lua::L);
	lua::openworld(lua::L);
	lua::openskill(lua::L);
	lua::openguild(lua::L);
	lua::opengene(lua::L);
	lua::openmsg(lua::L);
	lua::openholiday(lua::L);
	lua::openRankItem(lua::L);
	lua::openRank(lua::L);
	lua::openevent(lua::L);
	lua::openzhandui(lua::L);


	//加载脚本
	lua::dostring(lua::L, "require 'script/main'");

	//调用脚本初始化函数
	lua::call(lua::L, "init");

	g_database.load();

	registerModule<LoginMsgHandler>();
	registerModule<WorldMsgHandler>();
	registerModule<SceneMsgHandler>();
	registerModule<TradeMsgHandler>();
	registerModule<PlayerMsgHandler>();
	registerModule<ItemMsgHandler>();
	registerModule<QuestMsgHandler>();
	registerModule<TestMsgHandler>();
	registerModule<ShopMsgHandler>();
	registerModule<TeamMsgHandler>();
	registerModule<RelationshipMsgHandler>();
	registerModule<CSMsgHandler>();
	registerModule<GSMsgHandler>();
	registerModule<MailMsgHandler>();
	registerModule<AdminModule>();
	registerModule<GuildMsgHandler>();
	registerModule<ConsignmentMsgHandler>();
	registerModule<HolidayMsgHandler>();
	registerModule<RankMsgHandler>();
	registerModule<ZhanDuiMsgHandler>();

	sendLoadMessage<MsgDBLoadWorldData>();
	sendLoadMessage<MsgDBLoadChannelProps>();
	sendLoadMessage<MsgDBLoadTeams>();
	sendLoadMessage<MsgDBLoadAuthRewardIDRequest>();
	sendLoadMessage<MsgDBLoadSwitch>();
	sendLoadMessage<MsgDBGuildLoad>();
	sendLoadMessage<MsgDBGuildExDataLoad>();
	sendLoadMessage<MsgDBGuildApplicationLoad>();
	sendLoadMessage<MsgDBGuildMemberLoad>();
	sendLoadMessage<MsgDBGuildLeagueLoad>();
	sendLoadMessage<MsgDBGuildLeagueAppLoad>();
	sendLoadMessage<MsgDBGuildRecordLoad>();
	sendLoadMessage<MsgDBGuildRedLoad>();
	sendLoadMessage<MsgDBGuildRedRecordLoad>();
	sendLoadMessage<MsgDBLoadGuildItems>();
	sendLoadMessage<MsgDBLoadGuildGuishi>();
	sendLoadMessage<MsgDBLoadConsignments>();
	sendLoadMessage<MsgDBHolidayLoad>();
	sendLoadMessage<MsgDBHolidayGradeLoad>();
	sendLoadMessage<MsgDBHolidayItemLoad>();
	sendLoadMessage<MsgDBHolidayPropIntLoad>();
	sendLoadMessage<MsgDBHolidayPropStringLoad>();
	sendLoadMessage<MsgDBLoadAllAcution>();
	sendLoadMessage<MsgDBLoadNextIDs>();
	sendLoadMessage<MsgDBZhanDuiLoad>();
	sendLoadMessage<MsgDBZhanDuiExDataLoad>();
	sendLoadMessage<MsgDBZhanDuiMemberLoad>();
	sendLoadMessage<MsgDBZhanDuiApplicationLoad>();
	sendLoadMessage<MsgDBZhanDuiRecordLoad>();

	if (g_config.isCrossServer())
	{
		sendLoadMessage<MsgDBKF3V3ZhanDuiLoad>();
		sendLoadMessage<MsgDBKF3V3ZhanDuiMemberLoad>();
		sendLoadMessage<MsgDBKF3V3RecordLoad>();
	}
}

//数据加载完成
void LogicService::onDataLoaded()
{
	LOG_INFO("world data loaded");
	lua::call(lua::L, "Event.worldDataBuilder");

	g_world.setWarZoneModuleLogLevel();
	bool isCrossServer = g_config.isCrossServer();
	if(!isCrossServer)
	{
		lua::call(lua::L, "initChatData");
		LoginHelper::loadAllTuoguanPlayers();
	}
	for (size_t i = 0; i < m_modules.size(); ++i)
	{
		Module *module = m_modules[i];
		module->initialize();
	}

	schedule_timer(0, 30, std::bind(&LogicService::onFrameTimer, this, std::placeholders::_1));
	schedule_timer(0, 1000, std::bind(&LogicService::onSecondTimer, this, std::placeholders::_1));
	schedule_timer(0, 1000, std::bind(&LogicService::onLuaGcSecondTimer, this, std::placeholders::_1));
	schedule_timer(0, 60000, std::bind(&LogicService::onMinuteTimer, this, std::placeholders::_1));
	schedule_timer(0, 600000, std::bind(&LogicService::onUpdateWorldDataTimer, this, std::placeholders::_1));

	
	if(!isCrossServer)
	{
		g_rank_mgr.initialize();
		lua::call(lua::L,"_G.clearDBBKItems");
	}
	g_app.GetNetService()->startServer();

}

void LogicService::onFrameTimer(size_t elapse)
{
	g_scene_mgr.update((int)elapse);
}

void LogicService::onLuaGcSecondTimer(size_t elapse)
{
	//调用lua的垃圾回收
	lua::gc(lua::L);
}


void LogicService::onSecondTimer(size_t elapse)
{
	//更新事件
	lua::call(lua::L, "Event.onUpdate");
	if(!g_config.isCrossServer())
	{
		//合服活动
		// lua::call(lua::L, "Event.HfhdonUpdate");

		g_guild_mgr.update((int)elapse);
		g_consignment_store.update((int)elapse);
	}
	g_holiday_mgr.update((int)elapse);
}

void LogicService::onUpdateWorldDataTimer(size_t elapse)
{
	g_world.update((int)elapse);
}

void LogicService::onMinuteTimer(size_t elapse)
{ 
	g_scene_mgr.dump();

	if (m_queue_counter > _SERVICE_QUEUE_LIMIT_)
	{
		LOG_WARN("logic service queue size: %d", (int)m_queue_counter);
	}
	OperationHelper::recordLogicMessageStatistics(m_queue_counter, (int)elapse, m_message_time, g_world_player_mgr.getPlayerCount());
	m_message_time = 0;

	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	LOG_INFO("Memory using: %dK/%dK + %dK/%dK",
		pmc.WorkingSetSize / 1024, pmc.PeakWorkingSetSize / 1024, pmc.PagefileUsage / 1024, pmc.PeakPagefileUsage / 1024);
	OperationHelper::recordMemory((int)pmc.WorkingSetSize / (1024 * 1024), (int)pmc.PeakWorkingSetSize /(1024 * 1024));
}

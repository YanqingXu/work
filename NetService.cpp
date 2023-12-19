#include "stdafx.h"
#include "windows.h"
#include "NetService.h"
#include "common/TCPClient.h"
#include "common/TCPServer.h"
#include "common/TCPProtocol16.h"
#include "common/TCPProtocol32.h"
#include "message/MsgLogin.h"
#include "message/MsgAuth.h"
#include "message/MsgTest.h"
#include "message/MsgCross.h"
#include "message/MsgCenter.h"
#include "message/MsgServerLogic.h"
#include "message/MsgWorld.h"
#include "message/DBMsgWorld.h"
#include "Application.h"
#include "World/World.h"
#include "Entity/WorldPlayerManager.h"
#include "Scene/SceneManager.h"

#define SESSION_BREAK_TIME	30

NetService::NetService() :
	m_accelerator_ping_count(5),
	m_accelerator_ping_average(4000),
	m_dblist_lock(false),
	m_crossserver_list_lock(false)
{
	m_client_server = new TCPServer("client server", this);
	m_admin_server = new TCPServer("admin server", this);
	m_auth_client = new TCPClient("auth client", this);
	m_dbagent_client = new TCPClient("dbagent client", this);
	m_chat_client = new TCPClient("chat client", this);
	if(g_config.isCrossServer())
	{
		m_cross_manager_server = new TCPServer("cross manager server", this);
	}
	else
	{
		m_cross_manager_server = nullptr;
	}
	m_center_client = new TCPClient("center client", this);
	m_center_client->setDisconnectDiscard(true);

	m_center_update = false;
	gsManagerServerStart = false;
}

NetService::~NetService()
{
	delete m_client_server;
	delete m_auth_client;
	delete m_admin_server;
	delete m_dbagent_client;
	delete m_chat_client;
	delete m_center_client;
	if(m_cross_manager_server != nullptr)
	{
		delete m_cross_manager_server;
	}
	
	for(auto iter = m_dbagent_client_list.begin(); iter != m_dbagent_client_list.end(); iter++)
	{
		TCPClient* dbagent = iter->second;
		if(dbagent != nullptr)
		{
			delete dbagent;
		}
	}

	m_dbagent_client_list.clear();

	for(auto iter = m_cross_server_client_list.begin(); iter != m_cross_server_client_list.end(); iter++)
	{
		TCPClient* crossServerClient = iter->second;
		if(crossServerClient != nullptr)
		{
			delete crossServerClient;
		}
	}

	m_cross_server_client_list.clear();
}

void NetService::init()
{
	//m_last_check_session_time = time(nullptr);

	//数据库代理服务器客户端
	m_dbagent_client->start(g_config.getDBAgentHost().c_str(), g_config.getDBAgentPort(),
		TCPProtocol32(),
		std::bind(&NetService::onDBAgentSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, 0),
		std::bind(&NetService::onDBAgentSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onDBAgentSessionRecv, this, std::placeholders::_1));

	//验证服务器客户端
	m_auth_client->start(g_config.getAuthHost().c_str(), g_config.getAuthPort(),
		TCPProtocol16(),
		std::bind(&NetService::onAuthSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onAuthSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onAuthSessionRecv, this, std::placeholders::_1));

	//聊天服务器
	if (g_config.getChatInuse())
	{
		m_chat_client->start(g_config.getChatHost().c_str(), g_config.getChatPort(),
			TCPProtocol16(),
			std::bind(&NetService::onChatSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
			std::bind(&NetService::onChatSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
			std::bind(&NetService::onChatSessionRecv, this, std::placeholders::_1));
	}
}

void NetService::connectToDbAgent(std::string ip, int port, int gameServerId)
{
	auto iter = m_dbagent_client_list.find(gameServerId);
	if(iter != m_dbagent_client_list.end())
	{
		return;
	}
	m_dblist_lock = true;
	TCPClient* client = new TCPClient("dbagent client", this);

	client->start(ip.c_str(), port,
		TCPProtocol32(),
		std::bind(&NetService::onDBAgentSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, gameServerId),
		std::bind(&NetService::onDBAgentSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onDBAgentSessionRecv, this, std::placeholders::_1));

	m_dbagent_client_list[gameServerId] = client;

	m_dblist_lock = false;
}

void NetService::connectToCrossServer(std::string ip, int port, int crossServerId)
{
	auto iter = m_cross_server_client_list.find(crossServerId);
	if(iter != m_cross_server_client_list.end())
	{ 
		return;
	}
	m_crossserver_list_lock = true;
	 
	TCPClient* client = new TCPClient("cross server client", this);
	 

	client->start(ip.c_str(), port,
		TCPProtocol32(),
		std::bind(&NetService::onCrossServerSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, crossServerId),
		std::bind(&NetService::onCrossServerSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, crossServerId),
		std::bind(&NetService::onCrossServerSessionRecv, this, std::placeholders::_1));

	client->setDisconnectDiscard(true);

	m_cross_server_client_list[crossServerId] = client;
	LOG_INFO("CS_MODULE_INFO: connecting to corssServer, crossServerInfo = {serverId = %d, crossManagerServerAddr = %s, crossManagerServerPort = %d}",
		crossServerId, ip.c_str(), port);
	m_crossserver_list_lock = false;
}


void NetService::getCrossServerInfo(int crossServerId, CrossServerInfo& info)
{
	auto iter = m_cross_server_info.find(crossServerId);
	if(iter != m_cross_server_info.end())
	{
		info = iter->second;
	}
};

void NetService::onStart()
{
}

void NetService::onStop()
{
	m_client_server->stop();
	m_admin_server->stop();
	m_dbagent_client->stop();

	if(m_cross_manager_server != nullptr)
	{
		m_cross_manager_server->stop();
	}

	for(auto iter = m_dbagent_client_list.begin(); iter != m_dbagent_client_list.end(); iter++)
	{
		TCPClient* dbagent = iter->second;
		if(dbagent != nullptr)
		{
			dbagent->stop();
		}
	}

	for(auto iter = m_cross_server_client_list.begin(); iter != m_cross_server_client_list.end(); iter++)
	{
		TCPClient* crossServerClient = iter->second;
		if(crossServerClient != nullptr)
		{
			crossServerClient->stop();
		}
	}
}

void NetService::onUpdate(int elapse)
{
	m_dbagent_client->update(elapse);

	if(!m_dblist_lock)
	{  
		for(auto iter = m_dbagent_client_list.begin(); iter != m_dbagent_client_list.end(); iter++)
		{
			if(m_dblist_lock)
			{
				break;
			}
			TCPClient* dbagent = iter->second;
			if(dbagent != nullptr)
			{
				if(g_world.getWarZoneIdByGameServeID(iter->first) > 0 || g_config.isCommonCrossServer())
				{
					dbagent->update(elapse);
				}
			}
		}
	}
	if(!m_crossserver_list_lock)
	{
		for(auto iter = m_cross_server_client_list.begin(); iter != m_cross_server_client_list.end(); iter++)
		{
			if(m_crossserver_list_lock)
			{
				break;
			}
			TCPClient* crossServerClient = iter->second;
			if(crossServerClient != nullptr)
			{
				crossServerClient->update(elapse);
			}
		}
	}


	if (m_center_update)
	{
		m_center_client->update(elapse);
	}
	m_auth_client->update(elapse);

	if (g_config.getChatInuse())
	{
		if (m_chat_client->isDisconnected())
		{
			m_chat_client->start(g_config.getChatHost().c_str(), g_config.getChatPort(),
				TCPProtocol16(),
				std::bind(&NetService::onChatSessionConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
				std::bind(&NetService::onChatSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
				std::bind(&NetService::onChatSessionRecv, this, std::placeholders::_1));
		}
		else
		{
			m_chat_client->update(elapse);
		}
	}

	
}

void NetService::startServer()
{
	m_center_client->start(g_config.getCenterHost().c_str(), g_config.getCenterPort(),
		TCPProtocol32(),
		std::bind(&NetService::onCenterClientConnect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onCenterClientClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onCenterClientRecv, this, std::placeholders::_1));
	m_center_update = true;

	m_admin_server->start(g_config.getAdminHost().c_str(), g_config.getAdminPort(),
		TCPProtocol16(),
		std::bind(&NetService::onAdminSessionAccept, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onAdminSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onAdminSessionRecv, this, std::placeholders::_1),
		30);

	m_client_server->start(g_config.getGameHost().c_str(), g_config.getGamePort(),
		TCPProtocol16(),
		std::bind(&NetService::onClientSessionAccept, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onClientSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
		std::bind(&NetService::onClientSessionRecv, this, std::placeholders::_1),
		30, 100, true);
}

void NetService::startGSManagerServer()
{
	if(g_config.isCrossServer() && !gsManagerServerStart)
	{
		m_cross_manager_server->start(g_config.getCrossManagerHost().c_str(), g_config.getCrossManagerPort(),
			TCPProtocol32(),
			std::bind(&NetService::onCrossManagerSessionAccept, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
			std::bind(&NetService::onCrossManagerSessionClose, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
			std::bind(&NetService::onCrossManagerSessionRecv, this, std::placeholders::_1));

		gsManagerServerStart = true;
	}
}

void NetService::stopClientServer()
{
	m_client_server->stop();
}

void NetService::onMessage(Message *message)
{
	if (message == nullptr)
	{
		LOG_ERROR("invalid message");
		return;
	}

	if (message->getCategory() == MSG_CATEGORY_CONTROL)
	{
		//控制消息,
		onControlMsg(message);
	}
	else if (message->getCategory() == MSG_CATEGORY_GM)
	{
		if (message->getSessionID() == 0)
		{
			//GM命令转发给验证服务器
			m_auth_client->send(message);
		}
		else
		{
			//原checkserver消息
			m_admin_server->send(message);
		}
	}
	else if(message->getCategory() == MSG_CATEGORY_CHAT)
	{
		if (g_config.getChatInuse() && m_chat_client->isConnected())
		{
			m_chat_client->send(message);
		}
	}
	else if (((message->getCategory() == MsgAccountAuthRequest::Category) &&
		(message->getID() == MsgAccountAuthRequest::Id)) ||
		((message->getCategory() == MsgPlayerAuthRequest::Category) &&
		(message->getID() == MsgPlayerAuthRequest::Id)) ||
		((message->getCategory() == MsgPlayerAuthRequestEx::Category) &&
		(message->getID() == MsgPlayerAuthRequestEx::Id)))
	{
		//GM命令转发给验证服务器
		if (m_auth_client->isConnected())
		{
			m_auth_client->send(message);
		}
	}
	else if (message->getCategory() == MSG_CATEGORY_CROSS || message->getCategory() == MSG_CATEGORY_GS_TO_GS)
	{
		MessageEx *crossmsg = dynamic_cast<MessageEx *>(message);
		if(crossmsg != nullptr)
		{
			int serverId = crossmsg->getUserData();
			if(!g_config.isCrossServer())
			{
				if(message->getCategory() == MSG_CATEGORY_GS_TO_GS)
				{
					//借用m_source_session_id字段用来存储目标游戏服的id
					//借用m_userData字段存储源游戏服的id
					crossmsg->setUserData(g_world.getID());
				}

				auto iter = m_cross_server_client_list.find(serverId);
				if(iter != m_cross_server_client_list.end())
				{
					TCPClient* client = iter->second;
					if(client != nullptr && client->isConnected())
					{
						client->send(message);
					}
				}
			}
			else
			{
				if(message->getCategory() != MSG_CATEGORY_GS_TO_GS)
				{
					auto iter = m_game_server_info.find(serverId);
					if(iter != m_game_server_info.end())
					{
						message->setSessionID(iter->second.session);
						m_cross_manager_server->send(message);
					}
				}
			}
		}
	}
	else if(message->getCategory() == MSG_CATEGORY_CENTER)
	{
		m_center_client->send(message);
	}
	else if ((message->getCategory() > MSG_CATEGORY_CLIENT_MAX) &&
		(message->getCategory() <= MSG_CATEGORY_DB_MAX))
	{
		MessageEx *dbmsg = dynamic_cast<MessageEx *>(message);
		if (dbmsg != nullptr)
		{
			dbmsg->setSourceSessionID(dbmsg->getSessionID());

			int srcServerId = dbmsg->getUserData();
			if(srcServerId == 0)
			{
				m_dbagent_client->send(message);
			}
			else
			{
				if(srcServerId > 0)
				{
					auto iter = m_dbagent_client_list.find(srcServerId);
					if(iter != m_dbagent_client_list.end())
					{
						TCPClient* dbagent = iter->second;
						if(dbagent != nullptr && dbagent->isConnected())
						{
							dbagent->send(message);
						}
					}
				}
			}

		}
		else
		{
			LOG_ERROR("invalid db message");
		}
	}
	else
	{
		//发送消息给客户端

		//for test
		if(message->getSessionIndex() < 0 || message->getSessionSerial() < 0)
		{
		//	LOG_WARN("invalid client message, message category = %d, message id = %d", message->getCategory(), message->getID());
		}else
		{
			m_client_server->send(message);
		}
	}

	delete message;
	message = nullptr;
}

void NetService::onControlMsg(Message *message)
{
	switch (message->getID())
	{
	case MsgSessionRelease::Id:
		{
			MsgSessionRelease* msg = dynamic_cast<MsgSessionRelease*>(message);
			if (msg)
			{
				LOG_DEBUG("release session %d-%d", msg->getSessionIndex(), msg->getSessionSerial());

				//删除回话
				m_client_server->closeSession(msg->getSessionID());
			}
		}

	case MsgSessionKick::Id:
		{
			MsgSessionKick* msg = dynamic_cast<MsgSessionKick*>(message);
			if (msg)
			{
				//踢人??
				//m_client_server->kickSession(message->getSessionID());
				MsgBeKicked *bekicked = new MsgBeKicked;
				bekicked->setSessionID(message->getSessionID());
				m_client_server->send(bekicked);
				delete bekicked;
				bekicked = nullptr;
			}
		}
		break;

	case MsgMulticast::Id:
		{
			MsgMulticast* msg = dynamic_cast<MsgMulticast*>(message);
			if (msg != nullptr)
			{
				if(msg->m_message->getCategory() == MSG_CATEGORY_WAR_ZONE_BROADCAST)
				{
					m_cross_manager_server->multicast(msg->m_sessions, msg->m_message);
				}
				else
				{
					m_client_server->multicast(msg->m_sessions, msg->m_message);
				}

				delete msg->m_message;
				msg->m_message = nullptr;
			}
		}
		break;

	case MsgBroadcast::Id:
		{
			MsgBroadcast* msg = dynamic_cast<MsgBroadcast*>(message);
			if (msg != nullptr)
			{
				if(g_config.isCrossServer())
				{
					if(msg->m_message->getCategory() == MSG_CATEGORY_CROSS)
					{
						m_cross_manager_server->broadcast(msg->m_message);
					}
				}
				else
				{
					m_client_server->broadcast(msg->m_message);
				}

				delete msg->m_message;
				msg->m_message = nullptr;
			}
		}
		break;

	case MsgBroadcastToGameServer::Id:
		{
			MsgBroadcastToGameServer* msg = dynamic_cast<MsgBroadcastToGameServer*>(message);
			if (msg != nullptr)
			{
				if (g_config.isCrossServer())
				{
					auto iter = m_game_server_info.find(msg->getUserData());
					if(iter != m_game_server_info.end())
					{
						msg->m_message->setSessionID(iter->second.session);
						m_cross_manager_server->send(msg->m_message);
					}
				}

				delete msg->m_message;
				msg->m_message = nullptr;
			}
		}
		break;
	}
}

void NetService::onAuthSessionConnect(int session_id, const char *addr, int port)
{
	//发送注册消息给验证服务器
	MsgGSAuthToASRequest *msg = new MsgGSAuthToASRequest;
	msg->ServerIP = g_config.getGameHost();
	msg->ServerPort = g_config.getGamePort();
	msg->lastpingID = m_auth_ping_id;
	m_auth_client->sendFirst(msg);
	delete msg;
}

void NetService::onAuthSessionClose(int session_id, const char *addr, int port)
{
}

void NetService::onAuthSessionRecv(Message *message)
{
	if (message == nullptr)
	{
		return;
	}

	if (message->getCategory() == MSG_CATEGORY_AUTH)
	{
		LOG_INFO("auth client recv message %d-%d %s", (int)message->getCategory(), (int)message->getID(), message->getName());
		g_app.postToLogicService(message);
	}
	else if (message->getCategory() == MSG_CATEGORY_GM)
	{
		LOG_INFO("auth client recv message %d-%d %s", (int)message->getCategory(), (int)message->getID(), message->getName());
		//message->setSessionID(0);
		g_app.postToLogicService(message);						
	}
	else if (((message->getCategory() == MsgAccountAuthResponse::Category) &&
		(message->getID() == MsgAccountAuthResponse::Id)) ||
		((message->getCategory() == MsgPlayerAuthResponse::Category) &&
		(message->getID() == MsgPlayerAuthResponse::Id)))
	{
		LOG_INFO("auth client recv message %d-%d %s", (int)message->getCategory(), (int)message->getID(), message->getName());
		//message->setSessionID(0);
		g_app.postToLogicService(message);						
	}
	else if ((message->getCategory() == MsgGSASPing::Category) &&
		(message->getID() == MsgGSASPing::Id))
	{
		MsgGSASPing *ping = dynamic_cast<MsgGSASPing*>(message);
		if (ping)
		{
			m_auth_ping_id = ping->PingID;
			MsgGSASPong *pong = new MsgGSASPong;
			pong->PingID = m_auth_ping_id;
			m_auth_client->send(pong);
			delete pong;
		}
		delete message;
		message = nullptr;
	}
	else
	{
		LOG_ERROR("auth client recv message %d-%d %s, unknown message", (int)message->getCategory(), (int)message->getID(), message->getName());
		delete message;
		message = nullptr;
	}
}

void NetService::onChatSessionConnect(int session_id, const char *addr, int port)
{
	//发送注册消息给验证服务器
	MsgGSAuthToASRequest *msg = new MsgGSAuthToASRequest;
	msg->ServerIP = g_config.getGameHost();
	msg->ServerPort = g_config.getGamePort();
	msg->lastpingID = m_auth_ping_id;
	m_chat_client->sendFirst(msg);
	delete msg;
}

void NetService::onChatSessionClose(int session_id, const char *addr, int port)
{

}
void NetService::onChatSessionRecv(Message *message)
{
	if (message == nullptr)
	{
		return;
	}

	if ((message->getCategory() == MsgGSASPing::Category) &&
		(message->getID() == MsgGSASPing::Id))
	{
		MsgGSASPing *ping = dynamic_cast<MsgGSASPing*>(message);
		if (ping)
		{
			m_auth_ping_id = ping->PingID;
			MsgGSASPong *pong = new MsgGSASPong;
			pong->PingID = m_auth_ping_id;
			m_auth_client->send(pong);
			delete pong;
		}
		delete message;
		message = nullptr;
	}
	else
	{
		LOG_ERROR("chat client recv message %d-%d %s, unknown message", (int)message->getCategory(), (int)message->getID(), message->getName());
		delete message;
		message = nullptr;
	}
}

void NetService::onDBAgentSessionConnect(int session_id, const char *addr, int port, int gameServerId)
{
	if (g_config.server_id > 0)
	{
		MsgDBServerID *dbmsg = new MsgDBServerID;
		dbmsg->server_id = g_config.server_id;
		if(gameServerId > 0)
		{
			dbmsg->register_server_id = 0;
			m_dbagent_client_list[gameServerId]->send(dbmsg);
		}
		else
		{
			dbmsg->register_server_id = 1;
			m_dbagent_client->send(dbmsg);
		}
		delete dbmsg;
	}
}

void NetService::onDBAgentSessionClose(int session_id, const char *addr, int port)
{

}

void NetService::onDBAgentSessionRecv(Message *message)
{
	MessageEx *dbmsg = dynamic_cast<MessageEx *>(message);
	if (dbmsg == nullptr)
	{
		LOG_ERROR("invalid db message");
		delete message;
		return;
	}

	dbmsg->setSessionID(dbmsg->getSourceSessionID());

	LOG_DEBUG("dbagent client recv message %d-%d %s", (int)message->getCategory(), (int)message->getID(), message->getName());
	g_app.postToLogicService(message);
}

void NetService::onCrossServerSessionConnect(int session_id, const char *addr, int port, int crossServerId)
{
	if (g_config.server_id > 0)
	{
		MsgRegisterGameServerToCrossServer *msg = new MsgRegisterGameServerToCrossServer;
		msg->setUserData(crossServerId);
		msg->gameServerId = g_config.server_id;
		msg->gameServerName = g_world.getServerName();
		msg->gameServerAddr = g_config.getGameHost();
		msg->gameServerPort = g_config.getGamePort();
		msg->dbAgentAddr = g_config.getDBAgentHost();
		msg->dbAgentPort = g_config.getDBAgentPort();
		g_app.postToNetService(msg);

		MsgConnectToCorssServerOK* notify = new MsgConnectToCorssServerOK();
		g_app.postToLogicService(notify);

		LOG_INFO("CS_MODULE_INFO: connect to corssServer success! register gameServer to crossServer"); 
	}
}

void NetService::onCrossServerSessionClose(int session_id, const char *addr, int port, int crossServerId)
{
	//g_world_player_mgr.onGSLostCSConnection(crossServerId);
}

void NetService::onCrossServerSessionRecv(Message *message)
{ 
	if ((message->getCategory() == MsgBroadcastSystemPromptToGSNotify::Category) &&
		(message->getID() == MsgBroadcastSystemPromptToGSNotify::Id))
	{
		MsgBroadcastSystemPromptToGSNotify* systemMsg = dynamic_cast<MsgBroadcastSystemPromptToGSNotify*>(message);
		if (systemMsg != nullptr)
		{
			MsgSyncSystemAnnouncement* notify = new MsgSyncSystemAnnouncement;
			notify->basestring = systemMsg->msg;
			notify->TouchID = systemMsg->touchID;
			notify->ItemSid = systemMsg->itemSid;
			notify->showflag = systemMsg->showflag;
			m_client_server->broadcast(notify);

			delete notify;
		}

		delete message;
		message = nullptr;
	}
	else if(message->getCategory() == MSG_CATEGORY_WAR_ZONE_BROADCAST)
	{
		m_client_server->broadcast(message);
		delete message;
		message = nullptr;
	}
	else
	{
		g_app.postToLogicService(message);
	}
}

void NetService::onAdminSessionAccept(int session_id, const char *addr, int port)
{

}

void NetService::onAdminSessionClose(int session_id, const char *addr, int port)
{

}

void NetService::onAdminSessionRecv(Message *message)
{
	//if (message->getID() == MsgGMGetPlayerInfoRequest::Id)
	//{
	//	int now = get_time();
	//	if (now - session->last_get_player_info_time < 3)
	//	{
	//		delete message;
	//		message = NULL;
	//		continue;
	//	}
	//}

	//将消息转发给逻辑服务
	//message->setSessionID(session->id);
	g_app.postToLogicService(message);
}

void NetService::onCrossManagerSessionAccept(int session_id, const char *addr, int port)
{

}

void NetService::onCrossManagerSessionClose(int session_id, const char *addr, int port)
{
	for(auto iter = m_game_server_info.begin(); iter != m_game_server_info.end(); iter++)
	{
		if(iter->second.session == session_id)
		{
			//g_world_player_mgr.onCSLostGSConnection(iter->first); 
			m_game_server_info.erase(iter);
			break;
		}
	}

	//通知逻辑服务
	MsgGameServerSessionClosed *closed = new MsgGameServerSessionClosed;
	closed->setSessionID(session_id);
	g_app.postToLogicService(closed);
}

void NetService::onCrossManagerSessionRecv(Message *message)
{
	if ((message->getCategory() == MsgRegisterGameServerToCrossServer::Category) &&
		(message->getID() == MsgRegisterGameServerToCrossServer::Id))
	{
		MsgRegisterGameServerToCrossServer* msg = dynamic_cast<MsgRegisterGameServerToCrossServer*>(message);
		if (msg != nullptr)
		{
			GameServerInfo info;
			info.session = msg->getSessionID();
			info.serverAddr = msg->gameServerAddr;
			info.serverPort = msg->gameServerPort;
			m_game_server_info[msg->gameServerId] = info;

			connectToDbAgent(msg->dbAgentAddr, msg->dbAgentPort, msg->gameServerId);
		}

		g_app.postToLogicService(message);
	}
	else if(message->getCategory() == MSG_CATEGORY_GS_TO_GS)
	{
		MessageEx *msg = dynamic_cast<MessageEx *>(message);
		if(msg != nullptr)
		{
			int targetGameServerId = msg->getSourceSessionID();
			auto iter = m_game_server_info.find(targetGameServerId);
			if(iter != m_game_server_info.end())
			{
				msg->setSessionID(iter->second.session);
				m_cross_manager_server->send(msg);
			}
		}

		delete message;
		message = nullptr;
	}
	else
	{
		g_app.postToLogicService(message);
	}
}

void NetService::onClientSessionAccept(int session_id, const char *addr, int port)
{
	ClientSessionData *data = (ClientSessionData *)m_client_server->getSessionData(session_id);
	data->last_ping_tick_count = 0;
	data->ping_count = 0;
	data->ping_ticks = 0;
}

void NetService::onClientSessionClose(int session_id, const char *addr, int port)
{
	//通知逻辑服务
	MsgSessionClosed *closed = new MsgSessionClosed;
	closed->setSessionID(session_id);
	g_app.postToLogicService(closed);
}

void NetService::onClientSessionRecv(Message *message)
{
	if(g_config.isCrossServer())
	{
		//对来自客户端的消息进行筛选验证
		if(!message->canSendToCrossFromClient())
		{
			delete message;
			message = nullptr;
			return;
		}
	}

	if ((message->getCategory() == MsgPing::Category) &&
		(message->getID() == MsgPing::Id))
	{
		onClientPing(message);
		delete message;
		message = nullptr;
	}
	else if ((message->getCategory() == MSG_CATEGORY_AUTH) ||
		(message->getCategory() == MSG_CATEGORY_CONTROL) ||
		(message->getCategory() == MSG_CATEGORY_GM))
	{
		LOG_ERROR("client session %d-%d recv forbid message %d-%d %s",
			message->getSessionIndex(), message->getSessionSerial(),
			(int)message->getCategory(), (int)message->getID(), message->getName());
		delete message;
		message = nullptr;
	}
	else
	{
		if (message->getCategory() > MSG_CATEGORY_CLIENT_MAX)
		{
			delete message;
			message = nullptr;
			return;
		}

		//将消息转发给逻辑服务
		//message->setSessionID(session->id);
		g_app.postToLogicService(message);

	}
}

void NetService::onClientPing(Message *message)
{
	//发送应答消息
	MsgPong *pong = new MsgPong;
	pong->setSessionID(message->getSessionID());
	m_client_server->send(pong);
	delete pong;
	pong = nullptr;

	ClientSessionData *data = (ClientSessionData *)m_client_server->getSessionData(message->getSessionID());
	if (data == nullptr)
	{
		return;
	}

	//更新ping数据
	uint64 now_tick_count = get_tick_count();

	if (data->last_ping_tick_count == 0)
	{
		data->last_ping_tick_count = now_tick_count;
		return;
	}

	data->ping_count++;
	data->ping_ticks += (int)(now_tick_count - data->last_ping_tick_count);
	data->last_ping_tick_count = now_tick_count;

	//检查ping值
	if (data->ping_count < m_accelerator_ping_count)
	{
		return;
	}

	//计算平均ping值，如果太低，将客户端关入小黑屋
	int average = data->ping_ticks / data->ping_count;

	data->ping_count = 0;
	data->ping_ticks = 0;

	if (average > m_accelerator_ping_average)
	{
		data->times = 0;
		return;
	}

	data->times += 1;

	LOG_WARN("client session %d-%d speed %d is strange, move to prison",
		message->getSessionIndex(), message->getSessionSerial(), average);

	MsgImprisonPlayer *msg = new MsgImprisonPlayer;
	msg->setSessionID(message->getSessionID());
	msg->average = average;
	msg->times = data->times;
	g_app.postToLogicService(msg);
}

void NetService::onCenterClientConnect(int session_id, const char *addr, int port)
{
	if (g_world.getID() > 0)
	{
		MsgRegisterToCenterServer *msg = new MsgRegisterToCenterServer;
		msg->serverId = g_world.getID();
		msg->gameServerAddr = g_config.getGameHost();
		msg->gameServerPort = g_config.getGamePort();
		msg->crossManagerServerAddr = g_config.getCrossManagerHost();
		msg->crossManagerServerPort = g_config.getCrossManagerPort();
		msg->dbAgentAddr = g_config.getDBAgentHost();
		msg->dbAgentPort = g_config.getDBAgentPort();
		msg->isCrossServer = g_config.isCrossServer() ? 1 : 0;
		msg->isCommonCrossServer = g_config.isCommonCrossServer() ? 1 : 0;
		m_center_client->sendFirst(msg);
		delete msg;

		LOG_INFO("CS_MODULE_INFO: connect to center server success!");
	}
}

void NetService::onCenterClientClose(int session_id, const char *addr, int port)
{
}

void NetService::onCenterClientRecv(Message *message)
{
	if ((message->getCategory() == MsgFindNewCrossServerNotify::Category) &&
		(message->getID() == MsgFindNewCrossServerNotify::Id))
	{
		MsgFindNewCrossServerNotify* msg = dynamic_cast<MsgFindNewCrossServerNotify*>(message);
		if (msg != nullptr)
		{
			CrossServerInfo info;
			info.serverAddr = msg->crossServerAddr;
			info.serverPort = msg->crossServerPort;
			m_cross_server_info[msg->serverId] = info;
		}
	}
	g_app.postToLogicService(message);
}

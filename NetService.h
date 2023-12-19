#ifndef _NET_SERVICE_H_INCLUDED
#define	_NET_SERVICE_H_INCLUDED

#include "common/Service.h"
#include "common/TCPClient.h"
#include <map>
#include <string>
#include <set>

class TCPClient;
class TCPServer;

struct GameServerInfo
{
	std::string serverAddr;
	int serverPort;
	int session;

	GameServerInfo(){memset(this,0,sizeof(*this));}
};

struct CrossServerInfo
{
	std::string serverAddr;
	int serverPort;

	CrossServerInfo(){memset(this,0,sizeof(*this));}
};


//网络服务
class NetService : public Service
{
	struct ClientSessionData
	{
		uint64 last_ping_tick_count;			//最后一次收到ping消息时间
		int ping_count;							//收到ping消息数量
		int ping_ticks;							//收到m_ping_cnt数量的ping消息的总时间间隔
		int times;								//连续几次检测到加速软件
	};

public:
	//构造函数
	NetService();

	//析构函数
	virtual ~NetService();

	virtual void init();

	void startServer();

	void startGSManagerServer();

	void stopClientServer();

	void setAcceleratorPingCount(int count) { m_accelerator_ping_count = count; }
	void setAcceleratorPingAverage(int average) { m_accelerator_ping_average = average; }

	bool isCenterClientConnected(){return m_center_client->isConnected();}
	
public:
	//游戏服使用
	void connectToCrossServer(std::string ip, int port, int crossServerId);
	bool isCSConnected(int crossServerId){ return m_cross_server_client_list.find(crossServerId) != m_cross_server_client_list.end() && m_cross_server_client_list[crossServerId]->isConnected(); }

	bool isGSConnected(int gameServerId){ return m_game_server_info.find(gameServerId) != m_game_server_info.end()  ; }
	void getCrossServerInfo(int crossServerId, CrossServerInfo& info);
public:
	//跨服使用
	void connectToDbAgent(std::string ip, int port, int gameServerId);  
	bool isGSDBConnected(int gameServerId){return m_dbagent_client_list.find(gameServerId) != m_dbagent_client_list.end() && m_dbagent_client_list[gameServerId]->isConnected();}
	int getGSSessionId(int gameServerId){return m_game_server_info.find(gameServerId) != m_game_server_info.end() ? m_game_server_info[gameServerId].session : 0;}

protected:
	virtual void onStart();
	virtual void onStop();
	virtual void onUpdate(int elapse);

	//处理消息
	virtual void onMessage(Message *message);
	void onControlMsg(Message *message);

	//验证服务器
	void onAuthSessionConnect(int session_id, const char *addr, int port);
	void onAuthSessionClose(int session_id, const char *addr, int port);
	void onAuthSessionRecv(Message *message);

	//聊天服务器
	void onChatSessionConnect(int session_id,const char *addr, int port);
	void onChatSessionClose(int session_id,const char *addr, int port);
	void onChatSessionRecv(Message *message);

	//数据库代理服务器
	void onDBAgentSessionConnect(int session_id, const char *addr, int port, int gameServerId);
	void onDBAgentSessionClose(int session_id, const char *addr, int port);
	void onDBAgentSessionRecv(Message *message);

	//跨服
	void onCrossServerSessionConnect(int session_id, const char *addr, int port, int crossServerId);
	void onCrossServerSessionClose(int session_id, const char *addr, int port, int crossServerId);
	void onCrossServerSessionRecv(Message *message);

	//GMS服务器
	void onAdminSessionAccept(int session_id, const char *addr, int port);
	void onAdminSessionClose(int session_id, const char *addr, int port);
	void onAdminSessionRecv(Message *message);

	//跨服管理服务器
	void onCrossManagerSessionAccept(int session_id, const char *addr, int port);
	void onCrossManagerSessionClose(int session_id, const char *addr, int port);
	void onCrossManagerSessionRecv(Message *message);

	//客户端
	void onClientSessionAccept(int session_id, const char *addr, int port);
	void onClientSessionClose(int session_id, const char *addr, int port);
	void onClientSessionRecv(Message *message);
	void onClientPing(Message *message);

	//中心服务器
	void onCenterClientConnect(int session_id, const char *addr, int port);
	void onCenterClientClose(int session_id, const char *addr, int port);
	void onCenterClientRecv(Message *message);
protected:
	TCPServer *m_client_server;		//游戏服务器

	TCPServer *m_admin_server;		//管理服务器

	TCPServer *m_cross_manager_server; //跨服管理服务器
	bool gsManagerServerStart;

	TCPClient *m_center_client;		//中心服务器
	bool m_center_update;

	TCPClient *m_auth_client;		//验证服务器客户端
	std::string m_auth_ping_id;

	TCPClient *m_chat_client;		//聊天服务器

	TCPClient *m_dbagent_client;	//数据库代理客户端

	std::map<int, TCPClient*> m_dbagent_client_list;  //跨服组内所有的数据库代理客户端（跨服使用）
	std::map<int, GameServerInfo> m_game_server_info; //游戏服服务器id对应的sessionid（跨服使用）

	std::map<int, TCPClient*> m_cross_server_client_list;  //跨服与游戏服的连接实例(游戏服使用）
	std::map<int, CrossServerInfo> m_cross_server_info; //跨服服务器id对应的ip和端口（游戏服使用）

	//加速判断
	int m_accelerator_ping_count;
	int m_accelerator_ping_average;

	bool m_dblist_lock;
	bool m_crossserver_list_lock;

};

#endif	//_NET_SERVICE_H_INCLUDED

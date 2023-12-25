
#ifndef _CONFIG_H_INCLUDED
#define _CONFIG_H_INCLUDED

#include <string>

class Config
{
public:
	Config()
	{
		m_log_level = "info";	//日志等级
		m_force_encrypt = true;

		//游戏服务器
		m_game_host = "172.16.90.15";
		m_game_port = 7702;

		//管理服务器
		m_admin_host = " 172.16.90.15";
		m_admin_port = 8802;

		//登陆服务器
		m_auth_host = "192.168.0.149";
		m_auth_port = 7000;

		//聊天服务器
		m_chat_inuse = false;
		m_chat_host = "192.168.0.149";
		m_chat_port = 6000;

		//DB代理服务器
		m_dbagent_host = "127.0.0.1";
		m_dbagent_port = 9001;

		//中心服务器地址和端口
		m_center_host = "172.16.90.15";
		m_center_port = 7701;

		//跨服服务器提供给游戏服的EndPoint
		m_cross_manager_host = "192.168.0.143";
		m_cross_manager_port = 7703;

		m_is_cross_server = false;   //是否是战区服务器
		m_is_common_cross_server = false;  //是否是公共战区服务器
		m_cross_server_line_counts = 1; //战区服务器有多少个分线（一个分线对应一个战区）
		server_id = 0;
	}

	//加载文件
	bool load(const std::string &filename1, const std::string &filename2);

	inline const std::string &getLogLevel() const { return m_log_level; }

	inline bool getForceEncrypt() const { return m_force_encrypt; }

	inline const std::string &getGameHost() const { return m_game_host; }
	inline int getGamePort() const { return m_game_port; }

	inline const std::string &getAdminHost() const { return m_admin_host; }
	inline int getAdminPort() const { return m_admin_port; }

	inline const std::string &getAuthHost() const { return m_auth_host; }
	inline int getAuthPort() const { return m_auth_port; }

	inline bool getChatInuse() const { return m_chat_inuse; }
	inline void setChatInuse(bool b) { m_chat_inuse = b; }
	inline const std::string &getChatHost() const { return m_chat_host;}
	inline int getChatPort() const {return m_chat_port;}

	inline const std::string &getDBAgentHost() const { return m_dbagent_host; }
	inline int getDBAgentPort() const { return m_dbagent_port; }

	inline const std::string &getCenterHost() const { return m_center_host; }
	inline int getCenterPort() const { return m_center_port; }

	inline const std::string &getCrossManagerHost() const { return m_cross_manager_host; }
	inline int getCrossManagerPort() const { return m_cross_manager_port; }

	inline bool isCrossServer() const { return m_is_cross_server; }
	inline bool isGameServer() {return !m_is_cross_server;}

	inline bool isCommonCrossServer() const { return m_is_common_cross_server; }

	inline int getWarZoneCounts(){ return m_cross_server_line_counts; }

public:
	std::string m_log_level;	//日志等级

	bool m_force_encrypt;

	//游戏服务器
	std::string m_game_host;
	int m_game_port;

	//管理服务器
	std::string m_admin_host;
	int m_admin_port;

	//登陆服务器
	std::string m_auth_host;
	int m_auth_port;

	//聊天服务器
	bool m_chat_inuse;
	std::string m_chat_host;
	int m_chat_port;

	//DB代理服务器
	std::string m_dbagent_host;
	int m_dbagent_port;

	//中心服务器地址和端口
	std::string m_center_host;
	int m_center_port;

	//跨服服务器提供给游戏服的EndPoint
	std::string m_cross_manager_host;
	int m_cross_manager_port;

	bool m_is_cross_server;   //是否是战区服务器

	bool m_is_common_cross_server;  //是否是公共战区服务器

	int m_cross_server_line_counts; //战区服务器有多少个分线（一个分线对应一个战区）

	int server_id;
};

extern Config g_config;

#endif // !_CONFIG_H_INCLUDED


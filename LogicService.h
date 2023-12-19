#ifndef _LOGIC_SERVICE_H_INCLUDED
#define _LOGIC_SERVICE_H_INCLUDED

#include "common/Service.h"
#include "message/MsgPlayer.h"
#include <functional>
#include <vector>

//游戏逻辑服务
class LogicService : public Service
{
public:
	LogicService();
	~LogicService();

	virtual void init();

	void broadcast(Message *message);

	void keepMessage(stcChatKeepInfo message);

	void registerMessageHandler(int msgcat, int msgid, int ref);

protected:
	virtual void onStart();
	virtual void onStop();

	//处理消息
	virtual void onMessage(Message *message);

protected:
	//注册服务器结果
	void onGSAuthToASResponse(Message *message);
	//服务器名称
	void onServerInfoResponse(Message *message);
	//数据加载完成
	void onDataLoaded();
	//每帧定时器
	void onFrameTimer(size_t elapse);
	//每秒定时器
	void onSecondTimer(size_t elapse);
	//每秒luagc定时器
	void onLuaGcSecondTimer(size_t elapse);
	
	//每分钟定时器
	void onMinuteTimer(size_t elapse);
	void onUpdateWorldDataTimer(size_t elapse);

private:
	int m_message_time;
	std::map<int, std::vector<int>> m_handler_map;
};

#endif	// _LOGIC_SERVICE_H_INCLUDED


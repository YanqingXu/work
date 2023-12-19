
#ifndef _GS_APPLICATION_H_INCLUDED
#define _GS_APPLICATION_H_INCLUDED

class NetService;
class LogicService;
class Module;
class MsgRegister;

class Application
{
public:
	Application();
	~Application();

	NetService *GetNetService() { return m_net_service; }
	LogicService *GetLogicService() { return m_logic_service; }

	//根据模块名取逻辑模块
	Module *getLogicModule(const char *name);

	bool initialize(int argc, char* argv[]);

	void run();

	void finalize();

	void stop();

	bool isFinalize() { return m_finalized; }

	void dispatchToLogicService(Message *message);
	void postToLogicService(Message *message);
	void postToNetService(Message *message);

private:
	MsgRegister		*m_msg_register;		//消息注册
	NetService			*m_net_service;
	LogicService		*m_logic_service;

	bool m_finalized;
};

extern Application g_app;

#endif	//_GS_APPLICATION_H_INCLUDED



#include "stdafx.h"
#include "Application.h"
#include "common/MiniDump.h"
#include "NetService.h"
#include "LogicService.h"
#include "Entity/EntityFactory.h"
#include "message/MsgRegister.h"

Application g_app;

Application::Application()
{
	//初始化日志
	g_logger = new Logger;
	g_logger->set_name(std::string("gameserver"));
	g_logger->set_level("info");

	m_msg_register = new MsgRegister;

	//实体工厂实例
	g_entity_factory = new EntityFactory;

	MiniDump::initialize();

	m_net_service = NULL;
	m_logic_service = NULL;

	m_finalized = false;
}

Application::~Application()
{
	delete m_msg_register;

	if (g_entity_factory != nullptr)
	{
		delete g_entity_factory;
		g_entity_factory = nullptr;
	}

	if (g_logger != nullptr)
	{
		delete g_logger;
		g_logger = nullptr;
	}
}

//根据模块名取逻辑模块
Module *Application::getLogicModule(const char *name)
{
	if ((m_logic_service == nullptr) || (name == nullptr))
	{
		return nullptr;
	}

	return m_logic_service->getModule(name);
}

bool Application::initialize(int argc, char* argv[])
{
	LOG_INFO("start gameserver ...");

	//加载配置文件
	if (!g_config.load("dbagent.conf", "gameserver.conf"))
	{
		LOG_ERROR("load config file gameserver.conf failed");
		return 0;
	}

	LOG_INFO("load config file gameserver.conf ok");

	//根据配置设置日志等级
	g_logger->set_level(g_config.getLogLevel());

	m_net_service = new NetService;
	m_logic_service = new LogicService;

	//初始化网络服务
	m_net_service->init();

	//初始化逻辑服务
	m_logic_service->init();

	//启动服务
	m_net_service->start();
	m_logic_service->start();

	return true;
}

void Application::run()
{
	//等待服务结束
	try
	{
		m_logic_service->wait();
	}
	catch (const std::system_error &e)
	{
		LOG_ERROR("Caught system_error with code %d:%s", e.code().value(), e.what());
	}

	try
	{
		m_net_service->wait();
	}
	catch (const std::system_error &e)
	{
		LOG_ERROR("Caught system_error with code %d:%s", e.code().value(), e.what());
	}
}

void Application::finalize()
{
	if (m_logic_service != nullptr)
	{
		delete m_logic_service;
		m_logic_service = nullptr;
	}
	
	if (m_net_service != nullptr)
	{
		delete m_net_service;
		m_net_service = nullptr;
	}

	m_finalized = true;
}

void Application::stop()
{
	m_net_service->stopClientServer();

	m_logic_service->stop();
	Sleep(1000);
	m_net_service->stop();
}

void Application::dispatchToLogicService(Message *message)
{
	m_logic_service->dispatchMessage(message);
}

void Application::postToLogicService(Message *message)
{
	m_logic_service->postMessage(message);
}

void Application::postToNetService(Message *message)
{
	m_net_service->postMessage(message);
}

BOOL WINAPI consoleHandler(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		switch (dwCtrlType)
		{
		case CTRL_CLOSE_EVENT:		LOG_INFO("CTRL_CLOSE_EVENT");		break;
		case CTRL_LOGOFF_EVENT:		LOG_INFO("CTRL_LOGOFF_EVENT");		break;
		case CTRL_SHUTDOWN_EVENT:	LOG_INFO("CTRL_SHUTDOWN_EVENT");	break;
		}

		g_app.stop();
		return TRUE;

	default:
		return FALSE;
	}
}

int main(int argc, char* argv[])
{
	_tzset();

	if (!check_program_singleton())
	{
		printf("program maybe already running");
		Sleep(5000);
		return -1;
	}

	set_console_utf8();

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)consoleHandler, TRUE);

	if (!g_app.initialize(argc, argv))
	{
		return 0;
	}

	g_app.run();

	g_app.finalize();

	LOG_INFO("stopped.");

	return 0;
}


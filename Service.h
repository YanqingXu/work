#ifndef _SERVICE_H_INCLUDED
#define _SERVICE_H_INCLUDED

#include "Message.h"
#include "TimerManager.h"

#include <thread>
#include <hash_map>
#include <map>

#pragma warning(push)
#pragma warning(disable:4251)

#define _DEBUG_SERVICE_QUEUE_

#ifdef _SERVICE_QUEUE_LIMIT_
#define _SERVICE_QUEUE_LIMIT_	4
#else
#define _SERVICE_QUEUE_LIMIT_	64
#endif

class Module;

//服务类
//
//	Service
//	Base on boost thread and asio
//
class COMMON_API Service
{
	template <typename Handler>
	class handler_wrapper
	{
	public:
		handler_wrapper(Handler &h) : handler_(h) { }
		~handler_wrapper() { }

		static void handle_message(void *self, Message *message)
		{
			((handler_wrapper *)self)->handler_(message);
		}

	private:
		Handler handler_;
	};

	struct message_handler
	{
		message_handler()
		{
			handler = NULL;
		}

		void (*handle_message)(void *base, Message *message);	//函数指针
		void *handler;											//参数
		char buf[32];											//处理器
	};

public:
	Service();
	virtual ~Service();

	void *getIOLoop() { return m_io_loop; }

	//
	//	initialize service
	//	using this function to initialize some static data
	//	this function should not have too much logic that consuming too much time
	//	large scale data initialize should be in onStart which will be runed in 
	//	separated threads
	//
	virtual void init();


	//
	//	start the service
	virtual void start();

	//	stop the service
	virtual void stop();

	//	wait for the end of service
	virtual void wait();

	//
	//	post a message to current service
	//
	virtual void postMessage(Message *message);

	virtual void dispatchMessage(Message *message);

	template <typename MessageType, typename Handler>
	void registerMessageHandler(Handler &&handler)
	{
		registerMessageHandler(MessageType::Category, MessageType::Id, std::move(handler));
	}

	template <typename Handler>
	void registerMessageHandler(int category, int id, Handler &&handler)
	{
		if (sizeof(handler_wrapper<Handler>) > 32)
		{
			LOG_ERROR("buf too small, neead %d", (int)sizeof(handler_wrapper<Handler>));
			return;
		}

		if (category < 0 || category > 255 || id <= 0 || id > 65535)
		{
			return;
		}

		int key = (category << 16) | id;

		message_handler *h = new message_handler;
		memset(h->buf, 0, sizeof(h->buf));
		h->handle_message = &handler_wrapper<Handler>::handle_message;
		h->handler = new(h->buf) handler_wrapper<Handler>(handler);

		auto &handler_vector = m_handler_map[key];
		handler_vector.push_back(h);
	}

	template<typename MODULE>
	bool registerModule()
	{
		Module *module = new MODULE(this);

		const char *module_name = module->getName();
		if (module_name == NULL || *module_name == 0)
		{
			delete module;
			return false;
		}

		auto it = m_module_map.find(module_name);
		if (it != m_module_map.end())
		{
			delete module;
			return false;
		}

		m_modules.push_back(module);
		m_module_map[module_name] = module;

		return true;
	}

	Module *getModule(const char *name);

	template <typename Handler>
	int schedule_timer(size_t delay, size_t period, Handler &&handler)
	{
		return m_timer_mgr.schedule_timer(delay, period, std::move(handler));
	}

	void cancel_timer(int timer_id)
	{
		m_timer_mgr.cancel_timer(timer_id);
	}

	TimerManager *getTimeManager() { return &m_timer_mgr; }

protected:
	//
	//	main run loop for current service
	//
	virtual void run();

	//
	//	invoked by service just after its starting
	virtual void onStart() = 0;

	//	invoked by service just before its stopping
	virtual void onStop() = 0;

	virtual void onUpdate(int elapse);

	//
	//	callbacks
	//
	virtual void onMessage(Message *message);

protected:
	//asio::io_service		m_io_service;
	//asio::io_service::work	m_service_work;
	void *m_io_loop;
	void *m_io_work;
	std::thread				m_thread;

	bool					m_running;

	volatile long			m_queue_counter;

	TimerManager			m_timer_mgr;

	stdext::hash_map<int, std::vector<message_handler*>> m_handler_map;		//消息处理

	std::vector<Module *> m_modules;				//逻辑处理模块
	std::map<std::string, Module*> m_module_map;	//逻辑处理模块
};

#pragma warning(pop)

#endif	//_SERVICE_H_INCLUDED

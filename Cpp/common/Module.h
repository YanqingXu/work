#ifndef _MESSAGE_HANDLER_H_INCLUDED
#define _MESSAGE_HANDLER_H_INCLUDED

#include "common/Message.h"
#include "common/Service.h"

class Module
{
public:
	Module(Service *service)
	{
		m_service = service;
	}

	virtual ~Module()
	{
	}

	virtual const char *getName() const = 0;

	template <typename MessageType, typename Handler>
	void registerMessageHandler(Handler &&handler)
	{
		if (m_service == nullptr)
		{
			LOG_ERROR("invalid service");
			return;
		}

		m_service->registerMessageHandler(MessageType::Category, MessageType::Id, std::move(handler));
	}

	virtual bool initialize()
	{
		return true;
	}


protected:
	Service *m_service;
};

#endif	//_MESSAGE_HANDLER_H_INCLUDED

﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_CONTROL_H_INCLUDED
#define _MSG_CONTROL_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

class MsgSessionClosed : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 2 };

	MsgSessionClosed() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgSessionClosed";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
};

class MsgSessionKick : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 5 };

	MsgSessionKick() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgSessionKick";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
};

class MsgSessionRelease : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 6 };

	MsgSessionRelease() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgSessionRelease";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
};

class MsgSessionAged : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 8 };

	MsgSessionAged() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgSessionAged";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
};

class MsgMulticast : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 10 };

	MsgMulticast() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgMulticast";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
	Message* m_message;
	std::vector<int> m_sessions;
};

class MsgBroadcast : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 12 };

	MsgBroadcast() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgBroadcast";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
	Message* m_message;
};

class MsgBroadcastToGameServer : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 14 };

	MsgBroadcastToGameServer() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgBroadcastToGameServer";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return 0;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

public:
	Message* m_message;
};

class MsgGameServerSessionClosed : public Message
{
public:
	enum { Category = MSG_CATEGORY_CONTROL, Id = 15 };

	MsgGameServerSessionClosed() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgGameServerSessionClosed";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

public:
};

#endif	//_MSG_CONTROL_H_INCLUDED

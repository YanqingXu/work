﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_CHAT_H_INCLUDED
#define _MSG_CHAT_H_INCLUDED

#include "category.h"
#include "common/Message.h"

class MsgChatSubmit : public Message
{
public:
	enum { Category = MSG_CATEGORY_CHAT, Id = 500 };

	MsgChatSubmit() :
		Message(Category, Id)
	{
		port = 0;
		chatType = 0;
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgChatSubmit";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 12;
		length += sizeof(short) + serverIp.size();
		length += sizeof(short) + playerName.size();
		length += sizeof(short) + privateName.size();
		length += sizeof(short) + chatStr.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << serverIp;
		s << port;
		s << chatType;
		s << pid;
		s << playerName;
		s << privateName;
		s << chatStr;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> serverIp;
		s >> port;
		s >> chatType;
		s >> pid;
		s >> playerName;
		s >> privateName;
		s >> chatStr;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "serverIp", serverIp);
		lua::settable(L, -1, "port", port);
		lua::settable(L, -1, "chatType", chatType);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "playerName", playerName);
		lua::settable(L, -1, "privateName", privateName);
		lua::settable(L, -1, "chatStr", chatStr);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "serverIp=" << serverIp;
		buffer << ",port=" << port;
		buffer << ",chatType=" << chatType;
		buffer << ",pid=" << pid;
		buffer << ",playerName=" << playerName;
		buffer << ",privateName=" << privateName;
		buffer << ",chatStr=" << chatStr;
	}

public:
	std::string serverIp;
	int port;
	int chatType;
	int pid;
	std::string playerName;
	std::string privateName;
	std::string chatStr;
};

#endif	//_MSG_CHAT_H_INCLUDED
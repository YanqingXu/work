﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_TEST_H_INCLUDED
#define _MSG_TEST_H_INCLUDED

#include "category.h"
#include "common/Message.h"

class MsgGMCommand : public Message
{
public:
	enum { Category = MSG_CATEGORY_TEST, Id = 100 };

	MsgGMCommand() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgGMCommand";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = 0;
		length += sizeof(short) + cmd.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << cmd;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> cmd;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "cmd", cmd);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "cmd=" << cmd;
	}

public:
	std::string cmd;
};

class MsgImprisonPlayer : public Message
{
public:
	enum { Category = MSG_CATEGORY_TEST, Id = 101 };

	MsgImprisonPlayer() :
		Message(Category, Id)
	{
		average = 0;
		times = 0;
	}

	virtual const char *getName() const
	{
		return "MsgImprisonPlayer";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << average;
		s << times;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> average;
		s >> times;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "average", average);
		lua::settable(L, -1, "times", times);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "average=" << average;
		buffer << ",times=" << times;
	}

public:
	int average;
	int times;
};

#endif	//_MSG_TEST_H_INCLUDED

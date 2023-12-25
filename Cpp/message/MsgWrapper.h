
#ifndef _MSG_WRAPPER_H_INCLUDED
#define _MSG_WRAPPER_H_INCLUDED

#include "category.h"
#include "common/MsgFactory.h"
#include "common/MessageEx.h"

class MsgSceneWrapper : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_CROSS, Id = 9999 };

	MsgSceneWrapper(Message* msg) :
		MessageEx(Category, Id)
	{
		subMsg = msg;
		subMsgCategory = msg->getCategory();
		subMsgId = msg->getID();
	}

	MsgSceneWrapper() :
		MessageEx(Category, Id)
	{
	}

	~MsgSceneWrapper(){
		if(subMsg)
		{
			delete subMsg;
		}
	}

	virtual const char *getName() const
	{
		return "MsgSceneWrapper";
	}

	virtual int getSalt() const
	{
		return 0;
	}

	virtual bool getSendBack() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		if(subMsg)
		{
			return subMsg->getLength() + 14;
		}
		else
		{
			return 14;
		}
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << subMsgCategory;
		s << subMsgId;
		s << pid;
		s << isHero;
		if(subMsg)
		{
			subMsg->serialize(s);
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> subMsgCategory;
		s >> subMsgId;
		s >> pid;
		s >> isHero;
		subMsg = g_msg_factory.createMessage(subMsgCategory, subMsgId);
		subMsg->unserialize(s);
		return true;
	}

	virtual void push(lua_State *L) const
	{	
	}

	virtual void dump(DumpBuffer &buffer)
	{
	}

public:
	Message* subMsg;
	int subMsgCategory;
	int subMsgId;
	int pid;
	short isHero;
};

#endif	//_MSG_WRAPPER_H_INCLUDED
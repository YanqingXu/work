#ifndef _PROTOCOL_H_INCLUDED
#define _PROTOCOL_H_INCLUDED

#include "common/Message.h"

//通信协议类
class Protocol
{
public:
	//析构函数
	virtual ~Protocol()
	{
	}

	//序列化消息
	virtual bool serialize(Message *message, ByteStream &stream)
	{
		return false;
	}

	//反序列化消息
	virtual bool unserialize(ByteStream &stream, Message *&message)
	{
		return false;
	}
};

#endif	//_PROTOCOL_H_INCLUDED


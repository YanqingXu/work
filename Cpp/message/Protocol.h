#ifndef _PROTOCOL_H_INCLUDED
#define _PROTOCOL_H_INCLUDED

#include "common/Message.h"

//ͨ��Э����
class Protocol
{
public:
	//��������
	virtual ~Protocol()
	{
	}

	//���л���Ϣ
	virtual bool serialize(Message *message, ByteStream &stream)
	{
		return false;
	}

	//�����л���Ϣ
	virtual bool unserialize(ByteStream &stream, Message *&message)
	{
		return false;
	}
};

#endif	//_PROTOCOL_H_INCLUDED


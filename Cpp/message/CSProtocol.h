#ifndef _CS_PROTOCOL_H_INCLUDED
#define _CS_PROTOCOL_H_INCLUDED

#include "Protocol.h"

//�ͻ��˷�����ͨ��Э����
class CSProtocol : public Protocol
{
public:
	CSProtocol();
	
	virtual ~CSProtocol();

	virtual bool serialize(Message *message, ByteStream &stream);

	virtual bool unserialize(ByteStream &stream, Message *&message);
};

#endif	//_CS_PROTOCOL_H_INCLUDED


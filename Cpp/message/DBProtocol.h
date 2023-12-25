#ifndef _DB_PROTOCOL_H_INCLUDED
#define _DB_PROTOCOL_H_INCLUDED

#include "Protocol.h"

//DBAGENTͨ��Э����
class DBProtocol : public Protocol
{
public:
	DBProtocol();
	
	virtual ~DBProtocol();

	virtual bool serialize(Message *message, ByteStream &stream);

	virtual bool unserialize(ByteStream &stream, Message *&message);
};

#endif	//_DB_PROTOCOL_H_INCLUDED


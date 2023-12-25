
#include "DBProtocol.h"
#include "MsgFactory.h"
#include "common/ByteStream.h"
#include "common/Logger.h"

static const char MSG_HEADER_FLAG			= 0x2f;	//消息头标记
static const size_t MSG_HEADER_SIZE		= 8;	//消息头长度

DBProtocol::DBProtocol()
{
}

DBProtocol::~DBProtocol()
{
}

bool DBProtocol::serialize(Message *message, ByteStream &stream)
{
	if (message == NULL)
	{
		return false;
	}

	if ((message->getCategory() <= 0) || (message->getID() <= 0) || (message->getLength() <= 0))
	{
		LOG_ERROR("invalid message: category=%d, id=%d, len=%d",
			message->getCategory(), message->getID(), message->getLength());
		return false;
	}

	size_t wpos1 = stream.wpos();

	//消息头
	stream << (char)MSG_HEADER_FLAG;			//消息头标记
	stream << (char)message->getCategory();		//消息类型
	stream << (short)message->getID();			//消息标识
	stream << (int)message->getLength();		//消息长度(消息头和消息体的总长度)

	//消息体
	message->serialize(stream);

	size_t wpos2 = stream.wpos();
	if (wpos2 - wpos1 != message->getLength())
	{
		LOG_ERROR("invalid message: category=%d, id=%d, len=%d",
			message->getCategory(), message->getID(), message->getLength());
	}

	return true;
}

bool DBProtocol::unserialize(ByteStream &stream, Message *&message)
{
	message = NULL;

	if (stream.rsize() < MSG_HEADER_SIZE)
	{
		return true;
	}

	char flag = 0;		//消息头标记
	char category = 0;	//消息类型
	short msgid = 0;	//消息标识
	int msglen = 0;		//消息长度(消息头和消息体的总长度)

	size_t old_rpos = stream.rpos();
	size_t skipped = 0;

	while (stream.rsize() >= MSG_HEADER_SIZE)
	{
		stream >> flag;
		if (flag == MSG_HEADER_FLAG)
		{
			break;
		}

		skipped++;
	}

	if (flag != MSG_HEADER_FLAG)
	{
		//未找到消息头标记
		LOG_ERROR("cannot find message header flag, skipped %d bytes", (int)skipped);
		return false;
	}
	
	stream >> category >> msgid >> msglen;

	if ((category <= 0) || (msgid <= 0) || (msglen <= 0))
	{
		LOG_ERROR("invalid message: category=%d, id=%d, len=%d",
			category, msgid, msglen);
		return false;
	}

	if (stream.rsize() < ((size_t)msglen - MSG_HEADER_SIZE))
	{
		//消息不完整, 等待数据
		stream.unread(MSG_HEADER_SIZE);
		return true;
	}

	//创建消息
	message = g_msg_factory.createMessage(category, msgid);
	if (message == NULL)
	{
		LOG_ERROR("create message FAILED, categroy = %d, id = %d", (int)category, (int)msgid);
		return false;
	}

	message->unserialize(stream);

	size_t real_size = stream.rpos() - old_rpos - skipped;
	if (real_size != (size_t)msglen)
	{
		LOG_ERROR("message length (%d) is wrong, real length is %d, category = %d, id = %d, name = %s",
			(int)msglen, (int)real_size, (int)category, (int)msgid, message->getName());
		return true;
	}

	//LOG_INFO("msg length right , message "<< pMsg->getMsgName());
	return true;
}

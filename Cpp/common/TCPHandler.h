
#ifndef _TCP_HANDLER_H_INCLUDED
#define _TCP_HANDLER_H_INCLUDED

class Message;
class ByteStream;

typedef void (*TCP_ACCEPT_FUNC)(void *handler, int session_id, const char *addr, int port);
typedef void (*TCP_CONNECT_FUNC)(void *handler, int session_id, const char *addr, int port);
typedef void (*TCP_CLOSE_FUNC)(void *handler, int session_id, const char *addr, int port);
typedef void (*TCP_RECV_FUNC)(void *handler, Message *message);

template <typename Handler>
class TCPHandler
{
public:
	TCPHandler(Handler &handler) :
		m_impl(handler)
	{
	}

	~TCPHandler()
	{
	}

	static void handleAccept(void *handler, int session_id, const char *addr, int port)
	{
		((TCPHandler *)handler)->m_impl(session_id, addr, port);
	}

	static void handleConnect(void *handler, int session_id, const char *addr, int port)
	{
		((TCPHandler *)handler)->m_impl(session_id, addr, port);
	}

	static void handleClose(void *handler, int session_id, const char *addr, int port)
	{
		((TCPHandler *)handler)->m_impl(session_id, addr, port);
	}

	static void handleRecv(void *handler, Message *message)
	{
		((TCPHandler *)handler)->m_impl(message);
	}

private:
	Handler m_impl;
};

//序列化消息
typedef bool (*TCP_SERIALIZE_FUNC)(Message *message, ByteStream &stream);
//反序列化消息
typedef bool (*TCP_UNSERIALIZE_FUNC)(ByteStream &stream, Message *&message);

////通信协议类
//class COMMON_API Protocol
//{
//public:
//	//序列化消息
//	static bool serialize(Message *message, ByteStream &stream);
//
//	//反序列化消息
//	static bool unserialize(ByteStream &stream, Message *&message);
//};

#endif	//!_TCP_HANDLER_H_INCLUDED

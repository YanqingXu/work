#ifndef _TCP_CLIENT_H_INCLUDED
#define	_TCP_CLIENT_H_INCLUDED

#include "types.h"
#include "TCPHandler.h"

class Message;
class Service;
class TCPClientImpl;

//TCP客户端
class COMMON_API TCPClient
{
public:
	//构造函数
	TCPClient(const char *name, Service *service);

	//析构函数
	~TCPClient();

	//启动
	template <typename Protocol, typename ConnectHandler, typename CloseHandler, typename RecvHandler>
	bool start(const char *host, int port, Protocol protocol,
		ConnectHandler &&connect_handler,
		CloseHandler &&close_handler,
		RecvHandler &&recv_handler)
	{
		return start(host, port,
			&Protocol::serialize,
			&Protocol::unserialize,
			&TCPHandler<ConnectHandler>::handleConnect, new TCPHandler<ConnectHandler>(connect_handler),
			&TCPHandler<CloseHandler>::handleClose, new TCPHandler<CloseHandler>(close_handler),
			&TCPHandler<RecvHandler>::handleRecv, new TCPHandler<RecvHandler>(recv_handler));
	}

	//停止
	void stop();

	//是否已经连接上服务器
	bool isConnected();

	//是否已经断开服务器
	bool isDisconnected();

	//更新
	void update(int elapse);

	//发送消息
	void send(Message *message);

	//发送消息
	void sendFirst(Message *message);

	void setDisconnectDiscard(bool b);

private:
	bool start(const char *host, int port,
		TCP_SERIALIZE_FUNC serialize_func,
		TCP_UNSERIALIZE_FUNC unserialize_func,
		TCP_CONNECT_FUNC connect_func, void *connect_handler,
		TCP_CLOSE_FUNC close_func, void *close_handler,
		TCP_RECV_FUNC recv_func, void *recv_handler);

private:
	Service *m_service;
	TCPClientImpl *m_impl;
};

#endif	//_TCP_CLIENT_H_INCLUDED

#ifndef _MESSAGE_H_INCLUDED
#define _MESSAGE_H_INCLUDED

#include "DumpBuffer.h"
#include "ByteStream.h"
#include "lua.h"

//
//	Message Interface
//
class Message
{
public:
	Message(char category, short id) :
		m_category(category),
		m_id(id),
		m_session_id(0)
	{
		m_in_queue_time = 0;
	}

	virtual ~Message()
	{
	}

	//入队时间
	unsigned long long getInQueueTime() const { return m_in_queue_time; }
	void setInQueueTime(unsigned long long t) { m_in_queue_time = t; }

	//会话ID
	void setSessionID(int session_id) { m_session_id = session_id; }
	int	getSessionID() const { return m_session_id; }
	int	getSessionIndex() const { return (m_session_id >> 16); }
	int	getSessionSerial() const { return (m_session_id & 0xffff); }

	//消息分类
	char getCategory() const { return m_category; }
	void setCategory(char category) { m_category = category; }

	//消息ID
	short getID() const { return m_id; }
	void setID(short id) { m_id = id; }

	//消息名称
	virtual const char *getName() const { return ""; }

	virtual int getSalt() const { return 0; }

	virtual bool canSendToCrossFromClient() const { return false; }

	//取消息长度
	virtual size_t getLength() const { return 0; }

	//序列化
	virtual bool serialize(ByteStream &stream) const { return true; }

	//反序列化
	virtual bool unserialize(ByteStream &stream) { return true; }

	virtual void push(lua_State *L) { lua::pushnil(L); }

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "m_session_id=" << m_session_id
			<< ",m_category=" << m_category
			<< ",m_id=" << m_id;
	}

protected:
	unsigned long long m_in_queue_time;	//入队时间

	int	m_session_id;		//会话ID
	char m_category;		//消息分类
	short m_id;				//消息ID
};

#endif	//_MESSAGE_H_INCLUDED

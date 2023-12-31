﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _DB_MSG_MAIL_H_INCLUDED
#define _DB_MSG_MAIL_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

struct DBMail
{
public:
	DBMail()
	{
		pid = 0;
		mid = 0;
		readed = 0;
		got = 0;
		opcode = 0;
		ctime = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 18;
		length += sizeof(short) + title.size();
		length += sizeof(short) + content.size();
		length += sizeof(short) + items.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << pid;
		s << mid;
		s << title;
		s << content;
		s << items;
		s << readed;
		s << got;
		s << opcode;
		s << ctime;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> pid;
		s >> mid;
		s >> title;
		s >> content;
		s >> items;
		s >> readed;
		s >> got;
		s >> opcode;
		s >> ctime;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "mid", mid);
		lua::settable(L, -1, "title", title);
		lua::settable(L, -1, "content", content);
		lua::settable(L, -1, "items", items);
		lua::settable(L, -1, "readed", readed);
		lua::settable(L, -1, "got", got);
		lua::settable(L, -1, "opcode", opcode);
		lua::settable(L, -1, "ctime", ctime);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "pid=" << pid;
		buffer << ",mid=" << mid;
		buffer << ",title=" << title;
		buffer << ",content=" << content;
		buffer << ",items=" << items;
		buffer << ",readed=" << readed;
		buffer << ",got=" << got;
		buffer << ",opcode=" << opcode;
		buffer << ",ctime=" << ctime;
	}

public:
	int pid;
	int mid;
	std::string title;
	std::string content;
	std::string items;
	char readed;
	char got;
	int opcode;
	int ctime;
};

class MsgDBLoadMail : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 1 };

	MsgDBLoadMail() :
		MessageEx(Category, Id)
	{
		pid = 0;
		load_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadMail";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return pid;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 8;
		length += sizeof(int);
		for (size_t i = 0; i < mails.size(); ++i)
		{
			length += mails[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << load_id;
		int mails_vector_size = (int)mails.size();
		s << mails_vector_size;
		if (mails_vector_size > 0)
		{
			for (auto it = mails.begin(); it != mails.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> load_id;
		int mails_vector_size = s.read_int32();
		mails.clear();
		while (mails_vector_size > 0)
		{
			mails_vector_size--;
			DBMail val;
			val.unserialize(s, true);
			mails.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "load_id", load_id);
		lua::newtable(lua::L);
		for (size_t i = 0; i < mails.size(); ++i)
		{
			mails[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "mails");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",load_id=" << load_id;
		buffer << ",mails=[";
		for (size_t i = 0; i < mails.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			mails[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int pid;
	int load_id;
	std::vector<DBMail> mails;
};

class MsgDBLoadExpiredMail : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 2 };

	MsgDBLoadExpiredMail() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadExpiredMail";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return 0;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength();
		length += sizeof(int);
		for (size_t i = 0; i < mails.size(); ++i)
		{
			length += mails[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int mails_vector_size = (int)mails.size();
		s << mails_vector_size;
		if (mails_vector_size > 0)
		{
			for (auto it = mails.begin(); it != mails.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int mails_vector_size = s.read_int32();
		mails.clear();
		while (mails_vector_size > 0)
		{
			mails_vector_size--;
			DBMail val;
			val.unserialize(s, true);
			mails.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < mails.size(); ++i)
		{
			mails[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "mails");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",mails=[";
		for (size_t i = 0; i < mails.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			mails[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBMail> mails;
};

class MsgDBCreateMail : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 3 };

	MsgDBCreateMail() :
		MessageEx(Category, Id)
	{
		pid = 0;
		mid = 0;
		opcode = 0;
		ctime = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBCreateMail";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return 0;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 16;
		length += sizeof(short) + pname.size();
		length += sizeof(short) + title.size();
		length += sizeof(short) + content.size();
		length += sizeof(short) + items.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pname;
		s << pid;
		s << mid;
		s << title;
		s << content;
		s << items;
		s << opcode;
		s << ctime;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pname;
		s >> pid;
		s >> mid;
		s >> title;
		s >> content;
		s >> items;
		s >> opcode;
		s >> ctime;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pname", pname);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "mid", mid);
		lua::settable(L, -1, "title", title);
		lua::settable(L, -1, "content", content);
		lua::settable(L, -1, "items", items);
		lua::settable(L, -1, "opcode", opcode);
		lua::settable(L, -1, "ctime", ctime);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pname=" << pname;
		buffer << ",pid=" << pid;
		buffer << ",mid=" << mid;
		buffer << ",title=" << title;
		buffer << ",content=" << content;
		buffer << ",items=" << items;
		buffer << ",opcode=" << opcode;
		buffer << ",ctime=" << ctime;
	}

public:
	std::string pname;
	int pid;
	int mid;
	std::string title;
	std::string content;
	std::string items;
	int opcode;
	int ctime;
};

class MsgDBDeleteMail : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 4 };

	MsgDBDeleteMail() :
		MessageEx(Category, Id)
	{
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBDeleteMail";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return pid;
	}

	virtual bool getSendBack() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += sizeof(int);
		length += mids.size() * 4;
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		int mids_vector_size = (int)mids.size();
		s << mids_vector_size;
		if (mids_vector_size > 0)
		{
			for (auto it = mids.begin(); it != mids.end(); ++it)
			{
				s << *it;
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		int mids_vector_size = s.read_int32();
		mids.clear();
		while (mids_vector_size > 0)
		{
			mids_vector_size--;
			int val;
			s >> val;
			mids.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::newtable(lua::L);
		for (size_t i = 0; i < mids.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, mids[i]);
		}
		lua::settable(L, -2, "mids");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",mids=[";
		for (size_t i = 0; i < mids.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << mids[i];
		}
		buffer << "]";
	}

public:
	int pid;
	std::vector<int> mids;
};

class MsgDBSetMailReaded : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 5 };

	MsgDBSetMailReaded() :
		MessageEx(Category, Id)
	{
		pid = 0;
		mid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBSetMailReaded";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return pid;
	}

	virtual bool getSendBack() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << mid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> mid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "mid", mid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",mid=" << mid;
	}

public:
	int pid;
	int mid;
};

class MsgDBSetMailGot : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_MAIL, Id = 6 };

	MsgDBSetMailGot() :
		MessageEx(Category, Id)
	{
		pid = 0;
		mid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBSetMailGot";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return pid;
	}

	virtual bool getSendBack() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << mid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> mid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "mid", mid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",mid=" << mid;
	}

public:
	int pid;
	int mid;
};

#endif	//_DB_MSG_MAIL_H_INCLUDED

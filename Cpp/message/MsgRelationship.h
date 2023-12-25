﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_RELATIONSHIP_H_INCLUDED
#define _MSG_RELATIONSHIP_H_INCLUDED

#include "category.h"
#include "common/Message.h"

struct RelationInfo
{
public:
	RelationInfo()
	{
		pid = 0;
		gender = 0;
		clazz = 0;
		reborn = 0;
		level = 0;
		online = 0;
		zhanli = 0;
		contactTime = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 26;
		length += sizeof(short) + name.size();
		length += sizeof(short) + gdname.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << pid;
		s << name;
		s << gender;
		s << clazz;
		s << reborn;
		s << level;
		s << gdname;
		s << online;
		s << zhanli;
		s << contactTime;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> pid;
		s >> name;
		s >> gender;
		s >> clazz;
		s >> reborn;
		s >> level;
		s >> gdname;
		s >> online;
		s >> zhanli;
		s >> contactTime;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "name", name);
		lua::settable(L, -1, "gender", gender);
		lua::settable(L, -1, "clazz", clazz);
		lua::settable(L, -1, "reborn", reborn);
		lua::settable(L, -1, "level", level);
		lua::settable(L, -1, "gdname", gdname);
		lua::settable(L, -1, "online", online);
		lua::settable(L, -1, "zhanli", zhanli);
		lua::settable(L, -1, "contactTime", contactTime);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "pid=" << pid;
		buffer << ",name=" << name;
		buffer << ",gender=" << gender;
		buffer << ",clazz=" << clazz;
		buffer << ",reborn=" << reborn;
		buffer << ",level=" << level;
		buffer << ",gdname=" << gdname;
		buffer << ",online=" << online;
		buffer << ",zhanli=" << zhanli;
		buffer << ",contactTime=" << contactTime;
	}

public:
	int pid;
	std::string name;
	char gender;
	char clazz;
	int reborn;
	int level;
	std::string gdname;
	int online;
	int zhanli;
	int contactTime;
};

class MsgRelationListRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 11 };

	MsgRelationListRequest() :
		Message(Category, Id)
	{
		type = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationListRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 1;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
	}

public:
	char type;
};

class MsgRelationListResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 12 };

	MsgRelationListResponse() :
		Message(Category, Id)
	{
		errcode = 0;
		type = 0;
		isbegin = 0;
		isend = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationListResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 5;
		length += sizeof(short);
		for (size_t i = 0; i < relations.size(); ++i)
		{
			length += relations[i].getLength(false);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << errcode;
		s << type;
		s << isbegin;
		s << isend;
		short relations_vector_size = (short)relations.size();
		s << relations_vector_size;
		if (relations_vector_size > 0)
		{
			for (auto it = relations.begin(); it != relations.end(); ++it)
			{
				(*it).serialize(s, false);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> errcode;
		s >> type;
		s >> isbegin;
		s >> isend;
		int relations_vector_size = s.read_int16();
		relations.clear();
		while (relations_vector_size > 0)
		{
			relations_vector_size--;
			RelationInfo val;
			val.unserialize(s, false);
			relations.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "errcode", errcode);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "isbegin", isbegin);
		lua::settable(L, -1, "isend", isend);
		lua::newtable(lua::L);
		for (size_t i = 0; i < relations.size(); ++i)
		{
			relations[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "relations");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "errcode=" << errcode;
		buffer << ",type=" << type;
		buffer << ",isbegin=" << isbegin;
		buffer << ",isend=" << isend;
		buffer << ",relations=[";
		for (size_t i = 0; i < relations.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			relations[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	short errcode;
	char type;
	char isbegin;
	char isend;
	std::vector<RelationInfo> relations;
};

class MsgRelationOperateRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 13 };

	MsgRelationOperateRequest() :
		Message(Category, Id)
	{
		type = 0;
		step = 0;
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationOperateRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 8;
		length += sizeof(short) + name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		s << step;
		s << pid;
		s << name;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		s >> step;
		s >> pid;
		s >> name;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "step", step);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "name", name);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",step=" << step;
		buffer << ",pid=" << pid;
		buffer << ",name=" << name;
	}

public:
	short type;
	short step;
	int pid;
	std::string name;
};

class MsgRelationOperateResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 14 };

	MsgRelationOperateResponse() :
		Message(Category, Id)
	{
		type = 0;
		step = 0;
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationOperateResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 6;
		length += data.getLength(false);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		s << step;
		s << errcode;
		data.serialize(s, false);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		s >> step;
		s >> errcode;
		data.unserialize(s, false);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "step", step);
		lua::settable(L, -1, "errcode", errcode);
		data.push(L);
		lua::settable(L, -1, "data");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",step=" << step;
		buffer << ",errcode=" << errcode;
		buffer << ",data={";
		data.dump(buffer);
		buffer << "}";
	}

public:
	short type;
	short step;
	short errcode;
	RelationInfo data;
};

class MsgRelationFindingRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 15 };

	MsgRelationFindingRequest() :
		Message(Category, Id)
	{
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationFindingRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 4;
		length += sizeof(short) + name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << pid;
		s << name;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> pid;
		s >> name;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "name", name);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "pid=" << pid;
		buffer << ",name=" << name;
	}

public:
	int pid;
	std::string name;
};

class MsgRelationFindingResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 16 };

	MsgRelationFindingResponse() :
		Message(Category, Id)
	{
		pid = 0;
		posx = 0;
		posy = 0;
		sceneid = 0;
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationFindingResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 18;
		length += sizeof(short) + name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << pid;
		s << name;
		s << posx;
		s << posy;
		s << sceneid;
		s << errcode;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> pid;
		s >> name;
		s >> posx;
		s >> posy;
		s >> sceneid;
		s >> errcode;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "name", name);
		lua::settable(L, -1, "posx", posx);
		lua::settable(L, -1, "posy", posy);
		lua::settable(L, -1, "sceneid", sceneid);
		lua::settable(L, -1, "errcode", errcode);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "pid=" << pid;
		buffer << ",name=" << name;
		buffer << ",posx=" << posx;
		buffer << ",posy=" << posy;
		buffer << ",sceneid=" << sceneid;
		buffer << ",errcode=" << errcode;
	}

public:
	int pid;
	std::string name;
	int posx;
	int posy;
	int sceneid;
	short errcode;
};

class MsgRelationAddNotify : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 17 };

	MsgRelationAddNotify() :
		Message(Category, Id)
	{
		type = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationAddNotify";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 4;
		length += info.getLength(false);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		info.serialize(s, false);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		info.unserialize(s, false);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		info.push(L);
		lua::settable(L, -1, "info");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",info={";
		info.dump(buffer);
		buffer << "}";
	}

public:
	int type;
	RelationInfo info;
};

class MsgRelationRmvNotify : public Message
{
public:
	enum { Category = MSG_CATEGORY_RELATIONSHIP, Id = 18 };

	MsgRelationRmvNotify() :
		Message(Category, Id)
	{
		type = 0;
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgRelationRmvNotify";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		s << pid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		s >> pid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "pid", pid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",pid=" << pid;
	}

public:
	int type;
	int pid;
};

#endif	//_MSG_RELATIONSHIP_H_INCLUDED
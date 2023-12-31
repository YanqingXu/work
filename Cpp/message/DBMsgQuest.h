﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _DB_MSG_QUEST_H_INCLUDED
#define _DB_MSG_QUEST_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

struct DBQuestInfo
{
public:
	DBQuestInfo()
	{
		qid = 0;
		sid = 0;
		state = 0;
		datax = 0;
		datay = 0;
		dataz = 0;
	}

	size_t getLength(bool ex) const
	{
		return 20;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << qid;
		s << sid;
		s << state;
		s << datax;
		s << datay;
		s << dataz;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> qid;
		s >> sid;
		s >> state;
		s >> datax;
		s >> datay;
		s >> dataz;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "qid", qid);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "state", state);
		lua::settable(L, -1, "datax", datax);
		lua::settable(L, -1, "datay", datay);
		lua::settable(L, -1, "dataz", dataz);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "qid=" << qid;
		buffer << ",sid=" << sid;
		buffer << ",state=" << state;
		buffer << ",datax=" << datax;
		buffer << ",datay=" << datay;
		buffer << ",dataz=" << dataz;
	}

public:
	short qid;
	int sid;
	short state;
	int datax;
	int datay;
	int dataz;
};

class MsgDBLoadQuests : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_QUEST, Id = 1 };

	MsgDBLoadQuests() :
		MessageEx(Category, Id)
	{
		pid = 0;
		load_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadQuests";
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
		for (size_t i = 0; i < quests.size(); ++i)
		{
			length += quests[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << load_id;
		int quests_vector_size = (int)quests.size();
		s << quests_vector_size;
		if (quests_vector_size > 0)
		{
			for (auto it = quests.begin(); it != quests.end(); ++it)
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
		int quests_vector_size = s.read_int32();
		quests.clear();
		while (quests_vector_size > 0)
		{
			quests_vector_size--;
			DBQuestInfo val;
			val.unserialize(s, true);
			quests.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "load_id", load_id);
		lua::newtable(lua::L);
		for (size_t i = 0; i < quests.size(); ++i)
		{
			quests[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "quests");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",load_id=" << load_id;
		buffer << ",quests=[";
		for (size_t i = 0; i < quests.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			quests[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int pid;
	int load_id;
	std::vector<DBQuestInfo> quests;
};

class MsgDBUpdateQuest : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_QUEST, Id = 2 };

	MsgDBUpdateQuest() :
		MessageEx(Category, Id)
	{
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBUpdateQuest";
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
		size_t length = __super::getLength() + 4;
		length += quest.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		quest.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		quest.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		quest.push(L);
		lua::settable(L, -1, "quest");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",quest={";
		quest.dump(buffer);
		buffer << "}";
	}

public:
	int pid;
	DBQuestInfo quest;
};

class MsgDBDeleteQuest : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_QUEST, Id = 3 };

	MsgDBDeleteQuest() :
		MessageEx(Category, Id)
	{
		pid = 0;
		qid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBDeleteQuest";
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
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << qid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> qid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "qid", qid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",qid=" << qid;
	}

public:
	int pid;
	int qid;
};

#endif	//_DB_MSG_QUEST_H_INCLUDED

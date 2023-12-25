﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _DB_MSG_CROSS_H_INCLUDED
#define _DB_MSG_CROSS_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

class MsgDBCreateCrossMail : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 1 };

	MsgDBCreateCrossMail() :
		MessageEx(Category, Id)
	{
		pid = 0;
		sourceServerId = 0;
		mid = 0;
		opcode = 0;
		ctime = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBCreateCrossMail";
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
		size_t length = __super::getLength() + 20;
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
		s << sourceServerId;
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
		s >> sourceServerId;
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
		lua::settable(L, -1, "sourceServerId", sourceServerId);
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
		buffer << ",sourceServerId=" << sourceServerId;
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
	int sourceServerId;
	int mid;
	std::string title;
	std::string content;
	std::string items;
	int opcode;
	int ctime;
};

struct DBPlayerCrossEvent
{
public:
	DBPlayerCrossEvent()
	{
		eid = 0;
		tindex = 0;
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
		s << eid;
		s << tindex;
		s << datax;
		s << datay;
		s << dataz;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> eid;
		s >> tindex;
		s >> datax;
		s >> datay;
		s >> dataz;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "eid", eid);
		lua::settable(L, -1, "tindex", tindex);
		lua::settable(L, -1, "datax", datax);
		lua::settable(L, -1, "datay", datay);
		lua::settable(L, -1, "dataz", dataz);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "eid=" << eid;
		buffer << ",tindex=" << tindex;
		buffer << ",datax=" << datax;
		buffer << ",datay=" << datay;
		buffer << ",dataz=" << dataz;
	}

public:
	int eid;
	int tindex;
	int datax;
	int datay;
	int dataz;
};

class MsgDBLoadPlayerCrossEvent : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 2 };

	MsgDBLoadPlayerCrossEvent() :
		MessageEx(Category, Id)
	{
		pid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadPlayerCrossEvent";
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
		length += sizeof(int);
		for (size_t i = 0; i < events.size(); ++i)
		{
			length += events[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		int events_vector_size = (int)events.size();
		s << events_vector_size;
		if (events_vector_size > 0)
		{
			for (auto it = events.begin(); it != events.end(); ++it)
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
		int events_vector_size = s.read_int32();
		events.clear();
		while (events_vector_size > 0)
		{
			events_vector_size--;
			DBPlayerCrossEvent val;
			val.unserialize(s, true);
			events.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::newtable(lua::L);
		for (size_t i = 0; i < events.size(); ++i)
		{
			events[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "events");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",events=[";
		for (size_t i = 0; i < events.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			events[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int pid;
	std::vector<DBPlayerCrossEvent> events;
};

struct DBKF3V3ZhanDui
{
public:
	DBKF3V3ZhanDui()
	{
		zhandui_id = 0;
		game_server_id = 0;
		score = 0;
		score_seq = 0;
		score_time = 0;
		rank = 0;
		top = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 28;
		length += sizeof(short) + zhandui_name.size();
		length += sizeof(short) + game_server_name.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << zhandui_id;
		s << zhandui_name;
		s << game_server_id;
		s << game_server_name;
		s << score;
		s << score_seq;
		s << score_time;
		s << rank;
		s << top;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> zhandui_id;
		s >> zhandui_name;
		s >> game_server_id;
		s >> game_server_name;
		s >> score;
		s >> score_seq;
		s >> score_time;
		s >> rank;
		s >> top;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "zhandui_name", zhandui_name);
		lua::settable(L, -1, "game_server_id", game_server_id);
		lua::settable(L, -1, "game_server_name", game_server_name);
		lua::settable(L, -1, "score", score);
		lua::settable(L, -1, "score_seq", score_seq);
		lua::settable(L, -1, "score_time", score_time);
		lua::settable(L, -1, "rank", rank);
		lua::settable(L, -1, "top", top);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "zhandui_id=" << zhandui_id;
		buffer << ",zhandui_name=" << zhandui_name;
		buffer << ",game_server_id=" << game_server_id;
		buffer << ",game_server_name=" << game_server_name;
		buffer << ",score=" << score;
		buffer << ",score_seq=" << score_seq;
		buffer << ",score_time=" << score_time;
		buffer << ",rank=" << rank;
		buffer << ",top=" << top;
	}

public:
	int zhandui_id;
	std::string zhandui_name;
	int game_server_id;
	std::string game_server_name;
	int score;
	int score_seq;
	int score_time;
	int rank;
	int top;
};

class MsgDBKF3V3ZhanDuiLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 11 };

	MsgDBKF3V3ZhanDuiLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiLoad";
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
		for (size_t i = 0; i < zhanduis.size(); ++i)
		{
			length += zhanduis[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int zhanduis_vector_size = (int)zhanduis.size();
		s << zhanduis_vector_size;
		if (zhanduis_vector_size > 0)
		{
			for (auto it = zhanduis.begin(); it != zhanduis.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int zhanduis_vector_size = s.read_int32();
		zhanduis.clear();
		while (zhanduis_vector_size > 0)
		{
			zhanduis_vector_size--;
			DBKF3V3ZhanDui val;
			val.unserialize(s, true);
			zhanduis.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < zhanduis.size(); ++i)
		{
			zhanduis[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "zhanduis");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhanduis=[";
		for (size_t i = 0; i < zhanduis.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			zhanduis[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBKF3V3ZhanDui> zhanduis;
};

class MsgDBKF3V3ZhanDuiAdd : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 12 };

	MsgDBKF3V3ZhanDuiAdd() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		game_server_id = 0;
		score = 0;
		score_seq = 0;
		score_time = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiAdd";
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
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 20;
		length += sizeof(short) + zhandui_name.size();
		length += sizeof(short) + game_server_name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << zhandui_name;
		s << game_server_id;
		s << game_server_name;
		s << score;
		s << score_seq;
		s << score_time;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> zhandui_name;
		s >> game_server_id;
		s >> game_server_name;
		s >> score;
		s >> score_seq;
		s >> score_time;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "zhandui_name", zhandui_name);
		lua::settable(L, -1, "game_server_id", game_server_id);
		lua::settable(L, -1, "game_server_name", game_server_name);
		lua::settable(L, -1, "score", score);
		lua::settable(L, -1, "score_seq", score_seq);
		lua::settable(L, -1, "score_time", score_time);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",zhandui_name=" << zhandui_name;
		buffer << ",game_server_id=" << game_server_id;
		buffer << ",game_server_name=" << game_server_name;
		buffer << ",score=" << score;
		buffer << ",score_seq=" << score_seq;
		buffer << ",score_time=" << score_time;
	}

public:
	int zhandui_id;
	std::string zhandui_name;
	int game_server_id;
	std::string game_server_name;
	int score;
	int score_seq;
	int score_time;
};

class MsgDBKF3V3ZhanDuiSetScore : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 13 };

	MsgDBKF3V3ZhanDuiSetScore() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		score = 0;
		score_seq = 0;
		score_time = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiSetScore";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 16;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << score;
		s << score_seq;
		s << score_time;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> score;
		s >> score_seq;
		s >> score_time;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "score", score);
		lua::settable(L, -1, "score_seq", score_seq);
		lua::settable(L, -1, "score_time", score_time);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",score=" << score;
		buffer << ",score_seq=" << score_seq;
		buffer << ",score_time=" << score_time;
	}

public:
	int zhandui_id;
	int score;
	int score_seq;
	int score_time;
};

class MsgDBKF3V3ZhanDuiSetRank : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 14 };

	MsgDBKF3V3ZhanDuiSetRank() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		rank = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiSetRank";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << rank;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> rank;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "rank", rank);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",rank=" << rank;
	}

public:
	int zhandui_id;
	int rank;
};

class MsgDBKF3V3ZhanDuiSetTop : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 15 };

	MsgDBKF3V3ZhanDuiSetTop() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		top = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiSetTop";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << top;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> top;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "top", top);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",top=" << top;
	}

public:
	int zhandui_id;
	int top;
};

class MsgDBKF3V3ZhanDuiSetGameServerId : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 16 };

	MsgDBKF3V3ZhanDuiSetGameServerId() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		game_server_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiSetGameServerId";
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
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 8;
		length += sizeof(short) + game_server_name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << game_server_id;
		s << game_server_name;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> game_server_id;
		s >> game_server_name;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "game_server_id", game_server_id);
		lua::settable(L, -1, "game_server_name", game_server_name);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",game_server_id=" << game_server_id;
		buffer << ",game_server_name=" << game_server_name;
	}

public:
	int zhandui_id;
	int game_server_id;
	std::string game_server_name;
};

class MsgDBKF3V3ZhanDuiDel : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 17 };

	MsgDBKF3V3ZhanDuiDel() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiDel";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 4;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
	}

public:
	int zhandui_id;
};

struct DBKF3V3ZhanDuiMember
{
public:
	DBKF3V3ZhanDuiMember()
	{
		zhandui_id = 0;
		player_id = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 8;
		length += sizeof(short) + player_name.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << zhandui_id;
		s << player_id;
		s << player_name;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> zhandui_id;
		s >> player_id;
		s >> player_name;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "player_id", player_id);
		lua::settable(L, -1, "player_name", player_name);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "zhandui_id=" << zhandui_id;
		buffer << ",player_id=" << player_id;
		buffer << ",player_name=" << player_name;
	}

public:
	int zhandui_id;
	int player_id;
	std::string player_name;
};

class MsgDBKF3V3ZhanDuiMemberLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 21 };

	MsgDBKF3V3ZhanDuiMemberLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiMemberLoad";
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
		for (size_t i = 0; i < members.size(); ++i)
		{
			length += members[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int members_vector_size = (int)members.size();
		s << members_vector_size;
		if (members_vector_size > 0)
		{
			for (auto it = members.begin(); it != members.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int members_vector_size = s.read_int32();
		members.clear();
		while (members_vector_size > 0)
		{
			members_vector_size--;
			DBKF3V3ZhanDuiMember val;
			val.unserialize(s, true);
			members.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < members.size(); ++i)
		{
			members[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "members");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",members=[";
		for (size_t i = 0; i < members.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			members[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBKF3V3ZhanDuiMember> members;
};

class MsgDBKF3V3ZhanDuiMemberAdd : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 22 };

	MsgDBKF3V3ZhanDuiMemberAdd() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		player_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiMemberAdd";
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
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 8;
		length += sizeof(short) + player_name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << player_id;
		s << player_name;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> player_id;
		s >> player_name;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "player_id", player_id);
		lua::settable(L, -1, "player_name", player_name);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",player_id=" << player_id;
		buffer << ",player_name=" << player_name;
	}

public:
	int zhandui_id;
	int player_id;
	std::string player_name;
};

class MsgDBKF3V3ZhanDuiMemberDel : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 23 };

	MsgDBKF3V3ZhanDuiMemberDel() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		player_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiMemberDel";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength() + 8;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << player_id;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> player_id;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "player_id", player_id);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",player_id=" << player_id;
	}

public:
	int zhandui_id;
	int player_id;
};

class MsgDBKF3V3ZhanDuiMemberNameChanged : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 24 };

	MsgDBKF3V3ZhanDuiMemberNameChanged() :
		MessageEx(Category, Id)
	{
		zhandui_id = 0;
		player_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3ZhanDuiMemberNameChanged";
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
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 8;
		length += sizeof(short) + player_name.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << zhandui_id;
		s << player_id;
		s << player_name;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> zhandui_id;
		s >> player_id;
		s >> player_name;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "zhandui_id", zhandui_id);
		lua::settable(L, -1, "player_id", player_id);
		lua::settable(L, -1, "player_name", player_name);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",zhandui_id=" << zhandui_id;
		buffer << ",player_id=" << player_id;
		buffer << ",player_name=" << player_name;
	}

public:
	int zhandui_id;
	int player_id;
	std::string player_name;
};

struct DBKF3V3Record
{
public:
	DBKF3V3Record()
	{
		competition_id = 0;
		zhandui_id1 = 0;
		zhandui_id2 = 0;
		winner = 0;
		ctime = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 20;
		length += sizeof(short) + zhandui_name1.size();
		length += sizeof(short) + zhandui_name2.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << competition_id;
		s << zhandui_id1;
		s << zhandui_name1;
		s << zhandui_id2;
		s << zhandui_name2;
		s << winner;
		s << ctime;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> competition_id;
		s >> zhandui_id1;
		s >> zhandui_name1;
		s >> zhandui_id2;
		s >> zhandui_name2;
		s >> winner;
		s >> ctime;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "competition_id", competition_id);
		lua::settable(L, -1, "zhandui_id1", zhandui_id1);
		lua::settable(L, -1, "zhandui_name1", zhandui_name1);
		lua::settable(L, -1, "zhandui_id2", zhandui_id2);
		lua::settable(L, -1, "zhandui_name2", zhandui_name2);
		lua::settable(L, -1, "winner", winner);
		lua::settable(L, -1, "ctime", ctime);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "competition_id=" << competition_id;
		buffer << ",zhandui_id1=" << zhandui_id1;
		buffer << ",zhandui_name1=" << zhandui_name1;
		buffer << ",zhandui_id2=" << zhandui_id2;
		buffer << ",zhandui_name2=" << zhandui_name2;
		buffer << ",winner=" << winner;
		buffer << ",ctime=" << ctime;
	}

public:
	int competition_id;
	int zhandui_id1;
	std::string zhandui_name1;
	int zhandui_id2;
	std::string zhandui_name2;
	int winner;
	int ctime;
};

class MsgDBKF3V3RecordLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 31 };

	MsgDBKF3V3RecordLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3RecordLoad";
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
		for (size_t i = 0; i < records.size(); ++i)
		{
			length += records[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int records_vector_size = (int)records.size();
		s << records_vector_size;
		if (records_vector_size > 0)
		{
			for (auto it = records.begin(); it != records.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int records_vector_size = s.read_int32();
		records.clear();
		while (records_vector_size > 0)
		{
			records_vector_size--;
			DBKF3V3Record val;
			val.unserialize(s, true);
			records.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < records.size(); ++i)
		{
			records[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "records");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",records=[";
		for (size_t i = 0; i < records.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			records[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBKF3V3Record> records;
};

class MsgDBKF3V3RecordAdd : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 32 };

	MsgDBKF3V3RecordAdd() :
		MessageEx(Category, Id)
	{
		competition_id = 0;
		zhandui_id1 = 0;
		zhandui_id2 = 0;
		winner = 0;
		ctime = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3RecordAdd";
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
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 20;
		length += sizeof(short) + zhandui_name1.size();
		length += sizeof(short) + zhandui_name2.size();
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << competition_id;
		s << zhandui_id1;
		s << zhandui_name1;
		s << zhandui_id2;
		s << zhandui_name2;
		s << winner;
		s << ctime;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> competition_id;
		s >> zhandui_id1;
		s >> zhandui_name1;
		s >> zhandui_id2;
		s >> zhandui_name2;
		s >> winner;
		s >> ctime;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "competition_id", competition_id);
		lua::settable(L, -1, "zhandui_id1", zhandui_id1);
		lua::settable(L, -1, "zhandui_name1", zhandui_name1);
		lua::settable(L, -1, "zhandui_id2", zhandui_id2);
		lua::settable(L, -1, "zhandui_name2", zhandui_name2);
		lua::settable(L, -1, "winner", winner);
		lua::settable(L, -1, "ctime", ctime);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",competition_id=" << competition_id;
		buffer << ",zhandui_id1=" << zhandui_id1;
		buffer << ",zhandui_name1=" << zhandui_name1;
		buffer << ",zhandui_id2=" << zhandui_id2;
		buffer << ",zhandui_name2=" << zhandui_name2;
		buffer << ",winner=" << winner;
		buffer << ",ctime=" << ctime;
	}

public:
	int competition_id;
	int zhandui_id1;
	std::string zhandui_name1;
	int zhandui_id2;
	std::string zhandui_name2;
	int winner;
	int ctime;
};

class MsgDBKF3V3Clear : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CROSS, Id = 33 };

	MsgDBKF3V3Clear() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBKF3V3Clear";
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
		return false;
	}

	virtual size_t getLength() const
	{
		return __super::getLength();
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
	}

public:
};

#endif	//_DB_MSG_CROSS_H_INCLUDED

﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _DB_MSG_HOLIDAY_H_INCLUDED
#define _DB_MSG_HOLIDAY_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

struct DBHolidayInfo
{
public:
	DBHolidayInfo()
	{
		switch_id = 0;
		type = 0;
		begin_show_time = 0;
		end_show_time = 0;
		begin_time = 0;
		end_time = 0;
		state = 0;
		world_id = 0;
		event_id = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 36;
		length += sizeof(short) + str_menu.size();
		length += sizeof(short) + str_title.size();
		length += sizeof(short) + str_content.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << switch_id;
		s << type;
		s << begin_show_time;
		s << end_show_time;
		s << begin_time;
		s << end_time;
		s << state;
		s << world_id;
		s << event_id;
		s << str_menu;
		s << str_title;
		s << str_content;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> switch_id;
		s >> type;
		s >> begin_show_time;
		s >> end_show_time;
		s >> begin_time;
		s >> end_time;
		s >> state;
		s >> world_id;
		s >> event_id;
		s >> str_menu;
		s >> str_title;
		s >> str_content;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "begin_show_time", begin_show_time);
		lua::settable(L, -1, "end_show_time", end_show_time);
		lua::settable(L, -1, "begin_time", begin_time);
		lua::settable(L, -1, "end_time", end_time);
		lua::settable(L, -1, "state", state);
		lua::settable(L, -1, "world_id", world_id);
		lua::settable(L, -1, "event_id", event_id);
		lua::settable(L, -1, "str_menu", str_menu);
		lua::settable(L, -1, "str_title", str_title);
		lua::settable(L, -1, "str_content", str_content);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "switch_id=" << switch_id;
		buffer << ",type=" << type;
		buffer << ",begin_show_time=" << begin_show_time;
		buffer << ",end_show_time=" << end_show_time;
		buffer << ",begin_time=" << begin_time;
		buffer << ",end_time=" << end_time;
		buffer << ",state=" << state;
		buffer << ",world_id=" << world_id;
		buffer << ",event_id=" << event_id;
		buffer << ",str_menu=" << str_menu;
		buffer << ",str_title=" << str_title;
		buffer << ",str_content=" << str_content;
	}

public:
	int switch_id;
	int type;
	int begin_show_time;
	int end_show_time;
	int begin_time;
	int end_time;
	int state;
	int world_id;
	int event_id;
	std::string str_menu;
	std::string str_title;
	std::string str_content;
};

struct DBHolidayGrade
{
public:
	DBHolidayGrade()
	{
		index = 0;
		mark = 0;
		switch_id = 0;
		world_id = 0;
		event_id = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 20;
		length += sizeof(short) + str_content.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << index;
		s << mark;
		s << switch_id;
		s << world_id;
		s << event_id;
		s << str_content;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> index;
		s >> mark;
		s >> switch_id;
		s >> world_id;
		s >> event_id;
		s >> str_content;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "index", index);
		lua::settable(L, -1, "mark", mark);
		lua::settable(L, -1, "switch_id", switch_id);
		lua::settable(L, -1, "world_id", world_id);
		lua::settable(L, -1, "event_id", event_id);
		lua::settable(L, -1, "str_content", str_content);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "index=" << index;
		buffer << ",mark=" << mark;
		buffer << ",switch_id=" << switch_id;
		buffer << ",world_id=" << world_id;
		buffer << ",event_id=" << event_id;
		buffer << ",str_content=" << str_content;
	}

public:
	int index;
	int mark;
	int switch_id;
	int world_id;
	int event_id;
	std::string str_content;
};

struct DBHolidayItem
{
public:
	DBHolidayItem()
	{
		index = 0;
		mark = 0;
		switch_id = 0;
		type = 0;
		static_id = 0;
		bind = 0;
		count = 0;
		world_id = 0;
		event_id = 0;
	}

	size_t getLength(bool ex) const
	{
		return 36;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << index;
		s << mark;
		s << switch_id;
		s << type;
		s << static_id;
		s << bind;
		s << count;
		s << world_id;
		s << event_id;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> index;
		s >> mark;
		s >> switch_id;
		s >> type;
		s >> static_id;
		s >> bind;
		s >> count;
		s >> world_id;
		s >> event_id;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "index", index);
		lua::settable(L, -1, "mark", mark);
		lua::settable(L, -1, "switch_id", switch_id);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "static_id", static_id);
		lua::settable(L, -1, "bind", bind);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "world_id", world_id);
		lua::settable(L, -1, "event_id", event_id);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "index=" << index;
		buffer << ",mark=" << mark;
		buffer << ",switch_id=" << switch_id;
		buffer << ",type=" << type;
		buffer << ",static_id=" << static_id;
		buffer << ",bind=" << bind;
		buffer << ",count=" << count;
		buffer << ",world_id=" << world_id;
		buffer << ",event_id=" << event_id;
	}

public:
	int index;
	int mark;
	int switch_id;
	int type;
	int static_id;
	int bind;
	int count;
	int world_id;
	int event_id;
};

struct DBHolidayPropInt
{
public:
	DBHolidayPropInt()
	{
		switch_id = 0;
		index = 0;
		cate = 0;
		prop = 0;
		value = 0;
	}

	size_t getLength(bool ex) const
	{
		return 20;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << switch_id;
		s << index;
		s << cate;
		s << prop;
		s << value;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> switch_id;
		s >> index;
		s >> cate;
		s >> prop;
		s >> value;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		lua::settable(L, -1, "index", index);
		lua::settable(L, -1, "cate", cate);
		lua::settable(L, -1, "prop", prop);
		lua::settable(L, -1, "value", value);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "switch_id=" << switch_id;
		buffer << ",index=" << index;
		buffer << ",cate=" << cate;
		buffer << ",prop=" << prop;
		buffer << ",value=" << value;
	}

public:
	int switch_id;
	int index;
	int cate;
	int prop;
	int value;
};

struct DBHolidayPropString
{
public:
	DBHolidayPropString()
	{
		switch_id = 0;
		index = 0;
		cate = 0;
		prop = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 16;
		length += sizeof(short) + value.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << switch_id;
		s << index;
		s << cate;
		s << prop;
		s << value;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> switch_id;
		s >> index;
		s >> cate;
		s >> prop;
		s >> value;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		lua::settable(L, -1, "index", index);
		lua::settable(L, -1, "cate", cate);
		lua::settable(L, -1, "prop", prop);
		lua::settable(L, -1, "value", value);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "switch_id=" << switch_id;
		buffer << ",index=" << index;
		buffer << ",cate=" << cate;
		buffer << ",prop=" << prop;
		buffer << ",value=" << value;
	}

public:
	int switch_id;
	int index;
	int cate;
	int prop;
	std::string value;
};

class MsgDBHolidayLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 1 };

	MsgDBHolidayLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayLoad";
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
		for (size_t i = 0; i < vinfo.size(); ++i)
		{
			length += vinfo[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int vinfo_vector_size = (int)vinfo.size();
		s << vinfo_vector_size;
		if (vinfo_vector_size > 0)
		{
			for (auto it = vinfo.begin(); it != vinfo.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int vinfo_vector_size = s.read_int32();
		vinfo.clear();
		while (vinfo_vector_size > 0)
		{
			vinfo_vector_size--;
			DBHolidayInfo val;
			val.unserialize(s, true);
			vinfo.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vinfo.size(); ++i)
		{
			vinfo[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "vinfo");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",vinfo=[";
		for (size_t i = 0; i < vinfo.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			vinfo[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBHolidayInfo> vinfo;
};

class MsgDBHolidayGradeLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 2 };

	MsgDBHolidayGradeLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayGradeLoad";
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
		for (size_t i = 0; i < vdata.size(); ++i)
		{
			length += vdata[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int vdata_vector_size = (int)vdata.size();
		s << vdata_vector_size;
		if (vdata_vector_size > 0)
		{
			for (auto it = vdata.begin(); it != vdata.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int vdata_vector_size = s.read_int32();
		vdata.clear();
		while (vdata_vector_size > 0)
		{
			vdata_vector_size--;
			DBHolidayGrade val;
			val.unserialize(s, true);
			vdata.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vdata.size(); ++i)
		{
			vdata[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "vdata");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",vdata=[";
		for (size_t i = 0; i < vdata.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			vdata[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBHolidayGrade> vdata;
};

class MsgDBHolidayItemLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 3 };

	MsgDBHolidayItemLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayItemLoad";
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
		for (size_t i = 0; i < vitem.size(); ++i)
		{
			length += vitem[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int vitem_vector_size = (int)vitem.size();
		s << vitem_vector_size;
		if (vitem_vector_size > 0)
		{
			for (auto it = vitem.begin(); it != vitem.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int vitem_vector_size = s.read_int32();
		vitem.clear();
		while (vitem_vector_size > 0)
		{
			vitem_vector_size--;
			DBHolidayItem val;
			val.unserialize(s, true);
			vitem.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vitem.size(); ++i)
		{
			vitem[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "vitem");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",vitem=[";
		for (size_t i = 0; i < vitem.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			vitem[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBHolidayItem> vitem;
};

class MsgDBHolidayPropIntLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 4 };

	MsgDBHolidayPropIntLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayPropIntLoad";
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
		for (size_t i = 0; i < vint.size(); ++i)
		{
			length += vint[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int vint_vector_size = (int)vint.size();
		s << vint_vector_size;
		if (vint_vector_size > 0)
		{
			for (auto it = vint.begin(); it != vint.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int vint_vector_size = s.read_int32();
		vint.clear();
		while (vint_vector_size > 0)
		{
			vint_vector_size--;
			DBHolidayPropInt val;
			val.unserialize(s, true);
			vint.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vint.size(); ++i)
		{
			vint[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "vint");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",vint=[";
		for (size_t i = 0; i < vint.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			vint[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBHolidayPropInt> vint;
};

class MsgDBHolidayPropStringLoad : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 5 };

	MsgDBHolidayPropStringLoad() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayPropStringLoad";
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
		for (size_t i = 0; i < vstring.size(); ++i)
		{
			length += vstring[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int vstring_vector_size = (int)vstring.size();
		s << vstring_vector_size;
		if (vstring_vector_size > 0)
		{
			for (auto it = vstring.begin(); it != vstring.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int vstring_vector_size = s.read_int32();
		vstring.clear();
		while (vstring_vector_size > 0)
		{
			vstring_vector_size--;
			DBHolidayPropString val;
			val.unserialize(s, true);
			vstring.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vstring.size(); ++i)
		{
			vstring[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "vstring");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",vstring=[";
		for (size_t i = 0; i < vstring.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			vstring[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBHolidayPropString> vstring;
};

class MsgDBHolidayCreate : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 11 };

	MsgDBHolidayCreate() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayCreate";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += info.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << switch_id;
		info.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		info.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		info.push(L);
		lua::settable(L, -1, "info");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
		buffer << ",info={";
		info.dump(buffer);
		buffer << "}";
	}

public:
	int switch_id;
	DBHolidayInfo info;
};

class MsgDBHolidayGradeCreate : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 12 };

	MsgDBHolidayGradeCreate() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayGradeCreate";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += data.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << switch_id;
		data.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		data.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		data.push(L);
		lua::settable(L, -1, "data");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
		buffer << ",data={";
		data.dump(buffer);
		buffer << "}";
	}

public:
	int switch_id;
	DBHolidayGrade data;
};

class MsgDBHolidayItemCreate : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 13 };

	MsgDBHolidayItemCreate() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayItemCreate";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += item.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << switch_id;
		item.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		item.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		item.push(L);
		lua::settable(L, -1, "item");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
		buffer << ",item={";
		item.dump(buffer);
		buffer << "}";
	}

public:
	int switch_id;
	DBHolidayItem item;
};

class MsgDBHolidayPropIntCreate : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 14 };

	MsgDBHolidayPropIntCreate() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayPropIntCreate";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += data.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << switch_id;
		data.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		data.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		data.push(L);
		lua::settable(L, -1, "data");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
		buffer << ",data={";
		data.dump(buffer);
		buffer << "}";
	}

public:
	int switch_id;
	DBHolidayPropInt data;
};

class MsgDBHolidayPropStringCreate : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 15 };

	MsgDBHolidayPropStringCreate() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayPropStringCreate";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength() + 4;
		length += data.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << switch_id;
		data.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		data.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
		data.push(L);
		lua::settable(L, -1, "data");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
		buffer << ",data={";
		data.dump(buffer);
		buffer << "}";
	}

public:
	int switch_id;
	DBHolidayPropString data;
};

class MsgDBHolidayRemove : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_HOLIDAY, Id = 21 };

	MsgDBHolidayRemove() :
		MessageEx(Category, Id)
	{
		switch_id = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBHolidayRemove";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return switch_id;
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
		s << switch_id;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> switch_id;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "switch_id", switch_id);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",switch_id=" << switch_id;
	}

public:
	int switch_id;
};

#endif	//_DB_MSG_HOLIDAY_H_INCLUDED
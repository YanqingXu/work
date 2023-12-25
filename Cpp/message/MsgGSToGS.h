﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_G_S_TO_G_S_H_INCLUDED
#define _MSG_G_S_TO_G_S_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

class MsgGSToGSTestRequest : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_GS_TO_GS, Id = 1 };

	MsgGSToGSTestRequest() :
		MessageEx(Category, Id)
	{
		sourceGameServerId = 0;
	}

	virtual const char *getName() const
	{
		return "MsgGSToGSTestRequest";
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
		return __super::getLength() + 4;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << sourceGameServerId;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> sourceGameServerId;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "sourceGameServerId", sourceGameServerId);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",sourceGameServerId=" << sourceGameServerId;
	}

public:
	int sourceGameServerId;
};

class MsgGSToGSTestResponse : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_GS_TO_GS, Id = 2 };

	MsgGSToGSTestResponse() :
		MessageEx(Category, Id)
	{
		sourceGameServerId = 0;
	}

	virtual const char *getName() const
	{
		return "MsgGSToGSTestResponse";
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
		return __super::getLength() + 4;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << sourceGameServerId;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> sourceGameServerId;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "sourceGameServerId", sourceGameServerId);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",sourceGameServerId=" << sourceGameServerId;
	}

public:
	int sourceGameServerId;
};

struct CrossOtherEntityProp
{
public:
	CrossOtherEntityProp()
	{
		type = 0;
		value = 0;
	}

	size_t getLength(bool ex) const
	{
		return 8;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << type;
		s << value;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> type;
		s >> value;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "value", value);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",value=" << value;
	}

public:
	int type;
	int value;
};

struct CrossOtherEntityStringProp
{
public:
	CrossOtherEntityStringProp()
	{
		type = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 4;
		length += sizeof(short) + value.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << type;
		s << value;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> type;
		s >> value;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "value", value);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",value=" << value;
	}

public:
	int type;
	std::string value;
};

struct CrossOtherEquipInfo
{
public:
	CrossOtherEquipInfo()
	{
		pos = 0;
		sid = 0;
		iid = 0;
		bind = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 16;
		length += ex ? sizeof(int) : sizeof(short);
		length += props.size() * 4;
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << pos;
		s << sid;
		s << iid;
		s << bind;
		int props_vector_size = ex ? (int)props.size() : (short)props.size();
		if (ex)
		{
			s << props_vector_size;
		}
		else
		{
			s << (short)props_vector_size;
		}
		if (props_vector_size > 0)
		{
			for (auto it = props.begin(); it != props.end(); ++it)
			{
				s << *it;
			}
		}
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> pos;
		s >> sid;
		s >> iid;
		s >> bind;
		int props_vector_size = ex ? s.read_int32() : s.read_int16();
		props.clear();
		while (props_vector_size > 0)
		{
			props_vector_size--;
			int val;
			s >> val;
			props.push_back(val);
		}
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pos", pos);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "iid", iid);
		lua::settable(L, -1, "bind", bind);
		lua::newtable(lua::L);
		for (size_t i = 0; i < props.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, props[i]);
		}
		lua::settable(L, -2, "props");
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "pos=" << pos;
		buffer << ",sid=" << sid;
		buffer << ",iid=" << iid;
		buffer << ",bind=" << bind;
		buffer << ",props=[";
		for (size_t i = 0; i < props.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << props[i];
		}
		buffer << "]";
	}

public:
	int pos;
	int sid;
	int iid;
	int bind;
	std::vector<int> props;
};

class MsgGetPlayerEquipInfoRequest : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_GS_TO_GS, Id = 3 };

	MsgGetPlayerEquipInfoRequest() :
		MessageEx(Category, Id)
	{
		srcPid = 0;
		targetPid = 0;
		srcServerid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgGetPlayerEquipInfoRequest";
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
		return __super::getLength() + 12;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << srcPid;
		s << targetPid;
		s << srcServerid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> srcPid;
		s >> targetPid;
		s >> srcServerid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "srcPid", srcPid);
		lua::settable(L, -1, "targetPid", targetPid);
		lua::settable(L, -1, "srcServerid", srcServerid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",srcPid=" << srcPid;
		buffer << ",targetPid=" << targetPid;
		buffer << ",srcServerid=" << srcServerid;
	}

public:
	int srcPid;
	int targetPid;
	int srcServerid;
};

class MsgGetPlayerEquipInfoResponse : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_GS_TO_GS, Id = 4 };

	MsgGetPlayerEquipInfoResponse() :
		MessageEx(Category, Id)
	{
		srcPid = 0;
		targetPid = 0;
		gender = 0;
		clazz = 0;
		level = 0;
		zhanli = 0;
		reborn = 0;
		cloth = 0;
		weapon = 0;
		wings = 0;
		godLevel = 0;
		enhanceExLevel = 0;
		soulExLevel = 0;
		moshiLevel = 0;
		honor = 0;
		pkvalue = 0;
		rebornsoul = 0;
		stonepoint = 0;
		xiliansuit = 0;
		heji = 0;
		exMaxLvl = 0;
		hide_moguan = 0;
		dress_cloth = 0;
		targetServerid = 0;
		srcServerid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgGetPlayerEquipInfoResponse";
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
		size_t length = __super::getLength() + 100;
		length += sizeof(short) + name.size();
		length += sizeof(short) + guild.size();
		length += sizeof(int);
		length += vcombat.size() * 4;
		length += sizeof(int);
		for (size_t i = 0; i < equips.size(); ++i)
		{
			length += equips[i].getLength(true);
		}
		length += sizeof(int);
		for (size_t i = 0; i < prop.size(); ++i)
		{
			length += prop[i].getLength(true);
		}
		length += sizeof(int);
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			length += sprop[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << srcPid;
		s << targetPid;
		s << name;
		s << gender;
		s << clazz;
		s << level;
		s << zhanli;
		s << reborn;
		s << cloth;
		s << weapon;
		s << wings;
		s << guild;
		s << godLevel;
		s << enhanceExLevel;
		s << soulExLevel;
		s << moshiLevel;
		s << honor;
		s << pkvalue;
		s << rebornsoul;
		s << stonepoint;
		s << xiliansuit;
		s << heji;
		s << exMaxLvl;
		s << hide_moguan;
		s << dress_cloth;
		s << targetServerid;
		s << srcServerid;
		int vcombat_vector_size = (int)vcombat.size();
		s << vcombat_vector_size;
		if (vcombat_vector_size > 0)
		{
			for (auto it = vcombat.begin(); it != vcombat.end(); ++it)
			{
				s << *it;
			}
		}
		int equips_vector_size = (int)equips.size();
		s << equips_vector_size;
		if (equips_vector_size > 0)
		{
			for (auto it = equips.begin(); it != equips.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int prop_vector_size = (int)prop.size();
		s << prop_vector_size;
		if (prop_vector_size > 0)
		{
			for (auto it = prop.begin(); it != prop.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int sprop_vector_size = (int)sprop.size();
		s << sprop_vector_size;
		if (sprop_vector_size > 0)
		{
			for (auto it = sprop.begin(); it != sprop.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> srcPid;
		s >> targetPid;
		s >> name;
		s >> gender;
		s >> clazz;
		s >> level;
		s >> zhanli;
		s >> reborn;
		s >> cloth;
		s >> weapon;
		s >> wings;
		s >> guild;
		s >> godLevel;
		s >> enhanceExLevel;
		s >> soulExLevel;
		s >> moshiLevel;
		s >> honor;
		s >> pkvalue;
		s >> rebornsoul;
		s >> stonepoint;
		s >> xiliansuit;
		s >> heji;
		s >> exMaxLvl;
		s >> hide_moguan;
		s >> dress_cloth;
		s >> targetServerid;
		s >> srcServerid;
		int vcombat_vector_size = s.read_int32();
		vcombat.clear();
		while (vcombat_vector_size > 0)
		{
			vcombat_vector_size--;
			int val;
			s >> val;
			vcombat.push_back(val);
		}
		int equips_vector_size = s.read_int32();
		equips.clear();
		while (equips_vector_size > 0)
		{
			equips_vector_size--;
			CrossOtherEquipInfo val;
			val.unserialize(s, true);
			equips.push_back(val);
		}
		int prop_vector_size = s.read_int32();
		prop.clear();
		while (prop_vector_size > 0)
		{
			prop_vector_size--;
			CrossOtherEntityProp val;
			val.unserialize(s, true);
			prop.push_back(val);
		}
		int sprop_vector_size = s.read_int32();
		sprop.clear();
		while (sprop_vector_size > 0)
		{
			sprop_vector_size--;
			CrossOtherEntityStringProp val;
			val.unserialize(s, true);
			sprop.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "srcPid", srcPid);
		lua::settable(L, -1, "targetPid", targetPid);
		lua::settable(L, -1, "name", name);
		lua::settable(L, -1, "gender", gender);
		lua::settable(L, -1, "clazz", clazz);
		lua::settable(L, -1, "level", level);
		lua::settable(L, -1, "zhanli", zhanli);
		lua::settable(L, -1, "reborn", reborn);
		lua::settable(L, -1, "cloth", cloth);
		lua::settable(L, -1, "weapon", weapon);
		lua::settable(L, -1, "wings", wings);
		lua::settable(L, -1, "guild", guild);
		lua::settable(L, -1, "godLevel", godLevel);
		lua::settable(L, -1, "enhanceExLevel", enhanceExLevel);
		lua::settable(L, -1, "soulExLevel", soulExLevel);
		lua::settable(L, -1, "moshiLevel", moshiLevel);
		lua::settable(L, -1, "honor", honor);
		lua::settable(L, -1, "pkvalue", pkvalue);
		lua::settable(L, -1, "rebornsoul", rebornsoul);
		lua::settable(L, -1, "stonepoint", stonepoint);
		lua::settable(L, -1, "xiliansuit", xiliansuit);
		lua::settable(L, -1, "heji", heji);
		lua::settable(L, -1, "exMaxLvl", exMaxLvl);
		lua::settable(L, -1, "hide_moguan", hide_moguan);
		lua::settable(L, -1, "dress_cloth", dress_cloth);
		lua::settable(L, -1, "targetServerid", targetServerid);
		lua::settable(L, -1, "srcServerid", srcServerid);
		lua::newtable(lua::L);
		for (size_t i = 0; i < vcombat.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, vcombat[i]);
		}
		lua::settable(L, -2, "vcombat");
		lua::newtable(lua::L);
		for (size_t i = 0; i < equips.size(); ++i)
		{
			equips[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "equips");
		lua::newtable(lua::L);
		for (size_t i = 0; i < prop.size(); ++i)
		{
			prop[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "prop");
		lua::newtable(lua::L);
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			sprop[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "sprop");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",srcPid=" << srcPid;
		buffer << ",targetPid=" << targetPid;
		buffer << ",name=" << name;
		buffer << ",gender=" << gender;
		buffer << ",clazz=" << clazz;
		buffer << ",level=" << level;
		buffer << ",zhanli=" << zhanli;
		buffer << ",reborn=" << reborn;
		buffer << ",cloth=" << cloth;
		buffer << ",weapon=" << weapon;
		buffer << ",wings=" << wings;
		buffer << ",guild=" << guild;
		buffer << ",godLevel=" << godLevel;
		buffer << ",enhanceExLevel=" << enhanceExLevel;
		buffer << ",soulExLevel=" << soulExLevel;
		buffer << ",moshiLevel=" << moshiLevel;
		buffer << ",honor=" << honor;
		buffer << ",pkvalue=" << pkvalue;
		buffer << ",rebornsoul=" << rebornsoul;
		buffer << ",stonepoint=" << stonepoint;
		buffer << ",xiliansuit=" << xiliansuit;
		buffer << ",heji=" << heji;
		buffer << ",exMaxLvl=" << exMaxLvl;
		buffer << ",hide_moguan=" << hide_moguan;
		buffer << ",dress_cloth=" << dress_cloth;
		buffer << ",targetServerid=" << targetServerid;
		buffer << ",srcServerid=" << srcServerid;
		buffer << ",vcombat=[";
		for (size_t i = 0; i < vcombat.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << vcombat[i];
		}
		buffer << "]";
		buffer << ",equips=[";
		for (size_t i = 0; i < equips.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			equips[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",prop=[";
		for (size_t i = 0; i < prop.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			prop[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",sprop=[";
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			sprop[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int srcPid;
	int targetPid;
	std::string name;
	int gender;
	int clazz;
	int level;
	int zhanli;
	int reborn;
	int cloth;
	int weapon;
	int wings;
	std::string guild;
	int godLevel;
	int enhanceExLevel;
	int soulExLevel;
	int moshiLevel;
	int honor;
	int pkvalue;
	int rebornsoul;
	int stonepoint;
	int xiliansuit;
	int heji;
	int exMaxLvl;
	int hide_moguan;
	int dress_cloth;
	int targetServerid;
	int srcServerid;
	std::vector<int> vcombat;
	std::vector<CrossOtherEquipInfo> equips;
	std::vector<CrossOtherEntityProp> prop;
	std::vector<CrossOtherEntityStringProp> sprop;
};

struct CrossOtherItemProp
{
public:
	CrossOtherItemProp()
	{
		idx = 0;
		data = 0;
	}

	size_t getLength(bool ex) const
	{
		return 8;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << idx;
		s << data;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> idx;
		s >> data;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "idx", idx);
		lua::settable(L, -1, "data", data);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "idx=" << idx;
		buffer << ",data=" << data;
	}

public:
	int idx;
	int data;
};

struct CrossOtherPlayerEquip
{
public:
	CrossOtherPlayerEquip()
	{
		sid = 0;
		iid = 0;
		pos = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 12;
		length += sizeof(short) + firstowner.size();
		length += sizeof(short) + appraiser.size();
		length += ex ? sizeof(int) : sizeof(short);
		for (size_t i = 0; i < props.size(); ++i)
		{
			length += props[i].getLength(ex);
		}
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << sid;
		s << iid;
		s << pos;
		s << firstowner;
		s << appraiser;
		int props_vector_size = ex ? (int)props.size() : (short)props.size();
		if (ex)
		{
			s << props_vector_size;
		}
		else
		{
			s << (short)props_vector_size;
		}
		if (props_vector_size > 0)
		{
			for (auto it = props.begin(); it != props.end(); ++it)
			{
				(*it).serialize(s, ex);
			}
		}
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> sid;
		s >> iid;
		s >> pos;
		s >> firstowner;
		s >> appraiser;
		int props_vector_size = ex ? s.read_int32() : s.read_int16();
		props.clear();
		while (props_vector_size > 0)
		{
			props_vector_size--;
			CrossOtherItemProp val;
			val.unserialize(s, ex);
			props.push_back(val);
		}
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "iid", iid);
		lua::settable(L, -1, "pos", pos);
		lua::settable(L, -1, "firstowner", firstowner);
		lua::settable(L, -1, "appraiser", appraiser);
		lua::newtable(lua::L);
		for (size_t i = 0; i < props.size(); ++i)
		{
			props[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "props");
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "sid=" << sid;
		buffer << ",iid=" << iid;
		buffer << ",pos=" << pos;
		buffer << ",firstowner=" << firstowner;
		buffer << ",appraiser=" << appraiser;
		buffer << ",props=[";
		for (size_t i = 0; i < props.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			props[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int sid;
	int iid;
	int pos;
	std::string firstowner;
	std::string appraiser;
	std::vector<CrossOtherItemProp> props;
};

struct CrossOtherPlayerSkill
{
public:
	CrossOtherPlayerSkill()
	{
		id = 0;
		level = 0;
	}

	size_t getLength(bool ex) const
	{
		return 8;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << id;
		s << level;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> id;
		s >> level;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "id", id);
		lua::settable(L, -1, "level", level);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "id=" << id;
		buffer << ",level=" << level;
	}

public:
	int id;
	int level;
};

class MsgNewGetPlayerEquipInfoResponse : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_GS_TO_GS, Id = 5 };

	MsgNewGetPlayerEquipInfoResponse() :
		MessageEx(Category, Id)
	{
		targetServerid = 0;
		srcServerid = 0;
		srcPid = 0;
		targetPid = 0;
		gender = 0;
		level = 0;
		exp = 0;
		zhanli = 0;
		cloth = 0;
		weapon = 0;
		wings = 0;
		lingwen = 0;
		guildpost = 0;
		job = 0;
		reborn = 0;
	}

	virtual const char *getName() const
	{
		return "MsgNewGetPlayerEquipInfoResponse";
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
		size_t length = __super::getLength() + 61;
		length += sizeof(short) + name.size();
		length += sizeof(short) + guild.size();
		length += sizeof(int);
		for (size_t i = 0; i < equips.size(); ++i)
		{
			length += equips[i].getLength(true);
		}
		length += sizeof(int);
		for (size_t i = 0; i < prop.size(); ++i)
		{
			length += prop[i].getLength(true);
		}
		length += sizeof(int);
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			length += sprop[i].getLength(true);
		}
		length += sizeof(int);
		for (size_t i = 0; i < skill.size(); ++i)
		{
			length += skill[i].getLength(true);
		}
		length += sizeof(int);
		length += vcombat.size() * 4;
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << targetServerid;
		s << srcServerid;
		s << srcPid;
		s << targetPid;
		s << gender;
		s << level;
		s << exp;
		s << zhanli;
		s << cloth;
		s << weapon;
		s << wings;
		s << name;
		s << guild;
		s << lingwen;
		s << guildpost;
		s << job;
		s << reborn;
		int equips_vector_size = (int)equips.size();
		s << equips_vector_size;
		if (equips_vector_size > 0)
		{
			for (auto it = equips.begin(); it != equips.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int prop_vector_size = (int)prop.size();
		s << prop_vector_size;
		if (prop_vector_size > 0)
		{
			for (auto it = prop.begin(); it != prop.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int sprop_vector_size = (int)sprop.size();
		s << sprop_vector_size;
		if (sprop_vector_size > 0)
		{
			for (auto it = sprop.begin(); it != sprop.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int skill_vector_size = (int)skill.size();
		s << skill_vector_size;
		if (skill_vector_size > 0)
		{
			for (auto it = skill.begin(); it != skill.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		int vcombat_vector_size = (int)vcombat.size();
		s << vcombat_vector_size;
		if (vcombat_vector_size > 0)
		{
			for (auto it = vcombat.begin(); it != vcombat.end(); ++it)
			{
				s << *it;
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> targetServerid;
		s >> srcServerid;
		s >> srcPid;
		s >> targetPid;
		s >> gender;
		s >> level;
		s >> exp;
		s >> zhanli;
		s >> cloth;
		s >> weapon;
		s >> wings;
		s >> name;
		s >> guild;
		s >> lingwen;
		s >> guildpost;
		s >> job;
		s >> reborn;
		int equips_vector_size = s.read_int32();
		equips.clear();
		while (equips_vector_size > 0)
		{
			equips_vector_size--;
			CrossOtherPlayerEquip val;
			val.unserialize(s, true);
			equips.push_back(val);
		}
		int prop_vector_size = s.read_int32();
		prop.clear();
		while (prop_vector_size > 0)
		{
			prop_vector_size--;
			CrossOtherEntityProp val;
			val.unserialize(s, true);
			prop.push_back(val);
		}
		int sprop_vector_size = s.read_int32();
		sprop.clear();
		while (sprop_vector_size > 0)
		{
			sprop_vector_size--;
			CrossOtherEntityStringProp val;
			val.unserialize(s, true);
			sprop.push_back(val);
		}
		int skill_vector_size = s.read_int32();
		skill.clear();
		while (skill_vector_size > 0)
		{
			skill_vector_size--;
			CrossOtherPlayerSkill val;
			val.unserialize(s, true);
			skill.push_back(val);
		}
		int vcombat_vector_size = s.read_int32();
		vcombat.clear();
		while (vcombat_vector_size > 0)
		{
			vcombat_vector_size--;
			int val;
			s >> val;
			vcombat.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "targetServerid", targetServerid);
		lua::settable(L, -1, "srcServerid", srcServerid);
		lua::settable(L, -1, "srcPid", srcPid);
		lua::settable(L, -1, "targetPid", targetPid);
		lua::settable(L, -1, "gender", gender);
		lua::settable(L, -1, "level", level);
		lua::settable(L, -1, "exp", exp);
		lua::settable(L, -1, "zhanli", zhanli);
		lua::settable(L, -1, "cloth", cloth);
		lua::settable(L, -1, "weapon", weapon);
		lua::settable(L, -1, "wings", wings);
		lua::settable(L, -1, "name", name);
		lua::settable(L, -1, "guild", guild);
		lua::settable(L, -1, "lingwen", lingwen);
		lua::settable(L, -1, "guildpost", guildpost);
		lua::settable(L, -1, "job", job);
		lua::settable(L, -1, "reborn", reborn);
		lua::newtable(lua::L);
		for (size_t i = 0; i < equips.size(); ++i)
		{
			equips[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "equips");
		lua::newtable(lua::L);
		for (size_t i = 0; i < prop.size(); ++i)
		{
			prop[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "prop");
		lua::newtable(lua::L);
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			sprop[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "sprop");
		lua::newtable(lua::L);
		for (size_t i = 0; i < skill.size(); ++i)
		{
			skill[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "skill");
		lua::newtable(lua::L);
		for (size_t i = 0; i < vcombat.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, vcombat[i]);
		}
		lua::settable(L, -2, "vcombat");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",targetServerid=" << targetServerid;
		buffer << ",srcServerid=" << srcServerid;
		buffer << ",srcPid=" << srcPid;
		buffer << ",targetPid=" << targetPid;
		buffer << ",gender=" << gender;
		buffer << ",level=" << level;
		buffer << ",exp=" << exp;
		buffer << ",zhanli=" << zhanli;
		buffer << ",cloth=" << cloth;
		buffer << ",weapon=" << weapon;
		buffer << ",wings=" << wings;
		buffer << ",name=" << name;
		buffer << ",guild=" << guild;
		buffer << ",lingwen=" << lingwen;
		buffer << ",guildpost=" << guildpost;
		buffer << ",job=" << job;
		buffer << ",reborn=" << reborn;
		buffer << ",equips=[";
		for (size_t i = 0; i < equips.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			equips[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",prop=[";
		for (size_t i = 0; i < prop.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			prop[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",sprop=[";
		for (size_t i = 0; i < sprop.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			sprop[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",skill=[";
		for (size_t i = 0; i < skill.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			skill[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
		buffer << ",vcombat=[";
		for (size_t i = 0; i < vcombat.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << vcombat[i];
		}
		buffer << "]";
	}

public:
	int targetServerid;
	int srcServerid;
	int srcPid;
	int targetPid;
	char gender;
	int level;
	long long exp;
	int zhanli;
	int cloth;
	int weapon;
	int wings;
	std::string name;
	std::string guild;
	int lingwen;
	int guildpost;
	int job;
	int reborn;
	std::vector<CrossOtherPlayerEquip> equips;
	std::vector<CrossOtherEntityProp> prop;
	std::vector<CrossOtherEntityStringProp> sprop;
	std::vector<CrossOtherPlayerSkill> skill;
	std::vector<int> vcombat;
};

#endif	//_MSG_G_S_TO_G_S_H_INCLUDED
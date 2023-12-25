﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _DB_MSG_CONSIGNMENT_H_INCLUDED
#define _DB_MSG_CONSIGNMENT_H_INCLUDED

#include "category.h"
#include "common/MessageEx.h"

struct DBConsignmentItemProp
{
public:
	DBConsignmentItemProp()
	{
		idx = 0;
		data = 0;
	}

	size_t getLength(bool ex) const
	{
		return 6;
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
	short idx;
	int data;
};

struct DBConsignment
{
public:
	DBConsignment()
	{
		sellerPid = 0;
		sellerServerId = 0;
		sellerWarZoneId = 0;
		cid = 0;
		sid = 0;
		count = 0;
		taxRate = 0;
		price = 0;
		ctime = 0;
		etime = 0;
		mailTip = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 44;
		length += sizeof(short) + sellerName.size();
		length += sizeof(short) + sellerServerName.size();
		length += sizeof(short) + firstOwner.size();
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
		s << sellerPid;
		s << sellerName;
		s << sellerServerId;
		s << sellerServerName;
		s << sellerWarZoneId;
		s << cid;
		s << sid;
		s << count;
		s << taxRate;
		s << price;
		s << ctime;
		s << etime;
		s << firstOwner;
		s << appraiser;
		s << mailTip;
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
		s >> sellerPid;
		s >> sellerName;
		s >> sellerServerId;
		s >> sellerServerName;
		s >> sellerWarZoneId;
		s >> cid;
		s >> sid;
		s >> count;
		s >> taxRate;
		s >> price;
		s >> ctime;
		s >> etime;
		s >> firstOwner;
		s >> appraiser;
		s >> mailTip;
		int props_vector_size = ex ? s.read_int32() : s.read_int16();
		props.clear();
		while (props_vector_size > 0)
		{
			props_vector_size--;
			DBConsignmentItemProp val;
			val.unserialize(s, ex);
			props.push_back(val);
		}
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "sellerPid", sellerPid);
		lua::settable(L, -1, "sellerName", sellerName);
		lua::settable(L, -1, "sellerServerId", sellerServerId);
		lua::settable(L, -1, "sellerServerName", sellerServerName);
		lua::settable(L, -1, "sellerWarZoneId", sellerWarZoneId);
		lua::settable(L, -1, "cid", cid);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "taxRate", taxRate);
		lua::settable(L, -1, "price", price);
		lua::settable(L, -1, "ctime", ctime);
		lua::settable(L, -1, "etime", etime);
		lua::settable(L, -1, "firstOwner", firstOwner);
		lua::settable(L, -1, "appraiser", appraiser);
		lua::settable(L, -1, "mailTip", mailTip);
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
		buffer << "sellerPid=" << sellerPid;
		buffer << ",sellerName=" << sellerName;
		buffer << ",sellerServerId=" << sellerServerId;
		buffer << ",sellerServerName=" << sellerServerName;
		buffer << ",sellerWarZoneId=" << sellerWarZoneId;
		buffer << ",cid=" << cid;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
		buffer << ",taxRate=" << taxRate;
		buffer << ",price=" << price;
		buffer << ",ctime=" << ctime;
		buffer << ",etime=" << etime;
		buffer << ",firstOwner=" << firstOwner;
		buffer << ",appraiser=" << appraiser;
		buffer << ",mailTip=" << mailTip;
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
	int sellerPid; //卖家ID 
	std::string sellerName; //卖家姓名 
	int sellerServerId; //卖家服务器id 
	std::string sellerServerName; //卖家服务器名称 
	int sellerWarZoneId; //卖家战区id 
	int cid; //寄售ID 
	int sid; //物品ID 
	int count; //物品数量 
	int taxRate; //税率 
	int price; //出售价格 
	int ctime; //寄售时间 
	int etime; //过期时间 
	std::string firstOwner; //第一个拥有者 
	std::string appraiser; //鉴定者 
	int mailTip; //邮件提示标志 
	std::vector<DBConsignmentItemProp> props;
};

class MsgDBLoadConsignments : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 1 };

	MsgDBLoadConsignments() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadConsignments";
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
		for (size_t i = 0; i < consignments.size(); ++i)
		{
			length += consignments[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int consignments_vector_size = (int)consignments.size();
		s << consignments_vector_size;
		if (consignments_vector_size > 0)
		{
			for (auto it = consignments.begin(); it != consignments.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int consignments_vector_size = s.read_int32();
		consignments.clear();
		while (consignments_vector_size > 0)
		{
			consignments_vector_size--;
			DBConsignment val;
			val.unserialize(s, true);
			consignments.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < consignments.size(); ++i)
		{
			consignments[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "consignments");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",consignments=[";
		for (size_t i = 0; i < consignments.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			consignments[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBConsignment> consignments;
};

class MsgDBAddConsignment : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 2 };

	MsgDBAddConsignment() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBAddConsignment";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return consignment.sellerPid;
	}

	virtual bool getSendBack() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength();
		length += consignment.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		consignment.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		consignment.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		consignment.push(L);
		lua::settable(L, -1, "consignment");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",consignment={";
		consignment.dump(buffer);
		buffer << "}";
	}

public:
	DBConsignment consignment;
};

class MsgDBDeleteConsignment : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 3 };

	MsgDBDeleteConsignment() :
		MessageEx(Category, Id)
	{
		pid = 0;
		cid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBDeleteConsignment";
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
		s << cid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> cid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "cid", cid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",cid=" << cid;
	}

public:
	int pid; //玩家ID 
	int cid; //寄售ID 
};

class MsgDBUpdateConsignment : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 4 };

	MsgDBUpdateConsignment() :
		MessageEx(Category, Id)
	{
		pid = 0;
		cid = 0;
		count = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBUpdateConsignment";
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
		return __super::getLength() + 12;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << cid;
		s << count;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> cid;
		s >> count;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "cid", cid);
		lua::settable(L, -1, "count", count);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",cid=" << cid;
		buffer << ",count=" << count;
	}

public:
	int pid; //玩家ID 
	int cid; //寄售ID 
	int count; //寄售数量 
};

struct DBAcution
{
public:
	DBAcution()
	{
		aid = 0;
		sid = 0;
		count = 0;
		fixed_price = 0;
		start_price = 0;
		things_type = 0;
		status = 0;
		buyer_pid = 0;
		cur_price = 0;
		atime = 0;
		etime = 0;
		crt_type = 0;
		next_auction = 0;
		guild_id = 0;
		server_id = 0;
		war_zone_id = 0;
		buyer_server_id = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 72;
		length += sizeof(short) + buyer_name.size();
		length += ex ? sizeof(int) : sizeof(short);
		length += parters.size() * 4;
		length += ex ? sizeof(int) : sizeof(short);
		length += buyers.size() * 4;
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << aid;
		s << sid;
		s << count;
		s << fixed_price;
		s << start_price;
		s << things_type;
		s << status;
		s << buyer_pid;
		s << buyer_name;
		s << cur_price;
		s << atime;
		s << etime;
		int parters_vector_size = ex ? (int)parters.size() : (short)parters.size();
		if (ex)
		{
			s << parters_vector_size;
		}
		else
		{
			s << (short)parters_vector_size;
		}
		if (parters_vector_size > 0)
		{
			for (auto it = parters.begin(); it != parters.end(); ++it)
			{
				s << *it;
			}
		}
		int buyers_vector_size = ex ? (int)buyers.size() : (short)buyers.size();
		if (ex)
		{
			s << buyers_vector_size;
		}
		else
		{
			s << (short)buyers_vector_size;
		}
		if (buyers_vector_size > 0)
		{
			for (auto it = buyers.begin(); it != buyers.end(); ++it)
			{
				s << *it;
			}
		}
		s << crt_type;
		s << next_auction;
		s << guild_id;
		s << server_id;
		s << war_zone_id;
		s << buyer_server_id;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> aid;
		s >> sid;
		s >> count;
		s >> fixed_price;
		s >> start_price;
		s >> things_type;
		s >> status;
		s >> buyer_pid;
		s >> buyer_name;
		s >> cur_price;
		s >> atime;
		s >> etime;
		int parters_vector_size = ex ? s.read_int32() : s.read_int16();
		parters.clear();
		while (parters_vector_size > 0)
		{
			parters_vector_size--;
			int val;
			s >> val;
			parters.push_back(val);
		}
		int buyers_vector_size = ex ? s.read_int32() : s.read_int16();
		buyers.clear();
		while (buyers_vector_size > 0)
		{
			buyers_vector_size--;
			int val;
			s >> val;
			buyers.push_back(val);
		}
		s >> crt_type;
		s >> next_auction;
		s >> guild_id;
		s >> server_id;
		s >> war_zone_id;
		s >> buyer_server_id;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "aid", aid);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "fixed_price", fixed_price);
		lua::settable(L, -1, "start_price", start_price);
		lua::settable(L, -1, "things_type", things_type);
		lua::settable(L, -1, "status", status);
		lua::settable(L, -1, "buyer_pid", buyer_pid);
		lua::settable(L, -1, "buyer_name", buyer_name);
		lua::settable(L, -1, "cur_price", cur_price);
		lua::settable(L, -1, "atime", atime);
		lua::settable(L, -1, "etime", etime);
		lua::newtable(lua::L);
		for (size_t i = 0; i < parters.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, parters[i]);
		}
		lua::settable(L, -2, "parters");
		lua::newtable(lua::L);
		for (size_t i = 0; i < buyers.size(); ++i)
		{
			lua::settable(L, -1, (int)i+1, buyers[i]);
		}
		lua::settable(L, -2, "buyers");
		lua::settable(L, -1, "crt_type", crt_type);
		lua::settable(L, -1, "next_auction", next_auction);
		lua::settable(L, -1, "guild_id", guild_id);
		lua::settable(L, -1, "server_id", server_id);
		lua::settable(L, -1, "war_zone_id", war_zone_id);
		lua::settable(L, -1, "buyer_server_id", buyer_server_id);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "aid=" << aid;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
		buffer << ",fixed_price=" << fixed_price;
		buffer << ",start_price=" << start_price;
		buffer << ",things_type=" << things_type;
		buffer << ",status=" << status;
		buffer << ",buyer_pid=" << buyer_pid;
		buffer << ",buyer_name=" << buyer_name;
		buffer << ",cur_price=" << cur_price;
		buffer << ",atime=" << atime;
		buffer << ",etime=" << etime;
		buffer << ",parters=[";
		for (size_t i = 0; i < parters.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << parters[i];
		}
		buffer << "]";
		buffer << ",buyers=[";
		for (size_t i = 0; i < buyers.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << buyers[i];
		}
		buffer << "]";
		buffer << ",crt_type=" << crt_type;
		buffer << ",next_auction=" << next_auction;
		buffer << ",guild_id=" << guild_id;
		buffer << ",server_id=" << server_id;
		buffer << ",war_zone_id=" << war_zone_id;
		buffer << ",buyer_server_id=" << buyer_server_id;
	}

public:
	long long aid; //拍卖ID 
	int sid; //物品ID 
	int count; //物品数量 
	int fixed_price; //一口价 
	int start_price; //起拍价 
	int things_type; //货币类型 
	int status; //拍卖状态 
	int buyer_pid; //竞价人pid 
	std::string buyer_name; //竞价人名字 
	int cur_price; //当前竞拍价格 
	int atime; //成交时间 
	int etime; //过期时间 
	std::vector<int> parters; //拍卖受益人 
	std::vector<int> buyers; //拍卖竞价者 
	int crt_type; //当前竞拍归属组 
	int next_auction; //是否进入下一拍卖行 
	int guild_id; //公会id 
	int server_id; //区服id 
	int war_zone_id; //战区id 
	int buyer_server_id; //竞价人区服id 
};

class MsgDBDelOneAcution : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 7 };

	MsgDBDelOneAcution() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBDelOneAcution";
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
		size_t length = __super::getLength();
		length += acution.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		acution.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		acution.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		acution.push(L);
		lua::settable(L, -1, "acution");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",acution={";
		acution.dump(buffer);
		buffer << "}";
	}

public:
	DBAcution acution;
};

class MsgDBUpdateOneAcution : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 8 };

	MsgDBUpdateOneAcution() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBUpdateOneAcution";
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
		size_t length = __super::getLength();
		length += acution.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		acution.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		acution.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		acution.push(L);
		lua::settable(L, -1, "acution");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",acution={";
		acution.dump(buffer);
		buffer << "}";
	}

public:
	DBAcution acution;
};

class MsgDBAddOneAcution : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 9 };

	MsgDBAddOneAcution() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBAddOneAcution";
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
		size_t length = __super::getLength();
		length += acution.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		acution.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		acution.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		acution.push(L);
		lua::settable(L, -1, "acution");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",acution={";
		acution.dump(buffer);
		buffer << "}";
	}

public:
	DBAcution acution;
};

class MsgDBLoadAllAcution : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 10 };

	MsgDBLoadAllAcution() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadAllAcution";
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
		for (size_t i = 0; i < acutions.size(); ++i)
		{
			length += acutions[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int acutions_vector_size = (int)acutions.size();
		s << acutions_vector_size;
		if (acutions_vector_size > 0)
		{
			for (auto it = acutions.begin(); it != acutions.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int acutions_vector_size = s.read_int32();
		acutions.clear();
		while (acutions_vector_size > 0)
		{
			acutions_vector_size--;
			DBAcution val;
			val.unserialize(s, true);
			acutions.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < acutions.size(); ++i)
		{
			acutions[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "acutions");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",acutions=[";
		for (size_t i = 0; i < acutions.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			acutions[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBAcution> acutions;
};

struct DBPurchase
{
public:
	DBPurchase()
	{
		buyerPid = 0;
		buyerServerId = 0;
		buyerWarZoneId = 0;
		purchaseId = 0;
		sid = 0;
		count = 0;
		taxRate = 0;
		price = 0;
		ctime = 0;
		etime = 0;
	}

	size_t getLength(bool ex) const
	{
		size_t length = 40;
		length += sizeof(short) + buyerName.size();
		length += sizeof(short) + buyerServerName.size();
		return length;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << buyerPid;
		s << buyerName;
		s << buyerServerId;
		s << buyerServerName;
		s << buyerWarZoneId;
		s << purchaseId;
		s << sid;
		s << count;
		s << taxRate;
		s << price;
		s << ctime;
		s << etime;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> buyerPid;
		s >> buyerName;
		s >> buyerServerId;
		s >> buyerServerName;
		s >> buyerWarZoneId;
		s >> purchaseId;
		s >> sid;
		s >> count;
		s >> taxRate;
		s >> price;
		s >> ctime;
		s >> etime;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "buyerPid", buyerPid);
		lua::settable(L, -1, "buyerName", buyerName);
		lua::settable(L, -1, "buyerServerId", buyerServerId);
		lua::settable(L, -1, "buyerServerName", buyerServerName);
		lua::settable(L, -1, "buyerWarZoneId", buyerWarZoneId);
		lua::settable(L, -1, "purchaseId", purchaseId);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "taxRate", taxRate);
		lua::settable(L, -1, "price", price);
		lua::settable(L, -1, "ctime", ctime);
		lua::settable(L, -1, "etime", etime);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "buyerPid=" << buyerPid;
		buffer << ",buyerName=" << buyerName;
		buffer << ",buyerServerId=" << buyerServerId;
		buffer << ",buyerServerName=" << buyerServerName;
		buffer << ",buyerWarZoneId=" << buyerWarZoneId;
		buffer << ",purchaseId=" << purchaseId;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
		buffer << ",taxRate=" << taxRate;
		buffer << ",price=" << price;
		buffer << ",ctime=" << ctime;
		buffer << ",etime=" << etime;
	}

public:
	int buyerPid; //求购者pid 
	std::string buyerName; //求购者姓名 
	int buyerServerId; //求购者服务器id 
	std::string buyerServerName; //求购者服务器名称 
	int buyerWarZoneId; //求购者战区id 
	int purchaseId; //求购id 
	int sid; //求购物品ID 
	int count; //求购物品数量 
	int taxRate; //税率 
	int price; //求购价格 
	int ctime; //求购时间 
	int etime; //求购过期时间 
};

class MsgDBLoadPurchases : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 11 };

	MsgDBLoadPurchases() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBLoadPurchases";
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
		for (size_t i = 0; i < purchases.size(); ++i)
		{
			length += purchases[i].getLength(true);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		int purchases_vector_size = (int)purchases.size();
		s << purchases_vector_size;
		if (purchases_vector_size > 0)
		{
			for (auto it = purchases.begin(); it != purchases.end(); ++it)
			{
				(*it).serialize(s, true);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		int purchases_vector_size = s.read_int32();
		purchases.clear();
		while (purchases_vector_size > 0)
		{
			purchases_vector_size--;
			DBPurchase val;
			val.unserialize(s, true);
			purchases.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < purchases.size(); ++i)
		{
			purchases[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "purchases");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",purchases=[";
		for (size_t i = 0; i < purchases.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			purchases[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<DBPurchase> purchases;
};

class MsgDBAddPurchase : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 12 };

	MsgDBAddPurchase() :
		MessageEx(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgDBAddPurchase";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual int getSalt() const
	{
		return purchase.buyerPid;
	}

	virtual bool getSendBack() const
	{
		return true;
	}

	virtual size_t getLength() const
	{
		size_t length = __super::getLength();
		length += purchase.getLength(true);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		purchase.serialize(s, true);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		purchase.unserialize(s, true);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		purchase.push(L);
		lua::settable(L, -1, "purchase");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",purchase={";
		purchase.dump(buffer);
		buffer << "}";
	}

public:
	DBPurchase purchase;
};

class MsgDBDeletePurchase : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 13 };

	MsgDBDeletePurchase() :
		MessageEx(Category, Id)
	{
		pid = 0;
		purchaseId = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBDeletePurchase";
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
		s << purchaseId;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> purchaseId;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "purchaseId", purchaseId);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",purchaseId=" << purchaseId;
	}

public:
	int pid; //玩家ID 
	int purchaseId; //求购ID 
};

class MsgDBUpdatePurchase : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 14 };

	MsgDBUpdatePurchase() :
		MessageEx(Category, Id)
	{
		pid = 0;
		purchaseId = 0;
		count = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBUpdatePurchase";
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
		return __super::getLength() + 12;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << purchaseId;
		s << count;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> purchaseId;
		s >> count;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "purchaseId", purchaseId);
		lua::settable(L, -1, "count", count);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",purchaseId=" << purchaseId;
		buffer << ",count=" << count;
	}

public:
	int pid; //玩家ID 
	int purchaseId; //求购ID 
	int count; //求购数量 
};

class MsgDBUpdateConsignmentMailTip : public MessageEx
{
public:
	enum { Category = MSG_CATEGORY_DB_CONSIGNMENT, Id = 15 };

	MsgDBUpdateConsignmentMailTip() :
		MessageEx(Category, Id)
	{
		pid = 0;
		cid = 0;
		mailTip = 0;
	}

	virtual const char *getName() const
	{
		return "MsgDBUpdateConsignmentMailTip";
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
		return __super::getLength() + 12;
	}

	virtual bool serialize(ByteStream &s) const
	{
		__super::serialize(s);
		s << pid;
		s << cid;
		s << mailTip;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		__super::unserialize(s);
		s >> pid;
		s >> cid;
		s >> mailTip;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "pid", pid);
		lua::settable(L, -1, "cid", cid);
		lua::settable(L, -1, "mailTip", mailTip);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		__super::dump(buffer);
		buffer << ",pid=" << pid;
		buffer << ",cid=" << cid;
		buffer << ",mailTip=" << mailTip;
	}

public:
	int pid; //玩家ID 
	int cid; //寄售ID 
	int mailTip; //邮件提醒 
};

#endif	//_DB_MSG_CONSIGNMENT_H_INCLUDED
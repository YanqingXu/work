﻿//
//Generated by lua
//2009-2012	(C) XianFeng Inc. Reserved
//

#ifndef _MSG_SHOP_H_INCLUDED
#define _MSG_SHOP_H_INCLUDED

#include "category.h"
#include "common/Message.h"

struct ShopItem
{
public:
	ShopItem()
	{
		sid = 0;
		count = 0;
		price_type = 0;
		price = 0;
		server_days = 0;
		is_bind = 0;
		eventId = 0;
		itemidx = 0;
		oriprice = 0;
		end_days = 0;
		vip = 0;
		limit_level = 0;
	}

	size_t getLength(bool ex) const
	{
		return 43;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << sid;
		s << count;
		s << price_type;
		s << price;
		s << server_days;
		s << is_bind;
		s << eventId;
		s << itemidx;
		s << oriprice;
		s << end_days;
		s << vip;
		s << limit_level;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> sid;
		s >> count;
		s >> price_type;
		s >> price;
		s >> server_days;
		s >> is_bind;
		s >> eventId;
		s >> itemidx;
		s >> oriprice;
		s >> end_days;
		s >> vip;
		s >> limit_level;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "price_type", price_type);
		lua::settable(L, -1, "price", price);
		lua::settable(L, -1, "server_days", server_days);
		lua::settable(L, -1, "is_bind", is_bind);
		lua::settable(L, -1, "eventId", eventId);
		lua::settable(L, -1, "itemidx", itemidx);
		lua::settable(L, -1, "oriprice", oriprice);
		lua::settable(L, -1, "end_days", end_days);
		lua::settable(L, -1, "vip", vip);
		lua::settable(L, -1, "limit_level", limit_level);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "sid=" << sid;
		buffer << ",count=" << count;
		buffer << ",price_type=" << price_type;
		buffer << ",price=" << price;
		buffer << ",server_days=" << server_days;
		buffer << ",is_bind=" << is_bind;
		buffer << ",eventId=" << eventId;
		buffer << ",itemidx=" << itemidx;
		buffer << ",oriprice=" << oriprice;
		buffer << ",end_days=" << end_days;
		buffer << ",vip=" << vip;
		buffer << ",limit_level=" << limit_level;
	}

public:
	int sid; //物品配置ID 
	int count; //物品数量 
	int price_type; //出售价格类型 
	int price; //出售价格 
	int server_days; //第几天开启 
	char is_bind; //是否绑定 
	short eventId; //限购对应的eventid 
	int itemidx; //物品在商城中的id 
	int oriprice; //初始价格 
	int end_days; //第几天关闭 
	int vip; //限制购买的贵族等级 
	int limit_level; //限制购买的玩家等级 
};

class MsgOpenShopRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 1 };

	MsgOpenShopRequest() :
		Message(Category, Id)
	{
		shop_id = 0;
		version = 0;
	}

	virtual const char *getName() const
	{
		return "MsgOpenShopRequest";
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
		s << shop_id;
		s << version;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> shop_id;
		s >> version;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "shop_id", shop_id);
		lua::settable(L, -1, "version", version);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "shop_id=" << shop_id;
		buffer << ",version=" << version;
	}

public:
	int shop_id; //商店ID 
	int version; //版本号 
};

class MsgOpenShopResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 2 };

	MsgOpenShopResponse() :
		Message(Category, Id)
	{
		shop_id = 0;
		version = 0;
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgOpenShopResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 10;
		length += sizeof(short);
		for (size_t i = 0; i < items.size(); ++i)
		{
			length += items[i].getLength(false);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << shop_id;
		s << version;
		s << errcode;
		short items_vector_size = (short)items.size();
		s << items_vector_size;
		if (items_vector_size > 0)
		{
			for (auto it = items.begin(); it != items.end(); ++it)
			{
				(*it).serialize(s, false);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> shop_id;
		s >> version;
		s >> errcode;
		int items_vector_size = s.read_int16();
		items.clear();
		while (items_vector_size > 0)
		{
			items_vector_size--;
			ShopItem val;
			val.unserialize(s, false);
			items.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "shop_id", shop_id);
		lua::settable(L, -1, "version", version);
		lua::settable(L, -1, "errcode", errcode);
		lua::newtable(lua::L);
		for (size_t i = 0; i < items.size(); ++i)
		{
			items[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "items");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "shop_id=" << shop_id;
		buffer << ",version=" << version;
		buffer << ",errcode=" << errcode;
		buffer << ",items=[";
		for (size_t i = 0; i < items.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			items[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	int shop_id;
	int version; //版本号 
	short errcode;
	std::vector<ShopItem> items;
};

struct ShopBuyBackData
{
public:
	ShopBuyBackData()
	{
		itemsid = 0;
		itemiid = 0;
		count = 0;
		price = 0;
		isbind = 0;
	}

	size_t getLength(bool ex) const
	{
		return 18;
	}

	bool serialize(ByteStream &s, bool ex) const
	{
		s << itemsid;
		s << itemiid;
		s << count;
		s << price;
		s << isbind;
		return true;
	}

	bool unserialize(ByteStream &s, bool ex)
	{
		s >> itemsid;
		s >> itemiid;
		s >> count;
		s >> price;
		s >> isbind;
		return true;
	}

	void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "itemsid", itemsid);
		lua::settable(L, -1, "itemiid", itemiid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "price", price);
		lua::settable(L, -1, "isbind", isbind);
	}

	void dump(DumpBuffer &buffer)
	{
		buffer << "itemsid=" << itemsid;
		buffer << ",itemiid=" << itemiid;
		buffer << ",count=" << count;
		buffer << ",price=" << price;
		buffer << ",isbind=" << isbind;
	}

public:
	int itemsid;
	int itemiid;
	int count;
	int price;
	short isbind;
};

class MsgShopBackBuyNotify : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 4 };

	MsgShopBackBuyNotify() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgShopBackBuyNotify";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 0;
		length += sizeof(short);
		for (size_t i = 0; i < items.size(); ++i)
		{
			length += items[i].getLength(false);
		}
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		short items_vector_size = (short)items.size();
		s << items_vector_size;
		if (items_vector_size > 0)
		{
			for (auto it = items.begin(); it != items.end(); ++it)
			{
				(*it).serialize(s, false);
			}
		}
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		int items_vector_size = s.read_int16();
		items.clear();
		while (items_vector_size > 0)
		{
			items_vector_size--;
			ShopBuyBackData val;
			val.unserialize(s, false);
			items.push_back(val);
		}
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::newtable(lua::L);
		for (size_t i = 0; i < items.size(); ++i)
		{
			items[i].push(L);
			lua::push(L, (int)i+1);
			lua::settable(L, -1);
		}
		lua::settable(L, -2, "items");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "items=[";
		for (size_t i = 0; i < items.size(); ++i)
		{
			buffer << ((i == 0) ? "" : ",") << "{";
			items[i].dump(buffer);
			buffer << "}";
		}
		buffer << "]";
	}

public:
	std::vector<ShopBuyBackData> items;
};

class MsgShopBackBuyRmvNotify : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 5 };

	MsgShopBackBuyRmvNotify() :
		Message(Category, Id)
	{
		itemiid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgShopBackBuyRmvNotify";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 4;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << itemiid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> itemiid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "itemiid", itemiid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "itemiid=" << itemiid;
	}

public:
	int itemiid;
};

class MsgShopBackBuyAddNotify : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 6 };

	MsgShopBackBuyAddNotify() :
		Message(Category, Id)
	{
	}

	virtual const char *getName() const
	{
		return "MsgShopBackBuyAddNotify";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		size_t length = 0;
		length += item.getLength(false);
		return length;
	}

	virtual bool serialize(ByteStream &s) const
	{
		item.serialize(s, false);
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		item.unserialize(s, false);
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		item.push(L);
		lua::settable(L, -1, "item");
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "item={";
		item.dump(buffer);
		buffer << "}";
	}

public:
	ShopBuyBackData item;
};

class MsgBuyItemInShopRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 20 };

	MsgBuyItemInShopRequest() :
		Message(Category, Id)
	{
		type = 0;
		id = 0;
		sid = 0;
		count = 0;
	}

	virtual const char *getName() const
	{
		return "MsgBuyItemInShopRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 16;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		s << id;
		s << sid;
		s << count;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		s >> id;
		s >> sid;
		s >> count;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "id", id);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",id=" << id;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
	}

public:
	int type;
	int id;
	int sid;
	int count;
};

class MsgBuyItemInShopResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 21 };

	MsgBuyItemInShopResponse() :
		Message(Category, Id)
	{
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgBuyItemInShopResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 2;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << errcode;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> errcode;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "errcode", errcode);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "errcode=" << errcode;
	}

public:
	short errcode;
};

class MsgShopBackBuyItemRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 22 };

	MsgShopBackBuyItemRequest() :
		Message(Category, Id)
	{
		itemiid = 0;
	}

	virtual const char *getName() const
	{
		return "MsgShopBackBuyItemRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 4;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << itemiid;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> itemiid;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "itemiid", itemiid);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "itemiid=" << itemiid;
	}

public:
	int itemiid;
};

class MsgShopBackBuyItemResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 23 };

	MsgShopBackBuyItemResponse() :
		Message(Category, Id)
	{
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgShopBackBuyItemResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 2;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << errcode;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> errcode;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "errcode", errcode);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "errcode=" << errcode;
	}

public:
	short errcode;
};

class MsgBuyAndUseItemRequest : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 24 };

	MsgBuyAndUseItemRequest() :
		Message(Category, Id)
	{
		type = 0;
		id = 0;
		sid = 0;
		count = 0;
	}

	virtual const char *getName() const
	{
		return "MsgBuyAndUseItemRequest";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 16;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << type;
		s << id;
		s << sid;
		s << count;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> type;
		s >> id;
		s >> sid;
		s >> count;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "type", type);
		lua::settable(L, -1, "id", id);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "type=" << type;
		buffer << ",id=" << id;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
	}

public:
	int type;
	int id;
	int sid;
	int count;
};

class MsgBuyAndUseItemResponse : public Message
{
public:
	enum { Category = MSG_CATEGORY_SHOP, Id = 25 };

	MsgBuyAndUseItemResponse() :
		Message(Category, Id)
	{
		shop_id = 0;
		index = 0;
		sid = 0;
		count = 0;
		errcode = 0;
	}

	virtual const char *getName() const
	{
		return "MsgBuyAndUseItemResponse";
	}

	virtual bool canSendToCrossFromClient() const
	{
		return false;
	}

	virtual size_t getLength() const
	{
		return 18;
	}

	virtual bool serialize(ByteStream &s) const
	{
		s << shop_id;
		s << index;
		s << sid;
		s << count;
		s << errcode;
		return true;
	}

	virtual bool unserialize(ByteStream &s)
	{
		s >> shop_id;
		s >> index;
		s >> sid;
		s >> count;
		s >> errcode;
		return true;
	}

	virtual void push(lua_State *L) const
	{
		lua::newtable(lua::L);
		lua::settable(L, -1, "shop_id", shop_id);
		lua::settable(L, -1, "index", index);
		lua::settable(L, -1, "sid", sid);
		lua::settable(L, -1, "count", count);
		lua::settable(L, -1, "errcode", errcode);
	}

	virtual void dump(DumpBuffer &buffer)
	{
		buffer << "shop_id=" << shop_id;
		buffer << ",index=" << index;
		buffer << ",sid=" << sid;
		buffer << ",count=" << count;
		buffer << ",errcode=" << errcode;
	}

public:
	int shop_id;
	int index;
	int sid;
	int count;
	short errcode;
};

#endif	//_MSG_SHOP_H_INCLUDED

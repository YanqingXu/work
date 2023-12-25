#include "stdafx.h"
#include "GuildItemManager.h"
#include "GuildLua.h"
#include "GuildHelper.h"
#include "Item/ItemOperationHelper.h"
#include "message/DBMsgItem.h"

int GuildItemManager::TIME_INTERVAL = 0;

GuildItemManager::GuildItemManager(Guild *guild) :
	m_next_item_id(1),
	m_guild(guild),
	m_start_time(false),
	m_time_to_update(0)
{
	memset(m_positions, 0, sizeof(m_positions));

	for (int i = GUILD_BAG_POS_FIRST; i <= GUILD_BAG_POS_LAST; ++i)
	{
		m_free_pos_set.insert(i);
	}

	lua::getglobal(lua::L, "Guild.timeinterval", TIME_INTERVAL);
	m_time_to_update = TIME_INTERVAL;
}

GuildItemManager::~GuildItemManager()
{
	for (int i = GUILD_BAG_POS_FIRST; i <= GUILD_BAG_POS_LAST; ++i)
	{
		if (m_positions[i] == nullptr)
		{
			continue;
		}
		delete m_positions[i];
	}
	memset(m_positions, 0, sizeof(m_positions));

	m_item_map.clear();
}

//初始化
void GuildItemManager::initAddItem(const DBItem &dbitem)
{
	if (dbitem.pid != m_guild->getGuildID())
	{
		return;
	}

	if (m_free_pos_set.size() == 0)
	{
		LOG_ERROR("too many guild items, gid=%d", m_guild->getGuildID());
		return;
	}

	int pos = 0;
	auto it = m_free_pos_set.find(dbitem.position);
	if ( it != m_free_pos_set.end())
	{
		pos = dbitem.position;
	}
	else
	{
		it = m_free_pos_set.begin();
		pos = *it;
	}
	m_free_pos_set.erase(it);

	Item *item = new Item;

	if (dbitem.iid >= m_next_item_id)
	{
		//更新物品ID生成器
		m_next_item_id = dbitem.iid + 1;
	}

	item->setID(dbitem.iid);
	item->setStaticID(dbitem.sid);

	if (!item->load() || item->getCategory() == ITEM_CATEGORY_INVALID)
	{
		delete item;
		m_free_pos_set.insert(pos);
		return;
	}

	item->setCount(dbitem.count);
	item->setBindType(dbitem.bind);
	item->setPosition(pos);

	m_positions[pos] = item;
	m_item_map[item->getID()] = item;
	if (pos != dbitem.position)
	{
		ItemOperationHelper::saveGuildItemPosition(*m_guild, item);
	}

	if (canStartClean() && !m_start_time) 
	{
		m_start_time = true;
		lua::call(lua::L, "Guild.syncCleanNotice", m_guild);
		// 获取清理间隔
		if(lua::call(lua::L, "Guild.onGetCleanGuildBagTime", m_guild))
		{
			int timer = lua::getinteger(1);
			if (timer != TIME_INTERVAL)
			{
				TIME_INTERVAL = timer;
				m_time_to_update = TIME_INTERVAL;
			}
		}
	}
}

void GuildItemManager::initSetItemProps(const DBItemProp &dbprop)
{
	if (dbprop.pid != m_guild->getGuildID())
	{
		return;
	}

	Item *item = getItemByID(dbprop.iid);
	if (item == nullptr)
	{
		LOG_WARN("invalid item prop3, pid=%d, iid=%d, propId=%d", -m_guild->getGuildID(), dbprop.iid, dbprop.idx);
		return;
	}

	item->setProp(dbprop.idx, dbprop.data);
}

//同步公会数据
const std::map<int, Item*>& GuildItemManager::getItems()
{
	return m_item_map;
}

//存放物品
Item *GuildItemManager::depositItem(Item *item)
{
	if (item == nullptr)
	{
		return nullptr;
	}

	if (item->getCategory() == ITEM_CATEGORY_INVALID)
	{
		LOG_ERROR("invalid item, static_id=%d", item->getStaticID());
		return nullptr;
	}

	int pos = allocPosition();
	if (pos < 0)
	{
		return nullptr;
	}

	int item_id = m_next_item_id++;

	item->setID(item_id);
	item->setPosition(pos);

	m_positions[pos] = item;
	m_item_map[item_id] = item;

	if (canStartClean() && !m_start_time) 
	{
		m_start_time = true;
		lua::call(lua::L, "Guild.syncCleanNotice", m_guild);
		// 获取清理间隔
		if(lua::call(lua::L, "Guild.onGetCleanGuildBagTime", m_guild))
		{
			int timer = lua::getinteger(1);
			if (timer != TIME_INTERVAL)
			{
				TIME_INTERVAL = timer;
				m_time_to_update = TIME_INTERVAL;
			}
		}
	}

	return item;
}

Item *GuildItemManager::withdrawItem(int item_id)
{
	auto it = m_item_map.find(item_id);
	if (it == m_item_map.end())
	{
		return nullptr;
	}

	Item *item = it->second;
	if (item == nullptr)
	{
		m_item_map.erase(it);
		//freePosition(item->getPosition());
		return 0;
	}

	m_item_map.erase(it);
	m_positions[item->getPosition()] = nullptr;
	freePosition(item->getPosition());

	if (!canStartClean())
	{
		m_start_time = false;

		m_time_to_update = TIME_INTERVAL;
	}

	return item;
}
void GuildItemManager::delItem(int item_id)
{
	auto it = m_item_map.find(item_id);
	if (it == m_item_map.end())
	{
		return;
	}

	Item *item = it->second;
	if (item == nullptr)
	{
		m_item_map.erase(it);
		//freePosition(item->getPosition());
		return;
	}

	m_item_map.erase(it);
	m_positions[item->getPosition()] = nullptr;
	freePosition(item->getPosition());

	if (!canStartClean())
	{
		m_start_time = false;
		m_time_to_update = TIME_INTERVAL;
	}

	delete item;
	item = nullptr;
}

bool GuildItemManager::isFull()
{
	return m_free_pos_set.size() == 0;
}


int GuildItemManager::allocPosition()
{
	if (m_free_pos_set.size() == 0)
	{
		return -1;
	}

	auto it = m_free_pos_set.begin();
	int pos = *it;
	m_free_pos_set.erase(it);

	return pos;
}

void GuildItemManager::freePosition(int pos)
{
	m_free_pos_set.insert(pos);
}


Item *GuildItemManager::getItemByID(int item_id)
{
	auto it = m_item_map.find(item_id);
	if (it == m_item_map.end())
	{
		return nullptr;
	}

	return it->second;
}

Item * GuildItemManager::getItemByPos(int pos) const
{
	if (pos < GUILD_BAG_POS_FIRST || pos > GUILD_BAG_POS_LAST) 
		return NULL;

	return m_positions[pos];
}

bool GuildItemManager::canStartClean() const
{
	return static_cast<int>(m_free_pos_set.size()) <= REMAIN_COUNT;
}

void GuildItemManager::onMinTimer(size_t elapse)
{
	if (!m_start_time) return;

	m_time_to_update -= static_cast<int>(elapse);
	if (m_time_to_update <= 0)
	{
		m_time_to_update += TIME_INTERVAL;

		lua::call(lua::L, "Guild.onCleanGuildBag", m_guild);
		GuildHelper::addRecord(m_guild, GUILD_RECORD_BAG_CLEAN, 0, 0, "", "");
	}
}

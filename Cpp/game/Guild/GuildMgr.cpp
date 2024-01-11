#include "stdafx.h"
#include "GuildMgr.h"
#include "GuildHelper.h"
#include "Entity/EntityOperationHelper.h"
#include "Entity/WorldPlayerManager.h"
#include "Application.h"
#include "World/World.h"
#include "Cross/GSHelper.h"

GuildMgr g_guild_mgr;

GuildMgr::GuildMgr() :
	m_version(0)
{
}

GuildMgr::~GuildMgr()
{
	clear();
}

void GuildMgr::clear()
{
	m_GuildRanks.clear();

	for (size_t i = 0; i < m_guilds.size(); ++i)
	{
		delete m_guilds[i];
	}
	m_guilds.clear();

	m_id2guild_map.clear();
	m_name2guild_map.clear();

	m_player_app_map.clear();

	m_sell_map.clear();
	m_ItemList.clear();
	++m_version;
}

void GuildMgr::initGuilds(MsgDBGuildLoad *msg)
{
	for (auto it = msg->Guilds.begin(); it != msg->Guilds.end(); ++it)
	{
		if (it->guildid == 0)
		{
			LOG_ERROR("guild_id 0 invalid");
			continue;
		}

		if (it->playercnt <= 0)
		{
			MsgDBGuildDelete *dbmsg = new MsgDBGuildDelete;
			dbmsg->guildid = it->guildid;
			g_app.postToNetService(dbmsg);
			continue;
		}

		Guild *guild = new Guild;
		guild->setGuildID(it->guildid);
		guild->setGuildName(it->guildname);
		guild->setProp(GUILD_PROP_MASTER_ID, it->masterpid);
		guild->setStringProp(GUILD_PROP_MASTER_NAME, it->mastername);
		guild->setStringProp(GUILD_PROP_PRIVATE_NOTICE, it->guildplacard);
		guild->setStringProp(GUILD_PROP_PUBLIC_NOTICE, it->publicnotice);
		guild->setCreateTime(it->createtime);
		guild->setProp(GUILD_PROP_LEVEL, 1);	//默认1级
		guild->setProp(GUILD_PROP_HAS_GOT_GIFT, it->isgot);

		addGuild(guild);
	}
}

Guild *GuildMgr::getGuildByID(int guild_id)
{
	auto it = m_id2guild_map.find(guild_id);
	return ((it != m_id2guild_map.end()) ? it->second : NULL);
}

bool GuildMgr::addGuild(Guild *guild)
{
	if (guild == NULL)
	{
		return false;
	}

	std::string guildname = guild->getGuildName();
	std::transform(guildname.begin(), guildname.end(), guildname.begin(), tolower);

	if (m_id2guild_map.find(guild->getGuildID()) != m_id2guild_map.end())
	{
		return false;
	}

	if (m_name2guild_map.find(guildname) != m_name2guild_map.end())
	{
		return false;
	}

	m_guilds.push_back(guild);
	m_name2guild_map.insert(std::make_pair(guildname, guild));
	m_id2guild_map.insert(std::make_pair(guild->getGuildID(), guild));

	addGuildRanks(guild->getGuildID());

	m_version ++;
	syncGuildVersion(NULL);

	return true;
}

Guild *GuildMgr::rmvGuild(int guild_id)
{
	size_t guild_index = m_guilds.size();
	size_t guild_count = m_guilds.size();
	for (size_t i = 0; i < guild_count; ++i)
	{
		Guild *guild = m_guilds[i];

		if (guild->getGuildID() == guild_id)
		{
			guild_index = i;
			break;
		}
	}

	if (guild_index >= m_guilds.size())
	{
		return NULL;
	}

	Guild *guild = m_guilds[guild_index];
	m_guilds.erase(m_guilds.begin() + guild_index);

	rmvGuildRanks(guild->getGuildID());

	m_id2guild_map.erase(guild->getGuildID());

	std::string guildname = guild->getGuildName();
	std::transform(guildname.begin(), guildname.end(), guildname.begin(), tolower);
	m_name2guild_map.erase(guildname);
	g_world.onGuildDelete(guild->getGuildID());
	GSHelper::syncGuildDeletedToCross(guild->getGuildID());
	m_version ++;
	syncGuildVersion(NULL);
	return guild;
}

void GuildMgr::rmvAllGuild()
{
	size_t guild_index = m_guilds.size();
	size_t guild_count = m_guilds.size();
	std::vector<Guild *> guilds = m_guilds;
	for (size_t i = 0; i < guild_count; ++i)
	{
		Guild *guild = guilds[i];
		MsgDBGuildDelete *dbmsg = new MsgDBGuildDelete;
		dbmsg->guildid = guild->getGuildID();
		g_app.postToNetService(dbmsg);
		rmvGuild(guild->getGuildID());
	}
}



Guild *GuildMgr::getGuildByName(const std::string &guild_name)
{
	std::string name = guild_name;
	std::transform(name.begin(), name.end(), name.begin(), tolower);

	auto it = m_name2guild_map.find(name);
	return ((it != m_name2guild_map.end()) ? it->second : NULL);
}

void GuildMgr::update(int elapse)
{
	bool guildmoneydown = false;
	bool guildpropreset = false;
	int  downmoneylvl = 5000;

	//showMemoryInfo(1);

	lua::call(lua::L, "Guild.getUpdateData");
	guildmoneydown = lua::getboolean(1);
	guildpropreset = lua::getboolean(2);
	downmoneylvl = lua::getinteger(3);
		
	//showMemoryInfo(2);

	int nowtime = get_time();
	//std::vector <int> releaseGuildID;
	std::vector <int> resetPropData;
	if (guildpropreset)
	{
		lua::call(lua::L, "Guild.returnresetProp");
		resetPropData = lua::getvector(1);
	}

	//showMemoryInfo(3);
	int now = get_time();

	size_t guild_count = m_guilds.size();
	for (size_t i = 0; i < guild_count; ++i)
	{
		Guild *guild = m_guilds[i];
		if (guild == NULL)
		{
			continue;
		}

		if (guildpropreset)
		{
			// Guild Reset Props;
			for (auto it = resetPropData.begin(); it != resetPropData.end(); ++it)
			{
				guild->setProp(*it,0);
				GuildHelper::syncProp(*guild, *it);
			}
		}
	}

	//定时删除公会申请记录
	GuildMgr::delPlayerGuildApp(elapse);
	//系统改变会长
	GuildHelper::autoChangeMaste();

	for (auto it = resetPropData.begin(); it != resetPropData.end(); ++it)
	{
		MsgDBGuildExDataUpdateAll *dbmsg = new MsgDBGuildExDataUpdateAll;
		dbmsg->idx = *it;
		dbmsg->data = 0;
		g_app.postToNetService(dbmsg);
	}
}

int GuildMgr::getGuildCount()
{
	return (int)m_guilds.size();
}

Guild *GuildMgr::getGuildByRank(int rank)
{
	if (rank >= 0 && rank < (int)m_GuildRanks.size())
	{
		int gid = m_GuildRanks[rank];
		return getGuildByID(gid);
	}
	return NULL;
}

int GuildMgr::getGuildRankSize() const
{
	return (int)m_GuildRanks.size();
}

void GuildMgr::clearGuildRanks()
{
	m_GuildRanks.clear();
}

void GuildMgr::addGuildRanks(int gid)
{
	for (size_t i = 0; i < m_GuildRanks.size(); ++i)
	{
		if (m_GuildRanks[i] == gid)
		{
			return;
		}
	}

	m_GuildRanks.push_back(gid);
	Guild *guild = getGuildByID(gid);
	if (guild)
	{
		guild->setProp(GUILD_PROP_RANK, (int)m_GuildRanks.size());
		GuildHelper::syncProp(*guild, GUILD_PROP_RANK);
	}

}

void GuildMgr::rmvGuildRanks(int gid)
{
	for (auto it = m_GuildRanks.begin(); it != m_GuildRanks.end(); ++it)
	{
		int rankgid = *(it);
		if (rankgid == gid)
		{
			m_GuildRanks.erase(it);
			break;
		}
	}
}

//获取行会名次
int GuildMgr::getGuildRank(int guild_id)
{
	for (int i = 0; i < m_GuildRanks.size(); ++i)
	{
		if (m_GuildRanks[i] == guild_id)
		{
			return i + 1;
		}
	}

	return (int)m_GuildRanks.size() + 1;
}

bool GuildMgr::playerAppGuild(int player_id, int guild_id)
{
	auto it = m_player_app_map.find(player_id);
	if (it == m_player_app_map.end())
	{
		m_player_app_map[player_id].insert(guild_id);
		return true;
	}

	if (it->second.size() >= PLAYER_APP_MAX)
	{
		return false;
	}
	else
	{
		it->second.insert(guild_id);
		return true;
	}
}

//清除申请加入行会请求
void GuildMgr::clearPlayerApp(int player_id, int guild_id)
{
	auto it = m_player_app_map.find(player_id);
	if (it == m_player_app_map.end())
	{
		return;
	}

	if (guild_id == 0)
	{
		for (auto apit = it->second.begin(); apit != it->second.end(); ++apit)
		{
			guild_id = *apit;
			Guild *guild = getGuildByID(guild_id);
			if (guild == NULL)
			{
				continue;
			}

			guild->removeApplication(player_id);
			GuildHelper::syncApplicationChange(*guild, player_id);
		}
		m_player_app_map.erase(it);
	}
	else
	{
		Guild *guild = getGuildByID(guild_id);
		if (guild)
		{
			guild->removeApplication(player_id);
		}
		it->second.erase(guild_id);

		if(guild)
		{
			GuildHelper::syncApplicationChange(*guild, player_id);
		}
	}
}
//定时删除申请记录
void GuildMgr::delPlayerGuildApp(int elapse)
{
	int now = get_time();
	int dsecond = 24 * 60 * 60;

	int guild_count = g_guild_mgr.getGuildCount();
	for (int i = 0; i < guild_count ; i++)
	{
		Guild *guild = g_guild_mgr.getGuildByRank(i);
		if (guild == nullptr)
		{
			continue;
		}
		std::vector<GuildApp*>  apps = guild->getApplications();
		for(size_t j = 0;j < apps.size();++j)
		{
			const GuildApp* app = apps[j];
			if (now - app->apptime > dsecond)
			{
				GuildMgr::clearPlayerApp(app->player_id,guild->getGuildID());
			}
		}

	}
}

void GuildMgr::sendShopList(Entity *entity, int page)
{
	if (entity == nullptr)
	{
		return;
	}

	const int everyPage = 10;
	int totalCount = (int)m_ItemList.size();
	int maxPage = totalCount/everyPage;

	int rtv = ERROR_UNKNOWN;
	if (page > maxPage)
	{
		rtv = ERROR_GUILD_SHOP_INVALID_PAGE;
	}

	MsgGuildShopItemResponse* notify = new MsgGuildShopItemResponse;
	notify->page = page;
	notify->maxpage = maxPage;

	for (auto it = m_ItemList.begin(); it != m_ItemList.end(); ++it)
	{
		auto sitem = m_sell_map.find(it->second);
		if (sitem != m_sell_map.end())
		{
			if (it->first/everyPage==page)
			{
				notify->items.push_back(sitem->second);
			}
		}
	}

	entity->sendMessage(notify);
}

void GuildMgr::addShopItem(int iid, int sid, int newprice, int lvl)
{
	m_ItemList[iid] = sid;
	GuildShopItem sd; 
	sd.sid = sid;
	sd.price = newprice;
	sd.level = lvl;
	m_sell_map[sid] = sd;
}

void GuildMgr::syncGuildVersion(Entity *entity)
{
	MsgGuildListVersionNotify *notify = new MsgGuildListVersionNotify;
	notify->version = m_version;
	notify->maxpage = (int)((m_id2guild_map.size() - 1) / 6 + 1);

	if (entity)
	{
		entity->sendMessage(notify);
	}
	else
	{
		EntityOperationHelper::syncWorldMsg(notify);
 		//MsgBroadcast* online = new MsgBroadcastOnline;
 		//online->m_message = notify;
 		//m_wpsvcNet->postMsg(online);
	}
}

void GuildMgr::removeGuildName(std::string guildName)
{
	std::transform(guildName.begin(), guildName.end(), guildName.begin(), tolower);
	m_name2guild_map.erase(guildName);
}

//加载工会祈福的数据
void GuildMgr::loadGuildQifuData()
{
	MsgDBQiFuLoad *msg = new MsgDBQiFuLoad;
	g_app.postToNetService(msg);
}

//保存祈福数据
void GuildMgr::saveGuildQifuData(std::vector<GuildQFInfo> items)
{
	guildQfItems = items; 
}

//获取公会祈福数据
GuildQFInfo GuildMgr::getGuildQFData(int guildid)
{
	GuildQFInfo item;
	for(auto it = guildQfItems.begin();it != guildQfItems.end();it++)
	{
		if(it->guildid == guildid)
		{
			item.id = it->id;
			item.guildid = it->guildid;
			item.percent = it->percent;
			item.percentOld = it->percentOld;
			return item;
		}
	}
	if(guildQfItems.size() == 0)
	{
		item.id = 1;
	}
	else
	{
		item.id = guildQfItems[guildQfItems.size()-1].id + 1;
	}
	item.guildid = guildid;
	item.percent = 0;
	item.percentOld = 0;
	guildQfItems.push_back(item);
	updateQFData(item);
	return item;
}

void GuildMgr::updateQFData(GuildQFInfo item)
{
	MsgDBQiFuUpdate *msg = new MsgDBQiFuUpdate;
	msg->guildQfItems.push_back(item);
	g_app.postToNetService(msg);

	loadGuildQifuData();
}

GuildQFInfo GuildMgr::startQiFu(int point,int guildid)
{
	GuildQFInfo item;
	for(auto it = guildQfItems.begin();it != guildQfItems.end();it++)
	{
		if(it->guildid == guildid)
		{
			it->percent = it->percent+point;
			if(it->percent > 100)
			{
				it->percent = 100;
			}
			item.id = it->id;
			item.guildid = it->guildid;
			item.percent = it->percent;
			item.percentOld = it->percentOld;
			updateQFData(item);
			return item;
		}
	}
	return item;
}

//0点刷新
void GuildMgr::onZeroTime()
{
	for(auto it = guildQfItems.begin();it != guildQfItems.end();it++)
	{
		int old = it->percent;
		it->percentOld = it->percent;
		it->percent = 0;
	}

	MsgDBQiFuUpdate *msg = new MsgDBQiFuUpdate;
	msg->guildQfItems = guildQfItems;
	g_app.postToNetService(msg);

	loadGuildQifuData();
}

// 从数据库加公会商城
void GuildMgr::loadGuildShop()
{
	lua::call(lua::L, "Guild.checkVersion");

	MsgDBLoadGuildShop *msg = new MsgDBLoadGuildShop;
	g_app.postToNetService(msg);
}

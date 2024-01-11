#ifndef _GUILD_MANAGER_H_INCLUDED
#define _GUILD_MANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <set>
#include "message/DBMsgGuild.h"

class Guild;
class Message;
class MsgDBGuildLoad;
struct GuildShopItem;
class Entity;

//行会管理器
class GuildMgr 
{
public:
	GuildMgr();
	~GuildMgr();

	void clear();

	//初始化
	void initGuilds(MsgDBGuildLoad *msg);

	void update(int elapse);

	Guild *getGuildByID(int guild_id);
	Guild *getGuildByName(const std::string &guild_name);
	Guild *getGuildByRank(int rank);

	int getGuildRankSize() const;
	void clearGuildRanks();
	void addGuildRanks(int guild_id);
	void rmvGuildRanks(int guild_id);
	//获取行会名次
	int getGuildRank(int guild_id);

	bool addGuild(Guild *guild);
	Guild *rmvGuild(int guildid);

	void rmvAllGuild();

	int getGuildCount();

	void sendGuildInfoAll(int pid,int guild_id,int sessid);

	//检查玩家是否有申请加入行会请求
	bool playerAppGuild(int player_id, int guild_id);

	//清除申请加入行会请求
	void clearPlayerApp(int player_id, int guild_id);

	//删除申请
	void delPlayerGuildApp(int elapse);

	std::vector<Guild *> &getGuilds() { return m_guilds; }

public:
	//发送行会商店物品列表
	void sendShopList(Entity *entity, int page);

	//增加行会商店中的物品
	void addShopItem(int iid, int sid, int newprice, int lvl);

	void syncGuildVersion(Entity *entity);

	void syncGuildGczList(Entity *entity);

	void removeGuildName(std::string guildName);

public:
	//从数据库加载祈福数据
	void loadGuildQifuData();
	//保存所有的祈福数据
	void saveGuildQifuData(std::vector<GuildQFInfo> items);
	//获取公会祈福数据
	GuildQFInfo getGuildQFData(int guildid);

	void updateQFData(GuildQFInfo item);

	GuildQFInfo startQiFu(int point,int guildid);

	void onZeroTime();

	// 从数据库加公会商城
	void loadGuildShop();

protected:
	std::vector<int> m_GuildRanks;

	std::vector<Guild *> m_guilds;
	std::map<int, Guild*> m_id2guild_map;
	std::map<std::string, Guild*> m_name2guild_map;

	//<玩家ID, 行会ID集合>
	std::map<int, std::set<int>> m_player_app_map;	//玩家申请加入行会请求表

	int m_version;	//行会信息版本号(增加,删除行会会修改此版本号)

	std::map<int, GuildShopItem> m_sell_map;
	std::map<int, int> m_ItemList;
	std::vector<GuildQFInfo> guildQfItems;  //工会祈福数据
};

extern GuildMgr g_guild_mgr;

#endif	//_GUILD_MANAGER_H_INCLUDED

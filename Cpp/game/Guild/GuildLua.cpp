#include "stdafx.h"
#include "GuildLua.h"
#include "GuildHelper.h"
#include "GuildMgr.h"
#include "GuildTeam.h"
#include "GuildShop.h"
#include "GuildGuishi.h"
#include "Entity/EntityLua.h"
#include "Entity/WorldPlayerManager.h"
#include "OperationHelper.h"
#include "Guild/GuildItemManager.h"
#include "Item/ItemLua.h"
#include "Item/ItemOperationHelper.h"
#include "message/MsgCross.h"
#include "Application.h"

static int getID(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		lua::push(L, guild->getGuildID());
		return 1;
	}
	return 0;
}

static int getGuildName(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		std::string name = guild->getGuildName();
		lua::push(L, name);
	}
	else
	{
		lua::push(L, "");
	}
	return 1;
}

static int getJob(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
// 		int pid = lua::tointeger(L, 2);
// 		GuildMember* pMember = guild->getGuildMember(pid);
// 		if (pMember)
// 		{
// 			int job = pMember->job;
// 			lua::push(L, job);
// 			return 1;
// 		}
	}
	return 0;
}

static int getGuildMoney(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
/*		int money = guild->getGuildMoney();*/
//		lua::push(L, money);
		return 1;
	}
	return 0;
}

static int addGuildMoney(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int money = lua::tointeger(L, 2);
/*		guild->addGuildMoney(money);*/
	}
	return 0;
}

static int addContribution(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int pid = lua::tointeger(L, 2);
		int con = lua::tointeger(L, 3);
// 		if (pid>0&&con>0)
// 		{
// 			guild->addContribution(pid,con);
// 		}
	}
	return 0;
}

static int syncFloatMessage(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		std::string msg = lua::tostring(L, 2);
		GuildHelper::syncGuildFloatNotice(*guild,msg);
	}
	return 0;
}

static int setProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		int data = lua::tointeger(L, 3);
		guild->setProp(idx,data);
	}
	return 0;
}

static int getProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		lua::push(L, guild->getProp(idx));
		return 1;
	}
	return 0;
}

static int recordMoneyOp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	Entity *entity = lua::toentity(L, 2);

	int old_count = lua::tointeger(L, 3);
	int cnt = lua::tointeger(L, 4);
	int opcode = lua::tointeger(L, 5);
	int opdata = lua::tointeger(L, 6);

	OperationHelper::recordGuildMoneyOp(*guild, entity, old_count, cnt, opcode, opdata);

	return 0;
}

static int addProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		int data = 1;
		if (lua::gettop(L)>=3)
		{
			data = lua::tointeger(L, 3);
		}
		guild->setProp(idx,guild->getProp(idx) + data);
	}
	return 0;
}

static int syncProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		GuildHelper::syncProp(*guild,idx);
	}
	return 0;
}

static int saveProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		GuildHelper::saveProp(*guild,idx);
	}
	return 0;
}

static int getMemberCount(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		lua::push(L, guild->getMemberCount());
		return 1;
	}
	return 0;
}

static int getOnlineMemberCount(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		lua::push(L, guild->getOnlineMemberCount());
		return 1;
	}
	return 0;
}

static int getMemberCountByPost(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int post = lua::tointeger(L, 2);
		lua::push(L, guild->getMemberCountByPost(post));
		return 1;
	}
	return 0;
}

static int addApplication(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, (int)ERROR_GUILD_NO_GUILD);
		return 1;
	}

	Entity *pEntity = (Entity *)lua::touserdata(L, 2, "mt_entity");
	lua::push(L, GuildHelper::addGuildApplication(*guild, *pEntity));
	return 1;
}

static int InApplicaition(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, (int)ERROR_GUILD_NO_GUILD);
		return 1;
	}

	Entity *pEntity = (Entity *)lua::touserdata(L, 2, "mt_entity");
	lua::push(L, GuildHelper::CheckHaveApplicationedGuild(*guild, *pEntity));
	return 1;
}

static int forEach(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	lua::settop(L, 2);
	if (!lua::isfunction(L, 2))
	{
		LOG_ERROR("Invalid parameter for entity:forEachEntity, require: scene, entity"); 
		return 0;
	}

	std::vector<GuildMember *> &members = guild->getMembers();
	size_t count = members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = members[i];
		if (member->player)
		{
			//	the call back function is on the top of stack
			if (lua::call(L, nullptr, member->player))
			{
				//return true;
			}
			else
			{
				//return false;
			}
		}
	}

	return 0;
}

static int forEachName(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	lua::settop(L, 2);
	if (!lua::isfunction(L, 2))
	{
		LOG_ERROR("Invalid parameter for entity:forEachEntity, require: scene, entity"); 
		return 0;
	}

	std::vector<GuildMember *> &members = guild->getMembers();
	size_t count = members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = members[i];
		if (NULL == member)
		{
			continue;
		}

		//	the call back function is on the top of stack
		lua::call(L, nullptr, member->player_name);
	}

	return 0;
}

static int forEachPlayerID(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	lua::settop(L, 2);
	if (!lua::isfunction(L, 2))
	{
		LOG_ERROR("Invalid parameter for entity:forEachEntity, require: scene, entity"); 
		return 0;
	}

	std::vector<GuildMember *> &members = guild->getMembers();
	size_t count = members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = members[i];
		if (NULL == member)
		{
			continue;
		}

		//	the call back function is on the top of stack
		lua::call(L, nullptr, member->player_id);
	}

	return 0;
}

static int addShopItem(lua_State *L)
{

	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
	return 0;
	}

	int static_id = lua::tointeger(L, 2);
	guild->getShop()->addItem(guild->getGuildID(), static_id);
	

	GuildHelper::saveGuildShopItem(*guild, static_id);

	return 0;
}

static int syncShopItems(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	GuildHelper::syncGuildShop(*guild);

	return 0;
}

static int delShopItem(lua_State *L)
{
	GuildHelper::DelShopItems();

	return 0;
}

static int setStringProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		std::string data = lua::tostring(L, 3);
		guild->setStringProp(idx,data);
	}
	return 0;
}

static int getStringProp(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		int idx = lua::tointeger(L, 2);
		std::string ename = guild->getStringProp(idx);
		lua::push(L, ename);
		return 1;
	}
	return 0;
}

static int getGuildMasterGenderJob(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild)
	{
		GuildMember* guildmember = guild->getMember(guild->getProp(GUILD_PROP_MASTER_ID));
		if (guildmember)
		{
			lua::push(L, guildmember->gender);
			return 1;
		}
		return 0;
	}
	return 0;
}

// 鬼市
static int addGuishiItem(lua_State *L)
{

	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
	return 0;
	}

	int static_id = lua::tointeger(L, 2);



	GuildGuishi *guild_guishi = guild->getGuishi();
	if (guild_guishi == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	ShopGuishiItem * item = guild_guishi->addItem(guild->getGuildID(), static_id ,0);

	if (item == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}
	
	GuildHelper::saveGuildGuishiItem(*guild, item);
	//GuildHelper::syncGuildGuishiItemAdd(*guild, item);

	return 0;
}

static int syncGuishiItems(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	GuildHelper::syncGuildGuishi(*guild);

	return 0;
}

static int delGuishiItem(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, ERROR_UNKNOWN);
		return 1;
	}

	int iid = lua::tointeger(L, 2) > 0 ? lua::tointeger(L, 2) : 0;
	if (iid <= 0)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	GuildGuishi *guild_guishi = guild->getGuishi();
	if (guild_guishi == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	ShopGuishiItem * item = guild_guishi->getItemByID(iid);
	if (item == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	guild_guishi->deleteItem(iid);

	GuildHelper::saveGuildGuishiItemDelete(*guild,iid);
	GuildHelper::syncGuildGuishiItemDelete(*guild,iid);

	lua::push(L, SUCCESS);
	return 1;
}

static int getAllGuishiItems(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	GuildGuishi *guild_guishi = guild->getGuishi();
	if (guild_guishi == nullptr)
	{
		return 0;
	}

	const auto &items_map = guild_guishi->getItems();

	lua::newtable(L);
	int i = 0;
	for (auto it = items_map.begin(); it != items_map.end(); ++it)
	{
		ShopGuishiItem *item = it->second;
		if (item)
		{
			lua::settable(L, -1, i + 1, it->second->cid);
			i++;
		}
	}

	return 1;
}

static int getGuishiItemBycid(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	GuildGuishi *guild_guishi = guild->getGuishi();
	if (guild_guishi == nullptr)
	{
		return 0;
	}

	int cid = lua::tointeger(L, 2) > 0 ? lua::tointeger(L, 2) : 0;

	ShopGuishiItem * item = guild_guishi->getItemByID(cid);
	if (item == nullptr)
	{
		return 0;
	}

	lua::push(L, item->sid);

	return 1;
}

//
static int getMemberByPlayerID(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	int player_id = lua::tointeger(L, 2);
	if (player_id <= 0)
	{
		return 0;
	}

	GuildMember *guildmember = guild->getMember(player_id);
	if (guildmember == nullptr)
	{
		return 0;
	}

	lua::newtable(L);
	lua::settable(L, -1, "player_id", guildmember->player_id);
	if (guildmember->player)
	{
		lua::push(L, guildmember->player);
		lua::settable(L, -2, "player");
	}
	lua::settable(L, -1, "player_name", guildmember->player_name);
	lua::settable(L, -1, "gender", guildmember->gender);
	lua::settable(L, -1, "level", guildmember->level);
	lua::settable(L, -1, "combatdata", guildmember->force);
	lua::settable(L, -1, "post", guildmember->post);
	lua::settable(L, -1, "contribution", guildmember->contribution);
	lua::settable(L, -1, "contribution_today", guildmember->contribution_today);
	lua::settable(L, -1, "intime", guildmember->intime);
	lua::settable(L, -1, "rank_week", guildmember->rank_day);
	lua::settable(L, -1, "rank", guildmember->rank);
	return 1;
}

static int destroyGuildTeam(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	int teamid = lua::tointeger(L, 2);

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL)
	{
		return 0;
	}

	teamM->destroyTeam(teamid);
	return 0;
}

static int getMasterName(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	std::string master_name = guild->getMasterName();

	lua::push(L, master_name);
	return 1;
}

static int getMasterPid(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}
	int pid = guild->getMasterPid();

	lua::push(L, pid);
	return 1;
}

static int getMemberIntime(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	int player_id = lua::tointeger(L, 2);
	GuildMember *member = guild->getMember(player_id);
	if (member == nullptr)
	{
		return 0;
	}

	lua::push(L, member->intime);
	return 1;
}

static int addRecord(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	int type = lua::tointeger(L, 2);
	int datax = lua::tointeger(L, 3);
	int datay = lua::tointeger(L, 4);
	std::string namex = lua::tostring(L, 5);
	std::string namey = lua::tostring(L, 6);

	GuildHelper::addRecord(guild, type, datax, datay, namex, namey);
	return 0;
}
//��ȡ�����̵깺������
static int getShopItemSellNum(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return -1;
	}
	int sid = lua::tointeger(L, 2);
	int sellNum = guild->getShop()->getSellNum(sid);
	lua::push(L, sellNum);
	return 1;
}
//�޸Ĺ����̵깺������
static int buyShopItemSetNum(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return -1;
	}
	int sid = lua::tointeger(L, 2);
	int num = lua::tointeger(L, 3);
	GuildHelper::updataGuildShopItemSellNum(*guild,sid,num);
	return 1;
}

static int addRedPacket(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == NULL)
	{
		return 0;
	}

	int redtype = lua::tointeger(L, 2);
	int max_gold = lua::tointeger(L, 3);
	int max_count = lua::tointeger(L, 4);
	std::string desc = lua::tostring(L, 5);

	GuildHelper::addRedPackage(guild, redtype, max_gold, max_count, desc);
	return 0;
}

static int releaseGuild(lua_State *L)
{
	int gid = lua::tointeger(L, 1);
	int pid = lua::tointeger(L, 2);
	int reason = lua::tointeger(L, 3);
	std::string name = lua::tostring(L, 4);
	GuildHelper::releaseGuild(gid, reason, pid, name);
	return 0;
}

static int mergeGuild(lua_State *L)
{
	int gid1 = lua::tointeger(L, 1);
	int gid2 = lua::tointeger(L, 2);
	GuildHelper::mergeGuild(gid1, gid2);
	return 0;
}

static int resetGuildMaster(lua_State* L)
{
	int guildId = lua::tointeger(L, 1);
	int presendMasterPid = lua::tointeger(L, 2);
	int newMasterPid = lua::tointeger(L, 3);
	Guild *guild = g_guild_mgr.getGuildByID(guildId);
	if (guild != nullptr)
	{
		GuildHelper::resetGuildMaster(*guild, presendMasterPid, newMasterPid);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////

static int getGuild(lua_State *L)
{
	int gid = lua::tointeger(L, 1);
	if (gid <= 0)
	{
		return 0;
	}

	Guild *guild = g_guild_mgr.getGuildByID(gid);
	if (guild == nullptr)
	{
		return 0;
	}

	lua::push(L, guild);
	return 1;
}

static int forEachGuild(lua_State *L)
{
	if (lua::gettop(L) < 1)
	{
		return 0;
	}

	lua::settop(L, 1);
	if (!lua::isfunction(L, 1))
	{
		LOG_ERROR("Invalid parameter for entity:forEachEntity, require: scene, entity"); 
		return 0;
	}

	std::vector<Guild *> &guilds = g_guild_mgr.getGuilds();
	size_t guild_count = guilds.size();
	for (size_t i = 0; i < guild_count; ++i)
	{
		Guild *guild = guilds[i];

		//	the call back function is on the top of stack
		if (lua::call(L, nullptr, guild))
		{
			//return true;
		}
		else
		{
			//return false;
		}
	}

	return 0;
}

static int addGuildRecord(lua_State* L)
{
	int guild_id = lua::tointeger(L, 1);
	if (guild_id <= 0)
	{
		return 0;
	}

	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	if (guild == nullptr)
	{
		return 0;
	}

	int type = lua::tointeger(L, 2);
	int datax = lua::tointeger(L, 3);
	int datay = lua::tointeger(L, 4);
	const char *namex = lua::tostring(L, 5);
	const char *namey = lua::tostring(L, 6);

	GuildHelper::addRecord(guild_id, type, datax, datay, namex, namey);
	return 0;
}

static int addVitality(lua_State* L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	int count = lua::tointeger(L, 2);

	GuildHelper::addVitality(guild, count);
	return 0;
}

static int useVitality(lua_State* L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	int count = lua::tointeger(L, 2);

	GuildHelper::useVitality(guild, count);
	return 0;
}

static int haveVitality(lua_State* L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	int count = lua::tointeger(L, 2);

	GuildHelper::haveVitality(guild, count);
	return 0;
}

static int syncMemberChange(lua_State* L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 2)
	{
		return 0;
	}

	int player_id = lua::tointeger(L, 2);
	if (player_id <= 0)
	{
		return 0;
	}

	GuildHelper::syncMemberChange(*guild, player_id);
	return 0;
}

static int updMemberVitality(lua_State* L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	if (lua::gettop(L) < 3)
	{
		return 0;
	}

	int player_id = lua::tointeger(L, 2);
	int value = lua::tointeger(L, 3);

	GuildHelper::updateMemberVitality(guild, player_id, value);
	return 0;
}

static int bagIsFull(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	GuildItemManager *guild_item_mgr = guild->getItemManager();
	if (guild_item_mgr == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	if (guild_item_mgr->isFull())
	{
		lua::push(L, ERROR_GUILD_NOT_ENOUGH_GUILD_BAG);
		return 1;
	}
	lua::push(L, SUCCESS);
	return 1;
}

//锟斤拷锟斤拷锟斤拷锟斤拷谢锟斤拷锟斤拷锟?
static int clearGuilds(lua_State *L)
{
	GuildHelper::clearGuilds();
	return 0;
}

static int sendGuildRecommendNotify(lua_State *L)
{
	Entity *entity = lua::toentity(L, 1);
	if (entity == nullptr)
	{
		return 0;
	}

	GuildHelper::sendGuildRecommendNotify(entity, 0);
	return 0;
}

static int depositItem(lua_State* L)
{
	EntityPlayer *player = dynamic_cast<EntityPlayer *>(lua::toentity(L, 1));
	if (player == nullptr)
	{
		return 0;
	}

	int item_id = lua::tointeger(L, 2);

	GuildHelper::donateItem(player, item_id);
	return 0;
}

static int getItemByPos(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		return 0;
	}

	int pos = lua::tointeger(L, 2);

	GuildItemManager *guild_item_mgr = guild->getItemManager();
	if (guild_item_mgr == nullptr)
	{
		return 0;
	}

	Item *item = guild_item_mgr->getItemByPos(pos);
	if (item == NULL)
	{
		return 0;
	}

	lua::push(L, item);
	return 1;
}

static int delItem(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, ERROR_UNKNOWN);
		return 1;
	}

	int iid = lua::tointeger(L, 2);

	GuildItemManager *guild_item_mgr = guild->getItemManager();
	if (guild_item_mgr == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	Item *item = guild_item_mgr->getItemByID(iid);
	if (item == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	guild_item_mgr->delItem(iid);
	ItemOperationHelper::saveGuildItemDelete(*guild, iid);
	ItemOperationHelper::syncGuildItemDelete(*guild, iid);

	lua::push(L, SUCCESS);
	return 1;
}

static int addItem(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, ERROR_UNKNOWN);
		return 1;
	}

	int static_id = lua::tointeger(L, 2);

	GuildItemManager *guild_item_mgr = guild->getItemManager();
	if (guild_item_mgr == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	Item *item = ItemOperationHelper::createItem(static_id);
	if (item == nullptr)
	{
		lua::push(L, ERROR_INVALID_ITEM);
		return 1;
	}

	item->setCount(1);

	guild_item_mgr->depositItem(item);
	ItemOperationHelper::saveGuildItemAdd(*guild, item);
	ItemOperationHelper::syncGuildItemAdd(*guild, item);

	lua::push(L, SUCCESS);
	return 1;
}

static int changeMaster(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, ERROR_UNKNOWN);
		return 1;
	}

	int new_master_pid = lua::tointeger(L, 2);

	int errcode = GuildHelper::changeMaster(*guild, new_master_pid);
	lua::push(L, errcode);
	return 1;
}

static int isMasterOnline(lua_State *L)
{
	Guild *guild = lua::toguild(L, 1);
	if (guild == nullptr)
	{
		lua::push(L, false);
		return 1;
	}

	GuildMember *master_member = guild->getMasterMember();
	if (master_member == nullptr)
	{
		lua::push(L, false);
		return 1;
	}
	
	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(master_member->player_id);
	if (player == nullptr)
	{
		lua::push(L, false);
		return 1;
	}

	lua::push(L, true);
	return 1;
}

static int gmAddMemGuildMaster(lua_State *L)
{
	int guildid = lua::tointeger(L, 1);
	int new_master_pid = lua::tointeger(L, 2);
	GuildHelper::decideGMApplicationAndUpdataGuildMaster(guildid,new_master_pid);
	return 0;
}

static int gmChangeMaster(lua_State *L)
{
	int guildid = lua::tointeger(L, 1);
	Guild *guild = g_guild_mgr.getGuildByID(guildid);
	if (guild == NULL)
	{
		return 0;
	}

	int new_master_pid = lua::tointeger(L, 2);

	int errcode = GuildHelper::gmChangeMaster(*guild, new_master_pid);
	lua::push(L, errcode);
	return 1;
}

static int rmvAllGuild(lua_State* L)
{
	g_guild_mgr.rmvAllGuild();
	return 0;
}

static int sendGuildActivitySWYRewards(lua_State *L)
{
	int pid = lua::tointeger(L, 1);
	int serverId = lua::tointeger(L, 2);
	int rank = lua::tointeger(L, 3);
	int rankType = lua::tointeger(L, 4);
	int gid = lua::tointeger(L, 5);
	if (g_config.isCrossServer())
	{
		MsgSendSWYAwardNotify* notify = new MsgSendSWYAwardNotify();
		notify->setUserData(serverId);
		notify->pid = pid;
		notify->rank = rank;
		notify->serverid = serverId;
		notify->rankType = rankType;
		notify->gid = gid;
		g_app.postToNetService(notify);
	} 
	else
	{
		lua::call(lua::L, "Guild.sendGuildActivitySWYRewards", pid,rank,rankType,gid);
	}
	return 0;
}

static int sendGuildBattleRewards(lua_State *L)
{
	int pid = lua::tointeger(L, 1);
	int serverId = lua::tointeger(L, 2);
	int rankType = lua::tointeger(L, 3);
	int rank = lua::tointeger(L, 4);
	if (g_config.isCrossServer())
	{
		MsgSendGuildBattleAwardNotify* notify = new MsgSendGuildBattleAwardNotify();
		notify->setUserData(serverId);
		notify->pid = pid;
		notify->rank = rank;
		notify->serverid = serverId;
		notify->rankType = rankType;
		g_app.postToNetService(notify);
	} 
	else
	{
		lua::call(lua::L, "GuildBattle.sendRankRewards", pid, rankType, rank);
	}
	return 0;
}

void lua::openguild(lua_State *L)
{
	static LuaReg funcs[] = {
		{"getID",						getID},
		{"getGuildName",				getGuildName},
		//{"getJob",					getJob},
		//{"getGuildMoney",				getGuildMoney},
		//{"addGuildMoney",				addGuildMoney},
		//{"addContribution",			addContribution},
		{"getProp",						getProp},
		{"setProp",						setProp},
		{"addProp",						addProp},
		{"syncProp",					syncProp},
		{"saveProp",					saveProp},
		{"setStringProp",				setStringProp},
		{"getStringProp",				getStringProp},
		{"setPropString",				setStringProp},
		{"getPropString",				getStringProp},
		{"forEach",						forEach},
		{"forEachName",					forEachName},
		{"forEachPlayerID",				forEachPlayerID},
		{"getMemberCount",				getMemberCount},
		{"getOnlineMemberCount",		getOnlineMemberCount},
		{"getMemberCountByPost",		getMemberCountByPost},
		{"addApplication",				addApplication},
		{"InApplicaition",				InApplicaition},
		{"syncFloatMessage",			syncFloatMessage},
		{"getGuildMasterGenderJob",		getGuildMasterGenderJob},
		{"recordMoneyOp",				recordMoneyOp},
		{"getMemberByPlayerID",			getMemberByPlayerID},
		{"addVitality",					addVitality},
		{"useVitality",					useVitality},
		{"haveVitality",				haveVitality},
		{"syncMemberChange",			syncMemberChange},
		{"updMemberVitality",			updMemberVitality},
		{"bagIsFull",					bagIsFull},
		{"destroyGuildTeam",			destroyGuildTeam},
		{"getItemByPos",				getItemByPos},
		{"delItem",						delItem},
		{"addItem",						addItem},
		{"addShopItem",					addShopItem},
		{"syncShopItems",				syncShopItems},
		{"changeMaster",				changeMaster},
		{"isMasterOnline",				isMasterOnline},
		{"getMasterName",				getMasterName},
		{"getMasterPid",				getMasterPid},
		{"getMemberIntime",				getMemberIntime},
		{"addRecord",					addRecord},
		{"getShopItemSellNum",          getShopItemSellNum},
		{"buyShopItemSetNum",           buyShopItemSetNum},
		{"addRedPacket",				addRedPacket},
		{"addGuishiItem",				addGuishiItem},
		{"syncGuishiItems",				syncGuishiItems},
		{"delGuishiItem",				delGuishiItem},
		{"getAllGuishiItems",			getAllGuishiItems},
		{"getGuishiItemBycid",			getGuishiItemBycid},
		{nullptr,						nullptr},
	};
	lua::registermetatable(L, "mt_guild", funcs);

	static LuaReg global_funcs[] = {
		{"getGuild",					getGuild},
		{"forEachGuild",				forEachGuild},
		{"addGuildRecord",				addGuildRecord},
		{"clearGuilds",					clearGuilds},
		{"sendGuildRecommendNotify",	sendGuildRecommendNotify},
		{"depositItem",					depositItem},
		{"delShopItem",					delShopItem},
		{"gmAddMemGuildMaster",			gmAddMemGuildMaster},
		{"gmChangeMaster",				gmChangeMaster},
		{"rmvAllGuild",					rmvAllGuild},
		{"releaseGuild",				releaseGuild},
		{"resetGuildMaster",			resetGuildMaster},
		{"sendGuildActivitySWYRewards",	sendGuildActivitySWYRewards},
		{"sendGuildBattleRewards",		sendGuildBattleRewards},
		{"mergeGuild",					mergeGuild},
		{nullptr,						nullptr},
	};
	lua::registerlib(L, "_G", global_funcs);
}

void lua::push(lua_State *L, Guild *guild)
{
	lua::push(L, "mt_guild", guild);
}

Guild *lua::toguild(lua_State *L, int index)
{
	return (Guild *)lua::touserdata(L, index, "mt_guild");
}

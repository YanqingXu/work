#include "stdafx.h"
#include "GuildHelper.h"
#include "GuildItemManager.h"
#include "Entity/EntityLua.h"
#include "Entity/WorldPlayerManager.h"
#include "message/MsgItem.h"
#include "message/MsgScene.h"
#include "message/MsgWorld.h"
#include "message/DBMsgPlayer.h"
#include "GuildLua.h"
#include "GuildMgr.h"
#include "GuildTeam.h"
#include "GuildShop.h"
#include "GuildGuishi.h"
#include "Item/ItemOperationHelper.h"
#include "Entity/EntityOperationHelper.h"
#include "Event/EventData.h"
#include "OperationHelper.h"
#include "Scene/SceneOperationHelper.h"
#include "Application.h"
#include "World/World.h"
#include "Event/EventHelper.h"
#include "Cross/GSHelper.h"

namespace GuildHelper
{
	// 初始化成员信息
	void initMemberMsgInfo(GuildMember* pMem, GuildMemberInfo* pInfo)
	{
		pInfo->pid = pMem->player_id;
		pInfo->level = pMem->level;
		pInfo->todaycontribution = pMem->contribution_today;
		pInfo->contribution = pMem->contribution;
		pInfo->rank = pMem->rank;
		pInfo->gender = pMem->gender;
		pInfo->speek = pMem->speek;
		pInfo->reborn = pMem->reborn;
		pInfo->sponsorGrade = pMem->sponsorGrade;
		pInfo->job = pMem->job;
		// 如果在线取在线数据
		EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(pInfo->pid);
		if (player)
		{
			pInfo->name = player->getName();
			pInfo->level = player->getLevel();
			pInfo->post = player->getProp(ENTITY_PROP_GUILD_POST);
			pInfo->online = 1;
			pInfo->offtime = 0;
			pInfo->sceneid = player->getSceneStaticID();
			pInfo->sponsorGrade = player->getProp(ENTITY_PROP_SPONSOR_GRADE);
			pInfo->reborn = player->getProp(ENTITY_PROP_REBORN);
			pInfo->job = player->getClass();
			pMem->player_name = player->getName();
			pMem->level = player->getLevel();
			pMem->post = player->getProp(ENTITY_PROP_GUILD_POST);
			pMem->reborn = player->getProp(ENTITY_PROP_REBORN);
			pMem->sponsorGrade = player->getProp(ENTITY_PROP_SPONSOR_GRADE);
			pMem->job = player->getClass();
		}
		else
		{
			pInfo->name = pMem->player_name;
			pInfo->level = pMem->level;
			pInfo->post = pMem->post;
			pInfo->vitality = pMem->vitality;
			pInfo->online = 0;
			pInfo->offtime = pMem->offTime;
			pInfo->sceneid = 0;
			pInfo->reborn = pMem->reborn;
			pInfo->sponsorGrade = pMem->sponsorGrade;
		}
	}

	// 设置成员在线状态
	int setGuildMemberOnline(Entity& player, bool bOnline)
	{
		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild* guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild)
		{
			MsgGuildMemberOnlineNotify* msg = new MsgGuildMemberOnlineNotify;
			msg->pid = player.getGlobalID();
			msg->online = bOnline ? 1 : 0;
			guild->sendMessage(msg);
		}
		return 0;
	}

	// 设置成员所在场景
	int setGuildMemberScene(const Entity& player, int sceneid)
	{
		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild* guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild)
		{
			MsgGuildMemberSceneNotify* msg = new MsgGuildMemberSceneNotify;
			msg->pid = player.getGlobalID();
			msg->sceneid = sceneid;
			guild->sendMessage(msg);
		}
		return 0;
	}

	//设置成员离线时间
	int setGuildMemberOffTime(Guild &guild,EntityPlayer& player)
	{
	
		GuildMember* gmember = guild.getMember(player.getPlayerID());
		if (gmember)
		{
			int currTime = get_time();
			gmember->offTime = currTime;
			MsgDBGuildMemberOffTimeUpdate* msg = new MsgDBGuildMemberOffTimeUpdate;
			msg->guildid = guild.getGuildID();
			msg->pid = player.getPlayerID();
			msg->offTime = currTime;
			g_app.postToNetService(msg);
		}
		GuildHelper::syncMemberChange(guild, player.getPlayerID());
		return 0;
	}


	//创建行会
	int createGuild(EntityPlayer &player, const std::string &guild_name,std::string &placard,int level)
	{
		OperationHelper::setOpCode(OP_GUILD_CREATE);
		int ret = ERROR_UNKNOWN;
		//如果名字重复或者名字为空
		if (guild_name.empty() || (g_guild_mgr.getGuildByName(guild_name) != NULL))
		{
			return ERROR_GUILD_NAME_USED;
		}

		//如果玩家已经有行会
		if (player.getProp(ENTITY_PROP_GUILD_ID) > 0)
		{	
			return ERROR_GUILD_HAS_GUILD;
		}

		//如果行会名字过长
		int name_len = utf8_to_unicode_len(guild_name);
		if ((name_len <= 0) || (name_len > GUILD_NAME_MAX))
		{
			return ERROR_GUILD_NAME_TOO_LONG;
		}

		int lvl = 1;
		int money = 0;
		int next_level_time = 0;
		ret = ERROR_SCRIPT;
		lua::call(lua::L, "Guild.preCreateGuild", &player);
		ret = lua::getinteger(1);
		if (ret != SUCCESS)
		{
			return ret;
		}

		int guild_id = g_world.getNextGuildID() * (SERVER_ID_MAX + 1) + g_world.getID();
		Guild *guild = new Guild;
		guild->setGuildID(guild_id);
		guild->setGuildName(guild_name);
		guild->setProp(GUILD_PROP_MASTER_ID, player.getPlayerID());
		guild->setStringProp(GUILD_PROP_MASTER_NAME, player.getName());
		guild->setProp(GUILD_PROP_LEVEL, lvl);
		guild->setProp(GUILD_PROP_CBTX_LEVEL, 1);
		guild->setProp(GUILD_PROP_MONEY, 0);
		guild->setProp(GUILD_PROP_AUTOADD_LEVEL, level);
		guild->setStringProp(GUILD_PROP_PRIVATE_NOTICE, placard);
		guild->setCreateTime(get_time());


		g_guild_mgr.addGuild(guild);

		//保存数据库
		MsgDBGuildCreate *dbcr = new MsgDBGuildCreate;
		dbcr->gid = guild_id;
		dbcr->guildname = guild_name;
		dbcr->pid = player.getPlayerID();
		dbcr->lvl = guild->getProp(GUILD_PROP_LEVEL);
		dbcr->money = guild->getProp(GUILD_PROP_MONEY);
		dbcr->defaultnotice = placard;
		g_app.postToNetService(dbcr);
		GuildHelper::saveProp(*guild, GUILD_PROP_CBTX_LEVEL);
		guild->setProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME,get_time());

		//记录日志
		OperationHelper::recordGuildOp(*guild, player.getPlayerID(), player.getName(), 0, "", OP_GUILD_CREATE);
		OperationHelper::recordGuildMoneyOp(*guild, nullptr, 0, money, OP_GUILD_CREATE);

		// 清除之前的申请
		g_guild_mgr.clearPlayerApp(player.getPlayerID(), 0);

		//删除玩家所有申请加入行会的请求
		MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
		dbmsg->gid = 0;
		dbmsg->pid = player.getPlayerID();
		g_app.postToNetService(dbmsg);

		// add player to Guild
		GuildMember gmember;
		gmember.player_name = player.getName();
		gmember.player_id = player.getPlayerID();
		gmember.level = player.getLevel();
		gmember.post = GUILD_POST_MASTER;
		gmember.player = &player;
		gmember.gender = player.getProp(ENTITY_PROP_GENDER);
		gmember.intime = get_time();
		gmember.speek = 1;
		gmember.job = player.getClass();

		guild->addMember(gmember);

		// set player's guild
		player.setProp(ENTITY_PROP_GUILD_ID, guild_id);
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_ID);
		player.setPropString(ENTITY_PROP_GUILD_NAME, guild_name);

		player.setProp(ENTITY_PROP_GUILD_POST, GUILD_POST_MASTER);
		EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_GUILD_POST);
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_POST);

		//清邀请信息
		player.setPropString(ENTITY_STRPROP_GUILD_INVITE_DATA,"");
		EntityOperationHelper::syncEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);
		EntityOperationHelper::saveEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);
		player.setPropString(ENTITY_STRPROP_GUILD_MERGE_DATA,"");
		EntityOperationHelper::syncEntityStringProp(player, ENTITY_STRPROP_GUILD_MERGE_DATA);
		EntityOperationHelper::saveEntityStringProp(player, ENTITY_STRPROP_GUILD_MERGE_DATA);
		lua::call(lua::L, "Guild.onCreateGuild", guild ,&player);
		syncMeetGuildName(player);
		syncGuildAllInfo(player);

		return SUCCESS;
	}
	//捐献奖励
	int getGuildReward(EntityPlayer &player,int index)
	{
		OperationHelper::setOpCode(OP_GUILD_REWARD);

		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		if (guild_id <= 0)
		{
			return ERROR_NOT_IN_GUILD;
		}

		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		int ret = ERROR_SCRIPT;
		//lua::call(lua::L, "Guild.getGuildReward", &player);
		lua::call(lua::L, "Guild.donateAward", &player,index);
		ret = lua::getinteger(1);
		return ret;
	}

	bool getGuildRewardData(int job, int &sid, int &cnt)
	{
		lua::call(lua::L, "Guild.GetReward", job);
		sid = lua::getinteger(1);
		cnt = lua::getinteger(2);
		return ((sid > 0) && (cnt > 0));
	}

	bool getGuildDefaultNicknameData(int job, std::string &nickname)
	{
		lua::call(lua::L, "Guild.GetDefaultNickname", job);
		nickname = lua::getstring(1);
		if (nickname.size() == 0)
		{
			LOG_ERROR("GetDefaultNickname FAILED");
			return false;
		}

		return true;
	}

	int inviteGuildMember(EntityPlayer *player, EntityPlayer *target, Guild *guild)
	{
		if ((player == NULL) || (target == NULL))
		{
			return ERROR_INVALID_ENTITY;
		}

		if (guild == NULL)
		{
			return ERROR_GUILD_NO_THIS;
		}

		if (target->getProp(ENTITY_SET_REFUSE_GUILD_INVITE) == 1)
			return ERROR_REFUSE_GUILD_INVITE;

		lua::call(lua::L, "Guild.invite", guild, player, target,false);

		int ret = lua::getinteger(1);

		return ret;
	}

	int inviteFriendsToGuildWithCustomMember(EntityPlayer *player, EntityPlayer *target, Guild *guild)
	{
		if ((player == NULL) || (target == NULL))
		{
			return ERROR_INVALID_ENTITY;
		}

		if (guild == NULL)
		{
			return ERROR_GUILD_NO_THIS;
		}

		lua::call(lua::L, "Guild.invite", guild, player, target,true);

		int ret = lua::getinteger(1);

		return ret;
	}


	int inviteGuildMemberResult(int guild_id, EntityPlayer &entity, int decide)
	{
		if (decide != 1)
		{
			lua::call(lua::L, "Guild.delInviteData", guild_id, &entity);
			return SUCCESS;
		}

		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_GUILD_NOT_EXIST;
		}

		bool is_full = false;
		lua::call(lua::L, "Guild.isMemberFull", guild->getProp(GUILD_PROP_LEVEL), guild->getMemberCount());
		is_full = lua::getboolean(1);
		if (is_full)
		{
			return ERROR_GUILD_MAX_MEMBER;
		}

		int level = entity.getLevel();
		if (level < 20)
		{
			return ERROR_NOT_ENOUGH_LEVEL;
		}

		if (entity.getProp(ENTITY_PROP_GUILD_ID) > 0)
		{
			return ERROR_GUILD_HAS_GUILD;
		}

		int gender = entity.getProp(ENTITY_PROP_GENDER);

		addGuildMember(*guild, entity.getPlayerID(), entity.getProp(ENTITY_PROP_REBORN),
			entity.getLevel(), entity.getClass(), gender, entity.getName(), entity.getProp(ENTITY_PROP_SPONSOR_GRADE));

		syncMemberChange(*guild, entity.getPlayerID());

		EntityOperationHelper::saveEntityGuildID(entity, guild->getGuildID());
		EntityOperationHelper::syncEntityProp(entity, ENTITY_PROP_GUILD_ID);
		syncGuildAllInfo(entity);

		// 公会名字发送可见玩家
		syncMeetGuildName(entity);

		GuildHelper::addRecord(guild, GUILD_RECORD_MEMBER_JOIN, 0, 0, entity.getName(), "");
		//加入行会日志
		OperationHelper::recordGuildOp(*guild, entity.getPlayerID(), entity.getName(), 0, "", OP_GUILD_ENTER);

		g_guild_mgr.clearPlayerApp(entity.getPlayerID(), 0);
		MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
		dbmsg->gid = 0;
		dbmsg->pid = entity.getPlayerID();
		g_app.postToNetService(dbmsg);

		return SUCCESS;
	}


	void syncGuildFloatNotice(Guild &guild, const std::string &msg)
	{
		MsgSyncFloatNoticeNotify *notify = new MsgSyncFloatNoticeNotify;
		notify->basestring = msg;
		guild.sendMessage(notify);
	}

	void syncProp(Guild &guild, int idx)
	{
		int data = guild.getProp(idx);
		MsgSyncGuildExDataNotify *notify = new MsgSyncGuildExDataNotify;
		notify->idx = idx;
		notify->data = data;
		guild.sendMessage(notify);
	}

	void saveProp(Guild &guild, int idx)
	{
		int data = guild.getProp(idx);
		MsgDBGuildExDataUpdate *db = new MsgDBGuildExDataUpdate;
		db->gid = guild.getGuildID();
		db->idx = idx;
		db->data = data;
		g_app.postToNetService(db);
	}

	int addGuildApplication(Guild &guild, Entity &entity)
	{
		if (lua::call(lua::L, "Event.isGuildActivityTime", &entity))
		{
			bool ret = lua::getboolean(1);
			if (!ret)
			{
				return -1;
			}
		}
		bool is_full = false;
		lua::call(lua::L, "Guild.isMemberFull", guild.getProp(GUILD_PROP_LEVEL), guild.getMemberCount());
		is_full = lua::getboolean(1);
		int autoadd_level = guild.getProp(GUILD_PROP_AUTOADD_LEVEL);
		if (!is_full && 1 <= autoadd_level && autoadd_level <= 999 && entity.getLevel() >= autoadd_level)
		{
			addGuildMember(guild, entity.getGlobalID(), entity.getProp(ENTITY_PROP_REBORN), entity.getLevel(), entity.getClass(), entity.getProp(ENTITY_PROP_GENDER), entity.getName(), entity.getProp(ENTITY_PROP_SPONSOR_GRADE));
			syncMemberChange(guild, entity.getGlobalID());
			EntityOperationHelper::saveEntityGuildID(entity, guild.getGuildID());
			syncGuildAllInfo(*(EntityPlayer*)&entity);
			EntityOperationHelper::syncEntityProp(entity, ENTITY_PROP_GUILD_ID);
			syncMeetGuildName(entity);
			//行会事件
			GuildHelper::addRecord(&guild, GUILD_RECORD_MEMBER_JOIN, 0, 0, entity.getName(), "");
			//加入行会日志
			OperationHelper::recordGuildOp(guild, entity.getGlobalID(), entity.getName(), entity.getGlobalID(), entity.getName(), OP_GUILD_ENTER);
			g_guild_mgr.clearPlayerApp(entity.getGlobalID(), 0);
			MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
			dbmsg->gid = 0;
			dbmsg->pid = entity.getGlobalID();
			g_app.postToNetService(dbmsg);

			return SUCCESS;
		}

		if (!g_guild_mgr.playerAppGuild(entity.getGlobalID(), guild.getGuildID()))
		{
			return ERROR_GUILD_APP_MAX;
		}

		GuildApp app;
		app.player_id = entity.getGlobalID();
		app.player_name = entity.getName();
		app.job = entity.getClass();
		app.gender = entity.getProp(ENTITY_PROP_GENDER);
		app.reborn = entity.getProp(ENTITY_PROP_REBORN);
		app.level = entity.getLevel();
		app.apptime = get_time();
		app.type = 0;
		app.sponsorGrade = entity.getProp(ENTITY_PROP_SPONSOR_GRADE);
		guild.addApplication(app);

		syncApplicationChange(guild, app.player_id);
		return ERROR_GUILD_APP_PENDING;
	}

	int CheckHaveApplicationedGuild(Guild &guild, Entity &entity)
	{
		return guild.hasApplicationed(entity.getGlobalID());
	}

	//int CheckIsInGuildApplication(Guild &guild, EntityPlayer &entity)
	//{
	//	if (guild.getApplication(entity.getPlayerID()))
	//	{
	//		return 1;
	//	}

	//	return 0;
	//}

	//一键增加行会申请
	int autoAddGuildApplication(EntityPlayer *player)
	{
		if (player == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}
		int guild = player->getProp(ENTITY_PROP_GUILD_ID);
		if(guild != 0)
		{
			return ERROR_GUILD_HAS_GUILD;
		}
		
		if (lua::call(lua::L, "Event.isGuildActivityTime", player))
		{
			bool ret = lua::getboolean(1);
			if (!ret)
			{
				return -1;
			}
		}

		int appNum = 0;
		std::vector<Guild*> freeGuild;
		std::vector<Guild*> limitGuild;
		int guild_count = g_guild_mgr.getGuildCount();
		for (int i = 0; i < guild_count ; i++)
		{
			Guild *guild = g_guild_mgr.getGuildByRank(i);
			if (guild == nullptr)
			{
				continue;
			}

			if (guild->getApplication(player->getPlayerID()))
			{
				appNum+=1;
				continue;
			}
			//找自由入会的 找到后加入
			//找不到自由入会的 找最多10个公会去审批
			int errcode = ERROR_SCRIPT;
			lua::call(lua::L, "Guild.canApplyToJoinGuild", player, guild->getGuildID());
			    errcode = lua::getinteger(1);
			if (errcode == SUCCESS)
			{
				int limitLevel = guild->getProp(GUILD_PROP_AUTOADD_LEVEL);
				if (limitLevel > 0)
				{
					if (player->getLevel() >= limitLevel)
					{
						freeGuild.push_back(guild);
					}
					else
					{
						limitGuild.push_back(guild);
					}
				}
				else
				{
					limitGuild.push_back(guild);
				}
			}
			else
			{
				return errcode;
			}
		}

		std::vector<GuildData> freeData;
		size_t freeSize = freeGuild.size();
		for(size_t i = 0; i < freeSize; ++i)
		{
			Guild *guild = freeGuild[i];
			GuildData data;
			data.guild = guild;
			data.level = guild->getProp(GUILD_PROP_LEVEL);
			data.memberCount = guild->getMemberCount();
			data.ctime = guild->getCreateTime();
			freeData.push_back(data);
		}

		std::sort(freeData.begin(), freeData.end(), [](const GuildData &m1, const GuildData &m2)->bool
		{
			if(m1.level != m2.level)
			{
				return m1.level > m2.level;
			}
			else if(m1.memberCount != m2.memberCount)
			{
				return m1.memberCount > m2.memberCount;
			}
			else
			{
				return m1.ctime > m2.ctime;
			}
		});


		if(freeSize > 0)
		{
			Guild * guild =(freeData.front().guild);
			addGuildMember(*guild, player->getGlobalID(),player->getProp(ENTITY_PROP_REBORN), player->getLevel(),player->getClass(), player->getProp(ENTITY_PROP_GENDER), player->getName(), player->getProp(ENTITY_PROP_SPONSOR_GRADE));
			syncMemberChange(*guild, player->getGlobalID());

			EntityOperationHelper::saveEntityGuildID(*player, guild->getGuildID());
			syncGuildAllInfo(*player);
			EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_GUILD_ID);

			syncMeetGuildName(*player);
			//加入行会日志
			OperationHelper::recordGuildOp(*guild, player->getGlobalID(), player->getName(), player->getGlobalID(), player->getName(), OP_GUILD_ENTER);

			// rmv all application by pid = 
			g_guild_mgr.clearPlayerApp(player->getGlobalID(), 0);

			MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
			dbmsg->gid = 0;
			dbmsg->pid = player->getGlobalID();
			g_app.postToNetService(dbmsg);
			return SUCCESS;
		}
		else
		{
			//申请数量达到最大
			if(appNum >= PLAYER_APP_MAX)
			{
				return ERROR_GUILD_APP_MAX;
			}
			std::vector<GuildData> limitData;
			size_t limitSize = limitGuild.size();
			for(size_t i = 0; i < limitSize; ++i)
			{
				Guild *guild = limitGuild[i];
				GuildData data;
				data.guild = guild;
				data.level = guild->getProp(GUILD_PROP_LEVEL);
				data.memberCount = guild->getMemberCount();
				data.ctime = guild->getCreateTime();
				limitData.push_back(data);
			}

			std::sort(limitData.begin(), limitData.end(), [](const GuildData &m1, const GuildData &m2)->bool
			{
				if(m1.level != m2.level)
				{
					return m1.level > m2.level;
				}
				else if(m1.memberCount != m2.memberCount)
				{
					return m1.memberCount > m2.memberCount;
				}
				else
				{
					return m1.ctime < m2.ctime;
				}
			});

			for(size_t j = 0; j < limitSize; ++j)
			{
				if (j <= PLAYER_APP_MAX - 1)
				{
					Guild *guild = limitGuild[j];
					if (g_guild_mgr.playerAppGuild(player->getGlobalID(), guild->getGuildID()))
					{
						GuildApp app;
						app.player_id = player->getGlobalID();
						app.player_name = player->getName();
						app.job = player->getClass();
						app.gender = player->getProp(ENTITY_PROP_GENDER);
						app.reborn = player->getProp(ENTITY_PROP_REBORN);
						app.level =  player->getLevel();
						app.apptime = get_time();
						app.type = 0;
						app.sponsorGrade = player->getProp(ENTITY_PROP_SPONSOR_GRADE);
						guild->addApplication(app);
						syncApplicationChange(*guild, app.player_id);
					}
				}

			}

			return ERROR_GUILD_APP_PENDING;

		}
		return SUCCESS;
	}

	//处理加入行会申请
	int decideApplication(EntityPlayer &player, short decide, int other_player_id)
	{
		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		int post = player.getProp(ENTITY_PROP_GUILD_POST);
		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (post == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		GuildApp *gapp = guild->getApplication(other_player_id);
		if (gapp == NULL)
		{
			return ERROR_GUILD_NOAPP;
		}

		if (decide != GUILD_APP_ACCEPT)
		{
			// rmv Application in guild ;
			g_guild_mgr.clearPlayerApp(other_player_id, guild->getGuildID());
			return SUCCESS;
		}

		//检查行会成员是否已满
		bool is_full = false;
		lua::call(lua::L, "Guild.isMemberFull", guild->getProp(GUILD_PROP_LEVEL), guild->getMemberCount());
		is_full = lua::getboolean(1);
		if (is_full)
		{
			return ERROR_GUILD_MAX_MEMBER;
		}

		addGuildMember(*guild, gapp->player_id, gapp->reborn, gapp->level, gapp->job, gapp->gender, gapp->player_name, gapp->sponsorGrade);
		syncMemberChange(*guild, gapp->player_id);

		EntityPlayer *other = g_world_player_mgr.getPlayerByPlayerID(other_player_id);
		if (other)
		{
			EntityOperationHelper::saveEntityGuildID(*other, guild->getGuildID());
			syncGuildAllInfo(*other);
			EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_GUILD_ID);

			syncMeetGuildName(*other);
			MsgApplicationResultResponse *response = new MsgApplicationResultResponse;
			response->setSessionID(other->getSessionID());
			response->errcode = SUCCESS;
			g_app.postToNetService(response);
		}
		else
		{
			MsgDBUpdatePlayerGuildID* gmsg = new MsgDBUpdatePlayerGuildID;
			gmsg->gid = guild->getGuildID();
			gmsg->pid = gapp->player_id;
			g_app.postToNetService(gmsg);
		}

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_MEMBER_JOIN, 0, 0, gapp->player_name, "");

		//加入行会日志
		OperationHelper::recordGuildOp(*guild, player.getPlayerID(), player.getName(), gapp->player_id, gapp->player_name, OP_GUILD_ENTER);

		// rmv all application by pid = 
		g_guild_mgr.clearPlayerApp(other_player_id, 0);

		MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
		dbmsg->gid = 0;
		dbmsg->pid = other_player_id;
		g_app.postToNetService(dbmsg);

		return SUCCESS;
	}

	//处理加入行会申请
	int decideGMApplicationAndUpdataGuildMaster(int guildid , int other_player_id)
	{
		EntityPlayer *other = g_world_player_mgr.getPlayerByPlayerID(other_player_id);
		//一定要在线进行操作
		if(!other)return SUCCESS;

		Guild *guild = g_guild_mgr.getGuildByID(guildid);
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		//已经有会长了直接return
		if(guild->getMasterMember())return SUCCESS;

		if(other->getProp(ENTITY_PROP_GUILD_ID) == guildid) //如果已经在该行会中
		{
			int errcode = GuildHelper::gmChangeMaster(*guild, other_player_id);
			return SUCCESS;
		}

		addGuildMember(*guild, other->getPlayerID(), other->getProp(ENTITY_PROP_REBORN), other->getLevel(), other->getClass(), other->getProp(ENTITY_PROP_GENDER) , other->getName(), other->getProp(ENTITY_PROP_SPONSOR_GRADE));
		syncMemberChange(*guild, other_player_id);

		EntityOperationHelper::saveEntityGuildID(*other, guild->getGuildID());
		syncGuildAllInfo(*other);
		EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_GUILD_ID);

		syncMeetGuildName(*other);

		//加入行会日志
		OperationHelper::recordGuildOp(*guild, 888888, "xianfeng" , other_player_id, other->getName(), OP_GUILD_ENTER);

		// rmv all application by pid = 
		g_guild_mgr.clearPlayerApp(other_player_id, 0);

		MsgDBGuildApplicationDelete *dbmsg = new MsgDBGuildApplicationDelete;
		dbmsg->gid = 0;
		dbmsg->pid = other_player_id;
		g_app.postToNetService(dbmsg);

		//改变职位
		int errcode = GuildHelper::gmChangeMaster(*guild, other_player_id);

		if( errcode == SUCCESS)
		{

			//检查行会成员是否已满
			bool is_full = false;
			lua::call(lua::L, "Guild.isMemberFull", guild->getProp(GUILD_PROP_LEVEL), guild->getMemberCount());
			is_full = lua::getboolean(1);
			//检查人员已满 就删除贡献度最低的那位
			if (is_full)
			{
				std::vector<GuildMember *> &members = guild->getMembers();
				size_t count = members.size();
				GuildMember* litterConMem = nullptr;
				for (size_t i = 0; i < count; ++i)
				{
					GuildMember *member = members[i];
					if( member->player_id == other_player_id ) continue;
					if (litterConMem == nullptr)
					{
						litterConMem = member;
					}
					else if(member->contribution < litterConMem->contribution)
					{
						litterConMem = member;
					}
				}
			
				if(litterConMem)
				{
					GuildMember* master = guild->getMasterMember();
					if(!master)return SUCCESS;
					int pid = litterConMem->player_id;
					int ret = GuildHelper::kickPlayer(*master->player, pid);

					if (ret == SUCCESS)
					{
						Entity *other = g_world_player_mgr.getPlayerByPlayerID(pid);
						if (other != nullptr)
						{
							if(other->getProp(ENTITY_PROP_ATTACK_MODE) == ATTACK_MODE_GUILD)
							{
								lua::call(lua::L, "Entity.setAttackMode", other, ATTACK_MODE_PEACE);
							}
						}
					}
				}
			}
		}
		return SUCCESS;
	}

	//拒绝所有加入行会申请
	int refuseAllApplication(EntityPlayer &player)
	{
		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		int post = player.getProp(ENTITY_PROP_GUILD_POST);

		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (post == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		guild->clearApplication();

		return SUCCESS;
	}

	//通过所有加入行会申请
	int passAllApplication(EntityPlayer &player)
	{
		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		int post = player.getProp(ENTITY_PROP_GUILD_POST);

		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (post == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		std::vector<GuildApp*> apps = guild->getApplications();
		for (size_t i = 0; i < apps.size(); ++i)
		{
			GuildApp *app = apps[i];

			int ret = GuildHelper::decideApplication(player, GUILD_APP_ACCEPT, app->player_id);
			if (ret != SUCCESS)
			{
				return ret;
			}
		}

		return SUCCESS;
	}

	void autoChangeMaste()
	{
		if (lua::call(lua::L, "Event.isGuildActivityTime"))
		{
			bool ret = lua::getboolean(1);
			if (!ret)
			{
				return;
			}
		}
		

		int logout_time = 72 * 3600;
		std::vector<Guild *> &guilds = g_guild_mgr.getGuilds();
		size_t guild_count = guilds.size();
		for (size_t i = 0; i < guild_count; ++i)
		{
			Guild *guild = guilds[i];
			int diffTIme =  get_time() - guild->getProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME);
			if (diffTIme < logout_time)
			{
				continue;
			}

			std::vector<GuildMember*> lastMember;
			std::vector<GuildMember*> &members = guild->getMembers();
			for (size_t i = 0; i < members.size(); ++i)
			{
				GuildMember *member = members[i];
				if(member)
				{
					int offTime = member->offTime;
					int playerDiffTime = get_time() - offTime;
					if (member == nullptr || member->player_id == guild->getProp(GUILD_PROP_MASTER_ID) || playerDiffTime > logout_time)
					{
						continue;
					}

					lastMember.push_back(member);
				}
			}

			std::sort(lastMember.begin(), lastMember.end(), [](const GuildMember *m1, const GuildMember *m2)->bool
			{
				if(m1->post != m2->post)
				{
					return m1->post > m2->post;
				}
				else if(m1->contribution != m2->contribution)
				{
					return m1->contribution > m2->contribution;
				}
				else
				{
					return m1->force > m2->force;
				}
			});	

			if (lastMember.size() <= 0)
			{
				continue;
			}
			const  GuildMember* member = lastMember.front();
			if(member== nullptr)
			{
				continue;
			}

			 GuildHelper::changeMaster(*guild,member->player_id);
			 guild->setProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME,get_time());
			 GuildHelper::saveProp(*guild,GUILD_PROP_MASTER_LAST_LOGOUT_TIME);
			 GuildHelper::syncProp(*guild,GUILD_PROP_MASTER_LAST_LOGOUT_TIME);

		}

	}

	//退出行会
	int leaveGuild(EntityPlayer &player)
	{
		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}
		if (guild->getMemberCount() == 1)
		{
			//行会解散日志
			lua::call(lua::L, "Guild.leaveGuildProTechnologyAttrRemove",&player);
			releaseGuild(guild->getGuildID(), GUILD_REASON_MASTER_LEAVE, player.getGlobalID(), player.getName());
			return SUCCESS;
		}

		if (guild->getProp(GUILD_PROP_MASTER_ID) == player.getPlayerID())
		{
			//会长退出 找最合适的继承会长
			std::vector<GuildMember*> lastMember;
			std::vector<GuildMember*> &members = guild->getMembers();
			for (size_t i = 0; i < members.size(); ++i)
			{
				GuildMember *member = members[i];
				if (member == nullptr || member->player_id == guild->getProp(GUILD_PROP_MASTER_ID))
				{
					continue;
				}

				lastMember.push_back(member);
			}

			std::sort(lastMember.begin(), lastMember.end(), [](const GuildMember *m1, const GuildMember *m2)->bool
			{
				if(m1->post != m2->post)
				{
					return m1->post > m2->post;
				}
				else if(m1->contribution != m2->contribution)
				{
					return m1->contribution > m2->contribution;
				}
				else
				{
					return m1->force > m2->force;
				}
			});	

			if (lastMember.size() <= 0)
			{
				return ERROR_GUILD_NO_GUILD;
			}
			const  GuildMember* member = lastMember.front();
			if(member== nullptr)
			{
				return ERROR_GUILD_NO_GUILD;
			}
			MsgGuildMasterResetResponse *response = new MsgGuildMasterResetResponse;
			response->setSessionID(player.getSessionID());
			response->oldpid = player.getGlobalID();
			response->newpid = member->player_id;
			response->errcode = ERROR_UNKNOWN;

			response->errcode = GuildHelper::resetGuildMaster(*guild, player.getGlobalID(), member->player_id);
			g_app.postToNetService(response);
			if (response->errcode != SUCCESS)
			{
				return response->errcode;
			}
		}
		//离开公会科技属性加成去除
		lua::call(lua::L, "Guild.leaveGuildProTechnologyAttrRemove",&player);
		GuildHelper::exitGuildTeam(&player, guild);

		player.setProp(ENTITY_PROP_GUILD_TEAM_ID, 0);

		player.setProp(ENTITY_PROP_GUILD_ID, 0);
		player.setProp(ENTITY_PROP_GUILD_POST, 0);
		EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_GUILD_POST);
		player.setPropString(ENTITY_PROP_GUILD_NAME, "");
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_ID);

		if(player.getProp(ENTITY_PROP_ATTACK_MODE) == ATTACK_MODE_GUILD)
		{
			lua::call(lua::L, "Entity.setAttackMode", &player, ATTACK_MODE_PEACE);
		}
		syncMeetGuildName(player);
		// 记录退会时间
		player.setProp(ENTITY_PROP_LEAVE_GUILD_TIME, get_time());
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_LEAVE_GUILD_TIME);
		EntityOperationHelper::saveEntityProp(player, ENTITY_PROP_LEAVE_GUILD_TIME);

		//清除工会宣战
		player.setProp(ENTITY_PROP_DECLARE_GUILD_ID, 0);
		EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_DECLARE_GUILD_ID);
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_DECLARE_GUILD_ID);

		guild->removeMember(player.getPlayerID());
		syncMemberChange(*guild, player.getPlayerID());

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_MEMBER_LEAVE, 0, 0, player.getName(), "");
		//退出行会日志
		OperationHelper::recordGuildOp(*guild, player.getPlayerID(), player.getName(), 0, "", OP_GUILD_LEAVE);

		return SUCCESS;
	}

	//踢除行会成员
	int kickPlayer(EntityPlayer &player, int player_id)
	{
		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		if (player.getPlayerID() == player_id)
		{
			return ERROR_GUILD_KICK_SELF;
		}

		// 不能踢会长
		if (guild->getProp(GUILD_PROP_MASTER_ID) == player_id)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		GuildMember *gmember = guild->getMember(player.getPlayerID());
		if (gmember == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		//只有会长和副会长有权限
		int post = player.getProp(ENTITY_PROP_GUILD_POST);
		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (post == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		GuildMember* bekicker = guild->getMember(player_id);
		if (bekicker == NULL)
		{
			//被踢的不是本行会成员
			return ERROR_GUILD_INVALID_MEMBER;
		}

		// 副会长不能踢副会长
		if (post == bekicker->post)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		// 不能踢弹劾发起人
		int impeach_pid = guild->getProp(GUILD_PROP_IMPEACH_PID);
		if (impeach_pid > 0)
		{
			if (player_id == impeach_pid)
			{
				return ERROR_GUILD_PROSECUTOR_CANNOT_BE_KICKED;
			}
		}

		Entity *other = bekicker->player;

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_KICK_MEMBER, 0, 0, bekicker->player_name, player.getName());

		//行会踢人日志
		OperationHelper::recordGuildOp(*guild, player.getPlayerID(), player.getName(), bekicker->player_id, bekicker->player_name, OP_GUILD_KICKOUT);

		if (other)
		{
			GuildHelper::exitGuildTeam(other, guild);

			//清邀请信息
			//离开公会科技属性加成去除
			lua::call(lua::L, "Guild.leaveGuildProTechnologyAttrRemove",bekicker->player);
			other->setPropString(ENTITY_STRPROP_GUILD_INVITE_DATA,"");
			EntityOperationHelper::syncEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);
			EntityOperationHelper::saveEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);
			other->setProp(ENTITY_PROP_GUILD_ID, 0);
			other->setPropString(ENTITY_PROP_GUILD_NAME, "");
			other->setProp(ENTITY_PROP_GUILD_POST, 0);
			EntityOperationHelper::saveEntityProp(*other,ENTITY_PROP_GUILD_POST);
			other->setProp(ENTITY_PROP_GUILD_TEAM_ID, 0);
			EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_GUILD_ID);

			//清除工会宣战
			other->setProp(ENTITY_PROP_DECLARE_GUILD_ID, 0);
			EntityOperationHelper::saveEntityProp(*other,ENTITY_PROP_DECLARE_GUILD_ID);
			EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_DECLARE_GUILD_ID);

			//退会不清理

			lua::call(lua::L, "Guild.syncGuildKick", other);

			syncMeetGuildName(*other);

			Scene *scene = other->getScene();

			if ((scene != nullptr) && ((scene->getProp(SCENE_PROP_OWNER_GUILD_ID) > 0) || (scene->getStaticID() == 201)))
			{
				int old_scene_id = other->getProp(ENTITY_PROP_OLD_MAPID);
				int old_posx = other->getProp(ENTITY_PROP_OLD_X);
				int old_posy = other->getProp(ENTITY_PROP_OLD_Y);
				if (old_scene_id <= 0 || old_posx <= 0 || old_posy <= 0)
				{
					SceneOperationHelper::conveyEntityToScene(*other, 42);
				}
				else
				{
					SceneOperationHelper::enterScene(g_scene_mgr, *other, old_scene_id, old_posx, old_posy);
				}
			}
			// 记录退会时间
			other->setProp(ENTITY_PROP_LEAVE_GUILD_TIME, get_time());
			EntityOperationHelper::syncEntityProp(*other, ENTITY_PROP_LEAVE_GUILD_TIME);
			EntityOperationHelper::saveEntityProp(*other, ENTITY_PROP_LEAVE_GUILD_TIME);
		}
		else
		{
			// 记录离线玩家退会时间
			EntityOperationHelper::saveEntityProp(player_id, ENTITY_PROP_LEAVE_GUILD_TIME, get_time());
		}

		guild->removeMember(player_id);
		syncMemberChange(*guild, player_id);

		return SUCCESS;
	}

	//增加行会成员
	void addGuildMember(Guild &guild, int player_id, int reborn, int level, int job, int gender, const std::string &name, int sponsorGrade)
	{
		GuildMember gmember;
		gmember.player_name = name;
		gmember.player_id = player_id;
		gmember.level = level;
		gmember.player = NULL;
		gmember.gender = gender;
		gmember.intime = get_time();
		gmember.reborn = reborn;
		gmember.sponsorGrade = sponsorGrade;
		gmember.job = job;
		Entity* player = g_world_player_mgr.getPlayerByPlayerID(player_id);
		if (player)
		{
			player->setProp(ENTITY_PROP_GUILD_POST, 0);
			EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_GUILD_POST);

			//清邀请信息
			player->setPropString(ENTITY_STRPROP_GUILD_INVITE_DATA,"");
			EntityOperationHelper::syncEntityStringProp(*player, ENTITY_STRPROP_GUILD_INVITE_DATA);
			EntityOperationHelper::saveEntityStringProp(*player, ENTITY_STRPROP_GUILD_INVITE_DATA);

			//同步工会宣战
			player->setProp(ENTITY_PROP_DECLARE_GUILD_ID, guild.getProp(GUILD_PROP_DECLARE_WAR_GUILD));
			EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_DECLARE_GUILD_ID);
			EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_DECLARE_GUILD_ID);
		}

		guild.addMember(gmember);
	}

	void syncGuildAllInfo(EntityPlayer &player)
	{
		std::vector<Guild *> &guilds = g_guild_mgr.getGuilds();
		size_t guild_count = guilds.size();
		for (size_t i = 0; i < guild_count; ++i)
		{
			Guild *guild = guilds[i];
			if (guild->getMember(player.getPlayerID()))
			{
				if (player.getProp(ENTITY_PROP_GUILD_ID) != guild->getGuildID())
				{
					EntityOperationHelper::saveEntityGuildID(player, guild->getGuildID());
				}
			}
		}

		syncGuildVersion(player);

		if (g_config.isCrossServer())
		{
			GuildHelper::syncGuildList(player);
		}

		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			if (guild_id > 0)
			{
				MsgDBGuildMemberDelete *dbmsg = new MsgDBGuildMemberDelete;
				dbmsg->guildid = guild_id;
				dbmsg->pid = player.getPlayerID();
				g_app.postToNetService(dbmsg);
			}

			player.setProp(ENTITY_PROP_GUILD_ID, 0);
			player.setProp(ENTITY_PROP_GUILD_POST, 0);
			EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_GUILD_POST);
			player.setPropString(ENTITY_PROP_GUILD_NAME, "");
			EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_ID);
			player.setProp(ENTITY_PROP_GUILD_TEAM_ID, 0);
			return;
		}

		GuildMember* member = guild->getMember(player.getPlayerID());
		if (member == nullptr)
		{
			LOG_ERROR("Guild Player Login not find in my Guild pid = %d, gid = %d",player.getPlayerID(),guild->getGuildID());

			MsgDBGuildMemberDelete *dbmsg = new MsgDBGuildMemberDelete;
			dbmsg->guildid = guild_id;
			dbmsg->pid = player.getPlayerID();
			g_app.postToNetService(dbmsg);

			player.setProp(ENTITY_PROP_GUILD_ID, 0);
			player.setProp(ENTITY_PROP_GUILD_POST, 0);
			EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_GUILD_POST);
			player.setPropString(ENTITY_PROP_GUILD_NAME, "");
			player.setProp(ENTITY_PROP_GUILD_TEAM_ID, 0);

			//清邀请信息
			player.setPropString(ENTITY_STRPROP_GUILD_INVITE_DATA,"");
			EntityOperationHelper::syncEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);
			EntityOperationHelper::saveEntityStringProp(player, ENTITY_STRPROP_GUILD_INVITE_DATA);

			player.setPropString(ENTITY_STRPROP_GUILD_MERGE_DATA,"");
			EntityOperationHelper::syncEntityStringProp(player, ENTITY_STRPROP_GUILD_MERGE_DATA);
			EntityOperationHelper::saveEntityStringProp(player, ENTITY_STRPROP_GUILD_MERGE_DATA);
			
			syncMemberChange(*guild, player.getPlayerID());
			return;
		}
	
		member->player = &player;
		player.setProp(ENTITY_PROP_GUILD_POST, member->post);
		if (guild->getProp(GUILD_PROP_MASTER_ID) == player.getPlayerID())
		{
			player.setProp(ENTITY_PROP_GUILD_POST, GUILD_POST_MASTER);
			member->post = GUILD_POST_MASTER;
		}

		GuildHelper::syncProp(*guild, GUILD_PROP_DECLARE_WAR_GUILD);
		GuildHelper::syncProp(*guild, GUILD_PROP_DECLARE_WAR_OVER_TIME);
		GuildHelper::syncProp(*guild, GUILD_PROP_DECLARE_WAR_TIMES);

		EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_GUILD_POST);
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_POST);
		player.setProp(ENTITY_PROP_DECLARE_GUILD_ID, guild->getProp(GUILD_PROP_DECLARE_WAR_GUILD));
		EntityOperationHelper::saveEntityProp(player,ENTITY_PROP_DECLARE_GUILD_ID);
		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_DECLARE_GUILD_ID);
		EntityOperationHelper::syncEntityEventData(player, EVENT_GUILDREWARD);
		EntityOperationHelper::syncEntityEventData(player, EVENT_GUILDPRAY);
		EntityOperationHelper::syncEntityEventData(player, EVENT_GUILDEXPLORE);
		EntityOperationHelper::syncEntityEventData(player, EVENT_GUILDWELFARE);
		EntityOperationHelper::syncEntityEventData(player, EVENT_GUILDREWARD);

		lua::call(lua::L, "Guild.PlayerLogin", member->player, guild);

		syncMyGuildInfo(player);

		//同步公会成员
		MsgGuildMemberInfoNotify *member_notify = new MsgGuildMemberInfoNotify;
		member_notify->guildid = guild->getGuildID();
		GuildMemberInfo member_info;
		std::vector<GuildMember *> &members = guild->getMembers();
		size_t member_count = members.size();
		for (size_t i = 0; i < member_count; ++i)
		{
			GuildMember *member = members[i];
			initMemberMsgInfo(member, &member_info);
			member_notify->members.push_back(member_info);
		}
		player.sendMessage(member_notify);

		//长老级别显示加入行会人员列表  ---策划目前改成只有会长、副会长才可以同意申请
		if (member->post >= GUILD_POST_SECOND_MASTER)
		{
			MsgGuildApplicationInfoNotify *app_notify = new MsgGuildApplicationInfoNotify;
			GuildApplicationInfo app_info;
			std::vector<GuildApp *> &apps = guild->getApplications();
			size_t app_count = apps.size();
			for (size_t i = 0; i < app_count; ++i)
			{
				GuildApp *app = apps[i];
				app_info.pid = app->player_id;
				app_info.name = app->player_name;
				app_info.lvl = app->level;
				app_info.gender = app->gender;
				app_info.force = app->force;
				app_info.apptime = app->apptime;
				app_info.job = app->job;
				app_notify->apps.push_back(app_info);
			}
			player.sendMessage(app_notify);
		}

		MsgSyncGuildExStringDataNotify* publicnotice = new MsgSyncGuildExStringDataNotify;
		publicnotice->idx = GUILD_PROP_PUBLIC_NOTICE;
		publicnotice->data = guild->getStringProp(GUILD_PROP_PUBLIC_NOTICE);
		player.sendMessage(publicnotice);

		MsgSyncGuildExStringDataNotify* privatenotice = new MsgSyncGuildExStringDataNotify;
		privatenotice->idx = GUILD_PROP_PRIVATE_NOTICE;
		privatenotice->data = guild->getStringProp(GUILD_PROP_PRIVATE_NOTICE);
		player.sendMessage(privatenotice);


		GuildHelper::syncProp(*guild, GUILD_PROP_MONEY);

		guild->setProp(GUILD_PROP_LAST_LOGIN_TIME, get_time());
		saveProp(*guild, GUILD_PROP_LAST_LOGIN_TIME);

		// 自动审批，创建即生效
		GuildHelper::saveProp(*guild, GUILD_PROP_AUTOADD_LEVEL);
		GuildHelper::syncProp(*guild, GUILD_PROP_AUTOADD_LEVEL);

		//行会事件
		const std::vector<GuildRecord> &records = guild->getRecords();
		if (records.size() > 0)
		{
			MsgGuildRecordsNotify *notify = new MsgGuildRecordsNotify;
			notify->setSessionID(player.getSessionID());
			for (size_t i = 0; i < records.size(); ++i)
			{
				notify->records.push_back(records[i]);
			}
			player.sendMessage(notify);
		}

		//行会红包
		std::vector<GuildRed> rect_reds;   //取最近的50条红包数据
		const std::vector<GuildRed> &reds = guild->getReds();
		if (reds.size() >= 0)
		{
			MsgGuildRedsNotify *notify = new MsgGuildRedsNotify;
			notify->setSessionID(player.getSessionID());
			int start_index = (int)(reds.size() > 50 ? reds.size() - 50 : 0);  //最多取50个红包
			for (int i = start_index; i < reds.size(); ++i)
			{
				if (reds[i].createtime + 24 * 3600 > time(nullptr))
				{
					rect_reds.push_back(reds[i]);
					notify->reds.push_back(reds[i]);
				}
			}
			
			player.sendMessage(notify);
		}

		//行会红包日志
		const std::vector<GuildRedRecord> &redRecords = guild->getRedRecords();
		if (redRecords.size() >= 0 && rect_reds.size() >= 0)
		{
			MsgGuildRedRecordsNotify *notify = new MsgGuildRedRecordsNotify;
			notify->setSessionID(player.getSessionID());

			for (size_t i = 0; i < rect_reds.size(); ++i)
			{
				for (size_t j = 0; j < redRecords.size(); ++j)
				{
					if (rect_reds[i].id == redRecords[j].redid)
					{
						notify->GuildRedRecords.push_back(redRecords[j]);
					}
				}
			}

			player.sendMessage(notify);
		}

		EntityOperationHelper::syncEntityProp(player, ENTITY_PROP_GUILD_ID);
		// 同步鬼市
		GuildHelper::syscGuildGuishiToPlayer(player);
	}

	void syncMyGuildInfo(EntityPlayer &player)
	{
		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return;
		}

		Entity *master = g_world_player_mgr.getPlayerByPlayerID(guild->getProp(GUILD_PROP_MASTER_ID));
		GuildMember* member = guild->getMember(player.getGlobalID());
		MsgMyGuildInfoNotify* notify = new MsgMyGuildInfoNotify;
		notify->GuildID = guild->getGuildID();
		notify->GuildName = guild->getGuildName();
		notify->inTime = member->intime;
		notify->level = guild->getProp(GUILD_PROP_LEVEL);
		notify->MasterName = guild->getStringProp(GUILD_PROP_MASTER_NAME);
		notify->MemberCount = guild->getMemberCount();
		notify->myGuildmoney = guild->getProp(GUILD_PROP_MONEY);
		notify->myGuildFCDCLevel = guild->getProp(GUILD_PROP_FCDC_LEVEL);// 风驰电掣
		notify->myGuildSNLBLevel = guild->getProp(GUILD_PROP_SNLB_LEVEL);// 势若奔雷
		notify->myGuildJRBBLevel = guild->getProp(GUILD_PROP_JRBB_LEVEL);// 坚忍不拔
		notify->myGuildGRJTLevel = guild->getProp(GUILD_PROP_GRJT_LEVEL); // 固若金汤
		notify->myGuildLTWJLevel = guild->getProp(GUILD_PROP_LTWJ_LEVEL);// 雷霆万钧
		notify->myGuildKBYZLevel = guild->getProp(GUILD_PROP_KBYZ_LEVEL);// 狂暴意志
		notify->myGuildYNQLLevel = guild->getProp(GUILD_PROP_YNQL_LEVEL);// 一念千里
		notify->myGuildQZYBLevel = guild->getProp(GUILD_PROP_QZYB_LEVEL);// 奇珍异宝
		notify->myGuildRJDJLevel = guild->getProp(GUILD_PROP_RJDJ_LEVEL);// 日进斗金
		notify->myGuildFKDGLevel = guild->getProp(GUILD_PROP_FKDG_LEVEL);// 富可敌国
		notify->myGuildCBTXLevel = guild->getProp(GUILD_PROP_CBTX_LEVEL);// 吃遍天下
		notify->myGuildJSCDLevel = guild->getProp(GUILD_PROP_JSCD_LEVEL);// 积少成多
		notify->DonTodaymoney    = guild->getProp(GUILD_PROP_MONEY_TODAY_MONEY);//当日捐献获得资金
		notify->DonTodaytime     = guild->getProp(GUILD_PROP_MONEY_COUNT);//当日捐献次数
		
		player.sendMessage(notify);

	}

	void syncApplicationChange(Guild &guild, int pid)
	{
		GuildApp* gapp = guild.getApplication(pid);
		if (gapp)
		{
			// save and sync
			MsgGuildApplicationChangeNotify* notify = new MsgGuildApplicationChangeNotify;
			notify->app.pid = gapp->player_id;
			notify->app.name = gapp->player_name;
			notify->app.lvl = gapp->level;
			notify->app.gender = gapp->gender;
			notify->app.force = gapp->force;
			notify->app.apptime = gapp->apptime;
			notify->app.job = gapp->job;
			notify->reason = GUILD_REASON_ADD_APP;
			guild.sendMessageToManager(notify); //只向管理层发，普通成员不发
			// db update guild application data
			MsgDBGuildApplicationUpdate* dbmsg = new MsgDBGuildApplicationUpdate;
			dbmsg->gid = guild.getGuildID();
			dbmsg->pid = gapp->player_id;
			dbmsg->type = 0;
			g_app.postToNetService(dbmsg);
		}
		else
		{
			// save and sync
			MsgGuildApplicationChangeNotify* notify = new MsgGuildApplicationChangeNotify;
			notify->app.pid = pid;
			notify->reason = GUILD_REASON_DELETE_APP;
			guild.sendMessageToManager(notify); //只向管理层发，普通成员不发

			// db delete guild application data
			MsgDBGuildApplicationDelete* dbmsg = new MsgDBGuildApplicationDelete;
			dbmsg->gid = guild.getGuildID();
			dbmsg->pid = pid;
			g_app.postToNetService(dbmsg);
		}
	}

	void syncMemberChange(Guild &guild, int pid)
	{
		GuildMember* gmember = guild.getMember(pid);
		if (gmember)
		{
			// update Guild Member
			MsgDBGuildMemberUpdate* dbmsg = new MsgDBGuildMemberUpdate;
			dbmsg->guildid = guild.getGuildID();
			dbmsg->pid = gmember->player_id;
			dbmsg->post = gmember->post;
			dbmsg->speek = gmember->speek;
			g_app.postToNetService(dbmsg);
		}
		else
		{
			// save and sync
			MsgGuildMemberChangeNotify* notify = new MsgGuildMemberChangeNotify;
			notify->reason = GUILD_REASON_DELETE_MEMBER;
			notify->player.pid = pid;
			guild.sendMessage(notify);

			MsgDBGuildMemberDelete* dbmsg = new MsgDBGuildMemberDelete;
			dbmsg->guildid = guild.getGuildID();
			dbmsg->pid = pid;
			g_app.postToNetService(dbmsg);
		}
	}

	void syncGuildList(EntityPlayer &player)
	{
		Guild *player_guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));

		int guild_rank_size = g_guild_mgr.getGuildRankSize();

		const int num_per_page = 10;
		int guild_count = g_guild_mgr.getGuildCount();
		int maxpage = (guild_count > 0) ? ((guild_count - 1) / num_per_page + 1) : 0;

		for (int page = 1; page <= maxpage; ++page)
		{
			MsgGuildsInfoResponse *response = new MsgGuildsInfoResponse;

			response->errcode = SUCCESS;
			response->maxpage = maxpage;
			response->page = page;

			for (int i = (page - 1) * num_per_page; (i < page * num_per_page) && (i < guild_rank_size); i++)
			{
				Guild *guild = g_guild_mgr.getGuildByRank(i);
				if (guild == nullptr)
				{
					continue;
				}

				Entity *master = g_world_player_mgr.getPlayerByPlayerID(guild->getProp(GUILD_PROP_MASTER_ID));

				GuildInfo ginfo;
				ginfo.GuildID = guild->getGuildID();
				ginfo.GuildName = guild->getGuildName();
				ginfo.level = guild->getProp(GUILD_PROP_LEVEL);
				ginfo.MasterID = guild->getProp(GUILD_PROP_MASTER_ID);
				ginfo.MasterName = guild->getStringProp(GUILD_PROP_MASTER_NAME);
				ginfo.MasterOnline = ((master != nullptr) && (master->getProp(ENTITY_PROP_OFFLINE) == 0)) ? 1 : 0;
				ginfo.MemberCount = guild->getMemberCount();
				ginfo.rank = i + 1;
				ginfo.state = GUILD_STATE_NORMAL;
				ginfo.ctime = guild->getCreateTime();
				ginfo.combat = guild->getGuildCombat();
				ginfo.notice = guild->getStringProp(GUILD_PROP_PRIVATE_NOTICE);
				ginfo.declareguildid = guild->getProp(GUILD_PROP_DECLARE_WAR_GUILD);
				ginfo.declareovertime = guild->getProp(GUILD_PROP_DECLARE_WAR_OVER_TIME);
				
					//if(guild->getProp(GUILD_PROP_AUTOADD_LEVEL) == 0)
					//{
						ginfo.state = guild->getProp(GUILD_PROP_AUTOADD_LEVEL);// 需要审核 等级限制 
					//}
				if (player_guild == nullptr)
				{
					if (guild->getApplication(player.getPlayerID()))
					{
						ginfo.state += 20000;//已经申请了
					}
				}

				response->Guilds.push_back(ginfo);
			}

			player.sendMessage(response);
		}
	}

	// 变更会长
	int changeMaster(Guild &guild, int new_master_pid)
	{
		GuildMember *new_master_member = guild.getMember(new_master_pid);
		if (new_master_member == nullptr)
		{
			return ERROR_GUILD_NOT_THIS_MEMBER;
		}

		if (new_master_member->post == GUILD_POST_MASTER)
		{
			return ERROR_UNKNOWN;
		}

		GuildMember *old_master_member = nullptr;
		auto &members = guild.getMembers();
		for (size_t i = 0; i < members.size(); ++i)
		{
			GuildMember *member = members[i];
			if (member->post == GUILD_POST_MASTER)
			{
				old_master_member = member;
				break;
			}
		}

		if (nullptr == old_master_member) 
		{
			return ERROR_UNKNOWN;
		}
		old_master_member->post = GUILD_POST_NORMAL;
		new_master_member->post = GUILD_POST_MASTER;
		old_master_member->speek = 0;
		new_master_member->speek = 1;

		if (old_master_member->player)
		{
			EntityPlayer *old_master = old_master_member->player;
			old_master->setProp(ENTITY_PROP_GUILD_POST, old_master_member->post);
			EntityOperationHelper::syncEntityProp(*old_master, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*old_master,ENTITY_PROP_GUILD_POST);
		}

		if (new_master_member->player)
		{
			EntityPlayer *new_master = new_master_member->player;
			new_master->setProp(ENTITY_PROP_GUILD_POST, new_master_member->post);
			EntityOperationHelper::syncEntityProp(*new_master, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*new_master,ENTITY_PROP_GUILD_POST);
		}
		syncMemberChange(guild, old_master_member->player_id);
		syncMemberChange(guild, new_master_member->player_id);

		guild.setProp(GUILD_PROP_MASTER_ID, new_master_member->player_id);
		guild.setStringProp(GUILD_PROP_MASTER_NAME, new_master_member->player_name);
		syncProp(guild, GUILD_PROP_MASTER_ID);
		syncStringProps(guild, GUILD_PROP_MASTER_NAME);

		MsgDBGuildMasterUpdate *dbmsg = new MsgDBGuildMasterUpdate;
		dbmsg->guildid = guild.getGuildID();
		dbmsg->pid = new_master_member->player_id;
		g_app.postToNetService(dbmsg);

		lua::call(lua::L, "GCZ.onResetGuildMaster", &guild);

		//会长变更日志
		OperationHelper::recordGuildOp(guild, old_master_member->player_id, old_master_member->player_name, new_master_member->player_id, new_master_member->player_name, OP_GUILD_MASTER_CHANGE);

		return SUCCESS;
	}

	// 变更会长
	int gmChangeMaster(Guild &guild, int new_master_pid)
	{
		GuildMember *new_master_member = guild.getMember(new_master_pid);
		if (new_master_member == nullptr)
		{
			return ERROR_GUILD_NOT_THIS_MEMBER;
		}

		if (new_master_member->post == GUILD_POST_MASTER)
		{
			return ERROR_UNKNOWN;
		}
		// 之前会长先处理
		GuildMember *old_master_member = nullptr;
		auto &members = guild.getMembers();
		for (size_t i = 0; i < members.size(); ++i)
		{
			GuildMember *member = members[i];
			if (member->post == GUILD_POST_MASTER)
			{
				old_master_member = member;
				break;
			}
		}
		old_master_member->post = GUILD_POST_NORMAL;
		//new_master_member->post = GUILD_POST_MASTER;
		old_master_member->speek = 0;
		//new_master_member->speek = 1;

		if (old_master_member->player)
		{
			EntityPlayer *old_master = old_master_member->player;
			old_master->setProp(ENTITY_PROP_GUILD_POST, old_master_member->post);
			EntityOperationHelper::syncEntityProp(*old_master, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*old_master,ENTITY_PROP_GUILD_POST);
		}

		new_master_member->post = GUILD_POST_MASTER;
		new_master_member->speek = 1;


		if (new_master_member->player)
		{
			EntityPlayer *new_master = new_master_member->player;
			new_master->setProp(ENTITY_PROP_GUILD_POST, new_master_member->post);
			EntityOperationHelper::syncEntityProp(*new_master, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*new_master,ENTITY_PROP_GUILD_POST);
		}

		syncMemberChange(guild, old_master_member->player_id);
		syncMemberChange(guild, new_master_member->player_id);

		guild.setProp(GUILD_PROP_MASTER_ID, new_master_member->player_id);
		guild.setStringProp(GUILD_PROP_MASTER_NAME, new_master_member->player_name);
		syncProp(guild, GUILD_PROP_MASTER_ID);
		syncStringProps(guild, GUILD_PROP_MASTER_NAME);

		MsgDBGuildMasterUpdate *dbmsg = new MsgDBGuildMasterUpdate;
		dbmsg->guildid = guild.getGuildID();
		dbmsg->pid = new_master_member->player_id;
		g_app.postToNetService(dbmsg);

		// lua 
		lua::call(lua::L, "GCZ.onResetGuildMaster", &guild);

		//会长变更日志
		OperationHelper::recordGuildOp(guild, 88888, "xianfeng" , new_master_member->player_id, new_master_member->player_name, OP_GUILD_MASTER_CHANGE);

		return SUCCESS;
	}

	// 变更会长
	int resetGuildMaster(Guild &guild, int srcpid, int tgtpid)
	{
		GuildMember* srcmem = guild.getMember(srcpid);
		if (NULL == srcmem || srcmem->post != GUILD_POST_MASTER)
		{
			return ERROR_GUILD_NOT_MASTER;
		}

		GuildMember* tgtmem = guild.getMember(tgtpid);
		if (tgtmem == nullptr)
		{
			return ERROR_GUILD_INVALID_MEMBER;
		}
		
		srcmem->post = GUILD_POST_NORMAL;
		tgtmem->post = GUILD_POST_MASTER;

		if (srcmem->player)
		{
			EntityPlayer* srcplayer = srcmem->player;
			srcplayer->setProp(ENTITY_PROP_GUILD_POST,srcmem->post);
			EntityOperationHelper::syncEntityProp(*srcplayer, ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*srcplayer,ENTITY_PROP_GUILD_POST);

			srcplayer->setPropString(ENTITY_STRPROP_GUILD_MERGE_DATA, "");
			EntityOperationHelper::syncEntityStringProp(*srcplayer, ENTITY_STRPROP_GUILD_MERGE_DATA);
			EntityOperationHelper::saveEntityStringProp(*srcplayer, ENTITY_STRPROP_GUILD_MERGE_DATA);
		}

		if (tgtmem->player)
		{
			EntityPlayer* tgtplayer = tgtmem->player;
			tgtplayer->setProp(ENTITY_PROP_GUILD_POST,tgtmem->post);
			EntityOperationHelper::syncEntityProp(*tgtplayer,ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::saveEntityProp(*tgtplayer,ENTITY_PROP_GUILD_POST);
			tgtplayer->setPropString(ENTITY_STRPROP_GUILD_MERGE_DATA, "");
			EntityOperationHelper::syncEntityStringProp(*tgtplayer, ENTITY_STRPROP_GUILD_MERGE_DATA);
			EntityOperationHelper::saveEntityStringProp(*tgtplayer, ENTITY_STRPROP_GUILD_MERGE_DATA);
		}

		syncMemberChange(guild, srcpid);
		syncMemberChange(guild, tgtmem->player_id);
		
		//同步公会申请列表给新会长
		if (tgtmem->player)
		{
			//长老级别显示加入行会人员列表
			MsgGuildApplicationInfoNotify *app_notify = new MsgGuildApplicationInfoNotify;
			if (tgtmem->post > GUILD_POST_NORMAL)
			{
				GuildApplicationInfo app_info;
				std::vector<GuildApp *> &apps = guild.getApplications();
				size_t app_count = apps.size();
				for (size_t i = 0; i < app_count; ++i)
				{
					GuildApp *app = apps[i];

					app_info.pid = app->player_id;
					app_info.name = app->player_name;
					app_info.lvl = app->level;
					app_info.gender = app->gender;
					app_info.force = app->force;
					app_info.apptime = app->apptime;
					app_info.job = app->job;
					app_notify->apps.push_back(app_info);
				}
			}
			tgtmem->player->sendMessage(app_notify);
		}

		guild.setProp(GUILD_PROP_MASTER_ID, tgtmem->player_id);
		guild.setStringProp(GUILD_PROP_MASTER_NAME, tgtmem->player_name);
		syncProp(guild,GUILD_PROP_MASTER_ID);
		syncStringProps(guild,GUILD_PROP_MASTER_NAME);

		MsgDBGuildMasterUpdate* mau = new MsgDBGuildMasterUpdate;
		mau->guildid = guild.getGuildID();
		mau->pid = tgtmem->player_id;
		g_app.postToNetService(mau);
		if (srcmem->player && tgtmem->player)
		{
			lua::call(lua::L, "Guild.resetMasterMsg", &guild, srcmem->player->getName() , tgtmem->player->getName());
		}
		// lua 
		lua::call(lua::L, "GCZ.onResetGuildMaster", &guild);

		//行会事件
		GuildHelper::addRecord(&guild, GUILD_RECORD_MEMBER_POST_CHANGED, GUILD_POST_MASTER, 0, srcmem->player_name, tgtmem->player_name);

		//会长变更日志
		OperationHelper::recordGuildOp(guild, srcmem->player_id, srcmem->player_name, tgtmem->player_id, tgtmem->player_name, OP_GUILD_MASTER_CHANGE);

		return SUCCESS;
	}

	void syncStringProps(Guild &guild, int idx)
	{
		MsgSyncGuildExStringDataNotify *notify = new MsgSyncGuildExStringDataNotify;
		notify->idx = idx;
		notify->data = guild.getStringProp(idx);
		guild.sendMessage(notify);
	}

	void saveStringProps(Guild &guild, int idx)
	{
		if (idx == GUILD_PROP_PRIVATE_NOTICE)
		{
			MsgDBGuildPlacardUpdate* dbmsg = new MsgDBGuildPlacardUpdate;
			dbmsg->guildid = guild.getGuildID();
			dbmsg->placard = guild.getStringProp(idx);
			g_app.postToNetService(dbmsg);
		}
		else if (idx == GUILD_PROP_PUBLIC_NOTICE)
		{
			MsgDBGuildPublicnoticeUpdate* dbmsg = new MsgDBGuildPublicnoticeUpdate;
			dbmsg->guildid = guild.getGuildID();
			dbmsg->publicnotice = guild.getStringProp(idx);
			g_app.postToNetService(dbmsg);
		}
		//else
		//{
		//	MsgDBGuildUpdateNickname* dbmsg = new MsgDBGuildUpdateNickname;
		//	dbmsg->gid = guild.getGuildID();
		//	dbmsg->job = idx;
		//	dbmsg->name = guild.getStringProp(idx);
		//	g_app.postToDBService(dbmsg);
		//}
	}

	void syncMeetGuildName(Entity& entity)
	{
		std::string guild_name;

		if(g_config.isCrossServer())
		{
			guild_name = entity.getPropString(ENTITY_PROP_GUILD_NAME);
		}
		else
		{
			Guild *guild = g_guild_mgr.getGuildByID(entity.getProp(ENTITY_PROP_GUILD_ID));
			if (guild)
			{
				guild_name = guild->getGuildName();
			}
		}

		// 公会名字发送可见玩家
		Scene *scene = entity.getScene();
		if (scene)
		{
			MeetExStr str;
			str.type = ENTITY_PROP_GUILD_ID;
			str.data = guild_name;

			MsgMeetEntityExStrNotify *notify = new MsgMeetEntityExStrNotify;
			notify->eid = entity.getID();
			notify->exstr.push_back(str);
			scene->sendMessage(entity.getGridX(), entity.getGridY(), notify);
		}
		else
		{
			if(!g_config.isCrossServer() && !entity.isInGSMap())
			{
				MeetExStr str;
				str.type = ENTITY_PROP_GUILD_ID;
				str.data = guild_name;

				MsgMeetEntityExStrNotify *notify = new MsgMeetEntityExStrNotify;
				notify->eid = entity.getProp(ENTITY_PROP_EID_IN_CROSS_SERVER);
				notify->exstr.push_back(str);
				GSHelper::wrapSceneMessage(entity, notify);

				return;
			}
		}
	}

	//int prayGuanGong(EntityP &player, int type)
	//{
	//	Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	OperationHelper::setOpCode(OP_GUILD_PRAY);

	//	int ret = ERROR_SCRIPT;
	//	lua::call(lua::L, "Guild.praytoGuanGong", &player, guild, type);
	//	ret = lua::getinteger(1);
	//	return ret;
	//}

	//int addGuanGongCnt(EntityP &player)
	//{
	//	Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;;
	//	}

	//	OperationHelper::setOpCode(OP_GUILD_PRAY);

	//	int ret = ERROR_SCRIPT;
	//	lua::call(lua::L, "Guild.addGuanGongCnt", &player, guild);
	//	ret = lua::getinteger(1);
	//	return ret;
	//}

	//int getGuanGongReward(EntityP &player)
	//{
	//	Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	OperationHelper::setOpCode(OP_GUILD_PRAY);

	//	int ret = ERROR_SCRIPT;
	//	EntityLua::push(g_lua.state(), &player);
	//	GuildLua::push(g_lua.state(), guild);
	//	lua::call(lua::L, "Guild.getGuanGongReward", &player, guild);
	//	ret = lua::getinteger(1);
	//	return ret;
	//}

	//变更行会公告或行会宣言
	int changeGuildNotice(EntityPlayer &player, int idx, const std::string &str)
	{
		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		int post = player.getProp(ENTITY_PROP_GUILD_POST);
		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		if (str.empty())
		{
			return ERROR_GUILD_PLCARD_NULL;
		}

		int notice_len = utf8_to_unicode_len(str);
		if ((notice_len > GUILD_NOTICE_MAX))
		{
			return ERROR_GUILD_NAME_TOO_LONG;
		}

		if (str.length() > 200 * 3)
		{
			return ERROR_GUILD_NOTICE_TOO_LONG;
		}
//		int old_count = guild->getProp(GUILD_PROP_MONEY);
//		if (old_count < 1000)
//		{
//			return ERROR_GUILD_NOT_ENOUGH_MONEY;
//		}
//		guild->setProp(GUILD_PROP_MONEY,old_count-1000);
//	    GuildHelper::saveProp(*guild,GUILD_PROP_MONEY);
//		GuildHelper::syncProp(*guild,GUILD_PROP_MONEY);
		guild->setStringProp(idx, str);
		syncStringProps(*guild, idx);
		saveStringProps(*guild, idx);
		return SUCCESS;
	}



	// GM命令改变公会公告
	int changeNoticeByGM(int guildid, const std::string &str)
	{
		Guild *guild = g_guild_mgr.getGuildByID(guildid);
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		if (str.length() > 200 * 3)
		{
			return ERROR_GUILD_NOTICE_TOO_LONG;
		}

		guild->setStringProp(GUILD_PROP_PRIVATE_NOTICE, str);
		syncStringProps(*guild, GUILD_PROP_PRIVATE_NOTICE);
		saveStringProps(*guild, GUILD_PROP_PRIVATE_NOTICE);
		return SUCCESS;
	}



	//设置成员是否可以说话
	int setMemberGuildSpeek(EntityPlayer &player, int player_id, int speek)
	{
		int mypost = player.getProp(ENTITY_PROP_GUILD_POST);
		if (mypost != GUILD_POST_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (!guild)
		{
			return ERROR_NOT_IN_GUILD;
		}

		if (player.getPlayerID() == player_id)
		{
			return ERROR_GUILD_INVALID_NICKNAME;
		}

		GuildMember *other_member = guild->getMember(player_id);
		if (!other_member)
		{
			return ERROR_GUILD_NOT_THIS_MEMBER;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (mypost == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		if (speek >= 1)
		{
			if (guild->getMemberSpeekCount() >= 5)
			{
				return ERROR_GUILD_SPEEK_MAX;
			}

			speek = 1;
		}
		else
		{
			speek = 0;
		}

		other_member->speek = speek;

		lua::call(lua::L, "Guild.sendSpeekStateMsg", guild, other_member->player_name, speek);

		if (other_member->player)
		{
			other_member->player->setProp(ENTITY_PROP_GUILD_SPEEK, other_member->speek);
			EntityOperationHelper::syncEntityProp(*(other_member->player), ENTITY_PROP_GUILD_SPEEK);
		}

		syncMemberChange(*guild, player_id);

		return SUCCESS;
	}

	//设置成员职务
	int setMemberGuildPost(EntityPlayer &player, int player_id, int post)
	{
		int mypost = player.getProp(ENTITY_PROP_GUILD_POST);
		if (mypost != GUILD_POST_MASTER && mypost != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		// 副会长，没有权限设置副会长职务
		if (mypost == GUILD_POST_SECOND_MASTER && post == GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
		if (!guild)
		{
			return ERROR_NOT_IN_GUILD;
		}

		if (player.getPlayerID() == player_id)
		{
			return ERROR_GUILD_INVALID_NICKNAME;
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (mypost == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		GuildMember *other_member = guild->getMember(player_id);
		if (!other_member)
		{
			return ERROR_GUILD_NOT_THIS_MEMBER;
		}

		if (other_member->post == post)
		{
			return SUCCESS;
		}

		if (other_member->post >= mypost)
		{
			return ERROR_GUILD_AUTHORITY;
		}

		if (post == GUILD_POST_MASTER || post < GUILD_POST_BEGIN || post >= GUILD_POST_END)
		{
			return ERROR_GUILD_INVALID_NICKNAME;
		}

		lua::call(lua::L, "Guild.getPostNum",  guild->getProp(GUILD_PROP_LEVEL),post);
		int num = lua::getinteger(1);
		if (num > 0)
		{
			int post_count = guild->getMemberCountByPost(post);
			if (post_count >= num)
			{
				return ERROR_GUILD_INVALID_NICKNAME;
			}
		}

		if (other_member->post < post)
		{
			other_member->post = post;
			lua::call(lua::L, "Guild.sendLevelUpPosMsg", guild, player.getName(), other_member->player_name, post);

			//行会事件
			GuildHelper::addRecord(guild, GUILD_RECORD_MEMBER_POST_CHANGED, post, 0, player.getName(), other_member->player_name);
		}
		else
		{
			other_member->post = post;
			lua::call(lua::L, "Guild.sendLevelDownPosMsg", guild, player.getName(), other_member->player_name, post);

			//行会事件
			GuildHelper::addRecord(guild, GUILD_RECORD_MEMBER_POST_CHANGED, post, 0, player.getName(), other_member->player_name);
		}

		if (other_member->player)
		{
			other_member->player->setProp(ENTITY_PROP_GUILD_POST, other_member->post);
			//LOG_INFO(" ck============>>>   11 setMemberGuildPost player_name = %s, member_post = %d ", other_member->player->getName().c_str(),other_member->post);
			EntityOperationHelper::saveEntityProp(*(other_member->player),ENTITY_PROP_GUILD_POST);
			EntityOperationHelper::syncEntityProp(*(other_member->player), ENTITY_PROP_GUILD_POST);
			
			//长老级别显示加入行会人员列表
			MsgGuildApplicationInfoNotify *app_notify = new MsgGuildApplicationInfoNotify;
			if (other_member->post > GUILD_POST_NORMAL)
			{
				GuildApplicationInfo app_info;
				std::vector<GuildApp *> &apps = guild->getApplications();
				size_t app_count = apps.size();
				for (size_t i = 0; i < app_count; ++i)
				{
					GuildApp *app = apps[i];

					app_info.pid = app->player_id;
					app_info.name = app->player_name;
					app_info.lvl = app->level;
					app_info.gender = app->gender;
					app_info.force = app->force;
					app_info.apptime = app->apptime;
					app_info.job = app->job;
					app_notify->apps.push_back(app_info);
				}
			}
			other_member->player->sendMessage(app_notify);
		}

		syncMemberChange(*guild, player_id);

		return SUCCESS;
	}

	void syncGuildVersion(Entity &entity)
	{
		g_guild_mgr.syncGuildVersion(&entity);
	}

	//删除行会
	void releaseGuild(int guild_id, int reason, int pid, const std::string &pname)
	{
		Guild *guild = g_guild_mgr.rmvGuild(guild_id);
		if (guild == NULL)
		{
			return;
		}
		OperationHelper::recordGuildOp(*guild, pid, pname, 0, "", OP_GUILD_DISMISS, reason);

		std::vector<GuildMember *> &mebers = guild->getMembers();
		size_t count = mebers.size();
		for (size_t i = 0; i < count; ++i)
		{
			GuildMember *member = mebers[i];
			EntityPlayer *entity = member->player;
			if (entity == NULL)
			{
				EntityOperationHelper::saveEntityProp(member->player_id, ENTITY_PROP_LEAVE_GUILD_TIME, get_time());
				continue;
			}
			GuildHelper::exitGuildTeam(entity, guild);
			entity->setProp(ENTITY_PROP_GUILD_ID, 0);
			entity->setPropString(ENTITY_PROP_GUILD_NAME, "");
			EntityOperationHelper::syncEntityProp(*entity, ENTITY_PROP_GUILD_ID);
			if(entity->getProp(ENTITY_PROP_ATTACK_MODE) == ATTACK_MODE_GUILD)
			{
				lua::call(lua::L, "Entity.setAttackMode", entity, ATTACK_MODE_PEACE);
			}
			syncMeetGuildName(*entity);
			entity->setProp(ENTITY_PROP_LEAVE_GUILD_TIME, get_time());
			EntityOperationHelper::saveEntityProp(*entity, ENTITY_PROP_LEAVE_GUILD_TIME);
			EntityOperationHelper::syncEntityProp(*entity, ENTITY_PROP_LEAVE_GUILD_TIME);
			entity->setProp(ENTITY_PROP_GUILD_POST, 0);
			EntityOperationHelper::saveEntityProp(*entity,ENTITY_PROP_GUILD_POST);

			//清除工会宣战
			entity->setProp(ENTITY_PROP_DECLARE_GUILD_ID, 0);
			EntityOperationHelper::saveEntityProp(*entity, ENTITY_PROP_DECLARE_GUILD_ID);
			EntityOperationHelper::syncEntityProp(*entity, ENTITY_PROP_DECLARE_GUILD_ID);
			//清邀请信息
			entity->setPropString(ENTITY_STRPROP_GUILD_INVITE_DATA,"");
			EntityOperationHelper::saveEntityStringProp(*entity, ENTITY_STRPROP_GUILD_INVITE_DATA);
			EntityOperationHelper::syncEntityStringProp(*entity, ENTITY_STRPROP_GUILD_INVITE_DATA);
			entity->setPropString(ENTITY_STRPROP_GUILD_MERGE_DATA,"");
			EntityOperationHelper::syncEntityStringProp(*entity, ENTITY_STRPROP_GUILD_MERGE_DATA);
			EntityOperationHelper::saveEntityStringProp(*entity, ENTITY_STRPROP_GUILD_MERGE_DATA);
		}

	    GuildHelper::backRed(guild, true);
		guild->CheckRed();
		lua::call(lua::L, "Guild.onRelease", guild);
		MsgDBGuildDelete *dbmsg = new MsgDBGuildDelete;
		dbmsg->guildid = guild_id;
		g_app.postToNetService(dbmsg);
		delete guild;	
	}

	int checkGuildIngot(Entity &entity, int ingot)
	{
		Guild *guild = g_guild_mgr.getGuildByID(entity.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		int count = guild->getProp(GUILD_PROP_INGOT) + ingot;

		if (ingot < 0)
		{
			return (ingot > 0) ? ERROR_GUILD_MONEY_LIMITED : ERROR_NOT_ENOUGH_INGOT;
		}

		return SUCCESS;
	}

	int addGuildIngot(Entity &entity, int ingot)
	{
		Guild *guild = g_guild_mgr.getGuildByID(entity.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		int old_count = guild->getProp(GUILD_PROP_INGOT);
		int new_count = old_count + ingot;
		if (new_count < 0)
		{
			return (ingot > 0) ? ERROR_GUILD_MONEY_LIMITED : ERROR_NOT_ENOUGH_INGOT;
		}

		guild->setProp(GUILD_PROP_INGOT, new_count);
		saveProp(*guild, GUILD_PROP_INGOT);
		syncProp(*guild, GUILD_PROP_INGOT);

		OperationHelper::recordGuildMoneyOp(*guild, &entity, old_count, ingot, OP_GUILD_DONATE_INGOT);

		return SUCCESS;
	}

	//增加(或减少)行会贡献
	int addGuildContribution(Entity &entity, int contribution, int opcode, int opdata)
	{
		Guild *guild = g_guild_mgr.getGuildByID(entity.getProp(ENTITY_PROP_GUILD_ID));
		if (guild == NULL)
		{
			return ERROR_NOT_IN_GUILD;
		}

		int old_contribution = entity.getProp(ENTITY_PROP_GUILD_CONTRIBUTION);
		int new_contribution = old_contribution + contribution;
		if (new_contribution < 0)
		{
			return ERROR_GUILD_NOT_ENOUGH_CONTRIBUTION;
		}

		entity.setProp(ENTITY_PROP_GUILD_CONTRIBUTION, new_contribution);
		EntityOperationHelper::saveEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION);
		EntityOperationHelper::syncEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION);

		if (contribution > 0 && opcode != OP_GUILD_RESET_SKILL)
		{
			//当日贡献
			int old_contributionToday = entity.getProp(ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);
			int new_contributionToday = old_contributionToday + contribution;

			entity.setProp(ENTITY_PROP_GUILD_CONTRIBUTION_TODAY, new_contributionToday);
			EntityOperationHelper::saveEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);
			EntityOperationHelper::syncEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);
		}

		//行会贡献日志
		OperationHelper::recordContributionOp(entity, old_contribution, contribution, opcode, opdata);

		GuildMember* guildmember = guild->getMember(entity.getGlobalID());
		if (guildmember)
		{
			guildmember->contribution = new_contribution;
			guildmember->contribution_today = entity.getProp(ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);
		}

		// TODO change it to a new message
		syncMemberChange(*guild, entity.getGlobalID());

		return SUCCESS;
	}
    //重置当天的行会贡献
	int resetTodayContribution(Entity &entity)
	{
		entity.setProp(ENTITY_PROP_GUILD_CONTRIBUTION_TODAY, 0);
		EntityOperationHelper::saveEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);
		EntityOperationHelper::syncEntityProp(entity, ENTITY_PROP_GUILD_CONTRIBUTION_TODAY);

		Guild *guild = g_guild_mgr.getGuildByID(entity.getProp(ENTITY_PROP_GUILD_ID));
		if (guild != NULL)
		{
			GuildMember* guildmember = guild->getMember(entity.getGlobalID());
			if (guildmember)
			{
				guildmember->contribution_today = 0;
			}
			syncMemberChange(*guild, entity.getGlobalID());
		}
		return SUCCESS;
	}

	//int initExplore(EntityPlayer &player, std::vector<int> &items)
	//{
	//	int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
	//	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	lua::call(lua::L, "Guild.init_explore", &player);
	//	items = lua::getvector(1);
	//	if (items.size() == 0)
	//	{
	//		return ERROR_SCRIPT;
	//	}

	//	return SUCCESS;
	//}

	//int explore(EntityPlayer &player, int &item_id)
	//{
	//	int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
	//	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	lua::call(lua::L, "Guild.explore", guild, &player);

	//	int ret = ERROR_SCRIPT;
	//	ret = lua::getinteger(1);
	//	item_id = lua::getinteger(2);
	//	return ret;
	//}

	//int getWelfareStatus(EntityPlayer &player, int &welfare_status)
	//{
	//	int guildID = player.getProp(ENTITY_PROP_GUILD_ID);
	//	Guild *guild = g_guild_mgr.getGuildByID(guildID);
	//	if (guild == NULL)
	//		return ERROR_NOT_IN_GUILD;

	//	lua::call(lua::L, "Guild.get_welfare_status", guild);
	//	welfare_status = lua::getinteger(1);
	//	return SUCCESS;
	//}

	//int openWelfare(EntityPlayer &player, int welfare_id)
	//{
	//	int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
	//	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	lua::call(lua::L, "Guild.open_welfare", guild, &player, welfare_id);

	//	int res = ERROR_SCRIPT;
	//	res = lua::getinteger(1);
	//	return res;
	//}

	//int getWelfare(EntityPlayer &player, int welfare_id)
	//{
	//	int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
	//	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	//	if (guild == NULL)
	//	{
	//		return ERROR_NOT_IN_GUILD;
	//	}

	//	lua::call(lua::L, "Guild.get_welfare", guild, &player, welfare_id);

	//	int res = ERROR_SCRIPT;
	//	res = lua::getinteger(1);
	//	return res;
	//}

	int openGuildBuff(EntityPlayer &player, int buff_id)
	{
		int guildID = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guildID);
		if (guild == NULL)
			return ERROR_NOT_IN_GUILD;

		lua::call(lua::L, "Guild.open_guild_buff", guild, &player, buff_id);

		int res = ERROR_SCRIPT;
		res = lua::getinteger(1);

		return res;
	}

	int renameGuild(EntityPlayer *player, const std::string &newname)
	{
		if (player == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		//检查是否有足够的物品
		if (!ItemOperationHelper::hasItem(*player, 74001, 1))
		{
			return ERROR_NOT_ENOUGH_ITEM;
		}

		if (lua::call(lua::L, "Event.isGuildActivityTime", player))
		{
			bool ret = lua::getboolean(1);
			if (!ret)
			{
				return -1;
			}
		}

		//如果名字为空或名字重复
		if ((newname.empty()) || (g_guild_mgr.getGuildByName(newname) != NULL))
		{
			return ERROR_GUILD_NAME_USED;
		}

		int guild_id = player->getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		// 不是会长，也不是副会长
		if (player->getProp(ENTITY_PROP_GUILD_POST) != GUILD_POST_MASTER && player->getProp(ENTITY_PROP_GUILD_POST) != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_NEED_MASTER_OR_SECOND_MASTER;
		}
		//如果行会名字过长
		int name_len = utf8_to_unicode_len(newname);
		if ((name_len <= 0) || (name_len > GUILD_NAME_MAX))
		{	
			return ERROR_GUILD_NAME_TOO_LONG;
		}

		std::string oldName = guild->getGuildName();
		if(strcmp("",oldName.c_str()) != 0)
		{
			g_guild_mgr.removeGuildName(oldName);
		}

		MsgDBGuildUpdateName *dbmsg = new MsgDBGuildUpdateName;
		dbmsg->guildid = guild_id;
		dbmsg->name = newname;
		player->sendMessageToDB(dbmsg);
		return SUCCESS;
	}

	int renameResponse(EntityPlayer &player, const std::string &newname)
	{
		if (!ItemOperationHelper::hasItem(player, 71700, 1))
		{
			return ERROR_NOT_ENOUGH_ITEM;
		}

		if (lua::call(lua::L, "Event.isGuildActivityTime", &player))
		{
			bool ret = lua::getboolean(1);
			if (!ret)
			{
				return -1;
			}
		}

		int guild_id = player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == NULL)
		{
			return ERROR_GUILD_NO_GUILD;
		}
		std::string oldname = guild->getGuildName();
		guild->setGuildName(newname);

		GuildHelper::syncMyGuildInfo(player);

		//消耗道具
		ItemOperationHelper::deleteItem(player, 74001, 1);

		//行会成员列表
		std::vector<GuildMember*> &members = guild->getMembers();
		for (size_t i = 0; i < members.size(); ++i)
		{
			GuildMember *member = members[i];
			if ((member == nullptr))
			{
				continue;
			}

			if (member->player != nullptr)
			{
				/*if (member->player->getProp(ENTITY_PROP_GUILD_POST) == GUILD_POST_MASTER)
				{
				continue;
				}*/
				GuildHelper::syncMyGuildInfo(*(member->player));
				syncMeetGuildName(*(member->player));
			}
			
			lua::call(lua::L, "Entity.sendGuildRenameMail", member->player_id, oldname, newname);
		}

		// 全服公告
		lua::call(lua::L, "Guild.sendRenameMsg", oldname, newname );

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_CHANGENAME, 0, 0, player.getName(), newname);
		
		//行会改名
		g_world.setGuildName(guild_id, newname, true);

		// 给跨服发送公会改名消息
		GSHelper::syncGuildRenameToCross(guild_id, newname);
		return SUCCESS;
	}

	//增加行会事件
	void addRecord(int guild_id, short type, int datax, int datay,
		const std::string &namex, const std::string &namey)
	{
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return;
		}

		addRecord(guild, type, datax, datay, namex, namey);
	}

	void addRecord(Guild *guild, short type, int datax, int datay, const std::string &namex, const std::string &namey)
	{
		if (guild == nullptr)
		{
			return;
		}

		GuildRecord record;
		record.type = type;
		record.recordtime = (int)time(nullptr);
		record.datax = datax;
		record.datay = datay;
		record.namex = namex;
		record.namey = namey;
		guild->addRecord(record);

		MsgDBGuildRecordAdd *dbmsg = new MsgDBGuildRecordAdd;
		dbmsg->gid = guild->getGuildID();
		dbmsg->type = type;
		dbmsg->datax = datax;
		dbmsg->datay = datay;
		dbmsg->namex = namex;
		dbmsg->namey = namey;
		g_app.postToNetService(dbmsg);

		MsgGuildRecordAddNotify *notify = new MsgGuildRecordAddNotify;
		notify->record = record;
		guild->sendMessage(notify);
	}

	// 发红包
	int sendRedPackage(Entity *player, int redtype, int max_gold, int max_count, const std::string &decs)
	{
		if (player == nullptr)
		{
			return ERROR_PLAYER_IS_OFFLINE;
		}

		int guild_id = player->getProp(ENTITY_PROP_GUILD_ID);

		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NOT_SEND_RED;
		}
	
		if (redtype == GUILD_RED_PACKAGE_COMMON)
		{
			if (max_gold < 100 || max_count < 10 || max_count > 50)
			{
				return ERROR_NOT_ENOUGH_INGOT;
			}
			
			if (!EntityOperationHelper::checkCanTransaction(*player, max_gold))
			{
				return ERROR_USE_INGOT_MAX;
			}

			if (lua::call(lua::L, "Guild.SendRedToCheck", player, redtype, max_gold))
			{
				int ret = lua::getinteger(1);
				if (SUCCESS != ret)
				{
					return ret;
				}
				else
				{
					EntityOperationHelper::updateTransactionAmount(*player, max_gold);
				}
			}
		}
		else if (redtype == GUILD_RED_PACKAGE_SALARY)
		{
			if (lua::call(lua::L, "Guild.SendRedToCheck", player, redtype, max_gold))
			{
				int ret = lua::getinteger(1);
				if (SUCCESS != ret)
				{
					return ret;
				}
			}
		}

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_REDPAG, redtype, max_gold, player->getName(), "");

		OperationHelper::setOpCode(OP_GUILD_SEND_RED);

		GuildRed red;
		red.redtype = redtype;
		red.guildid = guild_id;
		red.maxgold = max_gold;
		red.createtime = (int)time(nullptr);
		red.maxcount = max_count;
		red.curcount = 0;
		red.curgold = 0;
		red.job = player->getClass();
		red.gender = player->getProp(ENTITY_PROP_GENDER);
		red.pid = player->getGlobalID();
		red.name = player->getName();
		red.desc = decs;

		MsgDBGuildRedAdd *dbmsg = new MsgDBGuildRedAdd;
		dbmsg->redtype = red.redtype;
		dbmsg->guildid = red.guildid;
		dbmsg->maxgold = red.maxgold;
		dbmsg->createtime = red.createtime;
		dbmsg->maxcount = red.maxcount;
		dbmsg->curcount = red.curcount;
		dbmsg->curgold = red.curgold;
		dbmsg->pid = red.pid;
		dbmsg->job = red.job;
		dbmsg->gender = red.gender;
		dbmsg->name = red.name;
		dbmsg->desc = red.desc;
	
		g_app.postToNetService(dbmsg);

		lua::call(lua::L, "Guild.sendRedMsg", guild, player->getName(), max_gold, redtype);

		return SUCCESS;
	}

	// 添加红包
	void addRedPackage(Guild *guild, int redtype, int max_gold, int max_count, const std::string &desc)
	{
		if (guild == nullptr)
		{
			return;
		}

		GuildMember* master = guild->getMasterMember();
		if (!master)
		{
			return;
		}

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_REDPAG, redtype, max_gold, master->player_name, "");

		OperationHelper::setOpCode(OP_GUILD_SEND_RED);

		GuildRed red;
		red.redtype = redtype;
		red.guildid = guild->getGuildID();
		red.maxgold = max_gold;
		red.createtime = (int)time(nullptr);
		red.maxcount = max_count;
		red.curcount = 0;
		red.curgold = 0;
		red.job = GUILD_POST_MASTER;
		red.gender = master->gender;
		red.pid = master->player_id;
		red.name = master->player_name;
		red.desc = desc;

		MsgDBGuildRedAdd *dbmsg = new MsgDBGuildRedAdd;
		dbmsg->redtype =red.redtype;
		dbmsg->guildid = red.guildid;
		dbmsg->maxgold = red.maxgold;
		dbmsg->createtime = red.createtime;
		dbmsg->maxcount = red.maxcount;
		dbmsg->curcount = red.curcount;
		dbmsg->curgold = red.curgold;
		dbmsg->pid = red.pid;
		dbmsg->job = red.job;
		dbmsg->gender = red.gender;
		dbmsg->name = red.name;
		dbmsg->desc = red.desc;

		g_app.postToNetService(dbmsg);

		lua::call(lua::L, "Guild.sendRedMsg", guild, master->player_name, max_gold, redtype);
	}

	// 更新红包
	int updateRed(EntityPlayer *player, int redid, int guild_id, int &retGold)
	{
		int ret = ERROR_UNKNOWN;

		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		const std::vector<GuildRedRecord> &redrecords = guild->getRedRecords();
		if (redrecords.size() > 0)
		{
			for (size_t i = 0; i < redrecords.size(); ++i)
			{
				if (redrecords[i].redid == redid && redrecords[i].dpid == player->getPlayerID())
				{
					return ERROR_GUILD_ARRADY_GET_GUILD_RED;
				}
			}
		}
		
		std::vector<GuildRed>& reds = guild->getReds();
		if (reds.size() > 0)
		{
			for (size_t i = 0; i < reds.size(); ++i)
			{
				if (reds[i].id == redid && reds[i].guildid == guild_id)
				{
					if (reds[i].curcount >= reds[i].maxcount)
					{
						return ERROR_GUILD_NOT_ENOUGH_GUILD_RED;
					}

					// 如果是公会活动红包
					int offsetTime = 24 * 3600;
					if (reds[i].redtype == GUILD_RED_PACKAGE_ACTIVITY)
					{
						offsetTime = 3600;
					}
					if (reds[i].createtime + offsetTime < time(nullptr))
					{
						return ERROR_GUILD_NOT_ENOUGH_GUILD_RED;
					}
					
					ret = ERROR_SCRIPT;
					int gold = SUCCESS;
					if (lua::call(lua::L, "Guild.randomRed", player, reds[i].maxgold, reds[i].maxcount, reds[i].curgold, reds[i].curcount, reds[i].redtype, reds[i].desc))
					{
						ret = lua::getinteger(1);
						gold = lua::getinteger(2);
					}

					if (ret != SUCCESS)
					{
						return ret;
					}

					reds[i].curcount = reds[i].curcount + 1;
					reds[i].curgold = reds[i].curgold + gold;
					retGold = gold;

					//添加收红包记录
					addRedRecord(reds[i].redtype,reds[i].pid,reds[i].name, player->getPlayerID(), player->getName(), reds[i].id, gold, 1);

					MsgDBGuildRedUpdate *dbmsg = new MsgDBGuildRedUpdate;
					
					dbmsg->id = reds[i].id;
					dbmsg->curcount = reds[i].curcount;
					dbmsg->curgold = reds[i].curgold;

					g_app.postToNetService(dbmsg);

					MsgGuildRedUpdateNotify *notify = new MsgGuildRedUpdateNotify;
					notify->red = reds[i];

					guild->sendMessage(notify);

					return ret;
				}
			}
		}
		return ret;
	}

	// 返回红包
	void backRed(Guild *guild, bool dismiss)
	{
		if (guild == nullptr)
		{
			return;
		}

		std::vector<GuildRed>& reds = guild->getReds();

		for (size_t j = 0; j < reds.size(); ++j)
		{
			if (reds[j].curcount >= reds[j].maxcount)
			{
				continue;
			}

			//红包过期
			if (dismiss || reds[j].createtime + 24 * 3600 < time(nullptr))
			{
				int leftgold = 0;
				if (reds[j].curcount < reds[j].maxcount)
				{
					int left_gold = reds[j].maxgold - reds[j].curgold;
					reds[j].curcount =  reds[j].maxcount;
					reds[j].curgold =  reds[j].maxgold;

					MsgDBGuildRedUpdate *dbmsg = new MsgDBGuildRedUpdate;
					dbmsg->id = reds[j].id;
					dbmsg->curcount = reds[j].curcount;
					dbmsg->curgold = reds[j].curgold;
					g_app.postToNetService(dbmsg);

					MsgGuildRedUpdateNotify *notify = new MsgGuildRedUpdateNotify;
					notify->red = reds[j];
					guild->sendMessage(notify);

					//返回元宝(只有普通红包可以返回)
					if (left_gold > 0 && reds[j].redtype == GUILD_RED_PACKAGE_COMMON)
					{
						int gold = 0;
						lua::call(lua::L, "Guild.backRed", reds[j].pid, left_gold);
					}
				}
			}
		}
	}

	std::vector<int> getRedCount(EntityPlayer *player, Guild *guild, int redID)
	{
		std::vector<int> res;
		res.push_back(0);
		res.push_back(0);
		res.push_back(0);
		if (guild == nullptr)
		{
			return res;
		}

		std::vector<GuildRed>& reds = guild->getReds();

		int count = 0;
		int id = 0;
		int createtime = 0;

		for (size_t j = 0; j < reds.size(); ++j)
		{
			if (redID == reds[j].id)
			{
				if (reds[j].curcount >= reds[j].maxcount)
				{
					id = reds[j].id;
					createtime = reds[j].createtime;
					continue;
				}

				const std::vector<GuildRedRecord> &redRecords = guild->getRedRecords();
				bool bGet = false;
				for (size_t t = 0; t < redRecords.size(); ++t)
				{
					if (redRecords[t].dpid == player->getPlayerID() && redRecords[t].redid == reds[j].id)
					{
						bGet = true;
						break;
					}
				}
				if (!bGet)
				{
					id = reds[j].id;
					count++;
				}
				createtime = reds[j].createtime;
			}
		}
		res[0] = id;
		res[1] = count;
		res[2] = createtime;
		return res;
	}

	int addRedRecord(int redtype,int spid, const std::string &sname, int dpid, const std::string &dname, int redid, int gold, int type)
	{
		GuildRedRecord redrecords;
		Guild *guild = nullptr;
		//发红包
		if (type == 0)
		{
			EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(spid);
			if (player == nullptr)
			{
				return ERROR_PLAYER_IS_OFFLINE;
			}

			int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);

			guild = g_guild_mgr.getGuildByID(guild_id);
			if (guild == nullptr)
			{
				return ERROR_GUILD_NO_GUILD;
			}
			
			redrecords.redid = redid;
			redrecords.redtype= redtype;
			redrecords.guildid = guild_id;
			redrecords.spid = spid;
			redrecords.sname = sname;
			redrecords.dpid = 0; //发红包不需要记录谁收了红包
			redrecords.djob = 0;
			redrecords.dgender = 0;
			redrecords.dname = "";
			redrecords.gold = gold;
			redrecords.type = 0;
		}
		//收红包
		else
		{
			EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(dpid);
			if (player == nullptr)
			{
				return ERROR_PLAYER_IS_OFFLINE;
			}

			int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);

			guild = g_guild_mgr.getGuildByID(guild_id);
			if (guild == nullptr)
			{
				return ERROR_GUILD_NO_GUILD;
			}

			redrecords.redid = redid;
			redrecords.redtype= redtype;
			redrecords.guildid = guild_id;
			redrecords.spid = spid;
			redrecords.sname = sname;
			redrecords.dpid = dpid;
			redrecords.djob = player->getClass();
			redrecords.dgender = player->getProp(ENTITY_PROP_GENDER);
			redrecords.dname = dname;
			redrecords.gold = gold;
			redrecords.type = 1;
		}

		guild->addRedRecord(redrecords);

		MsgDBGuildRedRecordAdd *dbmsg = new MsgDBGuildRedRecordAdd;

		dbmsg->redid = redrecords.redid;
		dbmsg->redtype= redrecords.redtype;
		dbmsg->guildid = redrecords.guildid;
		dbmsg->spid = redrecords.spid;
		dbmsg->sname = redrecords.sname;
		dbmsg->gold = redrecords.gold;
		dbmsg->dpid = redrecords.dpid;
		dbmsg->djob = redrecords.djob;
		dbmsg->dgender = redrecords.dgender;
		dbmsg->dname = redrecords.dname;
		dbmsg->type = redrecords.type;

		g_app.postToNetService(dbmsg);

		MsgGuildRedRecordsAddNotify *notify = new MsgGuildRedRecordsAddNotify;
		notify->record = redrecords;

		guild->sendMessage(notify);

		return SUCCESS;
	}

	//增加行会活跃度
	bool addVitality(Guild *guild, int count)
	{
		if ((guild == nullptr) || (count < 0))
		{
			return false;
		}

		int vitality = guild->getProp(GUILD_PROP_VITALITY);
		int vitality_day = guild->getProp(GUILD_PROP_VITALITY_DAY);
		int vitality_today = guild->getProp(GUILD_PROP_VITALITY_TODAY);

		int now_day = get_time() / (24 * 60 * 60);
		if (now_day == vitality_day)
		{
			if (vitality_today >= 10000)
			{
				return false;
			}
		}
		else
		{
			vitality_today = 0;
		}

		//修正增加的活跃度
		if (vitality_today + count > 10000)
		{
			count = 10000 - vitality_today;
		}

		if (count == 0)
		{
			return true;
		}

		if (vitality_day != now_day)
		{
			guild->setProp(GUILD_PROP_VITALITY_DAY, now_day);
			GuildHelper::syncProp(*guild, GUILD_PROP_VITALITY_DAY);
			GuildHelper::saveProp(*guild, GUILD_PROP_VITALITY_DAY);
		}

		guild->setProp(GUILD_PROP_VITALITY_TODAY, vitality_today + count);
		GuildHelper::syncProp(*guild, GUILD_PROP_VITALITY_TODAY);
		GuildHelper::saveProp(*guild, GUILD_PROP_VITALITY_TODAY);

		guild->setProp(GUILD_PROP_VITALITY, vitality + count);
		GuildHelper::syncProp(*guild, GUILD_PROP_VITALITY);
		GuildHelper::saveProp(*guild, GUILD_PROP_VITALITY);

		return true;
	}

	//使用行会活跃度
	bool useVitality(Guild *guild, int count, int reason, int data)
	{
		if ((guild == nullptr) || (count < 0))
		{
			return false;
		}

		if (count == 0)
		{
			return true;
		}

		int vitality = guild->getProp(GUILD_PROP_VITALITY);
		if (vitality < count)
		{
			return false;
		}

		guild->setProp(GUILD_PROP_VITALITY, vitality - count);
		GuildHelper::syncProp(*guild, GUILD_PROP_VITALITY);
		GuildHelper::saveProp(*guild, GUILD_PROP_VITALITY);
		return true;
	}

	//是否有足够的行会活跃度
	bool haveVitality(Guild *guild, int count)
	{
		if (guild == nullptr)
		{
			return false;
		}

		int vitality = guild->getProp(GUILD_PROP_VITALITY);
		return (vitality >= count);
	}

	// 更新玩家活跃度
	void updateMemberVitality(Guild *guild, int player_id, int value)
	{
		GuildMember* mem = guild->getMember(player_id);
		if (mem)
		{
			mem->vitality = value;
		}
	}

	// 玩家删号处理
	void handlePlayerDelete(int guild_id, int player_id)
	{
		Guild* guild = g_guild_mgr.getGuildByID(guild_id);
		if (NULL == guild)
		{
			return;
		}

		GuildMember* mem = guild->getMember(player_id);
		if (NULL == mem)
		{
			return;
		}
	}

	// 同步物品信息
	int sysItem(EntityPlayer *player)
	{
		if (player == nullptr || player->getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildItemManager *guild_item_mgr = guild->getItemManager();
		if (guild_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		const auto &items_list = guild_item_mgr->getItems();

		MsgSyncGuildItemsNotify *notify = new MsgSyncGuildItemsNotify;
		notify->setSessionID(player->getSessionID());
		notify->pid = -guild_id;

		auto it = items_list.begin();
		while (it!= items_list.end())
		{
			ItemInfo iteminfo;

			iteminfo.iid = it->second->getID();
			iteminfo.sid = it->second->getStaticID();
			iteminfo.bind = it->second->getBindType();
			iteminfo.count = it->second->getCount();
			iteminfo.position = it->second->getPosition();

			notify->items.push_back(iteminfo);
			++it;
		}

		player->sendMessage(notify);

		auto it1 = items_list.begin();
		while (it1!= items_list.end())
		{
			Item *item = it1->second;
			if (item)
			{
				MsgUpdateGuildItemAllPropsNotify *notify1 = new MsgUpdateGuildItemAllPropsNotify;
				notify1->opcode = OperationHelper::getOpCode();
			    notify1->iid = item->getID();

				for (int i = ITEM_PROP_BEGIN; i < ITEM_PROP_MAX ; i++)
				{
					int data = item->getProp(i);
					if (data == 0)
					{
						continue;
					}

					ItemExData ex;
					ex.nIdx = i;
					ex.data = data;
					notify1->props.push_back(ex);
				}

				if (notify1->props.size() > 0)
				{
					player->sendMessage(notify1);
				}
				else
				{
					delete notify1;
				}

			}
			++it1;
		}

		return SUCCESS;
	}

	// 同步公会商店信息
	int syscGuildShopToPlayer(EntityPlayer &player)
	{
		if (player.getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildShop *guild_shop = guild->getShop();
		if (guild_shop == nullptr)
		{
			return ERROR_INVALID_ITEM_MGR;
		}

		const std::vector<ShopGuildItem>& items_list = guild_shop->getItems();

		MsgSyncGuildShopNotify *notify = new MsgSyncGuildShopNotify;
		notify->setSessionID(player.getSessionID());
		notify->pid = guild_id;

		ShopItemInfo itemInfo;
		for (size_t i = 0; i < items_list.size(); ++i)
		{
			const ShopGuildItem &item = items_list[i];
			itemInfo.sid = item.itemID;
			itemInfo.sellCount =item.count;
			notify->items.push_back(itemInfo);
		}

		player.sendMessage(notify);

		return SUCCESS;
	}

	// 同步鬼市
	int syscGuildGuishiToPlayer(EntityPlayer &player)
	{
		if (player.getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player.getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildGuishi *guild_guishi = guild->getGuishi();
		if (guild_guishi == nullptr)
		{
			return ERROR_INVALID_ITEM_MGR;
		}

		const auto &items_list = guild_guishi->getItems();

		MsgSyncGuildGuishiItemsNotify *notify = new MsgSyncGuildGuishiItemsNotify;
		notify->setSessionID(player.getSessionID());
		notify->gid = guild_id;

		auto it = items_list.begin();
		while (it!= items_list.end())
		{
			GuishiItem iteminfo;

			iteminfo.sid = it->second->sid;
			iteminfo.cid = it->second->cid;

			notify->items.push_back(iteminfo);
			++it;
		}

		player.sendMessage(notify);

		return SUCCESS;
	}

	//存放物品
	int depositItem(EntityPlayer *player, int item_id)
	{
		if (player == nullptr || player->getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildItemManager *guild_item_mgr = guild->getItemManager();
		if (guild_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		if (guild_item_mgr->isFull())
		{
			return ERROR_GUILD_NOT_ENOUGH_GUILD_BAG;
		}
		
		ItemManager *player_item_mgr = player->getItemManager();
		if (player_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		//删除玩家物品
		Item *item = player_item_mgr->cutItem(item_id);
		if (item == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}
		ItemOperationHelper::saveItemDelete(*player, item_id);
		ItemOperationHelper::syncItemDelete(*player, item_id);

		OperationHelper::setOpCode(OP_GUILD_PUT_ITEM);
		OperationHelper::recordItemOp(*player, item->getStaticID(), 1, OP_LOST_THING);

		//获得贡献
		int gx = 0;
		if (lua::call(lua::L, "Guild.getGxValue", item->getStaticID()))
		{
			gx = lua::getinteger(1);
		}
		if (gx > 0)
		{
			addGuildContribution(*player, gx, OP_GUILD_PUT_ITEM, item->getStaticID());
		}

		lua::call(lua::L, "Guild.sendPutItemMsg", guild, player->getName(), item->getStaticID(), gx, guild_id, item->getID());

		//增加行会物品
		guild_item_mgr->depositItem(item);
		ItemOperationHelper::saveGuildItemAdd(*guild, item);
		ItemOperationHelper::syncGuildItemAdd(*guild, item);

		OperationHelper::setOpCode(OP_GUILD_PUT_ITEM);
		OperationHelper::recordItemOp(*guild, item->getStaticID(), 1, OP_GET_THING, player->getGlobalID());
		
		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_BAG_SEND_ITEM, item->getStaticID(), gx, player->getName(), "");

		return SUCCESS;
	}

	//删除道具
	int delItem(EntityPlayer *player, int item_id)
	{
		if (player == nullptr || player->getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		//判断是否是会长或者副会长
		int post = player->getProp(ENTITY_PROP_GUILD_POST);
		if (post != GUILD_POST_MASTER && post != GUILD_POST_SECOND_MASTER)
		{
			return ERROR_GUILD_AUTHORITY;			
		}

		//会长正在被弹劾，暂时没有公会的管理权限
		if (post == GUILD_POST_MASTER && guild->getProp(GUILD_PROP_IMPEACH_PID) > 0)
		{
			return ERROR_GUILD_MASTER_BEING_IMPEACHED;
		}

		//检查物品是否存在
		GuildItemManager *guild_item_mgr = guild->getItemManager();
		if (guild_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}
		Item *item = guild_item_mgr->getItemByID(item_id);
		if (item == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		int item_sid = item->getStaticID();

		//删除行会物品
		guild_item_mgr->delItem(item_id);
		ItemOperationHelper::saveGuildItemDelete(*guild, item_id);
		ItemOperationHelper::syncGuildItemDelete(*guild, item_id);

		OperationHelper::setOpCode(OP_GUILD_DEL_ITEM);
		OperationHelper::recordItemOp(*guild, item_sid, 1, OP_LOST_THING, player->getGlobalID());
		return SUCCESS;
	}

	//取出物品
	int withdrawItem(EntityPlayer *player, int item_id)
	{
		if (player == nullptr || player->getGlobalID() <= 0)
		{
			return ERROR_INVALID_PARAM;
		}

		int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildItemManager *guild_item_mgr = guild->getItemManager();
		if (guild_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}


		ItemManager *player_item_mgr = player->getItemManager();
		if (player_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		if (player_item_mgr->getEmptyPositionCount(PLAYER_BAG_BEGIN, PLAYER_BAG_END) <= 0)
		{
			return ERROR_BAG_IS_FULL;
		}

		Item *item1 = guild_item_mgr->getItemByID(item_id);
		if (item1 == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		int gx = 0;
		if (lua::call(lua::L, "Guild.getGxValue", item1->getStaticID()))
		{
			gx = lua::getinteger(1);
		}
		if (gx < 0)
		{
			return ERROR_SCRIPT;
		}

		//消费贡献
		int ret = addGuildContribution(*player, -gx, OP_GUILD_GET_ITEM, item1->getStaticID());
		if (ret != SUCCESS)
		{
			return ret;
		}

		//删除行会物品
		Item *item = guild_item_mgr->withdrawItem(item_id);
		ItemOperationHelper::saveGuildItemDelete(*guild, item_id);
		ItemOperationHelper::syncGuildItemDelete(*guild, item_id);
		OperationHelper::setOpCode(OP_GUILD_GET_ITEM);
		OperationHelper::recordItemOp(*guild, item->getStaticID(), 1, OP_LOST_THING, player->getGlobalID());

		//增加玩家物品
		item = player_item_mgr->addItem(item);
		if (item == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}

		int err = ItemOperationHelper::setEmptyPosition(*player, item);
		if (err != SUCCESS)
		{
			return err;
		}

		ItemOperationHelper::saveItemAdd(*player, item);
		ItemOperationHelper::syncItemAdd(*player, item);
		OperationHelper::setOpCode(OP_GUILD_GET_ITEM);
		OperationHelper::recordItemOp(*player, item->getStaticID(), 1, OP_GET_THING);

		lua::call(lua::L, "Guild.sendGetItemMsg", guild, player->getName(), item->getStaticID(), gx, player->getPlayerID(), item->getID());

		//行会事件
		GuildHelper::addRecord(guild, GUILD_RECORD_BAG_GET_ITEM, gx, item->getStaticID(), player->getName(), "");

		return SUCCESS;
	}

	// 同步公会物品信息
	int syncGuildItemInfo(Entity *player, int guild_id, int item_id)
	{
		Guild *guild = g_guild_mgr.getGuildByID(guild_id);
		if (guild == nullptr)
		{
			return ERROR_GUILD_NO_GUILD;
		}

		GuildItemManager *guild_item_mgr = guild->getItemManager();
		if (guild_item_mgr == nullptr)
		{
			return ERROR_INVALID_ITEM;
		}


		Item* item = guild_item_mgr->getItemByID(item_id);

		if (item == NULL)
		{
			MsgItemInfoDataGetResponse* res = new MsgItemInfoDataGetResponse;
			res->errcode = ERROR_INVALID_ENTITY;
			res->eid = 0;
			res->pid = 0;
			res->iid = item_id;
			player->sendMessage(res);
			return SUCCESS;
		}

		MsgItemInfoDataGetResponse* res = new MsgItemInfoDataGetResponse;
		res->eid = 0;
		res->pid = 0;
		//res->sid = item->getStaticID();
		//res->cate = item->getCategory();
		res->errcode = SUCCESS;
		res->iid = item_id;
		for (int i = ITEM_PROP_BEGIN; i < ITEM_PROP_MAX ; i++)
		{
			int data = item->getProp(i);
			if (data)
			{
				ItemExData ex;
				ex.nIdx = i;
				ex.data = data;
				res->data.push_back(ex);
			}
		}
		player->sendMessage(res);
		return SUCCESS;
	}
}

//增加结盟申请(guild1向guild2申请结盟)
int GuildHelper::addLeagueApp(Guild *guild1, Guild *guild2)
{
	if (guild1 == nullptr || guild2 == nullptr)
	{
		return ERROR_UNKNOWN;
	}

	if (guild1->getProp(GUILD_PROP_LEAGUE_GUILD_ID) > 0)
	{
		return ERROR_GUILD_SELF_LEAGUE_EXIST;
	}

	if (guild2->getProp(GUILD_PROP_LEAGUE_GUILD_ID) > 0)
	{
		return ERROR_GUILD_OTHER_LEAGUE_EXIST;
	}

	int guild_id1 = guild1->getGuildID();
	int guild_id2 = guild2->getGuildID();

	if (guild1->hasPassiveLeagueApp(guild_id2) || guild1->hasActiveLeagueApp(guild_id2))
	{
		return ERROR_GUILD_LEAGUE_APP_EXIST;
	}

	guild1->addActiveLeagueApp(guild_id2, get_time());
	guild2->addPassiveLeagueApp(guild_id1, get_time());

	//保存数据库
	MsgDBGuildLeagueAppAdd *dbmsg = new MsgDBGuildLeagueAppAdd;
	dbmsg->guild_id1 = guild_id1;
	dbmsg->guild_id2 = guild_id2;
	g_app.postToNetService(dbmsg);

	//同步给客户端
	MsgGuildAddLeagueAppNotify *notify1 = new MsgGuildAddLeagueAppNotify;
	notify1->guild_id1 = guild_id1;
	notify1->guild_name1 = guild1->getGuildName();
	notify1->guild_id2 = guild_id2;
	notify1->guild_name2 = guild2->getGuildName();
	notify1->show_notice = 1;
	guild1->sendMessage(notify1);

	MsgGuildAddLeagueAppNotify *notify2 = new MsgGuildAddLeagueAppNotify;
	notify2->guild_id1 = guild_id1;
	notify2->guild_name1 = guild1->getGuildName();
	notify2->guild_id2 = guild_id2;
	notify2->guild_name2 = guild2->getGuildName();
	notify2->show_notice = 1;
	guild2->sendMessage(notify2);

	//记录操作日志
	//GuildHelper::addRecord(guild, GUILD_RECORD_RELATION, msg->type, 0, 
	//	player->getName(), other_guild->getGuildName());

	return SUCCESS;
}

//删除结盟申请
int GuildHelper::delLeagueApp(Guild *guild1, Guild *guild2)
{
	if (guild1 == nullptr || guild2 == nullptr)
	{
		return ERROR_UNKNOWN;
	}

	int guild_id1 = guild1->getGuildID();
	int guild_id2 = guild2->getGuildID();

	if (!guild1->hasActiveLeagueApp(guild_id2))
	{
		return SUCCESS;
	}

	guild1->delActiveLeagueApp(guild_id2);
	guild2->delPassiveLeagueApp(guild_id1);

	//保存数据库
	MsgDBGuildLeagueAppDelete *dbmsg = new MsgDBGuildLeagueAppDelete;
	dbmsg->guild_id1 = guild_id1;
	dbmsg->guild_id2 = guild_id2;
	g_app.postToNetService(dbmsg);

	//同步给客户端
	MsgGuildDelLeagueAppNotify *notify1 = new MsgGuildDelLeagueAppNotify;
	notify1->guild_id1 = guild_id1;
	notify1->guild_id2 = guild_id2;
	guild1->sendMessage(notify1);

	MsgGuildDelLeagueAppNotify *notify2 = new MsgGuildDelLeagueAppNotify;
	notify2->guild_id1 = guild_id1;
	notify2->guild_id2 = guild_id2;
	guild2->sendMessage(notify2);

	//{
	//	auto &appset = it->second;
	//	for (auto appit = appset.begin(); appit != appset.end(); ++appit)
	//	{
	//		int guild_id2 = *appit;

	//		Guild *guild2 = getGuildByID(guild_id2);
	//		if (guild2 == nullptr)
	//		{
	//			continue;
	//		}

	//		guild1->delActiveLeagueApp(guild_id2);
	//		guild2->delPassiveLeagueApp(guild_id1);

	//		//保存数据库
	//		MsgDBGuildLeagueAppDelete *dbmsg = new MsgDBGuildLeagueAppDelete;
	//		dbmsg->guild_id1 = guild_id1;
	//		dbmsg->guild_id2 = guild_id2;
	//		g_app.postToNetService(dbmsg);

	//		//同步给客户端
	//		MsgGuildDelLeagueAppNotify *notify1 = new MsgGuildDelLeagueAppNotify;
	//		notify1->guild_id1 = guild_id1;
	//		notify1->guild_id2 = guild_id2;
	//		guild1->sendMessage(notify1);

	//		MsgGuildDelLeagueAppNotify *notify2 = new MsgGuildDelLeagueAppNotify;
	//		notify2->guild_id1 = guild_id1;
	//		notify2->guild_id2 = guild_id2;
	//		guild2->sendMessage(notify2);
	//	}

	//	m_league_app_map.erase(it);
	//}

	return SUCCESS;
}

//设置结盟
int GuildHelper::setLeague(Guild *guild1, Guild *guild2)
{
	if (guild1 == nullptr || guild2 == nullptr)
	{
		return ERROR_UNKNOWN;
	}

	if (guild1 == guild2)
	{
		return ERROR_UNKNOWN;
	}

	if (guild1->getProp(GUILD_PROP_LEAGUE_GUILD_ID) > 0)
	{
		return ERROR_GUILD_SELF_LEAGUE_EXIST;
	}

	if (guild2->getProp(GUILD_PROP_LEAGUE_GUILD_ID) > 0)
	{
		return ERROR_GUILD_OTHER_LEAGUE_EXIST;
	}

	int guild_id1 = guild1->getGuildID();
	int guild_id2 = guild2->getGuildID();

	//复制结盟申请列表
	const std::vector<std::pair<int, int>> active_league_apps1 = guild1->getActiveLeagueApps();
	const std::vector<std::pair<int, int>> passive_league_apps1 = guild1->getPassiveLeagueApps();
	const std::vector<std::pair<int, int>> active_league_apps2 = guild2->getActiveLeagueApps();
	const std::vector<std::pair<int, int>> passive_league_apps2 = guild2->getPassiveLeagueApps();

	for (size_t i = 0; i < active_league_apps1.size(); ++i)
	{
		int other_guild_id = active_league_apps1[i].first;
		Guild *other_guild = g_guild_mgr.getGuildByID(other_guild_id);
		if (other_guild != nullptr)
		{
			other_guild->delPassiveLeagueApp(guild_id1);
			//MsgGuildDelLeagueAppNotify *notify3 = new MsgGuildDelLeagueAppNotify;
			//notify3->guild_id1 = guild_id1;
			//notify3->guild_id2 = other_guild_id;
			//other_guild->sendMessage(notify3);
		}
	}

	for (size_t i = 0; i < passive_league_apps1.size(); ++i)
	{
		int other_guild_id = passive_league_apps1[i].first;
		Guild *other_guild = g_guild_mgr.getGuildByID(other_guild_id);
		if (other_guild != nullptr)
		{
			other_guild->delActiveLeagueApp(guild_id1);
			//MsgGuildDelLeagueAppNotify *notify3 = new MsgGuildDelLeagueAppNotify;
			//notify3->guild_id1 = other_guild_id;
			//notify3->guild_id2 = guild_id1;
			//other_guild->sendMessage(notify3);
		}
	}

	for (size_t i = 0; i < active_league_apps2.size(); ++i)
	{
		int other_guild_id = active_league_apps2[i].first;
		Guild *other_guild = g_guild_mgr.getGuildByID(other_guild_id);
		if (other_guild != nullptr)
		{
			other_guild->delPassiveLeagueApp(guild_id2);
			//MsgGuildDelLeagueAppNotify *notify3 = new MsgGuildDelLeagueAppNotify;
			//notify3->guild_id1 = guild_id2;
			//notify3->guild_id2 = other_guild_id;
			//other_guild->sendMessage(notify3);
		}
	}

	for (size_t i = 0; i < passive_league_apps2.size(); ++i)
	{
		int other_guild_id = passive_league_apps2[i].first;
		Guild *other_guild = g_guild_mgr.getGuildByID(other_guild_id);
		if (other_guild != nullptr)
		{
			other_guild->delActiveLeagueApp(guild_id2);
			//MsgGuildDelLeagueAppNotify *notify3 = new MsgGuildDelLeagueAppNotify;
			//notify3->guild_id1 = other_guild_id;
			//notify3->guild_id2 = guild_id2;
			//other_guild->sendMessage(notify3);
		}
	}

	//清除结盟申请列表
	guild1->delActiveLeagueApp(0);
	guild1->delPassiveLeagueApp(0);
	guild2->delActiveLeagueApp(0);
	guild2->delPassiveLeagueApp(0);

	//结盟
	guild1->setProp(GUILD_PROP_LEAGUE_GUILD_ID, guild_id2);
	guild1->setProp(GUILD_PROP_LEAGUE_TIMES, guild1->getProp(GUILD_PROP_LEAGUE_TIMES) - 1);
	guild2->setProp(GUILD_PROP_LEAGUE_GUILD_ID, guild_id1);
	guild2->setProp(GUILD_PROP_LEAGUE_TIMES, guild2->getProp(GUILD_PROP_LEAGUE_TIMES) - 1);
	GuildHelper::saveProp(*guild1, GUILD_PROP_LEAGUE_TIMES);
	GuildHelper::saveProp(*guild2, GUILD_PROP_LEAGUE_TIMES);

	//保存数据库
	MsgDBGuildLeagueAdd *dbmsg = new MsgDBGuildLeagueAdd;
	dbmsg->guild_id1 = guild_id1;
	dbmsg->guild_id2 = guild_id2;
	g_app.postToNetService(dbmsg);

	//结盟行会
	GuildHelper::syncProp(*guild1, GUILD_PROP_LEAGUE_GUILD_ID);
	GuildHelper::syncProp(*guild2, GUILD_PROP_LEAGUE_GUILD_ID);

	//结盟次数
	GuildHelper::syncProp(*guild1, GUILD_PROP_LEAGUE_TIMES);
	GuildHelper::syncProp(*guild2, GUILD_PROP_LEAGUE_TIMES);

	//通知客户端
	MsgGuildAddLeagueNotify *notify = new MsgGuildAddLeagueNotify;
	notify->guild_id1 = guild_id1;
	notify->guild_id2 = guild_id2;
	g_world.sendMessage(notify);

	return SUCCESS;
}

//清除所有行会数据
void GuildHelper::clearGuilds()
{
	g_guild_mgr.clear();

	MsgDBClearGuilds *dbmsg = new MsgDBClearGuilds;
	g_app.postToNetService(dbmsg);
}

void GuildHelper::sendGuildRecommendNotify(Entity *entity, int exclude_guild_id)
{
	if (entity == nullptr)
	{
		return;
	}

	//if (entity->getLevel() < 150)
	//{
	//	return;
	//}

	if (g_guild_mgr.getGuildByID(entity->getProp(ENTITY_PROP_GUILD_ID)) != nullptr)
	{
		return;
	}

	lua::call(lua::L, "Guild.checkGuildCD", entity);
	short hasCD = lua::getinteger(1);
	if (hasCD != SUCCESS)
	{
		return;
	}

	int guild_id1 = 0;
	std::string guild_name1;
	int guild_id2 = 0;
	std::string guild_name2;

	std::vector<Guild *> guilds = g_guild_mgr.getGuilds();


	std::vector<Guild *> newGild_vec;

	for (size_t i = 0; i < guilds.size(); ++i)
	{
		Guild *guild = guilds[i];
		bool is_full = false;
		lua::call(lua::L, "Guild.isMemberFull", guild->getProp(GUILD_PROP_LEVEL), guild->getMemberCount());
		is_full = lua::getboolean(1);
		if (is_full || exclude_guild_id == guild->getGuildID())
		{
			
		}else
		{
			newGild_vec.push_back(guild);
		}
	}
	if (newGild_vec.size() > 0)
	{
		std::sort(newGild_vec.begin(), newGild_vec.end(), [](const Guild *guild1, const Guild *guild2) -> bool {
			int member_count1 = guild1->getMemberCount();
			int member_count2 = guild2->getMemberCount();
			if (member_count1 != member_count2)
			{
				return member_count1 < member_count2;
			}

			int guild_level1 = guild1->getProp(GUILD_PROP_LEVEL);
			int guild_level2 = guild2->getProp(GUILD_PROP_LEVEL);
			if (guild_level1 != guild_level2)
			{
				return guild_level1 < guild_level2;
			}

			return guild1->getCreateTime() < guild2->getCreateTime();
		});

		if (newGild_vec[0])
		{
			guild_id1 = newGild_vec[0]->getGuildID();
			guild_name1 = newGild_vec[0]->getGuildName();
			if (newGild_vec.size() > 1 &&  newGild_vec[1])
			{
				guild_id2 = newGild_vec[1]->getGuildID();
				guild_name2 = newGild_vec[1]->getGuildName();
			}
		}
	}

	if (guild_id1 == 0)
	{
		//MsgGuildRecommendNotify *msg = new MsgGuildRecommendNotify;
		//msg->guild_id1 = 0;
		//msg->master_class1 = 0;
		//msg->master_gender1 = 0;
		//msg->guild_id2 = 0;
		//msg->master_class2 = 0;
		//msg->master_gender2 = 0;
		//entity->sendMessage(msg);
		return;
	}

	//int master_class1 = 0;
	//int master_gender1 = 0;
	//Guild *guild1 = g_guild_mgr.getGuildByID(guild_id1);
	//if (guild1 != nullptr)
	//{
	//	//行会成员列表
	//	auto &members = guild1->getMembers();
	//	for (size_t i = 0; i < members.size(); ++i)
	//	{
	//		if (members[i]->post == GUILD_POST_MASTER)
	//		{
	//			master_gender1 = members[i]->gender;
	//			break;
	//		}
	//	}
	//}

	//int master_class2 = 0;
	//int master_gender2 = 0;
	//Guild *guild2 = g_guild_mgr.getGuildByID(guild_id2);
	//if (guild2 != nullptr)
	//{
	//	//行会成员列表
	//	auto &members = guild2->getMembers();
	//	for (size_t i = 0; i < members.size(); ++i)
	//	{
	//		if (members[i]->post == GUILD_POST_MASTER)
	//		{
	//			master_gender2 = members[i]->gender;
	//			break;
	//		}
	//	}
	//}

	MsgGuildRecommendNotify *msg = new MsgGuildRecommendNotify;
	msg->guild_id1 = guild_id1;
	msg->guild_name1 = guild_name1;
	msg->master_class1 = 0;
	msg->master_gender1 = 0;
	msg->guild_id2 = guild_id2;
	msg->guild_name2 = guild_name2;
	msg->master_class2 = 0;
	msg->master_gender2 = 0;
	entity->sendMessage(msg);
}

int GuildHelper::donateItem(EntityPlayer *player, int item_id)
{
	if (player == nullptr || player->getGlobalID() <= 0)
	{
		return ERROR_INVALID_PARAM;
	}

	int guild_id =  player->getProp(ENTITY_PROP_GUILD_ID);
	Guild *guild = g_guild_mgr.getGuildByID(guild_id);
	if (guild == nullptr)
	{
		return ERROR_GUILD_NO_GUILD;
	}

	GuildItemManager *guild_item_mgr = guild->getItemManager();
	if (guild_item_mgr == nullptr)
	{
		return ERROR_INVALID_ITEM;
	}

	if (guild_item_mgr->isFull())
	{
		return ERROR_GUILD_NOT_ENOUGH_GUILD_BAG;
	}

	ItemManager *player_item_mgr = player->getItemManager();
	if (player_item_mgr == nullptr)
	{
		return ERROR_INVALID_ITEM;
	}

	//删除玩家物品
	Item *item = player_item_mgr->cutItem(item_id);
	if (item == nullptr)
	{
		return ERROR_INVALID_ITEM;
	}
	ItemOperationHelper::saveItemDelete(*player, item_id);
	ItemOperationHelper::syncItemDelete(*player, item_id);

	OperationHelper::setOpCode(OP_GUILD_PUT_ITEM);
	OperationHelper::recordItemOp(*player, item->getStaticID(), 1, OP_LOST_THING);

	//获得贡献
	int gx = 0;

	//增加行会物品
	guild_item_mgr->depositItem(item);
	ItemOperationHelper::saveGuildItemAdd(*guild, item);
	ItemOperationHelper::syncGuildItemAdd(*guild, item);

	OperationHelper::setOpCode(OP_GUILD_PUT_ITEM);
	OperationHelper::recordItemOp(*guild, item->getStaticID(), 1, OP_GET_THING, player->getGlobalID());

	lua::call(lua::L, "Guild.sendSelflessGiveItemMsg", guild, player->getName(), item->getStaticID(), guild_id, item->getID());

	return SUCCESS;
}

int GuildHelper::createGuildTeam(Entity *player)
{
	Guild *guild = g_guild_mgr.getGuildByID(player->getProp(ENTITY_PROP_GUILD_ID));
	if (guild == NULL) return ERROR_GUILD_NO_GUILD;

	if (player->getProp(ENTITY_PROP_GUILD_TEAM_ID) != 0) return ERROR_YOU_GET_TEAM;

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL) return ERROR_UNKNOWN;

	GuildTeam *team = teamM->createTeam();
	if (team == NULL) return ERROR_UNKNOWN;

	team->setLeader(player->getGlobalID());
	team->addMember(player);

	player->setProp(ENTITY_PROP_GUILD_TEAM_ID, team->getTeamID());

	team->enterTeamScene(player);

	GuildHelper::sendGuildChat(player);

	MsgGuildAddTeamNotify *notify = new MsgGuildAddTeamNotify;
	notify->TeamInfo.teamid = team->getTeamID();
	notify->TeamInfo.status = team->getProp(TEAM_PROP_STATUS);
	notify->TeamInfo.count = team->size();
	notify->TeamInfo.pid = player->getGlobalID();
	notify->TeamInfo.level = player->getLevel();
	notify->TeamInfo.job = player->getClass();
	notify->TeamInfo.gender = player->getProp(ENTITY_PROP_GENDER);
	notify->TeamInfo.name = player->getName();
	guild->sendMessage(notify);
	return SUCCESS;
}

int GuildHelper::joinGuildTeam(Entity *player, int teamid)
{
	Guild *guild = g_guild_mgr.getGuildByID(player->getProp(ENTITY_PROP_GUILD_ID));
	if (guild == NULL) return ERROR_GUILD_NO_GUILD;

	if (player->getProp(ENTITY_PROP_GUILD_TEAM_ID) != 0) return ERROR_YOU_GET_TEAM;

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL) return ERROR_UNKNOWN;

	GuildTeam *team = teamM->getTeam(teamid);
	if (team == NULL) return ERROR_TEAM_NOT_EXIST;

	if (team->isFull()) return ERROR_TEAM_MAX_MEMBER;

	if (team->isFinal()) return ERROR_TEAM_MAX_MEMBER;

	team->addMember(player);

	player->setProp(ENTITY_PROP_GUILD_TEAM_ID, teamid);

	team->enterTeamScene(player);

	MsgGuildUpdateTeamNotify *notify = new MsgGuildUpdateTeamNotify;
	notify->teamid = teamid;
	notify->count = team->size();
	guild->sendMessage(notify);
	return SUCCESS;
}

int GuildHelper::searchGuildTeam(Entity *player)
{
	Guild *guild = g_guild_mgr.getGuildByID(player->getProp(ENTITY_PROP_GUILD_ID));
	if (guild == NULL) return ERROR_GUILD_NO_GUILD;

	if (player->getProp(ENTITY_PROP_GUILD_TEAM_ID) != 0) return ERROR_YOU_GET_TEAM;

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL) return ERROR_UNKNOWN;

	if (teamM->hasCanJoinTeam())
	{
		GuildTeam *team = teamM->autoFindTeam();
		if (team == NULL) return ERROR_TEAM_NOT_EXIST;

		team->addMember(player);

		player->setProp(ENTITY_PROP_GUILD_TEAM_ID, team->getTeamID());

		team->enterTeamScene(player);

		MsgGuildUpdateTeamNotify *notify = new MsgGuildUpdateTeamNotify;
		notify->teamid = team->getTeamID();
		notify->count = team->size();
		guild->sendMessage(notify);
		return SUCCESS;
	}
	else
	{
		return GuildHelper::createGuildTeam(player);
	}
}

int GuildHelper::exitGuildTeam(Entity *player, Guild *guild)
{
	if (guild == NULL) return ERROR_GUILD_NO_GUILD;

	int teamid = player->getProp(ENTITY_PROP_GUILD_TEAM_ID);
	if (teamid == 0) return ERROR_YOU_NOT_TEAM;

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL) return ERROR_UNKNOWN;

	GuildTeam *team = teamM->getTeam(teamid);
	if (team == NULL) return ERROR_UNKNOWN;

	if (team->size() == 1)
	{
		teamM->destroyTeam(teamid);
	}
	else
	{
		team->rmvMember(player);

		MsgGuildUpdateTeamNotify *notify = new MsgGuildUpdateTeamNotify;
		notify->teamid = team->getTeamID();
		notify->count = team->size();
		guild->sendMessage(notify);
	}

	// 策划需求返回原场景
	//lua::call(lua::L, "Scene.conveyEntityToScene", player, 4);
	SceneOperationHelper::conveyEntityBack(*player);
	return lua::getinteger(1);
}

int GuildHelper::sendGuildChat(Entity *player)
{
	Guild *guild = g_guild_mgr.getGuildByID(player->getProp(ENTITY_PROP_GUILD_ID));
	if (guild == NULL) return ERROR_GUILD_NO_GUILD;

	int teamid = player->getProp(ENTITY_PROP_GUILD_TEAM_ID);
	if (teamid == 0) return ERROR_YOU_NOT_TEAM;

	GuildTeamM *teamM = guild->getTeamManager();
	if (teamM == NULL) return ERROR_UNKNOWN;

	GuildTeam *team = teamM->getTeam(teamid);
	if (team == NULL) return ERROR_UNKNOWN;

	if (!team->isLeader(player->getGlobalID())) return ERROR_NOT_TEAM_LEADER;

	if (team->getProp(TEAM_PROP_STATUS) == 2) return SUCCESS;

	if (get_time() - team->getProp(TEAM_PROP_CHAT_TIME) < 30)
		return ERROR_GUILD_TEAM_SPEAK_TOO_FAST;

	lua::call(lua::L, "Guild.getGuildChatText", teamid);
	std::string text = lua::getstring(1);

	EntityOperationHelper::syncChatMsg(player, CHAT_TYPE_GUILD, text);
	team->setProp(TEAM_PROP_CHAT_TIME, get_time());
	return SUCCESS;
}

void GuildHelper::syncGuildGatherList(Scene *scene)
{
	if (!scene) return;

	std::vector<Gather> GatherVec;

	scene->for_each_player([&GatherVec](Entity *entity){
		if (entity)
		{
			EventData *edata = entity->getEventData(EVENT_GHCJRECORD1);
			if (edata)
			{
				Gather gather;
				gather.pid = entity->getGlobalID();
				gather.point = edata->getDataZ();
				gather.sumkill = edata->getDataY();
				gather.level = entity->getLevel();
				gather.rebron = entity->getProp(ENTITY_PROP_REBORN);
				gather.name = entity->getName();
				GatherVec.push_back(gather);
			}
		}
	});

	if (!GatherVec.empty())
	{
		MsgGuildGatherListNotify *notify = new MsgGuildGatherListNotify;
		notify->GatherList = GatherVec;
		scene->sendMessage(notify);
	}
}

void GuildHelper::syncGuildGatherKill(Scene *scene, Entity *killer, Entity *target, int cnt)
{
	if (!killer || !target || !scene) return;

	MsgGuildGatherKillNotify *notify = new MsgGuildGatherKillNotify;
	notify->pid = killer->getGlobalID();
	notify->job = killer->getClass();
	notify->gender = killer->getProp(ENTITY_PROP_GENDER);
	notify->isdead = killer->getProp(ENTITY_PROP_GATHER_DEAD_TIMES);
	notify->tpid = target->getGlobalID();
	notify->tjob = target->getClass();
	notify->tgender = target->getProp(ENTITY_PROP_GENDER);
	notify->killNum = cnt;
	notify->name = killer->getName();
	notify->tname = target->getName();
	scene->sendMessage(notify);
}

void GuildHelper::syncGuildGatherBlance(Scene *scene, std::vector<Balance> &balanVec)
{
	scene->for_each(ENTITY_SCOPE_PLAYER, [&](Entity *e){
		if (e)
		{
			MsgGuildGatherBalanceNotify *notify = new MsgGuildGatherBalanceNotify;
			notify->balanceList = balanVec;
			e->sendMessage(notify);
		}
	});
}

//保存行会商店物品
void GuildHelper::saveGuildShopItem(Guild &guild, int sid)
{
	if ((guild.getGuildID() <= 0) || (sid <= 0))
	{
		return;
	}

	MsgDBGuildShopAdd *dbmsg = new MsgDBGuildShopAdd;
	dbmsg->guildId = guild.getGuildID();
	dbmsg->sid = sid;
	g_app.postToNetService(dbmsg);
}

// 初始化行会商店物品
void GuildHelper::initGuildShop()
{
	std::vector<Guild *> &guilds = g_guild_mgr.getGuilds();
	size_t guild_count = guilds.size();
	for (size_t i = 0; i < guild_count; ++i)
	{
		Guild *guild = guilds[i];

		GuildShop *shop = guild->getShop();
		if (shop == nullptr)
		{
			continue;
		}

		if (shop->isShopNull())
		{
			lua::call(lua::L, "Guild.refreshShop", guild);
		}
	}
}

// 同步商店物品信息
void GuildHelper::syncGuildShop(Guild &guild)
{
	GuildShop *guild_shop = guild.getShop();
	if (guild_shop == nullptr)
	{
		return;
	}

	MsgSyncGuildShopNotify *notify = new MsgSyncGuildShopNotify;

	notify->pid = guild.getGuildID();
	const std::vector<ShopGuildItem>& items_list = guild_shop->getItems();

	ShopItemInfo itemInfo;
	for (size_t i = 0; i < items_list.size(); ++i)
	{
		const ShopGuildItem &item = items_list[i];
		itemInfo.sid = item.itemID;
		itemInfo.sellCount =item.count;
		notify->items.push_back(itemInfo);
	}

	guild.sendMessage(notify);
}

int GuildHelper::buyItem(EntityPlayer &player, int sid, int cnt)
{
	Guild *guild = g_guild_mgr.getGuildByID(player.getProp(ENTITY_PROP_GUILD_ID));
	if (guild == NULL)
	{
		return ERROR_NOT_IN_GUILD;
	}

	if (cnt < 1)
	{
		return ERROR_UNKNOWN;
	}

	GuildShop *guild_shop =  guild->getShop();
	if (guild_shop == NULL)
	{
		return ERROR_NOT_IN_GUILD;
	}

	bool has = guild_shop->hasItem(sid);
	if (!has)
	{
		return ERROR_UNKNOWN;
	}

	lua::call(lua::L, "Guild.buyItem",guild,&player,sid,cnt);
	int errorCode = lua::getinteger(1);

	return errorCode;
}

// 清理帮会商店物品
void GuildHelper::DelShopItems()
{
	MsgDBGuildShopDel *msg = new MsgDBGuildShopDel;
	g_app.postToNetService(msg);

	// 清理商城物品
	auto guilds = g_guild_mgr.getGuilds();
	std::vector<int> delGuildIds;
	for (size_t i = 0; i < guilds.size(); ++i)
	{
		Guild *guild = guilds[i];
		if (guild == nullptr)
		{
			continue;
		}

		GuildShop *shop = guild->getShop();
		if (shop == nullptr)
		{
			continue;
		}

		shop->clear();
	}
}
//购买公会限购道具
void GuildHelper::updataGuildShopItemSellNum(Guild &guild, int sid,int num)
{
	GuildShop *guild_shop = guild.getShop();
	if (guild_shop == nullptr)
	{
		return;
	}

	guild_shop->setSellNum(sid,num);

	MsgDBUpdataGuildShopItemNum *dbmsg = new MsgDBUpdataGuildShopItemNum;
	dbmsg->guildId = guild.getGuildID();
	dbmsg->sid = sid;
	dbmsg->sellCount = guild_shop->getSellNum(sid);
	g_app.postToNetService(dbmsg);

	MsgSyncGuildShopItemSellNum *notify = new MsgSyncGuildShopItemSellNum;
	notify->sid = sid;
	notify->sellCount = guild_shop->getSellNum(sid);
	guild.sendMessage(notify);
}


void GuildHelper::saveGuildGuishiItem(Guild &guild, ShopGuishiItem *item)
{
	if ((guild.getGuildID() <= 0) || (item->sid <= 0))
	{
		return;
	}

	MsgDBGuildGuishiAdd *dbmsg = new MsgDBGuildGuishiAdd;
	dbmsg->guildId = guild.getGuildID();
	dbmsg->sid = item->sid;
	dbmsg->cid = item->cid;
	g_app.postToNetService(dbmsg);
}

// 同步鬼市
void GuildHelper::syncGuildGuishi(Guild &guild)
{
	GuildGuishi *guild_guishi = guild.getGuishi();
	if (guild_guishi == nullptr)
	{
		return;
	}

	MsgSyncGuildGuishiItemsNotify *notify = new MsgSyncGuildGuishiItemsNotify;

	notify->gid = guild.getGuildID();
	const auto &items_list = guild_guishi->getItems();

	auto it = items_list.begin();
	while (it!= items_list.end())
	{
		GuishiItem iteminfo;

		iteminfo.sid = it->second->sid;
		iteminfo.cid = it->second->cid;

		notify->items.push_back(iteminfo);
		++it;
	}

	guild.sendMessage(notify);
}

void GuildHelper::saveGuildGuishiItemDelete(Guild &guild, int item_id, Entity *entity)
{
	if (guild.getGuildID() <= 0)
	{
		return;
	}

	if (item_id <= 0)
	{
		return;
	}

	MsgDBGuildGuishiDel *dbmsg = new MsgDBGuildGuishiDel;
	dbmsg->setSessionID((entity != nullptr) ? entity->getSessionID() : 0);
	dbmsg->guildId = guild.getGuildID();
	dbmsg->cid = item_id;
	g_app.postToNetService(dbmsg);
}

//同步行会物品删除给玩家
void GuildHelper::syncGuildGuishiItemDelete(Guild &guild, int item_id)
{
	if (guild.getGuildID() <= 0 ||item_id <= 0 )
	{
		return;
	}

	MsgDelGuildGuishiItemNotify *notify = new MsgDelGuildGuishiItemNotify;
	notify->cid = item_id;
	guild.sendMessage(notify);
}


void GuildHelper::syncGuildGuishiItemAdd(Guild &guild, ShopGuishiItem *item)
{
	if (guild.getGuildID() <= 0)
	{
		return;
	}
	if (item == nullptr)
	{
		return;
	}
	if (item->sid < 0)
	{
		return;
	}

	MsgAddGuildGuishiItemNotify *notify = new MsgAddGuildGuishiItemNotify;
	notify->gid = guild.getGuildID();
	notify->items.sid = item->sid;
	notify->items.cid = item->cid;

	guild.sendMessage(notify);
}

//gid1---->gid2
void GuildHelper::mergeGuild(int gid1, int gid2)
{
	Guild* guild1 = g_guild_mgr.getGuildByID(gid1);
	Guild* guild2 = g_guild_mgr.getGuildByID(gid2);
	if (!guild1 || !guild2)
	{
		return;
	}
	
	guild1 = g_guild_mgr.rmvGuild(gid1);
	if (!guild1)
	{
		return;
	}
	lua::call(lua::L, "Guild.rmvGuildBuff", guild1);
	lua::call(lua::L, "GCZ.onGuildRelease", guild1);
	OperationHelper::recordGuildOp(*guild1, guild1->getMasterPid(), guild1->getMasterName(), 0, "", OP_GUILD_DISMISS, GUILD_REASON_MERGE);
	std::vector<GuildMember *> &mebers = guild1->getMembers();
	std::vector<GuildMember> mergeMembers;
	size_t count = mebers.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member1 = mebers[i];
		EntityPlayer *player = member1->player;

		GuildMember mergeMember;
		mergeMember.player_name = member1->player_name;
		mergeMember.player_id = member1->player_id;
		mergeMember.level = member1->level;
		mergeMember.post = GUILD_POST_NORMAL;
		mergeMember.player = player;
		mergeMember.gender = member1->gender;
		mergeMember.intime = get_time();
		mergeMember.speek = 0;
		mergeMember.offTime = member1->offTime;
		mergeMembers.push_back(mergeMember);
	}

	std::vector<GuildMember *> &beforeMembers = guild2->getMembers();
	count = beforeMembers.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember* beforeMember = beforeMembers[i];
		lua::call(lua::L, "Guild.sendMergeGuildSuccessMail", beforeMember->player_id, guild1->getGuildName());
	}

	MsgDBGuildDelete *dbmsg = new MsgDBGuildDelete;
	dbmsg->guildid = gid1;
	g_app.postToNetService(dbmsg);
	delete guild1;

	count = mergeMembers.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember mergeMember = mergeMembers[i];
		addGuildMember(*guild2, mergeMember.player_id, 0, mergeMember.level, mergeMember.job, mergeMember.gender, mergeMember.player_name, mergeMember.sponsorGrade);
		syncMemberChange(*guild2, mergeMember.player_id);
		EntityPlayer* player = mergeMember.player;
		if (player)
		{
			syncGuildAllInfo(*player);
			syncMeetGuildName(*player);
		}
		//行会事件
		GuildHelper::addRecord(guild2, GUILD_RECORD_MEMBER_JOIN, 0, 0, mergeMember.player_name, "");
		//加入行会日志
		OperationHelper::recordGuildOp(*guild2, mergeMember.player_id, mergeMember.player_name, 0, "", OP_GUILD_ENTER);
		lua::call(lua::L, "Guild.sendMergeGuildSuccessMail", mergeMember.player_id, guild2->getGuildName());
	}
}

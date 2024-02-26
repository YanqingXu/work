#include "stdafx.h"
#include "Application.h"
#include "NetService.h"
#include "GSHelper.h"
#include "message/MsgGSToGS.h"
#include "message/MsgLogin.h"
#include "message/MsgWrapper.h"
#include "message/DBMsgConsignment.h"
#include "Entity/EntityOperationHelper.h"
#include "Entity/EntityLua.h"
#include "Entity/WorldPlayerManager.h"
#include "World/World.h"
#include "Scene/SceneOperationHelper.h"
#include "Event/EventData.h"
#include "Event/Event.h"
#include "Auction/AuctionManager.h"

/*--------------------------------------------------------------------------------跨服-----------------------------------------------------------------------------------------*
【设计目标】
1.游戏服切换跨服场景可以实现秒切
2.进入跨服场景后，不屏蔽任何原有功能，换言之，玩家在跨服可以操作一切在原服能操作的功能
3.假设一台游戏服可以容纳1000玩家，那么跨服服务器必须实现8 * 1000 容量的理论值（因为1台跨服最多会连接8台游戏服，形成一个战区）
4.在不大量修改服务器架构的情况下解决上述问题

【问题分析】
Q: 游戏服切换跨服场景可以实现秒切
A: 玩家在登陆现有服务器的时候，会同步大量的属性，每条属性都是以一条独立消息同步，会造成客户端进入服务器异常缓慢，所以为解决上述问题，
   在角色登陆跨服时，我会将所有需要同步的属性放到一条消息里下发给客户端

Q: 进入跨服场景后，不屏蔽任何原有功能，换言之，玩家在跨服可以操作一切在原服能操作的功能
A: 所有的游戏功能可以分为两类：①玩家相关的，对应的功能数据都存在玩家表里  ②游戏世界相关的，对应的功能数据都存在世界表里；
   按之前项目的跨服逻辑，我们只能将玩家相关的功能数据同步给跨服，而游戏世界相关功能的数据同步会带来额外的开销（开发以及维护困难），所以，
   解决世界相关的功能的正常使用至关重要，既然该数据同步给跨服比较困难，我们考虑是否可以不同步该类数据也能让玩家在跨服时正常使用
   
Q: 假设一台游戏服可以容纳1000玩家，那么跨服服务器必须实现8 * 1000 容量的理论值（因为1台跨服最多会连接8台游戏服，形成一个战区）
A: 现有的游戏服的通信架构 和 跨服的通信架构是一样的，所以在物理机配置一样的情况下，不可能实现跨服承载是游戏服的8倍，那么突破点，只能是修改跨服
   的通信机制，现有的服务器架构之所以承载量有限，一个重要的原因就是数据库的瓶颈，玩家的所有数据都是实时存储，代码遍地都是saveprop（）这样的数据库
   存储调用，在没有memcache数据库的情况下，mysql根本扛不住，所以我们考虑是否可以减少甚至避免跨服服务器的mysql读写操作

【设计思路】
基于Q2的分析，我们很容易想到，当玩家进入跨服服务器的时候，保留游戏服的玩家对象，让该对象去完成世界相关的功能操作，操作之后产生的数据变化再同步给跨服
的自己，这样就可以实现不同步世界数据到跨服的情况下，玩家也能完成游戏世界相关功能的操作；对于Q3，玩家在跨服的时候，势必会有写数据库的操作，那么我们可以通过将
写请求相关的操作转发给游戏服，让游戏服的玩家对象完成mysql的写操作，这样，既不会增加游戏服的mysql读写操作，又完避免了跨服的mysql读写，当然，仅避免mysql读写
并不能解决跨服服务器的承载问题，我们还应该减少跨服的消息量，自然而然的，我们想到让游戏服的玩家对象去分担部分的客户端操作请求。

【解决方案】
1.客户端保持两条tcp连接，一条连接游戏服，一条连接跨服，客户端的操作请求根据情况选择交给游戏服对象或者跨服对象处理，从而实现分流（原则是，场景相关的交由跨服对象处理，其他由游戏服对象处理）；
2.玩家在进入跨服时，保留游戏服的玩家对象，仅从当前场景中移除，然后将对象的部分场景操作所需的数据（以下称为基础数据）以序列化的形式发送给跨服，跨服根据这部分数据创建一个
  分身对象，该对象仅处理场景相关的操作（通俗点讲，就是你的该操作必须要用到scene对象），场景无关的操作全部由游戏服的对象完成；
3.跨服的分身对象仅用来展示，如果跨服分身的某些操作产生了需要持久化的数据，那么会将该操作转发给游戏服的玩家对象完成（举个例子，记录玩家的boss击杀数量，假如在跨服击杀了一只boss，我们不是直接
  修改记录boss数量对应的属性，而是将击杀boss这个操作转发给游戏服的玩家对象，由该对象修改对应的属性值并保存到数据库，接着再同步给跨服的分身玩家）
4.分身对象只会同步操作请求给游戏服对象，绝不会直接同步玩家数据给游戏服，换言之，玩家的数据流向是单向的，只会从游戏服对象流向跨服分身对象；
5.游戏服的玩家对象会定时监测基础数据，一旦数据发生变化，会同步给跨服的分身对象，从而保证原服对象的基础数据和跨服分身对象的基础数据是一致的；
6.玩家自生的数据的更新一定是游戏服的玩家对象先更新，然后再同步给跨服的分身玩家，换言之，必须保证玩家数据的单向流动；
7.细节请看源码；
*****************************************************************************************************************************************************************************************/

/*-----------------------------------------------------------------------跨服开发指南-----------------------------------------------------------------------------------------*
【从游戏服进入跨服阶段】
1. 主玩家对象依然留在原服服务器内存，但是会从当前场景中移除，此时，若在原服处理玩家相关的功能逻辑，切记不能用玩家身上的scene对象，因为此对象为nullptr;
2. 将玩家的以下模块同步给跨服，用以在跨服创建一个用于场景相关操作的分身玩家对象：
	①、指定范围内的人物整型和字符串属性，范围区间用以下字段表示 【游戏服需要实时同步给跨服的属性 START】 【游戏服需要实时同步给跨服的属性 END】
	②、全部的战斗属性，即 COMBAT_PROP_BEGIN --> COMBAT_PROP_END
	③、部分基因（通过基因配置表里的mapReleated字段筛选）
	④、指定范围内的EVENT属性（EVENT_GS_CS_COMMON_BEGIN --> EVENT_GS_CS_COMMON_END）
	⑤、全部的技能（combat.h中的m_skill_map)

【跨服playing阶段】
1. 原服以下模块的变更会实时同步给跨服的分身玩家：
	①、指定范围内的人物整型和字符串属性，范围区间用以下字段表示 【游戏服需要实时同步给跨服的属性 START】 【游戏服需要实时同步给跨服的属性 END】
	②、全部的战斗属性，即 COMBAT_PROP_BEGIN --> COMBAT_PROP_END
	③、部分基因（通过基因配置表里的mapReleated字段筛选）
	④、指定范围内的EVENT属性（EVENT_GS_CS_COMMON_BEGIN --> EVENT_GS_CS_COMMON_END）
	⑤、全部的技能（combat.h中的m_skill_map)
2. 场景相关的操作（即该操作的完成需要用到玩家的scene对象），由客户端直接发给跨服的分身玩家进行处理（比如： 走路， 放技能， 切换战斗模式）;
3. 非场景相关的操作（即该操作的完成不需要用到玩家的scene对象），由客户端直接发给原服的主玩家进行处理（绝大多数客户端点点点的功能都是场景无关的操作，比如强化，充值，寻宝等等）;
4. 原服的一切操作，【绝对】 【绝对】 【绝对】不能用到scene对象，因为scene对象为nullptr;
5. 跨服屏蔽了所有持久化玩家数据的接口;
6. 在跨服，一切玩家相关的数据【严禁】 【严禁】 【严禁】 回传给原服（确保无论当跨服发送多么严重的bug，原服的真实玩家的数据不会被污染），当然，一切都有例外
		====》仅以下数据能回传给原服《======：
		EVENT_GS_CS_COMMON_BEGIN --> EVENT_GS_CS_COMMON_END，该区间的事件属性，在调用saveEvent之后，会回传给原服，并且持久化到数据库，换言之，假如在跨服处理了一些逻辑后，产生了需要
		持久化的数据,并且该数据需要得到及时刷新（通过回传操作，再同步数据的方式有延时性，换言之就是先更新游戏服对象数据，再更新跨服分身对象数据，和上述方式正好相反），辣么，
		就在上述区间里定义一个EVENT事件用于保存相关数据

【从跨服回到游戏服阶段】
1. 直接销毁跨服的分身对象,无需数据同步

【其他注意点】
待补充............................

*****************************************************************************************************************************************************************************************/

int GSHelper::enterCSMap(Entity* entity, int dstMapId, int posX, int posY)
{
	EntityPlayer *player = (EntityPlayer *)entity;

	if (player == nullptr)
	{
		return ERROR_INVALID_ENTITY;
	}

	if(!player->isAlive() || player->getState() == ENTITY_STATE_OFFLINE)
	{
		return ERROR_PLAYER_IS_DEAD;
	}

	if (!lua::call(lua::L, "Cross.checkCanEnter", player, player->getSceneStaticID(), dstMapId))
	{
		return ERROR_SCRIPT;
	}
	int canEnter = lua::getinteger(1);
	if(canEnter != SUCCESS)
	{
		return canEnter;
	}

	if (!lua::call(lua::L, "Cross.getEnterCSMapReason", dstMapId))
	{
		return ERROR_SCRIPT;
	}
	int reason = lua::getinteger(1);
	int crossServerId = 0;

	if(reason == REASON_WAR_ZONE)
	{
		crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);
		player->setProp(ENTITY_PROP_WAR_ZONE_LINE_ID, g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO));
	}
	else if (reason == REASON_COMMON_CS)
	{
		crossServerId = g_world.getWorldDataX(WORLD_PROP_COMMON_CROSS_SERVER_ID);
	}
	else
	{
		return ERROR_INVALID_PARAM;
	}

	if(!g_app.GetNetService()->isCSConnected(crossServerId))
	{
		return ERROR_FUNCTION_DISABLED;
	}

	CrossServerInfo info;
	g_app.GetNetService()->getCrossServerInfo(crossServerId, info);
	if(info.serverPort == 0)
	{
		return ERROR_FUNCTION_DISABLED;
	}

	//通知客户端去连接跨服服务器
	MsgChangeServerNotify *notify = new MsgChangeServerNotify;
	notify->addr = info.serverAddr;
	notify->port = info.serverPort;
	notify->serverID = player->getProp(ENTITY_PROP_SERVER_ID);
	player->sendMessage(notify);

	//在跨服创建玩家
	createPlayerInCrossServer(player, crossServerId, dstMapId, posX, posY);

	return ERROR_DELAY_ENTER;
}

int GSHelper::enterGSMap(Entity* entity, int reason, int dstMapId, int posX, int posY,int sceneInstanceId, int enterSceneType)
{
	EntityPlayer *player = (EntityPlayer *)entity;

	if (player == nullptr)
	{
		return ERROR_UNKNOWN;
	}

	if(dstMapId != 0)
	{
		if (!lua::call(lua::L, "Cross.checkCanEnter", player, 0, dstMapId))
		{
			return ERROR_UNKNOWN;
		}
		int canEnter = lua::getinteger(1);
		if(canEnter != SUCCESS)
		{
			return canEnter;
		}
	}

	//离开跨服地图
	MsgLeaveFromCrossServerMapRequest* request = new MsgLeaveFromCrossServerMapRequest;
	request->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	request->sourceServerId = g_world.getID();
	request->playerId = player->getPlayerID();
	request->dstMapId = dstMapId;
	request->posX = posX;
	request->posY = posY;
	request->reason = reason;
	request->sceneInstanceId = sceneInstanceId;
	request->enterSceneType = enterSceneType;
	g_app.postToNetService(request);

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: send leave csMap request to cross server, playerInfo = {player_id = %d, player_name = %s, cross_server_id = %d}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	}

	return ERROR_DELAY_ENTER;
}

int GSHelper::switchCSMap(Entity* entity , int dstMapId, int posX, int posY)
{
	EntityPlayer *player = (EntityPlayer *)entity;

	if (player == nullptr)
	{
		return ERROR_UNKNOWN;
	}

	int oldCSMapId = player->getProp(ENTITY_PROP_CROSS_MAP_ID);
	if(oldCSMapId == 0)
	{
		return ERROR_DELAY_ENTER;
	}

	if (!lua::call(lua::L, "Cross.checkCanEnter", player, oldCSMapId, dstMapId))
	{
		return ERROR_UNKNOWN;
	}
	int canEnter = lua::getinteger(1);
	if(canEnter != SUCCESS)
	{
		return canEnter;
	}

	int oldPosX = player->getProp(ENTITY_PROP_CROSS_MAP_POSX);
	int oldPosY = player->getProp(ENTITY_PROP_CROSS_MAP_POSY);
	if(oldCSMapId == dstMapId && oldPosX == posX && oldPosY == posY)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: switch csMap failed, player is already in target map, playerInfo = {player_id = %d, player_name = %s, mapId = %d}",
				player->getGlobalID(), player->getGlobalID(), player->getName().c_str(), dstMapId);
		}
		return SUCCESS;
	}

	if (!lua::call(lua::L, "Scene.isWarZoneMap", oldCSMapId))
	{
		return ERROR_SCRIPT;
	}
	bool oldMapIsWarZneMap = lua::getboolean(1);

	if (!lua::call(lua::L, "Scene.isWarZoneMap", dstMapId))
	{
		return ERROR_SCRIPT;
	}
	bool dstMapIsWarZneMap = lua::getboolean(1);

	if(oldMapIsWarZneMap && dstMapIsWarZneMap)
	{
		player->syncCommonInfoToCrossServer();
		MsgSwitchCSMapRequest *msg = new MsgSwitchCSMapRequest;
		msg->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
		msg->playerId = player->getPlayerID();
		msg->dstMapId = dstMapId;
		msg->posX = posX;
		msg->posY = posY;
		g_app.postToNetService(msg);

		player->setProp(ENTITY_PROP_FLY_REASON, 0);
		player->setProp(ENTITY_PROP_FLY_NPC, 0);
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: send switch csMap request to cross server, playerInfo = {player_id = %d, player_name = %s, dstMapId = %d}",
				player->getGlobalID(), player->getGlobalID(), player->getName().c_str(), dstMapId);
		}
	}
	else
	{
		//先回到游戏服地图
		MsgLeaveFromCrossServerMapRequest* request = new MsgLeaveFromCrossServerMapRequest;
		request->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
		request->sourceServerId = g_world.getID();
		request->playerId = player->getPlayerID();
		request->dstMapId = dstMapId;
		request->posX = posX;
		request->posY = posY;
		request->reason = REASON_SWITCH_CS_MAP;
		g_app.postToNetService(request);

		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: send leave csMap request to cross server, playerInfo = {player_id = %d, player_name = %s}",
				player->getGlobalID(), player->getGlobalID(), player->getName().c_str());
		}
	}

	if(oldCSMapId > 0)
	{
		int sceneType = SceneOperationHelper::getSceneType(oldCSMapId);
		if(sceneType == SCENE_TYPE_NORMAL)
		{
			player->setProp(ENTITY_PROP_OLD_MAPID, oldCSMapId);
			player->setProp(ENTITY_PROP_OLD_X, oldPosX);
			player->setProp(ENTITY_PROP_OLD_Y, oldPosY);

			EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_OLD_MAPID);
		}
	}

	return ERROR_DELAY_ENTER;
}

void GSHelper::createPlayerInCrossServer(EntityPlayer *player, int crossServerId, int dstMapId,  int posX, int posY)
{
	MsgCreatePlayerInCrossServerRequest *msg = new MsgCreatePlayerInCrossServerRequest;
	msg->setUserData(crossServerId);
	msg->dstMapId = dstMapId;
	msg->posX = posX;
	msg->posY = posY;
	player->serialize(msg);
	g_app.postToNetService(msg);

	player->onLeaveGSMap(crossServerId, dstMapId);

	MsgCreatePlayerInCrossServerEnd *endMsg = new MsgCreatePlayerInCrossServerEnd;
	endMsg->setUserData(crossServerId);
	endMsg->playerId = player->getPlayerID();
	g_app.postToNetService(endMsg);

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: send create player request to cross server, playerInfo = {player_id = %d, player_name = %s, cross_server_id = %d, dst_map = %d}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), crossServerId, dstMapId);
	}
}

void GSHelper::kickPlayerFromCS(EntityPlayer* player)
{
	MsgKickPlayerFromCSRequest *req = new MsgKickPlayerFromCSRequest;
	req->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
	req->playerId = player->getPlayerID();
	g_app.postToNetService(req);
}

void GSHelper::revivePlayerInCS(EntityPlayer* player, int type, int subType)
{
	if(type == REVIVE_MODE_SAFE)   //回城复活
	{
		bool ret = true;
		if (lua::call(lua::L, "Scene.checkReviveInCurMap", player->getProp(ENTITY_PROP_CROSS_MAP_ID)))
		{
			ret = lua::getboolean(1);
		}
		
		if(ret)
		{
			//安全复活
			MsgReviveInCSMapRequest* req = new MsgReviveInCSMapRequest;
			req->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
			req->playerId = player->getPlayerID();
			req->subType = -1;
			g_app.postToNetService(req);
		}
		else
		{
			//回城复活
			enterGSMap(player, LeaveCSMapReason::REASON_REVIVE);
		}
	}
	else  //原地复活
	{
		//检查复活条件
		bool ret = false;
		if(subType == INPLACE_REVIVE_FREE)			//免费复活
		{
			if (!lua::call(lua::L, "Vip.checkFreeDeadRelive", player))
			{
				return;
			}
			ret = lua::getboolean(1);
		}
		else if(subType == INPLACE_REVIVE_DIAMOND)		//钻石复活
		{
			int64 myDiamond = player->getProp(ENTITY_PROP_LINGFU) + player->getProp(ENTITY_PROP_BOUND_LINGFU);

			EventData* eventData = player->getEventData(EVENT_JRFH);
			if (eventData == nullptr)
			{
				return;
			}

			if(!lua::call(lua::L,"Entity.getPayReliveCost",eventData->getDataX()))
			{
				return;
			}
			int price = lua::getinteger(1);

			if (myDiamond < price)
			{
				return;
			}
			ret = true;
		}
		
		if(ret)
		{
			MsgReviveInCSMapRequest* req = new MsgReviveInCSMapRequest;
			req->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
			req->playerId = player->getPlayerID();
			req->subType = subType;
			g_app.postToNetService(req);
		}
	}
}

void GSHelper::useItemInCSMap(Entity* entity, int sid, int count, int rid, int targetType)
{
	if(entity == nullptr || entity->getType() != ENTITY_TYPE_PLAYER)
	{
		return;
	}

	MsgUseItemInCSMapRequest* req = new MsgUseItemInCSMapRequest;
	req->setUserData(entity->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	req->playerId = entity->getGlobalID();
	req->sid = sid;
	req->count = count;
	req->rid = rid;
	req->targetType = targetType;
	g_app.postToNetService(req);
}

void GSHelper::syncEventDataToCS(Entity* entity, int eid)
{
	EntityPlayer *player = (EntityPlayer*)entity;

	if(player == nullptr)
	{
		return;
	}

	EventData *event_data = player->getEventData(eid);
	if (event_data == nullptr)
	{
		return;
	}

	const LastSaveEventData& lastSaveData = event_data->getLastSaveData();

	MsgSyncEventDataRequest* req = new MsgSyncEventDataRequest;
	req->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	req->playerId = player->getGlobalID();
	req->data.id = event_data->getID();
	req->data.timeIndex = event_data->getTimeIndex();
	req->data.datax = event_data->getDataX() - lastSaveData.m_datax;
	req->data.datay = event_data->getDataY() - lastSaveData.m_datay;
	req->data.dataz = event_data->getDataZ() - lastSaveData.m_dataz;

	g_app.postToNetService(req);
}

void GSHelper::resetAndSyncAllEventToCS(Entity* entity)
{
	EntityPlayer *player = (EntityPlayer*)entity;

	if(player == nullptr)
	{
		return;
	}

	if(g_config.isCrossServer() || player->isInGSMap())
	{
		return;
	}

	MsgResetAndSyncAllEventDataNotify* notify = new MsgResetAndSyncAllEventDataNotify;
	notify->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	notify->playerId = player->getGlobalID();

	for(int eid = EVENT_GS_CS_COMMON_BEGIN + 1; eid < EVENT_GS_CS_COMMON_END; eid++)
	{
		EventData* eventData = player->getEventData(eid);
		if(eventData != nullptr)
		{
			CrossEventData data;
			data.id = eventData->getID();
			data.datax = eventData->getDataX();
			data.datay = eventData->getDataY();
			data.dataz = eventData->getDataZ();
			data.timeIndex = eventData->getTimeIndex();
			notify->events.push_back(data);
			eventData->cacheLastSaveData();
		}
	}

	std::set<int> events = EntityOperationHelper::getPlayerEventCross();
	for (auto iter = events.begin(); iter != events.end(); ++iter)
	{
		int eid = *iter;
		EventData* eventData = player->getEventData(eid);
		if(eventData != nullptr)
		{
			CrossEventData data;
			data.id = eventData->getID();
			data.datax = eventData->getDataX();
			data.datay = eventData->getDataY();
			data.dataz = eventData->getDataZ();
			data.timeIndex = eventData->getTimeIndex();
			notify->events.push_back(data);
			eventData->cacheLastSaveData();
		}
	}

	if(notify->events.size() > 0)
	{
		g_app.postToNetService(notify);
	}
	else
	{
		delete notify;
	}
}

void GSHelper::getQualifiedPlayerListNearby(EntityPlayer* player, int condition)
{
	MsgGetQualifiedPlayerListNearbyRequest *req = new MsgGetQualifiedPlayerListNearbyRequest;
	req->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	req->pid = player->getPlayerID();
	req->condition = condition;
	g_app.postToNetService(req);
}

bool GSHelper::addItemToCrossAuction(DBAcution* au)
{
	int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);
	if(crossServerId == 0)
	{
		return false;
	}

	if(!g_app.GetNetService()->isCSConnected(crossServerId))
	{
		return false;
	}

	au->war_zone_id = crossServerId * 1000 + g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
	au->status = 1;

	MsgAddItemToCrossAuctionRequset* req = new MsgAddItemToCrossAuctionRequset;
	req->setUserData(crossServerId);
	req->auctionItem = *((CrossAcution*)au);
	g_app.postToNetService(req);

	return true;
}

int GSHelper::checkBuyCrossAuctionItem(EntityPlayer* player, int64 aid, short type, int payMoney)
{
	DBAcution* ac = g_acution_mgr.get_cross_acution_item_cache(aid);
	if(ac == nullptr)
	{
		return ERROR_ACUTION_ALREADY_SELLED;
	}

	int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);
	if(crossServerId == 0)
	{
		return ERROR_FUNCTION_DISABLED;
	}

	if(!g_app.GetNetService()->isCSConnected(crossServerId))
	{
		return ERROR_FUNCTION_DISABLED;
	}

	if(type == 3 && ac->buyer_pid == player->getPlayerID())
	{
		return ERROR_AUCTION_PRICE_MAX;
	}

	int sum_price = 0;
	if(type == 3)
	{
		int add_price = -1;
		if (lua::call(lua::L, "Consignment.getAcutionAddPrice", ac->sid))
		{//获取拍卖道具的信息
			add_price = lua::getinteger(1);
		}
		if (add_price == -1) return ERROR_UNKNOWN;

		sum_price = (ac->cur_price == 0) ? ac->start_price : ac->cur_price + add_price ;
		if (sum_price >= ac->fixed_price)
		{
			sum_price = ac->fixed_price;
		}

		if(sum_price != payMoney)
		{
			return ERROR_CUR_PRICE_CHANGED;
		}
	}
	else
	{
		sum_price = ac->fixed_price;
	}
	
	if (ac->things_type == ITEM_LINGFU)
	{
	
	}
	else
	{
		return ERROR_UNKNOWN;
	}

	MsgCheckBuyCrossAuctionItemRequest* req = new MsgCheckBuyCrossAuctionItemRequest();
	req->setUserData(crossServerId);
	req->buyer_pid = player->getPlayerID();
	req->buyer_server_id = g_world.getID();
	req->buyer_war_zone_id = crossServerId * 1000 + g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
	req->aid = aid;
	req->type = type;
	g_app.postToNetService(req);

	return SUCCESS;
}

int GSHelper::buyCrossAuctionItem(EntityPlayer* player, int64 aid, short type)
{
	DBAcution* ac = g_acution_mgr.get_cross_acution_item_cache(aid);
	if(ac == nullptr)
	{
		return ERROR_ACUTION_ALREADY_SELLED;
	}

	int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);
	if(crossServerId == 0)
	{
		return ERROR_FUNCTION_DISABLED;
	}

	int sum_price = 0;
	if(type == 3)
	{
		int add_price = -1;
		if (lua::call(lua::L, "Consignment.getAcutionAddPrice", ac->sid))
		{//获取拍卖道具的信息
			add_price = lua::getinteger(1);
		}
		if (add_price == -1) return ERROR_UNKNOWN;

		sum_price = (ac->cur_price == 0) ? ac->start_price : ac->cur_price + add_price ;//* it->count;
		if (sum_price >= ac->fixed_price)
		{
			sum_price = ac->fixed_price;
		}
	}
	else
	{
		sum_price = ac->fixed_price;
	}

	if (ac->things_type == ITEM_LINGFU)
	{
		
	}
	else
	{
		return ERROR_UNKNOWN;
	}

	MsgBuyCrossAuctionItemRequest* req = new MsgBuyCrossAuctionItemRequest();
	req->setUserData(crossServerId);
	req->buyer_pid = player->getPlayerID();
	req->buyer_name = player->getName();
	req->buyer_server_id = g_world.getID();
	req->buyer_war_zone_id = crossServerId * 1000 + g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
	req->cost_money = sum_price;
	req->money_type = ac->things_type;
	req->aid = aid;
	req->sid = ac->sid;
	req->type = type;
	g_app.postToNetService(req);

	LOG_INFO("CS_ACUTION: buy cross acution success! buyer_pid = %d, buy_type = %d, buy_auction_aid = %lld, cost = %d", player->getPlayerID(), type, aid, sum_price);

	return SUCCESS;
}

void GSHelper::addCrossConsignment(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName, std::string firstOwner, std::string appraiser,std::map<int,int> props, int cTime, int eTime,int mailTip)
{
	int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);

	MsgAddConsignmentToCrossRequest* req = new MsgAddConsignmentToCrossRequest();
	req->setUserData(crossServerId);
	req->pid = pid;
	req->name = name;
	req->srcServerId = g_world.getID();
	req->srcServerName = srcServerName;
	req->warZoneId = crossServerId * 1000 + g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
	req->sid = sid;
	req->count = count;
	req->taxRate = taxRate;
	req->price = price;
	req->time = hours;
	req->firstOwner = firstOwner;
	req->appraiser = appraiser;
	req->cTime = cTime;
	req->eTime = eTime;
	req->mailTip = mailTip;
	std::vector<CrossConsignmentItemProp> teprops;
	for (auto iter = props.begin();iter != props.end(); iter ++)
	{
		CrossConsignmentItemProp itemprop;
		itemprop.idx = iter->first;
		itemprop.data = iter->second;
		teprops.push_back(itemprop);
	}
	req->props = teprops;	
	g_app.postToNetService(req);
}

void GSHelper::rmvCrossConsignment(int pid, int cid, int warZoneId)
{
	MsgRmvCrossConsignmentRequest* req = new MsgRmvCrossConsignmentRequest();
	req->setUserData(warZoneId/1000);
	req->sellerServerId = g_world.getID();
	req->sellerPid = pid;
	req->cid = cid;
	g_app.postToNetService(req);
}

void GSHelper::addCrossPurchase(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName)
{
	int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);

	MsgAddPurchaseToCrossRequest* req = new MsgAddPurchaseToCrossRequest();
	req->setUserData(crossServerId);
	req->buyerPid = pid;
	req->buyerName = name;
	req->buyerServerId = g_world.getID();
	req->buyerServerName = srcServerName;
	req->buyerWarZoneId = crossServerId * 1000 + g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
	req->sid = sid;
	req->count = count;
	req->price = price;
	req->time = hours;
	g_app.postToNetService(req);
}

void GSHelper::rmvCrossPurchase(int buyerPid, int purchaseId, int warZoneId)
{
	MsgRmvCrossPurchaseRequest* req = new MsgRmvCrossPurchaseRequest();
	req->setUserData(warZoneId/1000);
	req->buyerServerId = g_world.getID();
	req->buyerPid = buyerPid;
	req->purchaseId = purchaseId;
	g_app.postToNetService(req);
}


//for test
void GSHelper::sendGSToGSTestMsg()
{
	MsgGSToGSTestRequest* req = new MsgGSToGSTestRequest();
	req->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));  //战区服务器id
	req->setSourceSessionID(19);  //目标游戏服id
	req->sourceGameServerId = g_world.getID();  //源游戏服的id

	g_app.postToNetService(req);
}

void GSHelper::playerCSActionTrigger(Entity* entity, int actionType, std::map<int, int>& intParams, std::map<int, std::string>& strParams)
{
	switch (actionType)
	{
	case CROSS_ACTION_MONSTER_OWNER:
		{
			if(intParams[CROSS_ACTION_INT_PARAM_MONSTER_OWNER_TYPE] == OWNER_TYPE_SINGLE_PLAYER)
			{
				int mid = intParams[CROSS_ACTION_INT_PARAM_MONSTER_SID];
				int sceneId = intParams[CROSS_ACTION_INT_PARAM_SCENE_ID];
				//boss归属者
				if(entity != nullptr)
				{
					lua::call(lua::L, "Cross.killMonsterBelongToSomeone", entity, mid, sceneId, entity->getGlobalID());
					Event evt(CROSS_EVENT_GROUP_QUEST, EVENT_KILL_MONSTER,
						mid, sceneId);
					entity->onEvent(evt);

					lua::call(lua::L, "gdNewVipExtension.onMonsterDie",entity, mid);
				}

				//boss归属者的队友
				for(int key = CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_1; key <= CROSS_ACTION_INT_PARAM_MONSTER_OWNER_PID_15; key++)
				{
					auto iter = intParams.find(key);
					if(iter != intParams.end())
					{
						int pid = iter->second;
						EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(pid);
						if(player != nullptr && player->getProp(ENTITY_PROP_OFFLINE) != 1)
						{
							lua::call(lua::L, "Cross.killMonsterBelongToSomeone", player, mid, sceneId, entity ? entity->getGlobalID() : -1);

							Event evt(CROSS_EVENT_GROUP_QUEST, EVENT_KILL_MONSTER,
								mid, sceneId);
							player->onEvent(evt);
						}
					}
				}
			}
			
		}
		break;
	case CROSS_ACTION_MONSTER_LAST_ATTACKER:
		if(entity != nullptr)
		{
			lua::call(lua::L, "Tuoguan.killMonstor", entity);
		}
		break;
	case CROSS_ACTION_KILL_PLAYER:
		{
			if(entity != nullptr)
			{
				lua::call(lua::L, "Cross.killPlayer", entity);
			}
		}
		break;
	case CROSS_ACTION_BE_KILLED:
		{
			if(entity != nullptr)
			{
				if(intParams[CROSS_ACTION_INT_PARAM_KILLER_TYPE] == ENTITY_TYPE_PLAYER)
				{
					lua::call(lua::L, "Cross.beKilledByPlayer", entity);
				}
				else if(intParams[CROSS_ACTION_INT_PARAM_KILLER_TYPE] == ENTITY_TYPE_MONSTER)
				{
					lua::call(lua::L, "Cross.beKilledByMonster", entity);
				}
				bool isKilledByMonster = intParams[CROSS_ACTION_INT_PARAM_KILLER_TYPE] == ENTITY_TYPE_MONSTER;
				lua::call(lua::L, "Tuoguan.death", entity, isKilledByMonster);
			}
		}
		break;
	case CROSS_ACTION_KILL_PLAYER_KBZL:
		{
			if(entity != nullptr)
			{
				if(intParams[CROSS_ACTION_INT_PARAM_KBZL_DIAMOND] > 0)
				{
					std::string beKillerName = strParams[CROSS_ACTION_INT_PARAM_BEKILLER_NAME];
					lua::call(lua::L, "Entity.sendKBKillerMail",entity,beKillerName);
					lua::call(lua::L, "Entity.setKBZLKillReward", entity, intParams[CROSS_ACTION_INT_PARAM_KBZL_DIAMOND]);
				}
			}
		}
		break;
	case CROSS_ACTION_BE_KILLED_KBZL:
		{
			if(entity != nullptr)
			{
				std::string killerName = strParams[CROSS_ACTION_INT_PARAM_KILLER_NAME];
				lua::call(lua::L, "Entity.sendKBLostMail",entity,killerName);
				lua::call(lua::L, "Cross.playerBeKilledWithKBZL", entity);
			}
		}
		break;
	case CROSS_ACTION_USE_ITEM:
		{
				if (nullptr != entity)
				{
					int sid = intParams[CROSS_ACTION_INT_PARAM_ITEM_SID];
					int prop = intParams[CROSS_ACTION_INT_PARAM_ITEM_PROP];

					if (sid == 80001)	// 回城和随机石，都用 80001 代替， 用 prop 控制具体的内容
					{
						int rett = ERROR_UNKNOWN;
						if (lua::call(lua::L, "Entity.use_stone",entity,prop))
						{
							rett = lua::getinteger(1);
							if (rett == SUCCESS)
							{
								if (prop == ENTITY_PROP_STONE_RANDOM_CD)
								{
									lua::call(lua::L, "Item.useStoneRandom",entity);
								}
								if (prop==ENTITY_PROP_STONE_GOHOME_CD)
								{
									lua::call(lua::L, "Item.useStoneHome",entity);
								}
							}
						}
							
					}
				}
		}
		break;
	case CROSS_ACTION_GOTO_MAP://进入地图
		
		break;
	case CROSS_ACTION_FAOBAO:
		if(entity !=nullptr)
		{
			EntityPlayer *player = dynamic_cast<EntityPlayer *>(entity);
			if(player != nullptr)
			{
				int cdtime = intParams[CROSS_ACTION_INT_PARAM_FABAO_CD];
				player->setProp(ENTITY_PROP_FABAO_CD,cdtime);
				EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_FABAO_CD);
			}
		}
		break;
	case CROSS_ACTION_CD_TIME:
		if(entity !=nullptr)
		{
			// 用之前一定要先定义
			std::map<int,int> cdprop;
			cdprop[ENTITY_PROP_ARTIFACT_XR_CD] = 1;
			cdprop[ENTITY_PROP_ARTIFACT_YS_CD] = 1;

			EntityPlayer *player = dynamic_cast<EntityPlayer *>(entity);
			if(player != nullptr)
			{
				int cdtype = intParams[CROSS_ACTION_INT_PARAM_TIMECD_TYPE];
				int cdtime = intParams[CROSS_ACTION_INT_PRRAM_TIMECD_VALUE];
				if (!cdprop[cdtype])
				{
					LOG_ERROR("player-> %d, corss  a undefinde type -> %d",entity->getGlobalID(),cdtype);
				}else
				{
					player->setProp(cdtype,cdtime);
					EntityOperationHelper::saveEntityProp(*player, cdtype);
				}
			}
		}
		break;
	default:
		break;
	}
}

void GSHelper::onWarZoneChanged(int oldWarZoneId, int newWarZoneId)
{
	//踢出还在旧战区的玩家
	g_world_player_mgr.onGSLostCSConnection(oldWarZoneId/1000);
	if(oldWarZoneId != newWarZoneId)
	{
		g_world_player_mgr.for_each([&](EntityPlayer* player){
			if(player != nullptr && player->getProp(ENTITY_PROP_OFFLINE) != 1)
			{
				g_scene_mgr.syncAllBossInfoToPlayer(player);
			}
		});
	}
}


void GSHelper::wrapSceneMessage(Entity& entity, Message* msg)
{
	if(msg == nullptr)
	{
		return;
	}

	if(entity.getType() != ENTITY_TYPE_PLAYER)
	{
		delete msg;
		return;
	}
	int pid = 0;
	int crossServerId = 0;
	pid = entity.getGlobalID();
	crossServerId = entity.getProp(ENTITY_PROP_CROSS_SERVER_ID);

	entity.syncCommonInfoToCrossServer();

	MsgSceneWrapper* wrapper = new MsgSceneWrapper(msg);
	wrapper->setUserData(crossServerId);
	wrapper->pid = pid;
	g_app.postToNetService(wrapper);
}


//同步英雄模型改变给跨服
void  GSHelper::sendPlayerLevelToCross(EntityPlayer* player)
{
	if(player == NULL) 
	{
		return ;
	}

	int crossServerId = player->getProp(ENTITY_PROP_CROSS_SERVER_ID);

	//发给跨服
	MsgPlayerChangeNotify* req = new MsgPlayerChangeNotify();
	req->setUserData(crossServerId);
	req->pid = player->getPlayerID();
	req->lvl= player->getLevel();
	g_app.postToNetService(req);
}

void GSHelper::sendPlayerStateToCross(EntityPlayer* player,int m_state)
{
	if (NULL == player)
	{
		return;
	}

	int crossServerId = player->getProp(ENTITY_PROP_CROSS_SERVER_ID);

	//发给跨服
	MsgCrossPlayerStateG2C* req = new MsgCrossPlayerStateG2C();
	req->setUserData(crossServerId);
	req->pid = player->getPlayerID();
	req->state= m_state;
	g_app.postToNetService(req);


}

void GSHelper::sendCrossInitDream(EntityPlayer * player)
{
	if(player == NULL) 
	{
		return ;
	}
	player->syncCommonInfoToCrossServer();
	int crossServerId = player->getProp(ENTITY_PROP_CROSS_SERVER_ID);

	//发给跨服
	MsgNotifyInitDreamNotify* req = new MsgNotifyInitDreamNotify();
	req->setUserData(crossServerId);
	req->pid = player->getPlayerID();
	g_app.postToNetService(req);
}
	

void GSHelper::getBossCntInCrossMap(EntityPlayer& player, std::map<short, int>& crossMaps,std::string targetName)
{
	std::map<std::pair<int, int>, std::vector<short> > servers;
	for (auto& it : crossMaps)
	{
		if (lua::call(lua::L, "Cross.getEnterCSMapReason", it.second))
		{
			int reason = lua::getinteger(1);
			if(reason == REASON_WAR_ZONE)
			{
				int crossServerId = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO);
				int warZoneLineId = g_world.getWorldDataY(WORLD_PROP_WAR_ZONE_INFO);
				servers[std::make_pair(crossServerId, warZoneLineId)].push_back(it.first);
			}
		}
	}

	if (!servers.empty())
	{
		for (auto& it : servers)
		{
			MsgGetBossCntInCrossMapRequest* req = new MsgGetBossCntInCrossMapRequest;
			req->setUserData(it.first.first);
			req->source_world_id = g_world.getID();
			req->warzone_line_id = it.first.second;
			req->pid = player.getPlayerID();

			for (short index : it.second)
			{
				CrossMap cm;
				cm.index = index;
				cm.map_id = crossMaps[index];
				req->cross_maps.emplace_back(cm);
			}
			req->targetName = targetName;

			g_app.postToNetService(req);
		}
	}
}

bool GSHelper::isWarZoneGameServer()
{
	if(g_config.isCrossServer())
	{
		return false;
	}

	if(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO) == 0)
	{
		return false;
	}

	return true;
}

void GSHelper::syncPlayerDeletedToCross(int pid)
{
	if(isWarZoneGameServer())
	{
		MsgSyncPlayerDeletedNotify* notify = new MsgSyncPlayerDeletedNotify;
		if(notify == nullptr)
		{
			return;
		}
		notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		notify->serverid = g_world.getID();
		notify->pid = pid;
		g_app.postToNetService(notify);
	}
}

void GSHelper::syncGuildDeletedToCross(int guildid)
{
	if(isWarZoneGameServer())
	{
		MsgSyncGuildDeletedNotify* notify = new MsgSyncGuildDeletedNotify;
		if(notify == nullptr)
		{
			return;
		}

		notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		notify->serverid = g_world.getID();
		notify->guildid = guildid;
		g_app.postToNetService(notify);
	}
}

void GSHelper::syncPlayerRenameToCross(int pid, const std::string& newname)
{
	if(isWarZoneGameServer())
	{
		MsgSyncPlayerRenameNotify* notify = new MsgSyncPlayerRenameNotify;
		if(notify == nullptr)
		{
			return;
		}
		notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		notify->serverid = g_world.getID();
		notify->pid = pid;
		notify->newName = newname;
		g_app.postToNetService(notify);	
	}
}

void GSHelper::syncGuildRenameToCross(int guildid, const std::string& newname)
{
	if(isWarZoneGameServer())
	{
		MsgSyncGuildRenameNotify* notify = new MsgSyncGuildRenameNotify;
		if(notify == nullptr)
		{
			return;
		}
		notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		notify->serverid = g_world.getID();
		notify->guildid = guildid;
		notify->newName = newname;
		g_app.postToNetService(notify);
	}
}

void GSHelper::syncGuildMasterToCross(int guildid, int masterpid)
{
	if(!isWarZoneGameServer())
	{
		return;
	}

	MsgSyncGuildMasterNotify* notify = new MsgSyncGuildMasterNotify;
	if(notify == nullptr)
	{
		return;
	}

	notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
	notify->serverid = g_world.getID();
	notify->guildid = guildid;
	notify->masterpid = masterpid;
	g_app.postToNetService(notify);
}

void GSHelper::syncPlayerJobToCross(int pid, int job)
{
	if(!isWarZoneGameServer())
	{
		return;
	}

	MsgSyncPlayerJobNotify* notify = new MsgSyncPlayerJobNotify;
	if(notify == nullptr)
	{
		return;
	}
	notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
	notify->serverid = g_world.getID();
	notify->pid = pid;
	notify->job = job;
	g_app.postToNetService(notify);
}

void GSHelper::removeGeneToCross(int pid, int geneid)
{
	if(!isWarZoneGameServer())
	{
		return;
	}

	MsgRemoveCSGeneFromeGSNotify *notify = new MsgRemoveCSGeneFromeGSNotify;
	if(notify == nullptr)
	{
		return;
	}
	notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
	notify->serverid = g_world.getID();
	notify->pid = pid;
	notify->geneid = geneid;
	g_app.postToNetService(notify);
}

void GSHelper::doctorPlayerToCorss(int pid)
{
	MsgDoctorPlayerNotify *notify = new MsgDoctorPlayerNotify;
	if(notify == nullptr)
	{
		return;
	}
	notify->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
	notify->serverid = g_world.getID();
	notify->pid = pid;
	g_app.postToNetService(notify);
}
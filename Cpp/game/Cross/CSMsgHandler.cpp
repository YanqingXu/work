#include "stdafx.h"
#include <sstream>
#include "CSMsgHandler.h"
#include "Cross/CSHelper.h"
#include "Application.h"
#include "NetService.h"
#include "Entity/EntityLua.h"
#include "Entity/WorldPlayerManager.h"
#include "Entity/EntityFactory.h"
#include "Entity/EntityOperationHelper.h"
#include "Scene/SceneOperationHelper.h"
#include "Event/EventData.h"
#include "World/World.h"
#include "OperationHelper.h"
#include "WarZoneDropBroadcast/DropBroadcastMgr.h"
#include "Consignment/ConsignmentStore.h"
#include "Holiday/HolidayOperationHelper.h"
#include "message/MsgCenter.h"
#include "message/MsgScene.h"
#include "message/MsgWrapper.h"
#include "message/DBMsgConsignment.h"
#include "Auction/AuctionManager.h"
#include "Purchase/PurchaseManager.h"
#include "Combat/CombatHelper.h"
#include "Rank/RankManager.h"

CSMsgHandler::CSMsgHandler(Service *service) :
	Module(service)
{
	//center server --> cross server
	registerMessageHandler<MsgWarZoneInfoNotify>(std::bind(&CSMsgHandler::onWarZoneInfoNotify, this, std::placeholders::_1));

	//game server --> cross server
	registerMessageHandler<MsgGS2CS>(std::bind(&CSMsgHandler::onGS2CS, this, std::placeholders::_1));
	registerMessageHandler<MsgRegisterGameServerToCrossServer>(std::bind(&CSMsgHandler::onRegisterGameServerToCrossServer, this, std::placeholders::_1));
	registerMessageHandler<MsgGameServerSessionClosed>(std::bind(&CSMsgHandler::onGameServerClose, this, std::placeholders::_1));

	registerMessageHandler<MsgCreatePlayerInCrossServerRequest>(std::bind(&CSMsgHandler::onCreatePlayerInCrossServerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCreatePlayerInCrossServerEnd>(std::bind(&CSMsgHandler::onCreatePlayerInCrossServerEnd, this, std::placeholders::_1));

	registerMessageHandler<MsgSyncCommonInfoToCrossServerRequest>(std::bind(&CSMsgHandler::onSyncCommonInfoToCrossServerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgLeaveFromCrossServerMapRequest>(std::bind(&CSMsgHandler::onLeaveFromCrossServerMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSwitchCSMapRequest>(std::bind(&CSMsgHandler::onSwitchCSMapRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgKickPlayerFromCSRequest>(std::bind(&CSMsgHandler::onKickPlayerFromCSRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgNotifyCrossServerItemAbandon>(std::bind(&CSMsgHandler::onNotifyCrossServerItemAbandon, this, std::placeholders::_1));
	registerMessageHandler<MsgReviveInCSMapRequest>(std::bind(&CSMsgHandler::onReviveInCSMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUseItemInCSMapRequest>(std::bind(&CSMsgHandler::onUseItemInCSMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncEventDataRequest>(std::bind(&CSMsgHandler::onSyncEventDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgResetAndSyncAllEventDataNotify>(std::bind(&CSMsgHandler::onResetAndSyncAllEventDatat, this, std::placeholders::_1));

	registerMessageHandler<MsgGetQualifiedPlayerListNearbyRequest>(std::bind(&CSMsgHandler::onGetQualifiedPlayerListNearbyRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncWarZoneDropInfoToCS>(std::bind(&CSMsgHandler::onSyncWarZoneDropInfoToCS, this, std::placeholders::_1));

	registerMessageHandler<MsgAddItemToCrossAuctionRequset>(std::bind(&CSMsgHandler::onAddToCrossAuction, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckBuyCrossAuctionItemRequest>(std::bind(&CSMsgHandler::onCheckBuyCrossAuctionItem, this, std::placeholders::_1));
	registerMessageHandler<MsgBuyCrossAuctionItemRequest>(std::bind(&CSMsgHandler::onBuyCrossAuctionItem, this, std::placeholders::_1));

	registerMessageHandler<MsgAddConsignmentToCrossRequest>(std::bind(&CSMsgHandler::onAddConsignmentToCross, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckBuyCrossConsignmentRequest>(std::bind(&CSMsgHandler::onCheckBuyCrossConsignment, this, std::placeholders::_1));
	registerMessageHandler<MsgSendSellerRewardRequest>(std::bind(&CSMsgHandler::onSendSellerReward, this, std::placeholders::_1));
	registerMessageHandler<MsgRmvCrossConsignmentRequest>(std::bind(&CSMsgHandler::onRmvCrossConsignment, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossGetPlayerSerializeInfoG2C>(std::bind(&CSMsgHandler::onCrossGetPlayerSerializeInfoG2C, this, std::placeholders::_1));

	//求购
	registerMessageHandler<MsgAddPurchaseToCrossRequest>(std::bind(&CSMsgHandler::onAddPurchaseToCrossRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRmvCrossPurchaseRequest>(std::bind(&CSMsgHandler::onRmvPurchaseFromCrossRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgTrySellCrossPurchaseRequest>(std::bind(&CSMsgHandler::onTrySellCrossPurchaseRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSendBuyerPurchaseItemRequest>(std::bind(&CSMsgHandler::onSendBuyerPurchaseItemRequest, this, std::placeholders::_1));
	
	//GM
	registerMessageHandler<MsgGetPlayerCrossPropRequest>(std::bind(&CSMsgHandler::onGetPlayerCrossProp, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckPlayerAllCrossPropRequest>(std::bind(&CSMsgHandler::onCheckPlayerAllCrossProp, this, std::placeholders::_1));

	registerMessageHandler<MsgSceneWrapper>(std::bind(&CSMsgHandler::onSceneMessageWrapper, this, std::placeholders::_1));
	//跨服聊天  
	registerMessageHandler<MsgSendCrossChaToCsRequest>(std::bind(&CSMsgHandler::onSendCrossChaToCsRequest, this, std::placeholders::_1));

	//
	registerMessageHandler<MsgPlayerChangeNotify>(std::bind(&CSMsgHandler::onPlayerChangeNotify, this, std::placeholders::_1));

	   
	registerMessageHandler<MsgCrossPlayerStateG2C>(std::bind(&CSMsgHandler::onPlayerStateChange, this, std::placeholders::_1));
	registerMessageHandler<MsgGetBossCntInCrossMapRequest>(std::bind(&CSMsgHandler::onGetBossCntInCrossMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgServerDaysNotify>(std::bind(&CSMsgHandler::onServerDaysNotify, this, std::placeholders::_1));


	registerMessageHandler<MsgEnterGameGuajiRequest>(std::bind(&CSMsgHandler::onEnterGameGuajiRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgNotifyInitDreamNotify>(std::bind(&CSMsgHandler::onNotifyInitDreamNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgRemoveChatCrossRequest>(std::bind(&CSMsgHandler::onRemoveChatRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgSetCrossFlagNotify>(std::bind(&CSMsgHandler::onNotifyCrossFlagNotify, this, std::placeholders::_1));


	registerMessageHandler<MsgSyncGuildDeletedNotify>(std::bind(&CSMsgHandler::onSyncGuildDeletedNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncPlayerDeletedNotify>(std::bind(&CSMsgHandler::onSyncPlayerDeletedNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncGuildRenameNotify>(std::bind(&CSMsgHandler::onSyncGuildRenameNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncPlayerRenameNotify>(std::bind(&CSMsgHandler::onSyncPlayerRenameNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgGSBroadcastAllGSRequest>(std::bind(&CSMsgHandler::onGSBroadcastAllGSRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgChangeCsWordDataRequestFromGs>(std::bind(&CSMsgHandler::onChangeWorldDataFromGsRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgRemoveCSGeneFromeGSNotify>(std::bind(&CSMsgHandler::onRemoveCSGeneFromeGSNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgDoctorPlayerNotify>(std::bind(&CSMsgHandler::onDoctorPlayerNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPlayerBaseInfoFromCSRequest>(std::bind(&CSMsgHandler::onGetPlayerBaseInfoFromCSRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPlayerBaseInfoFromGSResponse>(std::bind(&CSMsgHandler::onGetPlayerBaseInfoFromGSResponse, this, std::placeholders::_1));

	// game server将跨服排行榜数据发过来
	registerMessageHandler<MsgSendGSRankToCS>(std::bind(&CSMsgHandler::onReceiveGSRankList, this, std::placeholders::_1));
}

CSMsgHandler::~CSMsgHandler()
{
}

bool CSMsgHandler::initialize()
{
	if (!__super::initialize())
	{
		return false;
	}

	return true;
}

std::vector<std::string> CSMsgHandler::split(const std::string &s, char sep)
{
	std::vector<std::string> v;

	size_t pos1 = 0;
	while (true)
	{
		std::string item_str;
		size_t pos2 = s.find(sep, pos1);
		if (pos2 == std::string::npos)
		{
			v.push_back(s.substr(pos1));
			break;
		}
		else
		{
			v.push_back(s.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
		}
	}

	return v;
}

void CSMsgHandler::onGS2CS(Message *message)
{
	MsgGS2CS* msg = dynamic_cast<MsgGS2CS*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	int game_server_id = CSHelper::getGameServerIdBySessionId(msg->getSessionID());
	lua::call(lua::L, "Entity.GS2CS", msg->funcID, msg->pid, msg->datax, msg->datay, msg->dataz, msg->datas, game_server_id);
}

void CSMsgHandler::onWarZoneInfoNotify(Message* message)
{
	if(!g_config.isCrossServer())
	{
		return;
	}

	MsgWarZoneInfoNotify* msg = dynamic_cast<MsgWarZoneInfoNotify*>(message);
	if (msg == nullptr)
	{
		return;
	}

	g_world.clearWarZoneServerList();
	g_world.clearWarZoneOpenTime();

	LOG_INFO("CS_MODULE_INFO:  ========================> warZone configuration info start<========================");
	WorldData *world_data = g_world.getWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);
	std::string oldServerNameList = world_data->getDataS();
	std::vector<std::string> vstr = split(oldServerNameList,'|');
	std::map<int,std::string> serverNameMap;
	for(std::vector<std::string>::iterator it = vstr.begin();it != vstr.end();it++)
	{
		std::vector<std::string> vstr2 = split(*it,':');
		if (vstr2.size() == 2)
		{
			int warZoneId = atoi(vstr2[0].c_str());
			std::string serverName = vstr2[1];
			serverNameMap.insert(std::pair<int,std::string>(warZoneId,serverName));
		}
	}
	std::string newServerNameList = "";
	for(auto iter = msg->list.begin(); iter != msg->list.end(); iter++)
	{
		std::string serverNameList;
		for(auto it = iter->gameServerInfoList.begin(); it != iter->gameServerInfoList.end(); it++)
		{
			WarZoneServerInfo info;
			info.serverId = it->serverId;
			info.serverName = it->serverName;
			g_world.addWarZoneServer(iter->warZoneId, info);

			std::stringstream str;
			str << it->serverName << ",";
			serverNameList = serverNameList + str.str();
		}

		g_world.setWarZoneOpenTime(iter->warZoneId, iter->warZoneOpenTime);

		newServerNameList = newServerNameList + std::to_string(iter->warZoneId) + ":" + serverNameList + "|";
		
		// std::map<int,std::string>::iterator nameIter = serverNameMap.find(iter->warZoneId);
		// if (nameIter != serverNameMap.end())
		// {
		// 	LOG_INFO("oldServerNameList:%s, serverNameList:%s",nameIter->second.c_str(),serverNameList.c_str());
		// 	if (nameIter->second != serverNameList)//战区服务器列表改变，要下架寄售行所有道具
		// 	{
		// 		g_consignment_store.deleteAllConsignmentsByWarZoneId(iter->warZoneId);
		// 	}
		// }
		LOG_INFO("CS_MODULE_INFO:  warZone config info = {warZoneId = %d, warZonePreOpenTime = %s, warZoneOpenTime = %s, serverNameList = %s }",
			iter->warZoneId, HolidayOperationHelper::timeIntToString(iter->warZonePreOpenTime).c_str(),HolidayOperationHelper::timeIntToString(iter->warZoneOpenTime).c_str(),serverNameList.c_str());
	}
	LOG_INFO("CS_MODULE_INFO:  ========================> warZone configuration info end<========================");

	g_app.GetNetService()->startGSManagerServer();

	MsgWarZoneInfoUpdFinishedNotify* notify = new MsgWarZoneInfoUpdFinishedNotify();
	g_app.postToNetService(notify);
	LOG_INFO("oldServerNameList=%s,newServerNameList=%s",oldServerNameList.c_str(),newServerNameList.c_str());
	if (oldServerNameList!= newServerNameList)//战区服务器列表发生改变，需要下架所有寄售行商品
	{
		world_data->setDataS(newServerNameList);
		g_world.syncWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);
		g_world.saveWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);
	}
	CSHelper::onWarZoneChanged();
}

void CSMsgHandler::onRegisterGameServerToCrossServer(Message* message)
{
	if(!g_config.isCrossServer())
	{
		return;
	}

	MsgRegisterGameServerToCrossServer* msg = dynamic_cast<MsgRegisterGameServerToCrossServer*>(message);
	if (msg == nullptr)
	{
		return;
	}

	LOG_INFO("CS_MODULE_INFO: new gameServer connected! gameServerInfo = {serverId = %d, serverName = %s, serverAddr = %s, serverPort = %d}", 
		msg->gameServerId, msg->gameServerName.c_str(), msg->gameServerAddr.c_str(), msg->gameServerPort);

	g_world.setServerName(msg->gameServerId, msg->gameServerName);

	CSHelper::bindGameServerIdBySessionId(msg->getSessionID(), msg->gameServerId);

	if(!g_config.isCommonCrossServer())
	{
		// g_scene_mgr.syncAllWarZoneBossInfoToGS(msg->gameServerId);
		// g_drop_broadcast_mgr.syncAllDropRecordToGS(msg->gameServerId);
		// g_acution_mgr.syncAllAcutionToGs(msg->gameServerId);
		// CSHelper::syncAllCrossConsignmentToGS(msg->gameServerId);
		// CSHelper::syncAllCrossPurchaseToGS(msg->gameServerId);
		// CSHelper::SyncCrossActivityToGS(msg->gameServerId,false);
		CSHelper::loadCrossRankFromToGS(msg->gameServerId);
	}

	lua::call(lua::L, "Cross.onGameServerConnected",
		msg->gameServerId,
		msg->gameServerAddr,
		msg->gameServerPort,
		msg->dbAgentAddr,
		msg->dbAgentPort);
}

void CSMsgHandler::onGameServerClose(Message* message)
{
	if(!g_config.isCrossServer())
	{
		return;
	}

	MsgGameServerSessionClosed* msg = dynamic_cast<MsgGameServerSessionClosed*>(message);
	if (msg == nullptr)
	{
		return;
	}

	//LOG_INFO("CS_MODULE_INFO: new gameServer connected! gameServerInfo = {serverId = %d, serverAddr = %s, serverPort = %d}", 
	//	msg->gameServerId, msg->gameServerAddr.c_str(), msg->gameServerPort);

	int game_server_id = CSHelper::getGameServerIdBySessionId(msg->getSessionID());

	CSHelper::unbindGameServerIdBySessionId(msg->getSessionID());

	lua::call(lua::L, "Cross.onGameServerClose", game_server_id);
}


void CSMsgHandler::onCreatePlayerInCrossServerRequest(Message* message)
{
	MsgCreatePlayerInCrossServerRequest* msg = dynamic_cast<MsgCreatePlayerInCrossServerRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player != nullptr)
	{
		Scene *scene = player->getScene();
		if(scene != nullptr)
		{
			SceneOperationHelper::removeEntity(*scene, player->getID());
		}

		g_world_player_mgr.removePlayerByPlayerID(msg->playerId);

		g_entity_factory->deleteEntity(player);
	}


	player = (EntityPlayer *)g_entity_factory->newEntity(ENTITY_TYPE_PLAYER);
	if(player == nullptr)
	{
		return;
	}

	player->setGlobalID(msg->playerId);
	player->setPlayerID(msg->playerId);
	player->setStaticID(msg->job);
	player->setClass(msg->job);
	player->setName(msg->name);
	player->setLevel(msg->level);
	player->setSceneStaticID(msg->dstMapId);
	player->setPositionX(msg->posX);
	player->setPositionY(msg->posY);
	player->setOwner(NULL);

	player->unSerialize(msg);

	g_world_player_mgr.addPreLoadPlayer(player);
	g_world_player_mgr.enterCS(msg->playerId, player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: create player in cross server start, playerInfo = {player_id = %d, player_name = %s, map_id = %d}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), msg->dstMapId);
	}
}

void CSMsgHandler::onCreatePlayerInCrossServerEnd(Message* message)
{
	MsgCreatePlayerInCrossServerEnd* msg = dynamic_cast<MsgCreatePlayerInCrossServerEnd*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	//从数据库加载数据
	player->load();

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: start load player data from db, playerInfo = {player_id = %d, player_name = %s}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str());
	}
}

void CSMsgHandler::onSyncCommonInfoToCrossServerRequest(Message* message)
{
	MsgSyncCommonInfoToCrossServerRequest* msg = dynamic_cast<MsgSyncCommonInfoToCrossServerRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	if(msg->entityType == ENTITY_TYPE_PLAYER)
	{
		player->updCommonInfo(msg);
	}
}

void CSMsgHandler::onLeaveFromCrossServerMapRequest(Message* message)
{
	MsgLeaveFromCrossServerMapRequest* msg = dynamic_cast<MsgLeaveFromCrossServerMapRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	CSHelper::leaveCSMap(msg->playerId, msg->sourceServerId, msg->reason, msg->dstMapId, msg->posX, msg->posY,msg->sceneInstanceId,msg->enterSceneType);
}

void CSMsgHandler::onSwitchCSMapRequest(Message* message)
{
	MsgSwitchCSMapRequest* msg = dynamic_cast<MsgSwitchCSMapRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	int ret = SceneOperationHelper::enterScene(g_scene_mgr, *player, msg->dstMapId, msg->posX, msg->posY);

	if(ret != SUCCESS)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: switch cross map failed, playerInfo = {player_id = %d, player_name = %s, crossMapId = %d, errorCode = %d}", 
				msg->playerId, msg->playerId, player->getName().c_str(), msg->dstMapId, ret);
		}

		if (player->getScene() == nullptr)
		{
			CSHelper::leaveCSMap(player->getPlayerID(), player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
		}
		return;
	}

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
	{
		LOG_INFO("CS_MODULE_LOG_%d: switch cross map successful, playerInfo = {player_id = %d, player_name = %s, crossMapId = %d}", 
			msg->playerId, msg->playerId, player->getName().c_str(), msg->dstMapId);
	}

	MsgEnterSceneResponse *response = new MsgEnterSceneResponse;
	response->errcode = ret;
	response->reason = player->getProp(ENTITY_PROP_FLY_REASON);
	response->setSessionID(player->getSessionID());
	response->npcfly = player->getProp(ENTITY_PROP_FLY_NPC);
	g_app.postToNetService(response);

	CSHelper::syncPosToGS(player);
}

void CSMsgHandler::onKickPlayerFromCSRequest(Message* message)
{
	MsgKickPlayerFromCSRequest* msg = dynamic_cast<MsgKickPlayerFromCSRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	player->onLeaveCSMap(false);
}

void CSMsgHandler::onNotifyCrossServerItemAbandon(Message* message)
{
	MsgNotifyCrossServerItemAbandon* msg = dynamic_cast<MsgNotifyCrossServerItemAbandon*>(message);
	if (msg == nullptr)
	{
		return;
	}

	OperationHelper::setOpCode(OP_ABANDON_ITEM);

	Scene* scene = g_scene_mgr.getWarZoneSceneByStaticID(msg->mapId, msg->mapLineId, msg->warZoneLineId);
	if (scene)
	{
		Entity *item_entity = SceneOperationHelper::addEntityItem(*scene, msg->itemId, msg->posX, msg->posY, msg->itemCount);
		if (item_entity)
		{
			item_entity->setProp(ENTITY_PROP_ITEM_LAST_OWNER, msg->pid);
			for (auto iter = msg->itemProps.begin(); iter != msg->itemProps.end(); iter++)
			{
				item_entity->setProp(iter->ctype, iter->data);
			}
			item_entity->setPropString(ENTITY_STRPROP_FIRST_OWNER,msg->firstowner);
			item_entity->setPropString(ENTITY_STRPROP_APPRAISER,msg->appraiser);
		}
	}
}

void CSMsgHandler::onReviveInCSMapRequest(Message* message)
{
	MsgReviveInCSMapRequest* msg = dynamic_cast<MsgReviveInCSMapRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == NULL)
	{
		return;
	}

	if(player->isAlive())
	{
		return;
	}

	int ret = ERROR_UNKNOWN;
	if(msg->subType == -1)   //安全复活
	{
		lua::call(lua::L, "Entity.reviveSafeInCrossMap", player);
		ret = lua::getinteger(1);
	}
	else                   //原地复活
	{
		lua::call(lua::L, "Entity.reviveDeadPlaceInCrossMap", player);
		ret = lua::getinteger(1);
	}
	
	if (ret == SUCCESS)
	{
		//召唤宝宝跟英雄  
		EntityOperationHelper::summonPet(player);
	}

	MsgReviveEntityResponse *response = new MsgReviveEntityResponse;
	response->eid = player->getID();
	response->errcode = SUCCESS;
	player->sendMessage(response);

	if(msg->subType != -1)
	{
		MsgReviveInCSMapResponse* rsp = new MsgReviveInCSMapResponse;
		rsp->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
		rsp->playerId = msg->playerId;
		rsp->subType = msg->subType;
		g_app.postToNetService(rsp);
	}
}

void CSMsgHandler::onUseItemInCSMapRequest(Message* message)
{
	MsgUseItemInCSMapRequest* msg = dynamic_cast<MsgUseItemInCSMapRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == NULL)
	{
		return;
	}

	lua::call(lua::L, "Item.onUseInCSMap", player,  msg->sid, msg->rid, msg->count, msg->targetType);
}

void CSMsgHandler::onSyncEventDataRequest(Message* message)
{
	
	if (g_config.isGameServer())
	{
		return;
	}

	MsgSyncEventDataRequest* msg = dynamic_cast<MsgSyncEventDataRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	EventData *edata = player->getEventData(msg->data.id);
	if (edata == nullptr)
	{
		return;
	}

	edata->setTimeIndex(msg->data.timeIndex);
	edata->setDataX(edata->getDataX() + msg->data.datax);
	edata->setDataY(edata->getDataY() + msg->data.datay);
	edata->setDataZ(edata->getDataZ() + msg->data.dataz);

	edata->cacheLastSaveData();
}

void CSMsgHandler::onResetAndSyncAllEventDatat(Message* message)
{
	MsgResetAndSyncAllEventDataNotify* msg = dynamic_cast<MsgResetAndSyncAllEventDataNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	for(auto iter = msg->events.begin(); iter != msg->events.end(); iter++)
	{
		EventData* eventData = player->getEventData(iter->id);
		if (eventData != nullptr)
		{
			eventData->setTimeIndex(iter->timeIndex);
			eventData->setDataX(iter->datax);
			eventData->setDataY(iter->datay);
			eventData->setDataZ(iter->dataz);

			eventData->cacheLastSaveData();
		}
	}
}

void CSMsgHandler::onGetQualifiedPlayerListNearbyRequest(Message* message)
{
	MsgGetQualifiedPlayerListNearbyRequest* msg = dynamic_cast<MsgGetQualifiedPlayerListNearbyRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	CSHelper::getQualifiedPlayerNearby(player, msg->condition);
}

void CSMsgHandler::onSyncWarZoneDropInfoToCS(Message* message)
{
	MsgSyncWarZoneDropInfoToCS* msg = dynamic_cast<MsgSyncWarZoneDropInfoToCS*>(message);

	if (msg == nullptr)
	{
		return;
	}

	CSHelper::broadcastDropToWarZone(msg->record.killerPid, msg->record.killerName, msg->serverId, msg->record.mapId, msg->record.monsterId, msg->record.dropItemId, msg->record.dropTime, msg->top == 1);
}

void CSMsgHandler::onSceneMessageWrapper(Message* message)
{
	MsgSceneWrapper* msgWrapper = dynamic_cast<MsgSceneWrapper*>(message);
	if (msgWrapper == nullptr)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msgWrapper->pid);
	if (player == nullptr)
	{
		return;
	}

	int gridX = 0, gridY = 0;
	gridX = player->getGridX();
	gridY = player->getGridY();

	Scene* scene = player->getScene();
	if(scene != nullptr)
	{
		Message* msg = g_msg_factory.createMessage(msgWrapper->subMsgCategory, msgWrapper->subMsgId);
		ByteStream s;
		msgWrapper->subMsg->serialize(s);
		msg->unserialize(s);

		//MsgMeetEntityExDataNotify* testmsg = dynamic_cast<MsgMeetEntityExDataNotify*>(msg);
		//if (testmsg)
		//{
		//	std::vector<MeetExData> props = testmsg->exdata;
		//	for (auto it = props.begin(); it != props.end(); ++it)
		//	{
		//		LOG_INFO("MsgMeetEntityExDataNotify   -> %d   -->%d",it->type,it->data);
		//	}
		//}
		scene->sendMessage(gridX, gridY, msg);
	}
}

void CSMsgHandler::onAddToCrossAuction(Message* message)
{
	MsgAddItemToCrossAuctionRequset* msg = dynamic_cast<MsgAddItemToCrossAuctionRequset*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_acution_mgr.add_item_to_cross_auction(&(msg->auctionItem));
}

void CSMsgHandler::onCheckBuyCrossAuctionItem(Message* message)
{
	MsgCheckBuyCrossAuctionItemRequest* msg = dynamic_cast<MsgCheckBuyCrossAuctionItemRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgCheckBuyCrossAuctionItemResponse* response = new MsgCheckBuyCrossAuctionItemResponse();
	response->setUserData(msg->buyer_server_id);
	response->buyer_pid = msg->buyer_pid;
	response->aid = msg->aid;
	response->type = msg->type;
	response->errcode = g_acution_mgr.check_can_buy_cross_acution_item(msg->buyer_pid, msg->buyer_war_zone_id, msg->aid, msg->type);
	g_app.postToNetService(response);
}

void CSMsgHandler::onBuyCrossAuctionItem(Message* message)
{
	MsgBuyCrossAuctionItemRequest* msg = dynamic_cast<MsgBuyCrossAuctionItemRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgBuyCrossAuctionItemResponse* rsp = new MsgBuyCrossAuctionItemResponse;
	rsp->setUserData(msg->buyer_server_id);
	rsp->buyer_pid = msg->buyer_pid;
	rsp->cost_money = msg->cost_money;
	rsp->money_type = msg->money_type;
	rsp->sid = msg->sid;
	rsp->type = msg->type;
	if(msg->type == 3)
	{
		rsp->errcode = g_acution_mgr.on_add_buy_cross_acution(msg->buyer_pid, msg->buyer_name, msg->buyer_server_id, msg->buyer_war_zone_id, msg->aid);
	}
	else if(msg->type == 4)
	{
		rsp->errcode = g_acution_mgr.on_fix_buy_cross_acution(msg->buyer_pid, msg->buyer_name, msg->buyer_server_id, msg->buyer_war_zone_id, msg->aid);
	}
	g_app.postToNetService(rsp);
}

void CSMsgHandler::onAddConsignmentToCross(Message* message)
{
	MsgAddConsignmentToCrossRequest* msg = dynamic_cast<MsgAddConsignmentToCrossRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgAddConsignmentToCrossResponse* rsp = new MsgAddConsignmentToCrossResponse();
	rsp->setUserData(msg->srcServerId);
	rsp->pid = msg->pid;
	rsp->sid  = msg->sid;
	rsp->count = msg->count;

	if (g_consignment_store.getConsignmentCount(msg->pid) >= 30)
	{
		rsp->errcode = ERROR_THINGS_OVER_MAX;
		g_app.postToNetService(rsp);
		return;
	}

	std::map<int,int> props;
	for (int i = 0;i < msg->props.size();i++)
	{
		CrossConsignmentItemProp prop = msg->props[i];
		props[prop.idx] = prop.data;
	}

	Consignment *consignment = g_consignment_store.addConsignment(msg->pid, msg->sid, msg->count, msg->price, msg->time,msg->name,msg->taxRate, props,  msg->srcServerName, msg->srcServerId,  msg->warZoneId,msg->firstOwner,msg->appraiser,msg->cTime,msg->eTime);
	if(consignment == nullptr)
	{
		delete rsp;
		return;
	}

	CSHelper::broadcastCrossConsignmentAddToWarZone(consignment);
	
	rsp->errcode = SUCCESS;
	g_app.postToNetService(rsp);

// 	int noticeType = 0;
// 	if(lua::call(lua::L, "Consignment.getConsignmentNoticeType", consignment->sid))
// 	{
// 		noticeType = lua::getinteger(1);
// 	}
// 	if(noticeType == 1 || noticeType == 3)
// 	{
// 		MsgAddNiceConsignmentNotify* notify = new MsgAddNiceConsignmentNotify;
// 		notify->sellerPid = consignment->sellerPid;
// 		notify->cid = consignment->cid;
// 		notify->sid = msg->sid;
// 		g_world.broadcastWarZoneNoticeToAllClients(notify, msg->warZoneId);
// 	}
// 
// 	if(noticeType == 2 || noticeType == 3)
// 	{
// 		lua::call(lua::L, "Consignment.boardcastNiceItem", msg->srcServerName.c_str(), msg->name.c_str(), consignment->sid, msg->warZoneId % 1000);
// 	}

	LOG_INFO("Consignment Info: player %d-%s add cross consignment success! itemid = %d, itemPrice = %d, itemCounts = %d, taxRate = %d",
		msg->pid, msg->name.c_str(), msg->sid, msg->price, msg->count, msg->taxRate);
}

void CSMsgHandler::onCheckBuyCrossConsignment(Message* message)
{
	MsgCheckBuyCrossConsignmentRequest* msg = dynamic_cast<MsgCheckBuyCrossConsignmentRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgCheckBuyCrossConsignmentResponse* rsp = new MsgCheckBuyCrossConsignmentResponse();
	rsp->setUserData(msg->buyerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->sellerPid = msg->sellerPid;
	rsp->cid = msg->cid;
	rsp->count = msg->count;
	rsp->errcode = g_consignment_store.tryBuyCrossConsignment(msg->buyerPid, msg->sellerPid, msg->cid, msg->count);
	g_app.postToNetService(rsp);
}

void CSMsgHandler::onSendSellerReward(Message* message)
{
	MsgSendSellerRewardRequest* msg = dynamic_cast<MsgSendSellerRewardRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgSendSellerRewardResponse* rsp = new MsgSendSellerRewardResponse();
	rsp->setUserData(msg->buyerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->sellerPid = msg->sellerPid;
	rsp->cid = msg->cid;
	rsp->count = msg->count;
	rsp->errcode = g_consignment_store.sendSellerReward(msg->buyerPid, msg->buyerName, msg->buyerServerId, msg->sellerPid, msg->cid, msg->count);
	g_app.postToNetService(rsp);
}

void CSMsgHandler::onRmvCrossConsignment(Message* message)
{
	MsgRmvCrossConsignmentRequest* msg = dynamic_cast<MsgRmvCrossConsignmentRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgRmvCrossConsignmentResponse* rsp = new MsgRmvCrossConsignmentResponse();
	rsp->setUserData(msg->sellerServerId);
	rsp->sellerPid = msg->sellerPid;
	rsp->cid = msg->cid;

	Consignment *consignment = g_consignment_store.getConsignment(msg->sellerPid, msg->cid);
	if(consignment == nullptr)
	{
		rsp->errcode = ERROR_INVALID_ITEM;
		g_app.postToNetService(rsp);
	}
	else if(g_consignment_store.isLocked(msg->sellerPid, msg->cid))
	{
		rsp->errcode = ERROR_ACUTION_TRY_LATER;
		g_app.postToNetService(rsp);
	}
	else
	{
		rsp->errcode = SUCCESS;
		g_app.postToNetService(rsp);

		CSHelper::broadcastCrossConsignmentRmvToWarZone(consignment);
		g_consignment_store.deleteConsignment(msg->sellerPid, msg->cid);

		MsgDBDeleteConsignment *dbmsg = new MsgDBDeleteConsignment;
		dbmsg->pid = msg->sellerPid;
		dbmsg->cid = msg->cid;
		g_app.postToNetService(dbmsg);
	}
}

void CSMsgHandler::onAddPurchaseToCrossRequest(Message* message)
{
	MsgAddPurchaseToCrossRequest* msg = dynamic_cast<MsgAddPurchaseToCrossRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgAddPurchaseToCrossResponse* rsp = new MsgAddPurchaseToCrossResponse();
	rsp->setUserData(msg->buyerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->sid = msg->sid;
	rsp->count = msg->count;
	rsp->price = msg->price;

	if (g_purchase_mgr.getPurchaseCount(msg->buyerPid) >= 5)
	{
		rsp->errcode = ERROR_THINGS_OVER_MAX;
		g_app.postToNetService(rsp);
		return;
	}

	Purchase *purchase = g_purchase_mgr.addPurchase(msg->buyerPid, msg->sid, msg->count, msg->price, msg->time,msg->buyerName, 0, msg->buyerServerName, msg->buyerServerId, msg->buyerWarZoneId);
	if(purchase == nullptr)
	{
		delete rsp;
		return;
	}

	CSHelper::broadcastCrossPurchaseAddToWarZone(purchase);

	rsp->errcode = SUCCESS;
	g_app.postToNetService(rsp);

	LOG_INFO("Purchase Info: player %d-%s add cross purchase success! itemid = %d, itemUnitPrice = %d, itemCounts = %d",
		msg->buyerPid, msg->buyerName.c_str(), msg->sid, msg->price, msg->count);
}

void CSMsgHandler::onRmvPurchaseFromCrossRequest(Message* message)
{
	MsgRmvCrossPurchaseRequest* msg = dynamic_cast<MsgRmvCrossPurchaseRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgRmvCrossPurchaseResponse* rsp = new MsgRmvCrossPurchaseResponse();
	rsp->setUserData(msg->buyerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->purchaseId = msg->purchaseId;

	Purchase* purchase = g_purchase_mgr.getPurchase(msg->buyerPid, msg->purchaseId);
	if(purchase == nullptr)
	{
		rsp->errcode = ERROR_PURCHASE_INVAILD;
	}
	else if(g_purchase_mgr.isLocked(msg->buyerPid, msg->purchaseId))
	{
		rsp->errcode = ERROR_ACUTION_TRY_LATER;
	}
	else
	{
		rsp->errcode = SUCCESS;

		//给求购者退钱
		int moneyType = ITEM_LINGFU;
		if(lua::call(lua::L, "Consignment.getPurchaseItemMoneyType", purchase->sid))
		{
			moneyType = lua::getinteger(1);
		}
		int totalMomey = purchase->price * purchase->count;
		lua::call(lua::L, "Consignment.sendItemToPurchaseBuyer", purchase->buyerPid, purchase->buyerServerId, purchase->sid, purchase->count, 2, totalMomey, moneyType);

		CSHelper::broadcastCrossPurchaseRmvToWarZone(purchase);
		g_purchase_mgr.deletePurchase(msg->buyerPid, msg->purchaseId);

		MsgDBDeletePurchase *dbmsg = new MsgDBDeletePurchase;
		dbmsg->pid = msg->buyerPid;
		dbmsg->purchaseId = msg->purchaseId;
		g_app.postToNetService(dbmsg);
	}

	g_app.postToNetService(rsp);
}

void CSMsgHandler::onTrySellCrossPurchaseRequest(Message* message)
{
	MsgTrySellCrossPurchaseRequest* msg = dynamic_cast<MsgTrySellCrossPurchaseRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgTrySellCrossPurchaseResponse* rsp = new MsgTrySellCrossPurchaseResponse();
	rsp->setUserData(msg->sellerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->sellerPid = msg->sellerPid;
	rsp->purchaseId = msg->purchaseId;
	rsp->sellCounts = msg->sellCounts;
	rsp->errcode = g_purchase_mgr.trySellPurchase(msg->buyerPid, msg->sellerPid, msg->purchaseId, msg->sellCounts);
	g_app.postToNetService(rsp);
}

void CSMsgHandler::onSendBuyerPurchaseItemRequest(Message* message)
{
	MsgSendBuyerPurchaseItemRequest* msg = dynamic_cast<MsgSendBuyerPurchaseItemRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	MsgSendBuyerPurchaseItemResponse* rsp = new MsgSendBuyerPurchaseItemResponse();
	rsp->setUserData(msg->sellerServerId);
	rsp->buyerPid = msg->buyerPid;
	rsp->sellerPid = msg->sellerPid;
	rsp->purchaseId = msg->purchaseId;
	rsp->errcode = g_purchase_mgr.sendbuyerReward(msg->buyerPid, msg->purchaseId, msg->sellerPid, msg->sellerServerId, msg->sellerName, msg->sellCounts);
	g_app.postToNetService(rsp);
}

void CSMsgHandler::onGetPlayerCrossProp(Message* message)
{
	MsgGetPlayerCrossPropRequest* msg = dynamic_cast<MsgGetPlayerCrossPropRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	std::string arg = "GM getcrossprop " + std::to_string(msg->ctype) + ": " + std::to_string(player->getProp(msg->ctype));
	std::vector<std::string> args;
	args.push_back(arg);
	EntityOperationHelper::sendSystemInfo(*player, 1, args);
}

void CSMsgHandler::onCheckPlayerAllCrossProp(Message* message)
{
	MsgCheckPlayerAllCrossPropRequest* msg = dynamic_cast<MsgCheckPlayerAllCrossPropRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	LOG_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>check cross player start<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	LOG_INFO("check player info = {playerId = %d, playerName = %s}", player->getGlobalID(), player->getName().c_str());

	LOG_INFO("================= check cross player event data =========================");
	for(auto iter = msg->events.begin(); iter != msg->events.end(); iter++)
	{
		EventData* csData = player->getEventData(iter->id);
		if(csData == nullptr)
		{
			LOG_INFO("event data is different, gsEventInfo = {eventId = %d, timeIndex = %d, datax = %d, datay = %d, dataz = %d}, csEventInfo = nil", 
				iter->id, iter->timeIndex, iter->datax, iter->datay, iter->dataz);
		}
		else
		{
			if(csData->getTimeIndex() != iter->timeIndex || csData->getDataX() != iter->datax ||
				csData->getDataY() != iter->datay || csData->getDataZ() != iter->dataz)
			{
				LOG_INFO("event data is different, eventInfo = {eventId = %d, timeIndexInGS = %d, dataxInGS = %d, datayInGS = %d, datazInGS = %d, timeIndexInCS = %d, dataxInCS = %d, datayInCS = %d, datazInCS = %d}", 
					iter->id, iter->timeIndex, iter->datax, iter->datay, iter->dataz, csData->getTimeIndex(), csData->getDataX(), csData->getDataY(), csData->getDataZ());
			}
		}
	}

	LOG_INFO("================= check cross player int prop =========================");
	for(auto iter = msg->commonInfo.intProps.begin(); iter != msg->commonInfo.intProps.end(); iter++)
	{
		int ctype = iter->ctype;
		int gsValue = iter->data;
		int csValue = player->getProp(ctype);
		if(gsValue != csValue)
		{
			LOG_INFO("int prop value is different, propInfo = {propId = %d, propValueInGS = %d, propValueInCS = %d}", ctype, gsValue, csValue);
		}
	}

	LOG_INFO("================= check cross player str prop =========================");
	for(auto iter = msg->commonInfo.strProps.begin(); iter != msg->commonInfo.strProps.end(); iter++)
	{
		int ctype = iter->ctype;
		std::string gsValue = iter->data;
		std::string csValue = player->getPropString(ctype);
		if(gsValue != csValue)
		{
			LOG_INFO("str prop value is different, propInfo = {propId = %d, propValueInGS = %s, propValueInCS = %s}", ctype, gsValue.c_str(), csValue.c_str());
		}
	}

	LOG_INFO("================= check cross player combat  =========================");
	Combat* combat = player->getCombat();
	const int* combatProps = combat->getCombatPropsMap();
	for(auto iter = msg->commonInfo.combatProps.begin(); iter != msg->commonInfo.combatProps.end(); iter++)
	{
		int ctype = iter->ctype;
		int gsValue = iter->data;
		int csValue = combatProps[ctype];
		if(gsValue != csValue)
		{
			LOG_INFO("combat value is different, combatInfo = {combatId = %d, combatValueInGS = %d, combatValueInCS = %d}", ctype, gsValue, csValue);
		}
	}

	LOG_INFO("================= check cross player skill =========================");
	for(auto iter = msg->commonInfo.skills.begin(); iter != msg->commonInfo.skills.end(); iter++)
	{
		int skillId = iter->sid;
		int skillLvlInGs = iter->level;
		int skillLvlInCs = 0;

		Skill* skill = combat->getSkill(skillId);
		if(skill)
		{
			skillLvlInCs = skill->getProp(SKILL_PROP_LEVEL);
		}
		if(skillLvlInGs != skillLvlInCs)
		{
			LOG_INFO("skill is different, skillInfo = {skillId = %d, skillLvlInGs = %d, skillLvlInCs = %d}", skillId, skillLvlInGs, skillLvlInCs);
		}
	}

	LOG_INFO("================= check cross player gene =========================");
	for(auto iter = msg->commonInfo.genes.begin(); iter != msg->commonInfo.genes.end(); iter++)
	{
		int geneId = iter->geneId;
		if(!player->hasGene(geneId))
		{
			LOG_INFO("gene is different, geneInfo = {geneId = %d}", geneId);
		}
	}

	LOG_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>check cross player end<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
}

//跨服聊天  
void  CSMsgHandler::onSendCrossChaToCsRequest(Message* message){
	MsgSendCrossChaToCsRequest* msg = dynamic_cast<MsgSendCrossChaToCsRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	int warZoneId = g_world.getWarZoneIdByGameServeID(msg->serverid);
	for(auto iter = g_world.getAllWarZoneInfo().begin(); iter != g_world.getAllWarZoneInfo().end(); iter++)
	{
		if(iter->first == warZoneId || warZoneId == 0)
		{
			for(auto it = iter->second.begin(); it != iter->second.end(); it++)
			{
				MsgSyncCrossChatNotify *notify = new MsgSyncCrossChatNotify;
				notify->setUserData(it->serverId);
				notify->chatType = msg->chatType;
				notify->pid = msg->pid;
				notify->playerName = msg->playerName;

				notify->gender = msg->gender;
				notify->vipLevel = msg->vipLevel;
				notify->level = msg->level;
				notify->job = msg->job;
				notify->position = msg->position;
				notify->redID = 0;
				notify->serverid = msg->serverid;
				notify->guildName ="";
				notify->chatText = msg->chatText;
				notify->props = msg->props;
				g_app.postToNetService(notify);
			}
		}
	}	
}

void CSMsgHandler::onCrossGetPlayerSerializeInfoG2C(Message* message)
{
	MsgCrossGetPlayerSerializeInfoG2C* msg = dynamic_cast<MsgCrossGetPlayerSerializeInfoG2C*>(message);
	if (msg == nullptr)
	{
		return;
	}
	lua::call(lua::L, "Entity.isRobot", msg->enemy_pid);
	bool b = lua::getboolean(1);
	if (b)
	{
		//挑战机器人
		MsgCrossGetPlayerSerializeInfoC2G * notify = new MsgCrossGetPlayerSerializeInfoC2G;
		notify->setUserData(msg->sourceWorldId);
		notify->pid = msg->pid;
		notify->enemy_pid = msg->enemy_pid;
		notify->action = msg->action;
		notify->scene_static_id = msg->scene_static_id;
		notify->errcode = SUCCESS;
		//notify->json = msg->json;
		g_app.postToNetService(notify);
	}
}

void CSMsgHandler::onPlayerChangeNotify(Message* message)
{
	MsgPlayerChangeNotify* msg = dynamic_cast<MsgPlayerChangeNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	int newLvl  = msg->lvl;
	player->setLevel(newLvl);

	return;
}


void CSMsgHandler::onPlayerStateChange(Message* message)
{
	MsgCrossPlayerStateG2C* msg = dynamic_cast<MsgCrossPlayerStateG2C*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	int state  = msg->state;
	player->setState(state);

	return;
}

void CSMsgHandler::onGetBossCntInCrossMapRequest(Message* message)
{
	MsgGetBossCntInCrossMapRequest* msg = dynamic_cast<MsgGetBossCntInCrossMapRequest*>(message);
	if (!msg)
	{
		return;
	}

	std::map<short, std::pair<int, int>> bossCnts;
	for (auto& it : msg->cross_maps)
	{
		bossCnts[it.index] = std::make_pair(it.map_id,SceneOperationHelper::getMapBossCount(it.map_id, msg->warzone_line_id)) ;
	}

	if (bossCnts.empty())
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player)
	{
		MsgGetBossCntInMapNotify* notify = new MsgGetBossCntInMapNotify;
		for (auto& it : bossCnts)
		{
			MapBossCount m;
			m.index = it.first;
			m.sceneId = it.second.first;
			m.count = it.second.second;
			SceneOperationHelper::addBossInfo(m, msg->warzone_line_id);
			notify->boss_cnts.emplace_back(m);
			notify->targetName = msg->targetName;
		}
		player->sendMessage(notify);
	}
	else
	{
		MsgGetBossCntInCrossMapNotify* notify = new MsgGetBossCntInCrossMapNotify;
		notify->setUserData(msg->source_world_id);
		notify->pid = msg->pid;
		for (auto& it : bossCnts)
		{
			CrossMapBossCount m;
			m.index = it.first;
			m.sceneId = it.second.first;
			m.count = it.second.second;
			SceneOperationHelper::addBossInfo(m, msg->warzone_line_id);
			notify->boss_cnts.emplace_back(m);
		}
		notify->targetName = msg->targetName;
		g_app.postToNetService(notify);
	}

}

void CSMsgHandler::onServerDaysNotify(Message* message)
{
	MsgServerDaysNotify* msg = dynamic_cast<MsgServerDaysNotify*>(message);
	if (!msg)
	{
		return;
	}

	g_world.setServerDays(msg->server_id, msg->server_days);
}



void CSMsgHandler::onEnterGameGuajiRequest(Message* message)
{
	MsgEnterGameGuajiRequest* msg = dynamic_cast<MsgEnterGameGuajiRequest*>(message);
	if (!msg)
	{
		return;
	}

	
	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
		{
			LOG_INFO("CS_MODULE_LOG_%d: player login to cross server failed, player is not been created,  playerInfo = {player_id = %d}",
				msg->pid, msg->pid);
		}
		return;
	}

	player->setSessionID(msg->pid * -1);
	g_world_player_mgr.setPlayerSession(player);

	player->setProp(ENTITY_PROP_IN_GAME, 1);

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
	{
		LOG_INFO("CS_MODULE_LOG_%d: player login to cross server success,  playerInfo = {player_id = %d, player_name = %s}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str());
	}

	CSHelper::enterCSMap(player->getPlayerID(), player->getSceneStaticID(), player->getPositionX(), player->getPositionY());
}

void CSMsgHandler::onNotifyCrossFlagNotify(Message *message)
{
	MsgSetCrossFlagNotify* msg = dynamic_cast<MsgSetCrossFlagNotify*>(message);
	if (!msg)
	{
		return;
	}
	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
		{
			LOG_INFO("CS_MODULE_LOG_%d: player MsgSetCrossFlagNotify, player is not been created,  playerInfo = {player_id = %d}",
				msg->pid, msg->pid);
		}
		return;
	}
	Combat *c = player->getCombat();
	int flag = msg->flag;
	if (c)
	{
		if (flag > 0)
		{
			c->setFlags(flag);
		}else
		{
			c->clearFlags(flag*-1);
		}
	}

}


void CSMsgHandler::onNotifyInitDreamNotify(Message *message)
{
	MsgNotifyInitDreamNotify* msg = dynamic_cast<MsgNotifyInitDreamNotify*>(message);
	if (!msg)
	{
		return;
	}


	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
		{
			LOG_INFO("CS_MODULE_LOG_%d: player login to cross server failed, player is not been created,  playerInfo = {player_id = %d}",
				msg->pid, msg->pid);
		}
		return;
	}
}

void CSMsgHandler::onRemoveChatRequest(Message *message)
{
	MsgRemoveChatCrossRequest* msg = dynamic_cast<MsgRemoveChatCrossRequest*>(message);
	if (!msg)
	{
		return;
	}

	CSHelper::removeChatToAllWarZone(msg->pid, msg->src_server_id);
}

void CSMsgHandler::onSyncGuildDeletedNotify(Message *message)
{
	MsgSyncGuildDeletedNotify* msg = dynamic_cast<MsgSyncGuildDeletedNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(g_config.isGameServer())
	{
		return;
	}

	g_world.onGuildDelete(msg->guildid);
}


void CSMsgHandler::onSyncPlayerDeletedNotify(Message *message)
{
	MsgSyncPlayerDeletedNotify* msg = dynamic_cast<MsgSyncPlayerDeletedNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(g_config.isGameServer())
	{
		return;
	}

	g_world_player_mgr.addDelPlayer(msg->pid);
}

void CSMsgHandler::onSyncGuildRenameNotify(Message *message)
{
	MsgSyncGuildRenameNotify* msg = dynamic_cast<MsgSyncGuildRenameNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(g_config.isGameServer())
	{
		return;
	}
	g_world.setGuildName(msg->guildid, msg->newName, true);
}

void CSMsgHandler::onSyncPlayerRenameNotify(Message *message)
{
	MsgSyncPlayerRenameNotify* msg = dynamic_cast<MsgSyncPlayerRenameNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(g_config.isGameServer())
	{
		return;
	}
	g_world.setPlayerName(msg->pid, msg->newName, true);
}

void CSMsgHandler::onGSBroadcastAllGSRequest(Message *message)
{
	MsgGSBroadcastAllGSRequest* msg = dynamic_cast<MsgGSBroadcastAllGSRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}

	int warZoneId = g_world.getWarZoneIdByGameServeID(msg->serverid);

	if(warZoneId == 0)
	{
		return;
	}


	for(auto iter = g_world.getAllWarZoneInfo().begin(); iter != g_world.getAllWarZoneInfo().end(); iter++)
	{
		if(iter->first == warZoneId)
		{
			for(auto it = iter->second.begin(); it != iter->second.end(); it++)
			{
				if(it->serverId != msg->serverid)
				{
					int gameServerId = it->serverId;
					MsgGSBroadcastAllGSResponse* response = new MsgGSBroadcastAllGSResponse;
					if(response == nullptr)
					{
						return;
					}
					response->setUserData(gameServerId);
					response->basestring = msg->basestring;
					response->showflag = msg->showflag;
					response->TouchID = msg->TouchID;
					g_app.postToNetService(response);
				}
			}
		}
	}
}


void CSMsgHandler::onChangeWorldDataFromGsRequest(Message *message)
{
	MsgChangeCsWordDataRequestFromGs* msg = dynamic_cast<MsgChangeCsWordDataRequestFromGs*>(message);

	if(msg == nullptr)
	{
		return;
	}

	if(g_config.isGameServer())
	{
		return;
	}
	

	WorldData* worlddata =	g_world.getWorldData(msg->wprop);
	if (!worlddata)
	{
		return;
	}

	worlddata->setData(msg->datax,msg->datay,msg->dataz,msg->datas);
	g_world.saveWorldData(msg->wprop);
	g_world.syncCsWordDataToGs(msg->wprop);
}

void CSMsgHandler::onRemoveCSGeneFromeGSNotify(Message *message)
{
	MsgRemoveCSGeneFromeGSNotify * msg = dynamic_cast<MsgRemoveCSGeneFromeGSNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}

	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		return;
	}

	player->removeGene(msg->geneid);
}

void CSMsgHandler::onDoctorPlayerNotify(Message *message)
{
	MsgDoctorPlayerNotify *msg = dynamic_cast<MsgDoctorPlayerNotify*>(message);
	if(msg == nullptr)
	{
		return;
	}
	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		return;
	}
	player->removeGene(201);
	EntityOperationHelper::syncPlayerCombatCombo(*player);
	Combat* cbt = player->getCombat();
	if(cbt == nullptr)
	{
		return;
	}
	CombatHelper::updateHP(*cbt, cbt->getMaxHP());
	CombatHelper::updateMP(*cbt, cbt->getMaxMP());
}

void CSMsgHandler::onGetPlayerBaseInfoFromCSRequest(Message *message)
{
	MsgGetPlayerBaseInfoFromCSRequest *msg = dynamic_cast<MsgGetPlayerBaseInfoFromCSRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}

	if(msg->serverId <= 0 || g_world.getWarZoneIdByGameServeID(msg->serverId) <= 0)
	{
		return;
	}	

	MsgGetPlayerBaseInfoFromGSRequest *req = new MsgGetPlayerBaseInfoFromGSRequest();
	if(req == nullptr)
	{
		return;
	}
	req->setUserData(msg->serverId);
	req->srcPid = msg->srcPid;
	req->srcServerId = msg->srcServerId;

	req->pid = msg->pid;
	req->serverId = msg->serverId;
	g_app.postToNetService(req);
}

void CSMsgHandler::onGetPlayerBaseInfoFromGSResponse(Message *message)
{
	MsgGetPlayerBaseInfoFromGSResponse *msg = dynamic_cast<MsgGetPlayerBaseInfoFromGSResponse*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(msg->srcServerId <= 0 || g_world.getWarZoneIdByGameServeID(msg->srcServerId) <= 0)
	{
		return;
	}	

	MsgGetPlayerBaseInfoFromCSResponse *res = new MsgGetPlayerBaseInfoFromCSResponse();
	if(res == nullptr)
	{
		return;
	}

	res->setUserData(msg->srcServerId);

	res->pid = msg->pid;
	res->srcPid = msg->srcPid;
	res->gender = msg->gender;
	res->job = msg->job;
	res->weapon = msg->weapon;
	res->dressWeapon = msg->dressWeapon;
	res->cloth = msg->cloth;
	res->dressCloth = msg->dressCloth;
	res->hat = msg->hat;
	res->shield = msg->shield;
	res->guardLevel = msg->guardLevel;
	res->hunhuan = msg->hunhuan;
	res->jingling = msg->jingling;

	g_app.postToNetService(res);
}

void CSMsgHandler::onReceiveGSRankList(Message *message)
{
	MsgSendGSRankToCS *msg = dynamic_cast<MsgSendGSRankToCS*>(message);
	if(msg == nullptr)
	{
		return;
	}

	LOG_INFO("++++++/////serverId: %d, warZoomId: %d", msg->serverId, msg->warZoomId);

	g_rank_mgr.addRankData(msg->type, msg->list, msg->warZoomId, msg->serverId);
}
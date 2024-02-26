#include "stdafx.h"
#include "CSHelper.h"
#include "Application.h"
#include "message/DBMsgConsignment.h"
#include "Entity/WorldPlayerManager.h"
#include "Scene/Scene.h"
#include "Event/EventData.h"
#include "World/World.h"
#include "WarZoneDropBroadcast/DropBroadcastMgr.h"
#include "Consignment/ConsignmentStore.h"
#include "Gene/Gene.h"
#include "Purchase/PurchaseManager.h"
#include "Rank/RankManager.h"

static std::unordered_map<int, int> g_gameserver_sessionid_serverid_map;

void CSHelper::leaveCSMap(int pid, int sourceServerId, int reason/* =0 */, int dstMapId/* =0 */, int posX/* =0 */, int posY/* =0 */,int sceneInstanceId,int enterSceneType)
{
	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(pid);
	if (player != nullptr)
	{
		player->onLeaveCSMap();
	}

	MsgLeaveFromCrossServerMapResponse* rsp = new MsgLeaveFromCrossServerMapResponse;
	rsp->setUserData(sourceServerId);
	rsp->playerId = pid;
	rsp->dstMapId = dstMapId;
	rsp->posX = posX;
	rsp->posY = posY;
	rsp->reason = reason;
	rsp->sceneInstanceId = sceneInstanceId;
	rsp->enterSceneType = enterSceneType;
	g_app.postToNetService(rsp);

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: notify gameserver player leave cross map,  playerInfo = {player_id = %d}",
			pid, pid);
	}
}

void CSHelper::enterCSMap(int pid, int dstMapId, int posX, int posY)
{
	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(pid);
	if (player != nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: player ready to enter cross map,  playerInfo = {player_id = %d, player_name = %s, mapId = %d}",
				player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), dstMapId);
		}

		if(dstMapId > 0)
		{
			player->onEnterCSMap(dstMapId, posX, posY);
		}
	}
}

void CSHelper::sendCrossDropRequest(Entity* entity, Entity* killer)
{
	if(entity == nullptr)
	{
		return;
	}

	EntityPlayer* player = (EntityPlayer*)(entity);
	if(player == nullptr)
	{
		return;
	}

	Scene *scene = player->getScene();
	if(scene == nullptr)
	{
		return;
	}

	CSHelper::syncPosToGS(player);

	MsgCrossMapDropRequest* request = new MsgCrossMapDropRequest;
	request->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	request->playerId = player->getPlayerID();
	request->mapId = scene->getStaticID();
	request->mapLineId = scene->getProp(SCENE_PROP_LINE_ID) > 0 ? scene->getProp(SCENE_PROP_LINE_ID) : 1;
	request->posx = player->getPositionX();
	request->posy = player->getPositionY();
	request->killerName = killer->getName();
	g_app.postToNetService(request);
}

int CSHelper::conveyToScene(Entity* player, int mapId, int posX, int posY)
{
	MsgConveyToSceneRequest* request = new MsgConveyToSceneRequest;
	request->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	request->playerId = player->getGlobalID();
	request->mapId = mapId;
	request->posX = posX;
	request->posY = posY;
	g_app.postToNetService(request);

	return ERROR_DELAY_ENTER;
}

void CSHelper::syncPlayerPropToGS(Entity* player,int prop,int value)
{

}


void CSHelper::syncEventDataToGS(Entity* player, int eid)
{
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
	req->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	req->playerId = player->getGlobalID();
	req->data.id = event_data->getID();
	req->data.timeIndex = event_data->getTimeIndex();
	req->data.datax = event_data->getDataX() - lastSaveData.m_datax;
	req->data.datay = event_data->getDataY() - lastSaveData.m_datay;
	req->data.dataz = event_data->getDataZ() - lastSaveData.m_dataz;

	g_app.postToNetService(req);
}

void CSHelper::syncPosToGS(EntityPlayer* player)
{
	if(player == nullptr)
	{
		return;
	}

	Scene *scene = player->getScene();
	if(scene == nullptr)
	{
		return;
	}

	MsgSyncCSPosToGSNotify* notify = new MsgSyncCSPosToGSNotify;
	notify->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	notify->playerId = player->getGlobalID();
	notify->mapId = scene->getStaticID();
	notify->mapLineId = scene->getProp(SCENE_PROP_LINE_ID) > 0 ? scene->getProp(SCENE_PROP_LINE_ID) : 1;
	notify->posX = player->getPositionX();
	notify->posY = player->getPositionY();
	g_app.postToNetService(notify);
}

void CSHelper::createPlayerInCrossServerFinished(EntityPlayer* player)
{
	if(player == nullptr)
	{
		return;
	}

	MsgCreatePlayerInCrossServerResponse* rsp = new MsgCreatePlayerInCrossServerResponse;
	rsp->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	rsp->playerId = player->getPlayerID();
	rsp->playerEid = player->getID();
	g_app.postToNetService(rsp);

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: create player in cross server end, playerInfo = {player_id = %d, player_name = %s}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str());

		LOG_INFO("CS_MODULE_LOG_%d: notify gameserver player created success, playerInfo = {player_id = %d, player_name = %s, player_server_id = %d}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	}
}

void CSHelper::syncBossInfoToGS(Scene* scene, int bossIndex, int gameServerId)
{
	int warZoneLineId = scene->getProp(SCENE_PROP_WAR_ZONE_LINE_ID);
	if(warZoneLineId == 0)
	{
		return;
	}

	std::map<int, BossInfo*> bossInfoList = scene->getBossInfo(bossIndex);
	if(bossInfoList.size() == 0)
	{
		return;
	}

	int warZoneId = g_world.getID() * 1000 + warZoneLineId;
	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);
	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		if(iter->serverId == gameServerId || gameServerId == 0)
		{
			MsgSyncBossInfoToGSNotify *notify = new MsgSyncBossInfoToGSNotify;
			notify->setUserData(iter->serverId);
			notify->serverId = iter->serverId;
			notify->sceneId = scene->getStaticID();

			for(auto it = bossInfoList.begin(); it != bossInfoList.end(); it++)
			{
				CrossBossInfo info;
				info.index = it->first;
				info.bossId = it->second->bossId;
				info.freshTime = it->second->freshTime;
				info.alive = it->second->alive ? 1 : 0;

				notify->list.push_back(info);
			}

			g_app.postToNetService(notify);
		}
	}
}

void CSHelper::getQualifiedPlayerNearby(EntityPlayer* player, int condition)
{
	if(player == nullptr)
	{
		return;
	}

	Scene *scene = player->getScene();
	if(scene == nullptr)
	{
		return;
	}

	MsgGetQualifiedPlayerListNearbyResponse *rsp = new MsgGetQualifiedPlayerListNearbyResponse;
	rsp->setUserData(player->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	rsp->pid = player->getPlayerID();
	rsp->condition = condition;
	
	scene->for_each_in_grid_around(player->getGridX(),
		player->getGridY(), ENTITY_SCOPE_PLAYER, [&](Entity* entity)
	{
		switch (condition)
		{
		case PlayerNearCondition::CONDITION_NEAR_TEAM:
			if(entity->getProp(ENTITY_PROP_TEAM_ID) > 0 && entity->getProp(ENTITY_PROP_TEAM_ID) != player->getProp(ENTITY_PROP_TEAM_ID))
			{
				rsp->list.push_back(entity->getGlobalID());
			}
			break;
		default:
			break;
		}
	});

	if(rsp->list.size() == 0)
	{
		delete rsp;
		return;
	}

	g_app.postToNetService(rsp);
}

void CSHelper::broadcastDropToWarZone(int killerPid, std::string killerName, int killerServerId, int mapId, int monsterId, int dropItemId, int dropTime, bool top)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(killerServerId);
	if(warZoneId == 0)
	{
		return;
	}

	DropInfo info;
	info.killerPid = killerPid;
	info.killerName = killerName;
	info.mapId = mapId;
	info.monsterId = monsterId;
	info.dropItemId = dropItemId;
	info.dropTime = dropTime;

// 	std::vector<WarZoneServerInfo> serverInfoList;
// 	g_world.getWarZoneServerList(warZoneId, serverInfoList);
// 	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
// 	{
// 		if(iter->serverId == killerServerId)
// 		{
// 			info.gameServerName = iter->serverName;
// 			break;
// 		}
// 	}


	MsgSyncWarZoneDropInfo *notify = new MsgSyncWarZoneDropInfo;
	notify->setUserData(killerServerId);
	notify->reload = 0;
	if(top)
	{
		notify->topDropInfoList.push_back(*((WarZoneDropInfo*)(&info)));
	}
	else
	{
		notify->dropInfoList.push_back(*((WarZoneDropInfo*)(&info)));
	}
	g_app.postToNetService(notify);

	g_drop_broadcast_mgr.addDropInfoRecord(warZoneId, info, top);

// 	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
// 	{
// 		MsgSyncWarZoneDropInfo *notify = new MsgSyncWarZoneDropInfo;
// 		notify->setUserData(iter->serverId);
// 		notify->reload = 0;
// 		if(top)
// 		{
// 			notify->topDropInfoList.push_back(*((WarZoneDropInfo*)(&info)));
// 		}
// 		else
// 		{
// 			notify->dropInfoList.push_back(*((WarZoneDropInfo*)(&info)));
// 		}
// 		g_app.postToNetService(notify);
// 	}

	//战区播报
//	lua::call(lua::L, "Cross.boardcastMonsterDrop", killerName, mapId, monsterId, dropItemId, warZoneId % 1000);
}

void CSHelper::addGeneInGS(Entity* entity, Gene* gene)
{
	MsgAddGeneInGameServerRequest* req = new MsgAddGeneInGameServerRequest();
	req->setUserData(entity->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	req->pid = entity->getGlobalID();
	req->geneId = gene->getID();
	req->geneType = gene->getType();
	req->geneGroup = gene->getGroupID();
	req->geneDuration = gene->getDuration();
	req->geneInherit = gene->isInheritHostDead() ? 1 : 0;
	req->geneDatax = gene->getDataX();
	req->geneDatay = gene->getDataY();
	req->geneDataz = gene->getDataZ();
	req->geneDatau = gene->getDataU();

	g_app.postToNetService(req);
}

void CSHelper::rmvGeneFromGS(Entity* entity, int id)
{
	MsgRmvGeneFromGameServerRequest* req = new MsgRmvGeneFromGameServerRequest();
	req->setUserData(entity->getProp(ENTITY_PROP_SOURCE_WORLD_ID));
	req->pid = entity->getGlobalID();
	req->geneId = id;
	g_app.postToNetService(req);
}

void CSHelper::onWarZoneChanged()
{
	
}

void CSHelper::notifyPlayerActionToGS(int pid, int gameServerId, int actionType, std::map<int, int>& intParams, std::map<int, std::string>& strParams)
{
	if(!g_config.isCrossServer())
	{
		return;
	}

	MsgPlayerCSActionNotify* notify = new MsgPlayerCSActionNotify();
	notify->setUserData(gameServerId);
	notify->pid = pid;
	notify->crossActionType = actionType;
	for(auto iter = intParams.begin(); iter != intParams.end(); iter++)
	{
		if(iter->second != 0)
		{
			CrossIntProp param;
			param.ctype = iter->first;
			param.data = iter->second;

			notify->intParams.push_back(param);
		}
	}
	for(auto iter = strParams.begin(); iter != strParams.end(); iter++)
	{
		if(iter->second != "")
		{
			CrossStrProp param;
			param.ctype = iter->first;
			param.data = iter->second;

			notify->strParams.push_back(param);
		}
	}
	g_app.postToNetService(notify);
}

void CSHelper::broadcastCrossAuctionItemAddToWarZone(DBAcution* au)
{
	int warZoneId = au->war_zone_id;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossAuctionItemAddNotify *notify = new MsgCrossAuctionItemAddNotify;
		notify->setUserData(iter->serverId);
		notify->reload = 0;
		notify->auctionItemList.push_back(*((CrossAcution*)(au)));
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossAuctionItemRmvToWarZone(DBAcution* au)
{
	int warZoneId = au->war_zone_id;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossAuctionItemRmvNotify *notify = new MsgCrossAuctionItemRmvNotify;
		notify->setUserData(iter->serverId);
		notify->auctionItemList.push_back(*((CrossAcution*)(au)));
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossAuctionItemUpdToWarZone(DBAcution* au)
{
	int warZoneId = au->war_zone_id;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossAuctionItemUpdNotify *notify = new MsgCrossAuctionItemUpdNotify;
		notify->setUserData(iter->serverId);
		notify->auctionItem = *((CrossAcution*)(au));
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossConsignmentAddToWarZone(Consignment* consignment)
{
	int warZoneId = consignment->sellerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossConsignmentAddNotify *notify = new MsgCrossConsignmentAddNotify();
		notify->setUserData(iter->serverId);

		CrossConsignment croCons; 
		croCons.sellerPid = consignment->sellerPid;
		croCons.sellerName = consignment->sellerName;
		croCons.sellerServerId = consignment->sellerServerId;
		croCons.sellerServerName = consignment->sellerServerName;
		croCons.sellerWarZoneId = consignment->sellerWarZoneId;
		croCons.cid = consignment->cid;
		croCons.sid = consignment->sid;
		croCons.count = consignment->count;
		croCons.taxRate = consignment->taxRate;
		croCons.price = consignment->price;
		croCons.ctime = consignment->ctime;
		croCons.etime = consignment->etime;
		croCons.firstOwner = consignment->firstOwner;
		croCons.appraiser = consignment->appraiser;
		croCons.mailTip = consignment->mailTip;
		std::vector<CrossConsignmentItemProp> notifyprops;

		for (int i = 0;i < consignment->props.size();i++)
		{
			CrossConsignmentItemProp itemprop;
			itemprop.idx = consignment->props[i].idx;
			itemprop.data = consignment->props[i].data;
			notifyprops.push_back(itemprop);
		}
		croCons.props = notifyprops;
		notify->item = croCons;

		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossConsignmentRmvToWarZone(Consignment* consignment)
{
	int warZoneId = consignment->sellerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossConsignmentRmvNotify* notify = new MsgCrossConsignmentRmvNotify();
		notify->setUserData(iter->serverId);
		notify->sellerPid = consignment->sellerPid;
		notify->cid = consignment->cid;
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossConsignmentUpdToWarZone(Consignment* consignment)
{
	int warZoneId = consignment->sellerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossConsignmentUpdNotify* notify = new MsgCrossConsignmentUpdNotify();
		notify->setUserData(iter->serverId);
		notify->sellerPid = consignment->sellerPid;
		notify->cid = consignment->cid;
		notify->newCount = consignment->count;
		g_app.postToNetService(notify);
	}
}

void CSHelper::syncAllCrossConsignmentToGS(int gameServerId)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(gameServerId);
	if(warZoneId == 0)
	{
		return;
	}

	MsgSyncAllCrossConsignmentNotify* notify = new MsgSyncAllCrossConsignmentNotify();
	notify->setUserData(gameServerId);
	
	std::vector<void*> list;
	g_consignment_store.getConsignments(list, warZoneId);
	for(auto iter = list.begin(); iter != list.end(); iter++)
	{
		CrossConsignment * consignment = new CrossConsignment;
		Consignment * cons = (Consignment *)(*iter); 
		consignment->sellerPid = cons->sellerPid;
		consignment->sellerName = cons->sellerName;
		consignment->sellerServerId = cons->sellerServerId;
		consignment->sellerServerName = cons->sellerServerName;
		consignment->sellerWarZoneId = cons->sellerWarZoneId;
		consignment->sid = cons->sid;
		consignment->cid = cons->cid;
		consignment->count = cons->count;
		consignment->taxRate = cons->taxRate;
		consignment->price = cons->price;
		consignment->ctime = cons->ctime;
		consignment->etime = cons->etime;
		consignment->firstOwner = cons->firstOwner;
		consignment->appraiser = cons->appraiser;
		consignment->mailTip = cons->mailTip;

		std::vector<CrossConsignmentItemProp> csprops;

		for (int i = 0;i < cons->props.size(); i++)
		{
			ConsignmentItemProp  cprop = cons->props[i];
			CrossConsignmentItemProp tprop;
			tprop.idx = cprop.idx;
			tprop.data = cprop.data;
			csprops.push_back(tprop);
		}
		consignment->props = csprops;

		notify->list.push_back(*consignment);
	}

	g_app.postToNetService(notify);
}

void CSHelper::broadcastCrossPurchaseAddToWarZone(Purchase* purchase)
{
	int warZoneId = purchase->buyerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossPurchaseAddNotify *notify = new MsgCrossPurchaseAddNotify();
		notify->setUserData(iter->serverId);
		notify->crossPurchase = *((CrossPurchase*)purchase);
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossPurchaseRmvToWarZone(Purchase* purchase)
{
	int warZoneId = purchase->buyerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossPurchaseRmvNotify* notify = new MsgCrossPurchaseRmvNotify();
		notify->setUserData(iter->serverId);
		notify->buyerPid = purchase->buyerPid;
		notify->purchaseId = purchase->purchaseId;
		g_app.postToNetService(notify);
	}
}

void CSHelper::broadcastCrossPurchaseUpdToWarZone(Purchase* purchase)
{
	int warZoneId = purchase->buyerWarZoneId;

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for(auto iter = serverInfoList.begin(); iter != serverInfoList.end(); iter++)
	{
		MsgCrossPurchaseUpdNotify* notify = new MsgCrossPurchaseUpdNotify();
		notify->setUserData(iter->serverId);
		notify->buyerPid = purchase->buyerPid;
		notify->purchaseId = purchase->purchaseId;
		notify->newCount = purchase->count;
		g_app.postToNetService(notify);
	}
}

void CSHelper::syncAllCrossPurchaseToGS(int gameServerId)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(gameServerId);
	if(warZoneId == 0)
	{
		return;
	}

	MsgSyncAllCrossPurchaseNotify* notify = new MsgSyncAllCrossPurchaseNotify();
	notify->setUserData(gameServerId);

	std::vector<void*> list;
	g_purchase_mgr.getPurchases(list, warZoneId);
	for(auto iter = list.begin(); iter != list.end(); iter++)
	{
		CrossPurchase* crossPurchase = (CrossPurchase*)(*iter);
		notify->list.push_back(*crossPurchase);
	}

	g_app.postToNetService(notify);
}

void CSHelper::removeChatToAllWarZone(int pid, int src_server_id)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(src_server_id);
	if(warZoneId == 0)
	{
		return;
	}

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for (auto& it : serverInfoList)
	{
		MsgRemoveChatCrossNotify* notify = new MsgRemoveChatCrossNotify;
		notify->setUserData(it.serverId);
		notify->pid = pid;
		g_app.postToNetService(notify);
	}
}

void CSHelper::SyncCrossActivityToGS(int gameServerId, bool reset)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(gameServerId);
	if(warZoneId == 0) 
	{
		return;
	}

	int type = g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_RANK_TYPE);
	if(type == 0)
	{
		return;
	}

	MsgSyncCrossActivityNotify * notify = new MsgSyncCrossActivityNotify;
	if(notify == nullptr)
	{
		return;
	}
	notify->setUserData(gameServerId);
	notify->type = type;
	notify->reset = reset ? 1 : 0;
	g_app.postToNetService(notify);
}

void CSHelper::loadCrossRankFromToGS(int gameServerId)
{
	int warZoneId = g_world.getWarZoneIdByGameServeID(gameServerId);
	if(warZoneId == 0) 
	{
		return;
	}

	// 跨服启动时，需要通知原服将跨服排行榜数据同步过来
	MsgLoadCSRankNotify *notify = new MsgLoadCSRankNotify;
	notify->setUserData(gameServerId);
	notify->warZoomId = warZoneId;
	notify->serverId = gameServerId;
	g_app.postToNetService(notify);
}

void CSHelper::syncCrossRankToGS(int type, int warZoomId)
{
	for(auto iter = g_world.getAllWarZoneInfo().begin(); iter != g_world.getAllWarZoneInfo().end(); iter++)
	{
		if(iter->first == warZoomId)
		{
			Rank* rank = g_rank_mgr.getRankByType(type);
			if (rank != nullptr)
			{
				std::vector<CrossDBRankData> list;
				std::vector<RankItem*>& rankItems = rank->getRankItemVecs();
				for (size_t i = 0; i < rankItems.size(); i++)
				{
					RankItem* it = rankItems[i];
					CrossDBRankData* cDBRankData = new CrossDBRankData();
					cDBRankData->datax = it->getDataX();
					cDBRankData->datay = it->getDataY();
					cDBRankData->dataz = it->getDataZ();
					cDBRankData->time = it->getTime();
					cDBRankData->pid = it->getPid();
					cDBRankData->gid = it->getGid();

					list.push_back(*cDBRankData);
				}

				//将最新的数据同步到该战区下的所有原服
				for(auto iter = g_world.getAllWarZoneInfo().begin(); iter != g_world.getAllWarZoneInfo().end(); iter++)
				{
					for(auto it = iter->second.begin(); it != iter->second.end(); it++)
					{
						MsgSendCSRankToGS *notify = new MsgSendCSRankToGS;
						notify->setUserData(it->serverId);
						notify->type = type;
						notify->list = list;
						g_app.postToNetService(notify);
					}
				}	
			}
		}
	}
}

void CSHelper::bindGameServerIdBySessionId(int session_id, int server_id)
{
	g_gameserver_sessionid_serverid_map[session_id] = server_id;
}

void CSHelper::unbindGameServerIdBySessionId(int session_id)
{
	g_gameserver_sessionid_serverid_map.erase(session_id);
}

int CSHelper::getGameServerIdBySessionId(int session_id)
{
	auto it = g_gameserver_sessionid_serverid_map.find(session_id);
	return (it != g_gameserver_sessionid_serverid_map.end()) ? it->second : 0;
}

void CSHelper::CS2GS(Entity& entity, int funcid, int datax, int datay, int dataz, const std::string& datas)
{
	if (!g_config.isCrossServer())
	{
		return;
	}

	int game_server_id = entity.getProp(ENTITY_PROP_SOURCE_WORLD_ID);
	int pid = entity.getGlobalID();

	CS2GS(game_server_id, funcid, pid, datax, datay, dataz, datas);
}

void CSHelper::CS2GS(int game_server_id, int funcid, int pid, int datax, int datay, int dataz, const std::string& datas)
{
	if (!g_config.isCrossServer())
	{
		return;
	}

	MsgCS2GS *msg = new MsgCS2GS();
	msg->funcID = funcid;
	msg->pid = pid;
	msg->datax = datax;
	msg->datay = datay;
	msg->dataz = dataz;
	msg->datas = datas;

	if (game_server_id == -1)
	{
		msg->setUserData(0);

		MsgBroadcast *broadcast = new MsgBroadcast;
		broadcast->m_message = msg;
		g_app.postToNetService(broadcast);
	}
	else
	{
		msg->setUserData(game_server_id);
		g_app.postToNetService(msg);
	}
}

void CSHelper::CS2WZ(int warZoneId, int funcid, int pid, int datax, int datay, int dataz, const std::string& datas)
{
	if (!g_config.isCrossServer())
	{
		return;
	}

	std::vector<WarZoneServerInfo> serverInfoList;
	g_world.getWarZoneServerList(warZoneId, serverInfoList);

	for (auto it = serverInfoList.begin(); it != serverInfoList.end(); it++)
	{
		MsgCS2GS *msg = new MsgCS2GS;
		msg->setUserData(it->serverId);
		msg->funcID = funcid;
		msg->pid = pid;
		msg->datax = datax;
		msg->datay = datay;
		msg->dataz = dataz;
		msg->datas = datas;
		g_app.postToNetService(msg);
	}
}

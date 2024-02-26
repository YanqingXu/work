#include <sstream>
#include "stdafx.h"
#include "GSMsgHandler.h"
#include "Cross/GSHelper.h"
#include "Application.h"
#include "NetService.h"
#include "LogicService.h"
#include "Entity/EntityLua.h"
#include "Entity/WorldPlayerManager.h"
#include "Entity/EntityOperationHelper.h"
#include "Combat/Combat.h"
#include "Item/ItemOperationHelper.h"
#include "Scene/SceneOperationHelper.h"
#include "Event/EventData.h"
#include "World/World.h"
#include "OperationHelper.h"
#include "Team/TeamMsgHandler.h"
#include "WarZoneDropBroadcast/DropBroadcastMgr.h"
#include "Auction/AuctionManager.h"
#include "Consignment/ConsignmentStore.h"
#include "Consignment/ConsignmentHelper.h"
#include "Holiday/HolidayOperationHelper.h"
#include "message/DBMsgConsignment.h"
#include "message/MsgCenter.h"
#include "message/DBMsgRecords.h"
#include "message/DBMsgMail.h"
#include "message/MsgGsToGs.h"
#include "message/DBMsgPlayer.h"
#include "Player/PlayerMsgKeepManager.h"
#include "Purchase/PurchaseManager.h"
#include "Purchase/PurchaseHelper.h"
#include "Rank/RankManager.h"

GSMsgHandler::GSMsgHandler(Service *service) :
	Module(service)
{
	//center server --> game server
	registerMessageHandler<MsgCS2GS>(std::bind(&GSMsgHandler::onCS2GS, this, std::placeholders::_1));
	registerMessageHandler<MsgWarZoneInfoNotify>(std::bind(&GSMsgHandler::onWarZoneInfoNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgFindNewCrossServerNotify>(std::bind(&GSMsgHandler::onFindNewCrossServerNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSendCrossMailFromCenter>(std::bind(&GSMsgHandler::onSendCrossMailFromCenter, this, std::placeholders::_1));


	//cross server --> game server
	registerMessageHandler<MsgAddHYDScoreNotify>(std::bind(&GSMsgHandler::onAddHYDScore, this, std::placeholders::_1));
	registerMessageHandler<MsgSendSWZDZAwardNotify>(std::bind(&GSMsgHandler::onSendSWZDZAward, this, std::placeholders::_1));
	registerMessageHandler<MsgCreatePlayerInCrossServerResponse>(std::bind(&GSMsgHandler::onCreatePlayerInCrossServerResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgLeaveFromCrossServerMapResponse>(std::bind(&GSMsgHandler::onLeaveFromCrossServerMapResponse, this, std::placeholders::_1));

	registerMessageHandler<MsgSyncInfoToGameServerRequest>(std::bind(&GSMsgHandler::onSyncInfoToGameServerRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgNotifyGameServerExpAdd>(std::bind(&GSMsgHandler::onNotifyGameServerExpAdd, this, std::placeholders::_1));
	registerMessageHandler<MsgNotifyGameServerItemAdd>(std::bind(&GSMsgHandler::onNotifyGameServerItemAdd, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPlayerEquipInfoRequest>(std::bind(&GSMsgHandler::onGetPlayerEquipInfoRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossMapDropRequest>(std::bind(&GSMsgHandler::onCrossMapDropRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgReviveInCSMapResponse>(std::bind(&GSMsgHandler::onReviveInCSMapResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgConveyToSceneRequest>(std::bind(&GSMsgHandler::onConveyToSceneRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncEventDataRequest>(std::bind(&GSMsgHandler::onSyncEventDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncCSPosToGSNotify>(std::bind(&GSMsgHandler::onSyncCSPosToGSNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncBossInfoToGSNotify>(std::bind(&GSMsgHandler::onSyncBossInfoToGSNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgAddGeneInGameServerRequest>(std::bind(&GSMsgHandler::onAddGeneInGameServerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRmvGeneFromGameServerRequest>(std::bind(&GSMsgHandler::onRmvGeneFromGameServerRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgGetQualifiedPlayerListNearbyResponse>(std::bind(&GSMsgHandler::onGetQualifiedPlayerListNearbyResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncWarZoneDropInfo>(std::bind(&GSMsgHandler::onSyncWarZoneDropInfo, this, std::placeholders::_1));

	registerMessageHandler<MsgCrossAuctionItemAddNotify>(std::bind(&GSMsgHandler::onCrossAuctionItemAddNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossAuctionItemRmvNotify>(std::bind(&GSMsgHandler::onCrossAuctionItemRmvNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossAuctionItemUpdNotify>(std::bind(&GSMsgHandler::onCrossAuctionItemUpdNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckBuyCrossAuctionItemResponse>(std::bind(&GSMsgHandler::onCheckBuyCrossAuctionItemRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgBuyCrossAuctionItemResponse>(std::bind(&GSMsgHandler::onBuyCrossAuctionItemRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossAuctionRecordNotify>(std::bind(&GSMsgHandler::onCrossAuctionRecordNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossGetPlayerSerializeInfoC2G>(std::bind(&GSMsgHandler::onCrossGetPlayerSerializeInfoC2G, this, std::placeholders::_1));

	registerMessageHandler<MsgCrossConsignmentAddNotify>(std::bind(&GSMsgHandler::onCrossConsignmentAddNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossConsignmentRmvNotify>(std::bind(&GSMsgHandler::onCrossConsignmentRmvNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossConsignmentUpdNotify>(std::bind(&GSMsgHandler::onCrossConsignmentUpdNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgAddConsignmentToCrossResponse>(std::bind(&GSMsgHandler::onAddConsignmentToCrossRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckBuyCrossConsignmentResponse>(std::bind(&GSMsgHandler::onCheckBuyCrossConsignmentRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgSendSellerRewardResponse>(std::bind(&GSMsgHandler::onSendSellerRewardRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgRmvCrossConsignmentResponse>(std::bind(&GSMsgHandler::onRmvCrossConsignmentRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncAllCrossConsignmentNotify>(std::bind(&GSMsgHandler::onSyncAllCrossConsignmentNotify, this, std::placeholders::_1));

	//求购
	registerMessageHandler<MsgCrossPurchaseAddNotify>(std::bind(&GSMsgHandler::onCrossPurchaseAddNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossPurchaseRmvNotify>(std::bind(&GSMsgHandler::onCrossPurchaseRmvNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgCrossPurchaseUpdNotify>(std::bind(&GSMsgHandler::onCrossPurchaseUpdNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgAddPurchaseToCrossResponse>(std::bind(&GSMsgHandler::onAddPurchaseToCrossRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgTrySellCrossPurchaseResponse>(std::bind(&GSMsgHandler::onTrySellCrossPurchaseRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgSendBuyerPurchaseItemResponse>(std::bind(&GSMsgHandler::onSendBuyerPurchaseItemRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgRmvCrossPurchaseResponse>(std::bind(&GSMsgHandler::onRmvCrossPurchaseRsp, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncAllCrossPurchaseNotify>(std::bind(&GSMsgHandler::onSyncAllCrossPurchaseNotify, this, std::placeholders::_1));

	//玩家在跨服的行为
	registerMessageHandler<MsgPlayerCSActionNotify>(std::bind(&GSMsgHandler::onPlayerCSActionNotify, this, std::placeholders::_1));

	//跨服聊天相关
	registerMessageHandler<MsgSyncCrossChatNotify>(std::bind(&GSMsgHandler::onCrossChatNotify, this, std::placeholders::_1));
	//跨服查看角色装备
	registerMessageHandler<MsgGetPlayerEquipInfoResponse>(std::bind(&GSMsgHandler::onGetPlayerEquipInfoResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgNewGetPlayerEquipInfoResponse>(std::bind(&GSMsgHandler::onNewGetPlayerEquipInfoResponse, this, std::placeholders::_1));

	registerMessageHandler<MsgGetBossCntInCrossMapNotify>(std::bind(&GSMsgHandler::onGetBossCntInCrossMapNotify, this, std::placeholders::_1));
	registerMessageHandler<MsgSyncSkillExpAddToGameServer>(std::bind(&GSMsgHandler::onSyncSkillExpAddToGameServer, this, std::placeholders::_1));

	registerMessageHandler<MsgRemoveChatCrossNotify>(std::bind(&GSMsgHandler::onRemoveChatCrossNotify, this, std::placeholders::_1));

	//发神威狱奖励
	registerMessageHandler<MsgSendSWYAwardNotify>(std::bind(&GSMsgHandler::onSendSWYAward, this, std::placeholders::_1));

	//发行会对战奖励
	registerMessageHandler<MsgSendGuildBattleAwardNotify>(std::bind(&GSMsgHandler::onSendGuildBattleAward, this, std::placeholders::_1));

	registerMessageHandler<MsgGSBroadcastAllGSResponse>(std::bind(&GSMsgHandler::onGSBroadcastAllGSResponse, this, std::placeholders::_1));

	registerMessageHandler<MsgSyncWordDataToGSNotify>(std::bind(&GSMsgHandler::onSyncWordDataToGameServerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPlayerBaseInfoFromGSRequest>(std::bind(&GSMsgHandler::onGetPlayerBaseInfoFromGSRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPlayerBaseInfoFromCSResponse>(std::bind(&GSMsgHandler::onGetPlayerBaseInfoFromCSResponse, this, std::placeholders::_1));
	// cross server将跨服排行榜数据发过来
	registerMessageHandler<MsgLoadCSRankNotify>(std::bind(&GSMsgHandler::onLoadCSRank, this, std::placeholders::_1));
	registerMessageHandler<MsgSendCSRankToGS>(std::bind(&GSMsgHandler::onReceiveCSRankList, this, std::placeholders::_1));

	registerMessageHandler<MsgSendPlayerGreyNameToGS>(std::bind(&GSMsgHandler::onSendPlayerGreyNameToGS, this, std::placeholders::_1));
	registerMessageHandler<MsgSendPlayerKillWhiteRoleToGS>(std::bind(&GSMsgHandler::onSendPlayerKillWhiteRoleToGS, this, std::placeholders::_1));
}

GSMsgHandler::~GSMsgHandler()
{
}

bool GSMsgHandler::initialize()
{
	if (!__super::initialize())
	{
		return false;
	}

	return true;
}

void GSMsgHandler::onCS2GS(Message *message)
{
	MsgCS2GS* msg = dynamic_cast<MsgCS2GS*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	lua::call(lua::L, "Entity.CS2GS", msg->funcID, msg->pid, msg->datax, msg->datay, msg->dataz, msg->datas);
}

void GSMsgHandler::onWarZoneInfoNotify(Message* message)
{
	if(g_config.isCrossServer())
	{
		return;
	}

	MsgWarZoneInfoNotify* msg = dynamic_cast<MsgWarZoneInfoNotify*>(message);
	if (msg == nullptr)
	{
		return;
	}

	if(msg->list.size() > 1)
	{
		LOG_ERROR("CS_MODULE_INFO: multiple warZone configuration!");
		return;
	}

	WarZoneInfoDetail newWarZoneInfo;
	if(msg->list.size() == 1)
	{
		newWarZoneInfo = msg->list[0];
	}

	std::string newServerNameList;
	if(newWarZoneInfo.warZoneId > 0)
	{
		for(auto iter = newWarZoneInfo.gameServerInfoList.begin(); iter != newWarZoneInfo.gameServerInfoList.end(); iter++)
		{
			std::stringstream str;
			str << iter->serverName << ",";
			newServerNameList = newServerNameList + str.str();
		}
	}

	WorldData *world_data = g_world.getWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);
	int oldWarZoneId = world_data->getDataX();
	int oldWarZonePreOpenTime = world_data->getDataY();
	int oldWarZoneOpenTime = world_data->getDataZ();
	std::string oldServerNameList = world_data->getDataS();

	if(oldWarZoneId == newWarZoneInfo.warZoneId && oldWarZonePreOpenTime == newWarZoneInfo.warZonePreOpenTime && 
		oldWarZoneOpenTime == newWarZoneInfo.warZoneOpenTime && oldServerNameList == newServerNameList)
	{
		return;
	}
	// else//战区信息发生变化，寄售行商品下架
	// {
	// 	LOG_INFO("GSMsgHandler oldWarZoneId:%d oldWarZoneId:%d",oldWarZoneId,newWarZoneInfo.warZoneId);
	// 	g_consignment_store.deleteAllConsignmentsByWarZoneId(0);
	// }

	LOG_INFO("CS_MODULE_INFO:  ========================> warZone configuration info start<========================");

	g_world.clearWarZoneServerList();

	world_data->setDataX(newWarZoneInfo.warZoneId);
	world_data->setDataY((int)newWarZoneInfo.warZonePreOpenTime);
	world_data->setDataZ((int)newWarZoneInfo.warZoneOpenTime);
	world_data->setDataS(newServerNameList);
	g_world.syncWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);
	g_world.saveWorldData(WORLD_PROP_WAR_ZONE_DATE_INFO);

	
	LOG_INFO("CS_MODULE_INFO:  warZone config info = {warZoneId = %d, warZonePreOpenTime = %s, warZoneOpenTime = %s, serverNameList = %s }",
		newWarZoneInfo.warZoneId, HolidayOperationHelper::timeIntToString(newWarZoneInfo.warZonePreOpenTime).c_str(),HolidayOperationHelper::timeIntToString(newWarZoneInfo.warZoneOpenTime).c_str(),newServerNameList.c_str());
	
	LOG_INFO("CS_MODULE_INFO:  ========================> warZone configuration info end<========================");

	long long now = (long long)time(nullptr);
	WorldData *war_zone_data = g_world.getWorldData(WORLD_PROP_WAR_ZONE_INFO);
	war_zone_data->setDataX(0);
	war_zone_data->setDataY(0);
	war_zone_data->setDataZ(0);
	war_zone_data->setDataS("");
	if(newWarZoneInfo.warZoneId > 0 && now >= newWarZoneInfo.warZoneOpenTime)
	{
		war_zone_data->setDataX(newWarZoneInfo.warZoneId/1000);
		war_zone_data->setDataY(newWarZoneInfo.warZoneId%1000);
		war_zone_data->setDataS(newServerNameList);
	}
	g_world.syncWorldData(WORLD_PROP_WAR_ZONE_INFO);
	g_world.saveWorldData(WORLD_PROP_WAR_ZONE_INFO);

	WorldData *war_zone_status = g_world.getWorldData(WORLD_PROP_WAR_ZONE_STATUS);
	war_zone_status->setDataX(0);
	war_zone_status->setDataY(0);
	war_zone_status->setDataZ(0);
	war_zone_status->setDataS("");
	if(newWarZoneInfo.warZoneId > 0)
	{
		if(now >= newWarZoneInfo.warZoneOpenTime)
		{
			war_zone_status->setDataX(2);
		}
		else if(now >= newWarZoneInfo.warZonePreOpenTime)
		{
			war_zone_status->setDataX(1);
		}
	}
	g_world.syncWorldData(WORLD_PROP_WAR_ZONE_STATUS);
	g_world.saveWorldData(WORLD_PROP_WAR_ZONE_STATUS);

	for(int i = 0; i < 5; i++)
	{
		WorldData *military_evt = g_world.getWorldData(WORLD_PROP_MILITARY_EXPLOITS_RANK_1 + i);
		if(military_evt)
		{
			military_evt->setDataX(0);
			military_evt->setDataY(0);
			military_evt->setDataZ(0);
			military_evt->setDataS("");
		}
		g_world.syncWorldData(WORLD_PROP_MILITARY_EXPLOITS_RANK_1 + i);
		g_world.saveWorldData(WORLD_PROP_MILITARY_EXPLOITS_RANK_1 + i);

		if(i < 3)
		{
			WorldData *GMD_evt = g_world.getWorldData(WORLD_PROP_SHENQIZHONG_RANK_1 + i);
			if(GMD_evt)
			{
				GMD_evt->setDataX(0);
				GMD_evt->setDataY(0);
				GMD_evt->setDataZ(0);
				GMD_evt->setDataS("");
			}
			g_world.syncWorldData(WORLD_PROP_SHENQIZHONG_RANK_1 + i);
			g_world.saveWorldData(WORLD_PROP_SHENQIZHONG_RANK_1 + i);
		}
	}

	GSHelper::onWarZoneChanged(oldWarZoneId, newWarZoneInfo.warZoneId);
	


}

void GSMsgHandler::onFindNewCrossServerNotify(Message* message)
{
	if(g_config.isCrossServer())
	{
		return;
	}

	MsgFindNewCrossServerNotify* msg = dynamic_cast<MsgFindNewCrossServerNotify*>(message);
	if (msg == nullptr)
	{
		return;
	}

	if (msg->isCommonCrossServer != 0)
	{
		WorldData *world_data = g_world.getWorldData(WORLD_PROP_COMMON_CROSS_SERVER_ID);
		world_data->setDataX(msg->serverId);
	}

	g_app.GetNetService()->connectToCrossServer(msg->crossManagerServerAddr, msg->crossManagerServerPort, msg->serverId);
}

void GSMsgHandler::onSendCrossMailFromCenter(Message* message)
{
	MsgSendCrossMailFromCenter* msg = dynamic_cast<MsgSendCrossMailFromCenter*>(message);
	if (msg == nullptr)
	{
		return;
	}

	MsgDBCreateMail *dbmsg = new MsgDBCreateMail;
	dbmsg->pid = msg->pid;
	dbmsg->title = msg->title;
	dbmsg->content = msg->content;
	dbmsg->items = msg->items;
	dbmsg->opcode = msg->opcode;
	dbmsg->ctime = msg->ctime;
	g_app.postToNetService(dbmsg);
}

void GSMsgHandler::onCreatePlayerInCrossServerResponse(Message* message)
{
	MsgCreatePlayerInCrossServerResponse* msg = dynamic_cast<MsgCreatePlayerInCrossServerResponse*>(message);
	if (msg == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_: enter cross scene failed, msg MsgCreatePlayerInCrossServerResponse is invalid");
		}
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d:  enter cross scene failed,  player is logout,  playerInfo = {player_id = %d}", 
				msg->playerId, msg->playerId);
		}
		return;
	}

	if(player->isInGSMap())
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: enter cross scene failed , player is in gsMap, playerInfo = {player_id = %d, player_name = %s}", 
				msg->playerId, msg->playerId, player->getName().c_str());
		}
		return;
	}

	player->setProp(ENTITY_PROP_EID_IN_CROSS_SERVER, msg->playerEid);

	MsgEnterCrossServerNotify* notify = new MsgEnterCrossServerNotify;
	notify->errcode = SUCCESS;
	player->sendMessage(notify);


	if (player->getProp(ENTITY_PROP_TUOGUAN_STATE) == 1)
	{
		MsgEnterGameGuajiRequest *request = new MsgEnterGameGuajiRequest;
		request->setUserData(player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
		request->sourceServerId = g_world.getID();
		request->pid = player->getPlayerID();
		g_app.postToNetService(request);
	}else
	{
		LOG_INFO("ENTITY_PROP_TUOGUAN_STATE  IS 0  player_id = %d, player_name = %s",player->getPlayerID(),player->getName().c_str());
	}

	if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_LITTLE)
	{
		LOG_INFO("CS_MODULE_LOG_%d: create player in cross server successful, playerInfo = {player_id = %d, player_name = %s, cross_server_id = %d}",
			player->getPlayerID(), player->getPlayerID(), player->getName().c_str(), player->getProp(ENTITY_PROP_CROSS_SERVER_ID));
	}
}

void GSMsgHandler::onLeaveFromCrossServerMapResponse(Message* message)
{
	MsgLeaveFromCrossServerMapResponse* msg = dynamic_cast<MsgLeaveFromCrossServerMapResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d:  leave from cross scene failed,  player is logout,  playerInfo = {player_id = %d}", 
				msg->playerId, msg->playerId);
		}
		return;
	}

	if(player->isInGSMap())
	{
		if(g_world.getWarZoneModuleLogLevel() >= LOG_LEVEL_MANY)
		{
			LOG_INFO("CS_MODULE_LOG_%d: leave from cross scene failed , player is already in gsMap, playerInfo = {player_id = %d, player_name = %s}", 
				msg->playerId, msg->playerId, player->getName().c_str());
		}
		return;
	}

	if(msg->reason == LeaveCSMapReason::REASON_SWITCH_CS_MAP)
	{
		//首先回到原服
		player->onEnterGSMap(msg->reason);

		//接着前往跨服地图
		int ret = SceneOperationHelper::enterScene(g_scene_mgr, *player, msg->dstMapId, msg->posX, msg->posY);
		if(ret != ERROR_DELAY_ENTER)
		{
			SceneOperationHelper::conveyEntityBack(*player);
		}

		player->setProp(ENTITY_PROP_FLY_REASON, 0);
		player->setProp(ENTITY_PROP_FLY_NPC, 0);
	}
	else
	{
		player->onEnterGSMap(msg->reason, msg->dstMapId, msg->posX, msg->posY,msg->sceneInstanceId,msg->enterSceneType);
		EntityOperationHelper::summonPet(player);	
	}
}

void GSMsgHandler::onSyncInfoToGameServerRequest(Message* message)
{
	MsgSyncInfoToGameServerRequest* msg = dynamic_cast<MsgSyncInfoToGameServerRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	if(player->isInGSMap())
	{
		return;
	}

	player->unSerializeCommonInfo(msg->commonInfoPlayer);
}

void GSMsgHandler::onNotifyGameServerExpAdd(Message* message)
{
	MsgNotifyGameServerExpAdd* msg = dynamic_cast<MsgNotifyGameServerExpAdd*>(message);
	if (msg == nullptr)
		return;

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
		return;

	EntityOperationHelper::addExp(*player, msg->count, msg->opcode, msg->opdata);
}

void GSMsgHandler::onNotifyGameServerItemAdd(Message* message)
{
	MsgNotifyGameServerItemAdd* msg = dynamic_cast<MsgNotifyGameServerItemAdd*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	OperationHelper::setOpCode(msg->opcode);

	std::map<int, int> prop;
	for (auto iter = msg->itemProps.begin(); iter != msg->itemProps.end(); iter++)
	{
		prop[iter->ctype] = iter->data;
	}
	int ret =  ItemOperationHelper::addItem(*player, msg->sid, msg->count, msg->bindType, msg->bag,prop ,msg->monster,true,msg->firstowner,msg->appraiser);
	Item* newitem = nullptr;
	if (ret == SUCCESS)
	{
		newitem = ItemOperationHelper::getItemAddedLast(*(player));
	}
	if (NULL != newitem)
	{
		bool isTuoguanItem = true;
		int iid = newitem->getID();
		//自动合成
		if (lua::call(lua::L, "Item.autoCompose", player, iid))
		{
			if (lua::getboolean(1))
			{
				isTuoguanItem = false;
			}
		}

		//自动回收
		if (lua::call(lua::L, "Item.autoRecovery", player, iid))
		{
			if (lua::getboolean(1))
			{
				isTuoguanItem = false;
			}
		}

		// 自动火祭
		if (lua::call(lua::L, "Item.autoHuoJi", player, iid))
		{
			if (lua::getboolean(1))
			{
				isTuoguanItem = false;
			}
		}
		if (isTuoguanItem)
		{
			lua::call(lua::L, "Tuoguan.checkItem", player, newitem->getStaticID());
		}
	}
}

void GSMsgHandler::onGetPlayerEquipInfoRequest(Message* message)
{
	MsgGetPlayerEquipInfoRequest* msg = dynamic_cast<MsgGetPlayerEquipInfoRequest*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *target = g_world_player_mgr.getPlayerByPlayerID(msg->targetPid);
	if (target == nullptr)
	{
		MsgDBLoadOtherPlayerInfo* req = new MsgDBLoadOtherPlayerInfo;
		req->pid = msg->targetPid;
		req->srcPid = msg->srcPid;
		req->srcServerid = msg->srcServerid;
		req->setSessionID(msg->getSessionID());
		g_app.postToNetService(req);
		return;
	}
	
	MsgNewGetPlayerEquipInfoResponse* res = new MsgNewGetPlayerEquipInfoResponse;
	res->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));  //战区服务器id
	res->setSourceSessionID(msg->srcServerid);  //目标游戏服id
	res->srcPid = msg->srcPid;
	res->targetPid = msg->targetPid;
	res->name = target->getName();
	res->level = target->getLevel();
	res->exp = EntityOperationHelper::getPlayerExp(*target);
	res->gender = target->getProp(ENTITY_PROP_GENDER);
	res->guild = EntityOperationHelper::getGuildName(*target);
	res->job = target->getClass();
	res->reborn = target->getProp(ENTITY_PROP_REBORN);
	res->lingwen = target->getProp(ENTITY_PROP_LINGWEN_SHOW_ID);
	res->guildpost = target->getProp(ENTITY_PROP_GUILD_POST);
	res->weapon = EntityOperationHelper::getDressByType(target, DRESS_TYPE_WUQI);
	res->cloth = EntityOperationHelper::getDressByType(target, DRESS_TYPE_YIFU);

	// 装备
	for (auto& it : EntityOperationHelper::getOtherPlayerEquip())
	{
		Item* pItem = ItemOperationHelper::getItemByPosition(*target, it);
		if (pItem)
		{
			CrossOtherPlayerEquip e;
			e.pos = it;
			e.sid = pItem->getStaticID();
			e.iid = pItem->getID();
			e.firstowner = pItem->getFirstOwnerName();
			for (int prop = ITEM_PROP_BEGIN; prop < ITEM_PROP_MAX; ++prop)
			{
				int data = pItem->getProp(prop);
				if (data)
				{
					CrossOtherItemProp p;
					p.idx = prop;
					p.data = data;
					e.props.push_back(p);
				}
			}
			res->equips.push_back(e);
		}
	}

	// 整形属性
	for (auto& it : EntityOperationHelper::getOtherPlayerIntProp())
	{
		int data = target->getProp(it);
		if (data)
		{
			CrossOtherEntityProp p;
			p.type = it;
			p.value = data;
			res->prop.push_back(p);
		}
	}

	// 字符属性
	for (auto& it : EntityOperationHelper::getOtherPlayerStrProp())
	{
		std::string data = target->getPropString(it);
		if (!data.empty())
		{
			CrossOtherEntityStringProp p;
			p.type = it;
			p.value = data;
			res->sprop.push_back(p);
		}
	}

	Combat* m_combat = target->getCombat();
	if (m_combat)
	{
		//技能
		const auto &skill_map = m_combat->getSkillMap();
		for (auto iter = skill_map.begin(); iter != skill_map.end(); ++iter)
		{
			CrossOtherPlayerSkill s;
			Skill *skill = iter->second;
			s.id = skill->getStaticID();
			s.level = skill->getProp(SKILL_PROP_LEVEL);
			res->skill.push_back(s);
		}
		// 属性
		for (short index = COMBAT_PROP_BEGIN+1; index < COMBAT_PROP_NORMAL_END; index++)
		{
			res->vcombat.push_back(m_combat->getProp(index)); 
		}
	}

	g_app.postToNetService(res);
}

void GSMsgHandler::onCrossMapDropRequest(Message* message)
{
	MsgCrossMapDropRequest* msg = dynamic_cast<MsgCrossMapDropRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	lua::call(lua::L, "Cross.dropPlayerThings", player, msg->mapId, msg->mapLineId, msg->posx, msg->posy, msg->killerName);
}

void GSMsgHandler::onReviveInCSMapResponse(Message* message)
{
	MsgReviveInCSMapResponse* msg = dynamic_cast<MsgReviveInCSMapResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	lua::call(lua::L, "Entity.checkAndDelRose", player, msg->subType);
}

void GSMsgHandler::onConveyToSceneRequest(Message* message)
{
	MsgConveyToSceneRequest* msg = dynamic_cast<MsgConveyToSceneRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	SceneOperationHelper::enterScene(g_scene_mgr, *player, msg->mapId, msg->posX, msg->posY);
}

void GSMsgHandler::onSyncEventDataRequest(Message* message)
{
	if (g_config.isCrossServer())
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
	if (edata == NULL)
	{
		return;
	}

	if(edata->getTimeIndex() != msg->data.timeIndex)
	{
		int resetMode = EntityOperationHelper::getEventResetMode(msg->data.id);
		if (resetMode >= 0 && resetMode <= 7)
		{
			//低3bit从高到低分别表示重置时是否保留(不重置)X, Y, Z值
			//	+---+------+------+------+
			//	|   |   X  |   Y  |   Z  |
			//	+---+------+------+------+
			//	| 0 | 重置 | 重置 | 重置 |
			//	| 1 | 重置 | 重置 | 保留 |
			//	| 2 | 重置 | 保留 | 重置 |
			//	| 3 | 重置 | 保留 | 保留 |
			//	| 4 | 保留 | 重置 | 重置 |
			//	| 5 | 保留 | 重置 | 保留 |
			//	| 6 | 保留 | 保留 | 重置 |
			//	| 7 | 保留 | 保留 | 保留 |
			//	+---+------+------+------+
			if ((resetMode & 0x4) == 0)
			{
				msg->data.datax = 0;
			}
			if ((resetMode & 0x2) == 0)
			{
				msg->data.datay = 0;
			}
			if ((resetMode & 0x1) == 0)
			{
				msg->data.dataz = 0;
			}
		}
		else
		{
			return;
		}
	}

	edata->setDataX(edata->getDataX() + msg->data.datax);
	edata->setDataY(edata->getDataY() + msg->data.datay);
	edata->setDataZ(edata->getDataZ() + msg->data.dataz);

	bool dataChanged = msg->data.datax != 0 || msg->data.datay != 0 || msg->data.dataz != 0;
	if(edata->getTimeIndex() != msg->data.timeIndex && dataChanged)
	{
		GSHelper::syncEventDataToCS(player, msg->data.id);
	}

	if(dataChanged)
	{
		MsgDBUpdPlayerEvent *dbmsg = new MsgDBUpdPlayerEvent;
		dbmsg->pid = player->getGlobalID();
		dbmsg->eid = edata->getID();
		dbmsg->tindex = edata->getTimeIndex();
		dbmsg->datax = edata->getDataX();
		dbmsg->datay = edata->getDataY();
		dbmsg->dataz = edata->getDataZ();
		player->sendMessageToDB(dbmsg);

		edata->cacheLastSaveData();
	}
}

void GSMsgHandler::onSyncCSPosToGSNotify(Message* message)
{
	MsgSyncCSPosToGSNotify* msg = dynamic_cast<MsgSyncCSPosToGSNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->playerId);
	if (player == nullptr)
	{
		return;
	}

	if (player->getProp(ENTITY_PROP_CROSS_MAP_ID) != msg->mapId)
	{
		lua::call(lua::L, "Cross.onPlayerEnterCrossMap", player, msg->mapId);
	}

	player->setProp(ENTITY_PROP_CROSS_MAP_ID, msg->mapId);
	player->setProp(ENTITY_PROP_CROSS_MAP_LINE_ID, msg->mapLineId);
	player->setProp(ENTITY_PROP_CROSS_MAP_POSX, msg->posX);
	player->setProp(ENTITY_PROP_CROSS_MAP_POSY, msg->posY);
}

void GSMsgHandler::onSyncBossInfoToGSNotify(Message* message)
{
	MsgSyncBossInfoToGSNotify* msg = dynamic_cast<MsgSyncBossInfoToGSNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	if(g_world.getID() != msg->serverId)
	{
		return;
	}

	if(msg->list.size() == 0)
	{
		return;
	}

	Scene *scene = g_scene_mgr.getSceneByStaticID(msg->sceneId, 1);
	if(scene == nullptr)
	{
		return;
	}

	for(auto iter = msg->list.begin(); iter != msg->list.end(); iter++)
	{
		scene->updCrossBossInfo(iter->index, iter->bossId, iter->freshTime, iter->alive == 1 ? true : false);
	}

	//遍历所有玩家
	g_world_player_mgr.for_each([&](EntityPlayer* player){
		if(player != nullptr && player->getProp(ENTITY_PROP_OFFLINE) != 1)
		{
			if(msg->list.size() > 1)
			{
				scene->syncSceneBossInfoToPlayer(player);
			}
			else
			{
				scene->syncSceneBossInfoToPlayer(player, msg->list[0].index);
				if (msg->list[0].alive)
				{
					scene->sendBossRefreshWarnToPlayer(player, msg->list[0].bossId);
				}
			}
		}
	});
}

void GSMsgHandler::onAddGeneInGameServerRequest(Message* message)
{
	MsgAddGeneInGameServerRequest* msg = dynamic_cast<MsgAddGeneInGameServerRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr || player->getProp(ENTITY_PROP_OFFLINE) == 1)
	{
		return;
	}

	EntityOperationHelper::addGene(*player, msg->geneId, msg->geneType, msg->geneGroup, msg->geneDuration, msg->geneInherit == 1, msg->geneDatax, msg->geneDatay, msg->geneDataz,0,0,msg->geneDatau);
}

void GSMsgHandler::onRmvGeneFromGameServerRequest(Message* message)
{
	MsgRmvGeneFromGameServerRequest* msg = dynamic_cast<MsgRmvGeneFromGameServerRequest*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr || player->getProp(ENTITY_PROP_OFFLINE) == 1)
	{
		return;
	}

	player->removeGene(msg->geneId);
}

void GSMsgHandler::onGetQualifiedPlayerListNearbyResponse(Message* message)
{
	MsgGetQualifiedPlayerListNearbyResponse* msg = dynamic_cast<MsgGetQualifiedPlayerListNearbyResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	switch (msg->condition)
	{
	case PlayerNearCondition::CONDITION_NEAR_TEAM:
		{
			TeamMsgHandler *teamMsgmodule = (TeamMsgHandler *)g_app.GetLogicService()->getModule("TeamModule");
			if (teamMsgmodule != nullptr)
			{
				teamMsgmodule->onGetNearbyTeam(player, msg->list);
			}
		}
		break;
	default:
		break;
	}
}

void GSMsgHandler::onSyncWarZoneDropInfo(Message* message)
{
	MsgSyncWarZoneDropInfo* msg = dynamic_cast<MsgSyncWarZoneDropInfo*>(message);
	if (msg == nullptr)
	{
		return;
	}

	if(msg->reload == 1)
	{
		g_drop_broadcast_mgr.clear();

		for(auto iter = msg->topDropInfoList.rbegin(); iter != msg->topDropInfoList.rend(); iter++)
		{
			g_drop_broadcast_mgr.cacheDropInfoRecordInGS(*((DropInfo*)(&(*iter))), true);
		}

		for(auto iter = msg->dropInfoList.rbegin(); iter != msg->dropInfoList.rend(); iter++)
		{
			g_drop_broadcast_mgr.cacheDropInfoRecordInGS(*((DropInfo*)(&(*iter))), false);
		}

		g_drop_broadcast_mgr.syncReloadDropRecordToPlayer();
	}
	else
	{
		for(auto iter = msg->topDropInfoList.begin(); iter != msg->topDropInfoList.end(); iter++)
		{
			g_drop_broadcast_mgr.cacheDropInfoRecordInGS(*((DropInfo*)(&(*iter))), true);
		}

		for(auto iter = msg->dropInfoList.begin(); iter != msg->dropInfoList.end(); iter++)
		{
			g_drop_broadcast_mgr.cacheDropInfoRecordInGS(*((DropInfo*)(&(*iter))), false);
		}

		MsgSyncWarZoneDropInfoToPlayer *notify = new MsgSyncWarZoneDropInfoToPlayer;
		notify->reload = 0;

		for(auto iter = msg->topDropInfoList.begin(); iter != msg->topDropInfoList.end(); iter++)
		{
			notify->topDropInfoList.push_back(*((WarZoneDropDetail*)(&(*iter))));
		}

		for(auto iter = msg->dropInfoList.begin(); iter != msg->dropInfoList.end(); iter++)
		{
			notify->dropInfoList.push_back(*((WarZoneDropDetail*)(&(*iter))));
		}

		g_world.sendMessage(notify);
	}
}

void GSMsgHandler::onCrossAuctionItemAddNotify(Message* message)
{
	MsgCrossAuctionItemAddNotify* msg = dynamic_cast<MsgCrossAuctionItemAddNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_acution_mgr.cache_cross_auction(msg->reload, msg->auctionItemList);
}

void GSMsgHandler::onCrossAuctionItemRmvNotify(Message* message)
{
	MsgCrossAuctionItemRmvNotify* msg = dynamic_cast<MsgCrossAuctionItemRmvNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_acution_mgr.rmv_cross_auction_cache(msg->auctionItemList);
}

void GSMsgHandler::onCrossAuctionItemUpdNotify(Message* message)
{
	MsgCrossAuctionItemUpdNotify* msg = dynamic_cast<MsgCrossAuctionItemUpdNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_acution_mgr.upd_cross_auction_cache(&(msg->auctionItem));
}

void GSMsgHandler::onCheckBuyCrossAuctionItemRsp(Message* message)
{
	MsgCheckBuyCrossAuctionItemResponse* msg = dynamic_cast<MsgCheckBuyCrossAuctionItemResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyer_pid);
	if (player == nullptr)
	{
		return;
	}

	int ret = msg->errcode;
	if(ret == SUCCESS)
	{
		ret = GSHelper::buyCrossAuctionItem(player, msg->aid, msg->type);
	}

	if(ret != SUCCESS)
	{
		MsgBuyAcutionResponse *response = new MsgBuyAcutionResponse;
		response->errcode = msg->errcode;
		response->ctype = msg->type;
		player->sendMessage(response);
	}
}

void GSMsgHandler::onBuyCrossAuctionItemRsp(Message* message)
{
	MsgBuyCrossAuctionItemResponse* msg = dynamic_cast<MsgBuyCrossAuctionItemResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	if(msg->errcode != SUCCESS)
	{
		lua::call(lua::L, "Consignment.sendFailedAuctionMail", msg->buyer_pid, msg->sid, msg->money_type, msg->cost_money);
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyer_pid);
	if (player != nullptr)
	{
		MsgBuyAcutionResponse *response = new MsgBuyAcutionResponse;
		response->errcode = msg->errcode;
		response->ctype = msg->type;
		player->sendMessage(response);
	}
}

void GSMsgHandler::onCrossAuctionRecordNotify(Message* message)
{
	MsgCrossAuctionRecordNotify* msg = dynamic_cast<MsgCrossAuctionRecordNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_consignment_store.addConsignmentRecord(msg->other_pid, msg->other_name, msg->buyer_pid,msg->buyer_name ,
		msg->sid, msg->count,msg->fixed_price,msg->ctype,msg->things_type);

	//交易记录
	MsgDBAddConsignmentRecording *dbmsgrecord = new MsgDBAddConsignmentRecording();
	dbmsgrecord->pid = msg->other_pid;
	dbmsgrecord->sellername = msg->other_name;
	dbmsgrecord->buyerpid = msg->buyer_pid;
	dbmsgrecord->buyername = msg->buyer_name;
	dbmsgrecord->sid = msg->sid;
	dbmsgrecord->count = msg->count;
	dbmsgrecord->price = msg->fixed_price;
	dbmsgrecord->pricetype = msg->things_type;
	dbmsgrecord->ctype = msg->ctype;
	g_app.postToNetService(dbmsgrecord);
}

void GSMsgHandler::onCrossConsignmentAddNotify(Message* message)
{
	MsgCrossConsignmentAddNotify* msg = dynamic_cast<MsgCrossConsignmentAddNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_consignment_store.cacheConsignment(&(msg->item));
}

void GSMsgHandler::onCrossConsignmentRmvNotify(Message* message)
{
	MsgCrossConsignmentRmvNotify* msg = dynamic_cast<MsgCrossConsignmentRmvNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_consignment_store.deleteConsignment(msg->sellerPid, msg->cid);
}

void GSMsgHandler::onCrossConsignmentUpdNotify(Message* message)
{
	MsgCrossConsignmentUpdNotify* msg = dynamic_cast<MsgCrossConsignmentUpdNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_consignment_store.updateConsignmentCount(msg->sellerPid, msg->cid, msg->newCount);
}

void GSMsgHandler::onAddConsignmentToCrossRsp(Message* message)
{
	MsgAddConsignmentToCrossResponse* msg = dynamic_cast<MsgAddConsignmentToCrossResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	if(msg->errcode != SUCCESS)
	{
		//通过邮件返还物品
		lua::call(lua::L, "Consignment.onConsignmentFail",  msg->pid, msg->count, msg->sid);
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	MsgAddConsignmentResponse *response = new MsgAddConsignmentResponse;
	response->errcode = msg->errcode;
	player->sendMessage(response);
}

void GSMsgHandler::onCheckBuyCrossConsignmentRsp(Message* message)
{
	MsgCheckBuyCrossConsignmentResponse* msg = dynamic_cast<MsgCheckBuyCrossConsignmentResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyerPid);
	if (player == nullptr)
	{
		return;
	}

	MsgBuyConsignmentResponse *response = new MsgBuyConsignmentResponse;
	response->errcode = msg->errcode;

	if(msg->errcode == SUCCESS)
	{
		response->errcode = ConsignmentHelper::checkCanBuyConsignment(player, msg->sellerPid, msg->cid, msg->count);
		if(response->errcode ==  SUCCESS)
		{
			delete response;
			ConsignmentHelper::buyConsignment(player, msg->sellerPid, msg->cid, msg->count);
			return;
		}
	}

	player->sendMessage(response);
}

void GSMsgHandler::onSendSellerRewardRsp(Message* message)
{
	MsgSendSellerRewardResponse* msg = dynamic_cast<MsgSendSellerRewardResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyerPid);
	if (player == nullptr)
	{
		return;
	}

	MsgBuyConsignmentResponse *response = new MsgBuyConsignmentResponse;
	response->errcode = msg->errcode;
	player->sendMessage(response);
}

void GSMsgHandler::onRmvCrossConsignmentRsp(Message* message)
{
	MsgRmvCrossConsignmentResponse* msg = dynamic_cast<MsgRmvCrossConsignmentResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	Consignment* consignment = g_consignment_store.getConsignment(msg->sellerPid, msg->cid);
	if(consignment == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->sellerPid);
	if (player == nullptr)
	{
		//新版中只有主动下线 
		if(msg->errcode == SUCCESS) 
		{
			return;
			/*lua::call(lua::L, "Consignment.onReturnConsignment",  consignment->sellerPid, consignment->count, consignment->sid);*/
		}
	}
	else
	{
		if(msg->errcode == SUCCESS)
		{
			OperationHelper::setOpCode(OP_CONSIGNMENT);
			std::map<int,int> itemProps;
			for (int i = 0;i < consignment->props.size(); i++)
			{
				ConsignmentItemProp prop = consignment->props[i];
				itemProps[prop.idx] = prop.data;
			}

			ItemOperationHelper::addConsignmentItem(*player, consignment->sid, consignment->count,itemProps,true,consignment->firstOwner,consignment->appraiser);
			//ItemOperationHelper::addItem(*player, consignment->sid, consignment->count, ITEM_BIND_STATE_UNBOUND, BAG_TYPE_PLAYER);
		}
		
		MsgDeleteConsignmentResponse *response = new MsgDeleteConsignmentResponse;
		response->cid = msg->cid;
		response->errcode = msg->errcode;
		player->sendMessage(response);
	}

	MsgDBDeleteConsignment *dbmsg = new MsgDBDeleteConsignment;
	dbmsg->pid = msg->sellerPid;
	dbmsg->cid = msg->cid;
	g_app.postToNetService(dbmsg);
}

void GSMsgHandler::onSyncAllCrossConsignmentNotify(Message* message)
{
	MsgSyncAllCrossConsignmentNotify* msg = dynamic_cast<MsgSyncAllCrossConsignmentNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_consignment_store.refreshAllCrossConsignments(msg->list);
}

void GSMsgHandler::onPlayerCSActionNotify(Message* message)
{
	MsgPlayerCSActionNotify* msg = dynamic_cast<MsgPlayerCSActionNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}


	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);

	std::map<int, int> intParamsList;
	for(auto iter = msg->intParams.begin(); iter != msg->intParams.end(); iter++)
	{
		intParamsList[iter->ctype] = iter->data;
	}
	std::map<int, std::string> strParamsList;
	for(auto iter = msg->strParams.begin(); iter != msg->strParams.end(); iter++)
	{
		strParamsList[iter->ctype] = iter->data;
	}

	GSHelper::playerCSActionTrigger(player, msg->crossActionType, intParamsList, strParamsList);
}

//跨服聊天相关
void GSMsgHandler::onCrossChatNotify(Message * message)
{
	MsgSyncCrossChatNotify * msg = dynamic_cast<MsgSyncCrossChatNotify *>(message);
	if (msg == nullptr)
	{
		return;
	}
	//聊天内容 
	MsgChatNotify *notify = new MsgChatNotify; 
	notify->chatType = msg->chatType;
	notify->pid = msg->pid;
	notify->playerName = msg->playerName;
	notify->gender =  msg->gender;
	notify->vipLevel =  msg->vipLevel;
	notify->level =  msg->level;
	notify->job =  msg->job;
	notify->position =  msg->position;
	notify->redID = 0;
	notify->serverid = msg->serverid;
	notify->guildName =  msg->guildName;
	notify->chatText = msg->chatText;

	for (auto it : msg->props)
	{
		chatPlayerProp* pCp = (chatPlayerProp*)&it;
		notify->props.emplace_back(*pCp);
	}
	g_app.GetLogicService()->broadcast(notify);

	//数据存储
	stcChatKeepInfo stcMsg ; 
	stcMsg.chatType = msg->chatType;
	stcMsg.pid = msg->pid;
	stcMsg.playerName = msg->playerName;

	stcMsg.gender = msg->gender;
	stcMsg.vipLevel = msg->vipLevel;
	stcMsg.level = msg->level;
	stcMsg.job = msg->job;
	stcMsg.position = msg->position;
	stcMsg.redID = 0;
	stcMsg.serverid = msg->serverid;
	stcMsg.guildName = msg->guildName;
	stcMsg.guildName = msg->guildName;
	stcMsg.chatText = msg->chatText;
	stcMsg.keepTime = get_time();
	g_msg_keep_mgr.AddMsgKeep(ENTITY_PROP_CHAT_CODE,CHAT_TYPE_WARZONE,stcMsg);
}

//跨服查看角色装备
void GSMsgHandler::onGetPlayerEquipInfoResponse(Message * message)
{
	MsgGetPlayerEquipInfoResponse* msg = dynamic_cast<MsgGetPlayerEquipInfoResponse*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->srcPid);
	if (player == NULL)
	{
		return;
	}

	MsgCheckEquipResponse* res = new MsgCheckEquipResponse;

// 	EntityPlayer* target = g_world_player_mgr.getPlayerByPlayerID(msg->targetPid);
// 	if (NULL == target)
// 	{
// 		res->errcode = ERROR_PLAYER_IS_OFFLINE;
// 		player->sendMessage(res);
// 		return;
// 	}

	res->pid = msg->targetPid;
	res->name = msg->name;
	res->gender = msg->gender;
	res->clazz = msg->clazz;
	res->level = msg->level;
	res->zhanli = msg->zhanli;
	res->reborn = msg->reborn;
	// 	res->cloth = msg->cloth;
	// 	res->weapon = msg->weapon;
	// 	res->wings = msg->wings;
	res->guild = msg->guild;
	res->godLevel = msg->godLevel;
	res->enhanceExLevel = msg->enhanceExLevel;
	res->soulExLevel = msg->soulExLevel;
	res->moshiLevel = msg->moshiLevel;
	res->honor = 0;//target->getProp(ENTITY_PROP_HONOR);
	res->pkvalue = msg->pkvalue;
	res->rebornsoul = msg->rebornsoul;
	res->stonepoint = msg->stonepoint;
	res->xiliansuit = msg->xiliansuit;
	res->heji = msg->heji;
	res->exMaxLvl = msg->exMaxLvl;
	res->hide_moguan = msg->hide_moguan;
	res->dress_cloth = msg->dress_cloth;
	res->cloth = msg->cloth;
	res->weapon =  msg->weapon;
	res->wings =  msg->wings;
	
	// 战斗属性
	res->vcombat = msg->vcombat;

	// 装备物品组装
	for(auto iter = msg->equips.begin(); iter != msg->equips.end(); iter++)
	{
		OtherEquipInfo* equip = (OtherEquipInfo*)(&(*iter));
		if(equip != nullptr)
		{
			res->equips.push_back(*equip);
		}
	}

	// 各种属性
	for(auto iter = msg->prop.begin(); iter != msg->prop.end(); iter++)
	{
		OtherEntityProp* equip = (OtherEntityProp*)(&(*iter));
		if(equip != nullptr)
		{
			res->prop.push_back(*equip);
		}
	}
	// 各种属性
	for(auto iter = msg->sprop.begin(); iter != msg->sprop.end(); iter++)
	{
		OtherEntityStringProp* sprop = (OtherEntityStringProp*)(&(*iter));
		if(sprop != nullptr)
		{
			res->sprop.push_back(*sprop);
		}
	}
	res->errcode = SUCCESS;
	player->sendMessage(res);

}

void GSMsgHandler::onNewGetPlayerEquipInfoResponse(Message* message)
{
	MsgNewGetPlayerEquipInfoResponse* msg = dynamic_cast<MsgNewGetPlayerEquipInfoResponse*>(message);
	if (msg == nullptr)
	{
		LOG_ERROR("invalid message MsgNewGetPlayerEquipInfoResponse");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->srcPid);
	if (player == nullptr)
	{
		return;
	}

	MsgNewCheckEquipResponse* res = new MsgNewCheckEquipResponse;
	res->pid = msg->targetPid;
	res->name = msg->name;
	res->level = msg->level;
	res->exp = msg->exp;
	res->gender = msg->gender;
	res->guild = msg->guild;
	res->job = msg->job;
	res->reborn = msg->reborn;
	res->lingwen = msg->lingwen;
	res->guildpost = msg->guildpost;
	res->weapon = msg->weapon;
	res->cloth = msg->cloth;	

	// 装备
	for (auto& it : msg->equips)
	{
		OtherPlayerEquip* e = (OtherPlayerEquip*)(&it);
		if (e)
		{
			res->equips.push_back(*e);
		}
	}

	// 整形属性
	for (auto& it : msg->prop)
	{
		OtherEntityProp* p = (OtherEntityProp*)(&it);
		if (p)
		{
			res->prop.push_back(*p);
		}
	}

	// 字符属性
	for (auto& it : msg->sprop)
	{
		OtherEntityStringProp* p = (OtherEntityStringProp*)(&it);
		if (p)
		{
			res->sprop.push_back(*p);
		}
	}

	// 技能
	for (auto& it : msg->skill)
	{
		OtherPlayerSkill* s = (OtherPlayerSkill*)(&it);
		if (s)
		{
			res->skill.push_back(*s);
		}
	}

	for (auto& it : msg->vcombat)
	{
		res->vcombat.push_back(it);
	}

	player->sendMessage(res);
}

void GSMsgHandler::onGetBossCntInCrossMapNotify(Message* message)
{
	MsgGetBossCntInCrossMapNotify* msg = dynamic_cast<MsgGetBossCntInCrossMapNotify*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgGetBossCntInCrossMapNotify");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (!player)
	{
		return;
	}

	if (msg->boss_cnts.empty())
	{
		return;
	}

	MsgGetBossCntInMapNotify* notify = new MsgGetBossCntInMapNotify;
	for (auto& it : msg->boss_cnts)
	{
		notify->boss_cnts.emplace_back(*((MapBossCount*)(&it)));
	}
	notify->targetName = msg->targetName;
	player->sendMessage(notify);
}

void GSMsgHandler::onCrossGetPlayerSerializeInfoC2G(Message* message)
{
	MsgCrossGetPlayerSerializeInfoC2G* msg = dynamic_cast<MsgCrossGetPlayerSerializeInfoC2G*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	if (msg->errcode==SUCCESS)
	{
		lua::call(lua::L, "Entity.isRobot", msg->enemy_pid);
		bool b = lua::getboolean(1);
		if (b)
		{
			if (msg->action == CSZT_FIGHT)
			{
				EntityOperationHelper::doStartRobotFightCszt(msg->pid,msg->enemy_pid,msg->scene_static_id);
			}
			else if (msg->action == CSZT_SHOW)
			{
				EntityOperationHelper::doShowRobotCszt(msg->pid,msg->enemy_pid);
			}
		}
		else
		{
			if (msg->action == CSZT_FIGHT)
			{
				EntityOperationHelper::doStartFightCszt(msg->pid,msg->enemy_pid,msg->scene_static_id,msg->json);
			}
			else if (msg->action == CSZT_SHOW)
			{
				EntityOperationHelper::doShowCszt(msg->pid,msg->enemy_pid,msg->json);
			}
		}
		return;
	}
	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player)
	{
		int lan_id = 0;
		switch (msg->errcode)
		{
		case ERROR_NO_PLAYER_INFO:
			lan_id = 30660;
			break;
		case ERROR_ROBBED_ING:
			lan_id = 30656;
			break;
		case ERROR_NO_CHANLLENG_TIME:
			lan_id = 30658;
			break;
		case ERROR_CANT_FIGHT_TOO_HEIGH:
			lan_id = 30674;
			break;
		case ERROR_NOT_START:
			lan_id = 4245;
			break;
		case ERROR_SELF_BE_ROBBED_ING:
			lan_id = 31165;
			break;
		}
		if (lan_id>0)
		{
			EntityOperationHelper::sendShowPrompt(*player,1,lan_id,std::vector<std::string>());
		}
	}
}

void GSMsgHandler::onCrossPurchaseAddNotify(Message* message)
{
	MsgCrossPurchaseAddNotify* msg = dynamic_cast<MsgCrossPurchaseAddNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_purchase_mgr.cachePurchase(&(msg->crossPurchase));
}

void GSMsgHandler::onCrossPurchaseRmvNotify(Message* message)
{
	MsgCrossPurchaseRmvNotify* msg = dynamic_cast<MsgCrossPurchaseRmvNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_purchase_mgr.deletePurchase(msg->buyerPid, msg->purchaseId);
}

void GSMsgHandler::onCrossPurchaseUpdNotify(Message* message)
{
	MsgCrossPurchaseUpdNotify* msg = dynamic_cast<MsgCrossPurchaseUpdNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_purchase_mgr.updatePurchaseCount(msg->buyerPid, msg->purchaseId, msg->newCount);
}

void GSMsgHandler::onAddPurchaseToCrossRsp(Message* message)
{
	MsgAddPurchaseToCrossResponse* msg = dynamic_cast<MsgAddPurchaseToCrossResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	if(msg->errcode != SUCCESS)
	{
		int moneyType = ITEM_LINGFU;
		if(lua::call(lua::L, "Consignment.getPurchaseItemMoneyType", msg->sid))
		{
			moneyType = lua::getinteger(1);
		}

		lua::call(lua::L, "Consignment.onPurchaseFail", msg->buyerPid, msg->sid, moneyType, msg->price * msg->count);
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyerPid);
	if (player == nullptr)
	{
		return;
	}

	MsgPostPurchaseResponse *response = new MsgPostPurchaseResponse;
	response->errcode = msg->errcode;
	player->sendMessage(response);
}

void GSMsgHandler::onTrySellCrossPurchaseRsp(Message* message)
{
	MsgTrySellCrossPurchaseResponse* msg = dynamic_cast<MsgTrySellCrossPurchaseResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->sellerPid);
	if (player == nullptr)
	{
		return;
	}

	MsgSellPurchaseResponse *response = new MsgSellPurchaseResponse;
	response->errcode = msg->errcode;

	if(msg->errcode == SUCCESS)
	{
		response->errcode = PurchaseHelper::checkCanSellPurchaseItem(player, msg->buyerPid, msg->purchaseId, msg->sellCounts);
		if(response->errcode == SUCCESS)
		{
			PurchaseHelper::sellPurchaseItem(player, msg->buyerPid, msg->purchaseId, msg->sellCounts);
			delete response;
			return;
		}
	}

	player->sendMessage(response);
}

void GSMsgHandler::onSendBuyerPurchaseItemRsp(Message* message)
{
	MsgSendBuyerPurchaseItemResponse* msg = dynamic_cast<MsgSendBuyerPurchaseItemResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->sellerPid);
	if (player == nullptr)
	{
		return;
	}

	MsgSellPurchaseResponse *response = new MsgSellPurchaseResponse;
	response->errcode = msg->errcode;
	player->sendMessage(response);
}

void GSMsgHandler::onRmvCrossPurchaseRsp(Message* message)
{
	MsgRmvCrossPurchaseResponse* msg = dynamic_cast<MsgRmvCrossPurchaseResponse*>(message);

	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->buyerPid);
	if (player != nullptr)
	{
		MsgCancelPurchaseResponse *response = new MsgCancelPurchaseResponse;
		response->errcode = msg->errcode;
		player->sendMessage(response);
	}
}

void GSMsgHandler::onSyncAllCrossPurchaseNotify(Message* message)
{
	MsgSyncAllCrossPurchaseNotify* msg = dynamic_cast<MsgSyncAllCrossPurchaseNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	g_purchase_mgr.refreshAllCrossPurchases(msg->list);
}

void GSMsgHandler::onSyncSkillExpAddToGameServer(Message* message)
{
	//LOG_ERROR(">>>>>>>>>>>>>>>>>>>>99999999999999999999999999999");
	MsgSyncSkillExpAddToGameServer* msg = dynamic_cast<MsgSyncSkillExpAddToGameServer*>(message);
	if (msg == nullptr)
	{
		return;
	}
	if(g_config.isCrossServer())
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (!player)
	{
		return;
	}
	Combat* cbt = player->getCombat();
	if(!cbt)
	{
		return;
	}

	SkillManager *skillmanager = cbt->getSkillManager();
	if(!skillmanager)
	{
		return;
	}
	for (auto it = msg->skillList.begin();it !=msg->skillList.end();++it)
	{
		Skill *skill = cbt->getSkill(it->sid);
		if (skill)
		{
			int cur_exp = skill->getProp(SKILL_PROP_EXP);
			cur_exp += it->addexp;
			skill->setProp(SKILL_PROP_EXP,cur_exp);
			skillmanager->addSaveSkill(it->sid);
		}
	}

}

void GSMsgHandler::onRemoveChatCrossNotify(Message* message)
{
	MsgRemoveChatCrossNotify* msg = dynamic_cast<MsgRemoveChatCrossNotify*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityOperationHelper::removeChat(msg->pid);
}

void GSMsgHandler::onAddHYDScore(Message *message)
{
	MsgAddHYDScoreNotify* msg = dynamic_cast<MsgAddHYDScoreNotify*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (!player)
	{
		return;
	}
	lua::call(lua::L, "Entity.addHYDScore",player,msg->eventId);
}

void GSMsgHandler::onSendSWZDZAward(Message *message)
{
	MsgSendSWZDZAwardNotify *msg = dynamic_cast<MsgSendSWZDZAwardNotify*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	int guildId = msg->GuildID;
	lua::call(lua::L, "Guild.sendSWZDZAward", guildId);
}

void GSMsgHandler::onSendSWYAward(Message *message)
{
	MsgSendSWYAwardNotify *msg = dynamic_cast<MsgSendSWYAwardNotify*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	if (msg->serverid == g_world.getID())
	{
		lua::call(lua::L, "Guild.sendGuildActivitySWYRewards", msg->pid,msg->rank,msg->rankType,msg->gid);
	}
}

void GSMsgHandler::onSendGuildBattleAward(Message *message)
{
	MsgSendGuildBattleAwardNotify *msg = dynamic_cast<MsgSendGuildBattleAwardNotify*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	if (msg->serverid == g_world.getID())
	{
		lua::call(lua::L, "GuildBattle.sendRankRewards", msg->pid, msg->rankType, msg->rank, true);
	}
}

void GSMsgHandler::onGSBroadcastAllGSResponse(Message *message)
{
	MsgGSBroadcastAllGSResponse *msg = dynamic_cast<MsgGSBroadcastAllGSResponse*>(message);
	if(msg == nullptr)
	{
		return;
	}

	if(g_config.isCrossServer())
	{
		return;
	}
	g_world.syncWorldFloatNotice(msg->basestring,msg->showflag,msg->TouchID);
}

void GSMsgHandler::onSyncWordDataToGameServerRequest(Message* message)
{
	MsgSyncWordDataToGSNotify* msg = dynamic_cast<MsgSyncWordDataToGSNotify*>(message);

	if (msg == nullptr)
	{
		return;
	}

	if(g_config.isCrossServer())
	{
		return;
	}

	WorldData *world_data = g_world.getWorldData(msg->wprop);
	if (world_data)
	{
		world_data->setDataX(msg->datax); //神器当前状态
		world_data->setDataY(msg->datay); //玩家pid
		world_data->setDataZ(msg->dataz); //玩家服务器id
		world_data->setDataS(msg->datas); //玩家名称
	}
	g_world.syncWorldData(msg->wprop);
}

void GSMsgHandler::onGetPlayerBaseInfoFromGSRequest(Message *message)
{
	MsgGetPlayerBaseInfoFromGSRequest *msg = dynamic_cast<MsgGetPlayerBaseInfoFromGSRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}
	if(msg->pid <= 0)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		PlayerBaseInfo * info = g_world.getOfflinePlayerBaseInfo(msg->pid);
		if(info != nullptr)
		{
			MsgGetPlayerBaseInfoFromGSResponse *res = new MsgGetPlayerBaseInfoFromGSResponse();
			if(res == nullptr)
			{
				return;
			}
			res->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
			res->srcPid = msg->srcPid;
			res->srcServerId = msg->srcServerId;

			res->pid = msg->pid;
			res->gender = info->gender;
			res->job = info->job;
			res->weapon = info->weapon;
			res->dressWeapon = info->dressWeapon;
			res->cloth = info->cloth;
			res->dressCloth = info->dressCloth;
			res->hat = info->hat;
			res->shield = info->shield;
			res->guardLevel = info->guardLevel;
			res->hunhuan = info->hunhuan;
			res->jingling = info->jingling;
			g_app.postToNetService(res);
		}
		else
		{
			MsgLoadPlayerBaseInfo *db = new MsgLoadPlayerBaseInfo();
			if(db == nullptr)
			{
				return;
			}
			db->pid = msg->pid;
			db->srcPid = msg->srcPid;
			db->srcServerid = msg->srcServerId;
			g_app.postToNetService(db);
		}
	}
	else
	{
		MsgGetPlayerBaseInfoFromGSResponse *res = new MsgGetPlayerBaseInfoFromGSResponse();
		if(res == nullptr)
		{
			return;
		}
		res->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		res->srcPid = msg->srcPid;
		res->srcServerId = msg->srcServerId;

		res->pid = msg->pid;
		res->gender = player->getProp(ENTITY_PROP_GENDER);
		res->job = player->getClass();
		res->weapon = player->getProp(ENTITY_PROP_PLAYER_WEAPON);
		res->dressWeapon = player->getProp(ENTITY_PROP_DRESS_WUQI);
		res->cloth = player->getProp(ENTITY_PROP_PLAYER_CLOTH);
		res->dressCloth = player->getProp(ENTITY_PROP_DRESS_YIFU);
		res->hat = player->getProp(ENTITY_PROP_PLAYER_HAT);
		res->shield = player->getProp(ENTITY_PROP_PLAYER_SHIELD);
		res->guardLevel = player->getProp(ENTITY_PROP_GUARD_LEVEL);
		res->hunhuan = player->getProp(ENTITY_PROP_DRESS_HUNHUAN);
		res->jingling = player->getProp(ENTITY_PROP_DRESS_JINGLING);
		g_app.postToNetService(res);
		return;
	}
}

void GSMsgHandler::onGetPlayerBaseInfoFromCSResponse(Message *message)
{
	MsgGetPlayerBaseInfoFromCSResponse *msg = dynamic_cast<MsgGetPlayerBaseInfoFromCSResponse*>(message);
	if(msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->srcPid);
	if(player == nullptr)
	{
		return;
	}

	MsgGetPlayerBaseInfoResponse *res = new MsgGetPlayerBaseInfoResponse();
	if(res == nullptr)
	{
		return;
	}
	res->pid = msg->pid;
	res->gender = msg->gender;
	res->job = msg->job;
	res->weapon = msg->weapon;
	res->dress_weapon = msg->dressWeapon;
	res->cloth = msg->cloth;
	res->dress_cloth = msg->dressCloth;
	res->hat = msg->hat;
	res->shield = msg->shield;
	res->guard_level = msg->guardLevel;
	res->hunhuan = msg->hunhuan;
	res->jingling = msg->jingling;
	player->sendMessage(res);
}

void GSMsgHandler::onLoadCSRank(Message *message)
{
	lua::call(lua::L, "Rank.onInitCSRank");
}

//原服收到跨服排行榜数据
void GSMsgHandler::onReceiveCSRankList(Message *message)
{
	MsgSendCSRankToGS *msg = dynamic_cast<MsgSendCSRankToGS*>(message);
	if(msg == nullptr)
	{
		return;
	}

	LOG_INFO("++++++/////onReceiveCSRankList:%d", msg->type);
	
	g_rank_mgr.initRankData(msg->type, msg->list);
}

void GSMsgHandler::onSendPlayerGreyNameToGS(Message* message)
{
	MsgSendPlayerGreyNameToGS* msg = dynamic_cast<MsgSendPlayerGreyNameToGS*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	lua::call(lua::L, "Entity.setGreyName", player);
}

void GSMsgHandler::onSendPlayerKillWhiteRoleToGS(Message* message)
{
	MsgSendPlayerKillWhiteRoleToGS* msg = dynamic_cast<MsgSendPlayerKillWhiteRoleToGS*>(message);
	if (msg == nullptr)
	{
		return;
	}

	EntityPlayer* player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr)
	{
		return;
	}

	lua::call(lua::L, "Entity.addPKValue", player);
}

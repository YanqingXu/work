#include "stdafx.h"
#include "PlayerMsgHandler.h"
#include "Login/Account.h"
#include "Login/AccountManager.h"
#include "message/DBMsgItem.h"
#include "message/DBMsgCross.h"
#include "message/MsgChat.h"
#include "message/MsgServerLogic.h"
#include "message/MsgGsToGs.h"
#include "message/DBMsgPlayer.h"
#include "Entity/EntityLua.h"
#include "Entity/EntityPet.h"
#include "Entity/EntityOperationHelper.h"
#include "Entity/WorldPlayerManager.h"
#include "Item/ItemOperationHelper.h"
#include "Entity/EntityFactory.h"
#include "Event/EventData.h"
#include "OperationHelper.h"
#include "Guild/GuildHelper.h"
#include "Application.h"
#include "Guild/GuildMgr.h"
#include "World/SwitchManager.h"
#include "Event/EventHelper.h"
#include "Scene/SceneOperationHelper.h"
#include "World/World.h"
#include "Cross//GSHelper.h"
#include "Gene/Gene.h"
#include "message/MsgGMaster.h"
#include "Login/LoginHelper.h"

PlayerMsgHandler::PlayerMsgHandler(Service *service) :
	Module(service)
{
	// 设置攻击模式
	registerMessageHandler<MsgSetPlayerPkModeRequest>(std::bind(&PlayerMsgHandler::onSetPkModeRequest, this, std::placeholders::_1));
	// 获取地图内怪物信息
	registerMessageHandler<MsgGetBossCntInMapRequest>(std::bind(&PlayerMsgHandler::onMsgGetBossCntInMapRequest, this, std::placeholders::_1));
	// 兑换礼包码
	registerMessageHandler<MsgGetGiftByCodeRequest>(std::bind(&PlayerMsgHandler::onGetGiftByCodeRequest, this, std::placeholders::_1));
	// 领取内置活动奖励
	registerMessageHandler<MsgActivityRewardRequest>(std::bind(&PlayerMsgHandler::onActivityRewardRequest, this, std::placeholders::_1));
	// 内置活动操作请求
	registerMessageHandler<MsgActivityOperateRequest>(std::bind(&PlayerMsgHandler::onActivityOperateRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgUpdPlayerPropsDataRequest>(std::bind(&PlayerMsgHandler::onGetPlayerTypeData, this, std::placeholders::_1));
	registerMessageHandler<MsgChatRequest>(std::bind(&PlayerMsgHandler::onChatRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgShutUpRequest>(std::bind(&PlayerMsgHandler::onShutUpRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgExchangeRebornPointsRequest>(std::bind(&PlayerMsgHandler::onExchangeRebornPointsRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRebornRequest>(std::bind(&PlayerMsgHandler::onRebornRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgExchangeSamsaraPointsRequest>(std::bind(&PlayerMsgHandler::onExchangeSamsaraPointsRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSamsaraRequest>(std::bind(&PlayerMsgHandler::onSamsaraRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgSyncPlayerEventDataRequest>(std::bind(&PlayerMsgHandler::onSyncPlayerEventDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetOtherPlayerDataRequest>(std::bind(&PlayerMsgHandler::onGetOtherPlayerDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetGiftRequest>(std::bind(&PlayerMsgHandler::onGetGiftRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgFuncDataOperatorRequest>(std::bind(&PlayerMsgHandler::onFuncDataOperator, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenHeadTitleRequest>(std::bind(&PlayerMsgHandler::onOpenHeadTitleRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCloseHeadTitleRequest>(std::bind(&PlayerMsgHandler::onCloseHeadTitleRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRenameRequest>(std::bind(&PlayerMsgHandler::onRenameRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgCheckEquipRequest>(std::bind(&PlayerMsgHandler::onCheckEquipRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCheckSoulStoneRequest>(std::bind(&PlayerMsgHandler::onCheckSoulStoneRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgEventDataRequest>(std::bind(&PlayerMsgHandler::onEventDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetOfflineExpRequest>(std::bind(&PlayerMsgHandler::onGetOfflineExp, this, std::placeholders::_1));
	registerMessageHandler<MsgExerciseRequest>(std::bind(&PlayerMsgHandler::onExerciseRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgOpenWingsRequest>(std::bind(&PlayerMsgHandler::onOpenWingsRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdataWingsRequest>(std::bind(&PlayerMsgHandler::onUpdataWingsRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgChangeWingDressRequest>(std::bind(&PlayerMsgHandler::onChangeWingDressRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgImproveWingRequest>(std::bind(&PlayerMsgHandler::onImproveWingRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdataBossScoreRequest>(std::bind(&PlayerMsgHandler::onUpdataBossScoreRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdataBsscCnRequest>(std::bind(&PlayerMsgHandler::onUpdataBsscCnRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenAutoAtkMapRequest>(std::bind(&PlayerMsgHandler::onOpenAutoAtkMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgStartOffLineRequest>(std::bind(&PlayerMsgHandler::onStartOffLineRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOfflineTakeRewardRequest>(std::bind(&PlayerMsgHandler::onOfflineTakeRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOfflineVipRewardRequest>(std::bind(&PlayerMsgHandler::onOfflineVipRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenOffLineRequest>(std::bind(&PlayerMsgHandler::onOpenOffLineRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCloseOffLineRequest>(std::bind(&PlayerMsgHandler::onCloseOffLineRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgGetVipExpBuffRequest>(std::bind(&PlayerMsgHandler::onGetVipExpBuffRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRefreshEventDataRequest>(std::bind(&PlayerMsgHandler::onRefreshEventDataRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetLevelRewardRequest>(std::bind(&PlayerMsgHandler::onGetLevelRewardRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgDBLoadPlayerProps>(std::bind(&PlayerMsgHandler::onDBLoadPlayerExData, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadPlayerStrData>(std::bind(&PlayerMsgHandler::onDBLoadPlayerStrData, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadPlayerEvent>(std::bind(&PlayerMsgHandler::onDBLoadPlayerEvent, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadPlayerGene>(std::bind(&PlayerMsgHandler::onDBLoadPlayerGene, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadSkill>(std::bind(&PlayerMsgHandler::onDBLoadSkill, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadPetSkill>(std::bind(&PlayerMsgHandler::onDBLoadPetSkill, this, std::placeholders::_1));
	registerMessageHandler<MsgDBAddPetSkill>(std::bind(&PlayerMsgHandler::onDBAddPetSkill, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadPlayerDress>(std::bind(&PlayerMsgHandler::onDBLoadPlayerDress, this, std::placeholders::_1));

	registerMessageHandler<MsgDBAddSkill>([](Message *message){});
	registerMessageHandler<MsgDBRemoveSkill>([](Message *message){});
	registerMessageHandler<MsgDBUpdPlayerEvent>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerProp>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerStrData>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerGuildID>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerLvlExp>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerPositon>([](Message *message){});
	registerMessageHandler<MsgDBUpdateSkillSidExp>([](Message *message){});
	registerMessageHandler<MsgDBUpdatePlayerName>(std::bind(&PlayerMsgHandler::onDBRenameResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgDBUpdatePlayerBoundIngot>([](Message *message){});
	registerMessageHandler<MsgDBAddPlayerProp>([](Message *message){});
	registerMessageHandler<MsgDBLoadPlayerGene>([](Message *message){});
	registerMessageHandler<MsgDBUpdPlayerGene>([](Message *message){});
	registerMessageHandler<MsgDBRmvPlayerGene>([](Message *message){});

	registerMessageHandler<MsgDBCheckAppStoreCommentRewarded>(std::bind(&PlayerMsgHandler::onDBCheckAppStoreCommentRewarded, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadIncome>(std::bind(&PlayerMsgHandler::onDBLoadIncome, this, std::placeholders::_1));
	
	registerMessageHandler<MsgOpenSpecialRingRequest>(std::bind(&PlayerMsgHandler::onOpenSpecialRingRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgAskForRewardRequest>(std::bind(&PlayerMsgHandler::onAskForRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgTTSYGuWuRequest>(std::bind(&PlayerMsgHandler::onTTSYGuWuRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgPlayerLvChangeCultRequest>(std::bind(&PlayerMsgHandler::onMsgPlayerLvChangeCultRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgEnhancePosRequest>(std::bind(&PlayerMsgHandler::onEnhancePosRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgStonePosRequest>(std::bind(&PlayerMsgHandler::onStonePosRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgPlayerDressOperatorRequest>(std::bind(&PlayerMsgHandler::onPlayerDressOperatorRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSetDressStatusRequest>(std::bind(&PlayerMsgHandler::onSetDressStatusRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgExchangeSkillBookRequest>(std::bind(&PlayerMsgHandler::onExchangeSkillBookRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdateCSRequest>(std::bind(&PlayerMsgHandler::onUpdateCSPosRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetMasterRewardRequest>(std::bind(&PlayerMsgHandler::onGetMasterRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenPrivilegeRequest>(std::bind(&PlayerMsgHandler::onOpenPrivilegeRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetPrivilegeRewardRequest>(std::bind(&PlayerMsgHandler::onGetPrivilegeRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgRenewPrivilegeRequest>(std::bind(&PlayerMsgHandler::onRenewPrivilegeRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdateXSRWTaskStateRequest>(std::bind(&PlayerMsgHandler::onUpdateXSRWTaskStateRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdateComposeStateRequest>(std::bind(&PlayerMsgHandler::onUpdateComposeStateRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgFulingRequest >(std::bind(&PlayerMsgHandler::onFulingRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgFulingZYRequest >(std::bind(&PlayerMsgHandler::onFulingZYRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgOnChallengeTowerRequest>(std::bind(&PlayerMsgHandler::onChallengeTowerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgGetTowerRewardRequest>(std::bind(&PlayerMsgHandler::onGetTowerRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgBuyDailyItemRequest>(std::bind(&PlayerMsgHandler::onBuyDailyItemRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCalcMyBossTimesRequest>(std::bind(&PlayerMsgHandler::onCalcMyBossTimesRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgBossBoxDigRequest>(std::bind(&PlayerMsgHandler::onBossBoxDigRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdateShopGuideRequest>(std::bind(&PlayerMsgHandler::onUpdateShopGuideRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgGetTowerSweepRequest>(std::bind(&PlayerMsgHandler::onGetTowerSweepRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgBailRequest>(std::bind(&PlayerMsgHandler::onGetBailRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgVipServiceShowCheckRequest>(std::bind(&PlayerMsgHandler::onVipServiceShowCheckRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNearbyPlayerRequest>(std::bind(&PlayerMsgHandler::onNearbyPlayerRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNearbyPlayerCheckRequest>(std::bind(&PlayerMsgHandler::onNearbyPlayerCheckRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCreateRoleCodeRequest>(std::bind(&PlayerMsgHandler::onCreateRoleCodeRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgCreateRoleCodeInfoRequest>(std::bind(&PlayerMsgHandler::onCreateRoleCodeInfoRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgAskforSoulSystemInfoRequest>(std::bind(&PlayerMsgHandler::onAskforSoulSystemInfoRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgImproveSoulRequest>(std::bind(&PlayerMsgHandler::onImproveSoul, this, std::placeholders::_1));
	registerMessageHandler<MsgExchangeSoulRequest>(std::bind(&PlayerMsgHandler::onExchangeSoulRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgBossUpdateTimeRequest>(std::bind(&PlayerMsgHandler::onUpdateBossTimeRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenSecondWareRequest>(std::bind(&PlayerMsgHandler::onOpenSecWarehouseRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgQuickUseItemsRequest>(std::bind(&PlayerMsgHandler::onQuickUseItemsRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSyntheticRequest>(std::bind(&PlayerMsgHandler::onSyntheticRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgDecomposeDressRequest>(std::bind(&PlayerMsgHandler::onDecomposeDress, this, std::placeholders::_1));

	registerMessageHandler<MsgUpdServerNameRequest>(std::bind(&PlayerMsgHandler::onUpdServerNameRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgPlayerLevelUpRequest>(std::bind(&PlayerMsgHandler::onLevelUpRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgUpdatePlayerSkillRequest>(std::bind(&PlayerMsgHandler::onUpgradeSkillLevelRequest, this, std::placeholders::_1));
	 
	registerMessageHandler<MsgSmeltRefreshRequest>(std::bind(&PlayerMsgHandler::onSmeltRefreshRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSmeltReplaceRequest>(std::bind(&PlayerMsgHandler::onSmeltReplaceRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSmeltClearNewAttrsRequest>(std::bind(&PlayerMsgHandler::onSmeltClearNewAttrsRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgLuckyImmedFullLevelRequest>(std::bind(&PlayerMsgHandler::onLuckyImmedFullLevelRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgSpiritStoneRequest>(std::bind(&PlayerMsgHandler::onSpiritStoneRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgSpiritStoneMakeRequest>(std::bind(&PlayerMsgHandler::onSpiritStoneMakeRequest, this, std::placeholders::_1));

	//圣兽升级
	registerMessageHandler<MsgPlayerTherionLevelRequest>(std::bind(&PlayerMsgHandler::onTherionLevelRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgExchangeHegemonEquipShowRequest>(std::bind(&PlayerMsgHandler::onExchangeHegemonEquipShowt, this, std::placeholders::_1));
	//衣橱升级
	registerMessageHandler<MsgPlayerDressWardrobeLvlUpRequest>(std::bind(&PlayerMsgHandler::onPlayerDressWardrobeUpRequest, this, std::placeholders::_1));
	//萌宠操作 
	registerMessageHandler<MsgPlayerLovelyPetRequest>(std::bind(&PlayerMsgHandler::onPlayerLovelyPetRequest, this, std::placeholders::_1));
	//加载萌宠
	registerMessageHandler<MsgPlayerLoadPetRequest>(std::bind(&PlayerMsgHandler::onPlayerLoadPetRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgKeepMsgRequest>(std::bind(&PlayerMsgHandler::onKeepMsgRequest, this, std::placeholders::_1));
	//萌宠技能包
	registerMessageHandler<MsgPlayerGetBaoBaoSkillRequest>(std::bind(&PlayerMsgHandler::onPlayerBuyBaoBaoSkill, this, std::placeholders::_1));

	//跨服相关
	registerMessageHandler<MsgDBLoadPlayerCrossEvent>(std::bind(&PlayerMsgHandler::onDBLoadPlayerCrossEvent, this, std::placeholders::_1));

	//获取练功房奖励 
	registerMessageHandler<MsgPlayerGetTrainingRewardRequest>(std::bind(&PlayerMsgHandler::onPlayerGetTrainingRewardRequest, this, std::placeholders::_1));
	//砖石兑换元宝
	registerMessageHandler<MsgExchangeIngotRequest>(std::bind(&PlayerMsgHandler::onExchangeIngotRequest, this, std::placeholders::_1));

	//购买特戒礼包
	registerMessageHandler<MsgPlayerGetSpecialRingGiftRequest>(std::bind(&PlayerMsgHandler::onPlayerGetSpecialRingGifrRequest, this, std::placeholders::_1));
	//石墓烧猪操作
	registerMessageHandler<MsgRoastPigRequest>(std::bind(&PlayerMsgHandler::onRoastPigRequest, this, std::placeholders::_1));
	//月卡奖励领取
	registerMessageHandler<MsgMonthCardGetRewardRequest>(std::bind(&PlayerMsgHandler::onMonthCardGetRewardRequest, this, std::placeholders::_1));
	//会员操作  
	registerMessageHandler<MsgMemberOpeartionRequest>(std::bind(&PlayerMsgHandler::onMemberOpeartionRequest, this, std::placeholders::_1));
	//获取玩家信息 
	registerMessageHandler<MsgDBLoadPlayerEquipInfo>(std::bind(&PlayerMsgHandler::onDBLoadPlayerEquipInfo, this, std::placeholders::_1));
	registerMessageHandler<MsgDBLoadOtherPlayerInfo>(std::bind(&PlayerMsgHandler::onDBLoadOtherPlayerInfo, this, std::placeholders::_1));

	//新vip
	registerMessageHandler<MsgNewVipActiveRequest>(std::bind(&PlayerMsgHandler::onNewVipActiveRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNewVipLvlUpRequest>(std::bind(&PlayerMsgHandler::onNewVipLvlUpRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNewVipChallengeRequest>(std::bind(&PlayerMsgHandler::onNewVipChallengeRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNewVipGetStarRewardRequest>(std::bind(&PlayerMsgHandler::onNewVipGetStarRewardRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgNewVipSubmitQuestRequest>(std::bind(&PlayerMsgHandler::onNewVipSubmitQuestRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgActiveQiLingRequest>(std::bind(&PlayerMsgHandler::onActiveQiLingRequest, this, std::placeholders::_1));
	//宝图
	registerMessageHandler<MsgGetTheasureMapPosRequest>(std::bind(&PlayerMsgHandler::onGetTheasureMapPosRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenTheasureMapRequest>(std::bind(&PlayerMsgHandler::onOpenTheasureMapRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgOpenTheasureMapGetAwardRequest>(std::bind(&PlayerMsgHandler::onOpenTheasureMapGetAwardRequest, this, std::placeholders::_1));
	//购买额外归属奖励次数 
	registerMessageHandler<MsgGetXiYouRewardCountRequest>(std::bind(&PlayerMsgHandler::onGetXiYouRewardCountRequest, this, std::placeholders::_1));	
	//领取历练之路奖励 
	registerMessageHandler<MsgExpRoadRewardRequest>(std::bind(&PlayerMsgHandler::onExpRoadRewardRequest, this, std::placeholders::_1));	
	//检测私聊目标玩家在不在线 
	registerMessageHandler<MsgPrivateChatOnlineCheckRequest>(std::bind(&PlayerMsgHandler::onPrivateChatOnlineCheckRequest, this, std::placeholders::_1));	

	// 领取天关秘境，pve爬塔，扫荡奖励
	registerMessageHandler<MsgTgmjTowerClearRequest>(std::bind(&PlayerMsgHandler::onTgmjTowerClearRequest, this, std::placeholders::_1));

	// 领取天关秘境，pve爬塔，扫荡奖励
	registerMessageHandler<MsgBloodUpdateRequest>(std::bind(&PlayerMsgHandler::onBloodUpRequest, this, std::placeholders::_1));

	// 统计 消息同步列表
	registerMessageHandler<MsgSYNCTABRequest>(std::bind(&PlayerMsgHandler::onSyncTabRequest, this, std::placeholders::_1));

	//跨服预热
	registerMessageHandler<MsgPlayerJuHePayRequest>(std::bind(&PlayerMsgHandler::onMsgPlayerJuHePayRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgPlayerChatVeriPhoneRequest>(std::bind(&PlayerMsgHandler::onMsgPlayerChatVeriPhoneRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgPlayerChatVeriCodeRequest>(std::bind(&PlayerMsgHandler::onMsgPlayerChatVeriCodeRequest, this, std::placeholders::_1));
	//自定义脚本
	registerMessageHandler<MsgCommonOperatorRequest>(std::bind(&PlayerMsgHandler::onMsgCommonOperatorRequest, this, std::placeholders::_1));
	
	registerMessageHandler<MsgGetMapStatisticsDataRequest>(std::bind(&PlayerMsgHandler::onMsgGetMapStatisticsDataRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgFabaoUpRequest>(std::bind(&PlayerMsgHandler::onFabaoUpRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgOperationRecordNotify>(std::bind(&PlayerMsgHandler::onOperationRecordNotify, this, std::placeholders::_1));

	registerMessageHandler<MsgDoctorRequest>(std::bind(&PlayerMsgHandler::onDoctorRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgDBUpdatePlayerClass>(std::bind(&PlayerMsgHandler::onUpdatePlayerClass, this, std::placeholders::_1));
	registerMessageHandler<MsgDBUpdatePlayerGender>(std::bind(&PlayerMsgHandler::onDBGenderResponse, this, std::placeholders::_1));
	registerMessageHandler<MsgToushiRequest>(std::bind(&PlayerMsgHandler::onToushiRequest, this, std::placeholders::_1));

	registerMessageHandler<MsgGetPlayerBaseInfoRequest>(std::bind(&PlayerMsgHandler::onGetPlayerBaseInfoRequest, this, std::placeholders::_1));
	registerMessageHandler<MsgLoadPlayerBaseInfo>(std::bind(&PlayerMsgHandler::onLoadPlayerBaseInfo, this, std::placeholders::_1));
}

PlayerMsgHandler::~PlayerMsgHandler()
{
}

bool PlayerMsgHandler::initialize()
{
	if (!__super::initialize())
	{
		return false;
	}

	// 	FindBoxPageOpenSession.insert(45);
	// 	FindBoxPageOpenSession.insert(1);
	// 	FindBoxPageOpenSession.insert(2);
	// 	FindBoxPageOpenSession.insert(5);
	// 	FindBoxPageOpenSession.insert(9);

	return true;
}

void PlayerMsgHandler::onDBLoadPlayerStrData(Message *message)
{
	MsgDBLoadPlayerStrData *msg = dynamic_cast<MsgDBLoadPlayerStrData *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	for (auto it = msg->playerStrVec.begin(); it != msg->playerStrVec.end(); ++it)
	{
		DBPlayerStr ed = (DBPlayerStr)(*it);
		player->setPropString(ed.keyid, ed.data);
		
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_STR, msg->load_id);
	player->onEvent(evt);
}

void PlayerMsgHandler::onDBLoadPlayerExData(Message *message)
{
 	MsgDBLoadPlayerProps *msg = dynamic_cast<MsgDBLoadPlayerProps*>(message);
 	if (!msg)
 	{
 		return;
 	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	for (auto it = msg->props.begin(); it != msg->props.end(); ++it)
	{
		exData ed = (exData)(*it);

		if (ed.ctype == ENTITY_PROP_STONE_POINT)
		{
			continue;
		}

		if (EntityOperationHelper::checkNeedSave(ed.ctype))
		{
			player->setProp(ed.ctype, ed.data);
		}
	}

	std::vector<int> saveProps;

	// 初始化背包格子
	if (player->getProp(ENTITY_PROP_BAG_SLOT) == 0)
	{
		int count = 56;
		lua::getglobal(lua::L, "gdGame.playerBagslot", count);
		player->setProp(ENTITY_PROP_BAG_SLOT, count);
		saveProps.push_back(ENTITY_PROP_BAG_SLOT);
	}
	// 初始化仓库格子
	if (player->getProp(ENTITY_PROP_NPC_BAG_SLOT) == 0)
	{
		int count = 56;
		lua::getglobal(lua::L, "gdGame.npcBagslot", count);
		player->setProp(ENTITY_PROP_NPC_BAG_SLOT, count);
		saveProps.push_back(ENTITY_PROP_NPC_BAG_SLOT);
	}

	// 初始化设置
	if (player->getProp(ENTITY_SET_INIT) == 0)
	{
		player->setProp(ENTITY_SET_AUTO_USE_STONE_HP_VAL, 30);
		saveProps.push_back(ENTITY_SET_AUTO_USE_STONE_HP_VAL);
		player->setProp(ENTITY_SET_AUTO_USE_ADD_HP_DRUG, 70);
		saveProps.push_back(ENTITY_SET_AUTO_USE_ADD_HP_DRUG);
		player->setProp(ENTITY_SET_AUTO_USE_ADD_MP_DRUG, 30);
		saveProps.push_back(ENTITY_SET_AUTO_USE_ADD_MP_DRUG);
		player->setProp(ENTITY_SET_INIT, 1);
		saveProps.push_back(ENTITY_SET_INIT);
	}

	player->setProp(ENTITY_PROP_PROPS_LOADED, 1);
	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_PROPS, msg->load_id);
	player->onEvent(evt);
	//批量保存属性
	if (saveProps.size() > 0)
	{
		EntityOperationHelper::savePlayerAllProps(*player, saveProps);
	}
}

void PlayerMsgHandler::onGetPlayerTypeData(Message *message)
{
	MsgUpdPlayerPropsDataRequest* msg = dynamic_cast<MsgUpdPlayerPropsDataRequest*>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	EntityOperationHelper::syncEntityProp(*player, msg->type);
}

void PlayerMsgHandler::onDBLoadSkill(Message *message)
{
	MsgDBLoadSkill* msg = dynamic_cast<MsgDBLoadSkill*>(message);
	if(!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if (player == NULL || player->getPlayerID() != msg->pid)
	{
		return;
	}

	Combat *combat = player->getCombat();
	if (!combat)
	{
		LOG_ERROR("Load Skill %d %d not Find combatSys", player->getType(), player->getPlayerID());
		return;
	}

	for (auto it = msg->skill_list.begin(); it != msg->skill_list.end(); ++it)
	{
		combat->addSkill(it->sid, it->lvl);
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_SKILLS, msg->load_id);
	player->onEvent(evt);
}

void PlayerMsgHandler::onDBLoadPetSkill(Message *message)
{
	MsgDBLoadPetSkill* msg = dynamic_cast<MsgDBLoadPetSkill*>(message);
	if(!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if (player == NULL || player->getPlayerID() != msg->pid)
	{
		return;
	}

	for (auto it = msg->skill_list.begin(); it != msg->skill_list.end(); ++it)
	{
		player->AddPetSkill(it->sid, it->exp, it->position);
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_PET_SKILLS, msg->load_id);
	player->onEvent(evt);
}

// 添加宠物技能
void PlayerMsgHandler::onDBAddPetSkill(Message *message)
{
	MsgDBAddPetSkill* msg = dynamic_cast<MsgDBAddPetSkill*>(message);
	if(!msg)
	{
		return;
	}

	EntityPlayer *player = player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == NULL)
	{
		return;
	}

	player->StudyPetSkillResult(msg->sid, msg->getErrcode());
}

void PlayerMsgHandler::onDBLoadPlayerEvent(Message *message)
{
	MsgDBLoadPlayerEvent *msg = dynamic_cast<MsgDBLoadPlayerEvent *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	int now = (int)time(NULL);

	for (auto it = msg->events.begin(); it != msg->events.end(); ++it)
	{
		DBPlayerEvent ed = (DBPlayerEvent)(*it);

		if (ed.eid >= EVENT_GENE_BEGIN && ed.eid <= EVENT_GENE_END)
		{
			//int duration = ed.tindex - now;
			//if (duration > 0)
			//{
			//	int rtv = SUCCESS;
			//	if (ed.datax > 100000)
			//	{
			//		EntityOperationHelper::addGene(*player, ed.datax, GENE_TYPE_ITEM_TIME, ed.datax - 10000000, duration);
			//	}
			//	else
			//	{
			//		EntityOperationHelper::addGene(*player, ed.datax, duration);
			//	}
			//}
		}
		else
		{
			EventData *data = player->addEventData(ed.eid);
			if (data)
			{
				data->setTimeIndex(ed.tindex); 
				data->setDataX(ed.datax);
				data->setDataY(ed.datay);
				data->setDataZ(ed.dataz);
				data->setCtime(ed.ctime);
			}
		}
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_EVENTS, msg->load_id);
	player->onEvent(evt);
}

//加载玩家基因
void PlayerMsgHandler::onDBLoadPlayerGene(Message *message)
{
	MsgDBLoadPlayerGene *msg = dynamic_cast<MsgDBLoadPlayerGene *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	if (msg->load_id == 0)
	{
		player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	else
	{
		player = g_world_player_mgr.getLoadPlayer(msg->load_id);
	}
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	int now = (int)time(NULL);

	for (auto it = msg->genes.begin(); it != msg->genes.end(); ++it)
	{
		DBPlayerGene &genedata = *it;

		int duration = genedata.duration - now;

		// If the event data is still in database, it means that the gene expired during the player is not online
		// Or the server is restarting, in these cases, we still need to detach the gene, otherwise the benefit associated
		// with the gene will never get off from the player. Change the duration to 1 (second), attache the gene,
		// then detach and remove it immediately
		// Ronghui Yu, Oct 23 2014
		if (duration <= 0)
		{
			duration = 1;
		}

		if (genedata.geneid > 10000000)
		{
			int item_id = genedata.geneid - 10000000;
			int ret = EntityOperationHelper::addGene(*player, genedata.geneid, GENE_TYPE_ITEM_TIME, item_id, duration, false, 0, 0, 0);
			if (ret != SUCCESS)
			{
				LOG_ERROR("player %d %s add gene %d failed",player->getPlayerID(), player->getName(), genedata.geneid);
			}
		}
		else
		{
			int ret = EntityOperationHelper::addGene(*player, genedata.geneid, duration);
			if(ret == SUCCESS)
			{
				Gene* gene = player->getGene(genedata.geneid);
				if(gene)
				{
					gene->setDataX(genedata.datax);
					gene->setDataY(genedata.datay);
					gene->setDataZ(genedata.dataz);
				}
			}
		}	
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_GENES, msg->load_id);
	player->onEvent(evt);
}

void PlayerMsgHandler::onDBLoadPlayerDress(Message *message)
{
	
}

// 设置攻击模式
void PlayerMsgHandler::onSetPkModeRequest(Message *message)
{
	MsgSetPlayerPkModeRequest* msg = dynamic_cast<MsgSetPlayerPkModeRequest*>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		return;
	}

	// 新手保护期间不允许切换模式
	if (player->getLevel() < NOVICE_PROTECTION_LEVEL)
	{
		return;
	}

	MsgSetPlayerPkModeResponse *response = new MsgSetPlayerPkModeResponse;
	response->errcode = SUCCESS;
	response->setSessionID(msg->getSessionID());

	Scene *scene = player->getScene();
	if (scene == NULL)
	{
		response->errcode = ERROR_INVALID_SCENE;
		g_app.postToNetService(response);
		return;
	}

	int mode = msg->pkmode;
	// 切换同一模式时不予切换
	int curMode = player->getProp(ENTITY_PROP_ATTACK_MODE);
	if (mode == curMode)
	{
		return;
	}

	if (lua::call(lua::L, "Entity.changePKMode", player, mode))
	{
		int ret = lua::getinteger(1);
		if (ret != SUCCESS)
		{
			response->errcode = ret;
			g_app.postToNetService(response);
			return;
		}

		mode = lua::getinteger(2);
	}
	// 比奇城中的几个打包地图，强制是和平[紧急修改]
	if (scene->getStaticID() >= 1101 && scene->getStaticID() <= 1106)
	{
		mode = ATTACK_MODE_PEACE;
	}
	else
	{
		// if (scene->getType() == SCENE_TYPE_NORMAL)
		// {
			player->setProp(ENTITY_PROP_ATTACK_MODE_BACKUP, mode);
		// }
	}
	
	player->setProp(ENTITY_PROP_ATTACK_MODE, mode);
	EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_ATTACK_MODE);
	EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_ATTACK_MODE);

	player->for_each_child([player](Entity *child){
		if (child->getType() == ENTITY_TYPE_DOG)
		{
			child->setState(ENTITY_STATE_IDLE);
		}
	});

	response->errcode = SUCCESS;
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onChatRequest(Message *message)
{
	MsgChatRequest *msg = dynamic_cast<MsgChatRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.legalChat", (Entity *)player, msg->chatText))
	{
		ret = lua::getinteger(1);
	}

	if( ret != SUCCESS)
	{
		ret = ERROR_UNKNOWN;
		return;
	}

	MsgChatResponse *response = new MsgChatResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	//检查是否被禁言了(禁止世界和附近）
	//if (msg->chatType == CHAT_TYPE_WORLD || msg->chatType == CHAT_TYPE_NEAR)
	//{
	//禁言时间内全渠道禁言
	if (player->getProp(ENTITY_PROP_NO_ALLOW_CHAT) >= time(NULL))
	{
		response->errcode = ERROR_PLAYER_NOT_ALLOW_CHAT;
		g_app.postToNetService(response);
		return;
	}

	//检查聊天CD
	bool targetIsOnline = false;
	if(msg->chatType == CHAT_TYPE_PRIVATE && msg->partnerPid)
	{
		Entity *chatPartner =  g_world_player_mgr.getPlayerByPlayerID(msg->partnerPid);
		if (chatPartner && msg->partnerPid != player->getID())
		{
			targetIsOnline = true;

			if (chatPartner->getProp(ENTITY_SET_REFUSE_PRIVATE_CHAT) == 1)
			{
				response->errcode = ERROR_REFUSE_PRIVATE_CHAT;
				g_app.postToNetService(response);
				return;
			}
		}
	}

	if(msg->chatType != CHAT_TYPE_PRIVATE || targetIsOnline)
	{
		if(lua::call(lua::L, "Entity.checkChatCD", player, msg->chatType))
		{
			ret = lua::getinteger(1);
			if(ret != SUCCESS)
			{
				response->errcode = ret;
				g_app.postToNetService(response);
				return;
			}
		}
		else
		{
			return;
		}
	}
	
	if(lua::call(lua::L, "Entity.dealChatMsg", player, msg->chatText))
	{
		msg->chatText = lua::getstring(1);
	}
	
	response->errcode = EntityOperationHelper::syncChatMsg(player,
		msg->chatType, msg->chatText, msg->partnerPid);
	g_app.postToNetService(response);

	if (response->errcode == SUCCESS && g_switch_mgr.IsSwitchEnabled(SWITCH_CHAT_SUBMIT))
	{
		MsgChatSubmit *request = new MsgChatSubmit();
		request->serverIp = g_config.getGameHost();
		request->port  =	g_config.getGamePort();
		request->chatType = msg->chatType;
		request->chatStr  = msg->chatText;
		request->playerName = player->getName();
		if (msg->partnerPid > 0 && g_world_player_mgr.getPlayerByPlayerID(msg->partnerPid) != NULL)
		{
			request->privateName =	g_world_player_mgr.getPlayerByPlayerID(msg->partnerPid)->getName();
		}
		request->pid      = player->getGlobalID();
		g_app.postToNetService(request);
	}


}

// 禁言
void PlayerMsgHandler::onShutUpRequest(Message *message)
{
	MsgShutUpRequest *msg = dynamic_cast<MsgShutUpRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgShutUpResponse* res = new MsgShutUpResponse;

	EntityPlayer* target = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (NULL == target)
	{
		res->errcode = ERROR_TARGET_NOT_ONLINE;
		player->sendMessage(res);
		return;
	}

	// 去禁言次数
	int count = 0;
	//lua::call(lua::L, "Vip.getVipData", player, VIP_SHUT_UP);
	//count = lua::getinteger(1);

	if (count <= 0)
	{
		res->errcode = ERROR_NOT_ENOUGH_VIP_LEVEL;
		player->sendMessage(res);
		return;
	}

	EventData* pData = player->getEventData(EVENT_DAYSHUTUP);
	int hascount = pData->getDataX();

	if (hascount >= count)
	{
		res->errcode = ERROR_NOT_ENOUGH_SHUT_UP;
		player->sendMessage(res);
		return;
	}

	pData->setDataX(hascount + 1);

	EntityOperationHelper::syncEntityEventData(*player, EVENT_DAYSHUTUP);
	EntityOperationHelper::saveEntityEventData(*player, EVENT_DAYSHUTUP);

	// 禁言一个小时（需要防止被GM永久禁言的角色因禁言1小时反而提前解禁）
	if(target->getProp(ENTITY_PROP_NO_ALLOW_CHAT)<time(NULL) + 3600)
	{
		target->setProp(ENTITY_PROP_NO_ALLOW_CHAT, (int)time(NULL) + 3600);
		EntityOperationHelper::saveEntityProp(*target, ENTITY_PROP_NO_ALLOW_CHAT);
		EntityOperationHelper::syncEntityProp(*target, ENTITY_PROP_NO_ALLOW_CHAT);
	}

	res->errcode = SUCCESS;
	player->sendMessage(res);
}

//兑换转生修为
void PlayerMsgHandler::onExchangeRebornPointsRequest(Message *message)
{
	MsgExchangeRebornPointsRequest *msg = dynamic_cast<MsgExchangeRebornPointsRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//OperationHelper::setOpCode(OP_EXCHANGE_REBORN_POINTS);

	EntityOperationHelper::exchangeRebornPoints(*player);
}

//转生
void PlayerMsgHandler::onRebornRequest(Message *message)
{
	MsgRebornRequest *msg = dynamic_cast<MsgRebornRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	OperationHelper::setOpCode(OP_REBORN);

	EntityOperationHelper::reborn(*player);
}

//兑换轮回修为
void PlayerMsgHandler::onExchangeSamsaraPointsRequest(Message *message)
{
	MsgExchangeSamsaraPointsRequest *msg = dynamic_cast<MsgExchangeSamsaraPointsRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	EntityOperationHelper::exchangeSamsaraPoints(*player);
}

//轮回
void PlayerMsgHandler::onSamsaraRequest(Message *message)
{
	MsgSamsaraRequest *msg = dynamic_cast<MsgSamsaraRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	OperationHelper::setOpCode(OP_SAMSARA);

	EntityOperationHelper::samsara(*player);
}

void PlayerMsgHandler::onSyncPlayerEventDataRequest(Message *message)
{
	MsgSyncPlayerEventDataRequest *msg = dynamic_cast<MsgSyncPlayerEventDataRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	EntityOperationHelper::syncEntityEventData(*player, msg->eventid);
	
}

void PlayerMsgHandler::onGetOtherPlayerDataRequest(Message *message)
{ 
	MsgGetOtherPlayerDataRequest *msg = dynamic_cast<MsgGetOtherPlayerDataRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgGetOtherPlayerDataResponse *response = new MsgGetOtherPlayerDataResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ERROR_UNKNOWN;

	Entity *entity = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (entity == NULL)
	{
		response->errcode = ERROR_PLAYER_IS_OFFLINE;
		g_app.postToNetService(response);
		return;
	}

	EntityOperationHelper::syncOtherEntityData(*player, entity);
	ItemOperationHelper::syncOtherPlayerEquip(*player, entity);

	response->errcode = SUCCESS;
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onGetGiftRequest(Message *message)
{
	MsgGetGiftRequest *msg = dynamic_cast<MsgGetGiftRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret  = ERROR_UNKNOWN;
	switch (msg->GiftCate)
	{
	case GIFT_RECHARGE_ALL:
		{
			LOG_DEBUG("Get All Recharge Type = %d",msg->GiftType);
			if (g_switch_mgr.IsSwitchEnabled(SWITCH_RECHARGE))
			{
				if (msg->GiftType >= 0)
				{
					int rcgifts = player->getProp(ENTITY_PROP_RECHARGE_GIFT);
					if (!(rcgifts & ((int)1 <<(msg->GiftType))))
					{
						lua::call(lua::L, "Gift.rechargeGift", player, msg->GiftType);
						ret = lua::getinteger(1);
						if (ret == SUCCESS)
						{
							rcgifts |= ((int)1 <<(msg->GiftType));
							player->setProp(ENTITY_PROP_RECHARGE_GIFT,rcgifts);
							EntityOperationHelper::syncEntityProp(*player,ENTITY_PROP_RECHARGE_GIFT);
							EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_RECHARGE_GIFT);
						}
					} 
					else
					{
						ret = ERROR_ALREADY_GET;
					}
				}
			} 
			else 
			{
				ret = ERROR_FEATURES_NOT_OPEN;
			}
		}
		break;
	case GIFT_RECHARGE_FIRST:
		{
			//单职业首充 奖励领取 
		//	LOG_DEBUG("Get First Recharge = %d",msg->GiftType);
			if (g_switch_mgr.IsSwitchEnabled(SWITCH_RECHARGE))
			{
				if (msg->GiftType > 0)
				{
					int rcgifts = player->getProp(ENTITY_PROP_RECHARGE_GIFT_RECORD);
					if (!(rcgifts & ((int)1 <<(msg->GiftType -1))))
					{
						lua::call(lua::L, "Gift.firstRechargeGift", player, msg->GiftType);
						ret = lua::getinteger(1);
						if (ret == SUCCESS)
						{
							rcgifts |= ((int)1 <<(msg->GiftType -1));
							player->setProp(ENTITY_PROP_RECHARGE_GIFT_RECORD,rcgifts);
							EntityOperationHelper::syncEntityProp(*player,ENTITY_PROP_RECHARGE_GIFT_RECORD);
							EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_RECHARGE_GIFT_RECORD);
						}
					} 
					else
					{
						ret = ERROR_ALREADY_GET;
					}
				}
			} 
			else 
			{
				ret = ERROR_FEATURES_NOT_OPEN;
			}
		}
		break;
	case GIFT_CONSUME_ALL:
		{
			LOG_DEBUG("Get gift consume package");
			if (msg->GiftType >= 0) {
                int rcgifts = player->getProp(ENTITY_PROP_CONSUME_GIFT);
				if (!(rcgifts & ((int)1 <<(msg->GiftType))))
				{
					lua::call(lua::L, "Gift","consumeGift", player, msg->GiftType);
					ret = lua::getinteger(1);
					if (ret == SUCCESS)
					{
						rcgifts |= ((int)1 <<(msg->GiftType));
						player->setProp(ENTITY_PROP_CONSUME_GIFT,rcgifts);
						EntityOperationHelper::syncEntityProp(*player,ENTITY_PROP_CONSUME_GIFT);
						EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_CONSUME_GIFT);

					}
				}
				else
				{
					ret = ERROR_ALREADY_GET;
				}
			}

		}
		break;
	case GIFT_ZHIZUN_LEVEL:
		{
			int rcgifts = player->getProp(ENTITY_PROP_ZHIZUN_REWARD_RECORD);
			if (!(rcgifts & ((int)1 <<(msg->GiftType-1))))
			{
				lua::call(lua::L, "Gift.zhiZunGift", player, msg->GiftType);
				ret = lua::getinteger(1);
				if (ret == SUCCESS)
				{
					rcgifts |= ((int)1 <<(msg->GiftType-1));
					player->setProp(ENTITY_PROP_ZHIZUN_REWARD_RECORD,rcgifts);
					EntityOperationHelper::syncEntityProp(*player,ENTITY_PROP_ZHIZUN_REWARD_RECORD);
					EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_ZHIZUN_REWARD_RECORD);

				}
			}
			else
			{
				ret = ERROR_ALREADY_GET;
			}

			break;
		}
	case GIFT_LIMIT_TIME:
		{
			LOG_DEBUG("Get Limit time = %d",msg->GiftType);
			if (msg->GiftType >= 0)
			{
				int rcgifts = player->getProp(ENTITY_PROP_LIMIT_TIME_GIFT);
				if (!(rcgifts & ((int)1 <<(msg->GiftType))))
				{
					lua::call(lua::L, "Gift.GetTimeLimitGift", player, msg->GiftType);
					ret = lua::getinteger(1);
					if (ret == SUCCESS)
					{
						rcgifts |= ((int)1 <<(msg->GiftType));
						player->setProp(ENTITY_PROP_LIMIT_TIME_GIFT,rcgifts);
						EntityOperationHelper::syncEntityProp(*player,ENTITY_PROP_LIMIT_TIME_GIFT);
						EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_LIMIT_TIME_GIFT);
					}
				}
				else
				{
					ret = ERROR_ALREADY_GET;
				}	
			}
		}
		break;
	case GIFT_RECHARGE_DAY:
		{
			if (g_switch_mgr.IsSwitchEnabled(SWITCH_RECHARGE))
			{
				LOG_DEBUG("Get every day recharge get= %d",msg->GiftType);
				lua::call(lua::L, "Gift.GetRechargeDayGift", player,msg->GiftType);
				ret = lua::getinteger(1);
			}
			else
			{
				ret = ERROR_FEATURES_NOT_OPEN;
			}
		}
		break;
	case GIFT_RECHARGE_MONTH:
		{
			LOG_DEBUG("Get every month recharge get = %d",msg->GiftType);
			lua::call(lua::L, "Gift.GetRechargeMonthGift", player);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_SIGN_UP:
		{
			LOG_DEBUG("get gift sign in package");
			lua::call(lua::L, "Gift.getSignUpGift", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_WEEK_SIGN_IN:
		{
			LOG_DEBUG("get gift week sign in package");
			lua::call(lua::L, "Gift.getWeekSignUpGift", player);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_WEEK:
		{
			LOG_DEBUG("Get gift week package");
			lua::call(lua::L, "Gift.getLastWeekFlee", player);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_ONLINE_GOLD:
		{
			LOG_DEBUG("Get gift week online gold");
			lua::call(lua::L, "Gift.getLastWeekGold", player);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_QMBS_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation boss");
			lua::call(lua::L, "Gift.getKfhdQmbsReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_JSCJ_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation jscj");
			lua::call(lua::L, "Gift.getKfhdJscjReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_CBCJ_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation cbcj");
			lua::call(lua::L, "Gift.getKfhdCbcjReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_HZCJ_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation hzcj");
			lua::call(lua::L, "Gift.getKfhdHzcjReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_BSCJ_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation bscj");
			lua::call(lua::L, "Gift.getKfhdBscjReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_7DAY_RECEIVE:
		{
			LOG_DEBUG("Get gift open operation 7day");
			lua::call(lua::L, "Gift.getKfhd7dayReward", player, msg->GiftType);
			ret = lua::getinteger(1);
		}
		break;
	case GIFT_KFHD_7DAY_SIGN_IN:
		{
			LOG_DEBUG("Get gift open operation 7day sign in");
			lua::call(lua::L, "Gift.getKfhd7daySignIn", player);
			ret = lua::getinteger(1);
			return;
		}
		break;
	case GIFT_KFHD_COMMENT:
		{
			LOG_DEBUG("Get gift open appstore comment");
			lua::call(lua::L, "Gift.getKfhdAppStoreComment", player,msg->GiftType);
			ret = lua::getinteger(1);
			return;
		}
		break;
	case GIFT_KFHD_XFDB:
		{
			LOG_DEBUG("Get gift open xfdb");
			lua::call(lua::L, "Gift.getKfhdXfdbReward", player,msg->GiftType, player->getPlayerID());
			ret = lua::getinteger(1);
			return;
		}
		break;
	case GIFT_KFHD_SCCZFL:
		{
			LOG_DEBUG("Get gift open xfdb");
			lua::call(lua::L, "Gift.getKfhdScczflReward", player,msg->GiftType);
			ret = lua::getinteger(1);
			return;
		}
		break;
	default:
		break;
	}

	if  (ret == SUCCESS)
	{
		ret = ERROR_GET_GIFT_SUCCESS;
	}

	MsgGetGiftResponse *response = new MsgGetGiftResponse;
	response->errcode = ret;
	response->GiftCate = msg->GiftCate;
	response->GiftType = msg->GiftType;
	response->setSessionID(msg->getSessionID());
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onFuncDataOperator(Message *message)
{
	MsgFuncDataOperatorRequest *msg = dynamic_cast<MsgFuncDataOperatorRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = EntityOperationHelper::doFuncScript(*player,
		msg->funcid, msg->datax, msg->datay, msg->dataz,msg->datas);

	MsgFuncDataOperatorResponse *response = new MsgFuncDataOperatorResponse;
	response->errcode = ret;
	response->funcid = msg->funcid;
	response->datax = msg->datax;
	response->datay = msg->datay;
	response->dataz = msg->dataz;
	response->datas = msg->datas;
	response->setSessionID(msg->getSessionID());
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onOpenHeadTitleRequest(Message *message)
{
	
}

void PlayerMsgHandler::onCloseHeadTitleRequest(Message *message)
{
	
}

void PlayerMsgHandler::onRenameRequest(Message *message)
{
	MsgRenameRequest *msg = dynamic_cast<MsgRenameRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	if (msg->type == 0)
	{
		if(lua::call(lua::L, "Entity.checkUsePlayerRenameCard", player))
		{
			ret = lua::getinteger(1);
		}

		if(ret != SUCCESS)
		{
			return;
		}

		//玩家改名
		ret = EntityOperationHelper::renamePlayer(*player, msg->newname, msg->flags);
	}
	else if(msg->type == 1)
	{
		if(lua::call(lua::L, "Entity.checkUsePlayerRenameCard", player))
		{
			ret = lua::getinteger(1);
		}
		if(ret != SUCCESS)
		{
			return;
		}

		//玩家变性
		ret = EntityOperationHelper::changeGenderPlayer(*player);
	}
	else
	{
		if(lua::call(lua::L, "Entity.checkUseGuildRenameCard", player))
		{
			ret = lua::getinteger(1);
		}

		if(ret != SUCCESS)
		{
			return;
		}

		//行会改名
		ret = GuildHelper::renameGuild(player, msg->newname);
	}

	// 这不是最后一步，需要数据库操作完成才算成功
	if (ret != SUCCESS)
	{
		MsgRenameResponse *response = new MsgRenameResponse;
		response->errcode = ret;
		response->type = msg->type;
		response->setSessionID(msg->getSessionID());
		g_app.postToNetService(response);
	}
}

void PlayerMsgHandler::onDBGenderResponse(Message *message)
{
	MsgDBUpdatePlayerGender *msg = dynamic_cast<MsgDBUpdatePlayerGender*>(message);

		if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	if (msg->getErrcode() == SUCCESS)
	{
		int ret = EntityOperationHelper::changeGenderResponse(*player, msg->gender);
		if(ret == SUCCESS)
		{
			int needCount = 0;
			lua::call(lua::L, "NPC.mdsAssistCheck",1);
			needCount = lua::getinteger(1);
			EntityOperationHelper::useIngot(*player, needCount, OP_ASSIST,1);

		}

		MsgRenameResponse* cf = new MsgRenameResponse;
		cf->errcode = ret;
		cf->type = 1;
		cf->setSessionID(msg->getSessionID());
		g_app.postToNetService(cf);
		return;
	}

	MsgRenameResponse* cf = new MsgRenameResponse;
	cf->errcode = ERROR_NAME_EXIST;
	cf->type = 1;
	cf->setSessionID(msg->getSessionID());
	g_app.postToNetService(cf);


}


void PlayerMsgHandler::onDBRenameResponse(Message *message)
{
	MsgDBUpdatePlayerName *msg = dynamic_cast<MsgDBUpdatePlayerName*>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if ((player == NULL) || (player->getPlayerID() != msg->pid))
	{
		return;
	}

	if (msg->getErrcode() == SUCCESS)
	{
		int ret = EntityOperationHelper::renameResponse(*player, msg->name, msg->flags);
		if(ret == SUCCESS)
		{
			ItemOperationHelper::deleteItem(*player, 80009, 1);
		}

		MsgRenameResponse* cf = new MsgRenameResponse;
		cf->errcode = ret;
		cf->type = 0;
		cf->setSessionID(msg->getSessionID());
		g_app.postToNetService(cf);


		//通知后台角色更名
		MsgPlayerCreateDeleteNotify *notify = new MsgPlayerCreateDeleteNotify;
		notify->aid = player->getProp(ENTITY_PROP_ACCOUNT_ID);
		notify->channelId = player->getProp(ENTITY_PROP_CHANNEL_ID);
		notify->deviceId = player->getProp(ENTITY_PROP_DEVICE_ID);
		notify->platformId = player->getProp(ENTITY_PROP_PLATFORM_ID);
		notify->name = msg->name;
		notify->pid = msg->pid;
		notify->serverId = player->getProp(ENTITY_PROP_SERVER_ID);
		notify->time = get_time();
		notify->career = player->getClass();
		notify->type = 3;
		g_app.postToNetService(notify);
		return;
	}

	MsgRenameResponse* cf = new MsgRenameResponse;
	cf->errcode = ERROR_NAME_EXIST;
	cf->type = 0;
	cf->setSessionID(msg->getSessionID());
	g_app.postToNetService(cf);
}

// 查看玩家装备
void PlayerMsgHandler::onCheckEquipRequest(Message *message)
{
	MsgCheckEquipRequest* msg = dynamic_cast<MsgCheckEquipRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int lastCheckTime = player->getProp(ENTITY_PROP_OTHER_INFO_GET_CD);
	if ((time(nullptr) - lastCheckTime) < 3 )
	{
		EntityOperationHelper::sendShowPrompt(*player,1,1364,std::vector<std::string>());
		return;
	}
	player->setProp(ENTITY_PROP_OTHER_INFO_GET_CD,(int)time(nullptr));
	EntityOperationHelper::saveEntityProp(*player,ENTITY_PROP_OTHER_INFO_GET_CD);

	//跨服角色 向跨服发送消息 
	if(msg->serverid != 0 && msg->serverid != g_world.getID())
	{
		MsgGetPlayerEquipInfoRequest* req = new MsgGetPlayerEquipInfoRequest();
		req->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));  //战区服务器id
		req->setSourceSessionID(msg->serverid);  //目标游戏服id
		req->srcPid = player->getPlayerID();
		req->targetPid = msg->pid;
		req->srcServerid= g_world.getID();
		g_app.postToNetService(req);
		return;
	}
	
	EntityPlayer* target = nullptr;
	if (msg->pid < 0)
	{
		target = g_world_player_mgr.getRobotByrobotID(msg->pid);
	}
	else
	{
		target = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	}
	if (nullptr == target)
	{
		MsgDBLoadOtherPlayerInfo* req = new MsgDBLoadOtherPlayerInfo;
		req->pid = msg->pid;
		req->setSessionID(msg->getSessionID());
		g_app.postToNetService(req);

		return;
	}

	EntityOperationHelper::sendOtherPlayerInfo(player, target);
}

// 查看魂石
void PlayerMsgHandler::onCheckSoulStoneRequest(Message *message)
{
	MsgCheckSoulStoneRequest* msg = dynamic_cast<MsgCheckSoulStoneRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgCheckSoulStoneResponse* res = new MsgCheckSoulStoneResponse;

	EntityPlayer* target = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (NULL == target)
	{
		res->errcode = ERROR_PLAYER_IS_OFFLINE;
		player->sendMessage(res);
		return;
	}

	int max_soul = 5;

	// 魂石开始部位
	int beginpos = msg->pos;
	/*
	if (beginpos >= BAG_POS_SETTING_BEGIN || (beginpos + max_soul) < BAG_POS_SETTING_END)
	{
		res->errcode = ERROR_UNKNOWN;
		player->sendMessage(res);
		return;
	}*/

	// 取对应位置魂石
	for (int i = 0; i < max_soul; ++i)
	{
		int pos = beginpos - i;

		Item* item = ItemOperationHelper::getItemByPosition(*target, pos);
		if (item)
		{
			res->vsoul.push_back(item->getStaticID());
		}
		else
		{
			res->vsoul.push_back(0);
		}
	}

	res->pid = msg->pid;
	res->pos = msg->pos;

	player->sendMessage(res);
}

// 请求活动数据
void PlayerMsgHandler::onEventDataRequest(Message *message)
{
	MsgEventDataRequest* msg = dynamic_cast<MsgEventDataRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int event_id = msg->id;

	EntityOperationHelper::syncEntityEventData(*player, event_id);
}


//领取离线经验
// type 类型 占时不用 后期在加
void PlayerMsgHandler::onGetOfflineExp(Message *message)
{
	
}

void PlayerMsgHandler::onExerciseRequest(Message *message)
{
	MsgExerciseRequest *msg = dynamic_cast<MsgExerciseRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgExerciseResponse* er = new MsgExerciseResponse();
	er->errcode = SUCCESS;
	er->level = player->getProp(ENTITY_PROP_EXERCISE_LV);
	er->curExercise = EntityOperationHelper::getPlayerExerciseExp(*player);
	er->setSessionID(player->getSessionID());
	g_app.postToNetService(er);
}


void PlayerMsgHandler::onOpenWingsRequest( Message* message )
{
	
}

void PlayerMsgHandler::onUpdataWingsRequest( Message* message )
{
	MsgUpdataWingsRequest *msg = dynamic_cast<MsgUpdataWingsRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	lua::call(lua::L, "Entity.upgradeWing", player);
	ret = lua::getinteger(1);

	MsgUpdataWingsResponse *rsp = new MsgUpdataWingsResponse();
	rsp->errcode = ret;
	rsp->setSessionID(player->getSessionID());
	g_app.postToNetService(rsp);
}

void PlayerMsgHandler::onChangeWingDressRequest(Message* message)
{
	
}

void PlayerMsgHandler::onImproveWingRequest(Message* message)
{
	MsgImproveWingRequest *msg = dynamic_cast<MsgImproveWingRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	lua::call(lua::L, "Entity.improveWing", player, msg->index);
	ret = lua::getinteger(1);

	MsgImproveWingResponse *rsp = new MsgImproveWingResponse();
	rsp->errcode = ret;
	rsp->setSessionID(player->getSessionID());
	g_app.postToNetService(rsp);
}

void PlayerMsgHandler::onUpdataBossScoreRequest( Message* message )
{
	MsgUpdataBossScoreRequest *msg = dynamic_cast<MsgUpdataBossScoreRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	if(player->getLevel() < 80 )
	{
		return;
	}

	int ret = SUCCESS;
	lua::call(lua::L, "Entity.updataBossLvPoint", player, msg->level);
	ret = lua::getinteger(1);

	if(ret == SUCCESS)
	{
		EntityOperationHelper::syncPlayerCombatCombo( *player );
	}

	MsgUpdataBossScoreResponse* bs = new MsgUpdataBossScoreResponse();
	bs->errcode = ret;
	bs->setSessionID(player->getSessionID());
	g_app.postToNetService(bs);

}

void PlayerMsgHandler::onUpdataBsscCnRequest( Message* message )
{
	MsgUpdataBsscCnRequest *msg = dynamic_cast<MsgUpdataBsscCnRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	
	if(player->getLevel() < 80 )
	{
		return;
	}

	int ret = SUCCESS;
	lua::call(lua::L, "Entity.bossLvToScore", player);
	ret = lua::getinteger(1);


	MsgUpdataBsscCnResponse* bs = new MsgUpdataBsscCnResponse();
	bs->errcode = ret;
	bs->setSessionID(player->getSessionID());
	g_app.postToNetService(bs);

}

void PlayerMsgHandler::onOpenAutoAtkMapRequest( Message* message )
{
	
	MsgOpenAutoAtkMapRequest *msg = dynamic_cast<MsgOpenAutoAtkMapRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	lua::call(lua::L, "Entity.openAutoAtkMap", player , msg->sceneId);
	ret = lua::getinteger(1);

	MsgOpenAutoAtkMapResponse* op = new MsgOpenAutoAtkMapResponse();
	op->errcode = ret;
	op->setSessionID(player->getSessionID());
	g_app.postToNetService(op);

}

void PlayerMsgHandler::onStartOffLineRequest( Message* message )
{
	MsgStartOffLineRequest *msg = dynamic_cast<MsgStartOffLineRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	player->setProp( ENTITY_PROP_OFFLINE_SID , msg->sid );
	EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_OFFLINE_SID);

	EntityOperationHelper::addGene(*player, 401001);

	MsgStartOffLineResponse* so = new MsgStartOffLineResponse();
	so->errcode = SUCCESS;
	so->sid = msg->sid;
	so->setSessionID(player->getSessionID());
	g_app.postToNetService(so);

}

void PlayerMsgHandler::onOfflineTakeRewardRequest( Message* message )
{
	
}

void PlayerMsgHandler::onOfflineVipRewardRequest( Message* message )
{
	MsgOfflineVipRewardRequest *msg = dynamic_cast<MsgOfflineVipRewardRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgOfflineVipRewardResponse* ov = new MsgOfflineVipRewardResponse();
	ov->errcode = SUCCESS;
	ov->setSessionID(player->getSessionID());
	g_app.postToNetService(ov);

}

void PlayerMsgHandler::onOpenOffLineRequest( Message* message )
{
	
}

void PlayerMsgHandler::onCloseOffLineRequest( Message* message )
{
	
}

void PlayerMsgHandler::onGetVipExpBuffRequest( Message* message)
{
	MsgGetVipExpBuffRequest *msg = dynamic_cast<MsgGetVipExpBuffRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	lua::call(lua::L, "Vip.GetVipExpBuff", player);
	ret = lua::getinteger(1);

	MsgGetVipExpBuffResponse* op = new MsgGetVipExpBuffResponse();
	op->errcode = ret;
	op->setSessionID(player->getSessionID());
	g_app.postToNetService(op);
}

void PlayerMsgHandler::onRefreshEventDataRequest(Message* message)
{
	MsgRefreshEventDataRequest *msg = dynamic_cast<MsgRefreshEventDataRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	EventData* datax = player->getEventData(msg->eid);
	EntityOperationHelper::syncEntityEventData(*player,msg->eid);

	MsgRefreshEventDataResponse* red = new MsgRefreshEventDataResponse();
	red->errcode = SUCCESS;
	red->setSessionID(player->getSessionID());
	g_app.postToNetService(red);
}

//五星好评
void PlayerMsgHandler::onDBCheckAppStoreCommentRewarded(Message* message)
{
	MsgDBCheckAppStoreCommentRewarded* msg = dynamic_cast<MsgDBCheckAppStoreCommentRewarded*>(message);
	if(!msg)
	{
		return;
	}

	if (msg->getErrcode() != SUCCESS)
	{
		return;
	}

	EntityPlayer *player = player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);

	lua::call(lua::L, "Gift.sendAppStoreCommentReward", msg->pid);
}

//离线收入
void PlayerMsgHandler::onDBLoadIncome(Message* message)
{
	MsgDBLoadIncome *msg = dynamic_cast<MsgDBLoadIncome*>(message);
	if (msg == nullptr)
	{
		return;
	}

	if (msg->getErrcode() != SUCCESS)
	{
		return;
	}

	EntityPlayer *player = player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if (player == nullptr || player->getProp(ENTITY_PROP_IN_GAME) != 1)
	{
		return;
	}

	int old_opcode = OperationHelper::getOpCode();

	for (size_t i = 0; i < msg->items.size(); ++i)
	{
		DBIncome &income = msg->items[i];

		OperationHelper::setOpCode(income.opcode);

		int ret = SUCCESS;

		switch (income.sid)
		{
		case ITEM_EXP:
			ret = EntityOperationHelper::addExp(*player, income.count, 0, income.data);
			break;
		case ITEM_LINGFU:
			ret = EntityOperationHelper::addIngot(*player, income.count, 0, income.data);
			break;
		case ITEM_INGOT:
			ret = EntityOperationHelper::addIngot(*player, income.count, 0, income.data);
			break;
		case ITEM_BIND_INGOT:
			ret = EntityOperationHelper::addBoundIngot(*player, income.count, 0, income.data);
			break;
		default:
			income.bind = ItemOperationHelper::getBindState(income.sid, ITEM_BIND_STATE_UNBOUND);

			int ret = ItemOperationHelper::canAddItem(*player, income.sid, income.count, income.bind, BAG_TYPE_PLAYER);
			if (ret == SUCCESS)
			{
				ret = ItemOperationHelper::addItem(*player, income.sid, income.count, income.bind, BAG_TYPE_PLAYER);
				if (ret == SUCCESS)
				{
					Item *item = ItemOperationHelper::getItemAddedLast(*player);
					if (item != nullptr)
					{
						for (size_t j = 0; j < msg->props.size(); ++j)
						{
							DBIncomeProp &dbprop = msg->props[j];

							if (dbprop.pid != player->getGlobalID() || dbprop.iid != income.iid)
							{
								continue;
							}

							item->setProp(dbprop.idx, dbprop.data);

							ItemOperationHelper::saveItemProp(*player, item, dbprop.idx);
							ItemOperationHelper::syncItemProp(*player, item, dbprop.idx);
						}
					}
				}
			}
		}

		if (ret == SUCCESS)
		{
			MsgDBDeleteIncome *dbmsg = new MsgDBDeleteIncome;
			dbmsg->pid = player->getGlobalID();
			dbmsg->iid = income.iid;
			g_app.postToNetService(dbmsg);
		}
	}

	OperationHelper::setOpCode(old_opcode);
}

void PlayerMsgHandler::onGetLevelRewardRequest(Message* message)
{
	MsgGetLevelRewardRequest *msg = dynamic_cast<MsgGetLevelRewardRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgGetLevelRewardResponse* rsp = new MsgGetLevelRewardResponse();
	rsp->errcode = SUCCESS;
	rsp->id = msg->id;
	rsp->setSessionID(player->getSessionID());
	g_app.postToNetService(rsp);
}

void PlayerMsgHandler::onOpenSpecialRingRequest(Message* message)
{

	MsgOpenSpecialRingRequest *msg = dynamic_cast<MsgOpenSpecialRingRequest *>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
}

void PlayerMsgHandler::onAskForRewardRequest(Message* message)
{

	MsgAskForRewardRequest *msg = dynamic_cast<MsgAskForRewardRequest *>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}


	if(lua::call(lua::L, "Entity.onAskForRewardRequest",player))
	{
		return;
	}
}

void PlayerMsgHandler::onTTSYGuWuRequest(Message* message)
{
	MsgTTSYGuWuRequest *msg = dynamic_cast<MsgTTSYGuWuRequest *>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}


	if(lua::call(lua::L, "Entity.onTTSYGuWuRequest",player, msg->index))
	{
		int ret = lua::getinteger(1);
		int per = lua::getinteger(2);

		MsgTTSYGuWuResponse *resposnse = new MsgTTSYGuWuResponse;
		resposnse->errcode = ret;
		resposnse->index = msg->index;
		player->sendMessage(resposnse);
		return;
	} 

	

}

void PlayerMsgHandler::onMsgPlayerLvChangeCultRequest( Message* message)
{
	MsgPlayerLvChangeCultRequest *msg = dynamic_cast<MsgPlayerLvChangeCultRequest *>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	int day = player->getProp(ENTITY_PROP_REBORN_CONV_DAY);
	time_t curtime =  get_time();
	tm tim = *localtime(&curtime); 
	int mday = tim.tm_mday;

	if(mday != day)
	{
		player->setProp(ENTITY_PROP_REBORN_CONV_DAY , mday);
		player->setProp(ENTITY_PROP_REBORN_CONV_CNT , 3);
		EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_REBORN_CONV_DAY);
		EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_REBORN_CONV_CNT);
		EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_REBORN_CONV_DAY);
		EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_REBORN_CONV_CNT);
	}

	if(lua::call(lua::L, "Entity.playerLvChangeCult", player))
	{
		ret = lua::getinteger(1);
	}
	
	MsgPlayerLvChangeCultResponse *msgg = new MsgPlayerLvChangeCultResponse;
	msgg->errcode = ret;
	player->sendMessage(msgg);
}

// 升级魂石
void PlayerMsgHandler::onStonePosRequest(Message *message)
{
	MsgStonePosRequest *msg = dynamic_cast<MsgStonePosRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	OperationHelper::setOpCode(OP_GHOST_STONE);

	int ret = ERROR_SCRIPT;	
	
	unsigned int s_value = player->getProp(msg->partpos);
	int one		=	s_value & 0xf;
	int two		= (	s_value & 0xf0		)>> 4;
	int three	= (	s_value & 0xf00		)>> 8;
	int four	= (	s_value & 0xf000	)>> 12;
	int five	= (	s_value & 0xf0000	) >> 16;
	int six		= (	s_value & 0xf00000	) >> 20;


	if (lua::call(lua::L, "Entity.ghoststone", player, msg->typeId,msg->partpos, msg->stonepos,one,two,three,four,five,six))
	{
		ret = lua::getinteger(1);
	}

	MsgStonePosResponse *response = new MsgStonePosResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;
	response->partpos = msg->partpos;
	response->stonepos = msg->stonepos;
	g_app.postToNetService(response);

	// 通知服务器其他模块
	if (ret != SUCCESS)
	{
		return;
	}
}

//强化部位
void PlayerMsgHandler::onEnhancePosRequest(Message *message)
{
	
}

void PlayerMsgHandler::onFulingRequest(Message *message)
{
	
}

void PlayerMsgHandler::onFulingZYRequest(Message *message)
{
	
}

void PlayerMsgHandler::onPlayerDressOperatorRequest(Message *message)
{
	
}

void PlayerMsgHandler::onPlayerDressWardrobeUpRequest(Message *message)
{
	
}

void PlayerMsgHandler::onSetDressStatusRequest(Message *message)
{
	
}

void PlayerMsgHandler::onExchangeSkillBookRequest(Message *message)
{
	MsgExchangeSkillBookRequest *msg = dynamic_cast<MsgExchangeSkillBookRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if (lua::call(lua::L, "Entity.ExchangeSkillBook", player, msg->exchageType ,msg->exchageId))
	{
		ret = lua::getinteger(1);
	}

	MsgExchangeSkillBookResponse *response = new MsgExchangeSkillBookResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;
	response->exchageType = msg->exchageType;
	response->exchageId =msg->exchageId;

	g_app.postToNetService(response);
}

//强化部位
void PlayerMsgHandler::onUpdateCSPosRequest(Message *message)
{
	MsgUpdateCSRequest *msg = dynamic_cast<MsgUpdateCSRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	OperationHelper::setOpCode(OP_CHUANSHI);

	// 操作对象类型
	int nEntityType = ENTITY_TYPE_PLAYER;

	int ret = ERROR_SCRIPT;
	int careerId = player->getClass();
	if (lua::call(lua::L, "Entity.updateCSEquip", player, msg->typeId, msg->pos, careerId))
	{
		ret = lua::getinteger(1);
	}

	MsgUpdateCSResponse *response = new MsgUpdateCSResponse;
	response->setSessionID(msg->getSessionID());
	response->typeId = msg->typeId;
	response->pos = msg->pos;
	response->errcode = ret;
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onGetMasterRewardRequest(Message *message)
{
	MsgGetMasterRewardRequest *msg = dynamic_cast<MsgGetMasterRewardRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	//领取每日达人奖励
	if(lua::call(lua::L, "Entity.onGetMasterReward",player, msg->index))
	{
		ret = lua::getinteger(1);
	}

	MsgGetMasterRewardResponse *response = new MsgGetMasterRewardResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);

}

//开启特权
void PlayerMsgHandler::onOpenPrivilegeRequest(Message *message)
{
	MsgOpenPrivilegeRequest *msg = dynamic_cast<MsgOpenPrivilegeRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	
	if(lua::call(lua::L, "Entity.onOpenPrivilege",player, msg->index))
	{
		ret = lua::getinteger(1);
	}

	MsgOpenPrivilegeResponse *response = new MsgOpenPrivilegeResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);

}

//领取特权奖励特权
void PlayerMsgHandler::onGetPrivilegeRewardRequest(Message *message)
{
	MsgGetPrivilegeRewardRequest *msg = dynamic_cast<MsgGetPrivilegeRewardRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	
	if(lua::call(lua::L, "Entity.onGetPrivilegeReward",player, msg->index))
	{
		ret = lua::getinteger(1);
	}

	MsgGetPrivilegeRewardResponse *response = new MsgGetPrivilegeRewardResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);

}

//特权续费
void PlayerMsgHandler::onRenewPrivilegeRequest(Message *message)
{
	MsgRenewPrivilegeRequest *msg = dynamic_cast<MsgRenewPrivilegeRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	
	if(lua::call(lua::L, "Entity.onRenewPrivilege",player, msg->index))
	{
		ret = lua::getinteger(1);
	}

	MsgRenewPrivilegeResponse *response = new MsgRenewPrivilegeResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);
}

void PlayerMsgHandler::onUpdateShopGuideRequest(Message *message)
{
	MsgUpdateShopGuideRequest *msg = dynamic_cast<MsgUpdateShopGuideRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	player->setProp(ENTITY_PROP_GUIDE_BUY_OPEN, 2);
	EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_GUIDE_BUY_OPEN);
	EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_GUIDE_BUY_OPEN);
}

void PlayerMsgHandler::onUpdateXSRWTaskStateRequest(Message *message)
{
	MsgUpdateXSRWTaskStateRequest *msg = dynamic_cast<MsgUpdateXSRWTaskStateRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	int ret = SUCCESS;

	player->setProp(ENTITY_PROP_XSRW_IS_ACTIVE, 2);
	EntityOperationHelper::saveEntityProp(*player, ENTITY_PROP_XSRW_IS_ACTIVE);
	EntityOperationHelper::syncEntityProp(*player, ENTITY_PROP_XSRW_IS_ACTIVE);

	if(lua::call(lua::L, "Event.timeTaskInit",player))  //初始化限时任务
	{
		ret = lua::getinteger(1);
	}

	if(lua::call(lua::L, "Event.timeTaskStart",player))  //开始限时任务
	{
		ret = lua::getinteger(1);
	}

	if (ret != SUCCESS)
	{
		MsgUpdateXSRWTaskStateResponse *response = new MsgUpdateXSRWTaskStateResponse;
		response->setSessionID(msg->getSessionID());
		response->errcode = ret;
		g_app.postToNetService(response);
	}	
}

//爬塔
void PlayerMsgHandler::onChallengeTowerRequest(Message *message)
{
	MsgOnChallengeTowerRequest *msg = dynamic_cast<MsgOnChallengeTowerRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	
	if(lua::call(lua::L, "Entity.onChallengeTower",player, msg->index))
	{
		ret = lua::getinteger(1);
	}

	MsgOnChallengeTowerResponse *response = new MsgOnChallengeTowerResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);
}

//爬塔奖励
void PlayerMsgHandler::onGetTowerRewardRequest(Message *message)
{
	MsgGetTowerRewardRequest *msg = dynamic_cast<MsgGetTowerRewardRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.onGetTowerReward",player))
	{
		//ret = lua::getinteger(1);
	}
}

//购买每日特惠
//爬塔奖励
void PlayerMsgHandler::onBuyDailyItemRequest(Message *message)
{
	MsgBuyDailyItemRequest *msg = dynamic_cast<MsgBuyDailyItemRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.onBuyDailyItem",player,msg->bigindex,msg->smallindex))
	{
		ret = lua::getinteger(1);
	}

	MsgBuyDailyItemResponse *response = new MsgBuyDailyItemResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;

	g_app.postToNetService(response);
}

void PlayerMsgHandler::onCalcMyBossTimesRequest(Message *message)
{
	MsgCalcMyBossTimesRequest *msg = dynamic_cast<MsgCalcMyBossTimesRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.calcMyBossTimes", player, msg->eventid))
	{
		ret = lua::getinteger(1);
	}

	MsgCalcMyBossTimesResponse *response = new MsgCalcMyBossTimesResponse;
	response->errcode = ret;
	player->sendMessage(response);
}

//扫荡
void PlayerMsgHandler::onGetTowerSweepRequest(Message *message)
{
	MsgGetTowerSweepRequest *msg = dynamic_cast<MsgGetTowerSweepRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}


	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.onTowerSweep",player))
	{
		ret = lua::getinteger(1);
	}

	MsgGetTowerSweepResponse *response = new MsgGetTowerSweepResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;
	g_app.postToNetService(response);
}

//挖宝箱
void PlayerMsgHandler::onBossBoxDigRequest( Message *message )
{
	MsgBossBoxDigRequest *msg = dynamic_cast<MsgBossBoxDigRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Entity.finishBossgether",player, msg->eid))
	{
		ret = lua::getinteger(1);
	}

	MsgBossBoxDigResponse *response = new MsgBossBoxDigResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;
	g_app.postToNetService(response);

}

void PlayerMsgHandler::onGetBailRequest( Message *message )
{
	MsgBailRequest *msg = dynamic_cast<MsgBailRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	int sub_type = 0;
	if(lua::call(lua::L, "Entity.bailForPK",player, msg->money_type))
	{
		ret = lua::getinteger(1);
		sub_type = lua::getinteger(2);
	}

	MsgBailResponse *response = new MsgBailResponse;
	response->setSessionID(msg->getSessionID());
	response->errcode = ret;
	response->sub_type = sub_type;
	g_app.postToNetService(response);
}


void PlayerMsgHandler::onUpdateComposeStateRequest(Message *message)
{
	MsgUpdateComposeStateRequest *msg = dynamic_cast<MsgUpdateComposeStateRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int propType = ENTITY_PROP_COMPOSE_STATE;
	if (msg->mode == 2)
	{
		propType = ENTITY_PROP_COMPOSE_STATE_S;
	}
	player->setProp(propType, 1);
	EntityOperationHelper::saveEntityProp(*player, propType);
	EntityOperationHelper::syncEntityProp(*player, propType);


}


void PlayerMsgHandler::onVipServiceShowCheckRequest(Message *message)
{
	MsgVipServiceShowCheckRequest *msg = dynamic_cast<MsgVipServiceShowCheckRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int propType = ENTITY_PROP_VIP_SERVICE_SHOW;
	
	player->setProp(propType, msg->showflag);
	EntityOperationHelper::saveEntityProp(*player, propType);
	EntityOperationHelper::syncEntityProp(*player, propType);


}

//附近玩家

void PlayerMsgHandler::onNearbyPlayerRequest(Message *message)
{
	MsgNearbyPlayerRequest *msg = dynamic_cast<MsgNearbyPlayerRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	Scene *scene = player->getScene();
	if (scene == NULL)
	{
		return;
	}

	std::vector<NearPlayerInfo> pinfoVec;
	scene->for_each_in_grid_around(player->getGridX(), player->getGridY(), ENTITY_SCOPE_PLAYER, [&pinfoVec,&player](Entity *entity){
		if (entity)
		{
			int ret = 0 ;
			if(lua::call(lua::L, "Entity.nearByPlayer", player, entity))
			{
				ret = lua::getinteger(1);
			}
			if(ret ==1 ){
				int32 x1 = player->getPositionX() ;
				int32 y1 = player->getPositionY();
				int32 x2 = entity->getPositionX() ;
				int32 y2 = entity->getPositionY();
				int32 distance = (int)pow((x1-x2),2)+(int)pow((y1-y2),2);
				NearPlayerInfo pinfo ;
				pinfo.pid = entity->getGlobalID();
				pinfo.name = entity->getName();
				pinfo.level = entity->getLevel();
				pinfo.reborn = entity->getProp(ENTITY_PROP_REBORN);
				pinfo.distance = distance;
				pinfoVec.push_back(pinfo);
			}
		}
	});

	//排序

	std::sort(pinfoVec.begin(), pinfoVec.end(), [](const NearPlayerInfo &p1,const NearPlayerInfo &p2){
		return (p1.distance < p2.distance);
	});

	MsgNearbyPlayerResponse *response = new MsgNearbyPlayerResponse;
	if(pinfoVec.size() > 20 )
	{
		std::vector<NearPlayerInfo> pinfoVec2(20);
		std::copy(pinfoVec.begin(),pinfoVec.begin()+20,pinfoVec2.begin());
		response->playerlist = pinfoVec2;
	}else
	{
		response->playerlist = pinfoVec;
	}
	player->sendMessage(response);
	//pinfoVec;
}


void PlayerMsgHandler::onNearbyPlayerCheckRequest(Message *message){

	MsgNearbyPlayerCheckRequest *msg = dynamic_cast<MsgNearbyPlayerCheckRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	Scene *scene = player->getScene();
	if (scene == NULL)
	{
		return;
	}
	int ret = 1 ;
	EntityPlayer *entity = scene->getPlayer(msg->pid);
	if (entity == NULL)
	{
		LOG_WARN("cannot find entity, entity id is ", msg->pid);
	}
	else
	{
		int x = abs(player->getGridX() - entity->getGridX());
		int y = abs(player->getGridY() - entity->getGridY());
		if (x > 1 || y >1)
		{
			ret = 4;
		}
		else if(lua::call(lua::L, "Entity.checkNearByPlayer", player , entity))
		{
			ret = lua::getinteger(1);
		}
	}
	MsgNearbyCheckPlayerResponse *rsp =  new MsgNearbyCheckPlayerResponse;
	rsp->repcode = ret ;
	rsp->reppid = msg->pid;
	player->sendMessage(rsp);
}


void PlayerMsgHandler::onCreateRoleCodeRequest( Message* message )
{
	MsgCreateRoleCodeRequest* msg = dynamic_cast<MsgCreateRoleCodeRequest*>(message);
	if(!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//TODO 申请邀请码 
	int ret = SUCCESS;
	lua::call(lua::L, "Entity.CreateRoleCodeAdd", player, player->getPlayerID());
	ret =  lua::getinteger(1);
	std::string code =  lua::getstring(2);

	//邀请码
	MsgCreateRoleCodeResponse *re = new MsgCreateRoleCodeResponse;
	re->errcode = ret;
	re->code = code;
	re->setSessionID(msg->getSessionID());
	g_app.postToNetService(re);
}

void PlayerMsgHandler::onCreateRoleCodeInfoRequest( Message* message )
{
	MsgCreateRoleCodeInfoRequest* msg = dynamic_cast<MsgCreateRoleCodeInfoRequest*>(message);
	if(!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//TODO 返回当前玩家已经用掉的邀请码数量，返回当前玩家未使用的邀请码
	int count = 0;
	std::string code = "";
	lua::call(lua::L, "Entity.GetCreateRoleCodeInfo", player->getPlayerID());
	count =  lua::getinteger(1);
	code =  lua::getstring(2);

	//邀请码信息
	MsgCreateRoleCodeInfoResponse *re = new MsgCreateRoleCodeInfoResponse;
	re->count = count;
	re->code = code;
	re->setSessionID(msg->getSessionID());
	g_app.postToNetService(re);
}

void PlayerMsgHandler::onAskforSoulSystemInfoRequest(Message *message){

	MsgAskforSoulSystemInfoRequest *msg = dynamic_cast<MsgAskforSoulSystemInfoRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgAskforSoulSystemInfoRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;
	
	if(lua::call(lua::L, "SoulSys.syncInfo", player))
	{
		ret = lua::getinteger(1);
	}

	MsgAskforSoulSystemInfoResponse *rsp = new MsgAskforSoulSystemInfoResponse;
	rsp->errcode = ret;
	player->sendMessage(rsp);

}

void PlayerMsgHandler::onImproveSoul(Message *message){

	MsgImproveSoulRequest *msg = dynamic_cast<MsgImproveSoulRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgImproveSoulRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	short ret = SUCCESS;
	short type = 0;
	bool levelUp = false;
	bool gradeUp = false;

	if(lua::call(lua::L, "SoulSys.improve", player))
	{
		ret = lua::getinteger(1);
		if(ret == SUCCESS)
		{
			type = lua::getinteger(2);
			levelUp = lua::getboolean(3);
			gradeUp = lua::getboolean(4);
		}
	}

	MsgImproveSoulResponse *rsp = new MsgImproveSoulResponse;
	rsp->type = type;
	rsp->levelUp = levelUp ? 1 : 0;
	rsp->gradeUp = gradeUp ? 1 : 0;
	rsp->errcode = ret;
	player->sendMessage(rsp);

}

void PlayerMsgHandler::onExchangeSoulRequest(Message *message){

	MsgExchangeSoulRequest *msg = dynamic_cast<MsgExchangeSoulRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgExchangeSoulRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	if(lua::call(lua::L, "SoulSys.exchangeSoul", player))
	{
		ret = lua::getinteger(1);
	}

	MsgExchangeSoulResponse *rsp = new MsgExchangeSoulResponse;
	rsp->errcode = ret;
	player->sendMessage(rsp);

}


//

void PlayerMsgHandler::onUpdateBossTimeRequest(Message *message){

	MsgBossUpdateTimeRequest *msg = dynamic_cast<MsgBossUpdateTimeRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgExchangeSoulRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	lua::call(lua::L, "Entity.UpdateBossTime", player, msg->powerkey);

}

void PlayerMsgHandler::onOpenSecWarehouseRequest( Message* message )
{
	MsgOpenSecondWareRequest* msg = dynamic_cast<MsgOpenSecondWareRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgCrossSyncFloatNotify");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;
	int beginPos = 0;
	int endPos = 0;
	if(lua::call(lua::L, "Entity.OpenSecWarehouse", player, msg->gridKey))
	{
		ret = lua::getinteger(1);
		beginPos = lua::getinteger(2);
		endPos = lua::getinteger(3);
	}
	MsgOpenSecondWareResponse *rsp  = new MsgOpenSecondWareResponse;
	rsp->errcode = ret;
	rsp->beginPos = beginPos;
	rsp->endPos = endPos;
	player->sendMessage(rsp);

}


// 一键使用
void PlayerMsgHandler::onQuickUseItemsRequest( Message* message )
{

	MsgQuickUseItemsRequest* msg = dynamic_cast<MsgQuickUseItemsRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgCrossSyncFloatNotify");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	long long totalIndex = msg->totalIndex;


	//这里循环的次数是意见使用物品种类的数量
	for (int itemIndex = 1; itemIndex <= 21;itemIndex++)
	{
		int a = 1 << itemIndex;
		if(a & totalIndex ){
			lua::call(lua::L, "Entity.getItemsCount", itemIndex);
			int itemsCount = lua::getinteger(1);
			if (itemsCount < 1) break;
			for (int i=1;i<=itemsCount;i++)
			{
				lua::call(lua::L, "Entity.QuickyUseItems", player, itemIndex,i);
				int error = lua::getinteger(1);
				if( error != SUCCESS )
				{
					MsgQuickUseItemsResponse* rsp = new MsgQuickUseItemsResponse();
					rsp->errcode = error;
					player->sendMessage(rsp);
				}
			}

		}
	}
}

void PlayerMsgHandler::onSyntheticRequest(Message *message){
	MsgSyntheticRequest* msg = dynamic_cast<MsgSyntheticRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgSyntheticRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	lua::call(lua::L, "Entity.syntheticItem", player, msg->targetItemCounts);
	int error = lua::getinteger(1);
	if( error != SUCCESS )
	{
		MsgSyntheticResponse* rsp = new MsgSyntheticResponse();
		rsp->errcode = error;
		player->sendMessage(rsp);
	}
}

void PlayerMsgHandler::onDecomposeDress(Message *message)
{
	
}

void PlayerMsgHandler::onUpdServerNameRequest(Message* message)
{
	MsgUpdServerNameRequest* msg = dynamic_cast<MsgUpdServerNameRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgUpdServerNameRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	player->setPropString(ENTITY_PROP_SOURCE_SERVER_NAME, msg->serverName);
	//下发跨服排行榜
	if(!g_config.isCrossServer())
	{
		lua::call(lua::L, "Entity.checkOpenCszt",player);
	}
}

void PlayerMsgHandler::onDBLoadPlayerCrossEvent(Message *message)
{
	MsgDBLoadPlayerCrossEvent *msg = dynamic_cast<MsgDBLoadPlayerCrossEvent *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = NULL;
	player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);


	if (player == nullptr)
	{
		return;
	}

	Event evt(EVENT_GROUP_PLAYER_LOAD, EVENT_LOAD_PLAYER_CROSS_EVENTS);
	player->onEvent(evt);
}

//请求升级
void PlayerMsgHandler::onLevelUpRequest(Message* message)
{
	MsgPlayerLevelUpRequest* msg = dynamic_cast<MsgPlayerLevelUpRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgPlayerLevelUpRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	
	int ret = ERROR_SCRIPT;
	int64 oldexp = EntityOperationHelper::getPlayerExp(*player);
	int64 nextLevelExp = EntityOperationHelper::getPlayerLevelUpExp(player->getLevel());

	if (oldexp >= nextLevelExp )
	{
		if(lua::call(lua::L, "Entity.levelUpRequest", player))
		{
			ret = lua::getinteger(1);

			if (ret == 0)
			{
				EntityOperationHelper::subExp(*player,nextLevelExp,OP_PLAYER_LEVEL_UP);
			}
		}
	}
	else
	{
		ret = ERROR_NOT_ENOUGH_CONDITION;
	}

	MsgPlayerLevelUpResponse *rep = new MsgPlayerLevelUpResponse();
	rep->errcode = ret;
	player->sendMessage(rep);
}

//技能升级
void PlayerMsgHandler::onUpgradeSkillLevelRequest(Message* message)
{
	MsgUpdatePlayerSkillRequest* msg = dynamic_cast<MsgUpdatePlayerSkillRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgUpdatePlayerSkillRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = ERROR_SCRIPT;
	if(lua::call(lua::L, "Skill.skillLevelUp", player,msg->skillid))
	{
		ret = lua::getinteger(1);
	}

	if (ret != SUCCESS)
	{
		MsgUpdatePlayerSkillResponse *rep = new MsgUpdatePlayerSkillResponse();
		rep->errcode = ret;
		rep->skillid = msg->skillid;
		player->sendMessage(rep);
	}
}


//洗练刷新
void PlayerMsgHandler::onSmeltRefreshRequest(Message *message){

}

//洗练替换
void PlayerMsgHandler::onSmeltReplaceRequest(Message *message)
{
	
}

//清空右侧洗练出的属性
void PlayerMsgHandler::onSmeltClearNewAttrsRequest(Message *message)
{
	
}

//幸运直升满级
void PlayerMsgHandler::onLuckyImmedFullLevelRequest(Message *message){

	MsgLuckyImmedFullLevelRequest* msg = dynamic_cast<MsgLuckyImmedFullLevelRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgLuckyImmedFullLevelRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	lua::call(lua::L, "LuckySys.luckyImmedFullLevel", player);
	int error = lua::getinteger(1);

	MsgLuckyImmedFullLevelResponse* rsp = new MsgLuckyImmedFullLevelResponse();
	rsp->errcode = error;
	player->sendMessage(rsp);
}

//魂石
void PlayerMsgHandler::onSpiritStoneRequest(Message *message)
{
		 
}
// 魂石合成
void PlayerMsgHandler::onSpiritStoneMakeRequest(Message *message)
{
	
}


void PlayerMsgHandler::onExchangeHegemonEquipShowt(Message* message)
{
	MsgExchangeHegemonEquipShowRequest* msg = dynamic_cast<MsgExchangeHegemonEquipShowRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgExchangeHegemonEquipShowRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}


	lua::call(lua::L, "Entity.CheckHegemonEquipShow", player,msg->exchageType);


}

//聊天记录请求
void PlayerMsgHandler::onKeepMsgRequest(Message* message)
{
	MsgKeepMsgRequest *msg = dynamic_cast<MsgKeepMsgRequest *>(message);
	if (!msg){ return ;}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	player->SendKeepMsg(message->getSessionID());
}

//圣兽升级
void PlayerMsgHandler::onTherionLevelRequest(Message *message)
{
	MsgPlayerTherionLevelRequest *msg = dynamic_cast<MsgPlayerTherionLevelRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	OperationHelper::setOpCode(OP_THERION);

	lua::call(lua::L, "Entity.TherionLevelUpMerLevel",player,msg->index);
	int error = lua::getinteger(1);
	int oldLevel = lua::getinteger(2);
	int newLevel = lua::getinteger(3);
	int count1 = lua::getinteger(4);
	int count2 = lua::getinteger(5);

	if(error == SUCCESS)
	{
		// 添加日志
		OperationHelper::recordTherion(*player,
			oldLevel, newLevel, count1, count2,msg->index);
	}

	MsgPlayerTherionLevelResponse* res = new MsgPlayerTherionLevelResponse;
	res->errcode = error;
	player->sendMessage(res);
}

//萌宠操作
void PlayerMsgHandler::onPlayerLovelyPetRequest(Message *message)
{
	MsgPlayerLovelyPetRequest *msg = dynamic_cast<MsgPlayerLovelyPetRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;	
	if(lua::call(lua::L, "Entity.PlayerMengChongOperation", player,msg->type,msg->petid))
	{
		ret = lua::getinteger(1);
	}
	if(ret != SUCCESS)
	{
		MsgPlayerLovelyPetResponse* res = new MsgPlayerLovelyPetResponse;
		res->errcode = ret;
		player->sendMessage(res);
	}else{
		int optype = msg->type;
		//1、获取  2、使用 
		if(optype == 2) 
		{
			auto scene = player->getScene();
			if(msg->petid >0 && scene) //召唤 
			{
				EntityOperationHelper::summonPet(player);
			}else { //隐藏
				EntityPet * pet = player->GetPetBySid(1);
				if (pet && scene)
				{
					SceneOperationHelper::removeEntity(*scene,pet->getID());
				}
			}
		}

	}
}

//加载宝宝 
void PlayerMsgHandler::onPlayerLoadPetRequest(Message *message)
{
	MsgPlayerLoadPetRequest *msg = dynamic_cast<MsgPlayerLoadPetRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	Entity *pet = NULL;

	pet = player->getChildEntity(1);

	bool bnewentity = false;

	if (pet == NULL)
	{
		//根据宠物类型(普通宠物和道士狗宠物)创建宠物
		pet = g_entity_factory->newEntity(ENTITY_TYPE_PET);
		bnewentity = true;
	}
	pet->setStaticID(1);
	pet->setLevel(0);
	pet->setOwner(player);

	if (bnewentity)
	{
		bool success = false;
		success = player->addChildEntity(1, pet);

		if (!success)
		{
			g_entity_factory->deleteEntity(pet);
			pet = nullptr;
		}
	}
}

//购买宝宝技能礼包处理 
void PlayerMsgHandler::onPlayerBuyBaoBaoSkill(Message *message)
{
	MsgPlayerGetBaoBaoSkillRequest *msg = dynamic_cast<MsgPlayerGetBaoBaoSkillRequest*>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;
	//购买宝宝技礼包
	if(lua::call(lua::L, "Entity.buyBaoBaoSkill", player,msg->bagid))
	{
		ret = lua::getinteger(1);
	}

	if(ret != SUCCESS)
	{
		MsgPlayerGetBaoBaoSkillResponse * msgres = new MsgPlayerGetBaoBaoSkillResponse;
		if (msgres)
		{
			msgres->errcode = ret;
			player->sendMessage(msgres);
			return;
		}
	}
}

void PlayerMsgHandler::onExchangeIngotRequest(Message* message)
{
	MsgExchangeIngotRequest *msg = dynamic_cast<MsgExchangeIngotRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgExchangeIngotResponse *res = new MsgExchangeIngotResponse();
	res->errcode = EntityOperationHelper::exchangeIngot(*player, msg->count);
	player->sendMessage(res);
}

//获取练功房奖励 
void PlayerMsgHandler::onPlayerGetTrainingRewardRequest(Message* message)
{
	MsgPlayerGetTrainingRewardRequest *msg = dynamic_cast<MsgPlayerGetTrainingRewardRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	if(lua::call(lua::L, "Entity.getTrainingRoomReward", player,0)) 
	{
		int ret =  lua::getinteger(1);
		MsgPlayerGetTrainingRewardResponse * res = new MsgPlayerGetTrainingRewardResponse();
		res->errcode = ret;
		player->sendMessage(res);
	}
}

//购买特戒礼包
void PlayerMsgHandler::onPlayerGetSpecialRingGifrRequest(Message* message)
{
	MsgPlayerGetSpecialRingGiftRequest *msg = dynamic_cast<MsgPlayerGetSpecialRingGiftRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;

	if(lua::call(lua::L, "Entity.buySpecialRingGift", player,msg->index))
	{
		ret =  lua::getinteger(1);
	}
	
// 	MsgPlayerGetSpecialRingGiftResponse * resp = new MsgPlayerGetSpecialRingGiftResponse();
// 	resp->errcode = ret;
// 	player->sendMessage(resp);
}

//石墓烧猪操作
void PlayerMsgHandler::onRoastPigRequest(Message* message)
{
	MsgRoastPigRequest *msg = dynamic_cast<MsgRoastPigRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//具体操作 
	if (msg->type == 1) //开始召唤怪物 
	{
		if(lua::call(lua::L, "Entity.smszBeginSummonMonster", player))
		{
			int ret =  lua::getinteger(1);
		}
	}
	else if(msg->type == 2)//领取奖励
	{
		if(lua::call(lua::L, "Entity.getRoastPigReward", player))
		{
			int ret =  lua::getinteger(1);
			MsgRoastPigResponse * res = new MsgRoastPigResponse();
			res->errcode = ret;
			player->sendMessage(res);
		}
	}
	else if(msg->type == 3)//进地图
	{
		if(lua::call(lua::L, "Entity.canEnterSMSZ", player))
		{
			int ret =  lua::getinteger(1);
			if (ret == SUCCESS)
			{
				//进地图
				SceneOperationHelper::conveyEntityToScene(*player, 814);  
			}
		}
	}
	else if(msg->type == 4)//扫荡
	{
		if(lua::call(lua::L, "Entity.smszSaoDang", player))
		{
			int ret =  lua::getinteger(1);
			MsgRoastPigResponse * res = new MsgRoastPigResponse();
			res->errcode = ret;
			player->sendMessage(res);
		}
	}
}

//月卡奖励领取
void PlayerMsgHandler::onMonthCardGetRewardRequest(Message* message)
{
	MsgMonthCardGetRewardRequest *msg = dynamic_cast<MsgMonthCardGetRewardRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	lua::call(lua::L, "Entity.getMonthCardReward", player,msg->type);
}

//会员操作  
void PlayerMsgHandler::onMemberOpeartionRequest(Message* message)
{
	MsgMemberOpeartionRequest *msg = dynamic_cast<MsgMemberOpeartionRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	//会员操作 
	if(lua::call(lua::L, "Entity.memberOperation", player,msg->type))
	{
		int ret = lua::getinteger(1);
		MsgMemberOpeartionResponse * res = new MsgMemberOpeartionResponse();
		res->errcode = ret;
		player->sendMessage(res);
	}
}

//激活新vip
void PlayerMsgHandler::onNewVipActiveRequest(Message* message)
{
	MsgNewVipActiveRequest *msg = dynamic_cast<MsgNewVipActiveRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	if(lua::call(lua::L, "NewVip.active", player))
	{
		int ret = lua::getinteger(1);
		if(ret == SUCCESS)
		{
			MsgNewVipActiveResponse* rsp = new MsgNewVipActiveResponse();
			rsp->errcode = ret;
			player->sendMessage(rsp);
		}
	}
}

//升级新vip
void PlayerMsgHandler::onNewVipLvlUpRequest(Message* message)
{
	MsgNewVipLvlUpRequest *msg = dynamic_cast<MsgNewVipLvlUpRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int rtv = ERROR_SCRIPT;
	if(lua::call(lua::L, "gdNewVipExtension.upgrade", player))
	{
		rtv = lua::getinteger(1);
	}

	MsgNewVipLvlUpResponse* rsp = new MsgNewVipLvlUpResponse();
	rsp->errcode = rtv;
	player->sendMessage(rsp);
}

//挑战新vip副本
void PlayerMsgHandler::onNewVipChallengeRequest(Message* message)
{
	MsgNewVipChallengeRequest *msg = dynamic_cast<MsgNewVipChallengeRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	lua::call(lua::L, "gdNewVipExtension.challenge", player, msg->index);
}

void PlayerMsgHandler::onNewVipGetStarRewardRequest(Message* message)
{
	MsgNewVipGetStarRewardRequest *msg = dynamic_cast<MsgNewVipGetStarRewardRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int rtv = ERROR_SCRIPT;
	if(lua::call(lua::L, "gdNewVipExtension.getStarReward", player, msg->map_page, msg->index))
	{
		rtv = lua::getinteger(1);
	}

	MsgNewVipGetStarRewardResponse* res = new MsgNewVipGetStarRewardResponse;
	res->errcode = rtv;
	res->map_page = msg->map_page;
	player->sendMessage(res);
}

void PlayerMsgHandler::onNewVipSubmitQuestRequest(Message* message)
{
	MsgNewVipSubmitQuestRequest *msg = dynamic_cast<MsgNewVipSubmitQuestRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int rtv = ERROR_SCRIPT;
	if(lua::call(lua::L, "gdNewVipExtension.submitQuest", player, msg->quest_type))
	{
		rtv = lua::getinteger(1);
	}

	MsgNewVipSubmitQuestResponse* res = new MsgNewVipSubmitQuestResponse;
	res->errcode = rtv;
	res->quest_type = msg->quest_type;
	player->sendMessage(res);
}

void PlayerMsgHandler::onActiveQiLingRequest(Message* message)
{
	MsgActiveQiLingRequest *msg = dynamic_cast<MsgActiveQiLingRequest *>(message); 
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int rtv = ERROR_SCRIPT;
	if(lua::call(lua::L, "gdNewVipExtension.activeQiLing", player, msg->id))
	{
		rtv = lua::getinteger(1);
	}

	MsgActiveQiLingResponse* res = new MsgActiveQiLingResponse;
	res->errcode = rtv;
	res->id = msg->id;
	player->sendMessage(res);
}

//得到藏宝图位置
void PlayerMsgHandler::onGetTheasureMapPosRequest(Message* message)
{
	MsgGetTheasureMapPosRequest *msg = dynamic_cast<MsgGetTheasureMapPosRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	if(lua::call(lua::L, "TreasureMapMain.OpenTreasureMap", player,true))
	{
		int ret = lua::getinteger(1);
		if(ret == SUCCESS)
		{
			MsgGetTheasureMapPosResponse* rsp = new MsgGetTheasureMapPosResponse();
			rsp->errcode = ret;
			player->sendMessage(rsp);
		}
	}
}

//挖宝事件
void PlayerMsgHandler::onOpenTheasureMapRequest(Message* message)
{
	MsgOpenTheasureMapRequest *msg = dynamic_cast<MsgOpenTheasureMapRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	if(lua::call(lua::L, "TreasureMapMain.startOpenTreasure", player))
	{
		int ret = lua::getinteger(1);
		if(ret == SUCCESS)
		{
			int eventIndex = lua::getinteger(2);
			MsgOpenTheasureMapResponse* rsp = new MsgOpenTheasureMapResponse();
			rsp->errcode = ret;
			rsp->eventIndex = eventIndex;
			player->sendMessage(rsp);

			player->onEvent(Event(EVENT_GROUP_QUEST,EVENT_OPEN_TREASURE));
		}
	}
	
}

void PlayerMsgHandler::onOpenTheasureMapGetAwardRequest(Message* message)
{
	MsgOpenTheasureMapGetAwardRequest *msg = dynamic_cast<MsgOpenTheasureMapGetAwardRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret =ERROR_SCRIPT;
	int index = 0;
	if(lua::call(lua::L, "TreasureMapMain.GetTreasureEvent3Award", player,msg->eid))
	{
		ret = lua::getinteger(1);
		if (ret == SUCCESS)
		{
			index = lua::getinteger(2);
		}
	}

	MsgOpenTheasureMapGetAwardResponse* rsp = new MsgOpenTheasureMapGetAwardResponse();
	rsp->errcode = ret;
	rsp->index = index;
	player->sendMessage(rsp);
}

//获取玩家信息 
void  PlayerMsgHandler::onDBLoadPlayerEquipInfo(Message* message)
{
	MsgDBLoadPlayerEquipInfo *msg = dynamic_cast<MsgDBLoadPlayerEquipInfo *>(message); 
	if (!msg)
	{
		return;
	}

	if (msg->getErrcode() != SUCCESS)
	{
		return;
	}

	if(msg->srcServerid > 0)
	{
		//跨服查找的 
		MsgGetPlayerEquipInfoResponse* newMsg = new MsgGetPlayerEquipInfoResponse();
		//发回原服 
		newMsg->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));  //战区服务器id
		newMsg->setSourceSessionID(msg->srcServerid);  //目标游戏服id
		newMsg->srcPid = msg->srcPid;
		newMsg->targetPid = msg->pid;
		newMsg->name =  msg->name;
		newMsg->gender =  msg->gender;
		newMsg->clazz =  msg->clazz;
		newMsg->level =  msg->level;
		newMsg->zhanli =  msg->zhanli;
		newMsg->reborn = 0;	
		newMsg->srcServerid = msg->srcServerid;
		newMsg->honor = 0;//target->getProp(ENTITY_PROP_HONOR);
		newMsg->pkvalue = msg->pkvalue;
		newMsg->rebornsoul = msg->rebornsoul;
		newMsg->stonepoint = msg->stonepoint;
		newMsg->godLevel = msg->godLevel;
		newMsg->enhanceExLevel = msg->enhanceExLevel;
		newMsg->soulExLevel = msg->soulExLevel;
		newMsg->moshiLevel = msg->moshiLevel;
		newMsg->hide_moguan = msg->hide_moguan;
		newMsg->dress_cloth = msg->dress_cloth;
		newMsg->xiliansuit = msg->xiliansuit;
		newMsg->exMaxLvl = msg->exMaxLvl;
		newMsg->heji = msg->heji;
		newMsg->guild = msg->guild;
		
		for (auto it = msg->equips.begin(); it != msg->equips.end(); it ++) {
			OtherEquipInfoDB result = *it;
			CrossOtherEquipInfo equip;
			equip.bind = result.bind;
			equip.iid = result.iid;
			equip.sid = result.sid;
			equip.pos = result.pos;
			equip.props = result.props;
			newMsg->equips.push_back(equip);
		}

		for (auto it = msg->prop.begin(); it != msg->prop.end(); it ++) {
			OtherEntityPropDB result = *it;
			CrossOtherEntityProp propc;
			propc.type = result.type;
			propc.value = result.value;
			newMsg->prop.push_back(propc);
		}
		for (auto it = msg->sprop.begin(); it != msg->sprop.end(); it ++) {
			OtherEntityStringPropDB result = *it;
			CrossOtherEntityStringProp propc;
			propc.type = result.type;
			propc.value = result.value;
			newMsg->sprop.push_back(propc);
		}
		newMsg->vcombat = msg->vcombat;
		int dress = this->getPropValue(ENTITY_PROP_DRESS_YIFU,msg->prop);
		if  (dress == 0)  
		{
			newMsg->cloth = this->getPropValue(ENTITY_PROP_PLAYER_CLOTH,msg->prop);
		}else 
		{
			newMsg->cloth = dress;
		}
		newMsg->weapon = this->getEquipValue(BAG_POS_EQUIP_WEAPON,msg->equips);
		g_app.postToNetService(newMsg);
		return;
	}


	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (!player)
	{
		return;
	}

	MsgCheckEquipResponse* res = new MsgCheckEquipResponse;

	res->pid = msg->pid;
	res->name = msg->name;
	res->gender = msg->gender;
	res->clazz = msg->clazz;
	res->level = msg->level;
	std::vector<OtherEquipInfoDB> equips = msg->equips;
	std::vector<OtherEntityPropDB> props = msg->prop;
	std::vector<OtherEntityStringPropDB> sprops = msg->sprop;
	Guild* guild = g_guild_mgr.getGuildByID(this->getPropValue(ENTITY_PROP_GUILD_ID,props));
	if (guild)
	{
		res->guild = guild->getGuildName();
	}
	for (auto it = equips.begin(); it != equips.end(); it ++) {
		OtherEquipInfoDB result = *it;
		OtherEquipInfo equip;
		equip.bind = result.bind;
		equip.iid = result.iid;
		equip.sid = result.sid;
		equip.pos = result.pos;
		equip.props = result.props;
		res->equips.push_back(equip);
	}
	
	for (auto it = props.begin(); it != props.end(); it ++) {
		OtherEntityPropDB result = *it;
		OtherEntityProp propc;
		propc.type = result.type;
		propc.value = result.value;
		res->prop.push_back(propc);
	}
	for (auto it = sprops.begin(); it != sprops.end(); it ++) {
		OtherEntityStringPropDB result = *it;
		OtherEntityStringProp propc;
		propc.type = result.type;
		propc.value = result.value;
		res->sprop.push_back(propc);
	}

	res->zhanli = this->getPropValue(ENTITY_PROP_FORCE,props);
	res->honor = 0;//target->getProp(ENTITY_PROP_HONOR);
	res->pkvalue = this->getPropValue(ENTITY_PROP_PK_VALUE,props);
	res->rebornsoul =  this->getPropValue(ENTITY_PROP_REBORN_POINTS,props);   
	res->stonepoint = this->getPropValue(ENTITY_PROP_STONE_POINT,props);  
	res->godLevel = this->getPropValue(ENTITY_PROP_GOD_LV,props);  
	res->enhanceExLevel = this->getPropValue(ENTITY_PROP_ENHANCE_EX,props);  
	res->soulExLevel = this->getPropValue(ENTITY_PROP_SOUL_EX,props);   
	res->moshiLevel = this->getPropValue(ENTITY_PROP_MOSHI_LV,props);   
	res->hide_moguan = this->getPropValue(ENTITY_PROP_HIDE_MOGUAN,props);   
	res->dress_cloth = this->getPropValue(ENTITY_PROP_DRESS_YIFU,props);  
	res->xiliansuit = this->getPropValue(ENTITY_PROP_XL_SUIT,props); 
	res->exMaxLvl = this->getPropValue(ENTITY_PROP_MAX_EX_LEVEL,props);

	res->reborn = this->getPropValue(ENTITY_PROP_REBORN,props);
	
	int dress = this->getPropValue(ENTITY_PROP_DRESS_YIFU,props);
	if  (dress == 0)  
	{
		res->cloth = this->getPropValue(ENTITY_PROP_PLAYER_CLOTH,props);
	}else 
	{
		res->cloth = dress;
	}
	res->weapon = this->getEquipValue(BAG_POS_EQUIP_WEAPON,equips);
	res->errcode = SUCCESS;
	player->sendMessage(res);
}

void PlayerMsgHandler::onDBLoadOtherPlayerInfo(Message* message)
{
	MsgDBLoadOtherPlayerInfo *msg = dynamic_cast<MsgDBLoadOtherPlayerInfo *>(message);
	if (!msg)
	{
		return;
	}

	if (msg->getErrcode() != SUCCESS)
	{
		return;
	}

	if (msg->srcServerid)
	{
		//跨服查找,发回原服 
		MsgNewGetPlayerEquipInfoResponse* res = new MsgNewGetPlayerEquipInfoResponse;
		res->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));  //战区服务器id
		res->setSourceSessionID(msg->srcServerid);  //目标游戏服id
		res->srcPid = msg->srcPid;
		res->targetPid = msg->pid;
		res->name = msg->name;
		res->level = msg->level;
		res->gender = msg->gender;
		res->guild = msg->guild;
		res->job = msg->job;
		res->reborn = msg->reborn;
		res->lingwen = msg->lingwen;
		res->guildpost = this->getPropValue(ENTITY_PROP_GUILD_POST, msg->prop);
		res->weapon = this->getPropValue(ENTITY_PROP_DRESS_WUQI, msg->prop);
		if (res->weapon == 0)
		{
			res->weapon = this->getPropValue(ENTITY_PROP_PLAYER_WEAPON, msg->prop);
		}
		res->cloth = this->getPropValue(ENTITY_PROP_DRESS_YIFU, msg->prop);
		if (res->cloth == 0)
		{
			res->cloth = this->getPropValue(ENTITY_PROP_PLAYER_CLOTH, msg->prop);
		}	

		// 装备
		auto otherEquips = EntityOperationHelper::getOtherPlayerEquip();
		for (auto& it : msg->equips)
		{
			if (otherEquips.find(it.pos) != otherEquips.end())
			{
				CrossOtherPlayerEquip e;
				e.pos = it.pos;
				e.sid = it.sid;
				e.iid = it.iid;
				e.firstowner = it.firstowner;
				for (auto& prop : it.props)
				{
					CrossOtherItemProp p;
					p.idx = prop.idx;
					p.data = prop.data;
					e.props.push_back(p);
				}
				res->equips.push_back(e);
			}
		}

		// 整形属性
		auto otherIntProp = EntityOperationHelper::getOtherPlayerIntProp();
		for (auto& it : msg->prop)
		{
			if (otherIntProp.find(it.type) != otherIntProp.end())
			{
				CrossOtherEntityProp p;
				p.type = it.type;
				p.value = it.value;
				res->prop.push_back(p);
			}
		}

		// 字符属性
		auto otherStrProp = EntityOperationHelper::getOtherPlayerStrProp();
		for (auto& it : msg->sprop)
		{
			if (otherStrProp.find(it.type) != otherStrProp.end())
			{
				CrossOtherEntityStringProp p;
				p.type = it.type;
				p.value = it.value;
				res->sprop.push_back(p);
			}
		}

		// 技能
		for (auto& it : msg->skill)
		{
			CrossOtherPlayerSkill s;
			s.id = it.id;
			s.level = it.level;
			res->skill.push_back(s);
		}
		g_app.postToNetService(res);

		return;
	}
	
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (!player)
	{
		return;
	}

	MsgNewCheckEquipResponse* res = new MsgNewCheckEquipResponse;
	res->pid = msg->pid;
	res->name = msg->name;
	res->level = msg->level;
	res->exp = msg->exp;
	res->gender = msg->gender;
	res->guild = msg->guild;
	res->job = msg->job;
	res->reborn = msg->reborn;
	res->lingwen = this->getPropValue(ENTITY_PROP_LINGWEN_SHOW_ID, msg->prop);
	res->guildpost = this->getPropValue(ENTITY_PROP_GUILD_POST, msg->prop);
	res->weapon = this->getPropValue(ENTITY_PROP_DRESS_WUQI, msg->prop);
	if (res->weapon == 0)
	{
		res->weapon = this->getPropValue(ENTITY_PROP_PLAYER_WEAPON, msg->prop);
	}
	res->cloth = this->getPropValue(ENTITY_PROP_DRESS_YIFU, msg->prop);
	if (res->cloth == 0)
	{
		res->cloth = this->getPropValue(ENTITY_PROP_PLAYER_CLOTH, msg->prop);
	}

	// 装备
	auto otherEquips = EntityOperationHelper::getOtherPlayerEquip();
	for (auto& it : msg->equips)
	{
		if (otherEquips.find(it.pos) != otherEquips.end())
		{
			OtherPlayerEquip e;
			e.pos = it.pos;
			e.sid = it.sid;
			e.iid = it.iid;
			e.firstowner = it.firstowner;
			for (auto& prop : it.props)
			{
				OtherItemProp p;
				p.idx = prop.idx;
				p.data = prop.data;
				e.props.push_back(p);
			}
			res->equips.push_back(e);
		}
	}

	// 整形属性
	auto otherIntProp = EntityOperationHelper::getOtherPlayerIntProp();
	for (auto& it : msg->prop)
	{
		if (otherIntProp.find(it.type) != otherIntProp.end())
		{
			OtherEntityProp p;
			p.type = it.type;
			p.value = it.value;
			res->prop.push_back(p);
		}
	}

	// 字符属性
	auto otherStrProp = EntityOperationHelper::getOtherPlayerStrProp();
	for (auto& it : msg->sprop)
	{
		if (otherStrProp.find(it.type) != otherStrProp.end())
		{
			OtherEntityStringProp p;
			p.type = it.type;
			p.value = it.value;
			res->sprop.push_back(p);
		}
	}

	// 技能
	for (auto& it : msg->skill)
	{
		OtherPlayerSkill s;
		s.id = it.id;
		s.level = it.level;
		res->skill.push_back(s);
	}

	player->sendMessage(res);
}

std::string PlayerMsgHandler::getStringPropValue(int ptype,std::vector<OtherEntityStringPropDB> values)
{
	for (auto it = values.begin(); it != values.end(); it ++) {

		OtherEntityStringPropDB result = *it;
		if ((result.type) == ptype)
		{
			return result.value;
		}
	}
	return "";
}


int PlayerMsgHandler::getPropValue(int ptype,std::vector<OtherEntityPropDB> values)
{
	for (auto it = values.begin(); it != values.end(); it ++) {

		OtherEntityPropDB result = *it;
		if ((result.type) == ptype)
		{
			return result.value;
		}
	}
	return 0;
}

int PlayerMsgHandler::getEquipValue(int position,std::vector<OtherEquipInfoDB> values)
{
	for (auto it = values.begin(); it != values.end(); it ++) {

		OtherEquipInfoDB result = *it;
		if ((result.pos) == position)
		{
			return result.sid;
		}
	}
	return 0;

}

//购买额外归属奖励次数 
void  PlayerMsgHandler::onGetXiYouRewardCountRequest(Message* message)
{
	MsgGetXiYouRewardCountRequest *msg = dynamic_cast<MsgGetXiYouRewardCountRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int ret = SUCCESS;
	if(lua::call(lua::L, "Entity.onBuyBossCount", player,msg->type)) 
	{
		ret = lua::getinteger(1);
	}
	if (ret != SUCCESS)
	{
		MsgGetXiYouRewardCountResponse * res = new MsgGetXiYouRewardCountResponse;
		res->errcode = ret;
		player->sendMessage(res);
	}
}

//领取历练之路奖励 
void  PlayerMsgHandler::onExpRoadRewardRequest(Message* message)
{
	MsgExpRoadRewardRequest *msg = dynamic_cast<MsgExpRoadRewardRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	int ret = SUCCESS;
	if(lua::call(lua::L, "ExpRoad.onGetExpRoadReward", player,msg->type,msg->index)) 
	{
		ret = lua::getinteger(1);
	}
	
	MsgExpRoadRewardResponse * res = new MsgExpRoadRewardResponse;
	res->errcode = ret;
	res->index = msg->index;
	player->sendMessage(res);
	
}

//检测私聊目标玩家在不在线 
void  PlayerMsgHandler::onPrivateChatOnlineCheckRequest(Message* message)
{
	MsgPrivateChatOnlineCheckRequest *msg = dynamic_cast<MsgPrivateChatOnlineCheckRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	int ret = ERROR_CANNOT_CHAT_PRIVATE;

	Entity * aimTarget = g_world_player_mgr.getPlayerByPlayerID(msg->playerid);
	if (aimTarget)
	{
		if(aimTarget->getProp(ENTITY_PROP_OFFLINE) == 0)
		{
			ret = SUCCESS;
		}
	}
	MsgPrivateChatOnlineCheckResponse * res = new MsgPrivateChatOnlineCheckResponse;
	res->errcode = ret;
	res->playerid = msg->playerid;
	res->name = msg->name;
	player->sendMessage(res);
}

// 天关秘境，爬塔扫荡奖励
void PlayerMsgHandler::onTgmjTowerClearRequest(Message* message)
{
	MsgTgmjTowerClearRequest *msg = dynamic_cast<MsgTgmjTowerClearRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	int ret = SUCCESS;
	if(lua::call(lua::L, "Entity.onTgmjTowerClear", player,msg->clearType)) 
	{
		ret = lua::getinteger(1);
	}

	MsgTgmjTowerClearResponse * res = new MsgTgmjTowerClearResponse;
	res->errcode = ret;
	player->sendMessage(res);
}

void PlayerMsgHandler::onBloodUpRequest(Message* message)
{
	MsgBloodUpdateRequest *msg = dynamic_cast<MsgBloodUpdateRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	int ret = SUCCESS;
	if(lua::call(lua::L, "Entity.onBloodUp", player,msg->BloodType)) 
	{
		ret = lua::getinteger(1);
	}

	MsgBloodUpdateResponse * res = new MsgBloodUpdateResponse;
	res->errcode = ret;
	player->sendMessage(res);
}


void PlayerMsgHandler::onSyncTabRequest(Message* message)
{
	MsgSYNCTABRequest *msg = dynamic_cast<MsgSYNCTABRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	if(lua::call(lua::L, "SyncTab.handlerRequest", player,msg->syncType,msg->syncCode)) 
	{
	//	ret = lua::getinteger(1);
	}

}

void PlayerMsgHandler::onMsgPlayerJuHePayRequest(Message* message)
{
	MsgPlayerJuHePayRequest *msg = dynamic_cast<MsgPlayerJuHePayRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	LOG_INFO("send: player pay message orderid : %d ",msg->aid );
	MsgJuHePayRequest* jh = new MsgJuHePayRequest();
	jh->appId = msg->appId;
	jh->packageId = msg->packageId;
	jh->deviceId = msg->deviceId;
	jh->aid = msg->aid;
	jh->money = msg->money;
	jh->ip = msg->ip;
	jh->cpExt = msg->cpExt;
	jh->serverName = msg->serverName;
	jh->roleName = msg->roleName;
	jh->sdkId = msg->sdkId;
	jh->sessionId = message->getSessionID();
	jh->openId = msg->openId;
	jh->appKey = msg->appKey;
	g_app.postToNetService(jh);
}

void PlayerMsgHandler::onMsgPlayerChatVeriPhoneRequest(Message*  message)
{
	MsgPlayerChatVeriPhoneRequest *msg = dynamic_cast<MsgPlayerChatVeriPhoneRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgGMChatVeriPhoneRequest* cvi = new MsgGMChatVeriPhoneRequest();
	cvi->sessionId = message->getSessionID();
	cvi->appId = msg->appId;
	cvi->openId = msg->openId;
	cvi->mobile = msg->mobile;
	cvi->verifyCode = msg->verifyCode;
	g_app.postToNetService(cvi);

}

void PlayerMsgHandler::onMsgPlayerChatVeriCodeRequest(Message*  message)
{
	MsgPlayerChatVeriCodeRequest *msg = dynamic_cast<MsgPlayerChatVeriCodeRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgGMChatVeriCodeRequest* cvi = new MsgGMChatVeriCodeRequest();
	cvi->sessionId = message->getSessionID();
	cvi->appId = msg->appId;
	cvi->openId = msg->openId;
	cvi->mobile = msg->mobile;
	g_app.postToNetService(cvi);

}


void PlayerMsgHandler::onMsgCommonOperatorRequest(Message*  message)
{
	MsgCommonOperatorRequest *msg = dynamic_cast<MsgCommonOperatorRequest *>(message); 
	if (!msg)
	{
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int errcode = ERROR_SCRIPT;
	int datax = 0, datay = 0, dataz = 0;
	std::string datas;
	if (lua::call(lua::L, "Entity.doCommonRequestScript", player, msg->funcid, msg->datax, msg->datay, msg->dataz, msg->datas))
	{
		errcode = lua::getinteger(1);
		datax = lua::getinteger(2);
		datay = lua::getinteger(3);
		dataz = lua::getinteger(4);
		datas = lua::getstring(5);
	}

	MsgCommonOperatorResponse *response = new MsgCommonOperatorResponse;
	response->errcode = errcode;
	response->funcid = msg->funcid;
	response->datax = datax;
	response->datay = datay;
	response->dataz = dataz;
	response->datas = datas;
	response->setSessionID(msg->getSessionID());
	g_app.postToNetService(response);
}

void PlayerMsgHandler::onMsgGetMapStatisticsDataRequest(Message* message)
{
	MsgGetMapStatisticsDataRequest* msg = dynamic_cast<MsgGetMapStatisticsDataRequest*>(message);
	if (!msg)
	{
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	MsgGetMapStatisticsDataResponse* res = new MsgGetMapStatisticsDataResponse;
	res->setSessionID(msg->getSessionID());
	res->errcode = SUCCESS;
	for (int i = ENTITY_PROP_SCENE_ENTER_TIME; i <= ENTTIY_PROP_SCENE_LOOT_EQUIP_CNT_5; ++i)
	{
		OtherEntityProp prop;
		prop.type = i;
		prop.value = player->getProp(i);
		res->data_list.emplace_back(prop);
	}
	g_app.postToNetService(res);
}

void PlayerMsgHandler::onMsgGetBossCntInMapRequest(Message *message)
{
	MsgGetBossCntInMapRequest *msg = dynamic_cast<MsgGetBossCntInMapRequest *>(message);
	if (!msg)
	{
		LOG_ERROR("invalid message MsgGetBossCntInMapRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (!player)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	std::map<short, int> crossMaps;
	std::map<short,std::pair<int, int>> bossCnts;
	for (short i = 0; i < msg->maps.size(); ++i)
	{
		if(lua::call(lua::L, "Scene.isWarZoneMap", msg->maps[i]) && lua::getboolean(1))
		{
			crossMaps[i + 1] =  msg->maps[i];
		}
		else
		{
			int sceneId = msg->maps[i];
			int count = SceneOperationHelper::getMapBossCount(msg->maps[i]);
			bossCnts[i + 1] = std::make_pair(sceneId,count);
		}
	}

	// 有部分跨服地图
	if (!crossMaps.empty())
	{
		GSHelper::getBossCntInCrossMap(*player, crossMaps,msg->targetName);
	}

	// 本服地图
	if (!bossCnts.empty())
	{
		MsgGetBossCntInMapNotify* notify = new MsgGetBossCntInMapNotify;
		for (auto& it : bossCnts)
		{	
			MapBossCount m;
			m.index = it.first;
			m.sceneId = it.second.first;
			m.count = it.second.second;
			SceneOperationHelper::addBossInfo(m);
			notify->boss_cnts.emplace_back(m);
			notify->targetName = msg->targetName;
		}
		player->sendMessage(notify);
	}
	
}

void PlayerMsgHandler::onFabaoUpRequest(Message *message)
{
	MsgFabaoUpRequest *msg = dynamic_cast<MsgFabaoUpRequest *>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message onFabaoUpRequest");
		return;
	}
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}
	MsgFabaoUpResponse * response = new MsgFabaoUpResponse;
	int ret = ERROR_PLAYER_IS_DEAD;
	if (player->isAlive())
	{
		if (msg->opt == 1 || msg->opt == 5 || msg->opt == 6)
		{
			lua::call(lua::L,"Fabao.upLvl",player,msg->id);
			ret = lua::getinteger(1);
			response->errcode = ret;
		}else if(msg->opt == 2)
		{
			lua::call(lua::L,"Fabao.backLvl",player,msg->id);
			ret = lua::getinteger(1);
			response->errcode = ret;
		}else if (msg->opt == 3)
		{
			lua::call(lua::L,"Fabao.equip",player,msg->id,false);
			response->errcode = SUCCESS;
		}else if (msg->opt == 4)
		{
			lua::call(lua::L,"Fabao.offequip",player);
			response->errcode = SUCCESS;
		}
	}
	response->opt = msg->opt;
	player->sendMessage(response);

}

void PlayerMsgHandler::onOperationRecordNotify(Message *message)
{

}

void PlayerMsgHandler::onDoctorRequest(Message *message)
{
	MsgDoctorRequest *msg = dynamic_cast<MsgDoctorRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}
	
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(msg->getSessionID());
	if(player == nullptr)
	{
		return;
	}

	if(lua::call(lua::L, "Entity.doctorPlayer", player))
	{
		MsgDoctorResponse *response = new MsgDoctorResponse;
		if(response == nullptr)
		{
			return;
		}

		response->errcode = lua::getinteger(1);
		player->sendMessage(response);
	}
}

void PlayerMsgHandler::onUpdatePlayerClass(Message *message)
{
	MsgDBUpdatePlayerClass *msg = dynamic_cast<MsgDBUpdatePlayerClass*>(message);
	if(msg == nullptr)
	{
		return;
	}

	EntityPlayer *player = player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
	if(player == nullptr)
	{
		return;
	}

	int oldJob = player->getClass();
	player->setClass(msg->job);
	player->setStaticID(msg->job);

	if(lua::call(lua::L, "Entity.onChangeJob", player, oldJob, msg->job))
	{
		MsgChangeJobNotify *notify = new MsgChangeJobNotify;
		notify->errcode = SUCCESS;
		notify->job = player->getClass();
		player->sendMessage(notify);

		LoginHelper::logoutPlayer(player->getPlayerID());
	}
}

void PlayerMsgHandler::onToushiRequest(Message *message)
{
	MsgToushiRequest *msg = dynamic_cast<MsgToushiRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}
	EntityPlayer *player =  g_world_player_mgr.getPlayerBySessionID(msg->getSessionID());
	if(player == nullptr)
	{
		return;
	}

	if(lua::call(lua::L, "Entity.onToushi", player, msg->monsterId))
	{
		MsgToushiResponse *res = new MsgToushiResponse;
		if(res == nullptr)
		{
			return;
		}
		res->errcode = lua::getinteger(1);
		res->monsterId = msg->monsterId;
		res->itemList = lua::getstring(2);
		player->sendMessage(res);
	}	
}

void PlayerMsgHandler::onGetPlayerBaseInfoRequest(Message *message)
{
	MsgGetPlayerBaseInfoRequest *msg = dynamic_cast<MsgGetPlayerBaseInfoRequest*>(message);
	if(msg == nullptr)
	{
		return;
	}
	
	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(msg->getSessionID());
	if(player == nullptr)
	{
		return;
	}
	if(msg->serverid <= 0 || msg->serverid == g_world.getID())
	{
		EntityPlayer *tgt_player = g_world_player_mgr.getPlayerByPlayerID(msg->pid);
		if(tgt_player == nullptr)
		{
			PlayerBaseInfo * info = g_world.getOfflinePlayerBaseInfo(msg->pid);
			if(info != nullptr)
			{
				MsgGetPlayerBaseInfoResponse *res = new MsgGetPlayerBaseInfoResponse();
				if(res == nullptr)
				{
					return;
				}				
				res->pid = msg->pid;
				res->gender = info->gender;
				res->job = info->job;
				res->weapon = info->weapon;
				res->dress_weapon = info->dressWeapon;
				res->cloth = info->cloth;
				res->dress_cloth = info->dressCloth;
				res->hat = info->hat;
				res->shield = info->shield;
				res->guard_level = info->guardLevel;
				res->hunhuan = info->hunhuan;
				res->jingling = info->jingling;
				player->sendMessage(res);			
			}
			else
			{
				MsgLoadPlayerBaseInfo *db = new MsgLoadPlayerBaseInfo();
				if(db == nullptr)
				{
					return;
				}
				db->pid = msg->pid;
				db->srcPid = player->getGlobalID();
				g_app.postToNetService(db);
			}
		}
		else
		{
			MsgGetPlayerBaseInfoResponse *res = new MsgGetPlayerBaseInfoResponse();
			if(res == nullptr)
			{
				return;
			}
			res->pid = msg->pid;
			res->gender = tgt_player->getProp(ENTITY_PROP_GENDER);
			res->job = tgt_player->getClass();
			res->weapon = tgt_player->getProp(ENTITY_PROP_PLAYER_WEAPON);
			res->dress_weapon = tgt_player->getProp(ENTITY_PROP_DRESS_WUQI);
			res->cloth = tgt_player->getProp(ENTITY_PROP_PLAYER_CLOTH);
			res->dress_cloth = tgt_player->getProp(ENTITY_PROP_DRESS_YIFU);
			res->hat = tgt_player->getProp(ENTITY_PROP_PLAYER_HAT);
			res->shield = tgt_player->getProp(ENTITY_PROP_PLAYER_SHIELD);
			res->guard_level = tgt_player->getProp(ENTITY_PROP_GUARD_LEVEL);
			res->hunhuan = tgt_player->getProp(ENTITY_PROP_DRESS_HUNHUAN);
			res->jingling = tgt_player->getProp(ENTITY_PROP_DRESS_JINGLING);
			player->sendMessage(res);
		}	
	}
	else
	{
		MsgGetPlayerBaseInfoFromCSRequest *req = new MsgGetPlayerBaseInfoFromCSRequest();
		if(req == nullptr)
		{
			return;
		}
		req->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		req->srcPid = player->getGlobalID();
		req->srcServerId = g_world.getID();

		req->pid = msg->pid;
		req->serverId = msg->serverid;
		g_app.postToNetService(req);	
	}
}

void PlayerMsgHandler::onLoadPlayerBaseInfo(Message *message)
{
	MsgLoadPlayerBaseInfo *msg = dynamic_cast<MsgLoadPlayerBaseInfo*>(message);
	if(msg == nullptr)
	{
		return;
	}

	PlayerBaseInfo info;
	info.pid = msg->pid;
	info.gender = msg->gender;
	info.job = msg->job;
	info.weapon = msg->weapon;
	info.dressWeapon = msg->dressWeapon;
	info.cloth = msg->cloth;
	info.dressCloth = msg->dressCloth;
	info.hat = msg->hat;
	info.shield = msg->shield;
	info.guardLevel = msg->guardLevel;
	info.hunhuan = msg->hunhuan;
	info.jingling = msg->jingling;
	g_world.addOfflinePlayerBaseInfo(info);

	if(msg->srcServerid <= 0 || msg->srcServerid == g_world.getID())
	{
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
	else
	{
		MsgGetPlayerBaseInfoFromGSResponse *res = new MsgGetPlayerBaseInfoFromGSResponse();
		if(res == nullptr)
		{
			return;
		}

		res->setUserData(g_world.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO));
		res->srcPid = msg->srcPid;
		res->srcServerId = msg->srcServerid;

		res->pid = msg->pid;
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
}

void PlayerMsgHandler::onGetGiftByCodeRequest(Message *message)
{
	MsgGetGiftByCodeRequest* msg = dynamic_cast<MsgGetGiftByCodeRequest*>(message);
	if (msg == NULL)
	{
		LOG_ERROR("invalid message");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == NULL)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	//领取CD
	if (time(nullptr) <= player->getProp(ENTITY_PROP_GIFT_CODE_TIME) + 3)
	{
		MsgGetGiftByCodeResponse *response = new MsgGetGiftByCodeResponse;
		response->errcode = ERROR_TIME_3S_SPAN;
		player->sendMessage(response);
		return;
	}

	player->setProp(ENTITY_PROP_GIFT_CODE_TIME, (int)time(nullptr));

	int sid = 0;
	lua::call(lua::L, "Gift.GetCodeGiftSeries", msg->code, player->getPlayerID());
	sid = lua::getinteger(1);

	MsgGetCodeGiftFromAsRequest* request = new MsgGetCodeGiftFromAsRequest;
	request->code = msg->code;
	request->pid = player->getPlayerID();
	request->ServerID = g_world.getID();
	request->sid = sid;
	g_app.postToNetService(request);
}

void PlayerMsgHandler::onActivityRewardRequest(Message *message)
{
	MsgActivityRewardRequest *msg = dynamic_cast<MsgActivityRewardRequest*>(message);
	if (msg == nullptr)
	{
		LOG_ERROR("invalid message MsgActivityRewardRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == nullptr)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	int errcode = SUCCESS;
	MsgActivityRewardResponse* res = new MsgActivityRewardResponse;
	if (lua::call(lua::L, "Activity.getActivityReward", (Entity*)player, msg->id, msg->index, msg->flag))
	{
		errcode = lua::getinteger(1);
	}
	res->errcode = errcode;
	res->id = msg->id;
	res->index = msg->index;
	res->flag = msg->flag;
	player->sendMessage(res);
}

void PlayerMsgHandler::onActivityOperateRequest(Message *message)
{
	MsgActivityOperateRequest *msg = dynamic_cast<MsgActivityOperateRequest*>(message);
	if (msg == nullptr)
	{
		LOG_ERROR("invalid message MsgActivityOperateRequest");
		return;
	}

	EntityPlayer *player = g_world_player_mgr.getPlayerBySessionID(message->getSessionID());
	if (player == nullptr)
	{
		LOG_WARN("cannot find player, invalid session id %d-%d", message->getSessionIndex(), message->getSessionSerial());
		return;
	}

	if (lua::call(lua::L, "Activity.onActivityOperate", (Entity*)player, msg->id, msg->fun_name, msg->datax, msg->datay, msg->dataz, msg->datas))
	{
		MsgActivityOperateResponse* res = new MsgActivityOperateResponse;
		res->errcode = lua::getinteger(1);
		res->id = msg->id;
		res->fun_name = msg->fun_name;
		res->datax = lua::getinteger(2);
		res->datay = lua::getinteger(3);
		res->dataz = lua::getinteger(4);
		res->datas = lua::getstring(5);
		player->sendMessage(res);
	}
}
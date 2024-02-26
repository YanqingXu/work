#ifndef _CS_MSG_HANDLER_H_INCLUDED
#define _CS_MSG_HANDLER_H_INCLUDED

#include "common/Module.h"

class CSMsgHandler : public Module
{
public:
	CSMsgHandler(Service *service);
	virtual ~CSMsgHandler();

	virtual const char *getName() const { return "CSModule"; }

	virtual bool initialize();

private:
	//center server --> cross server
	void onWarZoneInfoNotify(Message* message);

private:
	std::vector<std::string> split(const std::string &s, char sep);

private:
	void onRegisterGameServerToCrossServer(Message* message);
	void onGameServerClose(Message* message);
	
private:
	//game server --> cross server
	void onGS2CS(Message* message);
	void onCreatePlayerInCrossServerRequest(Message* message);
	void onCreatePlayerInCrossServerEnd(Message* message);
	void onLeaveFromCrossServerMapRequest(Message* message);
	void onSwitchCSMapRequest(Message* message);
	void onSyncCommonInfoToCrossServerRequest(Message* message);

	void onKickPlayerFromCSRequest(Message* message);

	void onNotifyCrossServerItemAbandon(Message* message);
	void onReviveInCSMapRequest(Message* message);
	void onUseItemInCSMapRequest(Message* message);
	void onSyncEventDataRequest(Message* message);
	void onResetAndSyncAllEventDatat(Message* message);

	void onGetQualifiedPlayerListNearbyRequest(Message* message);
	void onSyncWarZoneDropInfoToCS(Message* message);
	void onSceneMessageWrapper(Message* message);
	void onCrossGetPlayerSerializeInfoG2C(Message* message);

	//拍卖行相关
	void onAddToCrossAuction(Message* message);
	void onCheckBuyCrossAuctionItem(Message* message);
	void onBuyCrossAuctionItem(Message* message);
	
	//寄售行相关
	void onAddConsignmentToCross(Message* message);
	void onCheckBuyCrossConsignment(Message* message);
	void onSendSellerReward(Message* message);
	void onRmvCrossConsignment(Message* message);

	//求购
	void onAddPurchaseToCrossRequest(Message* message);
	void onRmvPurchaseFromCrossRequest(Message* message);
	void onTrySellCrossPurchaseRequest(Message* message);
	void onSendBuyerPurchaseItemRequest(Message* message);

	//GM命令
	void onGetPlayerCrossProp(Message* message);
	void onCheckPlayerAllCrossProp(Message* message);

	//跨服聊天  
	void  onSendCrossChaToCsRequest(Message* message);

	void  onPlayerChangeNotify(Message* message);


	void onPlayerStateChange(Message* message);

	void onGetBossCntInCrossMapRequest(Message* message);

	void onServerDaysNotify(Message* message);


	void onEnterGameGuajiRequest(Message* message);

	void onNotifyInitDreamNotify(Message *message);

	void onRemoveChatRequest(Message *message);

	void onNotifyCrossFlagNotify(Message *message);
		
	void onSyncGuildDeletedNotify(Message *message);
	void onSyncPlayerDeletedNotify(Message *message);
	void onSyncGuildRenameNotify(Message *message);
	void onSyncPlayerRenameNotify(Message *message);

	void onGSBroadcastAllGSRequest(Message *message);

	void onChangeWorldDataFromGsRequest(Message *message);
	void onResetCritTempDataRequestFromGs(Message* message);

	void onRemoveCSGeneFromeGSNotify(Message *message);
	void onDoctorPlayerNotify(Message *message);

	void onGetPlayerBaseInfoFromCSRequest(Message *message);

	void onGetPlayerBaseInfoFromGSResponse(Message *message);

	void onReceiveGSRankList(Message *message);
};

#endif	//_CS_MSG_HANDLER_H_INCLUDED

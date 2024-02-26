#ifndef _GS_MSG_HANDLER_H_INCLUDED
#define _GS_MSG_HANDLER_H_INCLUDED

#include "common/Module.h"

class GSMsgHandler : public Module
{
public:
	GSMsgHandler(Service *service);
	virtual ~GSMsgHandler();

	virtual const char *getName() const { return "GSModule"; }

	virtual bool initialize();

private:
	//center server --> game server
	void onWarZoneInfoNotify(Message* message);
	void onFindNewCrossServerNotify(Message* message);
	void onSendCrossMailFromCenter(Message* message);

private:
	//cross server --> game server
	void onCS2GS(Message* message);
	void onCreatePlayerInCrossServerResponse(Message* message);
	void onLeaveFromCrossServerMapResponse(Message* message);
	void onSyncInfoToGameServerRequest(Message* message);

	void onSyncWordDataToGameServerRequest(Message* message);


	void onNotifyGameServerExpAdd(Message* message);
	void onNotifyGameServerItemAdd(Message* message);
	void onGetPlayerEquipInfoRequest(Message* message);
	void onCrossMapDropRequest(Message* message);
	void onReviveInCSMapResponse(Message* message);
	void onConveyToSceneRequest(Message* message);
	void onSyncEventDataRequest(Message* message);
	void onSyncCSPosToGSNotify(Message* message);
	void onSyncBossInfoToGSNotify(Message* message);
	void onAddGeneInGameServerRequest(Message* message);
	void onRmvGeneFromGameServerRequest(Message* message);
	void onGetQualifiedPlayerListNearbyResponse(Message* message);
	void onSyncWarZoneDropInfo(Message* message);
	void onCrossGetPlayerSerializeInfoC2G(Message* message);

	//���������
	void onCrossAuctionItemAddNotify(Message* message);
	void onCrossAuctionItemRmvNotify(Message* message);
	void onCrossAuctionItemUpdNotify(Message* message);
	void onCheckBuyCrossAuctionItemRsp(Message* message);
	void onBuyCrossAuctionItemRsp(Message* message);
	void onCrossAuctionRecordNotify(Message* message);

	//���������
	void onCrossConsignmentAddNotify(Message* message);
	void onCrossConsignmentRmvNotify(Message* message);
	void onCrossConsignmentUpdNotify(Message* message);
	void onAddConsignmentToCrossRsp(Message* message);
	void onCheckBuyCrossConsignmentRsp(Message* message);
	void onSendSellerRewardRsp(Message* message);
	void onRmvCrossConsignmentRsp(Message* message);
	void onSyncAllCrossConsignmentNotify(Message* message);

	//�����
	void onCrossPurchaseAddNotify(Message* message);
	void onCrossPurchaseRmvNotify(Message* message);
	void onCrossPurchaseUpdNotify(Message* message);
	void onAddPurchaseToCrossRsp(Message* message);
	void onTrySellCrossPurchaseRsp(Message* message);
	void onSendBuyerPurchaseItemRsp(Message* message);
	void onRmvCrossPurchaseRsp(Message* message);
	void onSyncAllCrossPurchaseNotify(Message* message);

	//����ڿ������Ϊ
	void onPlayerCSActionNotify(Message* message);

	//����������
	void onCrossChatNotify(Message * message);
	//����鿴��ɫװ��
	void onGetPlayerEquipInfoResponse(Message * message);

	void onNewGetPlayerEquipInfoResponse(Message* message);

	void onGetBossCntInCrossMapNotify(Message* message);

	void onSyncSkillExpAddToGameServer(Message* message);

	void onRemoveChatCrossNotify(Message* message);

	//��Ծ�Ȼ���
	void onAddHYDScore(Message *message);

	//����ʬ������ս����
	void onSendSWZDZAward(Message *message);

	//��������������
	void onSendSWYAward(Message *message);

	//�����л��ս����
	void onSendGuildBattleAward(Message *message);

	void onGSBroadcastAllGSResponse(Message *message);

	void onGetPlayerBaseInfoFromGSRequest(Message *message);
	void onGetPlayerBaseInfoFromCSResponse(Message *message);

	void onLoadCSRank(Message *message);
	void onReceiveCSRankList(Message *message);

	void onSendPlayerGreyNameToGS(Message* message);
	void onSendPlayerKillWhiteRoleToGS(Message* message);
};

#endif	//_GS_MSG_HANDLER_H_INCLUDED

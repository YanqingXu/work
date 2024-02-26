#ifndef _GS_HELPER_H_INCLUDED
#define _GS_HELPER_H_INCLUDED
#include "message/definition.h"

class Entity;
class EntityPlayer;
class Message;
struct DBAcution;
class Item;
class Guild;

namespace GSHelper
{
	int enterCSMap(Entity* entity , int dstMapId, int posX, int posY);  //����Ϸ����ͼ��������ͼ
	int switchCSMap(Entity* entity , int dstMapId, int posX, int posY);  //�ӵ�ǰ�����ͼ�л�����һ�ſ����ͼ
	int enterGSMap(Entity* entity, int reason = 0, int dstMapId = 0, int posX = 0, int posY = 0,int sceneInstanceId = 0,int enterSceneType = ENTER_SCENE_DEFAULT); //������Ϸ����ͼ

	void kickPlayerFromCS(EntityPlayer* player);  //�����������
	void createPlayerInCrossServer(EntityPlayer *player, int crossServerId, int dstMapId,  int posX, int posY); //�ڿ����������������Ҷ���
	void revivePlayerInCS(EntityPlayer* player, int type, int subType);//�����ͼ����
	void useItemInCSMap(Entity* entity, int sid, int count, int rid, int targetType);
	void syncEventDataToCS(Entity* entity, int eid);
	void resetAndSyncAllEventToCS(Entity* entity);
	void getQualifiedPlayerListNearby(EntityPlayer* player, int condition);  //��ȡ����Ҫ����ܱߵ����

	//��ҿ����Ϊ�Ļص�
	void playerCSActionTrigger(Entity* entity, int actionType, std::map<int, int>& intParams, std::map<int, std::string>& strParams);

	//������
	bool addItemToCrossAuction(DBAcution* au);
	int checkBuyCrossAuctionItem(EntityPlayer* player, int64 aid, short type, int payMoney = 0);  //���Ŀ����������Ʒ
	int buyCrossAuctionItem(EntityPlayer* player, int64 aid, short type);

	//������
	void addCrossConsignment(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName, std::string firstOwner, std::string appraiser,std::map<int,int> props, int cTime = 0, int eTime = 0,int mailTip = 0);
	void rmvCrossConsignment(int pid, int cid, int warZoneId);

	//��
	void addCrossPurchase(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName);
	void rmvCrossPurchase(int buyerPid, int purchaseId, int warZoneId);

	//test
	void sendGSToGSTestMsg();

	void onWarZoneChanged(int oldWarZoneId, int newWarZoneId);


	void wrapSceneMessage(Entity& entity, Message* msg); //��װ������Ϣ���������

	//ͬ����ҵȼ������
	void sendPlayerLevelToCross(EntityPlayer* player);


	void sendPlayerStateToCross(EntityPlayer* player,int m_state);

	void getBossCntInCrossMap(EntityPlayer& player, std::map<short, int>& crossMaps,std::string targetName);

	void sendCrossInitDream(EntityPlayer * player);
		
	//�Ƿ��Ѿ�����ս������Ϸ�������������ж�����Ҫ��ս��������Ϣ
	bool isWarZoneGameServer();
	//ͬ����ɫɾ����Ϣ
	void syncPlayerDeletedToCross(int pid);	
	//ͬ���л��ɢ��Ϣ
	void syncGuildDeletedToCross(int guildid);
	//ͬ����Ҹ�����Ϣ
	void syncPlayerRenameToCross(int pid, const std::string& newname);
	//ͬ�����������Ϣ
	void syncGuildRenameToCross(int guildid, const std::string& newname);
	//ͬ������᳤��Ϣ
	void syncGuildMasterToCross(int guilid, int pid);
	//ͬ�����ְҵ��Ϣ
	void syncPlayerJobToCross(int pid, int job);



	void removeGeneToCross(int pid, int geneid); 

	void doctorPlayerToCorss(int pid);
};

#endif	//_GS_HELPER_H_INCLUDED

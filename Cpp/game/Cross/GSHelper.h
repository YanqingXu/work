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
	int enterCSMap(Entity* entity , int dstMapId, int posX, int posY);  //从游戏服地图进入跨服地图
	int switchCSMap(Entity* entity , int dstMapId, int posX, int posY);  //从当前跨服地图切换到另一张跨服地图
	int enterGSMap(Entity* entity, int reason = 0, int dstMapId = 0, int posX = 0, int posY = 0,int sceneInstanceId = 0,int enterSceneType = ENTER_SCENE_DEFAULT); //进入游戏服地图

	void kickPlayerFromCS(EntityPlayer* player);  //提出跨服的玩家
	void createPlayerInCrossServer(EntityPlayer *player, int crossServerId, int dstMapId,  int posX, int posY); //在跨服服务器创建出玩家对象
	void revivePlayerInCS(EntityPlayer* player, int type, int subType);//跨服地图复活
	void useItemInCSMap(Entity* entity, int sid, int count, int rid, int targetType);
	void syncEventDataToCS(Entity* entity, int eid);
	void resetAndSyncAllEventToCS(Entity* entity);
	void getQualifiedPlayerListNearby(EntityPlayer* player, int condition);  //获取满足要求的周边的玩家

	//玩家跨服行为的回调
	void playerCSActionTrigger(Entity* entity, int actionType, std::map<int, int>& intParams, std::map<int, std::string>& strParams);

	//拍卖行
	bool addItemToCrossAuction(DBAcution* au);
	int checkBuyCrossAuctionItem(EntityPlayer* player, int64 aid, short type, int payMoney = 0);  //竞拍跨服拍卖行物品
	int buyCrossAuctionItem(EntityPlayer* player, int64 aid, short type);

	//寄售行
	void addCrossConsignment(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName, std::string firstOwner, std::string appraiser,std::map<int,int> props, int cTime = 0, int eTime = 0,int mailTip = 0);
	void rmvCrossConsignment(int pid, int cid, int warZoneId);

	//求购
	void addCrossPurchase(int pid, int sid, int count, int price, int hours,std::string name, int taxRate, std::string srcServerName);
	void rmvCrossPurchase(int buyerPid, int purchaseId, int warZoneId);

	//test
	void sendGSToGSTestMsg();

	void onWarZoneChanged(int oldWarZoneId, int newWarZoneId);


	void wrapSceneMessage(Entity& entity, Message* msg); //包装场景消息并发给跨服

	//同步玩家等级到跨服
	void sendPlayerLevelToCross(EntityPlayer* player);


	void sendPlayerStateToCross(EntityPlayer* player,int m_state);

	void getBossCntInCrossMap(EntityPlayer& player, std::map<short, int>& crossMaps,std::string targetName);

	void sendCrossInitDream(EntityPlayer * player);
		
	//是否已经开启战区的游戏服务器，用于判断是需要想战区发送消息
	bool isWarZoneGameServer();
	//同步角色删除信息
	void syncPlayerDeletedToCross(int pid);	
	//同步行会解散信息
	void syncGuildDeletedToCross(int guildid);
	//同步玩家改名信息
	void syncPlayerRenameToCross(int pid, const std::string& newname);
	//同步公会改名信息
	void syncGuildRenameToCross(int guildid, const std::string& newname);
	//同步公会会长信息
	void syncGuildMasterToCross(int guilid, int pid);
	//同步玩家职业信息
	void syncPlayerJobToCross(int pid, int job);



	void removeGeneToCross(int pid, int geneid); 

	void doctorPlayerToCorss(int pid);
};

#endif	//_GS_HELPER_H_INCLUDED

#ifndef _CS_HELPER_H_INCLUDED
#define _CS_HELPER_H_INCLUDED
#include <string>
#include <map>
#include <vector>
#include "message/definition.h"
class Entity;
class EntityPlayer;
class Scene;
class Gene;
struct RyzRank;
struct DBAcution;
struct Consignment;
struct Purchase;

namespace CSHelper
{
	void leaveCSMap(int pid , int sourceServerId, int reason = 0, int dstMapId=0, int posX=0, int posY=0, int sceneInstanceId = 0,int enterSceneType = ENTER_SCENE_DEFAULT);
	void enterCSMap(int pid, int dstMapId, int posX, int posY);
	void sendCrossDropRequest(Entity* player, Entity* killer);
	int conveyToScene(Entity* player, int mapId, int posX, int posY);
	void syncEventDataToGS(Entity* player, int eid);
	void syncPlayerPropToGS(Entity *player,int prop,int value);
	void syncPosToGS(EntityPlayer* player);
	void createPlayerInCrossServerFinished(EntityPlayer* player);
	void syncBossInfoToGS(Scene* scene, int bossIndex = 0, int gameServerId = 0);
	void getQualifiedPlayerNearby(EntityPlayer* player, int condition);
	void broadcastDropToWarZone(int killerPid, std::string killerName, int killerServerId, int mapId, int monsterId, int dropItemId, int dropTime, bool top);
	void addGeneInGS(Entity* entity, Gene* gene);
	void rmvGeneFromGS(Entity* entity, int id);
	
	void onWarZoneChanged();

	//������ڿ������Ϊ������ԭ��������ԭ����������߼�(�����ɾͣ� �������ȵȣ�
	void notifyPlayerActionToGS(int pid, int gameServerId, int actionType, std::map<int, int>& intParams, std::map<int, std::string>& strParams);

	//������������
	void broadcastCrossAuctionItemAddToWarZone(DBAcution* au);
	void broadcastCrossAuctionItemRmvToWarZone(DBAcution* au);
	void broadcastCrossAuctionItemUpdToWarZone(DBAcution* au);

	//���������
	void broadcastCrossConsignmentAddToWarZone(Consignment* consignment);
	void broadcastCrossConsignmentRmvToWarZone(Consignment* consignment);
	void broadcastCrossConsignmentUpdToWarZone(Consignment* consignment);
	void syncAllCrossConsignmentToGS(int gameServerId);

	//�����
	void broadcastCrossPurchaseAddToWarZone(Purchase* purchase);
	void broadcastCrossPurchaseRmvToWarZone(Purchase* purchase);
	void broadcastCrossPurchaseUpdToWarZone(Purchase* purchase);
	void syncAllCrossPurchaseToGS(int gameServerId);

	void removeChatToAllWarZone(int pid, int src_server_id);

	void SyncCrossActivityToGS(int gameServerId, bool reset = false);

	//��ԭ��Ҫ������а�����
	void loadCrossRankFromToGS(int gameServerId);
	//��������а�����ͬ����ԭ��
	void syncCrossRankToGS(int type, int warZoomId = 0);

	void bindGameServerIdBySessionId(int session_id, int server_id);
	void unbindGameServerIdBySessionId(int session_id);
	int getGameServerIdBySessionId(int session_id);

	void CS2GS(Entity& entity, int funcid, int datax, int datay, int dataz, const std::string& datas);
	void CS2GS(int game_server_id, int funcid, int pid, int datax, int datay, int dataz, const std::string& datas);

	// �㲥��ս�������з�����
	void CS2WZ(int warZoneId, int funcid, int pid, int datax, int datay, int dataz, const std::string& datas);

}

#endif	//_CS_HELPER_H_INCLUDED

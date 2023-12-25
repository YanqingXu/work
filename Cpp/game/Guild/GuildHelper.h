#ifndef _GUILD_HELPER_H_INCLUDED
#define _GUILD_HELPER_H_INCLUDED

#include "Guild.h"
#include "message/definition.h"

class Scene;
class Entity;
class EntityPlayer;
struct ShopGuishiItem;

namespace GuildHelper
{

	// 初始化成员信息
	void initMemberMsgInfo(GuildMember* pMem, GuildMemberInfo* pInfo);

	// 设置成员在线状态
	int setGuildMemberOnline(Entity& player, bool bOnline);

	// 设置成员所在场景
	int setGuildMemberScene(const Entity& player, int sceneid);

	//创建行会
	int createGuild(EntityPlayer &player, const std::string &guild_name,std::string &placard,int level);

	//增加行会申请
	int addGuildApplication(Guild &guild, Entity &entity);

	// 检测事是否已经加入过公会
	int CheckHaveApplicationedGuild(Guild &guild, Entity &entity);

	//一键增加行会申请
	int autoAddGuildApplication(EntityPlayer *player);

	//设置离线时间
	int setGuildMemberOffTime(Guild &guild,EntityPlayer& player);

	//处理加入行会申请
	int decideApplication(EntityPlayer &player, short decide, int other_player_id);

	//处理gm加入行会并且提升会长
	int decideGMApplicationAndUpdataGuildMaster(int guildid , int other_player_id);

	//拒绝所有加入行会申请
	int refuseAllApplication(EntityPlayer &player);

	//通过所有加入行会申请
	int passAllApplication(EntityPlayer &player);

	//增加行会成员
	void addGuildMember(Guild &guild, int player_id, int reborn, int level, int job, int gender, const std::string &name, int spGrade);

	// 变更会长
	int changeMaster(Guild &guild, int new_master_pid);
	int resetGuildMaster(Guild &guild, int srcpid, int tgtpid);

	int gmChangeMaster(Guild &guild, int new_master_pid);

	//同步行会所有信息
	void syncGuildAllInfo(EntityPlayer &player);

	void syncMyGuildInfo(EntityPlayer &player);

	//同步行会列表(按页)
	//void syncGuildByPage(EntityP &player, int page);
	void syncGuildList(EntityPlayer &player);

	void syncApplicationChange(Guild &guild, int pid);

	void syncMemberChange(Guild &guild, int pid);
	
	void syncProp(Guild &guild, int idx);
	void saveProp(Guild &guild, int idx);

	void syncStringProps(Guild &guild, int idx);
	void saveStringProps(Guild &guild, int idx);

	// 下发视野内行会名字
	void syncMeetGuildName(Entity& entity);

	//退出行会
	int leaveGuild(EntityPlayer &player);

	//踢除行会成员
	int kickPlayer(EntityPlayer &player, int player_id);
	
	int getGuildReward(EntityPlayer &player,int index);

	bool getGuildDefaultNicknameData(int job, std::string& nickname);

	//邀请加入行会
	int inviteGuildMember(EntityPlayer *player, EntityPlayer *target, Guild *guild);
	int inviteGuildMemberResult(int gid, EntityPlayer &entity, int pDecide);
	//普通玩家邀請好友入會和官员会员邀请规则一致
	int inviteFriendsToGuildWithCustomMember(EntityPlayer *player, EntityPlayer *target, Guild *guild);

	void syncGuildFloatNotice(Guild &guild, const std::string &msg);

	//变更行会公告或行会宣言
	int	changeGuildNotice(EntityPlayer &player, int idx, const std::string &str);

	// GM命令改变公会公告
	int changeNoticeByGM(int guildid, const std::string &str);

	//设置成员职务
	int setMemberGuildPost(EntityPlayer &player, int player_id, int post);

	//设置成员是否可以说话
	int setMemberGuildSpeek(EntityPlayer &player, int player_id, int speek);

	void syncGuildVersion(Entity &entity);

	//删除行会
	void releaseGuild(int guild_id, int reason, int pid = 0, const std::string &pname = "");

	int checkGuildCoin(Entity &entity, int coin);
	int checkGuildIngot(Entity &entity, int ingot);
	//添加金币
	int addGuildCoin(Entity &entity, int coin);
	int addGuildIngot(Entity &entity, int ingot);

	//增加(或减少)行会贡献
	int addGuildContribution(Entity &entity, int contribution, int opcode = 0, int opdata = 0);
	//重置当天的行会贡献
	int resetTodayContribution(Entity &entity);

	int openGuildBuff(EntityPlayer &player, int buff_id);

	//更改行会名称
	int renameGuild(EntityPlayer *player, const std::string &newname);
	int	renameResponse(EntityPlayer &player, const std::string &newname);

	//增加行会事件
	void addRecord(int guild_id, short type, int datax, int datay, const std::string &namex, const std::string &namey);
	void addRecord(Guild *guild, short type, int datax, int datay, const std::string &namex, const std::string &namey);

	//增加行会活跃度
	bool addVitality(Guild *guild, int count);
	//使用行会活跃度
	bool useVitality(Guild *guild, int count, int reason = 0, int data = 0);
	//是否有足够的行会活跃度
	bool haveVitality(Guild *guild, int count);
	// 更新玩家活跃度
	void updateMemberVitality(Guild *guild, int player_id, int value);

	// 玩家删号处理
	void handlePlayerDelete(int guild_id, int player_id);

	// 发红包
	int sendRedPackage(Entity *player, int redtype, int max_gold, int max_count, const std::string &desc);
	void addRedPackage(Guild *guild, int redtype, int max_gold, int max_count, const std::string &desc);
	// 更新红包
	int updateRed(EntityPlayer *player, int redid, int guild_id, int &retGold);
	// 返回红包
	void backRed(Guild *guild, bool dismiss = false);
	// 获得可领取的红包
	std::vector<int> getRedCount(EntityPlayer *player, Guild *guild, int redID);

	// 添加红包日志
	int addRedRecord(int redtype,int spid, const std::string &sname, int dpid, const std::string &dname, int redid, int gold, int type);

	//存放物品
	int depositItem(EntityPlayer *player, int item_id);

	//取出物品
	int withdrawItem(EntityPlayer *player, int item_id);

	//删除物品
	int delItem(EntityPlayer *player, int item_id);

	// 同步物品信息
	int sysItem(EntityPlayer *player);
	// 同步公会商店信息
	int syscGuildShopToPlayer(EntityPlayer &player);

	// 同步鬼市
	int syscGuildGuishiToPlayer(EntityPlayer &player);


	//将行会的物品item_id
	int syncGuildItemInfo(Entity *player, int guild_id, int item_id);

	//增加结盟申请(guild1向guild2申请结盟)
	int addLeagueApp(Guild *guild1, Guild *guild2);
	//删除结盟申请
	int delLeagueApp(Guild *guild1, Guild *guild2);
	//设置结盟
	int setLeague(Guild *guild1, Guild *guild2);

	//清除所有行会
	void clearGuilds();

	void sendGuildRecommendNotify(Entity *entity, int exclude_guild_id);
	//捐献物品(特殊处理)
	int donateItem(EntityPlayer *player, int item_id);

	//创建公会队伍
	int createGuildTeam(Entity *player);
	//加入公会队伍
	int joinGuildTeam(Entity *player, int teamid);
	//匹配公会队伍
	int searchGuildTeam(Entity *player);
	//退出公会队伍
	int exitGuildTeam(Entity *player, Guild *guild);

	int sendGuildChat(Entity *player);

	//同步采集列表
	void syncGuildGatherList(Scene *scene);
	/**
	 * @brief 通知公会采集击杀
	 * @param scene 场景
	 * @param killer 击杀者
	 * @param target 被杀者
	 * @param cnt 0是被杀者被终结  其他是击杀者的连杀数
	 */
	void syncGuildGatherKill(Scene *scene, Entity *killer, Entity *target, int cnt);

	//同步公会采集结算
	void syncGuildGatherBlance(Scene *scene, std::vector<Balance> &balanVec);

	//保存行会商店物品
	void saveGuildShopItem(Guild &guild, int sid);
	
	// 初始化行会商店物品
	void initGuildShop();

	// 同步商店物品信息
	void syncGuildShop(Guild &guild);

	// 购买帮会商店物品
	int buyItem(EntityPlayer &player, int sid, int cnt);

	// 清理帮会商店物品
	void DelShopItems();
	//购买公会限购道具
	void updataGuildShopItemSellNum(Guild &guild, int sid,int num);

	void autoChangeMaste();

	//同步公会镖车血量
	void updateGuildDartHP(Guild &guild);

	//同步公会镖车位置
	void updateGuildDartPosition(Guild &guild);

	//重置公会镖车信息
	void resetGuildDartInfo(Guild &guild);

	//保存鬼市商店物品
	void saveGuildGuishiItem(Guild &guild, ShopGuishiItem *item);

	// 同步鬼市
	void syncGuildGuishi(Guild &guild);
	//从数据库中删除鬼市
	void saveGuildGuishiItemDelete(Guild &guild, int item_id, Entity *entity = nullptr);
	//同步行会物品删除给玩家
	void syncGuildGuishiItemDelete(Guild &guild, int item_id);
	//同步鬼市物品添加给玩家
	void syncGuildGuishiItemAdd(Guild &guild, ShopGuishiItem *item);
	void mergeGuild(int gid1, int gid2);
}


#endif	//_GUILD_HELPER_H_INCLUDED

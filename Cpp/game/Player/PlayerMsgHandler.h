#ifndef _PLAYER_MSG_HANDLER_H_INCLUDED
#define _PLAYER_MSG_HANDLER_H_INCLUDED

#include "common/Module.h"

struct OtherEntityPropDB;
struct OtherEntityStringPropDB;
struct OtherEquipInfoDB;
class PlayerMsgHandler : public Module
{
public:
	PlayerMsgHandler(Service *service);
	virtual ~PlayerMsgHandler();

	virtual const char *getName() const { return "PlayerModule"; }

	virtual bool initialize();

private:
	// 查询玩家属性
	void onGetPlayerTypeData(Message *message);

	// 设置PK模式
	void onSetPkModeRequest(Message *message);

	// 聊天
	void onChatRequest(Message *message);

	// 禁言
	void onShutUpRequest(Message *message);

	// 兑换转生修为
	void onExchangeRebornPointsRequest(Message *message);

	// 转生
	void onRebornRequest(Message *message);

	// 兑换轮回修为
	void onExchangeSamsaraPointsRequest(Message *message);

	// 轮回
	void onSamsaraRequest(Message *message);

	// 主动同步数据
	void onSyncPlayerEventDataRequest(Message *message);

	// 获取其他玩家数据
	void onGetOtherPlayerDataRequest(Message *message);

	// 领取礼品
	void onGetGiftRequest(Message *message);

	// 调用功能脚本?
	void onFuncDataOperator(Message *message);

	// 打开称号
	void onOpenHeadTitleRequest(Message *message);

	// 关闭称号
	void onCloseHeadTitleRequest(Message *message);

	// 改名请求
	void onRenameRequest(Message *message);

	// 查看玩家装备
	void onCheckEquipRequest(Message *message);

	// 查看魂石
	void onCheckSoulStoneRequest(Message *message);

	// 请求活动数据
	void onEventDataRequest(Message *message);

	// 领取离线经验
	void onGetOfflineExp(Message *message);

	// 打开内功
	void onExerciseRequest(Message *message);

	// 内功提升
	void onExerciseUpdataRequest(Message *message);

	// 打开翅膀
	void onOpenWingsRequest(Message *message);

	// 升级翅膀
	void onUpdataWingsRequest(Message *message);

	// 更换翅膀穿戴
	void onChangeWingDressRequest(Message *message);

	// 提升翅膀
	void onImproveWingRequest(Message *message);

	// 提升bs积分
	void onUpdataBossScoreRequest(Message *message);

	// bs积分兑换
	void onUpdataBsscCnRequest(Message *message);

	// vip经验
	void onGetVipExpBuffRequest(Message *message);

	// 更新事件信息
	void onRefreshEventDataRequest(Message *message);

	// 进入挂机
	void onOpenAutoAtkMapRequest(Message *message);

	// 开始挂机
	void onStartOffLineRequest(Message *message);

	// 挂机奖励
	void onOfflineTakeRewardRequest(Message *message);

	// vip
	void onOfflineVipRewardRequest(Message *message);

	// 打开挂机
	void onOpenOffLineRequest(Message *message);

	// 停止挂机
	void onCloseOffLineRequest(Message *message);

	// 获取等级奖励
	void onGetLevelRewardRequest(Message *message);

	// 强化部位
	void onEnhancePosRequest(Message *message);

	// 装备附灵
	void onFulingRequest(Message *message);

	// 装备附灵转移
	void onFulingZYRequest(Message *message);

	// 魂石升级
	void onStonePosRequest(Message *message);

	// 穿戴或脱下时装
	void onPlayerDressOperatorRequest(Message *message);

	// 衣橱升级
	void onPlayerDressWardrobeUpRequest(Message *message);
	// 加载宝宝
	void onPlayerLoadPetRequest(Message *message);

	// 萌宠操作
	void onPlayerLovelyPetRequest(Message *message);

	// 购买宝宝技能礼包处理
	void onPlayerBuyBaoBaoSkill(Message *message);

	// 设置时装状态
	void onSetDressStatusRequest(Message *message);

	// 兑换技能书
	void onExchangeSkillBookRequest(Message *message);

	void onUpdateCSPosRequest(Message *message);

	// 领取蓝月达人奖励
	void onGetMasterRewardRequest(Message *message);

	// 开启特权
	void onOpenPrivilegeRequest(Message *message);
	// 领取特权奖励
	void onGetPrivilegeRewardRequest(Message *message);
	// 特权续费
	void onRenewPrivilegeRequest(Message *message);
	// 限时任务状态
	void onUpdateXSRWTaskStateRequest(Message *message);
	// 合成图标icon状态
	void onUpdateComposeStateRequest(Message *message);
	// 商店购买引导状态
	void onUpdateShopGuideRequest(Message *message);

	// 爬塔
	void onChallengeTowerRequest(Message *message);

	// 获得爬塔奖励并且退出
	void onGetTowerRewardRequest(Message *message);

	// 购买每日特惠
	void onBuyDailyItemRequest(Message *message);

	// 刷新个人BOSS次数
	void onCalcMyBossTimesRequest(Message *message);

	// 爬塔扫荡
	void onGetTowerSweepRequest(Message *message);
	// 挖宝箱
	void onBossBoxDigRequest(Message *message);

	// 红名保释请求
	void onGetBailRequest(Message *message);

	// 产生邀请码
	void onCreateRoleCodeRequest(Message *message);

	// 请求邀请码信息
	void onCreateRoleCodeInfoRequest(Message *message);

	// 请求同步野外boss时间
	void onUpdateBossTimeRequest(Message *message);

	void onSyncTabRequest(Message *message);

	void onMsgPlayerJuHePayRequest(Message *message);

	void onMsgPlayerChatVeriPhoneRequest(Message *message);

	void onMsgPlayerChatVeriCodeRequest(Message *message);

	void onMsgCommonOperatorRequest(Message *message);

	void onMsgGetMapStatisticsDataRequest(Message *message);

	void onFabaoUpRequest(Message *message);

	void onOperationRecordNotify(Message *message);

protected:
	// 加载玩家属性
	void onDBLoadPlayerExData(Message *message);

	// 加载玩家事件数据
	void onDBLoadPlayerEvent(Message *message);

	// 加载玩家基因
	void onDBLoadPlayerGene(Message *message);

	// 加载玩家技能
	void onDBLoadSkill(Message *message);

	// 加载宠物技能
	void onDBLoadPetSkill(Message *message);

	// 添加宠物技能
	void onDBAddPetSkill(Message *message);

	// 改性
	void onDBGenderResponse(Message *message);

	// 改名
	void onDBRenameResponse(Message *message);

	// 加载玩家装扮
	void onDBLoadPlayerDress(Message *message);

	// 加载玩家 文本属性
	void onDBLoadPlayerStrData(Message *message);

	// 五星好评
	void onDBCheckAppStoreCommentRewarded(Message *message);

	// 离线收入
	void onDBLoadIncome(Message *message);

	// 开启特戒
	void onOpenSpecialRingRequest(Message *message);

	// 获取奖励（石墓迷阵）
	void onAskForRewardRequest(Message *message);

	// 世界boss 鼓舞
	void onTTSYGuWuRequest(Message *message);

	// 人物等级兑换修为
	void onMsgPlayerLvChangeCultRequest(Message *message);
	// VIP客服
	void onVipServiceShowCheckRequest(Message *message);
	// 附近玩家
	void PlayerMsgHandler::onNearbyPlayerRequest(Message *message);
	//
	void PlayerMsgHandler::onNearbyPlayerCheckRequest(Message *message);

	// 神魂系统数据请求
	void PlayerMsgHandler::onAskforSoulSystemInfoRequest(Message *message);

	// 炼魂
	void PlayerMsgHandler::onImproveSoul(Message *message);

	// 兑换魂力
	void PlayerMsgHandler::onExchangeSoulRequest(Message *message);

	// 请求开启第二仓库
	void PlayerMsgHandler::onOpenSecWarehouseRequest(Message *message);

	// 一键使用
	void PlayerMsgHandler::onQuickUseItemsRequest(Message *message);

	// 黑铁矿兑换玄铁矿
	void PlayerMsgHandler::onSyntheticRequest(Message *message);

	// 分解装扮
	void PlayerMsgHandler::onDecomposeDress(Message *message);

	// 更新服务器的名称
	void PlayerMsgHandler::onUpdServerNameRequest(Message *message);

	// 请求升级
	void PlayerMsgHandler::onLevelUpRequest(Message *message);

	// 聊天记录请求
	void onKeepMsgRequest(Message *message);

	// 官阶升级
	void PlayerMsgHandler::onUpgradeGuanJieRequest(Message *message);

	// 官印升级
	void PlayerMsgHandler::onUpgradeGuanYinRequest(Message *message);

	// 技能升级
	void PlayerMsgHandler::onUpgradeSkillLevelRequest(Message *message);

	// 刷新洗练
	void onSmeltRefreshRequest(Message *message);

	// 洗练替换
	void onSmeltReplaceRequest(Message *message);
	// 清空右侧洗练出的属性
	void onSmeltClearNewAttrsRequest(Message *message);

	// 幸运直升满级
	void onLuckyImmedFullLevelRequest(Message *message);

	// 魂石
	void onSpiritStoneRequest(Message *message);
	// 魂石合成
	void onSpiritStoneMakeRequest(Message *message);

	void onExchangeHegemonEquipShowt(Message *message);
	// 圣兽升级
	void onTherionLevelRequest(Message *message);
	// 加载跨服数据
	void PlayerMsgHandler::onDBLoadPlayerCrossEvent(Message *message);

	// 获取练功房奖励
	void onPlayerGetTrainingRewardRequest(Message *message);
	// 购买特戒礼包
	void onPlayerGetSpecialRingGifrRequest(Message *message);

	// 钻石兑换元宝
	void onExchangeIngotRequest(Message *message);
	// 石墓烧猪操作
	void onRoastPigRequest(Message *message);
	// 月卡奖励领取
	void onMonthCardGetRewardRequest(Message *message);
	// 会员操作
	void onMemberOpeartionRequest(Message *message);

	// 激活新vip
	void onNewVipActiveRequest(Message *message);

	// 升级新vip
	void onNewVipLvlUpRequest(Message *message);

	// 挑战新vip副本
	void onNewVipChallengeRequest(Message *message);

	// 领取新vip副本星数奖励
	void onNewVipGetStarRewardRequest(Message *message);

	// 新vip提交任务
	void onNewVipSubmitQuestRequest(Message *message);

	// 激活器灵
	void onActiveQiLingRequest(Message *message);

	// 开始挖藏宝结果
	void onOpenTheasureMapRequest(Message *message);
	// 挖藏宝地图位置
	void onGetTheasureMapPosRequest(Message *message);
	// 藏宝图进入FB 获取奖励
	void onOpenTheasureMapGetAwardRequest(Message *message);

	// 获取玩家信息
	void onDBLoadPlayerEquipInfo(Message *message);

	void onDBLoadOtherPlayerInfo(Message *message);

	// 购买额外归属奖励次数
	void onGetXiYouRewardCountRequest(Message *message);

	// 领取历练之路奖励
	void onExpRoadRewardRequest(Message *message);

	// 检测私聊目标玩家在不在线
	void onPrivateChatOnlineCheckRequest(Message *message);

	// 领取天关秘境，pve爬塔，扫荡奖励
	void onTgmjTowerClearRequest(Message *message);

	// 领取天关秘境，pve爬塔，扫荡奖励
	void onBloodUpRequest(Message *message);

	void onMsgGetBossCntInMapRequest(Message *message);

	// 安全区医生
	void onDoctorRequest(Message *message);
	// 转职
	void onUpdatePlayerClass(Message *message);
	// 透视
	void onToushiRequest(Message *message);
	// 兑换码
	void onGetGiftByCodeRequest(Message *message);
	// 领取内置活动奖励
	void onActivityRewardRequest(Message *message);
	// 内置操作请求
	void onActivityOperateRequest(Message *message);

	void onGetPlayerBaseInfoRequest(Message *message);
	void onLoadPlayerBaseInfo(Message *message);
	int getPropValue(int ptype, std::vector<OtherEntityPropDB> values);
	int getEquipValue(int position, std::vector<OtherEquipInfoDB> values);
	std::string getStringPropValue(int ptype, std::vector<OtherEntityStringPropDB> values);
};

#endif //_PLAYER_MSG_HANDLER_H_INCLUDED

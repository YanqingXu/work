#ifndef _GUILD_H_INCLUDED
#define _GUILD_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "message/MsgGuild.h"
#include "message/MsgPlayer.h"

class EntityPlayer;
class Message;
class GuildItemManager;
class GuildTeamM;
class GuildShop;
class GuildGuishi;

//行会成员
class GuildMember
{
public:
	GuildMember() :
		player(NULL),
		player_id(0),
		contribution(0),
		contribution_today(0),
		post(0),
		force(0),
		intime(0),
		offTime(0),
	    speek(0),
		job(0)
	{
		rank_day = 0;
		rank = 0;
		vitality = 0;
		kfyz_time = 0;
	}

	EntityPlayer * getPlayer() const;

public:
	int			player_id;				//玩家ID
	EntityPlayer		*player;				//玩家实体(如果在线)
	std::string	player_name;			//玩家名称
	short		gender;					//性别
	short		level;					//等级
	int			force;				    //战力
	short		post;					//职务
	int			contribution;			//贡献
	int			contribution_today;		//当前贡献
	int			intime;					//加入行会时间
	int         offTime;                //离线时间
	int			job;					//职业

	int			rank_day;				//排名天
	int			rank;					//名次
	int         vitality;               //活跃度
	int			kfyz_time;				//参与跨服远征活动时间
	int         speek;                  //是否可以实时语音
	int			reborn;					//转生
	int 		sponsorGrade; 			//赞助等级
};

//申请加入行会
class GuildApp
{
public:
	int player_id;				//申请玩家ID
	std::string player_name;	//申请玩家名称
	int apptime;				//申请时间
	short job;					//申请玩家职业
	short gender;               //申请玩家性别
	short level;				//申请玩家等级
	int force;					//申请玩家战力
	short reborn;				//申请玩家转生等级
	short type;					//申请类型
	int sponsorGrade; 			//赞助等级
};


//行会
class Guild 
{
public:
	Guild();
	~Guild();

	//行会ID
	void setGuildID(int id) { m_id = id; }
	int getGuildID() const { return m_id; }

	//行会名称
	void setGuildName(const std::string &name) { m_name = name; }
	const std::string &getGuildName() const { return m_name; }

	void setCreateTime(int create_time) { m_create_time = create_time; }
	int getCreateTime() const { return m_create_time; }

	//整数属性
	void setProp(int idx, int datax);
	int getProp(int idx) const;	

	//字符串属性
	void setStringProp(int idx, const std::string &name);
	const std::string &getStringProp(int idx);

	//行会成员
	bool addMember(const GuildMember &member);
	void removeMember(int player_id);
	GuildMember *getMember(int player_id);
	//获取行会会长
	GuildMember *getMasterMember();
	//行会成员列表
	std::vector<GuildMember*> &getMembers() { return m_members; }
	//行会成员数量
	int getMemberCount() const;
	//获取公会在线人数
	int getOnlineMemberCount() const;
	//获取行会会长名称
	std::string getMasterName() const;
	//获取行会会长pid
	int getMasterPid() const;

	//获取行会可以语音的人数上限
	int getMemberSpeekCount() const;
	//获取职位成员数
	int getMemberCountByPost(int post) const;

	//加入申请
	void addApplication(const GuildApp &app);

	// 是否已经申请加入公会
	int hasApplicationed(int player_id);
	void removeApplication(int player_id);
	void clearApplication();
	GuildApp *getApplication(int player_id);
	std::vector<GuildApp*> &getApplications() { return m_apps; }

	//添加结盟申请
	void addActiveLeagueApp(int guild_id, int ctime);
	void addPassiveLeagueApp(int guild_id, int ctime);
	//删除结盟申请
	void delActiveLeagueApp(int guild_id);
	void delPassiveLeagueApp(int guild_id);
	//是否存在结盟申请
	bool hasActiveLeagueApp(int guild_id);
	bool hasPassiveLeagueApp(int guild_id);
	//获取结盟申请列表
	const std::vector<std::pair<int, int>> &getActiveLeagueApps() const { return m_active_league_apps; }
	const std::vector<std::pair<int, int>> &getPassiveLeagueApps() const { return m_passive_league_apps; }

	//给行会内所有在线成员发送消息
	void sendMessage(Message *message);
	void sendMessageToManager(Message *message);

	//获取行会事件
	const std::vector<GuildRecord> &getRecords() { return m_records; }
	//增加行会事件
	void addRecord(const GuildRecord &record);
	//添加行会红包
    void addRed(const GuildRed &red);
	//添加行会红包日志
	void addRedRecord(const GuildRedRecord &redrecord);
	//检查过期红包
	void CheckRed();
	//保存聊天消息
	void keepMessage(stcChatKeepInfo message);
	//获取行会红包
	std::vector<GuildRed>& getReds() { return m_reds; }

	//获取行会红包日志
	const std::vector<GuildRedRecord> &getRedRecords() { return m_red_records;}

	//获取物品管理器
	GuildItemManager *getItemManager() { return m_item_mgr; }

	//获取公会队伍管理器
	GuildTeamM * getTeamManager() { return m_team_mgr; }

	//获取物公会商城信息
	GuildShop *getShop() { return m_shop; }
	//行会总战力
	int64  getGuildCombat() const;

	GuildGuishi *getGuishi() { return m_guishi; }

private:
	int m_id;									//行会ID
	std::string m_name;							//行会名称
	int m_create_time;							//行会创建时间

	std::map<int, int> m_prop_map;				//行会属性
	std::map<int, std::string> m_strprop_map;	//行会属性

	std::vector<GuildMember*> m_members;		//行会成员
	std::map<int, GuildMember*> m_member_map;	//<玩家ID, 行会成员>

	std::vector<GuildApp*> m_apps;				//申请表
	std::map<int, GuildApp*> m_app_map;			//<玩家ID, 申请表>

	std::vector<std::pair<int, int>> m_active_league_apps;		//主动结盟申请表
	std::map<int, int> m_active_league_app_map;					//<目标行会ID, 申请时间>

	std::vector<std::pair<int, int>> m_passive_league_apps;		//被动结盟申请表
	std::map<int, int> m_passive_league_app_map;				//<申请行会ID, 申请时间>

	std::vector<GuildRecord> m_records;

	std::vector<GuildRed> m_reds;

	std::vector<GuildRedRecord> m_red_records;

	GuildItemManager *m_item_mgr;						//物品管理

	GuildTeamM *m_team_mgr;								//公会队伍管理器

	GuildShop *m_shop;		// 公会商店

	GuildGuishi *m_guishi;
};

struct GuildData
{
	Guild  *guild;
	int level;
	int memberCount;
	int ctime;
	GuildData()
	{
		guild = nullptr;
		level = 0;
		memberCount= 0;
		ctime = 0;
	}
};

#endif	//_GUILD_H_INCLUDED

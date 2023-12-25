#include "stdafx.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "GuildItemManager.h"
#include "GuildLua.h"
#include "GuildTeam.h"
#include "Guild/GuildShop.h"
#include "Guild/GuildGuishi.h"
#include "message/MsgControl.h"
#include "Player/PlayerMsgKeepManager.h"
#include "Application.h"
#include "Entity/WorldPlayerManager.h"

EntityPlayer * GuildMember::getPlayer() const
{
	return g_world_player_mgr.getPlayerByPlayerID(this->player_id);
}

Guild::Guild()
{
	m_item_mgr = new GuildItemManager(this);
	m_team_mgr = new GuildTeamM(this);
	m_shop = new GuildShop(this);
	m_guishi = new GuildGuishi(this);
	m_create_time = 0;
}

Guild::~Guild()
{
	m_prop_map.clear();
	m_strprop_map.clear();

	for (size_t i = 0; i < m_members.size(); ++i)
	{
		delete m_members[i];
	}
	m_members.clear();
	m_member_map.clear();

	for (size_t i = 0; i < m_apps.size(); ++i)
	{
		delete m_apps[i];
	}
	m_apps.clear();
	m_app_map.clear();

	m_active_league_apps.clear();
	m_active_league_app_map.clear();

	m_passive_league_apps.clear();
	m_passive_league_app_map.clear();

	m_records.clear();

	m_reds.clear();

	m_red_records.clear();

	delete m_item_mgr;

	if (m_team_mgr) 
	{
		delete m_team_mgr;
		m_team_mgr = NULL;
	}

	if (m_shop) 
	{
		delete m_shop;
		m_shop = NULL;
	}

	if (m_guishi) 
	{
		delete m_guishi;
		m_guishi = NULL;
	}
}

void Guild::setProp(int idx, int datax)
{
	if ( (idx == GUILD_PROP_MONEY) || (idx == GUILD_PROP_INGOT) )
	{
		if (datax < 0)
		{
			datax = 0;
		}
	}

	m_prop_map[idx] = datax;
}

int Guild::getProp(int idx) const
{
	const auto it = m_prop_map.find(idx);
	if (it != m_prop_map.end())
	{
		return it->second;
	}
	return 0;
}

void Guild::setStringProp(int idx, const std::string &name)
{
	m_strprop_map[idx] = name;
}

const std::string &Guild::getStringProp(int idx)
{
	static std::string empty;
	auto it = m_strprop_map.find(idx);
	if (it != m_strprop_map.end())
	{
		return it->second;
	}
	return empty;
}

bool Guild::addMember(const GuildMember &member)
{
	if (m_member_map.find(member.player_id) != m_member_map.end())
	{
		return false;
	}

	GuildMember *m = new GuildMember;
	*m = member;

	m_members.push_back(m);
	m_member_map[member.player_id] = m;

	lua::call(lua::L, "Guild.onAddMember", this, member.player_id);
	
	return true;
}

void Guild::removeMember(int player_id)
{
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (member->player_id == player_id)
		{
			m_members.erase(m_members.begin() + i);
			delete member;
			break;
		}
	}
	lua::call(lua::L, "Guild.onRmvMember", this, player_id);
	m_member_map.erase(player_id);
}

GuildMember* Guild::getMember(int player_id)
{
	if (player_id <= 0)
	{
		return nullptr;
	}

	auto it = m_member_map.find(player_id);
	if (it == m_member_map.end())
	{
		return nullptr;
	}

	return it->second;
}

//获取行会会长
GuildMember *Guild::getMasterMember()
{
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (member == nullptr)
		{
			continue;
		}

		if (member->post == GUILD_POST_MASTER)
		{
			return member;
		}
	}

	return nullptr;
}

void Guild::addApplication(const GuildApp &app)
{
	if (m_app_map.find(app.player_id) != m_app_map.end())
	{
		return;
	}

	GuildApp *a = new GuildApp;
	*a = app;

	m_apps.push_back(a);
	m_app_map[app.player_id] = a;
}

int Guild::hasApplicationed(int player_id)
{
	if (m_app_map.find(player_id) != m_app_map.end())
	{
		return 1;
	}

	return 0;
}

void Guild::removeApplication(int player_id)
{
	size_t count = m_apps.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildApp *app = m_apps[i];

		if (app->player_id == player_id)
		{
			m_apps.erase(m_apps.begin() + i);
			delete app;
			break;
		}
	}

	m_app_map.erase(player_id);
}

void Guild::clearApplication()
{
	std::vector<int> player_id_vector;

	size_t count = m_apps.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildApp *app = m_apps[i];
		player_id_vector.push_back(app->player_id);
	}

	for (size_t i = 0; i < player_id_vector.size(); ++i)
	{
		g_guild_mgr.clearPlayerApp(player_id_vector[i], getGuildID());
	}

	player_id_vector.clear();

	m_apps.clear();
	m_app_map.clear();
}

GuildApp *Guild::getApplication(int player_id)
{
	auto it = m_app_map.find(player_id);
	if (it == m_app_map.end())
	{
		return NULL;
	}

	return it->second;
}

//添加结盟申请
void Guild::addActiveLeagueApp(int guild_id, int ctime)
{
	if (m_active_league_app_map.find(guild_id) != m_active_league_app_map.end())
	{
		return;
	}

	m_active_league_apps.push_back(std::pair<int, int>(guild_id, ctime));
	m_active_league_app_map[guild_id] = ctime;
}

void Guild::addPassiveLeagueApp(int guild_id, int ctime)
{
	if (m_passive_league_app_map.find(guild_id) != m_passive_league_app_map.end())
	{
		return;
	}

	m_passive_league_apps.push_back(std::pair<int, int>(guild_id, ctime));
	m_passive_league_app_map[guild_id] = ctime;
}

//删除结盟申请
void Guild::delActiveLeagueApp(int guild_id)
{
	if (guild_id <= 0)
	{
		m_active_league_app_map.clear();
		m_active_league_apps.clear();
	}
	else
	{
		auto it = m_active_league_app_map.find(guild_id);
		if (it == m_active_league_app_map.end())
		{
			return;
		}

		m_active_league_app_map.erase(it);

		size_t count = m_active_league_apps.size();
		for (size_t i = 0; i < count; ++i)
		{
			if (m_active_league_apps[i].first == guild_id)
			{
				m_active_league_apps.erase(m_active_league_apps.begin() + i);
				break;
			}
		}
	}
}

void Guild::delPassiveLeagueApp(int guild_id)
{
	if (guild_id <= 0)
	{
		m_passive_league_app_map.clear();
		m_passive_league_apps.clear();
	}
	else
	{
		auto it = m_passive_league_app_map.find(guild_id);
		if (it == m_passive_league_app_map.end())
		{
			return;
		}

		m_passive_league_app_map.erase(it);

		size_t count = m_passive_league_apps.size();
		for (size_t i = 0; i < count; ++i)
		{
			if (m_passive_league_apps[i].first == guild_id)
			{
				m_passive_league_apps.erase(m_passive_league_apps.begin() + i);
				break;
			}
		}
	}
}

//是否存在同盟申请
bool Guild::hasActiveLeagueApp(int guild_id)
{
	return (m_active_league_app_map.find(guild_id) != m_active_league_app_map.end());
}

bool Guild::hasPassiveLeagueApp(int guild_id)
{
	return (m_passive_league_app_map.find(guild_id) != m_passive_league_app_map.end());
}

void Guild::sendMessage(Message *message)
{
	if (message == nullptr)
	{
		return;
	}

	MsgMulticast *bc = new MsgMulticast;
	bc->m_message = message;

	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];

		if (member->player && member->player->getSessionID()>0)
		{
			bc->m_sessions.push_back(member->player->getSessionID());
		}
	}

	if (bc->m_sessions.size() < 1)
	{
		//没有在线成员
		LOG_DEBUG("no online memeber of guild %d %s", m_id, m_name.c_str());
		delete message;
		delete bc;
		return;
	}

	g_app.postToNetService(bc);
}

void Guild::sendMessageToManager(Message *message)
{
	if (message == nullptr)
	{
		return;
	}

	MsgMulticast *bc = new MsgMulticast;
	bc->m_message = message;

	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];

		if (member->player && member->post > GUILD_POST_NORMAL && member->player->getSessionID()>0)
		{
			bc->m_sessions.push_back(member->player->getSessionID());
		}
	}

	if (bc->m_sessions.size() < 1)
	{
		//没有在线成员
		LOG_DEBUG("no online memeber of guild %d %s", m_id, m_name.c_str());
		delete message;
		delete bc;
		return;
	}

	g_app.postToNetService(bc);
}

int Guild::getMemberCount() const
{
	return (int)m_members.size();
}

int Guild::getOnlineMemberCount() const
{
	int count = 0;
	for (size_t i = 0; i < m_members.size(); ++i)
	{
		GuildMember *member = m_members[i];
		if (member->player && member->player->getSessionID()>0)
		{
			count++;
		}
	}
	return count;
}

//获取行会会长名称
std::string Guild::getMasterName() const
{
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (member == nullptr)
		{
			continue;
		}

		if (member->post == GUILD_POST_MASTER)
		{
			return member->player_name;
		}
	}

	return "";
}

int Guild::getMasterPid() const
{
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (member == nullptr)
		{
			continue;
		}

		if (member->post == GUILD_POST_MASTER)
		{
			return member->player_id;
		}
	}
	return 0;
}

int64 Guild::getGuildCombat() const
{
	int64 countCombat = 0;
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (member == nullptr)
		{
			continue;
		}
		countCombat += (int64)member->force;
	}

	return countCombat;
}

int Guild::getMemberSpeekCount() const
{
	int count = 0;
	for (size_t i = 0; i < m_members.size(); ++i)
	{
		GuildMember *member = m_members[i];
		if (member->speek == 1)
		{
			++count;
		}
	}

	return count;
}

//获取职位成员数
int Guild::getMemberCountByPost(int post) const
{
	if (post < GUILD_POST_BEGIN || post >= GUILD_POST_END)
	{
		return 0;
	}

	int count = 0;
	for (size_t i = 0; i < m_members.size(); ++i)
	{
		GuildMember *member = m_members[i];
		if (member->post == post)
		{
			++count;
		}
	}

	return count;
}

void Guild::keepMessage(stcChatKeepInfo message)
{
	size_t count = m_members.size();
	for (size_t i = 0; i < count; ++i)
	{
		GuildMember *member = m_members[i];
		if (!member) continue;

		EntityPlayer *member_player = member->getPlayer();
		if (member_player)
		{
			g_msg_keep_mgr.AddMsgKeep(this->getGuildID(),CHAT_TYPE_GUILD,message);
			return;
		}
	}
}

//增加行会事件
void Guild::addRecord(const GuildRecord &record)
{
	if (m_records.size() >= 30)
	{
		int time = m_records[0].recordtime;
		MsgDBGuildRecordDel *delmsg = new MsgDBGuildRecordDel;
		delmsg->gid = m_id;
		delmsg->recordtime = time;
		g_app.postToNetService(delmsg);

		for (std::vector<GuildRecord>::iterator it =  m_records.begin(); it != m_records.end();)
		{
			if (it->recordtime == time)
			{
				it = m_records.erase(m_records.begin());
			}
			else
			{
				++it;
			}
		}
	
	}

	m_records.push_back(record);
}

//添加行会红包
void Guild::addRed(const GuildRed &red)
{
	m_reds.push_back(red);
}

//添加行会红包日志
void Guild::addRedRecord(const GuildRedRecord &redrecord)
{
	m_red_records.push_back(redrecord);
}

void Guild::CheckRed()
{
	for (std::vector<GuildRed>::iterator it =  m_reds.begin(); it != m_reds.end();)
	{
		if ((it->curcount == it->maxcount)) {
			for (std::vector<GuildRedRecord>::iterator it1 =  m_red_records.begin(); it1 != m_red_records.end();)
			{
				if (it->id == it1->redid)
				{
					it1 = m_red_records.erase(it1);
				}
				else
				{
					++it1;
				}
			}
			MsgDBGuildRedDel *dbmsg = new MsgDBGuildRedDel;
			dbmsg->guildid = this->getGuildID();
			dbmsg->redid =it->id;
			g_app.postToNetService(dbmsg);
			it = m_reds.erase(it);
		}
		else {
			++it;
		}
	}
}

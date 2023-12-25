#include "stdafx.h"

#include "PlayerMsgKeepManager.h"
#include "message/definition.h"
#include "World/World.h"

PlayerMsgKeepManager g_msg_keep_mgr;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_world_Keep_map;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_near_Keep_map;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_guild_Keep_map;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_private_Keep_map;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_horn_Keep_map;
std::map<int, std::vector<stcChatKeepInfo>> PlayerMsgKeepManager::m_warzone_Keep_map;
PlayerMsgKeepManager::PlayerMsgKeepManager() 
{

}

PlayerMsgKeepManager::~PlayerMsgKeepManager()
{
}

void PlayerMsgKeepManager::clearMsg(int pid)
{
	if (pid==0)
	{
		return;
	}
	auto &a = m_world_Keep_map[pid];
	if (a.size() >= 0)
	{
		a.clear();
	}
	auto &b = m_near_Keep_map[pid];
	if (b.size() >= 0)
	{
		b.clear();
	}
	auto &c = m_guild_Keep_map[pid];
	if (c.size() >= 0)
	{
		c.clear();
	}
	auto &d = m_private_Keep_map[pid];
	if (d.size() >= 0)
	{
		d.clear();
	}
	auto &e = m_horn_Keep_map[pid];
	if (e.size() >= 0)
	{
		e.clear();
	}
	auto &f = m_warzone_Keep_map[pid];
	if (e.size() >= 0)
	{
		e.clear();
	}
}

void PlayerMsgKeepManager::deleteKeepMsg(int player_id)
{
	if (player_id == 0)
	{
		return;
	}

	// 世界
	for (auto& it : m_world_Keep_map)
	{
		for (auto iter = it.second.begin(); iter != it.second.end();)
		{
			if (iter->pid == player_id)
			{
				iter = it.second.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	// 附近
	auto nearIt = m_near_Keep_map.find(player_id);
	if (nearIt != m_near_Keep_map.end())
	{
		m_near_Keep_map.erase(nearIt);
	}

	// 私聊
	std::vector<int> targetPidVec;
	auto privateIt = m_private_Keep_map.find(player_id);
	if (privateIt != m_private_Keep_map.end())
	{
		for (auto& it : privateIt->second)
		{
			targetPidVec.emplace_back(it.targetPid);
		}

		m_private_Keep_map.erase(privateIt);
	}

	if (!targetPidVec.empty())
	{
		for (auto& it : targetPidVec)
		{
			auto targetIt = m_private_Keep_map.find(it);
			if (targetIt != m_private_Keep_map.end())
			{
				for (auto iter = targetIt->second.begin(); iter != targetIt->second.end();)
				{
					if (iter->pid == player_id)
					{
						iter = targetIt->second.erase(iter);
					}
					else
					{
						iter++;
					}
				}
			}
		}
	}

	// 小喇叭
	auto hornIt = m_horn_Keep_map.find(player_id);
	if (hornIt != m_horn_Keep_map.end())
	{
		m_horn_Keep_map.erase(hornIt);
	}

	// 行会
	for (auto& it : m_guild_Keep_map)
	{
		for (auto iter = it.second.begin(); iter != it.second.end();)
		{
			if (iter->pid == player_id)
			{
				iter = it.second.erase(iter);
			}
			else
			{
				 iter++;
			}
		}
	}

	// 战区
	for (auto& it : m_warzone_Keep_map)
	{
		for (auto iter = it.second.begin(); iter != it.second.end();)
		{
			if (iter->pid == player_id)
			{
				iter = it.second.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void PlayerMsgKeepManager::AddMsgKeep(int pid,int chatType,stcChatKeepInfo info)
{
	if (pid == 0 )
		return;
	int tid = info.targetPid;
	int oid = info.pid;
	auto tskp = g_world.m_forbidSpeaker.find(tid);
	auto oskp = g_world.m_forbidSpeaker.find(oid);

	if ( ( tid > 0 && (tskp != g_world.m_forbidSpeaker.end()) )||   (oid > 0 && (oskp != g_world.m_forbidSpeaker.end()) ))
	{
		return;
	}

	int maxLength = 50;
	if (chatType == CHAT_TYPE_WORLD)
	{
		auto &v = m_world_Keep_map[pid];
		if (v.size() >= 25)
		{
			v.erase(v.begin());
		}
		m_world_Keep_map[pid].push_back(info);
	}else if (chatType == CHAT_TYPE_NEAR)
	{
		auto &v = m_near_Keep_map[pid];
		if (v.size() >= maxLength)
		{
			v.erase(v.begin());
		}
		m_near_Keep_map[pid].push_back(info);
	}else if (chatType == CHAT_TYPE_GUILD)
	{
		auto &v = m_guild_Keep_map[pid];
		if (v.size() >= 25)
		{
			v.erase(v.begin());
		}
		m_guild_Keep_map[pid].push_back(info);
	}else if (chatType == CHAT_TYPE_PRIVATE)
	{
		auto &v = m_private_Keep_map[pid];
		if (v.size() >= 15)
		{
			v.erase(v.begin());
		}
		m_private_Keep_map[pid].push_back(info);
	}else if (chatType == CHAT_TYPE_HORN)
	{
		auto &v = m_horn_Keep_map[pid];
		if (v.size() >= maxLength)
		{
			v.erase(v.begin());
		}
		m_horn_Keep_map[pid].push_back(info);
	}else if (chatType == CHAT_TYPE_WARZONE)
	{
		auto &v = m_warzone_Keep_map[pid];
		if (v.size() >= maxLength)
		{
			v.erase(v.begin());
		}
		m_warzone_Keep_map[pid].push_back(info);
	}
	m_keep_time[pid] = get_time();
}


const std::vector<stcChatKeepInfo> &PlayerMsgKeepManager::GetMsgKeepVec(int pid,int chatType)
{
	static std::vector<stcChatKeepInfo> vec;
	if (pid > 0 )
	{
		if (chatType == CHAT_TYPE_WORLD)
		{
			auto it = m_world_Keep_map.find(pid);
			if (it != m_world_Keep_map.end() && it->second.size() > 0 )
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}

				return it->second;
			}
		}else if (chatType == CHAT_TYPE_NEAR)
		{
			auto it = m_near_Keep_map.find(pid);
			if (it != m_near_Keep_map.end() && it->second.size() > 0)
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}
				return it->second;
			}
		}else if (chatType == CHAT_TYPE_GUILD)
		{
			auto it = m_guild_Keep_map.find(pid);
			if (it != m_guild_Keep_map.end() && it->second.size() > 0  )
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}
				return it->second;
			}
		}else if (chatType == CHAT_TYPE_PRIVATE)
		{
			auto it = m_private_Keep_map.find(pid);
			if (it != m_private_Keep_map.end()   && it->second.size() > 0 )
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}
				return it->second;
			}
		}else if (chatType == CHAT_TYPE_HORN)
		{
			auto it = m_horn_Keep_map.find(pid);
			if (it != m_horn_Keep_map.end()   && it->second.size() > 0 )
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}
				return it->second;
			}
		}else if (chatType == CHAT_TYPE_WARZONE)
		{
			auto it = m_warzone_Keep_map.find(pid);
			if (it != m_warzone_Keep_map.end() && it->second.size() > 0 )
			{
				for (auto iit = it->second.begin(); iit != it->second.end();)
				{
					int tpid = iit->targetPid;
					int kpid = iit->pid;
					auto tpsk = g_world.m_forbidSpeaker.find(tpid);
					auto kpsk =  g_world.m_forbidSpeaker.find(kpid);
					if (( tpid > 0 && (tpsk != g_world.m_forbidSpeaker.end() ) )||  (kpid > 0 && (kpsk != g_world.m_forbidSpeaker.end() ) ))
					{
						iit = it->second.erase(iit);
					}else
					{
						iit++;
					}
				}

				return it->second;
			}
		}
	}
	return vec;
}

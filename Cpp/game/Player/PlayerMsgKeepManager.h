
#ifndef _PLAYER_MSG_MANAGER_H_INCLUDED
#define _PLAYER_MSG_MANAGER_H_INCLUDED

//聊天保存管理器
#include "message/MsgPlayer.h"

class PlayerMsgKeepManager
{
public:
	PlayerMsgKeepManager();
	~PlayerMsgKeepManager();
	void AddMsgKeep(int pid,int chatType,stcChatKeepInfo info); 
	const std::vector<stcChatKeepInfo> &GetMsgKeepVec(int pid,int chatType);
	void clearMsg(int pid);
	void deleteKeepMsg(int pid);
	std::map<int, int> m_keep_time;
	static std::map<int, std::vector<stcChatKeepInfo>> getMapByType(int chattype);
private:
	static std::map<int, std::vector<stcChatKeepInfo>> m_world_Keep_map;//世界頻道聊天記錄
	static std::map<int, std::vector<stcChatKeepInfo>> m_near_Keep_map;//附近頻道聊天記錄
	static std::map<int, std::vector<stcChatKeepInfo>> m_guild_Keep_map;//公會頻道聊天記錄
	static std::map<int, std::vector<stcChatKeepInfo>> m_private_Keep_map; //私聊頻道聊天記錄
	static std::map<int, std::vector<stcChatKeepInfo>> m_horn_Keep_map; //私聊頻道聊天記錄
	static std::map<int, std::vector<stcChatKeepInfo>> m_warzone_Keep_map; //战区聊天记录
};

extern PlayerMsgKeepManager g_msg_keep_mgr;

#endif	//_HEADTITLE_MANAGER_H_INCLUDED

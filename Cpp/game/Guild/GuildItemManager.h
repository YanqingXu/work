#ifndef _GUILD_ITEM_MANAGER_H_INCLUDED
#define _GUILD_ITEM_MANAGER_H_INCLUDED

#include "Item/Item.h"
#include "message/definition.h"
//#include "message/DBMsgItem.h"

#include <map>
#include <set>

class Message;
class Guild;
struct DBItem;
struct DBItemProp;

class GuildItemManager
{
public:
	GuildItemManager(Guild *guild);
	~GuildItemManager();

	//初始化
	void initAddItem(const DBItem &dbitem);
	void initSetItemProps(const DBItemProp &dbprop);

	//存放物品
	Item *depositItem(Item *item);

	//取出物品
	Item *withdrawItem(int item_id);
	
	void delItem(int item_id);

	const std::map<int, Item*> &getItems();

	Item *getItemByID(int item_id);

	Item * getItemByPos(int pos) const;

	bool isFull();
	
	//是否可以开始定时清理
	bool canStartClean() const;

	void onMinTimer(size_t elapse);

private:
	int allocPosition();
	void freePosition(int pos);

private:
	Guild *m_guild;							//行会

	int m_next_item_id;						//下一个物品ID

	Item *m_positions[GUILD_BAG_POS_LAST + 1];	//

	std::set<int> m_free_pos_set;			//空闲位置

	std::map<int, Item*> m_item_map;		//<位置, 物品>

	bool m_start_time;							//是否开始定时器
	static int TIME_INTERVAL;					//30分钟
	const static int REMAIN_COUNT = 12;			//剩余数量
	int m_time_to_update;
};

#endif	//_GUILD_ITEM_MANAGER_H_INCLUDED


#ifndef _TIMER_MANAGER_H_INCLUDED
#define _TIMER_MANAGER_H_INCLUDED

#include "Util.h"
#include "Logger.h"

#include <vector>
#include <list>
#include <functional>
#include <cassert>

#pragma warning(push)
#pragma warning(disable:4251)

//定时器管理类
//最小堆算法来自boost的timer_queue
class COMMON_API TimerManager
{
private:
	//定时器
	struct Timer
	{
		Timer()
		{
			inuse =  false;
			delay = 0;
			period = 0;
			last_expire_time = 0;
			expire_time = 0;
			cb = NULL;
			handler = NULL;
		}

		size_t id;									//定时器ID

		bool inuse;									//是否有效
		size_t delay;								//
		size_t period;								//定时器触发周期
		unsigned long long last_expire_time;		//上一次超时时间
		unsigned long long expire_time;				//超时时间

		int heap_index;								//在堆中的位置, 小于0表示不在堆中

		void (*cb)(void *base, size_t elapsed);		//定时器回调函数指针
		void *handler;								//定时器回调参数
		char buf[32];								//定时器处理器
	};

	template <typename Handler>
	class TimerHandler
	{
	public:
		TimerHandler(Handler &h) : handler_(h) { }
		~TimerHandler() { }

		static void do_timeout(void *base, size_t elapsed)
		{
			((TimerHandler *)base)->handler_(elapsed);
		}

	private:
		Handler handler_;
	};

public:
	TimerManager();
	~TimerManager();

	template <typename Handler>
	int schedule_timer(size_t delay, size_t period, Handler &&handler)
	{
		if (sizeof(TimerHandler<Handler>) > 32)
		{
			LOG_ERROR("buf too small, need %d", (int)sizeof(TimerHandler<Handler>));
			return -1;
		}

		Timer *timer = NULL;

		if (m_free_timer_list.begin() != m_free_timer_list.end())
		{
			timer = m_free_timer_list.front();
			m_free_timer_list.pop_front();
		}
		else
		{
			timer = new Timer;
			timer->id = m_timers.size();
			timer->heap_index = -1;
			m_timers.push_back(timer);
		}

		timer->inuse = true;
		timer->period = period;
		timer->last_expire_time = get_tick_count();
		if (delay > 0)
		{
			timer->expire_time = timer->last_expire_time + delay;
		}
		else
		{
			timer->expire_time = timer->last_expire_time + period;
		}

		memset(timer->buf, 0, sizeof(timer->buf));
		timer->cb = &TimerHandler<Handler>::do_timeout;
		timer->handler = new(timer->buf) TimerHandler<Handler>(handler);

		m_heap.push_back(timer);
		timer->heap_index = (int)(m_heap.size() - 1);
		//push_heap(m_heap.begin(), m_heap.end(), [](const timer *t1, const timer *t2)->bool{ return t1->expire_time > t2->expire_time; });
		up_heap(m_heap.size() - 1);

		return (int)timer->id;
	}

	void cancel_timer(int timer_id);

	void update();

private:
	// swap two entries in the heap.
	void swap_heap(size_t index1, size_t index2);

	// move the item at the given index up the heap to its correct position.
	void up_heap(size_t index);

	// move the item at the given index down the heap to its correct position.
	void down_heap(size_t index, size_t heap_size = 0);

	// remove the item from the heap.
	void remove_heap(size_t index);

private:
	unsigned long long m_last_tickcount;

	std::vector<Timer*> m_heap;				//超时时间的最小堆

	std::vector<Timer*> m_timers;			//定时器数组

	std::list<Timer*> m_free_timer_list;	//空闲定时器列表
};

#pragma warning(pop)

#endif	//_TIMER_MANAGER_H_INCLUDED


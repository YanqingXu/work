#include "TimerManager.h"


void TimerManager::update()
{
    unsigned long long current_time = get_tick_count();  // 获取当前时间

    while (!m_heap.empty())
    {
        Timer* timer = m_heap.front();  // 获取堆顶定时器

        // 检查定时器是否已过期
        if (timer->expire_time > current_time)
        {
            break;  // 如果堆顶定时器尚未过期，退出循环
        }

        // 移除堆顶定时器
        pop_heap(m_heap.begin(), m_heap.end(), [](const Timer* t1, const Timer* t2) {
            return t1->expire_time > t2->expire_time;
        });
        m_heap.pop_back();

        // 如果定时器是周期性的，重新计算下一个超时时间并重新添加到堆中
        if (timer->period > 0)
        {
            timer->last_expire_time = timer->expire_time;
            timer->expire_time += timer->period;
            m_heap.push_back(timer);
            push_heap(m_heap.begin(), m_heap.end(), [](const Timer* t1, const Timer* t2) {
                return t1->expire_time > t2->expire_time;
            });
        }
        else
        {
            // 非周期性定时器，标记为不再使用
            timer->inuse = false;
            m_free_timer_list.push_back(timer);  // 可以将其加入空闲定时器列表
        }

        // 触发定时器回调
        if (timer->cb)
        {
            timer->cb(timer->handler, current_time - timer->last_expire_time);
        }
    }
}

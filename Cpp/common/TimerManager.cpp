#include "TimerManager.h"

void TimerManager::cancel_timer(int timer_id)
{
    if (timer_id < 0 || timer_id >= m_timers.size())
    {
        LOG_ERROR("Invalid timer ID");
        return;
    }

    Timer* timer = m_timers[timer_id];
    if (!timer || !timer->inuse)
    {
        LOG_ERROR("Timer not in use or does not exist");
        return;
    }

    // 如果定时器在堆中，移除它
    if (timer->heap_index >= 0)
    {
        remove_heap(timer->heap_index);
    }

    // 标记定时器为不在使用，并重置相关字段
    timer->inuse = false;
    timer->cb = NULL;
    timer->handler = NULL;

    // 将定时器放回空闲列表
    m_free_timer_list.push_back(timer);
}

void TimerManager::remove_heap(size_t index)
{
    if (index < 0 || index >= m_heap.size())
    {
        LOG_ERROR("Invalid heap index");
        return;
    }

    // 将要移除的元素与最后一个元素交换
    swap_heap(index, m_heap.size() - 1);

    // 移除最后一个元素
    m_heap.pop_back();

    // 如果移除的元素是最后一个元素，不需要调整堆
    if (index == m_heap.size())
    {
        return;
    }

    // 调整堆
    down_heap(index, m_heap.size());
    up_heap(index);
}

void TimerManager::down_heap(size_t index, size_t heap_size)
{
    if (heap_size == 0) heap_size = m_heap.size();

    while (index < heap_size)
    {
        size_t left_child = 2 * index + 1;
        size_t right_child = 2 * index + 2;
        size_t smallest = index;

        // 找到三者（父节点、左子节点、右子节点）中的最小值
        if (left_child < heap_size && m_heap[left_child]->expire_time < m_heap[smallest]->expire_time)
        {
            smallest = left_child;
        }

        if (right_child < heap_size && m_heap[right_child]->expire_time < m_heap[smallest]->expire_time)
        {
            smallest = right_child;
        }

        if (smallest == index)
        {
            break;
        }

        // 交换父节点与最小的子节点
        swap_heap(index, smallest);
        index = smallest;
    }
}

// 将堆中的元素向上调整
void TimerManager::up_heap(size_t index)
{
    while (index > 0)
    {
        size_t parent = (index - 1) / 2;

        if (m_heap[parent]->expire_time <= m_heap[index]->expire_time)
        {
            break;
        }

        // 交换当前节点与父节点
        swap_heap(index, parent);
        index = parent;
    }
}

void TimerManager::swap_heap(size_t index1, size_t index2)
{
    std::swap(m_heap[index1], m_heap[index2]);
    m_heap[index1]->heap_index = index1;
    m_heap[index2]->heap_index = index2;
}


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

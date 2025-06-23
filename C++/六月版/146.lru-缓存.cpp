/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache
{
private:
    int capacity;
    // 双向链表，保存key-value
    list<pair<int, int>> lruList;
    // 哈希表：key -> 节点位置
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        auto item = cache.find(key);
        if (item == cache.end())
        {
            return -1;
        }
        // 将节点移动到链表头部
        lruList.splice(lruList.begin(), lruList, item->second);
        return item->second->second;
    }

    void put(int key, int value)
    {
        auto item = cache.find(key);
        if (item != cache.end())
        {
            item->second->second = value;
            lruList.splice(lruList.begin(), lruList, item->second);
        }
        else
        {
            if (lruList.size() == capacity)
            {
                // 淘汰最后一个节点
                int delKey = lruList.back().first;
                lruList.pop_back();
                cache.erase(delKey);
            }
            // 插入新节点到头部
            lruList.emplace_front(key, value);
            cache[key] = lruList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

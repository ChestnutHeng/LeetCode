/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// 题意：一个指定大小的cache，只维护最近使用过的N个。（set和get都算使用过）
// 思路：一个链表用来维护队列，最前面的优先级最高，最后面的优先级最低，即将出队
// 一个哈希表用来快速寻找元素。key是cache的key，value是链表对应节点的地址。注意出队的元素要删除
// 坑1：注意迭代器删除后会失效
// 坑2：注意处理链表没达到N个的情况
// 坑3：注意处理get不到的情况

// @lc code=start
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    struct ListNode
    {
        int k;
        int v;
        ListNode(int kk, int vv)
        {
            k = kk;
            v = vv;
        }
    };

    int cap = 0;
    list<ListNode> *que;
    unordered_map<int, list<ListNode>::iterator> *values;
    LRUCache(int capacity)
    {
        cap = capacity;
        que = new list<ListNode>();
        values = new unordered_map<int, list<ListNode>::iterator>();
    }

    int get(int key)
    {
        if (values->count(key))
        {
            auto addr = (*values)[key];
            int v = addr->v;
            que->erase(addr);
            que->push_front(ListNode(key, v));
            (*values)[key] = que->begin();
            return v;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (values->count(key))
        {
            auto addr = (*values)[key];
            que->erase(addr);
            que->push_front(ListNode(key, value));
            (*values)[key] = que->begin();
        }
        else
        {
            que->push_front(ListNode(key, value));
            int oldk = que->back().k;
            if (que->size() > cap)
            {
                que->pop_back();
                (*values).erase(oldk);
            }
            (*values)[key] = que->begin();
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

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
#include "inc.h"

class LRUCache {
public:
    list<pair<int, int> > l;
    map<int, list<pair<int, int> >::iterator> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        printf("cache.get(%d);\n", key);
        if(mp.count(key)){
            int value = mp[key]->second;
            l.erase(mp[key]);
            l.push_front(pair<int, int>(key, value));
            mp[key] = l.begin();
            return value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        printf("cache.put(%d, %d);\n", key, value);
        if(mp.count(key)){
            l.erase(mp[key]);
        }else{
            if(l.size() >= cap){
                mp.erase(l.back().first);
                l.pop_back();
            }
        }
        l.push_front(pair<int, int> (key, value));
        mp[key] = l.begin();
    }
};

int main(){
    LRUCache cache = LRUCache( 1 /* capacity */ );

    cache.put(2, 1);
    cache.get(2);
    cache.put(3, 2);
    cache.get(2);
    cache.get(3);
}
// @lc code=end

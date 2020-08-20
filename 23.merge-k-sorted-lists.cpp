/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 方法1：分治，两两合并
// 方法2：同时遍历所有头部+优先级队列

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        deque<ListNode *> q;
        for(auto v : lists){
            if(v)q.push_back(v);
        }
        if(q.empty()) return nullptr;
        while(q.size() > 1){
            ListNode *a = q.back();
            q.pop_back();
            ListNode *b = q.back();
            q.pop_back();
            ListNode* c = mergeList(a, b);
            q.push_front(c);
        }
        return q.back();
    }
    ListNode* mergeList(ListNode* a, ListNode* b){
        ListNode* head = a && b ? (a->val < b->val ? a : b) : (a ? a : b);
        ListNode* prev = nullptr;
        while(a && b){
            if(a->val < b->val){
                if(prev)prev->next = a;
                prev = a;
                a = a ->next;
            }else{
                if(prev)prev->next = b;
                prev = b;
                b = b ->next; 
            }
        }
        prev ->next = a ? a : b;
        return head;
    }
    
    struct PNode{
        ListNode *p;
        PNode(ListNode *pp) {p = pp;}
        bool operator < (const PNode &rhs) const {
            return p->val > rhs.p->val;
        }
    };
    ListNode* mergeKListsQ(vector<ListNode*>& lists) {
        priority_queue <PNode> q;
        for(auto v : lists){
            if(v) q.push(PNode(v));
        }
        if(q.empty()){
            return nullptr;
        }
        ListNode *nowhead = q.top().p;
        ListNode *prev = nullptr;
        do{
            ListNode *now = q.top().p;
            q.pop();
            if(now->next)q.push(now->next);
            if(prev)prev->next = now;
            prev = now;
        }while(!q.empty());
        return nowhead;
    }
};
// @lc code=end


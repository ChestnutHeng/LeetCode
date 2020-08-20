/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 快慢指针

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        ListNode *f = head;
        ListNode *s = head;
        while(f->next && f->next->next && s->next){
            f = f->next->next;
            s = s->next;
            if(f == s){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


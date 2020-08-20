/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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

// a遍历到最后，指向 headB，b同理
// 假设相交前A链表长度a，相交前b链表长度为b，公共长度为c
// 则有 a + c + b == b + c + a，最后会相遇

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a || b){
            if(a == b){
                return a;
            }
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return nullptr;
    }
};
// @lc code=end


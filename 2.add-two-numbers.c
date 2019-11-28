/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 这个题目的链表数字不会超过int
// 1. 注意这个题目进位会到右边去
// 2. 最后一位进位要处理

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    l3->val = 0;
    struct ListNode *tra = l3;
    int c = 0;
    while(c || l1 || l2){
        c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        tra->next = malloc(sizeof(struct ListNode));
        tra->next->val = c%10;
        tra = tra->next;
        c /= 10;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    tra->next = NULL;
    return l3->next;
}


// @lc code=end


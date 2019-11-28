/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 注意判断每个节点是NULL的情况
/* 最佳解
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
 */

class Solution {
public:
    void swapPair(ListNode *last, ListNode *now){
        if(now == NULL || now->next == NULL){
            return;
        }
        ListNode *a, *b, *c;
        a = now;
        b = a->next;
        c = b->next;
        a->next = c;
        b->next = a;
        last->next = b;
        swapPair(a, c);
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode *a, *b, *c;
        a = head;
        if(a == NULL) return NULL;
        b = a->next;
        if(b == NULL) return head;
        c = b->next;
        a->next = c;
        b->next = a;
        swapPair(a, c);
        return b;
    }
};


/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0){
            return NULL;
        }
        int k = 0;
        ListNode* k1 = head;
        while(--n > 0) k1 = k1->next;
        ListNode* k2 = head;
        ListNode* prev = NULL;
        while(k1->next != NULL){
            prev = k2;
            k1 = k1->next;
            k2 = k2->next;
        }
        if (k2 == head){
            return k2->next;
        }else{
            prev->next = k2->next;
            delete k2;
        }
        return head;
    }
};


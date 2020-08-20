/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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

// 拆开两个链表

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)    return head;
        ListNode *odd = head, *even = head->next, *evenStart = even;
        while(even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;          //将奇偶链表相连
        return head;
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next, *evenhead = head->next;
        while(even->next && even->next->next){
            ListNode* oddnext = even->next;
            ListNode* evennext = even->next->next;
            odd->next = oddnext;
            even->next = evennext;
            odd = oddnext;
            even = evennext;
        }
        if(even->next){
            ListNode* oddnext = even->next;
            odd->next = even->next;
            odd = oddnext;
        }
        odd->next = evenhead;
        even->next = nullptr;
        return head;
    }
};
// @lc code=end


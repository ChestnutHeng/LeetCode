/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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

// 先找出k个一组，然后翻转链表

class Solution {
public:
    ListNode* reverseL(ListNode *head, ListNode *tail){
        ListNode *pre = nullptr;
        while(head != tail){
            cout << head->val ;
            ListNode *tmp = head->next;
            //head->next->next = head;
            head->next = pre;
            pre = head;
            head = tmp;
        };
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tra = head;
        ListNode *hair = new ListNode();
        while(tra){
            ListNode *nowt = tra;
            for(int i = 0; i < k; ++i){
                if(tra){
                    tra = tra->next;
                }else{
                    hair->next = nowt;
                    return head;
                }
            }
            ListNode *newhead = reverseL(nowt, tra);
            if(nowt == head){
                head = newhead;
            }
            hair->next = newhead;
            hair = nowt;
        }
        return head;
    }
};
// @lc code=end


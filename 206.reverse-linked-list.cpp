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
class Solution {
public:
    ListNode* reverseListI(ListNode* head) {
        ListNode* tra = head;
        ListNode* prev = nullptr;
        ListNode* tmp;
        while(tra){
            tmp = tra->next;
            tra->next = prev;
            prev = tra;
            tra = tmp;
        }
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nowhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nowhead;
    }
};
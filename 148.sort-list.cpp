/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
#include "inc.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        //return mergeList(head, new ListNode(5));
        ListNode* rhead = findMid(head);
        ListNode* sortedleft = sortList(head);
        ListNode* sortedright = sortList(rhead);
        return mergeList(sortedleft, sortedright);
    }
    ListNode* mergeList(ListNode* r, ListNode* l){
        ListNode* hair = new ListNode(-1);
        ListNode *tra = hair;
        while(r && l){
            if(r->val <= l->val){
                tra->next = r;
                r = r->next;
            }else{
                tra->next = l;
                l = l->next;
            }
            tra = tra->next;
        }
        tra->next = r ? r : l;
        return hair->next;
    }
    
    // 1 2
    //   ^ ^
    // 1 2 3
    //   ^ ^
    // 1 2 3 4
    //   ^     ^
    ListNode* findMid(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *slow = head, *fast = head->next->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rhead = slow->next;
        slow->next = nullptr;
        return rhead;
    }
    
};

int main(){
    ListNode *head = conv_list(vector<int>{4, 3 ,1 ,2});
    plinklist(head);
    Solution s;
    plinklist(s.sortList(head));
}
// @lc code=end


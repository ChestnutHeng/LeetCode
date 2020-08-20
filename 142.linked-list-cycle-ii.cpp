/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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

// 设环外长度为a，环内长度为b
// 1.快慢第一次相遇，slow = nb（fast多走了n圈，fast=slow + nb，fast=2slow, 得出slow=nb）
// 2.设第三个元素从链表头走了k步到入口，则k=a+nb。所以slow想走到入口也要slow + x = a+nb, x = a，slow需要走a步
// 3.到此，可以通过slow，head同事走到重合为止，就是环的开头
// 4.由3得出，起始距离入口 = 第一次相遇位置 + a

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    }
};
// @lc code=end


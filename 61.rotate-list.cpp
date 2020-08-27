/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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

// 思路：需要处理一下k比链表大的情况，可以发现len(list)次和不旋转是一样的效果
// 求长度，直接求
// 找到倒数第k个，和头连起来
// 注意k=0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        // len
        ListNode *tra = head;
        int len = 1;
        while (tra->next)
        {
            tra = tra->next;
            len++;
        }
        k = k % len;
        if(k == 0){
            return head;
        }
        // find k
        ListNode *tra2 = head;
        int step = len - k;
        while (--step)
        {
            tra2 = tra2->next;
        }
        ListNode *newhead = tra2->next;
        tra2->next = nullptr;
        tra->next = head;
        return newhead;
    }
};
// @lc code=end

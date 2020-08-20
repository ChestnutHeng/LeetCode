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

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int len = 0;
        ListNode *tra = head;
        while (tra)
        {
            len++;
            tra = tra->next;
        }
        if (k >= len)
        {
            k = k % len;
        }
        tra = head;
        ListNode *bro = head;
        while (k--)
        {
            tra = tra->next;
        }
        while (tra->next)
        {
            tra = tra->next;
            bro = bro->next;
        }
        tra->next = head;
        tra = bro->next;
        bro->next = NULL;
        return tra;
    }
};
// @lc code=end

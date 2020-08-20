/*
@lc app=leetcode id=21 lang=cpp
 *
[21] Merge Two Sorted Lists
 */
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */
// #define NULL 0
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// 两个指针来制造新的list
// 吃亏：二级指针要时刻注意
// 下满的交换内存的方法让人震惊，每次从ab两个链表中选取一个，作为新链表的下一个
/*
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a || b && a->val > b->val) swap(a, b);
    if (a) a->next = mergeTwoLists(a->next, b);
    return a;
}
*/
class Solution {
public:
    ListNode* mergeTwoListsR(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
}


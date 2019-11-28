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
    void append(ListNode** head, ListNode** tra, int val){
        ListNode *node = new ListNode(val);
        
        if(*head == NULL){
            *head = node;
            *tra = node;
        }else{
            (*tra)->next = node;
            *tra = (*tra)->next;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = NULL, *tra = NULL;
        while(p1 || p2){
           while (p1 && (!p2 || p1->val <= p2->val)){
               append(&head, &tra, p1->val);
               p1 = p1->next;
           }
            while (p2 && (!p1 || p2->val <= p1->val)){
               append(&head, &tra, p2->val);
               p2 = p2->next;
           }
        }
        return head;
    }
};


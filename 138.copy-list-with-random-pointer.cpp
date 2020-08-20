/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        unordered_map<Node*, Node*> hmap;
        Node *tra = head;
        Node *nhead = new Node(head->val);
        hmap[head] = nhead;
        Node *ntra = nhead;
        while(tra->next){
            Node *now = new Node(tra->next->val);
            hmap[tra->next] = now;
            nhead->next = now;
            tra = tra->next;
            nhead = nhead->next;
        }
        nhead = ntra;
        while(nhead){
            nhead->random = head->random ? hmap[head->random] : nullptr;
            head = head->next;
            nhead = nhead->next;
        }
        return ntra;
    }
};
// @lc code=end


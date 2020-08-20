/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 思路1，用哪种遍历？不只是递归
// 注用栈的时候注意出栈顺序，从前面的开始出栈，这样每个出栈的节点的next就是下一个要出栈的
// 注意判断边界，最后一个next取默认值就好

// 思路2：利用父亲节点的next指针做递归

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        deque<Node *>stk;
        stk.push_back(root);
        while(!stk.empty()){
            Node *last = nullptr;
            int size = stk.size();
            for(int i = 0; i < size; ++i){
                Node *t = stk.front();
                stk.pop_front();
                if(i < size - 1){
                    t->next = stk.front();
                }
                if(t->left) {
                    stk.push_back(t->left);
                }
                if(t->right) {
                    stk.push_back(t->right);
                }
                
            }
        }
        return root;
    }
    
    Node* connectN(Node* root) {
        if(!root || !root->left){
            return root;
        }
        root->left->next = root->right;
        if(root->next)root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
    Node* connectS(Node* root) {
        if(!root){
            return root;
        }
        list<Node*> stk;
        stk.push_back(root);
        root->next = nullptr;
        
        while(!stk.empty()){
            list<Node*> st2;
            while(!stk.empty()){
                Node *tra = stk.front();
                stk.pop_front();
                if(tra->left)st2.push_back(tra->left);
                if(tra->right)st2.push_back(tra->right);
            }
            Node *last = nullptr;
            for(auto it = st2.rbegin(); it != st2.rend(); ++it){
                (*it)->next = last;
                last = *it;
            }
            stk = st2;
        }
        return root;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 思路，镜像二叉树，左右儿子的值一样，然后分别比对(left->left, right->right) (left->right, right->left)

#include <deque>

void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──左" : "└──右" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const TreeNode* node)
{
    printBT("", node, false);    
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // printBT(root);
        // deque<int> stack;
        // travMid(root, stack);
        // for(auto v:stack){
        //     cout << v << " ";
        // }
        // while(stack.size()>= 2 && stack.back() == stack.front()){
        //     stack.pop_back();
        //     stack.pop_front();
        // }
        // return stack.size() == 0 || (stack.size() == 1 && stack[0] == root->val);
        if(!root)return true;
        return isSymNR(root->left, root->right);
    }
    
    bool isSym(TreeNode* a, TreeNode *b){
        if(!b && !a){
            return true;
        }
        if (a && b){
            return a->val == b->val && isSym(a->left, b->right) && isSym(a->right, b->left);
        }
        return false;
    }
    
    bool isSymNR(TreeNode* a, TreeNode *b){
        deque<TreeNode *> stack;
        stack.push_back(a);
        stack.push_back(b);
        while(!stack.empty()){
            a = stack.back();
            stack.pop_back();
            b = stack.back();
            stack.pop_back();
            if(!a && !b){
                continue;
            }else if((a &&!b) ||(b && !a) || (a->val != b->val)){
                return false;    
            }
            stack.push_back(a->left);
            stack.push_back(b->right);
            stack.push_back(a->right);
            stack.push_back(b->left);
        }
        return true;
    }
    
    void travMid(TreeNode* root, deque<int> &stack){
        if(!root){
            stack.push_back(-1);
            return;
        }
        if (!root->left && !root->right){
            stack.push_back(root->val);
            return ;
        }
        travMid(root->left, stack);
        stack.push_back(root->val);
        travMid(root->right, stack);
    }
};
// @lc code=end


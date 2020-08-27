/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 方法1：递归，直到找到p或q为止。如果左边有p或q，回溯，右边同理。如果左右都有p，q，说明当前节点就是最低公共祖先
// 方法2：哈希表存储所有指针的父节点。从p和q开始追寻父节点，直到相交

//    x
//  x   x
// p x x q

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        if(p == root || q == root){
            return root;
        }

        TreeNode* lefthas = lowestCommonAncestor(root->left, p, q);
        TreeNode* righthas = lowestCommonAncestor(root->right, p, q);
        if(lefthas && righthas){
            return root;
        }else if(lefthas){
            return lefthas;
        }else{
            return righthas;
        }
        return nullptr;
    }
};
// @lc code=end


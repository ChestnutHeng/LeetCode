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

// 方法1：递归
// 方法2：哈希表存储所有指针的父节点。从p和q开始追寻父节点，直到相交

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root){
            return root;
        }
        if(!root){
            return root;
        }
        TreeNode* lefthas = lowestCommonAncestor(root->left, p, q);
        TreeNode* righthas = lowestCommonAncestor(root->right, p, q);
        if(lefthas && righthas){
            return root;
        }else if(lefthas){
            return lowestCommonAncestor(lefthas, p, q);
        }else{
            return lowestCommonAncestor(righthas, p, q);
        }
        return nullptr;
    }
};
// @lc code=end


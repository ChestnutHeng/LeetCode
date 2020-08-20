/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
// 深度优先：直接递归
// 广度优先：相当于层次遍历的层数
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return maxDR(root, 0);
    }
    int maxDR(TreeNode* root, int depth){
        if(!root){
            return depth;
        }
        return max(maxDR(root->left, depth+1), maxDR(root->right, depth+1));
    }
};
// @lc code=end


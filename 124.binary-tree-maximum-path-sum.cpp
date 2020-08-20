/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

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

// 最大路径和：当前节点作为顶点的最大路径
// 最大贡献值：当前节点作为一条分支的最大路径
// 递归的时候返回最大贡献值，但是算全局最大路径的时候，算的是每次遍历到的节点，以此节点作为顶点的最大路径


class Solution {
public:
    int maxval = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxval;
    }
    int maxPath(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lf = maxPath(root->left);
        int rf = maxPath(root->right);
        int newmax = max(lf, 0) + root->val + max(rf, 0);
        //cout << root->val << " " << newmax << lf << rf << endl;
        maxval = max(newmax, maxval);
        return root->val + max(max(lf, 0), max(rf, 0));
    }
};
// @lc code=end


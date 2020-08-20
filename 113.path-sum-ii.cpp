/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

// 搜索+回溯
// 注意只有到叶子节点的路径才算
// 注意root为空
// 注意不能到叶子节点的下一层

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root){
            return ans;
        }
        dfs(root, 0, sum, path);
        return ans;
    }
    void dfs(TreeNode* root, int psum, int sum, vector<int> &path){
        path.push_back(root->val);
        if(root->left)
            dfs(root->left, psum + root->val, sum, path);
        if(root->right)
            dfs(root->right, psum + root->val, sum, path);
        if(!root->left && !root->right && psum + root->val == sum)
            ans.push_back(path);
        path.pop_back();
    }
};
// @lc code=end


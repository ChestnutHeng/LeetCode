/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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

// 偶数个节点的时候，mid的选择方法有两种，选择最中间的，或者中间靠右边的
// 注意每次递归不用带上mid
// 这样也不会l == r

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildT(nums, 0, nums.size() - 1);
    }
    TreeNode* buildT(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        if(l == r){
            return new TreeNode(nums[l]);
        }
        int mid = (l+r)/2;
        TreeNode* now = new TreeNode(nums[mid]);
        now->left = buildT(nums, l, mid-1);
        now->right = buildT(nums, mid+1, r);
        return now;
    }
};
// @lc code=end


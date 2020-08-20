/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        //ans.push_back(vector<int>{root->val});
        bool isLeft = true;
        while(!q.empty()){
            deque<TreeNode*> q2;
            vector<int> l;
            while(!q.empty()){
                TreeNode *tra;
                tra = q.front();
                q.pop_front();
                l.push_back(tra->val);
                if(tra->left)q2.push_back(tra->left);
                if(tra->right)q2.push_back(tra->right);
            }
            q = q2;
            if(!isLeft){
                reverse(l.begin(), l.end());
            }
            isLeft = !isLeft;
            if(!l.empty()){
                ans.push_back(l);
            }
        }
        return ans;
    }
};
// @lc code=end


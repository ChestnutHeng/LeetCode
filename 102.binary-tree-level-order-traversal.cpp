/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

// 局部变量要清空
// 注意这个层遍历是有顺序的，从左到右
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            vector<int> level;
            while(curLevelSize--){
                TreeNode *tra = q.front();
                q.pop();
                level.push_back(tra->val);
                if(tra->left) q.push(tra->left);
                if(tra->right) q.push(tra->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        vector<int> l;
        deque<TreeNode *> q1;
        deque<TreeNode *> q2;
        l.push_back(root->val);
        ans.push_back(l);
        l.clear();
        q1.push_back(root);
        while(!q1.empty()){
            while(!q1.empty()){
                TreeNode *tra = q1.front();
                q1.pop_front();
                if (tra->left){
                    q2.push_back(tra->left);
                    l.push_back(tra->left->val);
                }
                if (tra->right){
                    q2.push_back(tra->right);
                    l.push_back(tra->right->val);
                }
            }
            if(!l.empty())ans.push_back(l);
            l.clear();
            q1 = q2;
            q2.clear();
        }
        return ans;
    }
};
// @lc code=end


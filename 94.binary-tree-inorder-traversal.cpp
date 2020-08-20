/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// 非遍历方法：
// while (curr != null || !stack.isEmpty()) {
//     while (curr != null) {
//         stack.push(curr);
//         curr = curr.left;
//     }
//     curr = stack.pop();
//     res.add(curr.val);
//     curr = curr.right;
// }


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        travI(root, ans);
        return ans;
    }
    void travR(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        travR(root->left, ans);
        ans.push_back(root->val);
        travR(root->right, ans);
    }
    
    void travI(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        stack<TreeNode *> stk;
        while(true){
            stk.push(root);
            while(root->left){
                stk.push(root->left);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            while(!root->right){
                if(stk.empty()){
                    return;
                }
                root = stk.top();
                stk.pop();
                ans.push_back(root->val);
                //cout << root->val << endl;
            };
            root = root->right;
        }
    }
};
// @lc code=end


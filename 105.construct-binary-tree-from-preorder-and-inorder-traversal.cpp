/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// 用下标避免数组拷贝

class Solution {
public:
    void printv(vector<int>& v){
        for(auto vv : v){
            cout << vv << " ";
        }
        cout << endl;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        //cout << preorder.size() << endl;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1){
            return root;
        }
        for(int i = 0; i < inorder.size(); ++i){
            if(inorder[i] == root->val){
                vector<int> lp(preorder.begin() + 1, preorder.begin() + 1 + i);
                vector<int> rp(preorder.begin() + 1 + i, preorder.end());
                vector<int> li(inorder.begin(), inorder.begin() + i);
                vector<int> ri(inorder.begin() + i + 1, inorder.end());
                //printv(lp);printv(rp);printv(li);printv(ri);
                root->left = buildTree(lp, li);
                root->right = buildTree(rp, ri);
                break;
            }
        }
        return root;
    }
};
// @lc code=end


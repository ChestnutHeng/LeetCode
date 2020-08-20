
// 中序遍历+剪枝
class Solution {
public:
    int co = 0;
    int mk ;
    int ans;
    void travPrev(TreeNode* root){
        if(!root) return;
        travPrev(root->left);
        co ++;
        if(co == mk){
            ans = root->val;
            return;
        }
        travPrev(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        mk = k;
        travPrev(root);
        return ans;
    }
};
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;

// 全排列的遍历

class Solution {
public:
    void search(vector<vector<int>> &ans, vector<int> stack, vector<int> left){
        if(stack.empty()){
            ans.push_back(left);
            return;
        }
        for(int i =0; i < stack.size(); ++i){
            vector<int> tstack = stack;
            vector<int> tleft = left;
            tleft.push_back(stack[i]);
            tstack.erase(tstack.begin() + i);
            search(ans, tstack, tleft);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> left;
        search(ans, nums, left);
        return ans;
    }
};
// @lc code=end


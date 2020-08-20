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

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> path, vector<int>& nums, int start){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < nums.size(); ++i){
            path.push_back(nums[i]);
            swap(nums[i], nums[path.size() - 1]);
            dfs(ans, path, nums, path.size());
            swap(nums[i], nums[path.size() - 1]);
            path.pop_back();
        }
    }
};
// @lc code=end


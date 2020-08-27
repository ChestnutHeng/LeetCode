/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;

// 全排列的遍历

class Solution
{
    vector<vector<int>> ans;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums, 0, nums.size());
        return ans;
    }

    void dfs(vector<int> &nums, int depth, int len)
    {
        if (depth == len)
        {
            ans.emplace_back(nums);
            return;
        }
        for (int i = depth; i < len; ++i)
        {
            swap(nums[i], nums[depth]);
            dfs(nums, depth + 1, len);
            swap(nums[i], nums[depth]);
        }
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


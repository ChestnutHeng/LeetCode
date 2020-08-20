/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start

//  dp[i] = max(dp[i-1], dp[i-2] + nums[i])

class Solution {
public:
    // [5,1,2,9,1,1,8]
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end


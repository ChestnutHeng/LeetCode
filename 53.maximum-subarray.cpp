/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

// 贪心：每次遇到nums[i] > nums[i] + nowsum，表明是一个新的开始点，重新开始算最大值
// DP：dp[i] = max(nums[i], dp[i-1] + nums[i])

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxdp = dp[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxdp = max(dp[i], maxdp);
        }
        return maxdp;
    }
    int maxSubArrayTX(vector<int>& nums) {
        int nowsum = 0;
        int maxsum = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > nums[i] + nowsum){
                nowsum = nums[i];
            }else{
                nowsum = nums[i] + nowsum;
            }
            maxsum = max(maxsum, nowsum);
        }
        return maxsum;
    }
};
// @lc code=end


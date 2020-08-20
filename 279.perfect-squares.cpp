/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start

// DP, dp[i] = min(dp[i - j*j], dp[i]), j = 1 ... i^(1/2)

class Solution {
public:
    int numSquares(int n) {
        // 初始化dp的可能性数组
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            dp[i] = INT_MAX;
            for(int j = 1; j <= pow(i, 0.5); ++j){
                dp[i] = min(dp[i - j*j] + 1, dp[i]);
            }
            //cout << mini << endl;
        }
        return dp[n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

// 情况很多的DP

class Solution {
public:
    // s[i] == '0' && s[index-1] == '1'|'2', dp[i] = dp[i-2] （前一个是1/2不增加情况，否则直接返回）
    // s[i-1] == '1', dp[i] = dp[i-1] + dp[i-2] 
    // s[i-1] == '2' && s[i] >= '1' && s[i] <= '6', dp[i] = dp[i-1] + dp[i-2] 
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i){
            int index = i - 1;
            if(s[index] == '0'){
                if (s[index-1] == '1' || s[index-1] == '2')dp[i] = dp[i-2];
                else return 0;
            }else{
                if(s[index-1] == '1') dp[i] = dp[i-1] + dp[i-2] ;
                else if(s[index-1] == '2' && s[index] >= '1' && s[index] <= '6') dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            } 
        }
        return dp[s.size()];
    }
};
// @lc code=end


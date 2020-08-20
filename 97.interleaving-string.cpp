/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start

// DP，
//dp[i][j] = (j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) ||
//                       (i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1])
// 1. 注意不能破坏原始的dp零值，赋值前要判断i>0或者j>0
// 2. 如果i>0的分支成立了，注意不能用下一个分支覆盖

class Solution {
public:
    //dp[i][j] = (j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) ||
    //                       (i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1])
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s1.size(); ++i){
            for(int j = 0; j <= s2.size(); ++j){
                if(j > 0){
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                if(i > 0){
                    // 防止覆盖
                    dp[i][j] = dp[i][j] || dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
// @lc code=end


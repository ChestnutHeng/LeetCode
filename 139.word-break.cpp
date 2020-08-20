/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

// 暴力搜索太慢了，用dp
// dp[i]=dp[j] && check(s[j..i−1])

class Solution {
public:
    unordered_map<string, bool> hmap;
    vector<int> seg;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto v : wordDict){
            hmap[v] = true;
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < i; ++j){
                //cout << dp[j]  << " "  << s.substr(j, i - j) << " " << hmap.count(s.substr(j, i - j)) << endl;
                if(dp[j] && hmap.count(s.substr(j, i - j)) > 0){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
    
    bool slowdfs(vector<int> &seg, string &s, int start){
        if(start >= s.size()){
            return true;
        }
        string segs;
        for(int i = start; i < s.size(); ++i){
            segs.push_back(s[i]);
            if(hmap.count(segs) >= 1){
                //seg.push_back(i);
                //cout << segs << endl;
                if (slowdfs(seg, s, i + 1)){
                    return true;
                }
                //seg.pop_back();
            }
        }
        return false;
    }
};
// @lc code=end


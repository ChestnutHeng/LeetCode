/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start

// 正着算更快

class Solution {
public:
    int titleToNumber(string s) {
        int pown = 0;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            ans += pow(26, pown)* (s[i] - 'A' + 1);
            pown++;
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto v : nums){
            ans = ans ^ v;
        }
        return ans;
    }
};
// @lc code=end


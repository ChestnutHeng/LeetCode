/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start

// 性质：n &(n-1)总能把最后一位1变成0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int co = 0;
        while(n){
            n = n & (n-1);
            co++;
        }
        return co;
    }
};
// @lc code=end


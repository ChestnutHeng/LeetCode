/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start

// 单调栈会有问题

// 如果比small小，直接更新small，如果大于small小于mid，更新mid，大于mid说明序列成立
// 直接更新small，有可能会有small在mid顺序之后的情况。但是，如果你能更新small，说明mid前已经有一个比mid小的数，所以也是没问题的

class Solution {
public:
    // 3 5 <- 1 2 4
    // 2 5 <- 1 6 3 单调栈失败

    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, mid = INT_MAX;
        for(auto v : nums){
            if(v <= small){
                small = v;
            }else if (v <= mid){
                mid = v;
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


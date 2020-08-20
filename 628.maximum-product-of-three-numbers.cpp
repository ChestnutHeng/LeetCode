/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
// [-5 -4 -3 ... 1 2]
// [-5 -4 -3 -1]
// [-3 1 2 3]
// [-4 -3 1 2]

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max1 = nums[0] * nums[1] * nums.back();
        int max2 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        return max(max1, max2);
    }
};
// @lc code=end


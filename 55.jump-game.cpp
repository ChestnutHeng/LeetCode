/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

// 思路：贪心，尽可能往前走

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int ican = 1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            ican--;
            if (nums[i] > ican)
            {
                ican = nums[i];
            }
            if (ican == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

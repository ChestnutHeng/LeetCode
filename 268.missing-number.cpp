/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
// 一直swap直到正确的位置
class Solution {
public:
    // 0 1 3
    int missingNumber(vector<int>& nums) {
        for(int i  = 0; i < nums.size(); ++i){
            while(nums[i] != 0 && nums[i] - 1!= i){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0)return i + 1;
        }
        return 0;
    }
};
// @lc code=end


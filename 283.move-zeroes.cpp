/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start

// 双指针
// 可以优化下思路，每次i不为0的时候p0也++，这样如果下一个元素是0，p0还留在原地，如果不是0，交换自己也无妨

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p0 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
    void moveZeroesL(vector<int>& nums) {
        int p0 = 0;
        while(p0 < nums.size() && nums[p0] != 0){
            p0++;
        }
        for(int i = p0 + 1; i < nums.size(); ++i){
            if(nums[i] != 0){
                swap(nums[i], nums[p0]);
                while(nums[p0] != 0 && p0 < nums.size()){
                    p0++;
                }
            }
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

// 双指针，一定要bugfree
// 返回是长度，不是下标
// 不用swap

class Solution {
public:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int p1 = 0;
        for(int p2 = 1; p2 < nums.size(); p2++){
            if(nums[p2] == nums[p1]){
                continue;
            }else{
                p1++;
                swap(nums[p1], nums[p2]);
            }
        }
        return p1 + 1;
    }
};
};
// @lc code=end


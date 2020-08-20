/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start

// 二分法，其实实质是分治，我们把数组分为两半，看重复数字在哪一半里，不断缩小区间
// 例如：区间 [1, 7][1,7] 的中位数是 4，遍历整个数组，统计小于等于 4 的整数的个数，如果不存在重复元素，最多为 4 个（1,2,3,4）。
// 等于 4 的时候区间 [1, 4]内也可能有重复元素（1,2,3,3）。
// 但是，如果整个数组里小于等于 4 的整数的个数严格大于 4 的时候，就可以说明重复的数存在于区间 [1, 4]。

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            
            int co = 0;
            for(auto v : nums){
                if(v <= mid){
                    co++;
                }
            }
            
            if (co > mid){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};
// @lc code=end


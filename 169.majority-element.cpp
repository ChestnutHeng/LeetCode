/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

// 解法1：投票法，众数个数至少比非众数多一，把COUNT加减当作一个众数抵消掉一个非众数，剩下的一定是众数
// 解法2：分治，切分数组后左右数组必然都有个众数，总数组的众数也在这两个之中，然后在这两个众数中选一个

class Solution {
public:
    int majorityElementVote(vector<int>& nums) {
        int me = nums[0];
        int ticket = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(ticket == 0){
                me = nums[i];
            }
            ticket += nums[i] == me ? 1 : -1;
        }
        return me;
    }
    int majorityElement(vector<int>& nums) {
        return majorityElementR(nums, 0, nums.size() - 1);
    }
    int count(vector<int>& nums, int left, int right, int tar){
        int co = 0;
        for(int i = left; i <= right; i++){
            co += nums[i] == tar ? 1 : 0;
        }
        return co;
    }
    int majorityElementR(vector<int>& nums, int left, int right) {
        if(left == right){
            return nums[left];
        }
        int leftm = majorityElementR(nums, left, (left+right)/2);
        int rightm = majorityElementR(nums, (left+right)/2+1, right);
        if(leftm == rightm){
            return leftm;
        }
        int lco = count(nums, left, right, leftm);
        int rco = count(nums, left, right, rightm);
        return lco > rco ? leftm : rightm;
    }
};
// @lc code=end


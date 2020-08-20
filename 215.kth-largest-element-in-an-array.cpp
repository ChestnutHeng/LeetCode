/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
// 快排分堆函数：对于比pivot小的，依次放在左边即可

class Solution {
public:
    // 4 1 5 2 7
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int p = l + 1;
        for(int i = l + 1; i <= r ; ++i){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p - 1], nums[l]);
        //cout << p - 1 << endl;
        return p-1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int target = nums.size() - k;
        int mk;
        while(true){
            mk = partition(nums, l, r);
            if(mk == target){
                return nums[target];
            }else if(mk > target){
                r = mk - 1;
            }else{
                l = mk + 1;
            }
        }
        return -1;
    }
};
// @lc code=end


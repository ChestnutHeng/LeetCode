
// 要求logn复杂度，只可能用二分
// 找一个峰值最大的即可
// 注意峰值两边越界的情况

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1)return 0;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l+r) / 2;
            if((mid-1 < 0 || nums[mid]> nums[mid-1]) && (mid+1 >= nums.size() || nums[mid] > nums[mid+1])){
                return mid;
            }else if(nums[mid] < nums[mid+1]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }
};
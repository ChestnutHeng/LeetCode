/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
// [5,7,7,8,8,10]

// 先找出任意一个目标值
// 分别在这个目标左右找 从目标值变成非目标的地方

// 注意lo==hi依然可以看是否有变化
// 注意如果数字到达了数组边缘，就不需要另一个数和他比较

// 官方版本没看懂

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int lo = 0, hi = nums.size() - 1, mid = 0;
        int findone = -1;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(nums[mid] > target){
                hi = mid - 1;
            }else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                findone = mid;
                break;
            }
        }
        if (nums.size() == 1 && nums[0] == target){
            ans[0] = 0;
            ans[1] = 0;
            return ans;
        }
        if(findone == -1){
            return ans;
        }
        //cout << findone << endl;
        lo = findone, hi = nums.size() - 1, mid = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(nums[mid] > target){
                hi = mid - 1;
            }else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                if(mid+1 >= nums.size() || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                }else{
                    lo = mid + 1;
                }
            }
            //cout << lo << mid << hi << endl;
        }
        lo = 0, hi = findone, mid = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(nums[mid] > target){
                hi = mid - 1;
            }else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                if(mid - 1 < 0 || nums[mid-1] != target){
                    ans[0] = mid ;
                    break;
                }else{
                    hi = mid -1;
                }
            }
        }

        return ans;
    }
};


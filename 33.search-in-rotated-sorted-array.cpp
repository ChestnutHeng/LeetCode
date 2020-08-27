/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */


// mid切开的两个数组里，一定有一个数组是有序的
// 如果 [l, mid - 1] 是有序数组，且 target 属于[nums[l], nums[mid-1]]，则我们应该将搜索范围缩小至 [l, mid - 1]，否则在 [mid + 1, r] 中寻找。
// 如果[mid, r] 是有序数组，且 target 属于 [nums[mid+1],nums[r]]，则我们应该将搜索范围缩小至 [mid + 1, r]，否则在 [l, mid - 1] 中寻找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            //cout << lo << " " << hi << endl;
            int mid = (lo + hi) >> 1; // 左中位数
            if(nums[mid] == target) return mid;
            // 右边有序
            if(mid < hi && nums[mid+1] <= nums[hi]){
                if(target >= nums[mid+1] && target <= nums[hi]){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            // 左边有序
            }else if(mid > lo && nums[lo] <= nums[mid-1]){
                if(target <= nums[mid-1] && target >= nums[lo]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }else{
                return -1;
            }
        }
        return -1;
    }
};

// 不仅仅是二分查找：二分查找需要注意查过的mid不要再查
// 用了一个先找最大值再找划分区间，从中找的注意，注意边界，过于复杂
//   target vs nums[0]  | target vs nums[mid]  | nums[0] vs nums[mid]  | ans
//                      |                      |                       |    
//         >            |        >             |        >              |   <
// > > > | <
// > > < | >
// > < > | >
// > < < | >

// < > > | >
// < > < | >
// < < > | >
// < < < | <

/*
int search(vector<int>& nums, int target) {
    int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}
*/
class Solution {
public:

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return -1;
        }
        int lo = 0, hi = nums.size() - 1, mid = (hi + lo)/2;
        int maxi = 0;
        while(lo <= hi){
            //cout << lo << mid << hi << endl;
            mid = (hi + lo)/2;
            if(nums[mid] < nums[lo]){
                hi = mid - 1;
            }else if(nums[mid] > nums[lo]){
                lo = mid;
            }else{
                break;
            }
            //cout << lo << mid << hi << endl;
        }
        maxi = nums[hi] > nums[lo] ? hi : lo;
        //cout << "maxi:" << maxi << endl;
        lo = 0, hi = nums.size() - 1, mid = (hi + lo)/2;
        if(target < nums[lo]){
            lo = maxi + 1;
        }else if(target > nums[lo]){
            hi = maxi;
            lo = lo + 1;
        }else{
            return lo;
        }
        while (lo <= hi)
        {
            mid = (hi + lo)/2;
            if(target < nums[mid]){
                hi = mid - 1;
            }else if(target > nums[mid]){
                lo = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};


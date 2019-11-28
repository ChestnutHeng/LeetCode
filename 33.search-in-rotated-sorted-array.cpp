/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

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


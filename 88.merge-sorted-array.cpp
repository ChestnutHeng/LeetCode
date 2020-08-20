/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

// 思路：从后面开始归并
// 坑1：下标要对，不是m，n开始
// 坑2：nums1可能没数字，但是有位置
// 坑3：nums1长度可能有多余

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        int p = m + n -1;
        while(p1>=0 && p2>=0){
            if(nums1[p1] > nums2[p2]){
                nums1[p] = nums1[p1];
                p1--;
            }else{
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        // p2剩下的元素拷贝进来
        while(p2>=0){
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }

};
// @lc code=end


/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// 也是同样的三指针的思想
// 每次指针移动后查看是否更接近目标，接近则更新

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
bool comp(int a,int b){return a < b;}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end(), comp);
        int like = INT_MAX;
        int likes = target;
        int lo = 0, lo2 = 1, hi = nums.size() - 1;
        for(lo = 0; lo < nums.size(); ++lo){
            lo2 = lo + 1;
            hi = nums.size() - 1;
            while(lo2 < hi){
                int sumi = nums[lo] + nums[lo2] + nums[hi];
                if (abs(sumi - target) < like){
                    like = abs(sumi - target);
                    likes = sumi;
                }
                if (sumi == target){
                    return target;
                }
                if(sumi < target){
                    lo2++;
                }
                if(sumi > target){
                    hi--;
                }
            }
        }
        return likes;
    }
};


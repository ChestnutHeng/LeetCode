/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start

// 一道细节题，考虑清楚所有的组合，单0单1，纯正数，纯负数，正负数

// [7,8,9]
// [1]
// [-1,-2]
// [1000,-1]
// [0]

#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());


        int start = 0;
        vector<int> numsp;
        int lasti = -1;
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0 && nums[i] != lasti){
                numsp.push_back(nums[i]);
                lasti = nums[i];
            }
        }
        if (numsp.empty()){
            return 1;
        }
        if (numsp[0] > 1){
            return 1;
        }
        if (numsp[start] == numsp.back()){
            return numsp[start] == 1 ? 2 : 1;
        }
        for(int i = start + 1; i < numsp.size(); ++i){
            if (numsp[i] - numsp[i-1] != 1){
                return numsp[i-1] + 1;
            }
            if (numsp[i] == numsp.back()){
                return numsp[i] > 0 ? numsp[i] + 1 : 1;
            }
        }
        return 1;
    }
};
// @lc code=end


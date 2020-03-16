/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start

// 1. 交换递归法 获得所有序列
// 2. 注意去重

// case 1: 1 2 2
// case 2: 2 2 1 1

#include <vector>
using namespace std;

class Solution {
public:
bool isGood(vector<int> nums, int l, int h){
    for (int i = l; i < h; i++){
        if (nums[i] == nums[h]){
            return false;
        }
    }
    return true;
}

void search(vector<vector<int>> &ans, vector<int> nums, int now){
    if(now == nums.size() - 1){
        ans.push_back(nums);
        return;
    }
    for(int i = now; i < nums.size(); ++i){
        if (!isGood(nums, now, i)){
            continue;
        }
        swap(nums[now], nums[i]);
        search(ans, nums, now + 1);
        swap(nums[now], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    search(ans, nums, 0);
    return ans; 
}

};
// @lc code=end


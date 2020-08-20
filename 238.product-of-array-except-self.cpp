/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start

// 如果用除法的话，有零是没办法处理的
// 构造一个l数组，存储下标i左边的所有的乘积值
// 右边同理

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            l[i] = nums[i - 1]* l [i - 1];
        }
        vector<int> r(nums.size(), 1);
        for(int i = nums.size() - 2; i >= 0; --i){
            r[i] = nums[i + 1]* r[i + 1];
        }
        vector<int> ans;
        for(int i = 0; i < l.size(); ++i){
            ans.push_back(l[i] * r[i]);
        }
        return ans;
    }
};
// @lc code=end


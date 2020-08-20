/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

// 注意不要修改迭代中的数组长度
//                        []                                  
//   ┌───────┬────────────┴───────────────┐                   
//  [3]     [2]                          [1]                  
//          └───────┐             ┌───────┴───────┐           
//                 [23]          [13]            [12]         
//                                               └───────┐    
//                                                     [123]  

class Solution {
public:
    // 递归法，每次在每个子集里加新的数字生成新子集
    vector<vector<int>> subsetsR(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>({}));
        for(auto num : nums){
            int size = ans.size();
            for(int i =0;i < size; ++i){
                vector<int> v = ans[i];
                v.push_back(num);
                ans.push_back(v);
            }
        }
        return ans;
    }
    // 回溯法
    // 实际上是一颗子集N叉树的前序遍历
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        bt(nums, path, 0 , ans);
        return ans;
    }
    void bt(vector<int> nums, vector<int> path, int start, vector<vector<int>> &ans){
        ans.push_back(path);
        for(int i = start; i < nums.size(); ++i){
            path.push_back(nums[i]);
            bt(nums, path, i + 1, ans);
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.subsets(nums);
    for(auto v1 : ans){
        for(auto v2 : v1){
            cout << v2 << " ";
        }
        cout << endl;
    }
}
// @lc code=end


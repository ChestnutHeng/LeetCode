/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

// 思路，三个指针，一个标记左边全是0的分界，一个标记右边全是2的分界，一个遍历数组
// 注意，把p2和i互换之后，i的值要再检查一遍

// [2,0,1]
// [1,2,0]
// [0,2,2,2,0,2,1,1]
// [2,0,2,1,1,0] 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0, p2 = nums.size() - 1;
        for(int i = p1; i <= p2;){
            if(nums[i] == 2){
                swap(nums[p2], nums[i]);
                p2--;
            }else if(nums[i] == 0){
                swap(nums[p1], nums[i]);
                p1++;
                i++;
            }else{
                i++;
            }
            // for(auto v :nums)cout << v << " ";
            // cout << endl;
            // cout << p1 << p2 << i << endl;
        }
    }
};
// @lc code=end


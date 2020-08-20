/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start

// 由于没有额外的空间做哈希表，只能在本地交换
// 本地交换需要把正确的正数都放在对应的下标上（相当于阉割的桶排序）
// 遍历找出第一个没有放正确数字的桶
// 注意有个-INT_MAX的用例

#include <algorithm>
using namespace std;

class Solution {
public:
// -1 -2 -1 0
// 6 5 3 2 1
// 5 4 3 2
// 1 2 3
// 1 1
// -1,0,-2147483648
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            long should = long(nums[i]) - 1;
            while(should >= 0 && should < nums.size() && should != i && nums[should] != nums[i]){
                swap(nums[should], nums[i]);
                should = nums[i] - 1;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end


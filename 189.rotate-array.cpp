/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    // 新建On数组
    // 反转三次
    // 环状替换，不断交换元素到正确位置
    // 注意总共交换n次就完成了，不能重复交换了
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int seg = nums.size() - k;
        int times = 0;
        for(int i = 0; times < nums.size(); ++i){
            int lasti = i;
            do{
                if(lasti < seg){
                    swap(nums[i], nums[lasti + k]);
                    lasti += k;
                }else{
                    swap(nums[i], nums[lasti - seg]);
                    lasti -= seg;
                }
                times ++;
            }while(lasti != i);
        }
    }
    void rotateR(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end


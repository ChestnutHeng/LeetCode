/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// 每看到一个正确元素就往头部放。
/*
int idx=0;
for(int i=0;i<nums.size();i++) {
    if(nums[i]!=val) {
        nums[idx] = nums[i];
        idx ++;
    }
}
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tail = nums.size() - 1;
        while(tail >=0 && nums[tail] == val){
            tail--;
        }
        int i = 0;
        while(i <= tail){
            if(nums[i] == val){
                swap(nums[i], nums[tail]);
                while(nums[tail] == val)tail--;
            }
            i++;
        }
        return i;
    }
};

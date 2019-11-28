/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// 每次推出一个元素的想法虽然不错，但是要注意尾部指针的位置，以及每次推出元素后都减一
// 也可以每看到一个正确元素就往头部放。
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
        int sum = 0;
        int tail = nums.size() - 1;
        for(int i =0; i < nums.size(); ++i){
            while(tail >= 0 && nums[tail] == val){
                tail--;
                nums.pop_back();
            }
            if (nums[i] == val){
                if (i < tail){
                    swap(nums[i], nums[tail]);
                    tail--;
                    nums.pop_back();
                }
            }else{

            }
        }
        return nums.size();
    }
};


/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
//[4,2,0,2,3,2,0]

// 注意两步：
// 1. 从后往前找，每找到一个比自己小的数就换一下，确保新数更大
// 2. 换的位置最靠后的一组，就是下一个字典序数字
// 3. 一直找不到的话，就返回逆序

// 坑：换了之后，对后面的数字重新从小到大排序，保证最小

// 官方解法：
// 1. 从后往前，先找到第一个比后面小的数字A（这个数破坏了数组的从后往前的递增
// 2. 从后到A，找出第一个比A大的数字B，和A交换 （这个数字是A后面最小的且满足比A大的数字
// 3. 把B后面的数组反转（以前是从大到小的顺序，改成从小到大，保证最小

bool cmp(int a, int b){return a < b;}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int maxj = -1;
        int maxi = -1;
        for(int i = nums.size() - 1; i >= 0; -- i){
            for(int j = i - 1; j >= 0; -- j){
                if(nums[i] > nums[j]){
                    if(j > maxj){
                        maxj = j;
                        maxi = i;
                        break;
                    }
                }
            }
        }

        if(maxi != -1){
            swap(nums[maxi], nums[maxj]);
            sort(nums.begin() + maxj + 1, nums.end(), cmp);
        }else{
            reverse(nums.begin(), nums.end());
        }
    }
};


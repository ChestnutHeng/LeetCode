/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start

// 洗牌算法，遍历数组，交换 nums[i], nums[k] k = [i, nums.size()-1] 随机选一个
class Solution {
public:
    vector<int> data;
    Solution(vector<int>& nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(data.empty()) return data;
        vector<int> ans = data;
        for(int i = 0; i < ans.size() - 1; ++i){
            swap(ans[i], ans[rand() % (ans.size() - i) + i]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

// 基本的去重：看过的i在j就不看了
// case 1: []
// case 2: [0,0,0]      // 
// case 3: [0,0,0,0]    // 看过的j前一个j就不查了

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> hash;
        vector<vector<int>> desu;
        if(nums.size() < 3 ){
            return desu;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i){
            if (i == nums.size() || (i > 0 && nums[i] != nums[i-1])){
                hash[nums[i-1]] = i-1;
            }
        }
        for(int ai = 0;ai < nums.size();ai++){
            if(ai > 0 && nums[ai] == nums[ai-1]){
                continue;
            }
            for(int aj = ai+1;aj < nums.size();aj++){
                if(aj > ai+1 && nums[aj] == nums[aj-1]){
                    continue;
                }
                int i = nums[ai];
                int j = nums[aj];
                int k = -(i+j);
                //cout << hash[i] << hash[j] << hash[k] << endl;
                if(hash.find(k) != hash.end() && hash[k] > aj){
                    //cout << ai << aj << hash[k] << endl;
                    vector<int> a = {i, j, - i - j};
                    desu.push_back(a);
                }
            }
        }
        return desu;
    }
};
// @lc code=end


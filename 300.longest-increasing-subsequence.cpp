

// 方法1：dp，如果当前元素比之前序列的末尾元素大，就可以添加当前元素到最长的子序列
// dp[i] = max(dp[i], dp[j] + 1); j = 0 ... i


class Solution {
public:
    // [1,3,6,7,9,4,10,5,6]
    // 1 2 7 9 4 5 6 10
    // 1 2 7 8 9 5 6 10
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size() + 1, 1);
        int ans = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i ; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
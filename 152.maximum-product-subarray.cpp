/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// DP的时候注意，不一定满足最优子结构，所以还要维护一个最小值的dp表
// maxF[i] = max(nums[i] * maxF[i-1], nums[i], minF[i-1]*nums[i]);
// minF[i] = min(minF[i-1]*nums[i], nums[i], maxF[i-1]*nums[i]);

// @lc code=start
class Solution {
public:
    //2
    //6   3 
    //-12 -6 -2
    //-48 -24 -8  4
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        int maxa = max(INT_MIN, nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            maxF[i] = max(nums[i] * maxF[i-1], max(nums[i], minF[i-1]*nums[i]));
            minF[i] = min(minF[i-1]*nums[i], min(nums[i], maxF[i-1]*nums[i]));
            maxa = max( maxF[i], maxa);
        }
        return maxa;
    }
    
    int maxProductTLE(vector<int>& nums) {
        vector<vector <int> > dp (nums.size(), vector<int>(nums.size(), 1));
        int maxa = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i; j >= 0; --j){
                if(i == j){
                  dp[i][j] = nums[i];
                }else{
                    dp[i][j] = dp[i][j+1] * nums[j];
                }
                //cout << dp[i][j] << endl;
                maxa = max(maxa, dp[i][j]);
            }
        }
        return maxa;
    }
};
// @lc code=end


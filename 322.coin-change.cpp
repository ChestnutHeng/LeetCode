/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start


// 找零钱，假设有几种面值 1,2,5， 求11块钱最少能几张钞票找回来
// 方法1：DFS+贪心+剪枝，还是会超时
// 方法2：dp，dp[i] = min(dp[i-coins[j]] + 1, dp[i]) j = 0 ... coins.size()

class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        // 无解的时候INT_MAX + 1会越界，所以取一个小的值
        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(i-coins[j] >= 0){
                    //cout << i << " " << i-coins[j] << endl;
                    dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
                }
            }
        }
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
    
    int target;
    int ans = INT_MAX;
    int coinChangeDFS(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        target = amount;
        sort(coins.begin(), coins.end());
        dfs(coins, 0, coins.size() - 1, 0);
        return ans == INT_MAX ? - 1 : ans;
        
    }
    
    void dfs(vector<int> &coins, int depth, int right, int summ){
        if(depth >= ans){
            return;
        }
        for(int i = right; i >= 0; --i){
            if(summ + coins[i] == target){
                ans = min(ans, depth+1);
            }else if(summ + coins[i] < target){
                dfs(coins, depth + 1, i, summ + coins[i]);
            }else{
                
            }
        }
    }
};
// @lc code=end


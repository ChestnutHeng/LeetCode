/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start


// 解法1：遍历，在每个点买入，看在后面每个点卖出的利润
// 解法2：没个点卖出的最高价，取决于之前买入点的最低价，用一个变量记下之前的最低点
// 这个方法其实是一个dp， dp[i]=max(dp[i−1],prices[i]−minprice)
// 解法3：单调栈，维护一个最小值的栈，每次拿栈底和当前值比

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = INT_MAX;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] > mini){
                maxi = max(maxi, prices[i] - mini);
            }
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
    int maxProfitB(vector<int>& prices) {
        int maxi = 0;
        for(int i = 0; i < prices.size(); ++i){
            for(int j = i + 1; j < prices.size(); ++j){
                if(prices[j] - prices[i]> maxi){
                    maxi = prices[j] - prices[i];
                }
            }
        }
        return maxi;
    }
};
// @lc code=end


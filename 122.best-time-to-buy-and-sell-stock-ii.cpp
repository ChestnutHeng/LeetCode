/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

// 关键：每次波谷必然买，波峰必然卖，就会得到最优的收益
// 方法1：每次找到一个波谷（一直跌到开始涨）和波峰（一直涨到开始跌），记录他们的差
// 方法2：方法1可以简化为求股票曲线的所有递增阶段的和

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
// @lc code=end


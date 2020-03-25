/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <vector>
using namespace std;

// 和上一题一样的DP，但是要注意阻断
// 注意初始化时第一行第一列，也有阻断的情况
// 注意溢出的情况，矩阵中会有溢出的

// [[1,0]]
// [[0,0],[1,0]]
// [[0]]

class Solution
{
public:
    void print(vector<vector<int>> &dp)
    {
        for (auto s : dp)
        {
            for (auto v : s)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
            return 0;
        vector<vector<uint64_t>> dp(obstacleGrid.size(), vector<uint64_t>(obstacleGrid[0].size(), 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        //print(dp);
        for (int i = 1; i < obstacleGrid.size(); ++i)
        {
            dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
        }
        for (int j = 1; j < obstacleGrid[0].size(); ++j)
        {
            dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i)
        {
            for (int j = 1; j < obstacleGrid[i].size(); ++j)
            {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
            //print(dp);
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end

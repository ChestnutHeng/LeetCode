/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start

// DP入门
// 从最右下的点开始，最右下的点的路径数量P(m,n)=P(m-1,n) + P(m, n-1)
// 初始化：把第一列初始化后，下面的列都可以用转移方程求得

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0)
        {
            return 0;
        }
        int dp[m][n];
        memset(dp, 0, sizeof(int) * m * n);
        dp[0][0] = 1;
        for (int i = 0, j = 0; i < m && j < n; ++i && ++j)
        {
            for (int jj = j; jj < n; ++jj)
            {
                if (i == 0 && jj == 0)
                    continue;
                dp[i][jj] = (i >= 1 ? dp[i - 1][jj] : 0) + (jj >= 1 ? dp[i][jj - 1] : 0);
                //cout << ":" << dp[i][jj];
            }
            //cout << endl;
            for (int ii = i; ii < m; ++ii)
            {
                if (ii == 0 && j == 0)
                    continue;
                dp[ii][j] = (ii >= 1 ? dp[ii - 1][j] : 0) + (j >= 1 ? dp[ii][j - 1] : 0);
                //cout << "!" << dp[ii][j];
            }
            //cout << endl;
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

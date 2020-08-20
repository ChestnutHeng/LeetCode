/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start

// DP入门
// 从最右下的点开始，最右下的点的路径数量P(m,n)=P(m-1,n) + P(m, n-1)
// 初始化：把第一列初始化后，下面的列都可以用转移方程求得

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(n,vector<int>(m,1));
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[n - 1][m - 1];
    }
};
// @lc code=end

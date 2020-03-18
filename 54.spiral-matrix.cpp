/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
/* 思路：研究蛇形的公式太复杂了，边界容易出错，不如用四个点锚定，
第一次遍历第一行，就把第一行剪切掉，遍历一列，就把一列剪切掉。
最后发现任意的行或者列是最后剪掉就没的了，循环结束
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> mat;
        if (matrix.empty())
            return mat;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = 0;
        while (c < m - c && r < n - r)
        {
            for (int i = c; i < m - c; ++i)
            {
                mat.push_back(matrix[r][i]);
            }
            //cout << "A:" << c << " " << m - c << endl;
            for (int j = r + 1; j < n - r; ++j)
            {
                mat.push_back(matrix[j][m - c - 1]);
            }
            //cout << "B:" << r + 1 << " " << n - r << endl;
            for (int i = m - c - 2; r < n - r - 1 && i >= c; --i)
            {
                mat.push_back(matrix[n - r - 1][i]);
            }
            //cout << "C:" << m - c - 2 << " " << c << endl;
            for (int j = n - r - 2; c < m - c - 1 && j >= r + 1; --j)
            {
                mat.push_back(matrix[j][c]);
            }
            //cout << "D:" << n - r - 2 << " " << r + 1 << endl;
            c++;
            r++;
        }
        return mat;
    }
};
// @lc code=end

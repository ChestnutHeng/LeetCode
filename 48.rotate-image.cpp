/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// 思路：其实一个图像的旋转可以分解为每条边、每4个点的旋转
// 坑1：i,j位置的点旋转后的点对应的坐标是什么
// 坑2：注意每次哪些点要旋转，注意i,j的范围

// 思路2：先转置矩阵，然后reverse每一行

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n <= 1)
            return;
        for (int r = 0; r < n - 1 - r; r++)
        {
            for (int c = r; c < n - 1 - r; c++)
            {
                swap(matrix[r][c], matrix[c][n - r - 1]);
                swap(matrix[r][c], matrix[n - r - 1][n - c - 1]);
                swap(matrix[r][c], matrix[n - c - 1][r]);
            }
        }
    }
};
// @lc code=end

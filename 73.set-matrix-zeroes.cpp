/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

// 思路就是用第一个遇到0的那行那列标记一下

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int robrow = -1;
        int robcol = -1;
        bool isf = true;
        for(int i=0;i < matrix.size(); ++i){
            for(int j = 0; j <matrix[i].size(); ++j){
                if(isf && matrix[i][j] == 0){
                    robrow = i;
                    robcol = j;
                    isf = false;
                }
                if(matrix[i][j] == 0){
                    matrix[robrow][j] = 0;
                    matrix[i][robcol] = 0;
                }
            }
        }
        if(robrow == -1){
            return;
        }
        for(int i=0;i < matrix.size(); ++i){
            for(int j = 0; j <matrix[i].size(); ++j){
                if((i!=robrow&&j!=robcol)&&(matrix[robrow][j] == 0 || matrix[i][robcol] == 0)){
                    matrix[i][j] = 0;
                }
            }
        }
        matrix[robrow] = vector<int>(matrix[robrow].size(), 0);
        for(auto &v : matrix){
            v[robcol] = 0;
        }
    }
};
// @lc code=end


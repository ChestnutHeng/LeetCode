/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start


// 1. 二维数组初始化
// 2. bitmap每次用前初始化
// 3. bitmap查失败后恢复false

class Solution {
public:
    bool find(vector<vector<char>>& board, vector<vector<bool>> bitmap, string &word, int p, int i, int j){
        if(p == word.size()){
            return true;
        }
        //cout << word[p];
        if(i + 1 < board.size() && !bitmap[i+1][j] && board[i+1][j] == word[p]){
            bitmap[i+1][j] = true;
            if(find(board, bitmap, word, p+1, i+1, j)){
                return true;
            }
            bitmap[i+1][j] = false;
        }
        if(i - 1 >= 0 && !bitmap[i-1][j] && board[i-1][j] == word[p]){
            bitmap[i-1][j] = true;
            if(find(board, bitmap, word, p+1, i-1, j)){
                return true;
            }
            bitmap[i-1][j] = false;
        }
        if(j + 1 < board[i].size() && !bitmap[i][j+1] && board[i][j+1] == word[p]){
            bitmap[i][j+1] = true;
            if(find(board, bitmap, word, p+1, i, j+1)){
                return true;
            }
            bitmap[i][j+1] = false;
        }
        if(j - 1 >= 0 && !bitmap[i][j-1] && board[i][j-1] == word[p]){
            bitmap[i][j-1] = true;
            if(find(board, bitmap, word, p+1, i, j-1)){
                return true;
            }
             bitmap[i][j-1] = false;
        }
        //cout << "===" << endl;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int p = 0;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == word[p]){
                    vector<vector<bool>> bitmap(board.size(), vector<bool>(board[0].size(), 0));
                    bitmap[i][j] = true;
                    if(find(board, bitmap, word, p+1, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 可以先画个图理清搜索的思路
// 1. dfs，暴力搜出所有可能
// 2. 括号匹配的条件：左右括号数相等
// 3. 剪枝的条件：右括号更多时肯定无法匹配

// DP
// dp[i] = "(" + dp[j] + ")" + dp[i- j - 1] , j = 0, 1, ..., i - 1

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string now;
        dfs(now, n, 0, 0, ans);
        return ans;
    }
    
    void dfs(string now, int n, int left, int right, vector<string> &ans){
        if(left > n || right > n){
            return;
        }
        if(left == n && right == n){
            ans.push_back(now);
            return;
        }
        if(left < right){
            return;
        }
        dfs(now + "(", n, left + 1, right, ans);
        dfs(now + ")", n, left, right + 1, ans);
    }
};

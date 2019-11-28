/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 1. dfs，暴力搜出所有可能
// 2. 括号匹配的条件：左右括号数相等
// 3. 剪枝的条件：右括号更多时坑定无法匹配

class Solution {
public:
    void dfs(vector<string> &ans, char * arr, int l, int r, int size, int i){
        if(i == size){
            if (l == r) {ans.push_back(string(arr));}
            return;
        }
        if (r > l) return;
        if (l > size/2) return;
        arr[i] = '(';
        dfs(ans, arr, l + 1, r, size, i + 1);
        arr[i] = ')';
        dfs(ans, arr, l, r + 1, size, i + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        char *arr = new char[2*n + 1];
        arr[2*n] = '\0';
        arr[0] = '(';
        dfs(ans, arr, 1, 0, 2*n, 1);
        delete []arr;
        return ans;
    }
};


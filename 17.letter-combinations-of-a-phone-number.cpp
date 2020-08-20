/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

// 回溯/DFS
// 注意空值
class Solution {
public:
    map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string now;
        dfs(digits, 0, now,  ans);
        return ans;
    }
    
    void dfs(string digits, int pos, string now, vector<string> &ans){
        if(pos == digits.size()){
            if(now.size())ans.push_back(now);
            return;
        }
        char v = digits[pos];
        for(auto c : phone[v]){
            now.push_back(c);
            dfs(digits, pos + 1, now, ans);
            now.pop_back();
        }
    }
};


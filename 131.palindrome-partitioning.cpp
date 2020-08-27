/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start

// dfs+回溯
// 先画出搜索树，发现所有前缀不是回文串的都可以剪枝
// 回溯搜索剩下的串


// 可以用二维数组预处理(i,j)是否回文串

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, s.size() - 1, path);
        return ans;
    }
    
    void dfs(string s, int lo, int hi, vector<string> &path){
        if(lo > hi){
            ans.push_back(path);
            return;
        }
        for(int i = lo; i <= hi; i++){
            if(!isPalin(s, lo, i)){
                continue;
            }
            path.push_back(s.substr(lo, i-lo+1));
            dfs(s, i+1, hi, path);
            path.pop_back();
        }
    }
    
    bool isPalin(string s, int lo, int hi){
        while(lo <= hi){
            if(s[lo] == s[hi]){
                lo++;
                hi--;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


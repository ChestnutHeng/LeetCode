/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// 解法1：取第一个字符串，把他和数组中的每个字符串逐个比较，找出公共前缀
// 解法2：排序，然后用第一个字符串和最后一个比较


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return string("");
        }
        string ans = "";
        int longest = 0;
        int longesti = 0;
        for (int i = 0;i < strs.size(); ++i){
            if (strs[i].size() > longest){
                longest = strs[i].size();
                longesti = i;
            }
        }
        for(int i = 0; i < strs[longesti].size(); ++i){
            char com = strs[longesti][i];
            for(int j = 0; j < strs.size(); ++j){
                if (i >= strs[j].size() || strs[j][i] != com){
                    return ans;
                }
            }
            ans += com;
        }
        return ans;
    }
};



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
bool comp(int a,int b){return a < b;}

map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

// 没啥意思，注意顺序
class Solution {
public:
    
    void letterSearch(vector<string> &ans, string digits, int index){
        if (index == digits.size() - 1){
            
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()){
            return ans;
        }
        for(int n = 0; n < (phone)[digits[0]].size(); n++){
            string s = string("") + phone[digits[0]][n];
            ans.push_back(s);
        }

        for(int i = 1;i < digits.size(); ++i){
            vector<string> new_ans;
            reverse(ans.begin(), ans.end());
            while(!ans.empty()){
                string s = ans.back();
                ans.pop_back();
                for(int j =0; j < phone[digits[i]].size(); ++j){
                    new_ans.push_back(s + phone[digits[i]][j]);
                }
            }
            ans = new_ans;
            new_ans.clear();
        }
        return ans;
    }
};


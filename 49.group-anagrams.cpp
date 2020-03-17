/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

// 思路：很朴素的，用排序过的字符串做key
// 优化：排序可以自己写一个桶排序更快速

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, list<vector<string>>::iterator > mp;
        list<vector<string>> ans;
        for(auto s : strs){
            string ach =  "}}}}}}}}}}}}}}}}}}}}}}}}}}";
            for(char c : s){
                ach[(c - 'a')] += 1;
            }
            string key(ach);
            if(mp.count(key)){
                mp[key]->push_back(s);
            }else{
                vector<string> b = {s};
                ans.push_back(b);
                auto it = ans.end();
                --it;
                mp[key] =  it;
            }
        }
        vector<vector<string>> a;
        for (auto v : ans){
            a.push_back(v);
        }
        return a;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        for(auto s : strs){
            mp[genStr(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto kv : mp){
            ans.push_back(kv.second);
        }
        return ans;
    }

    string genStr(string s){
        int co[26] = {0};
        for(char ch : s){
            co[ch - 'a'] += 1;
        }
        string news;
        for(int i = 0; i < 26; ++i){
            //int times = co[i];
            //while(times--) news += (i + 'a');
            news += string(co[i], i + 'a');
        }
        //cout << news << endl;
        return news;
    }
};



// int main(int argc, char const *argv[])
// {
//     vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
//     Solution s;
//     s.groupAnagrams(strs);
//     return 0;
// }

// @lc code=end


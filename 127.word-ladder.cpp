/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include "inc.h"


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        rr(beginWord, endWord, wordList, 1);
        return minlen == INT_MAX ? 0 : minlen;
    }
    int minlen = INT_MAX;
    bool islike(string &s1, string &s2){
        int len = 0;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i]){
                len++;
            }
        }
        return len == 1;
    }
    void rr(string &beginWord, string &endWord, vector<string>& wordList, int nowlen){
        if(beginWord == endWord){
            minlen = min(minlen, nowlen);
        }
        for(auto v : wordList){
            if(islike(beginWord, v)){
                rr(v, endWord, wordList, nowlen + 1);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<string> wd({"hot","dot","dog","lot","log","cog"});
    Solution s;
    s.ladderLength("hit", "cog", wd);
    return 0;
}

// @lc code=end


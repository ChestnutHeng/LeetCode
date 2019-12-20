/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

// 这道题遍历一遍就能搞定，用哈希记下遍历过的数字
// 一旦产生重复，需要从哪开始重新遍历？

// 注意结尾的时候也要结算
// 注意重复字母 "bbbb"
// 注意空字符 " "
// 注意字符 "dvdf" "pwwkew"
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> lastp;
        int p1 = 0, maxl = 0;
        int p2 = 0;
        while(s[p2] != '\0'){
            if(lastp.find(s[p2]) != lastp.end()){
                if (maxl < p2 - p1){
                    maxl = p2 - p1;
                }
                p1 = lastp[s[p2]] + 1;
                p2 = p1;
                lastp.clear();
            }
            //cout << p1 << p2 << maxl << endl;
            lastp[s[p2]] = p2;
            p2++;
        }
        if (maxl < p2 - p1){
            maxl = p2 - p1;
        }
        return maxl;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
// 双指针，栈，reverse三种方法
// 注意是数字或者字母都可以

class Solution {
public:
    char getch(char c){
        if(c >= 'a' && c <= 'z'){
            return c;
        }
        if(c >= 'A' && c <= 'Z'){
            return c - 'A' + 'a';
        }
        return '\0';
    }
    bool isPalindrome(string s) {
        string s2;
        for(auto c  : s){
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                s2.push_back(c);
            }
            if(c >= 'A' && c <= 'Z'){
                s2.push_back(c - 'A' + 'a');
            }
        }
        s = s2;
        if(s.size() <= 1){
            return true;
        }
        int p1 = 0;
        int p2 = s.size() - 1;
        while(p1 < p2){
            if(s[p1] != s[p2]){
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};
// @lc code=end


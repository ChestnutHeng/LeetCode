/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

// 如果下一个元素比当前的小，就做减法，否则加法

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            int next = i < s.size() - 1 ? getCh(s[i+1]) : -1;
            int now = getCh(s[i]);
            if(next > now){
                ans -= now;
            }else{
                ans += now;
            }
        }
        return ans;
    }
    
    int getCh(char ch){
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
// @lc code=end


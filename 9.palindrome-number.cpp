/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

// 注意int溢出
// 快速解法并解决溢出：
// 存两个数字，一个标识x的前一半（slow），一个表示x后一半的颠倒（revhalf）
// 数字有奇数位时，slow=revhalf/10，偶数位时， slow = revhalf

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int hus = x;
        long wife = 0;
        while(x > 0){
            int d = x % 10;
            wife = wife*10 + d;
            x = x / 10;
        }
        return wife == hus;
    }
    
    bool isPalindromeF(int x) {
        if(x < 0) return false;
        int revhalf = 0, slow = x, fast = x;
        while(fast){ 
            revhalf = revhalf * 10 + slow % 10;
            slow /= 10;
            fast /= 100;
        }
        return slow == revhalf || slow == revhalf / 10;
    }
};
// @lc code=end


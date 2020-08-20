/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start

// 注意最后的0也要加上
// 不用循环，分治按位翻转。
// 第一次：n >> 16 | n << 16 完成一次
// 第二次：n 第1~8, 第17~24 位右移8位， 第9~16位，第25~32 位左移8位

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0)return 0;
        uint32_t ans = 0;
        int bit = 32;
        while(bit--){
            if(n % 2 == 1){
                ans = ans*2 + 1;
            }else{
                ans = ans*2;
            }
            n = n / 2;
        }
        return ans;
    }
};
// @lc code=end


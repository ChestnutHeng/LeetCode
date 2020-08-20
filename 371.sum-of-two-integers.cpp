/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start

// a ^ b 等价于a+b没有进位的值
// (a & b) << 1 等价于a+b进位的值
// 再把两个值相加


class Solution {
public:
    int getSumC(int a, int b) {
        if(!a || !b) return a | b;
        return getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
    int getSumB(int a, int b) {
        while(b != 0){
            int temp = a ^ b;
            b = (a & b) << 1;
            a = temp;
        }
        return a;
    }
    int getSum(int a, int b) {
        int plus = a & b;
        int summer = 0;
        summer = a ^ b;
        return plus ? getSum((unsigned int)plus << 1, summer) : summer;
    }
};
// @lc code=end


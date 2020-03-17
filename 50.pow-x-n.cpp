/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

// 思路：平方快速幂
// 坑1：注意递归的时候(pow(x, n))^2 == (pow(x^2, n))，避免重复运算
// 坑2：注意INT_MIN的负数会溢出

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)return 1;
        if (n < 0) return 1/(myPow(x, -(n+1))*x);
        if(n == 1){
            return x;
        }
        if(!(n & 1)){
            return myPow(x*x, n/2);
        }else{
            return myPow(x*x, n/2) * x;
        }
    }

    // double myPow(double x, int n) {
    //     double res = 1.0;
    //     int i = n;
    //     if(i % 2){
    //         res = x
    //     }
    // }
};
// @lc code=end


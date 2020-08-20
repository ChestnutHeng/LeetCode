/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

// 一个简单的dp，f(n) = f(n-1) + f(n-2)
// 从0开始，这样就不用特殊处理n=1和2
// 使用n--，这样就不用算现在是第几项

class Solution {
public:
class Solution {
public:
    int climbStairs(int n) {
        int n1 = 0, n2 = 1;
        int n3;
        while(n--){
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
    int climbStairsR(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
};
// @lc code=end


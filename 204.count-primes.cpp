/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// 筛法，注意i从[2, √n)的，j从[i, n/i]的

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)return 0;
        int co = 0;
        vector<bool> mark(n - 1, true);
        mark[0] = false;
        // 2 3 4 .. 10
        for(int i = 2; i < pow(n, 0.5); ++i){
            // 2 3 .. 4
            // 2 3
            // 2
            // 2
            for(int j = i; j <= n/i; j+=1){
                mark[i*j-1] = false;
            }
        }
        for(auto v : mark){
            if(v) co++;
        }
        return co;
    }
};
// @lc code=end


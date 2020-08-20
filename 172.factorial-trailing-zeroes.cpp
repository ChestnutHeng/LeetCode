/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start

// 1. 找规律发现，只要因子能分解为2和5的一对，就能出现一个零。但是2总是比5多，找能分解为多少5就可以
// 2. 找5的因子的时候，发现[co += 1 if co % 5 == 0 for i in range(1, n)] 等价于co = n / 5
// 3. 但是25里面有两个因子5，上面的式子就漏了一个5的因子。总共漏了多少个？ n / 25 个。125也是同理
// 4. 所以ans = n/5 + n/25 + n/125 + n/625 + ...


class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n > 0){
            n = n / 5;
            ans += n;
        }
        return ans;
    }
};
// @lc code=end


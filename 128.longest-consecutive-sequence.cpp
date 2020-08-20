/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start

// 哈希法：遍历元素，如果元素不存在，加入该元素后那么新的区间长度等于，临近的两个区间长度的和+1
// 更新两端的区间长度(注意当前节点也要更新一个值表示已经访问过)

// 并查集：先set化，建立一个O1能找到的表
// 找的时候，需要关注的是是否是一个区间的头元素，如果是，一直贪心到区间的尾，算出这个元素作为头的长度
// 不是头的要剪枝，否则O(n^2)

// [4,0,-4,-2,2,5,-8,-1,7,6,-3]
// 4
// 0 x x x 4
// -4 x x x 0 x x x 4
// -4 x -2 x 0 x x x 4
// -4 x -2 x 0 x 2 x 4 5
// -8 x x x -4 x -2 x 0 x 2 x 4 5
// -8 x x x -4 x -2 -1 0 x 2 x 4 5 x 7
// -8 x x x -4 -3 -2 -1 0 x 2 x 4 5 6 7

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto v :nums){
            mp.insert(v);
        }
        int res = 0;
        for(auto v : mp){
            if(v != INT_MIN && mp.count(v - 1)){
                continue;
            }
            int co = 1;
            while(v != INT_MAX && mp.count(v + 1)){
                v++;
                co++;
            }
            res = max(res, co);
        }
        return res;
    }
    int longestConsecutiveHash(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for(auto v : nums){
            if(!mp[v]){
                int l = mp[v - 1];
                int r = mp[v + 1];
                int nowl = l + r + 1;
                res = max(res, nowl);
                mp[v] = 1;
                mp[v - l] = nowl;
                mp[v + r] = nowl;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

// 别想太复杂，就是个map计数
// 注意分析简单方案的时间。遍历一遍，建立哈希表O(n)，哈希表变数组O(n)，数组排序O(nlogn)，完事

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct Freq
{
    int num;
    int freq;
    Freq(int n, int f)
    {
        num = n;
        freq = f;
    }
};
bool comp(Freq a, Freq b)
{
    return a.freq > b.freq;
}
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<Freq> hp;
        for (auto v : nums)
        {
            mp[v]++;
        }
        for (auto s : mp)
        {
            Freq f = Freq(s.first, s.second);
            hp.push_back(f);
        }
        sort(hp.begin(), hp.end(), comp);
        vector<int> topk;
        for (int i = 0; i < k; ++i)
        {
            topk.push_back(hp[i].num);
        }
        return topk;
    }
};
// @lc code=end

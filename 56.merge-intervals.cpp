/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

// [[1,4],[0,4]]
// [[0,5],[1,4]]

// 比较优雅的是每次都和ans尾部的那个比较，如果重合就替换

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int a = intervals[0][0], b = intervals[0][1];
        vector<vector<int>> ans;
        for(auto pair : intervals){
            if (pair[0] > b){
                ans.push_back(vector<int>({a, b}));
                a = pair[0];
                b = pair[1];
            }else{
                b = max(b, pair[1]);
            }
        }
        ans.push_back(vector<int>({a, b}));
        return ans;
    }
};
// @lc code=end


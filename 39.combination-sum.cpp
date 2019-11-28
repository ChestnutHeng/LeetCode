/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &ans, set<int> has, vector<int> ball, int target, int left){
        cout << target << ball.size() << endl;
        if(has.find(target) != has.end()){
            ball.push_back(target);
            ans.push_back(ball);
            ball.pop_back();
        }
        if(target < *has.begin()){
            int roll = ball.back();
            ball.pop_back();
            //dfs(ans, has, ball, target + roll, 0);
            return;
        }

        for(auto s : has){
            if(target > s){
                ball.push_back(s);
                dfs(ans, has, ball, target - s, 0);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<int,less<int>> has;
        vector<int> ball;
        for(auto v : candidates){
            has.insert(v);
        }
        dfs(ans, has, ball, target, 0);
        return ans;
    }
};


/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// 回溯法：先列出回滚的状态模拟一遍整理思路
// 注意1：遍历的时候不要改变path数组，push后pop
// 注意2：去重的关键，不要回头找

#include <vector>
#include <set>
using namespace std;

void print(vector<int> ball){
    for(auto v: ball){
        cout << v << " ";
    }
    //cout << endl;
}

class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> ball, vector<int> cand, int target, int now, int dep){
        //print(ball);
        //cout << "" << ":" << now << endl;
        for(int i = dep; i < cand.size(); ++i){
            int v = cand[i];
            //cout << "now" << now <<" v" << v << endl;;
            if (now + v < target){
                ball.push_back(v);
                dfs(ans, ball, cand, target, now+v, i);
                ball.pop_back();
            }else if(now + v > target){
                //
            }else{
                ball.push_back(v);
                //print(ball);
                //cout << " push" << endl;
                ans.push_back(ball);
                ball.pop_back();
            }
        }
        //cout << "fallback" << endl;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ball;
        dfs(ans, ball, candidates, target, 0, 0);
        return ans;
    }
};


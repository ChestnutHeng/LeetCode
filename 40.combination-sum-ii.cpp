/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
// 和上个的唯一区别：遍历的时候不从自己开始，从下个开始

#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> ball, vector<int> cand, int target, int now, int dep){
        //print(ball);
        //cout << "" << ":" << now << endl;
        set<int> used;
        for(int i = dep; i < cand.size(); ++i){
            int v = cand[i];
            //cout << "ddd" << v << (i>0?cand[i-1]:-1) << endl;
            if (used.find(v) != used.end()){
                continue;
            }
            used.insert(v);
            //cout << "now" << now <<" v" << v << endl;;
            if (now + v < target){
                ball.push_back(v);
                dfs(ans , ball, cand, target, now+v, i+1);
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ball;
        sort(candidates.begin(), candidates.end());
        dfs(ans, ball, candidates, target, 0, 0);
        return ans;
    }
};
// @lc code=end


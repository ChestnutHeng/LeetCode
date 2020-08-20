/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < height.size(); ++i){
            while(!stk.empty() && height[stk.top()] < height[i]){
                int nowi = stk.top();
                stk.pop();
                while(!stk.empty() && height[stk.top()] == height[nowi]){
                    stk.pop();
                }
                if(!stk.empty()){
                    int left = stk.top();
                    // 只算这个新柱子这层的，减去上个柱子的层
                    ans += (min(height[left], height[i]) - height[nowi])* (i - left - 1);
                    cout << ans << " " << i << endl;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end


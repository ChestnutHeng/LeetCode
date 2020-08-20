/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start

// 排序的思想没错，但是不能用字典序。而是比较a+b和b+a哪个链接更优

class Solution {
public:
    static bool cmp(string a, string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(auto v : nums){
            snums.push_back(to_string(v));
        }
        sort(snums.begin(), snums.end(), cmp);
        string ans;
        for(auto v : snums){
            ans += v;
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
// 考虑三种情况：进位，连续进位，不进位

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        for(int i=digits.size()-1;i >=0;i--){
            if (digits[i] != 9){
                ans.push_back(digits[i]+1);
                for(int j = i-1;j >= 0;j--){
                    ans.push_back(digits[j]);
                }
                break;
            }else{
                ans.push_back(0);
            }
        }
        if(ans[ans.size()-1]==0){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> plusOne2(vector<int> &digits) {
        bool carry = true;
        
        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};
// @lc code=end


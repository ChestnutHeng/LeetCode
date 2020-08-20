/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

// c++ string.size 是uint类型，如果减去比自己大的会返回uintmax
// 注意进位

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int next = 0;
        for(int i = 1; i <= a.size() || i<=b.size();++i){
            int sum = (a.size() >= i ? a[a.size()-i] - '0': 0) + (b.size() >= i ? b[b.size()-i] - '0': 0) + next;
            if(sum > 1){
                next = sum/2;
                sum = sum%2;
            }else{
                next = 0;
            }
            c.push_back('0'+sum);
        }
        if(next){
            c.push_back('1');
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        int sz = max(a.size(), b.size());
        string c(sz + 1, '0');
        int p1 = a.size() - 1, p2 = b.size() - 1;
        int plus = 0;
        for(int i = 0; i <= sz; i ++){
            int aa = p1 >= i ? a[p1 - i] - '0' : 0;
            int bb = p2 >= i ? b[p2 - i] - '0' : 0;
            int cc = aa + bb + plus;
            plus = cc / 2;
            c[c.size() - 1 - i] = '0' + cc % 2;
        }
        if(c[0] == '0'){
            c = c.substr(1, c.size());
        }
        return c;
    }
};

int main(){
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}
// @lc code=end


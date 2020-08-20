/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s :tokens){
            if(s.size() == 1 && !isdigit(s[0])){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                switch(s[0]){
                    case '+':
                        stk.push(a+b);
                        break;
                    case '-':
                        stk.push(b-a);
                        break;
                    case '*':
                        stk.push(a*b);
                        break;
                    case '/':
                        stk.push(b/a);
                        break;
                }
                //cout << stk.top() << endl;
            }else{
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
// @lc code=end


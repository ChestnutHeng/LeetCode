/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start

// 数字每次解析完
// 记录上一个操作符，如果是加减法，就把数字带上符号入栈，如果是乘法就把栈里的顶上两个元素结合然后入栈
// 最后累加栈里的所有元素

// 如果含有括号呢？括号里的内容可以用一次递归解决
// case '(‘ 的时候发起递归，从i+1开始检查。递归结束后i+1
// case ')' 的时候break，回到主流程

class Solution {
public:
    int calculate(string s) {
        stack<int> q;
        char lastop = '+';
        int num = 0;
        int lastnum = 0;
        for(int i = 0; i < s.size(); ++i){
            char v = s[i];
            if(v >= '0' && v <= '9'){
                num = num * 10 + (v - '0');
            }
            if(v == '+' || v == '-' || v == '*' || v == '/' || i == s.size() - 1){
                //cout << num << endl;
                switch(lastop){
                    case '+':
                        q.push(num);
                        break;
                    case '-':
                        q.push(-num);
                        break;
                    case '*':
                        lastnum = q.top();
                        q.pop();
                        q.push(lastnum * num);
                        break;
                    case '/':
                        lastnum = q.top();
                        q.pop();
                        q.push(lastnum / num);
                        break;
                }
                lastop = v;
                num = 0;
            }
        }
        int ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
// @lc code=end


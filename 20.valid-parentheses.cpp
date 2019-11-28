/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */


// 引用计数解决不了括号互相包括的问题，还是要用栈来匹配
// stack<char> paren ，然后用case处理六种字符的情况更为简洁

#define INIT_STACK(p) (p = -1;)
#define PUSH_STACK(stack, p, x) ((stack)[++(p)] = x;)
#define POP_STACK(stack, p, x) (x = (stack)[(p)--];)

class Solution {
public:
    bool isValid2(string s) {
        map<char, int> times;
        for(int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                times[s[i]] += 1;
            }else{
                times['('] -= s[i] == ')' ? 1 : 0;
                times['['] -= s[i] == ']' ? 1 : 0;
                times['{'] -= s[i] == '}' ? 1 : 0;
            }
        }
        for(auto it = times.begin(); it != times.end(); ++it){
            if (it->second != 0){
                return false;
            }
        }
        return true;
    }
    bool match(char a, char b){
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }

    bool isValid(string s) {
        char *stack = new char[s.size()];
        int top = -1;
        for(int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack[++top] = s[i];
            }else{
                if (top < 0 || !match(stack[top--], s[i])){
                    return false;
                }
            }
        }
        return top == -1 ? true : false;
    }
};


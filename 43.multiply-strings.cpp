/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

#include <string>
using namespace std;
// @lc code=start
#define CTOI(x) (x - '0')
#define ITOC(x) (x + '0')
class Solution {
public:
// insert的用法
// size()和整数做运算
// 三元表达式优先级
// 9999*0 0*9999 的情况
// 123456789 大数

string multi_add(string num1, string num2)
{
    int bei = 0;
    string ans;
    int i = 1;
    int ls1 = num1.size();
    int ls2 = num2.size();
    for (;ls1 - i >= 0 || ls2 - i >= 0; i++)
    {
        //print(ls1 - i >= 0 ? CTOI(num1[ls1 - i]) : 0 , ls2 - i >= 0 ? CTOI(num2[ls2 - i]) : 0 , bei);
        int sum = (ls1 - i >= 0 ? CTOI(num1[ls1 - i]) : 0) + (ls2 - i >= 0 ? CTOI(num2[ls2 - i]) : 0) + bei;
        //print(sum);
        ans.insert(0, 1, ITOC(sum % 10));
        bei = sum / 10;
    }
    if (bei) {
        ans.insert(0, 1, ITOC(bei));
    }
    return ans;
}

string multiply(string num1, string num2)
{
    string ans = "0";
    string tail = "";
    int bei = 0;
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        if(num1[i] == '0'){
            tail += "0";
            continue;
        }
        string sum;
        bei = 0;
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            sum.insert(0, 1, (bei + n1 * n2) % 10 + '0');
            bei = (bei + n1 * n2) / 10;
            //print(n1, n2, bei, (bei + n1 * n2) % 10);
        }
        if (bei)
        {
            sum.insert(0, 1, bei + '0');
        }
        if(sum != "0")sum += tail;
        ans = multi_add(ans, sum);
        tail += "0";
    }

    return ans;
}
};
// @lc code=end


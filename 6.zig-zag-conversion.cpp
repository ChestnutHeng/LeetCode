/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    345K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// key: 用二位数组记录即可。
// 错误， == 写成了 = 。
// 错误，没考虑空字符串
// 错误，没考虑只有一行的情况 "AB"\n1

using namespace std;
#include <string>
#include <string.h>

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if(len == 0){
            return string("");
        }
        string ans;
        char arr[numRows][len];
        memset(arr[0], 0, sizeof(arr));

        int ti = 0, tj = 0;
        int status = 1; // 1 向下 2 向上
        for(int i = 0; i < s.size(); ++i){
            arr[ti][tj] = s[i];
            if (numRows == 1){
                tj ++;
                continue;
            }
            if (status == 1) {
                if (ti + 1 >= numRows) {
                    status = 2;
                    ti--;
                    tj++;
                }else{
                    ti++;
                }
            }else if (status == 2){
                if (ti - 1 < 0) {
                    status = 1;
                    ti++;
                }else{
                    ti--;
                    tj++;
                }
            }
        }
        for (int i = 0; i < numRows; ++i){
            for (int j = 0; j < len; ++j){
                if (arr[i][j] != 0) {
                    ans += arr[i][j];
                }
            }
        }
        return ans;
    }
};


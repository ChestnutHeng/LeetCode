/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// 简单bp，每次选一个出来全排列，知道次数够了为止，容易超时
// 思考发现可以根据k判断出交换的情况，可以分为(n-1)!组，然后算出是这组的第几个，
// 递归解决问题
// 注意：erase是一直删除到末尾
// 注意第几组和第几个的映射关系弄对

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int prc = 0;
    string bp(string now, string left, int k){
        if(left.empty()){
            prc += 1;
            //cout << now << endl;
            if (prc == k){
                return now;
            }
        }
        string bpans;
        for(int i = 0; i  < left.size(); ++i){
            swap(left[0], left[i]);
            if((bpans = bp(now + left[0], left.substr(1, left.size()), k)) != ""){
                return bpans;
            }
        }
        return "";
    }
    int wow[8] = {1, 2, 6, 24, 120, 720, 5040, 40320};
    string fastbp(string now, string left, int lastk){
        if(left.size() == 1){
            return now + left;
        }
        int pos = (lastk - 1) / (wow[left.size() - 2]);
        lastk = lastk - pos * wow[left.size() - 2];
        now += left[pos];
        left.erase(pos, 1);
        //cout << now << " " << left << " " << lastk << endl;
        return fastbp(now , left, lastk);
    }
    string getPermutation(int n, int k) {
        //return bp(string(""), string("123456789").substr(0, n), k);
        return fastbp(string(""), string("123456789").substr(0, n), k);
    }
};
// @lc code=end


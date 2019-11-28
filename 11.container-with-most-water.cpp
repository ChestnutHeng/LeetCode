/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (45.88%)
 * Total Accepted:    417.1K
 * Total Submissions: 908.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

// key很简单，是两个指针，分别从头尾开始搜索
// 错误的原因：应该关注的是水缸的高度h，如果h不比以前大，则一定没有上个最大值大

#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
  public:
    bool myfunction(int i, int j) { return (i < j); }

    int maxArea1(vector<int> &height)
    {
        int max_s = 0;
        int *arr = new int[height.size()];
        // int arri[height.size()];
        // // 比大小表 nlogn
        // int sarr[height.size()][height.size()];
        // for (int i = 0; i < height.size(); ++i){
        //     for(int j = i; j < height.size(); ++j){
        //         sarr[i][j] = arr[i] > arr[j] ? true : false;
        //         sarr[j][i] = !sarr[i][j];
        //     }
        // }

        // 每个和第一个的最大面积
        // for (int i = 0; i < height.size(); ++i){
        //     int now_s = min(height[0], height[i])* (i - 0);
        //     if (now_s > arr[i]) {
        //         arr[i] = now_s;
        //         //arri[i] = 0;
        //     }
        // }

        // for(int j = 1; j < height.size(); ++j){
        //     if j < arr
        // }

        //每个和第一个的最大面积
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = i; j < height.size(); ++j)
            {
                int now_s = min(height[j], height[i]) * (j - i);
                if (now_s > arr[i])
                {
                    max_s = max(max_s, now_s);
                    arr[i] = now_s;
                    //arri[i] = j;
                }
            }
        }
        return max_s;
    }

    int maxArea3(vector<int> &height)
    {
        int max_s = 0;
        int lo = 0, hi = height.size() - 1;
        max_s = (hi - lo) * min(height[lo], height[hi]);
        int max_lo = lo, max_hi = hi;
        while (lo < hi)
        {
            while (height[hi] <= height[max_hi] && lo < hi)
                hi--;
            while (height[lo] <= height[max_lo] && lo < hi)
                lo++;
            int new_s = (hi - lo) * min(height[lo], height[hi]);
            if (new_s > max_s)
            {
                max_s = new_s;
                max_lo = lo;
                max_hi = hi;
            }
        }
        return max_s;
    }

    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }

};

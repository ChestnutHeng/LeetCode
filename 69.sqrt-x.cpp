
// 二分法，与其判别边界，不如最后再统一判别一次


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        int l = 0, r = x;
        while(l <= r){
            int mid = (r + l) >> 1;
            if((long)mid * mid <= x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return (long)r*r <= x ? r : (r-1);
    }
    // 小心int越界
    // 小心0值
    int mySqrtSlow(int x) {
        int i = 1;
        while(i <= x/i)i++;
        return i - 1;
    }
};
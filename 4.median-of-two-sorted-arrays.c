/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

// 2
// 1 3
// 一个已经读完的情况

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mid = (nums1Size + nums2Size) / 2;
    int p1 = 0, p2 = 0, p3 = -1;
    int nowv, lastv;
    while(1){
        if(p1 < nums1Size && p2 < nums2Size){
            lastv = nowv;
            if ( nums1[p1] < nums2[p2] ){
                nowv = nums1[p1];
                p1++;
            }else{
                nowv = nums2[p2];
                p2++;
            }
        }else{
            lastv = nowv;
            if (p1 < nums1Size){
                    nowv = nums1[p1] ;
                    p1++;
            }
            if (p2 < nums2Size){
                    nowv = nums2[p2] ;
                    p2++;
            }
        }
        p3++;
        printf("%d %d %d \n", lastv, nowv, p3);
        if (p3 == mid){
            break;
        }
        lastv = nowv;
    }
    if ((nums1Size + nums2Size) % 2 == 0 ){
        return (lastv + nowv) / 2.0;
    }else{
        return nowv;
    }
}


// @lc code=end


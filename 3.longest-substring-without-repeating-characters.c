/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    char *p1 = s, *p2 = s;
    int maxlen = 0;
    int nowlen = 0;
    short mp[128];
    memset(mp, 0, sizeof(short)*128);
    while (*p2 != '\0')
    {
        if (mp[*p2] == 0) {
            mp[*p2] = 1;
            nowlen++;
            p2++;
        }else{
            p1 = p2;
            if(nowlen > maxlen){
                maxlen = nowlen;
            }
            nowlen = 0;
            memset(mp, 0, sizeof(short)*128);
        }
    }
    if(nowlen > maxlen){
        maxlen = nowlen;
    }
    return maxlen;
}


// @lc code=end


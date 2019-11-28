#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (27.68%)
# Total Accepted:    616.9K
# Total Submissions: 2.2M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
# 
# Example 1:
# 
# 
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: "cbbd"
# Output: "bb"
# 

# 感受：回文序列的性质
# 1. key在于如何判断回文序列？从中心字符开始。
# 比如abdbc就从d开始，查看d两边的字符是否相同。然后再看bdb两边的字符是否相同…
# 再比如abba就从两个b开始看，一对一对往外看。
# 出错的点：想清楚该看的一步的两个字符的下标。想清楚现在查看的字符子串的长度。

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ''
        maxlens = 1
        maxst = s[0]
        for i in range(len(s)):
            lens = 0
            while True:
                lens += 1
                if i - lens >= 0 and i + lens < len(s) and s[i - lens] == s[i + lens]:
                    if 2*lens + 1 > maxlens:
                        maxlens = 2*lens + 1
                        maxst = s[i - lens:i + lens + 1]
                else:
                    break
            lens = 0
            while True:
                lens += 1
                if i - lens + 1 >= 0 and i + lens < len(s) and s[i - lens + 1] == s[i + lens]:
                    if 2*lens > maxlens:
                        maxlens = 2*lens
                        maxst = s[i - lens + 1 : i + lens + 1]
                else:
                    break
        return maxst
            
c = Solution()
print(c.longestPalindrome('cbbd'))

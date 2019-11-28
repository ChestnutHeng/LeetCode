#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (28.68%)
# Total Accepted:    1M
# Total Submissions: 3.6M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# 
# Example 1:
# 
# 
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# 
# 
# 
# Example 2:
# 
# 
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# 
# 
# 
# Example 3:
# 
# 
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
# 
# abcabcbb
# 
# 感受：双指针
# 1. 遍历时记录一个下标和上标，表示这个区间内没有字符重复
# 2. 更新下标时机：在当前区间内字符发现重复 [lo, now)
# 3. 取历次遍历的最大区间

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        strdic = {}
        istart = 0
        imax = 0
        for i in range(len(s)):
            if s[i] in strdic and strdic[s[i]] >= istart:
                istart = strdic[s[i]] + 1
            imax = max(imax, i - istart + 1)
            strdic[s[i]] = i
        return imax


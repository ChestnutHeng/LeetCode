#!/usr/bin/env python3

def dfchars(t1, t2):
    assert len(t1) == len(t2)
    count = 0
    for idx in range(0, len(t1)):
        if t1[idx] != t2[idx]:
            count += 1
    return count

class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        
        mp =[]
        for i in range(0, len(wordlist)):
            sub = []
            for j in range(0, len(wordlist)):
                sub.append(dfchars(wordlist[i], wordlist[j]))
            mp.append(sub)
        
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

a = Solution()
a.find

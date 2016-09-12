
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

def cpp(s1, s2):
        dif = 0
        for i,j in zip(s1, s2):
            if i != j:
                dif += 1
        return not bool(dif - 1)
        
def findLadders(beginWord, endWord, wordlist):
    """
    :type beginWord: str
    :type endWord: str
    :type wordlist: Set[str]
    :rtype: List[List[int]]
    """
    depth = 1
    sh_dp = 999
    row_c = 0
    child = [beginWord]
    paths = [[]]
    flag = True
    while child and flag:
        word = child.pop(0)
        print(child)
        depth = depth - row_c + 1
        if cpp(word, endWord):
            print(depth)
            break
        row_c = 0
        for v in wordlist:
            if cpp(v, word) and v != word:
                child.append(v)
                print(v, word)
                row_c += 1
                
        
    print(paths)
    
    
    
findLadders(beginWord, endWord, wordList)

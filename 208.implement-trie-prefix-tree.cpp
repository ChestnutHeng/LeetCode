/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
    Trie *next[26];
    bool isLeaf;
    /** Initialize your data structure here. */
    Trie() {
        isLeaf = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *now = this;
        for(auto c : word){
            if(!now->next[c - 'a']){
                now->next[c - 'a'] = new Trie();
            }
            now = now->next[c - 'a'];
        }
        now->isLeaf = true;              
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *now = this;
        for(auto c : word){
            if(!now){
               return false;
            }
            now = now->next[c - 'a'];
        }
        return now && now->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *now = this;
        for(auto c : prefix){
            if(!now){
               return false;
            }
            now = now->next[c - 'a'];
        }
        return now != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
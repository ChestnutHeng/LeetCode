
// 哈希表

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for(auto v : s){
            mp1[v - 'a'] += 1;
        }
        for(auto v : t){
            mp2[v - 'a'] += 1;
        }
        for(int i = 0; i < 26; ++i){
            if(mp1[i] != mp2[i]){
                return false;
            }
        }
        return true;
    }
};
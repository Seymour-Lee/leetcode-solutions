class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> alpha(26, 0);
        for(auto c: s) alpha[c-'a']++;
        for(auto c: t){
            alpha[c-'a']--;
            if(alpha[c-'a'] < 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> s2t;
        for(auto c: s) s2t[c]++;
        for(auto c: t) if((--s2t[c]) == 0) s2t.erase(c);
        return s2t.empty();
    }
};
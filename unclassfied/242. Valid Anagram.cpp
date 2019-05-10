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
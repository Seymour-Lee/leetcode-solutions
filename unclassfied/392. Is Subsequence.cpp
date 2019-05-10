class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        if(t == "") return false;
        int i = 0;
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]) i++;
            if(i == s.size()) return true;
        }
        return false;
    }
};
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

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) if(s[i] == t[j++]) i++;
        return i == s.size();
    }
};
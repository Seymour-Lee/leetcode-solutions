class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> stt;
        map<char, char> tts;
        for(int i = 0; i < s.size(); i++){
            stt[s[i]] = t[i];
            tts[t[i]] = s[i];
        }
        for(int i = 0; i < s.size(); i++){
            if(stt[s[i]] != t[i] || tts[t[i]] != s[i]) return false;
            s[i] = stt[s[i]];
        }
        return s == t;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stt;
        unordered_map<char, char> tts;
        for(int i = 0; i < s.size(); i++){
            stt[s[i]] = t[i];
            tts[t[i]] = s[i];
        }
        for(int i = 0; i < s.size(); i++){
            if(stt[s[i]] != t[i] || tts[t[i]] != s[i]) return false;
            s[i] = stt[s[i]];
        }
        return s == t;
    }
};
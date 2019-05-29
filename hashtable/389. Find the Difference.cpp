class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(auto c: s) result = result ^ c;
        for(auto c: t) result = result ^ c;
        return result;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ch2t;
        for(auto c: s) ch2t[c]++;
        for(auto c: t){
            if(ch2t.find(c) == ch2t.end()) return c;
            if((--ch2t[c]) == 0) ch2t.erase(c);
        }
        return 'a';
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(auto c: s) ans ^= c;
        for(auto c: t) ans ^= c;
        return ans;
    }
};
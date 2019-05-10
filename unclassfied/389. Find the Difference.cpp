class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(auto c: s) result = result ^ c;
        for(auto c: t) result = result ^ c;
        return result;
    }
};
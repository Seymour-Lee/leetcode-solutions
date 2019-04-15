class Solution {
public:
    string removeVowels(string S) {
        string ans = "";
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(auto c: S) if(vowels.find(c) == vowels.end()) ans += c;
        return ans;
    }
};
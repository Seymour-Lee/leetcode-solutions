class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty() == true) return 0;
        if(s == string(s.rbegin(), s.rend())) return 1;
        return 2;
    }
};
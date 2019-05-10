class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        string result;
        string::iterator p;
        string::iterator q;
        for(p = s.begin(), q = s.begin()+1; q != s.end(); q++){
            if(*q == ' '){
                reverse(p, q);
                p = q + 1;
            }
        }
        reverse(p, q);
        return s;
    }
};
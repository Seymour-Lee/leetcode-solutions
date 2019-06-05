class Solution {
public:
    string reverseStr(string s, int k) {
        for(int l = 0; l < s.size(); l+=2*k){
            for(int i = l, j = min(l+k-1, (int)s.size()-1); i < j; i++, j--){
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += k*2) reverse(s.begin()+i, s.begin()+min(i+k, (int)s.size()));
        return s;
    }
};
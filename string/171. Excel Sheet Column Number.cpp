class Solution {
public:
    int titleToNumber(string s) {
        if(s == "") return 0;
        int result = 0;
        for(auto c: s){
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans = ans*26+(s[i]-'A'+1);
        }
        return ans;
    }
};
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
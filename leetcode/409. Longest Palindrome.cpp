class Solution {
public:
    int longestPalindrome(string s) {
        if(s == "") return 0;
        int result = 0;
        map<char, int> table;
        for(auto c: s) table[c]++;
        int odd = 0;
        for(auto item: table){
            if(item.second % 2){
                result += item.second - 1;
                odd = 1;
            }
            else result = result + item.second;
        }
        return result + odd;
    }
};
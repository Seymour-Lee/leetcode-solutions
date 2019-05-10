class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string pal = "";
        auto valid = [](string str){
            int i = 0, j = str.size()-1;
            while(i < j) if(str[i++] != str[j--]) return false;
            return true;
        };
        for(int len = s.size(); len >= 0; len--){
            string str = s.substr(0, len);
            if(valid(str)){
                pal = str;
                break;
            }
        }
        string torev = s.substr(pal.size());
        reverse(torev.begin(), torev.end());
        return torev+s;
    }
};
class Solution {
public:
    string replaceSpaces(string &str) {
        string ans;
        for(auto c: str){
            if(c == ' ') ans += "%20";
            else ans += c;
        }
        return ans;
    }
};
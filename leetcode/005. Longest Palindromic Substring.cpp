class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "" || s.size() == 1) return s;
        vector<vector<bool>> is;
        string result = s.substr(0, 1);
        for(int i = 0; i < s.size(); i++){
            vector<bool> cur = {true};
            is.push_back(cur);
            if(i > 0){
                if(s[i] == s[i-1]){
                    is[i-1].push_back(true);
                    result = s.substr(i-1, 2);
                }
                else{
                    is[i-1].push_back(false);
                }
            }
        }
        for(int j = 2; j < s.size(); j++){
            for(int i = 0; i < s.size() - j; i++){
                if(s[i] == s[i+j] && is[i+1][j-2]){
                    is[i].push_back(true);
                    result = s.substr(i, j+1);
                }
                else{
                    is[i].push_back(false);
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        return dp(s, dict);
    }
    
private:
    map<string, bool> str2in;
    
    bool dp(string s, set<string> dict){
        if(str2in.find(s) != str2in.end()) return str2in[s];
        if(dict.find(s) != dict.end()){
            str2in[s] = true;
            return true;
        }
        for(int i = 1; i < s.size(); i++){
            string left = s.substr(0, i);
            string right = s.substr(i);
            if(dp(left, dict) && dict.find(right) != dict.end()){
                str2in[s] = true;
                return true;
            }
        }
        str2in[s] = false;
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] == true && dict.find(s.substr(j, i-j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> strs(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int j = 1; j <= s.size(); j++){
            for(int i = 0; i < j; i++){
                if(dp[i] && strs.find(s.substr(i, j-i)) != strs.end()){
                    dp[j] = true;
                    break;
                }
            }
        } 
        return dp.back();
    }
};
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
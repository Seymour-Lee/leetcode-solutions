// TLE
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> dict(wordDict.begin(), wordDict.end());
        backtracking(s, dict, ans, "");
        return ans;
    }
    
private:
    void backtracking(string s, set<string> dict, vector<string> &ans, string cur){
        if(s == ""){
            ans.push_back(cur.substr(1));
            return;
        }
        for(int i = 1; i <= s.size(); i++){
            if(dict.find(s.substr(0, i)) != dict.end())
                backtracking(s.substr(i), dict, ans, cur+" "+s.substr(0, i));
        }
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> dict(wordDict.begin(), wordDict.end());
        if(m.count(s)) return m[s];
        if(dict.count(s)){ //a whole string is a word
            ans.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                ans.insert(ans.end(),prev.begin(), prev.end());
            }
        }
        m[s]=ans; //memorize
        return ans;
    }
    
private:
    map<string, vector<string>> m;
    vector<string> combine(string word, vector<string> prev){
        for(auto &p: prev) p += " "+word;
        return prev;
    }
};
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        return backtracking(pattern, 0, str, 0);
    }
    
private:
    unordered_map<char, string> ch2str;
    unordered_map<string, char> str2ch;
    
    bool backtracking(string &pattern, int i, string &str, int j) {
        int m = pattern.size();
        int n = str.size();
        if (i == m || j == n) {
            if (i == m && j == n) return true;
            return false;
        }
        bool ins = false;
        for(int k = j; k < n; k++){
            string s = str.substr(j, k - j + 1);
            if(ch2str.find(pattern[i]) != ch2str.end()){
                if (ch2str[pattern[i]] != s) continue;
            } 
            else if(str2ch.find(s) != str2ch.end()){
                if (str2ch[s] != pattern[i]) continue;
            } 
            else{
                ch2str[pattern[i]] = s;
                str2ch[s] = pattern[i];
                ins = true;
            }
            if(backtracking(pattern, i + 1, str, k + 1)) return true;
            if(ins){
                ch2str.erase(pattern[i]);
                str2ch.erase(s);
                ins = false;
            }
        }
        return false;
    }
};
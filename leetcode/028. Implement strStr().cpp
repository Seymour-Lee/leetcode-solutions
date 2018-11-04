class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int m = haystack.size();
        int n = needle.size();
        
        for(int i = 0; i < m-n+1; i++){
            string cur = haystack.substr(i, n);
            if(cur == needle) return i;
        }
        
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        return pos == string::npos? -1: pos;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int m = needle.size();
        int n = haystack.size();
        vector<int> lps = buildlps(needle);
        int i = 0, j = 0;
        while(i < n){
            if(needle[j] == haystack[i]) j++, i++;
            if(j == m) return i-j;
            else if(i < n && needle[j] != haystack[i]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
        return -1;
    }
    
private:
    vector<int> buildlps(string pattern){
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++, lps[i] = len, i++;
            }
            else{
                if(len != 0) len = lps[len-1];
                else lps[i] = 0, i++;
            }
        }
        return lps;
    }
};
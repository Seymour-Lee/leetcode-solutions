class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for(auto w: words) if(check(S, w)) ans++;
        return ans;
    }
    
private:
    bool check(string s, string w){
        int n = s.size(), m = w.size(), j = 0;
        for(int i = 0; i < n; i++){
            if(j < m && s[i] == w[j]) j++;
            else if(i > 1 && s[i-2] == s[i-1] && s[i-1] == s[i]);
            else if(0 < i && i < n-1 && s[i-1] == s[i] && s[i] == s[i+1]);
            else return false;
        }
        return j == m;
    }
};
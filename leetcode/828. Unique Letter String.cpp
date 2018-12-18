class Solution {
public:
    int uniqueLetterString(string S) {
        vector<vector<int>> index(26, vector<int>(2, -1));
        int ans = 0;
        int n = S.size();
        int mod = 1e9+7;
        for(int i = 0; i < n; i++){
            int c = S[i]-'A';
            ans = (ans + (i-index[c][1])*(index[c][1]-index[c][0])%mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for(int c = 0; c < 26; c++){
            ans = (ans + (n-index[c][1])*(index[c][1]-index[c][0])%mod) % mod;
        }
        return ans;
    }
};
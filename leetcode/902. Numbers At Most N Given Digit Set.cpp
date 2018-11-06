class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int k = s.size();
        vector<int> dp(k+1, 0);
        dp[k] = 1;
        for(int i = k-1; i >= 0; i--){
            int si = s[i] - '0';
            for(auto d: D){
                if(stoi(d) < si) dp[i] += pow(D.size(), k-i-1);
                else if(stoi(d) == si) dp[i] += dp[i+1];
            }
        }
        for(int i = 1; i < k; i++)
            dp[0] += pow(D.size(), i);
        return dp[0];
    }
};
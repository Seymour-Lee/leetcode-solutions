// Top 2 Bottom
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        memo = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));
        return dp(word1, word2, l1, l2);
    }
    
private:
    vector<vector<int>> memo;
    
    int dp(string s1, string s2, int l1, int l2){
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(memo[l1][l2] >= 0) return memo[l1][l2];
        int ans = max(l1, l2);
        if(s1[l1-1] == s2[l2-1]){
            ans = dp(s1, s2, l1-1, l2-1);
        }
        else{
            ans = min(dp(s1, s2, l1-1, l2),
                  min(dp(s1, s2, l1, l2-1),
                      dp(s1, s2, l1-1, l2-1)))+1;
        }
        memo[l1][l2] = ans;
        return memo[l1][l2];
    }
};

// Bottom 2 Top
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        for(int i = 0; i <= l2; i++) dp[0][i] = i;
        for(int i = 0; i <= l1; i++) dp[i][0] = i;
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], 
                                   min(dp[i-1][j], dp[i][j-1]))+1;
                }
            }
        }
        return dp.back().back();
    }
};
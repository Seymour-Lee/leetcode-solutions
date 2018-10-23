class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        for(int i = 0; i < piles.size(); i++) dp[i][i] = -piles[i];
        for(int len = 2; len <= piles.size(); len++){
            for(int i = 0; i+len-1 < piles.size(); i++){
                int j = i+len-1;
                if((j-i+1) % 2 == 1){
                    dp[i][j] = min(-piles[i]+dp[i+1][j], dp[i][j-1]-piles[j]);
                }
                else{
                    dp[i][j] = max(piles[i]+dp[i+1][j], dp[i][j-1]+piles[j]);
                }
            }
        }
        return dp.front().back() > 0;
    }
};
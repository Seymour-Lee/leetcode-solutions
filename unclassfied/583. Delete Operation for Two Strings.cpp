class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(decltype(dp.size()) i = 1; i != dp.size(); i++){
            for(decltype(dp[i].size()) j = 1; j != dp[i].size(); j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(decltype(dp.size()) i = 1; i != dp.size(); i++){
            for(decltype(dp[i].size()) j = 1; j != dp[i].size(); j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};
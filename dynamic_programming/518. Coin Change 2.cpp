class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> result(amount+1, 0);
        result[0] = 1;
        for(auto coin: coins){
            for(int i = 1; i < result.size(); i++){
                if(i >= coin){
                    result[i] = result[i] + result[i-coin];
                }
            }
        }
        return result.back();
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto c: coins) for(int i = 1; i <= amount; i++){
            if(i >= c) dp[i] += dp[i-c];
        }
        return dp[amount];
    }
};
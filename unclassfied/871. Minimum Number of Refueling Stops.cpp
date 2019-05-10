class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        vector<long> dp(501, startFuel);
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j >= 0 && dp[j] >= s[i][0]; j--){
                dp[j+1] = max(dp[j+1], dp[j]+s[i][1]);
            }
        }
        for(int i = 0; i <= s.size(); i++) if(dp[i] >= target) return i;
        return -1;
    }
};
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        set<pair<int, int>> zeros;
        for(auto m:mines) zeros.insert({m[0], m[1]});
        for(int r = 0; r < N; r++){
            int count = 0;
            for(int c = 0; c < N; c++){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = count;
            }
            count = 0;
            for(int c = N-1; c >= 0; c--){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
            }
        }
        for(int c = 0; c < N; c++){
            int count = 0;
            for(int r = 0; r < N; r++){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
            }
            count = 0;
            for(int r = N-1; r >= 0; r--){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
                ans = max(ans, dp[r][c]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        set<pair<int, int>> zeros;
        for(auto m:mines) zeros.insert({m[0], m[1]});
        for(int r = 0; r < N; r++){
            int count = 0;
            for(int c = 0; c < N; c++){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = count;
            }
            count = 0;
            for(int c = N-1; c >= 0; c--){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
            }
        }
        for(int c = 0; c < N; c++){
            int count = 0;
            for(int r = 0; r < N; r++){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
            }
            count = 0;
            for(int r = N-1; r >= 0; r--){
                count = zeros.find({r, c}) == zeros.end()? count+1: 0;
                dp[r][c] = min(dp[r][c], count);
                ans = max(ans, dp[r][c]);
            }
        }
        return ans;
    }
};
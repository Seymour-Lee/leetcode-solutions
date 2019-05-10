class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        vector<int> dr = {2,  2, 1,  1, -1, -1, -2, -2};
        vector<int> dc = {1, -1, 2, -2,  2, -2,  1, -1};
        dp[r][c] = 1;
        while(K--){
            vector<vector<double>> dp2 = vector<vector<double>>(N, vector<double>(N, 0));
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    for(int k = 0; k < 8; k++){
                        int cr = r + dr[k];
                        int cc = c + dc[k];
                        if(0 <= cr && cr < N && 0 <= cc && cc < N){
                            dp2[cr][cc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for(auto r: dp) for(auto e: r) ans += e;
        return ans;
    }
};
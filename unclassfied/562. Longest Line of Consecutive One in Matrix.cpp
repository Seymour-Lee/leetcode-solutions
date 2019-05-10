class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size() == 0 || M[0].size() == 0) return 0;
        int ans = 0;
        int m = M.size(), n = M[0].size();
        struct elements{
            int hori;
            int vert;
            int diag;
            int anti;
            elements(): hori(0), vert(0), diag(0), anti(0){}
        };
        vector<vector<elements>> dp(m, vector<elements>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    dp[i][j].hori = j-1 >= 0? dp[i][j-1].hori+1: 1;
                    dp[i][j].vert = i-1 >= 0? dp[i-1][j].vert+1: 1;
                    dp[i][j].diag = i-1 >= 0 && j-1 >= 0? dp[i-1][j-1].diag+1: 1;
                    dp[i][j].anti = i-1 >= 0 && j+1 < n? dp[i-1][j+1].anti+1: 1;
                    ans = max(dp[i][j].hori, max(dp[i][j].vert, 
                            max(dp[i][j].diag, max(dp[i][j].anti, ans))));
                }
            }
        }
        return ans;
    }
};
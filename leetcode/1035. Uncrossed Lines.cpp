class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        dp[0][0] = A[0] == B[0];
        // cout<<dp[0][0]<<endl;
        for(int i = 1; i < A.size(); i++){
            dp[i][0] = A[i] == B[0]? 1: dp[i-1][0];
        }
        for(int j = 1; j < B.size(); j++){
            dp[0][j] = A[0] == B[j]? 1: dp[0][j-1];
        }
        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < B.size(); j++){
                // cout<<i<<" "<<j<<endl;
                if(A[i] == B[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};
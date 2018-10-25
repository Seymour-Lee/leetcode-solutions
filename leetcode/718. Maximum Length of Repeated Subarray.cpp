class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if(m * n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for(int i = 0; i < n; i++) if(A.back() == B[i]) dp[m-1][i] = 1;
        for(int i = 0; i < m; i++) if(B.back() == A[i]) dp[i][n-1] = 1;
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                if(A[i] == B[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        for(int j = 0; j < B.size(); j++) if(A[0] == B[j]) dp[0][j] = 1, ans = 1;
        for(int i = 0; i < A.size(); i++) if(A[i] == B[0]) dp[i][0] = 1, ans = 1;
        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < B.size(); j++){
                if(A[i] == B[j]) dp[i][j] = dp[i-1][j-1]+1, ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> dp = A[0];
        vector<int> next(A[0].size(), 0);
        for(int i = 1; i < A.size(); i++){
            for(int j = 0; j < dp.size(); j++){
                if(j == 0){
                    next[j] = min(dp[j], dp[j+1]) + A[i][j];
                }
                else if(j == dp.size()-1){
                    next[j] = min(dp[j], dp[j-1]) + A[i][j];
                }
                else{
                    next[j] = min(min(dp[j-1], dp[j]), dp[j+1]) + A[i][j];
                }
            }
            dp = next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> dp = A[0];
        vector<int> next(A[0].size(), 0);
        for(int i = 1; i < A.size(); i++){
            for(int j = 0; j < dp.size(); j++){
                if(j == 0){
                    next[j] = min(dp[j], dp[j+1]) + A[i][j];
                }
                else if(j == dp.size()-1){
                    next[j] = min(dp[j], dp[j-1]) + A[i][j];
                }
                else{
                    next[j] = min(min(dp[j-1], dp[j]), dp[j+1]) + A[i][j];
                }
            }
            dp = next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
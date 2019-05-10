class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(A[0].size(), 1);
        for(int j = 0; j < A[0].size(); j++){
            for(int i = 0; i < j; i++){
                int k = 0;
                while(k < A.size() && A[k][i] <= A[k][j]) k++;
                if(k == A.size() && dp[i]+1 > dp[j]) dp[j] = dp[i]+1;
            }
        }
        return A[0].size()-*max_element(dp.begin(), dp.end());
    }
};
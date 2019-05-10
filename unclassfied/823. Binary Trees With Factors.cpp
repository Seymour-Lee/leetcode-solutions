class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        if(A.size() == 0) return 0;
        int MOD = 1000000007;
        sort(A.begin(), A.end());
        vector<long> dp(A.size(), 1);
        map<int, int> num2idx;
        for(int i = 0; i < A.size(); i++) num2idx[A[i]] = i;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < i; j++){
                if(A[i] % A[j] == 0){
                    int right = A[i] / A[j];
                    if(num2idx.find(right) != num2idx.end()){
                        dp[i] = (dp[i] + dp[j] * dp[num2idx[right]]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for(long r: dp) ans += r;
        return (int)(ans % MOD);
    }
};
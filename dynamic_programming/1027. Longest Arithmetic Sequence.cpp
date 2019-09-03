class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        return dp(A);
    }
    
private:
    int dp(vector<int> A){
        if(A.size() == 0) return 0;
        int ans = 1;
        map<int, map<int, int>> index_to_llac;
        for(int current = 1; current < A.size(); current++) {
            index_to_llac[current] = {};
            for(int prev = 0; prev < current; prev++) {
                int diff = A[current] - A[prev];
                int length = 2;
                if(index_to_llac.count(prev) && index_to_llac[prev].count(diff)) {
                    length = index_to_llac[prev][diff] + 1;
                }
                index_to_llac[current][diff] = length;
                ans = max(length, ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int ans = 1;
        for(int j = 0; j < A.size(); j++) for(int i = 0; i < j; i++){
            int diff = A[j] - A[i];
            if(dp[i].find(diff) != dp[i].end()) dp[j][diff] = max(dp[j][diff], dp[i][diff]+1);
            else dp[j][diff] = 2;
            ans = max(ans, dp[j][diff]);
        }
        return ans;
    }
};

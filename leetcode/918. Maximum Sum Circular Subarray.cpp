class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0) return 0;
        int n = A.size();
        
        int ans = A[0], cur = A[0];
        for(int i = 1; i < n; i++){
            cur = A[i] + max(cur, 0);
            ans = max(ans, cur);
        }
        
        vector<int> rsums(n, 0);
        rsums.back() = A.back();
        for(int i = n-2; i >= 0; i--) rsums[i] = rsums[i+1] + A[i];
        
        vector<int> rmaxs(n, INT_MIN);
        rmaxs.back() = rsums.back();
        for(int i = n-2; i >= 0; i--) rmaxs[i] = max(rmaxs[i+1], rsums[i]);
        
        int lsum = 0;
        for(int i = 0; i < n-2; i++){
            lsum += A[i];
            ans = max(ans, lsum+rmaxs[i+2]);
        }
        
        return ans;
    }
};
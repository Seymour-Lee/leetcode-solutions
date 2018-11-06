class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int mod = 1000000000+7;
        sort(A.begin(), A.end());
        long long ans = 0;
        int n = A.size();
        long long c = 1;
        for(int i = 0; i < n; i++, c = (c << 1) % mod){
            ans = (ans + (A[i]*c - A[n-i-1]*c) % mod) % mod;
        }
        return (ans + mod) % mod;
    }
};

// TLE
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int mod = 1000000000+7;
        sort(A.begin(), A.end());
        unsigned long long ans = 0;
        int n = A.size();
        vector<unsigned long long> powers(n, 1);
        for(int i = 1; i < n; i++) powers[i] = (powers[i-1] << 1) % mod;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans = (ans + ((A[j]-A[i])*powers[j-i-1]) % mod) % mod;
            }
        }
        return (int)ans;
    }
};
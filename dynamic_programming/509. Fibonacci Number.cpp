class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        int pprev = 0;
        int prev = 1;
        int i = 1;
        while(i < N){
            int ppprev = pprev;
            pprev = prev;
            prev = prev + ppprev;
            i++;
        }
        return prev;
    }
};

class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        vector<int> dp(N+1, 0);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= N; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[N];
    }
};
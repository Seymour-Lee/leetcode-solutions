class Solution {
public:
    int racecar(int target) {
        memo = vector<int>(10001, 0);
        return dp(target);
    }
    
private:
    vector<int> memo;
    
    int dp(int t){
        if(memo[t] > 0) return memo[t];
        int n = floor(log2(t))+1;
        int ans = 0;
        if(1 << n == t+1) memo[t] = n;
        else{
            memo[t] = dp((1 << n)-1-t)+n+1;
            for(int m = 0; m < n-1; m++) memo[t] = min(memo[t], dp(t-(1<<(n-1))+(1<<m))+n+m+1);
        }
        return memo[t];
    }
};


class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0 || (k == 1 && n > 2)) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        vector<int> dp(n, 0);
        dp[0] = k, dp[1] = k*k, dp[2] = k*(k*k-1);
        for(int i = 3; i < n; i++)
            dp[i] = k * (dp[i-1] - dp[i-3]*(k-1)/k);
        return dp.back();
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0 || (k == 1 && n > 2)) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        vector<int> same(n, 0);
        vector<int> diff(n, 0);
        same[0] = k, same[1] = k;
        diff[0] = k, diff[1] = k*(k-1);
        for(int i = 2; i < n; i++){
            same[i] = diff[i-1];
            diff[i] = (k-1) * (diff[i-1]+same[i-1]);
        }
        return same.back() + diff.back();
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0 || (k == 1 && n > 2)) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        vector<int> d(n, 0), s(n, 0);
        d[0] = k, d[1] = (k-1)*k;
        s[0] = k, s[1] = k;
        for(int i = 2; i < n; i++){
            s[i] = d[i-1];
            d[i] = (k-1)*(d[i-1]+s[i-1]);
        }
        return d.back() + s.back();
    }
};
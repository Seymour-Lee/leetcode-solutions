class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result = {0};
        int mask = 1;
        for(int i = 1; i <= num; i++){
            if(mask * 2 == i) mask = mask * 2;
            result.push_back(result[i % mask] + 1);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        if(num == 1) return {0, 1};
        int base = 2;
        vector<int> dp(num+1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for(int i = 3; i <= num; i++){
            if(i == base + base){dp[i] = 1, base += base; continue;}
            dp[i] = 1 + dp[i-base];
        }
        return dp;
    }
};
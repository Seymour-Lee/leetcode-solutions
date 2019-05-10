class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways = {1, 2};
        for(int i = 2; i < n; i++){
            ways.push_back(ways[i-1] + ways[i-2]);
        }
        return ways[n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int ans = 1;
        int prev2 = 1, prev1 = 1;
        for(int i = 2; i <= n; i++){
            ans = prev1 + prev2;
            prev2 = prev1, prev1 = ans;
        }
        return ans;
    }
};
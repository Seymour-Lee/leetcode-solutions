class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        return dp(0, x, target)-1;
    }
    
private:
    unordered_map<string, int> memo;
    
    int dp(int i, int x, int y){
        string key = to_string(i) + "#" + to_string(y);
        if(memo.find(key) != memo.end()) return memo[key];
        if(y == 0) return memo[key] = 0;
        if(y == 1) return memo[key] = i > 0? i: 2;
        if(i >= 39) return memo[key] = y+1;
        int res = y / x;
        int rem = y % x;
        return memo[key] = min(rem*(i>0? i: 2) + dp(i+1, x, res), (x-rem)*(i>0? i: 2) + dp(i+1, x, res+1));
    }
};
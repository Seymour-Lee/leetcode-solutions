class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        memo = vector<vector<int>>(n, vector<int>(10001, INT_MIN));
        return dp(rods, 0, 5000);
    }
    
private:
    vector<vector<int>> memo;
    
    int dp(vector<int> rods, int i, int s){
        if(i == rods.size()) return s == 5000? 0: INT_MIN/3;
        if(memo[i][s] != INT_MIN) return memo[i][s];
        int ans = dp(rods, i+1, s);
        ans = max(ans, dp(rods, i+1, s-rods[i]));
        ans = max(ans, rods[i] + dp(rods, i+1, s+rods[i]));
        memo[i][s] = ans;
        return ans;
    }
};
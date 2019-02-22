class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, 0));
        return dp(s, 0, n-1);
    }
    
private:
    vector<vector<int>> memo;
    
    int dp(string str, int i, int j){
        if(i > j) return 0;
        if(memo[i][j] != 0) return memo[i][j];
        int ans = dp(str, i+1, j)+1;
        for(int k = i+1; k <= j; k++) if(str[k] == str[i]) ans = min(ans, dp(str, i, k-1)+dp(str, k+1, j));
        return memo[i][j] = ans;
    }
};


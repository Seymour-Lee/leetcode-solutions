class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return search(m, n, N, i, j, memo);
    }
    
private:
    int search(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &memo){
        const int mod = 1000000007;
        if(i < 0 || j < 0 || i == m || j == n)
            return 1;
        if(N == 0) return 0;
        if(memo[i][j][N] >= 0) return memo[i][j][N];
        memo[i][j][N] = ((search(m, n, N-1, i-1, j, memo) + search(m, n, N-1, i+1, j, memo)) % mod
                + (search(m, n, N-1, i, j-1, memo) + search(m, n, N-1, i, j+1, memo)) %mod) % mod;
        return memo[i][j][N];
    }
};
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        return dp(boxes, 0, n-1, 0);
    }
private:
    int memo[100][100][100];
    
    int dp(vector<int>& b, int i, int j, int k){
        if(i > j) return 0;
        if(memo[i][j][k] != 0) return memo[i][j][k];
        while(i < j && b[j] == b[j-1]) j--, k++;
        memo[i][j][k] = dp(b, i, j-1, 0) + (k+1)*(k+1);
        for(int p = i; p < j; p++) if(b[p] == b[j]){
            memo[i][j][k] = max(memo[i][j][k], 
                                dp(b, i, p, k+1) + dp(b, p+1, j-1, 0));
        }
        return memo[i][j][k];
    }
};
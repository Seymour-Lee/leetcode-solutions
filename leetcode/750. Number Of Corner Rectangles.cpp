class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        map<int, int> count;
        int ans = 0;
        for(auto row: grid){
            for(int c1 = 0; c1 < row.size(); c1++) if(row[c1] == 1){
                    for(int c2 = c1+1; c2 < row.size(); c2++) if(row[c2] == 1){
                        int pos = c1*200+c2; // pos signature
                        int c = count[pos];
                        ans += c;
                        count[pos] = c+1;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 1) continue;
                for(int k = j+1; k < n; k++){
                    if(grid[i][k] == 1){
                        ans += dp[j][k];
                        dp[j][k]++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n*200+n, 0);
        for(auto row: grid){
            for(int c1 = 0; c1 < n; c1++){
                if(row[c1] != 1) continue;
                for(int c2 = c1+1; c2 < n; c2++){
                    if(row[c2] == 1){
                        ans += dp[c1*200+c2];
                        dp[c1*200+c2]++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> sig2cnt;
        for(auto row: grid){
            for(int c1 = 0; c1 < n; c1++){
                if(row[c1] != 1) continue;
                for(int c2 = c1+1; c2 < n; c2++){
                    if(row[c2] == 1){
                        ans += sig2cnt[c1*200+c2];
                        sig2cnt[c1*200+c2]++;
                    }
                }
            }
        }
        return ans;
    }
};
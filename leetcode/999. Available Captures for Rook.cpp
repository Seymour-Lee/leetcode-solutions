class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {
        if(b.size() == 0 || b[0].size() == 0) return 0;
        int row, col;
        for(int i = 0; i < b.size(); i++) for(int j = 0; j < b[i].size(); j++){
            if(b[i][j] == 'R') row = i, col = j;
        }
        int ans = 0;
        for(int r = row-1; r >= 0 && b[r][col] != 'B'; r--){
            if(b[r][col] == 'p'){
                ans++;
                break;
            }
        }
        for(int r = row+1; r < b.size() && b[r][col] != 'B'; r++){
            if(b[r][col] == 'p'){
                ans++;
                break;
            }
        }
        for(int c = col-1; c >= 0 && b[row][c] != 'B'; c--){
            if(b[row][c] == 'p'){
                ans++;
                break;
            }
        }
        for(int c = col+1; c < b[0].size() && b[row][c] != 'B'; c++){
            if(b[row][c] == 'p'){
                ans++;
                break;
            }
        }
        return ans;
    }
};
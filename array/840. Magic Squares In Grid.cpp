class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        int R = grid.size()-2;
        int C = grid[0].size()-2;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (grid[i+1][j+1] != 5) continue;  // optional skip
                if (magic(vector<int>{grid[i][j], grid[i][j+1], grid[i][j+2],
                          grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                          grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]}))
                    result++;
            }
        return result;
    }
    
private:
    bool magic(vector<int> vals) {
        vector<int> count(16, 0);
        for (auto v: vals) count[v]++;
        for (int v = 1; v <= 9; ++v)
            if (count[v] != 1)
                return false;

        return (vals[0] + vals[1] + vals[2] == 15 &&
                vals[3] + vals[4] + vals[5] == 15 &&
                vals[6] + vals[7] + vals[8] == 15 &&
                vals[0] + vals[3] + vals[6] == 15 &&
                vals[1] + vals[4] + vals[7] == 15 &&
                vals[2] + vals[5] + vals[8] == 15 &&
                vals[0] + vals[4] + vals[8] == 15 &&
                vals[2] + vals[4] + vals[6] == 15);
    }
};

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        int R = grid.size()-2;
        int C = grid[0].size()-2;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (grid[i+1][j+1] != 5) continue;  // optional skip
                if (magic(vector<int>{grid[i][j], grid[i][j+1], grid[i][j+2],
                          grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                          grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]}))
                    result++;
            }
        return result;
    }
    
private:
    bool magic(vector<int> vals) {
        vector<int> count(16, 0);
        for (auto v: vals) count[v]++;
        for (int v = 1; v <= 9; ++v)
            if (count[v] != 1)
                return false;

        return (vals[0] + vals[1] + vals[2] == 15 &&
                vals[3] + vals[4] + vals[5] == 15 &&
                vals[6] + vals[7] + vals[8] == 15 &&
                vals[0] + vals[3] + vals[6] == 15 &&
                vals[1] + vals[4] + vals[7] == 15 &&
                vals[2] + vals[5] + vals[8] == 15 &&
                vals[0] + vals[4] + vals[8] == 15 &&
                vals[2] + vals[4] + vals[6] == 15);
    }
};
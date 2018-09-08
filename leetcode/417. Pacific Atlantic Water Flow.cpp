class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if(matrix.size() == 0) return ans;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool toa = false, top = false;
                dfs(ans, matrix, i, j, m, n, toa, top);
                if(toa && top) ans.push_back({i, j});
            }
        }
        return ans;
    }
    
private:
    void dfs(vector<pair<int, int>>& res, vector<vector<int>>& matrix, int r, int c, int m, int n, bool& reachP, bool& reachA){
        if(matrix[r][c] == -1 || reachP && reachA) return;
        int tmp = matrix[r][c];
        matrix[r][c] = -1;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int i = 0; i < 4; i++){
            int R = r + dir[i].first, C = c + dir[i].second;
            if(R < 0 || C < 0) reachP = true;
            else if(R == m || C == n) reachA = true;
            else if(matrix[R][C] <= tmp) dfs(res, matrix, R, C, m, n, reachP, reachA);
        }
        matrix[r][c] = tmp;
    }
};
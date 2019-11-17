class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        k = k % (m*n);
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < n; j++){
            int d = j+k;
            int ii = (i+d/n)%m; // (i+((j+k)/m)+m)%m;
            int jj = d%n;// (j+(k%n)+n)%n;
            ans[ii][jj] = g[i][j];
        }
        return ans;
    }
};
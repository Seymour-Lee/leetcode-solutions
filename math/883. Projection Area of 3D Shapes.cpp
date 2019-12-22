class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0; 
        int result = 0;
        for(auto row: grid){
            int tallest = 0;
            for(auto elem: row){
                if(elem > 0) result++;
                tallest = max(tallest, elem);
            }
            result += tallest;
        }
        for(int i = 0; i < grid[0].size(); i++){
            int tallest = 0;
            for(int j = 0; j < grid.size(); j++){
                tallest = max(tallest, grid[j][i]);
            }
            result += tallest;
        }
        return result;
    }
};

class Solution {
public:
    int projectionArea(vector<vector<int>>& g) {
        int ans = 0;
        vector<int> r(g.size(), 0), c(g[0].size(), 0);
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < g[i].size(); j++){
            ans += (g[i][j] > 0);
            r[i] = max(r[i], g[i][j]);
            c[j] = max(c[j], g[i][j]);
        }
        for(auto e: r) ans += e;
        for(auto e: c) ans += e;
        return ans;
    }
};

class Solution {
public:
    int projectionArea(vector<vector<int>>& g) {
        int ans = 0;
        vector<int> r(g.size(), 0), c(g[0].size(), 0);
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < g[i].size(); j++){
            ans += (g[i][j] > 0);
            r[i] = max(r[i], g[i][j]);
            c[j] = max(c[j], g[i][j]);
        }
        for(auto e: r) ans += e;
        for(auto e: c) ans += e;
        return ans;
    }
};
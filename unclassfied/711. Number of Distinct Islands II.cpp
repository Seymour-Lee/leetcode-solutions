class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int num = 2;
        set<vector<pair<int, int>>> ans;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, num);
                    ans.insert(norm(num2points[num]));
                    num++;
                }
            }
        }
        return ans.size();
    }
    
private:
    map<int, vector<pair<int, int>>> num2points;
    
    vector<pair<int, int>> norm(vector<pair<int, int>> points){
        vector<vector<pair<int, int>>> ans(8);
        for(auto p: points){
            int x = p.first;
            int y = p.second;
            ans[0].push_back({x, y});
            ans[1].push_back({-x, y});
            ans[2].push_back({x, -y});
            ans[3].push_back({-x, -y});
            ans[4].push_back({y, x});
            ans[5].push_back({-y, x});
            ans[6].push_back({y, -x});
            ans[7].push_back({-y, -x});
        }
        for(auto &l: ans) sort(l.begin(), l.end());
        for(auto &l: ans){
            for(int i = l.size()-1; i >= 0; i--){
                l[i] = {l[i].first-l[0].first, l[i].second-l[0].second};
            }
        }
        sort(ans.begin(), ans.end());
        return ans.front();
    }
    
    void dfs(int r, int c, vector<vector<int>> &g, int num){
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size()) return;
        if(g[r][c] != 1) return ;
        g[r][c] = num;
        num2points[num].push_back({r, c});
        dfs(r+1, c, g, num);
        dfs(r-1, c, g, num);
        dfs(r, c+1, g, num);
        dfs(r, c-1, g, num);
    }
};
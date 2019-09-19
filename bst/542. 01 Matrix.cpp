class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(q.empty() == false){
            pair<int, int> curr = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int new_r = curr.first + dir[i][0];
                int new_c = curr.second + dir[i][1];
                if(new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols){
                    if(dist[new_r][new_c] > dist[curr.first][curr.second]+1){
                        dist[new_r][new_c] = dist[curr.first][curr.second]+1;
                        q.push({new_r, new_c});
                    }
                }
            }
        }
        return dist;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        vector<vector<int>> ans(m.size(), vector<int>(m[0].size(), INT_MAX));
        for(int i = 0; i < m.size(); i++) for(int j = 0; j < m[i].size(); j++){
            if(m[i][j] == 0) ans[i][j] = 0;
            else ans[i][j] = bfs(m, i, j);
        }
        return ans;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int bfs(vector<vector<int>>& g, int r, int c){
        unordered_set<int> v = {r*10000+c};
        queue<vector<int>> q;
        q.push({r, c});
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto pos = q.front(); q.pop();
                if(g[pos[0]][pos[1]] == 0) return ans;
                for(auto dir: dirs){
                    int i = pos[0]+dir[0];
                    int j = pos[1]+dir[1];
                    if(0 <= i && i < g.size() && 0 <= j && j < g[0].size() && v.find(i*10000+j) == v.end()){
                        q.push({i, j});
                        v.insert(i*10000+j);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
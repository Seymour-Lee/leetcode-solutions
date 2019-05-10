class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int DRAW = 0, MOUSE = 1, CAT = 2;
        vector<vector<vector<int>>> color(50, vector<vector<int>>(50, vector<int>(3, 0)));
        vector<vector<vector<int>>> degree(50, vector<vector<int>>(50, vector<int>(3, 0)));
        
        for(int m = 0; m < n; m++){
            for(int c = 0; c < n; c++){
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for(auto x: graph[c]){
                    if(x == 0){
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
        }
        
        queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            for(int t = 1; t <= 2; t++){
                color[0][i][t] = MOUSE;
                q.push(vector<int>{0, i, t, MOUSE});
                if(i > 0){
                    color[i][i][t] = CAT;
                    q.push(vector<int>{i, i, t, CAT});
                }
            }
        }
        
        while(q.empty() == false){
            auto node = q.front(); q.pop();
            int i = node[0], j = node[1], t = node[2], c = node[3];
            for(auto parent: parents(graph, i, j, t)){
                int i2 = parent[0], j2 = parent[1], t2 = parent[2];
                if(color[i2][j2][t2] == DRAW){
                    if(t2 == c){
                        color[i2][j2][t2] = c;
                        q.push(vector<int>{i2, j2, t2, c});
                    }
                    else{
                        degree[i2][j2][t2]--;
                        if(degree[i2][j2][t2] == 0){
                            color[i2][j2][t2] = 3-t2;
                            q.push(vector<int>{i2, j2, t2, 3-t2});
                        }
                    }
                }
            }
        }
        
        return color[1][2][1];
    }
    
private:
    vector<vector<int>> parents(vector<vector<int>> graph, int m, int c, int t){
        vector<vector<int>> ans;
        if(t == 2){
            for(auto m2: graph[m]) ans.push_back({m2, c, 3-t});
        }
        else{
            for(auto c2: graph[c]) if(c2 > 0) ans.push_back({m, c2, 3-t});
        }
        return ans;
    }
};
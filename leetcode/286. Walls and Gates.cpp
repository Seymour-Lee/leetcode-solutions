class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0) bfs(rooms, i, j);
            }
        }
    }
    
private:
    void bfs(vector<vector<int>> &rooms, int r, int c){
        queue<vector<int>> q;
        q.push({r, c});
        set<vector<int>> seen;
        seen.insert({r, c});
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dist = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto pos = q.front(); q.pop();
                rooms[pos[0]][pos[1]] = min(dist, rooms[pos[0]][pos[1]]);
                for(auto dir: dirs){
                    int nx = pos[0] + dir[0];
                    int ny = pos[1] + dir[1];
                    if(0 <= nx && nx < rooms.size() && 0 <= ny && ny < rooms[0].size() && 
                       seen.find({nx, ny}) == seen.end() && (rooms[nx][ny] > 0)){
                        q.push({nx, ny});
                        seen.insert({nx, ny});
                    }
                }
            }
            dist++;
        }
    }
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, 
                         vector<int>& destination) {
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
        queue<vector<int>> q;
        q.push(start);
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), 0));
        visited[start[0]][start[1]] = true;
        while(q.empty() == false){
            auto pos = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int r_next = pos[0] + dx[i], c_next = pos[1] + dy[i], dis = 0, 
                r = pos[0], c = pos[1];
                while(r_next >= 0 && r_next < maze.size() && 
                      c_next >= 0 && c_next < maze[0].size() && 
                      maze[r_next][c_next] == 0) {
                    r = r_next;
                    c = c_next;
                    r_next += dx[i];
                    c_next += dy[i];
                    dis++;
                }
                if(!visited[r][c] || dist[pos[0]][pos[1]] + dis < dist[r][c]) {
                    visited[r][c] = true;
                    q.push({r, c});
                    dist[r][c] = dist[pos[0]][pos[1]] + dis;
                }
            }
        }
        return dist[destination[0]][destination[1]] == 0? -1: 
                                        dist[destination[0]][destination[1]];
    }
};
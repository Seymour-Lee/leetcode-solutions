class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if (maze.empty()) return "";
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // the shortest distance from ball to (i, j)
        queue<pair<int, pair<int, string>>> q; // { i*n+j, { distance, path } }
        int go[4][3] = {{1,0,'d'}, {-1,0,'u'}, {0,1,'r'}, {0,-1,'l'}};

        dist[ball[0]][ball[1]] = 0;
        q.push({ball[0]*n+ball[1], {0, ""}});
        maze[hole[0]][hole[1]] = 2;

        string res;
        while (!q.empty()) {
            int i = q.front().first/n, j = q.front().first%n;
            int t = q.front().second.first;
            string path = q.front().second.second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i, nj = j, s = 0;
                while (ni+go[d][0] >= 0 && 
                       ni+go[d][0] < m && 
                       nj+go[d][1] >= 0 && 
                       nj+go[d][1] < n && 
                       maze[ni+go[d][0]][nj+go[d][1]] != 1) {
                    ni += go[d][0]; nj += go[d][1]; ++s;
                    if (maze[ni][nj] == 2) break;
                }
                if (maze[ni][nj] == 2) { // if reach hole, update dist and res if necessary
                    if ((t+s < dist[ni][nj]) || (t+s == dist[ni][nj] && (res.empty() || path+(char)go[d][2] < res))) {
                        dist[ni][nj] = t+s;
                        res = path+(char)go[d][2];
                    }
                    continue;
                }
                if ((s == 0) || t+s > dist[ni][nj]) continue; // note! here must be > rather than >=, because we need a lexicographically smaller path
                dist[ni][nj] = t+s;
                q.push({ni*n+nj, {t+s, path+(char)go[d][2]}});
            }
        }
        return res.empty() ? "impossible" : res;
    }
};
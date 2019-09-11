class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx, sy;
        int keys = 0;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(grid[i][j] == '@') sx = i, sy = j;
            if('a' <= grid[i][j] && grid[i][j] <= 'f') keys++;
        }
        struct state{
            int x;
            int y;
            int k;
            state(int _x, int _y, int _k): x(_x), y(_y), k(_k){}
        };
        queue<state> q;
        q.push(state(sx, sy, 0));
        q // format: x,y,k
        int ans = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto front = q.front(); q.pop();
                if(front.k == ((1<<keys)-1)) return ans;
                for(auto dir: dirs){
                    int i = front.x+dir[0];
                    int j = front.y+dir[1];
                    int k = front.k;
                    if(0 <= i && i < m && 0 <= j && j < n){
                        int c = grid[i][j];
                        if(c == '#') continue;
                        if('a' <= c && c <= 'f'){
                            int key = c-'a';
                            k = k | (1 << key);
                        }
                        if('A' <= c && c <= 'F'){
                            int lock = c-'A';
                            if((k & (1<<lock)) == 0) continue;
                        }
                        string next = to_string(i)+","+to_string(j)+","+to_string(k);
                        if(seen.find(next) != seen.end()) continue;
                        q.push(state(i, j, k));
                        seen.insert(next);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& g) {
        int ans = 0;
        int counter = 0;
        int si, sj;
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] == '@') si = i, sj = j;
            if('a' <= g[i][j] && g[i][j] <= 'f') counter++;
        }
        int target = (1 << counter)-1;
        struct state{
            int x;
            int y;
            int k;
            state(int _x, int _y, int _k): x(_x), y(_y), k(_k) {};
        };
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<state> q;
        q.push(state(si, sj, 0));
        unordered_set<string> v;
        v.insert(to_string(si)+","+to_string(sj)+","+to_string(0));
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop();
                int i = node.x, j = node.y, k = node.k;
                // if(k == target) return ans-1;
                for(auto &dir: dirs){
                    int ii = i + dir[0], jj = j + dir[1];
                    if(0 <= ii && ii < g.size() && 0 <= jj && jj < g[0].size() && g[ii][jj] != '#'){
                        if('a' <= g[i][j] && g[i][j] <= 'f'){
                            k = k | (1 << (g[i][j]-'a'));
                        }
                        if('A' <= g[i][j] && g[i][j] <= 'F'){
                            if((k & (1 << (g[i][j] - 'A'))) == 0) continue;
                        }
                        string str = to_string(ii)+","+to_string(jj)+","+to_string(k);
                        if(v.find(str) != v.end()) continue;
                        if(k == target) return ans;
                        q.push(state(ii, jj, k));
                        v.insert(to_string(ii)+","+to_string(jj)+","+to_string(k));
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
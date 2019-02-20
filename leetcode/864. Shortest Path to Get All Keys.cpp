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
        unordered_set<string> seen;
        seen.insert(to_string(sx)+","+to_string(sy)+","+to_string(0)); // format: x,y,k
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
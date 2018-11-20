class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        priority_queue<triple> pq;
        pq.push(triple(grid[0][0], 0, 0));
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        seen[0][0] = true;
        int dir[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(pq.empty() == false){
            auto top = pq.top(); pq.pop();
            time = max(time, top.t);
            if(top.x == n-1 && top.y == n-1) return time;
            for(auto d: dir){
                int nextx = top.x + d[0];
                int nexty = top.y + d[1];
                if(0 <= nextx && nextx < n && 0 <= nexty && nexty < n 
                   && seen[nextx][nexty] == false){
                    seen[nextx][nexty] = true;
                    pq.push(triple(grid[nextx][nexty], nextx, nexty));
                }
            }
        }
        return time;
    }
    
private:
    struct triple{
        int t, x, y;
        triple(int _t, int _x, int _y): t(_t), x(_x), y(_y){}
        bool operator< (const triple &tri) const {return t > tri.t;}
    };
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> p(n*n, -2);
        vector<pair<int, int>> poss(n*n);
        int front = grid.front().front();
        int back = grid.back().back();
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) poss[grid[i][j]] = {i, j};
        for(int k = 0; k < n*n; k++){
            auto pos = poss[k];
            int i = pos.first;
            int j = pos.second;
            p[grid[i][j]] = -1;
            if(i-1 >= 0 && p[grid[i-1][j]] != -2) u(p, grid[i][j], grid[i-1][j]);
            if(i+1 < n && p[grid[i+1][j]] != -2) u(p, grid[i][j], grid[i+1][j]);
            if(j-1 >= 0 && p[grid[i][j-1]] != -2) u(p, grid[i][j], grid[i][j-1]);
            if(j+1 < n && p[grid[i][j+1]] != -2) u(p, grid[i][j], grid[i][j+1]);
            if(p[front] != -2 && p[back] != -2 && f(p, front) == f(p, back)) return k;
        }
        return n*n-1;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};
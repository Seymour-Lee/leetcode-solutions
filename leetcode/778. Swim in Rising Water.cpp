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
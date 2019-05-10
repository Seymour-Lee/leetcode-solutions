class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n * n * 4;
        p = vector<int>(count, -1);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(i > 0) u(pos(i, j, 0), pos(i-1, j, 2));
                if(j > 0) u(pos(i, j, 3), pos(i, j-1, 1));
                if(grid[i][j] == '/'){
                    u(pos(i, j, 0), pos(i, j, 3));
                    u(pos(i, j, 1), pos(i, j, 2));
                }
                else if(grid[i][j] == '\\'){
                    u(pos(i, j, 0), pos(i, j, 1));
                    u(pos(i, j, 2), pos(i, j, 3));
                }
                else{
                    u(pos(i, j, 0), pos(i, j, 1));
                    u(pos(i, j, 1), pos(i, j, 2));
                    u(pos(i, j, 2), pos(i, j, 3));
                }
            }
        }
        return count;
    }
    
private:
    int n;
    int count;
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, count--;
    }
    
    int pos(int i, int j, int k){
        return (i * n + j) * 4 + k;
    }
};
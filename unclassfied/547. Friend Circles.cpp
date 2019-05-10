class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        for(int i = 0; i < M.size(); i++){
            if(M[i][i]){
                result++;
                dfs(M, i);
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& M, int peo){
        for(int i = 0; i < M.size(); i++){
            if(peo != i && M[i][i] && M[peo][i]){
                M[peo][i] = 0;
                M[i][peo] = 0;
                dfs(M, i);
            }
        }
        M[peo][peo] = 0;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> p(M.size(), -1);
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M[i].size(); j++){
                if(M[i][j] == 1 && i != j){
                    u(p, i, j);
                }
            }
        }
        return count(p.begin(), p.end(), -1);
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp){
            p[xp] = yp;
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> p(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(M[i][j] == 1) u(p, i, j);
            }
        }
        int ans = 0;
        for(auto e: p) ans += e == -1? 1: 0;
        return ans;
    }
    
private:
    void u(vector<int> &p, int x, int y){
        int px = f(p, x);
        int py = f(p, y);
        if(px != py) p[px] = py;
    }
    
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return p[x] = f(p, p[x]);
    }
};
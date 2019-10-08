class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;
        int m = A.size(), n = A[0].size();
        p = vector<int>(m*n, -1);
        unordered_set<int> b;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(A[i][j]){
            if(i == 0 || j == 0 || i == m-1 || j == n-1) b.insert(i*n+j);
            if(i-1 >= 0 && A[i-1][j]){
                u(i*n+j, (i-1)*n+j);
            }
            if(j-1 >= 0 && A[i][j-1]){
                u(i*n+j, i*n+j-1);
            }
        }
        unordered_set<int> ex;
        for(auto a: b) ex.insert(f(a));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(A[i][j] && ex.find(f(i*n+j)) == ex.end()) ans++;
        return ans;
    }
    
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int px = f(x), py = f(y);
        if(px != py) p[px] = py;
    }
};
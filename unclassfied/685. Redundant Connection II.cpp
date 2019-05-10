class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n+1, -1);
        vector<int >reone, retwo;
        for(auto &e: edges){
            if(p[e[1]] == -1) p[e[1]] = e[0];
            else{
                reone = {p[e[1]], e[1]};
                retwo = e;
                e[1] = -1;
            }
        }
        for (int i = 1; i <= n; i++) p[i] = -1;
        for(auto e: edges){
            if(e[1] == -1) continue;
            int u = e[0], v = e[1], pu = f(p, u);
            if(pu == v){
                if(reone.size() == 0) return e;
                return reone;
            }
            p[v] = pu;
        }
        
        return retwo;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
};
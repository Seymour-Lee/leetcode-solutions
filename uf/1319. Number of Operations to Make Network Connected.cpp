class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        p = vector<int>(n, -1);
        for(int i = 0; i < connections.size(); i++){
            u(connections[i][0], connections[i][1]);
        }
        return count(p.begin(), p.end(), -1)-1;
    }
        
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int px = f(x);
        int py = f(y);
        if(px != py) p[px] = py;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        p = vector<int>(n, -1);
        for(auto &x: connections) u(x[0], x[1]);        
        return count(p.begin(), p.end(), -1) - 1;
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
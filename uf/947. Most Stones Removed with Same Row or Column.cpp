class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size() <= 1) return 0;
        vector<int> p(stones.size(), -1);
        for(int i = 0; i < stones.size(); i++){
            for(int j = i+1; j < stones.size(); j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    u(p, i, j);
                }
            }
        }
        int ans = stones.size();
        for(auto e: p) if(e == -1) ans--;
        return ans;
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        p = vector<int>(stones.size(), -1);
        for(int i = 0; i < stones.size(); i++) for(int j = i+1; j < stones.size(); j++) 
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) u(i, j);
        return stones.size() - count(p.begin(), p.end(), -1);
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        p = vector<int>(stones.size(), -1);
        for(int i = 0; i < stones.size(); i++) for(int j = i+1; j < stones.size(); j++) 
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) u(i, j);
        return stones.size() - count(p.begin(), p.end(), -1);
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
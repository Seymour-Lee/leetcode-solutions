class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        map<pair<int, int>, pair<int, int>> p;
        vector<int> ans;
        for(auto pos: positions){
            p[pos] = {-1, -1};
            int x = pos.first;
            int y = pos.second;
            if(x-1 >= 0 && p.find({x-1, y}) != p.end()) u(p, pos, {x-1, y});
            if(x+1 < m && p.find({x+1, y}) != p.end()) u(p, pos, {x+1, y});
            if(y-1 >= 0 && p.find({x, y-1}) != p.end()) u(p, pos, {x, y-1});
            if(y+1 < n && p.find({x, y+1}) != p.end()) u(p, pos, {x, y+1});
            int a = 0;
            for(auto v: p) if(v.second == pair<int, int>{-1, -1}) a++;
            ans.push_back(a);
        }
        return ans;
    }
    
private:
    void u(map<pair<int, int>, pair<int, int>> &p, pair<int, int> x, pair<int, int> y){
        auto xp = f(p, x);
        auto yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
    
    pair<int, int> f(map<pair<int, int>, pair<int, int>> &p, pair<int ,int> x){
        if(p[x] == pair<int, int>{-1, -1}) return x;
        return f(p, p[x]);
    }
};
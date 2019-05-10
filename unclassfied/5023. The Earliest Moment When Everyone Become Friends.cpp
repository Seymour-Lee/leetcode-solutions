class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        auto f = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };
        sort(logs.begin(), logs.end(), f);
        p = vector<int>(N, -1);
        c = N;
        if(c == 1) return 0;
        for(auto log: logs){
            u(log[1], log[2]);
            if(c == 1) return log[0];
        }
        return -1;
    }
    
private:
    vector<int> p;
    int c = 0;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, c--;
    }
};
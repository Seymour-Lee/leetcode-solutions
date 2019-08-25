class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        a = vector<int>(n+1, -1);
        counter = n+1;
        int ans = 0;
        for(auto &p: pipes) swap(p[0], p[2]);
        for(int i = 0; i < wells.size(); i++) pipes.push_back({wells[i], 0, i+1});
        sort(pipes.begin(), pipes.end());
        for(auto p: pipes){
            int xp = f(p[1]), yp = f(p[2]);
            if(xp != yp){
                a[xp] = yp;
                counter--;
                ans += p[0];
            }
            if(counter == 0) break;
        }
        return ans;
    }
    
private:
    vector<int> a;
    int counter;
    
    int f(int x){
        if(a[x] == -1) return x;
        return f(a[x]);
    }
};
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                if(A[i][j] == 1) dfs(A, i, j), flag = false;
            }
        }
        int ans = INT_MAX;
        for(auto p1: points1){
            for(auto p2: points2){
                ans = min(ans, abs(p1.first-p2.first)+abs(p1.second-p2.second)-1);
            }
        }
        return ans;
    }
    
private:
    bool flag = true;
    set<pair<int, int>> points1;
    set<pair<int, int>> points2;
    void dfs(vector<vector<int>> &a, int i, int j){
        if(i < 0 || i >= a.size() || j < 0 || j >= a[0].size()) return;
        if(a[i][j] == 0) return;
        if(a[i][j] == 1){
            a[i][j] = 0;
            if(flag) points1.insert({i, j});
            else points2.insert({i, j});
        }
        dfs(a, i+1, j);
        dfs(a, i-1, j);
        dfs(a, i, j+1);
        dfs(a, i, j-1);
    }
};
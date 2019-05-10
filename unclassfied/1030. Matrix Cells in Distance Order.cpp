class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                ans.push_back({i, j});
            }
        }
        auto f = [r0, c0](vector<int> a, vector<int> b){
            return abs(a[0]-r0)+abs(a[1]-c0) < abs(b[0]-r0)+abs(b[1]-c0);
        };
        sort(ans.begin(), ans.end(), f);
        return ans;
    }
};
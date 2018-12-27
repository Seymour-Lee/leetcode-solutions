class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        if(a.size() == 0 || a[0].size() == 0) return 0;
        int m = a.size(), n = a[0].size();
        vector<vector<bool>> v(a.size(), vector<bool>(a[0].size(), false));
        auto f = [](vector<int> &a, vector<int> &b){return a[2] > b[2];};
        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int> &, vector<int> &)>> pq(f);
        for(int j = 0; j < n; j++){
            pq.push({0, j, a[0][j]}); v[0][j] = true;
            pq.push({m-1, j, a[m-1][j]}); v[m-1][j] = true;
        }
        for(int i = 1; i < m-1; i++){
            pq.push({i, 0, a[i][0]}); v[i][0] = true;
            pq.push({i, n-1, a[i][n-1]}); v[i][n-1] = true;
        }
        int ans = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(pq.empty() == false){
            auto top = pq.top(); pq.pop();
            for(auto d: dir){
                int nx = top[0]+d[0];
                int ny = top[1]+d[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n && v[nx][ny] == false){
                    if(a[nx][ny] < top[2]){
                        ans += top[2]-a[nx][ny];
                        a[nx][ny] = top[2];
                    }
                    v[nx][ny] = true;
                    pq.push({nx, ny, a[nx][ny]});
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int ans = 0;
        m = mat.size(), n = mat[0].size();
        string init = "";
        for(auto &r: mat) for(auto &c: r) init += char('0'+c);
        // cout<<init;
        unordered_set<string> v;
        queue<string> q;
        v.insert(init);
        q.push(init);
        string target = string(m*n, '0');
        while(q.size()){
            int size = q.size();
            while(size--){
                auto str = q.front(); q.pop();
                if(str == target) return ans;
                for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
                    string next = flip(str, i, j);
                    if(v.find(next) == v.end()){
                        v.insert(next);
                        q.push(next);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
private:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
    string flip(string str, int i, int j){
        // cout<<str<<endl;
        string ans = "";
        vector<vector<int>> mm(m, vector<int>(n, 0));
        for(int r = 0; r < m; r++) for(int c = 0; c < n; c++) mm[r][c] += str[r*n+c]-'0';
        for(auto &r: mm){
            for(auto &c: r){
                // cout<<c<<" ";
            }
            // cout<<endl;
        }
        for(auto &dir: dirs){
            int ii = i + dir[0], jj = j + dir[1];
            if(0 <= ii && ii < m && 0 <= jj && jj < n) mm[ii][jj] = mm[ii][jj]? 0: 1;
        }
        mm[i][j] = mm[i][j]? 0: 1;
        for(auto &r: mm) for(auto &c: r) ans += char('0'+c);
        // cout<<"next: "<<ans<<endl;
        return ans;
    }
};
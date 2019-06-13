class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int, int>> fresh;
        set<pair<int, int>> will;
        set<pair<int, int>> seen;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < grid.size(); i++) for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1) fresh.insert({i, j});
            if(grid[i][j] == 2){
                seen.insert({i, j});
                for(auto dir: dirs){
                    int ii = i+dir[0];
                    int jj = j+dir[1];
                    if(0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[i].size() && grid[ii][jj] == 1){
                        will.insert({ii, jj});
                        seen.insert({ii, jj});
                        // if(fresh.find({ii, jj}) != fresh.end()) fresh.erase({ii, jj});
                    }
                }
            }
        }
        // cout<<will.size();
        // cout<<fresh.size()<<endl;
        int ans = 0;
        queue<pair<int, int>> q;
        for(auto p: will) q.push(p);
        while(q.empty() == false){
            int size = q.size();
            // cout<<endl<<size<<endl;
            while(size--){
                auto p = q.front(); q.pop();
                int i = p.first;
                int j = p.second;
                // cout<<i<<" "<<j<<endl;
                // seen.insert({i, j});
                for(auto dir: dirs){
                    int ii = i+dir[0];
                    int jj = j+dir[1];
                    if(0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[i].size() 
                       && fresh.find({ii, jj}) != fresh.end() && seen.find({ii, jj}) == seen.end()){
                        q.push({ii, jj});
                        seen.insert({ii, jj});
                        // fresh.erase({ii, jj});
                    }
                }
                fresh.erase({i, j});
            }
            ans++;
        }
        return fresh.size()? -1: ans;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int, int>> fresh;
        set<pair<int, int>> will;
        set<pair<int, int>> seen;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < grid.size(); i++) for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1) fresh.insert({i, j});
            if(grid[i][j] == 2){
                seen.insert({i, j});
                for(auto dir: dirs){
                    int ii = i+dir[0];
                    int jj = j+dir[1];
                    if(0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[i].size() && grid[ii][jj] == 1){
                        will.insert({ii, jj});
                        seen.insert({ii, jj});
                        // if(fresh.find({ii, jj}) != fresh.end()) fresh.erase({ii, jj});
                    }
                }
            }
        }
        // cout<<will.size();
        // cout<<fresh.size()<<endl;
        int ans = 0;
        queue<pair<int, int>> q;
        for(auto p: will) q.push(p);
        while(q.empty() == false){
            int size = q.size();
            // cout<<endl<<size<<endl;
            while(size--){
                auto p = q.front(); q.pop();
                int i = p.first;
                int j = p.second;
                // cout<<i<<" "<<j<<endl;
                // seen.insert({i, j});
                for(auto dir: dirs){
                    int ii = i+dir[0];
                    int jj = j+dir[1];
                    if(0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[i].size() 
                       && fresh.find({ii, jj}) != fresh.end() && seen.find({ii, jj}) == seen.end()){
                        q.push({ii, jj});
                        seen.insert({ii, jj});
                        // fresh.erase({ii, jj});
                    }
                }
                fresh.erase({i, j});
            }
            ans++;
        }
        return fresh.size()? -1: ans;
    }
};
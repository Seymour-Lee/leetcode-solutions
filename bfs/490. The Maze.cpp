class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> seen;
        queue<vector<int>> q;
        q.push(start);
        seen.insert(start);
        while(q.empty() == false){
            auto pos = q.front(); q.pop();
            if(pos == destination) return true;
            auto nexts = getNextPos(maze, pos);
            for(auto next: nexts){
                if(seen.find(next) == seen.end()){
                    q.push(next);
                    seen.insert(next);
                }
            }
        }
        return false;
    }
    
private:
    vector<vector<int>> getNextPos(vector<vector<int>>& maze, vector<int> start){
        vector<vector<int>> ans;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto dir: dirs){
            auto pos = start;
            while(0 <= pos[0]+dir[0] && pos[0]+dir[0] < maze.size() && 
                  0 <= pos[1]+dir[1] && pos[1]+dir[1] < maze[0].size() && 
                  maze[pos[0]+dir[0]][pos[1]+dir[1]] == 0){
                pos[0] += dir[0];
                pos[1] += dir[1];
            }
            ans.push_back(pos);
        }
        return ans;
    }
};

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        unordered_set<string> v;
        queue<vector<int>> q;
        q.push(start);
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto pos = q.front(); q.pop();
                if(pos == destination) return true;
                int i = pos[0], j = pos[1];
                v.insert(to_string(i)+","+to_string(j));
                for(auto dir: dirs){
                    int ii = i, jj = j;
                    while(0 <= ii+dir[0] && ii+dir[0] < maze.size() && 
                          0 <= jj+dir[1] && jj+dir[1] < maze[0].size() &&
                          maze[ii+dir[0]][jj+dir[1]] == 0) ii += dir[0], jj += dir[1];
                    // cout<<ii<<" "<<jj<<endl;
                    if(v.find(to_string(ii)+","+to_string(jj)) == v.end()) q.push({ii, jj});
                }
            }
        }
        return false;
    }
};
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
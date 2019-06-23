class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() == 0) return true;
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        bool result = true;
        for(auto v: visited) result = result && v;
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int cur){
        visited[cur] = true;
        for(auto key: rooms[cur]){
            if(visited[key] == false) dfs(rooms, visited, key);
        }
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size(), false);
        dfs(rooms, v, 0);
        return count(v.begin(), v.end(), false) == 0;
    }
    
private:
    void dfs(vector<vector<int>>& r, vector<bool> &v, int node){
        v[node] = true;
        for(auto next: r[node]) if(v[next] == false) dfs(r, v, next);
    }
};
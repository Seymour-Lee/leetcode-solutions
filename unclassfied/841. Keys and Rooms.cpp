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
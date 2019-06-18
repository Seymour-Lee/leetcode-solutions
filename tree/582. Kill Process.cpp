class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        map<int, vector<int>> pid2kids;
        for(int i = 0; i < pid.size(); i++){
            pid2kids[ppid[i]].push_back(pid[i]);
        }
        dfs(kill, pid2kids, ans);
        return ans;
    }
    
private:
    void dfs(int pid, map<int, vector<int>> &pid2kids, vector<int> &ans){
        ans.push_back(pid);
        for(auto kid: pid2kids[pid]) dfs(kid, pid2kids, ans);
    }
};

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> p2c;
        for(int i = 0; i < pid.size(); i++) p2c[ppid[i]].push_back(pid[i]);
        vector<int> ans;
        queue<int> q;
        q.push(kill);
        while(q.empty() == false){
            auto node = q.front(); q.pop();
            ans.push_back(node);
            for(auto c: p2c[node]) q.push(c);
        }
        return ans;
    }
};
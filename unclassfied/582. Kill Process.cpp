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
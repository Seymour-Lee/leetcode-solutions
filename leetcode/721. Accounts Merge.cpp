class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        int n = accounts.size();
        vector<int> parents(n);
        map<string, int> e2g;
        map<int, set<string>> g2e;
        for(int i = 0; i < n; i++) parents[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(e2g.find(accounts[i][j]) == e2g.end()){
                    e2g[accounts[i][j]] = i;
                }
                else{
                    connect(i, e2g[accounts[i][j]], parents);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int k = find(i, parents);
            g2e[k].insert(accounts[i].begin()+1, accounts[i].end());
        }
        for(auto p: g2e){
            vector<string> res;
            string name = accounts[p.first][0];
            res.push_back(name);
            for(auto s: p.second) res.push_back(s);
            ans.push_back(res);
        }
        return ans;
    }
    
private:
    void connect(int i, int j, vector<int> &p){
        p[find(i, p)] = find(j, p);
    }
    
    int find(int k, vector<int> &p){
        if(p[k] != k)
            p[k] = find(p[k], p);
        return p[k];
    }
};
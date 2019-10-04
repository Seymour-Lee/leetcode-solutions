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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> p(n, -1);
        unordered_map<string, int> e2g;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(e2g.find(accounts[i][j]) == e2g.end()){
                    e2g[accounts[i][j]] = i;
                }
                else{
                    u(p, i, e2g[accounts[i][j]]);
                }
            }
        }
        
        unordered_map<int, set<string>> g2e;
        for(int i = 0; i < n; i++){
            int root = f(p, i);
            g2e[root].insert(accounts[i].begin()+1, accounts[i].end());
        }
        
        vector<vector<string>> ans;
        for(auto g: g2e){
            vector<string> cur = {accounts[g.first][0]};
            for(auto e: g.second) cur.push_back(e);
            ans.push_back(cur);
        }
        return ans;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};

// TLE
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email2name;
        for(auto l: accounts){
            string name = l[0];
            for(int i = 1; i < l.size(); i++){
                email2name[l[i]] = name;
                u(l[1], l[i]);
            }
        }
        unordered_map<string, set<string>> groups;
        for(auto str: p){
            string root = f(str.first);
            groups[root].insert(str.first);
        }
        
        vector<vector<string>> ans;
        for(auto g: groups){
            vector<string> cur = {};
            cur.push_back(email2name[g.first]);
            for(auto email:g.second) cur.push_back(email);
            ans.push_back(cur);
        }
        return ans;
    }
    
private:
    unordered_map<string, string> p;
    
    string f(string x){
        if(p[x] == "") return x;
        return f(p[x]);
    }
    
    void u(string x, string y){
        string xp = f(x);
        string yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        p = vector<int>(accounts.size(), -1);
        unordered_map<string, int> e2g;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(e2g.find(accounts[i][j]) == e2g.end()){
                    e2g[accounts[i][j]] = i;
                }
                else{
                    u(i, e2g[accounts[i][j]]);
                }
            }
        }
        unordered_map<int, set<string>> g2e;
        for(int i = 0; i < accounts.size(); i++){
            int root = f(i);
            g2e[root].insert(accounts[i].begin()+1, accounts[i].end());
        }
        for(auto g: g2e){
            vector<string> cur = {accounts[g.first][0]};
            for(auto e: g.second) cur.push_back(e);
            ans.push_back(cur);
        }
        return ans;
    }
    
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        p = vector<int>(accounts.size(), -1);
        unordered_map<string, int> e2g;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(e2g.find(accounts[i][j]) == e2g.end()){
                    e2g[accounts[i][j]] = i;
                }
                else{
                    u(i, e2g[accounts[i][j]]);
                }
            }
        }
        unordered_map<int, set<string>> g2e;
        for(int i = 0; i < accounts.size(); i++){
            int root = f(i);
            g2e[root].insert(accounts[i].begin()+1, accounts[i].end());
        }
        for(auto g: g2e){
            vector<string> cur = {accounts[g.first][0]};
            for(auto e: g.second) cur.push_back(e);
            ans.push_back(cur);
        }
        return ans;
    }
    
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};
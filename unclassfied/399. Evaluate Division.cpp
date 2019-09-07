class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        map<string, vector<pair<double, string>>> var2p;
        set<string> vars;
        for(int i = 0; i < values.size(); i++){
            auto p = equations[i];
            double val = values[i];
            vars.insert(p.first);
            vars.insert(p.second);
            var2p[p.first].push_back({val, p.second});
            var2p[p.second].push_back({1/val, p.first});
        }
        for(auto q: queries){
            if(vars.find(q.first) == vars.end() || vars.find(q.second) == vars.end())
                ans.push_back(-1.0);
            else
                ans.push_back(bfs(q.first, q.second, var2p));
        }
        return ans;
    }
    
private:
    double bfs(string start, string target, map<string, vector<pair<double, string>>> &var2p){
        if(start == target) return 1.0;
        set<string> seen;
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        while(q.empty() == false){
            auto p = q.front(); q.pop();
            if(p.first == target) return p.second;
            seen.insert(p.first);
            for(auto n: var2p[p.first]){
                if(seen.find(n.second) == seen.end()){
                    q.push({n.second, n.first * p.second});
                }
            }
        }
        return -1.0;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_set<string> vars;
        for(int i = 0; i < values.size(); i++){
            auto p = equations[i];
            double val = values[i];
            vars.insert(p[0]);
            vars.insert(p[1]);
            var2p[p[0]].push_back({val, p[1]});
            var2p[p[1]].push_back({1/val, p[0]});
        }
        for(auto q: queries){
            if(vars.find(q[0]) == vars.end() || vars.find(q[1]) == vars.end())
                ans.push_back(-1.0);
            else
                ans.push_back(bfs(q[0], q[1]));
        }
        return ans;
    }
    
private:
    unordered_map<string, vector<pair<double, string>>> var2p;
    
    double bfs(string start, string target){
        if(start == target) return 1.0;
        unordered_set<string> seen;
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        while(q.empty() == false){
            auto p = q.front(); q.pop();
            if(p.first == target) return p.second;
            seen.insert(p.first);
            for(auto n: var2p[p.first]){
                if(seen.find(n.second) == seen.end()){
                    q.push({n.second, n.first * p.second});
                }
            }
        }
        return -1.0;
    }
};
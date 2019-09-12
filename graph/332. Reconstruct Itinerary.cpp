class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> g;
        vector<string> ans;
        if(tickets.size() == 0) return ans;
        for(auto p: tickets) g[p.first].insert(p.second);
        stack<string> stk;
        stk.push("JFK");
        while(stk.empty() == false){
            string node = stk.top();
            if(g[node].empty()){
                ans.push_back(node);
                stk.pop();
            }
            else{
                stk.push(*(g[node].begin()));
                g[node].erase(g[node].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;
        vector<string> ans;
        if(tickets.size() == 0) return ans;
        for(auto p: tickets) g[p[0]].insert(p[1]);
        stack<string> stk;
        stk.push("JFK");
        while(stk.empty() == false){
            string node = stk.top();
            if(g[node].empty()){
                ans.push_back(node);
                stk.pop();
            }
            else{
                stk.push(*(g[node].begin()));
                g[node].erase(g[node].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
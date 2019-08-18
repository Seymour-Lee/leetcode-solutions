class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<pair<unordered_set<string>, unordered_set<string>>> stk;
        stk.push({unordered_set<string>(), unordered_set<string> ({""})});
        for (auto c: expression) {
            if (c == '{') {
                stk.push({unordered_set<string>(), unordered_set<string> ({""})});
            } 
            else if (c == '}') {
                auto tmp = stk.top();
                stk.pop();
                for (auto s: tmp.second) tmp.first.insert(s);
                auto news = unordered_set<string> ();
                for (auto s1: stk.top().second) {
                    for (auto s2: tmp.first) {
                        news.insert(s1 + s2);
                    }
                }
                stk.top().second = news;
            } 
            else if (c == ',') {
                for (auto s: stk.top().second) {
                    stk.top().first.insert(s);
                }
                stk.top().second = unordered_set<string> ({""});
            } 
            else {
                auto news = unordered_set<string> ();
                for (auto s: stk.top().second) {
                    news.insert(s + c);
                }
                stk.top().second = news;
            }
        }
        for (auto s: stk.top().second) stk.top().first.insert(s);
        vector<string> ans;
        for (auto s: stk.top().first) ans.push_back(s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
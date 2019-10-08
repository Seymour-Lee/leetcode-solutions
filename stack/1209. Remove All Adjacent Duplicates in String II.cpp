class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for(auto c: s){
            if(stk.size() && stk.top().first == c) stk.top().second++;
            else stk.push({c, 1});
            if(stk.top().second == k) stk.pop();
        }
        string ans = "";
        while(stk.empty() == false){
            ans += string(stk.top().second, stk.top().first);
            stk.pop();
        }
        return string(ans.rbegin(), ans.rend());
    }
};
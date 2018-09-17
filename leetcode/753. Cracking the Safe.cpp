class Solution {
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        int total = pow(k, n);
        set<string> seen;
        seen.insert(ans);
        dfs(ans, total, seen, n, k);
        return ans;
    }
    
private:
    bool dfs(string &ans, int goal, set<string> &seen, int n, int k){
        if(seen.size() == goal) return true;
        string prev = ans.substr(ans.size()-n+1);
        for(char i = '0'; i < k+'0'; i++){
            string next = prev + i;
            if(seen.find(next) == seen.end()){
                seen.insert(next);
                ans.push_back(i);
                if(dfs(ans, goal, seen, n, k)) return true;
                else{
                    seen.erase(next);
                    ans.pop_back();
                }
            }
        }
        return false;
    }
};
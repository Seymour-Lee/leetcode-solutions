class Solution {
public:
    vector<string> expand(string S) {
        vector<string> ans;
        backtracking(S, ans, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void backtracking(string str, vector<string> &ans, string cur){
        if(str.size() == 0){
            ans.push_back(cur);
            return;
        }
        if(str[0] != '{'){
            backtracking(str.substr(1), ans, cur+str[0]);
        }
        else{
            auto r = str.find('}');
            string next = str.substr(r+1);
            for(int i = 1; i < r; i += 2){
                backtracking(next, ans, cur+str[i]);
            }
        }
    }
};
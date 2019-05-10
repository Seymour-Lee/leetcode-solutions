class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        backtracking(result, s, vector<string>{});
        return result;
    }
    
private:
    void backtracking(vector<vector<string>> &ans, string s, 
                      vector<string> cur){
        if(s == ""){
            for(auto sub: cur){
                if(valid(sub) == false) return;
            }
            ans.push_back(cur);
            return;
        }
        for(int step = 1; step <= s.size(); step++){
            string sub = s.substr(0, step);
            if(valid(sub) == false) continue;
            cur.push_back(sub);
            backtracking(ans, s.substr(step), cur);
            cur.pop_back();
        }
    }
    
    bool valid(string str){
        for(int i = 0, j = str.size() - 1; i < j; i++, j--){
            if(str[i] != str[j]){
                return false;
            } 
        }
        return true;
    }
};
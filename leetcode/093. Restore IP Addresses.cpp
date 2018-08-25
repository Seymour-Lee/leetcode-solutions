class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return vector<string>{};
        vector<string> result;
        set<string> ans;
        backtracking(ans, s, vector<string>{});
        for(auto res: ans) result.push_back(res);
        return result;
    }
    
private:
    void backtracking(set<string> &ans, string s, 
                      vector<string> cur){
        if(cur.size() == 4){
            if(s != "") return;
            if(valid(cur)){
                ans.insert(generate(cur));
            }
            return ;
        }
        if(s == "") return;
        for(int i = 1; i <= s.size(); i++){
            string sub = s.substr(0, i);
            cur.push_back(sub);
            backtracking(ans, s.substr(i), cur);
            cur.pop_back();
        }
    }
    
    bool valid(vector<string> vec){
        if(vec.size() != 4) return false;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].size() > 1 && vec[i][0] == '0') return false;
            int num = stoi(vec[i]);
            if(num < 0 || num > 255) return false;
        }
        return true;
    }
    
    string generate(vector<string> vec){
        string result = "";
        for(auto str: vec) result += "." + str;
        return result.substr(1);
    }
};
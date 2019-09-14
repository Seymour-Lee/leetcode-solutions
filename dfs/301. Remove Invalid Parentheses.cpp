// TLE
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        set<string> res;
        res.insert("");
        int longest = 0;
        dfs(s, res, longest);
        for(auto r: res) ans.push_back(r);
        return ans;
    }
    
private:
    set<string> cache;
    void dfs(string s, set<string> &ans, int &longest){
        if(s == "" || s.size() < longest) return;
        if(cache.find(s) != cache.end() || valid(s)){
            cache.insert(s);
            if(s.size() > longest){
                ans.clear();
                ans.insert(s);
                longest = s.size();
            }
            else if(s.size() == longest){
                ans.insert(s);
            }
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ')')
                dfs(s.substr(0, i) + s.substr(i+1), ans, longest);
            if(s.size()-1 < longest) return;
        }
    }
    
    bool valid(string str){
        if (str == "") return false;
        int cnt = 0;
        for (auto ch : str) {
            if (ch == '(') cnt++;
            if (ch == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        int left = 0;
        int right = 0;
        for(auto c: s){
            if(c == '(') left++;
            if(c == ')'){
                if(left != 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right, 0, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
    
private:
    void dfs(string s, int idx, int l, int r, int p, string path, set<string> &ans){
        if(idx == s.size()){
            if(l == 0 && r == 0 && p == 0){
                ans.insert(path);
            }
            return;
        }
        if(s[idx] != '(' && s[idx] != ')'){
            dfs(s, idx+1, l, r, p, path+s[idx], ans);
        }
        else{
            if(s[idx] == '('){
                if(l > 0){
                    dfs(s, idx+1, l-1, r, p, path, ans);
                }
                dfs(s, idx+1, l, r, p+1, path+s[idx], ans);
            }
            if(s[idx] == ')'){
                if(r > 0){
                    dfs(s, idx+1, l, r-1, p, path, ans);
                }
                if(p > 0){
                    dfs(s, idx+1, l, r, p-1, path+s[idx], ans);
                }
            }
        }
    }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        int left = 0;
        int right = 0;
        for(auto c: s){
            if(c == '(') left++;
            if(c == ')'){
                if(left != 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right, 0, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
    
private:
    void dfs(string s, int idx, int l, int r, int p, string path, set<string> &ans){
        if(idx == s.size()){
            if(l == 0 && r == 0 && p == 0) ans.insert(path);
            return;
        }
        if(s[idx] != '(' && s[idx] != ')') dfs(s, idx+1, l, r, p, path+s[idx], ans);
        else{
            if(s[idx] == '('){
                if(l > 0) dfs(s, idx+1, l-1, r, p, path, ans);
                dfs(s, idx+1, l, r, p+1, path+s[idx], ans);
            }
            if(s[idx] == ')'){
                if(r > 0) dfs(s, idx+1, l, r-1, p, path, ans);
                if(p > 0) dfs(s, idx+1, l, r, p-1, path+s[idx], ans);
            }
        }
    }
};


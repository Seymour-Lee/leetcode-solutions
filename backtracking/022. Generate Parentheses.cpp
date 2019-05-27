class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtracking(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtracking(vector<string> &result, 
                      string cur, int open, int close, int n){
        if(cur.size() == n*2){
            result.push_back(cur);
            return;
        }
        if(open < n){
            backtracking(result, cur+"(", open+1, close, n);
        }
        if(close < open){
            backtracking(result, cur+")", open, close+1, n);
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans, n, n, "");
        return ans;
    }
    
private:
    void backtracking(vector<string> &ans, int l, int r, string cur){
        if(l == 0 && r == 0){
            ans.push_back(cur);
            return;
        }
        if(l) backtracking(ans, l-1, r, cur+"(");
        if(l < r) backtracking(ans, l, r-1, cur+")");
    }
};
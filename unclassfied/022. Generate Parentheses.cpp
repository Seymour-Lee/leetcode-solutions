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
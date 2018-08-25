class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        backtracking(result, vector<int>{}, k, n, 1);
        return result;
    }
    
private:
    void backtracking(vector<vector<int>> &ans, vector<int> cur,
                      int k, int n, int pos){
        if(k == 0 && n == 0){
            ans.push_back(cur);
            return ;
        }
        if(pos == 10) return;
        backtracking(ans, cur, k, n, pos+1);
        cur.push_back(pos);
        backtracking(ans, cur, k-1, n-pos, pos+1);
        cur.pop_back();
    }
};
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        backtracking(result, vector<int>{}, 1, n, k);
        return result;
    }
    
private:
    void backtracking(vector<vector<int>> &result, vector<int> vec,
                      int cur, int n, int k){
        if(cur > n){
            if(vec.size() == k){
                result.push_back(vec);
            }
            return;
        }
        backtracking(result, vec, cur+1, n, k);
        vec.push_back(cur);
        backtracking(result, vec, cur+1, n, k);
    }
};
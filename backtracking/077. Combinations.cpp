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

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtracking(ans, n, k, cur, 1);
        return ans;
    }
    
private:
    void backtracking(vector<vector<int>> &ans, int n, int k,
                      vector<int> &cur, int num){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        if(num > n) return;
        backtracking(ans, n, k, cur, num+1);
        cur.push_back(num);
        backtracking(ans, n, k, cur, num+1);
        cur.pop_back();
    }
};
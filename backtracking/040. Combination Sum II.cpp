class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size() == 0) return result;
        set<multiset<int>> ans;
        backtracking(ans, candidates, target, multiset<int>{}, 0, 0);
        for(auto res: ans){
            vector<int> cur = {};
            for(auto e: res) cur.push_back(e);
            result.push_back(cur);
        }
        return result;
    }
    
private:
    void backtracking(set<multiset<int>> &ans, vector<int>& candidates,
                      int target, multiset<int> cur, int pos, int sum){
        if(sum > target) return;
        if(pos == candidates.size()){
            if(sum == target){
                ans.insert(cur);
            }
            return;
        }
        backtracking(ans, candidates, target, cur, pos+1, sum);
        cur.insert(candidates[pos]);
        backtracking(ans, candidates, target, cur, pos+1, sum+candidates[pos]);
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        set<vector<int>> ans;
        vector<int> cur;
        backtracking(c, ans, t, 0, cur, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(vector<int> &c, set<vector<int>> &ans,
                     int t, int pos, vector<int> &cur, int sum){
        if(sum == t){
            ans.insert(cur);
            return;
        }
        if(pos == c.size() || sum > t) return;
        backtracking(c, ans, t, pos+1, cur, sum);
        cur.push_back(c[pos]);
        backtracking(c, ans, t, pos+1, cur, sum+c[pos]);
        cur.pop_back();
    }
};
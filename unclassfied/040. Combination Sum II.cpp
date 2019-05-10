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
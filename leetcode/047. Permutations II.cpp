class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, ans, visited, vector<int>{});
        for(auto res: ans) result.push_back(res);
        return result;
    }
    
private:
    void backtracking(vector<int> &nums, set<vector<int>> &ans,
                      vector<bool> &visited, vector<int> cur){
        if(cur.size() == nums.size()){
            ans.insert(cur);
            return;
        }
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                cur.push_back(nums[i]);
                backtracking(nums, ans, visited, cur);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, result, vector<int>{}, visited);
        return result;
    }
    
private:
    void backtracking(vector<int>& nums,
                      vector<vector<int>> &result,
                      vector<int> cur,
                      vector<bool> &visited){
        if(cur.size() == visited.size()){
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                cur.push_back(nums[i]);
                backtracking(nums, result, cur, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};
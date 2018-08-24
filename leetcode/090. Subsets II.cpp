class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<multiset<int>> st;
        backtracking(st, nums, 0, multiset<int>{});
        for(auto sub: st){
            vector<int> cur = {};
            for(auto e: sub){
                cur.push_back(e);
            }
            result.push_back(cur);
        }
        return result;
    }
    
private:
    void backtracking(set<multiset<int>> &st, vector<int> &nums, int pos,
                      multiset<int> cur){
        if(pos == nums.size()){
            st.insert(cur);
            return;
        }
        backtracking(st, nums, pos+1, cur);
        cur.insert(nums[pos]);
        backtracking(st, nums, pos+1, cur);
    }
};
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for(auto update: updates){
            for(int i = update[0]; i <= update[1]; i++) ans[i] += update[2];
        }
        return ans;
    }
};
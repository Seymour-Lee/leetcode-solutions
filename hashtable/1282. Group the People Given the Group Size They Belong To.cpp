class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> s2id;
        for(int i = 0; i < groupSizes.size(); i++){
            s2id[groupSizes[i]].push_back(i);
        }
        for(auto &p: s2id){
            while(p.second.size()){
                int s = p.first;
                ans.push_back({});
                while(s--){
                    ans.back().push_back(p.second.back());
                    p.second.pop_back();
                }
            }
        }
        return ans;
    }
};
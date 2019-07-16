class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int, int>> nums;
        for(auto a: A){
            nums.push_back({a[0], -1});
            nums.push_back({a[1], 1});
        }
        for(auto a: B){
            nums.push_back({a[0], -1});
            nums.push_back({a[1], 1});
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int counter = 0;
        int prev = -1;
        for(auto p: nums){
            // cout<<p.first<<" "<<p.second<<endl;
            if(counter == -2) ans.push_back({prev, p.first});
            counter += p.second;
            if(counter == -2) prev = p.first;
        }
        return ans;
    }
};
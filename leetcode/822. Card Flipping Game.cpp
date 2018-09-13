class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> same;
        for(int i = 0; i < fronts.size(); i++){
            if(fronts[i] == backs[i])
                same.insert(fronts[i]);
        }
        int ans = INT_MAX;
        for(auto e: fronts) if(same.find(e) == same.end()) ans = min(ans, e);
        for(auto e: backs) if(same.find(e) == same.end()) ans = min(ans, e);
        return ans == INT_MAX? 0: ans;
    }
};
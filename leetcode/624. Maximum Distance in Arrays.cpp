class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = INT_MIN;
        int minval = arrays[0][0];
        int maxval = arrays[0].back();
        for(int i = 1; i < arrays.size(); i++){
            ans = max(ans, max(abs(minval - arrays[i].back()), abs(maxval - arrays[i][0])));
            minval = min(minval, arrays[i][0]);
            maxval = max(maxval, arrays[i].back());
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        map<int, int> a2r;
        for(auto a: arr) a2r[a] = 1;
        int r = 1;
        for(auto &p: a2r) p.second = r++;
        for(auto a: arr) ans.push_back(a2r[a]);
        return ans;
    }
};
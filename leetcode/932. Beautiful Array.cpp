class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1) return {1};
        if(n == 2) return {1, 2};
        vector<int> ans;
        auto l = beautifulArray((n+1)/2);
        auto r = beautifulArray(n/2);
        for(auto e: l) ans.push_back(2*e-1);
        for(auto e: r) ans.push_back(2*e);
        return ans;
    }
};
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> a2t;
        for(auto a: A) a2t[a]++;
        int ans = -1;
        for(auto p: a2t) if(p.second == 1) ans = max(ans, p.first);
        return ans;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> p2n;
        for(auto d: dominoes){
            if(d[0] > d[1]) swap(d[0], d[1]);
            p2n[{d[0], d[1]}]++;
        }
        int ans = 0;
        for(auto p: p2n) ans += p.second*(p.second-1)/2;
        return ans;
    }
};
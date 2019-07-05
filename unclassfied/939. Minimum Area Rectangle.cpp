class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> x2p;
        map<int, set<int>> y2p;
        for(auto p: points) x2p[p[0]].insert(p[1]), y2p[p[1]].insert(p[0]);
        int ans = INT_MAX;
        for(auto xs: x2p){
            auto x = xs.first;
            auto ys = vector<int>(xs.second.begin(), xs.second.end());
            for(int i = 0; i < ys.size(); i++){
                for(int j = i+1; j < ys.size(); j++){
                    auto set1 = y2p[ys[i]];
                    auto set2 = y2p[ys[j]];
                    vector<int> v(set1.size()+set2.size());
                    auto it=set_intersection (set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
                    v.resize(it-v.begin());   
                    for(auto x2: v){
                        if(x == x2) continue;
                        ans = min(ans, abs(ys[i]-ys[j])*abs(x-x2));
                    }
                }
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        unordered_map<int, set<int>> x;
         for (auto p : points) x[p[0]].insert(p[1]);
         for (auto i = x.begin(); i != x.end(); ++i)
            for (auto j = next(i); j != x.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
                begin(j->second), end(j->second), back_inserter(y));
                for (int k = 1; k < y.size(); ++k)
                    res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
            }
         return res == INT_MAX ? 0 : res;
    }
};
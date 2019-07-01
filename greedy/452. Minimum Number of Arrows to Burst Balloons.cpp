class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) return 0;
        int ans = 1;
        auto f = [](pair<int, int> a, pair<int, int> b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };
        sort(points.begin(), points.end());
        auto p = points[0];
        for(decltype(points.size()) i = 1; i < points.size(); i++){
            if(p.first == points[i].first){
                if(p.second >= points[i].second)
                    p = points[i];
            }
            else if(p.second >= points[i].first){
                if(p.second >= points[i].second)
                    p = points[i];
            }
            else{
                ans++;
                p = points[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& ps) {
        int ans = 0;
        auto f = [](vector<int> a, vector<int> b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(ps.begin(), ps.end(), f);
        while(ps.empty() == false){
            auto p = ps.back(); ps.pop_back();
            int s = p[0];
            while(ps.empty() == false && ps.back()[1] >= s) {
                s = max(s, ps.back()[0]);
                ps.pop_back();
            }
            ans++;
        }
        return ans;
    }
};
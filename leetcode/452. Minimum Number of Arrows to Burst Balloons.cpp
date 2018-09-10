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
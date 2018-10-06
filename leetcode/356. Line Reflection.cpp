class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int len = points.size();
        if(len == 0 || len == 1) return true;
        unordered_map<int, set<int>> y2xs;
        int maxx = points[0].first, minx = points[0].first;
        for(int i = 0; i < len; i++){
            minx = min(minx, points[i].first);
            maxx = max(maxx, points[i].first);
            y2xs[points[i].second].insert(points[i].first);
        }
        double line = (minx + maxx) / 2.0;
        for(auto it: y2xs){
            auto xs = it.second;
            for(auto begin = xs.begin(), end = xs.end(); begin != end; begin++){
                if((*begin + *(--end)) / 2.0 != line) return false;
                if(begin == end) break;
            }
        }
        return true;
    }
};
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        double ans = numeric_limits<double>::max();
        unordered_set<string> pstrs;
        auto dist = [](vector<int> a, vector<int> b){
            return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
        };
        for(auto p: points) pstrs.insert(to_string(p[0]) + " " + to_string(p[1]));
        for(auto p0: points){
            for(auto p1: points){
                if(p0 == p1) continue;
                for(auto p2: points){
                    if(p0 == p2 || p1 == p2) continue;
                    if(dist(p0, p1) + dist(p0, p2) == dist(p1, p2)){
                        vector<int> p3 = {p1[0]+p2[0]-p0[0], p1[1]+p2[1]-p0[1]};
                        if(pstrs.find(to_string(p3[0]) + " " + to_string(p3[1])) != pstrs.end()){
                            ans = min(ans, sqrt(dist(p0, p1)) * sqrt(dist(p0, p2)));
                        }
                    }
                }
            }
        }
        return ans == numeric_limits<double>::max()? 0: ans;
    }
};
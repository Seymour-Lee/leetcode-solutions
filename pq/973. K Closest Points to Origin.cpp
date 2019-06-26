class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto f = [](vector<int> a, vector<int> b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        sort(points.begin(), points.end(), f);
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        using ii = pair<int, int>;
        auto f = [](ii a, ii b){
            return a.first*a.first+a.second*a.second > b.first*b.first+b.second*b.second;
        };
        priority_queue<ii, vector<ii>, function<bool(ii, ii)>> pq(f);
        for(auto p: points) pq.push({p[0], p[1]});
        while(K--){
            auto p = pq.top(); pq.pop();
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};
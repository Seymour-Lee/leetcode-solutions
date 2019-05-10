/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 2) return points.size();
        int ans = 0;
        unordered_map<double, int> k2freq;
        for(int i = 0; i < points.size(); i++){
            k2freq.clear();
            int curmax = 1, overlap = 0, vertical = 1;
            for(int j = i+1; j < points.size(); j++){
                if(points[i].x == points[j].x){
                    if(points[i].y == points[j].y) overlap++;
                    else vertical++;
                    continue;
                }
                double k = 1000000.0*(double)(points[i].y-points[j].y) / (double)(points[i].x-points[j].x);
                k2freq[k] = (k2freq[k] == 0? 2: k2freq[k]+1);
                curmax = max(curmax, k2freq[k]);
            }
            curmax = max(vertical+overlap, curmax+overlap);
            ans = max(ans, curmax);
        }
        
        return ans;
    }
};
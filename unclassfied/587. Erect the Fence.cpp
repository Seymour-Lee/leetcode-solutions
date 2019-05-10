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
    vector<Point> outerTrees(vector<Point>& points) {
        if(points.size() < 4) return points;
        auto dir = [](Point a, Point b, Point c){
            return (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
        };
        auto f = [](Point a, Point b){
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        };
        sort(points.begin(), points.end(), f);
        vector<Point> ans;
        for(auto point: points){
            while(ans.size() >= 2 && dir(ans[ans.size()-2], ans[ans.size()-1], point) < 0){
                ans.pop_back();
            }
            ans.push_back(point);
        }
        ans.pop_back();
        for(int i = points.size()-1; i >= 0; i--){
            while(ans.size() >= 2 && dir(ans[ans.size()-2], ans[ans.size()-1], points[i]) < 0){
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }
};
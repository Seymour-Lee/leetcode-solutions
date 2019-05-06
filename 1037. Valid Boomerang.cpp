class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        set<vector<int>> ps(points.begin(), points.end());
        if(ps.size() != 3) return false;
        int dx = points[0][0] - points[1][0];
        int dy = points[0][1] - points[1][1];
        if(dx == 0 && dy != 0){
            return points[0][0] != points[2][0];
        }
        else if(dy == 0 && dx != 0){
            return points[0][1] != points[2][1];
        }
        else{
            int dxx = points[1][0] - points[2][0];
            int dyy = points[1][1] - points[2][1];
            return double(dx)/dy != double(dxx)/dyy;
        }
        return false;
    }
};
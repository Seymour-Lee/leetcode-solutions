class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        constexpr double pi = atan(1.0) * 4.0;
        vector<double> polars;
        for(int i = 0; i < points.size(); i++){
            int dx = points[(i+1)%n][0] - points[i][0];
            int dy = points[(i+1)%n][1] - points[i][1];
            double ang =atan2(dy, dx);
            polars.push_back(ang >= 0? ang: ang+2*pi);
        }
        int up = 0;
        int down = 0;
        for (int i = 0; i < polars.size(); i++) {
            if (polars[(i+1)%n] > polars[i]) up++;
            if (polars[(i+1)%n] < polars[i]) down++;
        }
        return (up <= 1 || down <= 1);
    }
};
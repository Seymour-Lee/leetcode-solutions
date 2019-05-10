class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        srand(time(0));
    }
    
    vector<double> randPoint() {
        double theta = 2 * pi * uniform();
        double t = sqrt(uniform());
        return vector<double>{
            x + r * t * cos(theta),
            y + r * t * sin(theta)
        };
    }
    
private:
    const double pi = 3.14159265358979732384626433832795;
    double r, x, y;
    
    double uniform(){
        return (double)rand() / RAND_MAX;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
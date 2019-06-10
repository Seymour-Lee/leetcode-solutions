class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for(int i = 0; i < points.size()-2; i++){
            for(int j = i+1; j < points.size()-1; j++){
                for(int k = j+1; k < points.size(); k++){
                    result = max(result, getArea(points[i], points[j], points[k]));
                }
            }
        }
        return result;
    }
    
private:
    double getArea(vector<int> a, vector<int> b, vector<int> c){
        return 0.5 *abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1]
                             -a[1]*b[0] - b[1]*c[0] - c[1]*a[0]);
    }
};

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for(int i = 0; i < points.size()-2; i++){
            for(int j = i+1; j < points.size()-1; j++){
                for(int k = j+1; k < points.size(); k++){
                    result = max(result, getArea(points[i], points[j], points[k]));
                }
            }
        }
        return result;
    }
    
private:
    double getArea(vector<int> a, vector<int> b, vector<int> c){
        return 0.5 *abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1]
                             -a[1]*b[0] - b[1]*c[0] - c[1]*a[0]);
    }
};
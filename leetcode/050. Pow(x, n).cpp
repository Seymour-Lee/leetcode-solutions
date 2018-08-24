class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0.0) return 0.0;
        bool pos = n > 0? true: false;
        n = fabs(n);
        return pos? pow(x, n): 1 / pow(x, n);
    }
    
private:
    double pow(double x, int n){
        if(n == 0) return 1.0;
        if(n % 2 == 0){
            double half = pow(x, n/2);
            return half * half;
        }
        else{
            double half = pow(x, n/2);
            return half * half * x;
        }
    }
};
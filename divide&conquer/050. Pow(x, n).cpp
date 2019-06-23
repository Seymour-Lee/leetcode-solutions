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

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0.0) return 0.0;
        bool sign = n > 0? true: false;
        long p = labs((long)n);
        return sign? binaryPow(x, p): 1 / binaryPow(x, p);
    }
    
private:
    double binaryPow(double x, long n){
        if(n == 0) return 1.0;
        if(n % 2 == 1){
            double half = binaryPow(x, n/2);
            return half * half * x;
        }
        else{
            double half = binaryPow(x, n/2);
            return half*half;
        }
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0.0) return 0;
        bool pos = n > 0;
        long long nn = labs(n);
        return pos? p(x, nn): 1 / p(x, nn);
    }
    
private:
    double p(double x, long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double ans = p(x, n/2);
        return n%2 == 1? ans*ans*x: ans*ans;
    }
};
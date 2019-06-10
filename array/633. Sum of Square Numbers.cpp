class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for(int a = 0; a <= n; a++){
            double b = sqrt(c - a * a);
            if(b == (int)b) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        while(a <= b){
            int m = a*a + b*b;
            if(m == c)return true;
            if(m < c) a++;
            else b--;
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = sqrt(c/2);
        long long b = a;
        while(a >= 0){
            if(a*a + b*b == c) return true;
            if(a*a + b*b < c) b++;
            else a--;
        }
        return false;
    }
};
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
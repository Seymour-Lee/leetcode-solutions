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
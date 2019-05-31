class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        return getSum(a ^ b, (a & b) << 1);
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        return b ? getSum(a ^ b, ((a & b) & 0x7FFFFFFF) << 1) : a;
    }
};
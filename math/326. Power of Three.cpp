class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        while(n != 1){
            if(n % 3) return false;
            n = n / 3;
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return log10(n) / log10(3) - int(log10(n) / log10(3)) == 0;
    }
};
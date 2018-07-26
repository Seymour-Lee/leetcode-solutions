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
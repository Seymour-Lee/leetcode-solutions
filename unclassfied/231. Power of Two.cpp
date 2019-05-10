class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        int counter = 0;
        while(n){
            if(counter) return false;
            if(n & 1) counter++;
            n = n >> 1;
        }
        return true;
    }
};
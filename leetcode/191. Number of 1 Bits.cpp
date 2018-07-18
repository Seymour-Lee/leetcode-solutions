class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n){
            if(n & 1) result++;
            n = n >> 1;
        }
        return result;
    }
};
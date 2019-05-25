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

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) ans += (((n>>i)&1)==1);
        return ans;
    }
};
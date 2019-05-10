class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(uint32_t i = 0; i < 32; i++){
            result = (result << 1) + ((n >> i) & (uint32_t)1);
        }
        return result;
    }
};
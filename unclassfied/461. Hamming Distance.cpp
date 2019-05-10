class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int a = x ^ y;
        while(a){
            result += a & 1;
            a = a >> 1;
        }
        return result;
    }
};
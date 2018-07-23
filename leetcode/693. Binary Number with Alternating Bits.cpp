class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
        int cur;
        n = n >> 1;
        while(n){
            cur = n & 1;
            if(last == cur) return false;
            last = cur;
            n = n >> 1;
        }
        return true;
    }
};
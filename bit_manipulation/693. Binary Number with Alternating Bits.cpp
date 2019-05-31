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

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i = 31;
        while((n>>i) == 0) i--;
        for(int j = i-1; j >= 0; i--, j--){
            if(((n>>i)&1) == 1 && ((n>>j)&1) == 0 || ((n>>i)&1) == 0 && ((n>>j)&1) == 1) continue;
               return false;
        }
        return true;
    }
};
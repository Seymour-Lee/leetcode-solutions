class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(i <= n) n -= i, i++;
        return i-1;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        for(int i = 1; n >= 0; i++){
            n -= i;
            if(n < 0) return i-1;
        }
        return 0;
    }
};
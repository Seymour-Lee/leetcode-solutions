// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int m;
        while(l <= r){
            m = l + (r - l) / 2;
            int cur = guess(m);
            if(cur == 1) l = m + 1;
            else if(cur == -1) r = m - 1;
            else if(cur == 0) break;
        }
        return m;
    }
};
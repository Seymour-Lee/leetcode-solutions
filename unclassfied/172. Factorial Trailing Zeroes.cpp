class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n) ans += n/5, n /= 5;
        return ans;
    }
};
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int mod = 1e9 + 7;
        int L = A / __gcd(A, B) * B;
        long l = 0;
        long r = (long)1e15;
        while (l < r) {
            long m = l + (r - l) / 2;
            if (m/A + m/B - m/L < N) l = m + 1;
            else r = m;
        }
        return (int) (l % mod);
    }
};
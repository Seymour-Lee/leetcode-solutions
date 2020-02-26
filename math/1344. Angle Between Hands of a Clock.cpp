class Solution {
public:
    double angleClock(int h, int m) {
        return 180 - abs (180 - abs ( m * 6 - (h * 30 + m * 0.5) ) );
    }
};
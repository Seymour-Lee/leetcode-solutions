class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, mid = left + (right - left) / 2;
        while (left <= right) {
            if (mid == x / mid) return mid;
            else {
                if (mid > x / mid) right = mid - 1;
                else left = mid + 1;
                mid = left + (right - left) / 2;
            }
        }
        return right;
    }
};
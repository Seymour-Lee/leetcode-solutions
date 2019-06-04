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

class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = (long long)x+1;
        while(l < r){
            long long m = l + (r - l) / 2;
            if(m*m == x) return m;
            if(m*m < x) l = m+1;
            else r = m;
        }
        return l-1;
    }
};
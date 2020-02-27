class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int f2 = 2, f3 = 3, f5 = 5;
        for(int i = 1; i < n; i++){
            int smallest = min(f2, min(f3, f5));
            ugly[i] = smallest;
            if(f2 == smallest) f2 = 2 * ugly[++idx2];
            if(f3 == smallest) f3 = 3 * ugly[++idx3];
            if(f5 == smallest) f5 = 5 * ugly[++idx5];
        }
        return ugly.back();
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        int c2 = 2, c3 = 3, c5 = 5;
        for(int i = 1; i < n; i++){
            int minval = min({c2, c3, c5});
            nums[i] = minval;
            if(c2 == minval) c2 = 2 * nums[++i2];
            if(c3 == minval) c3 = 3 * nums[++i3];
            if(c5 == minval) c5 = 5 * nums[++i5];
        }
        return nums.back();
    }
};
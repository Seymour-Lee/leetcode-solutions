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
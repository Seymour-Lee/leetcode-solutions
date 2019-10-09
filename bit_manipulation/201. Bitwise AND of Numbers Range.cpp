class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m * n == 0) return 0;
        if(m == n) return m;
        long two = 1;
        while(two <= n) two = two << 1;
        cout<<"here";
        if(two / 2 > m) return 0;
        long mm = m;
        long nn = n;
        int result = mm++;
        while(mm <= nn) result = result & mm++;
        return result;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if((long)m * (long)n == 0) return 0;
        if(m == n) return m;
        long two = 1;
        while(two <= n) two = two << 1;
        if(two / 2 > m) return 0;
        long mm = m;
        long nn = n;
        int result = mm++;
        while(mm <= nn) result = result & mm++;
        return result;
    }
};
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long l = 1, r = num / 2;
        while(l <= r){
            long m = l + (r - l) / 2;
            if(m * m == num) return true;
            if(m * m > num) r =  m - 1;
            else l = m + 1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1 || num == 4) return true;
        int l = 1, r = num/2+1;
        while(l <= r){
            int m = l + (r - l) / 2;
            long temp = (long)m*m;
            if(temp == num) return true;
            else if(temp < num) l = m+1;
            else r = m-1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, r = (long)num+1;
        while(l < r){
            long m = l + (r - l) / 2;
            if(m*m == num) return true;
            if(m*m < num) l = m+1;
            else r = m;
        }
        
        return false;
    }
};
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l < r){
            int m = l + (r - l) / 2;
            if(isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 0, r = (long)n+1;
        while(l < r){
            long m = l + (r - l) / 2;
            if(isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(A[m-1] < A[m] && A[m] > A[m+1]) return m;
            else if(A[m-1] < A[m] && A[m] < A[m+1]) l = m;
            else if(A[m-1] > A[m] && A[m] > A[m+1]) r = m;
        }
        return A[1];
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int pos = 0;
        while(A[pos] < A[pos+1]) pos++;
        return pos;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(A[m] > A[m+1]) r = m;
            else l = m+1; // [m] <= [m+1]
        }
        return l;
    }
};
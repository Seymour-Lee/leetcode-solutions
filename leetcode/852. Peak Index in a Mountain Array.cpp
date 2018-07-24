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
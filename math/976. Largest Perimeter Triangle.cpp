class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        for(int i = 0; i < A.size()-2; i++) for(int j = i+1; j < A.size()-1; j++){
            if(A[i] < A[j] + A[j+1]) return A[i] + A[j] + A[j+1];
        }
        return 0;
    }
};

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i = A.size()-3; i >= 0; i--){
            if(A[i]+A[i+1] > A[i+2]) return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }
};
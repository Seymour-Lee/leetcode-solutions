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
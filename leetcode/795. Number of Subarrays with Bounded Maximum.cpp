class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        if(A.size() == 0) return 0;
        int result = 0;
        int j = 0, count = 0;
        for(int i = 0; i < A.size(); i++){
            if(L <= A[i] && A[i] <= R){
                result += i - j + 1;
                count = i - j + 1;
            }
            else if(A[i] < L){
                result += count;
            }
            else{
                j = i + 1;
                count = 0;
            }
        }
        return result;
    }
};
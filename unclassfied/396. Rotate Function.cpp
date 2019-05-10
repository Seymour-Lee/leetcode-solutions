class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int n = A.size();
        int f = 0;
        for(int i = 0; i < n; i++){
            f += i * A[i];
            sum += A[i];
        }
        int result = f;
        for(int i = n-1; i > 0; i--){
            f = f + sum - n*A[i];
            result = max(result, f);
        }
        return result;
    }
};
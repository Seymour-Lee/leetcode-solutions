class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int result = 1;
        for(int k = 2; k < sqrt(2*N); k++){
            if((N - (k * (k - 1) / 2)) % k == 0) result++;
        }
        return result;
    }
};
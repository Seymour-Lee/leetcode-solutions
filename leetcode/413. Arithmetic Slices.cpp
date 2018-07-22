class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<int> sums = {0, 0};
        for(int i = 2; i < A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                sums.push_back(sums[i-1] + 1);
                result += sums[i];
            }
            else{
                sums.push_back(0);
            }
        }
        return result;
    }
};
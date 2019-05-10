class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int result = 0;
        int row = A.size(), col = A[0].size();
        for(int r = 0; r < row; r++){
            if(A[r][0] == 0) {
                for(int c = 0; c < col; c++){
                    A[r][c] = A[r][c] ^ 1;
                }
            }
            result = result + pow(2, col-1);
        }
        for(int c = 1; c < col; c++){
            int counter = 0;
            for(int r = 0; r < row; r++){
                counter += A[r][c]? 1: 0;
            }
            result += max(counter, row-counter) * pow(2.0, col-c-1);
        }
        return result;
    }
};
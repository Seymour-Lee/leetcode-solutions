class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size(), vector<int>(A.size(), 0));
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};
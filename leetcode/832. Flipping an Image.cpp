class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty()) return vector<vector<int>>();
        vector<vector<int>> result(A.size(), vector<int>(A[0].size(), 0));
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j <= A[i].size()/2; j++){
                result[i][j] = A[i][A[i].size()-j-1] ^ 1;
                result[i][A[i].size()-j-1] = A[i][j] ^ 1;
            }
        }
        return result;
    }
};
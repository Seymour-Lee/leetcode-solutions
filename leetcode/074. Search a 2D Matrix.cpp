class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        for(auto row: matrix){
            if(row.front() <= target && target <= row.back()){
                return binary_search(row.begin(), row.end(), target);
            }
        }
        return false;
    }
};
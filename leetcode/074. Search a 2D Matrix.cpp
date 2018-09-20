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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l = 0, r = matrix.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[m][0] <= target && target <= matrix[m].back())
                return binary_search(matrix[m].begin(), matrix[m].end(), target);
            if(matrix[m].back() < target) l = m+1;
            else r = m-1;
        }
        return false;
    }
};
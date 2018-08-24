class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        return binary(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
    }
    
private:
    bool binary(vector<vector<int>> &matrix, 
                int sr, int sc, int er, int ec,
                int target){
        if(sr > er || sc > ec) return false;
        if(sr == er && sc == ec) return matrix[sr][sc] == target;
        if(target < matrix[sr][sc] || matrix[er][ec] < target) return false;
        int mr = sr + (er - sr) / 2;
        int mc = sc + (ec - sc) / 2;
        int mid = matrix[mr][mc];
        if(mid == target) return true;
        else{
            return binary(matrix, sr, sc, mr, mc, target) ||
                   binary(matrix, sr, mc+1, mr, ec, target) ||
                   binary(matrix, mr+1, sc, er, mc, target) ||
                   binary(matrix, mr+1, mc+1, er, ec, target);
        }
    }
};
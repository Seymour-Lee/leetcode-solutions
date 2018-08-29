class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto r: row){
            for(int c = 0; c < matrix[r].size(); c++)
                matrix[r][c] = 0;
        }
        for(auto c: col){
            for(int r = 0; r < matrix.size(); r++) 
                matrix[r][c] = 0;
        }
    }
};
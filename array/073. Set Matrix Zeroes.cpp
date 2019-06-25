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

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> cols;
        unordered_set<int> rows;
        for(int i = 0; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[i].size(); j++)
                if(matrix[i][j] == 0) cols.insert(j), rows.insert(i);
        for(auto r: rows) for(int c = 0; c < matrix[0].size(); c++) matrix[r][c] = 0;
        for(auto c: cols) for(int r = 0; r < matrix.size(); r++) matrix[r][c] = 0;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_set<int> row, col;
        for(int i = 0; i < m.size(); i++) for(int j = 0; j < m[i].size(); j++) if(m[i][j] == 0){
            row.insert(i);
            col.insert(j);
        }
        for(auto r: row) for(int j = 0; j < m[r].size(); j++) m[r][j] = 0;
        for(auto c: col) for(int i = 0; i < m.size(); i++) m[i][c] = 0;
    }
};
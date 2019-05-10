class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<int>{};
        if(matrix.size() == 1) return matrix.front();
        vector<int> result;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;
        int sr = 0;
        int sc = 0;
        while(sr <= er && sc <= ec){
            for(int c = sc; c <= ec; c++) 
                result.push_back(matrix[sr][c]);
            for(int r = sr+1; r <= er-1; r++) 
                result.push_back(matrix[r][ec]);
            if(sr != er) for(int c = ec; c >= sc; c--) 
                result.push_back(matrix[er][c]);
            if(sc != ec) for(int r = er-1; r >= sr+1; r--) 
                result.push_back(matrix[r][sc]);
            sr++; sc++;
            er--; ec--;
        }
        return result;
    }
};
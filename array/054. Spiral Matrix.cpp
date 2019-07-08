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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        if(m.size() == 0 || m[0].size() == 0) return {};
        vector<int> ans;
        int sr = 0, sc = 0;
        int er = m.size()-1, ec = m[0].size()-1;
        while(sr <= er && sc <= ec){
            for(int c = sc; c <= ec; c++) ans.push_back(m[sr][c]);
            for(int r = sr+1; r <= er-1; r++) ans.push_back(m[r][ec]);
            if(sr != er) for(int c = ec; c >= sc; c--) ans.push_back(m[er][c]);
            if(sc != ec) for(int r = er-1; r >= sr+1; r--) ans.push_back(m[r][sc]);
            sr++; sc++;
            er--; ec--;
        }
        return ans;
    }
};
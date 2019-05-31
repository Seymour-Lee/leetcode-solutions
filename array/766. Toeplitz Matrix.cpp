class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        for(int i = m.size()-1; i >= 0; i--){
            int a = m[i][0];
            int x = i, y = 0;
            while(x < m.size() && y < m[0].size()) if(m[x++][y++] != a) return false;
        }
        for(int i = 0; i < m[0].size(); i++){
             int a = m[0][i];
            int x = 0, y = i;
            while(x < m.size() && y < m[0].size()) if(m[x++][y++] != a) return false;
        }
        return true;
    }
};
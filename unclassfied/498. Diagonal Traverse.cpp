class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return vector<int>{};
        vector<int> result(matrix.size()*matrix[0].size());
        for(int i = 0, r = 0, c = 0; i < result.size(); i++){
            result[i] = matrix[r][c];
            if((r + c) % 2 == 0){
                if(c == matrix[0].size()-1)r++;
                else if(r == 0) c++;
                else{r--; c++;}
            }
            else{
                if(r == matrix.size()-1) c++;
                else if(c == 0) r++;
                else{r++; c--;}
            }
        }
        return result;
    }
};
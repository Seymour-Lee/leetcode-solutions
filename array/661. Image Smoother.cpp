class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.size() == 0) return vector<vector<int>>();
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
        for(int i = 0; i< M.size(); i++){
            for(int j = 0; j < M[0].size(); j++){
                int counter = 0;
                for(int m = i-1; m <= i+1; m++){
                    for(int n = j-1; n <= j+1; n++){
                        if(0 <=  m && m < M.size() && 0 <= n && n < M[i].size()){
                            result[i][j] += M[m][n];
                            counter++;
                        }
                    }
                }
                result[i][j] /= counter;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.size() == 0) return vector<vector<int>>();
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
        for(int i = 0; i< M.size(); i++){
            for(int j = 0; j < M[0].size(); j++){
                int counter = 0;
                for(int m = i-1; m <= i+1; m++){
                    for(int n = j-1; n <= j+1; n++){
                        if(0 <=  m && m < M.size() && 0 <= n && n < M[i].size()){
                            result[i][j] += M[m][n];
                            counter++;
                        }
                    }
                }
                result[i][j] /= counter;
            }
        }
        return result;
    }
};
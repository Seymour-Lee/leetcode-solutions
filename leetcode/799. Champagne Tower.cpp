class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> vec(101, vector<double>(101, 0));
        vec[0][0] = poured;
        for(int r = 0; r <= query_row; r++){
            for(int c = 0; c <= r; c++){
                double extra = (vec[r][c] - 1.0) / 2.0;
                if(extra > 0){
                    vec[r+1][c] += extra;
                    vec[r+1][c+1] += extra;
                }
            }
        }
        return min(1.0, vec[query_row][query_glass]);
    }
};
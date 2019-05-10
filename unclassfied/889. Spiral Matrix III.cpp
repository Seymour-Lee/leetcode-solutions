class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        result.push_back(vector<int>{r0, c0});
        int counter = 1;
        if(R*C == counter) return result;
        for(int i = 1; i <= 2*(R+C); i+=2){
            for(int j = 0; j < 4; j++){
                int steps = i + j/2;
                for(int k = 0; k < steps; k++){
                    r0 = r0 + dr[j];
                    c0 = c0 + dc[j];
                    if(0 <= r0 && r0 < R && 0 <= c0 && c0 < C){
                        result.push_back(vector<int>{r0, c0});
                        counter++;
                    }
                    if(counter == R*C) return result;
                }
            }
        }
        return result;
    }
};
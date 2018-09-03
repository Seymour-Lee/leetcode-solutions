class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(validr(i, board) == false) return false;
            if(validc(i, board) == false) return false;
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(valids(i, j, board) == false) return false;
            }
        }
        return true;
    }
    
private:
    bool validr(int r, vector<vector<char>> &b){
        vector<bool> vec(9, false);
        for(int i = 0; i < 9; i++){
            if(b[r][i] == '.') continue;
            if(vec[b[r][i] - '0'] == true) return false;
            vec[b[r][i] - '0'] = true;
        }
        return true;
    }
    
    bool validc(int c, vector<vector<char>> &b){
        vector<bool> vec(9, false);
        for(int i = 0; i < 9; i++){
            if(b[i][c] == '.') continue;
            if(vec[b[i][c] - '0'] == true) return false;
            vec[b[i][c] - '0'] = true;
        }
        return true;
    }
    
    bool valids(int sr, int sc, vector<vector<char>> &b){
        vector<bool> vec(9, false);
        for(int i = sr; i < sr+3; i++){
            for(int j = sc; j < sc+3; j++){
                if(b[i][j] == '.') continue;
                if(vec[b[i][j] - '0'] == true) return false;
                vec[b[i][j] - '0'] = true;
            }
        }
        return true;
    }
};
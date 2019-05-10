class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        backtracking(board);
    }
    
private:
    bool backtracking(vector<vector<char>> &board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(valid(board, i, j, c)){
                            board[i][j] = c;
                            if(backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(const vector<vector<char>> &board, const int row, const int col, const char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
        }
        return true;
    }
};
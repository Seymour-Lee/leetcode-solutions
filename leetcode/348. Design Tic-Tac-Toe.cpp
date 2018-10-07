class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rowcnt = vector<vector<int>>(2, vector<int>(n, 0));
        colcnt = vector<vector<int>>(2, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(++rowcnt[player-1][row] == n) return player;
        if(++colcnt[player-1][col] == n) return player;
        if(row == col && ++diag1[player-1] == n) return player;
        if(row+col+1 == n && ++diag2[player-1] == n) return player;
        return 0;
    }
    
private:
    int n;
    vector<vector<int>> rowcnt;
    vector<vector<int>> colcnt;
    vector<int> diag1 = {0, 0};
    vector<int> diag2 = {0, 0};
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
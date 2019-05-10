class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int R = board.size(), C = board[0].size();
        bool todo = false;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                int v = abs(board[r][c]);
                if (v != 0 && v == abs(board[r][c+1]) && v == abs(board[r][c+2])) {
                    board[r][c] = board[r][c+1] = board[r][c+2] = -v;
                    todo = true;
                }
            }
        }
        for (int r = 0; r + 2 < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int v = abs(board[r][c]);
                if (v != 0 && v == abs(board[r+1][c]) && v == abs(board[r+2][c])) {
                    board[r][c] = board[r+1][c] = board[r+2][c] = -v;
                    todo = true;
                }
            }
        }

        for (int c = 0; c < C; ++c) {
            int wr = R - 1;
            for (int r = R-1; r >= 0; --r)
                if (board[r][c] > 0)
                    board[wr--][c] = board[r][c];
            while (wr >= 0)
                board[wr--][c] = 0;
        }

        return todo ? candyCrush(board) : board;
    }
};
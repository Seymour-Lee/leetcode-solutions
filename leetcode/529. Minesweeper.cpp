class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size() == 0) return board;
        int m = board.size();
        int n = board[0].size();
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1], m, n);
        return board;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'E') return;
        int counter = 0;
        if (i+1 < m && board[i+1][j] == 'M') counter++;
        if (i-1 >= 0 && board[i-1][j] == 'M') counter++;
        if (j+1 < n && board[i][j+1] == 'M') counter++;
        if (j-1 >= 0 && board[i][j-1] == 'M') counter++;
        if (i+1 < m && j+1 < n && board[i+1][j+1] == 'M') counter++;
        if (i+1 < m && j-1 >= 0 && board[i+1][j-1] == 'M') counter++;
        if (i-1 >= 0 && j+1 < n && board[i-1][j+1] == 'M') counter++;
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 'M') counter++;
        
        if(counter > 0){
            board[i][j] = '0' + counter;
            return;
        }
        board[i][j] = 'B';
        dfs(board, i-1, j-1, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i-1, j+1, m, n);
        dfs(board, i ,j-1, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i+1, j-1, m, n);
        dfs(board, i+1, j, m, n);
        dfs(board, i+1, j+1, m, n);
    }
};
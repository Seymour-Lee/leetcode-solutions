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

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& click) {
        v = vector<vector<bool>>(b.size(), vector<bool>(b[0].size(), false));
        dfs(b, click[0], click[1]);
        return b;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    vector<vector<bool>> v;
    
    void dfs(vector<vector<char>> &b, int i, int j){
        if(i < 0 || i >= b.size() || j < 0 || j >= b[i].size() || v[i][j]) return;
        v[i][j] = true;
        if(b[i][j] != 'M' && b[i][j] != 'E') return;
        if(b[i][j] == 'M'){
            b[i][j] = 'X';
            return;
        }
        int counter = 0;
        for(int r = i-1; r <= i+1; r++) for(int c = j-1; c <= j+1; c++){
            if(!(r < 0 || r >= b.size() || c < 0 || c >= b[i].size())){
                if(b[r][c] == 'M') counter++;
            }
        }
        if(counter != 0){
            b[i][j] = '0'+counter;
            return;
        }
        b[i][j] = 'B';
        for(auto dir: dirs) dfs(b, i+dir[0], j+dir[1]);
    }
};
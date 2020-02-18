class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        vector<vector<bool>> beflipped(board.size(), 
                                       vector<bool>(board[0].size(), true));
        for(int i = 0; i < board.size(); i++){
            if(i == 0 || i == board.size()-1){
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j] == 'O' && beflipped[i][j] == true) 
                        dfs(beflipped, board, i, j);
                }
            }
            else{
                if(board[i][0] == 'O' && beflipped[i][0] == true)
                    dfs(beflipped, board, i, 0);
                if(board[i][board[i].size()-1] == 'O' 
                   && beflipped[i][board[i].size()-1] == true)
                    dfs(beflipped, board, i, board[i].size()-1);
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(beflipped[i][j]) board[i][j] = 'X';
            }
        }
    }

private:
    void dfs(vector<vector<bool>> &beflipped, vector<vector<char>>& board,
             int i, int j){
        if(board[i][j] == 'X' || beflipped[i][j] == false) return;
        beflipped[i][j] = false;
        if(i-1 >= 0) dfs(beflipped, board, i-1, j);
        if(j-1 >= 0) dfs(beflipped, board, i, j-1);
        if(i+1 <=board.size()-1) dfs(beflipped, board, i+1, j);
        if(j+1 <= board[0].size()-1) dfs(beflipped, board, i, j+1);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        vector<int> p(m*n+1, -2);
        p[m*n] = -1;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                p[i*n+j] = -1;
                if(i == 0 || j == 0 || i == m-1 || j == n-1) u(p, i*n+j, m*n);
                if(i-1 >= 0 && board[i-1][j] == 'O') u(p, i*n+j, (i-1)*n+j);
                if(j-1 >= 0 && board[i][j-1] == 'O') u(p, i*n+j, i*n+j-1);
            }
        }
        int bp = f(p, m*n);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O' && f(p, i*n+j) != bp) board[i][j] = 'X';
        }
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        vector<int> p(m*n+1, -2);
        p[m*n] = -1;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                p[i*n+j] = -1;
                if(i == 0 || j == 0 || i == m-1 || j == n-1) u(p, i*n+j, m*n);
                if(i-1 >= 0 && board[i-1][j] == 'O') u(p, i*n+j, (i-1)*n+j);
                if(j-1 >= 0 && board[i][j-1] == 'O') u(p, i*n+j, i*n+j-1);
            }
        }
        int bp = f(p, m*n);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O' && f(p, i*n+j) != bp) board[i][j] = 'X';
        }
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        vector<int> p(m*n+1, -2);
        p[m*n] = -1;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                p[i*n+j] = -1;
                if(i == 0 || j == 0 || i == m-1 || j == n-1) u(p, i*n+j, m*n);
                if(i-1 >= 0 && board[i-1][j] == 'O') u(p, i*n+j, (i-1)*n+j);
                if(j-1 >= 0 && board[i][j-1] == 'O') u(p, i*n+j, i*n+j-1);
            }
        }
        int bp = f(p, m*n);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'O' && f(p, i*n+j) != bp) board[i][j] = 'X';
        }
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return p[x] = f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};
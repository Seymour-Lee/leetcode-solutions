class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if((i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.') 
                   && (board[i][j] == 'X')){
                    result++;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return 0;
        int m = board.size();
        int n = board[0].size();
        vector<int> p(m*n, -1);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(board[i][j] == 'X'){
                if(i+1 < m && board[i+1][j] == 'X') u(p, i*n+j, (i+1)*n+j);
                if(j+1 < n && board[i][j+1] == 'X') u(p, i*n+j, i*n+(j+1));
            }
            else p[i*n+j] = -2;
        }
        int ans = 0;
        for(auto e: p) ans += e == -1? 1: 0;
        return ans;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return p[x] = f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int px = f(p, x);
        int py = f(p, y);
        if(px != py) p[px] = py;
    }
};
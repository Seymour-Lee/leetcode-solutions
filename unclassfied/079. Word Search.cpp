class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string word, 
             int pos, int x, int y){
        if(pos == word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        if(board[x][y] != word[pos]) return false;
        char ch = board[x][y];
        board[x][y] = '#';
        bool result = dfs(board, word, pos+1, x+1, y) ||
                      dfs(board, word, pos+1, x-1, y) ||
                      dfs(board, word, pos+1, x, y+1) ||
                      dfs(board, word, pos+1, x, y-1);
        board[x][y] = ch;
        return result;
    }
};
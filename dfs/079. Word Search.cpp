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

class Solution {
public:
    bool exist(vector<vector<char>>& b, string word) {
        unordered_set<string> v;
        for(int i = 0; i < b.size(); i++) for(int j = 0; j < b[i].size(); j++) if(b[i][j] == word[0] && dfs(b, i, j, word, 0, v)) return true;
        return false;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool dfs(vector<vector<char>> &b, int i, int j, string str, int pos, unordered_set<string> &v){
        if(pos == str.size()) return true;
        if(i < 0 || i >= b.size() || j < 0 || j >= b[0].size()) return false;
        if(v.find(to_string(i)+","+to_string(j)) != v.end()) return false;
        if(b[i][j] != str[pos]) return false;
        v.insert(to_string(i)+","+to_string(j));
        for(auto dir: dirs){
            int ii = i+dir[0], jj = j+dir[1];
            if(dfs(b, ii, jj, str, pos+1, v)) return true;
        }
        v.erase(to_string(i)+","+to_string(j));
        return false;
    }
};
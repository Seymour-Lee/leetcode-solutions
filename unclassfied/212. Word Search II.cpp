class Trie{
public:
    Trie(){
        children = vector<Trie *>(26, nullptr);
        end = false;
    }
    
    void insert(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
    }
    
    bool search(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return node->end;
    }
    
    bool prefix(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return true;
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0 || board.size() == 0 || board[0].size() == 0) return {};
        Trie *trie = new Trie();
        for(auto str: words) trie->insert(str);
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<string> ans;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) 
            backtracking(board, visited, "", i, j, trie, ans);
        return vector<string>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(vector<vector<char>>& board, vector<vector<bool>> &visited,
                      string str, int i, int j, Trie *trie, unordered_set<string> &ans){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(visited[i][j]) return;
        str += board[i][j];
        if(trie->prefix(str) == false) return;
        if(trie->search(str)) ans.insert(str);
        visited[i][j] = true;
        backtracking(board, visited, str, i - 1, j, trie, ans);
        backtracking(board, visited, str, i + 1, j, trie, ans);
        backtracking(board, visited, str, i, j - 1, trie, ans);
        backtracking(board, visited, str, i, j + 1, trie, ans);
        visited[i][j] = false;
    }
};
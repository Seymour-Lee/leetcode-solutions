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
            node->prefixs.push_back(str);
            node = node->children[i];
        }
        node->prefixs.push_back(str);
        node->end = true;
    }
    
    vector<string> prefix(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) return {};
            node = node->children[i];
        }
        return node->prefixs;
    }
    
private:
    vector<Trie *> children;
    bool end;
    vector<string> prefixs;
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.size() == 0) return {};
        int n = words[0].size();
        Trie *trie = new Trie();
        for(auto str: words) trie->insert(str);
        vector<vector<string>> ans;
        for(auto word: words){
            backtracking(n, {word}, ans, trie);
        }
        return ans;
    }
    
private:
    void backtracking(int n, vector<string> cur, vector<vector<string>> &ans, Trie *trie){
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }
        string pre = "";
        int idx = cur.size();
        for(auto str: cur) pre += str[idx];
        vector<string> nexts = trie->prefix(pre);
        for(auto next: nexts){
            cur.push_back(next);
            backtracking(n, cur, ans, trie);
            cur.pop_back();
        }
    }
};



class Trie{
public:
    Trie(){
        children = vector<Trie *>(27, nullptr);
        end = false;
        times = 0;
    }
    
    void insert(string str, int plus){
        Trie *node = this;
        for(auto c: str){
            int i = (c == ' '? 26: c-'a');
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
        node->times += plus;
    }
    
    vector<string> search(string str){
        Trie *node = this;
        for(auto c: str){
            int i = (c == ' '? 26: c-'a');
            if(node->children[i] == nullptr) return {};
            node = node->children[i];
        }
        vector<pair<int, string>> res;
        dfs(node, res, "");
        for(auto &p: res) p.second = str + p.second;
        vector<string> ans;
        auto f = [](pair<int, string> a, pair<int, string> b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        sort(res.begin(), res.end(), f);
        if(res.size() > 3) ans = {res[0].second, res[1].second, res[2].second};
        else for(auto p: res) ans.push_back(p.second);
        return ans;
    }
    
private:
    vector<Trie *> children;
    bool end;
    int times;
    
    void dfs(Trie *root, vector<pair<int, string>> &ans, string cur){
        if(root == nullptr) return;
        if(root->end) ans.push_back({root->times, cur});
        for(int i = 0; i < 26; i++) if(root->children[i]) dfs(root->children[i], ans, cur+string(1, i+'a'));
        if(root->children[26]) dfs(root->children[26], ans, cur+" ");
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        trie = new Trie();
        last = "";
        for(int i = 0; i < sentences.size(); i++)
            trie->insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if(c == '#'){
            trie->insert(last, 1);
            last = "";
            return {};
        }
        last += c;
        return trie->search(last);
    }
    
private:
    Trie *trie;
    string last;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
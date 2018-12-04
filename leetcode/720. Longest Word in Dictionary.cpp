class Solution {
public:
    string longestWord(vector<string>& words) {
        string result = "";
        set<string> wordset;
        for (auto word: words) wordset.insert(word);
        for (auto word: words) {
            if (word.size() > result.length() || (word.size() == result.size() && word < result)) {
                bool good = true;
                for (int i = 1; i < word.size(); i++) {
                    if (wordset.find(word.substr(0, i)) == wordset.end()) {
                        good = false;
                        break;
                    }
                }
                if (good) result = word;
            }    
        }
        return result;
    }
};

class Trie {
public:
    Trie() {
        children = vector<Trie *>(nodes, nullptr);
        end = false;
    }
    
    void insert(string word){
        Trie * node = this;
        for(auto c: word){
            int i = c-'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node->end = false;
            node = node->children[i];
        }
        node->end = true;
    }
    
    bool prefix(string word){
        Trie * node = this;
        for(auto c: word){
            int i = c-'a';
            if(node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return node != nullptr;
    }
    
    string longest(){
        string ans = "";
        queue<pair<Trie *, string>> q;
        q.push({this, ""});
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                Trie *node = p.first;
                string str = p.second;
                if(node->end){
                    if(str.size() > ans.size()) ans = str;
                    continue;
                }
                for(int i = 0; i < node->children.size(); i++){
                    char ch = 'a' + i;
                    if(node->children[i] == nullptr) continue;
                    q.push({node->children[i], str+string(1, ch)});
                }
            }
        }
        return ans;
    }
private:
    vector<Trie *> children;
    bool end;
    const int nodes = 26;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        auto f = [](string a, string b){
            if(a.size() == b.size()) return a < b;
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), f);
        root = new Trie();
        for(auto w: words) if(root->prefix(w.substr(0, w.size()-1))) root->insert(w);
        return root->longest();
    }
    
private:
    Trie *root;
};


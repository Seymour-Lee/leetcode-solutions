class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string result = "";
        string word = "";
        istringstream is(sentence);
        vector<string> words;
        while(getline(is, word, ' ')){
            if(word != ""){
                words.push_back(word);
            }
        }
        set<string> st;
        for(auto d: dict) st.insert(d);
        for(auto w: words){
            string prefix = "";
            for(int i = 0; i <= w.size(); i++){
                prefix = w.substr(0, i);
                if(st.find(prefix) != st.end()) break;
            }
            if(result.size() > 0) result += " ";
            result += prefix;
        }
        return result;
    }
};

class Trie{
public:
    Trie(){
        children = vector<Trie *>(26, nullptr);
        end = false;
    }
    
    void insert(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c-'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
    }
    
    string search(string str){
        string ans = "";
        Trie *node = this;
        for(auto c: str){
            int i = c-'a';
            if(node->children[i]== nullptr || node->end) return node->end? ans: "";
            ans += string(1, c);
            node = node->children[i];
        }
        return node != nullptr && node->end? ans: "";
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *trie = new Trie();
        for(auto s: dict) trie->insert(s);
        istringstream is(sentence);
        string str;
        string ans = "";
        while(getline(is, str, ' ')){
            string replace = trie->search(str);
            ans += replace.size()? " "+replace: " "+str;
        }
        return ans.substr(1);
    }
};

class Trie{
public:
    Trie(): cs(vector<Trie *>(26, nullptr)), end(false) {}
    
    void insert(string &str){
        auto node = this;
        for(auto c: str){
            if(node->cs[c-'a'] == nullptr) node->cs[c-'a'] = new Trie();
            node = node->cs[c-'a'];
        }
        node->end = true;
    }

    string search(string &str){
        auto node = this;
        string ans = "";
        for(auto c: str){
            if(node && node->end) break;
            if(node) node = node->cs[c-'a'];
            ans += c;
        }
        return ans;
    }
    
private:
    vector<Trie *> cs;
    bool end;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *trie = new Trie();
        for(auto &str: dict) trie->insert(str);
        string ans = "";
        istringstream is(sentence);
        string str = "";
        while(getline(is, str, ' ')) ans += trie->search(str) + " ";
        ans.pop_back();
        return ans;
    }
};
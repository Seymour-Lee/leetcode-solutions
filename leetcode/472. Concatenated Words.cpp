class Trie{
public:
    Trie(){
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
    
    bool search(string str, int pos = 0, int count = 0){
        Trie *node = this;
        for(int p = pos; p < str.size(); p++){
            int i = str[p] - 'a';
            if(node->children[i] == nullptr) return false;
            if(node->children[i]->end){
                if(p == str.size()-1) return count >= 1;
                if(this->search(str, p+1, count+1)) return true;
            }
            node = node->children[i];
        }
        return false;
    }
    
    ~Trie(){
        for(auto kid: children) if(kid.second != nullptr){
            kid.second->~Trie();
            delete kid.second;
        } 
    }
private:
    unordered_map<int, Trie*> children;
    bool end;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size() == 0) return {};
        Trie *trie = new Trie();
        auto f = [](string a, string b){return a.size() < b.size();};
        sort(words.begin(), words.end(), f);
        vector<string> ans;
        for(auto str: words){
            if(trie->search(str)) ans.push_back(str);
            else trie->insert(str);
        }
        return ans;
    }
};
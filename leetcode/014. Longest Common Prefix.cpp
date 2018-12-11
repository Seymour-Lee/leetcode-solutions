class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string cur = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].substr(0, cur.size()) != cur){
                cur = cur.substr(0, cur.size()-1);
                if(cur == "") return "";
            }
        }
        
        return cur;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < min(ans.size(), strs[i].size()) && ans[j] == strs[i][j]) j++;
            ans = ans.substr(0, j);
        }
        return ans;
    }
};

class Trie{
public:
    Trie(){
        children = vector<Trie*>(26, nullptr);
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
    
    string longestPrefix(){
        string ans = "";
        Trie *node = this;
        while(node->end == false){
            int counter = 0;
            int next = -1;
            for(int i = 0 ; i < node->children.size(); i++){
                if(node->children[i]) counter++;
                if(node->children[i] && next == -1) next = i;
            }
            if(counter == 0 || counter > 1) break;
            ans += string(1, 'a'+next);
            node = node->children[next];
        }
        return ans;
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie();
        for(auto str: strs) trie->insert(str);
        return trie->longestPrefix();
    }
};
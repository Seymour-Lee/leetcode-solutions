class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        cs = vector<Trie *>(26, nullptr);
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for(auto c: word){
            if(node->cs[c-'a'] == nullptr) node->cs[c-'a'] = new Trie();
            node = node->cs[c-'a'];
            node->pq.push(word);
            if(node->pq.empty() == false && node->pq.size() > 3) node->pq.pop();
        }
        node->end = true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    vector<vector<string>> startsWith(string prefix) {
        vector<vector<string>> ans;
        auto node = this;
        for(auto c: prefix){
            if(node->cs[c-'a'] == nullptr) return ans;
            node = node->cs[c-'a'];
            vector<string> cur = {};
            while(node->pq.size()){
                cur.push_back(node->pq.top());
                node->pq.pop();
            }
            for(auto str: cur) node->pq.push(str);
            ans.push_back(vector<string>(cur.rbegin(), cur.rend()));
        }
        return ans;
    }
    
private:
    vector<Trie *> cs;
    priority_queue<string, vector<string>> pq;
    bool end;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *trie = new Trie();
        for(auto str: products) trie->insert(str);
        cout<<"a";
        vector<vector<string>> ans = trie->startsWith(searchWord);
        while(ans.size() != searchWord.size()) ans.push_back({});
        return ans;
    }
};
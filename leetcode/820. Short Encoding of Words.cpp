class TrieNode{
public:
    vector<TrieNode *> children;
    int count;
    TrieNode(){
        children = vector<TrieNode *>(26);
        count = 0;
    }
    
    TrieNode *get(char c){
        if(children[c-'a'] == nullptr){
            children[c-'a'] = new TrieNode();
            count++;
        }
        return children[c-'a'];
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        TrieNode *trie = new TrieNode();
        map<TrieNode *, int> node2idx;
        for(int i = 0; i < words.size(); i++){
            TrieNode *cur = trie;
            string word = words[i];
            for(int j = word.size()-1; j >= 0; j--){
                cur = cur->get(word[j]);
            }
            node2idx[cur] = i;
        }
        for(auto it: node2idx){
            if(it.first->count == 0){
                ans += words[it.second].size()+1;
            }
        }
        return ans;
    }
};
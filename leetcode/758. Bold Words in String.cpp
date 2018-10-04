class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        TrieNode *root = new TrieNode;
        for(auto word: words){
            TrieNode *node = root;
            for(decltype(S.size()) i = 0; i < word.size(); i++){
                int idx = word[i] - 'a';
                if(node->children[idx] == nullptr){
                    node->children[idx] = new TrieNode;
                }
                node = node->children[idx];
            }
            node->isWord = true;
        }
        
        vector<vector<int>> intervals;
        for(decltype(S.size()) i = 0; i < S.size(); i++){
            TrieNode *node = root;
            for(decltype(S.size()) j = i; j < S.size(); j++){
                int idx = S[j] - 'a';
                if(node->children[idx] == nullptr) break;
                node = node->children[idx];
                if(node->isWord){
                    vector<int> interval = {i, j};
                    intervals.push_back(interval);
                }
            }
        }
        
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while((i < intervals.size()-1) && (intervals[i+1][0]-1 <= end)){
                end = max(end, intervals[i+1][1]);
                i++;
            }
            merged.push_back({start, end});
        }
        
        if(merged.empty() == true) return S;
        
        string ans = "";
        int curpos = 0;
        vector<int> curinterval = merged[curpos];
        for(int i = 0; i < S.size(); i++){
            if(i == curinterval[0]) ans += "<b>";
            ans.push_back(S[i]);
            if(i == curinterval[1]){
                ans += "</b>";
                if(curpos < merged.size()-1){
                    curinterval = merged[++curpos];
                }
                else{
                    curinterval = {-1, -1};
                }
            }
        }
        return ans;
    }
    
private:
    struct TrieNode{
        bool isWord;
        vector<TrieNode *> children;
        TrieNode(): isWord(false), children(26){}
    };
};
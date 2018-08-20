class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 1;
        set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        set<string> beginst{beginWord};
        set<string> visited{beginWord};
        int result = 1;
        while(beginst.empty() == false){
            set<string> next{};
            for(auto w: beginst){
                for(int i = 0; i < w.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        char old = w[i];
                        w[i] = c;
                        if(w == endWord) return result+1;
                        if(visited.find(w) == visited.end() 
                           && dict.find(w) != dict.end()){
                            next.insert(w);
                            visited.insert(w);
                        }
                        w[i] = old;
                    }
                }
            }
            beginst = next;
            result++;
        }
        return 0;
    }
};
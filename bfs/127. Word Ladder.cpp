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

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        unordered_set<string> seen;
        queue<string> q;
        q.push(beginWord);
        seen.insert(beginWord);
        unordered_set<string> strs(wordList.begin(), wordList.end());
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                string cur = q.front(); q.pop();
                if(cur == endWord) return ans;
                for(int i = 0; i < cur.size(); i++){
                    char prev = cur[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        cur[i] = c;
                        if(seen.find(cur) == seen.end() && strs.find(cur) != strs.end()){
                            q.push(cur);
                            seen.insert(cur);
                        }
                    }
                    cur[i] = prev;
                }
            }
            ans++;
        }
        return 0;
    }
};
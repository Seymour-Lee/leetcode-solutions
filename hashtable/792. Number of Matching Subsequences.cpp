class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int result = 0;
        map<string, bool> sub2right;
        for(auto word: words){
            if(sub2right.find(word) == sub2right.end()){
                sub2right[word] = isSubsequence(word, S);
            }
            result += sub2right[word]? 1: 0;
        }
        return result;
    }
    
private:
    bool isSubsequence(string w, string s){
        int i = 0, j = 0;
        while(i < w.size() && j < s.size()){
            if(w[i] == s[j]) i++;
            j++;
        }
        return i == w.size();
    }
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int result = 0;
        unordered_map<string, bool> sub2right;
        for(auto word: words){
            if(sub2right.find(word) == sub2right.end()){
                sub2right[word] = isSubsequence(word, S);
            }
            result += sub2right[word]? 1: 0;
        }
        return result;
    }
    
private:
    bool isSubsequence(string w, string s){
        int i = 0, j = 0;
        while(i < w.size() && j < s.size()){
            if(w[i] == s[j]) i++;
            j++;
        }
        return i == w.size();
    }
};
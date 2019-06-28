class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) str2idx[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        auto idx1 = str2idx[word1];
        auto idx2 = str2idx[word2];
        int i = 0, j = 0;
        if(idx1[i] < idx2[j]) ans = min(ans, idx2[j]-idx1[i++]);
        else ans = min(ans, idx1[i]-idx2[j++]);
        while(i < idx1.size() && j < idx2.size()){
            if(idx1[i] < idx2[j]) ans = min(ans, idx2[j]-idx1[i++]);
            else ans = min(ans, idx1[i]-idx2[j++]);
        }
        return ans;
    }
    
private:
    unordered_map<string, vector<int>> str2idx;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) str2pos[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> &a = str2pos[word1];
        vector<int> &b = str2pos[word2];
        int i = 0, j = 0;
        int ans = INT_MAX;
        while(i < a.size() && j < b.size()){
            ans = min(ans, abs(a[i]-b[j]));
            if(a[i] < b[j]) i++;
            else j++;
        }
        return ans;
    }
    
private:
    unordered_map<string, vector<int>> str2pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
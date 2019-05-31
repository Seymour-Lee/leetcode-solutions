class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.size() < 2) return INT_MAX;
        int ans = INT_MAX;
        int i = 0, j = 1;
        while(i < words.size() && words[i] != word1 && words[i] != word2) i++;
        j = i + 1;
        while(j < words.size()){
            string target = words[i] == word1? word2: word1;
            while(j < words.size() && words[j] != target) j++;
            if(j >= words.size()) break;
            ans = min(ans, j-i);
            i++;
            while(i < words.size() && words[i] != word1 && words[i] != word2) i++;
            if(i >= words.size()) break;
            j = i + 1;
        }
        return ans;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        int prev = -words.size()-1;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1) prev = i;
            if(words[i] == word2) ans = min(ans, i-prev);
        }
        prev = 2*(words.size()+1);
        for(int i = words.size()-1; i >= 0; i--){
            if(words[i] == word1) prev = i;
            if(words[i] == word2) ans = min(ans, prev-i);
        }
        return ans;
    }
};
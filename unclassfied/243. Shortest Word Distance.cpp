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
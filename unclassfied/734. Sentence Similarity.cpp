class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, 
                             vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        set<string> pairset;
        for(auto p: pairs) pairset.insert(p.first + "#" + p.second);
        for(int i = 0; i < words1.size(); i++){
            if(words1[i] != words2[i] && 
               pairset.find(words1[i] + "#" + words2[i]) == pairset.end() &&
               pairset.find(words2[i] + "#" + words1[i]) == pairset.end())
                return false;
        }
        return true;
    }
};
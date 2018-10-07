class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, 
                                vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        map<string, string> str2str;
        for(auto p: pairs){
            string parent1 = find(str2str, p.first), parent2 = find(str2str, p.second);
            if (parent1 != parent2) str2str[parent1] = parent2;
        }
        for(int i = 0; i < words1.size(); i++){
            if(words1[i] != words2[i] && 
               find(str2str, words1[i]) != find(str2str, words2[i])) return false;
        }
        return true;
    }
    
private:
    string find(map<string, string>& m, string s) {
        return m.count(s) == 0 ? m[s] = s : (m[s] == s ? s : find(m, m[s]));
    }
};
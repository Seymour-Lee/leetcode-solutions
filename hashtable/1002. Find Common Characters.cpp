class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> stat(26, INT_MAX);
        for(auto str: A){
            vector<int> cur = vector<int>(26, 0);
            for(auto c: str) cur[c-'a']++;
            for(int i = 0; i < 26; i++) stat[i] = min(stat[i], cur[i]);
        }
        vector<string> ans;
        for(int i = 0; i < stat.size(); i++) if(stat[i] != 0){
            while(stat[i]--) ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> minval(26, INT_MAX);
        for(auto &str: A){
            vector<int> counter(26, 0);
            for(auto c: str) counter[c-'a']++;
            for(int i = 0; i < 26; i++) minval[i] = min(minval[i], counter[i]);
        }
        for(int i = 0; i < 26; i++) while(minval[i]--) ans.push_back(string(1, i+'a'));
        return ans;
    }
};
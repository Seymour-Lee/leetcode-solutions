class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ans;
        vector<int> prefix(n, 0);
        for(auto str: dict) ans.push_back(abbrev(str, 0));
        for(int i = 0; i < n; i++){
            while(true){
                set<int> dupes;
                for(int j = i+1; j < n; j++){
                    if(ans[i] == ans[j]) dupes.insert(j);
                }
                if(dupes.empty()) break;
                dupes.insert(i);
                for(auto k: dupes) ans[k] = abbrev(dict[k], ++prefix[k]);
            }
        }
        return ans;
    }
    
private:
    string abbrev(string str, int i){
        int n = str.size();
        if(n-1-i <= 2) return str;
        return str.substr(0, i+1) + to_string(n-i-2) + string(1, str[n-1]);
    }
};
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> strs;
        istringstream is(text);
        string str;
        while(getline(is, str, ' ')) strs.push_back(str);
        vector<string> ans;
        for(int i = 0; i+2 < strs.size(); i++) if(strs[i] == first && strs[i+1] == second) ans.push_back(strs[i+2]);
        return ans;
    }
};
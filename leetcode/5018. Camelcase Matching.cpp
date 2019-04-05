class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto q: queries){
            int i = 0;
            bool upper = false;
            for(auto c: q){
                // if(i == pattern.size()) break;
                if(i < pattern.size() && pattern[i] == c) i++;
                else{
                    if('A' <= c && c <= 'Z') upper = true;
                }
            }
            // cout<<i<<endl;
            if(i == pattern.size() && upper == false) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
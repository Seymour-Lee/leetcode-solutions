class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto f = [](const string a, const string b){return a.size() > b.size();};
        sort(strs.begin(), strs.end(), f);
        set<string> dups = getDups(strs);
        for(int i = 0; i < strs.size(); i++){
            if(dups.find(strs[i]) == dups.end()){
                if(i == 0) return strs[i].size();
                for(int j = 0; j < i; j++){
                    if(isSubsequence(strs[j], strs[i])) break;
                    if(j == i-1) return strs[i].size();
                }
            }
        }
        return -1;
    }
    
private:
    set<string> getDups(vector<string> strs){
        set<string> st;
        set<string> dups;
        for(auto str: strs){
            if(st.find(str) != st.end()) dups.insert(str);
            st.insert(str);
        }
        return dups;
    }
    
    bool isSubsequence(string a, string b){
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]) j++;
            i++;
        }
        return j == b.size();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string cur = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].substr(0, cur.size()) != cur){
                cur = cur.substr(0, cur.size()-1);
                if(cur == "") return "";
            }
        }
        
        return cur;
    }
};
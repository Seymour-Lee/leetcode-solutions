class Solution {
public:
    vector<string> permute(string S) {
        vector<string> ans = {""};
        vector<char> cur = {};
        bool b = false;
        for(auto c: S){
            if(b == false){
                if(c == '{') b = true;
                else{
                    for(auto &str: ans) str += c;
                }
            }
            else{
                if(c == '}'){
                    b = false;
                    vector<string> next;
                    for(auto ch: cur){
                        for(auto str: ans){
                            next.push_back(str + ch);
                        }
                    }
                    ans = next;
                    cur = {};
                }
                else if(c == ','){
                    continue;
                }
                else cur.push_back(c);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
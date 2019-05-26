class Solution {
public:
    string removeDuplicates(string S) {
        string ans = S;
        while(ans.size() > 1){
            string cur = ans;
            ans = "";
            for(auto c: cur){
                if(ans == "" || ans.back() != c) ans += c;
                else ans.pop_back();
            }
            if(ans.size() == cur.size()) break;
        }
        return ans;
    }
};
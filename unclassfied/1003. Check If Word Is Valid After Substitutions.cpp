class Solution {
public:
    bool isValid(string S) {
        string ans = "";
        for(auto c: S){
            if(c == 'a'){
                ans += c;
            }
            else if(c == 'b'){
                ans += c;
            }
            else if(c == 'c'){
                if(ans.size() >= 2 && ans.substr(ans.size()-2) == "ab") ans = ans.substr(0, ans.size()-2);
                else return false;
            }
        }
        return ans.empty();
    }
};
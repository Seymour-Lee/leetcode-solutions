class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        for(auto c: num){
            while(result.size() && result.back() > c && k){
                result.pop_back();
                k--;
            }
            if(result.size() || c != '0') result.push_back(c);
        }
        while(result.size() && k--) result.pop_back();
        return result.empty()? "0": result;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(auto c: num){
            while(k > 0 && ans.size() && ans.back() > c) ans.pop_back(), k--;
            ans.push_back(c);
        }
        while(k > 0 && ans.size()) ans.pop_back(), k--;
        int pos = 0;
        while(pos < ans.size() && ans[pos] == '0') pos++;
        if(ans.size()) ans = ans.substr(pos);
        return ans.size()? ans: "0";
    }
};
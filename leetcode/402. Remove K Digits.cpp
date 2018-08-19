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
class Solution {
public:
    string makeLargestSpecial(string S) {
        if(S.size() == 0) return "";
        vector<string> strs;
        int counter = 0;
        for(int i = 0, j = 0; j < S.size(); j++){
            S[j] == '1'? counter++: counter--;
            if(counter == 0){
                strs.push_back('1' + makeLargestSpecial(S.substr(i+1, j-i-1)) + '0');
                i = j + 1;
            }
        }
        auto f = [](string a, string b){return a > b;};
        sort(strs.begin(), strs.end(), f);
        string ans = "";
        for(auto str: strs) ans += str;
        return ans;
    }
};
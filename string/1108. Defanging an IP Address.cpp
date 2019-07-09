class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        istringstream is(address);
        string str;
        while(getline(is, str, '.')) ans += str + "[.]";
        ans.pop_back();ans.pop_back();ans.pop_back();
        return ans;
    }
};
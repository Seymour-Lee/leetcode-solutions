class Solution {
    static bool cmp(string s1, string s2){
        return s1+s2 > s2+s1;
    }
public:    
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        string result;
        vector<string> strs;
        for(auto num: nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), cmp);
        if(*strs.begin() == "0") return "0";
        for(auto str: strs) result += str;
        return result;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto num: nums) strs.push_back(to_string(num));
        auto f = [](string a, string b){return a+b > b+a;};
        sort(strs.begin(), strs.end(), f);
        if(*strs.begin() == "0") return "0";
        string ans = "";
        for(auto str: strs) ans += str;
        return ans;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto num: nums) strs.push_back(to_string(num));
        auto f = [](string a, string b){
            return a+b > b+a;
        };
        sort(strs.begin(), strs.end(), f);
        string ans = "";
        for(auto str: strs) ans += str;
        return strs[0] == "0"? "0": ans;
    }
};
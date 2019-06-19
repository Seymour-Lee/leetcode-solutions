class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>{};
        vector<string> result{""};
        map<char, string> num2chars;
        num2chars['2'] = "abc"; num2chars['3'] = "def";
        num2chars['4'] = "ghi"; num2chars['5'] = "jkl";
        num2chars['6'] = "mno"; num2chars['7'] = "pqrs";
        num2chars['8'] = "tuv"; num2chars['9'] = "wxyz";
        for(auto d: digits){
            vector<string> cur = result;
            result.clear();
            for(auto ans: cur){
                string str = num2chars[d];
                for(auto ch: str){
                    result.push_back(ans + ch);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string> i2s = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        vector<string> ans = {""};
        for(auto d: digits){
            vector<string> prev = ans;
            ans = {};
            for(auto c: i2s[d]) for(auto str: prev) ans.push_back(str + c);
        }
        return ans;
    }
};
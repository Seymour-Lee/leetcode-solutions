class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        auto cmp = [](string a, string b){
            return a.size() == b.size()? a < b: a.size() > b.size();
        };
        sort(d.begin(), d.end(), cmp);
        for(auto sub: d){
            if(isSubsequence(sub, s)) return sub;
        }
        return "";
    }
    
private:
    bool isSubsequence(string sub, string str){
        int j = 0;
        for(int i = 0; i < str.size() && j < sub.size(); i++){
            if(sub[j] == str[i]) j++;
        }
        return j == sub.size();
    }
};
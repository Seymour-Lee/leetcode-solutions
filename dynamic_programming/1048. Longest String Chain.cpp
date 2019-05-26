class Solution {
public:
    int longestStrChain(vector<string>& words) {
        auto f = [](string a, string b){
            return a.size() < b.size();
        };
        auto v = [](string a, string b){
            if(a.size()+1 != b.size()) return false;
            int i = 0, j = 0;
            while(i < a.size() && j < b.size()){
                if(a[i] == b[j]) i++, j++;
                else j++;
            }
            return i == a.size() && (j == b.size() || j == b.size()-1);
        };
        sort(words.begin(), words.end(), f);
        vector<int> dp(words.size(), 1);
        for(int i = 0; i < words.size(); i++) for(int j = 0; j < i; j++){
            if(v(words[j], words[i])) dp[i] = max(dp[i], dp[j]+1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        int n = S.size();
        string result = "";
        for(auto c: S) count[c-'a']++;
        vector<pair<int, char>> freq2ch;
        for(int i = 0; i < 26; i++){
            if(count[i] > (n+1)/2) return "";
            if(count[i]) freq2ch.push_back({count[i], i+'a'});
        }
        sort(freq2ch.rbegin(), freq2ch.rend());
        string sorted = "";
        for(auto p: freq2ch) sorted += string(p.first, p.second);
        for(int i = 0, j = (n-1)/2+1; i <= (n-1)/2; i++, j++){
            result += sorted[i];
            if(j < n) result += sorted[j];
        }
        return result;
    }
};
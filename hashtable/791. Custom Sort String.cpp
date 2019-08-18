class Solution {
public:
    string customSortString(string S, string T) {
        if(T == "") return ""; 
        if(S == "") return T;
        vector<int> stat(26, 0);
        for(auto c: T) stat[c-'a']++;
        string result;
        for(auto c: S){
            result += string(stat[c-'a'], c);
            stat[c-'a'] = 0;
        }
        for(int i = 0; i < stat.size(); i++)  result += string(stat[i], i+'a');
        return result;
    }
};

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> c2p;
        for(int i = 0; i < S.size(); i++) c2p[S[i]] = i;
        auto f = [&](char a, char b){
            return c2p[a] < c2p[b];
        };
        sort(T.begin(), T.end(), f);
        return T;
    }
};
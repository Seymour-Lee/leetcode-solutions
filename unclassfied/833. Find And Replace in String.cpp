class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources,
                             vector<string>& targets) {
        if(indexes.size() == 0) return "";
        string ans = "";
        vector<pair<int, int>> sorted;
        for(int i = 0; i < indexes.size(); i++)
            sorted.push_back({indexes[i], i});
        sort(sorted.rbegin(), sorted.rend());
        for(auto cur: sorted){
            int i = cur.first;
            string s = sources[cur.second], t = targets[cur.second];
            if(S.substr(i, s.size()) == s) S = S.substr(0, i) + t + S.substr(i+s.size());
        }
        return S;
    }
};
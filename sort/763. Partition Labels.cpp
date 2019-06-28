class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        map<char, pair<int, int>> table;
        for(int i = 0; i < S.size(); i++){
            if(table.find(S[i]) == table.end()){
                table[S[i]] = pair<int, int>(i, i);
            }
            else{
                table[S[i]].second = i;
            }
        }
        int start = 0, end = table[S[0]].second;
        for(int i = 0; i < S.size(); i++){
            if(i == end){
                result.push_back(end - start + 1);
                start = i + 1;
                if(start < S.size()) end = table[S[start]].second;
            }
            else if(table[S[i]].second > end){
                end = table[S[i]].second;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> s(26, S.size()), e(26, -1);
        for(int i = 0; i < S.size(); i++){
            s[S[i]-'a'] = min(s[S[i]-'a'], i);
            e[S[i]-'a'] = max(e[S[i]-'a'], i);
        }
        vector<pair<int, int>> intervals;
        for(int i = 0; i < s.size(); i++) if(e[i] != -1) intervals.push_back({s[i], e[i]});
        auto f = [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        };
        sort(intervals.begin(), intervals.end(), f);
        vector<pair<int, int>> stk; 
        for(auto p: intervals){
            // cout<<p.first<<" "<<p.second<<endl;
            while(stk.empty() == false && stk.back().second > p.first){
                p.first = min(p.first, stk.back().first);
                stk.pop_back();
            }
            stk.push_back(p);
        }
        for(auto p: stk) ans.push_back(p.second-p.first+1);
        return ans;
    }
};
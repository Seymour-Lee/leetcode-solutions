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


class Solution {
public:
    string reorganizeString(string S) {
        vector<int> c2t(26, 0);
        for(auto c: S) if((++c2t[c-'a']) > (S.size()+1)/2) return "";
        using ii = pair<char, int>;
        auto f = [](ii a, ii b) {return a.second < b.second;};
        priority_queue<ii, vector<ii>, function<bool(ii, ii)>> q(f);
        for(int i = 0; i < c2t.size(); i++) if(c2t[i]) q.push({'a'+i, c2t[i]});
        string ans = "";
        while(q.empty() == false){
            auto p = q.top(); q.pop();
            if(ans.size() && ans.back() == p.first){
                if(q.empty()) return "";
                auto pp = q.top(); q.pop();
                swap(p, pp);
                q.push(pp);
            }
            ans += p.first;
            p.second--;
            if(p.second) q.push(p);
        }
        return ans;
    }
};
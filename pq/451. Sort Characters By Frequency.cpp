class Solution {
public:
    string frequencySort(string s) {
        string result;
        map<char, int> c2t;
        for(auto c: s) c2t[c]++;
        map<int, string> t2c;
        for(auto e: c2t) t2c[e.second] += e.first;
        for(map<int, string>::reverse_iterator ritor = t2c.rbegin();
            ritor != t2c.rend(); ritor++){
            for(auto c: ritor->second) result += string(ritor->first, c);
        }
        return result;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> c2t;
        for(auto c: s) c2t[c]++;
        using ii = pair<int, int>;
        auto f = [](ii a, ii b){
            return a.second < b.second;
        };
        priority_queue<ii, vector<ii>, function<bool(ii, ii)>> pq(f);
        for(auto p: c2t) pq.push({p.first, p.second});
        while(pq.empty() == false) ans += string(pq.top().second, pq.top().first), pq.pop();
        return ans;
    }
};
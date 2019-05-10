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
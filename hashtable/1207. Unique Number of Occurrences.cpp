class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> a2c;
        for(auto a: arr) a2c[a]++;
        unordered_set<int> v;
        for(auto [a, c]: a2c){
            if(v.find(c) != v.end()) return false;
            v.insert(c);
        }
        return true;
    }
};
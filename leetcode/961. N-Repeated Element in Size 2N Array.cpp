class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> num2times;
        for(auto a: A) num2times[a]++;
        for(auto p: num2times) if(p.second > 1) return p.first;
        return -1;
    }
};
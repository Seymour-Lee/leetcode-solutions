class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> num2times;
        for(auto a: A) for(auto b: A) num2times[a&b]++;
        int ans = 0;
        for(auto &p: num2times) for(auto a: A) if((p.first&a) == 0) ans += num2times[p.first];
        return ans;
    }
};


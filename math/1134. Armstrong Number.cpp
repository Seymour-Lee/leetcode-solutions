class Solution {
public:
    bool isArmstrong(int N) {
        int ans = 0;
        string num = to_string(N);
        int k = num.size();
        for(auto n: num) ans += pow(n-'0', k);
        return ans == N;
    }
};
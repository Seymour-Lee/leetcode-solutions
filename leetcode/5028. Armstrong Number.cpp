class Solution {
public:
    bool isArmstrong(int N) {
        int ans = 0;
        string str = to_string(N);
        int k = str.size();
        for(auto c: str) ans += pow(c-'0', k);
        return ans == N;
    }
};

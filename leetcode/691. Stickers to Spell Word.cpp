class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int N = target.size();
        vector<int> dp(1<<N, -1);
        dp[0] = 0;
        for (int state = 0; state < 1 << N; state++) {
            if (dp[state] == -1) continue;
            for (auto sticker: stickers) {
                int now = state;
                for (char letter: sticker) {
                    for (int i = 0; i < N; i++) {
                        if (((now >> i) & 1) == 1) continue;
                        if (target[i] == letter) {
                            now |= 1 << i;
                            break;
                        }
                    }
                }
                if (dp[now] == -1 || dp[now] > dp[state] + 1) {
                    dp[now] = dp[state] + 1;
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
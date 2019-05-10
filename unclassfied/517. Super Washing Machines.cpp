class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + machines[i];
        if (sum[n] % n) return -1;
        int avg = sum[n] / n;
        int ans = 0;
        for (int i = 0; i < n; ++i){
            int l = i * avg - sum[i];
            int r = (n - i - 1) * avg - (sum[n] - sum[i+1]);
            if (l > 0 && r > 0) ans = max(ans, abs(l) + abs(r));
            else ans = max(ans, max(abs(l), abs(r)));
        }
        return ans;
    }
};
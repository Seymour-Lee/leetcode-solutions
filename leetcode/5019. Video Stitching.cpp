class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
		int minval = INT_MAX;
		int maxval = 0;
		for (auto i : clips) minval = min(minval, i[0]), maxval = max(maxval, i[1]);
        if(minval > 0 || maxval < T) return -1;
		vector<int> dp(maxval+ 1, 0);
		for (auto i : clips) dp[i[0]] = max(dp[i[0]], i[1]-i[0]);
		int reach = dp[0];
		int maxreach = 0;
		int ans = 1;
		for (int i = 0; i < dp.size(); i++) {
			if (reach >= T) break;
			maxreach = max(maxreach, i + dp[i]);
			if (reach <= i) reach = maxreach, ans++;		
		}
		return reach >= T? ans : -1;
    }
};
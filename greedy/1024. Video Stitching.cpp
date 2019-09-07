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

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        auto f = [](vector<int> a, vector<int> b){
            return a[0] == b[0]? a[1] > b[1]: a[0] < b[0];
        };
        sort(clips.begin(), clips.end(), f);
        int ans = 0, end = 0, covered = 0;
        for(auto c: clips){
            if(covered >= T) break;
            if(c[0] > covered) return -1;
            if(c[0] >= end) ans++, end = c[1];
            covered = max(covered, c[1]);
        }
        if(end < T && covered >= T) ans++;
        return covered >= T? ans: -1;
    }
};
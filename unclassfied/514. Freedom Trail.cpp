class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int N = ring.size();
        unordered_map<char, vector<int>> indexMap;
        for (int i = 0; i < N; ++i) {
            indexMap[ring[i]].push_back(i);
        }
        
        vector<vector<pair<int, int>>> dp(key.size());
        for (int i : indexMap[key[0]]) {
            int dist = min(i, N - i);
            dp[0].push_back({i, dist});
        }
        
        int minOverall = INT_MAX;
        
        for (int i = 1; i < key.size(); ++i) {
            for (int idx : indexMap[key[i]]) {
                int minDist = INT_MAX;
                for (auto& pair : dp[i - 1]) {
                    int absDist = abs(pair.first - idx);
                    int dist = min(absDist, N - absDist);
                    minDist = min(minDist, dist + pair.second);
                }
                dp[i].push_back({idx, minDist});
                if (i == key.size() - 1) minOverall = min(minDist, minOverall);
            }
        }
        
        return minOverall + key.size();
    }
};
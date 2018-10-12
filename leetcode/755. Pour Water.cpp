class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        while (V--) {
            int j = K;
            for (int i = K - 1; i >= 0; i--) {
                if (heights[i] > heights[j]) break;
                else if (heights[i] < heights[j]) j = i;
            }
            if (j == K) {
                for (int i = K + 1; i < n; i++) {
                    if (heights[i] > heights[j]) break;
                    else if (heights[i] < heights[j]) j = i;
                }
            }
            heights[j]++;
        }
        
        return heights;
    }
};
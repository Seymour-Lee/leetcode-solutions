class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> result = {cost[0], cost[1]};
        for(int i = 2; i < cost.size(); i++){
            result.push_back(min(result[i - 1], result[i - 2]) + cost[i]);
        }
        return min(result[result.size() - 1], result[result.size() - 2]);
    }
};
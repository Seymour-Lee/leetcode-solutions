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

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 2) return *min_element(cost.begin(), cost.end());
        int prev2 = cost[0], prev1 = cost[1];
        for(decltype(cost.size()) i = 2; i < cost.size(); i++){
            int minval = min(prev1, prev2) + cost[i];
            prev2 = prev1, prev1 = minval;
        }
        return min(prev2, prev1);
    }
};
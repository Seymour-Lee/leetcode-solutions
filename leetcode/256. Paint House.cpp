class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        for(int i = 1; i < costs.size(); i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
            cout<<costs[i][0]<<" "<<costs[i][1]<<" "<<costs[i][2]<<endl;
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        vector<int> dp = costs[0];
        for(decltype(costs.size()) i = 1; i < costs.size(); i++){
            int zer = dp[0], one = dp[1], two = dp[2];
            dp[0] = min(one, two) + costs[i][0];
            dp[1] = min(zer, two) + costs[i][1];
            dp[2] = min(zer, one) + costs[i][2];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
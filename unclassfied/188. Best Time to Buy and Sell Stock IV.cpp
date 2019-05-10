class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k = min(k, (int)prices.size());
        vector<int> buy(k+1, 0);
        vector<int> sell(k+1, INT_MIN);
        for(auto p: prices){
            for(int i = k; i > 0; i--){
                buy[i] = max(buy[i], sell[i]+p);
                sell[i] = max(sell[i], buy[i-1]-p);
            }
        }
        return buy.back();
    }
};
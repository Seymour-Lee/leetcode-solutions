class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ans = 0;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
             ans = max(ans, sell[i]);
            if(i == 1) 
                buy[i] = buy[0] + prices[0] - prices[1];
            else
                buy[i] = max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);
        }
        return ans;
    }
};
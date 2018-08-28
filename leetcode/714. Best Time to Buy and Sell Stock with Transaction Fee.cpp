class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        vector<int> sold(prices.size(), 0);
        vector<int> hold(prices.size(), -prices[0]);
        for(int i = 1; i < prices.size(); i++){
            sold[i] = max(sold[i-1], hold[i-1] + prices[i] - fee);
            hold[i] = max(hold[i-1], sold[i-1] - prices[i]);
        }
        return sold.back();
    }
};
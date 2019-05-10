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

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        int without = 0;
        int with = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            without = max(without, prices[i]+with-fee);
            with = max(with, without-prices[i]);
        }
        return without;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        vector<int> cash(prices.size(), 0);
        vector<int> hold(prices.size(), -prices[0]);
        for(int i = 1; i < prices.size(); i++){
            cash[i] = max(cash[i-1], hold[i-1]+prices[i]-fee);
            hold[i] = max(hold[i-1], cash[i-1]-prices[i]);
        }
        return cash.back();
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        vector<int> buy(prices.size(), -prices[0]);
        vector<int> sell(prices.size(), 0);
        for(int i = 1; i < prices.size(); i++){
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
        }
        return sell.back();
    }
};
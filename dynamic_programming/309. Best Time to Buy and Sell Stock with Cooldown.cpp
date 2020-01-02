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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
            if(i == 1) buy[i] = buy[0] + prices[0] - prices[1];
            else buy[i] = max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);
        }
        return *max_element(sell.begin(), sell.end());
    }
};

class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.size() <= 1) return 0;
        int n = p.size();
        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        hold[0] = -p[0];
        hold[1] = max(-p[0], -p[1]);
        sold[1] = max(0, p[1]-p[0]);
        for(int i = 2; i < p.size(); i++){
            hold[i] = max(hold[i-1], sold[i-2]-p[i]);
            sold[i] = max(sold[i-1], hold[i-1]+p[i]);
        }
        return sold[n-1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int cool = 0;
        for(auto p: prices){
            int nh = max(hold, sold-p);
            int ns = max({sold, cool});
            int nc = hold+p;
            hold = nh, sold = ns, cool = nc;
        }
        return max(sold, cool);
    }
};
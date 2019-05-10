class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[i-1] > 0) result += prices[i] - prices[i-1];
        }
        return result;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) 
            ans += prices[i]>prices[i-1]? prices[i]-prices[i-1]:0;
        return ans;
    }
};
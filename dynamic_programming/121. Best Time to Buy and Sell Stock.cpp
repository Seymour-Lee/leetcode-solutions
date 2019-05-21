class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(auto cur: prices){
            if(cur < minPrice){
                minPrice = cur;
            }
            else if(cur - minPrice > maxProfit){
                maxProfit = cur - minPrice;
            }
        }
        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int ans = 0;
        int maxval = prices.back();
        for(int i = prices.size()-2; i >= 0; i--){
            if(prices[i] < maxval) 
                ans = max(ans, maxval-prices[i]);
            else
                maxval = max(maxval, prices[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int ans = 0;
        int minval = prices.front();
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minval) minval = prices[i];
            else ans = max(ans, prices[i]-minval);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int minval = INT_MAX;
        for(int i = 0; i < prices.size(); i++) dp[i] = prices[i]-minval, minval = min(minval, prices[i]);
        dp.push_back(0);
        return *max_element(dp.begin(), dp.end());
    }
};
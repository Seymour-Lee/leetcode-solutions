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
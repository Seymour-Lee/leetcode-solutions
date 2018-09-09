class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(stk.empty() == false && price >= stk.top().first){
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({price, ans});
        return ans;
    }
    
private:
    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
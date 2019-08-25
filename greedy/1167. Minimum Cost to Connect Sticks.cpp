class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        auto f = [](int a, int b){return a > b;};
        priority_queue<int, vector<int>, function<bool(int, int)>> pq(f);
        for(auto s: sticks) pq.push(s);
        int ans = 0;
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            ans += x+y;
            pq.push(x+y);
        }
        return ans;
    }
};
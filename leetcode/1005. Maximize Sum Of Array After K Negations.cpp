class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a: A) pq.push(a);
        while(K--){
            int top = pq.top();
            pq.pop();
            top = -top;
            pq.push(top);
        }
        int ans = 0;
        while(pq.empty() == false){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
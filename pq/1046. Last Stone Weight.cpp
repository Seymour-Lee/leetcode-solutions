class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(auto a: stones) pq.push(a);
        while(pq.size() > 1){
            auto a = pq.top(); pq.pop();
            auto b = pq.top(); pq.pop();
            if(a != b){
                int c = a - b;
                pq.push(c);
            }
        }
        return pq.size() == 0? 0: pq.top();
    }
};
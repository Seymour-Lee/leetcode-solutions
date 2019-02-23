class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        using pp = pair<double, pair<int, int>>;
        auto f = [](pp a, pp b){return a.first > b.first;};
        priority_queue<pp, vector<pp>, function<bool(pp, pp)>> pq(f);
        for(int i = 0; i < A.size(); i++) pq.push({1.0*A[i]/A.back(), {i, A.size()-1}});
        while(--K){
            auto next = pq.top().second;pq.pop();
            next.second--;
            pq.push({1.0*A[next.first]/A[next.second], {next.first, next.second}});
        }
        return {A[pq.top().second.first], A[pq.top().second.second]};
    }
};
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<vector<double>> workers;
        for(int i = 0; i < quality.size(); i++){
            workers.push_back({(double)wage[i]/quality[i], (double)quality[i]});
        }
        sort(workers.begin(), workers.end());
        double ans = numeric_limits<double>::max(), qsum = 0;
        priority_queue<int> pq;
        for(auto w: workers){
            qsum += w[1];
            pq.push(w[1]);
            if(pq.size() > K) qsum -= pq.top(), pq.pop();
            if(pq.size() == K) ans = min(ans, qsum*w[0]);
        }
        return ans;
    }
};
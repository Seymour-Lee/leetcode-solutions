class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for(int i = 0; i < difficulty.size(); i++){
            jobs.push_back({difficulty[i], profit[i]});
        }
        auto f = [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        };
        sort(jobs.begin(), jobs.end(), f);
        sort(worker.begin(), worker.end());
        int result = 0;
        int i = 0, profitest = 0;
        for(auto w: worker){
            while(i < jobs.size() && w >= jobs[i].first)
                profitest = max(profitest, jobs[i++].second);
            result += profitest;
        }
        return result;
    }
};
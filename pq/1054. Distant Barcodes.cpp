class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> num2times;
        for(auto a: barcodes) num2times[a]++;
        auto f = [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(f);
        for(auto p: num2times){
            pq.push({p.first, p.second});
        }
        pair<int, int> prev = {-1, -1};
        vector<int> ans;
        while(pq.empty() == false){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
            if(prev.second > 0) pq.push(prev);
            p.second--;
            prev = p;
        }
        return ans;
    }
};
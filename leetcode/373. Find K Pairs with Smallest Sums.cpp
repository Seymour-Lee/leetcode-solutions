class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using p = pair<int, int>;
        auto f = [](const auto a, const auto b){return a.first + a.second < b.first + b.second;};
        priority_queue<p, vector<p>, function<bool(p, p)>> pq(f);
        int l1 = min(k, (int)nums1.size());
        int l2 = min(k, static_cast<int>(nums2.size()));
        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                int n1 = nums1[i], n2 = nums2[j];
                if(pq.size() < k){
                    pq.push({n1, n2});
                }
                else if(n1 + n2 < pq.top().first + pq.top().second){
                    pq.pop();
                    pq.push({n1, n2});
                }
            }
        }
        vector<p> ans;
        while(pq.empty() == false){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
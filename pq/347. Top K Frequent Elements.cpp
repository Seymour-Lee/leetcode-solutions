class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() == 0) return result;
        map<int, int> num2freq;
        for(auto num: nums) num2freq[num]++;
        map<int, vector<int>> freq2num;
        for(auto e: num2freq) freq2num[e.second].push_back(e.first);
        for(map<int, vector<int>>::reverse_iterator ritor = freq2num.rbegin();
            k > 0 && ritor != freq2num.rend(); ritor++){
            for(auto e: ritor->second){
                result.push_back(e);
                k--;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> a2t;
        for(auto num: nums) a2t[num]++;
        using ii = pair<int, int>;
        auto f = [](ii a, ii b){ return a.second < b.second;};
        priority_queue<ii, vector<ii>, function<bool(ii, ii)>> pq(f);
        for(auto p: a2t) pq.push({p.first, p.second});
        while(pq.empty() == false && k--){
            auto p = pq.top(); pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};
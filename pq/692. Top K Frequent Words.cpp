class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        map<string, int> str2freq;
        for(auto w: words) str2freq[w]++;
        map<int, set<string>> freq2strs;
        for(auto e: str2freq) freq2strs[e.second].insert(e.first);
        for(auto ritor = freq2strs.rbegin(); 
            ritor != freq2strs.rend() ; ritor++){
            for(auto str: ritor->second){
                result.push_back(str);
                if(--k == 0) return result;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> str2times;
        for(auto str: words) str2times[str]++;
        using si = pair<string, int>;
        auto f = [](si a, si b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<si, vector<si>, function<bool(si, si)>> pq(f);
        for(auto p: str2times){
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        while(pq.empty() == false){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
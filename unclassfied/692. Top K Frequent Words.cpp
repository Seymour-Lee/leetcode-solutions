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